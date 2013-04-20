#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_fast_pac.c"












 

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

#line 16 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_fast_pac.c"

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



#line 18 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_fast_pac.c"
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

#line 19 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_fast_pac.c"
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

#line 20 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_fast_pac.c"
#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_fast_pac.h"












 




#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common/eap_fast_common.h"












 
















 








 









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

#line 19 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_fast_pac.h"

struct eap_fast_pac {
	struct eap_fast_pac *next;

	unsigned char pac_key[32];
	unsigned char *pac_opaque;
	size_t pac_opaque_len;
	unsigned char *pac_info;
	size_t pac_info_len;
	unsigned char *a_id;
	size_t a_id_len;
	unsigned char *i_id;
	size_t i_id_len;
	unsigned char *a_id_info;
	size_t a_id_info_len;
	unsigned short pac_type;
};


void eap_fast_free_pac(struct eap_fast_pac *pac);
struct eap_fast_pac * eap_fast_get_pac(struct eap_fast_pac *pac_root,
				       const unsigned char *a_id, size_t a_id_len,
				       unsigned short pac_type);
int eap_fast_add_pac(struct eap_fast_pac **pac_root,
		     struct eap_fast_pac **pac_current,
		     struct eap_fast_pac *entry);
int eap_fast_load_pac(struct eap_sm *sm, struct eap_fast_pac **pac_root,
		      const char *pac_file);
int eap_fast_save_pac(struct eap_sm *sm, struct eap_fast_pac *pac_root,
		      const char *pac_file);
size_t eap_fast_pac_list_truncate(struct eap_fast_pac *pac_root,
				  size_t max_len);
int eap_fast_load_pac_bin(struct eap_sm *sm, struct eap_fast_pac **pac_root,
			  const char *pac_file);
int eap_fast_save_pac_bin(struct eap_sm *sm, struct eap_fast_pac *pac_root,
			  const char *pac_file);

#line 21 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_fast_pac.c"

 


 
static const char *pac_file_hdr =
	"wpa_supplicant EAP-FAST PAC file - version 1";















 











 
void eap_fast_free_pac(struct eap_fast_pac *pac)
{
	os_free(pac->pac_opaque);
	os_free(pac->pac_info);
	os_free(pac->a_id);
	os_free(pac->i_id);
	os_free(pac->a_id_info);
	os_free(pac);
}









 
struct eap_fast_pac * eap_fast_get_pac(struct eap_fast_pac *pac_root,
				       const unsigned char *a_id, size_t a_id_len,
				       unsigned short pac_type)
{
	struct eap_fast_pac *pac = pac_root;

	while (pac) {
		if (pac->pac_type == pac_type && pac->a_id_len == a_id_len &&
		    os_memcmp(pac->a_id, a_id, a_id_len) == 0) {
			return pac;
		}
		pac = pac->next;
	}
	return 0;
}


static void eap_fast_remove_pac(struct eap_fast_pac **pac_root,
				struct eap_fast_pac **pac_current,
				const unsigned char *a_id, size_t a_id_len, unsigned short pac_type)
{
	struct eap_fast_pac *pac, *prev;

	pac = *pac_root;
	prev = 0;

	while (pac) {
		if (pac->pac_type == pac_type && pac->a_id_len == a_id_len &&
		    os_memcmp(pac->a_id, a_id, a_id_len) == 0) {
			if (prev == 0)
				*pac_root = pac->next;
			else
				prev->next = pac->next;
			if (*pac_current == pac)
				*pac_current = 0;
			eap_fast_free_pac(pac);
			break;
		}
		prev = pac;
		pac = pac->next;
	}
}


static int eap_fast_copy_buf(unsigned char **dst, size_t *dst_len,
			     const unsigned char *src, size_t src_len)
{
	if (src) {
		*dst = os_malloc(src_len);
		if (*dst == 0)
			return -1;
		os_memcpy(*dst, src, src_len);
		*dst_len = src_len;
	}
	return 0;
}













 
int eap_fast_add_pac(struct eap_fast_pac **pac_root,
		     struct eap_fast_pac **pac_current,
		     struct eap_fast_pac *entry)
{
	struct eap_fast_pac *pac;

