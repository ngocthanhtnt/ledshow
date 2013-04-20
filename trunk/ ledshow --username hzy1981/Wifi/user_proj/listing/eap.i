#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap.c"





















 

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

#line 25 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap.c"

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



#line 27 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap.c"
#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\pcsc_funcs.h"












 










 
#line 33 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\pcsc_funcs.h"




typedef enum {
	SCARD_GSM_SIM_ONLY,
	SCARD_USIM_ONLY,
	SCARD_TRY_BOTH
} scard_sim_type;


#line 58 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\pcsc_funcs.h"

#line 65 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\pcsc_funcs.h"



#line 28 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap.c"
#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\state_machine.h"























 












 













 
#line 59 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\state_machine.h"











 
#line 78 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\state_machine.h"










 
#line 97 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\state_machine.h"









 












 











 









 


#line 29 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap.c"
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

#line 30 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap.c"
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

#line 31 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap.c"
#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\common/wpa_ctrl.h"












 








 

 


 


 
 

 

 

 

 

 

 

 

 

 

 

 

 

 

 


 

 


 

 

 

 

 

 

 




 





 
#line 100 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\common/wpa_ctrl.h"


 










 
struct wpa_ctrl * wpa_ctrl_open(const char *ctrl_path);







 
void wpa_ctrl_close(struct wpa_ctrl *ctrl);



























 
int wpa_ctrl_request(struct wpa_ctrl *ctrl, const char *cmd, size_t cmd_len,
		     char *reply, size_t *reply_len,
		     void (*msg_cb)(char *msg, size_t len));











 
int wpa_ctrl_attach(struct wpa_ctrl *ctrl);










 
int wpa_ctrl_detach(struct wpa_ctrl *ctrl);














 
int wpa_ctrl_recv(struct wpa_ctrl *ctrl, char *reply, size_t *reply_len);











 
int wpa_ctrl_pending(struct wpa_ctrl *ctrl);














 
int wpa_ctrl_get_fd(struct wpa_ctrl *ctrl);











#line 32 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap.c"
#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common/eap_wsc_common.h"












 

















struct wpabuf * eap_wsc_build_frag_ack(unsigned char id, unsigned char code);

#line 33 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap.c"
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

#line 34 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap.c"
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

#line 35 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap.c"







static int eap_sm_allowMethod(struct eap_sm *sm, int vendor,
				  EapType method);
static struct wpabuf * eap_sm_buildNak(struct eap_sm *sm, int id);
static void eap_sm_processIdentity(struct eap_sm *sm,
				   const struct wpabuf *req);
static void eap_sm_processNotify(struct eap_sm *sm, const struct wpabuf *req);
static struct wpabuf * eap_sm_buildNotify(int id);
static void eap_sm_parseEapReq(struct eap_sm *sm, const struct wpabuf *req);

static const char * eap_sm_method_state_txt(EapMethodState state);
static const char * eap_sm_decision_txt(EapDecision decision);



static int eapol_get_bool(struct eap_sm *sm, enum eapol_bool_var var)
{
	struct eapol_callbacks * cb = sm->eapol_cb;
	return cb->get_bool(sm->eapol_ctx, var);
}


static void eapol_set_bool(struct eap_sm *sm, enum eapol_bool_var var,
			   int value)
{
	struct eapol_callbacks * cb = sm->eapol_cb;
	cb->set_bool(sm->eapol_ctx, var, value);
}


static unsigned int eapol_get_int(struct eap_sm *sm, enum eapol_int_var var)
{
	return sm->eapol_cb->get_int(sm->eapol_ctx, var);
}


static void eapol_set_int(struct eap_sm *sm, enum eapol_int_var var,
			  unsigned int value)
{
	sm->eapol_cb->set_int(sm->eapol_ctx, var, value);
}


static struct wpabuf * eapol_get_eapReqData(struct eap_sm *sm)
{
	return sm->eapol_cb->get_eapReqData(sm->eapol_ctx);
}


