#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\ikev2.c"












 

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

#line 16 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\ikev2.c"

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



#line 18 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\ikev2.c"
#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\crypto/dh_groups.h"












 




struct dh_group {
	int id;
	const unsigned char *generator;
	size_t generator_len;
	const unsigned char *prime;
	size_t prime_len;
};

const struct dh_group * dh_groups_get(int id);
struct wpabuf * dh_init(const struct dh_group *dh, struct wpabuf **priv);
struct wpabuf * dh_derive_shared(const struct wpabuf *peer_public,
				 const struct wpabuf *own_private,
				 const struct dh_group *dh);

#line 19 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\ikev2.c"
#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\ikev2.h"












 




#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common/ikev2_common.h"












 







 



 






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






 
#line 84 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common/ikev2_common.h"

 
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

#line 19 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\ikev2.h"

struct ikev2_proposal_data {
	unsigned char proposal_num;
	int integ;
	int prf;
	int encr;
	int dh;
};


struct ikev2_responder_data {
	enum { SA_INIT, SA_AUTH, CHILD_SA, NOTIFY, IKEV2_DONE, IKEV2_FAILED }
		state;
	unsigned char i_spi[8];
	unsigned char r_spi[8];
	unsigned char i_nonce[256];
	size_t i_nonce_len;
	unsigned char r_nonce[256];
	size_t r_nonce_len;
	struct wpabuf *i_dh_public;
	struct wpabuf *r_dh_private;
	struct ikev2_proposal_data proposal;
	const struct dh_group *dh;
	struct ikev2_keys keys;
	unsigned char *IDi;
	size_t IDi_len;
	unsigned char IDi_type;
	unsigned char *IDr;
	size_t IDr_len;
	struct wpabuf *r_sign_msg;
	struct wpabuf *i_sign_msg;
	unsigned char *shared_secret;
	size_t shared_secret_len;
	enum { PEER_AUTH_CERT, PEER_AUTH_SECRET } peer_auth;
	unsigned char *key_pad;
	size_t key_pad_len;
	unsigned short error_type;
	enum { LAST_MSG_SA_INIT, LAST_MSG_SA_AUTH } last_msg;
};


void ikev2_responder_deinit(struct ikev2_responder_data *data);
int ikev2_responder_process(struct ikev2_responder_data *data,
			    const struct wpabuf *buf);
struct wpabuf * ikev2_responder_build(struct ikev2_responder_data *data);

#line 20 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\ikev2.c"


void ikev2_responder_deinit(struct ikev2_responder_data *data)
{
	ikev2_free_keys(&data->keys);
	wpabuf_free(data->i_dh_public);
	wpabuf_free(data->r_dh_private);
	os_free(data->IDi);
	os_free(data->IDr);
	os_free(data->shared_secret);
	wpabuf_free(data->i_sign_msg);
	wpabuf_free(data->r_sign_msg);
	os_free(data->key_pad);
}


static int ikev2_derive_keys(struct ikev2_responder_data *data)
{
	unsigned char *buf, *pos, *pad, skeyseed[20];
	size_t buf_len, pad_len;
	struct wpabuf *shared;
	const struct ikev2_integ_alg *integ;
	const struct ikev2_prf_alg *prf;
	const struct ikev2_encr_alg *encr;
	int ret;
	const unsigned char *addr[2];
	size_t len[2];

	 

	integ = ikev2_get_integ(data->proposal.integ);
	prf = ikev2_get_prf(data->proposal.prf);
	encr = ikev2_get_encr(data->proposal.encr);
	if (integ == 0 || prf == 0 || encr == 0) {
		wpa_printf(0, "IKEV2: Unsupported proposal");
		return -1;
	}

	shared = dh_derive_shared(data->i_dh_public, data->r_dh_private,
				  data->dh);
	if (shared == 0)
		return -1;

	 

	buf_len = data->i_nonce_len + data->r_nonce_len + 2 * 8;
	buf = os_malloc(buf_len);
	if (buf == 0) {
		wpabuf_free(shared);
		return -1;
	}

	pos = buf;
	os_memcpy(pos, data->i_nonce, data->i_nonce_len);
	pos += data->i_nonce_len;
	os_memcpy(pos, data->r_nonce, data->r_nonce_len);
	pos += data->r_nonce_len;
	os_memcpy(pos, data->i_spi, 8);
	pos += 8;
	os_memcpy(pos, data->r_spi, 8);
#line 93 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\ikev2.c"

	 
	 
	pad_len = data->dh->prime_len - wpabuf_len(shared);




	pad = os_zalloc(pad_len ? pad_len : 1);
	if (pad == 0) {
		wpabuf_free(shared);
		os_free(buf);
		return -1;
	}

	addr[0] = pad;
	len[0] = pad_len;
	addr[1] = wpabuf_head(shared);
	len[1] = wpabuf_len(shared);
	if (ikev2_prf_hash(prf->id, buf, data->i_nonce_len + data->r_nonce_len,
			   2, addr, len, skeyseed) < 0) {
		wpabuf_free(shared);
		os_free(buf);
		os_free(pad);
		return -1;
	}
	os_free(pad);
	wpabuf_free(shared);

	 
	wpabuf_free(data->i_dh_public);
	data->i_dh_public = 0;
	wpabuf_free(data->r_dh_private);
	data->r_dh_private = 0;

	wpa_hexdump_key(0, "IKEV2: SKEYSEED",
			skeyseed, prf->hash_len);

	ret = ikev2_derive_sk_keys(prf, integ, encr, skeyseed, buf, buf_len,
				   &data->keys);
	os_free(buf);
	return ret;
}


