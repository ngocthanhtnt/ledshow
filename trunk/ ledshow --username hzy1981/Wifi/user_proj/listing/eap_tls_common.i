#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_tls_common.c"












 

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

#line 16 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_tls_common.c"

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



#line 18 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_tls_common.c"
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
#line 19 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_tls_common.c"
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

#line 20 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_tls_common.c"
#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_i.h"












 




#line 19 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_i.h"
#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer/eap.h"












 




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

#line 19 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer/eap.h"
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




#line 20 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer/eap.h"
#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer/eap_methods.h"












 




#line 19 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer/eap_methods.h"

const struct eap_method * eap_peer_get_eap_method(int vendor, EapType method);
const struct eap_method * eap_peer_get_methods(size_t *count);

struct eap_method * eap_peer_method_alloc(int version, int vendor,
					  EapType method, const char *name);
void eap_peer_method_free(struct eap_method *method);
int eap_peer_method_register(struct eap_method *method);




EapType eap_peer_get_type(const char *name, int *vendor);
const char * eap_get_name(int vendor, EapType type);
size_t eap_get_names(char *buf, size_t buflen);
char ** eap_get_names_as_string_array(size_t *num);
void eap_peer_unregister_methods(void);

#line 70 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer/eap_methods.h"


#line 78 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer/eap_methods.h"

static  int eap_peer_method_load(const char *so)
{
	return 0;
}

static  int eap_peer_method_unload(struct eap_method *method)
{
	return 0;
}



 
int eap_peer_md5_register(void);
int eap_peer_tls_register(void);
int eap_peer_mschapv2_register(void);
int eap_peer_peap_register(void);
int eap_peer_ttls_register(void);
int eap_peer_gtc_register(void);
int eap_peer_otp_register(void);
int eap_peer_sim_register(void);
int eap_peer_leap_register(void);
int eap_peer_psk_register(void);
int eap_peer_aka_register(void);
int eap_peer_aka_prime_register(void);
int eap_peer_fast_register(void);
int eap_peer_pax_register(void);
int eap_peer_sake_register(void);
int eap_peer_gpsk_register(void);
int eap_peer_wsc_register(void);
int eap_peer_ikev2_register(void);
int eap_peer_vendor_test_register(void);
int eap_peer_tnc_register(void);

#line 21 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer/eap.h"

struct eap_sm;
struct wpa_config_blob;
struct wpabuf;

struct eap_method_type {
	int vendor;
	unsigned int method;
};










 
enum eapol_bool_var {
	



 
	EAPOL_eapSuccess,

	



 
	EAPOL_eapRestart,

	



 
	EAPOL_eapFail,

	



 
	EAPOL_eapResp,

	



 
	EAPOL_eapNoResp,

	



 
	EAPOL_eapReq,

	



 
	EAPOL_portEnabled,

	



 
	EAPOL_altAccept,

	



 
	EAPOL_altReject
};








 
enum eapol_int_var {
	







 
	EAPOL_idleWhile
};









 
struct eapol_callbacks {
	


 
	struct eap_peer_config * (*get_config)(void *ctx);

	



 
	int (*get_bool)(void *ctx, enum eapol_bool_var variable);

	




 
	void (*set_bool)(void *ctx, enum eapol_bool_var variable,
			 int value);

	




 
	unsigned int (*get_int)(void *ctx, enum eapol_int_var variable);

	




 
	void (*set_int)(void *ctx, enum eapol_int_var variable,
			unsigned int value);

	





 
	struct wpabuf * (*get_eapReqData)(void *ctx);

	






 
	void (*set_config_blob)(void *ctx, struct wpa_config_blob *blob);

	




 
	const struct wpa_config_blob * (*get_config_blob)(void *ctx,
							  const char *name);

	








 
	void (*notify_pending)(void *ctx);

	




 
	void (*eap_param_needed)(void *ctx, const char *field,
				 const char *txt);
};



 
struct eap_config {
	



 
	const char *opensc_engine_path;
	



 
	const char *pkcs11_engine_path;
	



 
	const char *pkcs11_module_path;
	



 
	struct wps_context *wps;
};

struct eap_sm * eap_peer_sm_init(void *eapol_ctx,
				 struct eapol_callbacks *eapol_cb,
				 void *msg_ctx, struct eap_config *conf);
void eap_peer_sm_deinit(struct eap_sm *sm);
int eap_peer_sm_step(struct eap_sm *sm);
void eap_sm_abort(struct eap_sm *sm);
int eap_sm_get_status(struct eap_sm *sm, char *buf, size_t buflen,
		      int verbose);
struct wpabuf * eap_sm_buildIdentity(struct eap_sm *sm, int id, int encrypted);
void eap_sm_request_identity(struct eap_sm *sm);
void eap_sm_request_password(struct eap_sm *sm);
void eap_sm_request_new_password(struct eap_sm *sm);
void eap_sm_request_pin(struct eap_sm *sm);
void eap_sm_request_otp(struct eap_sm *sm, const char *msg, size_t msg_len);
void eap_sm_request_passphrase(struct eap_sm *sm);
void eap_sm_notify_ctrl_attached(struct eap_sm *sm);
unsigned int eap_get_phase2_type(const char *name, int *vendor);
struct eap_method_type * eap_get_phase2_types(struct eap_peer_config *config,
					      size_t *count);
