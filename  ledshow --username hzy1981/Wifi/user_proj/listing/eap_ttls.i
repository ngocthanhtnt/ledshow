#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_ttls.c"












 

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

#line 16 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_ttls.c"

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



#line 18 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_ttls.c"
#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\crypto/ms_funcs.h"












 




#line 19 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\crypto/ms_funcs.h"

int generate_nt_response(const unsigned char *auth_challenge, const unsigned char *peer_challenge,
			 const unsigned char *username, size_t username_len,
			 const unsigned char *password, size_t password_len,
			 unsigned char *response);
int generate_nt_response_pwhash(const unsigned char *auth_challenge,
				const unsigned char *peer_challenge,
				const unsigned char *username, size_t username_len,
				const unsigned char *password_hash,
				unsigned char *response);
int generate_authenticator_response(const unsigned char *password, size_t password_len,
				    const unsigned char *peer_challenge,
				    const unsigned char *auth_challenge,
				    const unsigned char *username, size_t username_len,
				    const unsigned char *nt_response, unsigned char *response);
int generate_authenticator_response_pwhash(
	const unsigned char *password_hash,
	const unsigned char *peer_challenge, const unsigned char *auth_challenge,
	const unsigned char *username, size_t username_len,
	const unsigned char *nt_response, unsigned char *response);
int nt_challenge_response(const unsigned char *challenge, const unsigned char *password,
			  size_t password_len, unsigned char *response);

void challenge_response(const unsigned char *challenge, const unsigned char *password_hash,
			unsigned char *response);
int nt_password_hash(const unsigned char *password, size_t password_len,
		     unsigned char *password_hash);
int hash_nt_password_hash(const unsigned char *password_hash, unsigned char *password_hash_hash);
int get_master_key(const unsigned char *password_hash_hash, const unsigned char *nt_response,
		   unsigned char *master_key);
int get_asymetric_start_key(const unsigned char *master_key, unsigned char *session_key,
			    size_t session_key_len, int is_send,
			    int is_server);
int  encrypt_pw_block_with_password_hash(
	const unsigned char *password, size_t password_len,
	const unsigned char *password_hash, unsigned char *pw_block);
int  new_password_encrypted_with_old_nt_password_hash(
	const unsigned char *new_password, size_t new_password_len,
	const unsigned char *old_password, size_t old_password_len,
	unsigned char *encrypted_pw_block);
void nt_password_hash_encrypted_with_block(const unsigned char *password_hash,
					   const unsigned char *block, unsigned char *cypher);
int old_nt_password_hash_encrypted_with_new_nt_password_hash(
	const unsigned char *new_password, size_t new_password_len,
	const unsigned char *old_password, size_t old_password_len,
	unsigned char *encrypted_password_hash);

#line 19 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_ttls.c"
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
#line 20 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_ttls.c"
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

#line 21 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_ttls.c"
#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common/chap.h"












 






int chap_md5(unsigned char id, const unsigned char *secret, size_t secret_len, const unsigned char *challenge,
	     size_t challenge_len, unsigned char *response);

#line 22 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_ttls.c"
#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common/eap_ttls.h"












 




struct ttls_avp {
	unsigned int avp_code;
	unsigned int avp_length; 
 
	 
	 
};

struct ttls_avp_vendor {
	unsigned int avp_code;
	unsigned int avp_length; 
 
	unsigned int vendor_id;
	 
};




#line 44 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common/eap_ttls.h"


 
#line 53 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common/eap_ttls.h"

 
#line 63 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common/eap_ttls.h"

#line 70 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common/eap_ttls.h"

#line 23 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_ttls.c"
#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\mschapv2.h"












 









const unsigned char * mschapv2_remove_domain(const unsigned char *username, size_t *len);
int mschapv2_derive_response(const unsigned char *username, size_t username_len,
			     const unsigned char *password, size_t password_len,
			     int pwhash,
			     const unsigned char *auth_challenge,
			     const unsigned char *peer_challenge,
			     unsigned char *nt_response, unsigned char *auth_response,
			     unsigned char *master_key);
int mschapv2_verify_auth_response(const unsigned char *auth_response,
				  const unsigned char *buf, size_t buf_len);

#line 24 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_ttls.c"
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

#line 25 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_ttls.c"
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

#line 26 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_ttls.c"
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

#line 27 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_ttls.c"





 









static void eap_ttls_deinit(struct eap_sm *sm, void *priv);


struct eap_ttls_data {
	struct eap_ssl_data ssl;
	int ssl_initialized;

	int ttls_version, force_ttls_version;

	const struct eap_method *phase2_method;
	void *phase2_priv;
	int phase2_success;
	int phase2_start;

	enum phase2_types {
		EAP_TTLS_PHASE2_EAP,
		EAP_TTLS_PHASE2_MSCHAPV2,
		EAP_TTLS_PHASE2_MSCHAP,
		EAP_TTLS_PHASE2_PAP,
		EAP_TTLS_PHASE2_CHAP
	} phase2_type;
	struct eap_method_type phase2_eap_type;
	struct eap_method_type *phase2_eap_types;
	size_t num_phase2_eap_types;

	unsigned char auth_response[20];
	int auth_response_valid;
	unsigned char master_key[16];  
	unsigned char ident;
	int resuming;  
	int reauth;  
	unsigned char *key_data;

	struct wpabuf *pending_phase2_req;





};


static void * eap_ttls_init(struct eap_sm *sm)
{
	struct eap_ttls_data *data;
	struct eap_peer_config *config = eap_get_config(sm);
	char *selected;

	data = os_zalloc(sizeof(*data));
	if (data == 0)
		return 0;
	data->ttls_version = 0;
	data->force_ttls_version = -1;
	selected = "EAP";
	data->phase2_type = EAP_TTLS_PHASE2_EAP;

#line 109 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_ttls.c"

	if (config && config->phase2) {
		if (os_strstr(config->phase2, "autheap=")) {
			selected = "EAP";
			data->phase2_type = EAP_TTLS_PHASE2_EAP;
		} else if (os_strstr(config->phase2, "auth=MSCHAPV2")) {
			selected = "MSCHAPV2";
			data->phase2_type = EAP_TTLS_PHASE2_MSCHAPV2;
		} else if (os_strstr(config->phase2, "auth=MSCHAP")) {
			selected = "MSCHAP";
			data->phase2_type = EAP_TTLS_PHASE2_MSCHAP;
		} else if (os_strstr(config->phase2, "auth=PAP")) {
			selected = "PAP";
			data->phase2_type = EAP_TTLS_PHASE2_PAP;
		} else if (os_strstr(config->phase2, "auth=CHAP")) {
			selected = "CHAP";
			data->phase2_type = EAP_TTLS_PHASE2_CHAP;
		}
	}
	wpa_printf(0, "EAP-TTLS: Phase2 type: %s", selected);

	if (data->phase2_type == EAP_TTLS_PHASE2_EAP) {
		if (eap_peer_select_phase2_methods(config, "autheap=",
						   &data->phase2_eap_types,
						   &data->num_phase2_eap_types)
		    < 0) {
			eap_ttls_deinit(sm, data);
			return 0;
		}

		data->phase2_eap_type.vendor = EAP_VENDOR_IETF;
		data->phase2_eap_type.method = EAP_TYPE_NONE;
	}

#line 156 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_ttls.c"

	return data;
}


