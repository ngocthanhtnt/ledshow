#ifndef SHT1X_H
#define SHT1X_H

#include "Pub.h"

#undef EXT
#ifdef SHT1X_C
#define EXT
#else
#define EXT  extern
#endif

EXT void SHT1X_Init(void);
//EXT INT8U Get_Temp_Humidity(INT16S *pTemp, INT16S *pHumidity);
EXT INT8U Get_SHT1X_Temp_Humi(INT8U Flag, INT16S *pTemp, INT16S *pHumi);
EXT INT8U Get_Humidity(INT16S *pTemp);
EXT INT8U Chk_SHT1X_Sensor(void);
#endif