void eap_set_fast_reauth(struct eap_sm *sm, int enabled);
void eap_set_workaround(struct eap_sm *sm, unsigned int workaround);
void eap_set_force_disabled(struct eap_sm *sm, int disabled);
int eap_key_available(struct eap_sm *sm);
void eap_notify_success(struct eap_sm *sm);
void eap_notify_lower_layer_success(struct eap_sm *sm);
const unsigned char * eap_get_eapKeyData(struct eap_sm *sm, size_t *len);
struct wpabuf * eap_get_eapRespData(struct eap_sm *sm);
void eap_register_scard_ctx(struct eap_sm *sm, void *ctx);
void eap_invalidate_cached_session(struct eap_sm *sm);

int eap_is_wps_pbc_enrollee(struct eap_peer_config *conf);
int eap_is_wps_pin_enrollee(struct eap_peer_config *conf);



#line 20 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_i.h"
#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common/eap_common.h"












 




#line 19 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common/eap_common.h"

const unsigned char * eap_hdr_validate(int vendor, EapType eap_type,
			    const struct wpabuf *msg, size_t *plen);
struct wpabuf * eap_msg_alloc(int vendor, EapType type, size_t payload_len,
			      unsigned char code, unsigned char identifier);
void eap_update_len(struct wpabuf *msg);
unsigned char eap_get_id(const struct wpabuf *msg);
EapType eap_get_type(const struct wpabuf *msg);

#line 21 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_i.h"

 

typedef enum {
	DECISION_FAIL, DECISION_COND_SUCC, DECISION_UNCOND_SUCC
} EapDecision;

typedef enum {
	METHOD_NONE, METHOD_INIT, METHOD_CONT, METHOD_MAY_CONT, METHOD_DONE
} EapMethodState;








 
struct eap_method_ret {
	

 
	int ignore;

	

 
	EapMethodState methodState;

	

 
	EapDecision decision;

	

 
	int allowNotifications;
};







 
struct eap_method {
	

 
	int vendor;

	

 
	EapType method;

	

 
	const char *name;

	








 
	void * (*init)(struct eap_sm *sm);

	





 
	void (*deinit)(struct eap_sm *sm, void *priv);

	













 
	struct wpabuf * (*process)(struct eap_sm *sm, void *priv,
				   struct eap_method_ret *ret,
				   const struct wpabuf *reqData);

	




 
	int (*isKeyAvailable)(struct eap_sm *sm, void *priv);

	









 
	unsigned char * (*getKey)(struct eap_sm *sm, void *priv, size_t *len);

	












 
	int (*get_status)(struct eap_sm *sm, void *priv, char *buf,
			  size_t buflen, int verbose);

	








 
	int (*has_reauth_data)(struct eap_sm *sm, void *priv);

	









 
	void (*deinit_for_reauth)(struct eap_sm *sm, void *priv);

	








 
	void * (*init_for_reauth)(struct eap_sm *sm, void *priv);

	









 
	const unsigned char * (*get_identity)(struct eap_sm *sm, void *priv, size_t *len);

	











 
	void (*free)(struct eap_method *method);


	






 
	int version;

	




 
	struct eap_method *next;

#line 257 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_i.h"

	









 
	unsigned char * (*get_emsk)(struct eap_sm *sm, void *priv, size_t *len);
};




 
struct eap_sm {
	enum {
		EAP_INITIALIZE, EAP_DISABLED, EAP_IDLE, EAP_RECEIVED,
		EAP_GET_METHOD, EAP_METHOD, EAP_SEND_RESPONSE, EAP_DISCARD,
		EAP_IDENTITY, EAP_NOTIFICATION, EAP_RETRANSMIT, EAP_SUCCESS,
		EAP_FAILURE
	} EAP_state;
	 
	EapType selectedMethod;
	EapMethodState methodState;
	int lastId;
	struct wpabuf *lastRespData;
	EapDecision decision;
	 
	int rxReq;
	int rxSuccess;
	int rxFailure;
	int reqId;
	EapType reqMethod;
	int reqVendor;
	unsigned int reqVendorMethod;
	int ignore;
	 
	int ClientTimeout;

	 
	int allowNotifications;  
	struct wpabuf *eapRespData;  
	int eapKeyAvailable;  
	unsigned char *eapKeyData;  
	size_t eapKeyDataLen;  
	const struct eap_method *m;  
	 
	int changed;
	void *eapol_ctx;
	struct eapol_callbacks *eapol_cb;
	void *eap_method_priv;
	int init_phase2;
	int fast_reauth;

	int rxResp  ;
	int leap_done;
	int peap_done;
	unsigned char req_md5[16];  
	unsigned char last_md5[16]; 
 

