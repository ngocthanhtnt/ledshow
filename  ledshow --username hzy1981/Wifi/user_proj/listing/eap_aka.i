#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_aka.c"












 

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

#line 16 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_aka.c"

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



#line 18 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_aka.c"
#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\pcsc_funcs.h"












 










 
#line 33 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\pcsc_funcs.h"




typedef enum {
	SCARD_GSM_SIM_ONLY,
	SCARD_USIM_ONLY,
	SCARD_TRY_BOTH
} scard_sim_type;


#line 58 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\pcsc_funcs.h"

#line 65 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\pcsc_funcs.h"



#line 19 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_aka.c"
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

#line 20 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_aka.c"
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
#line 21 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_aka.c"
#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\crypto/sha256.h"












 






void hmac_sha256_vector(const unsigned char *key, size_t key_len, size_t num_elem,
		      const unsigned char *addr[], const size_t *len, unsigned char *mac);
void hmac_sha256(const unsigned char *key, size_t key_len, const unsigned char *data,
		 size_t data_len, unsigned char *mac);
void sha256_prf(const unsigned char *key, size_t key_len, const char *label,
	      const unsigned char *data, size_t data_len, unsigned char *buf, size_t buf_len);

#line 22 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_aka.c"
#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\crypto/milenage.h"












 




void milenage_generate(const unsigned char *opc, const unsigned char *amf, const unsigned char *k,
		       const unsigned char *sqn, const unsigned char *_rand, unsigned char *autn, unsigned char *ik,
		       unsigned char *ck, unsigned char *res, size_t *res_len);
int milenage_auts(const unsigned char *opc, const unsigned char *k, const unsigned char *_rand, const unsigned char *auts,
		  unsigned char *sqn);
int gsm_milenage(const unsigned char *opc, const unsigned char *k, const unsigned char *_rand, unsigned char *sres,
		 unsigned char *kc);
int milenage_check(const unsigned char *opc, const unsigned char *k, const unsigned char *sqn, const unsigned char *_rand,
		   const unsigned char *autn, unsigned char *ik, unsigned char *ck, unsigned char *res, size_t *res_len,
		   unsigned char *auts);
int milenage_f1(const unsigned char *opc, const unsigned char *k, const unsigned char *_rand,
		const unsigned char *sqn, const unsigned char *amf, unsigned char *mac_a, unsigned char *mac_s);
int milenage_f2345(const unsigned char *opc, const unsigned char *k, const unsigned char *_rand,
		   unsigned char *res, unsigned char *ck, unsigned char *ik, unsigned char *ak, unsigned char *akstar);

#line 23 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_aka.c"
#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common/eap_sim_common.h"












 




#line 28 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common/eap_sim_common.h"





 






 










 
#line 59 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common/eap_sim_common.h"

 


#line 73 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common/eap_sim_common.h"





struct wpabuf;

void eap_sim_derive_mk(const unsigned char *identity, size_t identity_len,
		       const unsigned char *nonce_mt, unsigned short selected_version,
		       const unsigned char *ver_list, size_t ver_list_len,
		       int num_chal, const unsigned char *kc, unsigned char *mk);
void eap_aka_derive_mk(const unsigned char *identity, size_t identity_len,
		       const unsigned char *ik, const unsigned char *ck, unsigned char *mk);
int eap_sim_derive_keys(const unsigned char *mk, unsigned char *k_encr, unsigned char *k_aut, unsigned char *msk,
			unsigned char *emsk);
int eap_sim_derive_keys_reauth(unsigned short _counter,
			       const unsigned char *identity, size_t identity_len,
			       const unsigned char *nonce_s, const unsigned char *mk, unsigned char *msk,
			       unsigned char *emsk);
int eap_sim_verify_mac(const unsigned char *k_aut, const struct wpabuf *req,
		       const unsigned char *mac, const unsigned char *extra, size_t extra_len);
void eap_sim_add_mac(const unsigned char *k_aut, const unsigned char *msg, size_t msg_len, unsigned char *mac,
		     const unsigned char *extra, size_t extra_len);

#line 114 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common/eap_sim_common.h"
static  void eap_aka_prime_derive_keys(const unsigned char *identity,
					     size_t identity_len,
					     const unsigned char *ik, const unsigned char *ck,
					     unsigned char *k_encr, unsigned char *k_aut, unsigned char *k_re,
					     unsigned char *msk, unsigned char *emsk)
{
}

static  int eap_aka_prime_derive_keys_reauth(const unsigned char *k_re, unsigned short counter,
						   const unsigned char *identity,
						   size_t identity_len,
						   const unsigned char *nonce_s, unsigned char *msk,
						   unsigned char *emsk)
{
	return -1;
}

static  int eap_sim_verify_mac_sha256(const unsigned char *k_aut,
					    const struct wpabuf *req,
					    const unsigned char *mac, const unsigned char *extra,
					    size_t extra_len)
{
	return -1;
}



 
#line 169 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_common/eap_sim_common.h"

 






 


 



enum eap_sim_id_req {
	NO_ID_REQ, ANY_ID, FULLAUTH_ID, PERMANENT_ID
};