static int ikev2_parse_transform(struct ikev2_proposal_data *prop,
				 const unsigned char *pos, const unsigned char *end)
{
	int transform_len;
	const struct ikev2_transform *t;
	unsigned short transform_id;
	const unsigned char *tend;

	if (end - pos < (int) sizeof(*t)) {
		wpa_printf(0, "IKEV2: Too short transform");
		return -1;
	}

	t = (const struct ikev2_transform *) pos;
	transform_len = ((unsigned short) (((t->transform_length)[0] << 8) | (t->transform_length)[1]));
	if (transform_len < (int) sizeof(*t) || pos + transform_len > end) {
		wpa_printf(0, "IKEV2: Invalid transform length %d",
			   transform_len);
		return -1;
	}
	tend = pos + transform_len;

	transform_id = ((unsigned short) (((t->transform_id)[0] << 8) | (t->transform_id)[1]));

	wpa_printf(0, "IKEV2:   Transform:");
	wpa_printf(0, "IKEV2:     Type: %d  Transform Length: %d  "
		   "Transform Type: %d  Transform ID: %d",
		   t->type, transform_len, t->transform_type, transform_id);

	if (t->type != 0 && t->type != 3) {
		wpa_printf(0, "IKEV2: Unexpected Transform type");
		return -1;
	}

	pos = (const unsigned char *) (t + 1);
	if (pos < tend) {
		wpa_hexdump(0, "IKEV2:     Transform Attributes",
			    pos, tend - pos);
	}

	switch (t->transform_type) {
	case IKEV2_TRANSFORM_ENCR:
		if (ikev2_get_encr(transform_id)) {
			if (transform_id == ENCR_AES_CBC) {
				if (tend - pos != 4) {
					wpa_printf(0, "IKEV2: No "
						   "Transform Attr for AES");
					break;
				}
#line 195 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\ikev2.c"
				if (((unsigned short) (((pos)[0] << 8) | (pos)[1])) != 0x800e) {
					wpa_printf(0, "IKEV2: Not a "
						   "Key Size attribute for "
						   "AES");
					break;
				}

				if (((unsigned short) (((pos + 2)[0] << 8) | (pos + 2)[1])) != 128) {
					wpa_printf(0, "IKEV2: "
						   "Unsupported AES key size "
						   "%d bits",
						   ((unsigned short) (((pos + 2)[0] << 8) | (pos + 2)[1])));
					break;
				}
			}
			prop->encr = transform_id;
		}
		break;
	case IKEV2_TRANSFORM_PRF:
		if (ikev2_get_prf(transform_id))
			prop->prf = transform_id;
		break;
	case IKEV2_TRANSFORM_INTEG:
		if (ikev2_get_integ(transform_id))
			prop->integ = transform_id;
		break;
	case IKEV2_TRANSFORM_DH:
		if (dh_groups_get(transform_id))
			prop->dh = transform_id;
		break;
	}

	return transform_len;
}


static int ikev2_parse_proposal(struct ikev2_proposal_data *prop,
				const unsigned char *pos, const unsigned char *end)
{
	const unsigned char *pend, *ppos;
	int proposal_len, i;
	const struct ikev2_proposal *p;

	if (end - pos < (int) sizeof(*p)) {
		wpa_printf(0, "IKEV2: Too short proposal");
		return -1;
	}

	 

	p = (const struct ikev2_proposal *) pos;
	proposal_len = ((unsigned short) (((p->proposal_length)[0] << 8) | (p->proposal_length)[1]));
	if (proposal_len < (int) sizeof(*p) || pos + proposal_len > end) {
		wpa_printf(0, "IKEV2: Invalid proposal length %d",
			   proposal_len);
		return -1;
	}
	wpa_printf(0, "IKEV2: SAi1 Proposal # %d",
		   p->proposal_num);
	wpa_printf(0, "IKEV2:   Type: %d  Proposal Length: %d "
		   " Protocol ID: %d",
		   p->type, proposal_len, p->protocol_id);
	wpa_printf(0, "IKEV2:   SPI Size: %d  Transforms: %d",
		   p->spi_size, p->num_transforms);

	if (p->type != 0 && p->type != 2) {
		wpa_printf(0, "IKEV2: Unexpected Proposal type");
		return -1;
	}

	if (p->protocol_id != IKEV2_PROTOCOL_IKE) {
		wpa_printf(0, "IKEV2: Unexpected Protocol ID "
			   "(only IKE allowed for EAP-IKEv2)");
		return -1;
	}

	if (p->proposal_num != prop->proposal_num) {
		if (p->proposal_num == prop->proposal_num + 1)
			prop->proposal_num = p->proposal_num;
		else {
			wpa_printf(0, "IKEV2: Unexpected Proposal #");
			return -1;
		}
	}

	ppos = (const unsigned char *) (p + 1);
	pend = pos + proposal_len;
	if (ppos + p->spi_size > pend) {
		wpa_printf(0, "IKEV2: Not enough room for SPI "
			   "in proposal");
		return -1;
	}
	if (p->spi_size) {
		wpa_hexdump(0, "IKEV2:    SPI",
			    ppos, p->spi_size);
		ppos += p->spi_size;
	}

	



 
	if (p->spi_size != 0) {
		wpa_printf(0, "IKEV2: Unexpected SPI Size");
		return -1;
	}

	if (p->num_transforms == 0) {
		wpa_printf(0, "IKEV2: At least one transform required");
		return -1;
	}

	for (i = 0; i < (int) p->num_transforms; i++) {
		int tlen = ikev2_parse_transform(prop, ppos, pend);
		if (tlen < 0)
			return -1;
		ppos += tlen;
	}

	if (ppos != pend) {
		wpa_printf(0, "IKEV2: Unexpected data after "
			   "transforms");
		return -1;
	}

	return proposal_len;
}


