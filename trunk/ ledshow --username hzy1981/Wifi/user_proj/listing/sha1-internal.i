#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\crypto\\sha1-internal.c"












 

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

#line 16 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\crypto\\sha1-internal.c"

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



#line 18 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\crypto\\sha1-internal.c"
#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\crypto\\sha1.h"












 






#line 21 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\crypto\\sha1.h"

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
#line 19 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\crypto\\sha1-internal.c"
#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\crypto\\sha1_i.h"












 




struct SHA1Context {
	unsigned int state[5];
	unsigned int count[2];
	unsigned char buffer[64];
};

void SHA1Init(struct SHA1Context *context);
void SHA1Update(struct SHA1Context *context, const void *data, unsigned int len);
void SHA1Final(unsigned char digest[20], struct SHA1Context *context);
void SHA1Transform(unsigned int state[5], const unsigned char buffer[64]);

#line 20 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\crypto\\sha1-internal.c"
#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\crypto\\md5.h"












 






int hmac_md5_vector(const unsigned char *key, size_t key_len, size_t num_elem,
		    const unsigned char *addr[], const size_t *len, unsigned char *mac);
int hmac_md5(const unsigned char *key, size_t key_len, const unsigned char *data, size_t data_len,
	     unsigned char *mac);
#line 34 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\crypto\\md5.h"

#line 21 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\crypto\\sha1-internal.c"
#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\crypto\\crypto.h"
























 




#line 31 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\crypto\\crypto.h"








 
int md4_vector(size_t num_elem, const unsigned char *addr[], const size_t *len, unsigned char *mac);








 
int md5_vector(size_t num_elem, const unsigned char *addr[], const size_t *len, unsigned char *mac);

#line 66 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\crypto\\crypto.h"









 
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

#line 22 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\crypto\\sha1-internal.c"

typedef struct SHA1Context SHA1_CTX;

void SHA1Transform(unsigned int state[5], const unsigned char buffer[64]);









 
int sha1_vector(size_t num_elem, const unsigned char *addr[], const size_t *len, unsigned char *mac)
{
	SHA1_CTX ctx;
	size_t i;

	SHA1Init(&ctx);
	for (i = 0; i < num_elem; i++)
		SHA1Update(&ctx, addr[i], len[i]);
	SHA1Final(mac, &ctx);
	return 0;
}


 



































































 









 





 
 
#line 143 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\crypto\\sha1-internal.c"

 
#line 159 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\crypto\\sha1-internal.c"


#line 174 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\crypto\\sha1-internal.c"

 