struct eap_sim_attrs {
	const unsigned char *rand, *autn, *mac, *iv, *encr_data, *version_list, *nonce_s;
	const unsigned char *next_pseudonym, *next_reauth_id;
	const unsigned char *nonce_mt, *identity, *res, *auts;
	const unsigned char *checkcode;
	const unsigned char *kdf_input;
	const unsigned char *bidding;
	size_t num_chal, version_list_len, encr_data_len;
	size_t next_pseudonym_len, next_reauth_id_len, identity_len, res_len;
	size_t res_len_bits;
	size_t checkcode_len;
	size_t kdf_input_len;
	enum eap_sim_id_req id_req;
	int notification, counter, selected_version, client_error_code;
	int counter_too_small;
	int result_ind;

	unsigned short kdf[10];
	size_t kdf_count;
};

int eap_sim_parse_attr(const unsigned char *start, const unsigned char *end,
		       struct eap_sim_attrs *attr, int aka, int encr);
unsigned char * eap_sim_parse_encr(const unsigned char *k_encr, const unsigned char *encr_data,
			size_t encr_data_len, const unsigned char *iv,
			struct eap_sim_attrs *attr, int aka);


struct eap_sim_msg;

struct eap_sim_msg * eap_sim_msg_init(int code, int id, int type, int subtype);
struct wpabuf * eap_sim_msg_finish(struct eap_sim_msg *msg, const unsigned char *k_aut,
				   const unsigned char *extra, size_t extra_len);
void eap_sim_msg_free(struct eap_sim_msg *msg);
unsigned char * eap_sim_msg_add_full(struct eap_sim_msg *msg, unsigned char attr,
			  const unsigned char *data, size_t len);
unsigned char * eap_sim_msg_add(struct eap_sim_msg *msg, unsigned char attr,
		     unsigned short value, const unsigned char *data, size_t len);
unsigned char * eap_sim_msg_add_mac(struct eap_sim_msg *msg, unsigned char attr);
int eap_sim_msg_add_encr_start(struct eap_sim_msg *msg, unsigned char attr_iv,
			       unsigned char attr_encr);
int eap_sim_msg_add_encr_end(struct eap_sim_msg *msg, unsigned char *k_encr,
			     int attr_pad);

void eap_sim_report_notification(void *msg_ctx, int notification, int aka);

#line 24 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_aka.c"
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

#line 25 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_aka.c"
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

#line 26 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_aka.c"

#line 28 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_aka.c"

enum {
	CONTINUE, RESULT_SUCCESS, RESULT_FAILURE, SUCCESS, FAILURE
};


struct eap_aka_data {
	unsigned char ik[16], ck[16], res[16];
	size_t res_len;
	unsigned char nonce_s[16];
	unsigned char mk[20];
	unsigned char k_aut[32];
	unsigned char k_encr[16];
	unsigned char k_re[32];  
	unsigned char msk[64];
	unsigned char emsk[64];
	unsigned char rand[16], autn[16];
	unsigned char auts[14];

	int num_id_req, num_notification;
	unsigned char *pseudonym;
	size_t pseudonym_len;
	unsigned char *reauth_id;
	size_t reauth_id_len;
	int reauth;
	unsigned int counter, counter_too_small;
	unsigned char *last_eap_identity;
	size_t last_eap_identity_len;
	



 
	int state;

	struct wpabuf *id_msgs;
	int prev_id;
	int result_ind, use_result_ind;
	unsigned char eap_method;
	unsigned char *network_name;
	size_t network_name_len;
	unsigned short kdf;
	int kdf_negotiation;
};



static const char * eap_aka_state_txt(int state)
{
	switch (state) {
	case CONTINUE:
		return "CONTINUE";
	case RESULT_SUCCESS:
		return "RESULT_SUCCESS";
	case RESULT_FAILURE:
		return "RESULT_FAILURE";
	case SUCCESS:
		return "SUCCESS";
	case FAILURE:
		return "FAILURE";
	default:
		return "?";
	}
}



static void eap_aka_state(struct eap_aka_data *data, int state)
{
	wpa_printf(0, "EAP-AKA: %s -> %s",
		   eap_aka_state_txt(data->state),
		   eap_aka_state_txt(state));
	data->state = state;
}


static void * eap_aka_init(struct eap_sm *sm)
{
	struct eap_aka_data *data;
	const char *phase1 = eap_get_config_phase1(sm);

	data = os_zalloc(sizeof(*data));
	if (data == 0)
		return 0;

	data->eap_method = EAP_TYPE_AKA;

	eap_aka_state(data, CONTINUE);
	data->prev_id = -1;

	data->result_ind = phase1 && os_strstr(phase1, "result_ind=1") != 0;

	return data;
}


#line 134 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_aka.c"


static void eap_aka_deinit(struct eap_sm *sm, void *priv)
{
	struct eap_aka_data *data = priv;
	if (data) {
		os_free(data->pseudonym);
		os_free(data->reauth_id);
		os_free(data->last_eap_identity);
		wpabuf_free(data->id_msgs);
		os_free(data->network_name);
		os_free(data);
	}
}


static int eap_aka_umts_auth(struct eap_sm *sm, struct eap_aka_data *data)
{
	struct eap_peer_config *conf;

	wpa_printf(0, "EAP-AKA: UMTS authentication algorithm");

	conf = eap_get_config(sm);
	if (conf == 0)
		return -1;
	if (conf->pcsc) {
		return -1;


	}

#line 199 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_aka.c"

#line 232 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_aka.c"

	wpa_printf(0, "EAP-AKA: No UMTS authentication algorith "
		   "enabled");
	return -1;


}






