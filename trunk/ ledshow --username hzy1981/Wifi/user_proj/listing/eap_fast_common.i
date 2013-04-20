#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common\\eap_fast_common.c"












 

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

#line 16 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common\\eap_fast_common.c"

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



#line 18 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common\\eap_fast_common.c"
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
#line 19 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common\\eap_fast_common.c"
#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\crypto/tls.h"












 




#line 19 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\crypto/tls.h"

struct tls_connection;

struct tls_keys {
	const unsigned char *master_key;  
	size_t master_key_len;
	const unsigned char *client_random;
	size_t client_random_len;
	const unsigned char *server_random;
	size_t server_random_len;
	const unsigned char *inner_secret;  
	size_t inner_secret_len;
};

enum tls_event {
	TLS_CERT_CHAIN_FAILURE,
	TLS_PEER_CERTIFICATE
};




 
enum tls_fail_reason {
	TLS_FAIL_UNSPECIFIED = 0,
	TLS_FAIL_UNTRUSTED = 1,
	TLS_FAIL_REVOKED = 2,
	TLS_FAIL_NOT_YET_VALID = 3,
	TLS_FAIL_EXPIRED = 4,
	TLS_FAIL_SUBJECT_MISMATCH = 5,
	TLS_FAIL_ALTSUBJECT_MISMATCH = 6,
	TLS_FAIL_BAD_CERTIFICATE = 7,
	TLS_FAIL_SERVER_CHAIN_PROBE = 8
};

union tls_event_data {
	struct {
		int depth;
		const char *subject;
		enum tls_fail_reason reason;
		const char *reason_txt;
		const struct wpabuf *cert;
	} cert_fail;

	struct {
		int depth;
		const char *subject;
		const struct wpabuf *cert;
		const unsigned char *hash;
		size_t hash_len;
	} peer_cert;
};

struct tls_config {
	const char *opensc_engine_path;
	const char *pkcs11_engine_path;
	const char *pkcs11_module_path;
	int fips_mode;

	void (*event_cb)(void *ctx, enum tls_event ev,
			 union tls_event_data *data);
	void *cb_ctx;
};















































 
struct tls_connection_params {
	const char *ca_cert;
	const unsigned char *ca_cert_blob;
	size_t ca_cert_blob_len;
	const char *ca_path;
	const char *subject_match;
	const char *altsubject_match;
	const char *client_cert;
	const unsigned char *client_cert_blob;
	size_t client_cert_blob_len;
	const char *private_key;
	const unsigned char *private_key_blob;
	size_t private_key_blob_len;
	const char *private_key_passwd;
	const char *dh_file;
	const unsigned char *dh_blob;
	size_t dh_blob_len;
	int tls_ia;

	 
	int engine;
	const char *engine_id;
	const char *pin;
	const char *key_id;
	const char *cert_id;
	const char *ca_cert_id;

	unsigned int flags;
};













 
void * tls_init(const struct tls_config *conf);










 
void tls_deinit(void *tls_ctx);







 
int tls_get_errors(void *tls_ctx);





 
struct tls_connection * tls_connection_init(void *tls_ctx);







 
void tls_connection_deinit(void *tls_ctx, struct tls_connection *conn);






 
int tls_connection_established(void *tls_ctx, struct tls_connection *conn);











 
int tls_connection_shutdown(void *tls_ctx, struct tls_connection *conn);

enum {
	TLS_SET_PARAMS_ENGINE_PRV_VERIFY_FAILED = -3,
	TLS_SET_PARAMS_ENGINE_PRV_INIT_FAILED = -2
};











 
int 
tls_connection_set_params(void *tls_ctx, struct tls_connection *conn,
			  const struct tls_connection_params *params);










 
int  tls_global_set_params(
	void *tls_ctx, const struct tls_connection_params *params);







 
int  tls_global_set_verify(void *tls_ctx, int check_crl);







 
int  tls_connection_set_verify(void *tls_ctx,
					   struct tls_connection *conn,
					   int verify_peer);










 
