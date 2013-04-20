#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common\\eap_sim_common.c"












 

#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\includes.h"
















 






 
#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\build_config.h"


















 




 

#line 55 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\build_config.h"

#line 77 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\build_config.h"

#line 104 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\build_config.h"

#line 26 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\includes.h"

#line 1 "C:\\Keil\\ARM\\RV31\\INC\\stdlib.h"
 
 
 




 
 



 












  


 








#line 45 "C:\\Keil\\ARM\\RV31\\INC\\stdlib.h"


  
  typedef unsigned int size_t;










    



    typedef unsigned short wchar_t;  
#line 74 "C:\\Keil\\ARM\\RV31\\INC\\stdlib.h"

typedef struct div_t { int quot, rem; } div_t;
    
typedef struct ldiv_t { long int quot, rem; } ldiv_t;
    

typedef struct lldiv_t { __int64 quot, rem; } lldiv_t;
    


#line 95 "C:\\Keil\\ARM\\RV31\\INC\\stdlib.h"
   



 

   




 
#line 114 "C:\\Keil\\ARM\\RV31\\INC\\stdlib.h"
   


 
extern __declspec(__nothrow) int __aeabi_MB_CUR_MAX(void);

   




 

   




 




extern __declspec(__nothrow) double atof(const char *  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) int atoi(const char *  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) long int atol(const char *  ) __attribute__((__nonnull__(1)));
   



 

extern __declspec(__nothrow) __int64 atoll(const char *  ) __attribute__((__nonnull__(1)));
   



 


extern __declspec(__nothrow) double strtod(const char * __restrict  , char ** __restrict  ) __attribute__((__nonnull__(1)));
   

















 

extern __declspec(__nothrow) float strtof(const char * __restrict  , char ** __restrict  ) __attribute__((__nonnull__(1)));
extern __declspec(__nothrow) long double strtold(const char * __restrict  , char ** __restrict  ) __attribute__((__nonnull__(1)));
   

 

extern __declspec(__nothrow) long int strtol(const char * __restrict  ,
                        char ** __restrict  , int  ) __attribute__((__nonnull__(1)));
   



























 
extern __declspec(__nothrow) unsigned long int strtoul(const char * __restrict  ,
                                       char ** __restrict  , int  ) __attribute__((__nonnull__(1)));
   


























 

 
extern __declspec(__nothrow) __int64 strtoll(const char * __restrict  ,
                               char ** __restrict  , int  ) __attribute__((__nonnull__(1)));
   




 
extern __declspec(__nothrow) unsigned __int64 strtoull(const char * __restrict  ,
                                         char ** __restrict  , int  ) __attribute__((__nonnull__(1)));
   



 

extern __declspec(__nothrow) int rand(void);
   







 
extern __declspec(__nothrow) void srand(unsigned int  );
   






 

struct _rand_state { int __x[57]; };
extern __declspec(__nothrow) int _rand_r(struct _rand_state *);
extern __declspec(__nothrow) void _srand_r(struct _rand_state *, unsigned int);
struct _ANSI_rand_state { int __x[1]; };
extern __declspec(__nothrow) int _ANSI_rand_r(struct _ANSI_rand_state *);
extern __declspec(__nothrow) void _ANSI_srand_r(struct _ANSI_rand_state *, unsigned int);
   


 

extern __declspec(__nothrow) void *calloc(size_t  , size_t  );
   



 
extern __declspec(__nothrow) void free(void *  );
   





 
extern __declspec(__nothrow) void *malloc(size_t  );
   



 
extern __declspec(__nothrow) void *realloc(void *  , size_t  );
   













 

extern __declspec(__nothrow) int posix_memalign(void **  , size_t  , size_t  );
   









 

typedef int (*__heapprt)(void *, char const *, ...);
extern __declspec(__nothrow) void __heapstats(int (*  )(void *  ,
                                           char const *  , ...),
                        void *  ) __attribute__((__nonnull__(1)));
   










 
extern __declspec(__nothrow) int __heapvalid(int (*  )(void *  ,
                                           char const *  , ...),
                       void *  , int  ) __attribute__((__nonnull__(1)));
   














 
extern __declspec(__nothrow) __declspec(__noreturn) void abort(void);
   







 

extern __declspec(__nothrow) int atexit(void (*  )(void)) __attribute__((__nonnull__(1)));
   




 
#line 414 "C:\\Keil\\ARM\\RV31\\INC\\stdlib.h"


extern __declspec(__nothrow) __declspec(__noreturn) void exit(int  );
   












 

extern __declspec(__nothrow) __declspec(__noreturn) void _Exit(int  );
   







      

extern __declspec(__nothrow) char *getenv(const char *  ) __attribute__((__nonnull__(1)));
   









 

extern __declspec(__nothrow) int  system(const char *  );
   









 

extern  void *bsearch(const void *  , const void *  ,
              size_t  , size_t  ,
              int (*  )(const void *, const void *)) __attribute__((__nonnull__(1,2,5)));
   












 
#line 502 "C:\\Keil\\ARM\\RV31\\INC\\stdlib.h"


extern  void qsort(void *  , size_t  , size_t  ,
           int (*  )(const void *, const void *)) __attribute__((__nonnull__(1,4)));
   









 

#line 531 "C:\\Keil\\ARM\\RV31\\INC\\stdlib.h"

extern __declspec(__nothrow) __pure int abs(int  );
   



 

extern __declspec(__nothrow) __pure div_t div(int  , int  );
   









 
extern __declspec(__nothrow) __pure long int labs(long int  );
   



 




extern __declspec(__nothrow) __pure ldiv_t ldiv(long int  , long int  );
   











 







extern __declspec(__nothrow) __pure __int64 llabs(__int64  );
   



 




extern __declspec(__nothrow) __pure lldiv_t lldiv(__int64  , __int64  );
   











 
#line 612 "C:\\Keil\\ARM\\RV31\\INC\\stdlib.h"



 
typedef struct __sdiv32by16 { int quot, rem; } __sdiv32by16;
typedef struct __udiv32by16 { unsigned int quot, rem; } __udiv32by16;
    
typedef struct __sdiv64by32 { int rem, quot; } __sdiv64by32;

__value_in_regs extern __declspec(__nothrow) __pure __sdiv32by16 __rt_sdiv32by16(
     int  ,
     short int  );
   

 
__value_in_regs extern __declspec(__nothrow) __pure __udiv32by16 __rt_udiv32by16(
     unsigned int  ,
     unsigned short  );
   

 
__value_in_regs extern __declspec(__nothrow) __pure __sdiv64by32 __rt_sdiv64by32(
     int  , unsigned int  ,
     int  );
   

 



 
extern __declspec(__nothrow) unsigned int __fp_status(unsigned int  , unsigned int  );
   







 























 
extern __declspec(__nothrow) int mblen(const char *  , size_t  );
   












 
extern __declspec(__nothrow) int mbtowc(wchar_t * __restrict  ,
                   const char * __restrict  , size_t  );
   















 
extern __declspec(__nothrow) int wctomb(char *  , wchar_t  );
   













 





 
extern __declspec(__nothrow) size_t mbstowcs(wchar_t * __restrict  ,
                      const char * __restrict  , size_t  ) __attribute__((__nonnull__(2)));
   














 
extern __declspec(__nothrow) size_t wcstombs(char * __restrict  ,
                      const wchar_t * __restrict  , size_t  ) __attribute__((__nonnull__(2)));
   














 

extern __declspec(__nothrow) void __use_realtime_heap(void);
extern __declspec(__nothrow) void __use_realtime_division(void);
extern __declspec(__nothrow) void __use_two_region_memory(void);
extern __declspec(__nothrow) void __use_no_heap(void);
extern __declspec(__nothrow) void __use_no_heap_region(void);

extern __declspec(__nothrow) char const *__C_library_version_string(void);
extern __declspec(__nothrow) int __C_library_version_number(void);











#line 866 "C:\\Keil\\ARM\\RV31\\INC\\stdlib.h"


 
#line 28 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\includes.h"
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



 
#line 29 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\includes.h"
#line 1 "C:\\Keil\\ARM\\RV31\\INC\\stdarg.h"
 
 
 





 









#line 26 "C:\\Keil\\ARM\\RV31\\INC\\stdarg.h"








 

 
 
  typedef struct __va_list { void *__ap; } va_list;

   






 


   










 


   















 




   

 


   




 



   





 






#line 118 "C:\\Keil\\ARM\\RV31\\INC\\stdarg.h"











 
#line 30 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\includes.h"
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



 
#line 31 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\includes.h"






