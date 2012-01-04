/**
  ******************************************************************************
  * @file    usbh_usr.c
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    22/07/2011
  * @brief   This file includes the usb host user callbacks
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
#include "usbh_usr.h"

#define LCD_DisplayStringLine(X,Y) debug("%s", Y);
/** @addtogroup USBH_USER
  * @{
  */

/** @defgroup IAP_OVER_USB_USER
  * @brief
  * @{
  */

/* External variables --------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private defines -----------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/*  Points to the DEVICE_PROP structure of current device */
/*  The purpose of this register is to speed up the execution */
USBH_Usr_cb_TypeDef USR_Callbacks =
  {
    USBH_USR_Init,
    USBH_USR_DeviceAttached,
    USBH_USR_ResetDevice,
    USBH_USR_DeviceDisconnected,
    USBH_USR_OverCurrentDetected,
    USBH_USR_DeviceSpeedDetected,
    USBH_USR_Device_DescAvailable,
    USBH_USR_DeviceAddressAssigned,
    USBH_USR_Configuration_DescAvailable,
    USBH_USR_Manufacturer_String,
    USBH_USR_Product_String,
    USBH_USR_SerialNum_String,
    USBH_USR_IAPMenu,
    USBH_USR_UserInput,
    USBH_USR_DeviceNotSupported,
    USBH_USR_UnrecoveredError
  };

EmbeddedFileSystem          efs;
EmbeddedFile                file;
EmbeddedFile                fileR;
DirList                     list;
uint8_t joystick_use = 0x00;
uint8_t lcdLineNo = 0x00;
static uint8_t USBH_USR_ApplicationState = USH_USR_FS_INIT;
static uint8_t MSG_DEV_ATTACHED[]    = "> DEVICE ATTACHED                       ";
static uint8_t MSG_DEV_DISCONNECTED[] = "> DEVICE DISCONNECTED                   ";
static uint8_t MSG_DEV_ENUMERATED[]  = "> ENUMERATION COMPLETED                 ";
static uint8_t MSG_DEV_FULLSPEED[]   = "> DEVICE IS FULL SPEED                  ";
static uint8_t MSG_DEV_LOWSPEED[]    = "> DEVICE IS LOW SPEED                   ";
static uint8_t MSG_DEV_ERROR[]       = "> DEVICE ERROR                          ";
static uint8_t MSG_OVERCURRENT[]     = "> ERROR : OVERCURRENT DETECTED          ";
static uint8_t MSG_DEV_NSUPPORTED[]  = ">ATTACHED DEVICE IS NOT SUPPORTED!      ";
static uint8_t MSG_SEL_IMG[]         = "* Select the image to be downloaded     ";
static uint8_t MSG_WR_PROTECT[]      = "> The disk is write protected           ";
static uint8_t MSG_UNREC_ERROR[]     = "> UNRECOVERED ERROR STATE               ";
static uint8_t MSG_START_IAP[]       = "        STM32 IAP thru USB Host         ";
static uint8_t MSG_IAP_ENTER[]       = "              To ENTER IAP:             ";
static uint8_t MSG_IAP_PRSS[]        = "                  PRESS                 ";
static uint8_t MSG_IAP_KEY[]         = "             KEY under reset            ";
static uint8_t MSG_IAP_MENU[]        = "Use Joystick to select / Key to validate";
static uint8_t MSG_IAP_UPLOAD[]      = "                 Upload                 ";
static uint8_t MSG_IAP_DOWNLOAD[]    = "                 Download               ";
static uint8_t MSG_IAP_JUMP[]        = "                 Jump                   ";
static uint8_t MSG_IAP_NEXT_MENU[]   = " To see IAP Menu :                      ";
static uint8_t MSG_PRESS_KEY[]       = "                  'Press Key B3...'     ";
static uint8_t MSG_SEPARATION[]      = "----------------------------------------";
static uint8_t MSG_IO_FAILED[]       = "IO Expander FAILED                      ";
static uint8_t MSG_RESET[]           = "Please Reset the board and start again  ";
static uint8_t MSG_CLEAR[]           = "                                        ";
static uint8_t MSG_NOT_DIRECTORY[]   = "CAN NOT OPEN THE SELECTED DIRECTORY     ";
static uint8_t MSG_NO_IMAGE[]        = ">NO IMAGE TO BE DOWNLOADED              ";
static uint8_t MSG_OTHER_BIN[]       = "To see other 'BIN' file 'Press TAMPER..'";
static uint8_t MSG_BUFF_SIZE_ERROR1[] = ">BUFFER_SIZE ERROR ---- RESET TARGET    ";
static uint8_t MSG_BUFF_SIZE_ERROR2[] = " SEE APPLICATION NOTE FOR MORE DETAILS  ";
static uint8_t MSG_BUFF_SIZE_ERROR3[] = "        ABOUT BUFFER_SIZE VALUES        ";
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
  * @brief  USBH_USR_IAPInit
  *         Displays the message on LCD for IAP initialization
  * @param  None
  * @retval None
  */