int  tls_connection_set_ia(void *tls_ctx,
				       struct tls_connection *conn,
				       int tls_ia);







 
int  tls_connection_get_keys(void *tls_ctx,
					 struct tls_connection *conn,
					 struct tls_keys *keys);




















 
int   tls_connection_prf(void *tls_ctx,
				     struct tls_connection *conn,
				     const char *label,
				     int server_random_first,
				     unsigned char *out, size_t out_len);



























 
struct wpabuf * tls_connection_handshake(void *tls_ctx,
					 struct tls_connection *conn,
					 const struct wpabuf *in_data,
					 struct wpabuf **appl_data);










 
struct wpabuf * tls_connection_server_handshake(void *tls_ctx,
						struct tls_connection *conn,
						const struct wpabuf *in_data,
						struct wpabuf **appl_data);











 
struct wpabuf * tls_connection_encrypt(void *tls_ctx,
				       struct tls_connection *conn,
				       const struct wpabuf *in_data);











 
struct wpabuf * tls_connection_decrypt(void *tls_ctx,
				       struct tls_connection *conn,
				       const struct wpabuf *in_data);






 
int tls_connection_resumed(void *tls_ctx, struct tls_connection *conn);

enum {
	TLS_CIPHER_NONE,
	TLS_CIPHER_RC4_SHA  ,
	TLS_CIPHER_AES128_SHA  ,
	TLS_CIPHER_RSA_DHE_AES128_SHA  ,
	TLS_CIPHER_ANON_DH_AES128_SHA  
};








 
int  tls_connection_set_cipher_list(void *tls_ctx,
						struct tls_connection *conn,
						unsigned char *ciphers);










 
int  tls_get_cipher(void *tls_ctx, struct tls_connection *conn,
				char *buf, size_t buflen);









 
int  tls_connection_enable_workaround(void *tls_ctx,
						  struct tls_connection *conn);









 
int  tls_connection_client_hello_ext(void *tls_ctx,
						 struct tls_connection *conn,
						 int ext_type, const unsigned char *data,
						 size_t data_len);







 
int tls_connection_get_failed(void *tls_ctx, struct tls_connection *conn);







 
int tls_connection_get_read_alerts(void *tls_ctx, struct tls_connection *conn);







 
int tls_connection_get_write_alerts(void *tls_ctx,
				    struct tls_connection *conn);







 
int tls_connection_get_keyblock_size(void *tls_ctx,
				     struct tls_connection *conn);






 
unsigned int tls_capabilities(void *tls_ctx);










 
struct wpabuf * tls_connection_ia_send_phase_finished(
	void *tls_ctx, struct tls_connection *conn, int final);







 
int  tls_connection_ia_final_phase_finished(
	void *tls_ctx, struct tls_connection *conn);









 
int  tls_connection_ia_permute_inner_secret(
	void *tls_ctx, struct tls_connection *conn,
	const unsigned char *key, size_t key_len);

typedef int (*tls_session_ticket_cb)
(void *ctx, const unsigned char *ticket, size_t len, const unsigned char *client_random,
 const unsigned char *server_random, unsigned char *master_secret);

int   tls_connection_set_session_ticket_cb(
	void *tls_ctx, struct tls_connection *conn,
	tls_session_ticket_cb cb, void *ctx);

#line 20 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common\\eap_fast_common.c"
#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common\\eap_defs.h"












 




#line 19 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common\\eap_defs.h"

 





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




#line 21 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common\\eap_fast_common.c"
#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common\\eap_tlv_common.h"












 




 
#line 37 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common\\eap_tlv_common.h"











struct eap_tlv_hdr {
	unsigned short tlv_type;
	unsigned short length;
} ;

struct eap_tlv_nak_tlv {
	unsigned short tlv_type;
	unsigned short length;
	unsigned int vendor_id;
	unsigned short nak_type;
} ;