static void eap_deinit_prev_method(struct eap_sm *sm, const char *txt)
{
	if (sm->m == 0 || sm->eap_method_priv == 0)
		return;

	wpa_printf(0, "EAP: deinitialize previously used EAP method "
		   "(%d, %s) at %s", sm->selectedMethod, sm->m->name, txt);
	sm->m->deinit(sm, sm->eap_method_priv);
	sm->eap_method_priv = 0;
	sm->m = 0;
}








 
int eap_allowed_method(struct eap_sm *sm, int vendor, unsigned int method)
{
	struct eap_peer_config *config = eap_get_config(sm);
	int i;
	struct eap_method_type *m;

	if (config == 0 || config->eap_methods == 0)
		return 1;

	m = config->eap_methods;
	for (i = 0; m[i].vendor != EAP_VENDOR_IETF ||
		     m[i].method != EAP_TYPE_NONE; i++) {
		if (m[i].vendor == vendor && m[i].method == method)
			return 1;
	}
	return 0;
}






 
static void sm_EAP_INITIALIZE_Enter(struct eap_sm *sm, int global)
{
	if (!global || sm->EAP_state != EAP_INITIALIZE) { sm->changed = 1; wpa_printf(0, "EAP" ": " "EAP" " entering state " "INITIALIZE"); } sm->EAP_state = EAP_INITIALIZE;;
	if (sm->fast_reauth && sm->m && sm->m->has_reauth_data &&
	    sm->m->has_reauth_data(sm, sm->eap_method_priv) &&
	    !sm->prev_failure) {
		wpa_printf(0, "EAP: maintaining EAP method data for "
			   "fast reauthentication");
		sm->m->deinit_for_reauth(sm, sm->eap_method_priv);
	} else {
		eap_deinit_prev_method(sm, "INITIALIZE");
	}
	sm->selectedMethod = EAP_TYPE_NONE;
	sm->methodState = METHOD_NONE;
	sm->allowNotifications = 1;
	sm->decision = DECISION_FAIL;
	eapol_set_int(sm, EAPOL_idleWhile, sm->ClientTimeout);
	eapol_set_bool(sm, EAPOL_eapSuccess, 0);
	eapol_set_bool(sm, EAPOL_eapFail, 0);
	os_free(sm->eapKeyData);
	sm->eapKeyData = 0;
	sm->eapKeyAvailable = 0;
	eapol_set_bool(sm, EAPOL_eapRestart, 0);
	sm->lastId = -1; 
 
	






 
	eapol_set_bool(sm, EAPOL_eapResp, 0);
	eapol_set_bool(sm, EAPOL_eapNoResp, 0);
	sm->num_rounds = 0;
	sm->prev_failure = 0;
}






 
static void sm_EAP_DISABLED_Enter(struct eap_sm *sm, int global)
{
	if (!global || sm->EAP_state != EAP_DISABLED) { sm->changed = 1; wpa_printf(0, "EAP" ": " "EAP" " entering state " "DISABLED"); } sm->EAP_state = EAP_DISABLED;;
	sm->num_rounds = 0;
}






 
static void sm_EAP_IDLE_Enter(struct eap_sm *sm, int global)
{
	if (!global || sm->EAP_state != EAP_IDLE) { sm->changed = 1; wpa_printf(0, "EAP" ": " "EAP" " entering state " "IDLE"); } sm->EAP_state = EAP_IDLE;;
}





 
static void sm_EAP_RECEIVED_Enter(struct eap_sm *sm, int global)
{
	const struct wpabuf *eapReqData;

	if (!global || sm->EAP_state != EAP_RECEIVED) { sm->changed = 1; wpa_printf(0, "EAP" ": " "EAP" " entering state " "RECEIVED"); } sm->EAP_state = EAP_RECEIVED;;
	eapReqData = eapol_get_eapReqData(sm);
	 
	eap_sm_parseEapReq(sm, eapReqData);
	sm->num_rounds++;
}





 
static void sm_EAP_GET_METHOD_Enter(struct eap_sm *sm, int global)
{
	int reinit;
	EapType method;

	if (!global || sm->EAP_state != EAP_GET_METHOD) { sm->changed = 1; wpa_printf(0, "EAP" ": " "EAP" " entering state " "GET_METHOD"); } sm->EAP_state = EAP_GET_METHOD;;

	if (sm->reqMethod == EAP_TYPE_EXPANDED)
		method = sm->reqVendorMethod;
	else
		method = sm->reqMethod;

	if (!eap_sm_allowMethod(sm, sm->reqVendor, method)) {
		wpa_printf(0, "EAP: vendor %u method %u not allowed",
			   sm->reqVendor, method);
		wpa_msg(sm->msg_ctx, 0, "CTRL-EVENT-EAP-PROPOSED-METHOD "
			"vendor=%u method=%u -> NAK",
			sm->reqVendor, method);
		goto nak;
	}

	wpa_msg(sm->msg_ctx, 0, "CTRL-EVENT-EAP-PROPOSED-METHOD "
		"vendor=%u method=%u", sm->reqVendor, method);

	






 
	if (sm->fast_reauth &&
	    sm->m && sm->m->vendor == sm->reqVendor &&
	    sm->m->method == method &&
	    sm->m->has_reauth_data &&
	    sm->m->has_reauth_data(sm, sm->eap_method_priv)) {
		wpa_printf(0, "EAP: Using previous method data"
			   " for fast re-authentication");
		reinit = 1;
	} else {
		eap_deinit_prev_method(sm, "GET_METHOD");
		reinit = 0;
	}

	sm->selectedMethod = sm->reqMethod;
	if (sm->m == 0)
		sm->m = eap_peer_get_eap_method(sm->reqVendor, method);
	if (!sm->m) {
		wpa_printf(0, "EAP: Could not find selected method: "
			   "vendor %d method %d",
			   sm->reqVendor, method);
		goto nak;
	}

	wpa_printf(0, "EAP: Initialize selected EAP method: "
		   "vendor %u method %u (%s)",
		   sm->reqVendor, method, sm->m->name);
	if (reinit)
		sm->eap_method_priv = sm->m->init_for_reauth(
			sm, sm->eap_method_priv);
	else
		sm->eap_method_priv = sm->m->init(sm);

	if (sm->eap_method_priv == 0) {
		struct eap_peer_config *config = eap_get_config(sm);
		wpa_msg(sm->msg_ctx, 0,
			"EAP: Failed to initialize EAP method: vendor %u "
			"method %u (%s)",
			sm->reqVendor, method, sm->m->name);
		sm->m = 0;
		sm->methodState = METHOD_NONE;
		sm->selectedMethod = EAP_TYPE_NONE;
		if (sm->reqMethod == EAP_TYPE_TLS && config &&
		    (config->pending_req_pin ||
		     config->pending_req_passphrase)) {
			



 
			wpa_printf(0, "EAP: Pending PIN/passphrase "
				   "request - skip Nak");
			return;
		}

		goto nak;
	}

	sm->methodState = METHOD_INIT;
	wpa_msg(sm->msg_ctx, 0, "CTRL-EVENT-EAP-METHOD "
		"EAP vendor %u method %u (%s) selected",
		sm->reqVendor, method, sm->m->name);
	return;

nak:
	wpabuf_free(sm->eapRespData);
	sm->eapRespData = 0;
	sm->eapRespData = eap_sm_buildNak(sm, sm->reqId);
}





 
static void sm_EAP_METHOD_Enter(struct eap_sm *sm, int global)
{
	struct wpabuf *eapReqData;
	struct eap_method_ret ret;

	if (!global || sm->EAP_state != EAP_METHOD) { sm->changed = 1; wpa_printf(0, "EAP" ": " "EAP" " entering state " "METHOD"); } sm->EAP_state = EAP_METHOD;;
	if (sm->m == 0) {
		wpa_printf(0, "EAP::METHOD - method not selected");
		return;
	}

	eapReqData = eapol_get_eapReqData(sm);

	












 
	os_memset(&ret, 0, sizeof(ret));
	ret.ignore = sm->ignore;
	ret.methodState = sm->methodState;
	ret.decision = sm->decision;
	ret.allowNotifications = sm->allowNotifications;
	wpabuf_free(sm->eapRespData);
	sm->eapRespData = 0;
	sm->eapRespData = sm->m->process(sm, sm->eap_method_priv, &ret,
					 eapReqData);
	wpa_printf(0, "EAP: method process -> ignore=%s "
		   "methodState=%s decision=%s",
		   ret.ignore ? "TRUE" : "FALSE",
		   eap_sm_method_state_txt(ret.methodState),
		   eap_sm_decision_txt(ret.decision));

	sm->ignore = ret.ignore;
	if (sm->ignore)
		return;
	sm->methodState = ret.methodState;
	sm->decision = ret.decision;
	sm->allowNotifications = ret.allowNotifications;

	if (sm->m->isKeyAvailable && sm->m->getKey &&
	    sm->m->isKeyAvailable(sm, sm->eap_method_priv)) {
		os_free(sm->eapKeyData);
		sm->eapKeyData = sm->m->getKey(sm, sm->eap_method_priv,
					       &sm->eapKeyDataLen);
	}
}





 
static void sm_EAP_SEND_RESPONSE_Enter(struct eap_sm *sm, int global)
{
	if (!global || sm->EAP_state != EAP_SEND_RESPONSE) { sm->changed = 1; wpa_printf(0, "EAP" ": " "EAP" " entering state " "SEND_RESPONSE"); } sm->EAP_state = EAP_SEND_RESPONSE;;
	wpabuf_free(sm->lastRespData);
	if (sm->eapRespData) {
		if (sm->workaround)
			os_memcpy(sm->last_md5, sm->req_md5, 16);
		sm->lastId = sm->reqId;
		sm->lastRespData = wpabuf_dup(sm->eapRespData);
		eapol_set_bool(sm, EAPOL_eapResp, 1);
	} else
		sm->lastRespData = 0;
	eapol_set_bool(sm, EAPOL_eapReq, 0);
	eapol_set_int(sm, EAPOL_idleWhile, sm->ClientTimeout);
}





 
static void sm_EAP_DISCARD_Enter(struct eap_sm *sm, int global)
{
	if (!global || sm->EAP_state != EAP_DISCARD) { sm->changed = 1; wpa_printf(0, "EAP" ": " "EAP" " entering state " "DISCARD"); } sm->EAP_state = EAP_DISCARD;;
	eapol_set_bool(sm, EAPOL_eapReq, 0);
	eapol_set_bool(sm, EAPOL_eapNoResp, 1);
}




 
static void sm_EAP_IDENTITY_Enter(struct eap_sm *sm, int global)
{
	const struct wpabuf *eapReqData;

	if (!global || sm->EAP_state != EAP_IDENTITY) { sm->changed = 1; wpa_printf(0, "EAP" ": " "EAP" " entering state " "IDENTITY"); } sm->EAP_state = EAP_IDENTITY;;
	eapReqData = eapol_get_eapReqData(sm);
	eap_sm_processIdentity(sm, eapReqData);
	wpabuf_free(sm->eapRespData);
	sm->eapRespData = 0;
	sm->eapRespData = eap_sm_buildIdentity(sm, sm->reqId, 0);
}




 
static void sm_EAP_NOTIFICATION_Enter(struct eap_sm *sm, int global)
{
	const struct wpabuf *eapReqData;

	if (!global || sm->EAP_state != EAP_NOTIFICATION) { sm->changed = 1; wpa_printf(0, "EAP" ": " "EAP" " entering state " "NOTIFICATION"); } sm->EAP_state = EAP_NOTIFICATION;;
	eapReqData = eapol_get_eapReqData(sm);
	eap_sm_processNotify(sm, eapReqData);
	wpabuf_free(sm->eapRespData);
	sm->eapRespData = 0;
	sm->eapRespData = eap_sm_buildNotify(sm->reqId);
}




 
static void sm_EAP_RETRANSMIT_Enter(struct eap_sm *sm, int global)
{
	if (!global || sm->EAP_state != EAP_RETRANSMIT) { sm->changed = 1; wpa_printf(0, "EAP" ": " "EAP" " entering state " "RETRANSMIT"); } sm->EAP_state = EAP_RETRANSMIT;;
	wpabuf_free(sm->eapRespData);
	if (sm->lastRespData)
		sm->eapRespData = wpabuf_dup(sm->lastRespData);
	else
		sm->eapRespData = 0;
}






 
static void sm_EAP_SUCCESS_Enter(struct eap_sm *sm, int global)
{
	if (!global || sm->EAP_state != EAP_SUCCESS) { sm->changed = 1; wpa_printf(0, "EAP" ": " "EAP" " entering state " "SUCCESS"); } sm->EAP_state = EAP_SUCCESS;;
	if (sm->eapKeyData != 0)
		sm->eapKeyAvailable = 1;
	eapol_set_bool(sm, EAPOL_eapSuccess, 1);

	



 
	eapol_set_bool(sm, EAPOL_eapReq, 0);

	




 
	eapol_set_bool(sm, EAPOL_eapNoResp, 1);

	wpa_msg(sm->msg_ctx, 0, "CTRL-EVENT-EAP-SUCCESS "
		"EAP authentication completed successfully");
}





 
static void sm_EAP_FAILURE_Enter(struct eap_sm *sm, int global)
{
	if (!global || sm->EAP_state != EAP_FAILURE) { sm->changed = 1; wpa_printf(0, "EAP" ": " "EAP" " entering state " "FAILURE"); } sm->EAP_state = EAP_FAILURE;;
	eapol_set_bool(sm, EAPOL_eapFail, 1);

	



 
	eapol_set_bool(sm, EAPOL_eapReq, 0);

	



 
	eapol_set_bool(sm, EAPOL_eapNoResp, 1);

	wpa_msg(sm->msg_ctx, 0, "CTRL-EVENT-EAP-FAILURE "
		"EAP authentication failed");

	sm->prev_failure = 1;
}