#line 1 "C:\\Keil\\ARM\\RV31\\INC\\ctype.h"
 
 
 
 





 






 







#line 32 "C:\\Keil\\ARM\\RV31\\INC\\ctype.h"






#line 46 "C:\\Keil\\ARM\\RV31\\INC\\ctype.h"

 
#line 56 "C:\\Keil\\ARM\\RV31\\INC\\ctype.h"

 
 









 
#line 78 "C:\\Keil\\ARM\\RV31\\INC\\ctype.h"





#line 130 "C:\\Keil\\ARM\\RV31\\INC\\ctype.h"

extern __declspec(__nothrow) __pure unsigned char **__rt_ctype_table(void);







    extern int (isalnum)(int  );

     





    extern int (isalpha)(int  );

     





    extern int (iscntrl)(int  );

     
     

 




    extern int (isdigit)(int  );

     

    extern int (isblank)(int  );
     
     
     





    extern int (isgraph)(int  );

     





    extern int (islower)(int  );

     





    extern int (isprint)(int  );

     
     





    extern int (ispunct)(int  );

     





    extern int (isspace)(int  );

     





    extern int (isupper)(int  );

     

 
 

__inline int __isxdigit_helper(int __t) { return (__t ^ (__t << 2)); }




    extern int (isxdigit)(int  );

     



extern int tolower(int  );
     
     

extern int toupper(int  );
     
     







#line 269 "C:\\Keil\\ARM\\RV31\\INC\\ctype.h"



 
#line 39 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\includes.h"
#line 1 "C:\\Keil\\ARM\\RV31\\INC\\time.h"
 
 
 
 









 





 












#line 40 "C:\\Keil\\ARM\\RV31\\INC\\time.h"


  
  typedef unsigned int size_t;








    
 
#line 64 "C:\\Keil\\ARM\\RV31\\INC\\time.h"





typedef unsigned int clock_t;     
typedef unsigned int time_t;      

#pragma push
#pragma anon_unions

struct tm {
    int tm_sec;   
 
    int tm_min;    
    int tm_hour;   
    int tm_mday;   
    int tm_mon;    
    int tm_year;   
    int tm_wday;   
    int tm_yday;   
    int tm_isdst;  
    union {        
        struct {
            int __extra_1, __extra_2;
        };
        struct {
            long __extra_1_long, __extra_2_long;
        };
        struct {
            char *__extra_1_cptr, *__extra_2_cptr;
        };
        struct {
            void *__extra_1_vptr, *__extra_2_vptr;
        };
    };
};

#pragma pop

   



 

extern __declspec(__nothrow) clock_t clock(void);
   





 
extern __declspec(__nothrow) double difftime(time_t  , time_t  );
   


 
extern __declspec(__nothrow) time_t mktime(struct tm *  ) __attribute__((__nonnull__(1)));
   













 
extern __declspec(__nothrow) time_t time(time_t *  );
   






 

extern __declspec(__nothrow) char *asctime(const struct tm *  ) __attribute__((__nonnull__(1)));
extern __declspec(__nothrow) char *_asctime_r(const struct tm *  ,
                                char * __restrict  ) __attribute__((__nonnull__(1,2)));

extern __declspec(__nothrow) char *asctime_r(const struct tm *  ,
                               char * __restrict  ) __attribute__((__nonnull__(1,2)));

   



 
extern __declspec(__nothrow) char *ctime(const time_t *  ) __attribute__((__nonnull__(1)));
   




 
extern __declspec(__nothrow) struct tm *gmtime(const time_t *  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) struct tm *localtime(const time_t *  ) __attribute__((__nonnull__(1)));
extern __declspec(__nothrow) struct tm *_localtime_r(const time_t * __restrict  ,
                                       struct tm * __restrict  ) __attribute__((__nonnull__(1,2)));

extern __declspec(__nothrow) struct tm *localtime_r(const time_t * __restrict  ,
                                      struct tm * __restrict  ) __attribute__((__nonnull__(1,2)));

   



 
extern __declspec(__nothrow) size_t strftime(char * __restrict  , size_t  ,
                       const char * __restrict  ,
                       const struct tm * __restrict  ) __attribute__((__nonnull__(1,3,4)));
   











































 











#line 271 "C:\\Keil\\ARM\\RV31\\INC\\time.h"



 
#line 40 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\includes.h"







#line 60 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\includes.h"


#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\wpa_supp_linux_plat\\byteswap.h"













#line 63 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\includes.h"

#line 16 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common\\eap_sim_common.c"

#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\wpa_common.h"












 




#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\os.h"












 




typedef long os_time_t;





 
void os_sleep(os_time_t sec, os_time_t usec);

struct os_time {
	os_time_t sec;
	os_time_t usec;
};





 
int os_get_time(struct os_time *t);


 





#line 54 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\os.h"















 
int os_mktime(int year, int month, int day, int hour, int min, int sec,
	      os_time_t *t);






 
int os_daemonize(const char *pid_file);




 
void os_daemonize_terminate(const char *pid_file);






 
int os_get_random(unsigned char *buf, size_t len);




 
unsigned long os_random(void);













 
char * os_rel2abs_path(const char *rel_path);








 
int os_program_init(void);








 
void os_program_deinit(void);










 
int os_setenv(const char *name, const char *value, int overwrite);








 
int os_unsetenv(const char *name);










 
char * os_readfile(const char *name, size_t *len);







 
void * os_zalloc(size_t size);
















 









 
void * os_malloc(size_t size);










 
void * os_realloc(void *ptr, size_t size);




 
void os_free(void *ptr);










 
void * os_memcpy(void *dest, const void *src, size_t n);









 
void * os_memmove(void *dest, const void *src, size_t n);







 
void * os_memset(void *s, int c, size_t n);









 
int os_memcmp(const void *s1, const void *s2, size_t n);







 
char * os_strdup(const char *s);





 
size_t os_strlen(const char *s);







 
int os_strcasecmp(const char *s1, const char *s2);









 
int os_strncasecmp(const char *s1, const char *s2, size_t n);






 
char * os_strchr(const char *s, int c);






 
char * os_strrchr(const char *s, int c);







 
int os_strcmp(const char *s1, const char *s2);









 
int os_strncmp(const char *s1, const char *s2, size_t n);







 
char * os_strncpy(char *dest, const char *src, size_t n);






 
char * os_strstr(const char *haystack, const char *needle);





















 
int os_snprintf(char *str, size_t size, const char *format, ...);

#line 464 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\os.h"











 
size_t os_strlcpy(char *dest, const char *src, size_t siz);


#line 507 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\os.h"

#line 19 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\wpa_common.h"




static void dbug_buf(const char * name , const unsigned char * buf , const int len)
{
	
#line 35 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\wpa_common.h"
}










#line 66 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\wpa_common.h"

#line 84 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\wpa_common.h"

#line 94 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\wpa_common.h"







#line 111 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\wpa_common.h"

#line 120 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\wpa_common.h"


 

#line 135 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\wpa_common.h"

#line 147 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\wpa_common.h"








 













#line 178 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\wpa_common.h"

#line 195 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\wpa_common.h"


 

#line 223 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\wpa_common.h"




#line 238 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\wpa_common.h"

#line 270 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\wpa_common.h"





 

#line 283 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\wpa_common.h"

#line 290 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\wpa_common.h"

#line 299 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\wpa_common.h"

#line 309 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\wpa_common.h"

#line 319 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\wpa_common.h"

#line 335 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\wpa_common.h"







#line 363 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\wpa_common.h"


#line 372 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\wpa_common.h"


#line 429 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\wpa_common.h"













 
#line 450 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\wpa_common.h"

#line 463 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\wpa_common.h"


#line 472 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\wpa_common.h"

int hwaddr_aton(const char *txt, unsigned char *addr);
int hwaddr_aton2(const char *txt, unsigned char *addr);
int hexstr2bin(const char *hex, unsigned char *buf, size_t len);
void inc_byte_array(unsigned char *counter, size_t len);
void wpa_get_ntp_timestamp(unsigned char *buf);
int wpa_snprintf_hex(char *buf, size_t buf_size, const unsigned char *data, size_t len);
int wpa_snprintf_hex_uppercase(char *buf, size_t buf_size, const unsigned char *data,
			       size_t len);

#line 489 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\wpa_common.h"

const char * wpa_ssid_txt(const unsigned char *ssid, size_t ssid_len);

