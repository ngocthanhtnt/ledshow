#line 1 "..\\target\\stm32f10x_it.c"























 

 
#line 1 "..\\target\\stm32f10x_it.h"



















  

 







 
#line 1 "..\\STM32F10x_lib\\inc\\stm32f10x.h"





















 



 



 
    






  


 
  


 


       
       
       












 






 
   








            
#line 88 "..\\STM32F10x_lib\\inc\\stm32f10x.h"





 






 
#line 107 "..\\STM32F10x_lib\\inc\\stm32f10x.h"



 



 



 







 
typedef enum IRQn
{
 
  NonMaskableInt_IRQn         = -14,     
  MemoryManagement_IRQn       = -12,     
  BusFault_IRQn               = -11,     
  UsageFault_IRQn             = -10,     
  SVCall_IRQn                 = -5,      
  DebugMonitor_IRQn           = -4,      
  PendSV_IRQn                 = -2,      
  SysTick_IRQn                = -1,      

 
  WWDG_IRQn                   = 0,       
  PVD_IRQn                    = 1,       
  TAMPER_IRQn                 = 2,       
  RTC_IRQn                    = 3,       
  FLASH_IRQn                  = 4,       
  RCC_IRQn                    = 5,       
  EXTI0_IRQn                  = 6,       
  EXTI1_IRQn                  = 7,       
  EXTI2_IRQn                  = 8,       
  EXTI3_IRQn                  = 9,       
  EXTI4_IRQn                  = 10,      
  DMA1_Channel1_IRQn          = 11,      
  DMA1_Channel2_IRQn          = 12,      
  DMA1_Channel3_IRQn          = 13,      
  DMA1_Channel4_IRQn          = 14,      
  DMA1_Channel5_IRQn          = 15,      
  DMA1_Channel6_IRQn          = 16,      
  DMA1_Channel7_IRQn          = 17,      
  ADC1_2_IRQn                 = 18,      

#line 181 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

#line 208 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

#line 252 "..\\STM32F10x_lib\\inc\\stm32f10x.h"


  CAN1_TX_IRQn                = 19,      
  CAN1_RX0_IRQn               = 20,      
  CAN1_RX1_IRQn               = 21,      
  CAN1_SCE_IRQn               = 22,      
  EXTI9_5_IRQn                = 23,      
  TIM1_BRK_IRQn               = 24,      
  TIM1_UP_IRQn                = 25,      
  TIM1_TRG_COM_IRQn           = 26,      
  TIM1_CC_IRQn                = 27,      
  TIM2_IRQn                   = 28,      
  TIM3_IRQn                   = 29,      
  TIM4_IRQn                   = 30,      
  I2C1_EV_IRQn                = 31,      
  I2C1_ER_IRQn                = 32,      
  I2C2_EV_IRQn                = 33,      
  I2C2_ER_IRQn                = 34,      
  SPI1_IRQn                   = 35,      
  SPI2_IRQn                   = 36,      
  USART1_IRQn                 = 37,      
  USART2_IRQn                 = 38,      
  USART3_IRQn                 = 39,      
  EXTI15_10_IRQn              = 40,      
  RTCAlarm_IRQn               = 41,      
  OTG_FS_WKUP_IRQn            = 42,      
  TIM5_IRQn                   = 50,      
  SPI3_IRQn                   = 51,      
  UART4_IRQn                  = 52,      
  UART5_IRQn                  = 53,      
  TIM6_IRQn                   = 54,      
  TIM7_IRQn                   = 55,      
  DMA2_Channel1_IRQn          = 56,      
  DMA2_Channel2_IRQn          = 57,      
  DMA2_Channel3_IRQn          = 58,      
  DMA2_Channel4_IRQn          = 59,      
  DMA2_Channel5_IRQn          = 60,      
  ETH_IRQn                    = 61,      
  ETH_WKUP_IRQn               = 62,      
  CAN2_TX_IRQn                = 63,      
  CAN2_RX0_IRQn               = 64,      
  CAN2_RX1_IRQn               = 65,      
  CAN2_SCE_IRQn               = 66,      
  OTG_FS_IRQn                 = 67       

} IRQn_Type;



 

#line 1 "C:\\Keil\\ARM\\RV31\\INC\\core_cm3.h"
 




















 





































 

 
 
 
 
 
 
 
 








 











#line 1 "C:\\Keil\\ARM\\RV31\\INC\\stdint.h"
 
 





 









#line 25 "C:\\Keil\\ARM\\RV31\\INC\\stdint.h"







 

     

     
typedef   signed          char int8_t;
typedef   signed short     int int16_t;
typedef   signed           int int32_t;
typedef   signed       __int64 int64_t;

     
typedef unsigned          char uint8_t;
typedef unsigned short     int uint16_t;
typedef unsigned           int uint32_t;
typedef unsigned       __int64 uint64_t;

     

     
     
typedef   signed          char int_least8_t;
typedef   signed short     int int_least16_t;
typedef   signed           int int_least32_t;
typedef   signed       __int64 int_least64_t;

     
typedef unsigned          char uint_least8_t;
typedef unsigned short     int uint_least16_t;
typedef unsigned           int uint_least32_t;
typedef unsigned       __int64 uint_least64_t;

     

     
typedef   signed           int int_fast8_t;
typedef   signed           int int_fast16_t;
typedef   signed           int int_fast32_t;
typedef   signed       __int64 int_fast64_t;

     
typedef unsigned           int uint_fast8_t;
typedef unsigned           int uint_fast16_t;
typedef unsigned           int uint_fast32_t;
typedef unsigned       __int64 uint_fast64_t;

     
typedef   signed           int intptr_t;
typedef unsigned           int uintptr_t;

     
typedef   signed       __int64 intmax_t;
typedef unsigned       __int64 uintmax_t;




     

     





     





     





     

     





     





     





     

     





     





     





     

     


     


     


     

     


     


     


     

     



     



     


     
    
 



#line 196 "C:\\Keil\\ARM\\RV31\\INC\\stdint.h"

     







     










     











#line 260 "C:\\Keil\\ARM\\RV31\\INC\\stdint.h"



 


#line 91 "C:\\Keil\\ARM\\RV31\\INC\\core_cm3.h"

















 

