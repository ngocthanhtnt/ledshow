#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common\\ikev2_common.c"












 

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

#line 16 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common\\ikev2_common.c"

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



#line 18 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common\\ikev2_common.c"
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

#line 19 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common\\ikev2_common.c"
#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\crypto/md5.h"












 






int hmac_md5_vector(const unsigned char *key, size_t key_len, size_t num_elem,
		    const unsigned char *addr[], const size_t *len, unsigned char *mac);
int hmac_md5(const unsigned char *key, size_t key_len, const unsigned char *data, size_t data_len,
	     unsigned char *mac);
#line 34 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\crypto/md5.h"

#line 20 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common\\ikev2_common.c"
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
#line 21 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common\\ikev2_common.c"
#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common\\ikev2_common.h"












 







 



 






struct ikev2_hdr {
	unsigned char i_spi[8];  
	unsigned char r_spi[8];  
	unsigned char next_payload;
	unsigned char version;  
	unsigned char exchange_type;
	unsigned char flags;
	unsigned char message_id[4];
	unsigned char length[4];  
} ;

struct ikev2_payload_hdr {
	unsigned char next_payload;
	unsigned char flags;
	unsigned char payload_length[2];  
} ;

struct ikev2_proposal {
	unsigned char type;  
	unsigned char reserved;
	unsigned char proposal_length[2];  
	unsigned char proposal_num;
	unsigned char protocol_id;  
	unsigned char spi_size;
	unsigned char num_transforms;
	 
	 
} ;

struct ikev2_transform {
	unsigned char type;  
	unsigned char reserved;
	unsigned char transform_length[2];  
	unsigned char transform_type;
	unsigned char reserved2;
	unsigned char transform_id[2];
	 
} ;






 
#line 84 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common\\ikev2_common.h"

 
enum {
	 
	IKE_SA_INIT = 34,
	IKE_SA_AUTH = 35,
	CREATE_CHILD_SA = 36,
	INFORMATION = 37
	 
	 
};

 




 




 
enum {
	IKEV2_PAYLOAD_NO_NEXT_PAYLOAD = 0,
	IKEV2_PAYLOAD_SA = 33,
	IKEV2_PAYLOAD_KEY_EXCHANGE = 34,
	IKEV2_PAYLOAD_IDi = 35,
	IKEV2_PAYLOAD_IDr = 36,
	IKEV2_PAYLOAD_CERTIFICATE = 37,
	IKEV2_PAYLOAD_CERT_REQ = 38,
	IKEV2_PAYLOAD_AUTHENTICATION = 39,
	IKEV2_PAYLOAD_NONCE = 40,
	IKEV2_PAYLOAD_NOTIFICATION = 41,
	IKEV2_PAYLOAD_VENDOD_ID = 43,
	IKEV2_PAYLOAD_ENCRYPTED = 46,
	IKEV2_PAYLOAD_NEXT_FAST_ID = 121
};


 
enum {
	IKEV2_PROTOCOL_RESERVED = 0,
	IKEV2_PROTOCOL_IKE = 1,  
	IKEV2_PROTOCOL_AH = 2,
	IKEV2_PROTOCOL_ESP = 3
};


 
enum {
	IKEV2_TRANSFORM_ENCR = 1,
	IKEV2_TRANSFORM_PRF = 2,
	IKEV2_TRANSFORM_INTEG = 3,
	IKEV2_TRANSFORM_DH = 4,
	IKEV2_TRANSFORM_ESN = 5
};

 
enum {
	ENCR_DES_IV64 = 1,
	ENCR_DES = 2,
	ENCR_3DES = 3,
	ENCR_RC5 = 4,
	ENCR_IDEA = 5,
	ENCR_CAST = 6,
	ENCR_BLOWFISH = 7,
	ENCR_3IDEA = 8,
	ENCR_DES_IV32 = 9,
	ENCR_NULL = 11,
	ENCR_AES_CBC = 12,
	ENCR_AES_CTR = 13
};

 
enum {
	PRF_HMAC_MD5 = 1,
	PRF_HMAC_SHA1 = 2,
	PRF_HMAC_TIGER = 3,
	PRF_AES128_XCBC = 4
};

 
enum {
	AUTH_HMAC_MD5_96 = 1,
	AUTH_HMAC_SHA1_96 = 2,
	AUTH_DES_MAC = 3,
	AUTH_KPDK_MD5 = 4,
	AUTH_AES_XCBC_96 = 5
};

 
enum {
	DH_GROUP1_768BIT_MODP = 1,  
	DH_GROUP2_1024BIT_MODP = 2,  
	DH_GROUP5_1536BIT_MODP = 5,  
	DH_GROUP5_2048BIT_MODP = 14,  
	DH_GROUP5_3072BIT_MODP = 15,  
	DH_GROUP5_4096BIT_MODP = 16,  
	DH_GROUP5_6144BIT_MODP = 17,  
	DH_GROUP5_8192BIT_MODP = 18  
};


 
enum {
	ID_IPV4_ADDR = 1,
	ID_FQDN = 2,
	ID_RFC822_ADDR = 3,
	ID_IPV6_ADDR = 5,
	ID_DER_ASN1_DN = 9,
	ID_DER_ASN1_GN= 10,
	ID_KEY_ID = 11
};


 
enum {
	CERT_ENCODING_PKCS7_X509 = 1,
	CERT_ENCODING_PGP_CERT = 2,
	CERT_ENCODING_DNS_SIGNED_KEY = 3,
	
 
	CERT_ENCODING_X509_CERT_SIGN = 4,
	CERT_ENCODING_KERBEROS_TOKEN = 6,
	 
