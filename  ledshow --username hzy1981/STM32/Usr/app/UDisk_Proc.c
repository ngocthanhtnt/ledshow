#define UDISK_PROC_C
#include "Includes.h"
#include "FILE_SYS.H"

#define UDISK_RT_PLAY_TIME 3

extern esint8 efs_init(EmbeddedFileSystem * efs,eint8* opts);
/**
  ******************************************************************************
  * @file    command.c
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    22/07/2011
  * @brief   This file provides all the IAP command functions.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
//#include "command.h"

/** @addtogroup USBH_USER
  * @{
  */

/** @defgroup IAP_OVER_USB_COMMAND
  * @brief
  * @{
  */


/* External variables --------------------------------------------------------*/
extern uint8_t CMD_index;
extern uint8_t joystick_use;
/* Private typedef -----------------------------------------------------------*/
/* Private defines -----------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
Download_FileTypeDef Download_File [9];
/*
static uint8_t RAM_Buf[BUFFER_SIZE] =
  {
    0x00
  };
  */
//static uint32_t tmp_program_counter = 0x00, tmp_read_size = 0x00 , ram_address = 0x00;
//static uint32_t Last_PGAddress = APPLICATIONADDRESS;
const uint8_t MSG_UPLOAD_GOING[]        = "> UPLOAD ON GOING                        ";
const uint8_t MSG_UPLOAD_DONE[]         = "> UPLOAD DONE                            ";
const uint8_t MSG_ROP1[]                = ">      Can not access flash memory       ";
const uint8_t MSG_ROP2[]                = "> Please disable the Read Out Protection ";
const uint8_t MSG_DIR_ERROR[]           = "> Can not open directory                 ";
const uint8_t MSG_DOWNLOAD_GOING[]      = "> DOWNLOAD ON GOING                      ";
const uint8_t MSG_DOWNLOAD_DONE[]       = "> DOWNLOAD DONE                          ";
const uint8_t MSG_FLASH_PG_ERROR[]      = "> Flash programming error                ";
const uint8_t MSG_FLASH_ER_ERROR[]      = "> Flash erase error                      ";
const uint8_t MSG_FILE_SIZE_ERROR[]     = "> File size exceed 224Kbyte              ";
const uint8_t MSG_SELECT_MENU[]         = "> Please select a menu                   ";
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

void UDisk_Init(void)
{
#ifdef CHIP_USB_HOST
   /* Init Host Library */
   USBH_Init(&USB_OTG_FS_dev, &MSC_cb , &USR_Callbacks);
#else
  INT8U Re;

  Unselect_SPI_Device();

  SPI1_CH376_Init();
  Delay_ms(100);
  //SET_CH376_CS(0);	//选中CH376
  Re = mInitCH376Host();
  if(Re != USB_INT_SUCCESS)
  {
    ASSERT_FAILED();
  }
#endif
  //SET_CH376_CS(1);	//不选中CH376
}


void Set_UDisk_Status(INT8U Status)
{
  Screen_Status.UDisk_Flag = Status;
}

INT8U Chk_UDisk_Processing(void)
{
   if(Screen_Status.UDisk_Flag EQ UDISK_ING) //当前有U盘插入，并且正在处理状态
     return 1;
   else
     return 0;

	/*
   //当前没有在U盘处理状态中
   if(Query376Interrupt() EQ TRUE)
   {
     //Set_UDisk_Status(UDISK_ING);
	 Screen_Status.UDisk_Flag = UDISK_ING;
     return 1;
   }
   else
   {
     Screen_Status.UDisk_Flag = UDISK_NULL;
     return 0;
	 }
   	  */
}
     
