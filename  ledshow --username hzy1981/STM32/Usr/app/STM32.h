#ifndef STM32_H
#define STM32_H

//#if QT_EN == 0
//#include "LED_Cfg.h"

#undef EXT
#ifdef STM32_C
#define EXT
#else
#define EXT extern
#endif

//定义断言,多多使用，有益身心
#if ASSERT_EN>0
#define ASSERT(x) //Assert((BOOL)(x),__FILE__,__FUNCTION__,(INT16U)__LINE__)
#define ASSERT_FAILED() //Assert_Failed(__FILE__,__FUNCTION__,(INT16U)__LINE__)
#else
#define ASSERT(x)
#define ASSERT_FAILED()
#endif

typedef unsigned int INT32U;
typedef int INT32S;
typedef unsigned short int INT16U;
typedef short int INT16S;
typedef unsigned char INT8U;
typedef char INT8S;
typedef unsigned char BOOL;


//#endif
#endif