void SHA1Transform(unsigned int state[5], const unsigned char buffer[64])
{
	unsigned int a, b, c, d, e;
	typedef union {
		unsigned char c[64];
		unsigned int l[16];
	} CHAR64LONG16;
	CHAR64LONG16* block;

	CHAR64LONG16 workspace;
	block = &workspace;
	os_memcpy(block, buffer, 64);



	 
	a = state[0];
	b = state[1];
	c = state[2];
	d = state[3];
	e = state[4];
	 
	e += ((b & (c ^ d)) ^ d) + (block->l[0] = ((((block->l[0]) << (24)) | ((block->l[0]) >> (32 - (24)))) & 0xFF00FF00) | ((((block->l[0]) << (8)) | ((block->l[0]) >> (32 - (8)))) & 0x00FF00FF)) + 0x5A827999 + (((a) << (5)) | ((a) >> (32 - (5)))); b = (((b) << (30)) | ((b) >> (32 - (30))));; d += ((a & (b ^ c)) ^ c) + (block->l[1] = ((((block->l[1]) << (24)) | ((block->l[1]) >> (32 - (24)))) & 0xFF00FF00) | ((((block->l[1]) << (8)) | ((block->l[1]) >> (32 - (8)))) & 0x00FF00FF)) + 0x5A827999 + (((e) << (5)) | ((e) >> (32 - (5)))); a = (((a) << (30)) | ((a) >> (32 - (30))));; c += ((e & (a ^ b)) ^ b) + (block->l[2] = ((((block->l[2]) << (24)) | ((block->l[2]) >> (32 - (24)))) & 0xFF00FF00) | ((((block->l[2]) << (8)) | ((block->l[2]) >> (32 - (8)))) & 0x00FF00FF)) + 0x5A827999 + (((d) << (5)) | ((d) >> (32 - (5)))); e = (((e) << (30)) | ((e) >> (32 - (30))));; b += ((d & (e ^ a)) ^ a) + (block->l[3] = ((((block->l[3]) << (24)) | ((block->l[3]) >> (32 - (24)))) & 0xFF00FF00) | ((((block->l[3]) << (8)) | ((block->l[3]) >> (32 - (8)))) & 0x00FF00FF)) + 0x5A827999 + (((c) << (5)) | ((c) >> (32 - (5)))); d = (((d) << (30)) | ((d) >> (32 - (30))));;
	a += ((c & (d ^ e)) ^ e) + (block->l[4] = ((((block->l[4]) << (24)) | ((block->l[4]) >> (32 - (24)))) & 0xFF00FF00) | ((((block->l[4]) << (8)) | ((block->l[4]) >> (32 - (8)))) & 0x00FF00FF)) + 0x5A827999 + (((b) << (5)) | ((b) >> (32 - (5)))); c = (((c) << (30)) | ((c) >> (32 - (30))));; e += ((b & (c ^ d)) ^ d) + (block->l[5] = ((((block->l[5]) << (24)) | ((block->l[5]) >> (32 - (24)))) & 0xFF00FF00) | ((((block->l[5]) << (8)) | ((block->l[5]) >> (32 - (8)))) & 0x00FF00FF)) + 0x5A827999 + (((a) << (5)) | ((a) >> (32 - (5)))); b = (((b) << (30)) | ((b) >> (32 - (30))));; d += ((a & (b ^ c)) ^ c) + (block->l[6] = ((((block->l[6]) << (24)) | ((block->l[6]) >> (32 - (24)))) & 0xFF00FF00) | ((((block->l[6]) << (8)) | ((block->l[6]) >> (32 - (8)))) & 0x00FF00FF)) + 0x5A827999 + (((e) << (5)) | ((e) >> (32 - (5)))); a = (((a) << (30)) | ((a) >> (32 - (30))));; c += ((e & (a ^ b)) ^ b) + (block->l[7] = ((((block->l[7]) << (24)) | ((block->l[7]) >> (32 - (24)))) & 0xFF00FF00) | ((((block->l[7]) << (8)) | ((block->l[7]) >> (32 - (8)))) & 0x00FF00FF)) + 0x5A827999 + (((d) << (5)) | ((d) >> (32 - (5)))); e = (((e) << (30)) | ((e) >> (32 - (30))));;
	b += ((d & (e ^ a)) ^ a) + (block->l[8] = ((((block->l[8]) << (24)) | ((block->l[8]) >> (32 - (24)))) & 0xFF00FF00) | ((((block->l[8]) << (8)) | ((block->l[8]) >> (32 - (8)))) & 0x00FF00FF)) + 0x5A827999 + (((c) << (5)) | ((c) >> (32 - (5)))); d = (((d) << (30)) | ((d) >> (32 - (30))));; a += ((c & (d ^ e)) ^ e) + (block->l[9] = ((((block->l[9]) << (24)) | ((block->l[9]) >> (32 - (24)))) & 0xFF00FF00) | ((((block->l[9]) << (8)) | ((block->l[9]) >> (32 - (8)))) & 0x00FF00FF)) + 0x5A827999 + (((b) << (5)) | ((b) >> (32 - (5)))); c = (((c) << (30)) | ((c) >> (32 - (30))));; e += ((b & (c ^ d)) ^ d) + (block->l[10] = ((((block->l[10]) << (24)) | ((block->l[10]) >> (32 - (24)))) & 0xFF00FF00) | ((((block->l[10]) << (8)) | ((block->l[10]) >> (32 - (8)))) & 0x00FF00FF)) + 0x5A827999 + (((a) << (5)) | ((a) >> (32 - (5)))); b = (((b) << (30)) | ((b) >> (32 - (30))));; d += ((a & (b ^ c)) ^ c) + (block->l[11] = ((((block->l[11]) << (24)) | ((block->l[11]) >> (32 - (24)))) & 0xFF00FF00) | ((((block->l[11]) << (8)) | ((block->l[11]) >> (32 - (8)))) & 0x00FF00FF)) + 0x5A827999 + (((e) << (5)) | ((e) >> (32 - (5)))); a = (((a) << (30)) | ((a) >> (32 - (30))));;
	c += ((e & (a ^ b)) ^ b) + (block->l[12] = ((((block->l[12]) << (24)) | ((block->l[12]) >> (32 - (24)))) & 0xFF00FF00) | ((((block->l[12]) << (8)) | ((block->l[12]) >> (32 - (8)))) & 0x00FF00FF)) + 0x5A827999 + (((d) << (5)) | ((d) >> (32 - (5)))); e = (((e) << (30)) | ((e) >> (32 - (30))));; b += ((d & (e ^ a)) ^ a) + (block->l[13] = ((((block->l[13]) << (24)) | ((block->l[13]) >> (32 - (24)))) & 0xFF00FF00) | ((((block->l[13]) << (8)) | ((block->l[13]) >> (32 - (8)))) & 0x00FF00FF)) + 0x5A827999 + (((c) << (5)) | ((c) >> (32 - (5)))); d = (((d) << (30)) | ((d) >> (32 - (30))));; a += ((c & (d ^ e)) ^ e) + (block->l[14] = ((((block->l[14]) << (24)) | ((block->l[14]) >> (32 - (24)))) & 0xFF00FF00) | ((((block->l[14]) << (8)) | ((block->l[14]) >> (32 - (8)))) & 0x00FF00FF)) + 0x5A827999 + (((b) << (5)) | ((b) >> (32 - (5)))); c = (((c) << (30)) | ((c) >> (32 - (30))));; e += ((b & (c ^ d)) ^ d) + (block->l[15] = ((((block->l[15]) << (24)) | ((block->l[15]) >> (32 - (24)))) & 0xFF00FF00) | ((((block->l[15]) << (8)) | ((block->l[15]) >> (32 - (8)))) & 0x00FF00FF)) + 0x5A827999 + (((a) << (5)) | ((a) >> (32 - (5)))); b = (((b) << (30)) | ((b) >> (32 - (30))));;
	d += ((a & (b ^ c)) ^ c) + (block->l[16 & 15] = (((block->l[(16 + 13) & 15] ^ block->l[(16 + 8) & 15] ^ block->l[(16 + 2) & 15] ^ block->l[16 & 15]) << (1)) | ((block->l[(16 + 13) & 15] ^ block->l[(16 + 8) & 15] ^ block->l[(16 + 2) & 15] ^ block->l[16 & 15]) >> (32 - (1))))) + 0x5A827999 + (((e) << (5)) | ((e) >> (32 - (5)))); a = (((a) << (30)) | ((a) >> (32 - (30))));; c += ((e & (a ^ b)) ^ b) + (block->l[17 & 15] = (((block->l[(17 + 13) & 15] ^ block->l[(17 + 8) & 15] ^ block->l[(17 + 2) & 15] ^ block->l[17 & 15]) << (1)) | ((block->l[(17 + 13) & 15] ^ block->l[(17 + 8) & 15] ^ block->l[(17 + 2) & 15] ^ block->l[17 & 15]) >> (32 - (1))))) + 0x5A827999 + (((d) << (5)) | ((d) >> (32 - (5)))); e = (((e) << (30)) | ((e) >> (32 - (30))));; b += ((d & (e ^ a)) ^ a) + (block->l[18 & 15] = (((block->l[(18 + 13) & 15] ^ block->l[(18 + 8) & 15] ^ block->l[(18 + 2) & 15] ^ block->l[18 & 15]) << (1)) | ((block->l[(18 + 13) & 15] ^ block->l[(18 + 8) & 15] ^ block->l[(18 + 2) & 15] ^ block->l[18 & 15]) >> (32 - (1))))) + 0x5A827999 + (((c) << (5)) | ((c) >> (32 - (5)))); d = (((d) << (30)) | ((d) >> (32 - (30))));; a += ((c & (d ^ e)) ^ e) + (block->l[19 & 15] = (((block->l[(19 + 13) & 15] ^ block->l[(19 + 8) & 15] ^ block->l[(19 + 2) & 15] ^ block->l[19 & 15]) << (1)) | ((block->l[(19 + 13) & 15] ^ block->l[(19 + 8) & 15] ^ block->l[(19 + 2) & 15] ^ block->l[19 & 15]) >> (32 - (1))))) + 0x5A827999 + (((b) << (5)) | ((b) >> (32 - (5)))); c = (((c) << (30)) | ((c) >> (32 - (30))));;
	e += (b ^ c ^ d) + (block->l[20 & 15] = (((block->l[(20 + 13) & 15] ^ block->l[(20 + 8) & 15] ^ block->l[(20 + 2) & 15] ^ block->l[20 & 15]) << (1)) | ((block->l[(20 + 13) & 15] ^ block->l[(20 + 8) & 15] ^ block->l[(20 + 2) & 15] ^ block->l[20 & 15]) >> (32 - (1))))) + 0x6ED9EBA1 + (((a) << (5)) | ((a) >> (32 - (5)))); b = (((b) << (30)) | ((b) >> (32 - (30))));; d += (a ^ b ^ c) + (block->l[21 & 15] = (((block->l[(21 + 13) & 15] ^ block->l[(21 + 8) & 15] ^ block->l[(21 + 2) & 15] ^ block->l[21 & 15]) << (1)) | ((block->l[(21 + 13) & 15] ^ block->l[(21 + 8) & 15] ^ block->l[(21 + 2) & 15] ^ block->l[21 & 15]) >> (32 - (1))))) + 0x6ED9EBA1 + (((e) << (5)) | ((e) >> (32 - (5)))); a = (((a) << (30)) | ((a) >> (32 - (30))));; c += (e ^ a ^ b) + (block->l[22 & 15] = (((block->l[(22 + 13) & 15] ^ block->l[(22 + 8) & 15] ^ block->l[(22 + 2) & 15] ^ block->l[22 & 15]) << (1)) | ((block->l[(22 + 13) & 15] ^ block->l[(22 + 8) & 15] ^ block->l[(22 + 2) & 15] ^ block->l[22 & 15]) >> (32 - (1))))) + 0x6ED9EBA1 + (((d) << (5)) | ((d) >> (32 - (5)))); e = (((e) << (30)) | ((e) >> (32 - (30))));; b += (d ^ e ^ a) + (block->l[23 & 15] = (((block->l[(23 + 13) & 15] ^ block->l[(23 + 8) & 15] ^ block->l[(23 + 2) & 15] ^ block->l[23 & 15]) << (1)) | ((block->l[(23 + 13) & 15] ^ block->l[(23 + 8) & 15] ^ block->l[(23 + 2) & 15] ^ block->l[23 & 15]) >> (32 - (1))))) + 0x6ED9EBA1 + (((c) << (5)) | ((c) >> (32 - (5)))); d = (((d) << (30)) | ((d) >> (32 - (30))));;
	a += (c ^ d ^ e) + (block->l[24 & 15] = (((block->l[(24 + 13) & 15] ^ block->l[(24 + 8) & 15] ^ block->l[(24 + 2) & 15] ^ block->l[24 & 15]) << (1)) | ((block->l[(24 + 13) & 15] ^ block->l[(24 + 8) & 15] ^ block->l[(24 + 2) & 15] ^ block->l[24 & 15]) >> (32 - (1))))) + 0x6ED9EBA1 + (((b) << (5)) | ((b) >> (32 - (5)))); c = (((c) << (30)) | ((c) >> (32 - (30))));; e += (b ^ c ^ d) + (block->l[25 & 15] = (((block->l[(25 + 13) & 15] ^ block->l[(25 + 8) & 15] ^ block->l[(25 + 2) & 15] ^ block->l[25 & 15]) << (1)) | ((block->l[(25 + 13) & 15] ^ block->l[(25 + 8) & 15] ^ block->l[(25 + 2) & 15] ^ block->l[25 & 15]) >> (32 - (1))))) + 0x6ED9EBA1 + (((a) << (5)) | ((a) >> (32 - (5)))); b = (((b) << (30)) | ((b) >> (32 - (30))));; d += (a ^ b ^ c) + (block->l[26 & 15] = (((block->l[(26 + 13) & 15] ^ block->l[(26 + 8) & 15] ^ block->l[(26 + 2) & 15] ^ block->l[26 & 15]) << (1)) | ((block->l[(26 + 13) & 15] ^ block->l[(26 + 8) & 15] ^ block->l[(26 + 2) & 15] ^ block->l[26 & 15]) >> (32 - (1))))) + 0x6ED9EBA1 + (((e) << (5)) | ((e) >> (32 - (5)))); a = (((a) << (30)) | ((a) >> (32 - (30))));; c += (e ^ a ^ b) + (block->l[27 & 15] = (((block->l[(27 + 13) & 15] ^ block->l[(27 + 8) & 15] ^ block->l[(27 + 2) & 15] ^ block->l[27 & 15]) << (1)) | ((block->l[(27 + 13) & 15] ^ block->l[(27 + 8) & 15] ^ block->l[(27 + 2) & 15] ^ block->l[27 & 15]) >> (32 - (1))))) + 0x6ED9EBA1 + (((d) << (5)) | ((d) >> (32 - (5)))); e = (((e) << (30)) | ((e) >> (32 - (30))));;
	b += (d ^ e ^ a) + (block->l[28 & 15] = (((block->l[(28 + 13) & 15] ^ block->l[(28 + 8) & 15] ^ block->l[(28 + 2) & 15] ^ block->l[28 & 15]) << (1)) | ((block->l[(28 + 13) & 15] ^ block->l[(28 + 8) & 15] ^ block->l[(28 + 2) & 15] ^ block->l[28 & 15]) >> (32 - (1))))) + 0x6ED9EBA1 + (((c) << (5)) | ((c) >> (32 - (5)))); d = (((d) << (30)) | ((d) >> (32 - (30))));; a += (c ^ d ^ e) + (block->l[29 & 15] = (((block->l[(29 + 13) & 15] ^ block->l[(29 + 8) & 15] ^ block->l[(29 + 2) & 15] ^ block->l[29 & 15]) << (1)) | ((block->l[(29 + 13) & 15] ^ block->l[(29 + 8) & 15] ^ block->l[(29 + 2) & 15] ^ block->l[29 & 15]) >> (32 - (1))))) + 0x6ED9EBA1 + (((b) << (5)) | ((b) >> (32 - (5)))); c = (((c) << (30)) | ((c) >> (32 - (30))));; e += (b ^ c ^ d) + (block->l[30 & 15] = (((block->l[(30 + 13) & 15] ^ block->l[(30 + 8) & 15] ^ block->l[(30 + 2) & 15] ^ block->l[30 & 15]) << (1)) | ((block->l[(30 + 13) & 15] ^ block->l[(30 + 8) & 15] ^ block->l[(30 + 2) & 15] ^ block->l[30 & 15]) >> (32 - (1))))) + 0x6ED9EBA1 + (((a) << (5)) | ((a) >> (32 - (5)))); b = (((b) << (30)) | ((b) >> (32 - (30))));; d += (a ^ b ^ c) + (block->l[31 & 15] = (((block->l[(31 + 13) & 15] ^ block->l[(31 + 8) & 15] ^ block->l[(31 + 2) & 15] ^ block->l[31 & 15]) << (1)) | ((block->l[(31 + 13) & 15] ^ block->l[(31 + 8) & 15] ^ block->l[(31 + 2) & 15] ^ block->l[31 & 15]) >> (32 - (1))))) + 0x6ED9EBA1 + (((e) << (5)) | ((e) >> (32 - (5)))); a = (((a) << (30)) | ((a) >> (32 - (30))));;
	c += (e ^ a ^ b) + (block->l[32 & 15] = (((block->l[(32 + 13) & 15] ^ block->l[(32 + 8) & 15] ^ block->l[(32 + 2) & 15] ^ block->l[32 & 15]) << (1)) | ((block->l[(32 + 13) & 15] ^ block->l[(32 + 8) & 15] ^ block->l[(32 + 2) & 15] ^ block->l[32 & 15]) >> (32 - (1))))) + 0x6ED9EBA1 + (((d) << (5)) | ((d) >> (32 - (5)))); e = (((e) << (30)) | ((e) >> (32 - (30))));; b += (d ^ e ^ a) + (block->l[33 & 15] = (((block->l[(33 + 13) & 15] ^ block->l[(33 + 8) & 15] ^ block->l[(33 + 2) & 15] ^ block->l[33 & 15]) << (1)) | ((block->l[(33 + 13) & 15] ^ block->l[(33 + 8) & 15] ^ block->l[(33 + 2) & 15] ^ block->l[33 & 15]) >> (32 - (1))))) + 0x6ED9EBA1 + (((c) << (5)) | ((c) >> (32 - (5)))); d = (((d) << (30)) | ((d) >> (32 - (30))));; a += (c ^ d ^ e) + (block->l[34 & 15] = (((block->l[(34 + 13) & 15] ^ block->l[(34 + 8) & 15] ^ block->l[(34 + 2) & 15] ^ block->l[34 & 15]) << (1)) | ((block->l[(34 + 13) & 15] ^ block->l[(34 + 8) & 15] ^ block->l[(34 + 2) & 15] ^ block->l[34 & 15]) >> (32 - (1))))) + 0x6ED9EBA1 + (((b) << (5)) | ((b) >> (32 - (5)))); c = (((c) << (30)) | ((c) >> (32 - (30))));; e += (b ^ c ^ d) + (block->l[35 & 15] = (((block->l[(35 + 13) & 15] ^ block->l[(35 + 8) & 15] ^ block->l[(35 + 2) & 15] ^ block->l[35 & 15]) << (1)) | ((block->l[(35 + 13) & 15] ^ block->l[(35 + 8) & 15] ^ block->l[(35 + 2) & 15] ^ block->l[35 & 15]) >> (32 - (1))))) + 0x6ED9EBA1 + (((a) << (5)) | ((a) >> (32 - (5)))); b = (((b) << (30)) | ((b) >> (32 - (30))));;
	d += (a ^ b ^ c) + (block->l[36 & 15] = (((block->l[(36 + 13) & 15] ^ block->l[(36 + 8) & 15] ^ block->l[(36 + 2) & 15] ^ block->l[36 & 15]) << (1)) | ((block->l[(36 + 13) & 15] ^ block->l[(36 + 8) & 15] ^ block->l[(36 + 2) & 15] ^ block->l[36 & 15]) >> (32 - (1))))) + 0x6ED9EBA1 + (((e) << (5)) | ((e) >> (32 - (5)))); a = (((a) << (30)) | ((a) >> (32 - (30))));; c += (e ^ a ^ b) + (block->l[37 & 15] = (((block->l[(37 + 13) & 15] ^ block->l[(37 + 8) & 15] ^ block->l[(37 + 2) & 15] ^ block->l[37 & 15]) << (1)) | ((block->l[(37 + 13) & 15] ^ block->l[(37 + 8) & 15] ^ block->l[(37 + 2) & 15] ^ block->l[37 & 15]) >> (32 - (1))))) + 0x6ED9EBA1 + (((d) << (5)) | ((d) >> (32 - (5)))); e = (((e) << (30)) | ((e) >> (32 - (30))));; b += (d ^ e ^ a) + (block->l[38 & 15] = (((block->l[(38 + 13) & 15] ^ block->l[(38 + 8) & 15] ^ block->l[(38 + 2) & 15] ^ block->l[38 & 15]) << (1)) | ((block->l[(38 + 13) & 15] ^ block->l[(38 + 8) & 15] ^ block->l[(38 + 2) & 15] ^ block->l[38 & 15]) >> (32 - (1))))) + 0x6ED9EBA1 + (((c) << (5)) | ((c) >> (32 - (5)))); d = (((d) << (30)) | ((d) >> (32 - (30))));; a += (c ^ d ^ e) + (block->l[39 & 15] = (((block->l[(39 + 13) & 15] ^ block->l[(39 + 8) & 15] ^ block->l[(39 + 2) & 15] ^ block->l[39 & 15]) << (1)) | ((block->l[(39 + 13) & 15] ^ block->l[(39 + 8) & 15] ^ block->l[(39 + 2) & 15] ^ block->l[39 & 15]) >> (32 - (1))))) + 0x6ED9EBA1 + (((b) << (5)) | ((b) >> (32 - (5)))); c = (((c) << (30)) | ((c) >> (32 - (30))));;
	e += (((b | c) & d) | (b & c)) + (block->l[40 & 15] = (((block->l[(40 + 13) & 15] ^ block->l[(40 + 8) & 15] ^ block->l[(40 + 2) & 15] ^ block->l[40 & 15]) << (1)) | ((block->l[(40 + 13) & 15] ^ block->l[(40 + 8) & 15] ^ block->l[(40 + 2) & 15] ^ block->l[40 & 15]) >> (32 - (1))))) + 0x8F1BBCDC + (((a) << (5)) | ((a) >> (32 - (5)))); b = (((b) << (30)) | ((b) >> (32 - (30))));; d += (((a | b) & c) | (a & b)) + (block->l[41 & 15] = (((block->l[(41 + 13) & 15] ^ block->l[(41 + 8) & 15] ^ block->l[(41 + 2) & 15] ^ block->l[41 & 15]) << (1)) | ((block->l[(41 + 13) & 15] ^ block->l[(41 + 8) & 15] ^ block->l[(41 + 2) & 15] ^ block->l[41 & 15]) >> (32 - (1))))) + 0x8F1BBCDC + (((e) << (5)) | ((e) >> (32 - (5)))); a = (((a) << (30)) | ((a) >> (32 - (30))));; c += (((e | a) & b) | (e & a)) + (block->l[42 & 15] = (((block->l[(42 + 13) & 15] ^ block->l[(42 + 8) & 15] ^ block->l[(42 + 2) & 15] ^ block->l[42 & 15]) << (1)) | ((block->l[(42 + 13) & 15] ^ block->l[(42 + 8) & 15] ^ block->l[(42 + 2) & 15] ^ block->l[42 & 15]) >> (32 - (1))))) + 0x8F1BBCDC + (((d) << (5)) | ((d) >> (32 - (5)))); e = (((e) << (30)) | ((e) >> (32 - (30))));; b += (((d | e) & a) | (d & e)) + (block->l[43 & 15] = (((block->l[(43 + 13) & 15] ^ block->l[(43 + 8) & 15] ^ block->l[(43 + 2) & 15] ^ block->l[43 & 15]) << (1)) | ((block->l[(43 + 13) & 15] ^ block->l[(43 + 8) & 15] ^ block->l[(43 + 2) & 15] ^ block->l[43 & 15]) >> (32 - (1))))) + 0x8F1BBCDC + (((c) << (5)) | ((c) >> (32 - (5)))); d = (((d) << (30)) | ((d) >> (32 - (30))));;
	a += (((c | d) & e) | (c & d)) + (block->l[44 & 15] = (((block->l[(44 + 13) & 15] ^ block->l[(44 + 8) & 15] ^ block->l[(44 + 2) & 15] ^ block->l[44 & 15]) << (1)) | ((block->l[(44 + 13) & 15] ^ block->l[(44 + 8) & 15] ^ block->l[(44 + 2) & 15] ^ block->l[44 & 15]) >> (32 - (1))))) + 0x8F1BBCDC + (((b) << (5)) | ((b) >> (32 - (5)))); c = (((c) << (30)) | ((c) >> (32 - (30))));; e += (((b | c) & d) | (b & c)) + (block->l[45 & 15] = (((block->l[(45 + 13) & 15] ^ block->l[(45 + 8) & 15] ^ block->l[(45 + 2) & 15] ^ block->l[45 & 15]) << (1)) | ((block->l[(45 + 13) & 15] ^ block->l[(45 + 8) & 15] ^ block->l[(45 + 2) & 15] ^ block->l[45 & 15]) >> (32 - (1))))) + 0x8F1BBCDC + (((a) << (5)) | ((a) >> (32 - (5)))); b = (((b) << (30)) | ((b) >> (32 - (30))));; d += (((a | b) & c) | (a & b)) + (block->l[46 & 15] = (((block->l[(46 + 13) & 15] ^ block->l[(46 + 8) & 15] ^ block->l[(46 + 2) & 15] ^ block->l[46 & 15]) << (1)) | ((block->l[(46 + 13) & 15] ^ block->l[(46 + 8) & 15] ^ block->l[(46 + 2) & 15] ^ block->l[46 & 15]) >> (32 - (1))))) + 0x8F1BBCDC + (((e) << (5)) | ((e) >> (32 - (5)))); a = (((a) << (30)) | ((a) >> (32 - (30))));; c += (((e | a) & b) | (e & a)) + (block->l[47 & 15] = (((block->l[(47 + 13) & 15] ^ block->l[(47 + 8) & 15] ^ block->l[(47 + 2) & 15] ^ block->l[47 & 15]) << (1)) | ((block->l[(47 + 13) & 15] ^ block->l[(47 + 8) & 15] ^ block->l[(47 + 2) & 15] ^ block->l[47 & 15]) >> (32 - (1))))) + 0x8F1BBCDC + (((d) << (5)) | ((d) >> (32 - (5)))); e = (((e) << (30)) | ((e) >> (32 - (30))));;
	b += (((d | e) & a) | (d & e)) + (block->l[48 & 15] = (((block->l[(48 + 13) & 15] ^ block->l[(48 + 8) & 15] ^ block->l[(48 + 2) & 15] ^ block->l[48 & 15]) << (1)) | ((block->l[(48 + 13) & 15] ^ block->l[(48 + 8) & 15] ^ block->l[(48 + 2) & 15] ^ block->l[48 & 15]) >> (32 - (1))))) + 0x8F1BBCDC + (((c) << (5)) | ((c) >> (32 - (5)))); d = (((d) << (30)) | ((d) >> (32 - (30))));; a += (((c | d) & e) | (c & d)) + (block->l[49 & 15] = (((block->l[(49 + 13) & 15] ^ block->l[(49 + 8) & 15] ^ block->l[(49 + 2) & 15] ^ block->l[49 & 15]) << (1)) | ((block->l[(49 + 13) & 15] ^ block->l[(49 + 8) & 15] ^ block->l[(49 + 2) & 15] ^ block->l[49 & 15]) >> (32 - (1))))) + 0x8F1BBCDC + (((b) << (5)) | ((b) >> (32 - (5)))); c = (((c) << (30)) | ((c) >> (32 - (30))));; e += (((b | c) & d) | (b & c)) + (block->l[50 & 15] = (((block->l[(50 + 13) & 15] ^ block->l[(50 + 8) & 15] ^ block->l[(50 + 2) & 15] ^ block->l[50 & 15]) << (1)) | ((block->l[(50 + 13) & 15] ^ block->l[(50 + 8) & 15] ^ block->l[(50 + 2) & 15] ^ block->l[50 & 15]) >> (32 - (1))))) + 0x8F1BBCDC + (((a) << (5)) | ((a) >> (32 - (5)))); b = (((b) << (30)) | ((b) >> (32 - (30))));; d += (((a | b) & c) | (a & b)) + (block->l[51 & 15] = (((block->l[(51 + 13) & 15] ^ block->l[(51 + 8) & 15] ^ block->l[(51 + 2) & 15] ^ block->l[51 & 15]) << (1)) | ((block->l[(51 + 13) & 15] ^ block->l[(51 + 8) & 15] ^ block->l[(51 + 2) & 15] ^ block->l[51 & 15]) >> (32 - (1))))) + 0x8F1BBCDC + (((e) << (5)) | ((e) >> (32 - (5)))); a = (((a) << (30)) | ((a) >> (32 - (30))));;
	c += (((e | a) & b) | (e & a)) + (block->l[52 & 15] = (((block->l[(52 + 13) & 15] ^ block->l[(52 + 8) & 15] ^ block->l[(52 + 2) & 15] ^ block->l[52 & 15]) << (1)) | ((block->l[(52 + 13) & 15] ^ block->l[(52 + 8) & 15] ^ block->l[(52 + 2) & 15] ^ block->l[52 & 15]) >> (32 - (1))))) + 0x8F1BBCDC + (((d) << (5)) | ((d) >> (32 - (5)))); e = (((e) << (30)) | ((e) >> (32 - (30))));; b += (((d | e) & a) | (d & e)) + (block->l[53 & 15] = (((block->l[(53 + 13) & 15] ^ block->l[(53 + 8) & 15] ^ block->l[(53 + 2) & 15] ^ block->l[53 & 15]) << (1)) | ((block->l[(53 + 13) & 15] ^ block->l[(53 + 8) & 15] ^ block->l[(53 + 2) & 15] ^ block->l[53 & 15]) >> (32 - (1))))) + 0x8F1BBCDC + (((c) << (5)) | ((c) >> (32 - (5)))); d = (((d) << (30)) | ((d) >> (32 - (30))));; a += (((c | d) & e) | (c & d)) + (block->l[54 & 15] = (((block->l[(54 + 13) & 15] ^ block->l[(54 + 8) & 15] ^ block->l[(54 + 2) & 15] ^ block->l[54 & 15]) << (1)) | ((block->l[(54 + 13) & 15] ^ block->l[(54 + 8) & 15] ^ block->l[(54 + 2) & 15] ^ block->l[54 & 15]) >> (32 - (1))))) + 0x8F1BBCDC + (((b) << (5)) | ((b) >> (32 - (5)))); c = (((c) << (30)) | ((c) >> (32 - (30))));; e += (((b | c) & d) | (b & c)) + (block->l[55 & 15] = (((block->l[(55 + 13) & 15] ^ block->l[(55 + 8) & 15] ^ block->l[(55 + 2) & 15] ^ block->l[55 & 15]) << (1)) | ((block->l[(55 + 13) & 15] ^ block->l[(55 + 8) & 15] ^ block->l[(55 + 2) & 15] ^ block->l[55 & 15]) >> (32 - (1))))) + 0x8F1BBCDC + (((a) << (5)) | ((a) >> (32 - (5)))); b = (((b) << (30)) | ((b) >> (32 - (30))));;
	d += (((a | b) & c) | (a & b)) + (block->l[56 & 15] = (((block->l[(56 + 13) & 15] ^ block->l[(56 + 8) & 15] ^ block->l[(56 + 2) & 15] ^ block->l[56 & 15]) << (1)) | ((block->l[(56 + 13) & 15] ^ block->l[(56 + 8) & 15] ^ block->l[(56 + 2) & 15] ^ block->l[56 & 15]) >> (32 - (1))))) + 0x8F1BBCDC + (((e) << (5)) | ((e) >> (32 - (5)))); a = (((a) << (30)) | ((a) >> (32 - (30))));; c += (((e | a) & b) | (e & a)) + (block->l[57 & 15] = (((block->l[(57 + 13) & 15] ^ block->l[(57 + 8) & 15] ^ block->l[(57 + 2) & 15] ^ block->l[57 & 15]) << (1)) | ((block->l[(57 + 13) & 15] ^ block->l[(57 + 8) & 15] ^ block->l[(57 + 2) & 15] ^ block->l[57 & 15]) >> (32 - (1))))) + 0x8F1BBCDC + (((d) << (5)) | ((d) >> (32 - (5)))); e = (((e) << (30)) | ((e) >> (32 - (30))));; b += (((d | e) & a) | (d & e)) + (block->l[58 & 15] = (((block->l[(58 + 13) & 15] ^ block->l[(58 + 8) & 15] ^ block->l[(58 + 2) & 15] ^ block->l[58 & 15]) << (1)) | ((block->l[(58 + 13) & 15] ^ block->l[(58 + 8) & 15] ^ block->l[(58 + 2) & 15] ^ block->l[58 & 15]) >> (32 - (1))))) + 0x8F1BBCDC + (((c) << (5)) | ((c) >> (32 - (5)))); d = (((d) << (30)) | ((d) >> (32 - (30))));; a += (((c | d) & e) | (c & d)) + (block->l[59 & 15] = (((block->l[(59 + 13) & 15] ^ block->l[(59 + 8) & 15] ^ block->l[(59 + 2) & 15] ^ block->l[59 & 15]) << (1)) | ((block->l[(59 + 13) & 15] ^ block->l[(59 + 8) & 15] ^ block->l[(59 + 2) & 15] ^ block->l[59 & 15]) >> (32 - (1))))) + 0x8F1BBCDC + (((b) << (5)) | ((b) >> (32 - (5)))); c = (((c) << (30)) | ((c) >> (32 - (30))));;
	e += (b ^ c ^ d) + (block->l[60 & 15] = (((block->l[(60 + 13) & 15] ^ block->l[(60 + 8) & 15] ^ block->l[(60 + 2) & 15] ^ block->l[60 & 15]) << (1)) | ((block->l[(60 + 13) & 15] ^ block->l[(60 + 8) & 15] ^ block->l[(60 + 2) & 15] ^ block->l[60 & 15]) >> (32 - (1))))) + 0xCA62C1D6 + (((a) << (5)) | ((a) >> (32 - (5)))); b=(((b) << (30)) | ((b) >> (32 - (30))));; d += (a ^ b ^ c) + (block->l[61 & 15] = (((block->l[(61 + 13) & 15] ^ block->l[(61 + 8) & 15] ^ block->l[(61 + 2) & 15] ^ block->l[61 & 15]) << (1)) | ((block->l[(61 + 13) & 15] ^ block->l[(61 + 8) & 15] ^ block->l[(61 + 2) & 15] ^ block->l[61 & 15]) >> (32 - (1))))) + 0xCA62C1D6 + (((e) << (5)) | ((e) >> (32 - (5)))); a=(((a) << (30)) | ((a) >> (32 - (30))));; c += (e ^ a ^ b) + (block->l[62 & 15] = (((block->l[(62 + 13) & 15] ^ block->l[(62 + 8) & 15] ^ block->l[(62 + 2) & 15] ^ block->l[62 & 15]) << (1)) | ((block->l[(62 + 13) & 15] ^ block->l[(62 + 8) & 15] ^ block->l[(62 + 2) & 15] ^ block->l[62 & 15]) >> (32 - (1))))) + 0xCA62C1D6 + (((d) << (5)) | ((d) >> (32 - (5)))); e=(((e) << (30)) | ((e) >> (32 - (30))));; b += (d ^ e ^ a) + (block->l[63 & 15] = (((block->l[(63 + 13) & 15] ^ block->l[(63 + 8) & 15] ^ block->l[(63 + 2) & 15] ^ block->l[63 & 15]) << (1)) | ((block->l[(63 + 13) & 15] ^ block->l[(63 + 8) & 15] ^ block->l[(63 + 2) & 15] ^ block->l[63 & 15]) >> (32 - (1))))) + 0xCA62C1D6 + (((c) << (5)) | ((c) >> (32 - (5)))); d=(((d) << (30)) | ((d) >> (32 - (30))));;
	a += (c ^ d ^ e) + (block->l[64 & 15] = (((block->l[(64 + 13) & 15] ^ block->l[(64 + 8) & 15] ^ block->l[(64 + 2) & 15] ^ block->l[64 & 15]) << (1)) | ((block->l[(64 + 13) & 15] ^ block->l[(64 + 8) & 15] ^ block->l[(64 + 2) & 15] ^ block->l[64 & 15]) >> (32 - (1))))) + 0xCA62C1D6 + (((b) << (5)) | ((b) >> (32 - (5)))); c=(((c) << (30)) | ((c) >> (32 - (30))));; e += (b ^ c ^ d) + (block->l[65 & 15] = (((block->l[(65 + 13) & 15] ^ block->l[(65 + 8) & 15] ^ block->l[(65 + 2) & 15] ^ block->l[65 & 15]) << (1)) | ((block->l[(65 + 13) & 15] ^ block->l[(65 + 8) & 15] ^ block->l[(65 + 2) & 15] ^ block->l[65 & 15]) >> (32 - (1))))) + 0xCA62C1D6 + (((a) << (5)) | ((a) >> (32 - (5)))); b=(((b) << (30)) | ((b) >> (32 - (30))));; d += (a ^ b ^ c) + (block->l[66 & 15] = (((block->l[(66 + 13) & 15] ^ block->l[(66 + 8) & 15] ^ block->l[(66 + 2) & 15] ^ block->l[66 & 15]) << (1)) | ((block->l[(66 + 13) & 15] ^ block->l[(66 + 8) & 15] ^ block->l[(66 + 2) & 15] ^ block->l[66 & 15]) >> (32 - (1))))) + 0xCA62C1D6 + (((e) << (5)) | ((e) >> (32 - (5)))); a=(((a) << (30)) | ((a) >> (32 - (30))));; c += (e ^ a ^ b) + (block->l[67 & 15] = (((block->l[(67 + 13) & 15] ^ block->l[(67 + 8) & 15] ^ block->l[(67 + 2) & 15] ^ block->l[67 & 15]) << (1)) | ((block->l[(67 + 13) & 15] ^ block->l[(67 + 8) & 15] ^ block->l[(67 + 2) & 15] ^ block->l[67 & 15]) >> (32 - (1))))) + 0xCA62C1D6 + (((d) << (5)) | ((d) >> (32 - (5)))); e=(((e) << (30)) | ((e) >> (32 - (30))));;
	b += (d ^ e ^ a) + (block->l[68 & 15] = (((block->l[(68 + 13) & 15] ^ block->l[(68 + 8) & 15] ^ block->l[(68 + 2) & 15] ^ block->l[68 & 15]) << (1)) | ((block->l[(68 + 13) & 15] ^ block->l[(68 + 8) & 15] ^ block->l[(68 + 2) & 15] ^ block->l[68 & 15]) >> (32 - (1))))) + 0xCA62C1D6 + (((c) << (5)) | ((c) >> (32 - (5)))); d=(((d) << (30)) | ((d) >> (32 - (30))));; a += (c ^ d ^ e) + (block->l[69 & 15] = (((block->l[(69 + 13) & 15] ^ block->l[(69 + 8) & 15] ^ block->l[(69 + 2) & 15] ^ block->l[69 & 15]) << (1)) | ((block->l[(69 + 13) & 15] ^ block->l[(69 + 8) & 15] ^ block->l[(69 + 2) & 15] ^ block->l[69 & 15]) >> (32 - (1))))) + 0xCA62C1D6 + (((b) << (5)) | ((b) >> (32 - (5)))); c=(((c) << (30)) | ((c) >> (32 - (30))));; e += (b ^ c ^ d) + (block->l[70 & 15] = (((block->l[(70 + 13) & 15] ^ block->l[(70 + 8) & 15] ^ block->l[(70 + 2) & 15] ^ block->l[70 & 15]) << (1)) | ((block->l[(70 + 13) & 15] ^ block->l[(70 + 8) & 15] ^ block->l[(70 + 2) & 15] ^ block->l[70 & 15]) >> (32 - (1))))) + 0xCA62C1D6 + (((a) << (5)) | ((a) >> (32 - (5)))); b=(((b) << (30)) | ((b) >> (32 - (30))));; d += (a ^ b ^ c) + (block->l[71 & 15] = (((block->l[(71 + 13) & 15] ^ block->l[(71 + 8) & 15] ^ block->l[(71 + 2) & 15] ^ block->l[71 & 15]) << (1)) | ((block->l[(71 + 13) & 15] ^ block->l[(71 + 8) & 15] ^ block->l[(71 + 2) & 15] ^ block->l[71 & 15]) >> (32 - (1))))) + 0xCA62C1D6 + (((e) << (5)) | ((e) >> (32 - (5)))); a=(((a) << (30)) | ((a) >> (32 - (30))));;
	c += (e ^ a ^ b) + (block->l[72 & 15] = (((block->l[(72 + 13) & 15] ^ block->l[(72 + 8) & 15] ^ block->l[(72 + 2) & 15] ^ block->l[72 & 15]) << (1)) | ((block->l[(72 + 13) & 15] ^ block->l[(72 + 8) & 15] ^ block->l[(72 + 2) & 15] ^ block->l[72 & 15]) >> (32 - (1))))) + 0xCA62C1D6 + (((d) << (5)) | ((d) >> (32 - (5)))); e=(((e) << (30)) | ((e) >> (32 - (30))));; b += (d ^ e ^ a) + (block->l[73 & 15] = (((block->l[(73 + 13) & 15] ^ block->l[(73 + 8) & 15] ^ block->l[(73 + 2) & 15] ^ block->l[73 & 15]) << (1)) | ((block->l[(73 + 13) & 15] ^ block->l[(73 + 8) & 15] ^ block->l[(73 + 2) & 15] ^ block->l[73 & 15]) >> (32 - (1))))) + 0xCA62C1D6 + (((c) << (5)) | ((c) >> (32 - (5)))); d=(((d) << (30)) | ((d) >> (32 - (30))));; a += (c ^ d ^ e) + (block->l[74 & 15] = (((block->l[(74 + 13) & 15] ^ block->l[(74 + 8) & 15] ^ block->l[(74 + 2) & 15] ^ block->l[74 & 15]) << (1)) | ((block->l[(74 + 13) & 15] ^ block->l[(74 + 8) & 15] ^ block->l[(74 + 2) & 15] ^ block->l[74 & 15]) >> (32 - (1))))) + 0xCA62C1D6 + (((b) << (5)) | ((b) >> (32 - (5)))); c=(((c) << (30)) | ((c) >> (32 - (30))));; e += (b ^ c ^ d) + (block->l[75 & 15] = (((block->l[(75 + 13) & 15] ^ block->l[(75 + 8) & 15] ^ block->l[(75 + 2) & 15] ^ block->l[75 & 15]) << (1)) | ((block->l[(75 + 13) & 15] ^ block->l[(75 + 8) & 15] ^ block->l[(75 + 2) & 15] ^ block->l[75 & 15]) >> (32 - (1))))) + 0xCA62C1D6 + (((a) << (5)) | ((a) >> (32 - (5)))); b=(((b) << (30)) | ((b) >> (32 - (30))));;
	d += (a ^ b ^ c) + (block->l[76 & 15] = (((block->l[(76 + 13) & 15] ^ block->l[(76 + 8) & 15] ^ block->l[(76 + 2) & 15] ^ block->l[76 & 15]) << (1)) | ((block->l[(76 + 13) & 15] ^ block->l[(76 + 8) & 15] ^ block->l[(76 + 2) & 15] ^ block->l[76 & 15]) >> (32 - (1))))) + 0xCA62C1D6 + (((e) << (5)) | ((e) >> (32 - (5)))); a=(((a) << (30)) | ((a) >> (32 - (30))));; c += (e ^ a ^ b) + (block->l[77 & 15] = (((block->l[(77 + 13) & 15] ^ block->l[(77 + 8) & 15] ^ block->l[(77 + 2) & 15] ^ block->l[77 & 15]) << (1)) | ((block->l[(77 + 13) & 15] ^ block->l[(77 + 8) & 15] ^ block->l[(77 + 2) & 15] ^ block->l[77 & 15]) >> (32 - (1))))) + 0xCA62C1D6 + (((d) << (5)) | ((d) >> (32 - (5)))); e=(((e) << (30)) | ((e) >> (32 - (30))));; b += (d ^ e ^ a) + (block->l[78 & 15] = (((block->l[(78 + 13) & 15] ^ block->l[(78 + 8) & 15] ^ block->l[(78 + 2) & 15] ^ block->l[78 & 15]) << (1)) | ((block->l[(78 + 13) & 15] ^ block->l[(78 + 8) & 15] ^ block->l[(78 + 2) & 15] ^ block->l[78 & 15]) >> (32 - (1))))) + 0xCA62C1D6 + (((c) << (5)) | ((c) >> (32 - (5)))); d=(((d) << (30)) | ((d) >> (32 - (30))));; a += (c ^ d ^ e) + (block->l[79 & 15] = (((block->l[(79 + 13) & 15] ^ block->l[(79 + 8) & 15] ^ block->l[(79 + 2) & 15] ^ block->l[79 & 15]) << (1)) | ((block->l[(79 + 13) & 15] ^ block->l[(79 + 8) & 15] ^ block->l[(79 + 2) & 15] ^ block->l[79 & 15]) >> (32 - (1))))) + 0xCA62C1D6 + (((b) << (5)) | ((b) >> (32 - (5)))); c=(((c) << (30)) | ((c) >> (32 - (30))));;
	 
	state[0] += a;
	state[1] += b;
	state[2] += c;
	state[3] += d;
	state[4] += e;
	 
	a = b = c = d = e = 0;

	os_memset(block, 0, 64);

}


 