	CERT_ENCODING_CRL = 7,
	CERT_ENCODING_ARL = 8,
	CERT_ENCODING_SPKI_CERT = 9,
	CERT_ENCODING_X509_CERT_ATTR = 10,
	 
	CERT_ENCODING_RAW_RSA_KEY = 11,
	CERT_ENCODING_HASH_AND_URL_X509_CERT = 12,
	CERT_ENCODING_HASH_AND_URL_X509_BUNDLE = 13
};


 
enum {
	AUTH_RSA_SIGN = 1,
	AUTH_SHARED_KEY_MIC = 2,
	AUTH_DSS_SIGN = 3
};


 
enum {
	UNSUPPORTED_CRITICAL_PAYLOAD = 1,
	INVALID_IKE_SPI = 4,
	INVALID_MAJOR_VERSION = 5,
	INVALID_SYNTAX = 7,
	INVALID_MESSAGE_ID = 9,
	INVALID_SPI = 11,
	NO_PROPOSAL_CHOSEN = 14,
	INVALID_KE_PAYLOAD = 17,
	AUTHENTICATION_FAILED = 24,
	SINGLE_PAIR_REQUIRED = 34,
	NO_ADDITIONAL_SAS = 35,
	INTERNAL_ADDRESS_FAILURE = 36,
	FAILED_CP_REQUIRED = 37,
	TS_UNACCEPTABLE = 38,
	INVALID_SELECTORS = 39
};


struct ikev2_keys {
	unsigned char *SK_d, *SK_ai, *SK_ar, *SK_ei, *SK_er, *SK_pi, *SK_pr;
	size_t SK_d_len, SK_integ_len, SK_encr_len, SK_prf_len;
};


int ikev2_keys_set(struct ikev2_keys *keys);
void ikev2_free_keys(struct ikev2_keys *keys);


 


struct ikev2_integ_alg {
	int id;
	size_t key_len;
	size_t hash_len;
};

struct ikev2_prf_alg {
	int id;
	size_t key_len;
	size_t hash_len;
};

struct ikev2_encr_alg {
	int id;
	size_t key_len;
	size_t block_size;
};

const struct ikev2_integ_alg * ikev2_get_integ(int id);
int ikev2_integ_hash(int alg, const unsigned char *key, size_t key_len, const unsigned char *data,
		     size_t data_len, unsigned char *hash);
const struct ikev2_prf_alg * ikev2_get_prf(int id);
int ikev2_prf_hash(int alg, const unsigned char *key, size_t key_len,
		   size_t num_elem, const unsigned char *addr[], const size_t *len,
		   unsigned char *hash);
int ikev2_prf_plus(int alg, const unsigned char *key, size_t key_len,
		   const unsigned char *data, size_t data_len,
		   unsigned char *out, size_t out_len);
const struct ikev2_encr_alg * ikev2_get_encr(int id);
int ikev2_encr_encrypt(int alg, const unsigned char *key, size_t key_len, const unsigned char *iv,
		       const unsigned char *plain, unsigned char *crypt, size_t len);
int ikev2_encr_decrypt(int alg, const unsigned char *key, size_t key_len, const unsigned char *iv,
		       const unsigned char *crypt, unsigned char *plain, size_t len);