static int is_zero_ether_addr(const unsigned char *a)
{
	return !(a[0] | a[1] | a[2] | a[3] | a[4] | a[5]);
}

#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\wpa_debug.h"












 




#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\wpabuf.h"












 











 
struct wpabuf {
	size_t size;  
	size_t used;  
	unsigned char *ext_data; 
 
	 
};


int wpabuf_resize(struct wpabuf **buf, size_t add_len);
struct wpabuf * wpabuf_alloc(size_t len);
struct wpabuf * wpabuf_alloc_ext_data(unsigned char *data, size_t len);
struct wpabuf * wpabuf_alloc_copy(const void *data, size_t len);
struct wpabuf * wpabuf_dup(const struct wpabuf *src);
void wpabuf_free(struct wpabuf *buf);
void * wpabuf_put(struct wpabuf *buf, size_t len);
struct wpabuf * wpabuf_concat(struct wpabuf *a, struct wpabuf *b);
struct wpabuf * wpabuf_zeropad(struct wpabuf *buf, size_t len);
void wpabuf_printf(struct wpabuf *buf, char *fmt, ...) ;






 
static  size_t wpabuf_size(const struct wpabuf *buf)
{
	return buf->size;
}





 
static  size_t wpabuf_len(const struct wpabuf *buf)
{
	return buf->used;
}





 
static  size_t wpabuf_tailroom(const struct wpabuf *buf)
{
	return buf->size - buf->used;
}





 
static  const void * wpabuf_head(const struct wpabuf *buf)
{
	if (buf->ext_data)
		return buf->ext_data;
	return buf + 1;
}

static  const unsigned char * wpabuf_head_u8(const struct wpabuf *buf)
{
	return wpabuf_head(buf);
}





 
static  void * wpabuf_mhead(struct wpabuf *buf)
{
	if (buf->ext_data)
		return buf->ext_data;
	return buf + 1;
}

static  unsigned char * wpabuf_mhead_u8(struct wpabuf *buf)
{
	return wpabuf_mhead(buf);
}

static  void wpabuf_put_u8(struct wpabuf *buf, unsigned char data)
{
	unsigned char *pos = wpabuf_put(buf, 1);
	*pos = data;
}

static  void wpabuf_put_le16(struct wpabuf *buf, unsigned short data)
{
	unsigned char *pos = wpabuf_put(buf, 2);
	do { (pos)[1] = ((unsigned short) (data)) >> 8; (pos)[0] = ((unsigned short) (data)) & 0xff; } while (0);
}

static  void wpabuf_put_be16(struct wpabuf *buf, unsigned short data)
{
	unsigned char *pos = wpabuf_put(buf, 2);
	do { (pos)[0] = ((unsigned short) (data)) >> 8; (pos)[1] = ((unsigned short) (data)) & 0xff; } while (0);
}

static  void wpabuf_put_be24(struct wpabuf *buf, unsigned int data)
{
	unsigned char *pos = wpabuf_put(buf, 3);
	do { (pos)[0] = (unsigned char) ((((unsigned int) (data)) >> 16) & 0xff); (pos)[1] = (unsigned char) ((((unsigned int) (data)) >> 8) & 0xff); (pos)[2] = (unsigned char) (((unsigned int) (data)) & 0xff); } while (0);
}

static  void wpabuf_put_be32(struct wpabuf *buf, unsigned int data)
{
	unsigned char *pos = wpabuf_put(buf, 4);
	do { (pos)[0] = (unsigned char) ((((unsigned int) (data)) >> 24) & 0xff); (pos)[1] = (unsigned char) ((((unsigned int) (data)) >> 16) & 0xff); (pos)[2] = (unsigned char) ((((unsigned int) (data)) >> 8) & 0xff); (pos)[3] = (unsigned char) (((unsigned int) (data)) & 0xff); } while (0);
}

static  void wpabuf_put_data(struct wpabuf *buf, const void *data,
				   size_t len)
{
	if (data)
		os_memcpy(wpabuf_put(buf, len), data, len);
}

static  void wpabuf_put_buf(struct wpabuf *dst,
				  const struct wpabuf *src)
{
	wpabuf_put_data(dst, wpabuf_head(src), wpabuf_len(src));
}

static  void wpabuf_set(struct wpabuf *buf, const void *data, size_t len)
{
	buf->ext_data = (unsigned char *) data;
	buf->size = buf->used = len;
}

static  void wpabuf_put_str(struct wpabuf *dst, const char *str)
{
	wpabuf_put_data(dst, str, os_strlen(str));
}

#line 19 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\wpa_debug.h"


 



#line 32 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\wpa_debug.h"


#line 48 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\wpa_debug.h"

int wpa_debug_open_file(const char *path);
void wpa_debug_close_file(void);







 
void wpa_debug_print_timestamp(void);











 
void wpa_printf(int level, const char *fmt, ...)
;











 
void wpa_hexdump(int level, const char *title, const unsigned char *buf, size_t len);

static  void wpa_hexdump_buf(int level, const char *title,
				   const struct wpabuf *buf)
{
	wpa_hexdump(level, title, wpabuf_head(buf), wpabuf_len(buf));
}













 
void wpa_hexdump_key(int level, const char *title, const unsigned char *buf, size_t len);

static  void wpa_hexdump_buf_key(int level, const char *title,
				       const struct wpabuf *buf)
{
	wpa_hexdump_key(level, title, wpabuf_head(buf), wpabuf_len(buf));
}













 
void wpa_hexdump_ascii(int level, const char *title, const unsigned char *buf,
		       size_t len);














 
void wpa_hexdump_ascii_key(int level, const char *title, const unsigned char *buf,
			   size_t len);






















 
void wpa_msg(void *ctx, int level, const char *fmt, ...) ;












 
void wpa_msg_ctrl(void *ctx, int level, const char *fmt, ...)
;

typedef void (*wpa_msg_cb_func)(void *ctx, int level, const char *txt,
				size_t len);




 
void wpa_msg_register_cb(wpa_msg_cb_func func);







void hostapd_logger(void *ctx, const unsigned char *addr, unsigned int module, int level,
		    const char *fmt, ...) ;

typedef void (*hostapd_logger_cb_func)(void *ctx, const unsigned char *addr,
				       unsigned int module, int level,
				       const char *txt, size_t len);




 
void hostapd_logger_register_cb(hostapd_logger_cb_func func);


#line 223 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\wpa_debug.h"

enum hostapd_logger_level {
	HOSTAPD_LEVEL_DEBUG_VERBOSE = 0,
	HOSTAPD_LEVEL_DEBUG = 1,
	HOSTAPD_LEVEL_INFO = 2,
	HOSTAPD_LEVEL_NOTICE = 3,
	HOSTAPD_LEVEL_WARNING = 4
};


#line 239 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\wpa_debug.h"

static  void wpa_debug_open_syslog(void)
{
}

static  void wpa_debug_close_syslog(void)
{
}




#line 264 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\wpa_debug.h"

#line 498 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\wpa_common.h"










 
void * __hide_aliasing_typecast(void *foo);



#line 18 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common\\eap_sim_common.c"
#line 19 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common\\eap_sim_common.c"
#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\crypto/aes_wrap.h"



















 




#line 26 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\crypto/aes_wrap.h"

int  aes_wrap(const unsigned char *kek, int n, const unsigned char *plain, unsigned char *cipher);
int  aes_unwrap(const unsigned char *kek, int n, const unsigned char *cipher, unsigned char *plain);
int  omac1_aes_128_vector(const unsigned char *key, size_t num_elem,
				      const unsigned char *addr[], const size_t *len,
				      unsigned char *mac);
int  omac1_aes_128(const unsigned char *key, const unsigned char *data, size_t data_len,
			       unsigned char *mac);
int  aes_128_encrypt_block(const unsigned char *key, const unsigned char *in, unsigned char *out);
int  aes_128_ctr_encrypt(const unsigned char *key, const unsigned char *nonce,
				     unsigned char *data, size_t data_len);
int  aes_128_eax_encrypt(const unsigned char *key,
				     const unsigned char *nonce, size_t nonce_len,
				     const unsigned char *hdr, size_t hdr_len,
				     unsigned char *data, size_t data_len, unsigned char *tag);
int  aes_128_eax_decrypt(const unsigned char *key,
				     const unsigned char *nonce, size_t nonce_len,
				     const unsigned char *hdr, size_t hdr_len,
				     unsigned char *data, size_t data_len, const unsigned char *tag);
