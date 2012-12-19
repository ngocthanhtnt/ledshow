#ifndef SHT1X_H
#define SHT1X_H

#include "Pub.h"

#undef EXT
#ifdef SHT1X_C
#define EXT
#else
#define EXT  extern
#endif

EXT void SHT_Init(void);
EXT INT8U Get_Temp_Humidity(INT16S *pTemp, INT16S *pHumidity);
#endif