static void eap_aka_clear_identities(struct eap_aka_data *data, int id)
{
	wpa_printf(0, "EAP-AKA: forgetting old%s%s%s",
		   id & 0x01 ? " pseudonym" : "",
		   id & 0x02 ? " reauth_id" : "",
		   id & 0x04 ? " eap_id" : "");
	if (id & 0x01) {
		os_free(data->pseudonym);
		data->pseudonym = 0;
		data->pseudonym_len = 0;
	}
	if (id & 0x02) {
		os_free(data->reauth_id);
		data->reauth_id = 0;
		data->reauth_id_len = 0;
	}
	if (id & 0x04) {
		os_free(data->last_eap_identity);
		data->last_eap_identity = 0;
		data->last_eap_identity_len = 0;
	}
}


static int eap_aka_learn_ids(struct eap_aka_data *data,
			     struct eap_sim_attrs *attr)
{
	if (attr->next_pseudonym) {
		os_free(data->pseudonym);
		data->pseudonym = os_malloc(attr->next_pseudonym_len);
		if (data->pseudonym == 0) {
			wpa_printf(0, "EAP-AKA: (encr) No memory for "
				   "next pseudonym");
			return -1;
		}
		os_memcpy(data->pseudonym, attr->next_pseudonym,
			  attr->next_pseudonym_len);
		data->pseudonym_len = attr->next_pseudonym_len;
		wpa_hexdump_ascii(0,
				  "EAP-AKA: (encr) AT_NEXT_PSEUDONYM",
				  data->pseudonym,
				  data->pseudonym_len);
	}

	if (attr->next_reauth_id) {
		os_free(data->reauth_id);
		data->reauth_id = os_malloc(attr->next_reauth_id_len);
		if (data->reauth_id == 0) {
			wpa_printf(0, "EAP-AKA: (encr) No memory for "
				   "next reauth_id");
			return -1;
		}
		os_memcpy(data->reauth_id, attr->next_reauth_id,
			  attr->next_reauth_id_len);
		data->reauth_id_len = attr->next_reauth_id_len;
		wpa_hexdump_ascii(0,
				  "EAP-AKA: (encr) AT_NEXT_REAUTH_ID",
				  data->reauth_id,
				  data->reauth_id_len);
	}

	return 0;
}


static int eap_aka_add_id_msg(struct eap_aka_data *data,
			      const struct wpabuf *msg)
{
	if (msg == 0)
		return -1;

	if (data->id_msgs == 0) {
		data->id_msgs = wpabuf_dup(msg);
		return data->id_msgs == 0 ? -1 : 0;
	}

	if (wpabuf_resize(&data->id_msgs, wpabuf_len(msg)) < 0)
		return -1;
	wpabuf_put_buf(data->id_msgs, msg);

	return 0;
}


static void eap_aka_add_checkcode(struct eap_aka_data *data,
				  struct eap_sim_msg *msg)
{
	const unsigned char *addr;
	size_t len;
	unsigned char hash[32];

	wpa_printf(0, "   AT_CHECKCODE");

	if (data->id_msgs == 0) {
		


 
		eap_sim_msg_add(msg, 134, 0, 0, 0);
		return;
	}

	 
	addr = wpabuf_head(data->id_msgs);
	len = wpabuf_len(data->id_msgs);
	wpa_hexdump(0, "EAP-AKA: AT_CHECKCODE data", addr, len);





		sha1_vector(1, &addr, &len, hash);

	eap_sim_msg_add(msg, 134, 0, hash,
			data->eap_method == EAP_TYPE_AKA_PRIME ?
			32 : 20);
}


static int eap_aka_verify_checkcode(struct eap_aka_data *data,
				    const unsigned char *checkcode, size_t checkcode_len)
{
	const unsigned char *addr;
	size_t len;
	unsigned char hash[32];
	size_t hash_len;

	if (checkcode == 0)
		return -1;

	if (data->id_msgs == 0) {
		if (checkcode_len != 0) {
			wpa_printf(0, "EAP-AKA: Checkcode from server "
				   "indicates that AKA/Identity messages were "
				   "used, but they were not");
			return -1;
		}
		return 0;
	}

	hash_len = data->eap_method == EAP_TYPE_AKA_PRIME ?
		32 : 20;

	if (checkcode_len != hash_len) {
		wpa_printf(0, "EAP-AKA: Checkcode from server "
			   "indicates that AKA/Identity message were not "
			   "used, but they were");
		return -1;
	}

	 
	addr = wpabuf_head(data->id_msgs);
	len = wpabuf_len(data->id_msgs);





		sha1_vector(1, &addr, &len, hash);

	if (os_memcmp(hash, checkcode, hash_len) != 0) {
		wpa_printf(0, "EAP-AKA: Mismatch in AT_CHECKCODE");
		return -1;
	}

	return 0;
}


static struct wpabuf * eap_aka_client_error(struct eap_aka_data *data, unsigned char id,
					    int err)
{
	struct eap_sim_msg *msg;

	eap_aka_state(data, FAILURE);
	data->num_id_req = 0;
	data->num_notification = 0;

	msg = eap_sim_msg_init(EAP_CODE_RESPONSE, id, data->eap_method,
			       14);
	eap_sim_msg_add(msg, 22, err, 0, 0);
	return eap_sim_msg_finish(msg, 0, 0, 0);
}