#line 117 "C:\\Keil\\ARM\\RV31\\INC\\core_cm3.h"





 


 





 
typedef struct
{
  volatile uint32_t ISER[8];                       
       uint32_t RESERVED0[24];                                   
  volatile uint32_t ICER[8];                       
       uint32_t RSERVED1[24];                                    
  volatile uint32_t ISPR[8];                       
       uint32_t RESERVED2[24];                                   
  volatile uint32_t ICPR[8];                       
       uint32_t RESERVED3[24];                                   
  volatile uint32_t IABR[8];                       
       uint32_t RESERVED4[56];                                   
  volatile uint8_t  IP[240];                       
       uint32_t RESERVED5[644];                                  
  volatile  uint32_t STIR;                          
}  NVIC_Type;                                               
   





 
typedef struct
{
  volatile const  uint32_t CPUID;                         
  volatile uint32_t ICSR;                          
  volatile uint32_t VTOR;                          
  volatile uint32_t AIRCR;                         
  volatile uint32_t SCR;                           
  volatile uint32_t CCR;                           
  volatile uint8_t  SHP[12];                       
  volatile uint32_t SHCSR;                         
  volatile uint32_t CFSR;                          
  volatile uint32_t HFSR;                          
  volatile uint32_t DFSR;                          
  volatile uint32_t MMFAR;                         
  volatile uint32_t BFAR;                          
  volatile uint32_t AFSR;                          
  volatile const  uint32_t PFR[2];                        
  volatile const  uint32_t DFR;                           
  volatile const  uint32_t ADR;                           
  volatile const  uint32_t MMFR[4];                       
  volatile const  uint32_t ISAR[5];                       
} SCB_Type;                                                

 












 






























 






 





















 









 


















 
































                                     









 









 









 














   





 
typedef struct
{
  volatile uint32_t CTRL;                          
  volatile uint32_t LOAD;                          
  volatile uint32_t VAL;                           
  volatile const  uint32_t CALIB;                         
} SysTick_Type;

 












 



 



 








   





 
typedef struct
{
  volatile  union  
  {
    volatile  uint8_t    u8;                        
    volatile  uint16_t   u16;                       
    volatile  uint32_t   u32;                       
  }  PORT [32];                                
       uint32_t RESERVED0[864];                                 
  volatile uint32_t TER;                           
       uint32_t RESERVED1[15];                                  
  volatile uint32_t TPR;                           
       uint32_t RESERVED2[15];                                  
  volatile uint32_t TCR;                           
       uint32_t RESERVED3[29];                                  
  volatile uint32_t IWR;                           
  volatile uint32_t IRR;                           
  volatile uint32_t IMCR;                          
       uint32_t RESERVED4[43];                                  
  volatile uint32_t LAR;                           
  volatile uint32_t LSR;                           
       uint32_t RESERVED5[6];                                   
  volatile const  uint32_t PID4;                          
  volatile const  uint32_t PID5;                          
  volatile const  uint32_t PID6;                          
  volatile const  uint32_t PID7;                          
  volatile const  uint32_t PID0;                          
  volatile const  uint32_t PID1;                          
  volatile const  uint32_t PID2;                          
  volatile const  uint32_t PID3;                          
  volatile const  uint32_t CID0;                          
  volatile const  uint32_t CID1;                          
  volatile const  uint32_t CID2;                          
  volatile const  uint32_t CID3;                          
} ITM_Type;                                                

 



 
























 



 



 



 








   





 
typedef struct
{
       uint32_t RESERVED0;
  volatile const  uint32_t ICTR;                          



       uint32_t RESERVED1;

} InterruptType_Type;

 



 








   


#line 614 "C:\\Keil\\ARM\\RV31\\INC\\core_cm3.h"





 
typedef struct
{
  volatile uint32_t DHCSR;                         
  volatile  uint32_t DCRSR;                         
  volatile uint32_t DCRDR;                         
  volatile uint32_t DEMCR;                         
} CoreDebug_Type;

 




































 






 






































   


 
#line 721 "C:\\Keil\\ARM\\RV31\\INC\\core_cm3.h"

#line 728 "C:\\Keil\\ARM\\RV31\\INC\\core_cm3.h"






   




 





#line 758 "C:\\Keil\\ARM\\RV31\\INC\\core_cm3.h"


 


 




#line 783 "C:\\Keil\\ARM\\RV31\\INC\\core_cm3.h"


 
 
 
 








 
extern uint32_t __get_PSP(void);








 
extern void __set_PSP(uint32_t topOfProcStack);








 
extern uint32_t __get_MSP(void);








 
extern void __set_MSP(uint32_t topOfMainStack);








 
extern uint32_t __REV16(uint16_t value);








 
extern int32_t __REVSH(int16_t value);


#line 933 "C:\\Keil\\ARM\\RV31\\INC\\core_cm3.h"





 








 
static __inline uint32_t  __get_BASEPRI(void)
{
  register uint32_t __regBasePri         __asm("basepri");
  return(__regBasePri);
}







 
static __inline void __set_BASEPRI(uint32_t basePri)
{
  register uint32_t __regBasePri         __asm("basepri");
  __regBasePri = (basePri & 0xff);
}







 
static __inline uint32_t __get_PRIMASK(void)
{
  register uint32_t __regPriMask         __asm("primask");
  return(__regPriMask);
}







 
static __inline void __set_PRIMASK(uint32_t priMask)
{
  register uint32_t __regPriMask         __asm("primask");
  __regPriMask = (priMask);
}







 
static __inline uint32_t __get_FAULTMASK(void)
{
  register uint32_t __regFaultMask       __asm("faultmask");
  return(__regFaultMask);
}







 
static __inline void __set_FAULTMASK(uint32_t faultMask)
{
  register uint32_t __regFaultMask       __asm("faultmask");
  __regFaultMask = (faultMask & 1);
}







 
static __inline uint32_t __get_CONTROL(void)
{
  register uint32_t __regControl         __asm("control");
  return(__regControl);
}







 
static __inline void __set_CONTROL(uint32_t control)
{
  register uint32_t __regControl         __asm("control");
  __regControl = control;
}





#line 1445 "C:\\Keil\\ARM\\RV31\\INC\\core_cm3.h"







 
 

 











 
static __inline void NVIC_SetPriorityGrouping(uint32_t PriorityGroup)
{
  uint32_t reg_value;
  uint32_t PriorityGroupTmp = (PriorityGroup & 0x07);                          
  
  reg_value  =  ((SCB_Type *) ((0xE000E000) + 0x0D00))->AIRCR;                                                    
  reg_value &= ~((0xFFFFul << 16) | (7ul << 8));              
  reg_value  =  (reg_value                       |
                (0x5FA << 16) | 
                (PriorityGroupTmp << 8));                                      
  ((SCB_Type *) ((0xE000E000) + 0x0D00))->AIRCR =  reg_value;
}








 
static __inline uint32_t NVIC_GetPriorityGrouping(void)
{
  return ((((SCB_Type *) ((0xE000E000) + 0x0D00))->AIRCR & (7ul << 8)) >> 8);    
}








 
static __inline void NVIC_EnableIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000) + 0x0100))->ISER[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F));  
}








 
static __inline void NVIC_DisableIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000) + 0x0100))->ICER[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F));  
}









 
static __inline uint32_t NVIC_GetPendingIRQ(IRQn_Type IRQn)
{
  return((uint32_t) ((((NVIC_Type *) ((0xE000E000) + 0x0100))->ISPR[(uint32_t)(IRQn) >> 5] & (1 << ((uint32_t)(IRQn) & 0x1F)))?1:0));  
}








 
static __inline void NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000) + 0x0100))->ISPR[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F));  
}








 
static __inline void NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000) + 0x0100))->ICPR[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F));  
}









 
static __inline uint32_t NVIC_GetActive(IRQn_Type IRQn)
{
  return((uint32_t)((((NVIC_Type *) ((0xE000E000) + 0x0100))->IABR[(uint32_t)(IRQn) >> 5] & (1 << ((uint32_t)(IRQn) & 0x1F)))?1:0));  
}












 
static __inline void NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority)
{
  if(IRQn < 0) {
    ((SCB_Type *) ((0xE000E000) + 0x0D00))->SHP[((uint32_t)(IRQn) & 0xF)-4] = ((priority << (8 - 4)) & 0xff); }  
  else {
    ((NVIC_Type *) ((0xE000E000) + 0x0100))->IP[(uint32_t)(IRQn)] = ((priority << (8 - 4)) & 0xff);    }         
}















 
static __inline uint32_t NVIC_GetPriority(IRQn_Type IRQn)
{

  if(IRQn < 0) {
    return((uint32_t)(((SCB_Type *) ((0xE000E000) + 0x0D00))->SHP[((uint32_t)(IRQn) & 0xF)-4] >> (8 - 4)));  }  
  else {
    return((uint32_t)(((NVIC_Type *) ((0xE000E000) + 0x0100))->IP[(uint32_t)(IRQn)]           >> (8 - 4)));  }  
}
















 
static __inline uint32_t NVIC_EncodePriority (uint32_t PriorityGroup, uint32_t PreemptPriority, uint32_t SubPriority)
{
  uint32_t PriorityGroupTmp = (PriorityGroup & 0x07);           
  uint32_t PreemptPriorityBits;
  uint32_t SubPriorityBits;

  PreemptPriorityBits = ((7 - PriorityGroupTmp) > 4) ? 4 : 7 - PriorityGroupTmp;
  SubPriorityBits     = ((PriorityGroupTmp + 4) < 7) ? 0 : PriorityGroupTmp - 7 + 4;
 
  return (
           ((PreemptPriority & ((1 << (PreemptPriorityBits)) - 1)) << SubPriorityBits) |
           ((SubPriority     & ((1 << (SubPriorityBits    )) - 1)))
         );
}
















 
static __inline void NVIC_DecodePriority (uint32_t Priority, uint32_t PriorityGroup, uint32_t* pPreemptPriority, uint32_t* pSubPriority)
{
  uint32_t PriorityGroupTmp = (PriorityGroup & 0x07);           
  uint32_t PreemptPriorityBits;
  uint32_t SubPriorityBits;

  PreemptPriorityBits = ((7 - PriorityGroupTmp) > 4) ? 4 : 7 - PriorityGroupTmp;
  SubPriorityBits     = ((PriorityGroupTmp + 4) < 7) ? 0 : PriorityGroupTmp - 7 + 4;
  
  *pPreemptPriority = (Priority >> SubPriorityBits) & ((1 << (PreemptPriorityBits)) - 1);
  *pSubPriority     = (Priority                   ) & ((1 << (SubPriorityBits    )) - 1);
}



 












 
static __inline uint32_t SysTick_Config(uint32_t ticks)
{ 
  if (ticks > (0xFFFFFFul << 0))  return (1);             
                                                               
  ((SysTick_Type *) ((0xE000E000) + 0x0010))->LOAD  = (ticks & (0xFFFFFFul << 0)) - 1;       
  NVIC_SetPriority (SysTick_IRQn, (1<<4) - 1);   
  ((SysTick_Type *) ((0xE000E000) + 0x0010))->VAL   = 0;                                           
  ((SysTick_Type *) ((0xE000E000) + 0x0010))->CTRL  = (1ul << 2) | 
                   (1ul << 1)   | 
                   (1ul << 0);                     
  return (0);                                                   
}






 





 
static __inline void NVIC_SystemReset(void)
{
  ((SCB_Type *) ((0xE000E000) + 0x0D00))->AIRCR  = ((0x5FA << 16)      | 
                 (((SCB_Type *) ((0xE000E000) + 0x0D00))->AIRCR & (7ul << 8)) | 
                 (1ul << 2));                    
  __dsb(0);                                                                    
  while(1);                                                     
}

   



 






 
 