int  aes_128_cbc_encrypt(const unsigned char *key, const unsigned char *iv, unsigned char *data,
				     size_t data_len);
int  aes_128_cbc_decrypt(const unsigned char *key, const unsigned char *iv, unsigned char *data,
				     size_t data_len);

#line 20 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common\\eap_sim_common.c"
#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\crypto/crypto.h"
























 




#line 31 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\crypto/crypto.h"








 
int md4_vector(size_t num_elem, const unsigned char *addr[], const size_t *len, unsigned char *mac);








 
int md5_vector(size_t num_elem, const unsigned char *addr[], const size_t *len, unsigned char *mac);

#line 66 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\crypto/crypto.h"









 
int sha1_vector(size_t num_elem, const unsigned char *addr[], const size_t *len,
		unsigned char *mac);












 
int  fips186_2_prf(const unsigned char *seed, size_t seed_len, unsigned char *x,
			       size_t xlen);








 
int sha256_vector(size_t num_elem, const unsigned char *addr[], const size_t *len,
		  unsigned char *mac);






 
void des_encrypt(const unsigned char *clear, const unsigned char *key, unsigned char *cypher);






 
void * aes_encrypt_init(const unsigned char *key, size_t len);






 
void aes_encrypt(void *ctx, const unsigned char *plain, unsigned char *crypt);




 
void aes_encrypt_deinit(void *ctx);






 
void * aes_decrypt_init(const unsigned char *key, size_t len);






 
void aes_decrypt(void *ctx, const unsigned char *crypt, unsigned char *plain);




 
void aes_decrypt_deinit(void *ctx);


enum crypto_hash_alg {
	CRYPTO_HASH_ALG_MD5, CRYPTO_HASH_ALG_SHA1,
	CRYPTO_HASH_ALG_HMAC_MD5, CRYPTO_HASH_ALG_HMAC_SHA1
};

struct crypto_hash;












 
struct crypto_hash * crypto_hash_init(enum crypto_hash_alg alg, const unsigned char *key,
				      size_t key_len);










 
void crypto_hash_update(struct crypto_hash *ctx, const unsigned char *data, size_t len);

















 
int crypto_hash_finish(struct crypto_hash *ctx, unsigned char *hash, size_t *len);


enum crypto_cipher_alg {
	CRYPTO_CIPHER_NULL = 0, CRYPTO_CIPHER_ALG_AES, CRYPTO_CIPHER_ALG_3DES,
	CRYPTO_CIPHER_ALG_DES, CRYPTO_CIPHER_ALG_RC2, CRYPTO_CIPHER_ALG_RC4
};

struct crypto_cipher;













 
struct crypto_cipher * crypto_cipher_init(enum crypto_cipher_alg alg,
					  const unsigned char *iv, const unsigned char *key,
					  size_t key_len);












 
int  crypto_cipher_encrypt(struct crypto_cipher *ctx,
				       const unsigned char *plain, unsigned char *crypt, size_t len);












 
int  crypto_cipher_decrypt(struct crypto_cipher *ctx,
				       const unsigned char *crypt, unsigned char *plain, size_t len);








 
void crypto_cipher_deinit(struct crypto_cipher *ctx);


struct crypto_public_key;
struct crypto_private_key;














 
struct crypto_public_key * crypto_public_key_import(const unsigned char *key, size_t len);











 
struct crypto_private_key * crypto_private_key_import(const unsigned char *key,
						      size_t len,
						      const char *passwd);














 
struct crypto_public_key * crypto_public_key_from_cert(const unsigned char *buf,
						       size_t len);













 
int  crypto_public_key_encrypt_pkcs1_v15(
	struct crypto_public_key *key, const unsigned char *in, size_t inlen,
	unsigned char *out, size_t *outlen);













 
int  crypto_private_key_decrypt_pkcs1_v15(
	struct crypto_private_key *key, const unsigned char *in, size_t inlen,
	unsigned char *out, size_t *outlen);













 
int  crypto_private_key_sign_pkcs1(struct crypto_private_key *key,
					       const unsigned char *in, size_t inlen,
					       unsigned char *out, size_t *outlen);








 
void crypto_public_key_free(struct crypto_public_key *key);








 
void crypto_private_key_free(struct crypto_private_key *key);









 
int  crypto_public_key_decrypt_pkcs1(
	struct crypto_public_key *key, const unsigned char *crypt, size_t crypt_len,
	unsigned char *plain, size_t *plain_len);







 
int  crypto_global_init(void);







 
void crypto_global_deinit(void);




















 
int  crypto_mod_exp(const unsigned char *base, size_t base_len,
				const unsigned char *power, size_t power_len,
				const unsigned char *modulus, size_t modulus_len,
				unsigned char *result, size_t *result_len);













 
int rc4_skip(const unsigned char *key, size_t keylen, size_t skip,
	     unsigned char *data, size_t data_len);

#line 21 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common\\eap_sim_common.c"
#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\crypto/sha1.h"












 






#line 21 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\crypto/sha1.h"

int hmac_sha1_vector(const unsigned char *key, size_t key_len, size_t num_elem,
		     const unsigned char *addr[], const size_t *len, unsigned char *mac);
int hmac_sha1(const unsigned char *key, size_t key_len, const unsigned char *data, size_t data_len,
	       unsigned char *mac);
int sha1_prf(const unsigned char *key, size_t key_len, const char *label,
	     const unsigned char *data, size_t data_len, unsigned char *buf, size_t buf_len);
int sha1_t_prf(const unsigned char *key, size_t key_len, const char *label,
	       const unsigned char *seed, size_t seed_len, unsigned char *buf, size_t buf_len);
int  tls_prf(const unsigned char *secret, size_t secret_len,
			 const char *label, const unsigned char *seed, size_t seed_len,
			 unsigned char *out, size_t outlen);
int pbkdf2_sha1(const char *passphrase, const char *ssid, size_t ssid_len,
		int iterations, unsigned char *buf, size_t buflen);
#line 22 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common\\eap_sim_common.c"
#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\crypto/sha256.h"












 






void hmac_sha256_vector(const unsigned char *key, size_t key_len, size_t num_elem,
		      const unsigned char *addr[], const size_t *len, unsigned char *mac);
void hmac_sha256(const unsigned char *key, size_t key_len, const unsigned char *data,
		 size_t data_len, unsigned char *mac);
void sha256_prf(const unsigned char *key, size_t key_len, const char *label,
	      const unsigned char *data, size_t data_len, unsigned char *buf, size_t buf_len);

#line 23 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common\\eap_sim_common.c"
#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common/eap_defs.h"












 




#line 19 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common/eap_defs.h"

 





struct eap_hdr {
	unsigned char code;
	unsigned char identifier;
	unsigned short length;  
	 
} ;





enum { EAP_CODE_REQUEST = 1, EAP_CODE_RESPONSE = 2, EAP_CODE_SUCCESS = 3,
       EAP_CODE_FAILURE = 4 };


 




 
typedef enum {
	EAP_TYPE_NONE = 0,
	EAP_TYPE_IDENTITY = 1  ,
	EAP_TYPE_NOTIFICATION = 2  ,
	EAP_TYPE_NAK = 3  ,
	EAP_TYPE_MD5 = 4,  
	EAP_TYPE_OTP = 5  ,
	EAP_TYPE_GTC = 6,  
	EAP_TYPE_TLS = 13  ,
	EAP_TYPE_LEAP = 17  ,
	EAP_TYPE_SIM = 18  ,
	EAP_TYPE_TTLS = 21  ,
	EAP_TYPE_AKA = 23  ,
	EAP_TYPE_PEAP = 25  ,
	EAP_TYPE_MSCHAPV2 = 26  ,
	EAP_TYPE_TLV = 33  ,
	EAP_TYPE_TNC = 38 

 ,
	EAP_TYPE_FAST = 43  ,
	EAP_TYPE_PAX = 46  ,
	EAP_TYPE_PSK = 47  ,
	EAP_TYPE_SAKE = 48  ,
	EAP_TYPE_IKEV2 = 49  ,
	EAP_TYPE_AKA_PRIME = 50  ,
	EAP_TYPE_GPSK = 51  ,
	EAP_TYPE_EXPANDED = 254  
} EapType;


 
enum {
	EAP_VENDOR_IETF = 0,
	EAP_VENDOR_MICROSOFT = 0x000137  ,
	EAP_VENDOR_WFA = 0x00372A  
};




#line 24 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common\\eap_sim_common.c"
#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common/eap_sim_common.h"












 