static struct wpabuf * eap_aka_authentication_reject(struct eap_aka_data *data,
						     unsigned char id)
{
	struct eap_sim_msg *msg;

	eap_aka_state(data, FAILURE);
	data->num_id_req = 0;
	data->num_notification = 0;

	wpa_printf(0, "Generating EAP-AKA Authentication-Reject "
		   "(id=%d)", id);
	msg = eap_sim_msg_init(EAP_CODE_RESPONSE, id, data->eap_method,
			       2);
	return eap_sim_msg_finish(msg, 0, 0, 0);
}


static struct wpabuf * eap_aka_synchronization_failure(
	struct eap_aka_data *data, unsigned char id)
{
	struct eap_sim_msg *msg;

	data->num_id_req = 0;
	data->num_notification = 0;

	wpa_printf(0, "Generating EAP-AKA Synchronization-Failure "
		   "(id=%d)", id);
	msg = eap_sim_msg_init(EAP_CODE_RESPONSE, id, data->eap_method,
			       4);
	wpa_printf(0, "   AT_AUTS");
	eap_sim_msg_add_full(msg, 4, data->auts,
			     14);
	return eap_sim_msg_finish(msg, 0, 0, 0);
}


static struct wpabuf * eap_aka_response_identity(struct eap_sm *sm,
						 struct eap_aka_data *data,
						 unsigned char id,
						 enum eap_sim_id_req id_req)
{
	const unsigned char *identity = 0;
	size_t identity_len = 0;
	struct eap_sim_msg *msg;

	data->reauth = 0;
	if (id_req == ANY_ID && data->reauth_id) {
		identity = data->reauth_id;
		identity_len = data->reauth_id_len;
		data->reauth = 1;
	} else if ((id_req == ANY_ID || id_req == FULLAUTH_ID) &&
		   data->pseudonym) {
		identity = data->pseudonym;
		identity_len = data->pseudonym_len;
		eap_aka_clear_identities(data, 0x02);
	} else if (id_req != NO_ID_REQ) {
		identity = eap_get_config_identity(sm, &identity_len);
		if (identity) {
			eap_aka_clear_identities(data, 0x01 |
						 0x02);
		}
	}
	if (id_req != NO_ID_REQ)
		eap_aka_clear_identities(data, 0x04);

	wpa_printf(0, "Generating EAP-AKA Identity (id=%d)", id);
	msg = eap_sim_msg_init(EAP_CODE_RESPONSE, id, data->eap_method,
			       5);

	if (identity) {
		wpa_hexdump_ascii(0, "   AT_IDENTITY",
				  identity, identity_len);
		eap_sim_msg_add(msg, 14, identity_len,
				identity, identity_len);
	}

	return eap_sim_msg_finish(msg, 0, 0, 0);
}


static struct wpabuf * eap_aka_response_challenge(struct eap_aka_data *data,
						  unsigned char id)
{
	struct eap_sim_msg *msg;

	wpa_printf(0, "Generating EAP-AKA Challenge (id=%d)", id);
	msg = eap_sim_msg_init(EAP_CODE_RESPONSE, id, data->eap_method,
			       1);
	wpa_printf(0, "   AT_RES");
	eap_sim_msg_add(msg, 3, data->res_len * 8,
			data->res, data->res_len);
	eap_aka_add_checkcode(data, msg);
	if (data->use_result_ind) {
		wpa_printf(0, "   AT_RESULT_IND");
		eap_sim_msg_add(msg, 135, 0, 0, 0);
	}
	wpa_printf(0, "   AT_MAC");
	eap_sim_msg_add_mac(msg, 11);
	return eap_sim_msg_finish(msg, data->k_aut, (unsigned char *) "", 0);
}


static struct wpabuf * eap_aka_response_reauth(struct eap_aka_data *data,
					       unsigned char id, int counter_too_small,
					       const unsigned char *nonce_s)
{
	struct eap_sim_msg *msg;
	unsigned int counter;

	wpa_printf(0, "Generating EAP-AKA Reauthentication (id=%d)",
		   id);
	msg = eap_sim_msg_init(EAP_CODE_RESPONSE, id, data->eap_method,
			       13);
	wpa_printf(0, "   AT_IV");
	wpa_printf(0, "   AT_ENCR_DATA");
	eap_sim_msg_add_encr_start(msg, 129, 130);

	if (counter_too_small) {
		wpa_printf(0, "   *AT_COUNTER_TOO_SMALL");
		eap_sim_msg_add(msg, 20, 0, 0, 0);
		counter = data->counter_too_small;
	} else
		counter = data->counter;

	wpa_printf(0, "   *AT_COUNTER %d", counter);
	eap_sim_msg_add(msg, 19, counter, 0, 0);

	if (eap_sim_msg_add_encr_end(msg, data->k_encr, 6)) {
		wpa_printf(0, "EAP-AKA: Failed to encrypt "
			   "AT_ENCR_DATA");
		eap_sim_msg_free(msg);
		return 0;
	}
	eap_aka_add_checkcode(data, msg);
	if (data->use_result_ind) {
		wpa_printf(0, "   AT_RESULT_IND");
		eap_sim_msg_add(msg, 135, 0, 0, 0);
	}
	wpa_printf(0, "   AT_MAC");
	eap_sim_msg_add_mac(msg, 11);
	return eap_sim_msg_finish(msg, data->k_aut, nonce_s,
				  16);
}