void USBH_USR_IAPInit(void)
{

  /* Set default screen color*/
  //LCD_Clear(Black);

  /* Display the application header */
  //LCD_SetBackColor(Blue);
  //LCD_SetTextColor(White);

  /* Display LCD message: how to enter IAP mode */
  LCD_DisplayStringLine(Line0, (uint8_t *)MSG_START_IAP);
  LCD_DisplayStringLine(Line5, (uint8_t *)MSG_IAP_ENTER);
  LCD_DisplayStringLine(Line6, (uint8_t *)MSG_CLEAR);
  LCD_DisplayStringLine(Line7, (uint8_t *)MSG_IAP_PRSS);
  LCD_DisplayStringLine(Line8, (uint8_t *)MSG_CLEAR);
  LCD_DisplayStringLine(Line9, (uint8_t *)MSG_IAP_KEY);
}

/**
  * @brief  USBH_USR_Init
  *         Displays the message on LCD for host lib initialization
  * @param  None
  * @retval None
  */
void USBH_USR_Init(void)
{
  /* Set default screen color*/
  //LCD_Clear(Black);

  /* Display LCD message: how to enter IAP mode */
  LCD_DisplayStringLine(0, (uint8_t *)MSG_START_IAP);

  /* Set back color to black */
  //LCD_SetBackColor(Black);
}

/**
  * @brief  USBH_USR_DeviceAttached
  *         Displays the message on LCD on device attached
  * @param  None
  * @retval None
  */
void USBH_USR_DeviceAttached(void)
{
  /* LCD message device attached */
  LCD_DisplayStringLine(80, (uint8_t *)MSG_DEV_ATTACHED);
}


/**
  * @brief  USBH_USR_UnrecoveredError
  * @param  None
  * @retval None
  */
void USBH_USR_UnrecoveredError (void)
{

  /* Set default screen color*/
  //LCD_Clear(Black);

  /* Display the application header */
  //LCD_SetBackColor(Blue);
  //LCD_SetTextColor(White);
  LCD_DisplayStringLine(0, (uint8_t *)MSG_START_IAP);

  /* LCD message device error  */
  //LCD_SetBackColor(Red);
  LCD_DisplayStringLine(20,  (uint8_t *)MSG_UNREC_ERROR);
}

/**
  * @brief  USBH_DisconnectEvent
  *         Device disconnect event
  * @param  None
  * @retval Staus
  */
void USBH_USR_DeviceDisconnected (void)
{

  /* Set default screen color*/
  //LCD_Clear(Black);

  /* Display the application header */
  //LCD_SetBackColor(Blue);
  //LCD_SetTextColor(White);
  LCD_DisplayStringLine(0, (uint8_t *)MSG_START_IAP);

  /* LCD message device disconnecting */
  //LCD_SetBackColor(Black);
  LCD_DisplayStringLine(80, (uint8_t *)MSG_DEV_DISCONNECTED);
}

/**
  * @brief  USBH_USR_ResetUSBDevice
  * @param  None
  * @retval None
  */
void USBH_USR_ResetDevice(void)
{
  /* callback for USB-Reset */
}


/**
  * @brief  USBH_USR_DeviceSpeedDetected
  *         Displays the message on LCD for device speed
  * @param  Device speed:
  * @retval None
  */