	if (entry == 0 || entry->a_id == 0)
		return -1;

	 
	eap_fast_remove_pac(pac_root, pac_current,
			    entry->a_id, entry->a_id_len, entry->pac_type);

	 
	pac = os_zalloc(sizeof(*pac));
	if (pac == 0)
		return -1;

	pac->pac_type = entry->pac_type;
	os_memcpy(pac->pac_key, entry->pac_key, 32);
	if (eap_fast_copy_buf(&pac->pac_opaque, &pac->pac_opaque_len,
			      entry->pac_opaque, entry->pac_opaque_len) < 0 ||
	    eap_fast_copy_buf(&pac->pac_info, &pac->pac_info_len,
			      entry->pac_info, entry->pac_info_len) < 0 ||
	    eap_fast_copy_buf(&pac->a_id, &pac->a_id_len,
			      entry->a_id, entry->a_id_len) < 0 ||
	    eap_fast_copy_buf(&pac->i_id, &pac->i_id_len,
			      entry->i_id, entry->i_id_len) < 0 ||
	    eap_fast_copy_buf(&pac->a_id_info, &pac->a_id_info_len,
			      entry->a_id_info, entry->a_id_info_len) < 0) {
		eap_fast_free_pac(pac);
		return -1;
	}

	pac->next = *pac_root;
	*pac_root = pac;

	return 0;
}


struct eap_fast_read_ctx {
	FILE *f;
	const char *pos;
	const char *end;
	int line;
	char *buf;
	size_t buf_len;
};

static int eap_fast_read_line(struct eap_fast_read_ctx *rc, char **value)
{
	char *pos;

	rc->line++;
	if (rc->f) {
		if (fgets(rc->buf, rc->buf_len, rc->f) == 0)
			return -1;
	} else {
		const char *l_end;
		size_t len;
		if (rc->pos >= rc->end)
			return -1;
		l_end = rc->pos;
		while (l_end < rc->end && *l_end != '\n')
			l_end++;
		len = l_end - rc->pos;
		if (len >= rc->buf_len)
			len = rc->buf_len - 1;
		os_memcpy(rc->buf, rc->pos, len);
		rc->buf[len] = '\0';
		rc->pos = l_end + 1;
	}

	rc->buf[rc->buf_len - 1] = '\0';
	pos = rc->buf;
	while (*pos != '\0') {
		if (*pos == '\n' || *pos == '\r') {
			*pos = '\0';
			break;
		}
		pos++;
	}

	pos = os_strchr(rc->buf, '=');
	if (pos)
		*pos++ = '\0';
	*value = pos;

	return 0;
}


static unsigned char * eap_fast_parse_hex(const char *value, size_t *len)
{
	int hlen;
	unsigned char *buf;

	if (value == 0)
		return 0;
	hlen = os_strlen(value);
	if (hlen & 1)
		return 0;
	*len = hlen / 2;
	buf = os_malloc(*len);
	if (buf == 0)
		return 0;
	if (hexstr2bin(value, buf, *len)) {
		os_free(buf);
		return 0;
	}
	return buf;
}


static int eap_fast_init_pac_data(struct eap_sm *sm, const char *pac_file,
				  struct eap_fast_read_ctx *rc)
{
	os_memset(rc, 0, sizeof(*rc));

	rc->buf_len = 2048;
	rc->buf = os_malloc(rc->buf_len);
	if (rc->buf == 0)
		return -1;

