#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c"


















 

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

#line 22 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c"
#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\wpa_supp_linux_plat\\sys/ioctl.h"




int ioctl(int fd, int cmd, ...);


#line 23 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c"




#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\wireless_copy.h"




 









 




 






















































 

 

  
#line 104 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\wireless_copy.h"





#line 116 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\wireless_copy.h"


#line 1 "..\\marvel\\driver\\inc\\if.h"

















 



#line 1 "..\\sdio\\inc\\type.h"





typedef char  S8;
typedef short	S16;
typedef int     S32;
typedef long long  S64;

typedef char   __s8;
typedef short  __s16;
typedef int   	  __s32;
typedef long long    __s64;


typedef unsigned char  U8;
typedef unsigned short	U16;
typedef unsigned int     U32;
typedef unsigned long  long   U64;




 
typedef unsigned long long   u64; 

typedef unsigned char   __u8;
typedef unsigned short  __u16;
typedef unsigned int   	 __u32;
typedef unsigned long long    __u64; 

typedef unsigned char 		uint8_t;
typedef unsigned short 		uint16_t;
typedef unsigned int     	uint32_t; 

typedef unsigned char 		int8_t;
typedef unsigned short 		int16_t;
typedef unsigned int     	int32_t;

typedef unsigned short 		__le16;
typedef unsigned int 		__le32;
typedef unsigned long long	__le64;

typedef unsigned short 		__be16;
typedef unsigned int		__be32;








#line 61 "..\\sdio\\inc\\type.h"











 

#line 108 "..\\sdio\\inc\\type.h"





#line 202 "..\\sdio\\inc\\type.h"


#line 212 "..\\sdio\\inc\\type.h"

#line 220 "..\\sdio\\inc\\type.h"

 



#line 233 "..\\sdio\\inc\\type.h"

#line 23 "..\\marvel\\driver\\inc\\if.h"
#line 1 "..\\sdio\\inc\\common.h"
#line 1 "..\\main\\xxxconfig.h"














#line 4 "..\\sdio\\inc\\common.h"
#line 5 "..\\sdio\\inc\\common.h"
#line 6 "..\\sdio\\inc\\common.h"
#line 7 "..\\sdio\\inc\\common.h"
#line 8 "..\\sdio\\inc\\common.h"
#line 9 "..\\sdio\\inc\\common.h"
#line 10 "..\\sdio\\inc\\common.h"
#line 1 "..\\target\\system.h"



#line 1 "..\\STM32F10x_lib\\inc\\stm32f10x_lib.h"














 

 



 
#line 1 "..\\STM32F10x_lib\\inc\\stm32f10x_map.h"














 

 







 
#line 1 "..\\STM32F10x_lib\\inc\\stm32f10x_conf.h"













 

 



 
#line 1 "..\\STM32F10x_lib\\inc\\stm32f10x_type.h"














 

 



 
 
typedef signed long  s32;
typedef signed short s16;
typedef signed char  s8;

typedef signed long  const sc32;   
typedef signed short const sc16;   
typedef signed char  const sc8;    

typedef volatile signed long  vs32;
typedef volatile signed short vs16;
typedef volatile signed char  vs8;

typedef volatile signed long  const vsc32;   
typedef volatile signed short const vsc16;   
typedef volatile signed char  const vsc8;    

typedef unsigned long  u32;
typedef unsigned short u16;
typedef unsigned char  u8;

typedef unsigned long  const uc32;   
typedef unsigned short const uc16;   
typedef unsigned char  const uc8;    

typedef volatile unsigned long  vu32;
typedef volatile unsigned short vu16;
typedef volatile unsigned char  vu8;

typedef volatile unsigned long  const vuc32;   
typedef volatile unsigned short const vuc16;   
typedef volatile unsigned char  const vuc8;    

typedef enum {FALSE = 0, TRUE = !FALSE} bool;

typedef enum {RESET = 0, SET = !RESET} FlagStatus, ITStatus;

typedef enum {DISABLE = 0, ENABLE = !DISABLE} FunctionalState;


typedef enum {ERROR = 0, SUCCESS = !ERROR} ErrorStatus;

#line 73 "..\\STM32F10x_lib\\inc\\stm32f10x_type.h"

 
 
 



 
#line 22 "..\\STM32F10x_lib\\inc\\stm32f10x_conf.h"

 
 


 
 

 
 





 


 


 


 


 


 
#line 66 "..\\STM32F10x_lib\\inc\\stm32f10x_conf.h"

 


 



 


 


 
#line 90 "..\\STM32F10x_lib\\inc\\stm32f10x_conf.h"

 




 


 


 


 


 


 


 





 


 
#line 133 "..\\STM32F10x_lib\\inc\\stm32f10x_conf.h"

 
#line 141 "..\\STM32F10x_lib\\inc\\stm32f10x_conf.h"

 



 


 
#line 167 "..\\STM32F10x_lib\\inc\\stm32f10x_conf.h"



 
#line 27 "..\\STM32F10x_lib\\inc\\stm32f10x_map.h"
#line 28 "..\\STM32F10x_lib\\inc\\stm32f10x_map.h"
#line 1 "..\\STM32F10x_lib\\inc\\cortexm3_macro.h"













 

 



 
#line 22 "..\\STM32F10x_lib\\inc\\cortexm3_macro.h"

 
 
 
 
void __WFI(void);
void __WFE(void);
void __SEV(void);
void __ISB(void);
void __DSB(void);
void __DMB(void);
void __SVC(void);
u32 __MRS_CONTROL(void);
void __MSR_CONTROL(u32 Control);
u32 __MRS_PSP(void);
void __MSR_PSP(u32 TopOfProcessStack);
u32 __MRS_MSP(void);
void __MSR_MSP(u32 TopOfMainStack);
void __RESETPRIMASK(void);
void __SETPRIMASK(void);
u32 __READ_PRIMASK(void);
void __RESETFAULTMASK(void);
void __SETFAULTMASK(void);
u32 __READ_FAULTMASK(void);
void __BASEPRICONFIG(u32 NewPriority);
u32 __GetBASEPRI(void);
u16 __REV_HalfWord(u16 Data);
u32 __REV_Word(u32 Data);



 
#line 29 "..\\STM32F10x_lib\\inc\\stm32f10x_map.h"

 
 
 
 

 
typedef struct
{
  vu32 SR;
  vu32 CR1;
  vu32 CR2;
  vu32 SMPR1;
  vu32 SMPR2;
  vu32 JOFR1;
  vu32 JOFR2;
  vu32 JOFR3;
  vu32 JOFR4;
  vu32 HTR;
  vu32 LTR;
  vu32 SQR1;
  vu32 SQR2;
  vu32 SQR3;
  vu32 JSQR;
  vu32 JDR1;
  vu32 JDR2;
  vu32 JDR3;
  vu32 JDR4;
  vu32 DR;
} ADC_TypeDef;

 
typedef struct
{
  u32  RESERVED0;
  vu16 DR1;
  u16  RESERVED1;
  vu16 DR2;
  u16  RESERVED2;
  vu16 DR3;
  u16  RESERVED3;
  vu16 DR4;
  u16  RESERVED4;
  vu16 DR5;
  u16  RESERVED5;
  vu16 DR6;
  u16  RESERVED6;
  vu16 DR7;
  u16  RESERVED7;
  vu16 DR8;
  u16  RESERVED8;
  vu16 DR9;
  u16  RESERVED9;
  vu16 DR10;
  u16  RESERVED10; 
  vu16 RTCCR;
  u16  RESERVED11;
  vu16 CR;
  u16  RESERVED12;
  vu16 CSR;
  u16  RESERVED13[5];
  vu16 DR11;
  u16  RESERVED14;
  vu16 DR12;
  u16  RESERVED15;
  vu16 DR13;
  u16  RESERVED16;
  vu16 DR14;
  u16  RESERVED17;
  vu16 DR15;
  u16  RESERVED18;
  vu16 DR16;
  u16  RESERVED19;
  vu16 DR17;
  u16  RESERVED20;
  vu16 DR18;
  u16  RESERVED21;
  vu16 DR19;
  u16  RESERVED22;
  vu16 DR20;
  u16  RESERVED23;
  vu16 DR21;
  u16  RESERVED24;
  vu16 DR22;
  u16  RESERVED25;
  vu16 DR23;
  u16  RESERVED26;
  vu16 DR24;
  u16  RESERVED27;
  vu16 DR25;
  u16  RESERVED28;
  vu16 DR26;
  u16  RESERVED29;
  vu16 DR27;
  u16  RESERVED30;
  vu16 DR28;
  u16  RESERVED31;
  vu16 DR29;
  u16  RESERVED32;
  vu16 DR30;
  u16  RESERVED33; 
  vu16 DR31;
  u16  RESERVED34;
  vu16 DR32;
  u16  RESERVED35;
  vu16 DR33;
  u16  RESERVED36;
  vu16 DR34;
  u16  RESERVED37;
  vu16 DR35;
  u16  RESERVED38;
  vu16 DR36;
  u16  RESERVED39;
  vu16 DR37;
  u16  RESERVED40;
  vu16 DR38;
  u16  RESERVED41;
  vu16 DR39;
  u16  RESERVED42;
  vu16 DR40;
  u16  RESERVED43;
  vu16 DR41;
  u16  RESERVED44;
  vu16 DR42;
  u16  RESERVED45;    
} BKP_TypeDef;

 
typedef struct
{
  vu32 TIR;
  vu32 TDTR;
  vu32 TDLR;
  vu32 TDHR;
} CAN_TxMailBox_TypeDef;

typedef struct
{
  vu32 RIR;
  vu32 RDTR;
  vu32 RDLR;
  vu32 RDHR;
} CAN_FIFOMailBox_TypeDef;

typedef struct
{
  vu32 FR1;
  vu32 FR2;
} CAN_FilterRegister_TypeDef;

typedef struct
{
  vu32 MCR;
  vu32 MSR;
  vu32 TSR;
  vu32 RF0R;
  vu32 RF1R;
  vu32 IER;
  vu32 ESR;
  vu32 BTR;
  u32  RESERVED0[88];
  CAN_TxMailBox_TypeDef sTxMailBox[3];
  CAN_FIFOMailBox_TypeDef sFIFOMailBox[2];
  u32  RESERVED1[12];
  vu32 FMR;
  vu32 FM1R;
  u32  RESERVED2;
  vu32 FS1R;
  u32  RESERVED3;
  vu32 FFA1R;
  u32  RESERVED4;
  vu32 FA1R;
  u32  RESERVED5[8];
  CAN_FilterRegister_TypeDef sFilterRegister[14];
} CAN_TypeDef;

 
typedef struct
{
  vu32 DR;
  vu8  IDR;
  u8   RESERVED0;
  u16  RESERVED1;
  vu32 CR;
} CRC_TypeDef;


 
typedef struct
{
  vu32 CR;
  vu32 SWTRIGR;
  vu32 DHR12R1;
  vu32 DHR12L1;
  vu32 DHR8R1;
  vu32 DHR12R2;
  vu32 DHR12L2;
  vu32 DHR8R2;
  vu32 DHR12RD;
  vu32 DHR12LD;
  vu32 DHR8RD;
  vu32 DOR1;
  vu32 DOR2;
} DAC_TypeDef;

 
typedef struct
{
  vu32 IDCODE;
  vu32 CR;	
}DBGMCU_TypeDef;

 
typedef struct
{
  vu32 CCR;
  vu32 CNDTR;
  vu32 CPAR;
  vu32 CMAR;
} DMA_Channel_TypeDef;

typedef struct
{
  vu32 ISR;
  vu32 IFCR;
} DMA_TypeDef;

 
typedef struct
{
  vu32 IMR;
  vu32 EMR;
  vu32 RTSR;
  vu32 FTSR;
  vu32 SWIER;
  vu32 PR;
} EXTI_TypeDef;

 
typedef struct
{
  vu32 ACR;
  vu32 KEYR;
  vu32 OPTKEYR;
  vu32 SR;
  vu32 CR;
  vu32 AR;
  vu32 RESERVED;
  vu32 OBR;
  vu32 WRPR;
} FLASH_TypeDef;

typedef struct
{
  vu16 RDP;
  vu16 USER;
  vu16 Data0;
  vu16 Data1;
  vu16 WRP0;
  vu16 WRP1;
  vu16 WRP2;
  vu16 WRP3;
} OB_TypeDef;

 
typedef struct
{
  vu32 BTCR[8];   
} FSMC_Bank1_TypeDef; 

typedef struct
{
  vu32 BWTR[7];
} FSMC_Bank1E_TypeDef;

typedef struct
{
  vu32 PCR2;
  vu32 SR2;
  vu32 PMEM2;
  vu32 PATT2;
  u32  RESERVED0;   
  vu32 ECCR2; 
} FSMC_Bank2_TypeDef;  

typedef struct
{
  vu32 PCR3;
  vu32 SR3;
  vu32 PMEM3;
  vu32 PATT3;
  u32  RESERVED0;   
  vu32 ECCR3; 
} FSMC_Bank3_TypeDef; 

typedef struct
{
  vu32 PCR4;
  vu32 SR4;
  vu32 PMEM4;
  vu32 PATT4;
  vu32 PIO4; 
} FSMC_Bank4_TypeDef; 

 
typedef struct
{
  vu32 CRL;
  vu32 CRH;
  vu32 IDR;
  vu32 ODR;
  vu32 BSRR;
  vu32 BRR;
  vu32 LCKR;
} GPIO_TypeDef;

typedef struct
{
  vu32 EVCR;
  vu32 MAPR;
  vu32 EXTICR[4];
} AFIO_TypeDef;

 
typedef struct
{
  vu16 CR1;
  u16  RESERVED0;
  vu16 CR2;
  u16  RESERVED1;
  vu16 OAR1;
  u16  RESERVED2;
  vu16 OAR2;
  u16  RESERVED3;
  vu16 DR;
  u16  RESERVED4;
  vu16 SR1;
  u16  RESERVED5;
  vu16 SR2;
  u16  RESERVED6;
  vu16 CCR;
  u16  RESERVED7;
  vu16 TRISE;
  u16  RESERVED8;
} I2C_TypeDef;

 
typedef struct
{
  vu32 KR;
  vu32 PR;
  vu32 RLR;
  vu32 SR;
} IWDG_TypeDef;

 
typedef struct
{
  vu32 ISER[2];
  u32  RESERVED0[30];
  vu32 ICER[2];
  u32  RSERVED1[30];
  vu32 ISPR[2];
  u32  RESERVED2[30];
  vu32 ICPR[2];
  u32  RESERVED3[30];
  vu32 IABR[2];
  u32  RESERVED4[62];
  vu32 IPR[15];
} NVIC_TypeDef;

typedef struct
{
  vuc32 CPUID;
  vu32 ICSR;
  vu32 VTOR;
  vu32 AIRCR;
  vu32 SCR;
  vu32 CCR;
  vu32 SHPR[3];
  vu32 SHCSR;
  vu32 CFSR;
  vu32 HFSR;
  vu32 DFSR;
  vu32 MMFAR;
  vu32 BFAR;
  vu32 AFSR;
} SCB_TypeDef;

 
typedef struct
{
  vu32 CR;
  vu32 CSR;
} PWR_TypeDef;

 
typedef struct
{
  vu32 CR;
  vu32 CFGR;
  vu32 CIR;
  vu32 APB2RSTR;
  vu32 APB1RSTR;
  vu32 AHBENR;
  vu32 APB2ENR;
  vu32 APB1ENR;
  vu32 BDCR;
  vu32 CSR;
} RCC_TypeDef;

 
typedef struct
{
  vu16 CRH;
  u16  RESERVED0;
  vu16 CRL;
  u16  RESERVED1;
  vu16 PRLH;
  u16  RESERVED2;
  vu16 PRLL;
  u16  RESERVED3;
  vu16 DIVH;
  u16  RESERVED4;
  vu16 DIVL;
  u16  RESERVED5;
  vu16 CNTH;
  u16  RESERVED6;
  vu16 CNTL;
  u16  RESERVED7;
  vu16 ALRH;
  u16  RESERVED8;
  vu16 ALRL;
  u16  RESERVED9;
} RTC_TypeDef;

 
typedef struct
{
  vu32 POWER;
  vu32 CLKCR;
  vu32 ARG;
  vu32 CMD;
  vuc32 RESPCMD;
  vuc32 RESP1;
  vuc32 RESP2;
  vuc32 RESP3;
  vuc32 RESP4;
  vu32 DTIMER;
  vu32 DLEN;
  vu32 DCTRL;
  vuc32 DCOUNT;
  vuc32 STA;
  vu32 ICR;
  vu32 MASK;
  u32  RESERVED0[2];
  vuc32 FIFOCNT;
  u32  RESERVED1[13];
  vu32 FIFO;
} SDIO_TypeDef;

 
typedef struct
{
  vu16 CR1;
  u16  RESERVED0;
  vu16 CR2;
  u16  RESERVED1;
  vu16 SR;
  u16  RESERVED2;
  vu16 DR;
  u16  RESERVED3;
  vu16 CRCPR;
  u16  RESERVED4;
  vu16 RXCRCR;
  u16  RESERVED5;
  vu16 TXCRCR;
  u16  RESERVED6;
  vu16 I2SCFGR;
  u16  RESERVED7;
  vu16 I2SPR;
  u16  RESERVED8;  
} SPI_TypeDef;

 
typedef struct
{
  vu32 CTRL;
  vu32 LOAD;
  vu32 VAL;
  vuc32 CALIB;
} SysTick_TypeDef;

 
typedef struct
{
  vu16 CR1;
  u16  RESERVED0;
  vu16 CR2;
  u16  RESERVED1;
  vu16 SMCR;
  u16  RESERVED2;
  vu16 DIER;
  u16  RESERVED3;
  vu16 SR;
  u16  RESERVED4;
  vu16 EGR;
  u16  RESERVED5;
  vu16 CCMR1;
  u16  RESERVED6;
  vu16 CCMR2;
  u16  RESERVED7;
  vu16 CCER;
  u16  RESERVED8;
  vu16 CNT;
  u16  RESERVED9;
  vu16 PSC;
  u16  RESERVED10;
  vu16 ARR;
  u16  RESERVED11;
  vu16 RCR;
  u16  RESERVED12;
  vu16 CCR1;
  u16  RESERVED13;
  vu16 CCR2;
  u16  RESERVED14;
  vu16 CCR3;
  u16  RESERVED15;
  vu16 CCR4;
  u16  RESERVED16;
  vu16 BDTR;
  u16  RESERVED17;
  vu16 DCR;
  u16  RESERVED18;
  vu16 DMAR;
  u16  RESERVED19;
} TIM_TypeDef;

 
typedef struct
{
  vu16 SR;
  u16  RESERVED0;
  vu16 DR;
  u16  RESERVED1;
  vu16 BRR;
  u16  RESERVED2;
  vu16 CR1;
  u16  RESERVED3;
  vu16 CR2;
  u16  RESERVED4;
  vu16 CR3;
  u16  RESERVED5;
  vu16 GTPR;
  u16  RESERVED6;
} USART_TypeDef;

 
typedef struct
{
  vu32 CR;
  vu32 CFR;
  vu32 SR;
} WWDG_TypeDef;

 
 
 
 



 



 


 




#line 634 "..\\STM32F10x_lib\\inc\\stm32f10x_map.h"

#line 651 "..\\STM32F10x_lib\\inc\\stm32f10x_map.h"



#line 670 "..\\STM32F10x_lib\\inc\\stm32f10x_map.h"

 

 


 






 


 






 
 
 

 



























































































































































































































#line 924 "..\\STM32F10x_lib\\inc\\stm32f10x_map.h"














 
#line 1180 "..\\STM32F10x_lib\\inc\\stm32f10x_map.h"

 
 
 



 
#line 23 "..\\STM32F10x_lib\\inc\\stm32f10x_lib.h"

#line 1 "..\\STM32F10x_lib\\inc\\stm32f10x_adc.h"














 

 



 
#line 23 "..\\STM32F10x_lib\\inc\\stm32f10x_adc.h"

 
 
typedef struct
{
  u32 ADC_Mode;
  FunctionalState ADC_ScanConvMode; 
  FunctionalState ADC_ContinuousConvMode;
  u32 ADC_ExternalTrigConv;
  u32 ADC_DataAlign;
  u8 ADC_NbrOfChannel;
}ADC_InitTypeDef;

 



                                 



 
#line 55 "..\\STM32F10x_lib\\inc\\stm32f10x_adc.h"

#line 66 "..\\STM32F10x_lib\\inc\\stm32f10x_adc.h"

 
 
#line 75 "..\\STM32F10x_lib\\inc\\stm32f10x_adc.h"
 


 
#line 85 "..\\STM32F10x_lib\\inc\\stm32f10x_adc.h"

#line 100 "..\\STM32F10x_lib\\inc\\stm32f10x_adc.h"

 






 
#line 127 "..\\STM32F10x_lib\\inc\\stm32f10x_adc.h"

#line 137 "..\\STM32F10x_lib\\inc\\stm32f10x_adc.h"

 
#line 147 "..\\STM32F10x_lib\\inc\\stm32f10x_adc.h"

#line 156 "..\\STM32F10x_lib\\inc\\stm32f10x_adc.h"

 
 





 



 






#line 188 "..\\STM32F10x_lib\\inc\\stm32f10x_adc.h"

 










 
#line 208 "..\\STM32F10x_lib\\inc\\stm32f10x_adc.h"

#line 216 "..\\STM32F10x_lib\\inc\\stm32f10x_adc.h"

 








 











 


 


 


 


 


 


 


 
 
