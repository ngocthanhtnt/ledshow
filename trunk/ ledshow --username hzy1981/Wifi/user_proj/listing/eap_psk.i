#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_psk.c"















 

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

#line 19 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_psk.c"

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



#line 21 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_psk.c"
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

#line 22 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_psk.c"
#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common/eap_psk_common.h"












 





#line 25 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common/eap_psk_common.h"













 
struct eap_psk_hdr_1 {
	unsigned char flags;
	unsigned char rand_s[16];
	 
} ;

 
struct eap_psk_hdr_2 {
	unsigned char flags;
	unsigned char rand_s[16];
	unsigned char rand_p[16];
	unsigned char mac_p[16];
	 
} ;

 
struct eap_psk_hdr_3 {
	unsigned char flags;
	unsigned char rand_s[16];
	unsigned char mac_s[16];
	 
} ;

 
struct eap_psk_hdr_4 {
	unsigned char flags;
	unsigned char rand_s[16];
	 
} ;






int  eap_psk_key_setup(const unsigned char *psk, unsigned char *ak, unsigned char *kdk);
int  eap_psk_derive_keys(const unsigned char *kdk, const unsigned char *rand_p, unsigned char *tek,
				     unsigned char *msk, unsigned char *emsk);

#line 23 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_psk.c"
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

#line 24 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_psk.c"


struct eap_psk_data {
	enum { PSK_INIT, PSK_MAC_SENT, PSK_DONE } state;
	unsigned char rand_p[16];
	unsigned char ak[16], kdk[16], tek[16];
	unsigned char *id_s, *id_p;
	size_t id_s_len, id_p_len;
	unsigned char msk[64];
	unsigned char emsk[64];
};


static void * eap_psk_init(struct eap_sm *sm)
{
	struct eap_psk_data *data;
	const unsigned char *identity, *password;
	size_t identity_len, password_len;

	password = eap_get_config_password(sm, &password_len);
	if (!password || password_len != 16) {
		wpa_printf(0, "EAP-PSK: 16-octet pre-shared key not "
			   "configured");
		return 0;
	}

	data = os_zalloc(sizeof(*data));
	if (data == 0)
		return 0;
	if (eap_psk_key_setup(password, data->ak, data->kdk)) {
		os_free(data);
		return 0;
	}
	wpa_hexdump_key(0, "EAP-PSK: AK", data->ak, 16);
	wpa_hexdump_key(0, "EAP-PSK: KDK", data->kdk, 16);
	data->state = PSK_INIT;

	identity = eap_get_config_identity(sm, &identity_len);
	if (identity) {
		data->id_p = os_malloc(identity_len);
		if (data->id_p)
			os_memcpy(data->id_p, identity, identity_len);
		data->id_p_len = identity_len;
	}
	if (data->id_p == 0) {
		wpa_printf(0, "EAP-PSK: could not get own identity");
		os_free(data);
		return 0;
	}

	return data;
}


static void eap_psk_deinit(struct eap_sm *sm, void *priv)
{
	struct eap_psk_data *data = priv;
	os_free(data->id_s);
	os_free(data->id_p);
	os_free(data);
}