static void eap_ttls_phase2_eap_deinit(struct eap_sm *sm,
				       struct eap_ttls_data *data)
{
	if (data->phase2_priv && data->phase2_method) {
		data->phase2_method->deinit(sm, data->phase2_priv);
		data->phase2_method = 0;
		data->phase2_priv = 0;
	}
}


static void eap_ttls_deinit(struct eap_sm *sm, void *priv)
{
	struct eap_ttls_data *data = priv;
	if (data == 0)
		return;
	eap_ttls_phase2_eap_deinit(sm, data);
	os_free(data->phase2_eap_types);
	if (data->ssl_initialized)
		eap_peer_tls_ssl_deinit(sm, &data->ssl);
	os_free(data->key_data);
	wpabuf_free(data->pending_phase2_req);
	os_free(data);
}


static unsigned char * eap_ttls_avp_hdr(unsigned char *avphdr, unsigned int avp_code, unsigned int vendor_id,
			     int mandatory, size_t len)
{
	struct ttls_avp_vendor *avp;
	unsigned char flags;
	size_t hdrlen;

	avp = (struct ttls_avp_vendor *) avphdr;
	flags = mandatory ? 0x40 : 0;
	if (vendor_id) {
		flags |= 0x80;
		hdrlen = sizeof(*avp);
		avp->vendor_id = (( unsigned int) ((((unsigned int) ((vendor_id)) << 24) & 0xff000000) | (((unsigned int) ((vendor_id)) << 8) & 0xff0000) | (((unsigned int) ((vendor_id)) >> 8) & 0xff00) | (((unsigned int) ((vendor_id)) >> 24) & 0xff)));
	} else {
		hdrlen = sizeof(struct ttls_avp);
	}

	avp->avp_code = (( unsigned int) ((((unsigned int) ((avp_code)) << 24) & 0xff000000) | (((unsigned int) ((avp_code)) << 8) & 0xff0000) | (((unsigned int) ((avp_code)) >> 8) & 0xff00) | (((unsigned int) ((avp_code)) >> 24) & 0xff)));
	avp->avp_length = (( unsigned int) ((((unsigned int) (((flags << 24) | (hdrlen + len))) << 24) & 0xff000000) | (((unsigned int) (((flags << 24) | (hdrlen + len))) << 8) & 0xff0000) | (((unsigned int) (((flags << 24) | (hdrlen + len))) >> 8) & 0xff00) | (((unsigned int) (((flags << 24) | (hdrlen + len))) >> 24) & 0xff)));

	return avphdr + hdrlen;
}


static unsigned char * eap_ttls_avp_add(unsigned char *start, unsigned char *avphdr, unsigned int avp_code,
			     unsigned int vendor_id, int mandatory,
			     const unsigned char *data, size_t len)
{
	unsigned char *pos;
	pos = eap_ttls_avp_hdr(avphdr, avp_code, vendor_id, mandatory, len);
	os_memcpy(pos, data, len);
	pos += len;
	do { int __pad; __pad = (4 - (((pos) - (start)) & 3)) & 3; os_memset((pos), 0, __pad); pos += __pad; } while (0);
	return pos;
}


static int eap_ttls_avp_encapsulate(struct wpabuf **resp, unsigned int avp_code,
				    int mandatory)
{
	struct wpabuf *msg;
	unsigned char *avp, *pos;

	msg = wpabuf_alloc(sizeof(struct ttls_avp) + wpabuf_len(*resp) + 4);
	if (msg == 0) {
		wpabuf_free(*resp);
		*resp = 0;
		return -1;
	}

	avp = wpabuf_mhead(msg);
	pos = eap_ttls_avp_hdr(avp, avp_code, 0, mandatory, wpabuf_len(*resp));
	os_memcpy(pos, wpabuf_head(*resp), wpabuf_len(*resp));
	pos += wpabuf_len(*resp);
	do { int __pad; __pad = (4 - (((pos) - (avp)) & 3)) & 3; os_memset((pos), 0, __pad); pos += __pad; } while (0);
	wpabuf_free(*resp);
	wpabuf_put(msg, pos - avp);
	*resp = msg;
	return 0;
}


#line 280 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_ttls.c"


static int eap_ttls_v0_derive_key(struct eap_sm *sm,
				  struct eap_ttls_data *data)
{
	os_free(data->key_data);
	data->key_data = eap_peer_tls_derive_key(sm, &data->ssl,
						 "ttls keying material",
						 64);
	if (!data->key_data) {
		wpa_printf(0, "EAP-TTLS: Failed to derive key");
		return -1;
	}

	wpa_hexdump_key(0, "EAP-TTLS: Derived key",
			data->key_data, 64);

	return 0;
}


#line 357 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_ttls.c"


static unsigned char * eap_ttls_implicit_challenge(struct eap_sm *sm,
					struct eap_ttls_data *data, size_t len)
{





	if (data->ttls_version == 0) {
		return eap_peer_tls_derive_key(sm, &data->ssl,
					       "ttls challenge", len);
	}

#line 416 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_ttls.c"

	return 0;


}


static void eap_ttlsv1_phase2_eap_finish(struct eap_sm *sm,
					 struct eap_ttls_data *data,
					 struct eap_method_ret *ret)
{
#line 451 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_ttls.c"
}


static void eap_ttls_phase2_select_eap_method(struct eap_ttls_data *data,
					      unsigned char method)
{
	size_t i;
	for (i = 0; i < data->num_phase2_eap_types; i++) {
		if (data->phase2_eap_types[i].vendor != EAP_VENDOR_IETF ||
		    data->phase2_eap_types[i].method != method)
			continue;

		data->phase2_eap_type.vendor =
			data->phase2_eap_types[i].vendor;
		data->phase2_eap_type.method =
			data->phase2_eap_types[i].method;
		wpa_printf(0, "EAP-TTLS: Selected "
			   "Phase 2 EAP vendor %d method %d",
			   data->phase2_eap_type.vendor,
			   data->phase2_eap_type.method);
		break;
	}
}


static int eap_ttls_phase2_eap_process(struct eap_sm *sm,
				       struct eap_ttls_data *data,
				       struct eap_method_ret *ret,
				       struct eap_hdr *hdr, size_t len,
				       struct wpabuf **resp)
{
	struct wpabuf msg;
	struct eap_method_ret iret;

	os_memset(&iret, 0, sizeof(iret));
	wpabuf_set(&msg, hdr, len);
	*resp = data->phase2_method->process(sm, data->phase2_priv, &iret,
					     &msg);
	if ((iret.methodState == METHOD_DONE ||
	     iret.methodState == METHOD_MAY_CONT) &&
	    (iret.decision == DECISION_UNCOND_SUCC ||
	     iret.decision == DECISION_COND_SUCC ||
	     iret.decision == DECISION_FAIL)) {
		ret->methodState = iret.methodState;
		ret->decision = iret.decision;
	}
	eap_ttlsv1_phase2_eap_finish(sm, data, ret);

	return 0;
}