void UDisk_Proc(void)
{
#ifdef CHIP_USB_HOST
	USBH_Process();
#else
    //static S_Int8U Flag = {CHK_BYTE, 0, CHK_BYTE};
    volatile static INT8U Re;
	INT8U Counts;
    INT16U RealCount,len;
	unsigned char buf[30];

    //if(Screen_Status.UDisk_Flag != UDISK_ING) //当前有U盘中断需要处理
	  //return;

	if(Query376Interrupt() EQ FALSE)//再次确认中断信号
	{
      Set_UDisk_Status(UDISK_NULL);
	  return;
	 }
    
	Set_UDisk_Status(UDISK_ING); 

    Unselect_SPI_Device();
	SPI1_CH376_Init();
	
	    Counts = 0;
		//while(!=USB_INT_SUCCESS) //SPI软件查询是否有U盘插入
 		do
		{
		  Re = CH376DiskConnect();
		  if(Re EQ USB_INT_DISCONNECT || Re EQ ERR_DISK_DISCON) //U盘被拔出
		  {
		    //RT_Play_Status_Exit(); //退出实时显示状态

            Set_UDisk_Status(UDISK_NULL);
		    goto UDiskProcEnd;
		  }
					  
		  Counts++;
		  if(Counts >= 20)
		  {
            Set_UDisk_Status(UDISK_NULL);
		    goto UDiskProcEnd;
		   }
		   
		   Delay_ms(100);	   
		 }while(Re != USB_INT_SUCCESS);
		 
		Delay_ms(200);

		Counts = 0;
 		while(Counts <= 10)//for ( i = 0; i < 100; i ++ ) {  /* 最长等待时间,100*50mS */
	    {
			Re = CH376DiskMount( );  /* 初始化磁盘并测试磁盘是否就绪 */
			if ( Re == USB_INT_SUCCESS ) 
			   break;  /* 准备好 */
			else if ( Re == ERR_DISK_DISCON ) 
			{
			  /* 检测到断开,重新检测并计时 */
			   Set_UDisk_Status(UDISK_NULL);
		       goto UDiskProcEnd;
			}

			if ( CH376GetDiskStatus( ) >= DEF_DISK_MOUNTED && Counts >= 5 ) 
			    break;  /* 有的U盘总是返回未准备好,不过可以忽略,只要其建立连接MOUNTED且尝试5*50mS */
		    
		    Delay_ms(50);
			Counts ++;
		}

		Set_RT_Show_Area(0, 0, 32, 16);
        RT_Play_Status_Enter(UDISK_RT_PLAY_TIME);

  		if ( CH376GetDiskStatus( ) < DEF_DISK_MOUNTED )/* 未知USB设备,例如USB键盘、打印机等 */ 
		{ 
			Clr_All_Show_Data();
			LED_Print(FONT0, Screen_Para.Base_Para.Color, &Show_Data, 0, 0, 0, "ERR4");
			Set_UDisk_Status(UDISK_NULL);
			goto UDiskProcEnd;
		}

		if(CH376DiskMount()==USB_INT_SUCCESS) //磁盘就绪?
		{
			//strcpy((char *)buf, "\\led_data\\");
			//itoa(Screen_Para.COM_Para.Addr, buf + 10, 10); //文件名是板地址,找不到文件则以广播地址读
			//sprintf(buf, (const char *)"\\%d.dat", Screen_Para.COM_Para.Addr);
			//strcpy((char *)buf, "\\LEDDATA\\0.DAT");
			sprintf((char *)buf, "\\LEDDATA\\%d.DAT", Screen_Para.COM_Para.Addr);
			Re = CH376FileOpenPath(buf);
			//LED_Print(FONT0, Screen_Para.Base_Para.Color, &Show_Data, 0, 0, 0, "%d", Re);
			if(Re != USB_INT_SUCCESS)
			{
			  strcpy((char *)buf, "\\LEDDATA\\65535.DAT");
			  Re = CH376FileOpenPath(buf);
			  if(Re != USB_INT_SUCCESS) //找不到文件则以广播地址读
			  {
			    Set_UDisk_Status(UDISK_NULL);
			    Clr_All_Show_Data();
			    LED_Print(FONT0, Screen_Para.Base_Para.Color, &Show_Data, 0, 0, 0, "ERR0");
				goto UDiskProcEnd;
			  }
			}

 			while(1)
			{
			    //Set_Screen_Com_Time(0); //到计时0秒后重新播放节目

				CH376ByteRead((INT8U *)RCV_DATA_BUF, FLEN + 2, &RealCount );
                if(RealCount EQ 0)
				{
  				  Clr_All_Show_Data();
				  LED_Print(FONT0, Screen_Para.Base_Para.Color, &Show_Data, 0, 0, 0, "OK");
				  break;
				}
			    else if(RealCount != FLEN + 2)
				{
				  //Screen_Status.UDisk_Flag = UDISK_END; //处理完毕
				  Clr_All_Show_Data();
				  LED_Print(FONT0, Screen_Para.Base_Para.Color, &Show_Data, 0, 0, 0, "ERR1");
				  break;
				}

                memcpy(&len, (INT8U *)RCV_DATA_BUF + FLEN, 2);
				if(len <= sizeof(RCV_DATA_BUF) && len > FLEN + 2)
				{
				  CH376ByteRead((INT8U *)RCV_DATA_BUF + FLEN + 2, len - (FLEN + 2), &RealCount );
		          if(RealCount EQ len - (FLEN + 2) && Check_Frame_Format((INT8U *)RCV_DATA_BUF, len))
		          {

				    Re = Rcv_Frame_Proc(CH_UDISK, (INT8U *)RCV_DATA_BUF, len, sizeof(RCV_DATA_BUF)); 
                    
					Unselect_SPI_Device();
	                SPI1_CH376_Init();
					
					if(Re EQ 0)
					{
					  //Screen_Status.UDisk_Flag = UDISK_END; //处理完毕
					  ASSERT_FAILED();
					  Clr_All_Show_Data();
					  LED_Print(FONT0, Screen_Para.Base_Para.Color, &Show_Data, 0, 0, 0, "ERR2");
					  break;
					} 
		          }
		        }
				else
				{
				      //Screen_Status.UDisk_Flag = UDISK_END; //处理完毕
   					  ASSERT_FAILED();
					  Clr_All_Show_Data();
					  LED_Print(FONT0, Screen_Para.Base_Para.Color, &Show_Data, 0, 0, 0, "ERR3");
					  break;
				}
		    }


		CH376FileClose(FALSE);
	    Set_UDisk_Status(UDISK_NULL);
	}
	else
	{
	  ASSERT_FAILED();
	  Clr_All_Show_Data();
	  LED_Print(FONT0, Screen_Para.Base_Para.Color, &Show_Data, 0, 0, 0, "ERR5");
	}
	
	Set_Screen_Com_Time(0); //到计时0秒后重新播放节目
UDiskProcEnd:
	Restore_Show_Area();

#endif
}