extern volatile int ITM_RxBuffer;                     












 
static __inline uint32_t ITM_SendChar (uint32_t ch)
{
  if ((((CoreDebug_Type *) (0xE000EDF0))->DEMCR & (1ul << 24))  &&       
      (((ITM_Type *) (0xE0000000))->TCR & (1ul << 0))                  &&       
      (((ITM_Type *) (0xE0000000))->TER & (1ul << 0)        )                    )      
  {
    while (((ITM_Type *) (0xE0000000))->PORT[0].u32 == 0);
    ((ITM_Type *) (0xE0000000))->PORT[0].u8 = (uint8_t) ch;
  }  
  return (ch);
}










 
static __inline int ITM_ReceiveChar (void) {
  int ch = -1;                                

  if (ITM_RxBuffer != 0x5AA55AA5) {
    ch = ITM_RxBuffer;
    ITM_RxBuffer = 0x5AA55AA5;        
  }
  
  return (ch); 
}









 
static __inline int ITM_CheckChar (void) {

  if (ITM_RxBuffer == 0x5AA55AA5) {
    return (0);                                  
  } else {
    return (1);                                  
  }
}

   






   



 
#line 304 "..\\STM32F10x_lib\\inc\\stm32f10x.h"
#line 1 "..\\STM32F10x_lib\\inc\\system_stm32f10x.h"


















 



 



   
  


 









 



 




 

extern const uint32_t SystemFrequency;           
extern const uint32_t SystemFrequency_SysClk;    
extern const uint32_t SystemFrequency_AHBClk;    
extern const uint32_t SystemFrequency_APB1Clk;   
extern const uint32_t SystemFrequency_APB2Clk;   



 



 



 



 



 



 
  
extern void SystemInit(void);


 









 
  


   
 
#line 305 "..\\STM32F10x_lib\\inc\\stm32f10x.h"
#line 306 "..\\STM32F10x_lib\\inc\\stm32f10x.h"



   

 
typedef int32_t  s32;
typedef int16_t s16;
typedef int8_t  s8;

typedef const int32_t sc32;   
typedef const int16_t sc16;   
typedef const int8_t sc8;    

typedef volatile int32_t  vs32;
typedef volatile int16_t  vs16;
typedef volatile int8_t   vs8;

typedef volatile const int32_t vsc32;   
typedef volatile const int16_t vsc16;   
typedef volatile const int8_t vsc8;    

typedef uint32_t  u32;
typedef uint16_t u16;
typedef uint8_t  u8;

typedef const uint32_t uc32;   
typedef const uint16_t uc16;   
typedef const uint8_t uc8;    

typedef volatile uint32_t  vu32;
typedef volatile uint16_t vu16;
typedef volatile uint8_t  vu8;

typedef volatile const uint32_t vuc32;   
typedef volatile const uint16_t vuc16;   
typedef volatile const uint8_t vuc8;    


typedef enum {FALSE = 0, TRUE = !FALSE} bool;


typedef enum {RESET = 0, SET = !RESET} FlagStatus, ITStatus;

typedef enum {DISABLE = 0, ENABLE = !DISABLE} FunctionalState;


typedef enum {ERROR = 0, SUCCESS = !ERROR} ErrorStatus;



 



    



 

typedef struct
{
  volatile uint32_t SR;
  volatile uint32_t CR1;
  volatile uint32_t CR2;
  volatile uint32_t SMPR1;
  volatile uint32_t SMPR2;
  volatile uint32_t JOFR1;
  volatile uint32_t JOFR2;
  volatile uint32_t JOFR3;
  volatile uint32_t JOFR4;
  volatile uint32_t HTR;
  volatile uint32_t LTR;
  volatile uint32_t SQR1;
  volatile uint32_t SQR2;
  volatile uint32_t SQR3;
  volatile uint32_t JSQR;
  volatile uint32_t JDR1;
  volatile uint32_t JDR2;
  volatile uint32_t JDR3;
  volatile uint32_t JDR4;
  volatile uint32_t DR;
} ADC_TypeDef;



 

typedef struct
{
  uint32_t  RESERVED0;
  volatile uint16_t DR1;
  uint16_t  RESERVED1;
  volatile uint16_t DR2;
  uint16_t  RESERVED2;
  volatile uint16_t DR3;
  uint16_t  RESERVED3;
  volatile uint16_t DR4;
  uint16_t  RESERVED4;
  volatile uint16_t DR5;
  uint16_t  RESERVED5;
  volatile uint16_t DR6;
  uint16_t  RESERVED6;
  volatile uint16_t DR7;
  uint16_t  RESERVED7;
  volatile uint16_t DR8;
  uint16_t  RESERVED8;
  volatile uint16_t DR9;
  uint16_t  RESERVED9;
  volatile uint16_t DR10;
  uint16_t  RESERVED10; 
  volatile uint16_t RTCCR;
  uint16_t  RESERVED11;
  volatile uint16_t CR;
  uint16_t  RESERVED12;
  volatile uint16_t CSR;
  uint16_t  RESERVED13[5];
  volatile uint16_t DR11;
  uint16_t  RESERVED14;
  volatile uint16_t DR12;
  uint16_t  RESERVED15;
  volatile uint16_t DR13;
  uint16_t  RESERVED16;
  volatile uint16_t DR14;
  uint16_t  RESERVED17;
  volatile uint16_t DR15;
  uint16_t  RESERVED18;
  volatile uint16_t DR16;
  uint16_t  RESERVED19;
  volatile uint16_t DR17;
  uint16_t  RESERVED20;
  volatile uint16_t DR18;
  uint16_t  RESERVED21;
  volatile uint16_t DR19;
  uint16_t  RESERVED22;
  volatile uint16_t DR20;
  uint16_t  RESERVED23;
  volatile uint16_t DR21;
  uint16_t  RESERVED24;
  volatile uint16_t DR22;
  uint16_t  RESERVED25;
  volatile uint16_t DR23;
  uint16_t  RESERVED26;
  volatile uint16_t DR24;
  uint16_t  RESERVED27;
  volatile uint16_t DR25;
  uint16_t  RESERVED28;
  volatile uint16_t DR26;
  uint16_t  RESERVED29;
  volatile uint16_t DR27;
  uint16_t  RESERVED30;
  volatile uint16_t DR28;
  uint16_t  RESERVED31;
  volatile uint16_t DR29;
  uint16_t  RESERVED32;
  volatile uint16_t DR30;
  uint16_t  RESERVED33; 
  volatile uint16_t DR31;
  uint16_t  RESERVED34;
  volatile uint16_t DR32;
  uint16_t  RESERVED35;
  volatile uint16_t DR33;
  uint16_t  RESERVED36;
  volatile uint16_t DR34;
  uint16_t  RESERVED37;
  volatile uint16_t DR35;
  uint16_t  RESERVED38;
  volatile uint16_t DR36;
  uint16_t  RESERVED39;
  volatile uint16_t DR37;
  uint16_t  RESERVED40;
  volatile uint16_t DR38;
  uint16_t  RESERVED41;
  volatile uint16_t DR39;
  uint16_t  RESERVED42;
  volatile uint16_t DR40;
  uint16_t  RESERVED43;
  volatile uint16_t DR41;
  uint16_t  RESERVED44;
  volatile uint16_t DR42;
  uint16_t  RESERVED45;    
} BKP_TypeDef;



 

