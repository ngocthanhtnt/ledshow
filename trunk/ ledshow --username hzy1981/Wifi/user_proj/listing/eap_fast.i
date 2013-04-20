#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_fast.c"












 

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

#line 16 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_fast.c"

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



#line 18 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_fast.c"
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

#line 19 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_fast.c"
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
#line 20 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_fast.c"
#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common/eap_tlv_common.h"












 




 
#line 37 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common/eap_tlv_common.h"











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











#line 21 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_fast.c"
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

#line 22 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_fast.c"
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

#line 23 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_fast.c"
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

#line 24 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_fast.c"
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

#line 25 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_fast.c"








 


static void eap_fast_deinit(struct eap_sm *sm, void *priv);


struct eap_fast_data {
	struct eap_ssl_data ssl;

	int fast_version;

	const struct eap_method *phase2_method;
	void *phase2_priv;
	int phase2_success;

	struct eap_method_type phase2_type;
	struct eap_method_type *phase2_types;
	size_t num_phase2_types;
	int resuming;  
	struct eap_fast_key_block_provisioning *key_block_p;


	int provisioning_allowed;  
	int provisioning;  
	int anon_provisioning; 
 
	int session_ticket_used;

	unsigned char key_data[64];
	unsigned char emsk[64];
	int success;

	struct eap_fast_pac *pac;
	struct eap_fast_pac *current_pac;
	size_t max_pac_list_len;
	int use_pac_binary_format;

	unsigned char simck[40];
	int simck_idx;

	struct wpabuf *pending_phase2_req;
};


static int eap_fast_session_ticket_cb(void *ctx, const unsigned char *ticket, size_t len,
				      const unsigned char *client_random,
				      const unsigned char *server_random,
				      unsigned char *master_secret)
{
	struct eap_fast_data *data = ctx;

	wpa_printf(0, "EAP-FAST: SessionTicket callback");

	if (client_random == 0 || server_random == 0 ||
	    master_secret == 0) {
		wpa_printf(0, "EAP-FAST: SessionTicket failed - fall "
			   "back to full TLS handshake");
		data->session_ticket_used = 0;
		if (data->provisioning_allowed) {
			wpa_printf(0, "EAP-FAST: Try to provision a "
				   "new PAC-Key");
			data->provisioning = 1;
			data->current_pac = 0;
		}
		return 0;
	}

	wpa_hexdump(0, "EAP-FAST: SessionTicket", ticket, len);

	if (data->current_pac == 0) {
		wpa_printf(0, "EAP-FAST: No PAC-Key available for "
			   "using SessionTicket");
		data->session_ticket_used = 0;
		return 0;
	}

	eap_fast_derive_master_secret(data->current_pac->pac_key,
				      server_random, client_random,
				      master_secret);

	data->session_ticket_used = 1;

	return 1;
}


static int eap_fast_parse_phase1(struct eap_fast_data *data,
				 const char *phase1)
{
	const char *pos;

	pos = os_strstr(phase1, "fast_provisioning=");
	if (pos) {
		data->provisioning_allowed = atoi(pos + 18);
		wpa_printf(0, "EAP-FAST: Automatic PAC provisioning "
			   "mode: %d", data->provisioning_allowed);
	}

	pos = os_strstr(phase1, "fast_max_pac_list_len=");
	if (pos) {
		data->max_pac_list_len = atoi(pos + 22);
		if (data->max_pac_list_len == 0)
			data->max_pac_list_len = 1;
		wpa_printf(0, "EAP-FAST: Maximum PAC list length: %lu",
			   (unsigned long) data->max_pac_list_len);
	}

	pos = os_strstr(phase1, "fast_pac_format=binary");
	if (pos) {
		data->use_pac_binary_format = 1;
		wpa_printf(0, "EAP-FAST: Using binary format for PAC "
			   "list");
	}

	return 0;
}


static void * eap_fast_init(struct eap_sm *sm)
{
	struct eap_fast_data *data;
	struct eap_peer_config *config = eap_get_config(sm);

	data = os_zalloc(sizeof(*data));
	if (data == 0)
		return 0;
	data->fast_version = 1;
	data->max_pac_list_len = 10;

	if (config && config->phase1 &&
	    eap_fast_parse_phase1(data, config->phase1) < 0) {
		eap_fast_deinit(sm, data);
		return 0;
	}

	if (eap_peer_select_phase2_methods(config, "auth=",
					   &data->phase2_types,
					   &data->num_phase2_types) < 0) {
		eap_fast_deinit(sm, data);
		return 0;
	}

	data->phase2_type.vendor = EAP_VENDOR_IETF;
	data->phase2_type.method = EAP_TYPE_NONE;

	if (eap_peer_tls_ssl_init(sm, &data->ssl, config)) {
		wpa_printf(0, "EAP-FAST: Failed to initialize SSL.");
		eap_fast_deinit(sm, data);
		return 0;
	}

	if (tls_connection_set_session_ticket_cb(sm->ssl_ctx, data->ssl.conn,
						 eap_fast_session_ticket_cb,
						 data) < 0) {
		wpa_printf(0, "EAP-FAST: Failed to set SessionTicket "
			   "callback");
		eap_fast_deinit(sm, data);
		return 0;
	}

	



 
	if (tls_connection_enable_workaround(sm->ssl_ctx, data->ssl.conn)) {
		wpa_printf(0, "EAP-FAST: Failed to enable TLS "
			   "workarounds");
	}

	if (data->use_pac_binary_format &&
	    eap_fast_load_pac_bin(sm, &data->pac, config->pac_file) < 0) {
		eap_fast_deinit(sm, data);
		return 0;
	}

	if (!data->use_pac_binary_format &&
	    eap_fast_load_pac(sm, &data->pac, config->pac_file) < 0) {
		eap_fast_deinit(sm, data);
		return 0;
	}
	eap_fast_pac_list_truncate(data->pac, data->max_pac_list_len);

	if (data->pac == 0 && !data->provisioning_allowed) {
		wpa_printf(0, "EAP-FAST: No PAC configured and "
			   "provisioning disabled");
		eap_fast_deinit(sm, data);
		return 0;
	}

	return data;
}


static void eap_fast_deinit(struct eap_sm *sm, void *priv)
{
	struct eap_fast_data *data = priv;
	struct eap_fast_pac *pac, *prev;

	if (data == 0)
		return;
	if (data->phase2_priv && data->phase2_method)
		data->phase2_method->deinit(sm, data->phase2_priv);
	os_free(data->phase2_types);
	os_free(data->key_block_p);
	eap_peer_tls_ssl_deinit(sm, &data->ssl);

	pac = data->pac;
	prev = 0;
	while (pac) {
		prev = pac;
		pac = pac->next;
		eap_fast_free_pac(prev);
	}
	wpabuf_free(data->pending_phase2_req);
	os_free(data);
}


static int eap_fast_derive_msk(struct eap_fast_data *data)
{
	eap_fast_derive_eap_msk(data->simck, data->key_data);
	eap_fast_derive_eap_emsk(data->simck, data->emsk);
	data->success = 1;
	return 0;
}


