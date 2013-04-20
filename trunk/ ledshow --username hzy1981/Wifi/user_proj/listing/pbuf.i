#line 1 "..\\lwIP\\src\\core\\pbuf.c"





























 































 

#line 1 "..\\lwIP\\src\\include\\lwip/opt.h"




 































 






 
#line 1 "..\\lwIP\\port\\include\\lwipopts.h"




















 





 








 





 


 


 



 




 


 


 


 


 


 




 
 


 



 







 






 






 







 


 


 



 


 



 



 


 






 




 



 








 





 



#line 188 "..\\lwIP\\port\\include\\lwipopts.h"
   

   

   

   

   

   








 


 





 


 











 
#line 46 "..\\lwIP\\src\\include\\lwip/opt.h"
#line 1 "..\\lwIP\\src\\include\\lwip/debug.h"






























 



#line 1 "..\\lwIP\\src\\include\\lwip/arch.h"






























 











#line 1 "..\\lwIP\\port\\include\\arch/cc.h"






























 



#line 1 "..\\lwIP\\port\\include\\arch/cpu.h"






























 





#line 36 "..\\lwIP\\port\\include\\arch/cc.h"
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



 
#line 37 "..\\lwIP\\port\\include\\arch/cc.h"

 

typedef unsigned   char    u8_t;     
typedef signed     char    s8_t;     
typedef unsigned   short   u16_t;    
typedef signed     short   s16_t;    
typedef unsigned   long    u32_t;    
typedef signed     long    s32_t;    
typedef u32_t mem_ptr_t;             


 













 

 
#line 75 "..\\lwIP\\port\\include\\arch/cc.h"






#line 96 "..\\lwIP\\port\\include\\arch/cc.h"

 

#line 105 "..\\lwIP\\port\\include\\arch/cc.h"

 
#line 113 "..\\lwIP\\port\\include\\arch/cc.h"





#line 44 "..\\lwIP\\src\\include\\lwip/arch.h"

 




























#line 131 "..\\lwIP\\src\\include\\lwip/arch.h"







#line 156 "..\\lwIP\\src\\include\\lwip/arch.h"




#line 176 "..\\lwIP\\src\\include\\lwip/arch.h"










#line 198 "..\\lwIP\\src\\include\\lwip/arch.h"





#line 222 "..\\lwIP\\src\\include\\lwip/arch.h"


extern int errno;








#line 36 "..\\lwIP\\src\\include\\lwip/debug.h"






 






 



 


 

 

 

 





#line 74 "..\\lwIP\\src\\include\\lwip/debug.h"

 








 
#line 96 "..\\lwIP\\src\\include\\lwip/debug.h"







#line 47 "..\\lwIP\\src\\include\\lwip/opt.h"





 





 







 







 







 








 




 








 








 







 












 







 









 







 









 





















 








 




 







 








 







 







 







 







 









 









 







 







 







 








 








 






 








 


 






 







 











 








 




 








 








 








 








 









 








 







 






 








 







 








 



 






 






 






 








 


 






 








 


 















 








 


 







 










 








 



 







 







 






 








 








 


 








 



 




 




 




 




 






 




 













 





 








 


 






 






 








 


 






 







 






 






 







 










 











 







 







 








 






 








 






 







 










 
#line 872 "..\\lwIP\\src\\include\\lwip/opt.h"






 




 








 








 



 






 







 







 










 







 







 
















 












 








 


 








 


 








 


 








 








 








 






 








 








 






 








 








 






 








 








 








 








 








 








 








 



 






 








 


 







 








 








 






 






 






 






 








 


 




#line 1352 "..\\lwIP\\src\\include\\lwip/opt.h"

#line 1364 "..\\lwIP\\src\\include\\lwip/opt.h"







 


 






 






 




#line 1527 "..\\lwIP\\src\\include\\lwip/opt.h"





 


 



 


 



 


 



 


 



 


 






 








 




 







 






 






 






 






 






 






 






 






 






 






 






 






 






 






 






 






 






 






 







 






 






 






 






 






 






 






 






 






 






 






 






 






 






 




#line 65 "..\\lwIP\\src\\core\\pbuf.c"

#line 1 "..\\lwIP\\src\\include\\lwip/stats.h"






























 



#line 36 "..\\lwIP\\src\\include\\lwip/stats.h"