static int ikev2_process_sai1(struct ikev2_responder_data *data,
			      const unsigned char *sai1, size_t sai1_len)
{
	struct ikev2_proposal_data prop;
	const unsigned char *pos, *end;
	int found = 0;

	 

	if (sai1 == 0) {
		wpa_printf(0, "IKEV2: SAi1 not received");
		return -1;
	}

	os_memset(&prop, 0, sizeof(prop));
	prop.proposal_num = 1;

	pos = sai1;
	end = sai1 + sai1_len;

	while (pos < end) {
		int plen;

		prop.integ = -1;
		prop.prf = -1;
		prop.encr = -1;
		prop.dh = -1;
		plen = ikev2_parse_proposal(&prop, pos, end);
		if (plen < 0)
			return -1;

		if (!found && prop.integ != -1 && prop.prf != -1 &&
		    prop.encr != -1 && prop.dh != -1) {
			os_memcpy(&data->proposal, &prop, sizeof(prop));
			data->dh = dh_groups_get(prop.dh);
			found = 1;
		}

		pos += plen;
	}

	if (pos != end) {
		wpa_printf(0, "IKEV2: Unexpected data after proposals");
		return -1;
	}

	if (!found) {
		wpa_printf(0, "IKEV2: No acceptable proposal found");
		return -1;
	}

	wpa_printf(0, "IKEV2: Accepted proposal #%d: ENCR:%d PRF:%d "
		   "INTEG:%d D-H:%d", data->proposal.proposal_num,
		   data->proposal.encr, data->proposal.prf,
		   data->proposal.integ, data->proposal.dh);

	return 0;
}


static int ikev2_process_kei(struct ikev2_responder_data *data,
			     const unsigned char *kei, size_t kei_len)
{
	unsigned short group;

	




 

	if (kei == 0) {
		wpa_printf(0, "IKEV2: KEi not received");
		return -1;
	}

	if (kei_len < 4 + 96) {
		wpa_printf(0, "IKEV2: Too show Key Exchange Payload");
		return -1;
	}

	group = ((unsigned short) (((kei)[0] << 8) | (kei)[1]));
	wpa_printf(0, "IKEV2: KEi DH Group #%u", group);

	if (group != data->proposal.dh) {
		wpa_printf(0, "IKEV2: KEi DH Group #%u does not match "
			   "with the selected proposal (%u)",
			   group, data->proposal.dh);
		
 
		data->error_type = INVALID_KE_PAYLOAD;
		data->state = NOTIFY;
		return -1;
	}

	if (data->dh == 0) {
		wpa_printf(0, "IKEV2: Unsupported DH group");
		return -1;
	}

	


 
	if (kei_len - 4 != data->dh->prime_len) {
		wpa_printf(0, "IKEV2: Invalid DH public value length "
			   "%ld (expected %ld)",
			   (long) (kei_len - 4), (long) data->dh->prime_len);
		return -1;
	}

	wpabuf_free(data->i_dh_public);
	data->i_dh_public = wpabuf_alloc(kei_len - 4);
	if (data->i_dh_public == 0)
		return -1;
	wpabuf_put_data(data->i_dh_public, kei + 4, kei_len - 4);

	wpa_hexdump_buf(0, "IKEV2: KEi Diffie-Hellman Public Value",
			data->i_dh_public);
	
	return 0;
}


static int ikev2_process_ni(struct ikev2_responder_data *data,
			    const unsigned char *ni, size_t ni_len)
{
	if (ni == 0) {
		wpa_printf(0, "IKEV2: Ni not received");
		return -1;
	}

	if (ni_len < 16 || ni_len > 256) {
		wpa_printf(0, "IKEV2: Invalid Ni length %ld",
		           (long) ni_len);
		return -1;
	}

#line 471 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\ikev2.c"

	data->i_nonce_len = ni_len;
	os_memcpy(data->i_nonce, ni, ni_len);
	wpa_hexdump(0, "IKEV2: Ni",
		    data->i_nonce, data->i_nonce_len);

	return 0;
}


static int ikev2_process_sa_init(struct ikev2_responder_data *data,
				 const struct ikev2_hdr *hdr,
				 struct ikev2_payloads *pl)
{
	if (ikev2_process_sai1(data, pl->sa, pl->sa_len) < 0 ||
	    ikev2_process_kei(data, pl->ke, pl->ke_len) < 0 ||
	    ikev2_process_ni(data, pl->nonce, pl->nonce_len) < 0)
		return -1;

	os_memcpy(data->i_spi, hdr->i_spi, 8);

	return 0;
}


static int ikev2_process_idi(struct ikev2_responder_data *data,
			     const unsigned char *idi, size_t idi_len)
{
	unsigned char id_type;

	if (idi == 0) {
		wpa_printf(0, "IKEV2: No IDi received");
		return -1;
	}

	if (idi_len < 4) {
		wpa_printf(0, "IKEV2: Too short IDi payload");
		return -1;
	}

	id_type = idi[0];
	idi += 4;
	idi_len -= 4;

	wpa_printf(0, "IKEV2: IDi ID Type %d", id_type);
	wpa_hexdump_ascii(0, "IKEV2: IDi", idi, idi_len);
	os_free(data->IDi);
	data->IDi = os_malloc(idi_len);
	if (data->IDi == 0)
		return -1;
	os_memcpy(data->IDi, idi, idi_len);
	data->IDi_len = idi_len;
	data->IDi_type = id_type;

	return 0;
}