static void eap_fast_derive_key_auth(struct eap_sm *sm,
				     struct eap_fast_data *data)
{
	unsigned char *sks;

	

 

	sks = eap_fast_derive_key(sm->ssl_ctx, data->ssl.conn, "key expansion",
				  40);
	if (sks == 0) {
		wpa_printf(0, "EAP-FAST: Failed to derive "
			   "session_key_seed");
		return;
	}

	


 
	wpa_hexdump_key(0,
			"EAP-FAST: session_key_seed (SKS = S-IMCK[0])",
			sks, 40);
	data->simck_idx = 0;
	os_memcpy(data->simck, sks, 40);
	os_free(sks);
}


static void eap_fast_derive_key_provisioning(struct eap_sm *sm,
					     struct eap_fast_data *data)
{
	os_free(data->key_block_p);
	data->key_block_p = (struct eap_fast_key_block_provisioning *)
		eap_fast_derive_key(sm->ssl_ctx, data->ssl.conn,
				    "key expansion",
				    sizeof(*data->key_block_p));
	if (data->key_block_p == 0) {
		wpa_printf(0, "EAP-FAST: Failed to derive key block");
		return;
	}
	


 
	wpa_hexdump_key(0,
			"EAP-FAST: session_key_seed (SKS = S-IMCK[0])",
			data->key_block_p->session_key_seed,
			sizeof(data->key_block_p->session_key_seed));
	data->simck_idx = 0;
	os_memcpy(data->simck, data->key_block_p->session_key_seed,
		  40);
	wpa_hexdump_key(0, "EAP-FAST: server_challenge",
			data->key_block_p->server_challenge,
			sizeof(data->key_block_p->server_challenge));
	wpa_hexdump_key(0, "EAP-FAST: client_challenge",
			data->key_block_p->client_challenge,
			sizeof(data->key_block_p->client_challenge));
}


static void eap_fast_derive_keys(struct eap_sm *sm, struct eap_fast_data *data)
{
	if (data->anon_provisioning)
		eap_fast_derive_key_provisioning(sm, data);
	else
		eap_fast_derive_key_auth(sm, data);
}


static int eap_fast_init_phase2_method(struct eap_sm *sm,
				       struct eap_fast_data *data)
{
	data->phase2_method =
		eap_peer_get_eap_method(data->phase2_type.vendor,
					data->phase2_type.method);
	if (data->phase2_method == 0)
		return -1;

	if (data->key_block_p) {
		sm->auth_challenge = data->key_block_p->server_challenge;
		sm->peer_challenge = data->key_block_p->client_challenge;
	}
	sm->init_phase2 = 1;
	data->phase2_priv = data->phase2_method->init(sm);
	sm->init_phase2 = 0;
	sm->auth_challenge = 0;
	sm->peer_challenge = 0;

	return data->phase2_priv == 0 ? -1 : 0;
}


static int eap_fast_select_phase2_method(struct eap_fast_data *data, unsigned char type)
{
	size_t i;

	
 

	if (data->anon_provisioning && type != EAP_TYPE_MSCHAPV2) {
		wpa_printf(0, "EAP-FAST: Only EAP-MSCHAPv2 is allowed "
			   "during unauthenticated provisioning; reject phase2"
			   " type %d", type);
		return -1;
	}

#line 380 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_fast.c"

	for (i = 0; i < data->num_phase2_types; i++) {
		if (data->phase2_types[i].vendor != EAP_VENDOR_IETF ||
		    data->phase2_types[i].method != type)
			continue;

		data->phase2_type.vendor = data->phase2_types[i].vendor;
		data->phase2_type.method = data->phase2_types[i].method;
		wpa_printf(0, "EAP-FAST: Selected Phase 2 EAP "
			   "vendor %d method %d",
			   data->phase2_type.vendor,
			   data->phase2_type.method);
		break;
	}

	if (type != data->phase2_type.method || type == EAP_TYPE_NONE)
		return -1;

	return 0;
}


static int eap_fast_phase2_request(struct eap_sm *sm,
				   struct eap_fast_data *data,
				   struct eap_method_ret *ret,
				   struct eap_hdr *hdr,
				   struct wpabuf **resp)
{
	size_t len = ((((unsigned short) ((unsigned short) (unsigned short) (hdr->length)) << 8) & 0xff00) | (((unsigned short) ((unsigned short) (unsigned short) (hdr->length)) >> 8) & 0xff));
	unsigned char *pos;
	struct eap_method_ret iret;
	struct eap_peer_config *config = eap_get_config(sm);
	struct wpabuf msg;

	if (len <= sizeof(struct eap_hdr)) {
		wpa_printf(0, "EAP-FAST: too short "
			   "Phase 2 request (len=%lu)", (unsigned long) len);
		return -1;
	}
	pos = (unsigned char *) (hdr + 1);
	wpa_printf(0, "EAP-FAST: Phase 2 Request: type=%d", *pos);
	if (*pos == EAP_TYPE_IDENTITY) {
		*resp = eap_sm_buildIdentity(sm, hdr->identifier, 1);
		return 0;
	}

	if (data->phase2_priv && data->phase2_method &&
	    *pos != data->phase2_type.method) {
		wpa_printf(0, "EAP-FAST: Phase 2 EAP sequence - "
			   "deinitialize previous method");
		data->phase2_method->deinit(sm, data->phase2_priv);
		data->phase2_method = 0;
		data->phase2_priv = 0;
		data->phase2_type.vendor = EAP_VENDOR_IETF;
		data->phase2_type.method = EAP_TYPE_NONE;
	}

	if (data->phase2_type.vendor == EAP_VENDOR_IETF &&
	    data->phase2_type.method == EAP_TYPE_NONE &&
	    eap_fast_select_phase2_method(data, *pos) < 0) {
		if (eap_peer_tls_phase2_nak(data->phase2_types,
					    data->num_phase2_types,
					    hdr, resp))
			return -1;
		return 0;
	}

	if (data->phase2_priv == 0 &&
	    eap_fast_init_phase2_method(sm, data) < 0) {
		wpa_printf(0, "EAP-FAST: Failed to initialize "
			   "Phase 2 EAP method %d", *pos);
		ret->methodState = METHOD_DONE;
		ret->decision = DECISION_FAIL;
		return -1;
	}

	os_memset(&iret, 0, sizeof(iret));
	wpabuf_set(&msg, hdr, len);
	*resp = data->phase2_method->process(sm, data->phase2_priv, &iret,
					     &msg);
	if (*resp == 0 ||
	    (iret.methodState == METHOD_DONE &&
	     iret.decision == DECISION_FAIL)) {
		ret->methodState = METHOD_DONE;
		ret->decision = DECISION_FAIL;
	} else if ((iret.methodState == METHOD_DONE ||
		    iret.methodState == METHOD_MAY_CONT) &&
		   (iret.decision == DECISION_UNCOND_SUCC ||
		    iret.decision == DECISION_COND_SUCC)) {
		data->phase2_success = 1;
	}

	if (*resp == 0 && config &&
	    (config->pending_req_identity || config->pending_req_password ||
	     config->pending_req_otp || config->pending_req_new_password)) {
		wpabuf_free(data->pending_phase2_req);
		data->pending_phase2_req = wpabuf_alloc_copy(hdr, len);
	} else if (*resp == 0)
		return -1;