	void *msg_ctx;
	void *scard_ctx;
	void *ssl_ctx;

	unsigned int workaround;

	 
	unsigned char *peer_challenge, *auth_challenge;

	int num_rounds;
	int force_disabled;

	struct wps_context *wps;

	int prev_failure;
};

const unsigned char * eap_get_config_identity(struct eap_sm *sm, size_t *len);
const unsigned char * eap_get_config_password(struct eap_sm *sm, size_t *len);
const unsigned char * eap_get_config_password2(struct eap_sm *sm, size_t *len, int *hash);
const unsigned char * eap_get_config_new_password(struct eap_sm *sm, size_t *len);
const unsigned char * eap_get_config_otp(struct eap_sm *sm, size_t *len);
void eap_clear_config_otp(struct eap_sm *sm);
const char * eap_get_config_phase1(struct eap_sm *sm);
const char * eap_get_config_phase2(struct eap_sm *sm);
struct eap_peer_config * eap_get_config(struct eap_sm *sm);
void eap_set_config_blob(struct eap_sm *sm, struct wpa_config_blob *blob);
const struct wpa_config_blob *
eap_get_config_blob(struct eap_sm *sm, const char *name);
void eap_notify_pending(struct eap_sm *sm);
int eap_allowed_method(struct eap_sm *sm, int vendor, unsigned int method);

#line 21 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_tls_common.c"
#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_tls_common.h"












 






 
struct eap_ssl_data {
	

 
	struct tls_connection *conn;

	

 
	struct wpabuf *tls_out;

	

 
	size_t tls_out_pos;

	

 
	size_t tls_out_limit;

	

 
	struct wpabuf *tls_in;

	

 
	size_t tls_in_left;

	

 
	size_t tls_in_total;

	

 
	int phase2;

	


 
	int include_tls_length;

	

 
	int tls_ia;

	

 
	struct eap_sm *eap;
};


 





  



int eap_peer_tls_ssl_init(struct eap_sm *sm, struct eap_ssl_data *data,
			  struct eap_peer_config *config);
void eap_peer_tls_ssl_deinit(struct eap_sm *sm, struct eap_ssl_data *data);
unsigned char * eap_peer_tls_derive_key(struct eap_sm *sm, struct eap_ssl_data *data,
			     const char *label, size_t len);
int eap_peer_tls_process_helper(struct eap_sm *sm, struct eap_ssl_data *data,
				EapType eap_type, int peap_version,
				unsigned char id, const unsigned char *in_data, size_t in_len,
				struct wpabuf **out_data);
struct wpabuf * eap_peer_tls_build_ack(unsigned char id, EapType eap_type,
				       int peap_version);
int eap_peer_tls_reauth_init(struct eap_sm *sm, struct eap_ssl_data *data);
int eap_peer_tls_status(struct eap_sm *sm, struct eap_ssl_data *data,
			char *buf, size_t buflen, int verbose);
const unsigned char * eap_peer_tls_process_init(struct eap_sm *sm,
				     struct eap_ssl_data *data,
				     EapType eap_type,
				     struct eap_method_ret *ret,
				     const struct wpabuf *reqData,
				     size_t *len, unsigned char *flags);
void eap_peer_tls_reset_input(struct eap_ssl_data *data);
void eap_peer_tls_reset_output(struct eap_ssl_data *data);
int eap_peer_tls_decrypt(struct eap_sm *sm, struct eap_ssl_data *data,
			 const struct wpabuf *in_data,
			 struct wpabuf **in_decrypted);
int eap_peer_tls_encrypt(struct eap_sm *sm, struct eap_ssl_data *data,
			 EapType eap_type, int peap_version, unsigned char id,
			 const struct wpabuf *in_data,
			 struct wpabuf **out_data);
int eap_peer_select_phase2_methods(struct eap_peer_config *config,
				   const char *prefix,
				   struct eap_method_type **types,
				   size_t *num_types);
int eap_peer_tls_phase2_nak(struct eap_method_type *types, size_t num_types,
			    struct eap_hdr *hdr, struct wpabuf **resp);