static int ikev2_process_cert(struct ikev2_responder_data *data,
			      const unsigned char *cert, size_t cert_len)
{
	unsigned char cert_encoding;

	if (cert == 0) {
		if (data->peer_auth == PEER_AUTH_CERT) {
			wpa_printf(0, "IKEV2: No Certificate received");
			return -1;
		}
		return 0;
	}

	if (cert_len < 1) {
		wpa_printf(0, "IKEV2: No Cert Encoding field");
		return -1;
	}

	cert_encoding = cert[0];
	cert++;
	cert_len--;

	wpa_printf(0, "IKEV2: Cert Encoding %d", cert_encoding);
	wpa_hexdump(0, "IKEV2: Certificate Data", cert, cert_len);

	 

	return 0;
}


static int ikev2_process_auth_cert(struct ikev2_responder_data *data,
				   unsigned char method, const unsigned char *auth, size_t auth_len)
{
	if (method != AUTH_RSA_SIGN) {
		wpa_printf(0, "IKEV2: Unsupported authentication "
			   "method %d", method);
		return -1;
	}

	 
	return 0;
}


static int ikev2_process_auth_secret(struct ikev2_responder_data *data,
				     unsigned char method, const unsigned char *auth,
				     size_t auth_len)
{
	unsigned char auth_data[20];
	const struct ikev2_prf_alg *prf;

	if (method != AUTH_SHARED_KEY_MIC) {
		wpa_printf(0, "IKEV2: Unsupported authentication "
			   "method %d", method);
		return -1;
	}

	 
	if (ikev2_derive_auth_data(data->proposal.prf, data->i_sign_msg,
				   data->IDi, data->IDi_len, data->IDi_type,
				   &data->keys, 1, data->shared_secret,
				   data->shared_secret_len,
				   data->r_nonce, data->r_nonce_len,
				   data->key_pad, data->key_pad_len,
				   auth_data) < 0) {
		wpa_printf(0, "IKEV2: Could not derive AUTH data");
		return -1;
	}

	wpabuf_free(data->i_sign_msg);
	data->i_sign_msg = 0;

	prf = ikev2_get_prf(data->proposal.prf);
	if (prf == 0)
		return -1;

	if (auth_len != prf->hash_len ||
	    os_memcmp(auth, auth_data, auth_len) != 0) {
		wpa_printf(0, "IKEV2: Invalid Authentication Data");
		wpa_hexdump(0, "IKEV2: Received Authentication Data",
			    auth, auth_len);
		wpa_hexdump(0, "IKEV2: Expected Authentication Data",
			    auth_data, prf->hash_len);
		data->error_type = AUTHENTICATION_FAILED;
		data->state = NOTIFY;
		return -1;
	}

	wpa_printf(0, "IKEV2: Server authenticated successfully "
		   "using shared keys");

	return 0;
}


static int ikev2_process_auth(struct ikev2_responder_data *data,
			      const unsigned char *auth, size_t auth_len)
{
	unsigned char auth_method;

	if (auth == 0) {
		wpa_printf(0, "IKEV2: No Authentication Payload");
		return -1;
	}

	if (auth_len < 4) {
		wpa_printf(0, "IKEV2: Too short Authentication "
			   "Payload");
		return -1;
	}

	auth_method = auth[0];
	auth += 4;
	auth_len -= 4;

	wpa_printf(0, "IKEV2: Auth Method %d", auth_method);
	wpa_hexdump(0, "IKEV2: Authentication Data", auth, auth_len);

	switch (data->peer_auth) {
	case PEER_AUTH_CERT:
		return ikev2_process_auth_cert(data, auth_method, auth,
					       auth_len);
	case PEER_AUTH_SECRET:
		return ikev2_process_auth_secret(data, auth_method, auth,
						 auth_len);
	}

	return -1;
}


static int ikev2_process_sa_auth_decrypted(struct ikev2_responder_data *data,
					   unsigned char next_payload,
					   unsigned char *payload, size_t payload_len)
{
	struct ikev2_payloads pl;

	wpa_printf(0, "IKEV2: Processing decrypted payloads");

	if (ikev2_parse_payloads(&pl, next_payload, payload, payload +
				 payload_len) < 0) {
		wpa_printf(0, "IKEV2: Failed to parse decrypted "
			   "payloads");
		return -1;
	}

	if (ikev2_process_idi(data, pl.idi, pl.idi_len) < 0 ||
	    ikev2_process_cert(data, pl.cert, pl.cert_len) < 0 ||
	    ikev2_process_auth(data, pl.auth, pl.auth_len) < 0)
		return -1;

	return 0;
}


static int ikev2_process_sa_auth(struct ikev2_responder_data *data,
				 const struct ikev2_hdr *hdr,
				 struct ikev2_payloads *pl)
{
	unsigned char *decrypted;
	size_t decrypted_len;
	int ret;

	decrypted = ikev2_decrypt_payload(data->proposal.encr,
					  data->proposal.integ,
					  &data->keys, 1, hdr, pl->encrypted,
					  pl->encrypted_len, &decrypted_len);
	if (decrypted == 0)
		return -1;

	ret = ikev2_process_sa_auth_decrypted(data, pl->encr_next_payload,
					      decrypted, decrypted_len);
	os_free(decrypted);

	return ret;
}