	return 0;
}


static struct wpabuf * eap_fast_tlv_nak(int vendor_id, int tlv_type)
{
	struct wpabuf *buf;
	struct eap_tlv_nak_tlv *nak;
	buf = wpabuf_alloc(sizeof(*nak));
	if (buf == 0)
		return 0;
	nak = wpabuf_put(buf, sizeof(*nak));
	nak->tlv_type = (( unsigned short) ((((unsigned short) ((0x8000 | 4)) << 8) & 0xff00) | (((unsigned short) ((0x8000 | 4)) >> 8) & 0xff)));
	nak->length = (( unsigned short) ((((unsigned short) ((6)) << 8) & 0xff00) | (((unsigned short) ((6)) >> 8) & 0xff)));
	nak->vendor_id = (( unsigned int) ((((unsigned int) ((vendor_id)) << 24) & 0xff000000) | (((unsigned int) ((vendor_id)) << 8) & 0xff0000) | (((unsigned int) ((vendor_id)) >> 8) & 0xff00) | (((unsigned int) ((vendor_id)) >> 24) & 0xff)));
	nak->nak_type = (( unsigned short) ((((unsigned short) ((tlv_type)) << 8) & 0xff00) | (((unsigned short) ((tlv_type)) >> 8) & 0xff)));
	return buf;
}


static struct wpabuf * eap_fast_tlv_result(int status, int intermediate)
{
	struct wpabuf *buf;
	struct eap_tlv_intermediate_result_tlv *result;
	buf = wpabuf_alloc(sizeof(*result));
	if (buf == 0)
		return 0;
	wpa_printf(0, "EAP-FAST: Add %sResult TLV(status=%d)",
		   intermediate ? "Intermediate " : "", status);
	result = wpabuf_put(buf, sizeof(*result));
	result->tlv_type = (( unsigned short) ((((unsigned short) ((0x8000 | (intermediate ? 10 : 3))) << 8) & 0xff00) | (((unsigned short) ((0x8000 | (intermediate ? 10 : 3))) >> 8) & 0xff)));



	result->length = (( unsigned short) ((((unsigned short) ((2)) << 8) & 0xff00) | (((unsigned short) ((2)) >> 8) & 0xff)));
	result->status = (( unsigned short) ((((unsigned short) ((status)) << 8) & 0xff00) | (((unsigned short) ((status)) >> 8) & 0xff)));
	return buf;
}


static struct wpabuf * eap_fast_tlv_pac_ack(void)
{
	struct wpabuf *buf;
	struct eap_tlv_result_tlv *res;
	struct eap_tlv_pac_ack_tlv *ack;

	buf = wpabuf_alloc(sizeof(*res) + sizeof(*ack));
	if (buf == 0)
		return 0;

	wpa_printf(0, "EAP-FAST: Add PAC TLV (ack)");
	ack = wpabuf_put(buf, sizeof(*ack));
	ack->tlv_type = (( unsigned short) ((((unsigned short) ((11 | 0x8000)) << 8) & 0xff00) | (((unsigned short) ((11 | 0x8000)) >> 8) & 0xff)));

	ack->length = (( unsigned short) ((((unsigned short) ((sizeof(*ack) - sizeof(struct eap_tlv_hdr))) << 8) & 0xff00) | (((unsigned short) ((sizeof(*ack) - sizeof(struct eap_tlv_hdr))) >> 8) & 0xff)));
	ack->pac_type = (( unsigned short) ((((unsigned short) ((8)) << 8) & 0xff00) | (((unsigned short) ((8)) >> 8) & 0xff)));
	ack->pac_len = (( unsigned short) ((((unsigned short) ((2)) << 8) & 0xff00) | (((unsigned short) ((2)) >> 8) & 0xff)));
	ack->result = (( unsigned short) ((((unsigned short) ((1)) << 8) & 0xff00) | (((unsigned short) ((1)) >> 8) & 0xff)));

	return buf;
}


static struct wpabuf * eap_fast_process_eap_payload_tlv(
	struct eap_sm *sm, struct eap_fast_data *data,
	struct eap_method_ret *ret, const struct eap_hdr *req,
	unsigned char *eap_payload_tlv, size_t eap_payload_tlv_len)
{
	struct eap_hdr *hdr;
	struct wpabuf *resp = 0;

	if (eap_payload_tlv_len < sizeof(*hdr)) {
		wpa_printf(0, "EAP-FAST: too short EAP "
			   "Payload TLV (len=%lu)",
			   (unsigned long) eap_payload_tlv_len);
		return 0;
	}

	hdr = (struct eap_hdr *) eap_payload_tlv;
	if (((((unsigned short) ((unsigned short) (unsigned short) (hdr->length)) << 8) & 0xff00) | (((unsigned short) ((unsigned short) (unsigned short) (hdr->length)) >> 8) & 0xff)) > eap_payload_tlv_len) {
		wpa_printf(0, "EAP-FAST: EAP packet overflow in "
			   "EAP Payload TLV");
		return 0;
	}

	if (hdr->code != EAP_CODE_REQUEST) {
		wpa_printf(0, "EAP-FAST: Unexpected code=%d in "
			   "Phase 2 EAP header", hdr->code);
		return 0;
	}

	if (eap_fast_phase2_request(sm, data, ret, hdr, &resp)) {
		wpa_printf(0, "EAP-FAST: Phase2 Request processing "
			   "failed");
		return 0;
	}

	return eap_fast_tlv_eap_payload(resp);
}


static int eap_fast_validate_crypto_binding(
	struct eap_tlv_crypto_binding_tlv *_bind)
{
	wpa_printf(0, "EAP-FAST: Crypto-Binding TLV: Version %d "
		   "Received Version %d SubType %d",
		   _bind->version, _bind->received_version, _bind->subtype);
	wpa_hexdump(0, "EAP-FAST: NONCE",
		    _bind->nonce, sizeof(_bind->nonce));
	wpa_hexdump(0, "EAP-FAST: Compound MAC",
		    _bind->compound_mac, sizeof(_bind->compound_mac));

	if (_bind->version != 1 ||
	    _bind->received_version != 1 ||
	    _bind->subtype != 0) {
		wpa_printf(0, "EAP-FAST: Invalid version/subtype in "
			   "Crypto-Binding TLV: Version %d "
			   "Received Version %d SubType %d",
			   _bind->version, _bind->received_version,
			   _bind->subtype);
		return -1;
	}

	return 0;
}


static void eap_fast_write_crypto_binding(
	struct eap_tlv_crypto_binding_tlv *rbind,
	struct eap_tlv_crypto_binding_tlv *_bind, const unsigned char *cmk)
{
	rbind->tlv_type = (( unsigned short) ((((unsigned short) ((0x8000 | 12)) << 8) & 0xff00) | (((unsigned short) ((0x8000 | 12)) >> 8) & 0xff)));

	rbind->length = (( unsigned short) ((((unsigned short) ((sizeof(*rbind) - sizeof(struct eap_tlv_hdr))) << 8) & 0xff00) | (((unsigned short) ((sizeof(*rbind) - sizeof(struct eap_tlv_hdr))) >> 8) & 0xff)));