	if (os_strncmp(pac_file, "blob://", 7) == 0) {
		const struct wpa_config_blob *blob;
		blob = eap_get_config_blob(sm, pac_file + 7);
		if (blob == 0) {
			wpa_printf(0, "EAP-FAST: No PAC blob '%s' - "
				   "assume no PAC entries have been "
				   "provisioned", pac_file + 7);
			os_free(rc->buf);
			return -1;
		}
		rc->pos = (char *) blob->data;
		rc->end = (char *) blob->data + blob->len;
	} else {
		rc->f = fopen(pac_file, "rb");
		if (rc->f == 0) {
			wpa_printf(0, "EAP-FAST: No PAC file '%s' - "
				   "assume no PAC entries have been "
				   "provisioned", pac_file);
			os_free(rc->buf);
			return -1;
		}
	}

	return 0;
}


static void eap_fast_deinit_pac_data(struct eap_fast_read_ctx *rc)
{
	os_free(rc->buf);
	if (rc->f)
		fclose(rc->f);
}


static const char * eap_fast_parse_start(struct eap_fast_pac **pac)
{
	if (*pac)
		return "START line without END";

	*pac = os_zalloc(sizeof(struct eap_fast_pac));
	if (*pac == 0)
		return "No memory for PAC entry";
	(*pac)->pac_type = 1;
	return 0;
}


static const char * eap_fast_parse_end(struct eap_fast_pac **pac_root,
				       struct eap_fast_pac **pac)
{
	if (*pac == 0)
		return "END line without START";
	if (*pac_root) {
		struct eap_fast_pac *end = *pac_root;
		while (end->next)
			end = end->next;
		end->next = *pac;
	} else
		*pac_root = *pac;

	*pac = 0;
	return 0;
}


static const char * eap_fast_parse_pac_type(struct eap_fast_pac *pac,
					    char *pos)
{
	pac->pac_type = atoi(pos);
	if (pac->pac_type != 1 &&
	    pac->pac_type != 3 &&
	    pac->pac_type != 2)
		return "Unrecognized PAC-Type";

	return 0;
}


static const char * eap_fast_parse_pac_key(struct eap_fast_pac *pac, char *pos)
{
	unsigned char *key;
	size_t key_len;

	key = eap_fast_parse_hex(pos, &key_len);
	if (key == 0 || key_len != 32) {
		os_free(key);
		return "Invalid PAC-Key";
	}

	os_memcpy(pac->pac_key, key, 32);
	os_free(key);

	return 0;
}


static const char * eap_fast_parse_pac_opaque(struct eap_fast_pac *pac,
					      char *pos)
{
	os_free(pac->pac_opaque);
	pac->pac_opaque = eap_fast_parse_hex(pos, &pac->pac_opaque_len);
	if (pac->pac_opaque == 0)
		return "Invalid PAC-Opaque";
	return 0;
}


static const char * eap_fast_parse_a_id(struct eap_fast_pac *pac, char *pos)
{
	os_free(pac->a_id);
	pac->a_id = eap_fast_parse_hex(pos, &pac->a_id_len);
	if (pac->a_id == 0)
		return "Invalid A-ID";
	return 0;
}


static const char * eap_fast_parse_i_id(struct eap_fast_pac *pac, char *pos)
{
	os_free(pac->i_id);
	pac->i_id = eap_fast_parse_hex(pos, &pac->i_id_len);
	if (pac->i_id == 0)
		return "Invalid I-ID";
	return 0;
}