void USBH_USR_DeviceSpeedDetected(uint8_t DeviceSpeed)
{
  if (DeviceSpeed == HPRT0_PRTSPD_FULL_SPEED)
  {
    LCD_DisplayStringLine(100, (uint8_t *)MSG_DEV_FULLSPEED);
  }
  else if (DeviceSpeed == HPRT0_PRTSPD_LOW_SPEED)
  {
    LCD_DisplayStringLine(100, (uint8_t *)MSG_DEV_LOWSPEED);
  }
  else
  {
    LCD_DisplayStringLine(100, (uint8_t *)MSG_DEV_ERROR);
  }
}

/**
  * @brief  USBH_USR_Device_DescAvailable
  * @param  device descriptor
  * @retval None
  */
void USBH_USR_Device_DescAvailable(void *DeviceDesc)
{
  /* callback for device descriptor */
}

/**
  * @brief  USBH_USR_DeviceAddressAssigned
  *         USB device is successfully assigned the Address
  * @param  None
  * @retval None
  */
void USBH_USR_DeviceAddressAssigned(void)
{
  /* callback for device successfully assigned the Address */
}


/**
  * @brief  USBH_USR_Conf_Desc
  * @param  Configuration descriptor
  * @retval None
  */
void USBH_USR_Configuration_DescAvailable(USBH_CfgDesc_TypeDef * cfgDesc,
    USBH_InterfaceDesc_TypeDef *itfDesc,
    USBH_EpDesc_TypeDef *epDesc)
{
  /* callback for configuration descriptor */
}

/**
  * @brief  USBH_USR_Manufacturer_String
  * @param  Manufacturer String
  * @retval None
  */
void USBH_USR_Manufacturer_String(void *ManufacturerString)
{
  /* callback for  Manufacturer String */
}

/**
  * @brief  USBH_USR_Product_String
  * @param  Product String
  * @retval None
  */
void USBH_USR_Product_String(void *ProductString)
{
  /* callback for Product String */
}

/**
  * @brief  USBH_USR_SerialNum_String
  * @param  SerialNum_String
  * @retval None
  */
void USBH_USR_SerialNum_String(void *SerialNumString)
{
  /* callback for SerialNum_String */
}

/**
  * @brief  IAP Display main menu on LCD
  * @param  None
  * @retval None
  */
void USBH_USR_IAPMenu(void)
{

  /* Enumeration complete */
  LCD_DisplayStringLine(120, (uint8_t *)MSG_DEV_ENUMERATED);
#if 0
  /* Display LCD next menu message */
  LCD_DisplayStringLine(180, (uint8_t *)MSG_SEPARATION);
  LCD_DisplayStringLine(200, (uint8_t *)MSG_IAP_NEXT_MENU);
  LCD_DisplayStringLine(210, (uint8_t *)MSG_PRESS_KEY);

  /* 0.5 seconds delay */
  USB_OTG_BSP_mDelay(500);

  /* Polling Key status */
  while ((HCD_IsDeviceConnected(&USB_OTG_FS_dev)) && \
         (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_9) == SET));

  /* Clear LCD */
  //LCD_Clear(Black);

  /* Display the application header */
  //LCD_SetBackColor(Blue);
  //LCD_SetTextColor(White);
  LCD_DisplayStringLine(1, (uint8_t *)MSG_START_IAP);

  /* Control BUFFER_SIZE value */
  USBH_USR_BufferSizeControl();

  /* Display LCD message: IAP menu */
  LCD_DisplayStringLine(30, (uint8_t *)MSG_IAP_MENU);

  /* Display IAP commands */
  //LCD_SetBackColor(Black);
  LCD_DisplayStringLine(40, (uint8_t *)MSG_IAP_UPLOAD);
  LCD_DisplayStringLine(50, (uint8_t *)MSG_IAP_DOWNLOAD);
  LCD_DisplayStringLine(60, (uint8_t *)MSG_IAP_JUMP);

  /* Display cursor */
  //LCD_DrawFullRect(50, 200, 10, 8);
  //LCD_SetTextColor(White);
  //LCD_DrawFullRect(60, 200, 10, 8);
  //LCD_SetBackColor(Blue);
  //LCD_DrawFullRect(40, 200, 10, 8);
  //LCD_SetTextColor(White);

  /* Joystick used to select IAP command */
  joystick_use = IAP_COMMAND_SELECT;

  /* Init the cursor */
  Seclect_CommandCounter = 40;
  CMD_index = 0x01;

  /* Configure the IO Expander */
  if (IOE_Config() == IOE_OK)
  {
    /* Enable Joystick interrupts */
    IOE_ITConfig(IOE_ITSRC_JOYSTICK);
  }
  else
  {
    /* IO expander failed */
    LCD_DisplayStringLine(60, (uint8_t *)MSG_IO_FAILED);
    LCD_DisplayStringLine(70, (uint8_t *)MSG_RESET);
    while (1);
  }