#line 22 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_tls_common.c"
#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_config.h"












 






 
struct eap_peer_config {
	




 
	unsigned char *identity;

	

 
	size_t identity_len;

	








 
	unsigned char *anonymous_identity;

	

 
	size_t anonymous_identity_len;

	














 
	unsigned char *password;

	

 
	size_t password_len;

	



























 
	unsigned char *ca_cert;

	







 
	unsigned char *ca_path;

	










 
	unsigned char *client_cert;

	























 
	unsigned char *private_key;

	



 
	unsigned char *private_key_passwd;

	














 
	unsigned char *dh_file;

	








 
	unsigned char *subject_match;

	














 
	unsigned char *altsubject_match;

	














 
	unsigned char *ca_cert2;

	










 
	unsigned char *ca_path2;

	









 
	unsigned char *client_cert2;

	









 
	unsigned char *private_key2;

	




 
	unsigned char *private_key2_passwd;

	









 
	unsigned char *dh_file2;

	




 
	unsigned char *subject_match2;

	




 
	unsigned char *altsubject_match2;

	




 
	struct eap_method_type *eap_methods;

	






















































 
	char *phase1;

	




 
	char *phase2;

	







 
	char *pcsc;

	







 
	char *pin;

	




 
	int engine;

	







 
	char *engine_id;

	







 
	int engine2;


	










 
	char *pin2;

	










 
	char *engine2_id;


	




 
	char *key_id;

	




 
	char *cert_id;

	



 
	char *ca_cert_id;

	




 
	char *key2_id;

	




 
	char *cert2_id;

	



 
	char *ca_cert2_id;

	




 
	unsigned char *otp;

	

 
	size_t otp_len;

	





 
	int pending_req_identity;

	





 
	int pending_req_password;

	





 
	int pending_req_pin;

	





 
	int pending_req_new_password;

	





 
	int pending_req_passphrase;

	





 
	char *pending_req_otp;

	

 
	size_t pending_req_otp_len;

	








 
	char *pac_file;

	




 
	int mschapv2_retry;

	





 
	unsigned char *new_password;

	

 
	size_t new_password_len;

	







 
	int fragment_size;


	






 
	unsigned int flags;
};








 
struct wpa_config_blob {
	

 
	char *name;

	

 
	unsigned char *data;

	

 
	size_t len;

	

 
	struct wpa_config_blob *next;
};

#line 23 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_tls_common.c"


static int eap_tls_check_blob(struct eap_sm *sm, const char **name,
			      const unsigned char **data, size_t *data_len)
{
	const struct wpa_config_blob *blob;

	if (*name == 0 || os_strncmp(*name, "blob://", 7) != 0)
		return 0;

	blob = eap_get_config_blob(sm, *name + 7);
	if (blob == 0) {
		wpa_printf(0, "%s: Named configuration blob '%s' not "
			   "found", __func__, *name + 7);
		return -1;
	}

	*name = 0;
	*data = blob->data;
	*data_len = blob->len;

	return 0;
}


static void eap_tls_params_flags(struct tls_connection_params *params,
				 const char *txt)
{
	if (txt == 0)
		return;
	if (os_strstr(txt, "tls_allow_md5=1"))
		params->flags |= (1 << (0));
	if (os_strstr(txt, "tls_disable_time_checks=1"))
		params->flags |= (1 << (1));
}


static void eap_tls_params_from_conf1(struct tls_connection_params *params,
				      struct eap_peer_config *config)
{
	params->ca_cert = (char *) config->ca_cert;
	params->ca_path = (char *) config->ca_path;
	params->client_cert = (char *) config->client_cert;
	params->private_key = (char *) config->private_key;
	params->private_key_passwd = (char *) config->private_key_passwd;
	params->dh_file = (char *) config->dh_file;
	params->subject_match = (char *) config->subject_match;
	params->altsubject_match = (char *) config->altsubject_match;
	params->engine = config->engine;
	params->engine_id = config->engine_id;
	params->pin = config->pin;
	params->key_id = config->key_id;
	params->cert_id = config->cert_id;
	params->ca_cert_id = config->ca_cert_id;
	eap_tls_params_flags(params, config->phase1);
}


static void eap_tls_params_from_conf2(struct tls_connection_params *params,
				      struct eap_peer_config *config)
{
	params->ca_cert = (char *) config->ca_cert2;
	params->ca_path = (char *) config->ca_path2;
	params->client_cert = (char *) config->client_cert2;
	params->private_key = (char *) config->private_key2;
	params->private_key_passwd = (char *) config->private_key2_passwd;
	params->dh_file = (char *) config->dh_file2;
	params->subject_match = (char *) config->subject_match2;
	params->altsubject_match = (char *) config->altsubject_match2;
	params->engine = config->engine2;
	params->engine_id = config->engine2_id;
	params->pin = config->pin2;
	params->key_id = config->key2_id;
	params->cert_id = config->cert2_id;
	params->ca_cert_id = config->ca_cert2_id;
	eap_tls_params_flags(params, config->phase2);
}


static int eap_tls_params_from_conf(struct eap_sm *sm,
				    struct eap_ssl_data *data,
				    struct tls_connection_params *params,
				    struct eap_peer_config *config, int phase2)
{
	os_memset(params, 0, sizeof(*params));
	if (phase2) {
		wpa_printf(0, "TLS: using phase2 config options");
		eap_tls_params_from_conf2(params, config);
	} else {
		wpa_printf(0, "TLS: using phase1 config options");
		eap_tls_params_from_conf1(params, config);
	}
	params->tls_ia = data->tls_ia;

	


 
	if (eap_tls_check_blob(sm, &params->ca_cert, &params->ca_cert_blob,
			       &params->ca_cert_blob_len) ||
	    eap_tls_check_blob(sm, &params->client_cert,
			       &params->client_cert_blob,
			       &params->client_cert_blob_len) ||
	    eap_tls_check_blob(sm, &params->private_key,
			       &params->private_key_blob,
			       &params->private_key_blob_len) ||
	    eap_tls_check_blob(sm, &params->dh_file, &params->dh_blob,
			       &params->dh_blob_len)) {
		wpa_printf(0, "SSL: Failed to get configuration blobs");
		return -1;
	}