static int eap_ttls_phase2_request_eap_method(struct eap_sm *sm,
					      struct eap_ttls_data *data,
					      struct eap_method_ret *ret,
					      struct eap_hdr *hdr, size_t len,
					      unsigned char method, struct wpabuf **resp)
{
#line 542 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_ttls.c"

	if (data->phase2_eap_type.vendor == EAP_VENDOR_IETF &&
	    data->phase2_eap_type.method == EAP_TYPE_NONE)
		eap_ttls_phase2_select_eap_method(data, method);

	if (method != data->phase2_eap_type.method || method == EAP_TYPE_NONE)
	{
		if (eap_peer_tls_phase2_nak(data->phase2_eap_types,
					    data->num_phase2_eap_types,
					    hdr, resp))
			return -1;
		return 0;
	}

	if (data->phase2_priv == 0) {
		data->phase2_method = eap_peer_get_eap_method(
			EAP_VENDOR_IETF, method);
		if (data->phase2_method) {
			sm->init_phase2 = 1;
			data->phase2_priv = data->phase2_method->init(sm);
			sm->init_phase2 = 0;
		}
	}
	if (data->phase2_priv == 0 || data->phase2_method == 0) {
		wpa_printf(0, "EAP-TTLS: failed to initialize "
			   "Phase 2 EAP method %d", method);
		return -1;
	}

	return eap_ttls_phase2_eap_process(sm, data, ret, hdr, len, resp);
}


static int eap_ttls_phase2_request_eap(struct eap_sm *sm,
				       struct eap_ttls_data *data,
				       struct eap_method_ret *ret,
				       struct eap_hdr *hdr,
				       struct wpabuf **resp)
{
	size_t len = ((((unsigned short) ((unsigned short) (unsigned short) (hdr->length)) << 8) & 0xff00) | (((unsigned short) ((unsigned short) (unsigned short) (hdr->length)) >> 8) & 0xff));
	unsigned char *pos;
	struct eap_peer_config *config = eap_get_config(sm);

	if (len <= sizeof(struct eap_hdr)) {
		wpa_printf(0, "EAP-TTLS: too short "
			   "Phase 2 request (len=%lu)", (unsigned long) len);
		return -1;
	}
	pos = (unsigned char *) (hdr + 1);
	wpa_printf(0, "EAP-TTLS: Phase 2 EAP Request: type=%d", *pos);
	switch (*pos) {
	case EAP_TYPE_IDENTITY:
		*resp = eap_sm_buildIdentity(sm, hdr->identifier, 1);
		break;
	default:
		if (eap_ttls_phase2_request_eap_method(sm, data, ret, hdr, len,
						       *pos, resp) < 0)
			return -1;
		break;
	}

	if (*resp == 0 &&
	    (config->pending_req_identity || config->pending_req_password ||
	     config->pending_req_otp)) {
		return 0;
	}

	if (*resp == 0)
		return -1;

	wpa_hexdump_buf(0, "EAP-TTLS: AVP encapsulate EAP Response",
			*resp);
	return eap_ttls_avp_encapsulate(resp, 79, 1);
}


static void eap_ttlsv1_permute_inner(struct eap_sm *sm,
				     struct eap_ttls_data *data)
{
#line 635 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_ttls.c"
}


static int eap_ttls_phase2_request_mschapv2(struct eap_sm *sm,
					    struct eap_ttls_data *data,
					    struct eap_method_ret *ret,
					    struct wpabuf **resp)
{
	struct wpabuf *msg;
	unsigned char *buf, *pos, *challenge, *peer_challenge;
	const unsigned char *identity, *password;
	size_t identity_len, password_len;
	int pwhash;

	wpa_printf(0, "EAP-TTLS: Phase 2 MSCHAPV2 Request");

	identity = eap_get_config_identity(sm, &identity_len);
	password = eap_get_config_password2(sm, &password_len, &pwhash);
	if (identity == 0 || password == 0)
		return -1;

	msg = wpabuf_alloc(identity_len + 1000);
	if (msg == 0) {
		wpa_printf(0,
			   "EAP-TTLS/MSCHAPV2: Failed to allocate memory");
		return -1;
	}
	pos = buf = wpabuf_mhead(msg);

	 
	pos = eap_ttls_avp_add(buf, pos, 1, 0, 1,
			       identity, identity_len);

	 
	challenge = eap_ttls_implicit_challenge(
		sm, data, 16 + 1);
	if (challenge == 0) {
		wpabuf_free(msg);
		wpa_printf(0, "EAP-TTLS/MSCHAPV2: Failed to derive "
			   "implicit challenge");
		return -1;
	}
	peer_challenge = challenge + 1 + 16;

	pos = eap_ttls_avp_add(buf, pos, 11,
			       311, 1,
			       challenge, 16);

	 
	pos = eap_ttls_avp_hdr(pos, 25,
			       311, 1,
			       50);
	data->ident = challenge[16];
	*pos++ = data->ident;
	*pos++ = 0;  
	os_memcpy(pos, peer_challenge, 16);
	pos += 16;
	os_memset(pos, 0, 8);  
	pos += 8;
	if (mschapv2_derive_response(identity, identity_len, password,
				     password_len, pwhash, challenge,
				     peer_challenge, pos, data->auth_response,
				     data->master_key)) {
		wpabuf_free(msg);
		wpa_printf(0, "EAP-TTLS/MSCHAPV2: Failed to derive "
			   "response");
		return -1;
	}
	data->auth_response_valid = 1;

	eap_ttlsv1_permute_inner(sm, data);

	pos += 24;
	os_free(challenge);
	do { int __pad; __pad = (4 - (((pos) - (buf)) & 3)) & 3; os_memset((pos), 0, __pad); pos += __pad; } while (0);

	wpabuf_put(msg, pos - buf);
	*resp = msg;

	if (sm->workaround && data->ttls_version == 0) {
		

 
		wpa_printf(0, "EAP-TTLS/MSCHAPV2: EAP workaround - "
			   "allow success without tunneled response");
		ret->methodState = METHOD_MAY_CONT;
		ret->decision = DECISION_COND_SUCC;
	}

	return 0;
}


static int eap_ttls_phase2_request_mschap(struct eap_sm *sm,
					  struct eap_ttls_data *data,
					  struct eap_method_ret *ret,
					  struct wpabuf **resp)
{
	struct wpabuf *msg;
	unsigned char *buf, *pos, *challenge;
	const unsigned char *identity, *password;
	size_t identity_len, password_len;
	int pwhash;

	wpa_printf(0, "EAP-TTLS: Phase 2 MSCHAP Request");

	identity = eap_get_config_identity(sm, &identity_len);
	password = eap_get_config_password2(sm, &password_len, &pwhash);
	if (identity == 0 || password == 0)
		return -1;

	msg = wpabuf_alloc(identity_len + 1000);
	if (msg == 0) {
		wpa_printf(0,
			   "EAP-TTLS/MSCHAP: Failed to allocate memory");
		return -1;
	}
	pos = buf = wpabuf_mhead(msg);

	 
	pos = eap_ttls_avp_add(buf, pos, 1, 0, 1,
			       identity, identity_len);

	 
	challenge = eap_ttls_implicit_challenge(
		sm, data, 8 + 1);
	if (challenge == 0) {
		wpabuf_free(msg);
		wpa_printf(0, "EAP-TTLS/MSCHAP: Failed to derive "
			   "implicit challenge");
		return -1;
	}