#endif
}


/**
  * @brief  USBH_USR_DeviceNotSupported
  *         Device is not supported
  * @param  None
  * @retval None
  */
void USBH_USR_DeviceNotSupported(void)
{
  /* Set default screen color */
  //LCD_Clear(Black);

  /* Display the application header */
  //LCD_SetBackColor(Blue);
  //LCD_SetTextColor(White);
  LCD_DisplayStringLine(0, (uint8_t*)MSG_START_IAP);

  /* Device not supported */
  //LCD_SetBackColor(Black);
  LCD_DisplayStringLine(40, (uint8_t*)MSG_DEV_NSUPPORTED);

  /* 2 seconds delay */
  USB_OTG_BSP_mDelay(2000);
}


/**
  * @brief  USBH_USR_UserInput
  *         User Action for application state entry
  * @param  None
  * @retval USBH_USR_Status : User response for key button
  */
USBH_USR_Status USBH_USR_UserInput(void)
{
  /* callback for Key botton: set by software in this case */
  return USBH_USR_RESP_OK;
}

/**
  * @brief  USBH_USR_OverCurrentDetected
  *         Over Current Detected on VBUS
  * @param  None
  * @retval None
  */
void USBH_USR_OverCurrentDetected (void)
{
  /* Display color on LCD */
  //LCD_Clear(Black);

  /* Display the application header */
  //LCD_SetBackColor(Blue);
  //LCD_SetTextColor(White);
  LCD_DisplayStringLine(0, (uint8_t*)MSG_START_IAP);
  //LCD_SetBackColor(Black);

  /* Set the LCD Text Color */
  //LCD_SetTextColor(White);
  LCD_DisplayStringLine(40, (uint8_t *)MSG_OVERCURRENT);

  /* 2 seconds delay */
  USB_OTG_BSP_mDelay(2000);
}

/**
  * @brief  USBH_USR_MSC_Application
  *         Demo application for IAP thru USB mass storage
  * @param  None
  * @retval Staus
  */
int USBH_USR_MSC_Application(void)
{

  switch (USBH_USR_ApplicationState)
  {
    case USH_USR_FS_INIT:

      /* Initialises the EFS lib*/
      if (efs_init(&efs, 0) != 0)
      {
        /* efs initialisation fails*/
        return(-1);
      }

      /* Set LCD parameters */
      //LCD_SetBackColor(Black);
      //LCD_SetTextColor(White);

      /* Flash Disk is write protected */
	  /*
      if (USBH_MSC_Param.MSWriteProtect == DISK_WRITE_PROTECTED)
      {
        LCD_DisplayStringLine(70, (uint8_t *)MSG_WR_PROTECT);
      }
	  */
      /* Control the select of commands */
      //USBH_USR_SelectControlMenu();

      /* Go to IAP menu */
      USBH_USR_ApplicationState = USH_USR_IAP;
      break;

    case USH_USR_IAP:

      /* Go to IAP menu */
      COMMAND_IAPExecuteApplication();

      /* Set user initialization flag */
      USBH_USR_ApplicationState = USH_USR_FS_INIT;
      break;

    default:
      break;
  }
  return(0);
}

/**
  * @brief  USBH_USR_DeInit
  *         Deint User state and associated variables
  * @param  None
  * @retval None
  */
void USBH_USR_DeInit(void)
{
  USBH_USR_ApplicationState = USH_USR_FS_INIT;
}

/**
  * @brief  USBH_USR_DisplayBinaryFlashContents
  * @param  Download_FileStruct: a pointer to structure that contain file name string
  *        and the file position under LCD
  * @retval status: the status of next command
  */