static int eap_success_workaround(struct eap_sm *sm, int reqId, int lastId)
{
	








 
	if (sm->workaround && (reqId == ((lastId + 1) & 0xff) ||
			       reqId == ((lastId + 2) & 0xff))) {
		wpa_printf(0, "EAP: Workaround for unexpected "
			   "identifier field in EAP Success: "
			   "reqId=%d lastId=%d (these are supposed to be "
			   "same)", reqId, lastId);
		return 1;
	}
	wpa_printf(0, "EAP: EAP-Success Id mismatch - reqId=%d "
		   "lastId=%d", reqId, lastId);
	return 0;
}




 

static void eap_peer_sm_step_idle(struct eap_sm *sm)
{
	



 
	if (eapol_get_bool(sm, EAPOL_eapReq))
		sm_EAP_RECEIVED_Enter(sm, 0);
	else if ((eapol_get_bool(sm, EAPOL_altAccept) &&
		  sm->decision != DECISION_FAIL) ||
		 (eapol_get_int(sm, EAPOL_idleWhile) == 0 &&
		  sm->decision == DECISION_UNCOND_SUCC))
		sm_EAP_SUCCESS_Enter(sm, 0);
	else if (eapol_get_bool(sm, EAPOL_altReject) ||
		 (eapol_get_int(sm, EAPOL_idleWhile) == 0 &&
		  sm->decision != DECISION_UNCOND_SUCC) ||
		 (eapol_get_bool(sm, EAPOL_altAccept) &&
		  sm->methodState != METHOD_CONT &&
		  sm->decision == DECISION_FAIL))
		sm_EAP_FAILURE_Enter(sm, 0);
	else if (sm->selectedMethod == EAP_TYPE_LEAP &&
		 sm->leap_done && sm->decision != DECISION_FAIL &&
		 sm->methodState == METHOD_DONE)
		sm_EAP_SUCCESS_Enter(sm, 0);
	else if (sm->selectedMethod == EAP_TYPE_PEAP &&
		 sm->peap_done && sm->decision != DECISION_FAIL &&
		 sm->methodState == METHOD_DONE)
		sm_EAP_SUCCESS_Enter(sm, 0);
}