static int ikev2_validate_rx_state(struct ikev2_responder_data *data,
				   unsigned char exchange_type, unsigned int message_id)
{
	switch (data->state) {
	case SA_INIT:
		 
		if (exchange_type != IKE_SA_INIT) {
			wpa_printf(0, "IKEV2: Unexpected Exchange Type "
				   "%u in SA_INIT state", exchange_type);
			return -1;
		}
		if (message_id != 0) {
			wpa_printf(0, "IKEV2: Unexpected Message ID %u "
				   "in SA_INIT state", message_id);
			return -1;
		}
		break;
	case SA_AUTH:
		


 
		if (exchange_type != IKE_SA_AUTH) {
			wpa_printf(0, "IKEV2: Unexpected Exchange Type "
				   "%u in SA_AUTH state", exchange_type);
			return -1;
		}
		if (message_id != 1) {
			wpa_printf(0, "IKEV2: Unexpected Message ID %u "
				   "in SA_AUTH state", message_id);
			return -1;
		}
		break;
	case CHILD_SA:
		if (exchange_type != CREATE_CHILD_SA) {
			wpa_printf(0, "IKEV2: Unexpected Exchange Type "
				   "%u in CHILD_SA state", exchange_type);
			return -1;
		}
		if (message_id != 2) {
			wpa_printf(0, "IKEV2: Unexpected Message ID %u "
				   "in CHILD_SA state", message_id);
			return -1;
		}
		break;
	case NOTIFY:
	case IKEV2_DONE:
	case IKEV2_FAILED:
		return -1;
	}

	return 0;
}


int ikev2_responder_process(struct ikev2_responder_data *data,
			    const struct wpabuf *buf)
{
	const struct ikev2_hdr *hdr;
	unsigned int length, message_id;
	const unsigned char *pos, *end;
	struct ikev2_payloads pl;

	wpa_printf(0, "IKEV2: Received message (len %lu)",
		   (unsigned long) wpabuf_len(buf));

	if (wpabuf_len(buf) < sizeof(*hdr)) {
		wpa_printf(0, "IKEV2: Too short frame to include HDR");
		return -1;
	}

	data->error_type = 0;
	hdr = (const struct ikev2_hdr *) wpabuf_head(buf);
	end = wpabuf_head_u8(buf) + wpabuf_len(buf);
	message_id = ((((unsigned int) (hdr->message_id)[0]) << 24) | (((unsigned int) (hdr->message_id)[1]) << 16) | (((unsigned int) (hdr->message_id)[2]) << 8) | ((unsigned int) (hdr->message_id)[3]));
	length = ((((unsigned int) (hdr->length)[0]) << 24) | (((unsigned int) (hdr->length)[1]) << 16) | (((unsigned int) (hdr->length)[2]) << 8) | ((unsigned int) (hdr->length)[3]));

	wpa_hexdump(0, "IKEV2:   IKE_SA Initiator's SPI",
		    hdr->i_spi, 8);
	wpa_hexdump(0, "IKEV2:   IKE_SA Responder's SPI",
		    hdr->r_spi, 8);
	wpa_printf(0, "IKEV2:   Next Payload: %u  Version: 0x%x  "
		   "Exchange Type: %u",
		   hdr->next_payload, hdr->version, hdr->exchange_type);
	wpa_printf(0, "IKEV2:   Message ID: %u  Length: %u",
		   message_id, length);

	if (hdr->version != (((2) << 4) | (0))) {
		wpa_printf(0, "IKEV2: Unsupported HDR version 0x%x "
			   "(expected 0x%x)", hdr->version, (((2) << 4) | (0)));
		return -1;
	}

	if (length != wpabuf_len(buf)) {
		wpa_printf(0, "IKEV2: Invalid length (HDR: %lu != "
			   "RX: %lu)", (unsigned long) length,
			   (unsigned long) wpabuf_len(buf));
		return -1;
	}

	if (ikev2_validate_rx_state(data, hdr->exchange_type, message_id) < 0)
		return -1;

	if ((hdr->flags & (0x08 | 0x20)) !=
	    0x08) {
		wpa_printf(0, "IKEV2: Unexpected Flags value 0x%x",
			   hdr->flags);
		return -1;
	}

	if (data->state != SA_INIT) {
		if (os_memcmp(data->i_spi, hdr->i_spi, 8) != 0) {
			wpa_printf(0, "IKEV2: Unexpected IKE_SA "
				   "Initiator's SPI");
			return -1;
		}
		if (os_memcmp(data->r_spi, hdr->r_spi, 8) != 0) {
			wpa_printf(0, "IKEV2: Unexpected IKE_SA "
				   "Responder's SPI");
			return -1;
		}
	}

	pos = (const unsigned char *) (hdr + 1);
	if (ikev2_parse_payloads(&pl, hdr->next_payload, pos, end) < 0)
		return -1;

	if (data->state == SA_INIT) {
		data->last_msg = LAST_MSG_SA_INIT;
		if (ikev2_process_sa_init(data, hdr, &pl) < 0) {
			if (data->state == NOTIFY)
				return 0;
			return -1;
		}
		wpabuf_free(data->i_sign_msg);
		data->i_sign_msg = wpabuf_dup(buf);
	}

	if (data->state == SA_AUTH) {
		data->last_msg = LAST_MSG_SA_AUTH;
		if (ikev2_process_sa_auth(data, hdr, &pl) < 0) {
			if (data->state == NOTIFY)
				return 0;
			return -1;
		}
	}

	return 0;
}