int ikev2_derive_auth_data(int prf_alg, const struct wpabuf *sign_msg,
			   const unsigned char *ID, size_t ID_len, unsigned char ID_type,
			   struct ikev2_keys *keys, int initiator,
			   const unsigned char *shared_secret, size_t shared_secret_len,
			   const unsigned char *nonce, size_t nonce_len,
			   const unsigned char *key_pad, size_t key_pad_len,
			   unsigned char *auth_data);


struct ikev2_payloads {
	const unsigned char *sa;
	size_t sa_len;
	const unsigned char *ke;
	size_t ke_len;
	const unsigned char *idi;
	size_t idi_len;
	const unsigned char *idr;
	size_t idr_len;
	const unsigned char *cert;
	size_t cert_len;
	const unsigned char *auth;
	size_t auth_len;
	const unsigned char *nonce;
	size_t nonce_len;
	const unsigned char *encrypted;
	size_t encrypted_len;
	unsigned char encr_next_payload;
	const unsigned char *notification;
	size_t notification_len;
};

int ikev2_parse_payloads(struct ikev2_payloads *payloads,
			 unsigned char next_payload, const unsigned char *pos, const unsigned char *end);

unsigned char * ikev2_decrypt_payload(int encr_id, int integ_id, struct ikev2_keys *keys,
			   int initiator, const struct ikev2_hdr *hdr,
			   const unsigned char *encrypted, size_t encrypted_len,
			   size_t *res_len);
void ikev2_update_hdr(struct wpabuf *msg);
int ikev2_build_encrypted(int encr_id, int integ_id, struct ikev2_keys *keys,
			  int initiator, struct wpabuf *msg,
			  struct wpabuf *plain, unsigned char next_payload);
int ikev2_derive_sk_keys(const struct ikev2_prf_alg *prf,
			 const struct ikev2_integ_alg *integ,
			 const struct ikev2_encr_alg *encr,
			 const unsigned char *skeyseed, const unsigned char *data, size_t data_len,
			 struct ikev2_keys *keys);

#line 22 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common\\ikev2_common.c"


static struct ikev2_integ_alg ikev2_integ_algs[] = {
	{ AUTH_HMAC_SHA1_96, 20, 12 },
	{ AUTH_HMAC_MD5_96, 16, 12 }
};




static struct ikev2_prf_alg ikev2_prf_algs[] = {
	{ PRF_HMAC_SHA1, 20, 20 },
	{ PRF_HMAC_MD5, 16, 16 }
};




static struct ikev2_encr_alg ikev2_encr_algs[] = {
	{ ENCR_AES_CBC, 16, 16 },  
	{ ENCR_3DES, 24, 8 }
};




const struct ikev2_integ_alg * ikev2_get_integ(int id)
{
	size_t i;

	for (i = 0; i < (sizeof(ikev2_integ_algs) / sizeof(ikev2_integ_algs[0])); i++) {
		if (ikev2_integ_algs[i].id == id)
			return &ikev2_integ_algs[i];
	}

	return 0;
}


int ikev2_integ_hash(int alg, const unsigned char *key, size_t key_len, const unsigned char *data,
		     size_t data_len, unsigned char *hash)
{
	unsigned char tmphash[20];

	switch (alg) {
	case AUTH_HMAC_SHA1_96:
		if (key_len != 20)
			return -1;
		hmac_sha1(key, key_len, data, data_len, tmphash);
		os_memcpy(hash, tmphash, 12);
		break;
	case AUTH_HMAC_MD5_96:
		if (key_len != 16)
			return -1;
		hmac_md5(key, key_len, data, data_len, tmphash);
		os_memcpy(hash, tmphash, 12);
		break;
	default:
		return -1;
	}

	return 0;
}


const struct ikev2_prf_alg * ikev2_get_prf(int id)
{
	size_t i;

	for (i = 0; i < (sizeof(ikev2_prf_algs) / sizeof(ikev2_prf_algs[0])); i++) {
		if (ikev2_prf_algs[i].id == id)
			return &ikev2_prf_algs[i];
	}

	return 0;
}