void Update_From_UDisk(void)
{
  unsigned char buf[30];
  INT32U RealCount;
  INT16U len;
  INT8U Re;

  if (efs_init(&efs, 0) != 0)
  {
    debug("fs init error!");
    /* efs initialisation fails*/
    return;
  }
#if 0
  /* Get the read out protection status */
  if(ls_openDir(&list, &(efs.myFs), "/LEDDATA") != 0)//"/LEDDATA/"
  {
    /* Clear LCD msg */
    //USBH_USR_LCDClearPart(80, 80);
    /* Could not open the selected directory */
    debug(MSG_DIR_ERROR);
	return;
  }
  else
#endif
  {
    sprintf((char *)buf, "/LEDDATA/%d.dat", Screen_Para.COM_Para.Addr);
    if (file_fopen(&fileR, &efs.myFs, (char *)buf, 'r') != 0)
	{
		if (file_fopen(&fileR, &efs.myFs, (char *)"/LEDDATA/65535.dat", 'r') != 0)
		{
			Set_UDisk_Status(UDISK_NULL);
			Clr_All_Show_Data();
			LED_Print(FONT0, Screen_Para.Base_Para.Color, &Show_Data, 0, 0, 0, "ERR0");
			goto UDiskProcEnd;
		}
	}

	while (1)
	{
	    //读取字节数
	    RealCount = file_read(&fileR, FLEN + 2, (INT8U *)RCV_DATA_BUF);
        
		if(RealCount EQ 0)
		{
		  Clr_All_Show_Data();
		  LED_Print(FONT0, Screen_Para.Base_Para.Color, &Show_Data, 0, 0, 0, "OK");
		  break;
		}
	    else if(RealCount != FLEN + 2)
		{
		  Clr_All_Show_Data();
		  LED_Print(FONT0, Screen_Para.Base_Para.Color, &Show_Data, 0, 0, 0, "ERR1");
		  break;
		}

        memcpy(&len, (INT8U *)RCV_DATA_BUF + FLEN, 2);
		if(len <= sizeof(RCV_DATA_BUF) && len > FLEN + 2)
		{
		  RealCount = file_read(&fileR, len - (FLEN + 2), (INT8U *)RCV_DATA_BUF + FLEN + 2);
          if(RealCount EQ len - (FLEN + 2) && Check_Frame_Format((INT8U *)RCV_DATA_BUF, len))
          {

		    Re = Rcv_Frame_Proc(CH_UDISK, (INT8U *)RCV_DATA_BUF, len, sizeof(RCV_DATA_BUF)); 
			
			if(Re EQ 0)
			{
			  //Screen_Status.UDisk_Flag = UDISK_END; //处理完毕
			  ASSERT_FAILED();
			  Clr_All_Show_Data();
			  LED_Print(FONT0, Screen_Para.Base_Para.Color, &Show_Data, 0, 0, 0, "ERR2");
			  break;
			}
		}
	  }
	  else
	  {
		  ASSERT_FAILED();
		  Clr_All_Show_Data();
		  LED_Print(FONT0, Screen_Para.Base_Para.Color, &Show_Data, 0, 0, 0, "ERR3");
		  break;
	  }
	 }

     file_fclose(&fileR);
   }
   
   Set_Screen_Com_Time(0); //到计时0秒后重新播放节目
UDiskProcEnd:
   Restore_Show_Area();
}