static struct wpabuf * eap_aka_response_notification(struct eap_aka_data *data,
						     unsigned char id, unsigned short notification)
{
	struct eap_sim_msg *msg;
	unsigned char *k_aut = (notification & 0x4000) == 0 ? data->k_aut : 0;

	wpa_printf(0, "Generating EAP-AKA Notification (id=%d)", id);
	msg = eap_sim_msg_init(EAP_CODE_RESPONSE, id, data->eap_method,
			       12);
	if (k_aut && data->reauth) {
		wpa_printf(0, "   AT_IV");
		wpa_printf(0, "   AT_ENCR_DATA");
		eap_sim_msg_add_encr_start(msg, 129,
					   130);
		wpa_printf(0, "   *AT_COUNTER %d", data->counter);
		eap_sim_msg_add(msg, 19, data->counter,
				0, 0);
		if (eap_sim_msg_add_encr_end(msg, data->k_encr,
					     6)) {
			wpa_printf(0, "EAP-AKA: Failed to encrypt "
				   "AT_ENCR_DATA");
			eap_sim_msg_free(msg);
			return 0;
		}
	}
	if (k_aut) {
		wpa_printf(0, "   AT_MAC");
		eap_sim_msg_add_mac(msg, 11);
	}
	return eap_sim_msg_finish(msg, k_aut, (unsigned char *) "", 0);
}


static struct wpabuf * eap_aka_process_identity(struct eap_sm *sm,
						struct eap_aka_data *data,
						unsigned char id,
						const struct wpabuf *reqData,
						struct eap_sim_attrs *attr)
{
	int id_error;
	struct wpabuf *buf;

	wpa_printf(0, "EAP-AKA: subtype Identity");

	id_error = 0;
	switch (attr->id_req) {
	case NO_ID_REQ:
		break;
	case ANY_ID:
		if (data->num_id_req > 0)
			id_error++;
		data->num_id_req++;
		break;
	case FULLAUTH_ID:
		if (data->num_id_req > 1)
			id_error++;
		data->num_id_req++;
		break;
	case PERMANENT_ID:
		if (data->num_id_req > 2)
			id_error++;
		data->num_id_req++;
		break;
	}
	if (id_error) {
		wpa_printf(0, "EAP-AKA: Too many ID requests "
			   "used within one authentication");
		return eap_aka_client_error(data, id,
					    0);
	}

	buf = eap_aka_response_identity(sm, data, id, attr->id_req);

	if (data->prev_id != id) {
		eap_aka_add_id_msg(data, reqData);
		eap_aka_add_id_msg(data, buf);
		data->prev_id = id;
	}

	return buf;
}


static int eap_aka_verify_mac(struct eap_aka_data *data,
			      const struct wpabuf *req,
			      const unsigned char *mac, const unsigned char *extra,
			      size_t extra_len)
{
	if (data->eap_method == EAP_TYPE_AKA_PRIME)
		return eap_sim_verify_mac_sha256(data->k_aut, req, mac, extra,
						 extra_len);
	return eap_sim_verify_mac(data->k_aut, req, mac, extra, extra_len);
}


#line 752 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_aka.c"


static struct wpabuf * eap_aka_process_challenge(struct eap_sm *sm,
						 struct eap_aka_data *data,
						 unsigned char id,
						 const struct wpabuf *reqData,
						 struct eap_sim_attrs *attr)
{
	const unsigned char *identity;
	size_t identity_len;
	int res;
	struct eap_sim_attrs eattr;

	wpa_printf(0, "EAP-AKA: subtype Challenge");

	if (attr->checkcode &&
	    eap_aka_verify_checkcode(data, attr->checkcode,
				     attr->checkcode_len)) {
		wpa_printf(0, "EAP-AKA: Invalid AT_CHECKCODE in the "
			   "message");
		return eap_aka_client_error(data, id,
					    0);
	}

#line 821 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_aka.c"

	data->reauth = 0;
	if (!attr->mac || !attr->rand || !attr->autn) {
		wpa_printf(0, "EAP-AKA: Challenge message "
			   "did not include%s%s%s",
			   !attr->mac ? " AT_MAC" : "",
			   !attr->rand ? " AT_RAND" : "",
			   !attr->autn ? " AT_AUTN" : "");
		return eap_aka_client_error(data, id,
					    0);
	}
	os_memcpy(data->rand, attr->rand, 16);
	os_memcpy(data->autn, attr->autn, 16);