static const char * eap_fast_parse_a_id_info(struct eap_fast_pac *pac,
					     char *pos)
{
	os_free(pac->a_id_info);
	pac->a_id_info = eap_fast_parse_hex(pos, &pac->a_id_info_len);
	if (pac->a_id_info == 0)
		return "Invalid A-ID-Info";
	return 0;
}








 
int eap_fast_load_pac(struct eap_sm *sm, struct eap_fast_pac **pac_root,
		      const char *pac_file)
{
	struct eap_fast_read_ctx rc;
	struct eap_fast_pac *pac = 0;
	int count = 0;
	char *pos;
	const char *err = 0;

	if (pac_file == 0)
		return -1;

	if (eap_fast_init_pac_data(sm, pac_file, &rc) < 0)
		return 0;

	if (eap_fast_read_line(&rc, &pos) < 0 ||
	    os_strcmp(pac_file_hdr, rc.buf) != 0)
		err = "Unrecognized header line";

	while (!err && eap_fast_read_line(&rc, &pos) == 0) {
		if (os_strcmp(rc.buf, "START") == 0)
			err = eap_fast_parse_start(&pac);
		else if (os_strcmp(rc.buf, "END") == 0) {
			err = eap_fast_parse_end(pac_root, &pac);
			count++;
		} else if (!pac)
			err = "Unexpected line outside START/END block";
		else if (os_strcmp(rc.buf, "PAC-Type") == 0)
			err = eap_fast_parse_pac_type(pac, pos);
		else if (os_strcmp(rc.buf, "PAC-Key") == 0)
			err = eap_fast_parse_pac_key(pac, pos);
		else if (os_strcmp(rc.buf, "PAC-Opaque") == 0)
			err = eap_fast_parse_pac_opaque(pac, pos);
		else if (os_strcmp(rc.buf, "A-ID") == 0)
			err = eap_fast_parse_a_id(pac, pos);
		else if (os_strcmp(rc.buf, "I-ID") == 0)
			err = eap_fast_parse_i_id(pac, pos);
		else if (os_strcmp(rc.buf, "A-ID-Info") == 0)
			err = eap_fast_parse_a_id_info(pac, pos);
	}

	if (pac) {
		err = "PAC block not terminated with END";
		eap_fast_free_pac(pac);
	}

	eap_fast_deinit_pac_data(&rc);

	if (err) {
		wpa_printf(0, "EAP-FAST: %s in '%s:%d'",
			   err, pac_file, rc.line);
		return -1;
	}

	wpa_printf(0, "EAP-FAST: Read %d PAC entries from '%s'",
		   count, pac_file);

	return 0;
}


static void eap_fast_write(char **buf, char **pos, size_t *buf_len,
			   const char *field, const unsigned char *data,
			   size_t len, int txt)
{
	size_t i, need;
	int ret;
	char *end;

	if (data == 0 || buf == 0 || *buf == 0 ||
	    pos == 0 || *pos == 0 || *pos < *buf)
		return;

	need = os_strlen(field) + len * 2 + 30;
	if (txt)
		need += os_strlen(field) + len + 20;

	if (*pos - *buf + need > *buf_len) {
		char *nbuf = os_realloc(*buf, *buf_len + need);
		if (nbuf == 0) {
			os_free(*buf);
			*buf = 0;
			return;
		}
		*buf = nbuf;
		*buf_len += need;
	}
	end = *buf + *buf_len;

	ret = os_snprintf(*pos, end - *pos, "%s=", field);
	if (ret < 0 || ret >= end - *pos)
		return;
	*pos += ret;
	*pos += wpa_snprintf_hex(*pos, end - *pos, data, len);
	ret = os_snprintf(*pos, end - *pos, "\n");
	if (ret < 0 || ret >= end - *pos)
		return;
	*pos += ret;

	if (txt) {
		ret = os_snprintf(*pos, end - *pos, "%s-txt=", field);
		if (ret < 0 || ret >= end - *pos)
			return;
		*pos += ret;
		for (i = 0; i < len; i++) {
			ret = os_snprintf(*pos, end - *pos, "%c", data[i]);
			if (ret < 0 || ret >= end - *pos)
				return;
			*pos += ret;
		}
		ret = os_snprintf(*pos, end - *pos, "\n");
		if (ret < 0 || ret >= end - *pos)
			return;
		*pos += ret;
	}
}