/**
  * @brief  COMMAND_IAPExecuteApplication
  * @param  None
  * @retval None
  */
void COMMAND_IAPExecuteApplication(void)
{
  Update_From_UDisk();
  /* Execute the command switch the command index */
  switch (CMD_index)
  {
      /* Reads all flash memory */
    case CMD_UPLOAD:
     // COMMAND_UPLOAD();
      break;

      /* Writes Flash memory */
    case CMD_DOWNLOAD:
     // COMMAND_DOWNLOAD();
      break;

      /* Jumps to user application code located in the internal Flash memory */
    case CMD_JUMP:
     // COMMAND_JUMP();
      break;
  }
}
#if 0
/**
  * @brief IAP Read all flash memory
  * @param  None
  * @retval None
  */
void COMMAND_UPLOAD(void)
{
  __IO uint32_t address = FLASH_STARTADDRESS;
  __IO uint32_t counter_read = 0x00;
  uint32_t tmp_counter = 0x00, index_offset = 0x00;
  FlagStatus readoutstatus = SET;

  /* Get the read out protection status */
  readoutstatus = FLASH_LAYER_ReadOutProtectionStatus();

  if (readoutstatus == RESET)
  {
    /* Remove UPLOAD file if exist on flash disk */
    rmfile(&efs.myFs, "UPLOAD.BIN");

    /* Init written byte counter */
    index_offset = 0x00;

    /* Open binary file to write on it */
    if ((HCD_IsDeviceConnected(&USB_OTG_FS_dev) == 1) && (file_fopen(&file, &efs.myFs, "UPLOAD.BIN", 'w') == 0))
    {
      /* Clear LCD msg */
      USBH_USR_LCDClearPart(90, 90);

      /* Display LCD message */
      LCD_DisplayStringLine(80, (uint8_t *)MSG_UPLOAD_GOING);

      /* Read flash memory */
      while ((index_offset != FLASH_SIZE) && (HCD_IsDeviceConnected(&USB_OTG_FS_dev) == 1))
      {
        for (counter_read = 0; counter_read < BUFFER_SIZE; counter_read++)
        {
          /* Check the read bytes versus the end of flash */
          if (index_offset + counter_read != FLASH_SIZE)
          {
            tmp_counter = counter_read;
            RAM_Buf[tmp_counter] = (*(uint8_t*)(address++));
          }
          /* In this case all flash was read */
          else
          {
            break;
          }
        }

        /* Write buffer to file */
        file_write(&file, counter_read, RAM_Buf);

        /* Number of byte written  */
        index_offset = index_offset + counter_read;
      }

      /* Display LCD message */
      LCD_DisplayStringLine(80, (uint8_t *)MSG_UPLOAD_DONE);

      /* Close file and filesystem */
      file_fclose(&file);
      fs_umount(&efs.myFs);
    }
  }
  else
  {
    /* Display LCD message ROP active */
    LCD_DisplayStringLine(80, (uint8_t *)MSG_ROP1);
    LCD_DisplayStringLine(90, (uint8_t *)MSG_ROP2);
  }
}

/**
  * @brief  IAP write memory
  * @param  None
  * @retval None
  */