static int eap_peer_req_is_duplicate(struct eap_sm *sm)
{
	int duplicate;

	duplicate = (sm->reqId == sm->lastId) && sm->rxReq;
	if (sm->workaround && duplicate &&
	    os_memcmp(sm->req_md5, sm->last_md5, 16) != 0) {
		






 
		wpa_printf(0, "EAP: AS used the same Id again, but "
			   "EAP packets were not identical");
		wpa_printf(0, "EAP: workaround - assume this is not a "
			   "duplicate packet");
		duplicate = 0;
	}

	return duplicate;
}


static void eap_peer_sm_step_received(struct eap_sm *sm)
{
	int duplicate = eap_peer_req_is_duplicate(sm);

	



 
	if (sm->rxSuccess && sm->decision != DECISION_FAIL &&
	    (sm->reqId == sm->lastId ||
	     eap_success_workaround(sm, sm->reqId, sm->lastId)))
		sm_EAP_SUCCESS_Enter(sm, 0);
	else if (sm->methodState != METHOD_CONT &&
		 ((sm->rxFailure &&
		   sm->decision != DECISION_UNCOND_SUCC) ||
		  (sm->rxSuccess && sm->decision == DECISION_FAIL &&
		   (sm->selectedMethod != EAP_TYPE_LEAP ||
		    sm->methodState != METHOD_MAY_CONT))) &&
		 (sm->reqId == sm->lastId ||
		  eap_success_workaround(sm, sm->reqId, sm->lastId)))
		sm_EAP_FAILURE_Enter(sm, 0);
	else if (sm->rxReq && duplicate)
		sm_EAP_RETRANSMIT_Enter(sm, 0);
	else if (sm->rxReq && !duplicate &&
		 sm->reqMethod == EAP_TYPE_NOTIFICATION &&
		 sm->allowNotifications)
		sm_EAP_NOTIFICATION_Enter(sm, 0);
	else if (sm->rxReq && !duplicate &&
		 sm->selectedMethod == EAP_TYPE_NONE &&
		 sm->reqMethod == EAP_TYPE_IDENTITY)
		sm_EAP_IDENTITY_Enter(sm, 0);
	else if (sm->rxReq && !duplicate &&
		 sm->selectedMethod == EAP_TYPE_NONE &&
		 sm->reqMethod != EAP_TYPE_IDENTITY &&
		 sm->reqMethod != EAP_TYPE_NOTIFICATION)
		sm_EAP_GET_METHOD_Enter(sm, 0);
	else if (sm->rxReq && !duplicate &&
		 sm->reqMethod == sm->selectedMethod &&
		 sm->methodState != METHOD_DONE)
		sm_EAP_METHOD_Enter(sm, 0);
	else if (sm->selectedMethod == EAP_TYPE_LEAP &&
		 (sm->rxSuccess || sm->rxResp))
		sm_EAP_METHOD_Enter(sm, 0);
	else
		sm_EAP_DISCARD_Enter(sm, 0);
}


static void eap_peer_sm_step_local(struct eap_sm *sm)
{
	switch (sm->EAP_state) {
	case EAP_INITIALIZE:
		sm_EAP_IDLE_Enter(sm, 0);
		break;
	case EAP_DISABLED:
		if (eapol_get_bool(sm, EAPOL_portEnabled) &&
		    !sm->force_disabled)
			sm_EAP_INITIALIZE_Enter(sm, 0);
		break;
	case EAP_IDLE:
		eap_peer_sm_step_idle(sm);
		break;
	case EAP_RECEIVED:
		eap_peer_sm_step_received(sm);
		break;
	case EAP_GET_METHOD:
		if (sm->selectedMethod == sm->reqMethod)
			sm_EAP_METHOD_Enter(sm, 0);
		else
			sm_EAP_SEND_RESPONSE_Enter(sm, 0);
		break;
	case EAP_METHOD:
		if (sm->ignore)
			sm_EAP_DISCARD_Enter(sm, 0);
		else
			sm_EAP_SEND_RESPONSE_Enter(sm, 0);
		break;
	case EAP_SEND_RESPONSE:
		sm_EAP_IDLE_Enter(sm, 0);
		break;
	case EAP_DISCARD:
		sm_EAP_IDLE_Enter(sm, 0);
		break;
	case EAP_IDENTITY:
		sm_EAP_SEND_RESPONSE_Enter(sm, 0);
		break;
	case EAP_NOTIFICATION:
		sm_EAP_SEND_RESPONSE_Enter(sm, 0);
		break;
	case EAP_RETRANSMIT:
		sm_EAP_SEND_RESPONSE_Enter(sm, 0);
		break;
	case EAP_SUCCESS:
		break;
	case EAP_FAILURE:
		break;
	}
}


static void sm_EAP_Step(struct eap_sm *sm)
{
	 
	if (eapol_get_bool(sm, EAPOL_eapRestart) &&
	    eapol_get_bool(sm, EAPOL_portEnabled))
		sm_EAP_INITIALIZE_Enter(sm, 1);
	else if (!eapol_get_bool(sm, EAPOL_portEnabled) || sm->force_disabled)
		sm_EAP_DISABLED_Enter(sm, 1);
	else if (sm->num_rounds > 50) {
		






 
		if (sm->num_rounds == 50 + 1) {
			wpa_msg(sm->msg_ctx, 0, "EAP: more than %d "
				"authentication rounds - abort",
				50);
			sm->num_rounds++;
			sm_EAP_FAILURE_Enter(sm, 1);
		}
	} else {
		 
		eap_peer_sm_step_local(sm);
	}
}


static int eap_sm_allowMethod(struct eap_sm *sm, int vendor,
				  EapType method)
{
	if (!eap_allowed_method(sm, vendor, method)) {
		wpa_printf(0, "EAP: configuration does not allow: "
			   "vendor %u method %u", vendor, method);
		return 0;
	}
	if (eap_peer_get_eap_method(vendor, method))
		return 1;
	wpa_printf(0, "EAP: not included in build: "
		   "vendor %u method %u", vendor, method);
	return 0;
}