	return 0;
}


static int eap_tls_init_connection(struct eap_sm *sm,
				   struct eap_ssl_data *data,
				   struct eap_peer_config *config,
				   struct tls_connection_params *params)
{
	int res;

	data->conn = tls_connection_init(sm->ssl_ctx);
	if (data->conn == 0) {
		wpa_printf(0, "SSL: Failed to initialize new TLS "
			   "connection");
		return -1;
	}

	res = tls_connection_set_params(sm->ssl_ctx, data->conn, params);
	if (res == TLS_SET_PARAMS_ENGINE_PRV_INIT_FAILED) {
		



 
		os_free(config->pin);
		config->pin = 0;
	} else if (res == TLS_SET_PARAMS_ENGINE_PRV_VERIFY_FAILED) {
		wpa_printf(0, "TLS: Failed to load private key");
		


 
		os_free(config->pin);
		config->pin = 0;
		eap_sm_request_pin(sm);
		sm->ignore = 1;
		tls_connection_deinit(sm->ssl_ctx, data->conn);
		data->conn = 0;
		return -1;
	} else if (res) {
		wpa_printf(0, "TLS: Failed to set TLS connection "
			   "parameters");
		tls_connection_deinit(sm->ssl_ctx, data->conn);
		data->conn = 0;
		return -1;
	}

	return 0;
}











 
int eap_peer_tls_ssl_init(struct eap_sm *sm, struct eap_ssl_data *data,
			  struct eap_peer_config *config)
{
	struct tls_connection_params params;

	if (config == 0)
		return -1;

	data->eap = sm;
	data->phase2 = sm->init_phase2;
	if (eap_tls_params_from_conf(sm, data, &params, config, data->phase2) <
	    0)
		return -1;

	if (eap_tls_init_connection(sm, data, config, &params) < 0)
		return -1;

	data->tls_out_limit = config->fragment_size;
	if (data->phase2) {
		

 
		if (data->tls_out_limit > 100)
			data->tls_out_limit -= 100;
	}

	if (config->phase1 &&
	    os_strstr(config->phase1, "include_tls_length=1")) {
		wpa_printf(0, "TLS: Include TLS Message Length in "
			   "unfragmented packets");
		data->include_tls_length = 1;
	}

	return 0;
}









 
void eap_peer_tls_ssl_deinit(struct eap_sm *sm, struct eap_ssl_data *data)
{
	tls_connection_deinit(sm->ssl_ctx, data->conn);
	eap_peer_tls_reset_input(data);
	eap_peer_tls_reset_output(data);
}















 
unsigned char * eap_peer_tls_derive_key(struct eap_sm *sm, struct eap_ssl_data *data,
			     const char *label, size_t len)
{
	struct tls_keys keys;
	unsigned char *rnd = 0, *out;

	out = os_malloc(len);
	if (out == 0)
		return 0;

	 
	if (tls_connection_prf(sm->ssl_ctx, data->conn, label, 0, out, len) ==
	    0)
		return out;

	



 
	if (tls_connection_get_keys(sm->ssl_ctx, data->conn, &keys))
		goto fail;

	if (keys.client_random == 0 || keys.server_random == 0 ||
	    keys.master_key == 0)
		goto fail;

	rnd = os_malloc(keys.client_random_len + keys.server_random_len);
	if (rnd == 0)
		goto fail;
	os_memcpy(rnd, keys.client_random, keys.client_random_len);
	os_memcpy(rnd + keys.client_random_len, keys.server_random,
		  keys.server_random_len);

	if (tls_prf(keys.master_key, keys.master_key_len,
		    label, rnd, keys.client_random_len +
		    keys.server_random_len, out, len))
		goto fail;

	os_free(rnd);
	return out;

fail:
	os_free(out);
	os_free(rnd);
	return 0;
}








 
static int eap_peer_tls_reassemble_fragment(struct eap_ssl_data *data,
					    const struct wpabuf *in_data)
{
	size_t tls_in_len, in_len;

	tls_in_len = data->tls_in ? wpabuf_len(data->tls_in) : 0;
	in_len = in_data ? wpabuf_len(in_data) : 0;

	if (tls_in_len + in_len == 0) {
		 
		wpa_printf(0, "SSL: Invalid reassembly state: "
			   "tls_in_left=%lu tls_in_len=%lu in_len=%lu",
			   (unsigned long) data->tls_in_left,
			   (unsigned long) tls_in_len,
			   (unsigned long) in_len);
		eap_peer_tls_reset_input(data);
		return -1;
	}

	if (tls_in_len + in_len > 65536) {
		


 
		wpa_printf(0, "SSL: Too long TLS fragment (size over "
			   "64 kB)");
		eap_peer_tls_reset_input(data);
		return -1;
	}

	if (in_len > data->tls_in_left) {
		 
		wpa_printf(0, "SSL: more data than TLS message length "
			   "indicated");
		eap_peer_tls_reset_input(data);
		return -1;
	}

	if (wpabuf_resize(&data->tls_in, in_len) < 0) {
		wpa_printf(0, "SSL: Could not allocate memory for TLS "
			   "data");
		eap_peer_tls_reset_input(data);
		return -1;
	}
	wpabuf_put_buf(data->tls_in, in_data);
	data->tls_in_left -= in_len;

	if (data->tls_in_left > 0) {
		wpa_printf(0, "SSL: Need %lu bytes more input "
			   "data", (unsigned long) data->tls_in_left);
		return 1;
	}

	return 0;
}













 
static const struct wpabuf * eap_peer_tls_data_reassemble(
	struct eap_ssl_data *data, const struct wpabuf *in_data,
	int *need_more_input)
{
	*need_more_input = 0;

	if (data->tls_in_left > wpabuf_len(in_data) || data->tls_in) {
		 
		int res = eap_peer_tls_reassemble_fragment(data, in_data);
		if (res) {
			if (res == 1)
				*need_more_input = 1;
			return 0;
		}

		 
	} else {
		 
		data->tls_in_left = 0;
		data->tls_in = wpabuf_dup(in_data);
		if (data->tls_in == 0)
			return 0;
	}

	return data->tls_in;
}











 
static int eap_tls_process_input(struct eap_sm *sm, struct eap_ssl_data *data,
				 const unsigned char *in_data, size_t in_len,
				 struct wpabuf **out_data)
{
	const struct wpabuf *msg;
	int need_more_input;
	struct wpabuf *appl_data;
	struct wpabuf buf;