	pos = eap_ttls_avp_add(buf, pos, 11,
			       311, 1,
			       challenge, 8);

	 
	pos = eap_ttls_avp_hdr(pos, 1,
			       311, 1,
			       50);
	data->ident = challenge[8];
	*pos++ = data->ident;
	*pos++ = 1;  
	os_memset(pos, 0, 24);  
	pos += 24;
	if (pwhash) {
		challenge_response(challenge, password, pos);  
		wpa_hexdump_key(0, "EAP-TTLS: MSCHAP password hash",
				password, 16);
	} else {
		nt_challenge_response(challenge, password, password_len,
				      pos);  
		wpa_hexdump_ascii_key(0, "EAP-TTLS: MSCHAP password",
				      password, password_len);
	}
	wpa_hexdump(0, "EAP-TTLS: MSCHAP implicit challenge",
		    challenge, 8);
	wpa_hexdump(0, "EAP-TTLS: MSCHAP response", pos, 24);
	pos += 24;
	os_free(challenge);
	do { int __pad; __pad = (4 - (((pos) - (buf)) & 3)) & 3; os_memset((pos), 0, __pad); pos += __pad; } while (0);

	wpabuf_put(msg, pos - buf);
	*resp = msg;

	if (data->ttls_version > 0) {
		
 
		ret->methodState = METHOD_CONT;
		ret->decision = DECISION_COND_SUCC;
	} else {
		
 
		ret->methodState = METHOD_DONE;
		ret->decision = DECISION_COND_SUCC;
	}

	return 0;
}


static int eap_ttls_phase2_request_pap(struct eap_sm *sm,
				       struct eap_ttls_data *data,
				       struct eap_method_ret *ret,
				       struct wpabuf **resp)
{
	struct wpabuf *msg;
	unsigned char *buf, *pos;
	size_t pad;
	const unsigned char *identity, *password;
	size_t identity_len, password_len;

	wpa_printf(0, "EAP-TTLS: Phase 2 PAP Request");

	identity = eap_get_config_identity(sm, &identity_len);
	password = eap_get_config_password(sm, &password_len);
	if (identity == 0 || password == 0)
		return -1;

	msg = wpabuf_alloc(identity_len + password_len + 100);
	if (msg == 0) {
		wpa_printf(0,
			   "EAP-TTLS/PAP: Failed to allocate memory");
		return -1;
	}
	pos = buf = wpabuf_mhead(msg);

	 
	pos = eap_ttls_avp_add(buf, pos, 1, 0, 1,
			       identity, identity_len);

	

 
	pad = password_len == 0 ? 16 : (16 - (password_len & 15)) & 15;
	pos = eap_ttls_avp_hdr(pos, 2, 0, 1,
			       password_len + pad);
	os_memcpy(pos, password, password_len);
	pos += password_len;
	os_memset(pos, 0, pad);
	pos += pad;
	do { int __pad; __pad = (4 - (((pos) - (buf)) & 3)) & 3; os_memset((pos), 0, __pad); pos += __pad; } while (0);

	wpabuf_put(msg, pos - buf);
	*resp = msg;

	if (data->ttls_version > 0) {
		
 
		ret->methodState = METHOD_CONT;
		ret->decision = DECISION_COND_SUCC;
	} else {
		
 
		ret->methodState = METHOD_DONE;
		ret->decision = DECISION_COND_SUCC;
	}

	return 0;
}


static int eap_ttls_phase2_request_chap(struct eap_sm *sm,
					struct eap_ttls_data *data,
					struct eap_method_ret *ret,
					struct wpabuf **resp)
{
	struct wpabuf *msg;
	unsigned char *buf, *pos, *challenge;
	const unsigned char *identity, *password;
	size_t identity_len, password_len;

	wpa_printf(0, "EAP-TTLS: Phase 2 CHAP Request");

	identity = eap_get_config_identity(sm, &identity_len);
	password = eap_get_config_password(sm, &password_len);
	if (identity == 0 || password == 0)
		return -1;

	msg = wpabuf_alloc(identity_len + 1000);
	if (msg == 0) {
		wpa_printf(0,
			   "EAP-TTLS/CHAP: Failed to allocate memory");
		return -1;
	}
	pos = buf = wpabuf_mhead(msg);

	 
	pos = eap_ttls_avp_add(buf, pos, 1, 0, 1,
			       identity, identity_len);

	 
	challenge = eap_ttls_implicit_challenge(
		sm, data, 16 + 1);
	if (challenge == 0) {
		wpabuf_free(msg);
		wpa_printf(0, "EAP-TTLS/CHAP: Failed to derive "
			   "implicit challenge");
		return -1;
	}

	pos = eap_ttls_avp_add(buf, pos, 60, 0, 1,
			       challenge, 16);

	 
	pos = eap_ttls_avp_hdr(pos, 3, 0, 1,
			       1 + 16);
	data->ident = challenge[16];
	*pos++ = data->ident;

	 
	chap_md5(data->ident, password, password_len, challenge,
		 16, pos);

	wpa_hexdump_ascii(0, "EAP-TTLS: CHAP username",
			  identity, identity_len);
	wpa_hexdump_ascii_key(0, "EAP-TTLS: CHAP password",
			      password, password_len);
	wpa_hexdump(0, "EAP-TTLS: CHAP implicit challenge",
		    challenge, 16);
	wpa_hexdump(0, "EAP-TTLS: CHAP password",
		    pos, 16);
	pos += 16;
	os_free(challenge);
	do { int __pad; __pad = (4 - (((pos) - (buf)) & 3)) & 3; os_memset((pos), 0, __pad); pos += __pad; } while (0);

	wpabuf_put(msg, pos - buf);
	*resp = msg;

	if (data->ttls_version > 0) {
		
 
		ret->methodState = METHOD_CONT;
		ret->decision = DECISION_COND_SUCC;
	} else {
		
 
		ret->methodState = METHOD_DONE;
		ret->decision = DECISION_COND_SUCC;
	}

	return 0;
}


static int eap_ttls_phase2_request(struct eap_sm *sm,
				   struct eap_ttls_data *data,
				   struct eap_method_ret *ret,
				   struct eap_hdr *hdr,
				   struct wpabuf **resp)
{
	int res = 0;
	size_t len;
	enum phase2_types phase2_type = data->phase2_type;

#line 977 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_ttls.c"

	if (phase2_type == EAP_TTLS_PHASE2_MSCHAPV2 ||
	    phase2_type == EAP_TTLS_PHASE2_MSCHAP ||
	    phase2_type == EAP_TTLS_PHASE2_PAP ||
	    phase2_type == EAP_TTLS_PHASE2_CHAP) {
		if (eap_get_config_identity(sm, &len) == 0) {
			wpa_printf(0,
				   "EAP-TTLS: Identity not configured");
			eap_sm_request_identity(sm);
			if (eap_get_config_password(sm, &len) == 0)
				eap_sm_request_password(sm);
			return 0;
		}

		if (eap_get_config_password(sm, &len) == 0) {
			wpa_printf(0,
				   "EAP-TTLS: Password not configured");
			eap_sm_request_password(sm);
			return 0;
		}
	}