int ikev2_prf_hash(int alg, const unsigned char *key, size_t key_len,
		   size_t num_elem, const unsigned char *addr[], const size_t *len,
		   unsigned char *hash)
{
	switch (alg) {
	case PRF_HMAC_SHA1:
		hmac_sha1_vector(key, key_len, num_elem, addr, len, hash);
		break;
	case PRF_HMAC_MD5:
		hmac_md5_vector(key, key_len, num_elem, addr, len, hash);
		break;
	default:
		return -1;
	}

	return 0;
}


int ikev2_prf_plus(int alg, const unsigned char *key, size_t key_len,
		   const unsigned char *data, size_t data_len,
		   unsigned char *out, size_t out_len)
{
	unsigned char hash[20];
	size_t hash_len;
	unsigned char iter, *pos, *end;
	const unsigned char *addr[3];
	size_t len[3];
	const struct ikev2_prf_alg *prf;
	int res;

	prf = ikev2_get_prf(alg);
	if (prf == 0)
		return -1;
	hash_len = prf->hash_len;

	addr[0] = hash;
	len[0] = hash_len;
	addr[1] = data;
	len[1] = data_len;
	addr[2] = &iter;
	len[2] = 1;

	pos = out;
	end = out + out_len;
	iter = 1;
	while (pos < end) {
		size_t clen;
		if (iter == 1)
			res = ikev2_prf_hash(alg, key, key_len, 2, &addr[1],
					     &len[1], hash);
		else
			res = ikev2_prf_hash(alg, key, key_len, 3, addr, len,
					     hash);
		if (res < 0)
			return -1;
		clen = hash_len;
		if ((int) clen > end - pos)
			clen = end - pos;
		os_memcpy(pos, hash, clen);
		pos += clen;
		iter++;
	}

	return 0;
}


const struct ikev2_encr_alg * ikev2_get_encr(int id)
{
	size_t i;

	for (i = 0; i < (sizeof(ikev2_encr_algs) / sizeof(ikev2_encr_algs[0])); i++) {
		if (ikev2_encr_algs[i].id == id)
			return &ikev2_encr_algs[i];
	}

	return 0;
}


#line 192 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common\\ikev2_common.c"


int ikev2_encr_encrypt(int alg, const unsigned char *key, size_t key_len, const unsigned char *iv,
		       const unsigned char *plain, unsigned char *crypt, size_t len)
{
	struct crypto_cipher *cipher;
	int encr_alg;

#line 221 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common\\ikev2_common.c"
	switch (alg) {
	case ENCR_3DES:
		encr_alg = CRYPTO_CIPHER_ALG_3DES;
		break;
	case ENCR_AES_CBC:
		encr_alg = CRYPTO_CIPHER_ALG_AES;
		break;
	default:
		wpa_printf(0, "IKEV2: Unsupported encr alg %d", alg);
		return -1;
	}

	cipher = crypto_cipher_init(encr_alg, iv, key, key_len);
	if (cipher == 0) {
		wpa_printf(0, "IKEV2: Failed to initialize cipher");
		return -1;
	}

	if (crypto_cipher_encrypt(cipher, plain, crypt, len) < 0) {
		wpa_printf(0, "IKEV2: Encryption failed");
		crypto_cipher_deinit(cipher);
		return -1;
	}
	crypto_cipher_deinit(cipher);




	return 0;
}


int ikev2_encr_decrypt(int alg, const unsigned char *key, size_t key_len, const unsigned char *iv,
		       const unsigned char *crypt, unsigned char *plain, size_t len)
{
	struct crypto_cipher *cipher;
	int encr_alg;

#line 284 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common\\ikev2_common.c"
	switch (alg) {
	case ENCR_3DES:
		encr_alg = CRYPTO_CIPHER_ALG_3DES;
		break;
	case ENCR_AES_CBC:
		encr_alg = CRYPTO_CIPHER_ALG_AES;
		break;
	default:
		wpa_printf(0, "IKEV2: Unsupported encr alg %d", alg);
		return -1;
	}

	cipher = crypto_cipher_init(encr_alg, iv, key, key_len);
	if (cipher == 0) {
		wpa_printf(0, "IKEV2: Failed to initialize cipher");
		return -1;
	}

	if (crypto_cipher_decrypt(cipher, crypt, plain, len) < 0) {
		wpa_printf(0, "IKEV2: Decryption failed");
		crypto_cipher_deinit(cipher);
		return -1;
	}
	crypto_cipher_deinit(cipher);




	return 0;
}