static struct wpabuf * eap_sm_build_expanded_nak(
	struct eap_sm *sm, int id, const struct eap_method *methods,
	size_t count)
{
	struct wpabuf *resp;
	int found = 0;
	const struct eap_method *m;

	wpa_printf(0, "EAP: Building expanded EAP-Nak");

	 
	resp = eap_msg_alloc(EAP_VENDOR_IETF, EAP_TYPE_EXPANDED,
			     8 + 8 * (count + 1), EAP_CODE_RESPONSE, id);
	if (resp == 0)
		return 0;

	wpabuf_put_be24(resp, EAP_VENDOR_IETF);
	wpabuf_put_be32(resp, EAP_TYPE_NAK);

	for (m = methods; m; m = m->next) {
		if (sm->reqVendor == m->vendor &&
		    sm->reqVendorMethod == m->method)
			continue;  
		if (eap_allowed_method(sm, m->vendor, m->method)) {
			wpa_printf(0, "EAP: allowed type: "
				   "vendor=%u method=%u",
				   m->vendor, m->method);
			wpabuf_put_u8(resp, EAP_TYPE_EXPANDED);
			wpabuf_put_be24(resp, m->vendor);
			wpabuf_put_be32(resp, m->method);

			found++;
		}
	}
	if (!found) {
		wpa_printf(0, "EAP: no more allowed methods");
		wpabuf_put_u8(resp, EAP_TYPE_EXPANDED);
		wpabuf_put_be24(resp, EAP_VENDOR_IETF);
		wpabuf_put_be32(resp, EAP_TYPE_NONE);
	}

	eap_update_len(resp);

	return resp;
}


static struct wpabuf * eap_sm_buildNak(struct eap_sm *sm, int id)
{
	struct wpabuf *resp;
	unsigned char *start;
	int found = 0, expanded_found = 0;
	size_t count;
	const struct eap_method *methods, *m;

	wpa_printf(0, "EAP: Building EAP-Nak (requested type %u "
		   "vendor=%u method=%u not allowed)", sm->reqMethod,
		   sm->reqVendor, sm->reqVendorMethod);
	methods = eap_peer_get_methods(&count);
	if (methods == 0)
		return 0;
	if (sm->reqMethod == EAP_TYPE_EXPANDED)
		return eap_sm_build_expanded_nak(sm, id, methods, count);

	 
	resp = eap_msg_alloc(EAP_VENDOR_IETF, EAP_TYPE_NAK,
			     sizeof(struct eap_hdr) + 1 + count + 1,
			     EAP_CODE_RESPONSE, id);
	if (resp == 0)
		return 0;

	start = wpabuf_put(resp, 0);
	for (m = methods; m; m = m->next) {
		if (m->vendor == EAP_VENDOR_IETF && m->method == sm->reqMethod)
			continue;  
		if (eap_allowed_method(sm, m->vendor, m->method)) {
			if (m->vendor != EAP_VENDOR_IETF) {
				if (expanded_found)
					continue;
				expanded_found = 1;
				wpabuf_put_u8(resp, EAP_TYPE_EXPANDED);
			} else
				wpabuf_put_u8(resp, m->method);
			found++;
		}
	}
	if (!found)
		wpabuf_put_u8(resp, EAP_TYPE_NONE);
	wpa_hexdump(0, "EAP: allowed methods", start, found);

	eap_update_len(resp);

	return resp;
}


static void eap_sm_processIdentity(struct eap_sm *sm, const struct wpabuf *req)
{
	const struct eap_hdr *hdr = wpabuf_head(req);
	const unsigned char *pos = (const unsigned char *) (hdr + 1);
	pos++;

	wpa_msg(sm->msg_ctx, 0, "CTRL-EVENT-EAP-STARTED "
		"EAP authentication started");

	





 
	
 
	wpa_hexdump_ascii(0, "EAP: EAP-Request Identity data",
			  pos, ((((unsigned short) ((unsigned short) (unsigned short) (hdr->length)) << 8) & 0xff00) | (((unsigned short) ((unsigned short) (unsigned short) (hdr->length)) >> 8) & 0xff)) - 5);
}


#line 919 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap.c"


static int eap_sm_set_scard_pin(struct eap_sm *sm,
				struct eap_peer_config *conf)
{
#line 939 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap.c"
	return -1;

}

static int eap_sm_get_scard_identity(struct eap_sm *sm,
				     struct eap_peer_config *conf)
{
#line 952 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap.c"
	return -1;

}












 
struct wpabuf * eap_sm_buildIdentity(struct eap_sm *sm, int id, int encrypted)
{
	struct eap_peer_config *config = eap_get_config(sm);
	struct wpabuf *resp;
	const unsigned char *identity;
	size_t identity_len;

	if (config == 0) {
		wpa_printf(0, "EAP: buildIdentity: configuration "
			   "was not available");
		return 0;
	}

	if (sm->m && sm->m->get_identity &&
	    (identity = sm->m->get_identity(sm, sm->eap_method_priv,
					    &identity_len)) != 0) {
		wpa_hexdump_ascii(0, "EAP: using method re-auth "
				  "identity", identity, identity_len);
	} else if (!encrypted && config->anonymous_identity) {
		identity = config->anonymous_identity;
		identity_len = config->anonymous_identity_len;
		wpa_hexdump_ascii(0, "EAP: using anonymous identity",
				  identity, identity_len);
	} else {
		identity = config->identity;
		identity_len = config->identity_len;
		wpa_hexdump_ascii(0, "EAP: using real identity",
				  identity, identity_len);
	}

	if (identity == 0) {
		wpa_printf(0, "EAP: buildIdentity: identity "
			   "configuration was not available");
		if (config->pcsc) {
			if (eap_sm_get_scard_identity(sm, config) < 0)
				return 0;
			identity = config->identity;
			identity_len = config->identity_len;
			wpa_hexdump_ascii(0, "permanent identity from "
					  "IMSI", identity, identity_len);
		} else {
			eap_sm_request_identity(sm);
			return 0;
		}
	} else if (config->pcsc) {
		if (eap_sm_set_scard_pin(sm, config) < 0)
			return 0;
	}

	resp = eap_msg_alloc(EAP_VENDOR_IETF, EAP_TYPE_IDENTITY, identity_len,
			     EAP_CODE_RESPONSE, id);
	if (resp == 0)
		return 0;

	wpabuf_put_data(resp, identity, identity_len);

	return resp;
}


static void eap_sm_processNotify(struct eap_sm *sm, const struct wpabuf *req)
{
	const unsigned char *pos;
	char *msg;
	size_t i, msg_len;

	pos = eap_hdr_validate(EAP_VENDOR_IETF, EAP_TYPE_NOTIFICATION, req,
			       &msg_len);
	if (pos == 0)
		return;
	wpa_hexdump_ascii(0, "EAP: EAP-Request Notification data",
			  pos, msg_len);

	msg = os_malloc(msg_len + 1);
	if (msg == 0)
		return;
	for (i = 0; i < msg_len; i++)
		msg[i] = ((* __rt_ctype_table())[pos[i]] & (8+16+32+2+4)) ? (char) pos[i] : '_';
	msg[msg_len] = '\0';
	wpa_msg(sm->msg_ctx, 0, "%s%s",
		"CTRL-EVENT-EAP-NOTIFICATION ", msg);
	os_free(msg);
}


static struct wpabuf * eap_sm_buildNotify(int id)
{
	struct wpabuf *resp;