	switch (phase2_type) {
	case EAP_TTLS_PHASE2_EAP:
		res = eap_ttls_phase2_request_eap(sm, data, ret, hdr, resp);
		break;
	case EAP_TTLS_PHASE2_MSCHAPV2:
		res = eap_ttls_phase2_request_mschapv2(sm, data, ret, resp);
		break;
	case EAP_TTLS_PHASE2_MSCHAP:
		res = eap_ttls_phase2_request_mschap(sm, data, ret, resp);
		break;
	case EAP_TTLS_PHASE2_PAP:
		res = eap_ttls_phase2_request_pap(sm, data, ret, resp);
		break;
	case EAP_TTLS_PHASE2_CHAP:
		res = eap_ttls_phase2_request_chap(sm, data, ret, resp);
		break;
	default:
		wpa_printf(0, "EAP-TTLS: Phase 2 - Unknown");
		res = -1;
		break;
	}

	if (res < 0) {
		ret->methodState = METHOD_DONE;
		ret->decision = DECISION_FAIL;
	}

	return res;
}


#line 1058 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_ttls.c"


struct ttls_parse_avp {
	unsigned char *mschapv2;
	unsigned char *eapdata;
	size_t eap_len;
	int mschapv2_error;
};


static int eap_ttls_parse_attr_eap(const unsigned char *dpos, size_t dlen,
				   struct ttls_parse_avp *parse)
{
	wpa_printf(0, "EAP-TTLS: AVP - EAP Message");
	if (parse->eapdata == 0) {
		parse->eapdata = os_malloc(dlen);
		if (parse->eapdata == 0) {
			wpa_printf(0, "EAP-TTLS: Failed to allocate "
				   "memory for Phase 2 EAP data");
			return -1;
		}
		os_memcpy(parse->eapdata, dpos, dlen);
		parse->eap_len = dlen;
	} else {
		unsigned char *neweap = os_realloc(parse->eapdata, parse->eap_len + dlen);
		if (neweap == 0) {
			wpa_printf(0, "EAP-TTLS: Failed to allocate "
				   "memory for Phase 2 EAP data");
			return -1;
		}
		os_memcpy(neweap + parse->eap_len, dpos, dlen);
		parse->eapdata = neweap;
		parse->eap_len += dlen;
	}

	return 0;
}


static int eap_ttls_parse_avp(unsigned char *pos, size_t left,
			      struct ttls_parse_avp *parse)
{
	struct ttls_avp *avp;
	unsigned int avp_code, avp_length, vendor_id = 0;
	unsigned char avp_flags, *dpos;
	size_t dlen;

	avp = (struct ttls_avp *) pos;
	avp_code = ((((unsigned int) ((unsigned int) (unsigned int) (avp->avp_code)) << 24) & 0xff000000) | (((unsigned int) ((unsigned int) (unsigned int) (avp->avp_code)) << 8) & 0xff0000) | (((unsigned int) ((unsigned int) (unsigned int) (avp->avp_code)) >> 8) & 0xff00) | (((unsigned int) ((unsigned int) (unsigned int) (avp->avp_code)) >> 24) & 0xff));
	avp_length = ((((unsigned int) ((unsigned int) (unsigned int) (avp->avp_length)) << 24) & 0xff000000) | (((unsigned int) ((unsigned int) (unsigned int) (avp->avp_length)) << 8) & 0xff0000) | (((unsigned int) ((unsigned int) (unsigned int) (avp->avp_length)) >> 8) & 0xff00) | (((unsigned int) ((unsigned int) (unsigned int) (avp->avp_length)) >> 24) & 0xff));
	avp_flags = (avp_length >> 24) & 0xff;
	avp_length &= 0xffffff;
	wpa_printf(0, "EAP-TTLS: AVP: code=%d flags=0x%02x "
		   "length=%d", (int) avp_code, avp_flags,
		   (int) avp_length);

	if (avp_length > left) {
		wpa_printf(0, "EAP-TTLS: AVP overflow "
			   "(len=%d, left=%lu) - dropped",
			   (int) avp_length, (unsigned long) left);
		return -1;
	}

	if (avp_length < sizeof(*avp)) {
		wpa_printf(0, "EAP-TTLS: Invalid AVP length %d",
			   avp_length);
		return -1;
	}

	dpos = (unsigned char *) (avp + 1);
	dlen = avp_length - sizeof(*avp);
	if (avp_flags & 0x80) {
		if (dlen < 4) {
			wpa_printf(0, "EAP-TTLS: Vendor AVP "
				   "underflow");
			return -1;
		}
		vendor_id = ((((unsigned int) (dpos)[0]) << 24) | (((unsigned int) (dpos)[1]) << 16) | (((unsigned int) (dpos)[2]) << 8) | ((unsigned int) (dpos)[3]));
		wpa_printf(0, "EAP-TTLS: AVP vendor_id %d",
			   (int) vendor_id);
		dpos += 4;
		dlen -= 4;
	}

	wpa_hexdump(0, "EAP-TTLS: AVP data", dpos, dlen);

	if (vendor_id == 0 && avp_code == 79) {
		if (eap_ttls_parse_attr_eap(dpos, dlen, parse) < 0)
			return -1;
	} else if (vendor_id == 0 && avp_code == 18) {
		
 
		wpa_hexdump_ascii(0, "EAP-TTLS: AVP - Reply-Message",
				  dpos, dlen);
	} else if (vendor_id == 311 &&
		   avp_code == 26) {
		wpa_hexdump_ascii(0, "EAP-TTLS: MS-CHAP2-Success",
				  dpos, dlen);
		if (dlen != 43) {
			wpa_printf(0, "EAP-TTLS: Unexpected "
				   "MS-CHAP2-Success length "
				   "(len=%lu, expected 43)",
				   (unsigned long) dlen);
			return -1;
		}
		parse->mschapv2 = dpos;
	} else if (vendor_id == 311 &&
		   avp_code == 2) {
		wpa_hexdump_ascii(0, "EAP-TTLS: MS-CHAP-Error",
				  dpos, dlen);
		parse->mschapv2_error = 1;
	} else if (avp_flags & 0x40) {
		wpa_printf(0, "EAP-TTLS: Unsupported mandatory AVP "
			   "code %d vendor_id %d - dropped",
			   (int) avp_code, (int) vendor_id);
		return -1;
	} else {
		wpa_printf(0, "EAP-TTLS: Ignoring unsupported AVP "
			   "code %d vendor_id %d",
			   (int) avp_code, (int) vendor_id);
	}

	return avp_length;
}


static int eap_ttls_parse_avps(struct wpabuf *in_decrypted,
			       struct ttls_parse_avp *parse)
{
	unsigned char *pos;
	size_t left, pad;
	int avp_length;