int ikev2_parse_payloads(struct ikev2_payloads *payloads,
			 unsigned char next_payload, const unsigned char *pos, const unsigned char *end)
{
	const struct ikev2_payload_hdr *phdr;

	os_memset(payloads, 0, sizeof(*payloads));

	while (next_payload != IKEV2_PAYLOAD_NO_NEXT_PAYLOAD) {
		int plen, pdatalen;
		const unsigned char *pdata;
		wpa_printf(0, "IKEV2: Processing payload %u",
			   next_payload);
		if (end - pos < (int) sizeof(*phdr)) {
			wpa_printf(0, "IKEV2:   Too short message for "
				   "payload header (left=%ld)",
				   (long) (end - pos));
		}
		phdr = (const struct ikev2_payload_hdr *) pos;
		plen = ((unsigned short) (((phdr->payload_length)[0] << 8) | (phdr->payload_length)[1]));
		if (plen < (int) sizeof(*phdr) || pos + plen > end) {
			wpa_printf(0, "IKEV2:   Invalid payload header "
				   "length %d", plen);
			return -1;
		}

		wpa_printf(0, "IKEV2:   Next Payload: %u  Flags: 0x%x"
			   "  Payload Length: %d",
			   phdr->next_payload, phdr->flags, plen);

		pdata = (const unsigned char *) (phdr + 1);
		pdatalen = plen - sizeof(*phdr);

		switch (next_payload) {
		case IKEV2_PAYLOAD_SA:
			wpa_printf(0, "IKEV2:   Payload: Security "
				   "Association");
			payloads->sa = pdata;
			payloads->sa_len = pdatalen;
			break;
		case IKEV2_PAYLOAD_KEY_EXCHANGE:
			wpa_printf(0, "IKEV2:   Payload: Key "
				   "Exchange");
			payloads->ke = pdata;
			payloads->ke_len = pdatalen;
			break;
		case IKEV2_PAYLOAD_IDi:
			wpa_printf(0, "IKEV2:   Payload: IDi");
			payloads->idi = pdata;
			payloads->idi_len = pdatalen;
			break;
		case IKEV2_PAYLOAD_IDr:
			wpa_printf(0, "IKEV2:   Payload: IDr");
			payloads->idr = pdata;
			payloads->idr_len = pdatalen;
			break;
		case IKEV2_PAYLOAD_CERTIFICATE:
			wpa_printf(0, "IKEV2:   Payload: Certificate");
			payloads->cert = pdata;
			payloads->cert_len = pdatalen;
			break;
		case IKEV2_PAYLOAD_AUTHENTICATION:
			wpa_printf(0, "IKEV2:   Payload: "
				   "Authentication");
			payloads->auth = pdata;
			payloads->auth_len = pdatalen;
			break;
		case IKEV2_PAYLOAD_NONCE:
			wpa_printf(0, "IKEV2:   Payload: Nonce");
			payloads->nonce = pdata;
			payloads->nonce_len = pdatalen;
			break;
		case IKEV2_PAYLOAD_ENCRYPTED:
			wpa_printf(0, "IKEV2:   Payload: Encrypted");
			payloads->encrypted = pdata;
			payloads->encrypted_len = pdatalen;
			break;
		case IKEV2_PAYLOAD_NOTIFICATION:
			wpa_printf(0, "IKEV2:   Payload: "
				   "Notification");
			payloads->notification = pdata;
			payloads->notification_len = pdatalen;
			break;
		default:
			if (phdr->flags & 0x01) {
				wpa_printf(0, "IKEV2:   Unsupported "
					   "critical payload %u - reject the "
					   "entire message", next_payload);
				return -1;
			} else {
				wpa_printf(0, "IKEV2:   Skipped "
					   "unsupported payload %u",
					   next_payload);
			}
		}

		if (next_payload == IKEV2_PAYLOAD_ENCRYPTED &&
		    pos + plen == end) {
			



 
			payloads->encr_next_payload = phdr->next_payload;
			next_payload = IKEV2_PAYLOAD_NO_NEXT_PAYLOAD;
		} else
			next_payload = phdr->next_payload;

		pos += plen;
	}

	if (pos != end) {
		wpa_printf(0, "IKEV2: Unexpected extra data after "
			   "payloads");
		return -1;
	}

	return 0;
}