void SHA1Init(SHA1_CTX* context)
{
	 
	context->state[0] = 0x67452301;
	context->state[1] = 0xEFCDAB89;
	context->state[2] = 0x98BADCFE;
	context->state[3] = 0x10325476;
	context->state[4] = 0xC3D2E1F0;
	context->count[0] = context->count[1] = 0;
}


 

void SHA1Update(SHA1_CTX* context, const void *_data, unsigned int len)
{
	unsigned int i, j;
	const unsigned char *data = _data;




	j = (context->count[0] >> 3) & 63;
	if ((context->count[0] += len << 3) < (len << 3))
		context->count[1]++;
	context->count[1] += (len >> 29);
	if ((j + len) > 63) {
		os_memcpy(&context->buffer[j], data, (i = 64-j));
		SHA1Transform(context->state, context->buffer);
		for ( ; i + 63 < len; i += 64) {
			SHA1Transform(context->state, &data[i]);
		}
		j = 0;
	}
	else i = 0;
	os_memcpy(&context->buffer[j], &data[i], len - i);



}


 

void SHA1Final(unsigned char digest[20], SHA1_CTX* context)
{
	unsigned int i;
	unsigned char finalcount[8];

	for (i = 0; i < 8; i++) {
		finalcount[i] = (unsigned char)
			((context->count[(i >= 4 ? 0 : 1)] >>
			  ((3-(i & 3)) * 8) ) & 255);   
	}
	SHA1Update(context, (unsigned char *) "\200", 1);
	while ((context->count[0] & 504) != 448) {
		SHA1Update(context, (unsigned char *) "\0", 1);
	}
	SHA1Update(context, finalcount, 8);  
 
	for (i = 0; i < 20; i++) {
		digest[i] = (unsigned char)
			((context->state[i >> 2] >> ((3 - (i & 3)) * 8)) &
			 255);
	}
	 
	i = 0;
	os_memset(context->buffer, 0, 64);
	os_memset(context->state, 0, 20);
	os_memset(context->count, 0, 8);
	os_memset(finalcount, 0, 8);
}

 