#line 28 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common/eap_sim_common.h"





 






 










 
#line 59 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common/eap_sim_common.h"

 


#line 73 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common/eap_sim_common.h"





struct wpabuf;

void eap_sim_derive_mk(const unsigned char *identity, size_t identity_len,
		       const unsigned char *nonce_mt, unsigned short selected_version,
		       const unsigned char *ver_list, size_t ver_list_len,
		       int num_chal, const unsigned char *kc, unsigned char *mk);
void eap_aka_derive_mk(const unsigned char *identity, size_t identity_len,
		       const unsigned char *ik, const unsigned char *ck, unsigned char *mk);
int eap_sim_derive_keys(const unsigned char *mk, unsigned char *k_encr, unsigned char *k_aut, unsigned char *msk,
			unsigned char *emsk);
int eap_sim_derive_keys_reauth(unsigned short _counter,
			       const unsigned char *identity, size_t identity_len,
			       const unsigned char *nonce_s, const unsigned char *mk, unsigned char *msk,
			       unsigned char *emsk);
int eap_sim_verify_mac(const unsigned char *k_aut, const struct wpabuf *req,
		       const unsigned char *mac, const unsigned char *extra, size_t extra_len);
void eap_sim_add_mac(const unsigned char *k_aut, const unsigned char *msg, size_t msg_len, unsigned char *mac,
		     const unsigned char *extra, size_t extra_len);

#line 114 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common/eap_sim_common.h"
static  void eap_aka_prime_derive_keys(const unsigned char *identity,
					     size_t identity_len,
					     const unsigned char *ik, const unsigned char *ck,
					     unsigned char *k_encr, unsigned char *k_aut, unsigned char *k_re,
					     unsigned char *msk, unsigned char *emsk)
{
}

static  int eap_aka_prime_derive_keys_reauth(const unsigned char *k_re, unsigned short counter,
						   const unsigned char *identity,
						   size_t identity_len,
						   const unsigned char *nonce_s, unsigned char *msk,
						   unsigned char *emsk)
{
	return -1;
}

static  int eap_sim_verify_mac_sha256(const unsigned char *k_aut,
					    const struct wpabuf *req,
					    const unsigned char *mac, const unsigned char *extra,
					    size_t extra_len)
{
	return -1;
}



 
#line 169 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common/eap_sim_common.h"

 






 


 



enum eap_sim_id_req {
	NO_ID_REQ, ANY_ID, FULLAUTH_ID, PERMANENT_ID
};


struct eap_sim_attrs {
	const unsigned char *rand, *autn, *mac, *iv, *encr_data, *version_list, *nonce_s;
	const unsigned char *next_pseudonym, *next_reauth_id;
	const unsigned char *nonce_mt, *identity, *res, *auts;
	const unsigned char *checkcode;
	const unsigned char *kdf_input;
	const unsigned char *bidding;
	size_t num_chal, version_list_len, encr_data_len;
	size_t next_pseudonym_len, next_reauth_id_len, identity_len, res_len;
	size_t res_len_bits;
	size_t checkcode_len;
	size_t kdf_input_len;
	enum eap_sim_id_req id_req;
	int notification, counter, selected_version, client_error_code;
	int counter_too_small;
	int result_ind;

	unsigned short kdf[10];
	size_t kdf_count;
};

int eap_sim_parse_attr(const unsigned char *start, const unsigned char *end,
		       struct eap_sim_attrs *attr, int aka, int encr);
unsigned char * eap_sim_parse_encr(const unsigned char *k_encr, const unsigned char *encr_data,
			size_t encr_data_len, const unsigned char *iv,
			struct eap_sim_attrs *attr, int aka);


struct eap_sim_msg;

struct eap_sim_msg * eap_sim_msg_init(int code, int id, int type, int subtype);
struct wpabuf * eap_sim_msg_finish(struct eap_sim_msg *msg, const unsigned char *k_aut,
				   const unsigned char *extra, size_t extra_len);
void eap_sim_msg_free(struct eap_sim_msg *msg);
unsigned char * eap_sim_msg_add_full(struct eap_sim_msg *msg, unsigned char attr,
			  const unsigned char *data, size_t len);
unsigned char * eap_sim_msg_add(struct eap_sim_msg *msg, unsigned char attr,
		     unsigned short value, const unsigned char *data, size_t len);
unsigned char * eap_sim_msg_add_mac(struct eap_sim_msg *msg, unsigned char attr);
int eap_sim_msg_add_encr_start(struct eap_sim_msg *msg, unsigned char attr_iv,
			       unsigned char attr_encr);
int eap_sim_msg_add_encr_end(struct eap_sim_msg *msg, unsigned char *k_encr,
			     int attr_pad);

void eap_sim_report_notification(void *msg_ctx, int notification, int aka);

#line 25 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common\\eap_sim_common.c"




static int eap_sim_prf(const unsigned char *key, unsigned char *x, size_t xlen)
{
	return fips186_2_prf(key, 20, x, xlen);
}


void eap_sim_derive_mk(const unsigned char *identity, size_t identity_len,
		       const unsigned char *nonce_mt, unsigned short selected_version,
		       const unsigned char *ver_list, size_t ver_list_len,
		       int num_chal, const unsigned char *kc, unsigned char *mk)
{
	unsigned char sel_ver[2];
	const unsigned char *addr[5];
	size_t len[5];

	addr[0] = identity;
	len[0] = identity_len;
	addr[1] = kc;
	len[1] = num_chal * 8;
	addr[2] = nonce_mt;
	len[2] = 16;
	addr[3] = ver_list;
	len[3] = ver_list_len;
	addr[4] = sel_ver;
	len[4] = 2;

	do { (sel_ver)[0] = ((unsigned short) (selected_version)) >> 8; (sel_ver)[1] = ((unsigned short) (selected_version)) & 0xff; } while (0);

	 
	sha1_vector(5, addr, len, mk);
	wpa_hexdump_key(0, "EAP-SIM: MK", mk, 20);
}


void eap_aka_derive_mk(const unsigned char *identity, size_t identity_len,
		       const unsigned char *ik, const unsigned char *ck, unsigned char *mk)
{
	const unsigned char *addr[3];
	size_t len[3];

	addr[0] = identity;
	len[0] = identity_len;
	addr[1] = ik;
	len[1] = 16;
	addr[2] = ck;
	len[2] = 16;

	 
	sha1_vector(3, addr, len, mk);
	wpa_hexdump_key(0, "EAP-AKA: IK", ik, 16);
	wpa_hexdump_key(0, "EAP-AKA: CK", ck, 16);
	wpa_hexdump_key(0, "EAP-AKA: MK", mk, 20);
}


int eap_sim_derive_keys(const unsigned char *mk, unsigned char *k_encr, unsigned char *k_aut, unsigned char *msk, unsigned char *emsk)
{
	unsigned char buf[16 + 16 +
	       64 + 64], *pos;
	if (eap_sim_prf(mk, buf, sizeof(buf)) < 0) {
		wpa_printf(0, "EAP-SIM: Failed to derive keys");
		return -1;
	}
	pos = buf;
	os_memcpy(k_encr, pos, 16);
	pos += 16;
	os_memcpy(k_aut, pos, 16);
	pos += 16;
	os_memcpy(msk, pos, 64);
	pos += 64;
	os_memcpy(emsk, pos, 64);

	wpa_hexdump_key(0, "EAP-SIM: K_encr",
			k_encr, 16);
	wpa_hexdump_key(0, "EAP-SIM: K_aut",
			k_aut, 16);
	wpa_hexdump_key(0, "EAP-SIM: keying material (MSK)",
			msk, 64);
	wpa_hexdump_key(0, "EAP-SIM: EMSK", emsk, 64);
	os_memset(buf, 0, sizeof(buf));

	return 0;
}