uint8_t USBH_USR_DisplayBinaryFlashContents (Download_FileTypeDef* Download_FileStruct)
{
  uint8_t index_struct = 0x00, status = NEXT_DOWNLOAD;


  /* Initilize struct */
  USBH_USR_InitDownloadStructure(Download_File);

  //USBH_USR_LCDClearPart(80, 100);

  /*Reads the dis list*/
  if (ls_openDir(&list, &(efs.myFs), "/") != 0)
  {
    /*Could not open the selected directory*/
    LCD_DisplayStringLine(120, (uint8_t *)MSG_NOT_DIRECTORY);
  }

  /* Search and display all .BIN files */
  while ((HCD_IsDeviceConnected(&USB_OTG_FS_dev)) && (ls_getNext(&list) == 0))
  {
    Download_FileStruct[index_struct].filenameString[0]  = list.currentEntry.FileName[0];
    Download_FileStruct[index_struct].filenameString[1]  = list.currentEntry.FileName[1];
    Download_FileStruct[index_struct].filenameString[2]  = list.currentEntry.FileName[2];
    Download_FileStruct[index_struct].filenameString[3]  = list.currentEntry.FileName[3];
    Download_FileStruct[index_struct].filenameString[4]  = list.currentEntry.FileName[4];
    Download_FileStruct[index_struct].filenameString[5]  = list.currentEntry.FileName[5];
    Download_FileStruct[index_struct].filenameString[6]  = list.currentEntry.FileName[6];
    Download_FileStruct[index_struct].filenameString[7]  = list.currentEntry.FileName[7];
    Download_FileStruct[index_struct].filenameString[8]  = '.' ;
    Download_FileStruct[index_struct].filenameString[9]  = list.currentEntry.FileName[8];
    Download_FileStruct[index_struct].filenameString[10] = list.currentEntry.FileName[9];
    Download_FileStruct[index_struct].filenameString[11] = list.currentEntry.FileName[10];

    /* BIN file */
    if ((Download_FileStruct[index_struct].filenameString[9] == 'B') && \
        (Download_FileStruct[index_struct].filenameString[10] == 'I') && \
        (Download_FileStruct[index_struct].filenameString[11] == 'N'))
    {
      lcdLineNo = lcdLineNo + 10;
      /* Display the file name */
      LCD_DisplayStringLine(lcdLineNo, Download_FileStruct[index_struct].filenameString);
      /* Index of file fixed under LCD */
      Download_FileStruct[index_struct].file_index = lcdLineNo;
      /* Display the file cursor */
      //LCD_DrawFullRect(lcdLineNo, 200, 10, 8);
      /* Set the LCD parameters */
      //LCD_SetBackColor(Black);
      //LCD_SetTextColor(White);
      /* increment index file */
      index_struct++;

      /* LCD maximum lines */
      if ( lcdLineNo == 210)
      {
        lcdLineNo = lcdLineNo + 20;
        /* Configure Tamper botton*/
        //STM_EVAL_PBInit(Button_TAMPER, Mode_GPIO);

        /* LCD set paramerters */
        //LCD_SetBackColor(Blue);
        LCD_DisplayStringLine(120, (uint8_t *)MSG_SEL_IMG);
        //LCD_DrawFullRect(130, 200, 10, 8);
        //LCD_SetBackColor(Black);
        //LCD_SetTextColor(White);

        /* Display LCD message */
        LCD_DisplayStringLine(lcdLineNo, (uint8_t *)MSG_OTHER_BIN);

        /* Enable joystick interrupt */
        USBH_USR_JoystickInterrupt(ENABLE);

        /* Polling Tamper botton */
        while ((HCD_IsDeviceConnected(&USB_OTG_FS_dev)) && \
               (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13) == SET))
        {
          /* Key botton pressed */
          if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_9) == RESET)
          {
            /* Disable joystick interrupt */
            USBH_USR_JoystickInterrupt(DISABLE);

            /* File selected */
            status = NEXT_DOWNLOAD;

            /* 0.5 seconds delay */
            USB_OTG_BSP_mDelay(500);

            return status;
          }
        }

        /* Disable joystick interrupt */
        USBH_USR_JoystickInterrupt(DISABLE);

        /* init download structure */
        USBH_USR_InitDownloadStructure(Download_FileStruct);
        index_struct = 0x00;

        /* Clear LCD BIN file names */
        //USBH_USR_LCDClearPart(130, 230);
      }
    }
  }

  /* BIN image found on the flash disk */
  if (index_struct > 0)
  {
    /* Set LCD parameters */
    //LCD_SetBackColor(Blue);
    LCD_DisplayStringLine(120, (uint8_t *)MSG_SEL_IMG);
    //LCD_DrawFullRect(130, 200, 10, 8);
    //LCD_SetBackColor(Black);
    //LCD_SetTextColor(White);

    /* control menu selection */
    status = USBH_USR_SelectControlMenu();
  }
  /* NO BIN image found in flash disk */
  else
  {
    LCD_DisplayStringLine(120, (uint8_t *)MSG_NO_IMAGE);

    /* joystick used to select IAP command */
    joystick_use = IAP_COMMAND_SELECT;

    /* Select other IAP command */
    status = NEXT_MENU;
  }
  return status;
}