#line 1 "..\\lwIP\\src\\include\\lwip/mem.h"






























 



#line 36 "..\\lwIP\\src\\include\\lwip/mem.h"





#line 69 "..\\lwIP\\src\\include\\lwip/mem.h"



 



typedef u16_t mem_size_t;


#line 86 "..\\lwIP\\src\\include\\lwip/mem.h"
 
void  mem_init(void);
void *mem_realloc(void *mem, mem_size_t size);

void *mem_malloc(mem_size_t size);
void *mem_calloc(mem_size_t count, mem_size_t size);
void  mem_free(void *mem);














#line 38 "..\\lwIP\\src\\include\\lwip/stats.h"
#line 1 "..\\lwIP\\src\\include\\lwip/memp.h"






























 




#line 37 "..\\lwIP\\src\\include\\lwip/memp.h"





 
typedef enum {
#line 1 "..\\lwIP\\src\\include\\lwip/memp_std.h"










 


 







 









 

MEMP_RAW_PCB,



MEMP_UDP_PCB,



MEMP_TCP_PCB,
MEMP_TCP_PCB_LISTEN,
MEMP_TCP_SEG,



MEMP_REASSDATA,













MEMP_ARP_QUEUE,


















 
MEMP_PBUF,
MEMP_PBUF_POOL,





 







 
#line 46 "..\\lwIP\\src\\include\\lwip/memp.h"
  MEMP_MAX
} memp_t;

#line 77 "..\\lwIP\\src\\include\\lwip/memp.h"





#line 91 "..\\lwIP\\src\\include\\lwip/memp.h"

#line 99 "..\\lwIP\\src\\include\\lwip/memp.h"

void  memp_init(void);





void *memp_malloc(memp_t type);

void  memp_free(memp_t type, void *mem);







#line 39 "..\\lwIP\\src\\include\\lwip/stats.h"





#line 151 "..\\lwIP\\src\\include\\lwip/stats.h"

#line 159 "..\\lwIP\\src\\include\\lwip/stats.h"

#line 167 "..\\lwIP\\src\\include\\lwip/stats.h"

#line 175 "..\\lwIP\\src\\include\\lwip/stats.h"

#line 183 "..\\lwIP\\src\\include\\lwip/stats.h"

#line 191 "..\\lwIP\\src\\include\\lwip/stats.h"

#line 199 "..\\lwIP\\src\\include\\lwip/stats.h"

#line 207 "..\\lwIP\\src\\include\\lwip/stats.h"

#line 215 "..\\lwIP\\src\\include\\lwip/stats.h"

#line 233 "..\\lwIP\\src\\include\\lwip/stats.h"

#line 251 "..\\lwIP\\src\\include\\lwip/stats.h"

#line 261 "..\\lwIP\\src\\include\\lwip/stats.h"

 
#line 278 "..\\lwIP\\src\\include\\lwip/stats.h"





#line 67 "..\\lwIP\\src\\core\\pbuf.c"
#line 1 "..\\lwIP\\src\\include\\lwip/def.h"






























 



 
#line 37 "..\\lwIP\\src\\include\\lwip/def.h"











#line 68 "..\\lwIP\\src\\core\\pbuf.c"
#line 69 "..\\lwIP\\src\\core\\pbuf.c"
#line 70 "..\\lwIP\\src\\core\\pbuf.c"
#line 1 "..\\lwIP\\src\\include\\lwip/pbuf.h"






























 




#line 37 "..\\lwIP\\src\\include\\lwip/pbuf.h"
#line 1 "..\\lwIP\\src\\include\\lwip/err.h"






























 



#line 36 "..\\lwIP\\src\\include\\lwip/err.h"
#line 37 "..\\lwIP\\src\\include\\lwip/err.h"






 



 typedef s8_t err_t;


 



























extern const char *lwip_strerr(err_t err);








#line 38 "..\\lwIP\\src\\include\\lwip/pbuf.h"








typedef enum {
  PBUF_TRANSPORT,
  PBUF_IP,
  PBUF_LINK,
  PBUF_RAW
} pbuf_layer;

typedef enum {
  PBUF_RAM,  
  PBUF_ROM,  
  PBUF_REF,  
  PBUF_POOL  
} pbuf_type;


 


struct pbuf {
   