int ikev2_derive_auth_data(int prf_alg, const struct wpabuf *sign_msg,
			   const unsigned char *ID, size_t ID_len, unsigned char ID_type,
			   struct ikev2_keys *keys, int initiator,
			   const unsigned char *shared_secret, size_t shared_secret_len,
			   const unsigned char *nonce, size_t nonce_len,
			   const unsigned char *key_pad, size_t key_pad_len,
			   unsigned char *auth_data)
{
	size_t sign_len, buf_len;
	unsigned char *sign_data, *pos, *buf, hash[20];
	const struct ikev2_prf_alg *prf;
	const unsigned char *SK_p = initiator ? keys->SK_pi : keys->SK_pr;

	prf = ikev2_get_prf(prf_alg);
	if (sign_msg == 0 || ID == 0 || SK_p == 0 ||
	    shared_secret == 0 || nonce == 0 || prf == 0)
		return -1;

	 
	buf_len = 4 + ID_len;
	buf = os_zalloc(buf_len);
	if (buf == 0)
		return -1;
	buf[0] = ID_type;
	os_memcpy(buf + 4, ID, ID_len);
	if (ikev2_prf_hash(prf->id, SK_p, keys->SK_prf_len,
			   1, (const unsigned char **) &buf, &buf_len, hash) < 0) {
		os_free(buf);
		return -1;
	}
	os_free(buf);

	 
	sign_len = wpabuf_len(sign_msg) + nonce_len + prf->hash_len;
	sign_data = os_malloc(sign_len);
	if (sign_data == 0)
		return -1;
	pos = sign_data;
	os_memcpy(pos, wpabuf_head(sign_msg), wpabuf_len(sign_msg));
	pos += wpabuf_len(sign_msg);
	os_memcpy(pos, nonce, nonce_len);
	pos += nonce_len;
	os_memcpy(pos, hash, prf->hash_len);

	 
	if (ikev2_prf_hash(prf->id, shared_secret, shared_secret_len, 1,
			   &key_pad, &key_pad_len, hash) < 0 ||
	    ikev2_prf_hash(prf->id, hash, prf->hash_len, 1,
			   (const unsigned char **) &sign_data, &sign_len, auth_data) < 0)
	{
		os_free(sign_data);
		return -1;
	}
	os_free(sign_data);

	return 0;
}


unsigned char * ikev2_decrypt_payload(int encr_id, int integ_id,
			   struct ikev2_keys *keys, int initiator,
			   const struct ikev2_hdr *hdr,
			   const unsigned char *encrypted, size_t encrypted_len,
			   size_t *res_len)
{
	size_t iv_len;
	const unsigned char *pos, *end, *iv, *integ;
	unsigned char hash[20], *decrypted;
	size_t decrypted_len, pad_len;
	const struct ikev2_integ_alg *integ_alg;
	const struct ikev2_encr_alg *encr_alg;
	const unsigned char *SK_e = initiator ? keys->SK_ei : keys->SK_er;
	const unsigned char *SK_a = initiator ? keys->SK_ai : keys->SK_ar;

	if (encrypted == 0) {
		wpa_printf(0, "IKEV2: No Encrypted payload in SA_AUTH");
		return 0;
	}

	encr_alg = ikev2_get_encr(encr_id);
	if (encr_alg == 0) {
		wpa_printf(0, "IKEV2: Unsupported encryption type");
		return 0;
	}
	iv_len = encr_alg->block_size;

	integ_alg = ikev2_get_integ(integ_id);
	if (integ_alg == 0) {
		wpa_printf(0, "IKEV2: Unsupported intergrity type");
		return 0;
	}

	if (encrypted_len < iv_len + 1 + integ_alg->hash_len) {
		wpa_printf(0, "IKEV2: No room for IV or Integrity "
			  "Checksum");
		return 0;
	}

	iv = encrypted;
	pos = iv + iv_len;
	end = encrypted + encrypted_len;
	integ = end - integ_alg->hash_len;

	if (SK_a == 0) {
		wpa_printf(0, "IKEV2: No SK_a available");
		return 0;
	}
	if (ikev2_integ_hash(integ_id, SK_a, keys->SK_integ_len,
			     (const unsigned char *) hdr,
			     integ - (const unsigned char *) hdr, hash) < 0) {
		wpa_printf(0, "IKEV2: Failed to calculate integrity "
			   "hash");
		return 0;
	}
	if (os_memcmp(integ, hash, integ_alg->hash_len) != 0) {
		wpa_printf(0, "IKEV2: Incorrect Integrity Checksum "
			   "Data");
		return 0;
	}

	if (SK_e == 0) {
		wpa_printf(0, "IKEV2: No SK_e available");
		return 0;
	}

	decrypted_len = integ - pos;
	decrypted = os_malloc(decrypted_len);
	if (decrypted == 0)
		return 0;

	if (ikev2_encr_decrypt(encr_alg->id, SK_e, keys->SK_encr_len, iv, pos,
			       decrypted, decrypted_len) < 0) {
		os_free(decrypted);
		return 0;
	}

	pad_len = decrypted[decrypted_len - 1];
	if (decrypted_len < pad_len + 1) {
		wpa_printf(0, "IKEV2: Invalid padding in encrypted "
			   "payload");
		os_free(decrypted);
		return 0;
	}

	decrypted_len -= pad_len + 1;

	*res_len = decrypted_len;
	return decrypted;
}