static struct wpabuf * eap_psk_process_1(struct eap_psk_data *data,
					 struct eap_method_ret *ret,
					 const struct wpabuf *reqData)
{
	const struct eap_psk_hdr_1 *hdr1;
	struct eap_psk_hdr_2 *hdr2;
	struct wpabuf *resp;
	unsigned char *buf, *pos;
	size_t buflen, len;
	const unsigned char *cpos;

	wpa_printf(0, "EAP-PSK: in INIT state");

	cpos = eap_hdr_validate(EAP_VENDOR_IETF, EAP_TYPE_PSK, reqData, &len);
	hdr1 = (const struct eap_psk_hdr_1 *) cpos;
	if (cpos == 0 || len < sizeof(*hdr1)) {
		wpa_printf(0, "EAP-PSK: Invalid first message "
			   "length (%lu; expected %lu or more)",
			   (unsigned long) len,
			   (unsigned long) sizeof(*hdr1));
		ret->ignore = 1;
		return 0;
	}
	wpa_printf(0, "EAP-PSK: Flags=0x%x", hdr1->flags);
	if ((((hdr1->flags) & 0xc0) >> 6) != 0) {
		wpa_printf(0, "EAP-PSK: Unexpected T=%d (expected 0)",
			   (((hdr1->flags) & 0xc0) >> 6));
		ret->methodState = METHOD_DONE;
		ret->decision = DECISION_FAIL;
		return 0;
	}
	wpa_hexdump(0, "EAP-PSK: RAND_S", hdr1->rand_s,
		    16);
	os_free(data->id_s);
	data->id_s_len = len - sizeof(*hdr1);
	data->id_s = os_malloc(data->id_s_len);
	if (data->id_s == 0) {
		wpa_printf(0, "EAP-PSK: Failed to allocate memory for "
			   "ID_S (len=%lu)", (unsigned long) data->id_s_len);
		ret->ignore = 1;
		return 0;
	}
	os_memcpy(data->id_s, (unsigned char *) (hdr1 + 1), data->id_s_len);
	wpa_hexdump_ascii(0, "EAP-PSK: ID_S",
			  data->id_s, data->id_s_len);

	if (os_get_random(data->rand_p, 16)) {
		wpa_printf(0, "EAP-PSK: Failed to get random data");
		ret->ignore = 1;
		return 0;
	}

	resp = eap_msg_alloc(EAP_VENDOR_IETF, EAP_TYPE_PSK,
			     sizeof(*hdr2) + data->id_p_len, EAP_CODE_RESPONSE,
			     eap_get_id(reqData));
	if (resp == 0)
		return 0;
	hdr2 = wpabuf_put(resp, sizeof(*hdr2));
	hdr2->flags = ((unsigned char) (1) << 6);  
	os_memcpy(hdr2->rand_s, hdr1->rand_s, 16);
	os_memcpy(hdr2->rand_p, data->rand_p, 16);
	wpabuf_put_data(resp, data->id_p, data->id_p_len);
	 
	buflen = data->id_p_len + data->id_s_len + 2 * 16;
	buf = os_malloc(buflen);
	if (buf == 0) {
		wpabuf_free(resp);
		return 0;
	}
	os_memcpy(buf, data->id_p, data->id_p_len);
	pos = buf + data->id_p_len;
	os_memcpy(pos, data->id_s, data->id_s_len);
	pos += data->id_s_len;
	os_memcpy(pos, hdr1->rand_s, 16);
	pos += 16;
	os_memcpy(pos, data->rand_p, 16);
	if (omac1_aes_128(data->ak, buf, buflen, hdr2->mac_p)) {
		os_free(buf);
		wpabuf_free(resp);
		return 0;
	}
	os_free(buf);
	wpa_hexdump(0, "EAP-PSK: RAND_P", hdr2->rand_p,
		    16);
	wpa_hexdump(0, "EAP-PSK: MAC_P", hdr2->mac_p, 16);
	wpa_hexdump_ascii(0, "EAP-PSK: ID_P",
			  data->id_p, data->id_p_len);

	data->state = PSK_MAC_SENT;

	return resp;
}