typedef struct
{
  volatile uint32_t TIR;
  volatile uint32_t TDTR;
  volatile uint32_t TDLR;
  volatile uint32_t TDHR;
} CAN_TxMailBox_TypeDef;



 
  
typedef struct
{
  volatile uint32_t RIR;
  volatile uint32_t RDTR;
  volatile uint32_t RDLR;
  volatile uint32_t RDHR;
} CAN_FIFOMailBox_TypeDef;



 
  
typedef struct
{
  volatile uint32_t FR1;
  volatile uint32_t FR2;
} CAN_FilterRegister_TypeDef;



 
  
typedef struct
{
  volatile uint32_t MCR;
  volatile uint32_t MSR;
  volatile uint32_t TSR;
  volatile uint32_t RF0R;
  volatile uint32_t RF1R;
  volatile uint32_t IER;
  volatile uint32_t ESR;
  volatile uint32_t BTR;
  uint32_t  RESERVED0[88];
  CAN_TxMailBox_TypeDef sTxMailBox[3];
  CAN_FIFOMailBox_TypeDef sFIFOMailBox[2];
  uint32_t  RESERVED1[12];
  volatile uint32_t FMR;
  volatile uint32_t FM1R;
  uint32_t  RESERVED2;
  volatile uint32_t FS1R;
  uint32_t  RESERVED3;
  volatile uint32_t FFA1R;
  uint32_t  RESERVED4;
  volatile uint32_t FA1R;
  uint32_t  RESERVED5[8];



  CAN_FilterRegister_TypeDef sFilterRegister[28];

} CAN_TypeDef;



 

typedef struct
{
  volatile uint32_t DR;
  volatile uint8_t  IDR;
  uint8_t   RESERVED0;
  uint16_t  RESERVED1;
  volatile uint32_t CR;
} CRC_TypeDef;



 

typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t SWTRIGR;
  volatile uint32_t DHR12R1;
  volatile uint32_t DHR12L1;
  volatile uint32_t DHR8R1;
  volatile uint32_t DHR12R2;
  volatile uint32_t DHR12L2;
  volatile uint32_t DHR8R2;
  volatile uint32_t DHR12RD;
  volatile uint32_t DHR12LD;
  volatile uint32_t DHR8RD;
  volatile uint32_t DOR1;
  volatile uint32_t DOR2;
} DAC_TypeDef;



 

typedef struct
{
  volatile uint32_t IDCODE;
  volatile uint32_t CR;	
}DBGMCU_TypeDef;



 

typedef struct
{
  volatile uint32_t CCR;
  volatile uint32_t CNDTR;
  volatile uint32_t CPAR;
  volatile uint32_t CMAR;
} DMA_Channel_TypeDef;

typedef struct
{
  volatile uint32_t ISR;
  volatile uint32_t IFCR;
} DMA_TypeDef;



 

typedef struct
{
  volatile uint32_t MACCR;
  volatile uint32_t MACFFR;
  volatile uint32_t MACHTHR;
  volatile uint32_t MACHTLR;
  volatile uint32_t MACMIIAR;
  volatile uint32_t MACMIIDR;
  volatile uint32_t MACFCR;
  volatile uint32_t MACVLANTR;              
       uint32_t RESERVED0[2];
  volatile uint32_t MACRWUFFR;              
  volatile uint32_t MACPMTCSR;
       uint32_t RESERVED1[2];
  volatile uint32_t MACSR;                  
  volatile uint32_t MACIMR;
  volatile uint32_t MACA0HR;
  volatile uint32_t MACA0LR;
  volatile uint32_t MACA1HR;
  volatile uint32_t MACA1LR;
  volatile uint32_t MACA2HR;
  volatile uint32_t MACA2LR;
  volatile uint32_t MACA3HR;
  volatile uint32_t MACA3LR;                
       uint32_t RESERVED2[40];
  volatile uint32_t MMCCR;                  
  volatile uint32_t MMCRIR;
  volatile uint32_t MMCTIR;
  volatile uint32_t MMCRIMR;
  volatile uint32_t MMCTIMR;                
       uint32_t RESERVED3[14];
  volatile uint32_t MMCTGFSCCR;             
  volatile uint32_t MMCTGFMSCCR;
       uint32_t RESERVED4[5];
  volatile uint32_t MMCTGFCR;
       uint32_t RESERVED5[10];
  volatile uint32_t MMCRFCECR;
  volatile uint32_t MMCRFAECR;
       uint32_t RESERVED6[10];
  volatile uint32_t MMCRGUFCR;
       uint32_t RESERVED7[334];
  volatile uint32_t PTPTSCR;
  volatile uint32_t PTPSSIR;
  volatile uint32_t PTPTSHR;
  volatile uint32_t PTPTSLR;
  volatile uint32_t PTPTSHUR;
  volatile uint32_t PTPTSLUR;
  volatile uint32_t PTPTSAR;
  volatile uint32_t PTPTTHR;
  volatile uint32_t PTPTTLR;
       uint32_t RESERVED8[567];
  volatile uint32_t DMABMR;
  volatile uint32_t DMATPDR;
  volatile uint32_t DMARPDR;
  volatile uint32_t DMARDLAR;
  volatile uint32_t DMATDLAR;
  volatile uint32_t DMASR;
  volatile uint32_t DMAOMR;
  volatile uint32_t DMAIER;
  volatile uint32_t DMAMFBOCR;
       uint32_t RESERVED9[9];
  volatile uint32_t DMACHTDR;
  volatile uint32_t DMACHRDR;
  volatile uint32_t DMACHTBAR;
  volatile uint32_t DMACHRBAR;
} ETH_TypeDef;



 

typedef struct
{
  volatile uint32_t IMR;
  volatile uint32_t EMR;
  volatile uint32_t RTSR;
  volatile uint32_t FTSR;
  volatile uint32_t SWIER;
  volatile uint32_t PR;
} EXTI_TypeDef;



 

typedef struct
{
  volatile uint32_t ACR;
  volatile uint32_t KEYR;
  volatile uint32_t OPTKEYR;
  volatile uint32_t SR;
  volatile uint32_t CR;
  volatile uint32_t AR;
  volatile uint32_t RESERVED;
  volatile uint32_t OBR;
  volatile uint32_t WRPR;
} FLASH_TypeDef;



 
  