static void ikev2_build_hdr(struct ikev2_responder_data *data,
			    struct wpabuf *msg, unsigned char exchange_type,
			    unsigned char next_payload, unsigned int message_id)
{
	struct ikev2_hdr *hdr;

	wpa_printf(0, "IKEV2: Adding HDR");

	 
	hdr = wpabuf_put(msg, sizeof(*hdr));
	os_memcpy(hdr->i_spi, data->i_spi, 8);
	os_memcpy(hdr->r_spi, data->r_spi, 8);
	hdr->next_payload = next_payload;
	hdr->version = (((2) << 4) | (0));
	hdr->exchange_type = exchange_type;
	hdr->flags = 0x20;
	do { (hdr->message_id)[0] = (unsigned char) ((((unsigned int) (message_id)) >> 24) & 0xff); (hdr->message_id)[1] = (unsigned char) ((((unsigned int) (message_id)) >> 16) & 0xff); (hdr->message_id)[2] = (unsigned char) ((((unsigned int) (message_id)) >> 8) & 0xff); (hdr->message_id)[3] = (unsigned char) (((unsigned int) (message_id)) & 0xff); } while (0);
}


static int ikev2_build_sar1(struct ikev2_responder_data *data,
			    struct wpabuf *msg, unsigned char next_payload)
{
	struct ikev2_payload_hdr *phdr;
	size_t plen;
	struct ikev2_proposal *p;
	struct ikev2_transform *t;

	wpa_printf(0, "IKEV2: Adding SAr1 payload");

	 
	phdr = wpabuf_put(msg, sizeof(*phdr));
	phdr->next_payload = next_payload;
	phdr->flags = 0;

	p = wpabuf_put(msg, sizeof(*p));
#line 903 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\ikev2.c"
	p->proposal_num = data->proposal.proposal_num;

	p->protocol_id = IKEV2_PROTOCOL_IKE;
	p->num_transforms = 4;

	t = wpabuf_put(msg, sizeof(*t));
	t->type = 3;
	t->transform_type = IKEV2_TRANSFORM_ENCR;
	do { (t->transform_id)[0] = ((unsigned short) (data->proposal . encr)) >> 8; (t->transform_id)[1] = ((unsigned short) (data->proposal . encr)) & 0xff; } while (0);
	if (data->proposal.encr == ENCR_AES_CBC) {
		 



		wpabuf_put_be16(msg, 0x800e);  

		wpabuf_put_be16(msg, 128);  
	}
	plen = (unsigned char *) wpabuf_put(msg, 0) - (unsigned char *) t;
	do { (t->transform_length)[0] = ((unsigned short) (plen)) >> 8; (t->transform_length)[1] = ((unsigned short) (plen)) & 0xff; } while (0);

	t = wpabuf_put(msg, sizeof(*t));
	t->type = 3;
	do { (t->transform_length)[0] = ((unsigned short) (sizeof(*t))) >> 8; (t->transform_length)[1] = ((unsigned short) (sizeof(*t))) & 0xff; } while (0);
	t->transform_type = IKEV2_TRANSFORM_PRF;
	do { (t->transform_id)[0] = ((unsigned short) (data->proposal . prf)) >> 8; (t->transform_id)[1] = ((unsigned short) (data->proposal . prf)) & 0xff; } while (0);

	t = wpabuf_put(msg, sizeof(*t));
	t->type = 3;
	do { (t->transform_length)[0] = ((unsigned short) (sizeof(*t))) >> 8; (t->transform_length)[1] = ((unsigned short) (sizeof(*t))) & 0xff; } while (0);
	t->transform_type = IKEV2_TRANSFORM_INTEG;
	do { (t->transform_id)[0] = ((unsigned short) (data->proposal . integ)) >> 8; (t->transform_id)[1] = ((unsigned short) (data->proposal . integ)) & 0xff; } while (0);

	t = wpabuf_put(msg, sizeof(*t));
	do { (t->transform_length)[0] = ((unsigned short) (sizeof(*t))) >> 8; (t->transform_length)[1] = ((unsigned short) (sizeof(*t))) & 0xff; } while (0);
	t->transform_type = IKEV2_TRANSFORM_DH;
	do { (t->transform_id)[0] = ((unsigned short) (data->proposal . dh)) >> 8; (t->transform_id)[1] = ((unsigned short) (data->proposal . dh)) & 0xff; } while (0);

	plen = (unsigned char *) wpabuf_put(msg, 0) - (unsigned char *) p;
	do { (p->proposal_length)[0] = ((unsigned short) (plen)) >> 8; (p->proposal_length)[1] = ((unsigned short) (plen)) & 0xff; } while (0);

	plen = (unsigned char *) wpabuf_put(msg, 0) - (unsigned char *) phdr;
	do { (phdr->payload_length)[0] = ((unsigned short) (plen)) >> 8; (phdr->payload_length)[1] = ((unsigned short) (plen)) & 0xff; } while (0);

	return 0;
}


static int ikev2_build_ker(struct ikev2_responder_data *data,
			   struct wpabuf *msg, unsigned char next_payload)
{
	struct ikev2_payload_hdr *phdr;
	size_t plen;
	struct wpabuf *pv;

	wpa_printf(0, "IKEV2: Adding KEr payload");

	pv = dh_init(data->dh, &data->r_dh_private);
	if (pv == 0) {
		wpa_printf(0, "IKEV2: Failed to initialize DH");
		return -1;
	}

	 
	phdr = wpabuf_put(msg, sizeof(*phdr));
	phdr->next_payload = next_payload;
	phdr->flags = 0;

	wpabuf_put_be16(msg, data->proposal.dh);  
	wpabuf_put(msg, 2);  
	


 
	wpabuf_put(msg, data->dh->prime_len - wpabuf_len(pv));
	wpabuf_put_buf(msg, pv);
	wpabuf_free(pv);

	plen = (unsigned char *) wpabuf_put(msg, 0) - (unsigned char *) phdr;
	do { (phdr->payload_length)[0] = ((unsigned short) (plen)) >> 8; (phdr->payload_length)[1] = ((unsigned short) (plen)) & 0xff; } while (0);
	return 0;
}