static struct wpabuf * eap_psk_process_3(struct eap_psk_data *data,
					 struct eap_method_ret *ret,
					 const struct wpabuf *reqData)
{
	const struct eap_psk_hdr_3 *hdr3;
	struct eap_psk_hdr_4 *hdr4;
	struct wpabuf *resp;
	unsigned char *buf, *rpchannel, nonce[16], *decrypted;
	const unsigned char *pchannel, *tag, *msg;
	unsigned char mac[16];
	size_t buflen, left, data_len, len, plen;
	int failed = 0;
	const unsigned char *pos;

	wpa_printf(0, "EAP-PSK: in MAC_SENT state");

	pos = eap_hdr_validate(EAP_VENDOR_IETF, EAP_TYPE_PSK,
			       reqData, &len);
	hdr3 = (const struct eap_psk_hdr_3 *) pos;
	if (pos == 0 || len < sizeof(*hdr3)) {
		wpa_printf(0, "EAP-PSK: Invalid third message "
			   "length (%lu; expected %lu or more)",
			   (unsigned long) len,
			   (unsigned long) sizeof(*hdr3));
		ret->ignore = 1;
		return 0;
	}
	left = len - sizeof(*hdr3);
	pchannel = (const unsigned char *) (hdr3 + 1);
	wpa_printf(0, "EAP-PSK: Flags=0x%x", hdr3->flags);
	if ((((hdr3->flags) & 0xc0) >> 6) != 2) {
		wpa_printf(0, "EAP-PSK: Unexpected T=%d (expected 2)",
			   (((hdr3->flags) & 0xc0) >> 6));
		ret->methodState = METHOD_DONE;
		ret->decision = DECISION_FAIL;
		return 0;
	}
	wpa_hexdump(0, "EAP-PSK: RAND_S", hdr3->rand_s,
		    16);
	wpa_hexdump(0, "EAP-PSK: MAC_S", hdr3->mac_s, 16);
	wpa_hexdump(0, "EAP-PSK: PCHANNEL", pchannel, left);

	if (left < 4 + 16 + 1) {
		wpa_printf(0, "EAP-PSK: Too short PCHANNEL data in "
			   "third message (len=%lu, expected 21)",
			   (unsigned long) left);
		ret->ignore = 1;
		return 0;
	}

	 
	buflen = data->id_s_len + 16;
	buf = os_malloc(buflen);
	if (buf == 0)
		return 0;
	os_memcpy(buf, data->id_s, data->id_s_len);
	os_memcpy(buf + data->id_s_len, data->rand_p, 16);
	if (omac1_aes_128(data->ak, buf, buflen, mac)) {
		os_free(buf);
		return 0;
	}
	os_free(buf);
	if (os_memcmp(mac, hdr3->mac_s, 16) != 0) {
		wpa_printf(0, "EAP-PSK: Invalid MAC_S in third "
			   "message");
		ret->methodState = METHOD_DONE;
		ret->decision = DECISION_FAIL;
		return 0;
	}
	wpa_printf(0, "EAP-PSK: MAC_S verified successfully");

	if (eap_psk_derive_keys(data->kdk, data->rand_p, data->tek,
				data->msk, data->emsk)) {
		ret->methodState = METHOD_DONE;
		ret->decision = DECISION_FAIL;
		return 0;
	}
	wpa_hexdump_key(0, "EAP-PSK: TEK", data->tek, 16);
	wpa_hexdump_key(0, "EAP-PSK: MSK", data->msk, 64);
	wpa_hexdump_key(0, "EAP-PSK: EMSK", data->emsk, 64);

	os_memset(nonce, 0, 12);
	os_memcpy(nonce + 12, pchannel, 4);
	pchannel += 4;
	left -= 4;

	tag = pchannel;
	pchannel += 16;
	left -= 16;

	msg = pchannel;

	wpa_hexdump(0, "EAP-PSK: PCHANNEL - nonce",
		    nonce, sizeof(nonce));
	wpa_hexdump(0, "EAP-PSK: PCHANNEL - hdr",
		    wpabuf_head(reqData), 5);
	wpa_hexdump(0, "EAP-PSK: PCHANNEL - cipher msg", msg, left);

	decrypted = os_malloc(left);
	if (decrypted == 0) {
		ret->methodState = METHOD_DONE;
		ret->decision = DECISION_FAIL;
		return 0;
	}
	os_memcpy(decrypted, msg, left);

	if (aes_128_eax_decrypt(data->tek, nonce, sizeof(nonce),
				wpabuf_head(reqData),
				sizeof(struct eap_hdr) + 1 +
				sizeof(*hdr3) - 16, decrypted,
				left, tag)) {
		wpa_printf(0, "EAP-PSK: PCHANNEL decryption failed");
		os_free(decrypted);
		return 0;
	}
	wpa_hexdump(0, "EAP-PSK: Decrypted PCHANNEL message",
		    decrypted, left);

	 
	switch (decrypted[0] >> 6) {
	case 1:
		wpa_printf(0, "EAP-PSK: R flag - CONT - unsupported");
		failed = 1;
		break;
	case 2:
		wpa_printf(0, "EAP-PSK: R flag - DONE_SUCCESS");
		break;
	case 3:
		wpa_printf(0, "EAP-PSK: R flag - DONE_FAILURE");
		wpa_printf(0, "EAP-PSK: Authentication server rejected "
			   "authentication");
		failed = 1;
		break;
	}

	data_len = 1;
	if ((decrypted[0] & 0x20) && left > 1)
		data_len++;
	plen = sizeof(*hdr4) + 4 + 16 + data_len;
	resp = eap_msg_alloc(EAP_VENDOR_IETF, EAP_TYPE_PSK, plen,
			     EAP_CODE_RESPONSE, eap_get_id(reqData));
	if (resp == 0) {
		os_free(decrypted);
		return 0;
	}
	hdr4 = wpabuf_put(resp, sizeof(*hdr4));
	hdr4->flags = ((unsigned char) (3) << 6);  
	os_memcpy(hdr4->rand_s, hdr3->rand_s, 16);
	rpchannel = wpabuf_put(resp, 4 + 16 + data_len);

	 
	inc_byte_array(nonce, sizeof(nonce));
	os_memcpy(rpchannel, nonce + 12, 4);

	if (decrypted[0] & 0x20) {
		wpa_printf(0, "EAP-PSK: Unsupported E (Ext) flag");
		failed = 1;
		rpchannel[4 + 16] = (3 << 6) |
			0x20;
		if (left > 1) {
			 
			rpchannel[4 + 16 + 1] = decrypted[1];
		}
	} else if (failed)
		rpchannel[4 + 16] = 3 << 6;
	else
		rpchannel[4 + 16] = 2 << 6;

	wpa_hexdump(0, "EAP-PSK: reply message (plaintext)",
		    rpchannel + 4 + 16, data_len);
	if (aes_128_eax_encrypt(data->tek, nonce, sizeof(nonce),
				wpabuf_head(resp),
				sizeof(struct eap_hdr) + 1 + sizeof(*hdr4),
				rpchannel + 4 + 16, data_len, rpchannel + 4)) {
		os_free(decrypted);
		wpabuf_free(resp);
		return 0;
	}
	wpa_hexdump(0, "EAP-PSK: reply message (PCHANNEL)",
		    rpchannel, 4 + 16 + data_len);

	wpa_printf(0, "EAP-PSK: Completed %ssuccessfully",
		   failed ? "un" : "");
	data->state = PSK_DONE;
	ret->methodState = METHOD_DONE;
	ret->decision = failed ? DECISION_FAIL : DECISION_UNCOND_SUCC;

	os_free(decrypted);

	return resp;
}