typedef struct
{
  volatile uint16_t RDP;
  volatile uint16_t USER;
  volatile uint16_t Data0;
  volatile uint16_t Data1;
  volatile uint16_t WRP0;
  volatile uint16_t WRP1;
  volatile uint16_t WRP2;
  volatile uint16_t WRP3;
} OB_TypeDef;



 

typedef struct
{
  volatile uint32_t BTCR[8];   
} FSMC_Bank1_TypeDef; 



 
  
typedef struct
{
  volatile uint32_t BWTR[7];
} FSMC_Bank1E_TypeDef;



 
  
typedef struct
{
  volatile uint32_t PCR2;
  volatile uint32_t SR2;
  volatile uint32_t PMEM2;
  volatile uint32_t PATT2;
  uint32_t  RESERVED0;   
  volatile uint32_t ECCR2; 
} FSMC_Bank2_TypeDef;  



 
  
typedef struct
{
  volatile uint32_t PCR3;
  volatile uint32_t SR3;
  volatile uint32_t PMEM3;
  volatile uint32_t PATT3;
  uint32_t  RESERVED0;   
  volatile uint32_t ECCR3; 
} FSMC_Bank3_TypeDef; 



 
  
typedef struct
{
  volatile uint32_t PCR4;
  volatile uint32_t SR4;
  volatile uint32_t PMEM4;
  volatile uint32_t PATT4;
  volatile uint32_t PIO4; 
} FSMC_Bank4_TypeDef; 



 

typedef struct
{
  volatile uint32_t CRL;
  volatile uint32_t CRH;
  volatile uint32_t IDR;
  volatile uint32_t ODR;
  volatile uint32_t BSRR;
  volatile uint32_t BRR;
  volatile uint32_t LCKR;
} GPIO_TypeDef;



 

typedef struct
{
  volatile uint32_t EVCR;
  volatile uint32_t MAPR;
  volatile uint32_t EXTICR[4];
} AFIO_TypeDef;


 

typedef struct
{
  volatile uint16_t CR1;
  uint16_t  RESERVED0;
  volatile uint16_t CR2;
  uint16_t  RESERVED1;
  volatile uint16_t OAR1;
  uint16_t  RESERVED2;
  volatile uint16_t OAR2;
  uint16_t  RESERVED3;
  volatile uint16_t DR;
  uint16_t  RESERVED4;
  volatile uint16_t SR1;
  uint16_t  RESERVED5;
  volatile uint16_t SR2;
  uint16_t  RESERVED6;
  volatile uint16_t CCR;
  uint16_t  RESERVED7;
  volatile uint16_t TRISE;
  uint16_t  RESERVED8;
} I2C_TypeDef;



 

typedef struct
{
  volatile uint32_t KR;
  volatile uint32_t PR;
  volatile uint32_t RLR;
  volatile uint32_t SR;
} IWDG_TypeDef;



 

typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t CSR;
} PWR_TypeDef;



 

typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t CFGR;
  volatile uint32_t CIR;
  volatile uint32_t APB2RSTR;
  volatile uint32_t APB1RSTR;
  volatile uint32_t AHBENR;
  volatile uint32_t APB2ENR;
  volatile uint32_t APB1ENR;
  volatile uint32_t BDCR;
  volatile uint32_t CSR;

  volatile uint32_t AHBRSTR;
  volatile uint32_t CFGR2;

} RCC_TypeDef;



 

typedef struct
{
  volatile uint16_t CRH;
  uint16_t  RESERVED0;
  volatile uint16_t CRL;
  uint16_t  RESERVED1;
  volatile uint16_t PRLH;
  uint16_t  RESERVED2;
  volatile uint16_t PRLL;
  uint16_t  RESERVED3;
  volatile uint16_t DIVH;
  uint16_t  RESERVED4;
  volatile uint16_t DIVL;
  uint16_t  RESERVED5;
  volatile uint16_t CNTH;
  uint16_t  RESERVED6;
  volatile uint16_t CNTL;
  uint16_t  RESERVED7;
  volatile uint16_t ALRH;
  uint16_t  RESERVED8;
  volatile uint16_t ALRL;
  uint16_t  RESERVED9;
} RTC_TypeDef;



 

typedef struct
{
  volatile uint32_t POWER;
  volatile uint32_t CLKCR;
  volatile uint32_t ARG;
  volatile uint32_t CMD;
  volatile const uint32_t RESPCMD;
  volatile const uint32_t RESP1;
  volatile const uint32_t RESP2;
  volatile const uint32_t RESP3;
  volatile const uint32_t RESP4;
  volatile uint32_t DTIMER;
  volatile uint32_t DLEN;
  volatile uint32_t DCTRL;
  volatile const uint32_t DCOUNT;
  volatile const uint32_t STA;
  volatile uint32_t ICR;
  volatile uint32_t MASK;
  uint32_t  RESERVED0[2];
  volatile const uint32_t FIFOCNT;
  uint32_t  RESERVED1[13];
  volatile uint32_t FIFO;
} SDIO_TypeDef;



 

typedef struct
{
  volatile uint16_t CR1;
  uint16_t  RESERVED0;
  volatile uint16_t CR2;
  uint16_t  RESERVED1;
  volatile uint16_t SR;
  uint16_t  RESERVED2;
  volatile uint16_t DR;
  uint16_t  RESERVED3;
  volatile uint16_t CRCPR;
  uint16_t  RESERVED4;
  volatile uint16_t RXCRCR;
  uint16_t  RESERVED5;
  volatile uint16_t TXCRCR;
  uint16_t  RESERVED6;
  volatile uint16_t I2SCFGR;
  uint16_t  RESERVED7;
  volatile uint16_t I2SPR;
  uint16_t  RESERVED8;  
} SPI_TypeDef;



 

typedef struct
{
  volatile uint16_t CR1;
  uint16_t  RESERVED0;
  volatile uint16_t CR2;
  uint16_t  RESERVED1;
  volatile uint16_t SMCR;
  uint16_t  RESERVED2;
  volatile uint16_t DIER;
  uint16_t  RESERVED3;
  volatile uint16_t SR;
  uint16_t  RESERVED4;
  volatile uint16_t EGR;
  uint16_t  RESERVED5;
  volatile uint16_t CCMR1;
  uint16_t  RESERVED6;
  volatile uint16_t CCMR2;
  uint16_t  RESERVED7;
  volatile uint16_t CCER;
  uint16_t  RESERVED8;
  volatile uint16_t CNT;
  uint16_t  RESERVED9;
  volatile uint16_t PSC;
  uint16_t  RESERVED10;
  volatile uint16_t ARR;
  uint16_t  RESERVED11;
  volatile uint16_t RCR;
  uint16_t  RESERVED12;
  volatile uint16_t CCR1;
  uint16_t  RESERVED13;
  volatile uint16_t CCR2;
  uint16_t  RESERVED14;
  volatile uint16_t CCR3;
  uint16_t  RESERVED15;
  volatile uint16_t CCR4;
  uint16_t  RESERVED16;
  volatile uint16_t BDTR;
  uint16_t  RESERVED17;
  volatile uint16_t DCR;
  uint16_t  RESERVED18;
  volatile uint16_t DMAR;
  uint16_t  RESERVED19;
} TIM_TypeDef;



 
 
typedef struct
{
  volatile uint16_t SR;
  uint16_t  RESERVED0;
  volatile uint16_t DR;
  uint16_t  RESERVED1;
  volatile uint16_t BRR;
  uint16_t  RESERVED2;
  volatile uint16_t CR1;
  uint16_t  RESERVED3;
  volatile uint16_t CR2;
  uint16_t  RESERVED4;
  volatile uint16_t CR3;
  uint16_t  RESERVED5;
  volatile uint16_t GTPR;
  uint16_t  RESERVED6;
} USART_TypeDef;



 

typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t CFR;
  volatile uint32_t SR;
} WWDG_TypeDef;



 
  


 









 




#line 1098 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

#line 1115 "..\\STM32F10x_lib\\inc\\stm32f10x.h"