void ikev2_update_hdr(struct wpabuf *msg)
{
	struct ikev2_hdr *hdr;

	 
	hdr = wpabuf_mhead(msg);
	do { (hdr->length)[0] = (unsigned char) ((((unsigned int) (wpabuf_len(msg))) >> 24) & 0xff); (hdr->length)[1] = (unsigned char) ((((unsigned int) (wpabuf_len(msg))) >> 16) & 0xff); (hdr->length)[2] = (unsigned char) ((((unsigned int) (wpabuf_len(msg))) >> 8) & 0xff); (hdr->length)[3] = (unsigned char) (((unsigned int) (wpabuf_len(msg))) & 0xff); } while (0);
}


int ikev2_build_encrypted(int encr_id, int integ_id, struct ikev2_keys *keys,
			  int initiator, struct wpabuf *msg,
			  struct wpabuf *plain, unsigned char next_payload)
{
	struct ikev2_payload_hdr *phdr;
	size_t plen;
	size_t iv_len, pad_len;
	unsigned char *icv, *iv;
	const struct ikev2_integ_alg *integ_alg;
	const struct ikev2_encr_alg *encr_alg;
	const unsigned char *SK_e = initiator ? keys->SK_ei : keys->SK_er;
	const unsigned char *SK_a = initiator ? keys->SK_ai : keys->SK_ar;

	wpa_printf(0, "IKEV2: Adding Encrypted payload");

	 

	encr_alg = ikev2_get_encr(encr_id);
	if (encr_alg == 0) {
		wpa_printf(0, "IKEV2: Unsupported encryption type");
		return -1;
	}
	iv_len = encr_alg->block_size;

	integ_alg = ikev2_get_integ(integ_id);
	if (integ_alg == 0) {
		wpa_printf(0, "IKEV2: Unsupported intergrity type");
		return -1;
	}

	if (SK_e == 0) {
		wpa_printf(0, "IKEV2: No SK_e available");
		return -1;
	}

	if (SK_a == 0) {
		wpa_printf(0, "IKEV2: No SK_a available");
		return -1;
	}

	phdr = wpabuf_put(msg, sizeof(*phdr));
	phdr->next_payload = next_payload;
	phdr->flags = 0;

	iv = wpabuf_put(msg, iv_len);
	if (os_get_random(iv, iv_len)) {
		wpa_printf(0, "IKEV2: Could not generate IV");
		return -1;
	}

	pad_len = iv_len - (wpabuf_len(plain) + 1) % iv_len;
	if (pad_len == iv_len)
		pad_len = 0;
	wpabuf_put(plain, pad_len);
	wpabuf_put_u8(plain, pad_len);

	if (ikev2_encr_encrypt(encr_alg->id, SK_e, keys->SK_encr_len, iv,
			       wpabuf_head(plain), wpabuf_mhead(plain),
			       wpabuf_len(plain)) < 0)
		return -1;

	wpabuf_put_buf(msg, plain);

	 
	icv = wpabuf_put(msg, integ_alg->hash_len);
	plen = (unsigned char *) wpabuf_put(msg, 0) - (unsigned char *) phdr;
	do { (phdr->payload_length)[0] = ((unsigned short) (plen)) >> 8; (phdr->payload_length)[1] = ((unsigned short) (plen)) & 0xff; } while (0);

	ikev2_update_hdr(msg);

	return ikev2_integ_hash(integ_id, SK_a, keys->SK_integ_len,
				wpabuf_head(msg),
				wpabuf_len(msg) - integ_alg->hash_len, icv);

	return 0;
}