	res = eap_aka_umts_auth(sm, data);
	if (res == -1) {
		wpa_printf(0, "EAP-AKA: UMTS authentication "
			   "failed (AUTN)");
		return eap_aka_authentication_reject(data, id);
	} else if (res == -2) {
		wpa_printf(0, "EAP-AKA: UMTS authentication "
			   "failed (AUTN seq# -> AUTS)");
		return eap_aka_synchronization_failure(data, id);
	} else if (res) {
		wpa_printf(0, "EAP-AKA: UMTS authentication failed");
		return eap_aka_client_error(data, id,
					    0);
	}
#line 865 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eap_peer\\eap_aka.c"
	if (data->last_eap_identity) {
		identity = data->last_eap_identity;
		identity_len = data->last_eap_identity_len;
	} else if (data->pseudonym) {
		identity = data->pseudonym;
		identity_len = data->pseudonym_len;
	} else
		identity = eap_get_config_identity(sm, &identity_len);
	wpa_hexdump_ascii(0, "EAP-AKA: Selected identity for MK "
			  "derivation", identity, identity_len);
	if (data->eap_method == EAP_TYPE_AKA_PRIME) {
		eap_aka_prime_derive_keys(identity, identity_len, data->ik,
					  data->ck, data->k_encr, data->k_aut,
					  data->k_re, data->msk, data->emsk);
	} else {
		eap_aka_derive_mk(identity, identity_len, data->ik, data->ck,
				  data->mk);
		eap_sim_derive_keys(data->mk, data->k_encr, data->k_aut,
				    data->msk, data->emsk);
	}
	if (eap_aka_verify_mac(data, reqData, attr->mac, (unsigned char *) "", 0)) {
		wpa_printf(0, "EAP-AKA: Challenge message "
			   "used invalid AT_MAC");
		return eap_aka_client_error(data, id,
					    0);
	}

	

 
	eap_aka_clear_identities(data, 0x01 | 0x02 |
				 0x04);

	if (attr->encr_data) {
		unsigned char *decrypted;
		decrypted = eap_sim_parse_encr(data->k_encr, attr->encr_data,
					       attr->encr_data_len, attr->iv,
					       &eattr, 0);
		if (decrypted == 0) {
			return eap_aka_client_error(
				data, id, 0);
		}
		eap_aka_learn_ids(data, &eattr);
		os_free(decrypted);
	}

	if (data->result_ind && attr->result_ind)
		data->use_result_ind = 1;

	if (data->state != FAILURE && data->state != RESULT_FAILURE) {
		eap_aka_state(data, data->use_result_ind ?
			      RESULT_SUCCESS : SUCCESS);
	}

	data->num_id_req = 0;
	data->num_notification = 0;
	

 
	data->counter = 0;
	return eap_aka_response_challenge(data, id);
}


static int eap_aka_process_notification_reauth(struct eap_aka_data *data,
					       struct eap_sim_attrs *attr)
{
	struct eap_sim_attrs eattr;
	unsigned char *decrypted;

	if (attr->encr_data == 0 || attr->iv == 0) {
		wpa_printf(0, "EAP-AKA: Notification message after "
			   "reauth did not include encrypted data");
		return -1;
	}

	decrypted = eap_sim_parse_encr(data->k_encr, attr->encr_data,
				       attr->encr_data_len, attr->iv, &eattr,
				       0);
	if (decrypted == 0) {
		wpa_printf(0, "EAP-AKA: Failed to parse encrypted "
			   "data from notification message");
		return -1;
	}

	if (eattr.counter < 0 || (size_t) eattr.counter != data->counter) {
		wpa_printf(0, "EAP-AKA: Counter in notification "
			   "message does not match with counter in reauth "
			   "message");
		os_free(decrypted);
		return -1;
	}

	os_free(decrypted);
	return 0;
}


static int eap_aka_process_notification_auth(struct eap_aka_data *data,
					     const struct wpabuf *reqData,
					     struct eap_sim_attrs *attr)
{
	if (attr->mac == 0) {
		wpa_printf(0, "EAP-AKA: no AT_MAC in after_auth "
			   "Notification message");
		return -1;
	}

	if (eap_aka_verify_mac(data, reqData, attr->mac, (unsigned char *) "", 0)) {
		wpa_printf(0, "EAP-AKA: Notification message "
			   "used invalid AT_MAC");
		return -1;
	}

	if (data->reauth &&
	    eap_aka_process_notification_reauth(data, attr)) {
		wpa_printf(0, "EAP-AKA: Invalid notification "
			   "message after reauth");
		return -1;
	}

	return 0;
}


static struct wpabuf * eap_aka_process_notification(
	struct eap_sm *sm, struct eap_aka_data *data, unsigned char id,
	const struct wpabuf *reqData, struct eap_sim_attrs *attr)
{
	wpa_printf(0, "EAP-AKA: subtype Notification");
	if (data->num_notification > 0) {
		wpa_printf(0, "EAP-AKA: too many notification "
			   "rounds (only one allowed)");
		return eap_aka_client_error(data, id,
					    0);
	}
	data->num_notification++;
	if (attr->notification == -1) {
		wpa_printf(0, "EAP-AKA: no AT_NOTIFICATION in "
			   "Notification message");
		return eap_aka_client_error(data, id,
					    0);
	}

	if ((attr->notification & 0x4000) == 0 &&
	    eap_aka_process_notification_auth(data, reqData, attr)) {
		return eap_aka_client_error(data, id,
					    0);
	}

	eap_sim_report_notification(sm->msg_ctx, attr->notification, 1);
	if (attr->notification >= 0 && attr->notification < 32768) {
		eap_aka_state(data, FAILURE);
	} else if (attr->notification == 32768 &&
		   data->state == RESULT_SUCCESS)
		eap_aka_state(data, SUCCESS);
	return eap_aka_response_notification(data, id, attr->notification);
}