void ADC_DeInit(ADC_TypeDef* ADCx);
void ADC_Init(ADC_TypeDef* ADCx, ADC_InitTypeDef* ADC_InitStruct);
void ADC_StructInit(ADC_InitTypeDef* ADC_InitStruct);
void ADC_Cmd(ADC_TypeDef* ADCx, FunctionalState NewState);
void ADC_DMACmd(ADC_TypeDef* ADCx, FunctionalState NewState);
void ADC_ITConfig(ADC_TypeDef* ADCx, u16 ADC_IT, FunctionalState NewState);
void ADC_ResetCalibration(ADC_TypeDef* ADCx);
FlagStatus ADC_GetResetCalibrationStatus(ADC_TypeDef* ADCx);
void ADC_StartCalibration(ADC_TypeDef* ADCx);
FlagStatus ADC_GetCalibrationStatus(ADC_TypeDef* ADCx);
void ADC_SoftwareStartConvCmd(ADC_TypeDef* ADCx, FunctionalState NewState);
FlagStatus ADC_GetSoftwareStartConvStatus(ADC_TypeDef* ADCx);
void ADC_DiscModeChannelCountConfig(ADC_TypeDef* ADCx, u8 Number);
void ADC_DiscModeCmd(ADC_TypeDef* ADCx, FunctionalState NewState);
void ADC_RegularChannelConfig(ADC_TypeDef* ADCx, u8 ADC_Channel, u8 Rank, u8 ADC_SampleTime);
void ADC_ExternalTrigConvCmd(ADC_TypeDef* ADCx, FunctionalState NewState);
u16 ADC_GetConversionValue(ADC_TypeDef* ADCx);
u32 ADC_GetDualModeConversionValue(void);
void ADC_AutoInjectedConvCmd(ADC_TypeDef* ADCx, FunctionalState NewState);
void ADC_InjectedDiscModeCmd(ADC_TypeDef* ADCx, FunctionalState NewState);
void ADC_ExternalTrigInjectedConvConfig(ADC_TypeDef* ADCx, u32 ADC_ExternalTrigInjecConv);
void ADC_ExternalTrigInjectedConvCmd(ADC_TypeDef* ADCx, FunctionalState NewState);
void ADC_SoftwareStartInjectedConvCmd(ADC_TypeDef* ADCx, FunctionalState NewState);
FlagStatus ADC_GetSoftwareStartInjectedConvCmdStatus(ADC_TypeDef* ADCx);
void ADC_InjectedChannelConfig(ADC_TypeDef* ADCx, u8 ADC_Channel, u8 Rank, u8 ADC_SampleTime);
void ADC_InjectedSequencerLengthConfig(ADC_TypeDef* ADCx, u8 Length);
void ADC_SetInjectedOffset(ADC_TypeDef* ADCx, u8 ADC_InjectedChannel, u16 Offset);
u16 ADC_GetInjectedConversionValue(ADC_TypeDef* ADCx, u8 ADC_InjectedChannel);
void ADC_AnalogWatchdogCmd(ADC_TypeDef* ADCx, u32 ADC_AnalogWatchdog);
void ADC_AnalogWatchdogThresholdsConfig(ADC_TypeDef* ADCx, u16 HighThreshold, u16 LowThreshold);
void ADC_AnalogWatchdogSingleChannelConfig(ADC_TypeDef* ADCx, u8 ADC_Channel);
void ADC_TempSensorVrefintCmd(FunctionalState NewState);
FlagStatus ADC_GetFlagStatus(ADC_TypeDef* ADCx, u8 ADC_FLAG);
void ADC_ClearFlag(ADC_TypeDef* ADCx, u8 ADC_FLAG);
ITStatus ADC_GetITStatus(ADC_TypeDef* ADCx, u16 ADC_IT);
void ADC_ClearITPendingBit(ADC_TypeDef* ADCx, u16 ADC_IT);



 
#line 26 "..\\STM32F10x_lib\\inc\\stm32f10x_lib.h"


#line 1 "..\\STM32F10x_lib\\inc\\stm32f10x_bkp.h"














 

 



 
#line 23 "..\\STM32F10x_lib\\inc\\stm32f10x_bkp.h"

 
 
 






 










 
#line 87 "..\\STM32F10x_lib\\inc\\stm32f10x_bkp.h"

#line 102 "..\\STM32F10x_lib\\inc\\stm32f10x_bkp.h"



 
 
void BKP_DeInit(void);
void BKP_TamperPinLevelConfig(u16 BKP_TamperPinLevel);
void BKP_TamperPinCmd(FunctionalState NewState);
void BKP_ITConfig(FunctionalState NewState);
void BKP_RTCOutputConfig(u16 BKP_RTCOutputSource);
void BKP_SetRTCCalibrationValue(u8 CalibrationValue);
void BKP_WriteBackupRegister(u16 BKP_DR, u16 Data);
u16 BKP_ReadBackupRegister(u16 BKP_DR);
FlagStatus BKP_GetFlagStatus(void);
void BKP_ClearFlag(void);
ITStatus BKP_GetITStatus(void);
void BKP_ClearITPendingBit(void);



 
#line 30 "..\\STM32F10x_lib\\inc\\stm32f10x_lib.h"


#line 1 "..\\STM32F10x_lib\\inc\\stm32f10x_can.h"














 

 



 
#line 23 "..\\STM32F10x_lib\\inc\\stm32f10x_can.h"

 
 
typedef struct
{
  FunctionalState CAN_TTCM;
  FunctionalState CAN_ABOM;
  FunctionalState CAN_AWUM;
  FunctionalState CAN_NART;
  FunctionalState CAN_RFLM;
  FunctionalState CAN_TXFP;
  u8 CAN_Mode;
  u8 CAN_SJW;
  u8 CAN_BS1;
  u8 CAN_BS2;
  u16 CAN_Prescaler;
} CAN_InitTypeDef;

 
typedef struct
{
  u8 CAN_FilterNumber;
  u8 CAN_FilterMode;
  u8 CAN_FilterScale;
  u16 CAN_FilterIdHigh;
  u16 CAN_FilterIdLow;
  u16 CAN_FilterMaskIdHigh;
  u16 CAN_FilterMaskIdLow;
  u16 CAN_FilterFIFOAssignment;
  FunctionalState CAN_FilterActivation;
} CAN_FilterInitTypeDef;

 
typedef struct
{
  u32 StdId;
  u32 ExtId;
  u8 IDE;
  u8 RTR;
  u8 DLC;
  u8 Data[8];
} CanTxMsg;

 
typedef struct
{
  u32 StdId;
  u32 ExtId;
  u8 IDE;
  u8 RTR;
  u8 DLC;
  u8 Data[8];
  u8 FMI;
} CanRxMsg;

 

 



 








 








 
#line 119 "..\\STM32F10x_lib\\inc\\stm32f10x_can.h"



 
#line 131 "..\\STM32F10x_lib\\inc\\stm32f10x_can.h"



 


 


 






 






 






 





 





 





 





 





 



 



 







 
#line 225 "..\\STM32F10x_lib\\inc\\stm32f10x_can.h"

#line 233 "..\\STM32F10x_lib\\inc\\stm32f10x_can.h"

#line 240 "..\\STM32F10x_lib\\inc\\stm32f10x_can.h"

 
 
void CAN_DeInit(void);
u8 CAN_Init(CAN_InitTypeDef* CAN_InitStruct);
void CAN_FilterInit(CAN_FilterInitTypeDef* CAN_FilterInitStruct);
void CAN_StructInit(CAN_InitTypeDef* CAN_InitStruct);
void CAN_ITConfig(u32 CAN_IT, FunctionalState NewState);
u8 CAN_Transmit(CanTxMsg* TxMessage);
u8 CAN_TransmitStatus(u8 TransmitMailbox);
void CAN_CancelTransmit(u8 Mailbox);
void CAN_FIFORelease(u8 FIFONumber);
u8 CAN_MessagePending(u8 FIFONumber);
void CAN_Receive(u8 FIFONumber, CanRxMsg* RxMessage);
u8 CAN_Sleep(void);
u8 CAN_WakeUp(void);
FlagStatus CAN_GetFlagStatus(u32 CAN_FLAG);
void CAN_ClearFlag(u32 CAN_FLAG);
ITStatus CAN_GetITStatus(u32 CAN_IT);
void CAN_ClearITPendingBit(u32 CAN_IT);



 
#line 34 "..\\STM32F10x_lib\\inc\\stm32f10x_lib.h"


#line 1 "..\\STM32F10x_lib\\inc\\stm32f10x_crc.h"














 

 



 
#line 23 "..\\STM32F10x_lib\\inc\\stm32f10x_crc.h"

 
 
 
 
void CRC_ResetDR(void);
u32 CRC_CalcCRC(u32 Data);
u32 CRC_CalcBlockCRC(u32 pBuffer[], u32 BufferLength);
u32 CRC_GetCRC(void);
void CRC_SetIDRegister(u8 IDValue);
u8 CRC_GetIDRegister(void);



 
#line 38 "..\\STM32F10x_lib\\inc\\stm32f10x_lib.h"


#line 1 "..\\STM32F10x_lib\\inc\\stm32f10x_dac.h"














 

 



 
#line 23 "..\\STM32F10x_lib\\inc\\stm32f10x_dac.h"

 
 
typedef struct
{
  u32 DAC_Trigger;
  u32 DAC_WaveGeneration;
  u32 DAC_LFSRUnmask_TriangleAmplitude;
  u32 DAC_OutputBuffer; 
}DAC_InitTypeDef;

 
 
#line 45 "..\\STM32F10x_lib\\inc\\stm32f10x_dac.h"

#line 55 "..\\STM32F10x_lib\\inc\\stm32f10x_dac.h"

 








 
#line 78 "..\\STM32F10x_lib\\inc\\stm32f10x_dac.h"

#line 91 "..\\STM32F10x_lib\\inc\\stm32f10x_dac.h"

#line 116 "..\\STM32F10x_lib\\inc\\stm32f10x_dac.h"

 






 






 








 






 


 
 
void DAC_DeInit(void);
void DAC_Init(u32 DAC_Channel, DAC_InitTypeDef* DAC_InitStruct);
void DAC_StructInit(DAC_InitTypeDef* DAC_InitStruct);
void DAC_Cmd(u32 DAC_Channel, FunctionalState NewState);
void DAC_DMACmd(u32 DAC_Channel, FunctionalState NewState);
void DAC_SoftwareTriggerCmd(u32 DAC_Channel, FunctionalState NewState);
void DAC_DualSoftwareTriggerCmd(FunctionalState NewState);
void DAC_WaveGenerationCmd(u32 DAC_Channel, u32 DAC_Wave, FunctionalState NewState);
void DAC_SetChannel1Data(u32 DAC_Align, u16 Data);
void DAC_SetChannel2Data(u32 DAC_Align, u16 Data);
void DAC_SetDualChannelData(u32 DAC_Align, u16 Data2, u16 Data1);
u16 DAC_GetDataOutputValue(u32 DAC_Channel);



 
#line 42 "..\\STM32F10x_lib\\inc\\stm32f10x_lib.h"


#line 1 "..\\STM32F10x_lib\\inc\\stm32f10x_dbgmcu.h"














 

 



 
#line 23 "..\\STM32F10x_lib\\inc\\stm32f10x_dbgmcu.h"

 
 
#line 42 "..\\STM32F10x_lib\\inc\\stm32f10x_dbgmcu.h"
                                           


 
 
u32 DBGMCU_GetREVID(void);
u32 DBGMCU_GetDEVID(void);
void DBGMCU_Config(u32 DBGMCU_Periph, FunctionalState NewState);



 


#line 46 "..\\STM32F10x_lib\\inc\\stm32f10x_lib.h"


#line 1 "..\\STM32F10x_lib\\inc\\stm32f10x_dma.h"














 

 



 
#line 23 "..\\STM32F10x_lib\\inc\\stm32f10x_dma.h"

 
 
typedef struct
{
  u32 DMA_PeripheralBaseAddr;
  u32 DMA_MemoryBaseAddr;
  u32 DMA_DIR;
  u32 DMA_BufferSize;
  u32 DMA_PeripheralInc;
  u32 DMA_MemoryInc;
  u32 DMA_PeripheralDataSize;
  u32 DMA_MemoryDataSize;
  u32 DMA_Mode;
  u32 DMA_Priority;
  u32 DMA_M2M;
}DMA_InitTypeDef;

 
#line 54 "..\\STM32F10x_lib\\inc\\stm32f10x_dma.h"

 






 






 






 








 








 





 










 





 






 
#line 153 "..\\STM32F10x_lib\\inc\\stm32f10x_dma.h"
 
#line 174 "..\\STM32F10x_lib\\inc\\stm32f10x_dma.h"

#line 200 "..\\STM32F10x_lib\\inc\\stm32f10x_dma.h"

 
 
#line 231 "..\\STM32F10x_lib\\inc\\stm32f10x_dma.h"
 
#line 252 "..\\STM32F10x_lib\\inc\\stm32f10x_dma.h"

#line 278 "..\\STM32F10x_lib\\inc\\stm32f10x_dma.h"

 


 
 
void DMA_DeInit(DMA_Channel_TypeDef* DMAy_Channelx);
void DMA_Init(DMA_Channel_TypeDef* DMAy_Channelx, DMA_InitTypeDef* DMA_InitStruct);
void DMA_StructInit(DMA_InitTypeDef* DMA_InitStruct);
void DMA_Cmd(DMA_Channel_TypeDef* DMAy_Channelx, FunctionalState NewState);
void DMA_ITConfig(DMA_Channel_TypeDef* DMAy_Channelx, u32 DMA_IT, FunctionalState NewState);
u16 DMA_GetCurrDataCounter(DMA_Channel_TypeDef* DMAy_Channelx);
FlagStatus DMA_GetFlagStatus(u32 DMA_FLAG);
void DMA_ClearFlag(u32 DMA_FLAG);
ITStatus DMA_GetITStatus(u32 DMA_IT);
void DMA_ClearITPendingBit(u32 DMA_IT);



 
#line 50 "..\\STM32F10x_lib\\inc\\stm32f10x_lib.h"


#line 1 "..\\STM32F10x_lib\\inc\\stm32f10x_exti.h"














 

 



 
#line 23 "..\\STM32F10x_lib\\inc\\stm32f10x_exti.h"

 
 
typedef enum
{
  EXTI_Mode_Interrupt = 0x00,
  EXTI_Mode_Event = 0x04
}EXTIMode_TypeDef;


                            
 
typedef enum
{
  EXTI_Trigger_Rising = 0x08,
  EXTI_Trigger_Falling = 0x0C,  
  EXTI_Trigger_Rising_Falling = 0x10
}EXTITrigger_TypeDef;





 
typedef struct
{
  u32 EXTI_Line;
  EXTIMode_TypeDef EXTI_Mode;
  EXTITrigger_TypeDef EXTI_Trigger;
  FunctionalState EXTI_LineCmd;
}EXTI_InitTypeDef;

 
 
#line 80 "..\\STM32F10x_lib\\inc\\stm32f10x_exti.h"



#line 93 "..\\STM32F10x_lib\\inc\\stm32f10x_exti.h"
                                 
 
 
void EXTI_DeInit(void);
void EXTI_Init(EXTI_InitTypeDef* EXTI_InitStruct);
void EXTI_StructInit(EXTI_InitTypeDef* EXTI_InitStruct);
void EXTI_GenerateSWInterrupt(u32 EXTI_Line);
FlagStatus EXTI_GetFlagStatus(u32 EXTI_Line);
void EXTI_ClearFlag(u32 EXTI_Line);
ITStatus EXTI_GetITStatus(u32 EXTI_Line);
void EXTI_ClearITPendingBit(u32 EXTI_Line);



 
#line 54 "..\\STM32F10x_lib\\inc\\stm32f10x_lib.h"


#line 1 "..\\STM32F10x_lib\\inc\\stm32f10x_flash.h"














 

 



 
#line 23 "..\\STM32F10x_lib\\inc\\stm32f10x_flash.h"

 

 
typedef enum
{ 
  FLASH_BUSY = 1,
  FLASH_ERROR_PG,
  FLASH_ERROR_WRP,
  FLASH_COMPLETE,
  FLASH_TIMEOUT
}FLASH_Status;


 








 







 







 

 
#line 97 "..\\STM32F10x_lib\\inc\\stm32f10x_flash.h"

 
#line 132 "..\\STM32F10x_lib\\inc\\stm32f10x_flash.h"






 





 





 





 





 





 






								 
 
 
 
void FLASH_SetLatency(u32 FLASH_Latency);
void FLASH_HalfCycleAccessCmd(u32 FLASH_HalfCycleAccess);
void FLASH_PrefetchBufferCmd(u32 FLASH_PrefetchBuffer);


void FLASH_Unlock(void);
void FLASH_Lock(void);
FLASH_Status FLASH_ErasePage(u32 Page_Address);
FLASH_Status FLASH_EraseAllPages(void);
FLASH_Status FLASH_EraseOptionBytes(void);
FLASH_Status FLASH_ProgramWord(u32 Address, u32 Data);
FLASH_Status FLASH_ProgramHalfWord(u32 Address, u16 Data);
FLASH_Status FLASH_ProgramOptionByteData(u32 Address, u8 Data);
FLASH_Status FLASH_EnableWriteProtection(u32 FLASH_Pages);
FLASH_Status FLASH_ReadOutProtection(FunctionalState NewState);
FLASH_Status FLASH_UserOptionByteConfig(u16 OB_IWDG, u16 OB_STOP, u16 OB_STDBY);
u32 FLASH_GetUserOptionByte(void);
u32 FLASH_GetWriteProtectionOptionByte(void);
FlagStatus FLASH_GetReadOutProtectionStatus(void);
FlagStatus FLASH_GetPrefetchBufferStatus(void);
void FLASH_ITConfig(u16 FLASH_IT, FunctionalState NewState);
FlagStatus FLASH_GetFlagStatus(u16 FLASH_FLAG);
void FLASH_ClearFlag(u16 FLASH_FLAG);
FLASH_Status FLASH_GetStatus(void);
FLASH_Status FLASH_WaitForLastOperation(u32 Timeout);




 
#line 58 "..\\STM32F10x_lib\\inc\\stm32f10x_lib.h"


#line 1 "..\\STM32F10x_lib\\inc\\stm32f10x_fsmc.h"














 

 



 
#line 23 "..\\STM32F10x_lib\\inc\\stm32f10x_fsmc.h"

 
 
typedef struct
{
  u32 FSMC_AddressSetupTime;
  u32 FSMC_AddressHoldTime;
  u32 FSMC_DataSetupTime;
  u32 FSMC_BusTurnAroundDuration;
  u32 FSMC_CLKDivision;
  u32 FSMC_DataLatency;
  u32 FSMC_AccessMode;
}FSMC_NORSRAMTimingInitTypeDef;

 
typedef struct
{
  u32 FSMC_Bank;
  u32 FSMC_DataAddressMux;
  u32 FSMC_MemoryType;
  u32 FSMC_MemoryDataWidth;
  u32 FSMC_BurstAccessMode;
  u32 FSMC_WaitSignalPolarity;
  u32 FSMC_WrapMode;
  u32 FSMC_WaitSignalActive;
  u32 FSMC_WriteOperation;
  u32 FSMC_WaitSignal;
  u32 FSMC_ExtendedMode;
  u32 FSMC_AsyncWait;
  u32 FSMC_WriteBurst;
   
  FSMC_NORSRAMTimingInitTypeDef* FSMC_ReadWriteTimingStruct;
   
  FSMC_NORSRAMTimingInitTypeDef* FSMC_WriteTimingStruct;
}FSMC_NORSRAMInitTypeDef;

 
typedef struct
{
  u32 FSMC_SetupTime;
  u32 FSMC_WaitSetupTime;
  u32 FSMC_HoldSetupTime;
  u32 FSMC_HiZSetupTime;
}FSMC_NAND_PCCARDTimingInitTypeDef;

 
typedef struct
{
  u32 FSMC_Bank;
  u32 FSMC_Waitfeature;
  u32 FSMC_MemoryDataWidth;
  u32 FSMC_ECC;
  u32 FSMC_ECCPageSize;
  u32 FSMC_AddressLowMapping;
  u32 FSMC_TCLRSetupTime;
  u32 FSMC_TARSetupTime;
   
  FSMC_NAND_PCCARDTimingInitTypeDef*  FSMC_CommonSpaceTimingStruct;
   
  FSMC_NAND_PCCARDTimingInitTypeDef*  FSMC_AttributeSpaceTimingStruct;
}FSMC_NANDInitTypeDef;

 
typedef struct
{
  u32 FSMC_Waitfeature;
  u32 FSMC_AddressLowMapping;
  u32 FSMC_TCLRSetupTime;
  u32 FSMC_TARSetupTime;
   
  FSMC_NAND_PCCARDTimingInitTypeDef*  FSMC_CommonSpaceTimingStruct;
   
  FSMC_NAND_PCCARDTimingInitTypeDef*  FSMC_AttributeSpaceTimingStruct;
   
  FSMC_NAND_PCCARDTimingInitTypeDef*  FSMC_IOSpaceTimingStruct;
}FSMC_PCCARDInitTypeDef;

 
 
#line 109 "..\\STM32F10x_lib\\inc\\stm32f10x_fsmc.h"













                                    





 
 






 









                                     
 





                                      
                               
 






                                   





                                        
  





                                 
                                  





                                    
 





                              
 






 





                               
 





                                  
                                   






 


 


 


 


 


 


 









                                  
 
 





                                    
 





                                    
 





                                            
 
#line 276 "..\\STM32F10x_lib\\inc\\stm32f10x_fsmc.h"

#line 283 "..\\STM32F10x_lib\\inc\\stm32f10x_fsmc.h"
                                                              
 





 


 


 


 


 


 


 










 











 
 