	wpa_printf(0, "EAP: Generating EAP-Response Notification");
	resp = eap_msg_alloc(EAP_VENDOR_IETF, EAP_TYPE_NOTIFICATION, 0,
			     EAP_CODE_RESPONSE, id);
	if (resp == 0)
		return 0;

	return resp;
}


static void eap_sm_parseEapReq(struct eap_sm *sm, const struct wpabuf *req)
{
	const struct eap_hdr *hdr;
	size_t plen;
	const unsigned char *pos;

	sm->rxReq = sm->rxResp = sm->rxSuccess = sm->rxFailure = 0;
	sm->reqId = 0;
	sm->reqMethod = EAP_TYPE_NONE;
	sm->reqVendor = EAP_VENDOR_IETF;
	sm->reqVendorMethod = EAP_TYPE_NONE;

	if (req == 0 || wpabuf_len(req) < sizeof(*hdr))
		return;

	hdr = wpabuf_head(req);
	plen = ((((unsigned short) ((unsigned short) (unsigned short) (hdr->length)) << 8) & 0xff00) | (((unsigned short) ((unsigned short) (unsigned short) (hdr->length)) >> 8) & 0xff));
	if (plen > wpabuf_len(req)) {
		wpa_printf(0, "EAP: Ignored truncated EAP-Packet "
			   "(len=%lu plen=%lu)",
			   (unsigned long) wpabuf_len(req),
			   (unsigned long) plen);
		return;
	}

	sm->reqId = hdr->identifier;

	if (sm->workaround) {
		const unsigned char *addr[1];
		addr[0] = wpabuf_head(req);
		md5_vector(1, addr, &plen, sm->req_md5);
	}

	switch (hdr->code) {
	case EAP_CODE_REQUEST:
		if (plen < sizeof(*hdr) + 1) {
			wpa_printf(0, "EAP: Too short EAP-Request - "
				   "no Type field");
			return;
		}
		sm->rxReq = 1;
		pos = (const unsigned char *) (hdr + 1);
		sm->reqMethod = *pos++;
		if (sm->reqMethod == EAP_TYPE_EXPANDED) {
			if (plen < sizeof(*hdr) + 8) {
				wpa_printf(0, "EAP: Ignored truncated "
					   "expanded EAP-Packet (plen=%lu)",
					   (unsigned long) plen);
				return;
			}
			sm->reqVendor = ((((unsigned int) (pos)[0]) << 16) | (((unsigned int) (pos)[1]) << 8) | ((unsigned int) (pos)[2]));
			pos += 3;
			sm->reqVendorMethod = ((((unsigned int) (pos)[0]) << 24) | (((unsigned int) (pos)[1]) << 16) | (((unsigned int) (pos)[2]) << 8) | ((unsigned int) (pos)[3]));
		}
		wpa_printf(0, "EAP: Received EAP-Request id=%d "
			   "method=%u vendor=%u vendorMethod=%u",
			   sm->reqId, sm->reqMethod, sm->reqVendor,
			   sm->reqVendorMethod);
		break;
	case EAP_CODE_RESPONSE:
		if (sm->selectedMethod == EAP_TYPE_LEAP) {
			



 
			if (plen < sizeof(*hdr) + 1) {
				wpa_printf(0, "EAP: Too short "
					   "EAP-Response - no Type field");
				return;
			}
			sm->rxResp = 1;
			pos = (const unsigned char *) (hdr + 1);
			sm->reqMethod = *pos;
			wpa_printf(0, "EAP: Received EAP-Response for "
				   "LEAP method=%d id=%d",
				   sm->reqMethod, sm->reqId);
			break;
		}
		wpa_printf(0, "EAP: Ignored EAP-Response");
		break;
	case EAP_CODE_SUCCESS:
		wpa_printf(0, "EAP: Received EAP-Success");
		sm->rxSuccess = 1;
		break;
	case EAP_CODE_FAILURE:
		wpa_printf(0, "EAP: Received EAP-Failure");
		sm->rxFailure = 1;
		break;
	default:
		wpa_printf(0, "EAP: Ignored EAP-Packet with unknown "
			   "code %d", hdr->code);
		break;
	}
}


static void eap_peer_sm_tls_event(void *ctx, enum tls_event ev,
				  union tls_event_data *data)
{
	struct eap_sm *sm = ctx;
	char *hash_hex = 0;
	char *cert_hex = 0;

	switch (ev) {
	case TLS_CERT_CHAIN_FAILURE:
		wpa_msg(sm->msg_ctx, 0, "CTRL-EVENT-EAP-TLS-CERT-ERROR "
			"reason=%d depth=%d subject='%s' err='%s'",
			data->cert_fail.reason,
			data->cert_fail.depth,
			data->cert_fail.subject,
			data->cert_fail.reason_txt);
		break;
	case TLS_PEER_CERTIFICATE:
		if (data->peer_cert.hash) {
			size_t len = data->peer_cert.hash_len * 2 + 1;
			hash_hex = os_malloc(len);
			if (hash_hex) {
				wpa_snprintf_hex(hash_hex, len,
						 data->peer_cert.hash,
						 data->peer_cert.hash_len);
			}
		}
		wpa_msg(sm->msg_ctx, 0, "CTRL-EVENT-EAP-PEER-CERT "
			"depth=%d subject='%s'%s%s",
			data->peer_cert.depth, data->peer_cert.subject,
			hash_hex ? " hash=" : "", hash_hex ? hash_hex : "");

		if (data->peer_cert.cert) {
			size_t len = wpabuf_len(data->peer_cert.cert) * 2 + 1;
			cert_hex = os_malloc(len);
			if (cert_hex == 0)
				break;
			wpa_snprintf_hex(cert_hex, len,
					 wpabuf_head(data->peer_cert.cert),
					 wpabuf_len(data->peer_cert.cert));
			wpa_msg_ctrl(sm->msg_ctx, 0,
				     "CTRL-EVENT-EAP-PEER-CERT "
				     "depth=%d subject='%s' cert=%s",
				     data->peer_cert.depth,
				     data->peer_cert.subject,
				     cert_hex);
		}
		break;
	}