#line 1134 "..\\STM32F10x_lib\\inc\\stm32f10x.h"




















 
  


   

#line 1224 "..\\STM32F10x_lib\\inc\\stm32f10x.h"



 



 
  
  

 
    
 
 
 

 
 
 
 
 

 



 



 


 
 
 
 
 

 











 
#line 1285 "..\\STM32F10x_lib\\inc\\stm32f10x.h"




 





 
 
 
 
 

 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 





 



 






 
 
 
 
 

 
#line 1461 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

#line 1468 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
 








 








 






#line 1504 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 











 











 













 













#line 1564 "..\\STM32F10x_lib\\inc\\stm32f10x.h"
 

 
 






#line 1619 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 1638 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

#line 1647 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 1659 "..\\STM32F10x_lib\\inc\\stm32f10x.h"





#line 1670 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 1680 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

#line 1687 "..\\STM32F10x_lib\\inc\\stm32f10x.h"





#line 1701 "..\\STM32F10x_lib\\inc\\stm32f10x.h"





 














#line 1727 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 1739 "..\\STM32F10x_lib\\inc\\stm32f10x.h"





#line 1750 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 1760 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

#line 1767 "..\\STM32F10x_lib\\inc\\stm32f10x.h"





#line 1781 "..\\STM32F10x_lib\\inc\\stm32f10x.h"





 








 








   
#line 1814 "..\\STM32F10x_lib\\inc\\stm32f10x.h"


 



 
 






#line 1844 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 






#line 1868 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 






#line 1885 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 






#line 1902 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

#line 1909 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
 
 
 
 

 




































































 




































































 
#line 2071 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 2089 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 2107 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

#line 2124 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 2142 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 2161 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 

 






 
#line 2188 "..\\STM32F10x_lib\\inc\\stm32f10x.h"






 








 









 








 








 









 










 




#line 2263 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 











 


 


 


 


 


 



 





 
#line 2309 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 2318 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

   
#line 2327 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 2336 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 





 
#line 2351 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 2360 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

   
#line 2369 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 2378 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 





 
#line 2393 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 2402 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

   
#line 2411 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 2420 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 





 
#line 2435 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 2444 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

   
#line 2453 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 2462 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
 
 
 
 

 





 


 


 




 
 
 
 
 

 
#line 2526 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 2561 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 2596 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 2631 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 2666 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 





 





 





 





 





 





 





 





 






 
#line 2733 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 



 









 
#line 2757 "..\\STM32F10x_lib\\inc\\stm32f10x.h"




 




 
#line 2773 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 





 
#line 2795 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
 





 
#line 2810 "..\\STM32F10x_lib\\inc\\stm32f10x.h"
 
#line 2817 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 




 






 


 


 


 
 
 
 
 

 
#line 2866 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 2888 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 2910 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 2932 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 2954 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 2976 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
 
 
 
 

 
#line 3012 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 3042 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 3052 "..\\STM32F10x_lib\\inc\\stm32f10x.h"















 
#line 3076 "..\\STM32F10x_lib\\inc\\stm32f10x.h"















 
#line 3100 "..\\STM32F10x_lib\\inc\\stm32f10x.h"















 
#line 3124 "..\\STM32F10x_lib\\inc\\stm32f10x.h"















 
#line 3148 "..\\STM32F10x_lib\\inc\\stm32f10x.h"















 
#line 3172 "..\\STM32F10x_lib\\inc\\stm32f10x.h"















 
#line 3196 "..\\STM32F10x_lib\\inc\\stm32f10x.h"















 


 


 


 


 


 


 


 


 


 



 


 


 



 


 


 


 



 


 


 


 


 
 
 
 
 

 






 
#line 3297 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

#line 3306 "..\\STM32F10x_lib\\inc\\stm32f10x.h"















  
 
#line 3329 "..\\STM32F10x_lib\\inc\\stm32f10x.h"


















 








































 


















































 


 


 


 


 


 


 
#line 3464 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

#line 3471 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

#line 3478 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

#line 3485 "..\\STM32F10x_lib\\inc\\stm32f10x.h"







 
#line 3499 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

#line 3506 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

#line 3513 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

#line 3520 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

#line 3527 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

#line 3534 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 3542 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

#line 3549 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

#line 3556 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

#line 3563 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

#line 3570 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

#line 3577 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 3585 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

#line 3592 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

#line 3599 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

#line 3606 "..\\STM32F10x_lib\\inc\\stm32f10x.h"





 


 


 


 


 



 
 
 
 
 

 









































 



 


 


 


 


 


 


 



 



 



 


 


 
 
 
 
 

 
















 









#line 3756 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 

























 
#line 3799 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 3813 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 3823 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 




























 





















 




























 





















 
#line 3941 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 


 


 


 


 


 


 


 


 
#line 3976 "..\\STM32F10x_lib\\inc\\stm32f10x.h"





#line 3987 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 3995 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

#line 4002 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 


 
 
 
 
 

 




 
#line 4024 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 


 


 


 


 


 


 


 


 
 
 
 
 

 


 





 


 



 
 
 
 
 

 
#line 4086 "..\\STM32F10x_lib\\inc\\stm32f10x.h"



 
#line 4098 "..\\STM32F10x_lib\\inc\\stm32f10x.h"







 


 
 
 
 
 

 











#line 4135 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 











#line 4157 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 











#line 4179 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 











#line 4201 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 








































 








































 








































 








































 


































 


































 


































 


































 



























 



























 



























 
#line 4598 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 4607 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 4616 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 4627 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

#line 4637 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

#line 4647 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

#line 4657 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 4668 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

#line 4678 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

#line 4688 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

#line 4698 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 4709 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

#line 4719 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

#line 4729 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

#line 4739 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 4750 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

#line 4760 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

#line 4770 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

#line 4780 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 4791 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

#line 4801 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

#line 4811 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

#line 4821 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 4832 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

#line 4842 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

#line 4852 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

#line 4862 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 4873 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

#line 4883 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

#line 4893 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

#line 4903 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 


 


 
 
 
 
 

 




 












 


 






#line 4951 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 


 


 


 


 


 


 


 


 
















 


 
#line 5021 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 5036 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 5062 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 


 


 
 
 
 
 

 
 























 























 























 























 























 























 























 























 
 
#line 5283 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 5295 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 






 
#line 5312 "..\\STM32F10x_lib\\inc\\stm32f10x.h"



     


 
 


 


 


 


 


 


 


 


 

 


 


 


 


 


 


 


 


 

 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 

 


 


 


 


 


 


 


 


 

 


#line 5456 "..\\STM32F10x_lib\\inc\\stm32f10x.h"



 


#line 5468 "..\\STM32F10x_lib\\inc\\stm32f10x.h"



 


#line 5480 "..\\STM32F10x_lib\\inc\\stm32f10x.h"



 


#line 5492 "..\\STM32F10x_lib\\inc\\stm32f10x.h"



 


#line 5504 "..\\STM32F10x_lib\\inc\\stm32f10x.h"



 


#line 5516 "..\\STM32F10x_lib\\inc\\stm32f10x.h"



 


#line 5528 "..\\STM32F10x_lib\\inc\\stm32f10x.h"



 


#line 5540 "..\\STM32F10x_lib\\inc\\stm32f10x.h"



 

 


#line 5554 "..\\STM32F10x_lib\\inc\\stm32f10x.h"



 


#line 5566 "..\\STM32F10x_lib\\inc\\stm32f10x.h"



 


#line 5578 "..\\STM32F10x_lib\\inc\\stm32f10x.h"



 


#line 5590 "..\\STM32F10x_lib\\inc\\stm32f10x.h"



 


#line 5602 "..\\STM32F10x_lib\\inc\\stm32f10x.h"



 


#line 5614 "..\\STM32F10x_lib\\inc\\stm32f10x.h"



 


#line 5626 "..\\STM32F10x_lib\\inc\\stm32f10x.h"



 


#line 5638 "..\\STM32F10x_lib\\inc\\stm32f10x.h"



 