	rbind->version = 1;
	rbind->received_version = _bind->version;
	rbind->subtype = 1;
	os_memcpy(rbind->nonce, _bind->nonce, sizeof(_bind->nonce));
	inc_byte_array(rbind->nonce, sizeof(rbind->nonce));
	hmac_sha1(cmk, 20, (unsigned char *) rbind, sizeof(*rbind),
		  rbind->compound_mac);

	wpa_printf(0, "EAP-FAST: Reply Crypto-Binding TLV: Version %d "
		   "Received Version %d SubType %d",
		   rbind->version, rbind->received_version, rbind->subtype);
	wpa_hexdump(0, "EAP-FAST: NONCE",
		    rbind->nonce, sizeof(rbind->nonce));
	wpa_hexdump(0, "EAP-FAST: Compound MAC",
		    rbind->compound_mac, sizeof(rbind->compound_mac));
}


static int eap_fast_get_phase2_key(struct eap_sm *sm,
				   struct eap_fast_data *data,
				   unsigned char *isk, size_t isk_len)
{
	unsigned char *key;
	size_t key_len;

	os_memset(isk, 0, isk_len);

	if (data->phase2_method == 0 || data->phase2_priv == 0) {
		wpa_printf(0, "EAP-FAST: Phase 2 method not "
			   "available");
		return -1;
	}

	if (data->phase2_method->isKeyAvailable == 0 ||
	    data->phase2_method->getKey == 0)
		return 0;

	if (!data->phase2_method->isKeyAvailable(sm, data->phase2_priv) ||
	    (key = data->phase2_method->getKey(sm, data->phase2_priv,
					       &key_len)) == 0) {
		wpa_printf(0, "EAP-FAST: Could not get key material "
			   "from Phase 2");
		return -1;
	}

	if (key_len > isk_len)
		key_len = isk_len;
	if (key_len == 32 &&
	    data->phase2_method->vendor == EAP_VENDOR_IETF &&
	    data->phase2_method->method == EAP_TYPE_MSCHAPV2) {
		



 
		os_memcpy(isk, key + 16, 16);
		os_memcpy(isk + 16, key, 16);
	} else
		os_memcpy(isk, key, key_len);
	os_free(key);

	return 0;
}


static int eap_fast_get_cmk(struct eap_sm *sm, struct eap_fast_data *data,
			    unsigned char *cmk)
{
	unsigned char isk[32], imck[60];

	wpa_printf(0, "EAP-FAST: Determining CMK[%d] for Compound MIC "
		   "calculation", data->simck_idx + 1);

	





 

	if (eap_fast_get_phase2_key(sm, data, isk, sizeof(isk)) < 0)
		return -1;
	wpa_hexdump_key(0, "EAP-FAST: ISK[j]", isk, sizeof(isk));
	sha1_t_prf(data->simck, 40,
		   "Inner Methods Compound Keys",
		   isk, sizeof(isk), imck, sizeof(imck));
	data->simck_idx++;
	os_memcpy(data->simck, imck, 40);
	wpa_hexdump_key(0, "EAP-FAST: S-IMCK[j]",
			data->simck, 40);
	os_memcpy(cmk, imck + 40, 20);
	wpa_hexdump_key(0, "EAP-FAST: CMK[j]",
			cmk, 20);

	return 0;
}


static unsigned char * eap_fast_write_pac_request(unsigned char *pos, unsigned short pac_type)
{
	struct eap_tlv_hdr *pac;
	struct eap_tlv_request_action_tlv *act;
	struct eap_tlv_pac_type_tlv *type;

	act = (struct eap_tlv_request_action_tlv *) pos;
	act->tlv_type = (( unsigned short) ((((unsigned short) ((19)) << 8) & 0xff00) | (((unsigned short) ((19)) >> 8) & 0xff)));
	act->length = (( unsigned short) ((((unsigned short) ((2)) << 8) & 0xff00) | (((unsigned short) ((2)) >> 8) & 0xff)));
	act->action = (( unsigned short) ((((unsigned short) ((1)) << 8) & 0xff00) | (((unsigned short) ((1)) >> 8) & 0xff)));

	pac = (struct eap_tlv_hdr *) (act + 1);
	pac->tlv_type = (( unsigned short) ((((unsigned short) ((11)) << 8) & 0xff00) | (((unsigned short) ((11)) >> 8) & 0xff)));
	pac->length = (( unsigned short) ((((unsigned short) ((sizeof(*type))) << 8) & 0xff00) | (((unsigned short) ((sizeof(*type))) >> 8) & 0xff)));

	type = (struct eap_tlv_pac_type_tlv *) (pac + 1);
	type->tlv_type = (( unsigned short) ((((unsigned short) ((10)) << 8) & 0xff00) | (((unsigned short) ((10)) >> 8) & 0xff)));
	type->length = (( unsigned short) ((((unsigned short) ((2)) << 8) & 0xff00) | (((unsigned short) ((2)) >> 8) & 0xff)));
	type->pac_type = (( unsigned short) ((((unsigned short) ((pac_type)) << 8) & 0xff00) | (((unsigned short) ((pac_type)) >> 8) & 0xff)));

	return (unsigned char *) (type + 1);
}


static struct wpabuf * eap_fast_process_crypto_binding(
	struct eap_sm *sm, struct eap_fast_data *data,
	struct eap_method_ret *ret,
	struct eap_tlv_crypto_binding_tlv *_bind, size_t bind_len)
{
	struct wpabuf *resp;
	unsigned char *pos;
	unsigned char cmk[20], cmac[20];
	int res;
	size_t len;

	if (eap_fast_validate_crypto_binding(_bind) < 0)
		return 0;

	if (eap_fast_get_cmk(sm, data, cmk) < 0)
		return 0;

	 
	os_memcpy(cmac, _bind->compound_mac, sizeof(cmac));
	os_memset(_bind->compound_mac, 0, sizeof(cmac));
	wpa_hexdump(0, "EAP-FAST: Crypto-Binding TLV for Compound "
		    "MAC calculation", (unsigned char *) _bind, bind_len);
	hmac_sha1(cmk, 20, (unsigned char *) _bind, bind_len,
		  _bind->compound_mac);
	res = os_memcmp(cmac, _bind->compound_mac, sizeof(cmac));
	wpa_hexdump(0, "EAP-FAST: Received Compound MAC",
		    cmac, sizeof(cmac));
	wpa_hexdump(0, "EAP-FAST: Calculated Compound MAC",
		    _bind->compound_mac, sizeof(cmac));
	if (res != 0) {
		wpa_printf(0, "EAP-FAST: Compound MAC did not match");
		os_memcpy(_bind->compound_mac, cmac, sizeof(cmac));
		return 0;
	}

	


 

	len = sizeof(struct eap_tlv_crypto_binding_tlv);
	resp = wpabuf_alloc(len);
	if (resp == 0)
		return 0;