	os_free(hash_hex);
	os_free(cert_hex);
}















 
struct eap_sm * eap_peer_sm_init(void *eapol_ctx,
				 struct eapol_callbacks *eapol_cb,
				 void *msg_ctx, struct eap_config *conf)
{
	struct eap_sm *sm;
	struct tls_config tlsconf;

	sm = os_zalloc(sizeof(*sm));
	if (sm == 0)
		return 0;
	sm->eapol_ctx = eapol_ctx;
	sm->eapol_cb = eapol_cb;
	sm->msg_ctx = msg_ctx;
	sm->ClientTimeout = 60;
	sm->wps = conf->wps;

	os_memset(&tlsconf, 0, sizeof(tlsconf));
	tlsconf.opensc_engine_path = conf->opensc_engine_path;
	tlsconf.pkcs11_engine_path = conf->pkcs11_engine_path;
	tlsconf.pkcs11_module_path = conf->pkcs11_module_path;



	tlsconf.event_cb = eap_peer_sm_tls_event;
	tlsconf.cb_ctx = sm;
	sm->ssl_ctx = tls_init(&tlsconf);
	if (sm->ssl_ctx == 0) {
		wpa_printf(0, "SSL: Failed to initialize TLS "
			   "context.");
		os_free(sm);
		return 0;
	}

	return sm;
}








 
void eap_peer_sm_deinit(struct eap_sm *sm)
{
	if (sm == 0)
		return;
	eap_deinit_prev_method(sm, "EAP deinit");
	eap_sm_abort(sm);
	tls_deinit(sm->ssl_ctx);
	os_free(sm);
}










 
int eap_peer_sm_step(struct eap_sm *sm)
{
	int res = 0;
	do {
		sm->changed = 0;
		sm_EAP_Step(sm);
		if (sm->changed)
			res = 1;
	} while (sm->changed);
	return res;
}








 
void eap_sm_abort(struct eap_sm *sm)
{
	wpabuf_free(sm->lastRespData);
	sm->lastRespData = 0;
	wpabuf_free(sm->eapRespData);
	sm->eapRespData = 0;
	os_free(sm->eapKeyData);
	sm->eapKeyData = 0;

	

 
	eapol_set_bool(sm, EAPOL_eapSuccess, 0);
}


#line 1367 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap.c"



static const char * eap_sm_method_state_txt(EapMethodState state)
{
	switch (state) {
	case METHOD_NONE:
		return "NONE";
	case METHOD_INIT:
		return "INIT";
	case METHOD_CONT:
		return "CONT";
	case METHOD_MAY_CONT:
		return "MAY_CONT";
	case METHOD_DONE:
		return "DONE";
	default:
		return "UNKNOWN";
	}
}


static const char * eap_sm_decision_txt(EapDecision decision)
{
	switch (decision) {
	case DECISION_FAIL:
		return "FAIL";
	case DECISION_COND_SUCC:
		return "COND_SUCC";
	case DECISION_UNCOND_SUCC:
		return "UNCOND_SUCC";
	default:
		return "UNKNOWN";
	}
}



#line 1478 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap.c"



typedef enum {
	TYPE_IDENTITY, TYPE_PASSWORD, TYPE_OTP, TYPE_PIN, TYPE_NEW_PASSWORD,
	TYPE_PASSPHRASE
} eap_ctrl_req_type;

static void eap_sm_request(struct eap_sm *sm, eap_ctrl_req_type type,
			   const char *msg, size_t msglen)
{
	struct eap_peer_config *config;
	char *field, *txt, *tmp;

	if (sm == 0)
		return;
	config = eap_get_config(sm);
	if (config == 0)
		return;

	switch (type) {
	case TYPE_IDENTITY:
		field = "IDENTITY";
		txt = "Identity";
		config->pending_req_identity++;
		break;
	case TYPE_PASSWORD:
		field = "PASSWORD";
		txt = "Password";
		config->pending_req_password++;
		break;
	case TYPE_NEW_PASSWORD:
		field = "NEW_PASSWORD";
		txt = "New Password";
		config->pending_req_new_password++;
		break;
	case TYPE_PIN:
		field = "PIN";
		txt = "PIN";
		config->pending_req_pin++;
		break;
	case TYPE_OTP:
		field = "OTP";
		if (msg) {
			tmp = os_malloc(msglen + 3);
			if (tmp == 0)
				return;
			tmp[0] = '[';
			os_memcpy(tmp + 1, msg, msglen);
			tmp[msglen + 1] = ']';
			tmp[msglen + 2] = '\0';
			txt = tmp;
			os_free(config->pending_req_otp);
			config->pending_req_otp = tmp;
			config->pending_req_otp_len = msglen + 3;
		} else {
			if (config->pending_req_otp == 0)
				return;
			txt = config->pending_req_otp;
		}
		break;
	case TYPE_PASSPHRASE:
		field = "PASSPHRASE";
		txt = "Private key passphrase";
		config->pending_req_passphrase++;
		break;
	default:
		return;
	}

	if (sm->eapol_cb->eap_param_needed)
		sm->eapol_cb->eap_param_needed(sm->eapol_ctx, field, txt);
}













 
void eap_sm_request_identity(struct eap_sm *sm)
{
	eap_sm_request(sm, TYPE_IDENTITY, 0, 0);
}










 
void eap_sm_request_password(struct eap_sm *sm)
{
	eap_sm_request(sm, TYPE_PASSWORD, 0, 0);
}










 
void eap_sm_request_new_password(struct eap_sm *sm)
{
	eap_sm_request(sm, TYPE_NEW_PASSWORD, 0, 0);
}










 
void eap_sm_request_pin(struct eap_sm *sm)
{
	eap_sm_request(sm, TYPE_PIN, 0, 0);
}











 
void eap_sm_request_otp(struct eap_sm *sm, const char *msg, size_t msg_len)
{
	eap_sm_request(sm, TYPE_OTP, msg, msg_len);
}










 
void eap_sm_request_passphrase(struct eap_sm *sm)
{
	eap_sm_request(sm, TYPE_PASSPHRASE, 0, 0);
}








 
void eap_sm_notify_ctrl_attached(struct eap_sm *sm)
{
	struct eap_peer_config *config = eap_get_config(sm);

	if (config == 0)
		return;

	


 
	if (config->pending_req_identity)
		eap_sm_request_identity(sm);
	if (config->pending_req_password)
		eap_sm_request_password(sm);
	if (config->pending_req_new_password)
		eap_sm_request_new_password(sm);
	if (config->pending_req_otp)
		eap_sm_request_otp(sm, 0, 0);
	if (config->pending_req_pin)
		eap_sm_request_pin(sm);
	if (config->pending_req_passphrase)
		eap_sm_request_passphrase(sm);
}