static struct wpabuf * eap_aka_process_reauthentication(
	struct eap_sm *sm, struct eap_aka_data *data, unsigned char id,
	const struct wpabuf *reqData, struct eap_sim_attrs *attr)
{
	struct eap_sim_attrs eattr;
	unsigned char *decrypted;

	wpa_printf(0, "EAP-AKA: subtype Reauthentication");

	if (attr->checkcode &&
	    eap_aka_verify_checkcode(data, attr->checkcode,
				     attr->checkcode_len)) {
		wpa_printf(0, "EAP-AKA: Invalid AT_CHECKCODE in the "
			   "message");
		return eap_aka_client_error(data, id,
					    0);
	}

	if (data->reauth_id == 0) {
		wpa_printf(0, "EAP-AKA: Server is trying "
			   "reauthentication, but no reauth_id available");
		return eap_aka_client_error(data, id,
					    0);
	}

	data->reauth = 1;
	if (eap_aka_verify_mac(data, reqData, attr->mac, (unsigned char *) "", 0)) {
		wpa_printf(0, "EAP-AKA: Reauthentication "
			   "did not have valid AT_MAC");
		return eap_aka_client_error(data, id,
					    0);
	}

	if (attr->encr_data == 0 || attr->iv == 0) {
		wpa_printf(0, "EAP-AKA: Reauthentication "
			   "message did not include encrypted data");
		return eap_aka_client_error(data, id,
					    0);
	}

	decrypted = eap_sim_parse_encr(data->k_encr, attr->encr_data,
				       attr->encr_data_len, attr->iv, &eattr,
				       0);
	if (decrypted == 0) {
		wpa_printf(0, "EAP-AKA: Failed to parse encrypted "
			   "data from reauthentication message");
		return eap_aka_client_error(data, id,
					    0);
	}

	if (eattr.nonce_s == 0 || eattr.counter < 0) {
		wpa_printf(0, "EAP-AKA: (encr) No%s%s in reauth packet",
			   !eattr.nonce_s ? " AT_NONCE_S" : "",
			   eattr.counter < 0 ? " AT_COUNTER" : "");
		os_free(decrypted);
		return eap_aka_client_error(data, id,
					    0);
	}

	if (eattr.counter < 0 || (size_t) eattr.counter <= data->counter) {
		struct wpabuf *res;
		wpa_printf(0, "EAP-AKA: (encr) Invalid counter "
			   "(%d <= %d)", eattr.counter, data->counter);
		data->counter_too_small = eattr.counter;

		



 
		os_free(data->last_eap_identity);
		data->last_eap_identity = data->reauth_id;
		data->last_eap_identity_len = data->reauth_id_len;
		data->reauth_id = 0;
		data->reauth_id_len = 0;

		res = eap_aka_response_reauth(data, id, 1, eattr.nonce_s);
		os_free(decrypted);

		return res;
	}
	data->counter = eattr.counter;

	os_memcpy(data->nonce_s, eattr.nonce_s, 16);
	wpa_hexdump(0, "EAP-AKA: (encr) AT_NONCE_S",
		    data->nonce_s, 16);

	if (data->eap_method == EAP_TYPE_AKA_PRIME) {
		eap_aka_prime_derive_keys_reauth(data->k_re, data->counter,
						 data->reauth_id,
						 data->reauth_id_len,
						 data->nonce_s,
						 data->msk, data->emsk);
	} else {
		eap_sim_derive_keys_reauth(data->counter, data->reauth_id,
					   data->reauth_id_len,
					   data->nonce_s, data->mk,
					   data->msk, data->emsk);
	}
	eap_aka_clear_identities(data, 0x02 | 0x04);
	eap_aka_learn_ids(data, &eattr);

	if (data->result_ind && attr->result_ind)
		data->use_result_ind = 1;

	if (data->state != FAILURE && data->state != RESULT_FAILURE) {
		eap_aka_state(data, data->use_result_ind ?
			      RESULT_SUCCESS : SUCCESS);
	}

	data->num_id_req = 0;
	data->num_notification = 0;
	if (data->counter > 1000) {
		wpa_printf(0, "EAP-AKA: Maximum number of "
			   "fast reauths performed - force fullauth");
		eap_aka_clear_identities(data, 0x02 | 0x04);
	}
	os_free(decrypted);
	return eap_aka_response_reauth(data, id, 0, data->nonce_s);
}