	if (!data->anon_provisioning && data->phase2_success &&
	    eap_fast_derive_msk(data) < 0) {
		wpa_printf(0, "EAP-FAST: Failed to generate MSK");
		ret->methodState = METHOD_DONE;
		ret->decision = DECISION_FAIL;
		data->phase2_success = 0;
		wpabuf_free(resp);
		return 0;
	}

	pos = wpabuf_put(resp, sizeof(struct eap_tlv_crypto_binding_tlv));
	eap_fast_write_crypto_binding((struct eap_tlv_crypto_binding_tlv *)
				      pos, _bind, cmk);

	return resp;
}


static void eap_fast_parse_pac_tlv(struct eap_fast_pac *entry, int type,
				   unsigned char *pos, size_t len, int *pac_key_found)
{
	switch (type & 0x7fff) {
	case 1:
		wpa_hexdump_key(0, "EAP-FAST: PAC-Key", pos, len);
		if (len != 32) {
			wpa_printf(0, "EAP-FAST: Invalid PAC-Key "
				   "length %lu", (unsigned long) len);
			break;
		}
		*pac_key_found = 1;
		os_memcpy(entry->pac_key, pos, len);
		break;
	case 2:
		wpa_hexdump(0, "EAP-FAST: PAC-Opaque", pos, len);
		entry->pac_opaque = pos;
		entry->pac_opaque_len = len;
		break;
	case 9:
		wpa_hexdump(0, "EAP-FAST: PAC-Info", pos, len);
		entry->pac_info = pos;
		entry->pac_info_len = len;
		break;
	default:
		wpa_printf(0, "EAP-FAST: Ignored unknown PAC type %d",
			   type);
		break;
	}
}


static int eap_fast_process_pac_tlv(struct eap_fast_pac *entry,
				    unsigned char *pac, size_t pac_len)
{
	struct pac_tlv_hdr *hdr;
	unsigned char *pos;
	size_t left, len;
	int type, pac_key_found = 0;

	pos = pac;
	left = pac_len;

	while (left > sizeof(*hdr)) {
		hdr = (struct pac_tlv_hdr *) pos;
		type = ((((unsigned short) ((unsigned short) (unsigned short) (hdr->type)) << 8) & 0xff00) | (((unsigned short) ((unsigned short) (unsigned short) (hdr->type)) >> 8) & 0xff));
		len = ((((unsigned short) ((unsigned short) (unsigned short) (hdr->len)) << 8) & 0xff00) | (((unsigned short) ((unsigned short) (unsigned short) (hdr->len)) >> 8) & 0xff));
		pos += sizeof(*hdr);
		left -= sizeof(*hdr);
		if (len > left) {
			wpa_printf(0, "EAP-FAST: PAC TLV overrun "
				   "(type=%d len=%lu left=%lu)",
				   type, (unsigned long) len,
				   (unsigned long) left);
			return -1;
		}

		eap_fast_parse_pac_tlv(entry, type, pos, len, &pac_key_found);

		pos += len;
		left -= len;
	}

	if (!pac_key_found || !entry->pac_opaque || !entry->pac_info) {
		wpa_printf(0, "EAP-FAST: PAC TLV does not include "
			   "all the required fields");
		return -1;
	}

	return 0;
}


static int eap_fast_parse_pac_info(struct eap_fast_pac *entry, int type,
				   unsigned char *pos, size_t len)
{
	unsigned short pac_type;
	unsigned int lifetime;
	struct os_time now;

	switch (type & 0x7fff) {
	case 3:
		if (len != 4) {
			wpa_hexdump(0, "EAP-FAST: PAC-Info - "
				    "Invalid CRED_LIFETIME length - ignored",
				    pos, len);
			return 0;
		}

		




 
		lifetime = ((((unsigned int) (pos)[0]) << 24) | (((unsigned int) (pos)[1]) << 16) | (((unsigned int) (pos)[2]) << 8) | ((unsigned int) (pos)[3]));
		os_get_time(&now);
		wpa_printf(0, "EAP-FAST: PAC-Info - CRED_LIFETIME %d "
			   "(%d days)",
			   lifetime, (lifetime - (unsigned int) now.sec) / 86400);
		break;
	case 4:
		wpa_hexdump_ascii(0, "EAP-FAST: PAC-Info - A-ID",
				  pos, len);
		entry->a_id = pos;
		entry->a_id_len = len;
		break;
	case 5:
		wpa_hexdump_ascii(0, "EAP-FAST: PAC-Info - I-ID",
				  pos, len);
		entry->i_id = pos;
		entry->i_id_len = len;
		break;
	case 7:
		wpa_hexdump_ascii(0, "EAP-FAST: PAC-Info - A-ID-Info",
				  pos, len);
		entry->a_id_info = pos;
		entry->a_id_info_len = len;
		break;
	case 10:
		 
		if (len != 2) {
			wpa_printf(0, "EAP-FAST: Invalid PAC-Type "
				   "length %lu (expected 2)",
				   (unsigned long) len);
			wpa_hexdump_ascii(0,
					  "EAP-FAST: PAC-Info - PAC-Type",
					  pos, len);
			return -1;
		}
		pac_type = ((unsigned short) (((pos)[0] << 8) | (pos)[1]));
		if (pac_type != 1 &&
		    pac_type != 3 &&
		    pac_type != 2) {
			wpa_printf(0, "EAP-FAST: Unsupported PAC Type "
				   "%d", pac_type);
			return -1;
		}

		wpa_printf(0, "EAP-FAST: PAC-Info - PAC-Type %d",
			   pac_type);
		entry->pac_type = pac_type;
		break;
	default:
		wpa_printf(0, "EAP-FAST: Ignored unknown PAC-Info "
			   "type %d", type);
		break;
	}

	return 0;
}


static int eap_fast_process_pac_info(struct eap_fast_pac *entry)
{
	struct pac_tlv_hdr *hdr;
	unsigned char *pos;
	size_t left, len;
	int type;

	 

	 
	entry->pac_type = 1;

	pos = entry->pac_info;
	left = entry->pac_info_len;
	while (left > sizeof(*hdr)) {
		hdr = (struct pac_tlv_hdr *) pos;
		type = ((((unsigned short) ((unsigned short) (unsigned short) (hdr->type)) << 8) & 0xff00) | (((unsigned short) ((unsigned short) (unsigned short) (hdr->type)) >> 8) & 0xff));
		len = ((((unsigned short) ((unsigned short) (unsigned short) (hdr->len)) << 8) & 0xff00) | (((unsigned short) ((unsigned short) (unsigned short) (hdr->len)) >> 8) & 0xff));
		pos += sizeof(*hdr);
		left -= sizeof(*hdr);
		if (len > left) {
			wpa_printf(0, "EAP-FAST: PAC-Info overrun "
				   "(type=%d len=%lu left=%lu)",
				   type, (unsigned long) len,
				   (unsigned long) left);
			return -1;
		}

		if (eap_fast_parse_pac_info(entry, type, pos, len) < 0)
			return -1;

		pos += len;
		left -= len;
	}

	if (entry->a_id == 0 || entry->a_id_info == 0) {
		wpa_printf(0, "EAP-FAST: PAC-Info does not include "
			   "all the required fields");
		return -1;
	}

	return 0;
}