/**
  * @brief  USBH_USR_JoystickInterrupt
  * @param  NewState: can be ENABLE or DISABLE
  * @retval None
  */
void USBH_USR_JoystickInterrupt (FunctionalState NewState)
{
#if 0
  NVIC_InitTypeDef NVIC_InitStructure;

  /* Enable/Disable EXTI Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = IOE_IT_EXTI_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x0F;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x0F;
  NVIC_InitStructure.NVIC_IRQChannelCmd = NewState;
  NVIC_Init(&NVIC_InitStructure);
#endif
}

/**
  * @brief  USBH_USR_InitDownloadStructure
  * @param  Download_FileStruct: a pointer to structure that contain file name string
  *        and the file position under LCD
  * @retval None
  */
void USBH_USR_InitDownloadStructure(Download_FileTypeDef* Download_FileStruct)
{
  __IO uint8_t index_struct = 0x00, index_filename = 0x00;
  uint8_t tmp_indexstruct = 0x00;

  for (index_struct; index_struct < 0x09;index_struct++)
  {
    for (index_filename = 0x00; index_filename < 12; index_filename++)
    {
      tmp_indexstruct = index_struct;
      Download_FileStruct[tmp_indexstruct].filenameString[index_filename] = 0x00;
    }

    Download_FileStruct[index_struct].file_index = 0x00;
  }

  lcdLineNo = 120;
  //Seclect_FileCounter = 130;
}
/**
  * @brief  //USBH_USR_LCDClearPart
  * @param  start: the start line to clear LCD
  * @param  end: the end line to clear LCD
  * @retval None
  */
void USBH_USR_LCDClearPart(uint8_t start, uint8_t end)
{
  uint8_t clear_index = 0x00;
  for (clear_index = start;clear_index < end + 1;clear_index++)
  {
    LCD_DisplayStringLine(clear_index, (uint8_t *)MSG_CLEAR);
  }
}

/**
  * @brief  USBH_USR_SelectControlMenu
  * @param  None
  * @retval status: flash disk status
  */
uint8_t USBH_USR_SelectControlMenu(void)
{
  uint8_t status = DEVICE_DISCONNECT;

  /* Enable joystick interrupt */
  USBH_USR_JoystickInterrupt(ENABLE);

  /* Key in polling */
  while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_9) == SET)
  {
    if (HCD_IsDeviceConnected(&USB_OTG_FS_dev) == 0)
    {
      status = DEVICE_DISCONNECT;
      return status;
    }
  }

  /* Disable joystick interrupt */
  USBH_USR_JoystickInterrupt(DISABLE);

  status = NEXT_DOWNLOAD;

  /* 0.8 seconds delay */
  USB_OTG_BSP_mDelay(800);

  return status;
}

/**
  * @brief  USBH_USR_BufferSizeControl
  * @param  None
  * @retval None
  */
void USBH_USR_BufferSizeControl(void)
{
  /* control Buffer size and limit this value to 32Kbyte maximum */
  if ((BUFFER_SIZE % 4 != 0x00) || (BUFFER_SIZE / 4 > 8192))
  {
    /* Set LCD parameters */
    //LCD_SetBackColor(Black);
    //LCD_SetTextColor(White);

    /* write LCD message error */
    LCD_DisplayStringLine(70, (uint8_t *)MSG_BUFF_SIZE_ERROR1);
    LCD_DisplayStringLine(90, (uint8_t *)MSG_BUFF_SIZE_ERROR2);
    LCD_DisplayStringLine(110, (uint8_t *)MSG_BUFF_SIZE_ERROR3);
    while (1);
  }
}
/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