int eap_sim_derive_keys_reauth(unsigned short _counter,
			       const unsigned char *identity, size_t identity_len,
			       const unsigned char *nonce_s, const unsigned char *mk, unsigned char *msk,
			       unsigned char *emsk)
{
	unsigned char xkey[20];
	unsigned char buf[64 + 64 + 32];
	unsigned char counter[2];
	const unsigned char *addr[4];
	size_t len[4];

	while (identity_len > 0 && identity[identity_len - 1] == 0) {
		wpa_printf(0, "EAP-SIM: Workaround - drop null "
			   "character from the end of identity");
		identity_len--;
	}
	addr[0] = identity;
	len[0] = identity_len;
	addr[1] = counter;
	len[1] = 2;
	addr[2] = nonce_s;
	len[2] = 16;
	addr[3] = mk;
	len[3] = 20;

	do { (counter)[0] = ((unsigned short) (_counter)) >> 8; (counter)[1] = ((unsigned short) (_counter)) & 0xff; } while (0);

	wpa_printf(0, "EAP-SIM: Deriving keying data from reauth");
	wpa_hexdump_ascii(0, "EAP-SIM: Identity",
			  identity, identity_len);
	wpa_hexdump(0, "EAP-SIM: counter", counter, 2);
	wpa_hexdump(0, "EAP-SIM: NONCE_S", nonce_s,
		    16);
	wpa_hexdump_key(0, "EAP-SIM: MK", mk, 20);

	 
	sha1_vector(4, addr, len, xkey);
	wpa_hexdump(0, "EAP-SIM: XKEY'", xkey, 20);

	if (eap_sim_prf(xkey, buf, sizeof(buf)) < 0) {
		wpa_printf(0, "EAP-SIM: Failed to derive keys");
		return -1;
	}
	if (msk) {
		os_memcpy(msk, buf, 64);
		wpa_hexdump(0, "EAP-SIM: keying material (MSK)",
			    msk, 64);
	}
	if (emsk) {
		os_memcpy(emsk, buf + 64, 64);
		wpa_hexdump(0, "EAP-SIM: EMSK", emsk, 64);
	}
	os_memset(buf, 0, sizeof(buf));

	return 0;
}


int eap_sim_verify_mac(const unsigned char *k_aut, const struct wpabuf *req,
		       const unsigned char *mac, const unsigned char *extra, size_t extra_len)
{
	unsigned char hmac[20];
	const unsigned char *addr[2];
	size_t len[2];
	unsigned char *tmp;

	if (mac == 0 || wpabuf_len(req) < 16 ||
	    mac < wpabuf_head_u8(req) ||
	    mac > wpabuf_head_u8(req) + wpabuf_len(req) - 16)
		return -1;

	tmp = os_malloc(wpabuf_len(req));
	if (tmp == 0)
		return -1;

	addr[0] = tmp;
	len[0] = wpabuf_len(req);
	addr[1] = extra;
	len[1] = extra_len;

	 
	os_memcpy(tmp, wpabuf_head(req), wpabuf_len(req));
	os_memset(tmp + (mac - wpabuf_head_u8(req)), 0, 16);
	wpa_hexdump(0, "EAP-SIM: Verify MAC - msg",
		    tmp, wpabuf_len(req));
	wpa_hexdump(0, "EAP-SIM: Verify MAC - extra data",
		    extra, extra_len);
	wpa_hexdump_key(0, "EAP-SIM: Verify MAC - K_aut",
			k_aut, 16);
	hmac_sha1_vector(k_aut, 16, 2, addr, len, hmac);
	wpa_hexdump(0, "EAP-SIM: Verify MAC: MAC",
		    hmac, 16);
	os_free(tmp);

	return (os_memcmp(hmac, mac, 16) == 0) ? 0 : 1;
}


void eap_sim_add_mac(const unsigned char *k_aut, const unsigned char *msg, size_t msg_len, unsigned char *mac,
		     const unsigned char *extra, size_t extra_len)
{
	unsigned char hmac[20];
	const unsigned char *addr[2];
	size_t len[2];

	addr[0] = msg;
	len[0] = msg_len;
	addr[1] = extra;
	len[1] = extra_len;

	 
	os_memset(mac, 0, 16);
	wpa_hexdump(0, "EAP-SIM: Add MAC - msg", msg, msg_len);
	wpa_hexdump(0, "EAP-SIM: Add MAC - extra data",
		    extra, extra_len);
	wpa_hexdump_key(0, "EAP-SIM: Add MAC - K_aut",
			k_aut, 16);
	hmac_sha1_vector(k_aut, 16, 2, addr, len, hmac);
	os_memcpy(mac, hmac, 16);
	wpa_hexdump(0, "EAP-SIM: Add MAC: MAC",
		    mac, 16);
}


#line 502 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common\\eap_sim_common.c"


int eap_sim_parse_attr(const unsigned char *start, const unsigned char *end,
		       struct eap_sim_attrs *attr, int aka, int encr)
{
	const unsigned char *pos = start, *apos;
	size_t alen, plen, i, list_len;

	os_memset(attr, 0, sizeof(*attr));
	attr->id_req = NO_ID_REQ;
	attr->notification = -1;
	attr->counter = -1;
	attr->selected_version = -1;
	attr->client_error_code = -1;