  struct pbuf *next;

   
  void *payload;
  
  





 
  u16_t tot_len;
  
   
  u16_t len;  

   
  u8_t   type;

   
  u8_t flags;

  



 
  u16_t ref;
  
};

 


struct pbuf *pbuf_alloc(pbuf_layer l, u16_t size, pbuf_type type);
void pbuf_realloc(struct pbuf *p, u16_t size); 
u8_t pbuf_header(struct pbuf *p, s16_t header_size);
void pbuf_ref(struct pbuf *p);
void pbuf_ref_chain(struct pbuf *p);
u8_t pbuf_free(struct pbuf *p);
u8_t pbuf_clen(struct pbuf *p);  
void pbuf_cat(struct pbuf *head, struct pbuf *tail);
void pbuf_chain(struct pbuf *head, struct pbuf *tail);
struct pbuf *pbuf_dechain(struct pbuf *p);
err_t pbuf_copy(struct pbuf *p_to, struct pbuf *p_from);
u16_t pbuf_copy_partial(struct pbuf *p, void *dataptr, u16_t len, u16_t offset);
err_t pbuf_take(struct pbuf *buf, const void *dataptr, u16_t len);
struct pbuf *pbuf_coalesce(struct pbuf *p, pbuf_layer layer);





#line 71 "..\\lwIP\\src\\core\\pbuf.c"
#line 1 "..\\lwIP\\src\\include\\lwip/sys.h"






























 



#line 36 "..\\lwIP\\src\\include\\lwip/sys.h"








 
typedef u8_t sys_sem_t;
typedef u8_t sys_mbox_t;
struct sys_timeo {u8_t dummy;};

#line 64 "..\\lwIP\\src\\include\\lwip/sys.h"



#line 142 "..\\lwIP\\src\\include\\lwip/sys.h"

 
u32_t sys_now(void);

 



 





 
#line 188 "..\\lwIP\\src\\include\\lwip/sys.h"












 

#line 210 "..\\lwIP\\src\\include\\lwip/sys.h"

#line 219 "..\\lwIP\\src\\include\\lwip/sys.h"

#line 228 "..\\lwIP\\src\\include\\lwip/sys.h"

#line 237 "..\\lwIP\\src\\include\\lwip/sys.h"






#line 72 "..\\lwIP\\src\\core\\pbuf.c"
#line 1 "..\\lwIP\\port\\include\\arch/perf.h"






























 






#line 73 "..\\lwIP\\src\\core\\pbuf.c"




#line 1 "C:\\Keil\\ARM\\RV31\\INC\\string.h"
 
 
 
 




 








 











#line 37 "C:\\Keil\\ARM\\RV31\\INC\\string.h"


  
  typedef unsigned int size_t;








extern __declspec(__nothrow) void *memcpy(void * __restrict  ,
                    const void * __restrict  , size_t  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) void *memmove(void *  ,
                    const void *  , size_t  ) __attribute__((__nonnull__(1,2)));
   







 
extern __declspec(__nothrow) char *strcpy(char * __restrict  , const char * __restrict  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) char *strncpy(char * __restrict  , const char * __restrict  , size_t  ) __attribute__((__nonnull__(1,2)));
   





 

extern __declspec(__nothrow) char *strcat(char * __restrict  , const char * __restrict  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) char *strncat(char * __restrict  , const char * __restrict  , size_t  ) __attribute__((__nonnull__(1,2)));
   






 






 