int ikev2_keys_set(struct ikev2_keys *keys)
{
	return keys->SK_d && keys->SK_ai && keys->SK_ar && keys->SK_ei &&
		keys->SK_er && keys->SK_pi && keys->SK_pr;
}


void ikev2_free_keys(struct ikev2_keys *keys)
{
	os_free(keys->SK_d);
	os_free(keys->SK_ai);
	os_free(keys->SK_ar);
	os_free(keys->SK_ei);
	os_free(keys->SK_er);
	os_free(keys->SK_pi);
	os_free(keys->SK_pr);
	keys->SK_d = keys->SK_ai = keys->SK_ar = keys->SK_ei = keys->SK_er =
		keys->SK_pi = keys->SK_pr = 0;
}


int ikev2_derive_sk_keys(const struct ikev2_prf_alg *prf,
			 const struct ikev2_integ_alg *integ,
			 const struct ikev2_encr_alg *encr,
			 const unsigned char *skeyseed, const unsigned char *data, size_t data_len,
			 struct ikev2_keys *keys)
{
	unsigned char *keybuf, *pos;
	size_t keybuf_len;

	


 
	ikev2_free_keys(keys);
	keys->SK_d_len = prf->key_len;
	keys->SK_integ_len = integ->key_len;
	keys->SK_encr_len = encr->key_len;
	keys->SK_prf_len = prf->key_len;





	keybuf_len = keys->SK_d_len + 2 * keys->SK_integ_len +
		2 * keys->SK_encr_len + 2 * keys->SK_prf_len;
	keybuf = os_malloc(keybuf_len);
	if (keybuf == 0)
		return -1;

	if (ikev2_prf_plus(prf->id, skeyseed, prf->hash_len,
			   data, data_len, keybuf, keybuf_len)) {
		os_free(keybuf);
		return -1;
	}

	pos = keybuf;

	keys->SK_d = os_malloc(keys->SK_d_len);
	if (keys->SK_d) {
		os_memcpy(keys->SK_d, pos, keys->SK_d_len);
		wpa_hexdump_key(0, "IKEV2: SK_d",
				keys->SK_d, keys->SK_d_len);
	}
	pos += keys->SK_d_len;

	keys->SK_ai = os_malloc(keys->SK_integ_len);
	if (keys->SK_ai) {
		os_memcpy(keys->SK_ai, pos, keys->SK_integ_len);
		wpa_hexdump_key(0, "IKEV2: SK_ai",
				keys->SK_ai, keys->SK_integ_len);
	}
	pos += keys->SK_integ_len;

	keys->SK_ar = os_malloc(keys->SK_integ_len);
	if (keys->SK_ar) {
		os_memcpy(keys->SK_ar, pos, keys->SK_integ_len);
		wpa_hexdump_key(0, "IKEV2: SK_ar",
				keys->SK_ar, keys->SK_integ_len);
	}
	pos += keys->SK_integ_len;

	keys->SK_ei = os_malloc(keys->SK_encr_len);
	if (keys->SK_ei) {
		os_memcpy(keys->SK_ei, pos, keys->SK_encr_len);
		wpa_hexdump_key(0, "IKEV2: SK_ei",
				keys->SK_ei, keys->SK_encr_len);
	}
	pos += keys->SK_encr_len;

	keys->SK_er = os_malloc(keys->SK_encr_len);
	if (keys->SK_er) {
		os_memcpy(keys->SK_er, pos, keys->SK_encr_len);
		wpa_hexdump_key(0, "IKEV2: SK_er",
				keys->SK_er, keys->SK_encr_len);
	}
	pos += keys->SK_encr_len;

	keys->SK_pi = os_malloc(keys->SK_prf_len);
	if (keys->SK_pi) {
		os_memcpy(keys->SK_pi, pos, keys->SK_prf_len);
		wpa_hexdump_key(0, "IKEV2: SK_pi",
				keys->SK_pi, keys->SK_prf_len);
	}
	pos += keys->SK_prf_len;

	keys->SK_pr = os_malloc(keys->SK_prf_len);
	if (keys->SK_pr) {
		os_memcpy(keys->SK_pr, pos, keys->SK_prf_len);
		wpa_hexdump_key(0, "IKEV2: SK_pr",
				keys->SK_pr, keys->SK_prf_len);
	}

	os_free(keybuf);

	if (!ikev2_keys_set(keys)) {
		ikev2_free_keys(keys);
		return -1;
	}

	return 0;
}