	while (pos < end) {
		if (pos + 2 > end) {
			wpa_printf(0, "EAP-SIM: Attribute overflow(1)");
			return -1;
		}
		wpa_printf(0, "EAP-SIM: Attribute: Type=%d Len=%d",
			   pos[0], pos[1] * 4);
		if (pos + pos[1] * 4 > end) {
			wpa_printf(0, "EAP-SIM: Attribute overflow "
				   "(pos=%p len=%d end=%p)",
				   pos, pos[1] * 4, end);
			return -1;
		}
		if (pos[1] == 0) {
			wpa_printf(0, "EAP-SIM: Attribute underflow");
			return -1;
		}
		apos = pos + 2;
		alen = pos[1] * 4 - 2;
		wpa_hexdump(0, "EAP-SIM: Attribute data",
			    apos, alen);

		switch (pos[0]) {
		case 1:
			wpa_printf(0, "EAP-SIM: AT_RAND");
			apos += 2;
			alen -= 2;
			if ((!aka && (alen % 16)) ||
			    (aka && alen != 16)) {
				wpa_printf(0, "EAP-SIM: Invalid AT_RAND"
					   " (len %lu)",
					   (unsigned long) alen);
				return -1;
			}
			attr->rand = apos;
			attr->num_chal = alen / 16;
			break;
		case 2:
			wpa_printf(0, "EAP-AKA: AT_AUTN");
			if (!aka) {
				wpa_printf(0, "EAP-SIM: "
					   "Unexpected AT_AUTN");
				return -1;
			}
			apos += 2;
			alen -= 2;
			if (alen != 16) {
				wpa_printf(0, "EAP-AKA: Invalid AT_AUTN"
					   " (len %lu)",
					   (unsigned long) alen);
				return -1;
			}
			attr->autn = apos;
			break;
		case 6:
			if (!encr) {
				wpa_printf(0, "EAP-SIM: Unencrypted "
					   "AT_PADDING");
				return -1;
			}
			wpa_printf(0, "EAP-SIM: (encr) AT_PADDING");
			for (i = 2; i < alen; i++) {
				if (apos[i] != 0) {
					wpa_printf(0, "EAP-SIM: (encr) "
						   "AT_PADDING used a non-zero"
						   " padding byte");
					wpa_hexdump(0, "EAP-SIM: "
						    "(encr) padding bytes",
						    apos + 2, alen - 2);
					return -1;
				}
			}
			break;
		case 7:
			wpa_printf(0, "EAP-SIM: AT_NONCE_MT");
			if (alen != 2 + 16) {
				wpa_printf(0, "EAP-SIM: Invalid "
					   "AT_NONCE_MT length");
				return -1;
			}
			attr->nonce_mt = apos + 2;
			break;
		case 10:
			wpa_printf(0, "EAP-SIM: AT_PERMANENT_ID_REQ");
			attr->id_req = PERMANENT_ID;
			break;
		case 11:
			wpa_printf(0, "EAP-SIM: AT_MAC");
			if (alen != 2 + 16) {
				wpa_printf(0, "EAP-SIM: Invalid AT_MAC "
					   "length");
				return -1;
			}
			attr->mac = apos + 2;
			break;
		case 12:
			if (alen != 2) {
				wpa_printf(0, "EAP-SIM: Invalid "
					   "AT_NOTIFICATION length %lu",
					   (unsigned long) alen);
				return -1;
			}
			attr->notification = apos[0] * 256 + apos[1];
			wpa_printf(0, "EAP-SIM: AT_NOTIFICATION %d",
				   attr->notification);
			break;
		case 13:
			wpa_printf(0, "EAP-SIM: AT_ANY_ID_REQ");
			attr->id_req = ANY_ID;
			break;
		case 14:
			wpa_printf(0, "EAP-SIM: AT_IDENTITY");
			plen = ((unsigned short) (((apos)[0] << 8) | (apos)[1]));
			apos += 2;
			alen -= 2;
			if (plen > alen) {
				wpa_printf(0, "EAP-SIM: Invalid "
					   "AT_IDENTITY (Actual Length %lu, "
					   "remaining length %lu)",
					   (unsigned long) plen,
					   (unsigned long) alen);
				return -1;
			}

			attr->identity = apos;
			attr->identity_len = plen;
			break;
		case 15:
			if (aka) {
				wpa_printf(0, "EAP-AKA: "
					   "Unexpected AT_VERSION_LIST");
				return -1;
			}
			list_len = apos[0] * 256 + apos[1];
			wpa_printf(0, "EAP-SIM: AT_VERSION_LIST");
			if (list_len < 2 || list_len > alen - 2) {
				wpa_printf(0, "EAP-SIM: Invalid "
					   "AT_VERSION_LIST (list_len=%lu "
					   "attr_len=%lu)",
					   (unsigned long) list_len,
					   (unsigned long) alen);
				return -1;
			}
			attr->version_list = apos + 2;
			attr->version_list_len = list_len;
			break;
		case 16:
			wpa_printf(0, "EAP-SIM: AT_SELECTED_VERSION");
			if (alen != 2) {
				wpa_printf(0, "EAP-SIM: Invalid "
					   "AT_SELECTED_VERSION length %lu",
					   (unsigned long) alen);
				return -1;
			}
			attr->selected_version = apos[0] * 256 + apos[1];
			wpa_printf(0, "EAP-SIM: AT_SELECTED_VERSION "
				   "%d", attr->selected_version);
			break;
		case 17:
			wpa_printf(0, "EAP-SIM: AT_FULLAUTH_ID_REQ");
			attr->id_req = FULLAUTH_ID;
			break;
		case 19:
			if (!encr) {
				wpa_printf(0, "EAP-SIM: Unencrypted "
					   "AT_COUNTER");
				return -1;
			}
			if (alen != 2) {
				wpa_printf(0, "EAP-SIM: (encr) Invalid "
					   "AT_COUNTER (alen=%lu)",
					   (unsigned long) alen);
				return -1;
			}
			attr->counter = apos[0] * 256 + apos[1];
			wpa_printf(0, "EAP-SIM: (encr) AT_COUNTER %d",
				   attr->counter);
			break;
		case 20:
			if (!encr) {
				wpa_printf(0, "EAP-SIM: Unencrypted "
					   "AT_COUNTER_TOO_SMALL");
				return -1;
			}
			if (alen != 2) {
				wpa_printf(0, "EAP-SIM: (encr) Invalid "
					   "AT_COUNTER_TOO_SMALL (alen=%lu)",
					   (unsigned long) alen);
				return -1;
			}
			wpa_printf(0, "EAP-SIM: (encr) "
				   "AT_COUNTER_TOO_SMALL");
			attr->counter_too_small = 1;
			break;
		case 21:
			if (!encr) {
				wpa_printf(0, "EAP-SIM: Unencrypted "
					   "AT_NONCE_S");
				return -1;
			}
			wpa_printf(0, "EAP-SIM: (encr) "
				   "AT_NONCE_S");
			if (alen != 2 + 16) {
				wpa_printf(0, "EAP-SIM: (encr) Invalid "
					   "AT_NONCE_S (alen=%lu)",
					   (unsigned long) alen);
				return -1;
			}
			attr->nonce_s = apos + 2;
			break;
		case 22:
			if (alen != 2) {
				wpa_printf(0, "EAP-SIM: Invalid "
					   "AT_CLIENT_ERROR_CODE length %lu",
					   (unsigned long) alen);
				return -1;
			}
			attr->client_error_code = apos[0] * 256 + apos[1];
			wpa_printf(0, "EAP-SIM: AT_CLIENT_ERROR_CODE "
				   "%d", attr->client_error_code);
			break;
		case 129:
			wpa_printf(0, "EAP-SIM: AT_IV");
			if (alen != 2 + 16) {
				wpa_printf(0, "EAP-SIM: Invalid AT_IV "
					   "length %lu", (unsigned long) alen);
				return -1;
			}
			attr->iv = apos + 2;
			break;
		case 130:
			wpa_printf(0, "EAP-SIM: AT_ENCR_DATA");
			attr->encr_data = apos + 2;
			attr->encr_data_len = alen - 2;
			if (attr->encr_data_len % 16) {
				wpa_printf(0, "EAP-SIM: Invalid "
					   "AT_ENCR_DATA length %lu",
					   (unsigned long)
					   attr->encr_data_len);
				return -1;
			}
			break;
		case 132:
			if (!encr) {
				wpa_printf(0, "EAP-SIM: Unencrypted "
					   "AT_NEXT_PSEUDONYM");
				return -1;
			}
			wpa_printf(0, "EAP-SIM: (encr) "
				   "AT_NEXT_PSEUDONYM");
			plen = apos[0] * 256 + apos[1];
			if (plen > alen - 2) {
				wpa_printf(0, "EAP-SIM: (encr) Invalid"
					   " AT_NEXT_PSEUDONYM (actual"
					   " len %lu, attr len %lu)",
					   (unsigned long) plen,
					   (unsigned long) alen);
				return -1;
			}
			attr->next_pseudonym = pos + 4;
			attr->next_pseudonym_len = plen;
			break;
		case 133:
			if (!encr) {
				wpa_printf(0, "EAP-SIM: Unencrypted "
					   "AT_NEXT_REAUTH_ID");
				return -1;
			}
			wpa_printf(0, "EAP-SIM: (encr) "
				   "AT_NEXT_REAUTH_ID");
			plen = apos[0] * 256 + apos[1];
			if (plen > alen - 2) {
				wpa_printf(0, "EAP-SIM: (encr) Invalid"
					   " AT_NEXT_REAUTH_ID (actual"
					   " len %lu, attr len %lu)",
					   (unsigned long) plen,
					   (unsigned long) alen);
				return -1;
			}
			attr->next_reauth_id = pos + 4;
			attr->next_reauth_id_len = plen;
			break;
		case 3:
			wpa_printf(0, "EAP-SIM: AT_RES");
			attr->res_len_bits = ((unsigned short) (((apos)[0] << 8) | (apos)[1]));
			apos += 2;
			alen -= 2;
			if (!aka || alen < 4 ||
			    alen > 16) {
				wpa_printf(0, "EAP-SIM: Invalid AT_RES "
					   "(len %lu)",
					   (unsigned long) alen);
				return -1;
			}
			attr->res = apos;
			attr->res_len = alen;
			break;
		case 4:
			wpa_printf(0, "EAP-AKA: AT_AUTS");
			if (!aka) {
				wpa_printf(0, "EAP-SIM: "
					   "Unexpected AT_AUTS");
				return -1;
			}
			if (alen != 14) {
				wpa_printf(0, "EAP-AKA: Invalid AT_AUTS"
					   " (len %lu)",
					   (unsigned long) alen);
				return -1;
			}
			attr->auts = apos;
			break;
		case 134:
			wpa_printf(0, "EAP-AKA: AT_CHECKCODE");
			if (!aka) {
				wpa_printf(0, "EAP-SIM: "
					   "Unexpected AT_CHECKCODE");
				return -1;
			}
			apos += 2;
			alen -= 2;
			if (alen != 0 && alen != 20 &&
			    alen != 32) {
				wpa_printf(0, "EAP-AKA: Invalid "
					   "AT_CHECKCODE (len %lu)",
					   (unsigned long) alen);
				return -1;
			}
			attr->checkcode = apos;
			attr->checkcode_len = alen;
			break;
		case 135:
			if (encr) {
				wpa_printf(0, "EAP-SIM: Encrypted "
					   "AT_RESULT_IND");
				return -1;
			}
			if (alen != 2) {
				wpa_printf(0, "EAP-SIM: Invalid "
					   "AT_RESULT_IND (alen=%lu)",
					   (unsigned long) alen);
				return -1;
			}
			wpa_printf(0, "EAP-SIM: AT_RESULT_IND");
			attr->result_ind = 1;
			break;
#line 919 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common\\eap_sim_common.c"
		default:
			if (pos[0] < 128) {
				wpa_printf(0, "EAP-SIM: Unrecognized "
					   "non-skippable attribute %d",
					   pos[0]);
				return -1;
			}

			wpa_printf(0, "EAP-SIM: Unrecognized skippable"
				   " attribute %d ignored", pos[0]);
			break;
		}

		pos += pos[1] * 4;
	}

	wpa_printf(0, "EAP-SIM: Attributes parsed successfully "
		   "(aka=%d encr=%d)", aka, encr);