struct eap_tlv_result_tlv {
	unsigned short tlv_type;
	unsigned short length;
	unsigned short status;
} ;

 
struct eap_tlv_intermediate_result_tlv {
	unsigned short tlv_type;
	unsigned short length;
	unsigned short status;
	 
} ;

 
struct eap_tlv_crypto_binding_tlv {
	unsigned short tlv_type;
	unsigned short length;
	unsigned char reserved;
	unsigned char version;
	unsigned char received_version;
	unsigned char subtype;
	unsigned char nonce[32];
	unsigned char compound_mac[20];
} ;

struct eap_tlv_pac_ack_tlv {
	unsigned short tlv_type;
	unsigned short length;
	unsigned short pac_type;
	unsigned short pac_len;
	unsigned short result;
} ;

 
struct eap_tlv_request_action_tlv {
	unsigned short tlv_type;
	unsigned short length;
	unsigned short action;
} ;

 
struct eap_tlv_pac_type_tlv {
	unsigned short tlv_type;  
	unsigned short length;
	unsigned short pac_type;
} ;











#line 22 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common\\eap_fast_common.c"
#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common\\eap_fast_common.h"












 
















 








 









struct pac_tlv_hdr {
	unsigned short type;
	unsigned short len;
} ;








 

 
 

 
 






 
struct eap_fast_key_block_provisioning {
	 
	unsigned char session_key_seed[40];
	unsigned char server_challenge[16];  
	unsigned char client_challenge[16];  
};


struct wpabuf;
struct tls_connection;

struct eap_fast_tlv_parse {
	unsigned char *eap_payload_tlv;
	size_t eap_payload_tlv_len;
	struct eap_tlv_crypto_binding_tlv *crypto_binding;
	size_t crypto_binding_len;
	int iresult;
	int result;
	int request_action;
	unsigned char *pac;
	size_t pac_len;
};

void eap_fast_put_tlv_hdr(struct wpabuf *buf, unsigned short type, unsigned short len);
void eap_fast_put_tlv(struct wpabuf *buf, unsigned short type, const void *data,
		      unsigned short len);
void eap_fast_put_tlv_buf(struct wpabuf *buf, unsigned short type,
			  const struct wpabuf *data);
struct wpabuf * eap_fast_tlv_eap_payload(struct wpabuf *buf);
void eap_fast_derive_master_secret(const unsigned char *pac_key, const unsigned char *server_random,
				   const unsigned char *client_random, unsigned char *master_secret);
unsigned char * eap_fast_derive_key(void *ssl_ctx, struct tls_connection *conn,
			 const char *label, size_t len);
void eap_fast_derive_eap_msk(const unsigned char *simck, unsigned char *msk);
void eap_fast_derive_eap_emsk(const unsigned char *simck, unsigned char *emsk);
int eap_fast_parse_tlv(struct eap_fast_tlv_parse *tlv,
		       int tlv_type, unsigned char *pos, int len);

#line 23 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common\\eap_fast_common.c"


void eap_fast_put_tlv_hdr(struct wpabuf *buf, unsigned short type, unsigned short len)
{
	struct pac_tlv_hdr hdr;
	hdr.type = (( unsigned short) ((((unsigned short) ((type)) << 8) & 0xff00) | (((unsigned short) ((type)) >> 8) & 0xff)));
	hdr.len = (( unsigned short) ((((unsigned short) ((len)) << 8) & 0xff00) | (((unsigned short) ((len)) >> 8) & 0xff)));
	wpabuf_put_data(buf, &hdr, sizeof(hdr));
}


void eap_fast_put_tlv(struct wpabuf *buf, unsigned short type, const void *data,
			     unsigned short len)
{
	eap_fast_put_tlv_hdr(buf, type, len);
	wpabuf_put_data(buf, data, len);
}


void eap_fast_put_tlv_buf(struct wpabuf *buf, unsigned short type,
				 const struct wpabuf *data)
{
	eap_fast_put_tlv_hdr(buf, type, wpabuf_len(data));
	wpabuf_put_buf(buf, data);
}