static struct wpabuf * eap_fast_process_pac(struct eap_sm *sm,
					    struct eap_fast_data *data,
					    struct eap_method_ret *ret,
					    unsigned char *pac, size_t pac_len)
{
	struct eap_peer_config *config = eap_get_config(sm);
	struct eap_fast_pac entry;

	os_memset(&entry, 0, sizeof(entry));
	if (eap_fast_process_pac_tlv(&entry, pac, pac_len) ||
	    eap_fast_process_pac_info(&entry))
		return 0;

	eap_fast_add_pac(&data->pac, &data->current_pac, &entry);
	eap_fast_pac_list_truncate(data->pac, data->max_pac_list_len);
	if (data->use_pac_binary_format)
		eap_fast_save_pac_bin(sm, data->pac, config->pac_file);
	else
		eap_fast_save_pac(sm, data->pac, config->pac_file);

	if (data->provisioning) {
		if (data->anon_provisioning) {
			



 
			data->success = 0;
			ret->decision = DECISION_FAIL;
		} else {
			


 
			ret->decision = DECISION_COND_SUCC;
		}
		wpa_printf(0, "EAP-FAST: Send PAC-Acknowledgement TLV "
			   "- Provisioning completed successfully");
	} else {
		


 
		wpa_printf(0, "EAP-FAST: Send PAC-Acknowledgement TLV "
			   "- PAC refreshing completed successfully");
		ret->decision = DECISION_UNCOND_SUCC;
	}
	ret->methodState = METHOD_DONE;
	return eap_fast_tlv_pac_ack();
}


static int eap_fast_parse_decrypted(struct wpabuf *decrypted,
				    struct eap_fast_tlv_parse *tlv,
				    struct wpabuf **resp)
{
	int mandatory, tlv_type, len, res;
	unsigned char *pos, *end;

	os_memset(tlv, 0, sizeof(*tlv));

	 
	pos = wpabuf_mhead(decrypted);
	end = pos + wpabuf_len(decrypted);
	while (pos + 4 < end) {
		mandatory = pos[0] & 0x80;
		tlv_type = ((unsigned short) (((pos)[0] << 8) | (pos)[1])) & 0x3fff;
		pos += 2;
		len = ((unsigned short) (((pos)[0] << 8) | (pos)[1]));
		pos += 2;
		if (pos + len > end) {
			wpa_printf(0, "EAP-FAST: TLV overflow");
			return -1;
		}
		wpa_printf(0, "EAP-FAST: Received Phase 2: "
			   "TLV type %d length %d%s",
			   tlv_type, len, mandatory ? " (mandatory)" : "");

		res = eap_fast_parse_tlv(tlv, tlv_type, pos, len);
		if (res == -2)
			break;
		if (res < 0) {
			if (mandatory) {
				wpa_printf(0, "EAP-FAST: Nak unknown "
					   "mandatory TLV type %d", tlv_type);
				*resp = eap_fast_tlv_nak(0, tlv_type);
				break;
			} else {
				wpa_printf(0, "EAP-FAST: ignored "
					   "unknown optional TLV type %d",
					   tlv_type);
			}
		}

		pos += len;
	}

	return 0;
}


static int eap_fast_encrypt_response(struct eap_sm *sm,
				     struct eap_fast_data *data,
				     struct wpabuf *resp,
				     unsigned char identifier, struct wpabuf **out_data)
{
	if (resp == 0)
		return 0;

	wpa_hexdump_buf(0, "EAP-FAST: Encrypting Phase 2 data",
			resp);
	if (eap_peer_tls_encrypt(sm, &data->ssl, EAP_TYPE_FAST,
				 data->fast_version, identifier,
				 resp, out_data)) {
		wpa_printf(0, "EAP-FAST: Failed to encrypt a Phase 2 "
			   "frame");
	}
	wpabuf_free(resp);

	return 0;
}


static struct wpabuf * eap_fast_pac_request(void)
{
	struct wpabuf *tmp;
	unsigned char *pos, *pos2;

	tmp = wpabuf_alloc(sizeof(struct eap_tlv_hdr) +
			   sizeof(struct eap_tlv_request_action_tlv) +
			   sizeof(struct eap_tlv_pac_type_tlv));
	if (tmp == 0)
		return 0;

	pos = wpabuf_put(tmp, 0);
	pos2 = eap_fast_write_pac_request(pos, 1);
	wpabuf_put(tmp, pos2 - pos);
	return tmp;
}


static int eap_fast_process_decrypted(struct eap_sm *sm,
				      struct eap_fast_data *data,
				      struct eap_method_ret *ret,
				      const struct eap_hdr *req,
				      struct wpabuf *decrypted,
				      struct wpabuf **out_data)
{
	struct wpabuf *resp = 0, *tmp;
	struct eap_fast_tlv_parse tlv;
	int failed = 0;

	if (eap_fast_parse_decrypted(decrypted, &tlv, &resp) < 0)
		return 0;
	if (resp)
		return eap_fast_encrypt_response(sm, data, resp,
						 req->identifier, out_data);

	if (tlv.result == 2) {
		resp = eap_fast_tlv_result(2, 0);
		return eap_fast_encrypt_response(sm, data, resp,
						 req->identifier, out_data);
	}

	if (tlv.iresult == 2) {
		resp = eap_fast_tlv_result(2, 1);
		return eap_fast_encrypt_response(sm, data, resp,
						 req->identifier, out_data);
	}

	if (tlv.crypto_binding) {
		tmp = eap_fast_process_crypto_binding(sm, data, ret,
						      tlv.crypto_binding,
						      tlv.crypto_binding_len);
		if (tmp == 0)
			failed = 1;
		else
			resp = wpabuf_concat(resp, tmp);
	}

	if (tlv.iresult == 1) {
		tmp = eap_fast_tlv_result(failed ? 2 :
					  1, 1);
		resp = wpabuf_concat(resp, tmp);
	}

	if (tlv.eap_payload_tlv) {
		tmp = eap_fast_process_eap_payload_tlv(
			sm, data, ret, req, tlv.eap_payload_tlv,
			tlv.eap_payload_tlv_len);
		resp = wpabuf_concat(resp, tmp);
	}

	if (tlv.pac && tlv.result != 1) {
		wpa_printf(0, "EAP-FAST: PAC TLV without Result TLV "
			   "acknowledging success");
		failed = 1;
	} else if (tlv.pac && tlv.result == 1) {
		tmp = eap_fast_process_pac(sm, data, ret, tlv.pac,
					   tlv.pac_len);
		resp = wpabuf_concat(resp, tmp);
	}

	if (data->current_pac == 0 && data->provisioning &&
	    !data->anon_provisioning && !tlv.pac &&
	    (tlv.iresult == 1 ||
	     tlv.result == 1)) {
		


 
		wpa_printf(0, "EAP-FAST: Request Tunnel PAC");
		tmp = eap_fast_pac_request();
		resp = wpabuf_concat(resp, tmp);
	}

	if (tlv.result == 1 && !failed) {
		tmp = eap_fast_tlv_result(1, 0);
		resp = wpabuf_concat(tmp, resp);
	} else if (failed) {
		tmp = eap_fast_tlv_result(2, 0);
		resp = wpabuf_concat(tmp, resp);
	}