static int eap_allowed_phase2_type(int vendor, int type)
{
	if (vendor != EAP_VENDOR_IETF)
		return 0;
	return type != EAP_TYPE_PEAP && type != EAP_TYPE_TTLS &&
		type != EAP_TYPE_FAST;
}











 
unsigned int eap_get_phase2_type(const char *name, int *vendor)
{
	int v;
	unsigned char type = eap_peer_get_type(name, &v);
	if (eap_allowed_phase2_type(v, type)) {
		*vendor = v;
		return type;
	}
	*vendor = EAP_VENDOR_IETF;
	return EAP_TYPE_NONE;
}










 
struct eap_method_type * eap_get_phase2_types(struct eap_peer_config *config,
					      size_t *count)
{
	struct eap_method_type *buf;
	unsigned int method;
	int vendor;
	size_t mcount;
	const struct eap_method *methods, *m;

	methods = eap_peer_get_methods(&mcount);
	if (methods == 0)
		return 0;
	*count = 0;
	buf = os_malloc(mcount * sizeof(struct eap_method_type));
	if (buf == 0)
		return 0;

	for (m = methods; m; m = m->next) {
		vendor = m->vendor;
		method = m->method;
		if (eap_allowed_phase2_type(vendor, method)) {
			if (vendor == EAP_VENDOR_IETF &&
			    method == EAP_TYPE_TLS && config &&
			    config->private_key2 == 0)
				continue;
			buf[*count].vendor = vendor;
			buf[*count].method = method;
			(*count)++;
		}
	}

	return buf;
}






 
void eap_set_fast_reauth(struct eap_sm *sm, int enabled)
{
	sm->fast_reauth = enabled;
}






 
void eap_set_workaround(struct eap_sm *sm, unsigned int workaround)
{
	sm->workaround = workaround;
}











 
struct eap_peer_config * eap_get_config(struct eap_sm *sm)
{
	return sm->eapol_cb->get_config(sm->eapol_ctx);
}







 
const unsigned char * eap_get_config_identity(struct eap_sm *sm, size_t *len)
{
	struct eap_peer_config *config = eap_get_config(sm);
	if (config == 0)
		return 0;
	*len = config->identity_len;
	return config->identity;
}







 
const unsigned char * eap_get_config_password(struct eap_sm *sm, size_t *len)
{
	struct eap_peer_config *config = eap_get_config(sm);
	if (config == 0)
		return 0;
	*len = config->password_len;
	return config->password;
}










 
const unsigned char * eap_get_config_password2(struct eap_sm *sm, size_t *len, int *hash)
{
	struct eap_peer_config *config = eap_get_config(sm);
	if (config == 0)
		return 0;
	*len = config->password_len;
	if (hash)
		*hash = !!(config->flags & (1 << (0)));
	return config->password;
}







 
const unsigned char * eap_get_config_new_password(struct eap_sm *sm, size_t *len)
{
	struct eap_peer_config *config = eap_get_config(sm);
	if (config == 0)
		return 0;
	*len = config->new_password_len;
	return config->new_password;
}







 
const unsigned char * eap_get_config_otp(struct eap_sm *sm, size_t *len)
{
	struct eap_peer_config *config = eap_get_config(sm);
	if (config == 0)
		return 0;
	*len = config->otp_len;
	return config->otp;
}









 
void eap_clear_config_otp(struct eap_sm *sm)
{
	struct eap_peer_config *config = eap_get_config(sm);
	if (config == 0)
		return;
	os_memset(config->otp, 0, config->otp_len);
	os_free(config->otp);
	config->otp = 0;
	config->otp_len = 0;
}






 
const char * eap_get_config_phase1(struct eap_sm *sm)
{
	struct eap_peer_config *config = eap_get_config(sm);
	if (config == 0)
		return 0;
	return config->phase1;
}






 
const char * eap_get_config_phase2(struct eap_sm *sm)
{
	struct eap_peer_config *config = eap_get_config(sm);
	if (config == 0)
		return 0;
	return config->phase2;
}






 
int eap_key_available(struct eap_sm *sm)
{
	return sm ? sm->eapKeyAvailable : 0;
}










 
void eap_notify_success(struct eap_sm *sm)
{
	if (sm) {
		sm->decision = DECISION_COND_SUCC;
		sm->EAP_state = EAP_SUCCESS;
	}
}








 
void eap_notify_lower_layer_success(struct eap_sm *sm)
{
	if (sm == 0)
		return;


	if (eapol_get_bool(sm, EAPOL_eapSuccess) ||
	    sm->decision == DECISION_FAIL ||
	    (sm->methodState != METHOD_MAY_CONT &&
	     sm->methodState != METHOD_DONE))
		return;

	if (sm->eapKeyData != 0)
		sm->eapKeyAvailable = 1;
	eapol_set_bool(sm, EAPOL_eapSuccess, 1);
	wpa_msg(sm->msg_ctx, 0, "CTRL-EVENT-EAP-SUCCESS "
		"EAP authentication completed successfully (based on lower "
		"layer success)");
}












 
const unsigned char * eap_get_eapKeyData(struct eap_sm *sm, size_t *len)
{
	if (sm == 0 || sm->eapKeyData == 0) {
		*len = 0;
		return 0;
	}

	*len = sm->eapKeyDataLen;
	return sm->eapKeyData;
}











 
struct wpabuf * eap_get_eapRespData(struct eap_sm *sm)
{
	struct wpabuf *resp;

	if (sm == 0 || sm->eapRespData == 0)
		return 0;

	resp = sm->eapRespData;
	sm->eapRespData = 0;

	return resp;
}









 
void eap_register_scard_ctx(struct eap_sm *sm, void *ctx)
{
	if (sm)
		sm->scard_ctx = ctx;
}









 
void eap_set_config_blob(struct eap_sm *sm, struct wpa_config_blob *blob)
{

	sm->eapol_cb->set_config_blob(sm->eapol_ctx, blob);

}







 
const struct wpa_config_blob * eap_get_config_blob(struct eap_sm *sm,
						   const char *name)
{

	return sm->eapol_cb->get_config_blob(sm->eapol_ctx, name);



}









 
void eap_set_force_disabled(struct eap_sm *sm, int disabled)
{
	sm->force_disabled = disabled;
}


 







 
void eap_notify_pending(struct eap_sm *sm)
{
	sm->eapol_cb->notify_pending(sm->eapol_ctx);
}





 
void eap_invalidate_cached_session(struct eap_sm *sm)
{
	if (sm)
		eap_deinit_prev_method(sm, "invalidate");
}


int eap_is_wps_pbc_enrollee(struct eap_peer_config *conf)
{
	if (conf->identity_len != 29 ||
	    os_memcmp(conf->identity, "WFA-SimpleConfig-Enrollee-1-0", 29))
		return 0;  

	if (conf->phase1 == 0 || os_strstr(conf->phase1, "pbc=1") == 0)
		return 0;  

	return 1;
}


int eap_is_wps_pin_enrollee(struct eap_peer_config *conf)
{
	if (conf->identity_len != 29 ||
	    os_memcmp(conf->identity, "WFA-SimpleConfig-Enrollee-1-0", 29))
		return 0;  

	if (conf->phase1 == 0 || os_strstr(conf->phase1, "pin=") == 0)
		return 0;  

	return 1;
}