	pos = wpabuf_mhead(in_decrypted);
	left = wpabuf_len(in_decrypted);
	wpa_hexdump(0, "EAP-TTLS: Decrypted Phase 2 AVPs", pos, left);
	if (left < sizeof(struct ttls_avp)) {
		wpa_printf(0, "EAP-TTLS: Too short Phase 2 AVP frame"
			   " len=%lu expected %lu or more - dropped",
			   (unsigned long) left,
			   (unsigned long) sizeof(struct ttls_avp));
		return -1;
	}

	 
	os_memset(parse, 0, sizeof(*parse));

	while (left > 0) {
		avp_length = eap_ttls_parse_avp(pos, left, parse);
		if (avp_length < 0)
			return -1;

		pad = (4 - (avp_length & 3)) & 3;
		pos += avp_length + pad;
		if (left < avp_length + pad)
			left = 0;
		else
			left -= avp_length + pad;
	}

	return 0;
}


static unsigned char * eap_ttls_fake_identity_request(void)
{
	struct eap_hdr *hdr;
	unsigned char *buf;

	wpa_printf(0, "EAP-TTLS: empty data in beginning of "
		   "Phase 2 - use fake EAP-Request Identity");
	buf = os_malloc(sizeof(*hdr) + 1);
	if (buf == 0) {
		wpa_printf(0, "EAP-TTLS: failed to allocate "
			   "memory for fake EAP-Identity Request");
		return 0;
	}

	hdr = (struct eap_hdr *) buf;
	hdr->code = EAP_CODE_REQUEST;
	hdr->identifier = 0;
	hdr->length = (( unsigned short) ((((unsigned short) ((sizeof(*hdr) + 1)) << 8) & 0xff00) | (((unsigned short) ((sizeof(*hdr) + 1)) >> 8) & 0xff)));
	buf[sizeof(*hdr)] = EAP_TYPE_IDENTITY;

	return buf;
}


static int eap_ttls_encrypt_response(struct eap_sm *sm,
				     struct eap_ttls_data *data,
				     struct wpabuf *resp, unsigned char identifier,
				     struct wpabuf **out_data)
{
	if (resp == 0)
		return 0;

	wpa_hexdump_buf_key(0, "EAP-TTLS: Encrypting Phase 2 data",
			    resp);
	if (eap_peer_tls_encrypt(sm, &data->ssl, EAP_TYPE_TTLS,
				 data->ttls_version, identifier,
				 resp, out_data)) {
		wpa_printf(0, "EAP-TTLS: Failed to encrypt a Phase 2 "
			   "frame");
		return -1;
	}
	wpabuf_free(resp);

	return 0;
}


static int eap_ttls_process_phase2_eap(struct eap_sm *sm,
				       struct eap_ttls_data *data,
				       struct eap_method_ret *ret,
				       struct ttls_parse_avp *parse,
				       struct wpabuf **resp)
{
	struct eap_hdr *hdr;
	size_t len;

	if (parse->eapdata == 0) {
		wpa_printf(0, "EAP-TTLS: No EAP Message in the "
			   "packet - dropped");
		return -1;
	}

	wpa_hexdump(0, "EAP-TTLS: Phase 2 EAP",
		    parse->eapdata, parse->eap_len);
	hdr = (struct eap_hdr *) parse->eapdata;

	if (parse->eap_len < sizeof(*hdr)) {
		wpa_printf(0, "EAP-TTLS: Too short Phase 2 EAP "
			   "frame (len=%lu, expected %lu or more) - dropped",
			   (unsigned long) parse->eap_len,
			   (unsigned long) sizeof(*hdr));
		return -1;
	}
	len = ((((unsigned short) ((unsigned short) (unsigned short) (hdr->length)) << 8) & 0xff00) | (((unsigned short) ((unsigned short) (unsigned short) (hdr->length)) >> 8) & 0xff));
	if (len > parse->eap_len) {
		wpa_printf(0, "EAP-TTLS: Length mismatch in Phase 2 "
			   "EAP frame (EAP hdr len=%lu, EAP data len in "
			   "AVP=%lu)",
			   (unsigned long) len,
			   (unsigned long) parse->eap_len);
		return -1;
	}
	wpa_printf(0, "EAP-TTLS: received Phase 2: code=%d "
		   "identifier=%d length=%lu",
		   hdr->code, hdr->identifier, (unsigned long) len);
	switch (hdr->code) {
	case EAP_CODE_REQUEST:
		if (eap_ttls_phase2_request(sm, data, ret, hdr, resp)) {
			wpa_printf(0, "EAP-TTLS: Phase2 Request "
				   "processing failed");
			return -1;
		}
		break;
	default:
		wpa_printf(0, "EAP-TTLS: Unexpected code=%d in "
			   "Phase 2 EAP header", hdr->code);
		return -1;
	}

	return 0;
}


static int eap_ttls_process_phase2_mschapv2(struct eap_sm *sm,
					    struct eap_ttls_data *data,
					    struct eap_method_ret *ret,
					    struct ttls_parse_avp *parse)
{
	if (parse->mschapv2_error) {
		wpa_printf(0, "EAP-TTLS/MSCHAPV2: Received "
			   "MS-CHAP-Error - failed");
		ret->methodState = METHOD_DONE;
		ret->decision = DECISION_FAIL;
		 
		return 1;
	}

	if (parse->mschapv2 == 0) {
#line 1349 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_ttls.c"
		wpa_printf(0, "EAP-TTLS: no MS-CHAP2-Success AVP "
			   "received for Phase2 MSCHAPV2");
		return -1;
	}
	if (parse->mschapv2[0] != data->ident) {
		wpa_printf(0, "EAP-TTLS: Ident mismatch for Phase 2 "
			   "MSCHAPV2 (received Ident 0x%02x, expected 0x%02x)",
			   parse->mschapv2[0], data->ident);
		return -1;
	}
	if (!data->auth_response_valid ||
	    mschapv2_verify_auth_response(data->auth_response,
					  parse->mschapv2 + 1, 42)) {
		wpa_printf(0, "EAP-TTLS: Invalid authenticator "
			   "response in Phase 2 MSCHAPV2 success request");
		return -1;
	}

	wpa_printf(0, "EAP-TTLS: Phase 2 MSCHAPV2 "
		   "authentication succeeded");
	if (data->ttls_version > 0) {
		



 
		ret->methodState = METHOD_CONT;
		ret->decision = DECISION_COND_SUCC;
	} else {
		ret->methodState = METHOD_DONE;
		ret->decision = DECISION_UNCOND_SUCC;
		data->phase2_success = 1;
	}

	


 
	return 1;
}


#line 1421 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_ttls.c"


static int eap_ttls_process_decrypted(struct eap_sm *sm,
				      struct eap_ttls_data *data,
				      struct eap_method_ret *ret,
				      unsigned char identifier,
				      struct ttls_parse_avp *parse,
				      struct wpabuf *in_decrypted,
				      struct wpabuf **out_data)
{
	struct wpabuf *resp = 0;
	struct eap_peer_config *config = eap_get_config(sm);
	int res;
	enum phase2_types phase2_type = data->phase2_type;