static struct wpabuf * eap_aka_process(struct eap_sm *sm, void *priv,
				       struct eap_method_ret *ret,
				       const struct wpabuf *reqData)
{
	struct eap_aka_data *data = priv;
	const struct eap_hdr *req;
	unsigned char subtype, id;
	struct wpabuf *res;
	const unsigned char *pos;
	struct eap_sim_attrs attr;
	size_t len;

	wpa_hexdump_buf(0, "EAP-AKA: EAP data", reqData);
	if (eap_get_config_identity(sm, &len) == 0) {
		wpa_printf(0, "EAP-AKA: Identity not configured");
		eap_sm_request_identity(sm);
		ret->ignore = 1;
		return 0;
	}

	pos = eap_hdr_validate(EAP_VENDOR_IETF, data->eap_method, reqData,
			       &len);
	if (pos == 0 || len < 1) {
		ret->ignore = 1;
		return 0;
	}
	req = wpabuf_head(reqData);
	id = req->identifier;
	len = ((((unsigned short) ((unsigned short) (unsigned short) (req->length)) << 8) & 0xff00) | (((unsigned short) ((unsigned short) (unsigned short) (req->length)) >> 8) & 0xff));

	ret->ignore = 0;
	ret->methodState = METHOD_MAY_CONT;
	ret->decision = DECISION_FAIL;
	ret->allowNotifications = 1;

	subtype = *pos++;
	wpa_printf(0, "EAP-AKA: Subtype=%d", subtype);
	pos += 2;  

	if (eap_sim_parse_attr(pos, wpabuf_head_u8(reqData) + len, &attr,
			       data->eap_method == EAP_TYPE_AKA_PRIME ? 2 : 1,
			       0)) {
		res = eap_aka_client_error(data, id,
					   0);
		goto done;
	}

	switch (subtype) {
	case 5:
		res = eap_aka_process_identity(sm, data, id, reqData, &attr);
		break;
	case 1:
		res = eap_aka_process_challenge(sm, data, id, reqData, &attr);
		break;
	case 12:
		res = eap_aka_process_notification(sm, data, id, reqData,
						   &attr);
		break;
	case 13:
		res = eap_aka_process_reauthentication(sm, data, id, reqData,
						       &attr);
		break;
	case 14:
		wpa_printf(0, "EAP-AKA: subtype Client-Error");
		res = eap_aka_client_error(data, id,
					   0);
		break;
	default:
		wpa_printf(0, "EAP-AKA: Unknown subtype=%d", subtype);
		res = eap_aka_client_error(data, id,
					   0);
		break;
	}

done:
	if (data->state == FAILURE) {
		ret->decision = DECISION_FAIL;
		ret->methodState = METHOD_DONE;
	} else if (data->state == SUCCESS) {
		ret->decision = data->use_result_ind ?
			DECISION_UNCOND_SUCC : DECISION_COND_SUCC;
		



 
		ret->methodState = data->use_result_ind ?
			METHOD_DONE : METHOD_MAY_CONT;
	} else if (data->state == RESULT_FAILURE)
		ret->methodState = METHOD_CONT;
	else if (data->state == RESULT_SUCCESS)
		ret->methodState = METHOD_CONT;

	if (ret->methodState == METHOD_DONE) {
		ret->allowNotifications = 0;
	}

	return res;
}


static int eap_aka_has_reauth_data(struct eap_sm *sm, void *priv)
{
	struct eap_aka_data *data = priv;
	return data->pseudonym || data->reauth_id;
}


static void eap_aka_deinit_for_reauth(struct eap_sm *sm, void *priv)
{
	struct eap_aka_data *data = priv;
	eap_aka_clear_identities(data, 0x04);
	data->prev_id = -1;
	wpabuf_free(data->id_msgs);
	data->id_msgs = 0;
	data->use_result_ind = 0;
	data->kdf_negotiation = 0;
}


static void * eap_aka_init_for_reauth(struct eap_sm *sm, void *priv)
{
	struct eap_aka_data *data = priv;
	data->num_id_req = 0;
	data->num_notification = 0;
	eap_aka_state(data, CONTINUE);
	return priv;
}


static const unsigned char * eap_aka_get_identity(struct eap_sm *sm, void *priv,
				       size_t *len)
{
	struct eap_aka_data *data = priv;

	if (data->reauth_id) {
		*len = data->reauth_id_len;
		return data->reauth_id;
	}

	if (data->pseudonym) {
		*len = data->pseudonym_len;
		return data->pseudonym;
	}

	return 0;
}


static int eap_aka_isKeyAvailable(struct eap_sm *sm, void *priv)
{
	struct eap_aka_data *data = priv;
	return data->state == SUCCESS;
}


static unsigned char * eap_aka_getKey(struct eap_sm *sm, void *priv, size_t *len)
{
	struct eap_aka_data *data = priv;
	unsigned char *key;

	if (data->state != SUCCESS)
		return 0;

	key = os_malloc(64);
	if (key == 0)
		return 0;

	*len = 64;
	os_memcpy(key, data->msk, 64);

	return key;
}


static unsigned char * eap_aka_get_emsk(struct eap_sm *sm, void *priv, size_t *len)
{
	struct eap_aka_data *data = priv;
	unsigned char *key;

	if (data->state != SUCCESS)
		return 0;

	key = os_malloc(64);
	if (key == 0)
		return 0;

	*len = 64;
	os_memcpy(key, data->emsk, 64);

	return key;
}


int eap_peer_aka_register(void)
{
	struct eap_method *eap;
	int ret;

	eap = eap_peer_method_alloc(1,
				    EAP_VENDOR_IETF, EAP_TYPE_AKA, "AKA");
	if (eap == 0)
		return -1;

	eap->init = eap_aka_init;
	eap->deinit = eap_aka_deinit;
	eap->process = eap_aka_process;
	eap->isKeyAvailable = eap_aka_isKeyAvailable;
	eap->getKey = eap_aka_getKey;
	eap->has_reauth_data = eap_aka_has_reauth_data;
	eap->deinit_for_reauth = eap_aka_deinit_for_reauth;
	eap->init_for_reauth = eap_aka_init_for_reauth;
	eap->get_identity = eap_aka_get_identity;
	eap->get_emsk = eap_aka_get_emsk;

	ret = eap_peer_method_register(eap);
	if (ret)
		eap_peer_method_free(eap);
	return ret;
}