struct wpabuf * eap_fast_tlv_eap_payload(struct wpabuf *buf)
{
	struct wpabuf *e;

	if (buf == 0)
		return 0;

	 
	wpa_printf(0, "EAP-FAST: Add EAP-Payload TLV");
	e = wpabuf_alloc(sizeof(struct pac_tlv_hdr) + wpabuf_len(buf));
	if (e == 0) {
		wpa_printf(0, "EAP-FAST: Failed to allocate memory "
			   "for TLV encapsulation");
		wpabuf_free(buf);
		return 0;
	}
	eap_fast_put_tlv_buf(e,
			     0x8000 | 9,
			     buf);
	wpabuf_free(buf);
	return e;
}


void eap_fast_derive_master_secret(const unsigned char *pac_key, const unsigned char *server_random,
				   const unsigned char *client_random, unsigned char *master_secret)
{


	unsigned char seed[2 * 32];

	wpa_hexdump(0, "EAP-FAST: client_random",
		    client_random, 32);
	wpa_hexdump(0, "EAP-FAST: server_random",
		    server_random, 32);

	



 
	os_memcpy(seed, server_random, 32);
	os_memcpy(seed + 32, client_random, 32);
	sha1_t_prf(pac_key, 32,
		   "PAC to master secret label hash",
		   seed, sizeof(seed), master_secret, 48);

	wpa_hexdump_key(0, "EAP-FAST: master_secret",
			master_secret, 48);
}


unsigned char * eap_fast_derive_key(void *ssl_ctx, struct tls_connection *conn,
			 const char *label, size_t len)
{
	struct tls_keys keys;
	unsigned char *rnd = 0, *out;
	int block_size;

	block_size = tls_connection_get_keyblock_size(ssl_ctx, conn);
	if (block_size < 0)
		return 0;

	out = os_malloc(block_size + len);
	if (out == 0)
		return 0;

	if (tls_connection_prf(ssl_ctx, conn, label, 1, out, block_size + len)
	    == 0) {
		os_memmove(out, out + block_size, len);
		return out;
	}

	if (tls_connection_get_keys(ssl_ctx, conn, &keys))
		goto fail;

	rnd = os_malloc(keys.client_random_len + keys.server_random_len);
	if (rnd == 0)
		goto fail;

	os_memcpy(rnd, keys.server_random, keys.server_random_len);
	os_memcpy(rnd + keys.server_random_len, keys.client_random,
		  keys.client_random_len);

	wpa_hexdump_key(0, "EAP-FAST: master_secret for key "
			"expansion", keys.master_key, keys.master_key_len);
	if (tls_prf(keys.master_key, keys.master_key_len,
		    label, rnd, keys.client_random_len +
		    keys.server_random_len, out, block_size + len))
		goto fail;
	os_free(rnd);
	os_memmove(out, out + block_size, len);
	return out;

fail:
	os_free(rnd);
	os_free(out);
	return 0;
}


void eap_fast_derive_eap_msk(const unsigned char *simck, unsigned char *msk)
{
	


 

	sha1_t_prf(simck, 40,
		   "Session Key Generating Function", (unsigned char *) "", 0,
		   msk, 64);
	wpa_hexdump_key(0, "EAP-FAST: Derived key (MSK)",
			msk, 64);
}


void eap_fast_derive_eap_emsk(const unsigned char *simck, unsigned char *emsk)
{
	



 

	sha1_t_prf(simck, 40,
		   "Extended Session Key Generating Function", (unsigned char *) "", 0,
		   emsk, 64);
	wpa_hexdump_key(0, "EAP-FAST: Derived key (EMSK)",
			emsk, 64);
}