	switch (phase2_type) {
	case EAP_TTLS_PHASE2_EAP:
		if (eap_ttls_process_phase2_eap(sm, data, ret, parse, &resp) <
		    0)
			return -1;
		break;
	case EAP_TTLS_PHASE2_MSCHAPV2:
		res = eap_ttls_process_phase2_mschapv2(sm, data, ret, parse);
#line 1462 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_ttls.c"
		return res;
	case EAP_TTLS_PHASE2_MSCHAP:
	case EAP_TTLS_PHASE2_PAP:
	case EAP_TTLS_PHASE2_CHAP:
#line 1472 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_ttls.c"
		
 
		wpa_printf(0, "EAP-TTLS: Phase 2 received unexpected "
			   "tunneled data");
		return -1;

	}

	if (resp) {
		if (eap_ttls_encrypt_response(sm, data, resp, identifier,
					      out_data) < 0)
			return -1;
	} else if (config->pending_req_identity ||
		   config->pending_req_password ||
		   config->pending_req_otp ||
		   config->pending_req_new_password) {
		wpabuf_free(data->pending_phase2_req);
		data->pending_phase2_req = wpabuf_dup(in_decrypted);
	}

	return 0;
}


#line 1512 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_ttls.c"


static int eap_ttls_implicit_identity_request(struct eap_sm *sm,
					      struct eap_ttls_data *data,
					      struct eap_method_ret *ret,
					      unsigned char identifier,
					      struct wpabuf **out_data)
{
	int retval = 0;
	struct eap_hdr *hdr;
	struct wpabuf *resp;

	hdr = (struct eap_hdr *) eap_ttls_fake_identity_request();
	if (hdr == 0) {
		ret->methodState = METHOD_DONE;
		ret->decision = DECISION_FAIL;
		return -1;
	}

	resp = 0;
	if (eap_ttls_phase2_request(sm, data, ret, hdr, &resp)) {
		wpa_printf(0, "EAP-TTLS: Phase2 Request "
			   "processing failed");
		retval = -1;
	} else {
		retval = eap_ttls_encrypt_response(sm, data, resp, identifier,
						   out_data);
	}

	os_free(hdr);

	if (retval < 0) {
		ret->methodState = METHOD_DONE;
		ret->decision = DECISION_FAIL;
	}

	return retval;
}


static int eap_ttls_phase2_start(struct eap_sm *sm, struct eap_ttls_data *data,
				 struct eap_method_ret *ret, unsigned char identifier,
				 struct wpabuf **out_data)
{
	data->phase2_start = 0;

	





 
	if (data->reauth &&
	    tls_connection_resumed(sm->ssl_ctx, data->ssl.conn)) {
		wpa_printf(0, "EAP-TTLS: Session resumption - "
			   "skip phase 2");
		*out_data = eap_peer_tls_build_ack(identifier, EAP_TYPE_TTLS,
						   data->ttls_version);
		ret->methodState = METHOD_DONE;
		ret->decision = DECISION_UNCOND_SUCC;
		data->phase2_success = 1;
		return 0;
	}

	return eap_ttls_implicit_identity_request(sm, data, ret, identifier,
						  out_data);
}


static int eap_ttls_decrypt(struct eap_sm *sm, struct eap_ttls_data *data,
			    struct eap_method_ret *ret, unsigned char identifier,
			    const struct wpabuf *in_data,
			    struct wpabuf **out_data)
{
	struct wpabuf *in_decrypted = 0;
	int retval = 0;
	struct ttls_parse_avp parse;

	os_memset(&parse, 0, sizeof(parse));

	wpa_printf(0, "EAP-TTLS: received %lu bytes encrypted data for"
		   " Phase 2",
		   in_data ? (unsigned long) wpabuf_len(in_data) : 0);

	if (data->pending_phase2_req) {
		wpa_printf(0, "EAP-TTLS: Pending Phase 2 request - "
			   "skip decryption and use old data");
		 
		eap_peer_tls_reset_input(&data->ssl);

		in_decrypted = data->pending_phase2_req;
		data->pending_phase2_req = 0;
		if (wpabuf_len(in_decrypted) == 0) {
			wpabuf_free(in_decrypted);
			return eap_ttls_implicit_identity_request(
				sm, data, ret, identifier, out_data);
		}
		goto continue_req;
	}

	if ((in_data == 0 || wpabuf_len(in_data) == 0) &&
	    data->phase2_start) {
		return eap_ttls_phase2_start(sm, data, ret, identifier,
					     out_data);
	}

	if (in_data == 0 || wpabuf_len(in_data) == 0) {
		 
		return eap_peer_tls_encrypt(sm, &data->ssl, EAP_TYPE_TTLS,
					    data->ttls_version,
					    identifier, 0, out_data);
	}

	retval = eap_peer_tls_decrypt(sm, &data->ssl, in_data, &in_decrypted);
	if (retval)
		goto done;

#line 1640 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_ttls.c"

continue_req:
	data->phase2_start = 0;

	if (eap_ttls_parse_avps(in_decrypted, &parse) < 0) {
		retval = -1;
		goto done;
	}

	retval = eap_ttls_process_decrypted(sm, data, ret, identifier,
					    &parse, in_decrypted, out_data);

done:
	wpabuf_free(in_decrypted);
	os_free(parse.eapdata);

	if (retval < 0) {
		ret->methodState = METHOD_DONE;
		ret->decision = DECISION_FAIL;
	}

	return retval;
}


static int eap_ttls_process_start(struct eap_sm *sm,
				  struct eap_ttls_data *data, unsigned char flags,
				  struct eap_method_ret *ret)
{
	struct eap_peer_config *config = eap_get_config(sm);

	wpa_printf(0, "EAP-TTLS: Start (server ver=%d, own ver=%d)",
		   flags & 0x07, data->ttls_version);
#line 1692 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_ttls.c"
	if (!data->ssl_initialized &&
	    eap_peer_tls_ssl_init(sm, &data->ssl, config)) {
		wpa_printf(0, "EAP-TTLS: Failed to initialize SSL.");
		return -1;
	}
	data->ssl_initialized = 1;

	wpa_printf(0, "EAP-TTLS: Start");

	return 0;
}


static int eap_ttls_process_handshake(struct eap_sm *sm,
				      struct eap_ttls_data *data,
				      struct eap_method_ret *ret,
				      unsigned char identifier,
				      const unsigned char *in_data, size_t in_len,
				      struct wpabuf **out_data)
{
	int res;

	res = eap_peer_tls_process_helper(sm, &data->ssl, EAP_TYPE_TTLS,
					  data->ttls_version, identifier,
					  in_data, in_len, out_data);

	if (tls_connection_established(sm->ssl_ctx, data->ssl.conn)) {
		wpa_printf(0, "EAP-TTLS: TLS done, proceed to "
			   "Phase 2");
		if (data->resuming) {
			wpa_printf(0, "EAP-TTLS: fast reauth - may "
				   "skip Phase 2");
			ret->decision = DECISION_COND_SUCC;
			ret->methodState = METHOD_MAY_CONT;
		}
		data->phase2_start = 1;
		if (data->ttls_version == 0)
			eap_ttls_v0_derive_key(sm, data);

		if (*out_data == 0 || wpabuf_len(*out_data) == 0) {
			if (eap_ttls_decrypt(sm, data, ret, identifier,
					     0, out_data)) {
				wpa_printf(0, "EAP-TTLS: "
					   "failed to process early "
					   "start for Phase 2");
			}
			res = 0;
		}
		data->resuming = 0;
	}