void FSMC_NORSRAMDeInit(u32 FSMC_Bank);
void FSMC_NANDDeInit(u32 FSMC_Bank);
void FSMC_PCCARDDeInit(void);
void FSMC_NORSRAMInit(FSMC_NORSRAMInitTypeDef* FSMC_NORSRAMInitStruct);
void FSMC_NANDInit(FSMC_NANDInitTypeDef* FSMC_NANDInitStruct);
void FSMC_PCCARDInit(FSMC_PCCARDInitTypeDef* FSMC_PCCARDInitStruct);
void FSMC_NORSRAMStructInit(FSMC_NORSRAMInitTypeDef* FSMC_NORSRAMInitStruct);
void FSMC_NANDStructInit(FSMC_NANDInitTypeDef* FSMC_NANDInitStruct);
void FSMC_PCCARDStructInit(FSMC_PCCARDInitTypeDef* FSMC_PCCARDInitStruct);
void FSMC_NORSRAMCmd(u32 FSMC_Bank, FunctionalState NewState);
void FSMC_NANDCmd(u32 FSMC_Bank, FunctionalState NewState);
void FSMC_PCCARDCmd(FunctionalState NewState);
void FSMC_NANDECCCmd(u32 FSMC_Bank, FunctionalState NewState);
u32 FSMC_GetECC(u32 FSMC_Bank);
void FSMC_ITConfig(u32 FSMC_Bank, u32 FSMC_IT, FunctionalState NewState);
FlagStatus FSMC_GetFlagStatus(u32 FSMC_Bank, u32 FSMC_FLAG);
void FSMC_ClearFlag(u32 FSMC_Bank, u32 FSMC_FLAG);
ITStatus FSMC_GetITStatus(u32 FSMC_Bank, u32 FSMC_IT);
void FSMC_ClearITPendingBit(u32 FSMC_Bank, u32 FSMC_IT);



 
#line 62 "..\\STM32F10x_lib\\inc\\stm32f10x_lib.h"


#line 1 "..\\STM32F10x_lib\\inc\\stm32f10x_gpio.h"














 

 



 
#line 23 "..\\STM32F10x_lib\\inc\\stm32f10x_gpio.h"

 
#line 32 "..\\STM32F10x_lib\\inc\\stm32f10x_gpio.h"
                                     
 
typedef enum
{ 
  GPIO_Speed_10MHz = 1,
  GPIO_Speed_2MHz, 
  GPIO_Speed_50MHz
}GPIOSpeed_TypeDef;



                                         
 
typedef enum
{ GPIO_Mode_AIN = 0x0,
  GPIO_Mode_IN_FLOATING = 0x04,
  GPIO_Mode_IPD = 0x28,
  GPIO_Mode_IPU = 0x48,
  GPIO_Mode_Out_OD = 0x14,
  GPIO_Mode_Out_PP = 0x10,
  GPIO_Mode_AF_OD = 0x1C,
  GPIO_Mode_AF_PP = 0x18
}GPIOMode_TypeDef;





                              
 
typedef struct
{
  u16 GPIO_Pin;
  GPIOSpeed_TypeDef GPIO_Speed;
  GPIOMode_TypeDef GPIO_Mode;
}GPIO_InitTypeDef;

 
typedef enum
{ Bit_RESET = 0,
  Bit_SET
}BitAction;


 
 
#line 95 "..\\STM32F10x_lib\\inc\\stm32f10x_gpio.h"



#line 114 "..\\STM32F10x_lib\\inc\\stm32f10x_gpio.h"
                            
 
#line 141 "..\\STM32F10x_lib\\inc\\stm32f10x_gpio.h"


#line 156 "..\\STM32F10x_lib\\inc\\stm32f10x_gpio.h"
                              
 
#line 165 "..\\STM32F10x_lib\\inc\\stm32f10x_gpio.h"






                                         
#line 179 "..\\STM32F10x_lib\\inc\\stm32f10x_gpio.h"
                                       
 
#line 197 "..\\STM32F10x_lib\\inc\\stm32f10x_gpio.h"

#line 214 "..\\STM32F10x_lib\\inc\\stm32f10x_gpio.h"
                          
 
 
void GPIO_DeInit(GPIO_TypeDef* GPIOx);
void GPIO_AFIODeInit(void);
void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct);
void GPIO_StructInit(GPIO_InitTypeDef* GPIO_InitStruct);
u8 GPIO_ReadInputDataBit(GPIO_TypeDef* GPIOx, u16 GPIO_Pin);
u16 GPIO_ReadInputData(GPIO_TypeDef* GPIOx);
u8 GPIO_ReadOutputDataBit(GPIO_TypeDef* GPIOx, u16 GPIO_Pin);
u16 GPIO_ReadOutputData(GPIO_TypeDef* GPIOx);
void GPIO_SetBits(GPIO_TypeDef* GPIOx, u16 GPIO_Pin);
void GPIO_ResetBits(GPIO_TypeDef* GPIOx, u16 GPIO_Pin);
void GPIO_WriteBit(GPIO_TypeDef* GPIOx, u16 GPIO_Pin, BitAction BitVal);
void GPIO_Write(GPIO_TypeDef* GPIOx, u16 PortVal);
void GPIO_PinLockConfig(GPIO_TypeDef* GPIOx, u16 GPIO_Pin);
void GPIO_EventOutputConfig(u8 GPIO_PortSource, u8 GPIO_PinSource);
void GPIO_EventOutputCmd(FunctionalState NewState);
void GPIO_PinRemapConfig(u32 GPIO_Remap, FunctionalState NewState);
void GPIO_EXTILineConfig(u8 GPIO_PortSource, u8 GPIO_PinSource);



 
#line 66 "..\\STM32F10x_lib\\inc\\stm32f10x_lib.h"


#line 1 "..\\STM32F10x_lib\\inc\\stm32f10x_i2c.h"














 

 



 
#line 23 "..\\STM32F10x_lib\\inc\\stm32f10x_i2c.h"

 
 
typedef struct
{
  u16 I2C_Mode;
  u16 I2C_DutyCycle;
  u16 I2C_OwnAddress1;
  u16 I2C_Ack;
  u16 I2C_AcknowledgedAddress;
  u32 I2C_ClockSpeed;
}I2C_InitTypeDef;

 



 







 






 






 






 






 
#line 86 "..\\STM32F10x_lib\\inc\\stm32f10x_i2c.h"

#line 96 "..\\STM32F10x_lib\\inc\\stm32f10x_i2c.h"

 






 






 






 
#line 133 "..\\STM32F10x_lib\\inc\\stm32f10x_i2c.h"

#line 140 "..\\STM32F10x_lib\\inc\\stm32f10x_i2c.h"

#line 148 "..\\STM32F10x_lib\\inc\\stm32f10x_i2c.h"

 
#line 171 "..\\STM32F10x_lib\\inc\\stm32f10x_i2c.h"

#line 178 "..\\STM32F10x_lib\\inc\\stm32f10x_i2c.h"

#line 190 "..\\STM32F10x_lib\\inc\\stm32f10x_i2c.h"

 
 






 

     
 


 


 


 



 


 

      
 

                                          
 


#line 246 "..\\STM32F10x_lib\\inc\\stm32f10x_i2c.h"

 

 


 
 