static int ikev2_build_nr(struct ikev2_responder_data *data,
			  struct wpabuf *msg, unsigned char next_payload)
{
	struct ikev2_payload_hdr *phdr;
	size_t plen;

	wpa_printf(0, "IKEV2: Adding Nr payload");

	 
	phdr = wpabuf_put(msg, sizeof(*phdr));
	phdr->next_payload = next_payload;
	phdr->flags = 0;
	wpabuf_put_data(msg, data->r_nonce, data->r_nonce_len);
	plen = (unsigned char *) wpabuf_put(msg, 0) - (unsigned char *) phdr;
	do { (phdr->payload_length)[0] = ((unsigned short) (plen)) >> 8; (phdr->payload_length)[1] = ((unsigned short) (plen)) & 0xff; } while (0);
	return 0;
}


static int ikev2_build_idr(struct ikev2_responder_data *data,
			   struct wpabuf *msg, unsigned char next_payload)
{
	struct ikev2_payload_hdr *phdr;
	size_t plen;

	wpa_printf(0, "IKEV2: Adding IDr payload");

	if (data->IDr == 0) {
		wpa_printf(0, "IKEV2: No IDr available");
		return -1;
	}

	 
	phdr = wpabuf_put(msg, sizeof(*phdr));
	phdr->next_payload = next_payload;
	phdr->flags = 0;
	wpabuf_put_u8(msg, ID_KEY_ID);
	wpabuf_put(msg, 3);  
	wpabuf_put_data(msg, data->IDr, data->IDr_len);
	plen = (unsigned char *) wpabuf_put(msg, 0) - (unsigned char *) phdr;
	do { (phdr->payload_length)[0] = ((unsigned short) (plen)) >> 8; (phdr->payload_length)[1] = ((unsigned short) (plen)) & 0xff; } while (0);
	return 0;
}


static int ikev2_build_auth(struct ikev2_responder_data *data,
			    struct wpabuf *msg, unsigned char next_payload)
{
	struct ikev2_payload_hdr *phdr;
	size_t plen;
	const struct ikev2_prf_alg *prf;

	wpa_printf(0, "IKEV2: Adding AUTH payload");

	prf = ikev2_get_prf(data->proposal.prf);
	if (prf == 0)
		return -1;

	 
	phdr = wpabuf_put(msg, sizeof(*phdr));
	phdr->next_payload = next_payload;
	phdr->flags = 0;
	wpabuf_put_u8(msg, AUTH_SHARED_KEY_MIC);
	wpabuf_put(msg, 3);  

	 
	if (ikev2_derive_auth_data(data->proposal.prf, data->r_sign_msg,
				   data->IDr, data->IDr_len, ID_KEY_ID,
				   &data->keys, 0, data->shared_secret,
				   data->shared_secret_len,
				   data->i_nonce, data->i_nonce_len,
				   data->key_pad, data->key_pad_len,
				   wpabuf_put(msg, prf->hash_len)) < 0) {
		wpa_printf(0, "IKEV2: Could not derive AUTH data");
		return -1;
	}
	wpabuf_free(data->r_sign_msg);
	data->r_sign_msg = 0;

	plen = (unsigned char *) wpabuf_put(msg, 0) - (unsigned char *) phdr;
	do { (phdr->payload_length)[0] = ((unsigned short) (plen)) >> 8; (phdr->payload_length)[1] = ((unsigned short) (plen)) & 0xff; } while (0);
	return 0;
}


static int ikev2_build_notification(struct ikev2_responder_data *data,
				    struct wpabuf *msg, unsigned char next_payload)
{
	struct ikev2_payload_hdr *phdr;
	size_t plen;

	wpa_printf(0, "IKEV2: Adding Notification payload");

	if (data->error_type == 0) {
		wpa_printf(0, "IKEV2: No Notify Message Type "
			   "available");
		return -1;
	}

	 
	phdr = wpabuf_put(msg, sizeof(*phdr));
	phdr->next_payload = next_payload;
	phdr->flags = 0;



	wpabuf_put_u8(msg, 0);  

	wpabuf_put_u8(msg, 0);  
	wpabuf_put_be16(msg, data->error_type);

	switch (data->error_type) {
	case INVALID_KE_PAYLOAD:
		if (data->proposal.dh == -1) {
			wpa_printf(0, "IKEV2: No DH Group selected for "
				   "INVALID_KE_PAYLOAD notifications");
			return -1;
		}
		wpabuf_put_be16(msg, data->proposal.dh);
		wpa_printf(0, "IKEV2: INVALID_KE_PAYLOAD - request "
			   "DH Group #%d", data->proposal.dh);
		break;
	case AUTHENTICATION_FAILED:
		 
		break;
	default:
		wpa_printf(0, "IKEV2: Unsupported Notify Message Type "
			   "%d", data->error_type);
		return -1;
	}

	plen = (unsigned char *) wpabuf_put(msg, 0) - (unsigned char *) phdr;
	do { (phdr->payload_length)[0] = ((unsigned short) (plen)) >> 8; (phdr->payload_length)[1] = ((unsigned short) (plen)) & 0xff; } while (0);
	return 0;
}


static struct wpabuf * ikev2_build_sa_init(struct ikev2_responder_data *data)
{
	struct wpabuf *msg;

	 

	if (os_get_random(data->r_spi, 8))
		return 0;
	wpa_hexdump(0, "IKEV2: IKE_SA Responder's SPI",
		    data->r_spi, 8);