	wpabuf_set(&buf, in_data, in_len);
	msg = eap_peer_tls_data_reassemble(data, &buf, &need_more_input);
	if (msg == 0)
		return need_more_input ? 1 : -1;

	 
	if (data->tls_out) {
		 
		wpa_printf(0, "SSL: eap_tls_process_input - pending "
			   "tls_out data even though tls_out_len = 0");
		wpabuf_free(data->tls_out);
		do { } while (0);
	}
	appl_data = 0;
	data->tls_out = tls_connection_handshake(sm->ssl_ctx, data->conn,
						 msg, &appl_data);

	eap_peer_tls_reset_input(data);

	if (appl_data &&
	    tls_connection_established(sm->ssl_ctx, data->conn) &&
	    !tls_connection_get_failed(sm->ssl_ctx, data->conn)) {
		wpa_hexdump_buf_key(0, "SSL: Application data",
				    appl_data);
		*out_data = appl_data;
		return 2;
	}

	wpabuf_free(appl_data);

	return 0;
}











 
static int eap_tls_process_output(struct eap_ssl_data *data, EapType eap_type,
				  int peap_version, unsigned char id, int ret,
				  struct wpabuf **out_data)
{
	size_t len;
	unsigned char *flags;
	int more_fragments, length_included;

	if (data->tls_out == 0)
		return -1;
	len = wpabuf_len(data->tls_out) - data->tls_out_pos;
	wpa_printf(0, "SSL: %lu bytes left to be sent out (of total "
		   "%lu bytes)",
		   (unsigned long) len,
		   (unsigned long) wpabuf_len(data->tls_out));

	


 
	if (len > data->tls_out_limit) {
		more_fragments = 1;
		len = data->tls_out_limit;
		wpa_printf(0, "SSL: sending %lu bytes, more fragments "
			   "will follow", (unsigned long) len);
	} else
		more_fragments = 0;

	length_included = data->tls_out_pos == 0 &&
		(wpabuf_len(data->tls_out) > data->tls_out_limit ||
		 data->include_tls_length);
	if (!length_included &&
	    eap_type == EAP_TYPE_PEAP && peap_version == 0 &&
	    !tls_connection_established(data->eap->ssl_ctx, data->conn)) {
		




 
		length_included = 1;
	}

	*out_data = eap_msg_alloc(EAP_VENDOR_IETF, eap_type,
				  1 + length_included * 4 + len,
				  EAP_CODE_RESPONSE, id);
	if (*out_data == 0)
		return -1;

	flags = wpabuf_put(*out_data, 1);
	*flags = peap_version;
	if (more_fragments)
		*flags |= 0x40;
	if (length_included) {
		*flags |= 0x80;
		wpabuf_put_be32(*out_data, wpabuf_len(data->tls_out));
	}

	wpabuf_put_data(*out_data,
			wpabuf_head_u8(data->tls_out) + data->tls_out_pos,
			len);
	data->tls_out_pos += len;

	if (!more_fragments)
		eap_peer_tls_reset_output(data);