void COMMAND_DOWNLOAD(void)
{
  __IO uint8_t index_struct = 0x00, status = NEXT_MENU;
  __IO uint32_t erase_address = 0x00;
  uint8_t tmp = 0x00;

  /* Get the read out protection status */
  if (ls_openDir(&list, &(efs.myFs), "/") != 0)
  {
    /* Clear LCD msg */
    USBH_USR_LCDClearPart(80, 80);
    /* Could not open the selected directory */
    LCD_DisplayStringLine(90, (uint8_t *)MSG_DIR_ERROR);
  }
  else
  {
    /* Joystick is used now to select the image to be downloaded */
    joystick_use = IAP_DOWNLOAD_SELECT;

    /* Check the flash disk binary image */
    status = USBH_USR_DisplayBinaryFlashContents(Download_File);

    switch (status)
    {
        /* Binary image selected */
      case  NEXT_DOWNLOAD:

        tmp = Seclect_FileCounter;
        /* Search the selected image */
        while (Download_File[index_struct].file_index != tmp)
        {
          index_struct++;
        }

        /* Open the binary file to be downloaded */
        if (file_fopen(&fileR, &efs.myFs, (char *)&Download_File[index_struct].filenameString[0], 'r') == 0)
        {

          if (fileR.FileSize > FLASH_SIZE - IAP_SIZE)
          {
            /* Clear LCD message*/
            USBH_USR_LCDClearPart(80, 230);
            /* Display LCD message flash erase error */
            LCD_DisplayStringLine(80, (uint8_t *)MSG_FILE_SIZE_ERROR);
            /* Display LCD message flash erase error */
            LCD_DisplayStringLine(90, (uint8_t *)MSG_SELECT_MENU);

            /* Joystick is used now to select the image to be downloaded */
            joystick_use = IAP_DOWNLOAD_SELECT;
          }
          else
          {
            /* Clear LCD msg */
            USBH_USR_LCDClearPart(80, 80);

            /* Display LCD message */
            LCD_DisplayStringLine(90, (uint8_t *)MSG_DOWNLOAD_GOING);

            /* Erase necessary page to download image */
            for (erase_address = APPLICATIONADDRESS; (erase_address < (APPLICATIONADDRESS + fileR.FileSize)) && (erase_address < FLASH_ENDADDRESS); \
                 erase_address = erase_address + PAGE_SIZE)
            {
              if (FLASH_LAYER_ErasePage (erase_address) != FLASH_COMPLETE)
              {
                /* Clear LCD message*/
                USBH_USR_LCDClearPart(80, 230);

                /* Display LCD message flash erase error */
                LCD_DisplayStringLine(100, (uint8_t *)MSG_FLASH_ER_ERROR);
                while (1);
              }
            }

            /* Program flash memory */
            COMMAND_ProgramFlashMemory();

            /* Display LCD message */
            LCD_DisplayStringLine(90, (uint8_t *)MSG_DOWNLOAD_DONE);

            /* Close file and filesystem */
            file_fclose(&fileR);
          }
          /* Clear LCD flash disk binary image */
          USBH_USR_LCDClearPart(120, 230);

          /* Joystick is used now to select IAP command */
          joystick_use = IAP_COMMAND_SELECT;
        }
        break;

      default:
        break;
    }
  }
}

/**
  * @brief  IAP jump to user program
  * @param  None
  * @retval None
  */
void COMMAND_JUMP(void)
{
  /* Software reset */
  NVIC_SystemReset();
}

/**
  * @brief  COMMAND_ProgramFlashMemory
  * @param  None
  * @retval None
  */
void COMMAND_ProgramFlashMemory(void)
{
  __IO uint32_t program_counter = 0x00, read_size = 0x00;
  uint8_t read_flag = TRUE;

  /* RAM Address Initialization */
  ram_address = (uint32_t) & RAM_Buf;

  /* Erase address init */
  Last_PGAddress = APPLICATIONADDRESS;

  /* While file still contain data */
  while (read_flag == TRUE)
  {
    /* Read maximum "BUFFER_SIZE" Kbyte from the selected file  */
    read_size = file_read(&fileR, BUFFER_SIZE, RAM_Buf);

    /* Temp variable */
    tmp_read_size = read_size;

    /* The read data < "BUFFER_SIZE" Kbyte */
    if (tmp_read_size < BUFFER_SIZE)
    {
      read_flag = FALSE;
    }

    /* Program flash memory */
    for (program_counter = tmp_read_size; program_counter != 0; program_counter -= 4)
    {
      tmp_program_counter = program_counter;
      /* Write word into flash memory */
      if (FLASH_LAYER_ProgramWord((Last_PGAddress - tmp_program_counter + tmp_read_size), \
                                  *(__IO uint32_t *)(ram_address - program_counter + tmp_read_size)) != FLASH_COMPLETE)
      {
        /* Clear LCD message*/
        USBH_USR_LCDClearPart(80, 230);

        /* Display LCD message flash programing error */
        LCD_DisplayStringLine(100, (uint8_t *)MSG_FLASH_PG_ERROR);
        while (1);
      }
    }

    /* Update last programmed address value */
    Last_PGAddress = Last_PGAddress + tmp_read_size;
  }
}
#endif
/**
  * @}
  */

/**
  * @}
  */

/*******************(C)COPYRIGHT 2011 STMicroelectronics *****END OF FILE******/