	if (res == 2) {
		struct wpabuf msg;
		

 
		wpabuf_free(data->pending_phase2_req);
		data->pending_phase2_req = *out_data;
		*out_data = 0;
		wpabuf_set(&msg, in_data, in_len);
		res = eap_ttls_decrypt(sm, data, ret, identifier, &msg,
				       out_data);
	}

	return res;
}


static void eap_ttls_check_auth_status(struct eap_sm *sm, 
				       struct eap_ttls_data *data,
				       struct eap_method_ret *ret)
{
	if (data->ttls_version == 0 && ret->methodState == METHOD_DONE) {
		ret->allowNotifications = 0;
		if (ret->decision == DECISION_UNCOND_SUCC ||
		    ret->decision == DECISION_COND_SUCC) {
			wpa_printf(0, "EAP-TTLS: Authentication "
				   "completed successfully");
			data->phase2_success = 1;
#line 1781 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_ttls.c"
		}
	} else if (data->ttls_version == 0 &&
		   ret->methodState == METHOD_MAY_CONT &&
		   (ret->decision == DECISION_UNCOND_SUCC ||
		    ret->decision == DECISION_COND_SUCC)) {
			wpa_printf(0, "EAP-TTLS: Authentication "
				   "completed successfully (MAY_CONT)");
			data->phase2_success = 1;
	}
}


static struct wpabuf * eap_ttls_process(struct eap_sm *sm, void *priv,
					struct eap_method_ret *ret,
					const struct wpabuf *reqData)
{
	size_t left;
	int res;
	unsigned char flags, id;
	struct wpabuf *resp;
	const unsigned char *pos;
	struct eap_ttls_data *data = priv;

	pos = eap_peer_tls_process_init(sm, &data->ssl, EAP_TYPE_TTLS, ret,
					reqData, &left, &flags);
	if (pos == 0)
		return 0;
	id = eap_get_id(reqData);

	if (flags & 0x20) {
		if (eap_ttls_process_start(sm, data, flags, ret) < 0)
			return 0;

		



 
		left = 0;
	} else if (!data->ssl_initialized) {
		wpa_printf(0, "EAP-TTLS: First message did not "
			   "include Start flag");
		ret->methodState = METHOD_DONE;
		ret->decision = DECISION_FAIL;
		ret->allowNotifications = 0;
		return 0;
	}

	resp = 0;
	if (tls_connection_established(sm->ssl_ctx, data->ssl.conn) &&
	    !data->resuming) {
		struct wpabuf msg;
		wpabuf_set(&msg, pos, left);
		res = eap_ttls_decrypt(sm, data, ret, id, &msg, &resp);
	} else {
		res = eap_ttls_process_handshake(sm, data, ret, id,
						 pos, left, &resp);
	}

	eap_ttls_check_auth_status(sm, data, ret);

	
 
	if (res == 1) {
		wpabuf_free(resp);
		return eap_peer_tls_build_ack(id, EAP_TYPE_TTLS,
					      data->ttls_version);
	}
	return resp;
}


static int eap_ttls_has_reauth_data(struct eap_sm *sm, void *priv)
{
	struct eap_ttls_data *data = priv;
	return tls_connection_established(sm->ssl_ctx, data->ssl.conn) &&
		data->phase2_success;
}


static void eap_ttls_deinit_for_reauth(struct eap_sm *sm, void *priv)
{
	struct eap_ttls_data *data = priv;
	wpabuf_free(data->pending_phase2_req);
	data->pending_phase2_req = 0;




}


static void * eap_ttls_init_for_reauth(struct eap_sm *sm, void *priv)
{
	struct eap_ttls_data *data = priv;
	os_free(data->key_data);
	data->key_data = 0;
	if (eap_peer_tls_reauth_init(sm, &data->ssl)) {
		os_free(data);
		return 0;
	}
	if (data->phase2_priv && data->phase2_method &&
	    data->phase2_method->init_for_reauth)
		data->phase2_method->init_for_reauth(sm, data->phase2_priv);
	data->phase2_start = 0;
	data->phase2_success = 0;
	data->resuming = 1;
	data->reauth = 1;
	return priv;
}


static int eap_ttls_get_status(struct eap_sm *sm, void *priv, char *buf,
			       size_t buflen, int verbose)
{
	struct eap_ttls_data *data = priv;
	int len, ret;

	len = eap_peer_tls_status(sm, &data->ssl, buf, buflen, verbose);
	ret = os_snprintf(buf + len, buflen - len,
			  "EAP-TTLSv%d Phase2 method=",
			  data->ttls_version);
	if (ret < 0 || (size_t) ret >= buflen - len)
		return len;
	len += ret;
	switch (data->phase2_type) {
	case EAP_TTLS_PHASE2_EAP:
		ret = os_snprintf(buf + len, buflen - len, "EAP-%s\n",
				  data->phase2_method ?
				  data->phase2_method->name : "?");
		break;
	case EAP_TTLS_PHASE2_MSCHAPV2:
		ret = os_snprintf(buf + len, buflen - len, "MSCHAPV2\n");
		break;
	case EAP_TTLS_PHASE2_MSCHAP:
		ret = os_snprintf(buf + len, buflen - len, "MSCHAP\n");
		break;
	case EAP_TTLS_PHASE2_PAP:
		ret = os_snprintf(buf + len, buflen - len, "PAP\n");
		break;
	case EAP_TTLS_PHASE2_CHAP:
		ret = os_snprintf(buf + len, buflen - len, "CHAP\n");
		break;
	default:
		ret = 0;
		break;
	}
	if (ret < 0 || (size_t) ret >= buflen - len)
		return len;
	len += ret;

	return len;
}


static int eap_ttls_isKeyAvailable(struct eap_sm *sm, void *priv)
{
	struct eap_ttls_data *data = priv;
	return data->key_data != 0 && data->phase2_success;
}


static unsigned char * eap_ttls_getKey(struct eap_sm *sm, void *priv, size_t *len)
{
	struct eap_ttls_data *data = priv;
	unsigned char *key;

	if (data->key_data == 0 || !data->phase2_success)
		return 0;

	key = os_malloc(64);
	if (key == 0)
		return 0;

	*len = 64;
	os_memcpy(key, data->key_data, 64);

	return key;
}


int eap_peer_ttls_register(void)
{
	struct eap_method *eap;
	int ret;

	eap = eap_peer_method_alloc(1,
				    EAP_VENDOR_IETF, EAP_TYPE_TTLS, "TTLS");
	if (eap == 0)
		return -1;

	eap->init = eap_ttls_init;
	eap->deinit = eap_ttls_deinit;
	eap->process = eap_ttls_process;
	eap->isKeyAvailable = eap_ttls_isKeyAvailable;
	eap->getKey = eap_ttls_getKey;
	eap->get_status = eap_ttls_get_status;
	eap->has_reauth_data = eap_ttls_has_reauth_data;
	eap->deinit_for_reauth = eap_ttls_deinit_for_reauth;
	eap->init_for_reauth = eap_ttls_init_for_reauth;

	ret = eap_peer_method_register(eap);
	if (ret)
		eap_peer_method_free(eap);
	return ret;
}