	return ret;
}






























 
int eap_peer_tls_process_helper(struct eap_sm *sm, struct eap_ssl_data *data,
				EapType eap_type, int peap_version,
				unsigned char id, const unsigned char *in_data, size_t in_len,
				struct wpabuf **out_data)
{
	int ret = 0;

	*out_data = 0;

	if (data->tls_out && wpabuf_len(data->tls_out) > 0 && in_len > 0) {
		wpa_printf(0, "SSL: Received non-ACK when output "
			   "fragments are waiting to be sent out");
		return -1;
	}

	if (data->tls_out == 0 || wpabuf_len(data->tls_out) == 0) {
		


 
		int res = eap_tls_process_input(sm, data, in_data, in_len,
						out_data);
		if (res) {
			


 
			return res;
		}

		


 
	}

	if (data->tls_out == 0) {
		



 
		eap_peer_tls_reset_output(data);
		return -1;
	}

	if (tls_connection_get_failed(sm->ssl_ctx, data->conn)) {
		 
		wpa_printf(0, "SSL: Failed - tls_out available to "
			   "report error");
		ret = -1;
		 
	}

	if (data->tls_out == 0 || wpabuf_len(data->tls_out) == 0) {
		



 
		wpa_printf(0, "SSL: No data to be sent out");
		wpabuf_free(data->tls_out);
		data->tls_out = 0;
		return 1;
	}

	 
	return eap_tls_process_output(data, eap_type, peap_version, id, ret,
				      out_data);
}








 
struct wpabuf * eap_peer_tls_build_ack(unsigned char id, EapType eap_type,
				       int peap_version)
{
	struct wpabuf *resp;

	resp = eap_msg_alloc(EAP_VENDOR_IETF, eap_type, 1, EAP_CODE_RESPONSE,
			     id);
	if (resp == 0)
		return 0;
	wpa_printf(0, "SSL: Building ACK (type=%d id=%d ver=%d)",
		   (int) eap_type, id, peap_version);
	wpabuf_put_u8(resp, peap_version);  
	return resp;
}







 
int eap_peer_tls_reauth_init(struct eap_sm *sm, struct eap_ssl_data *data)
{
	eap_peer_tls_reset_input(data);
	eap_peer_tls_reset_output(data);
	return tls_connection_shutdown(sm->ssl_ctx, data->conn);
}










 
int eap_peer_tls_status(struct eap_sm *sm, struct eap_ssl_data *data,
			char *buf, size_t buflen, int verbose)
{
	char name[128];
	int len = 0, ret;

	if (tls_get_cipher(sm->ssl_ctx, data->conn, name, sizeof(name)) == 0) {
		ret = os_snprintf(buf + len, buflen - len,
				  "EAP TLS cipher=%s\n", name);
		if (ret < 0 || (size_t) ret >= buflen - len)
			return len;
		len += ret;
	}

	return len;
}

























 
const unsigned char * eap_peer_tls_process_init(struct eap_sm *sm,
				     struct eap_ssl_data *data,
				     EapType eap_type,
				     struct eap_method_ret *ret,
				     const struct wpabuf *reqData,
				     size_t *len, unsigned char *flags)
{
	const unsigned char *pos;
	size_t left;
	unsigned int tls_msg_len;

	if (tls_get_errors(sm->ssl_ctx)) {
		wpa_printf(0, "SSL: TLS errors detected");
		ret->ignore = 1;
		return 0;
	}

	pos = eap_hdr_validate(EAP_VENDOR_IETF, eap_type, reqData, &left);
	if (pos == 0) {
		ret->ignore = 1;
		return 0;
	}
	if (left == 0) {
		wpa_printf(0, "SSL: Invalid TLS message: no Flags "
			   "octet included");
		if (!sm->workaround) {
			ret->ignore = 1;
			return 0;
		}

		wpa_printf(0, "SSL: Workaround - assume no Flags "
			   "indicates ACK frame");
		*flags = 0;
	} else {
		*flags = *pos++;
		left--;
	}
	wpa_printf(0, "SSL: Received packet(len=%lu) - "
		   "Flags 0x%02x", (unsigned long) wpabuf_len(reqData),
		   *flags);
	if (*flags & 0x80) {
		if (left < 4) {
			wpa_printf(0, "SSL: Short frame with TLS "
				   "length");
			ret->ignore = 1;
			return 0;
		}
		tls_msg_len = ((((unsigned int) (pos)[0]) << 24) | (((unsigned int) (pos)[1]) << 16) | (((unsigned int) (pos)[2]) << 8) | ((unsigned int) (pos)[3]));
		wpa_printf(0, "SSL: TLS Message Length: %d",
			   tls_msg_len);
		if (data->tls_in_left == 0) {
			data->tls_in_total = tls_msg_len;
			data->tls_in_left = tls_msg_len;
			wpabuf_free(data->tls_in);
			data->tls_in = 0;
		}
		pos += 4;
		left -= 4;
	}

	ret->ignore = 0;
	ret->methodState = METHOD_MAY_CONT;
	ret->decision = DECISION_FAIL;
	ret->allowNotifications = 1;

	*len = left;
	return pos;
}








 
void eap_peer_tls_reset_input(struct eap_ssl_data *data)
{
	data->tls_in_left = data->tls_in_total = 0;
	wpabuf_free(data->tls_in);
	data->tls_in = 0;
}








 
void eap_peer_tls_reset_output(struct eap_ssl_data *data)
{
	data->tls_out_pos = 0;
	wpabuf_free(data->tls_out);
	data->tls_out = 0;
}









 
int eap_peer_tls_decrypt(struct eap_sm *sm, struct eap_ssl_data *data,
			 const struct wpabuf *in_data,
			 struct wpabuf **in_decrypted)
{
	const struct wpabuf *msg;
	int need_more_input;