	data->r_nonce_len = 16;
	if (os_get_random(data->r_nonce, data->r_nonce_len))
		return 0;
#line 1145 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\ikev2.c"
	wpa_hexdump(0, "IKEV2: Nr", data->r_nonce, data->r_nonce_len);

	msg = wpabuf_alloc(sizeof(struct ikev2_hdr) + data->IDr_len + 1500);
	if (msg == 0)
		return 0;

	ikev2_build_hdr(data, msg, IKE_SA_INIT, IKEV2_PAYLOAD_SA, 0);
	if (ikev2_build_sar1(data, msg, IKEV2_PAYLOAD_KEY_EXCHANGE) ||
	    ikev2_build_ker(data, msg, IKEV2_PAYLOAD_NONCE) ||
	    ikev2_build_nr(data, msg, data->peer_auth == PEER_AUTH_SECRET ?
			   IKEV2_PAYLOAD_ENCRYPTED :
			   IKEV2_PAYLOAD_NO_NEXT_PAYLOAD)) {
		wpabuf_free(msg);
		return 0;
	}

	if (ikev2_derive_keys(data)) {
		wpabuf_free(msg);
		return 0;
	}

	if (data->peer_auth == PEER_AUTH_CERT) {
		
 
	}

	if (data->peer_auth == PEER_AUTH_SECRET) {
		struct wpabuf *plain = wpabuf_alloc(data->IDr_len + 1000);
		if (plain == 0) {
			wpabuf_free(msg);
			return 0;
		}
		if (ikev2_build_idr(data, plain,
				    IKEV2_PAYLOAD_NO_NEXT_PAYLOAD) ||
		    ikev2_build_encrypted(data->proposal.encr,
					  data->proposal.integ,
					  &data->keys, 0, msg, plain,
					  IKEV2_PAYLOAD_IDr)) {
			wpabuf_free(plain);
			wpabuf_free(msg);
			return 0;
		}
		wpabuf_free(plain);
	}

	ikev2_update_hdr(msg);

	wpa_hexdump_buf(0, "IKEV2: Sending message (SA_INIT)", msg);

	data->state = SA_AUTH;

	wpabuf_free(data->r_sign_msg);
	data->r_sign_msg = wpabuf_dup(msg);

	return msg;
}


static struct wpabuf * ikev2_build_sa_auth(struct ikev2_responder_data *data)
{
	struct wpabuf *msg, *plain;

	 

	msg = wpabuf_alloc(sizeof(struct ikev2_hdr) + data->IDr_len + 1000);
	if (msg == 0)
		return 0;
	ikev2_build_hdr(data, msg, IKE_SA_AUTH, IKEV2_PAYLOAD_ENCRYPTED, 1);

	plain = wpabuf_alloc(data->IDr_len + 1000);
	if (plain == 0) {
		wpabuf_free(msg);
		return 0;
	}

	if (ikev2_build_idr(data, plain, IKEV2_PAYLOAD_AUTHENTICATION) ||
	    ikev2_build_auth(data, plain, IKEV2_PAYLOAD_NO_NEXT_PAYLOAD) ||
	    ikev2_build_encrypted(data->proposal.encr, data->proposal.integ,
				  &data->keys, 0, msg, plain,
				  IKEV2_PAYLOAD_IDr)) {
		wpabuf_free(plain);
		wpabuf_free(msg);
		return 0;
	}
	wpabuf_free(plain);

	wpa_hexdump_buf(0, "IKEV2: Sending message (SA_AUTH)", msg);

	data->state = IKEV2_DONE;

	return msg;
}


static struct wpabuf * ikev2_build_notify(struct ikev2_responder_data *data)
{
	struct wpabuf *msg;

	msg = wpabuf_alloc(sizeof(struct ikev2_hdr) + 1000);
	if (msg == 0)
		return 0;
	if (data->last_msg == LAST_MSG_SA_AUTH) {
		 
		struct wpabuf *plain = wpabuf_alloc(100);
		if (plain == 0) {
			wpabuf_free(msg);
			return 0;
		}
		ikev2_build_hdr(data, msg, IKE_SA_AUTH,
				IKEV2_PAYLOAD_ENCRYPTED, 1);
		if (ikev2_build_notification(data, plain,
					     IKEV2_PAYLOAD_NO_NEXT_PAYLOAD) ||
		    ikev2_build_encrypted(data->proposal.encr,
					  data->proposal.integ,
					  &data->keys, 0, msg, plain,
					  IKEV2_PAYLOAD_NOTIFICATION)) {
			wpabuf_free(plain);
			wpabuf_free(msg);
			return 0;
		}
		data->state = IKEV2_FAILED;
	} else {
		 
		ikev2_build_hdr(data, msg, IKE_SA_INIT,
				IKEV2_PAYLOAD_NOTIFICATION, 0);
		if (ikev2_build_notification(data, msg,
					     IKEV2_PAYLOAD_NO_NEXT_PAYLOAD)) {
			wpabuf_free(msg);
			return 0;
		}
		data->state = SA_INIT;
	}

	ikev2_update_hdr(msg);

	wpa_hexdump_buf(0, "IKEV2: Sending message (Notification)",
			msg);

	return msg;
}


struct wpabuf * ikev2_responder_build(struct ikev2_responder_data *data)
{
	switch (data->state) {
	case SA_INIT:
		return ikev2_build_sa_init(data);
	case SA_AUTH:
		return ikev2_build_sa_auth(data);
	case CHILD_SA:
		return 0;
	case NOTIFY:
		return ikev2_build_notify(data);
	case IKEV2_DONE:
	case IKEV2_FAILED:
		return 0;
	}
	return 0;
}