void I2C_DeInit(I2C_TypeDef* I2Cx);
void I2C_Init(I2C_TypeDef* I2Cx, I2C_InitTypeDef* I2C_InitStruct);
void I2C_StructInit(I2C_InitTypeDef* I2C_InitStruct);
void I2C_Cmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_DMACmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_DMALastTransferCmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_GenerateSTART(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_GenerateSTOP(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_AcknowledgeConfig(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_OwnAddress2Config(I2C_TypeDef* I2Cx, u8 Address);
void I2C_DualAddressCmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_GeneralCallCmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_ITConfig(I2C_TypeDef* I2Cx, u16 I2C_IT, FunctionalState NewState);
void I2C_SendData(I2C_TypeDef* I2Cx, u8 Data);
u8 I2C_ReceiveData(I2C_TypeDef* I2Cx);
void I2C_Send7bitAddress(I2C_TypeDef* I2Cx, u8 Address, u8 I2C_Direction);
u16 I2C_ReadRegister(I2C_TypeDef* I2Cx, u8 I2C_Register);
void I2C_SoftwareResetCmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_SMBusAlertConfig(I2C_TypeDef* I2Cx, u16 I2C_SMBusAlert);
void I2C_TransmitPEC(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_PECPositionConfig(I2C_TypeDef* I2Cx, u16 I2C_PECPosition);
void I2C_CalculatePEC(I2C_TypeDef* I2Cx, FunctionalState NewState);
u8 I2C_GetPEC(I2C_TypeDef* I2Cx);
void I2C_ARPCmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_StretchClockCmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_FastModeDutyCycleConfig(I2C_TypeDef* I2Cx, u16 I2C_DutyCycle);
u32 I2C_GetLastEvent(I2C_TypeDef* I2Cx);
ErrorStatus I2C_CheckEvent(I2C_TypeDef* I2Cx, u32 I2C_EVENT);
FlagStatus I2C_GetFlagStatus(I2C_TypeDef* I2Cx, u32 I2C_FLAG);
void I2C_ClearFlag(I2C_TypeDef* I2Cx, u32 I2C_FLAG);
ITStatus I2C_GetITStatus(I2C_TypeDef* I2Cx, u32 I2C_IT);
void I2C_ClearITPendingBit(I2C_TypeDef* I2Cx, u32 I2C_IT);



 
#line 70 "..\\STM32F10x_lib\\inc\\stm32f10x_lib.h"


#line 1 "..\\STM32F10x_lib\\inc\\stm32f10x_iwdg.h"














 

 



 
#line 23 "..\\STM32F10x_lib\\inc\\stm32f10x_iwdg.h"

 
 
 






 
#line 41 "..\\STM32F10x_lib\\inc\\stm32f10x_iwdg.h"

#line 49 "..\\STM32F10x_lib\\inc\\stm32f10x_iwdg.h"

 







 
 
void IWDG_WriteAccessCmd(u16 IWDG_WriteAccess);
void IWDG_SetPrescaler(u8 IWDG_Prescaler);
void IWDG_SetReload(u16 Reload);
void IWDG_ReloadCounter(void);
void IWDG_Enable(void);
FlagStatus IWDG_GetFlagStatus(u16 IWDG_FLAG);



 
#line 74 "..\\STM32F10x_lib\\inc\\stm32f10x_lib.h"


#line 1 "..\\STM32F10x_lib\\inc\\stm32f10x_nvic.h"














 

 



 
#line 23 "..\\STM32F10x_lib\\inc\\stm32f10x_nvic.h"

 
 
typedef struct
{
  u8 NVIC_IRQChannel;
  u8 NVIC_IRQChannelPreemptionPriority;
  u8 NVIC_IRQChannelSubPriority;
  FunctionalState NVIC_IRQChannelCmd;
} NVIC_InitTypeDef;

 
 
#line 96 "..\\STM32F10x_lib\\inc\\stm32f10x_nvic.h"


#line 158 "..\\STM32F10x_lib\\inc\\stm32f10x_nvic.h"


 
#line 170 "..\\STM32F10x_lib\\inc\\stm32f10x_nvic.h"





#line 182 "..\\STM32F10x_lib\\inc\\stm32f10x_nvic.h"












#line 201 "..\\STM32F10x_lib\\inc\\stm32f10x_nvic.h"











 






 








 
#line 239 "..\\STM32F10x_lib\\inc\\stm32f10x_nvic.h"












 
 
void NVIC_DeInit(void);
void NVIC_SCBDeInit(void);
void NVIC_PriorityGroupConfig(u32 NVIC_PriorityGroup);
void NVIC_Init(NVIC_InitTypeDef* NVIC_InitStruct);
void NVIC_StructInit(NVIC_InitTypeDef* NVIC_InitStruct);
void NVIC_SETPRIMASK(void);
void NVIC_RESETPRIMASK(void);
void NVIC_SETFAULTMASK(void);
void NVIC_RESETFAULTMASK(void);
void NVIC_BASEPRICONFIG(u32 NewPriority);
u32 NVIC_GetBASEPRI(void);
u16 NVIC_GetCurrentPendingIRQChannel(void);
ITStatus NVIC_GetIRQChannelPendingBitStatus(u8 NVIC_IRQChannel);
void NVIC_SetIRQChannelPendingBit(u8 NVIC_IRQChannel);
void NVIC_ClearIRQChannelPendingBit(u8 NVIC_IRQChannel);
u16 NVIC_GetCurrentActiveHandler(void);
ITStatus NVIC_GetIRQChannelActiveBitStatus(u8 NVIC_IRQChannel);
u32 NVIC_GetCPUID(void);
void NVIC_SetVectorTable(u32 NVIC_VectTab, u32 Offset);
void NVIC_GenerateSystemReset(void);
void NVIC_GenerateCoreReset(void);
void NVIC_SystemLPConfig(u8 LowPowerMode, FunctionalState NewState);
void NVIC_SystemHandlerConfig(u32 SystemHandler, FunctionalState NewState);
void NVIC_SystemHandlerPriorityConfig(u32 SystemHandler, u8 SystemHandlerPreemptionPriority,
                                      u8 SystemHandlerSubPriority);
ITStatus NVIC_GetSystemHandlerPendingBitStatus(u32 SystemHandler);
void NVIC_SetSystemHandlerPendingBit(u32 SystemHandler);
void NVIC_ClearSystemHandlerPendingBit(u32 SystemHandler);
ITStatus NVIC_GetSystemHandlerActiveBitStatus(u32 SystemHandler);
u32 NVIC_GetFaultHandlerSources(u32 SystemHandler);
u32 NVIC_GetFaultAddress(u32 SystemHandler);



 
#line 78 "..\\STM32F10x_lib\\inc\\stm32f10x_lib.h"


#line 1 "..\\STM32F10x_lib\\inc\\stm32f10x_pwr.h"














 

 



 
#line 23 "..\\STM32F10x_lib\\inc\\stm32f10x_pwr.h"

 
 
 
#line 35 "..\\STM32F10x_lib\\inc\\stm32f10x_pwr.h"






 






 




 
 








 
 
void PWR_DeInit(void);
void PWR_BackupAccessCmd(FunctionalState NewState);
void PWR_PVDCmd(FunctionalState NewState);
void PWR_PVDLevelConfig(u32 PWR_PVDLevel);
void PWR_WakeUpPinCmd(FunctionalState NewState);
void PWR_EnterSTOPMode(u32 PWR_Regulator, u8 PWR_STOPEntry);
void PWR_EnterSTANDBYMode(void);
FlagStatus PWR_GetFlagStatus(u32 PWR_FLAG);
void PWR_ClearFlag(u32 PWR_FLAG);



 
#line 82 "..\\STM32F10x_lib\\inc\\stm32f10x_lib.h"


#line 1 "..\\STM32F10x_lib\\inc\\stm32f10x_rcc.h"














 

 



 
#line 23 "..\\STM32F10x_lib\\inc\\stm32f10x_rcc.h"

 
typedef struct
{
  u32 SYSCLK_Frequency;
  u32 HCLK_Frequency;
  u32 PCLK1_Frequency;
  u32 PCLK2_Frequency;
  u32 ADCCLK_Frequency;
}RCC_ClocksTypeDef;

 
 







 








 
#line 68 "..\\STM32F10x_lib\\inc\\stm32f10x_rcc.h"

#line 77 "..\\STM32F10x_lib\\inc\\stm32f10x_rcc.h"

 








 
#line 97 "..\\STM32F10x_lib\\inc\\stm32f10x_rcc.h"







 










 
#line 122 "..\\STM32F10x_lib\\inc\\stm32f10x_rcc.h"







 






 








 







 








 
#line 170 "..\\STM32F10x_lib\\inc\\stm32f10x_rcc.h"



 
#line 190 "..\\STM32F10x_lib\\inc\\stm32f10x_rcc.h"



 
#line 215 "..\\STM32F10x_lib\\inc\\stm32f10x_rcc.h"



 










 
#line 241 "..\\STM32F10x_lib\\inc\\stm32f10x_rcc.h"

#line 248 "..\\STM32F10x_lib\\inc\\stm32f10x_rcc.h"



 
 
void RCC_DeInit(void);
void RCC_HSEConfig(u32 RCC_HSE);
ErrorStatus RCC_WaitForHSEStartUp(void);
void RCC_AdjustHSICalibrationValue(u8 HSICalibrationValue);
void RCC_HSICmd(FunctionalState NewState);
void RCC_PLLConfig(u32 RCC_PLLSource, u32 RCC_PLLMul);
void RCC_PLLCmd(FunctionalState NewState);
void RCC_SYSCLKConfig(u32 RCC_SYSCLKSource);
u8 RCC_GetSYSCLKSource(void);
void RCC_HCLKConfig(u32 RCC_SYSCLK);
void RCC_PCLK1Config(u32 RCC_HCLK);
void RCC_PCLK2Config(u32 RCC_HCLK);
void RCC_ITConfig(u8 RCC_IT, FunctionalState NewState);
void RCC_USBCLKConfig(u32 RCC_USBCLKSource);
void RCC_ADCCLKConfig(u32 RCC_PCLK2);
void RCC_LSEConfig(u8 RCC_LSE);
void RCC_LSICmd(FunctionalState NewState);
void RCC_RTCCLKConfig(u32 RCC_RTCCLKSource);
void RCC_RTCCLKCmd(FunctionalState NewState);
void RCC_GetClocksFreq(RCC_ClocksTypeDef* RCC_Clocks);
void RCC_AHBPeriphClockCmd(u32 RCC_AHBPeriph, FunctionalState NewState);
void RCC_APB2PeriphClockCmd(u32 RCC_APB2Periph, FunctionalState NewState);
void RCC_APB1PeriphClockCmd(u32 RCC_APB1Periph, FunctionalState NewState);
void RCC_APB2PeriphResetCmd(u32 RCC_APB2Periph, FunctionalState NewState);
void RCC_APB1PeriphResetCmd(u32 RCC_APB1Periph, FunctionalState NewState);
void RCC_BackupResetCmd(FunctionalState NewState);
void RCC_ClockSecuritySystemCmd(FunctionalState NewState);
void RCC_MCOConfig(u8 RCC_MCO);
FlagStatus RCC_GetFlagStatus(u8 RCC_FLAG);
void RCC_ClearFlag(void);
ITStatus RCC_GetITStatus(u8 RCC_IT);
void RCC_ClearITPendingBit(u8 RCC_IT);



 
#line 86 "..\\STM32F10x_lib\\inc\\stm32f10x_lib.h"


#line 1 "..\\STM32F10x_lib\\inc\\stm32f10x_rtc.h"














 

 



 
#line 23 "..\\STM32F10x_lib\\inc\\stm32f10x_rtc.h"

 
 
 








                                                                     
 













                           
 
 
void RTC_ITConfig(u16 RTC_IT, FunctionalState NewState);
void RTC_EnterConfigMode(void);
void RTC_ExitConfigMode(void);
u32  RTC_GetCounter(void);
void RTC_SetCounter(u32 CounterValue);
void RTC_SetPrescaler(u32 PrescalerValue);
void RTC_SetAlarm(u32 AlarmValue);
u32  RTC_GetDivider(void);
void RTC_WaitForLastTask(void);
void RTC_WaitForSynchro(void);
FlagStatus RTC_GetFlagStatus(u16 RTC_FLAG);
void RTC_ClearFlag(u16 RTC_FLAG);
ITStatus RTC_GetITStatus(u16 RTC_IT);
void RTC_ClearITPendingBit(u16 RTC_IT);



 
#line 90 "..\\STM32F10x_lib\\inc\\stm32f10x_lib.h"


#line 1 "..\\STM32F10x_lib\\inc\\stm32f10x_sdio.h"














 

 



 
#line 23 "..\\STM32F10x_lib\\inc\\stm32f10x_sdio.h"

 
typedef struct
{
  u8 SDIO_ClockDiv;
  u32 SDIO_ClockEdge;
  u32 SDIO_ClockBypass;
  u32 SDIO_ClockPowerSave;
  u32 SDIO_BusWide;
  u32 SDIO_HardwareFlowControl;
} SDIO_InitTypeDef;

typedef struct
{
  u32 SDIO_Argument;
  u32 SDIO_CmdIndex;
  u32 SDIO_Response;
  u32 SDIO_Wait;
  u32 SDIO_CPSM;
} SDIO_CmdInitTypeDef;

typedef struct
{
  u32 SDIO_DataTimeOut;
  u32 SDIO_DataLength;
  u32 SDIO_DataBlockSize;
  u32 SDIO_TransferDir;
  u32 SDIO_TransferMode;
  u32 SDIO_DPSM;
} SDIO_DataInitTypeDef;

 
 





                                   






  






 






                                
  





                                  
 





 
#line 121 "..\\STM32F10x_lib\\inc\\stm32f10x_sdio.h"



 


 








 







 





 








 


 
#line 178 "..\\STM32F10x_lib\\inc\\stm32f10x_sdio.h"

#line 194 "..\\STM32F10x_lib\\inc\\stm32f10x_sdio.h"

 






 






 





 
#line 240 "..\\STM32F10x_lib\\inc\\stm32f10x_sdio.h"

#line 265 "..\\STM32F10x_lib\\inc\\stm32f10x_sdio.h"



#line 292 "..\\STM32F10x_lib\\inc\\stm32f10x_sdio.h"


                                                        
 






 
 
void SDIO_DeInit(void);
void SDIO_Init(SDIO_InitTypeDef* SDIO_InitStruct);
void SDIO_StructInit(SDIO_InitTypeDef* SDIO_InitStruct);
void SDIO_ClockCmd(FunctionalState NewState);
void SDIO_SetPowerState(u32 SDIO_PowerState);
u32 SDIO_GetPowerState(void);
void SDIO_ITConfig(u32 SDIO_IT, FunctionalState NewState);
void SDIO_DMACmd(FunctionalState NewState);
void SDIO_SendCommand(SDIO_CmdInitTypeDef *SDIO_CmdInitStruct);
void SDIO_CmdStructInit(SDIO_CmdInitTypeDef* SDIO_CmdInitStruct);
u8 SDIO_GetCommandResponse(void);
u32 SDIO_GetResponse(u32 SDIO_RESP);
void SDIO_DataConfig(SDIO_DataInitTypeDef* SDIO_DataInitStruct);
void SDIO_DataStructInit(SDIO_DataInitTypeDef* SDIO_DataInitStruct);
u32 SDIO_GetDataCounter(void);
u32 SDIO_ReadData(void);
void SDIO_WriteData(u32 Data);
u32 SDIO_GetFIFOCount(void);
void SDIO_StartSDIOReadWait(FunctionalState NewState);
void SDIO_StopSDIOReadWait(FunctionalState NewState);
void SDIO_SetSDIOReadWaitMode(u32 SDIO_ReadWaitMode);
void SDIO_SetSDIOOperation(FunctionalState NewState);
void SDIO_SendSDIOSuspendCmd(FunctionalState NewState);
void SDIO_CommandCompletionCmd(FunctionalState NewState);
void SDIO_CEATAITCmd(FunctionalState NewState);
void SDIO_SendCEATACmd(FunctionalState NewState);
FlagStatus SDIO_GetFlagStatus(u32 SDIO_FLAG);
void SDIO_ClearFlag(u32 SDIO_FLAG);
ITStatus SDIO_GetITStatus(u32 SDIO_IT);
void SDIO_ClearITPendingBit(u32 SDIO_IT);



 
#line 94 "..\\STM32F10x_lib\\inc\\stm32f10x_lib.h"


#line 1 "..\\STM32F10x_lib\\inc\\stm32f10x_spi.h"














 

 



 
#line 23 "..\\STM32F10x_lib\\inc\\stm32f10x_spi.h"

 
 
typedef struct
{
  u16 SPI_Direction;
  u16 SPI_Mode;
  u16 SPI_DataSize;
  u16 SPI_CPOL;
  u16 SPI_CPHA;
  u16 SPI_NSS;
  u16 SPI_BaudRatePrescaler;
  u16 SPI_FirstBit;
  u16 SPI_CRCPolynomial;
}SPI_InitTypeDef;

 
typedef struct
{
  u16 I2S_Mode;
  u16 I2S_Standard;
  u16 I2S_DataFormat;
  u16 I2S_MCLKOutput;
  u16 I2S_AudioFreq;
  u16 I2S_CPOL;
}I2S_InitTypeDef;

 








 










 






 






 






 






 






 
#line 114 "..\\STM32F10x_lib\\inc\\stm32f10x_spi.h"

#line 123 "..\\STM32F10x_lib\\inc\\stm32f10x_spi.h"

 






 










 












 










  






 
#line 180 "..\\STM32F10x_lib\\inc\\stm32f10x_spi.h"

#line 187 "..\\STM32F10x_lib\\inc\\stm32f10x_spi.h"

 






 





 






 





 






 






















 
#line 253 "..\\STM32F10x_lib\\inc\\stm32f10x_spi.h"

#line 260 "..\\STM32F10x_lib\\inc\\stm32f10x_spi.h"

 


 
 
void SPI_I2S_DeInit(SPI_TypeDef* SPIx);
void SPI_Init(SPI_TypeDef* SPIx, SPI_InitTypeDef* SPI_InitStruct);
void I2S_Init(SPI_TypeDef* SPIx, I2S_InitTypeDef* I2S_InitStruct);
void SPI_StructInit(SPI_InitTypeDef* SPI_InitStruct);
void I2S_StructInit(I2S_InitTypeDef* I2S_InitStruct);
void SPI_Cmd(SPI_TypeDef* SPIx, FunctionalState NewState);
void I2S_Cmd(SPI_TypeDef* SPIx, FunctionalState NewState);
void SPI_I2S_ITConfig(SPI_TypeDef* SPIx, u8 SPI_I2S_IT, FunctionalState NewState);
void SPI_I2S_DMACmd(SPI_TypeDef* SPIx, u16 SPI_I2S_DMAReq, FunctionalState NewState);
void SPI_I2S_SendData(SPI_TypeDef* SPIx, u16 Data);
u16 SPI_I2S_ReceiveData(SPI_TypeDef* SPIx);
void SPI_NSSInternalSoftwareConfig(SPI_TypeDef* SPIx, u16 SPI_NSSInternalSoft);
void SPI_SSOutputCmd(SPI_TypeDef* SPIx, FunctionalState NewState);
void SPI_DataSizeConfig(SPI_TypeDef* SPIx, u16 SPI_DataSize);
void SPI_TransmitCRC(SPI_TypeDef* SPIx);
void SPI_CalculateCRC(SPI_TypeDef* SPIx, FunctionalState NewState);
u16 SPI_GetCRC(SPI_TypeDef* SPIx, u8 SPI_CRC);
u16 SPI_GetCRCPolynomial(SPI_TypeDef* SPIx);
void SPI_BiDirectionalLineConfig(SPI_TypeDef* SPIx, u16 SPI_Direction);
FlagStatus SPI_I2S_GetFlagStatus(SPI_TypeDef* SPIx, u16 SPI_I2S_FLAG);
void SPI_I2S_ClearFlag(SPI_TypeDef* SPIx, u16 SPI_I2S_FLAG);
ITStatus SPI_I2S_GetITStatus(SPI_TypeDef* SPIx, u8 SPI_I2S_IT);
void SPI_I2S_ClearITPendingBit(SPI_TypeDef* SPIx, u8 SPI_I2S_IT);



 
#line 98 "..\\STM32F10x_lib\\inc\\stm32f10x_lib.h"


#line 1 "..\\STM32F10x_lib\\inc\\stm32f10x_systick.h"














 

 



 
#line 23 "..\\STM32F10x_lib\\inc\\stm32f10x_systick.h"

 
 
 






 








 










 
 
void SysTick_CLKSourceConfig(u32 SysTick_CLKSource);
void SysTick_SetReload(u32 Reload);
void SysTick_CounterCmd(u32 SysTick_Counter);
void SysTick_ITConfig(FunctionalState NewState);
u32 SysTick_GetCounter(void);
FlagStatus SysTick_GetFlagStatus(u8 SysTick_FLAG);



 
#line 102 "..\\STM32F10x_lib\\inc\\stm32f10x_lib.h"


#line 1 "..\\STM32F10x_lib\\inc\\stm32f10x_tim.h"














 

 



 
#line 23 "..\\STM32F10x_lib\\inc\\stm32f10x_tim.h"

 

 
typedef struct
{
  u16 TIM_Prescaler;
  u16 TIM_CounterMode;
  u16 TIM_Period;
  u16 TIM_ClockDivision;
  u8 TIM_RepetitionCounter;
} TIM_TimeBaseInitTypeDef;

 
typedef struct
{
  u16 TIM_OCMode;
  u16 TIM_OutputState;
  u16 TIM_OutputNState;
  u16 TIM_Pulse;
  u16 TIM_OCPolarity;
  u16 TIM_OCNPolarity;
  u16 TIM_OCIdleState;
  u16 TIM_OCNIdleState;
} TIM_OCInitTypeDef;

 
typedef struct
{
  u16 TIM_Channel;
  u16 TIM_ICPolarity;
  u16 TIM_ICSelection;
  u16 TIM_ICPrescaler;
  u16 TIM_ICFilter;
} TIM_ICInitTypeDef;

 
typedef struct
{
  u16 TIM_OSSRState;
  u16 TIM_OSSIState;
  u16 TIM_LOCKLevel; 
  u16 TIM_DeadTime;
  u16 TIM_Break;
  u16 TIM_BreakPolarity;
  u16 TIM_AutomaticOutput;
} TIM_BDTRInitTypeDef;

                              

#line 81 "..\\STM32F10x_lib\\inc\\stm32f10x_tim.h"




#line 91 "..\\STM32F10x_lib\\inc\\stm32f10x_tim.h"

 
#line 99 "..\\STM32F10x_lib\\inc\\stm32f10x_tim.h"

#line 106 "..\\STM32F10x_lib\\inc\\stm32f10x_tim.h"

#line 115 "..\\STM32F10x_lib\\inc\\stm32f10x_tim.h"
 






 
















 








 












 






 






 






 






 






 






 






 






 





 










 






 






 






 






 






 








 










 
#line 298 "..\\STM32F10x_lib\\inc\\stm32f10x_tim.h"



#line 308 "..\\STM32F10x_lib\\inc\\stm32f10x_tim.h"

#line 317 "..\\STM32F10x_lib\\inc\\stm32f10x_tim.h"

 
#line 338 "..\\STM32F10x_lib\\inc\\stm32f10x_tim.h"

#line 358 "..\\STM32F10x_lib\\inc\\stm32f10x_tim.h"

 
#line 378 "..\\STM32F10x_lib\\inc\\stm32f10x_tim.h"

#line 397 "..\\STM32F10x_lib\\inc\\stm32f10x_tim.h"

 
#line 406 "..\\STM32F10x_lib\\inc\\stm32f10x_tim.h"



#line 416 "..\\STM32F10x_lib\\inc\\stm32f10x_tim.h"

 










 
#line 437 "..\\STM32F10x_lib\\inc\\stm32f10x_tim.h"

#line 446 "..\\STM32F10x_lib\\inc\\stm32f10x_tim.h"






 








 






 






 






  








 
#line 500 "..\\STM32F10x_lib\\inc\\stm32f10x_tim.h"



#line 510 "..\\STM32F10x_lib\\inc\\stm32f10x_tim.h"

 






 






 





                                     
 






  
#line 548 "..\\STM32F10x_lib\\inc\\stm32f10x_tim.h"

#line 557 "..\\STM32F10x_lib\\inc\\stm32f10x_tim.h"

#line 593 "..\\STM32F10x_lib\\inc\\stm32f10x_tim.h"

 










 






 
#line 625 "..\\STM32F10x_lib\\inc\\stm32f10x_tim.h"

#line 638 "..\\STM32F10x_lib\\inc\\stm32f10x_tim.h"

#line 646 "..\\STM32F10x_lib\\inc\\stm32f10x_tim.h"

#line 665 "..\\STM32F10x_lib\\inc\\stm32f10x_tim.h"
                                                                                            
 


 


 
 

void TIM_DeInit(TIM_TypeDef* TIMx);
void TIM_TimeBaseInit(TIM_TypeDef* TIMx, TIM_TimeBaseInitTypeDef* TIM_TimeBaseInitStruct);
void TIM_OC1Init(TIM_TypeDef* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);
void TIM_OC2Init(TIM_TypeDef* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);
void TIM_OC3Init(TIM_TypeDef* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);
void TIM_OC4Init(TIM_TypeDef* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);
void TIM_ICInit(TIM_TypeDef* TIMx, TIM_ICInitTypeDef* TIM_ICInitStruct);
void TIM_PWMIConfig(TIM_TypeDef* TIMx, TIM_ICInitTypeDef* TIM_ICInitStruct);
void TIM_BDTRConfig(TIM_TypeDef* TIMx, TIM_BDTRInitTypeDef *TIM_BDTRInitStruct);
void TIM_TimeBaseStructInit(TIM_TimeBaseInitTypeDef* TIM_TimeBaseInitStruct);
void TIM_OCStructInit(TIM_OCInitTypeDef* TIM_OCInitStruct);
void TIM_ICStructInit(TIM_ICInitTypeDef* TIM_ICInitStruct);
void TIM_BDTRStructInit(TIM_BDTRInitTypeDef* TIM_BDTRInitStruct);
void TIM_Cmd(TIM_TypeDef* TIMx, FunctionalState NewState);
void TIM_CtrlPWMOutputs(TIM_TypeDef* TIMx, FunctionalState NewState);
void TIM_ITConfig(TIM_TypeDef* TIMx, u16 TIM_IT, FunctionalState NewState);
void TIM_GenerateEvent(TIM_TypeDef* TIMx, u16 TIM_EventSource);
void TIM_DMAConfig(TIM_TypeDef* TIMx, u16 TIM_DMABase, u16 TIM_DMABurstLength);
void TIM_DMACmd(TIM_TypeDef* TIMx, u16 TIM_DMASource, FunctionalState NewState);
void TIM_InternalClockConfig(TIM_TypeDef* TIMx);
void TIM_ITRxExternalClockConfig(TIM_TypeDef* TIMx, u16 TIM_InputTriggerSource);
void TIM_TIxExternalClockConfig(TIM_TypeDef* TIMx, u16 TIM_TIxExternalCLKSource,
                                u16 TIM_ICPolarity, u16 ICFilter);                                
void TIM_ETRClockMode1Config(TIM_TypeDef* TIMx, u16 TIM_ExtTRGPrescaler, u16 TIM_ExtTRGPolarity,
                             u16 ExtTRGFilter);
void TIM_ETRClockMode2Config(TIM_TypeDef* TIMx, u16 TIM_ExtTRGPrescaler, 
                             u16 TIM_ExtTRGPolarity, u16 ExtTRGFilter);
void TIM_ETRConfig(TIM_TypeDef* TIMx, u16 TIM_ExtTRGPrescaler, u16 TIM_ExtTRGPolarity,
                   u16 ExtTRGFilter);
void TIM_PrescalerConfig(TIM_TypeDef* TIMx, u16 Prescaler, u16 TIM_PSCReloadMode);
void TIM_CounterModeConfig(TIM_TypeDef* TIMx, u16 TIM_CounterMode);
void TIM_SelectInputTrigger(TIM_TypeDef* TIMx, u16 TIM_InputTriggerSource);
void TIM_EncoderInterfaceConfig(TIM_TypeDef* TIMx, u16 TIM_EncoderMode,
                                u16 TIM_IC1Polarity, u16 TIM_IC2Polarity);
void TIM_ForcedOC1Config(TIM_TypeDef* TIMx, u16 TIM_ForcedAction);
void TIM_ForcedOC2Config(TIM_TypeDef* TIMx, u16 TIM_ForcedAction);
void TIM_ForcedOC3Config(TIM_TypeDef* TIMx, u16 TIM_ForcedAction);
void TIM_ForcedOC4Config(TIM_TypeDef* TIMx, u16 TIM_ForcedAction);
void TIM_ARRPreloadConfig(TIM_TypeDef* TIMx, FunctionalState NewState);
void TIM_SelectCOM(TIM_TypeDef* TIMx, FunctionalState NewState);
void TIM_SelectCCDMA(TIM_TypeDef* TIMx, FunctionalState NewState);
void TIM_CCPreloadControl(TIM_TypeDef* TIMx, FunctionalState NewState);
void TIM_OC1PreloadConfig(TIM_TypeDef* TIMx, u16 TIM_OCPreload);
void TIM_OC2PreloadConfig(TIM_TypeDef* TIMx, u16 TIM_OCPreload);
void TIM_OC3PreloadConfig(TIM_TypeDef* TIMx, u16 TIM_OCPreload);
void TIM_OC4PreloadConfig(TIM_TypeDef* TIMx, u16 TIM_OCPreload);
void TIM_OC1FastConfig(TIM_TypeDef* TIMx, u16 TIM_OCFast);
void TIM_OC2FastConfig(TIM_TypeDef* TIMx, u16 TIM_OCFast);
void TIM_OC3FastConfig(TIM_TypeDef* TIMx, u16 TIM_OCFast);
void TIM_OC4FastConfig(TIM_TypeDef* TIMx, u16 TIM_OCFast);
void TIM_ClearOC1Ref(TIM_TypeDef* TIMx, u16 TIM_OCClear);
void TIM_ClearOC2Ref(TIM_TypeDef* TIMx, u16 TIM_OCClear);
void TIM_ClearOC3Ref(TIM_TypeDef* TIMx, u16 TIM_OCClear);
void TIM_ClearOC4Ref(TIM_TypeDef* TIMx, u16 TIM_OCClear);
void TIM_OC1PolarityConfig(TIM_TypeDef* TIMx, u16 TIM_OCPolarity);
void TIM_OC1NPolarityConfig(TIM_TypeDef* TIMx, u16 TIM_OCNPolarity);
void TIM_OC2PolarityConfig(TIM_TypeDef* TIMx, u16 TIM_OCPolarity);
void TIM_OC2NPolarityConfig(TIM_TypeDef* TIMx, u16 TIM_OCNPolarity);
void TIM_OC3PolarityConfig(TIM_TypeDef* TIMx, u16 TIM_OCPolarity);
void TIM_OC3NPolarityConfig(TIM_TypeDef* TIMx, u16 TIM_OCNPolarity);
void TIM_OC4PolarityConfig(TIM_TypeDef* TIMx, u16 TIM_OCPolarity);
void TIM_CCxCmd(TIM_TypeDef* TIMx, u16 TIM_Channel, u16 TIM_CCx);
void TIM_CCxNCmd(TIM_TypeDef* TIMx, u16 TIM_Channel, u16 TIM_CCxN);
void TIM_SelectOCxM(TIM_TypeDef* TIMx, u16 TIM_Channel, u16 TIM_OCMode);
void TIM_UpdateDisableConfig(TIM_TypeDef* TIMx, FunctionalState NewState);
void TIM_UpdateRequestConfig(TIM_TypeDef* TIMx, u16 TIM_UpdateSource);
void TIM_SelectHallSensor(TIM_TypeDef* TIMx, FunctionalState NewState);
void TIM_SelectOnePulseMode(TIM_TypeDef* TIMx, u16 TIM_OPMode);
void TIM_SelectOutputTrigger(TIM_TypeDef* TIMx, u16 TIM_TRGOSource);
void TIM_SelectSlaveMode(TIM_TypeDef* TIMx, u16 TIM_SlaveMode);
void TIM_SelectMasterSlaveMode(TIM_TypeDef* TIMx, u16 TIM_MasterSlaveMode);
void TIM_SetCounter(TIM_TypeDef* TIMx, u16 Counter);
void TIM_SetAutoreload(TIM_TypeDef* TIMx, u16 Autoreload);
void TIM_SetCompare1(TIM_TypeDef* TIMx, u16 Compare1);
void TIM_SetCompare2(TIM_TypeDef* TIMx, u16 Compare2);
void TIM_SetCompare3(TIM_TypeDef* TIMx, u16 Compare3);
void TIM_SetCompare4(TIM_TypeDef* TIMx, u16 Compare4);
void TIM_SetIC1Prescaler(TIM_TypeDef* TIMx, u16 TIM_ICPSC);
void TIM_SetIC2Prescaler(TIM_TypeDef* TIMx, u16 TIM_ICPSC);
void TIM_SetIC3Prescaler(TIM_TypeDef* TIMx, u16 TIM_ICPSC);
void TIM_SetIC4Prescaler(TIM_TypeDef* TIMx, u16 TIM_ICPSC);
void TIM_SetClockDivision(TIM_TypeDef* TIMx, u16 TIM_CKD);
u16 TIM_GetCapture1(TIM_TypeDef* TIMx);
u16 TIM_GetCapture2(TIM_TypeDef* TIMx);
u16 TIM_GetCapture3(TIM_TypeDef* TIMx);
u16 TIM_GetCapture4(TIM_TypeDef* TIMx);
u16 TIM_GetCounter(TIM_TypeDef* TIMx);
u16 TIM_GetPrescaler(TIM_TypeDef* TIMx);
FlagStatus TIM_GetFlagStatus(TIM_TypeDef* TIMx, u16 TIM_FLAG);
void TIM_ClearFlag(TIM_TypeDef* TIMx, u16 TIM_FLAG);
ITStatus TIM_GetITStatus(TIM_TypeDef* TIMx, u16 TIM_IT);
void TIM_ClearITPendingBit(TIM_TypeDef* TIMx, u16 TIM_IT);
                                                                                                             


 








#line 106 "..\\STM32F10x_lib\\inc\\stm32f10x_lib.h"


#line 1 "..\\STM32F10x_lib\\inc\\stm32f10x_usart.h"














 

 



 
#line 23 "..\\STM32F10x_lib\\inc\\stm32f10x_usart.h"

 
 
typedef struct
{
  u32 USART_BaudRate;
  u16 USART_WordLength;
  u16 USART_StopBits;
  u16 USART_Parity;
  u16 USART_Mode;
  u16 USART_HardwareFlowControl;  
} USART_InitTypeDef;

 
typedef struct
{
  u16 USART_Clock;
  u16 USART_CPOL;
  u16 USART_CPHA;
  u16 USART_LastBit;
} USART_ClockInitTypeDef;

 















 


                                    



 









 








 





 















 






 




                               
 




 






 
#line 146 "..\\STM32F10x_lib\\inc\\stm32f10x_usart.h"






















 





 






 







 






 
#line 207 "..\\STM32F10x_lib\\inc\\stm32f10x_usart.h"






                              










 
 
void USART_DeInit(USART_TypeDef* USARTx);
void USART_Init(USART_TypeDef* USARTx, USART_InitTypeDef* USART_InitStruct);
void USART_StructInit(USART_InitTypeDef* USART_InitStruct);
void USART_ClockInit(USART_TypeDef* USARTx, USART_ClockInitTypeDef* USART_ClockInitStruct);
void USART_ClockStructInit(USART_ClockInitTypeDef* USART_ClockInitStruct);
void USART_Cmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_ITConfig(USART_TypeDef* USARTx, u16 USART_IT, FunctionalState NewState);
void USART_DMACmd(USART_TypeDef* USARTx, u16 USART_DMAReq, FunctionalState NewState);
void USART_SetAddress(USART_TypeDef* USARTx, u8 USART_Address);
void USART_WakeUpConfig(USART_TypeDef* USARTx, u16 USART_WakeUp);
void USART_ReceiverWakeUpCmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_LINBreakDetectLengthConfig(USART_TypeDef* USARTx, u16 USART_LINBreakDetectLength);
void USART_LINCmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_SendData(USART_TypeDef* USARTx, u16 Data);
u16 USART_ReceiveData(USART_TypeDef* USARTx);
void USART_SendBreak(USART_TypeDef* USARTx);
void USART_SetGuardTime(USART_TypeDef* USARTx, u8 USART_GuardTime);
void USART_SetPrescaler(USART_TypeDef* USARTx, u8 USART_Prescaler);
void USART_SmartCardCmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_SmartCardNACKCmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_HalfDuplexCmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_IrDAConfig(USART_TypeDef* USARTx, u16 USART_IrDAMode);
void USART_IrDACmd(USART_TypeDef* USARTx, FunctionalState NewState);
FlagStatus USART_GetFlagStatus(USART_TypeDef* USARTx, u16 USART_FLAG);
void USART_ClearFlag(USART_TypeDef* USARTx, u16 USART_FLAG);
ITStatus USART_GetITStatus(USART_TypeDef* USARTx, u16 USART_IT);
void USART_ClearITPendingBit(USART_TypeDef* USARTx, u16 USART_IT);



 
#line 110 "..\\STM32F10x_lib\\inc\\stm32f10x_lib.h"


#line 1 "..\\STM32F10x_lib\\inc\\stm32f10x_wwdg.h"














 

 



 
#line 23 "..\\STM32F10x_lib\\inc\\stm32f10x_wwdg.h"

 
 
 














 
 
void WWDG_DeInit(void);
void WWDG_SetPrescaler(u32 WWDG_Prescaler);
void WWDG_SetWindowValue(u8 WindowValue);
void WWDG_EnableIT(void);
void WWDG_SetCounter(u8 Counter);
void WWDG_Enable(u8 Counter);
FlagStatus WWDG_GetFlagStatus(void);
void WWDG_ClearFlag(void);



 
#line 114 "..\\STM32F10x_lib\\inc\\stm32f10x_lib.h"


 
 
 
 
void debug(void);



 
#line 5 "..\\target\\system.h"
#line 6 "..\\target\\system.h"











void dbg_void(void);
void print_void(void *fmt,...);
 







void enable_timer(void);
void disable_timer(void);
void Delay(u32 nTime);
void RCC_Configuration(void);
void NVIC_Configuration(void);
void GPIO_Configuration(void);
void USART_Configuration(USART_TypeDef *USARTx);
void timerbase_config(void);
void SPI1_Config(void);
void EXTI_Configuration(void);
void debug_data_stream(char *info,char *pdata,u16 len);
char Uart_GetKey(void);
void Uart_SendByte(u8 ch);
void Uart_GetString(char *string);
int Uart_GetIntNum(void);
int Uart_GetIntNum_GJ(void);
int write_flash(u32 StartAddr,u16 *buf,u16 len);
int read_flash(u32 StartAddr,u16 *buf,u16 len);


void RCC_Configuration(void);
void watch_dog_config(void);
void NVIC_Configuration(void);
void GPIO_Configuration(void);
void assert_failed(u8* file, u32 line);


#line 11 "..\\sdio\\inc\\common.h"
#line 1 "..\\sdio\\inc\\s3cmci.h"








 



#line 14 "..\\sdio\\inc\\s3cmci.h"



 








enum s3cmci_waitfor {
	COMPLETION_NONE,
	COMPLETION_FINALIZE,
	COMPLETION_CMDSENT,
	COMPLETION_RSPFIN,
	COMPLETION_XFERFINISH,
	COMPLETION_XFERFINISH_RSPFIN,
};
	

struct stm32_host {
	
	
	struct mmc_host		*mmc;
	
	
	unsigned long 		base;
	int			irq;
	int			irq_cd;
	int			dma;

	unsigned long		clk_rate;
	unsigned long		clk_div;
	unsigned long		real_rate;
	u8			prescaler;

	int			is2440;
	unsigned		sdiimsk;
	unsigned		sdidata;
	int			dodma;
	int			dmatogo;

	bool			irq_disabled;
	bool			irq_enabled;
	bool			irq_state;
	int			sdio_irqen;

	struct mmc_request	*mrq;
	int			cmd_is_stop;

	
	enum s3cmci_waitfor	complete_what;

	int			dma_complete;

	u32			pio_sgptr;
	u32			pio_bytes;
	u32			pio_count;
	u32			*pio_ptr;

	u32			pio_active;

	int			bus_width;

	
	
	char			*status;

	unsigned int		ccnt, dcnt;










 
};
struct mmc_host * stm32_probe(void);
void  stm32_irq(void);
#line 12 "..\\sdio\\inc\\common.h"




enum { MSG_MSGDUMP, MSG_DEBUG, MSG_INFO, MSG_WARNING, MSG_ERROR };




















 
#line 47 "..\\sdio\\inc\\common.h"



#line 58 "..\\sdio\\inc\\common.h"




 



















#line 88 "..\\sdio\\inc\\common.h"


#line 99 "..\\sdio\\inc\\common.h"

#line 110 "..\\sdio\\inc\\common.h"


#line 130 "..\\sdio\\inc\\common.h"





 







static void xdbug_buf(const char * name , const unsigned char * buf , const int len)
{
	int i = 0;
	printf("dbug buf [%s]\n",name);
	for(;i<len;i++)
	{
		printf("0x%02x,",buf[i]);
	}
	printf("\n");
}
#line 164 "..\\sdio\\inc\\common.h"























#line 195 "..\\sdio\\inc\\common.h"








void mmc_delay(unsigned int time);
void ms_delay(void);
void  mdelay(unsigned long time);

bool time_after(char res, unsigned long *time_out);
const char *print_ssid(char *buf, const char *ssid, u8 ssid_len);
u8 convert_from_bytes_to_power_of_two(u16 NumberOfBytes);
void  *ERR_PTR(long error);
long  PTR_ERR(const void *ptr);
long  IS_ERR(const void *ptr);
void  lbs_hex(unsigned int grp, const char *prompt, u8 *buf, int len);
#line 223 "..\\sdio\\inc\\common.h"

#line 24 "..\\marvel\\driver\\inc\\if.h"
#line 1 "..\\marvel\\driver\\inc\\wireless.h"







 

#line 1097 "..\\marvel\\driver\\inc\\wireless.h"

#line 25 "..\\marvel\\driver\\inc\\if.h"





 
#line 41 "..\\marvel\\driver\\inc\\if.h"


















 
#line 73 "..\\marvel\\driver\\inc\\if.h"




 
#line 85 "..\\marvel\\driver\\inc\\if.h"

 
#line 100 "..\\marvel\\driver\\inc\\if.h"

 
enum {
	IF_OPER_UNKNOWN,
	IF_OPER_NOTPRESENT,
	IF_OPER_DOWN,
	IF_OPER_LOWERLAYERDOWN,
	IF_OPER_TESTING,
	IF_OPER_DORMANT,
	IF_OPER_UP,
};

 
enum {
	IF_LINK_MODE_DEFAULT,
	IF_LINK_MODE_DORMANT,	 
};









 

struct ifmap 
{
	unsigned long mem_start;
	unsigned long mem_end;
	unsigned short base_addr; 
	unsigned char irq;
	unsigned char dma;
	unsigned char port;
	 
};





#line 119 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\wireless_copy.h"
#line 120 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\wireless_copy.h"
#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\wpa_supp_linux_plat\\wpa_supp_linux_plat.h"




#line 11 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\wpa_supp_linux_plat\\wpa_supp_linux_plat.h"








struct sockaddr 
{
	unsigned short sa_family;  
	char sa_data[14];  
}; 




#line 121 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\wireless_copy.h"

 





 




























































































































 

 

 

 




 

 
#line 275 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\wireless_copy.h"

 
#line 283 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\wireless_copy.h"

 

 





 






 






 

 
#line 319 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\wireless_copy.h"

 


 









 



 


 



 



 


 







 











 

 

 




 



 
 
 

#line 421 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\wireless_copy.h"




 




 

#line 439 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\wireless_copy.h"








 

 

 



 

 


 


 

 



 


 


 
#line 483 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\wireless_copy.h"

 
#line 494 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\wireless_copy.h"

 




 


 


 
#line 516 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\wireless_copy.h"

 
#line 532 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\wireless_copy.h"

 






 
#line 549 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\wireless_copy.h"

 
#line 560 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\wireless_copy.h"
 


 


 


 


 



 





 
#line 596 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\wireless_copy.h"

 




 






 



 




 




 




 

 
#line 637 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\wireless_copy.h"
 





 
#line 650 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\wireless_copy.h"

 








 






 




 




 

 


 

#line 685 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\wireless_copy.h"
struct	iw_param
{
  __s32		value;		 
  __u8		fixed;		 
  __u8		disabled;	 
  __u16		flags;		 
};




 
struct	iw_point
{
  void 	*pointer;	 
  __u16		length;		 
  __u16		flags;		 
};








 
struct	iw_freq
{
	__s32		m;		 
	__s16		e;		 
	__u8		i;		 
	__u8		flags;		 
};



 
struct	iw_quality
{
	__u8		qual;		
 
	__u8		level;		 
	__u8		noise;		 
	__u8		updated;	 
};







 
struct	iw_discarded
{
	__u32		nwid;		 
	__u32		code;		 
	__u32		fragment;	 
	__u32		retries;	 
	__u32		misc;		 
};




 
struct	iw_missed
{
	__u32		beacon;		 
};



 
struct	iw_thrspy
{
	struct sockaddr		addr;		 
	struct iw_quality	qual;		 
	struct iw_quality	low;		 
	struct iw_quality	high;		 
};











 
struct	iw_scan_req
{
	__u8		scan_type;  
	__u8		essid_len;
	__u8		num_channels; 
 
	__u8		flags; 

 
	struct sockaddr	bssid; 
 

	




 
	__u8		essid[32];

	








 
	__u32		min_channel_time;  
	__u32		max_channel_time;  

	struct iw_freq	channel_list[32];
};

 
























 
struct	iw_encode_ext
{
	__u32		ext_flags;  
	__u8		tx_seq[8];  
	__u8		rx_seq[8];  
	struct sockaddr	addr; 

 
	__u16		alg;  
	__u16		key_len;
	__u8		key[1];
};

 
struct	iw_mlme
{
	__u16		cmd;  
	__u16		reason_code;
	struct sockaddr	addr;
};

 






struct	iw_pmksa
{
	__u32		cmd;  
	struct sockaddr	bssid;
	__u8		pmkid[16];
};

 
struct	iw_michaelmicfailure
{
	__u32		flags;
	struct sockaddr	src_addr;
	__u8		tsc[8];  
};

 

struct	iw_pmkid_cand
{
	__u32		flags;  
	__u32		index; 
 
	struct sockaddr	bssid;
};

 


 
struct	iw_statistics
{
	__u16		status;		
 

	struct iw_quality	qual;		
 
	struct iw_discarded	discard;	 
	struct iw_missed	miss;		 
};

 









 
union	iwreq_data
{
	 
	char		name[16];
	
 

	struct iw_point	essid;		 
	struct iw_param	nwid;		 
	struct iw_freq	freq;		

 

	struct iw_param	sens;		 
	struct iw_param	bitrate;	 
	struct iw_param	txpower;	 
	struct iw_param	rts;		 
	struct iw_param	frag;		 
	__u32		mode;		 
	struct iw_param	retry;		 

	struct iw_point	encoding;	 
	struct iw_param	power;		 
	struct iw_quality qual;		 

	struct sockaddr	ap_addr;	 
	struct sockaddr	addr;		 

	struct iw_param	param;		 
	struct iw_point	data;		 
};






 
struct	iwreq 
{
	union
	{
		char	ifrn_name[16];	 
	} ifr_ifrn;

	 
	union	iwreq_data	u;
};

 



 



 

struct	iw_range
{
	 
	__u32		throughput;	 
	




 

	 
	__u32		min_nwid;	 
	__u32		max_nwid;	 

	 
	__u16		old_num_channels;
	__u8		old_num_frequency;

	 
	__u32		event_capa[6];

	 
	__s32		sensitivity;

	 
	


 
	struct iw_quality	max_qual;	 
	







 
	struct iw_quality	avg_qual;	 

	 
	__u8		num_bitrates;	 
	__s32		bitrate[32];	 

	 
	__s32		min_rts;	 
	__s32		max_rts;	 

	 
	__s32		min_frag;	 
	__s32		max_frag;	 

	 
	__s32		min_pmp;	 
	__s32		max_pmp;	 
	__s32		min_pmt;	 
	__s32		max_pmt;	 
	__u16		pmp_flags;	 
	__u16		pmt_flags;	 
	__u16		pm_capa;	 

	 
	__u16	encoding_size[8];	 
	__u8	num_encoding_sizes;	 
	__u8	max_encoding_tokens;	 
	 
	__u8	encoding_login_index;	 

	 
	__u16		txpower_capa;	 
	__u8		num_txpower;	 
	__s32		txpower[8];	 

	 
	__u8		we_version_compiled;	 
	__u8		we_version_source;	 

	 
	__u16		retry_capa;	 
	__u16		retry_flags;	 
	__u16		r_time_flags;	 
	__s32		min_retry;	 
	__s32		max_retry;	 
	__s32		min_r_time;	 
	__s32		max_r_time;	 

	 
	__u16		num_channels;	 
	__u8		num_frequency;	 
	struct iw_freq	freq[32];	 
	
 

	__u32		enc_capa;  
};



 
 
struct	iw_priv_args
{
	__u32		cmd;		 
	__u16		set_args;	 
	__u16		get_args;	 
	char		name[16];	 
};

 




 



 
struct iw_event
{
	__u16		len;			 
	__u16		cmd;			 
	union iwreq_data	u;		 
};

 

 
#line 1115 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\wireless_copy.h"



 





#line 28 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c"
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










 
void * memcpy(void *dest, const void *src, size_t n);









 
void * os_memmove(void *dest, const void *src, size_t n);







 
void * memset(void *s, int c, size_t n);









 
int memcmp(const void *s1, const void *s2, size_t n);







 
char * os_strdup(const char *s);





 
size_t strlen(const char *s);







 
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
		memcpy(wpabuf_put(buf, len), data, len);
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
	wpabuf_put_data(dst, str, strlen(str));
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



#line 29 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c"
#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\eloop.h"




















 






 







 
typedef enum {
	EVENT_TYPE_READ = 0,
	EVENT_TYPE_WRITE,
	EVENT_TYPE_EXCEPTION
} eloop_event_type;






 
typedef void (*eloop_sock_handler)(int sock, void *eloop_ctx, void *sock_ctx);





 
typedef void (*eloop_event_handler)(void *eloop_data, void *user_ctx);





 
typedef void (*eloop_timeout_handler)(void *eloop_data, void *user_ctx);







 
typedef void (*eloop_signal_handler)(int sig, void *signal_ctx);






 
int eloop_init(void);














 
int eloop_register_read_sock(int sock, eloop_sock_handler handler,
			     void *eloop_data, void *user_data);







 
void eloop_unregister_read_sock(int sock);















 
int eloop_register_sock(int sock, eloop_event_type type,
			eloop_sock_handler handler,
			void *eloop_data, void *user_data);








 
void eloop_unregister_sock(int sock, eloop_event_type type);






















 
int eloop_register_event(void *event, size_t event_size,
			 eloop_event_handler handler,
			 void *eloop_data, void *user_data);








 
void eloop_unregister_event(void *event, size_t event_size);












 
int eloop_register_timeout(unsigned int secs, unsigned int usecs,
			   eloop_timeout_handler handler,
			   void *eloop_data, void *user_data);











 
int eloop_cancel_timeout(eloop_timeout_handler handler,
			 void *eloop_data, void *user_data);










 
int eloop_is_timeout_registered(eloop_timeout_handler handler,
				void *eloop_data, void *user_data);













 
int eloop_register_signal(int sig, eloop_signal_handler handler,
			  void *user_data);

















 
int eloop_register_signal_terminate(eloop_signal_handler handler,
				    void *user_data);

















 
int eloop_register_signal_reconfig(eloop_signal_handler handler,
				   void *user_data);







 
void eloop_run(void);






 
void eloop_terminate(void);






 
void eloop_destroy(void);









 
int eloop_terminated(void);






 
void eloop_wait_for_read_sock(int sock);

#line 30 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c"
#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\common/ieee802_11_defs.h"













 





#line 21 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\common/ieee802_11_defs.h"

 

#line 33 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\common/ieee802_11_defs.h"












 
#line 58 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\common/ieee802_11_defs.h"

 
#line 66 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\common/ieee802_11_defs.h"

 
#line 77 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\common/ieee802_11_defs.h"

 







#line 97 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\common/ieee802_11_defs.h"

 
#line 110 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\common/ieee802_11_defs.h"
 



 



 




 





 
#line 142 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\common/ieee802_11_defs.h"
 





 
#line 158 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\common/ieee802_11_defs.h"
 


 
#line 174 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\common/ieee802_11_defs.h"


 
#line 186 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\common/ieee802_11_defs.h"
 
#line 197 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\common/ieee802_11_defs.h"
 
#line 213 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\common/ieee802_11_defs.h"


 
#line 226 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\common/ieee802_11_defs.h"

 





 









struct ieee80211_hdr {
	unsigned short frame_control;
	unsigned short duration_id;
	unsigned char addr1[6];
	unsigned char addr2[6];
	unsigned char addr3[6];
	unsigned short seq_ctrl;
	
 
} ;










struct ieee80211_mgmt {
	unsigned short frame_control;
	unsigned short duration;
	unsigned char da[6];
	unsigned char sa[6];
	unsigned char bssid[6];
	unsigned short seq_ctrl;
	union {
		struct {
			unsigned short auth_alg;
			unsigned short auth_transaction;
			unsigned short status_code;
			 
			unsigned char variable[1];
		}  auth;
		struct {
			unsigned short reason_code;
		}  deauth;
		struct {
			unsigned short capab_info;
			unsigned short listen_interval;
			 
			unsigned char variable[1];
		}  assoc_req;
		struct {
			unsigned short capab_info;
			unsigned short status_code;
			unsigned short aid;
			 
			unsigned char variable[1];
		}  assoc_resp, reassoc_resp;
		struct {
			unsigned short capab_info;
			unsigned short listen_interval;
			unsigned char current_ap[6];
			 
			unsigned char variable[1];
		}  reassoc_req;
		struct {
			unsigned short reason_code;
		}  disassoc;
		struct {
			unsigned char timestamp[8];
			unsigned short beacon_int;
			unsigned short capab_info;
			
 
			unsigned char variable[1];
		}  beacon;
		struct {
			 
			unsigned char variable[1];
		}  probe_req;
		struct {
			unsigned char timestamp[8];
			unsigned short beacon_int;
			unsigned short capab_info;
			
 
			unsigned char variable[1];
		}  probe_resp;
		struct {
			unsigned char category;
			union {
				struct {
					unsigned char action_code;
					unsigned char dialog_token;
					unsigned char status_code;
					unsigned char variable[1];
				}  wmm_action;
				struct{
					unsigned char action_code;
					unsigned char element_id;
					unsigned char length;
					unsigned char switch_mode;
					unsigned char new_chan;
					unsigned char switch_count;
				}  chan_switch;
				struct {
					unsigned char action;
					unsigned char sta_addr[6];
					unsigned char target_ap_addr[6];
					unsigned char variable[1];  
				}  ft_action_req;
				struct {
					unsigned char action;
					unsigned char sta_addr[6];
					unsigned char target_ap_addr[6];
					unsigned short status_code;
					unsigned char variable[1];  
				}  ft_action_resp;
				struct {
					unsigned char action;
					unsigned char trans_id[2];
				}  sa_query_req;
				struct {
					unsigned char action;  
					unsigned char trans_id[2];
				}  sa_query_resp;
			} u;
		}  action;
	} u;
} ;


struct ieee80211_ht_capabilities {
	unsigned short ht_capabilities_info;
	unsigned char a_mpdu_params;
	unsigned char supported_mcs_set[16];
	unsigned short ht_extended_capabilities;
	unsigned int tx_bf_capability_info;
	unsigned char asel_capabilities;
} ;


struct ieee80211_ht_operation {
	unsigned char control_chan;
	unsigned char ht_param;
	unsigned short operation_mode;
	unsigned short stbc_param;
	unsigned char basic_set[16];
} ;










#line 415 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\common/ieee802_11_defs.h"









#line 442 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\common/ieee802_11_defs.h"


#line 451 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\common/ieee802_11_defs.h"

#line 459 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\common/ieee802_11_defs.h"







#line 472 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\common/ieee802_11_defs.h"

#line 479 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\common/ieee802_11_defs.h"



















 

 

 


 





 
struct wmm_information_element {
	 
	 
	unsigned char oui[3];  
	unsigned char oui_type;  
	unsigned char oui_subtype;  
	unsigned char version;  
	unsigned char qos_info;  

} ;












struct wmm_ac_parameter {
	unsigned char aci_aifsn;  
	unsigned char cw;  
	unsigned short txop_limit;
}  ;




 
struct wmm_parameter_element {
	 
	 
	unsigned char oui[3];  
	unsigned char oui_type;  
	unsigned char oui_subtype;  
	unsigned char version;  
	unsigned char qos_info;  
	unsigned char reserved;  
	struct wmm_ac_parameter ac[4];  

} ;

 
struct wmm_tspec_element {
	unsigned char eid;  
	unsigned char length;  
	unsigned char oui[3];  
	unsigned char oui_type;  
	unsigned char oui_subtype;  
	unsigned char version;  
	 
	unsigned char ts_info[3];
	unsigned short nominal_msdu_size;
	unsigned short maximum_msdu_size;
	unsigned int minimum_service_interval;
	unsigned int maximum_service_interval;
	unsigned int inactivity_interval;
	unsigned int suspension_interval;
	unsigned int service_start_time;
	unsigned int minimum_data_rate;
	unsigned int mean_data_rate;
	unsigned int peak_data_rate;
	unsigned int maximum_burst_size;
	unsigned int delay_bound;
	unsigned int minimum_phy_rate;
	unsigned short surplus_bandwidth_allowance;
	unsigned short medium_time;
} ;


 
enum {
	WMM_AC_BE = 0  ,
	WMM_AC_BK = 1  ,
	WMM_AC_VI = 2  ,
	WMM_AC_VO = 3  
};






 



 




 



#line 31 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c"
#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\common/xwpa_common.h"












 




#line 19 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\common/xwpa_common.h"



 
#line 30 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\common/xwpa_common.h"










#line 51 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\common/xwpa_common.h"


#line 61 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\common/xwpa_common.h"

#line 73 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\common/xwpa_common.h"



 
#line 92 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\common/xwpa_common.h"





















 


 
 





 






 





 
#line 148 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\common/xwpa_common.h"

#pragma pack(push, 1)
struct wpa_eapol_key {
	unsigned char type;
	 
	unsigned char key_info[2];  
	unsigned char key_length[2];  
	unsigned char replay_counter[8];
	unsigned char key_nonce[32];
	unsigned char key_iv[16];
	unsigned char key_rsc[8];
	unsigned char key_id[8];  
	unsigned char key_mic[16];
	unsigned char key_data_length[2];  
	 
} ;




 

struct wpa_ptk {
	unsigned char kck[16];  
	unsigned char kek[16];  
	unsigned char tk1[16];  
	union {
		unsigned char tk2[16];  
		struct {
			unsigned char tx_mic_key[8];
			unsigned char rx_mic_key[8];
		} auth;
	} u;
} ;















 

struct wpa_ie_hdr {
	unsigned char elem_id;
	unsigned char len;
	unsigned char oui[4];  
	unsigned char version[2];  
} ;








 















 

struct rsn_ie_hdr {
	unsigned char elem_id;  
	unsigned char len;
	unsigned char version[2];  
} ;



enum {
	STK_MUI_4WAY_STA_AP = 1,
	STK_MUI_4WAY_STAT_STA = 2,
	STK_MUI_GTK = 3,
	STK_MUI_SMK = 4
};

enum {
	STK_ERR_STA_NR = 1,
	STK_ERR_STA_NRSN = 2,
	STK_ERR_CPHR_NS = 3,
	STK_ERR_NO_STSL = 4
};



struct rsn_error_kde {
	unsigned short mui;
	unsigned short error_type;
} ;


struct wpa_igtk_kde {
	unsigned char keyid[2];
	unsigned char pn[6];
	unsigned char igtk[16];
} ;



struct rsn_mdie {
	unsigned char mobility_domain[2];
	unsigned char ft_capab;
} ;




struct rsn_ftie {
	unsigned char mic_control[2];
	unsigned char mic[16];
	unsigned char anonce[32];
	unsigned char snonce[32];
	 
} ;






struct rsn_rdie {
	unsigned char id;
	unsigned char descr_count;
	unsigned short status_code;
} ;






#pragma pack(pop)

int wpa_eapol_key_mic(const unsigned char *key, int ver, const unsigned char *buf, size_t len,
		      unsigned char *mic);
void wpa_pmk_to_ptk(const unsigned char *pmk, size_t pmk_len, const char *label,
		    const unsigned char *addr1, const unsigned char *addr2,
		    const unsigned char *nonce1, const unsigned char *nonce2,
		    unsigned char *ptk, size_t ptk_len, int use_sha256);


int wpa_ft_mic(const unsigned char *kck, const unsigned char *sta_addr, const unsigned char *ap_addr,
	       unsigned char transaction_seqnum, const unsigned char *mdie, size_t mdie_len,
	       const unsigned char *ftie, size_t ftie_len,
	       const unsigned char *rsnie, size_t rsnie_len,
	       const unsigned char *ric, size_t ric_len, unsigned char *mic);
void wpa_derive_pmk_r0(const unsigned char *xxkey, size_t xxkey_len,
		       const unsigned char *ssid, size_t ssid_len,
		       const unsigned char *mdid, const unsigned char *r0kh_id, size_t r0kh_id_len,
		       const unsigned char *s0kh_id, unsigned char *pmk_r0, unsigned char *pmk_r0_name);
void wpa_derive_pmk_r1_name(const unsigned char *pmk_r0_name, const unsigned char *r1kh_id,
			    const unsigned char *s1kh_id, unsigned char *pmk_r1_name);
void wpa_derive_pmk_r1(const unsigned char *pmk_r0, const unsigned char *pmk_r0_name,
		       const unsigned char *r1kh_id, const unsigned char *s1kh_id,
		       unsigned char *pmk_r1, unsigned char *pmk_r1_name);
void wpa_pmk_r1_to_ptk(const unsigned char *pmk_r1, const unsigned char *snonce, const unsigned char *anonce,
		       const unsigned char *sta_addr, const unsigned char *bssid,
		       const unsigned char *pmk_r1_name,
		       unsigned char *ptk, size_t ptk_len, unsigned char *ptk_name);


struct wpa_ie_data {
	int proto;
	int pairwise_cipher;
	int group_cipher;
	int key_mgmt;
	int capabilities;
	size_t num_pmkid;
	const unsigned char *pmkid;
	int mgmt_group_cipher;
};


int wpa_parse_wpa_ie_rsn(const unsigned char *rsn_ie, size_t rsn_ie_len,
			 struct wpa_ie_data *data);

void rsn_pmkid(const unsigned char *pmk, size_t pmk_len, const unsigned char *aa, const unsigned char *spa,
	       unsigned char *pmkid, int use_sha256);

const char * wpa_cipher_txt(int cipher);
const char * wpa_key_mgmt_txt(int key_mgmt, int proto);
int wpa_compare_rsn_ie(int ft_initial_assoc,
		       const unsigned char *ie1, size_t ie1len,
		       const unsigned char *ie2, size_t ie2len);
int wpa_insert_pmkid(unsigned char *ies, size_t ies_len, const unsigned char *pmkid);

#line 32 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c"
#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\priv_netlink.h"












 







 

#line 29 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\priv_netlink.h"

#line 44 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\priv_netlink.h"



#line 53 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\priv_netlink.h"

#line 67 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\priv_netlink.h"

#line 78 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\priv_netlink.h"

typedef unsigned short int sa_family_t;
struct sockaddr_nl
{
	sa_family_t nl_family;
	unsigned short nl_pad;
	unsigned int nl_pid;
	unsigned int nl_groups;
};

struct nlmsghdr
{
	unsigned int nlmsg_len;
	unsigned short nlmsg_type;
	unsigned short nlmsg_flags;
	unsigned int nlmsg_seq;
	unsigned int nlmsg_pid;
};

struct ifinfomsg
{
	unsigned char ifi_family;
	unsigned char __ifi_pad;
	unsigned short ifi_type;
	int ifi_index;
	unsigned ifi_flags;
	unsigned ifi_change;
};

struct rtattr
{
	unsigned short rta_len;
	unsigned short rta_type;
};

#line 33 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c"
#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\netlink.h"












 




struct netlink_data;

struct netlink_config {
	void *ctx;
	void (*newlink_cb)(void *ctx, struct ifinfomsg *ifi, unsigned char *buf,
			   size_t len);
	void (*dellink_cb)(void *ctx, struct ifinfomsg *ifi, unsigned char *buf,
			   size_t len);
};

struct netlink_data * netlink_init(struct netlink_config *cfg);
void netlink_deinit(struct netlink_data *netlink);
int netlink_send_oper_ifla(struct netlink_data *netlink, int ifindex,
			   int linkmode, int operstate);

#line 34 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c"
#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\linux_ioctl.h"












 




int linux_set_iface_flags(int sock, const char *ifname, int dev_up);
int linux_get_ifhwaddr(int sock, const char *ifname, unsigned char *addr);
int linux_set_ifhwaddr(int sock, const char *ifname, const unsigned char *addr);
int linux_br_add(int sock, const char *brname);
int linux_br_del(int sock, const char *brname);
int linux_br_add_if(int sock, const char *brname, const char *ifname);
int linux_br_del_if(int sock, const char *brname, const char *ifname);
int linux_br_get(char *brname, const char *ifname);

#line 35 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c"
#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver.h"




















 






#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\common/defs.h"












 





#line 25 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\common/defs.h"





#line 38 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\common/defs.h"

#line 49 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\common/defs.h"



static  int wpa_key_mgmt_wpa_ieee8021x(int akm)
{
	return akm == (1 << (0)) ||
		akm == (1 << (5)) ||
		akm == (1 << (7));
}

static  int wpa_key_mgmt_wpa_psk(int akm)
{
	return akm == (1 << (1)) ||
		akm == (1 << (6)) ||
		akm == (1 << (8));
}

static  int wpa_key_mgmt_ft(int akm)
{
	return akm == (1 << (6)) ||
		akm == (1 << (5));
}

static  int wpa_key_mgmt_sha256(int akm)
{
	return akm == (1 << (8)) ||
		akm == (1 << (7));
}











enum wpa_alg {
	WPA_ALG_NONE,
	WPA_ALG_WEP,
	WPA_ALG_TKIP,
	WPA_ALG_CCMP,
	WPA_ALG_IGTK,
	WPA_ALG_PMK,
	WPA_BOTH
};



 
enum wpa_cipher {
	CIPHER_NONE,
	CIPHER_WEP40,
	CIPHER_TKIP,
	CIPHER_CCMP,
	CIPHER_WEP104
};



 
enum wpa_key_mgmt {
	KEY_MGMT_802_1X,
	KEY_MGMT_PSK,
	KEY_MGMT_NONE,
	KEY_MGMT_802_1X_NO_WPA,
	KEY_MGMT_WPA_NONE,
	KEY_MGMT_FT_802_1X,
	KEY_MGMT_FT_PSK,
	KEY_MGMT_802_1X_SHA256,
	KEY_MGMT_PSK_SHA256,
	KEY_MGMT_WPS
};










 
enum wpa_states {
	





 
	WPA_DISCONNECTED,

	






 
	WPA_INACTIVE,

	




 
	WPA_SCANNING,

	






 
	WPA_AUTHENTICATING,

	







 
	WPA_ASSOCIATING,

	






 
	WPA_ASSOCIATED,

	






 
	WPA_4WAY_HANDSHAKE,

	






 
	WPA_GROUP_HANDSHAKE,

	














 
	WPA_COMPLETED,
	WPA_NO_IMPL
};












 
enum mfp_options {
	NO_MGMT_FRAME_PROTECTION = 0,
	MGMT_FRAME_PROTECTION_OPTIONAL = 1,
	MGMT_FRAME_PROTECTION_REQUIRED = 2
};



 
enum hostapd_hw_mode {
	HOSTAPD_MODE_IEEE80211B,
	HOSTAPD_MODE_IEEE80211G,
	HOSTAPD_MODE_IEEE80211A,
	NUM_HOSTAPD_MODES
};

#line 29 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver.h"








 
struct hostapd_channel_data {
	

 
	short chan;

	

 
	short freq;

	

 
	int flag;

	

 
	unsigned char max_tx_power;
};



 
struct hostapd_hw_modes {
	

 
	enum hostapd_hw_mode mode;

	

 
	int num_channels;

	

 
	struct hostapd_channel_data *channels;

	

 
	int num_rates;

	

 
	int *rates;

	

 
	unsigned short ht_capab;

	

 
	unsigned char mcs_set[16];

	

 
	unsigned char a_mpdu_params;
};










#line 120 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver.h"

























 
struct wpa_scan_res {
	unsigned int flags;
	unsigned char bssid[6];
	int freq;
	unsigned short beacon_int;
	unsigned short caps;
	int qual;
	int noise;
	int level;
	unsigned long tsf;
	unsigned int age;
	size_t ie_len;
	size_t beacon_ie_len;
	





 
};





 
struct wpa_scan_results {
	struct wpa_scan_res **res;
	size_t num;
};










 
struct wpa_interface_info {
	struct wpa_interface_info *next;
	char *ifname;
	char *desc;
	const char *drv_name;
};






 
struct wpa_driver_scan_params {
	

 
	struct wpa_driver_scan_ssid {
		



 
		const unsigned char *ssid;
		

 
		size_t ssid_len;
	} ssids[4];

	


 
	size_t num_ssids;

	

 
	const unsigned char *extra_ies;

	

 
	size_t extra_ies_len;

	



 
	int *freqs;

	












 
	struct wpa_driver_scan_filter {
		unsigned char ssid[32];
		size_t ssid_len;
	} *filter_ssids;

	

 
	size_t num_filter_ssids;
};




 
struct wpa_driver_auth_params {
	int freq;
	const unsigned char *bssid;
	const unsigned char *ssid;
	size_t ssid_len;
	int auth_alg;
	const unsigned char *ie;
	size_t ie_len;
	const unsigned char *wep_key[4];
	size_t wep_key_len[4];
	int wep_tx_keyidx;
	int local_state_change;
};




 
struct wpa_driver_associate_params {
	


 
	const unsigned char *bssid;	   

	

 
	const unsigned char *ssid;		   

	

 
	size_t ssid_len;	   

	



 					   
	int freq;

	
















 
	const unsigned char *wpa_ie;		

	

 
	size_t wpa_ie_len;

	



 
	enum wpa_cipher pairwise_suite;

	



 
	enum wpa_cipher group_suite;

	



 
	enum wpa_key_mgmt key_mgmt_suite;

	


 
	int auth_alg;

	

 
	int mode;

	

 
	const unsigned char *wep_key[4];

	

 
	size_t wep_key_len[4];

	

 
	int wep_tx_keyidx;

	

 
	enum mfp_options mgmt_frame_protection;

	



















 
	const unsigned char *ft_ies;

	

 
	size_t ft_ies_len;

	





 
	const unsigned char *ft_md;

	







 
	const char *passphrase;

	






 
	const unsigned char *psk;

	





 
	int drop_unencrypted;

	




 
	const unsigned char *prev_bssid;
};



 
struct wpa_driver_capa {
#line 476 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver.h"
	unsigned int key_mgmt;





	unsigned int enc;




	unsigned int auth;

 

 



 



 

 

 

	unsigned int flags;

	int max_scan_ssids;

	

 
	unsigned int max_remain_on_chan;
};


struct hostapd_data;

struct hostap_sta_driver_data {
	unsigned long rx_packets, tx_packets, rx_bytes, tx_bytes;
	unsigned long current_tx_rate;
	unsigned long inactive_msec;
	unsigned long flags;
	unsigned long num_ps_buf_frames;
	unsigned long tx_retry_failed;
	unsigned long tx_retry_count;
	int last_rssi;
	int last_ack_rssi;
};

struct hostapd_sta_add_params {
	const unsigned char *addr;
	unsigned short aid;
	unsigned short capability;
	const unsigned char *supp_rates;
	size_t supp_rates_len;
	unsigned short listen_interval;
	const struct ieee80211_ht_capabilities *ht_capabilities;
};

struct hostapd_freq_params {
	int mode;
	int freq;
	int channel;
	int ht_enabled;
	int sec_channel_offset; 

 
};

enum wpa_driver_if_type {
	

 
	WPA_IF_STATION,

	




 
	WPA_IF_AP_VLAN,

	



 
	WPA_IF_AP_BSS,
};

struct wpa_init_params {
	const unsigned char *bssid;
	const char *ifname;
	const unsigned char *ssid;
	size_t ssid_len;
	const char *test_socket;
	int use_pae_group_addr;
	char **bridge;
	size_t num_bridge;

	unsigned char *own_addr;  
};


struct wpa_bss_params {
	 
	const char *ifname;
	 
	int enabled;

	int wpa;
	int ieee802_1x;
	int wpa_group;
	int wpa_pairwise;
	int wpa_key_mgmt;
	int rsn_preauth;
};












 
struct wpa_driver_ops {
	 
	const char *name;													  
	 
	const char *desc;													  

	









 																	   
	int (*get_bssid)(void *priv, unsigned char *bssid);

	













 
	int (*get_ssid)(void *priv, unsigned char *ssid);									

	










































 
	int (*set_key)(const char *ifname, void *priv, enum wpa_alg alg,		 
		       const unsigned char *addr, int key_idx, int set_tx,
		       const unsigned char *seq, size_t seq_len,
		       const unsigned char *key, size_t key_len);

	





















 
	void * (*init)(void *ctx, const char *ifname);							 

	





 
	void (*deinit)(void *priv);												

	








 
	int (*set_param)(void *priv, const char *param);						

	








 
	int (*set_countermeasures)(void *priv, int enabled);				  

	







 
	int (*deauthenticate)(void *priv, const unsigned char *addr, int reason_code);	  

	







 
	int (*disassociate)(void *priv, const unsigned char *addr, int reason_code);	   

	





 
	int (*associate)(void *priv,
			 struct wpa_driver_associate_params *params);				   

	















 
	int (*add_pmkid)(void *priv, const unsigned char *bssid, const unsigned char *pmkid);		  

	
















 
	int (*remove_pmkid)(void *priv, const unsigned char *bssid, const unsigned char *pmkid);	   

	














 
	int (*flush_pmkid)(void *priv);							   

	






 
	int (*get_capa)(void *priv, struct wpa_driver_capa *capa);	  

	










 
	void (*poll)(void *priv);									 

	









 
	const char * (*get_ifname)(void *priv);					  

	








 
	const unsigned char * (*get_mac_addr)(void *priv);					  

	
















 
	int (*send_eapol)(void *priv, const unsigned char *dest, unsigned short proto,
			  const unsigned char *data, size_t data_len);						   

	










 
	int (*set_operstate)(void *priv, int state);					  

	














 
	int (*mlme_setprotection)(void *priv, const unsigned char *addr, int protect_type,
				  int key_type);											   

	









 
	struct hostapd_hw_modes * (*get_hw_feature_data)(void *priv,
							 unsigned short *num_modes,
							 unsigned short *flags);								

	









 
	int (*set_channel)(void *priv, enum hostapd_hw_mode phymode, int chan,
			   int freq);										   

	








 
	int (*set_ssid)(void *priv, const unsigned char *ssid, size_t ssid_len);	   

	







 
	int (*set_bssid)(void *priv, const unsigned char *bssid);				 

	








 
	int (*send_mlme)(void *priv, const unsigned char *data, size_t data_len);		

	













 
	int (*mlme_add_sta)(void *priv, const unsigned char *addr, const unsigned char *supp_rates,
			    size_t supp_rates_len);							   

	







 
	int (*mlme_remove_sta)(void *priv, const unsigned char *addr);				  

	













 
	int (*update_ft_ies)(void *priv, const unsigned char *md, const unsigned char *ies,
			     size_t ies_len);									  

	











 
	int (*send_ft_action)(void *priv, unsigned char action, const unsigned char *target_ap,
			      const unsigned char *ies, size_t ies_len);					   

	





 
	 struct wpa_scan_results * (*get_scan_results2)(void *priv);	   

	







 
	int (*set_country)(void *priv, const char *alpha2);				  

	









 
	void * (*global_init)(void);										 

	





 
	void (*global_deinit)(void *priv);									   

	









 
	void * (*init2)(void *ctx, const char *ifname, void *global_priv);		 

	





 
	struct wpa_interface_info * (*get_interfaces)(void *global_priv);		 

	









 
	int (*scan2)(void *priv, struct wpa_driver_scan_params *params);		

	










 
	int (*authenticate)(void *priv,
			    struct wpa_driver_auth_params *params);					 

	














 
	int (*set_beacon)(void *priv, const unsigned char *head, size_t head_len,
			  const unsigned char *tail, size_t tail_len, int dtim_period,
			  int beacon_int);											 

	







 
	void * (*hapd_init)(struct hostapd_data *hapd,
			    struct wpa_init_params *params);						

	


 
	void (*hapd_deinit)(void *priv);								   

	










 
	int (*set_ieee8021x)(void *priv, struct wpa_bss_params *params);	   

	








 
	int (*set_privacy)(void *priv, int enabled);						   

	












 
	int (*get_seqnum)(const char *ifname, void *priv, const unsigned char *addr,
			  int idx, unsigned char *seq);									   

	







 
	int (*flush)(void *priv);										  

	










 
	int (*set_generic_elem)(void *priv, const unsigned char *elem, size_t elem_len);	

	





 
	int (*read_sta_data)(void *priv, struct hostap_sta_driver_data *data,
			     const unsigned char *addr);								 

	









 
	int (*hapd_send_eapol)(void *priv, const unsigned char *addr, const unsigned char *data,
			       size_t data_len, int encrypt,
			       const unsigned char *own_addr);								   

	









 
	int (*sta_deauth)(void *priv, const unsigned char *own_addr, const unsigned char *addr,
			  int reason);											   

	









 
	int (*sta_disassoc)(void *priv, const unsigned char *own_addr, const unsigned char *addr,
			    int reason);										   

	




 
	int (*sta_remove)(void *priv, const unsigned char *addr);					

	









 
	int (*hapd_get_ssid)(void *priv, unsigned char *buf, int len);				

	





 
	int (*hapd_set_ssid)(void *priv, const unsigned char *buf, int len);		

	







 
	int (*hapd_set_countermeasures)(void *priv, int enabled);	   

	








 
	int (*sta_add)(void *priv, struct hostapd_sta_add_params *params);	  

	




 
	int (*get_inact_sec)(void *priv, const unsigned char *addr);				 

	




 
	int (*sta_clear_stats)(void *priv, const unsigned char *addr);			   

	




 
	int (*set_freq)(void *priv, struct hostapd_freq_params *freq);	

	




 
	int (*set_rts)(void *priv, int rts);							

	




 
	int (*set_frag)(void *priv, int frag);						   

	







 
	int (*sta_set_flags)(void *priv, const unsigned char *addr,
			     int total_flags, int flags_or, int flags_and);		 

	






 
	int (*set_rate_sets)(void *priv, int *supp_rates, int *basic_rates,
			     int mode);													 

	




 
	int (*set_cts_protect)(void *priv, int value);						   

	




 
	int (*set_preamble)(void *priv, int value);							

	




 
	int (*set_short_slot_time)(void *priv, int value);					

	







 
	int (*set_tx_queue_params)(void *priv, int queue, int aifs, int cw_min,
				   int cw_max, int burst_time);									

	







 
	int (*valid_bss_mask)(void *priv, const unsigned char *addr, const unsigned char *mask);			 

	















 
	int (*if_add)(void *priv, enum wpa_driver_if_type type,
		      const char *ifname, const unsigned char *addr, void *bss_ctx,
		      void **drv_priv, char *force_ifname, unsigned char *if_addr);			  

	





 
	int (*if_remove)(void *priv, enum wpa_driver_if_type type,
			 const char *ifname);										   

	












 
	int (*set_sta_vlan)(void *priv, const unsigned char *addr, const char *ifname,
			    int vlan_id);												   

	








 
	int (*commit)(void *priv);												   

	








 
	int (*send_ether)(void *priv, const unsigned char *dst, const unsigned char *src, unsigned short proto,
			  const unsigned char *data, size_t data_len);									  

	






 
	int (*set_radius_acl_auth)(void *priv, const unsigned char *mac, int accepted, 
				   unsigned int session_timeout);											 

	




 
	int (*set_radius_acl_expire)(void *priv, const unsigned char *mac);						 

	







 
	int (*set_ht_params)(void *priv,
			     const unsigned char *ht_capab, size_t ht_capab_len,
			     const unsigned char *ht_oper, size_t ht_oper_len);							 

	











 
	int (*set_ap_wps_ie)(void *priv, const struct wpabuf *beacon,
			     const struct wpabuf *proberesp);								   

	




 
	int (*set_supp_port)(void *priv, int authorized);							  

	






 
	int (*set_wds_sta)(void *priv, const unsigned char *addr, int aid, int val);			 

	
















 
	int (*send_action)(void *priv, unsigned int freq,
			   const unsigned char *dst, const unsigned char *src, const unsigned char *bssid,
			   const unsigned char *data, size_t data_len);									

	




















 
	int (*remain_on_channel)(void *priv, unsigned int freq,
				 unsigned int duration);										   

	









 
	int (*cancel_remain_on_channel)(void *priv);								   

	












 
	int (*probe_req_report)(void *priv, int report);							   

	









 
	int (*disable_11b_rates)(void *priv, int disabled);							  

	







 
	int (*deinit_ap)(void *priv);												   

	


 
	void (*suspend)(void *priv);													

	


 
	void (*resume)(void *priv);														

	












 
	int (*signal_monitor)(void *priv, int threshold, int hysteresis);				

	









 
	int (*send_frame)(void *priv, const unsigned char *data, size_t data_len,
			  int encrypt);														   
};




 
enum wpa_event_type {
	










 
	EVENT_ASSOC,

	








 
	EVENT_DISASSOC,

	







 
	EVENT_MICHAEL_MIC_FAILURE,

	












 
	EVENT_SCAN_RESULTS,

	









 
	EVENT_ASSOCINFO,

	







 
	EVENT_INTERFACE_STATUS,

	






















 
	EVENT_PMKID_CANDIDATE,

	







 
	EVENT_STKSTART,

	





 
	EVENT_FT_RESPONSE,

	






 
	EVENT_IBSS_RSN_START,

	







 
	EVENT_AUTH,

	






 
	EVENT_DEAUTH,

	





 
	EVENT_ASSOC_REJECT,

	

 
	EVENT_AUTH_TIMED_OUT,

	

 
	EVENT_ASSOC_TIMED_OUT,

	

 
	EVENT_FT_RRB_RX,

	

 
	EVENT_WPS_BUTTON_PUSHED,

	

 
	EVENT_TX_STATUS,

	

 
	EVENT_RX_FROM_UNKNOWN,

	

 
	EVENT_RX_MGMT,

	





 
	EVENT_RX_ACTION,

	





 
	EVENT_REMAIN_ON_CHANNEL,

	






 
	EVENT_CANCEL_REMAIN_ON_CHANNEL,

	



 
	EVENT_MLME_RX,

	









 
	EVENT_RX_PROBE_REQ,

	







 
	EVENT_NEW_STA,

	






 
	EVENT_EAPOL_RX,

	





 
	EVENT_SIGNAL_CHANGE
};




 
union wpa_event_data {
	






 
	struct assoc_info {
		









 
		const unsigned char *req_ies;

		

 
		size_t req_ies_len;

		









 
		const unsigned char *resp_ies;

		

 
		size_t resp_ies_len;

		














 
		const unsigned char *beacon_ies;

		
 
		size_t beacon_ies_len;

		

 
		unsigned int freq;

		

 
		const unsigned char *addr;
	} assoc_info;

	

 
	struct disassoc_info {
		

 
		const unsigned char *addr;

		


 
		unsigned short reason_code;
	} disassoc_info;

	

 
	struct deauth_info {
		

 
		const unsigned char *addr;

		


 
		unsigned short reason_code;
	} deauth_info;

	

 
	struct michael_mic_failure {
		int unicast;
		const unsigned char *src;
	} michael_mic_failure;

	

 
	struct interface_status {
		char ifname[100];
		enum {
			EVENT_INTERFACE_ADDED, EVENT_INTERFACE_REMOVED
		} ievent;
	} interface_status;

	

 
	struct pmkid_candidate {
		 
		unsigned char bssid[6];
		 
		int index;
		 
		int preauth;
	} pmkid_candidate;

	

 
	struct stkstart {
		unsigned char peer[6];
	} stkstart;

	







 
	struct ft_ies {
		const unsigned char *ies;
		size_t ies_len;
		int ft_action;
		unsigned char target_ap[6];
		 
		const unsigned char *ric_ies;
		 
		size_t ric_ies_len;
	} ft_ies;

	

 
	struct ibss_rsn_start {
		unsigned char peer[6];
	} ibss_rsn_start;

	

 
	struct auth_info {
		unsigned char peer[6];
		unsigned short auth_type;
		unsigned short status_code;
		const unsigned char *ies;
		size_t ies_len;
	} auth;

	

 
	struct assoc_reject {
		









 
		unsigned char *resp_ies;

		

 
		size_t resp_ies_len;

		

 
		unsigned short status_code;
	} assoc_reject;

	struct timeout_event {
		unsigned char addr[6];
	} timeout_event;

	

 
	struct ft_rrb_rx {
		const unsigned char *src;
		const unsigned char *data;
		size_t data_len;
	} ft_rrb_rx;

	

 
	struct tx_status {
		unsigned short type;
		unsigned short stype;
		const unsigned char *dst;
		const unsigned char *data;
		size_t data_len;
		int ack;
	} tx_status;

	

 
	struct rx_from_unknown {
		const unsigned char *frame;
		size_t len;
	} rx_from_unknown;

	

 
	struct rx_mgmt {
		const unsigned char *frame;
		size_t frame_len;
		unsigned int datarate;
		unsigned int ssi_signal;
	} rx_mgmt;

	

 
	struct rx_action {
		

 
		const unsigned char *da;

		

 
		const unsigned char *sa;

		

 
		const unsigned char *bssid;

		

 
		unsigned char category;

		

 
		const unsigned char *data;

		

 
		size_t len;

		

 
		int freq;
	} rx_action;

	



 
	struct remain_on_channel {
		

 
		unsigned int freq;

		

 
		unsigned int duration;
	} remain_on_channel;

	







 
	struct scan_info {
		int aborted;
		const int *freqs;
		size_t num_freqs;
		struct wpa_driver_scan_ssid ssids[4];
		size_t num_ssids;
	} scan_info;

	

 
	struct mlme_rx {
		const unsigned char *buf;
		size_t len;
		int freq;
		int channel;
		int ssi;
	} mlme_rx;

	

 
	struct rx_probe_req {
		

 
		const unsigned char *sa;

		

 
		const unsigned char *ie;

		

 
		size_t ie_len;
	} rx_probe_req;

	

 
	struct new_sta {
		const unsigned char *addr;
	} new_sta;

	

 
	struct eapol_rx {
		const unsigned char *src;
		const unsigned char *data;
		size_t data_len;
	} eapol_rx;

	

 
	struct signal_change {
		int above_threshold;
	} signal_change;
};










 
void wpa_supplicant_event(void *ctx, enum wpa_event_type event,
			  union wpa_event_data *data);





 

static  void drv_event_assoc(void *ctx, const unsigned char *addr, const unsigned char *ie,
				   size_t ielen)
{
	union wpa_event_data event;
	memset(&event, 0, sizeof(event));
	event.assoc_info.req_ies = ie;
	event.assoc_info.req_ies_len = ielen;
	event.assoc_info.addr = addr;
	wpa_supplicant_event(ctx, EVENT_ASSOC, &event);
}

static  void drv_event_disassoc(void *ctx, const unsigned char *addr)
{
	union wpa_event_data event;
	memset(&event, 0, sizeof(event));
	event.disassoc_info.addr = addr;
	wpa_supplicant_event(ctx, EVENT_DISASSOC, &event);
}

static  void drv_event_eapol_rx(void *ctx, const unsigned char *src, const unsigned char *data,
				      size_t data_len)
{
	union wpa_event_data event;
	memset(&event, 0, sizeof(event));
	event.eapol_rx.src = src;
	event.eapol_rx.data = data;
	event.eapol_rx.data_len = data_len;
	wpa_supplicant_event(ctx, EVENT_EAPOL_RX, &event);
}

#line 36 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c"
#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.h"












 




#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\wpa_supp_linux_plat\\net/if.h"



#line 10 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\wpa_supp_linux_plat\\net/if.h"



#line 19 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.h"

struct wpa_driver_wext_data {
	void *ctx;
	struct netlink_data *netlink;
	int ioctl_sock;
	int mlme_sock;
	char ifname[32 + 1];
	int ifindex;
	int ifindex2;
	int if_removed;
	unsigned char *assoc_req_ies;
	size_t assoc_req_ies_len;
	unsigned char *assoc_resp_ies;
	size_t assoc_resp_ies_len;
	struct wpa_driver_capa capa;
	int has_capability;
	int we_version_compiled;

	 
	int use_crypt;
	int auth_alg_fallback;

	int operstate;

	char mlmedev[32 + 1];

	int scan_complete_events;

	int cfg80211;  
};

int wpa_driver_wext_get_bssid(void *priv, unsigned char *bssid);
int wpa_driver_wext_set_bssid(void *priv, const unsigned char *bssid);
int wpa_driver_wext_get_ssid(void *priv, unsigned char *ssid);
int wpa_driver_wext_set_ssid(void *priv, const unsigned char *ssid, size_t ssid_len);
int wpa_driver_wext_set_freq(void *priv, int freq);
int wpa_driver_wext_set_mode(void *priv, int mode);
int wpa_driver_wext_set_key(const char *ifname, void *priv, enum wpa_alg alg,
			    const unsigned char *addr, int key_idx,
			    int set_tx, const unsigned char *seq, size_t seq_len,
			    const unsigned char *key, size_t key_len);
int wpa_driver_wext_scan(void *priv, struct wpa_driver_scan_params *params);
struct wpa_scan_results * wpa_driver_wext_get_scan_results(void *priv);

void wpa_driver_wext_scan_timeout(void *eloop_ctx, void *timeout_ctx);

int wpa_driver_wext_alternative_ifindex(struct wpa_driver_wext_data *drv,
					const char *ifname);

void * wpa_driver_wext_init(void *ctx, const char *ifname);
void wpa_driver_wext_deinit(void *priv);

int wpa_driver_wext_set_operstate(void *priv, int state);
int wpa_driver_wext_get_version(struct wpa_driver_wext_data *drv);

int wpa_driver_wext_associate(void *priv,
			      struct wpa_driver_associate_params *params);
int wpa_driver_wext_get_capa(void *priv, struct wpa_driver_capa *capa);
int wpa_driver_wext_set_auth_param(struct wpa_driver_wext_data *drv,
				   int idx, unsigned int value);
int wpa_driver_wext_cipher2wext(int cipher);
int wpa_driver_wext_keymgmt2wext(int keymgmt);

#line 37 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c"


#line 40 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c"


static int wpa_driver_wext_flush_pmkid(void *priv);
static int wpa_driver_wext_get_range(void *priv);
static int wpa_driver_wext_finish_drv_init(struct wpa_driver_wext_data *drv);
static void wpa_driver_wext_disconnect(struct wpa_driver_wext_data *drv);
static int wpa_driver_wext_set_auth_alg(void *priv, int auth_alg);


int wpa_driver_wext_set_auth_param(struct wpa_driver_wext_data *drv,
				   int idx, unsigned int value)
{
	return 0;
#line 73 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c"
}







 
int wpa_driver_wext_get_bssid(void *priv, unsigned char *bssid)
{
	printf("RUN_TEST >>> LINE:%d ,,, FUNCTION:%s ,,, FILE:%s \r\n",84,__FUNCTION__,"..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c");;
	return 0;
#line 102 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c"
}







 
int wpa_driver_wext_set_bssid(void *priv, const unsigned char *bssid)
{
	printf("RUN_TEST >>> LINE:%d ,,, FUNCTION:%s ,,, FILE:%s \r\n",113,__FUNCTION__,"..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c");;
	return 0;
#line 135 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c"
}







 

int wpa_driver_wext_get_ssid(void *priv, unsigned char *ssid)
{
	printf("RUN_TEST >>> LINE:%d ,,, FUNCTION:%s ,,, FILE:%s \r\n",147,__FUNCTION__,"..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c");;
	return 0;

#line 178 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c"
}








 
int wpa_driver_wext_set_ssid(void *priv, const unsigned char *ssid, size_t ssid_len)
{
	printf("RUN_TEST >>> LINE:%d ,,, FUNCTION:%s ,,, FILE:%s \r\n",190,__FUNCTION__,"..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c");;
	return 0;
#line 229 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c"
}







 
int wpa_driver_wext_set_freq(void *priv, int freq)
{
	return 0;
#line 258 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c"
}


static void
wpa_driver_wext_event_wireless_custom(void *ctx, char *custom)
{
	union wpa_event_data data;

	wpa_printf(0, "WEXT: Custom wireless event: '%s'",
		   custom);

	memset(&data, 0, sizeof(data));
	 
	if (os_strncmp(custom, "MLME-MICHAELMICFAILURE.indication", 33) == 0) {
		data.michael_mic_failure.unicast =
			os_strstr(custom, " unicast ") != 0;
		 
		wpa_supplicant_event(ctx, EVENT_MICHAEL_MIC_FAILURE, &data);
	} else if (os_strncmp(custom, "ASSOCINFO(ReqIEs=", 17) == 0) {
		char *spos;
		int bytes;
		unsigned char *req_ies = 0, *resp_ies = 0;

		spos = custom + 17;

		bytes = strspn(spos, "0123456789abcdefABCDEF");
		if (!bytes || (bytes & 1))
			return;
		bytes /= 2;

		req_ies = os_malloc(bytes);
		if (req_ies == 0 ||
		    hexstr2bin(spos, req_ies, bytes) < 0)
			goto done;
		data.assoc_info.req_ies = req_ies;
		data.assoc_info.req_ies_len = bytes;

		spos += bytes * 2;

		data.assoc_info.resp_ies = 0;
		data.assoc_info.resp_ies_len = 0;

		if (os_strncmp(spos, " RespIEs=", 9) == 0) {
			spos += 9;

			bytes = strspn(spos, "0123456789abcdefABCDEF");
			if (!bytes || (bytes & 1))
				goto done;
			bytes /= 2;

			resp_ies = os_malloc(bytes);
			if (resp_ies == 0 ||
			    hexstr2bin(spos, resp_ies, bytes) < 0)
				goto done;
			data.assoc_info.resp_ies = resp_ies;
			data.assoc_info.resp_ies_len = bytes;
		}

		wpa_supplicant_event(ctx, EVENT_ASSOCINFO, &data);

	done:
		os_free(resp_ies);
		os_free(req_ies);

	} else if (os_strncmp(custom, "STKSTART.request=", 17) == 0) {
		if (hwaddr_aton(custom + 17, data.stkstart.peer)) {
			wpa_printf(0, "WEXT: unrecognized "
				   "STKSTART.request '%s'", custom + 17);
			return;
		}
		wpa_supplicant_event(ctx, EVENT_STKSTART, &data);

	}
}


static int wpa_driver_wext_event_wireless_michaelmicfailure(
	void *ctx, const char *ev, size_t len)
{
	const struct iw_michaelmicfailure *mic;
	union wpa_event_data data;

	if (len < sizeof(*mic))
		return -1;

	mic = (const struct iw_michaelmicfailure *) ev;

	wpa_printf(0, "Michael MIC failure wireless event: "
		   "flags=0x%x src_addr=" "%02x:%02x:%02x:%02x:%02x:%02x", mic->flags,
		   (mic->src_addr . sa_data)[0], (mic->src_addr . sa_data)[1], (mic->src_addr . sa_data)[2], (mic->src_addr . sa_data)[3], (mic->src_addr . sa_data)[4], (mic->src_addr . sa_data)[5]);

	memset(&data, 0, sizeof(data));
	data.michael_mic_failure.unicast = !(mic->flags & 0x00000004);
	wpa_supplicant_event(ctx, EVENT_MICHAEL_MIC_FAILURE, &data);

	return 0;
}


static int wpa_driver_wext_event_wireless_pmkidcand(
	struct wpa_driver_wext_data *drv, const char *ev, size_t len)
{
	const struct iw_pmkid_cand *cand;
	union wpa_event_data data;
	const unsigned char *addr;

	if (len < sizeof(*cand))
		return -1;

	cand = (const struct iw_pmkid_cand *) ev;
	addr = (const unsigned char *) cand->bssid.sa_data;

	wpa_printf(0, "PMKID candidate wireless event: "
		   "flags=0x%x index=%d bssid=" "%02x:%02x:%02x:%02x:%02x:%02x", cand->flags,
		   cand->index, (addr)[0], (addr)[1], (addr)[2], (addr)[3], (addr)[4], (addr)[5]);

	memset(&data, 0, sizeof(data));
	memcpy(data.pmkid_candidate.bssid, addr, 6);
	data.pmkid_candidate.index = cand->index;
	data.pmkid_candidate.preauth = cand->flags & 0x00000001;
	wpa_supplicant_event(drv->ctx, EVENT_PMKID_CANDIDATE, &data);

	return 0;
}


static int wpa_driver_wext_event_wireless_assocreqie(
	struct wpa_driver_wext_data *drv, const char *ev, int len)
{
	if (len < 0)
		return -1;

	wpa_hexdump(0, "AssocReq IE wireless event", (const unsigned char *) ev,
		    len);
	os_free(drv->assoc_req_ies);
	drv->assoc_req_ies = os_malloc(len);
	if (drv->assoc_req_ies == 0) {
		drv->assoc_req_ies_len = 0;
		return -1;
	}
	memcpy(drv->assoc_req_ies, ev, len);
	drv->assoc_req_ies_len = len;

	return 0;
}


static int wpa_driver_wext_event_wireless_assocrespie(
	struct wpa_driver_wext_data *drv, const char *ev, int len)
{
	if (len < 0)
		return -1;

	wpa_hexdump(0, "AssocResp IE wireless event", (const unsigned char *) ev,
		    len);
	os_free(drv->assoc_resp_ies);
	drv->assoc_resp_ies = os_malloc(len);
	if (drv->assoc_resp_ies == 0) {
		drv->assoc_resp_ies_len = 0;
		return -1;
	}
	memcpy(drv->assoc_resp_ies, ev, len);
	drv->assoc_resp_ies_len = len;

	return 0;
}


static void wpa_driver_wext_event_assoc_ies(struct wpa_driver_wext_data *drv)
{
	union wpa_event_data data;

	if (drv->assoc_req_ies == 0 && drv->assoc_resp_ies == 0)
		return;

	memset(&data, 0, sizeof(data));
	if (drv->assoc_req_ies) {
		data.assoc_info.req_ies = drv->assoc_req_ies;
		data.assoc_info.req_ies_len = drv->assoc_req_ies_len;
	}
	if (drv->assoc_resp_ies) {
		data.assoc_info.resp_ies = drv->assoc_resp_ies;
		data.assoc_info.resp_ies_len = drv->assoc_resp_ies_len;
	}

	wpa_supplicant_event(drv->ctx, EVENT_ASSOCINFO, &data);

	os_free(drv->assoc_req_ies);
	drv->assoc_req_ies = 0;
	os_free(drv->assoc_resp_ies);
	drv->assoc_resp_ies = 0;
}


static void wpa_driver_wext_event_wireless(struct wpa_driver_wext_data *drv,
					   char *data, int len)
{
	struct iw_event iwe_buf, *iwe = &iwe_buf;
	char *pos, *end, *custom, *buf;

	pos = data;
	end = data + len;

	while (pos + (sizeof(struct iw_event) - sizeof(union iwreq_data)) <= end) {
		
 
		memcpy(&iwe_buf, pos, (sizeof(struct iw_event) - sizeof(union iwreq_data)));
		wpa_printf(0, "Wireless event: cmd=0x%x len=%d",
			   iwe->cmd, iwe->len);
		if (iwe->len <= (sizeof(struct iw_event) - sizeof(union iwreq_data)))
			return;

		custom = pos + ((sizeof(struct iw_event) - sizeof(union iwreq_data)) + sizeof(struct iw_point) - (((char *) &(((struct iw_point *) 0)->length)) - (char *) 0));
		if (drv->we_version_compiled > 18 &&
		    (iwe->cmd == 0x8C06 ||
		     iwe->cmd == 0x8C02 ||
		     iwe->cmd == 0x8C07 ||
		     iwe->cmd == 0x8C08 ||
		     iwe->cmd == 0x8C09)) {
			 
			char *dpos = (char *) &iwe_buf.u.data.length;
			int dlen = dpos - (char *) &iwe_buf;
			memcpy(dpos, pos + (sizeof(struct iw_event) - sizeof(union iwreq_data)),
				  sizeof(struct iw_event) - dlen);
		} else {
			memcpy(&iwe_buf, pos, sizeof(struct iw_event));
			custom += (((char *) &(((struct iw_point *) 0)->length)) - (char *) 0);
		}

		switch (iwe->cmd) {
		case 0x8B15:
			wpa_printf(0, "Wireless event: new AP: "
				   "%02x:%02x:%02x:%02x:%02x:%02x",
				   ((unsigned char *) iwe ->u . ap_addr . sa_data)[0], ((unsigned char *) iwe ->u . ap_addr . sa_data)[1], ((unsigned char *) iwe ->u . ap_addr . sa_data)[2], ((unsigned char *) iwe ->u . ap_addr . sa_data)[3], ((unsigned char *) iwe ->u . ap_addr . sa_data)[4], ((unsigned char *) iwe ->u . ap_addr . sa_data)[5]);
			if (is_zero_ether_addr(
				    (const unsigned char *) iwe->u.ap_addr.sa_data) ||
			    memcmp(iwe->u.ap_addr.sa_data,
				      "\x44\x44\x44\x44\x44\x44", 6) ==
			    0) {
				os_free(drv->assoc_req_ies);
				drv->assoc_req_ies = 0;
				os_free(drv->assoc_resp_ies);
				drv->assoc_resp_ies = 0;
				wpa_supplicant_event(drv->ctx, EVENT_DISASSOC,
						     0);
			
			} else {
				wpa_driver_wext_event_assoc_ies(drv);
				wpa_supplicant_event(drv->ctx, EVENT_ASSOC,
						     0);
			}
			break;
		case 0x8C06:
			if (custom + iwe->u.data.length > end) {
				wpa_printf(0, "WEXT: Invalid "
					   "IWEVMICHAELMICFAILURE length");
				return;
			}
			wpa_driver_wext_event_wireless_michaelmicfailure(
				drv->ctx, custom, iwe->u.data.length);
			break;
		case 0x8C02:
			if (custom + iwe->u.data.length > end) {
				wpa_printf(0, "WEXT: Invalid "
					   "IWEVCUSTOM length");
				return;
			}
			buf = os_malloc(iwe->u.data.length + 1);
			if (buf == 0)
				return;
			memcpy(buf, custom, iwe->u.data.length);
			buf[iwe->u.data.length] = '\0';
			wpa_driver_wext_event_wireless_custom(drv->ctx, buf);
			os_free(buf);
			break;
		case 0x8B19:
			drv->scan_complete_events = 1;
			eloop_cancel_timeout(wpa_driver_wext_scan_timeout,
					     drv, drv->ctx);
			wpa_supplicant_event(drv->ctx, EVENT_SCAN_RESULTS,
					     0);
			break;
		case 0x8C07:
			if (custom + iwe->u.data.length > end) {
				wpa_printf(0, "WEXT: Invalid "
					   "IWEVASSOCREQIE length");
				return;
			}
			wpa_driver_wext_event_wireless_assocreqie(
				drv, custom, iwe->u.data.length);
			break;
		case 0x8C08:
			if (custom + iwe->u.data.length > end) {
				wpa_printf(0, "WEXT: Invalid "
					   "IWEVASSOCRESPIE length");
				return;
			}
			wpa_driver_wext_event_wireless_assocrespie(
				drv, custom, iwe->u.data.length);
			break;
		case 0x8C09:
			if (custom + iwe->u.data.length > end) {
				wpa_printf(0, "WEXT: Invalid "
					   "IWEVPMKIDCAND length");
				return;
			}
			wpa_driver_wext_event_wireless_pmkidcand(
				drv, custom, iwe->u.data.length);
			break;
		}

		pos += iwe->len;
	}
}


static void wpa_driver_wext_event_link(struct wpa_driver_wext_data *drv,
				       char *buf, size_t len, int del)
{
	union wpa_event_data event;

	memset(&event, 0, sizeof(event));
	if (len > sizeof(event.interface_status.ifname))
		len = sizeof(event.interface_status.ifname) - 1;
	memcpy(event.interface_status.ifname, buf, len);
	event.interface_status.ievent = del ? EVENT_INTERFACE_REMOVED :
		EVENT_INTERFACE_ADDED;

	wpa_printf(0, "RTM_%sLINK, IFLA_IFNAME: Interface '%s' %s",
		   del ? "DEL" : "NEW",
		   event.interface_status.ifname,
		   del ? "removed" : "added");

	if (os_strcmp(drv->ifname, event.interface_status.ifname) == 0) {
		if (del)
			drv->if_removed = 1;
		else
			drv->if_removed = 0;
	}

	wpa_supplicant_event(drv->ctx, EVENT_INTERFACE_STATUS, &event);
}


static int wpa_driver_wext_own_ifname(struct wpa_driver_wext_data *drv,
				      unsigned char *buf, size_t len)
{
	int attrlen, rta_len;
	struct rtattr *attr;

	attrlen = len;
	attr = (struct rtattr *) buf;

	rta_len = (((sizeof(struct rtattr)) + 4 - 1) & ~(4 - 1));
	while (((attrlen) > 0 && (attr)->rta_len >= sizeof(struct rtattr) && (attr)->rta_len <= (attrlen))) {
		if (attr->rta_type == 3) {
			if (os_strcmp(((char *) attr) + rta_len, drv->ifname)
			    == 0)
				return 1;
			else
				break;
		}
		attr = ((attrlen) -= ((((attr)->rta_len) + 4 - 1) & ~(4 - 1)), (struct rtattr *) (((char *)(attr)) + ((((attr)->rta_len) + 4 - 1) & ~(4 - 1))));
	}

	return 0;
}


static int wpa_driver_wext_own_ifindex(struct wpa_driver_wext_data *drv,
				       int ifindex, unsigned char *buf, size_t len)
{
	return 0;
#line 645 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c"
}


static void wpa_driver_wext_event_rtm_newlink(void *ctx, struct ifinfomsg *ifi,
					      unsigned char *buf, size_t len)
{

#line 699 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c"
}


static void wpa_driver_wext_event_rtm_dellink(void *ctx, struct ifinfomsg *ifi,
					      unsigned char *buf, size_t len)
{
	struct wpa_driver_wext_data *drv = ctx;
	int attrlen, rta_len;
	struct rtattr *attr;

	attrlen = len;
	attr = (struct rtattr *) buf;

	rta_len = (((sizeof(struct rtattr)) + 4 - 1) & ~(4 - 1));
	while (((attrlen) > 0 && (attr)->rta_len >= sizeof(struct rtattr) && (attr)->rta_len <= (attrlen))) {
		if (attr->rta_type == 3) {
			wpa_driver_wext_event_link(drv,
						   ((char *) attr) + rta_len,
						   attr->rta_len - rta_len, 1);
		}
		attr = ((attrlen) -= ((((attr)->rta_len) + 4 - 1) & ~(4 - 1)), (struct rtattr *) (((char *)(attr)) + ((((attr)->rta_len) + 4 - 1) & ~(4 - 1))));
	}
}








 
void * wpa_driver_wext_init(void *ctx, const char *ifname)
{

	struct wpa_driver_wext_data *drv;
	printf("RUN_TEST >>> LINE:%d ,,, FUNCTION:%s ,,, FILE:%s \r\n",735,__FUNCTION__,"..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c");;
	drv = os_zalloc(sizeof(*drv));
	if (drv == 0)
		return 0;
	drv->ctx = ctx;
	return drv;
#line 794 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c"
}


static int wpa_driver_wext_finish_drv_init(struct wpa_driver_wext_data *drv)
{
	printf("RUN_TEST >>> LINE:%d ,,, FUNCTION:%s ,,, FILE:%s \r\n",799,__FUNCTION__,"..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c");;
	return -1;
#line 847 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c"
}








 
void wpa_driver_wext_deinit(void *priv)
{
	printf("RUN_TEST >>> LINE:%d ,,, FUNCTION:%s ,,, FILE:%s \r\n",859,__FUNCTION__,"..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c");;

#line 889 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c"
}









 
void wpa_driver_wext_scan_timeout(void *eloop_ctx, void *timeout_ctx)
{
	printf("RUN_TEST >>> LINE:%d ,,, FUNCTION:%s ,,, FILE:%s \r\n",902,__FUNCTION__,"..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c");;
	wpa_printf(0, "Scan timeout - try to get results");
	wpa_supplicant_event(timeout_ctx, EVENT_SCAN_RESULTS, 0);
}







 
int wpa_driver_wext_scan(void *priv, struct wpa_driver_scan_params *params)
{
	return 0;
#line 969 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c"
}


static unsigned char * wpa_driver_wext_giwscan(struct wpa_driver_wext_data *drv,
				    size_t *len)
{
	return 0;

#line 1019 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c"
}





 
struct wext_scan_data {
	struct wpa_scan_res res;
	unsigned char *ie;
	size_t ie_len;
	unsigned char ssid[32];
	size_t ssid_len;
	int maxrate;
};


static void wext_get_scan_mode(struct iw_event *iwe,
			       struct wext_scan_data *res)
{
	if (iwe->u.mode == 1)
		res->res.caps |= 0x0002;
	else if (iwe->u.mode == 3 || iwe->u.mode == 2)
		res->res.caps |= 0x0001;
}


static void wext_get_scan_ssid(struct iw_event *iwe,
			       struct wext_scan_data *res, char *custom,
			       char *end)
{
	int ssid_len = iwe->u.essid.length;
	if (custom + ssid_len > end)
		return;
	if (iwe->u.essid.flags &&
	    ssid_len > 0 &&
	    ssid_len <= 32) {
		memcpy(res->ssid, custom, ssid_len);
		res->ssid_len = ssid_len;
	}
}


static void wext_get_scan_freq(struct iw_event *iwe,
			       struct wext_scan_data *res)
{
	int divi = 1000000, i;

	if (iwe->u.freq.e == 0) {
		






 

		if (res->res.freq)
			return;

		if (iwe->u.freq.m >= 1 && iwe->u.freq.m <= 13) {
			res->res.freq = 2407 + 5 * iwe->u.freq.m;
			return;
		} else if (iwe->u.freq.m == 14) {
			res->res.freq = 2484;
			return;
		}
	}

	if (iwe->u.freq.e > 6) {
		wpa_printf(0, "Invalid freq in scan results (BSSID="
			   "%02x:%02x:%02x:%02x:%02x:%02x" " m=%d e=%d)",
			   (res->res . bssid)[0], (res->res . bssid)[1], (res->res . bssid)[2], (res->res . bssid)[3], (res->res . bssid)[4], (res->res . bssid)[5], iwe->u.freq.m,
			   iwe->u.freq.e);
		return;
	}

	for (i = 0; i < iwe->u.freq.e; i++)
		divi /= 10;
	res->res.freq = iwe->u.freq.m / divi;
}


static void wext_get_scan_qual(struct iw_event *iwe,
			       struct wext_scan_data *res)
{
	res->res.qual = iwe->u.qual.qual;
	res->res.noise = iwe->u.qual.noise;
	res->res.level = iwe->u.qual.level;
	if (iwe->u.qual.updated & 0x10)
		res->res.flags |= (1 << (0));
	if (iwe->u.qual.updated & 0x20)
		res->res.flags |= (1 << (2));
	if (iwe->u.qual.updated & 0x40)
		res->res.flags |= (1 << (1));
	if (iwe->u.qual.updated & 0x08)
		res->res.flags |= (1 << (3));
}


static void wext_get_scan_encode(struct iw_event *iwe,
				 struct wext_scan_data *res)
{
	if (!(iwe->u.data.flags & 0x8000))
		res->res.caps |= 0x0010;
}


static void wext_get_scan_rate(struct iw_event *iwe,
			       struct wext_scan_data *res, char *pos,
			       char *end)
{
#line 1156 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c"
}


static void wext_get_scan_iwevgenie(struct iw_event *iwe,
				    struct wext_scan_data *res, char *custom,
				    char *end)
{
	char *genie, *gpos, *gend;
	unsigned char *tmp;

	if (iwe->u.data.length == 0)
		return;

	gpos = genie = custom;
	gend = genie + iwe->u.data.length;
	if (gend > end) {
		wpa_printf(0, "IWEVGENIE overflow");
		return;
	}

	tmp = os_realloc(res->ie, res->ie_len + gend - gpos);
	if (tmp == 0)
		return;
	memcpy(tmp + res->ie_len, gpos, gend - gpos);
	res->ie = tmp;
	res->ie_len += gend - gpos;
}


static void wext_get_scan_custom(struct iw_event *iwe,
				 struct wext_scan_data *res, char *custom,
				 char *end)
{
	size_t clen;
	unsigned char *tmp;

	clen = iwe->u.data.length;
	if (custom + clen > end)
		return;

	if (clen > 7 && os_strncmp(custom, "wpa_ie=", 7) == 0) {
		char *spos;
		int bytes;
		spos = custom + 7;
		bytes = custom + clen - spos;
		if (bytes & 1 || bytes == 0)
			return;
		bytes /= 2;
		tmp = os_realloc(res->ie, res->ie_len + bytes);
		if (tmp == 0)
			return;
		res->ie = tmp;
		if (hexstr2bin(spos, tmp + res->ie_len, bytes) < 0)
			return;
		res->ie_len += bytes;
	} else if (clen > 7 && os_strncmp(custom, "rsn_ie=", 7) == 0) {
		char *spos;
		int bytes;
		spos = custom + 7;
		bytes = custom + clen - spos;
		if (bytes & 1 || bytes == 0)
			return;
		bytes /= 2;
		tmp = os_realloc(res->ie, res->ie_len + bytes);
		if (tmp == 0)
			return;
		res->ie = tmp;
		if (hexstr2bin(spos, tmp + res->ie_len, bytes) < 0)
			return;
		res->ie_len += bytes;
	} else if (clen > 4 && os_strncmp(custom, "tsf=", 4) == 0) {
		char *spos;
		int bytes;
		unsigned char bin[8];
		spos = custom + 4;
		bytes = custom + clen - spos;
		if (bytes != 16) {
			wpa_printf(0, "Invalid TSF length (%d)", bytes);
			return;
		}
		bytes /= 2;
		if (hexstr2bin(spos, bin, bytes) < 0) {
			wpa_printf(0, "WEXT: Invalid TSF value");
			return;
		}
		res->res.tsf += ((((unsigned long) (bin)[0]) << 56) | (((unsigned long) (bin)[1]) << 48) | (((unsigned long) (bin)[2]) << 40) | (((unsigned long) (bin)[3]) << 32) | (((unsigned long) (bin)[4]) << 24) | (((unsigned long) (bin)[5]) << 16) | (((unsigned long) (bin)[6]) << 8) | ((unsigned long) (bin)[7]));
	}
}


static int wext_19_iw_point(struct wpa_driver_wext_data *drv, unsigned short cmd)
{
	return drv->we_version_compiled > 18 &&
		(cmd == 0x8B1B || cmd == 0x8B2B ||
		 cmd == 0x8C05 || cmd == 0x8C02);
}


static void wpa_driver_wext_add_scan_entry(struct wpa_scan_results *res,
					   struct wext_scan_data *data)
{
	struct wpa_scan_res **tmp;
	struct wpa_scan_res *r;
	size_t extra_len;
	unsigned char *pos, *end, *ssid_ie = 0, *rate_ie = 0;

	 
	pos = data->ie;
	end = pos + data->ie_len;
	while (pos && pos + 1 < end) {
		if (pos + 2 + pos[1] > end)
			break;
		if (pos[0] == 0)
			ssid_ie = pos;
		else if (pos[0] == 1)
			rate_ie = pos;
		else if (pos[0] == 50)
			rate_ie = pos;
		pos += 2 + pos[1];
	}

	extra_len = 0;
	if (ssid_ie == 0)
		extra_len += 2 + data->ssid_len;
	if (rate_ie == 0 && data->maxrate)
		extra_len += 3;

	r = os_zalloc(sizeof(*r) + extra_len + data->ie_len);
	if (r == 0)
		return;
	memcpy(r, &data->res, sizeof(*r));
	r->ie_len = extra_len + data->ie_len;
	pos = (unsigned char *) (r + 1);
	if (ssid_ie == 0) {
		


 
		*pos++ = 0;
		*pos++ = data->ssid_len;
		memcpy(pos, data->ssid, data->ssid_len);
		pos += data->ssid_len;
	}
	if (rate_ie == 0 && data->maxrate) {
		


 
		*pos++ = 1;
		*pos++ = 1;
		*pos++ = data->maxrate;
	}
	if (data->ie)
		memcpy(pos, data->ie, data->ie_len);

	tmp = os_realloc(res->res,
			 (res->num + 1) * sizeof(struct wpa_scan_res *));
	if (tmp == 0) {
		os_free(r);
		return;
	}
	tmp[res->num++] = r;
	res->res = tmp;
}
				      





 
struct wpa_scan_results * wpa_driver_wext_get_scan_results(void *priv)
{
	printf("RUN_TEST >>> LINE:%d ,,, FUNCTION:%s ,,, FILE:%s \r\n",1329,__FUNCTION__,"..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c");;
	return 0;
#line 1426 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c"
}


static int wpa_driver_wext_get_range(void *priv)
{
	return 0;
#line 1501 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c"
}


static int wpa_driver_wext_set_psk(struct wpa_driver_wext_data *drv,
				   const unsigned char *psk)
{
	return 0;
#line 1541 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c"
}


static int wpa_driver_wext_set_key_ext(void *priv, enum wpa_alg alg,
				       const unsigned char *addr, int key_idx,
				       int set_tx, const unsigned char *seq,
				       size_t seq_len,
				       const unsigned char *key, size_t key_len)
{
	printf("RUN_TEST >>> LINE:%d ,,, FUNCTION:%s ,,, FILE:%s \r\n",1550,__FUNCTION__,"..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c");;
	return 0;
#line 1639 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c"
}



























 
int wpa_driver_wext_set_key(const char *ifname, void *priv, enum wpa_alg alg,
			    const unsigned char *addr, int key_idx,
			    int set_tx, const unsigned char *seq, size_t seq_len,
			    const unsigned char *key, size_t key_len)
{
	return 0;
#line 1729 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c"
}


static int wpa_driver_wext_set_countermeasures(void *priv,
					       int enabled)
{
	printf("RUN_TEST >>> LINE:%d ,,, FUNCTION:%s ,,, FILE:%s \r\n",1735,__FUNCTION__,"..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c");;
	return 0;
#line 1744 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c"
}


static int wpa_driver_wext_set_drop_unencrypted(void *priv,
						int enabled)
{
	struct wpa_driver_wext_data *drv = priv;
	wpa_printf(0, "%s", __FUNCTION__);
	drv->use_crypt = enabled;
	return wpa_driver_wext_set_auth_param(drv, 5,
					      enabled);
}


static int wpa_driver_wext_mlme(struct wpa_driver_wext_data *drv,
				const unsigned char *addr, int cmd, int reason_code)
{
	return 0;
#line 1784 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c"
}


static void wpa_driver_wext_disconnect(struct wpa_driver_wext_data *drv)
{

#line 1837 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c"
}


static int wpa_driver_wext_deauthenticate(void *priv, const unsigned char *addr,
					  int reason_code)
{
	printf("RUN_TEST >>> LINE:%d ,,, FUNCTION:%s ,,, FILE:%s \r\n",1843,__FUNCTION__,"..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c");;
	return 0;
#line 1853 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c"
}


static int wpa_driver_wext_disassociate(void *priv, const unsigned char *addr,
					int reason_code)
{
	printf("RUN_TEST >>> LINE:%d ,,, FUNCTION:%s ,,, FILE:%s \r\n",1859,__FUNCTION__,"..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c");;
	return 0;
#line 1869 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c"
}


static int wpa_driver_wext_set_gen_ie(void *priv, const unsigned char *ie,
				      size_t ie_len)
{
	return 0;
#line 1893 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c"
}


int wpa_driver_wext_cipher2wext(int cipher)
{
	switch (cipher) {
	case CIPHER_NONE:
		return 0x00000001;
	case CIPHER_WEP40:
		return 0x00000002;
	case CIPHER_TKIP:
		return 0x00000004;
	case CIPHER_CCMP:
		return 0x00000008;
	case CIPHER_WEP104:
		return 0x00000010;
	default:
		return 0;
	}
}


int wpa_driver_wext_keymgmt2wext(int keymgmt)
{
	switch (keymgmt) {
	case KEY_MGMT_802_1X:
	case KEY_MGMT_802_1X_NO_WPA:
		return 1;
	case KEY_MGMT_PSK:
		return 2;
	default:
		return 0;
	}
}


static int
wpa_driver_wext_auth_alg_fallback(struct wpa_driver_wext_data *drv,
				  struct wpa_driver_associate_params *params)
{
	return 0;
#line 1973 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c"
}


int wpa_driver_wext_associate(void *priv,
			      struct wpa_driver_associate_params *params)
{
	printf("RUN_TEST >>> LINE:%d ,,, FUNCTION:%s ,,, FILE:%s \r\n",1979,__FUNCTION__,"..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c");;
	return 0;
#line 2096 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c"
}


static int wpa_driver_wext_set_auth_alg(void *priv, int auth_alg)
{
	struct wpa_driver_wext_data *drv = priv;
	int algs = 0, res;

	if (auth_alg & (1 << (0)))
		algs |= 0x00000001;
	if (auth_alg & (1 << (1)))
		algs |= 0x00000002;
	if (auth_alg & (1 << (2)))
		algs |= 0x00000004;
	if (algs == 0) {
		 
		algs = 0x00000001;
	}

	res = wpa_driver_wext_set_auth_param(drv, 6,
					     algs);
	drv->auth_alg_fallback = res == -2;
	return res;
}







 
int wpa_driver_wext_set_mode(void *priv, int mode)
{
	return -1;
#line 2178 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c"
}


static int wpa_driver_wext_pmksa(struct wpa_driver_wext_data *drv,
				 unsigned int cmd, const unsigned char *bssid, const unsigned char *pmkid)
{

	return 0;
#line 2211 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c"
}


static int wpa_driver_wext_add_pmkid(void *priv, const unsigned char *bssid,
				     const unsigned char *pmkid)
{
	struct wpa_driver_wext_data *drv = priv;
	return wpa_driver_wext_pmksa(drv, 1, bssid, pmkid);
}


static int wpa_driver_wext_remove_pmkid(void *priv, const unsigned char *bssid,
		 			const unsigned char *pmkid)
{
	struct wpa_driver_wext_data *drv = priv;
	return wpa_driver_wext_pmksa(drv, 2, bssid, pmkid);
}


static int wpa_driver_wext_flush_pmkid(void *priv)
{
	struct wpa_driver_wext_data *drv = priv;
	return wpa_driver_wext_pmksa(drv, 3, 0, 0);
}


int wpa_driver_wext_get_capa(void *priv, struct wpa_driver_capa *capa)
{
	printf("RUN_TEST >>> LINE:%d ,,, FUNCTION:%s ,,, FILE:%s \r\n",2239,__FUNCTION__,"..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c");;
	return 0;
#line 2248 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c"
}


int wpa_driver_wext_alternative_ifindex(struct wpa_driver_wext_data *drv,
					const char *ifname)
{
	return 0;
#line 2270 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c"
}


int wpa_driver_wext_set_operstate(void *priv, int state)
{
	printf("RUN_TEST >>> LINE:%d ,,, FUNCTION:%s ,,, FILE:%s \r\n",2275,__FUNCTION__,"..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c");;
	return 0;
#line 2286 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c"
}


int wpa_driver_wext_get_version(struct wpa_driver_wext_data *drv)
{
	return drv->we_version_compiled;
}

#line 2316 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\drivers\\driver_wext.c"
const struct wpa_driver_ops wpa_driver_wext_ops = {
	"wext",
"Linux wireless extensions (generic)",
wpa_driver_wext_get_bssid,
wpa_driver_wext_get_ssid,
wpa_driver_wext_set_key,
wpa_driver_wext_init,
wpa_driver_wext_deinit,
0,
wpa_driver_wext_set_countermeasures,
wpa_driver_wext_deauthenticate,
wpa_driver_wext_disassociate,
wpa_driver_wext_associate,
wpa_driver_wext_add_pmkid,
wpa_driver_wext_remove_pmkid,
wpa_driver_wext_flush_pmkid,
wpa_driver_wext_get_capa,
0,
0,
0,
0,
wpa_driver_wext_set_operstate,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
wpa_driver_wext_get_scan_results,
0,
0,
0,
0,
wpa_driver_wext_scan,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
};