#line 5650 "..\\STM32F10x_lib\\inc\\stm32f10x.h"



 


#line 5662 "..\\STM32F10x_lib\\inc\\stm32f10x.h"



 


#line 5674 "..\\STM32F10x_lib\\inc\\stm32f10x.h"



 


#line 5686 "..\\STM32F10x_lib\\inc\\stm32f10x.h"



 


#line 5698 "..\\STM32F10x_lib\\inc\\stm32f10x.h"



 


#line 5710 "..\\STM32F10x_lib\\inc\\stm32f10x.h"



 


#line 5722 "..\\STM32F10x_lib\\inc\\stm32f10x.h"



 


#line 5734 "..\\STM32F10x_lib\\inc\\stm32f10x.h"



 
 
 
 
 

 
 
#line 5754 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 5765 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 5783 "..\\STM32F10x_lib\\inc\\stm32f10x.h"











 





 





 
#line 5821 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 












 
#line 5842 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
 






 




 





 





 






 




 





 





 






   




 





 





 





 




 





 





 





 




 





 





 
 


 
#line 5982 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 5999 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 6016 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 6033 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 6067 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 6101 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 6135 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 6169 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 6203 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 6237 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 6271 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 6305 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 6339 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 6373 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 6407 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 6441 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 6475 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 6509 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 6543 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 6577 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 6611 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 6645 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 6679 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 6713 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 6747 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 6781 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 6815 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 6849 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 6883 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 6917 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 6951 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 6985 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
 
 
 
 

 









#line 7012 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 7020 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 7030 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 


 


 


 


 





















 




 
 
 
 
 

 
#line 7091 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 7100 "..\\STM32F10x_lib\\inc\\stm32f10x.h"







 



#line 7121 "..\\STM32F10x_lib\\inc\\stm32f10x.h"



 



 


 
#line 7146 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 7156 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 




 


 
 
 
 
 

 
#line 7182 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 


 



 
#line 7205 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 7214 "..\\STM32F10x_lib\\inc\\stm32f10x.h"







 
#line 7233 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 7244 "..\\STM32F10x_lib\\inc\\stm32f10x.h"



 
 
 
 
 

 


#line 7273 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 









#line 7298 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
 
 
 
 

 









 


 


 





 
#line 7338 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 


 









 


 

 



 



 



 



 



 



 



 




 
 
 
 
#line 7422 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 7438 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 


 


 
#line 7454 "..\\STM32F10x_lib\\inc\\stm32f10x.h"
  
 


 
#line 7470 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 



  


 








 

  
#line 7497 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 






 



 


 


 
#line 7526 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 


 
#line 7541 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 


 
#line 7556 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 


 
 
 

 





 




 




 




 




 


 


 


 


 


 


 
 
 

 
#line 7619 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 


 


 



 


 



 


 


 


 
 
 

 
#line 7689 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 


 


 


 


 




   
#line 7740 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 7766 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 
#line 7783 "..\\STM32F10x_lib\\inc\\stm32f10x.h"

 





 


 


 


 





 

 

  







 

















 









 

  

 

 
#line 32 "..\\target\\stm32f10x_it.h"

 
 
 
 

void NMI_Handler(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void SVC_Handler(void);
void DebugMon_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);







 
#line 28 "..\\target\\stm32f10x_it.c"
#line 1 "C:\\Keil\\ARM\\RV31\\INC\\stdio.h"
 
 
 





 






 









#line 34 "C:\\Keil\\ARM\\RV31\\INC\\stdio.h"


  
  typedef unsigned int size_t;    








 
 

 
  typedef struct __va_list __va_list;





   




 




typedef struct __fpos_t_struct {
    unsigned __int64 __pos;
    



 
    struct {
        unsigned int __state1, __state2;
    } __mbstate;
} fpos_t;
   


 


   

 

typedef struct __FILE FILE;
   






 

extern FILE __stdin, __stdout, __stderr;
extern FILE *__aeabi_stdin, *__aeabi_stdout, *__aeabi_stderr;

#line 125 "C:\\Keil\\ARM\\RV31\\INC\\stdio.h"
    

    

    





     



   


 


   


 

   



 

   


 




   


 





    


 