int eap_fast_parse_tlv(struct eap_fast_tlv_parse *tlv,
		       int tlv_type, unsigned char *pos, int len)
{
	switch (tlv_type) {
	case 9:
		wpa_hexdump(0, "EAP-FAST: EAP-Payload TLV",
			    pos, len);
		if (tlv->eap_payload_tlv) {
			wpa_printf(0, "EAP-FAST: More than one "
				   "EAP-Payload TLV in the message");
			tlv->iresult = 2;
			return -2;
		}
		tlv->eap_payload_tlv = pos;
		tlv->eap_payload_tlv_len = len;
		break;
	case 3:
		wpa_hexdump(0, "EAP-FAST: Result TLV", pos, len);
		if (tlv->result) {
			wpa_printf(0, "EAP-FAST: More than one "
				   "Result TLV in the message");
			tlv->result = 2;
			return -2;
		}
		if (len < 2) {
			wpa_printf(0, "EAP-FAST: Too short "
				   "Result TLV");
			tlv->result = 2;
			break;
		}
		tlv->result = ((unsigned short) (((pos)[0] << 8) | (pos)[1]));
		if (tlv->result != 1 &&
		    tlv->result != 2) {
			wpa_printf(0, "EAP-FAST: Unknown Result %d",
				   tlv->result);
			tlv->result = 2;
		}
		wpa_printf(0, "EAP-FAST: Result: %s",
			   tlv->result == 1 ?
			   "Success" : "Failure");
		break;
	case 10:
		wpa_hexdump(0, "EAP-FAST: Intermediate Result TLV",
			    pos, len);
		if (len < 2) {
			wpa_printf(0, "EAP-FAST: Too short "
				   "Intermediate-Result TLV");
			tlv->iresult = 2;
			break;
		}
		if (tlv->iresult) {
			wpa_printf(0, "EAP-FAST: More than one "
				   "Intermediate-Result TLV in the message");
			tlv->iresult = 2;
			return -2;
		}
		tlv->iresult = ((unsigned short) (((pos)[0] << 8) | (pos)[1]));
		if (tlv->iresult != 1 &&
		    tlv->iresult != 2) {
			wpa_printf(0, "EAP-FAST: Unknown Intermediate "
				   "Result %d", tlv->iresult);
			tlv->iresult = 2;
		}
		wpa_printf(0, "EAP-FAST: Intermediate Result: %s",
			   tlv->iresult == 1 ?
			   "Success" : "Failure");
		break;
	case 12:
		wpa_hexdump(0, "EAP-FAST: Crypto-Binding TLV",
			    pos, len);
		if (tlv->crypto_binding) {
			wpa_printf(0, "EAP-FAST: More than one "
				   "Crypto-Binding TLV in the message");
			tlv->iresult = 2;
			return -2;
		}
		tlv->crypto_binding_len = sizeof(struct eap_tlv_hdr) + len;
		if (tlv->crypto_binding_len < sizeof(*tlv->crypto_binding)) {
			wpa_printf(0, "EAP-FAST: Too short "
				   "Crypto-Binding TLV");
			tlv->iresult = 2;
			return -2;
		}
		tlv->crypto_binding = (struct eap_tlv_crypto_binding_tlv *)
			(pos - sizeof(struct eap_tlv_hdr));
		break;
	case 19:
		wpa_hexdump(0, "EAP-FAST: Request-Action TLV",
			    pos, len);
		if (tlv->request_action) {
			wpa_printf(0, "EAP-FAST: More than one "
				   "Request-Action TLV in the message");
			tlv->iresult = 2;
			return -2;
		}
		if (len < 2) {
			wpa_printf(0, "EAP-FAST: Too short "
				   "Request-Action TLV");
			tlv->iresult = 2;
			break;
		}
		tlv->request_action = ((unsigned short) (((pos)[0] << 8) | (pos)[1]));
		wpa_printf(0, "EAP-FAST: Request-Action: %d",
			   tlv->request_action);
		break;
	case 11:
		wpa_hexdump(0, "EAP-FAST: PAC TLV", pos, len);
		if (tlv->pac) {
			wpa_printf(0, "EAP-FAST: More than one "
				   "PAC TLV in the message");
			tlv->iresult = 2;
			return -2;
		}
		tlv->pac = pos;
		tlv->pac_len = len;
		break;
	default:
		 
		return -1;
	}

	return 0;
}