static struct wpabuf * eap_psk_process(struct eap_sm *sm, void *priv,
				       struct eap_method_ret *ret,
				       const struct wpabuf *reqData)
{
	struct eap_psk_data *data = priv;
	const unsigned char *pos;
	struct wpabuf *resp = 0;
	size_t len;

	pos = eap_hdr_validate(EAP_VENDOR_IETF, EAP_TYPE_PSK, reqData, &len);
	if (pos == 0) {
		ret->ignore = 1;
		return 0;
	}

	ret->ignore = 0;
	ret->methodState = METHOD_MAY_CONT;
	ret->decision = DECISION_FAIL;
	ret->allowNotifications = 1;

	switch (data->state) {
	case PSK_INIT:
		resp = eap_psk_process_1(data, ret, reqData);
		break;
	case PSK_MAC_SENT:
		resp = eap_psk_process_3(data, ret, reqData);
		break;
	case PSK_DONE:
		wpa_printf(0, "EAP-PSK: in DONE state - ignore "
			   "unexpected message");
		ret->ignore = 1;
		return 0;
	}

	if (ret->methodState == METHOD_DONE) {
		ret->allowNotifications = 0;
	}

	return resp;
}


static int eap_psk_isKeyAvailable(struct eap_sm *sm, void *priv)
{
	struct eap_psk_data *data = priv;
	return data->state == PSK_DONE;
}


static unsigned char * eap_psk_getKey(struct eap_sm *sm, void *priv, size_t *len)
{
	struct eap_psk_data *data = priv;
	unsigned char *key;

	if (data->state != PSK_DONE)
		return 0;

	key = os_malloc(64);
	if (key == 0)
		return 0;

	*len = 64;
	os_memcpy(key, data->msk, 64);

	return key;
}


static unsigned char * eap_psk_get_emsk(struct eap_sm *sm, void *priv, size_t *len)
{
	struct eap_psk_data *data = priv;
	unsigned char *key;

	if (data->state != PSK_DONE)
		return 0;

	key = os_malloc(64);
	if (key == 0)
		return 0;

	*len = 64;
	os_memcpy(key, data->emsk, 64);

	return key;
}


int eap_peer_psk_register(void)
{
	struct eap_method *eap;
	int ret;

	eap = eap_peer_method_alloc(1,
				    EAP_VENDOR_IETF, EAP_TYPE_PSK, "PSK");
	if (eap == 0)
		return -1;

	eap->init = eap_psk_init;
	eap->deinit = eap_psk_deinit;
	eap->process = eap_psk_process;
	eap->isKeyAvailable = eap_psk_isKeyAvailable;
	eap->getKey = eap_psk_getKey;
	eap->get_emsk = eap_psk_get_emsk;

	ret = eap_peer_method_register(eap);
	if (ret)
		eap_peer_method_free(eap);
	return ret;
}