extern __declspec(__nothrow) int remove(const char *  ) __attribute__((__nonnull__(1)));
   





 
extern __declspec(__nothrow) int rename(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   








 
extern __declspec(__nothrow) FILE *tmpfile(void);
   




 
extern __declspec(__nothrow) char *tmpnam(char *  );
   











 

extern __declspec(__nothrow) int fclose(FILE *  ) __attribute__((__nonnull__(1)));
   







 
extern __declspec(__nothrow) int fflush(FILE *  );
   







 
extern __declspec(__nothrow) FILE *fopen(const char * __restrict  ,
                           const char * __restrict  ) __attribute__((__nonnull__(1,2)));
   








































 
extern __declspec(__nothrow) FILE *freopen(const char * __restrict  ,
                    const char * __restrict  ,
                    FILE * __restrict  ) __attribute__((__nonnull__(2,3)));
   








 
extern __declspec(__nothrow) void setbuf(FILE * __restrict  ,
                    char * __restrict  ) __attribute__((__nonnull__(1)));
   




 
extern __declspec(__nothrow) int setvbuf(FILE * __restrict  ,
                   char * __restrict  ,
                   int  , size_t  ) __attribute__((__nonnull__(1)));
   















 
#pragma __printf_args
extern __declspec(__nothrow) int fprintf(FILE * __restrict  ,
                    const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   


















 
#pragma __printf_args
extern __declspec(__nothrow) int _fprintf(FILE * __restrict  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 
#pragma __printf_args
extern __declspec(__nothrow) int printf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   




 
#pragma __printf_args
extern __declspec(__nothrow) int _printf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   



 
#pragma __printf_args
extern __declspec(__nothrow) int sprintf(char * __restrict  , const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   






 
#pragma __printf_args
extern __declspec(__nothrow) int _sprintf(char * __restrict  , const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 

#pragma __printf_args
extern __declspec(__nothrow) int snprintf(char * __restrict  , size_t  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(3)));
   















 

#pragma __printf_args
extern __declspec(__nothrow) int _snprintf(char * __restrict  , size_t  ,
                      const char * __restrict  , ...) __attribute__((__nonnull__(3)));
   



 
#pragma __scanf_args
extern __declspec(__nothrow) int fscanf(FILE * __restrict  ,
                    const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   






























 
#pragma __scanf_args
extern __declspec(__nothrow) int _fscanf(FILE * __restrict  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 
#pragma __scanf_args
extern __declspec(__nothrow) int scanf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   






 
#pragma __scanf_args
extern __declspec(__nothrow) int _scanf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   



 
#pragma __scanf_args
extern __declspec(__nothrow) int sscanf(const char * __restrict  ,
                    const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   








 
#pragma __scanf_args
extern __declspec(__nothrow) int _sscanf(const char * __restrict  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 

 
extern __declspec(__nothrow) int vfscanf(FILE * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) int vscanf(const char * __restrict  , __va_list) __attribute__((__nonnull__(1)));
extern __declspec(__nothrow) int vsscanf(const char * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));

extern __declspec(__nothrow) int _vfscanf(FILE * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) int _vscanf(const char * __restrict  , __va_list) __attribute__((__nonnull__(1)));
extern __declspec(__nothrow) int _vsscanf(const char * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));

extern __declspec(__nothrow) int vprintf(const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1)));
   





 
extern __declspec(__nothrow) int _vprintf(const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) int vfprintf(FILE * __restrict  ,
                    const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   






 
extern __declspec(__nothrow) int vsprintf(char * __restrict  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   






 

extern __declspec(__nothrow) int vsnprintf(char * __restrict  , size_t  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(3)));
   







 

extern __declspec(__nothrow) int _vsprintf(char * __restrict  ,
                      const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   



 
extern __declspec(__nothrow) int _vfprintf(FILE * __restrict  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   



 
extern __declspec(__nothrow) int _vsnprintf(char * __restrict  , size_t  ,
                      const char * __restrict  , __va_list  ) __attribute__((__nonnull__(3)));
   



 
extern __declspec(__nothrow) int fgetc(FILE *  ) __attribute__((__nonnull__(1)));
   







 
extern __declspec(__nothrow) char *fgets(char * __restrict  , int  ,
                    FILE * __restrict  ) __attribute__((__nonnull__(1,3)));
   










 
extern __declspec(__nothrow) int fputc(int  , FILE *  ) __attribute__((__nonnull__(2)));
   







 
extern __declspec(__nothrow) int fputs(const char * __restrict  , FILE * __restrict  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) int getc(FILE *  ) __attribute__((__nonnull__(1)));
   







 




    extern __declspec(__nothrow) int (getchar)(void);

   





 
extern __declspec(__nothrow) char *gets(char *  ) __attribute__((__nonnull__(1)));
   









 
extern __declspec(__nothrow) int putc(int  , FILE *  ) __attribute__((__nonnull__(2)));
   





 




    extern __declspec(__nothrow) int (putchar)(int  );

   



 
extern __declspec(__nothrow) int puts(const char *  ) __attribute__((__nonnull__(1)));
   





 
extern __declspec(__nothrow) int ungetc(int  , FILE *  ) __attribute__((__nonnull__(2)));
   






















 

extern __declspec(__nothrow) size_t fread(void * __restrict  ,
                    size_t  , size_t  , FILE * __restrict  ) __attribute__((__nonnull__(1,4)));
   











 

extern __declspec(__nothrow) size_t __fread_bytes_avail(void * __restrict  ,
                    size_t  , FILE * __restrict  ) __attribute__((__nonnull__(1,3)));
   











 

extern __declspec(__nothrow) size_t fwrite(const void * __restrict  ,
                    size_t  , size_t  , FILE * __restrict  ) __attribute__((__nonnull__(1,4)));
   







 

extern __declspec(__nothrow) int fgetpos(FILE * __restrict  , fpos_t * __restrict  ) __attribute__((__nonnull__(1,2)));
   








 
extern __declspec(__nothrow) int fseek(FILE *  , long int  , int  ) __attribute__((__nonnull__(1)));
   














 
extern __declspec(__nothrow) int fsetpos(FILE * __restrict  , const fpos_t * __restrict  ) __attribute__((__nonnull__(1,2)));
   










 
extern __declspec(__nothrow) long int ftell(FILE *  ) __attribute__((__nonnull__(1)));
   











 
extern __declspec(__nothrow) void rewind(FILE *  ) __attribute__((__nonnull__(1)));
   





 

extern __declspec(__nothrow) void clearerr(FILE *  ) __attribute__((__nonnull__(1)));
   




 

extern __declspec(__nothrow) int feof(FILE *  ) __attribute__((__nonnull__(1)));
   


 
extern __declspec(__nothrow) int ferror(FILE *  ) __attribute__((__nonnull__(1)));
   


 
extern __declspec(__nothrow) void perror(const char *  );
   









 

extern __declspec(__nothrow) int _fisatty(FILE *   ) __attribute__((__nonnull__(1)));
    
 

extern __declspec(__nothrow) void __use_no_semihosting_swi(void);
extern __declspec(__nothrow) void __use_no_semihosting(void);
    





 











#line 944 "C:\\Keil\\ARM\\RV31\\INC\\stdio.h"



 
#line 29 "..\\target\\stm32f10x_it.c"

 
 
 
   
 
 







 
void NMIException(void)
{
}







 
void HardFaultException(void)
{
	printf("Hard Error!\n");
	while(1);
}







 
void MemManageException(void)
{
}







 
void BusFaultException(void)
{
}







 
void UsageFaultException(void)
{
}







 
void DebugMonitor(void)
{
}







 
void SVCHandler(void)
{
}







 
void PendSVC(void)
{
}







 
void SysTickHandler(void)
{
}







 
void WWDG_IRQHandler(void)
{
}







 
void PVD_IRQHandler(void)
{
}







 
void TAMPER_IRQHandler(void)
{
}







 
void RTC_IRQHandler(void)
{
}







 
void FLASH_IRQHandler(void)
{
}







 
void RCC_IRQHandler(void)
{
}







 
void EXTI0_IRQHandler(void)
{
}







 
void EXTI1_IRQHandler(void)
{
}







 
void EXTI2_IRQHandler(void)
{
}







 
void EXTI3_IRQHandler(void)
{
}







 
void EXTI4_IRQHandler(void)
{
}







 
void DMAChannel1_IRQHandler(void)
{
}







 
void DMAChannel2_IRQHandler(void)
{
}







 
void DMAChannel3_IRQHandler(void)
{
}







 
void DMAChannel4_IRQHandler(void)
{
}







 
void DMAChannel5_IRQHandler(void)
{
}







 
void DMAChannel6_IRQHandler(void)
{
}







 
void DMAChannel7_IRQHandler(void)
{
}







 
void ADC_IRQHandler(void)
{
}








 
void USB_HP_CAN_TX_IRQHandler(void)
{
}








 
void USB_LP_CAN_RX0_IRQHandler(void)
{
}







 
void CAN_RX1_IRQHandler(void)
{
}







 
void CAN_SCE_IRQHandler(void)
{
}







 








 
void TIM1_BRK_IRQHandler(void)
{
}








 
void TIM1_UP_IRQHandler(void)
{
}








 
void TIM1_TRG_COM_IRQHandler(void)
{
}







 
void TIM1_CC_IRQHandler(void)
{
}







 
void timer2_int(void);
void TIM2_IRQHandler(void)
{
	timer2_int();
}







 
void TIM3_IRQHandler(void)
{
}







 
void TIM4_IRQHandler(void)
{
}







 
void I2C1_EV_IRQHandler(void)
{
}







 
void I2C1_ER_IRQHandler(void)
{
}







 
void I2C2_EV_IRQHandler(void)
{
}







 
void I2C2_ER_IRQHandler(void)
{
}







 
void SPI1_IRQHandler(void)
{
}







 
void SPI2_IRQHandler(void)
{
}







 
void USART1_IRQHandler(void)
{
}







 
void USART2_IRQHandler(void)
{
}







 
void USART3_IRQHandler(void)
{
}







 








 
void RTCAlarm_IRQHandler(void)
{
}







 
void USBWakeUp_IRQHandler(void)
{
}








 
void TIM8_BRK_IRQHander(void)
{

} 






 
void TIM8_UP_IRQHander(void)
{


} 






 
void TIM8_TRG_COM_IRQHander(void)
{

}






       
void TIM8_CC_IRQHander(void)
{

}  






                
void ADC3_IRQHander(void)
{

} 






                             
void FSMC_IRQHander(void)
{
}  







 
void stm32_irq(void);
void SDIO_IRQHander(void)
{ 
	stm32_irq();
}
 





              
void TIM5_IRQHander(void)
{

}
 





                            
void SPI3_IRQHander(void)
{
} 
 





                                         
void UART4_IRQHander(void)
{
} 
 





                                         
            
void UART5_IRQHander(void)
{
}  
 





                                                    
void TIM6_IRQHander(void)
{
} 
 





                                                    
void TIM7_IRQHander(void)
{

}
 





                                                                  
void DMA2_Channel1_IRQHander(void)
{
} 
 





                                                                  
    
void DMA2_Channel2_IRQHander(void)
{
}
 





                                                                  
     
void DMA2_Channel3_IRQHander(void)
{
} 
 





                                                                  
    
void DMA2_Channel4_5_IRQHander(void)
{
}   

#line 823 "..\\target\\stm32f10x_it.c"

#line 1 "..\\main\\config.h"










#line 825 "..\\target\\stm32f10x_it.c"
#line 970 "..\\target\\stm32f10x_it.c"
void EXTI15_10_IRQHandler(void){}
void EXTI9_5_IRQHandler(void){}


 
