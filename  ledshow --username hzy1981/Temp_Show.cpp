#define TEMP_SHOW_C
#include "Includes.h"

#define SHOW_DATA_BLOCK_SIZE 250

//更新温度数据
void Update_Temp_Data(INT8U Area_No)
{

  Prog_Status.Area_Status[Area_No].Step = 100; //一步显示到位，直接100%
}