	if (resp && tlv.result == 1 && !failed &&
	    tlv.crypto_binding && data->phase2_success) {
		if (data->anon_provisioning) {
			wpa_printf(0, "EAP-FAST: Unauthenticated "
				   "provisioning completed successfully.");
			ret->methodState = METHOD_DONE;
			ret->decision = DECISION_FAIL;
		} else {
			wpa_printf(0, "EAP-FAST: Authentication "
				   "completed successfully.");
			if (data->provisioning)
				ret->methodState = METHOD_MAY_CONT;
			else
				ret->methodState = METHOD_DONE;
			ret->decision = DECISION_UNCOND_SUCC;
		}
	}

	if (resp == 0) {
		wpa_printf(0, "EAP-FAST: No recognized TLVs - send "
			   "empty response packet");
		resp = wpabuf_alloc(1);
	}

	return eap_fast_encrypt_response(sm, data, resp, req->identifier,
					 out_data);
}


static int eap_fast_decrypt(struct eap_sm *sm, struct eap_fast_data *data,
			    struct eap_method_ret *ret,
			    const struct eap_hdr *req,
			    const struct wpabuf *in_data,
			    struct wpabuf **out_data)
{
	struct wpabuf *in_decrypted;
	int res;

	wpa_printf(0, "EAP-FAST: Received %lu bytes encrypted data for"
		   " Phase 2", (unsigned long) wpabuf_len(in_data));

	if (data->pending_phase2_req) {
		wpa_printf(0, "EAP-FAST: Pending Phase 2 request - "
			   "skip decryption and use old data");
		 
		eap_peer_tls_reset_input(&data->ssl);

		in_decrypted = data->pending_phase2_req;
		data->pending_phase2_req = 0;
		goto continue_req;
	}

	if (wpabuf_len(in_data) == 0) {
		 
		return eap_peer_tls_encrypt(sm, &data->ssl, EAP_TYPE_FAST,
					    data->fast_version,
					    req->identifier, 0, out_data);
	}

	res = eap_peer_tls_decrypt(sm, &data->ssl, in_data, &in_decrypted);
	if (res)
		return res;

continue_req:
	wpa_hexdump_buf(0, "EAP-FAST: Decrypted Phase 2 TLV(s)",
			in_decrypted);

	if (wpabuf_len(in_decrypted) < 4) {
		wpa_printf(0, "EAP-FAST: Too short Phase 2 "
			   "TLV frame (len=%lu)",
			   (unsigned long) wpabuf_len(in_decrypted));
		wpabuf_free(in_decrypted);
		return -1;
	}

	res = eap_fast_process_decrypted(sm, data, ret, req,
					 in_decrypted, out_data);

	wpabuf_free(in_decrypted);

	return res;
}


static const unsigned char * eap_fast_get_a_id(const unsigned char *buf, size_t len, size_t *id_len)
{
	const unsigned char *a_id;
	struct pac_tlv_hdr *hdr;

	


 
	a_id = buf;
	*id_len = len;
	if (len > sizeof(*hdr)) {
		int tlen;
		hdr = (struct pac_tlv_hdr *) buf;
		tlen = ((((unsigned short) ((unsigned short) (unsigned short) (hdr->len)) << 8) & 0xff00) | (((unsigned short) ((unsigned short) (unsigned short) (hdr->len)) >> 8) & 0xff));
		if (((((unsigned short) ((unsigned short) (unsigned short) (hdr->type)) << 8) & 0xff00) | (((unsigned short) ((unsigned short) (unsigned short) (hdr->type)) >> 8) & 0xff)) == 4 &&
		    sizeof(*hdr) + tlen <= len) {
			wpa_printf(0, "EAP-FAST: A-ID was in TLV "
				   "(Start)");
			a_id = (unsigned char *) (hdr + 1);
			*id_len = tlen;
		}
	}
	wpa_hexdump_ascii(0, "EAP-FAST: A-ID", a_id, *id_len);

	return a_id;
}


static void eap_fast_select_pac(struct eap_fast_data *data,
				const unsigned char *a_id, size_t a_id_len)
{
	data->current_pac = eap_fast_get_pac(data->pac, a_id, a_id_len,
					     1);
	if (data->current_pac == 0) {
		


 
		data->current_pac = eap_fast_get_pac(
			data->pac, a_id, a_id_len,
			2);
	}

	if (data->current_pac) {
		wpa_printf(0, "EAP-FAST: PAC found for this A-ID "
			   "(PAC-Type %d)", data->current_pac->pac_type);
		wpa_hexdump_ascii(0, "EAP-FAST: A-ID-Info",
				  data->current_pac->a_id_info,
				  data->current_pac->a_id_info_len);
	}
}


static int eap_fast_use_pac_opaque(struct eap_sm *sm,
				   struct eap_fast_data *data,
				   struct eap_fast_pac *pac)
{
	unsigned char *tlv;
	size_t tlv_len, olen;
	struct eap_tlv_hdr *ehdr;

	olen = pac->pac_opaque_len;
	tlv_len = sizeof(*ehdr) + olen;
	tlv = os_malloc(tlv_len);
	if (tlv) {
		ehdr = (struct eap_tlv_hdr *) tlv;
		ehdr->tlv_type = (( unsigned short) ((((unsigned short) ((2)) << 8) & 0xff00) | (((unsigned short) ((2)) >> 8) & 0xff)));
		ehdr->length = (( unsigned short) ((((unsigned short) ((olen)) << 8) & 0xff00) | (((unsigned short) ((olen)) >> 8) & 0xff)));
		os_memcpy(ehdr + 1, pac->pac_opaque, olen);
	}
	if (tlv == 0 ||
	    tls_connection_client_hello_ext(sm->ssl_ctx, data->ssl.conn,
					    35,
					    tlv, tlv_len) < 0) {
		wpa_printf(0, "EAP-FAST: Failed to add PAC-Opaque TLS "
			   "extension");
		os_free(tlv);
		return -1;
	}
	os_free(tlv);

	return 0;
}


static int eap_fast_clear_pac_opaque_ext(struct eap_sm *sm,
					 struct eap_fast_data *data)
{
	if (tls_connection_client_hello_ext(sm->ssl_ctx, data->ssl.conn,
					    35, 0, 0) < 0) {
		wpa_printf(0, "EAP-FAST: Failed to remove PAC-Opaque "
			   "TLS extension");
		return -1;
	}
	return 0;
}


static int eap_fast_set_provisioning_ciphers(struct eap_sm *sm,
					     struct eap_fast_data *data)
{
	unsigned char ciphers[5];
	int count = 0;

	if (data->provisioning_allowed & 1) {
		wpa_printf(0, "EAP-FAST: Enabling unauthenticated "
			   "provisioning TLS cipher suites");
		ciphers[count++] = TLS_CIPHER_ANON_DH_AES128_SHA;
	}

	if (data->provisioning_allowed & 2) {
		wpa_printf(0, "EAP-FAST: Enabling authenticated "
			   "provisioning TLS cipher suites");
		ciphers[count++] = TLS_CIPHER_RSA_DHE_AES128_SHA;
		ciphers[count++] = TLS_CIPHER_AES128_SHA;
		ciphers[count++] = TLS_CIPHER_RC4_SHA;
	}