extern __declspec(__nothrow) int memcmp(const void *  , const void *  , size_t  ) __attribute__((__nonnull__(1,2)));
   





 
extern __declspec(__nothrow) int strcmp(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) int strncmp(const char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   






 
extern __declspec(__nothrow) int strcasecmp(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   





 
extern __declspec(__nothrow) int strncasecmp(const char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   






 
extern __declspec(__nothrow) int strcoll(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   







 

extern __declspec(__nothrow) size_t strxfrm(char * __restrict  , const char * __restrict  , size_t  ) __attribute__((__nonnull__(2)));
   













 


#line 184 "C:\\Keil\\ARM\\RV31\\INC\\string.h"
extern __declspec(__nothrow) void *memchr(const void *  , int  , size_t  ) __attribute__((__nonnull__(1)));

   





 

#line 200 "C:\\Keil\\ARM\\RV31\\INC\\string.h"
extern __declspec(__nothrow) char *strchr(const char *  , int  ) __attribute__((__nonnull__(1)));

   




 

extern __declspec(__nothrow) size_t strcspn(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   




 

#line 223 "C:\\Keil\\ARM\\RV31\\INC\\string.h"
extern __declspec(__nothrow) char *strpbrk(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));

   




 

#line 238 "C:\\Keil\\ARM\\RV31\\INC\\string.h"
extern __declspec(__nothrow) char *strrchr(const char *  , int  ) __attribute__((__nonnull__(1)));

   





 

extern __declspec(__nothrow) size_t strspn(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   



 

#line 261 "C:\\Keil\\ARM\\RV31\\INC\\string.h"
extern __declspec(__nothrow) char *strstr(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));

   





 

extern __declspec(__nothrow) char *strtok(char * __restrict  , const char * __restrict  ) __attribute__((__nonnull__(2)));
extern __declspec(__nothrow) char *_strtok_r(char *  , const char *  , char **  ) __attribute__((__nonnull__(2,3)));

extern __declspec(__nothrow) char *strtok_r(char *  , const char *  , char **  ) __attribute__((__nonnull__(2,3)));

   

































 

extern __declspec(__nothrow) void *memset(void *  , int  , size_t  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) char *strerror(int  );
   





 
extern __declspec(__nothrow) size_t strlen(const char *  ) __attribute__((__nonnull__(1)));
   



 

extern __declspec(__nothrow) size_t strlcpy(char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   
















 

extern __declspec(__nothrow) size_t strlcat(char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   






















 

extern __declspec(__nothrow) void _membitcpybl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpybb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpyhl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpyhb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpywl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpywb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovebl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovebb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovehl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovehb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovewl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovewb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
    














































 







#line 493 "C:\\Keil\\ARM\\RV31\\INC\\string.h"



 
#line 78 "..\\lwIP\\src\\core\\pbuf.c"



 









#line 119 "..\\lwIP\\src\\core\\pbuf.c"































 
struct pbuf *
pbuf_alloc(pbuf_layer layer, u16_t length, pbuf_type type)
{
  struct pbuf *p, *q, *r;
  u16_t offset;
  s32_t rem_len;  
  do { if ( ((0x00U | 0x40U | 3) & 0x80U) && ((0x00U | 0x40U | 3) & 0x80U) && ((s16_t)((0x00U | 0x40U | 3) & 0x03) >= 0x00)) { do {printf ("pbuf_alloc(length=%" "4d" ")\n", length);} while(0); if ((0x00U | 0x40U | 3) & 0x08U) { while(1); } } } while(0);

   
  offset = 0;
  switch (layer) {
  case PBUF_TRANSPORT:
     
    offset += 20;
     
  case PBUF_IP:
     
    offset += 20;
     
  case PBUF_LINK:
     
    offset += 14;
    break;
  case PBUF_RAW:
    break;
  default:
    ;
    return 0;
  }

  switch (type) {
  case PBUF_POOL:
     
    do { (p) = memp_malloc(MEMP_PBUF_POOL); } while (0);
    do { if ( ((0x00U | 0x40U | 3) & 0x80U) && ((0x00U | 0x40U | 3) & 0x80U) && ((s16_t)((0x00U | 0x40U | 3) & 0x03) >= 0x00)) { do {printf ("pbuf_alloc: allocated pbuf %p\n", (void *)p);} while(0); if ((0x00U | 0x40U | 3) & 0x08U) { while(1); } } } while(0);
    if (p == 0) {
      return 0;
    }
    p->type = type;
    p->next = 0;

     
    p->payload = ((void *)(((mem_ptr_t)((void *)((u8_t *)p + ((((sizeof(struct pbuf)) + 4 - 1) & ~(4-1)) + offset))) + 4 - 1) & ~(mem_ptr_t)(4-1)));
    ;

     
    p->tot_len = length;
     
    p->len = (((length) < ((((1550) + 4 - 1) & ~(4-1)) - (((offset) + 4 - 1) & ~(4-1)))) ? (length) : ((((1550) + 4 - 1) & ~(4-1)) - (((offset) + 4 - 1) & ~(4-1))));
    ;


    ;

     
    p->ref = 1;

     

     
    r = p;
     
    rem_len = length - p->len;
     
    while (rem_len > 0) {
      do { (q) = memp_malloc(MEMP_PBUF_POOL); } while (0);
      if (q == 0) {
         
        pbuf_free(p);
         
        return 0;
      }
      q->type = type;
      q->flags = 0;
      q->next = 0;
       
      r->next = q;
       
      ;
      q->tot_len = (u16_t)rem_len;
       
      q->len = ((((u16_t)rem_len) < ((((1550) + 4 - 1) & ~(4-1)))) ? ((u16_t)rem_len) : ((((1550) + 4 - 1) & ~(4-1))));
      q->payload = (void *)((u8_t *)q + (((sizeof(struct pbuf)) + 4 - 1) & ~(4-1)));
      ;

      ;


      q->ref = 1;
       
      rem_len -= q->len;
       
      r = q;
    }
     
     

    break;
  case PBUF_RAM:
     
    p = (struct pbuf*)mem_malloc(((((((sizeof(struct pbuf)) + 4 - 1) & ~(4-1)) + offset) + 4 - 1) & ~(4-1)) + (((length) + 4 - 1) & ~(4-1)));
    if (p == 0) {
      return 0;
    }
     
    p->payload = ((void *)(((mem_ptr_t)((void *)((u8_t *)p + (((sizeof(struct pbuf)) + 4 - 1) & ~(4-1)) + offset)) + 4 - 1) & ~(mem_ptr_t)(4-1)));
    p->len = p->tot_len = length;
    p->next = 0;
    p->type = type;

    ;

    break;
   
  case PBUF_ROM:
   
  case PBUF_REF:
     
    p = memp_malloc(MEMP_PBUF);
    if (p == 0) {
      do { if ( ((0x00U | 0x40U | 2) & 0x80U) && ((0x00U | 0x40U | 2) & 0x80U) && ((s16_t)((0x00U | 0x40U | 2) & 0x03) >= 0x00)) { do {printf ("pbuf_alloc: Could not allocate MEMP_PBUF for PBUF_%s.\n", (type == PBUF_ROM) ? "ROM" : "REF");} while(0); if ((0x00U | 0x40U | 2) & 0x08U) { while(1); } } } while(0);

      return 0;
    }
     
    p->payload = 0;
    p->len = p->tot_len = length;
    p->next = 0;
    p->type = type;
    break;
  default:
    ;
    return 0;
  }
   
  p->ref = 1;
   
  p->flags = 0;
  do { if ( ((0x00U | 0x40U | 3) & 0x80U) && ((0x00U | 0x40U | 3) & 0x80U) && ((s16_t)((0x00U | 0x40U | 3) & 0x03) >= 0x00)) { do {printf ("pbuf_alloc(length=%" "4d" ") == %p\n", length, (void *)p);} while(0); if ((0x00U | 0x40U | 3) & 0x08U) { while(1); } } } while(0);
  return p;
}
















 
void
pbuf_realloc(struct pbuf *p, u16_t new_len)
{
  struct pbuf *q;
  u16_t rem_len;  
  s32_t grow;

  ;
  ;




   
  if (new_len >= p->tot_len) {
     
    return;
  }

  
 
  grow = new_len - p->tot_len;

   
  rem_len = new_len;
  q = p;
   
  while (rem_len > q->len) {
     
    rem_len -= q->len;
     
    ;
    q->tot_len += (u16_t)grow;
     
    q = q->next;
    ;
  }
   
   

   
   
  if ((q->type == PBUF_RAM) && (rem_len != q->len)) {
     
    q = mem_realloc(q, (u8_t *)q->payload - (u8_t *)q + rem_len);
    ;
  }
   
  q->len = rem_len;
  q->tot_len = q->len;

   
  if (q->next != 0) {
     
    pbuf_free(q->next);
  }
   
  q->next = 0;

}




















 
u8_t
pbuf_header(struct pbuf *p, s16_t header_size_increment)
{
  u16_t type;
  void *payload;
  u16_t increment_magnitude;

  ;
  if ((header_size_increment == 0) || (p == 0))
    return 0;
 
  if (header_size_increment < 0){
    increment_magnitude = -header_size_increment;
     
    do { if (!((increment_magnitude <= p->len))) { do { printf("Assertion \"%s\" failed at line %d in %s\n", "increment_magnitude <= p->len", 404, "..\\lwIP\\src\\core\\pbuf.c"); } while(0); return 1;;}} while(0);
  } else {
    increment_magnitude = header_size_increment;
#line 417 "..\\lwIP\\src\\core\\pbuf.c"
  }

  type = p->type;
   
  payload = p->payload;

   
  if (type == PBUF_RAM || type == PBUF_POOL) {
     
    p->payload = (u8_t *)p->payload - header_size_increment;
     
    if ((u8_t *)p->payload < (u8_t *)p + (((sizeof(struct pbuf)) + 4 - 1) & ~(4-1))) {
      do { if ( ((0x00U | 2) & 0x80U) && ((0x00U | 2) & 0x80U) && ((s16_t)((0x00U | 2) & 0x03) >= 0x00)) { do {printf ("pbuf_header: failed as %p < %p (not enough space for new header size)\n", (void *)p->payload, (void *)(p + 1));} while(0); if ((0x00U | 2) & 0x08U) { while(1); } } } while(0);       



      p->payload = payload;
       
      return 1;
    }
   
  } else if (type == PBUF_REF || type == PBUF_ROM) {
     
    if ((header_size_increment < 0) && (increment_magnitude <= p->len)) {
       
      p->payload = (u8_t *)p->payload - header_size_increment;
    } else {
      
 
      return 1;
    }
  }
  else {
     
    ;
    return 1;
  }
   
  p->len += header_size_increment;
  p->tot_len += header_size_increment;

  do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("pbuf_header: old %p new %p (%" "4d" ")\n", (void *)payload, (void *)p->payload, header_size_increment);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);


  return 0;
}

































 
u8_t
pbuf_free(struct pbuf *p)
{
  u16_t type;
  struct pbuf *q;
  u8_t count;

  if (p == 0) {
    ;
     
    do { if ( ((0x00U | 0x40U | 2) & 0x80U) && ((0x00U | 0x40U | 2) & 0x80U) && ((s16_t)((0x00U | 0x40U | 2) & 0x03) >= 0x00)) { do {printf ("pbuf_free(p == NULL) was called.\n");} while(0); if ((0x00U | 0x40U | 2) & 0x08U) { while(1); } } } while(0);
    return 0;
  }
  do { if ( ((0x00U | 0x40U | 3) & 0x80U) && ((0x00U | 0x40U | 3) & 0x80U) && ((s16_t)((0x00U | 0x40U | 3) & 0x03) >= 0x00)) { do {printf ("pbuf_free(%p)\n", (void *)p);} while(0); if ((0x00U | 0x40U | 3) & 0x08U) { while(1); } } } while(0);

  ;

  ;



  count = 0;
  
 
  while (p != 0) {
    u16_t ref;
    ;
    

 
    ;
     
    ;
     
    ref = --(p->ref);
    ;
     
    if (ref == 0) {
       
      q = p->next;
      do { if ( ((0x00U | 2) & 0x80U) && ((0x00U | 2) & 0x80U) && ((s16_t)((0x00U | 2) & 0x03) >= 0x00)) { do {printf ("pbuf_free: deallocating %p\n", (void *)p);} while(0); if ((0x00U | 2) & 0x08U) { while(1); } } } while(0);
      type = p->type;
       
      if (type == PBUF_POOL) {
        memp_free(MEMP_PBUF_POOL, p);
       
      } else if (type == PBUF_ROM || type == PBUF_REF) {
        memp_free(MEMP_PBUF, p);
       
      } else {
        mem_free(p);
      }
      count++;
       
      p = q;
     
     
    } else {
      do { if ( ((0x00U | 2) & 0x80U) && ((0x00U | 2) & 0x80U) && ((s16_t)((0x00U | 2) & 0x03) >= 0x00)) { do {printf ("pbuf_free: %p has ref %" "4d" ", ending here.\n", (void *)p, ref);} while(0); if ((0x00U | 2) & 0x08U) { while(1); } } } while(0);
       
      p = 0;
    }
  }
  ;
   
  return count;
}






 

u8_t
pbuf_clen(struct pbuf *p)
{
  u8_t len;

  len = 0;
  while (p != 0) {
    ++len;
    p = p->next;
  }
  return len;
}






 
void
pbuf_ref(struct pbuf *p)
{
  ;
   
  if (p != 0) {
    ;
    ++(p->ref);
    ;
  }
}









 

void
pbuf_cat(struct pbuf *h, struct pbuf *t)
{
  struct pbuf *p;

  do { if (!(((h != 0) && (t != 0)))) { do { printf("Assertion \"%s\" failed at line %d in %s\n", "(h != NULL) && (t != NULL) (programmer violates API)", 618, "..\\lwIP\\src\\core\\pbuf.c"); } while(0); return;;}} while(0);


   
  for (p = h; p->next != 0; p = p->next) {
     
    p->tot_len += t->tot_len;
  }
   
  ;
  ;
   
  p->tot_len += t->tot_len;
   
  p->next = t;
  

 
}
















 
void
pbuf_chain(struct pbuf *h, struct pbuf *t)
{
  pbuf_cat(h, t);
   
  pbuf_ref(t);
  do { if ( ((0x00U | 0x10U | 2) & 0x80U) && ((0x00U | 0x10U | 2) & 0x80U) && ((s16_t)((0x00U | 0x10U | 2) & 0x03) >= 0x00)) { do {printf ("pbuf_chain: %p references %p\n", (void *)h, (void *)t);} while(0); if ((0x00U | 0x10U | 2) & 0x08U) { while(1); } } } while(0);
}








 
struct pbuf *
pbuf_dechain(struct pbuf *p)
{
  struct pbuf *q;
  u8_t tail_gone = 1;
   
  q = p->next;
   
  if (q != 0) {
     
    ;
     
    q->tot_len = p->tot_len - p->len;
     
    p->next = 0;
     
    p->tot_len = p->len;
     
    do { if ( ((0x00U | 0x20U) & 0x80U) && ((0x00U | 0x20U) & 0x80U) && ((s16_t)((0x00U | 0x20U) & 0x03) >= 0x00)) { do {printf ("pbuf_dechain: unreferencing %p\n", (void *)q);} while(0); if ((0x00U | 0x20U) & 0x08U) { while(1); } } } while(0);
    tail_gone = pbuf_free(q);
    if (tail_gone > 0) {
      do { if ( ((0x00U | 0x20U) & 0x80U) && ((0x00U | 0x20U) & 0x80U) && ((s16_t)((0x00U | 0x20U) & 0x03) >= 0x00)) { do {printf ("pbuf_dechain: deallocated %p (as it is no longer referenced)\n", (void *)q);} while(0); if ((0x00U | 0x20U) & 0x08U) { while(1); } } } while(0);

    }
     
  }
   
  ;
  return ((tail_gone > 0) ? 0 : q);
}


















 
err_t
pbuf_copy(struct pbuf *p_to, struct pbuf *p_from)
{
  u16_t offset_to=0, offset_from=0, len;

  do { if ( ((0x00U | 0x40U | 3) & 0x80U) && ((0x00U | 0x40U | 3) & 0x80U) && ((s16_t)((0x00U | 0x40U | 3) & 0x03) >= 0x00)) { do {printf ("pbuf_copy(%p, %p)\n", (void*)p_to, (void*)p_from);} while(0); if ((0x00U | 0x40U | 3) & 0x08U) { while(1); } } } while(0);


   
  do { if (!(((p_to != 0) && (p_from != 0) && (p_to->tot_len >= p_from->tot_len)))) { do { printf("Assertion \"%s\" failed at line %d in %s\n", "pbuf_copy: target not big enough to hold source", 729, "..\\lwIP\\src\\core\\pbuf.c"); } while(0); return -10;;}} while(0);


   
  do
  {
    ;
     
    if ((p_to->len - offset_to) >= (p_from->len - offset_from)) {
       
      len = p_from->len - offset_from;
    } else {
       
      len = p_to->len - offset_to;
    }
    memcpy((u8_t*)p_to->payload + offset_to,(u8_t*)p_from->payload + offset_from,len);
    offset_to += len;
    offset_from += len;
    ;
    if (offset_to == p_to->len) {
       
      offset_to = 0;
      p_to = p_to->next;
    }
    ;
    if (offset_from >= p_from->len) {
       
      offset_from = 0;
      p_from = p_from->next;
    }

    if((p_from != 0) && (p_from->len == p_from->tot_len)) {
       
      do { if (!((p_from->next == 0))) { do { printf("Assertion \"%s\" failed at line %d in %s\n", "pbuf_copy() does not allow packet queues!\n", 762, "..\\lwIP\\src\\core\\pbuf.c"); } while(0); return -9;;}} while(0);

    }
    if((p_to != 0) && (p_to->len == p_to->tot_len)) {
       
      do { if (!((p_to->next == 0))) { do { printf("Assertion \"%s\" failed at line %d in %s\n", "pbuf_copy() does not allow packet queues!\n", 767, "..\\lwIP\\src\\core\\pbuf.c"); } while(0); return -9;;}} while(0);

    }
  } while (p_from);
  do { if ( ((0x00U | 0x40U | 1) & 0x80U) && ((0x00U | 0x40U | 1) & 0x80U) && ((s16_t)((0x00U | 0x40U | 1) & 0x03) >= 0x00)) { do {printf ("pbuf_copy: end of chain reached.\n");} while(0); if ((0x00U | 0x40U | 1) & 0x08U) { while(1); } } } while(0);
  return 0;
}











 
u16_t
pbuf_copy_partial(struct pbuf *buf, void *dataptr, u16_t len, u16_t offset)
{
  struct pbuf *p;
  u16_t left;
  u16_t buf_copy_len;
  u16_t copied_total = 0;

  do { if (!((buf != 0))) { do { printf("Assertion \"%s\" failed at line %d in %s\n", "pbuf_copy_partial: invalid buf", 794, "..\\lwIP\\src\\core\\pbuf.c"); } while(0); return 0;;}} while(0);
  do { if (!((dataptr != 0))) { do { printf("Assertion \"%s\" failed at line %d in %s\n", "pbuf_copy_partial: invalid dataptr", 795, "..\\lwIP\\src\\core\\pbuf.c"); } while(0); return 0;;}} while(0);

  left = 0;

  if((buf == 0) || (dataptr == 0)) {
    return 0;
  }

   
  for(p = buf; len != 0 && p != 0; p = p->next) {
    if ((offset != 0) && (offset >= p->len)) {
       
      offset -= p->len;
    } else {
       
      buf_copy_len = p->len - offset;
      if (buf_copy_len > len)
          buf_copy_len = len;
       
      memcpy(&((char*)dataptr)[left],&((char*)p->payload)[offset],buf_copy_len);
      copied_total += buf_copy_len;
      left += buf_copy_len;
      len -= buf_copy_len;
      offset = 0;
    }
  }
  return copied_total;
}










 
err_t
pbuf_take(struct pbuf *buf, const void *dataptr, u16_t len)
{
  struct pbuf *p;
  u16_t buf_copy_len;
  u16_t total_copy_len = len;
  u16_t copied_total = 0;

  do { if (!((buf != 0))) { do { printf("Assertion \"%s\" failed at line %d in %s\n", "pbuf_take: invalid buf", 842, "..\\lwIP\\src\\core\\pbuf.c"); } while(0); return 0;;}} while(0);
  do { if (!((dataptr != 0))) { do { printf("Assertion \"%s\" failed at line %d in %s\n", "pbuf_take: invalid dataptr", 843, "..\\lwIP\\src\\core\\pbuf.c"); } while(0); return 0;;}} while(0);

  if ((buf == 0) || (dataptr == 0) || (buf->tot_len < len)) {
    return -10;
  }

   
  for(p = buf; total_copy_len != 0; p = p->next) {
    ;
    buf_copy_len = total_copy_len;
    if (buf_copy_len > p->len) {
       
      buf_copy_len = p->len;
    }
     
    memcpy(p->payload,&((char*)dataptr)[copied_total],buf_copy_len);
    total_copy_len -= buf_copy_len;
    copied_total += buf_copy_len;
  }
  ;
  return 0;
}












 
struct pbuf*
pbuf_coalesce(struct pbuf *p, pbuf_layer layer)
{
  struct pbuf *q;
  err_t err;
  if (p->next == 0) {
    return p;
  }
  q = pbuf_alloc(layer, p->tot_len, PBUF_RAM);
  if (q == 0) {
     
    return p;
  }
  err = pbuf_copy(q, p);
  if(err!= 0)
  	;
  pbuf_free(p);
  return q;
}
