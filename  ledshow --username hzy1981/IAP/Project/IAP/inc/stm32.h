#ifndef STM32_H
#define STM32_H

#include "LED_Cfg.h"
#include "stm32f10x.h"

#undef EXT
#ifdef STM32_C
#define EXT
#else
#define EXT extern
#endif

#define EQ ==

#define ASSERT_FAILED()

EXT void Clr_Watch_Dog(void);
EXT void IWDG_Init(void);
EXT void RCC_Configuration(void);
EXT void BKP_Register_Init(void);
EXT uint32_t Flash_PagesMask(__IO uint32_t Size);

#endif