static int eap_fast_write_pac(struct eap_sm *sm, const char *pac_file,
			      char *buf, size_t len)
{
	if (os_strncmp(pac_file, "blob://", 7) == 0) {
		struct wpa_config_blob *blob;
		blob = os_zalloc(sizeof(*blob));
		if (blob == 0)
			return -1;
		blob->data = (unsigned char *) buf;
		blob->len = len;
		buf = 0;
		blob->name = (char*)os_strdup(pac_file + 7);
		if (blob->name == 0) {
			os_free(blob);
			return -1;
		}
		eap_set_config_blob(sm, blob);
	} else {
		FILE *f;
		f = fopen(pac_file, "wb");
		if (f == 0) {
			wpa_printf(0, "EAP-FAST: Failed to open PAC "
				   "file '%s' for writing", pac_file);
			return -1;
		}
		if (fwrite(buf, 1, len, f) != len) {
			wpa_printf(0, "EAP-FAST: Failed to write all "
				   "PACs into '%s'", pac_file);
			fclose(f);
			return -1;
		}
		os_free(buf);
		fclose(f);
	}

	return 0;
}


static int eap_fast_add_pac_data(struct eap_fast_pac *pac, char **buf,
				 char **pos, size_t *buf_len)
{
	int ret;

	ret = os_snprintf(*pos, *buf + *buf_len - *pos,
			  "START\nPAC-Type=%d\n", pac->pac_type);
	if (ret < 0 || ret >= *buf + *buf_len - *pos)
		return -1;

	*pos += ret;
	eap_fast_write(buf, pos, buf_len, "PAC-Key",
		       pac->pac_key, 32, 0);
	eap_fast_write(buf, pos, buf_len, "PAC-Opaque",
		       pac->pac_opaque, pac->pac_opaque_len, 0);
	eap_fast_write(buf, pos, buf_len, "PAC-Info",
		       pac->pac_info, pac->pac_info_len, 0);
	eap_fast_write(buf, pos, buf_len, "A-ID",
		       pac->a_id, pac->a_id_len, 0);
	eap_fast_write(buf, pos, buf_len, "I-ID",
		       pac->i_id, pac->i_id_len, 1);
	eap_fast_write(buf, pos, buf_len, "A-ID-Info",
		       pac->a_id_info, pac->a_id_info_len, 1);
	if (*buf == 0) {
		wpa_printf(0, "EAP-FAST: No memory for PAC "
			   "data");
		return -1;
	}
	ret = os_snprintf(*pos, *buf + *buf_len - *pos, "END\n");
	if (ret < 0 || ret >= *buf + *buf_len - *pos)
		return -1;
	*pos += ret;

	return 0;
}








 
int eap_fast_save_pac(struct eap_sm *sm, struct eap_fast_pac *pac_root,
		      const char *pac_file)
{
	struct eap_fast_pac *pac;
	int ret, count = 0;
	char *buf, *pos;
	size_t buf_len;

	if (pac_file == 0)
		return -1;

	buf_len = 1024;
	pos = buf = os_malloc(buf_len);
	if (buf == 0)
		return -1;

	ret = os_snprintf(pos, buf + buf_len - pos, "%s\n", pac_file_hdr);
	if (ret < 0 || ret >= buf + buf_len - pos) {
		os_free(buf);
		return -1;
	}
	pos += ret;

	pac = pac_root;
	while (pac) {
		if (eap_fast_add_pac_data(pac, &buf, &pos, &buf_len)) {
			os_free(buf);
			return -1;
		}
		count++;
		pac = pac->next;
	}

	if (eap_fast_write_pac(sm, pac_file, buf, pos - buf)) {
		os_free(buf);
		return -1;
	}

	wpa_printf(0, "EAP-FAST: Wrote %d PAC entries into '%s'",
		   count, pac_file);

	return 0;
}







 
size_t eap_fast_pac_list_truncate(struct eap_fast_pac *pac_root,
				  size_t max_len)
{
	struct eap_fast_pac *pac, *prev;
	size_t count;

	pac = pac_root;
	prev = 0;
	count = 0;

	while (pac) {
		count++;
		if (count > max_len)
			break;
		prev = pac;
		pac = pac->next;
	}

	if (count <= max_len || prev == 0)
		return 0;

	count = 0;
	prev->next = 0;

	while (pac) {
		prev = pac;
		pac = pac->next;
		eap_fast_free_pac(prev);
		count++;
	}

	return count;
}