	msg = eap_peer_tls_data_reassemble(data, in_data, &need_more_input);
	if (msg == 0)
		return need_more_input ? 1 : -1;

	*in_decrypted = tls_connection_decrypt(sm->ssl_ctx, data->conn, msg);
	eap_peer_tls_reset_input(data);
	if (*in_decrypted == 0) {
		wpa_printf(0, "SSL: Failed to decrypt Phase 2 data");
		return -1;
	}
	return 0;
}












 
int eap_peer_tls_encrypt(struct eap_sm *sm, struct eap_ssl_data *data,
			 EapType eap_type, int peap_version, unsigned char id,
			 const struct wpabuf *in_data,
			 struct wpabuf **out_data)
{
	if (in_data) {
		eap_peer_tls_reset_output(data);
		data->tls_out = tls_connection_encrypt(sm->ssl_ctx, data->conn,
						       in_data);
		if (data->tls_out == 0) {
			wpa_printf(0, "SSL: Failed to encrypt Phase 2 "
				   "data (in_len=%lu)",
				   (unsigned long) wpabuf_len(in_data));
			eap_peer_tls_reset_output(data);
			return -1;
		}
	}

	return eap_tls_process_output(data, eap_type, peap_version, id, 0,
				      out_data);
}












 
int eap_peer_select_phase2_methods(struct eap_peer_config *config,
				   const char *prefix,
				   struct eap_method_type **types,
				   size_t *num_types)
{
	char *start, *pos, *buf;
	struct eap_method_type *methods = 0, *_methods;
	unsigned char method;
	size_t num_methods = 0, prefix_len;

	if (config == 0 || config->phase2 == 0)
		goto get_defaults;

	start = buf = (char*)os_strdup(config->phase2);
	if (buf == 0)
		return -1;

	prefix_len = os_strlen(prefix);

	while (start && *start != '\0') {
		int vendor;
		pos = os_strstr(start, prefix);
		if (pos == 0)
			break;
		if (start != pos && *(pos - 1) != ' ') {
			start = pos + prefix_len;
			continue;
		}

		start = pos + prefix_len;
		pos = os_strchr(start, ' ');
		if (pos)
			*pos++ = '\0';
		method = eap_get_phase2_type(start, &vendor);
		if (vendor == EAP_VENDOR_IETF && method == EAP_TYPE_NONE) {
			wpa_printf(0, "TLS: Unsupported Phase2 EAP "
				   "method '%s'", start);
		} else {
			num_methods++;
			_methods = os_realloc(methods,
					      num_methods * sizeof(*methods));
			if (_methods == 0) {
				os_free(methods);
				os_free(buf);
				return -1;
			}
			methods = _methods;
			methods[num_methods - 1].vendor = vendor;
			methods[num_methods - 1].method = method;
		}

		start = pos;
	}

	os_free(buf);

get_defaults:
	if (methods == 0)
		methods = eap_get_phase2_types(config, &num_methods);

	if (methods == 0) {
		wpa_printf(0, "TLS: No Phase2 EAP methods available");
		return -1;
	}
	wpa_hexdump(0, "TLS: Phase2 EAP types",
		    (unsigned char *) methods,
		    num_methods * sizeof(struct eap_method_type));

	*types = methods;
	*num_types = num_methods;

	return 0;
}









 
int eap_peer_tls_phase2_nak(struct eap_method_type *types, size_t num_types,
			    struct eap_hdr *hdr, struct wpabuf **resp)
{
	unsigned char *pos = (unsigned char *) (hdr + 1);
	size_t i;

	 
	wpa_printf(0, "TLS: Phase 2 Request: Nak type=%d", *pos);
	wpa_hexdump(0, "TLS: Allowed Phase2 EAP types",
		    (unsigned char *) types, num_types * sizeof(struct eap_method_type));
	*resp = eap_msg_alloc(EAP_VENDOR_IETF, EAP_TYPE_NAK, num_types,
			      EAP_CODE_RESPONSE, hdr->identifier);
	if (*resp == 0)
		return -1;

	for (i = 0; i < num_types; i++) {
		if (types[i].vendor == EAP_VENDOR_IETF &&
		    types[i].method < 256)
			wpabuf_put_u8(*resp, types[i].method);
	}

	eap_update_len(*resp);

	return 0;
}
