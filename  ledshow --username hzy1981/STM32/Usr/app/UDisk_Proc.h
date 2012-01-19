#ifndef UDISK_PROC_H
#define UDISK_PROC_H

#include "usbh_usr.h"

#undef EXT
#ifdef UDISK_PROC_C
#define EXT
#else
#define EXT extern
#endif

#define UDISK_NULL 0x00
#define UDISK_ING 0x01
#define UDISK_END 0x02


/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
   
#define CMD_UPLOAD                         ((uint8_t)0x01) /* Reads memory starting from an
                                                                  address specified by the application */
#define CMD_DOWNLOAD                       ((uint8_t)0x02) /* Writes RAM or Flash memory starting 
                                                            from an address specified by the application */
#define CMD_JUMP                           ((uint8_t)0x03) /* Jumps to user application code located
                                                                 in the internal Flash memory or in SRAM */
/* Exported macros -----------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */ 
void COMMAND_IAPExecuteApplication(void);
void COMMAND_UPLOAD(void);
void COMMAND_JUMP(void);
void COMMAND_DOWNLOAD(void);
void COMMAND_ProgramFlashMemory(void);

EXT void Update_From_UDisk(void);
EXT void UDisk_Init(void);
EXT void UDisk_Proc(void); 
EXT INT8U Chk_UDisk_Processing(void);
#endif