static void eap_fast_pac_get_a_id(struct eap_fast_pac *pac)
{
	unsigned char *pos, *end;
	unsigned short type, len;

	pos = pac->pac_info;
	end = pos + pac->pac_info_len;

	while (pos + 4 < end) {
		type = ((unsigned short) (((pos)[0] << 8) | (pos)[1]));
		pos += 2;
		len = ((unsigned short) (((pos)[0] << 8) | (pos)[1]));
		pos += 2;
		if (pos + len > end)
			break;

		if (type == 4) {
			os_free(pac->a_id);
			pac->a_id = os_malloc(len);
			if (pac->a_id == 0)
				break;
			os_memcpy(pac->a_id, pos, len);
			pac->a_id_len = len;
		}

		if (type == 7) {
			os_free(pac->a_id_info);
			pac->a_id_info = os_malloc(len);
			if (pac->a_id_info == 0)
				break;
			os_memcpy(pac->a_id_info, pos, len);
			pac->a_id_info_len = len;
		}

		pos += len;
	}
}








 
int eap_fast_load_pac_bin(struct eap_sm *sm, struct eap_fast_pac **pac_root,
			  const char *pac_file)
{
	const struct wpa_config_blob *blob = 0;
	unsigned char *buf, *end, *pos;
	size_t len, count = 0;
	struct eap_fast_pac *pac, *prev;

	*pac_root = 0;

	if (pac_file == 0)
		return -1;

	if (os_strncmp(pac_file, "blob://", 7) == 0) {
		blob = eap_get_config_blob(sm, pac_file + 7);
		if (blob == 0) {
			wpa_printf(0, "EAP-FAST: No PAC blob '%s' - "
				   "assume no PAC entries have been "
				   "provisioned", pac_file + 7);
			return 0;
		}
		buf = blob->data;
		len = blob->len;
	} else {
		buf = (unsigned char *) os_readfile(pac_file, &len);
		if (buf == 0) {
			wpa_printf(0, "EAP-FAST: No PAC file '%s' - "
				   "assume no PAC entries have been "
				   "provisioned", pac_file);
			return 0;
		}
	}

	if (len == 0) {
		if (blob == 0)
			os_free(buf);
		return 0;
	}

	if (len < 6 || ((((unsigned int) (buf)[0]) << 24) | (((unsigned int) (buf)[1]) << 16) | (((unsigned int) (buf)[2]) << 8) | ((unsigned int) (buf)[3])) != 0x6ae4920c ||
	    ((unsigned short) (((buf + 4)[0] << 8) | (buf + 4)[1])) != 0) {
		wpa_printf(0, "EAP-FAST: Invalid PAC file '%s' (bin)",
			   pac_file);
		if (blob == 0)
			os_free(buf);
		return -1;
	}

	pac = prev = 0;
	pos = buf + 6;
	end = buf + len;
	while (pos < end) {
		if (end - pos < 2 + 32 + 2 + 2)
			goto parse_fail;

		pac = os_zalloc(sizeof(*pac));
		if (pac == 0)
			goto parse_fail;

		pac->pac_type = ((unsigned short) (((pos)[0] << 8) | (pos)[1]));
		pos += 2;
		os_memcpy(pac->pac_key, pos, 32);
		pos += 32;
		pac->pac_opaque_len = ((unsigned short) (((pos)[0] << 8) | (pos)[1]));
		pos += 2;
		if (pos + pac->pac_opaque_len + 2 > end)
			goto parse_fail;
		pac->pac_opaque = os_malloc(pac->pac_opaque_len);
		if (pac->pac_opaque == 0)
			goto parse_fail;
		os_memcpy(pac->pac_opaque, pos, pac->pac_opaque_len);
		pos += pac->pac_opaque_len;
		pac->pac_info_len = ((unsigned short) (((pos)[0] << 8) | (pos)[1]));
		pos += 2;
		if (pos + pac->pac_info_len > end)
			goto parse_fail;
		pac->pac_info = os_malloc(pac->pac_info_len);
		if (pac->pac_info == 0)
			goto parse_fail;
		os_memcpy(pac->pac_info, pos, pac->pac_info_len);
		pos += pac->pac_info_len;
		eap_fast_pac_get_a_id(pac);

		count++;
		if (prev)
			prev->next = pac;
		else
			*pac_root = pac;
		prev = pac;
	}

	if (blob == 0)
		os_free(buf);

	wpa_printf(0, "EAP-FAST: Read %lu PAC entries from '%s' (bin)",
		   (unsigned long) count, pac_file);

	return 0;

parse_fail:
	wpa_printf(0, "EAP-FAST: Failed to parse PAC file '%s' (bin)",
		   pac_file);
	if (blob == 0)
		os_free(buf);
	if (pac)
		eap_fast_free_pac(pac);
	return -1;
}








 
int eap_fast_save_pac_bin(struct eap_sm *sm, struct eap_fast_pac *pac_root,
			  const char *pac_file)
{
	size_t len, count = 0;
	struct eap_fast_pac *pac;
	unsigned char *buf, *pos;

	len = 6;
	pac = pac_root;
	while (pac) {
		if (pac->pac_opaque_len > 65535 ||
		    pac->pac_info_len > 65535)
			return -1;
		len += 2 + 32 + 2 + pac->pac_opaque_len +
			2 + pac->pac_info_len;
		pac = pac->next;
	}

	buf = os_malloc(len);
	if (buf == 0)
		return -1;

	pos = buf;
	do { (pos)[0] = (unsigned char) ((((unsigned int) (0x6ae4920c)) >> 24) & 0xff); (pos)[1] = (unsigned char) ((((unsigned int) (0x6ae4920c)) >> 16) & 0xff); (pos)[2] = (unsigned char) ((((unsigned int) (0x6ae4920c)) >> 8) & 0xff); (pos)[3] = (unsigned char) (((unsigned int) (0x6ae4920c)) & 0xff); } while (0);
	pos += 4;
	do { (pos)[0] = ((unsigned short) (0)) >> 8; (pos)[1] = ((unsigned short) (0)) & 0xff; } while (0);
	pos += 2;

	pac = pac_root;
	while (pac) {
		do { (pos)[0] = ((unsigned short) (pac->pac_type)) >> 8; (pos)[1] = ((unsigned short) (pac->pac_type)) & 0xff; } while (0);
		pos += 2;
		os_memcpy(pos, pac->pac_key, 32);
		pos += 32;
		do { (pos)[0] = ((unsigned short) (pac->pac_opaque_len)) >> 8; (pos)[1] = ((unsigned short) (pac->pac_opaque_len)) & 0xff; } while (0);
		pos += 2;
		os_memcpy(pos, pac->pac_opaque, pac->pac_opaque_len);
		pos += pac->pac_opaque_len;
		do { (pos)[0] = ((unsigned short) (pac->pac_info_len)) >> 8; (pos)[1] = ((unsigned short) (pac->pac_info_len)) & 0xff; } while (0);
		pos += 2;
		os_memcpy(pos, pac->pac_info, pac->pac_info_len);
		pos += pac->pac_info_len;

		pac = pac->next;
		count++;
	}

	if (eap_fast_write_pac(sm, pac_file, (char *) buf, len)) {
		os_free(buf);
		return -1;
	}

	wpa_printf(0, "EAP-FAST: Wrote %lu PAC entries into '%s' "
		   "(bin)", (unsigned long) count, pac_file);

	return 0;
}