	return 0;
}


unsigned char * eap_sim_parse_encr(const unsigned char *k_encr, const unsigned char *encr_data,
			size_t encr_data_len, const unsigned char *iv,
			struct eap_sim_attrs *attr, int aka)
{
	unsigned char *decrypted;

	if (!iv) {
		wpa_printf(0, "EAP-SIM: Encrypted data, but no IV");
		return 0;
	}

	decrypted = os_malloc(encr_data_len);
	if (decrypted == 0)
		return 0;
	os_memcpy(decrypted, encr_data, encr_data_len);

	if (aes_128_cbc_decrypt(k_encr, iv, decrypted, encr_data_len)) {
		os_free(decrypted);
		return 0;
	}
	wpa_hexdump(0, "EAP-SIM: Decrypted AT_ENCR_DATA",
		    decrypted, encr_data_len);

	if (eap_sim_parse_attr(decrypted, decrypted + encr_data_len, attr,
			       aka, 1)) {
		wpa_printf(0, "EAP-SIM: (encr) Failed to parse "
			   "decrypted AT_ENCR_DATA");
		os_free(decrypted);
		return 0;
	}

	return decrypted;
}




struct eap_sim_msg {
	struct wpabuf *buf;
	size_t mac, iv, encr;  
	int type;
};


struct eap_sim_msg * eap_sim_msg_init(int code, int id, int type, int subtype)
{
	struct eap_sim_msg *msg;
	struct eap_hdr *eap;
	unsigned char *pos;

	msg = os_zalloc(sizeof(*msg));
	if (msg == 0)
		return 0;

	msg->type = type;
	msg->buf = wpabuf_alloc(128);
	if (msg->buf == 0) {
		os_free(msg);
		return 0;
	}
	eap = wpabuf_put(msg->buf, sizeof(*eap));
	eap->code = code;
	eap->identifier = id;

	pos = wpabuf_put(msg->buf, 4);
	*pos++ = type;
	*pos++ = subtype;
	*pos++ = 0;  
	*pos++ = 0;  

	return msg;
}


struct wpabuf * eap_sim_msg_finish(struct eap_sim_msg *msg, const unsigned char *k_aut,
				   const unsigned char *extra, size_t extra_len)
{
	struct eap_hdr *eap;
	struct wpabuf *buf;

	if (msg == 0)
		return 0;

	eap = wpabuf_mhead(msg->buf);
	eap->length = (( unsigned short) ((((unsigned short) ((wpabuf_len(msg->buf))) << 8) & 0xff00) | (((unsigned short) ((wpabuf_len(msg->buf))) >> 8) & 0xff)));

#line 1036 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common\\eap_sim_common.c"
	if (k_aut && msg->mac) {
		eap_sim_add_mac(k_aut, (unsigned char *) wpabuf_head(msg->buf),
				wpabuf_len(msg->buf),
				(unsigned char *) wpabuf_mhead(msg->buf) + msg->mac,
				extra, extra_len);
	}

	buf = msg->buf;
	os_free(msg);
	return buf;
}


void eap_sim_msg_free(struct eap_sim_msg *msg)
{
	if (msg) {
		wpabuf_free(msg->buf);
		os_free(msg);
	}
}


unsigned char * eap_sim_msg_add_full(struct eap_sim_msg *msg, unsigned char attr,
			  const unsigned char *data, size_t len)
{
	int attr_len = 2 + len;
	int pad_len;
	unsigned char *start;

	if (msg == 0)
		return 0;

	pad_len = (4 - attr_len % 4) % 4;
	attr_len += pad_len;
	if (wpabuf_resize(&msg->buf, attr_len))
		return 0;
	start = wpabuf_put(msg->buf, 0);
	wpabuf_put_u8(msg->buf, attr);
	wpabuf_put_u8(msg->buf, attr_len / 4);
	wpabuf_put_data(msg->buf, data, len);
	if (pad_len)
		os_memset(wpabuf_put(msg->buf, pad_len), 0, pad_len);
	return start;
}


unsigned char * eap_sim_msg_add(struct eap_sim_msg *msg, unsigned char attr, unsigned short value,
		     const unsigned char *data, size_t len)
{
	int attr_len = 4 + len;
	int pad_len;
	unsigned char *start;

	if (msg == 0)
		return 0;

	pad_len = (4 - attr_len % 4) % 4;
	attr_len += pad_len;
	if (wpabuf_resize(&msg->buf, attr_len))
		return 0;
	start = wpabuf_put(msg->buf, 0);
	wpabuf_put_u8(msg->buf, attr);
	wpabuf_put_u8(msg->buf, attr_len / 4);
	wpabuf_put_be16(msg->buf, value);
	if (data)
		wpabuf_put_data(msg->buf, data, len);
	else
		wpabuf_put(msg->buf, len);
	if (pad_len)
		os_memset(wpabuf_put(msg->buf, pad_len), 0, pad_len);
	return start;
}


unsigned char * eap_sim_msg_add_mac(struct eap_sim_msg *msg, unsigned char attr)
{
	unsigned char *pos = eap_sim_msg_add(msg, attr, 0, 0, 16);
	if (pos)
		msg->mac = (pos - wpabuf_head_u8(msg->buf)) + 4;
	return pos;
}


int eap_sim_msg_add_encr_start(struct eap_sim_msg *msg, unsigned char attr_iv,
			       unsigned char attr_encr)
{
	unsigned char *pos = eap_sim_msg_add(msg, attr_iv, 0, 0, 16);
	if (pos == 0)
		return -1;
	msg->iv = (pos - wpabuf_head_u8(msg->buf)) + 4;
	if (os_get_random(wpabuf_mhead_u8(msg->buf) + msg->iv,
			  16)) {
		msg->iv = 0;
		return -1;
	}

	pos = eap_sim_msg_add(msg, attr_encr, 0, 0, 0);
	if (pos == 0) {
		msg->iv = 0;
		return -1;
	}
	msg->encr = pos - wpabuf_head_u8(msg->buf);

	return 0;
}


int eap_sim_msg_add_encr_end(struct eap_sim_msg *msg, unsigned char *k_encr, int attr_pad)
{
	size_t encr_len;

	if (msg == 0 || k_encr == 0 || msg->iv == 0 || msg->encr == 0)
		return -1;

	encr_len = wpabuf_len(msg->buf) - msg->encr - 4;
	if (encr_len % 16) {
		unsigned char *pos;
		int pad_len = 16 - (encr_len % 16);
		if (pad_len < 4) {
			wpa_printf(0, "EAP-SIM: "
				   "eap_sim_msg_add_encr_end - invalid pad_len"
				   " %d", pad_len);
			return -1;
		}
		wpa_printf(0, "   *AT_PADDING");
		pos = eap_sim_msg_add(msg, attr_pad, 0, 0, pad_len - 4);
		if (pos == 0)
			return -1;
		os_memset(pos + 4, 0, pad_len - 4);
		encr_len += pad_len;
	}
	wpa_printf(0, "   (AT_ENCR_DATA data len %lu)",
		   (unsigned long) encr_len);
	wpabuf_mhead_u8(msg->buf)[msg->encr + 1] = encr_len / 4 + 1;
	return aes_128_cbc_encrypt(k_encr, wpabuf_head_u8(msg->buf) + msg->iv,
				   wpabuf_mhead_u8(msg->buf) + msg->encr + 4,
				   encr_len);
}


void eap_sim_report_notification(void *msg_ctx, int notification, int aka)
{

	const char *type = aka ? "AKA" : "SIM";


	switch (notification) {
	case 0:
		wpa_printf(0, "EAP-%s: General failure "
			   "notification (after authentication)", type);
		break;
	case 1026:
		wpa_printf(0, "EAP-%s: Failure notification: "
			   "User has been temporarily denied access to the "
			   "requested service", type);
		break;
	case 1031:
		wpa_printf(0, "EAP-%s: Failure notification: "
			   "User has not subscribed to the requested service",
			   type);
		break;
	case 16384:
		wpa_printf(0, "EAP-%s: General failure "
			   "notification (before authentication)", type);
		break;
	case 32768:
		wpa_printf(0, "EAP-%s: Successful authentication "
			   "notification", type);
		break;
	default:
		if (notification >= 32768) {
			wpa_printf(0, "EAP-%s: Unrecognized "
				   "non-failure notification %d",
				   type, notification);
		} else {
			wpa_printf(0, "EAP-%s: Unrecognized "
				   "failure notification %d",
				   type, notification);
		}
	}
}