	ciphers[count++] = TLS_CIPHER_NONE;

	if (tls_connection_set_cipher_list(sm->ssl_ctx, data->ssl.conn,
					   ciphers)) {
		wpa_printf(0, "EAP-FAST: Could not configure TLS "
			   "cipher suites for provisioning");
		return -1;
	}

	return 0;
}


static int eap_fast_process_start(struct eap_sm *sm,
				  struct eap_fast_data *data, unsigned char flags,
				  const unsigned char *pos, size_t left)
{
	const unsigned char *a_id;
	size_t a_id_len;

	 
	wpa_printf(0, "EAP-FAST: Start (server ver=%d, own ver=%d)",
		   flags & 0x07, data->fast_version);
	if ((flags & 0x07) < data->fast_version)
		data->fast_version = flags & 0x07;
	wpa_printf(0, "EAP-FAST: Using FAST version %d",
		   data->fast_version);

	a_id = eap_fast_get_a_id(pos, left, &a_id_len);
	eap_fast_select_pac(data, a_id, a_id_len);

	if (data->resuming && data->current_pac) {
		wpa_printf(0, "EAP-FAST: Trying to resume session - "
			   "do not add PAC-Opaque to TLS ClientHello");
		if (eap_fast_clear_pac_opaque_ext(sm, data) < 0)
			return -1;
	} else if (data->current_pac) {
		


 
		if (eap_fast_use_pac_opaque(sm, data, data->current_pac) < 0)
			return -1;
	} else {
		 
		if (!data->provisioning_allowed) {
			wpa_printf(0, "EAP-FAST: No PAC found and "
				   "provisioning disabled");
			return -1;
		}
		wpa_printf(0, "EAP-FAST: No PAC found - "
			   "starting provisioning");
		if (eap_fast_set_provisioning_ciphers(sm, data) < 0 ||
		    eap_fast_clear_pac_opaque_ext(sm, data) < 0)
			return -1;
		data->provisioning = 1;
	}

	return 0;
}


static struct wpabuf * eap_fast_process(struct eap_sm *sm, void *priv,
					struct eap_method_ret *ret,
					const struct wpabuf *reqData)
{
	const struct eap_hdr *req;
	size_t left;
	int res;
	unsigned char flags, id;
	struct wpabuf *resp;
	const unsigned char *pos;
	struct eap_fast_data *data = priv;

	pos = eap_peer_tls_process_init(sm, &data->ssl, EAP_TYPE_FAST, ret,
					reqData, &left, &flags);
	if (pos == 0)
		return 0;

	req = wpabuf_head(reqData);
	id = req->identifier;

	if (flags & 0x20) {
		if (eap_fast_process_start(sm, data, flags, pos, left) < 0)
			return 0;

		left = 0;  
	}

	resp = 0;
	if (tls_connection_established(sm->ssl_ctx, data->ssl.conn) &&
	    !data->resuming) {
		 
		struct wpabuf msg;
		wpabuf_set(&msg, pos, left);
		res = eap_fast_decrypt(sm, data, ret, req, &msg, &resp);
		if (res < 0) {
			ret->methodState = METHOD_DONE;
			ret->decision = DECISION_FAIL;
			


 
			res = 1;
		}
	} else {
		 
		res = eap_peer_tls_process_helper(sm, &data->ssl,
						  EAP_TYPE_FAST,
						  data->fast_version, id, pos,
						  left, &resp);

		if (tls_connection_established(sm->ssl_ctx, data->ssl.conn)) {
			char cipher[80];
			wpa_printf(0,
				   "EAP-FAST: TLS done, proceed to Phase 2");
			if (data->provisioning &&
			    (!(data->provisioning_allowed &
			       2) ||
			     tls_get_cipher(sm->ssl_ctx, data->ssl.conn,
					    cipher, sizeof(cipher)) < 0 ||
			     os_strstr(cipher, "ADH-") ||
			     os_strstr(cipher, "anon"))) {
				wpa_printf(0, "EAP-FAST: Using "
					   "anonymous (unauthenticated) "
					   "provisioning");
				data->anon_provisioning = 1;
			} else
				data->anon_provisioning = 0;
			data->resuming = 0;
			eap_fast_derive_keys(sm, data);
		}

		if (res == 2) {
			struct wpabuf msg;
			

 
			wpabuf_free(data->pending_phase2_req);
			data->pending_phase2_req = resp;
			resp = 0;
			wpabuf_set(&msg, pos, left);
			res = eap_fast_decrypt(sm, data, ret, req, &msg,
					       &resp);
		}
	}

	if (res == 1) {
		wpabuf_free(resp);
		return eap_peer_tls_build_ack(id, EAP_TYPE_FAST,
					      data->fast_version);
	}

	return resp;
}


#line 1619 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_fast.c"


static int eap_fast_get_status(struct eap_sm *sm, void *priv, char *buf,
			       size_t buflen, int verbose)
{
	struct eap_fast_data *data = priv;
	int len, ret;

	len = eap_peer_tls_status(sm, &data->ssl, buf, buflen, verbose);
	if (data->phase2_method) {
		ret = os_snprintf(buf + len, buflen - len,
				  "EAP-FAST Phase2 method=%s\n",
				  data->phase2_method->name);
		if (ret < 0 || (size_t) ret >= buflen - len)
			return len;
		len += ret;
	}
	return len;
}


static int eap_fast_isKeyAvailable(struct eap_sm *sm, void *priv)
{
	struct eap_fast_data *data = priv;
	return data->success;
}


static unsigned char * eap_fast_getKey(struct eap_sm *sm, void *priv, size_t *len)
{
	struct eap_fast_data *data = priv;
	unsigned char *key;

	if (!data->success)
		return 0;

	key = os_malloc(64);
	if (key == 0)
		return 0;

	*len = 64;
	os_memcpy(key, data->key_data, 64);

	return key;
}


static unsigned char * eap_fast_get_emsk(struct eap_sm *sm, void *priv, size_t *len)
{
	struct eap_fast_data *data = priv;
	unsigned char *key;

	if (!data->success)
		return 0;

	key = os_malloc(64);
	if (key == 0)
		return 0;

	*len = 64;
	os_memcpy(key, data->emsk, 64);

	return key;
}


int eap_peer_fast_register(void)
{
	struct eap_method *eap;
	int ret;

	eap = eap_peer_method_alloc(1,
				    EAP_VENDOR_IETF, EAP_TYPE_FAST, "FAST");
	if (eap == 0)
		return -1;

	eap->init = eap_fast_init;
	eap->deinit = eap_fast_deinit;
	eap->process = eap_fast_process;
	eap->isKeyAvailable = eap_fast_isKeyAvailable;
	eap->getKey = eap_fast_getKey;
	eap->get_status = eap_fast_get_status;





	eap->get_emsk = eap_fast_get_emsk;

	ret = eap_peer_method_register(eap);
	if (ret)
		eap_peer_method_free(eap);
	return ret;
}
