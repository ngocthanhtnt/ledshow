                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset
                AREA    CODE, READONLY


Save_Task_SP
   MOV R0,SP
   BX LR
  
Restore_Task_SP
   MOV SP,R0
   BX LR
   
   END