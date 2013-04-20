#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eapol_supp\\eapol_supp_sm.c"












 

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

#line 16 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eapol_supp\\eapol_supp_sm.c"

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



#line 18 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eapol_supp\\eapol_supp_sm.c"
#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\state_machine.h"























 












 













 
#line 59 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\state_machine.h"











 
#line 78 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\state_machine.h"










 
#line 97 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\state_machine.h"









 












 











 









 


#line 19 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eapol_supp\\eapol_supp_sm.c"
#line 20 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eapol_supp\\eapol_supp_sm.c"
#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\utils\\eloop.h"




















 






 







 
typedef enum {
	EVENT_TYPE_READ = 0,
	EVENT_TYPE_WRITE,
	EVENT_TYPE_EXCEPTION
} eloop_event_type;






 
typedef void (*eloop_sock_handler)(int sock, void *eloop_ctx, void *sock_ctx);





 
typedef void (*eloop_event_handler)(void *eloop_data, void *user_ctx);





 
typedef void (*eloop_timeout_handler)(void *eloop_data, void *user_ctx);







 
typedef void (*eloop_signal_handler)(int sig, void *signal_ctx);






 
int eloop_init(void);














 
int eloop_register_read_sock(int sock, eloop_sock_handler handler,
			     void *eloop_data, void *user_data);







 
void eloop_unregister_read_sock(int sock);















 
int eloop_register_sock(int sock, eloop_event_type type,
			eloop_sock_handler handler,
			void *eloop_data, void *user_data);








 
void eloop_unregister_sock(int sock, eloop_event_type type);






















 
int eloop_register_event(void *event, size_t event_size,
			 eloop_event_handler handler,
			 void *eloop_data, void *user_data);








 
void eloop_unregister_event(void *event, size_t event_size);












 
int eloop_register_timeout(unsigned int secs, unsigned int usecs,
			   eloop_timeout_handler handler,
			   void *eloop_data, void *user_data);











 
int eloop_cancel_timeout(eloop_timeout_handler handler,
			 void *eloop_data, void *user_data);










 
int eloop_is_timeout_registered(eloop_timeout_handler handler,
				void *eloop_data, void *user_data);













 
int eloop_register_signal(int sig, eloop_signal_handler handler,
			  void *user_data);

















 
int eloop_register_signal_terminate(eloop_signal_handler handler,
				    void *user_data);

















 
int eloop_register_signal_reconfig(eloop_signal_handler handler,
				   void *user_data);







 
void eloop_run(void);






 
void eloop_terminate(void);






 
void eloop_destroy(void);









 
int eloop_terminated(void);






 
void eloop_wait_for_read_sock(int sock);

#line 21 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eapol_supp\\eapol_supp_sm.c"
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

#line 22 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eapol_supp\\eapol_supp_sm.c"
#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\crypto/md5.h"












 






int hmac_md5_vector(const unsigned char *key, size_t key_len, size_t num_elem,
		    const unsigned char *addr[], const size_t *len, unsigned char *mac);
int hmac_md5(const unsigned char *key, size_t key_len, const unsigned char *data, size_t data_len,
	     unsigned char *mac);
#line 34 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\crypto/md5.h"

#line 23 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eapol_supp\\eapol_supp_sm.c"
#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\common/eapol_common.h"












 




 








#pragma pack(push, 1)

struct ieee802_1x_hdr {
	unsigned char version;
	unsigned char type;
	unsigned short length;
	 
};

#pragma pack(pop)







enum { IEEE802_1X_TYPE_EAP_PACKET = 0,
       IEEE802_1X_TYPE_EAPOL_START = 1,
       IEEE802_1X_TYPE_EAPOL_LOGOFF = 2,
       IEEE802_1X_TYPE_EAPOL_KEY = 3,
       IEEE802_1X_TYPE_EAPOL_ENCAPSULATED_ASF_ALERT = 4
};

enum { EAPOL_KEY_TYPE_RC4 = 1, EAPOL_KEY_TYPE_RSN = 2,
       EAPOL_KEY_TYPE_WPA = 254 };

#line 24 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eapol_supp\\eapol_supp_sm.c"
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



#line 25 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eapol_supp\\eapol_supp_sm.c"
#line 1 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eapol_supp\\eapol_supp_sm.h"












 




#line 19 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eapol_supp\\eapol_supp_sm.h"

typedef enum { Unauthorized, Authorized } PortStatus;
typedef enum { Auto, ForceUnauthorized, ForceAuthorized } PortControl;



 
struct eapol_config {
	






 
	int accept_802_1x_keys;



	





 
	int required_keys;

	

 
	int fast_reauth;

	

 
	unsigned int workaround;

	

 
	int eap_disabled;
};

struct eapol_sm;
struct wpa_config_blob;



 
struct eapol_ctx {
	

 
	void *ctx;

	




 
	int preauth;

	









 
	void (*cb)(struct eapol_sm *eapol, int success, void *ctx);

	

 
	void *cb_ctx;

	

 
	void *msg_ctx;

	



 
	void *scard_ctx;

	

 
	void *eapol_send_ctx;

	






 
	void (*eapol_done_cb)(void *ctx);

	






 
	int (*eapol_send)(void *ctx, int type, const unsigned char *buf, size_t len);

	







 
	int (*set_wep_key)(void *ctx, int unicast, int keyidx,
			   const unsigned char *key, size_t keylen);

	






 
	void (*set_config_blob)(void *ctx, struct wpa_config_blob *blob);

	




 
	const struct wpa_config_blob * (*get_config_blob)(void *ctx,
							  const char *name);

	


 
	void (*aborted_cached)(void *ctx);

	




 
	const char *opensc_engine_path;

	




 
	const char *pkcs11_engine_path;

	





 
	const char *pkcs11_module_path;

	



 
	struct wps_context *wps;

	




 
	void (*eap_param_needed)(void *ctx, const char *field,
				 const char *txt);

	



 
	void (*port_cb)(void *ctx, int authorized);
};


struct eap_peer_config;


struct eapol_sm *eapol_sm_init(struct eapol_ctx *ctx);
void eapol_sm_deinit(struct eapol_sm *sm);
void eapol_sm_step(struct eapol_sm *sm);
int eapol_sm_get_status(struct eapol_sm *sm, char *buf, size_t buflen,
			int verbose);
int eapol_sm_get_mib(struct eapol_sm *sm, char *buf, size_t buflen);
void eapol_sm_configure(struct eapol_sm *sm, int heldPeriod, int authPeriod,
			int startPeriod, int maxStart);
int eapol_sm_rx_eapol(struct eapol_sm *sm, const unsigned char *src, const unsigned char *buf,
		      size_t len);
void eapol_sm_notify_tx_eapol_key(struct eapol_sm *sm);
void eapol_sm_notify_portEnabled(struct eapol_sm *sm, int enabled);
void eapol_sm_notify_portValid(struct eapol_sm *sm, int valid);
void eapol_sm_notify_eap_success(struct eapol_sm *sm, int success);
void eapol_sm_notify_eap_fail(struct eapol_sm *sm, int fail);
void eapol_sm_notify_config(struct eapol_sm *sm,
			    struct eap_peer_config *config,
			    const struct eapol_config *conf);
int eapol_sm_get_key(struct eapol_sm *sm, unsigned char *key, size_t len);
void eapol_sm_notify_logoff(struct eapol_sm *sm, int logoff);
void eapol_sm_notify_cached(struct eapol_sm *sm);
void eapol_sm_notify_pmkid_attempt(struct eapol_sm *sm, int attempt);
void eapol_sm_register_scard_ctx(struct eapol_sm *sm, void *ctx);
void eapol_sm_notify_portControl(struct eapol_sm *sm, PortControl portControl);
void eapol_sm_notify_ctrl_attached(struct eapol_sm *sm);
void eapol_sm_notify_ctrl_response(struct eapol_sm *sm);
void eapol_sm_request_reauth(struct eapol_sm *sm);
void eapol_sm_notify_lower_layer_success(struct eapol_sm *sm, int in_eapol_sm);
void eapol_sm_invalidate_cached_session(struct eapol_sm *sm);
#line 346 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eapol_supp\\eapol_supp_sm.h"

#line 26 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eapol_supp\\eapol_supp_sm.c"





 



 
struct eapol_sm {
	 
	unsigned int authWhile;
	unsigned int heldWhile;
	unsigned int startWhen;
	unsigned int idleWhile;  
	int timer_tick_enabled;

	 
	int eapFail;
	int eapolEap;
	int eapSuccess;
	int initialize;
	int keyDone;
	int keyRun;
	PortControl portControl;
	int portEnabled;
	PortStatus suppPortStatus;   
	int portValid;
	int suppAbort;
	int suppFail;
	int suppStart;
	int suppSuccess;
	int suppTimeout;

	 
	enum {
		SUPP_PAE_UNKNOWN = 0,
		SUPP_PAE_DISCONNECTED = 1,
		SUPP_PAE_LOGOFF = 2,
		SUPP_PAE_CONNECTING = 3,
		SUPP_PAE_AUTHENTICATING = 4,
		SUPP_PAE_AUTHENTICATED = 5,
		 
		SUPP_PAE_HELD = 7,
		SUPP_PAE_RESTART = 8,
		SUPP_PAE_S_FORCE_AUTH = 9,
		SUPP_PAE_S_FORCE_UNAUTH = 10
	} SUPP_PAE_state;  
	 
	int userLogoff;
	int logoffSent;
	unsigned int startCount;
	int eapRestart;
	PortControl sPortMode;
	 
	unsigned int heldPeriod;  
	unsigned int startPeriod;  
	unsigned int maxStart;  

	 
	enum {
		KEY_RX_UNKNOWN = 0,
		KEY_RX_NO_KEY_RECEIVE, KEY_RX_KEY_RECEIVE
	} KEY_RX_state;
	 
	int rxKey;

	 
	enum {
		SUPP_BE_UNKNOWN = 0,
		SUPP_BE_INITIALIZE = 1,
		SUPP_BE_IDLE = 2,
		SUPP_BE_REQUEST = 3,
		SUPP_BE_RECEIVE = 4,
		SUPP_BE_RESPONSE = 5,
		SUPP_BE_FAIL = 6,
		SUPP_BE_TIMEOUT = 7, 
		SUPP_BE_SUCCESS = 8
	} SUPP_BE_state;  
	 
	int eapNoResp;
	int eapReq;
	int eapResp;
	 
	unsigned int authPeriod;  

	 
	unsigned int dot1xSuppEapolFramesRx;
	unsigned int dot1xSuppEapolFramesTx;
	unsigned int dot1xSuppEapolStartFramesTx;
	unsigned int dot1xSuppEapolLogoffFramesTx;
	unsigned int dot1xSuppEapolRespFramesTx;
	unsigned int dot1xSuppEapolReqIdFramesRx;
	unsigned int dot1xSuppEapolReqFramesRx;
	unsigned int dot1xSuppInvalidEapolFramesRx;
	unsigned int dot1xSuppEapLengthErrorFramesRx;
	unsigned int dot1xSuppLastEapolFrameVersion;
	unsigned char dot1xSuppLastEapolFrameSource[6];

	 
	int changed;
	struct eap_sm *eap;
	struct eap_peer_config *config;
	int initial_req;
	unsigned char *last_rx_key;
	size_t last_rx_key_len;
	struct wpabuf *eapReqData;  
	int altAccept;  
	int altReject;  
	int replay_counter_valid;
	unsigned char last_replay_counter[16];
	struct eapol_config conf;
	struct eapol_ctx *ctx;
	enum { EAPOL_CB_IN_PROGRESS = 0, EAPOL_CB_SUCCESS, EAPOL_CB_FAILURE }
		cb_status;
	int cached_pmk;

	int unicast_key_received, broadcast_key_received;
};













struct ieee802_1x_eapol_key {
	unsigned char type;
	 
	unsigned char key_length[2];
	
 
	unsigned char replay_counter[8];
	unsigned char key_iv[16];  
	unsigned char key_index; 


 
	
 
	unsigned char key_signature[16];

	




 
} ;






static void eapol_sm_txLogoff(struct eapol_sm *sm);
static void eapol_sm_txStart(struct eapol_sm *sm);
static void eapol_sm_processKey(struct eapol_sm *sm);
static void eapol_sm_getSuppRsp(struct eapol_sm *sm);
static void eapol_sm_txSuppRsp(struct eapol_sm *sm);
static void eapol_sm_abortSupp(struct eapol_sm *sm);
static void eapol_sm_abort_cached(struct eapol_sm *sm);
static void eapol_sm_step_timeout(void *eloop_ctx, void *timeout_ctx);
static void eapol_sm_set_port_authorized(struct eapol_sm *sm);
static void eapol_sm_set_port_unauthorized(struct eapol_sm *sm);



 
static void eapol_port_timers_tick(void *eloop_ctx, void *timeout_ctx)
{
	struct eapol_sm *sm = timeout_ctx;

	if (sm->authWhile > 0) {
		sm->authWhile--;
		if (sm->authWhile == 0)
			wpa_printf(0, "EAPOL: authWhile --> 0");
	}
	if (sm->heldWhile > 0) {
		sm->heldWhile--;
		if (sm->heldWhile == 0)
			wpa_printf(0, "EAPOL: heldWhile --> 0");
	}
	if (sm->startWhen > 0) {
		sm->startWhen--;
		if (sm->startWhen == 0)
			wpa_printf(0, "EAPOL: startWhen --> 0");
	}
	if (sm->idleWhile > 0) {
		sm->idleWhile--;
		if (sm->idleWhile == 0)
			wpa_printf(0, "EAPOL: idleWhile --> 0");
	}

	if (sm->authWhile | sm->heldWhile | sm->startWhen | sm->idleWhile) {
		eloop_register_timeout(1, 0, eapol_port_timers_tick, eloop_ctx,
				       sm);
	} else {
		wpa_printf(0, "EAPOL: disable timer tick");
		sm->timer_tick_enabled = 0;
	}
	eapol_sm_step(sm);
}


static void eapol_enable_timer_tick(struct eapol_sm *sm)
{
	if (sm->timer_tick_enabled)
		return;
	wpa_printf(0, "EAPOL: enable timer tick");
	sm->timer_tick_enabled = 1;
	eloop_cancel_timeout(eapol_port_timers_tick, 0, sm);
	eloop_register_timeout(1, 0, eapol_port_timers_tick, 0, sm);
}


static void sm_SUPP_PAE_LOGOFF_Enter(struct eapol_sm *sm, int global)
{
	if (!global || sm->SUPP_PAE_state != SUPP_PAE_LOGOFF) { sm->changed = 1; wpa_printf(0, "EAPOL" ": " "SUPP_PAE" " entering state " "LOGOFF"); } sm->SUPP_PAE_state = SUPP_PAE_LOGOFF;;
	eapol_sm_txLogoff(sm);
	sm->logoffSent = 1;
	sm->suppPortStatus = Unauthorized;
	eapol_sm_set_port_unauthorized(sm);
}


static void sm_SUPP_PAE_DISCONNECTED_Enter(struct eapol_sm *sm, int global)
{
	if (!global || sm->SUPP_PAE_state != SUPP_PAE_DISCONNECTED) { sm->changed = 1; wpa_printf(0, "EAPOL" ": " "SUPP_PAE" " entering state " "DISCONNECTED"); } sm->SUPP_PAE_state = SUPP_PAE_DISCONNECTED;;
	sm->sPortMode = Auto;
	sm->startCount = 0;
	sm->logoffSent = 0;
	sm->suppPortStatus = Unauthorized;
	eapol_sm_set_port_unauthorized(sm);
	sm->suppAbort = 1;

	sm->unicast_key_received = 0;
	sm->broadcast_key_received = 0;
}


static void sm_SUPP_PAE_CONNECTING_Enter(struct eapol_sm *sm, int global)
{
	int send_start = sm->SUPP_PAE_state == SUPP_PAE_CONNECTING;
	if (!global || sm->SUPP_PAE_state != SUPP_PAE_CONNECTING) { sm->changed = 1; wpa_printf(0, "EAPOL" ": " "SUPP_PAE" " entering state " "CONNECTING"); } sm->SUPP_PAE_state = SUPP_PAE_CONNECTING;;
	if (send_start) {
		sm->startWhen = sm->startPeriod;
		sm->startCount++;
	} else {
		





 




		sm->startWhen = 3;

	}
	eapol_enable_timer_tick(sm);
	sm->eapolEap = 0;
	if (send_start)
		eapol_sm_txStart(sm);
}


static void sm_SUPP_PAE_AUTHENTICATING_Enter(struct eapol_sm *sm, int global)
{
	if (!global || sm->SUPP_PAE_state != SUPP_PAE_AUTHENTICATING) { sm->changed = 1; wpa_printf(0, "EAPOL" ": " "SUPP_PAE" " entering state " "AUTHENTICATING"); } sm->SUPP_PAE_state = SUPP_PAE_AUTHENTICATING;;
	sm->startCount = 0;
	sm->suppSuccess = 0;
	sm->suppFail = 0;
	sm->suppTimeout = 0;
	sm->keyRun = 0;
	sm->keyDone = 0;
	sm->suppStart = 1;
}


static void sm_SUPP_PAE_HELD_Enter(struct eapol_sm *sm, int global)
{
	if (!global || sm->SUPP_PAE_state != SUPP_PAE_HELD) { sm->changed = 1; wpa_printf(0, "EAPOL" ": " "SUPP_PAE" " entering state " "HELD"); } sm->SUPP_PAE_state = SUPP_PAE_HELD;;
	sm->heldWhile = sm->heldPeriod;
	eapol_enable_timer_tick(sm);
	sm->suppPortStatus = Unauthorized;
	eapol_sm_set_port_unauthorized(sm);
	sm->cb_status = EAPOL_CB_FAILURE;
}


static void sm_SUPP_PAE_AUTHENTICATED_Enter(struct eapol_sm *sm, int global)
{
	if (!global || sm->SUPP_PAE_state != SUPP_PAE_AUTHENTICATED) { sm->changed = 1; wpa_printf(0, "EAPOL" ": " "SUPP_PAE" " entering state " "AUTHENTICATED"); } sm->SUPP_PAE_state = SUPP_PAE_AUTHENTICATED;;
	sm->suppPortStatus = Authorized;
	eapol_sm_set_port_authorized(sm);
	sm->cb_status = EAPOL_CB_SUCCESS;
}


static void sm_SUPP_PAE_RESTART_Enter(struct eapol_sm *sm, int global)
{
	if (!global || sm->SUPP_PAE_state != SUPP_PAE_RESTART) { sm->changed = 1; wpa_printf(0, "EAPOL" ": " "SUPP_PAE" " entering state " "RESTART"); } sm->SUPP_PAE_state = SUPP_PAE_RESTART;;
	sm->eapRestart = 1;
}


static void sm_SUPP_PAE_S_FORCE_AUTH_Enter(struct eapol_sm *sm, int global)
{
	if (!global || sm->SUPP_PAE_state != SUPP_PAE_S_FORCE_AUTH) { sm->changed = 1; wpa_printf(0, "EAPOL" ": " "SUPP_PAE" " entering state " "S_FORCE_AUTH"); } sm->SUPP_PAE_state = SUPP_PAE_S_FORCE_AUTH;;
	sm->suppPortStatus = Authorized;
	eapol_sm_set_port_authorized(sm);
	sm->sPortMode = ForceAuthorized;
}


static void sm_SUPP_PAE_S_FORCE_UNAUTH_Enter(struct eapol_sm *sm, int global)
{
	if (!global || sm->SUPP_PAE_state != SUPP_PAE_S_FORCE_UNAUTH) { sm->changed = 1; wpa_printf(0, "EAPOL" ": " "SUPP_PAE" " entering state " "S_FORCE_UNAUTH"); } sm->SUPP_PAE_state = SUPP_PAE_S_FORCE_UNAUTH;;
	sm->suppPortStatus = Unauthorized;
	eapol_sm_set_port_unauthorized(sm);
	sm->sPortMode = ForceUnauthorized;
	eapol_sm_txLogoff(sm);
}


static void sm_SUPP_PAE_Step(struct eapol_sm *sm)
{
	if ((sm->userLogoff && !sm->logoffSent) &&
	    !(sm->initialize || !sm->portEnabled))
		sm_SUPP_PAE_LOGOFF_Enter(sm, 1);
	else if (((sm->portControl == Auto) &&
		  (sm->sPortMode != sm->portControl)) ||
		 sm->initialize || !sm->portEnabled)
		sm_SUPP_PAE_DISCONNECTED_Enter(sm, 1);
	else if ((sm->portControl == ForceAuthorized) &&
		 (sm->sPortMode != sm->portControl) &&
		 !(sm->initialize || !sm->portEnabled))
		sm_SUPP_PAE_S_FORCE_AUTH_Enter(sm, 1);
	else if ((sm->portControl == ForceUnauthorized) &&
		 (sm->sPortMode != sm->portControl) &&
		 !(sm->initialize || !sm->portEnabled))
		sm_SUPP_PAE_S_FORCE_UNAUTH_Enter(sm, 1);
	else switch (sm->SUPP_PAE_state) {
	case SUPP_PAE_UNKNOWN:
		break;
	case SUPP_PAE_LOGOFF:
		if (!sm->userLogoff)
			sm_SUPP_PAE_DISCONNECTED_Enter(sm, 0);
		break;
	case SUPP_PAE_DISCONNECTED:
		sm_SUPP_PAE_CONNECTING_Enter(sm, 0);
		break;
	case SUPP_PAE_CONNECTING:
		if (sm->startWhen == 0 && sm->startCount < sm->maxStart)
			sm_SUPP_PAE_CONNECTING_Enter(sm, 0);
		else if (sm->startWhen == 0 &&
			 sm->startCount >= sm->maxStart &&
			 sm->portValid)
			sm_SUPP_PAE_AUTHENTICATED_Enter(sm, 0);
		else if (sm->eapSuccess || sm->eapFail)
			sm_SUPP_PAE_AUTHENTICATING_Enter(sm, 0);
		else if (sm->eapolEap)
			sm_SUPP_PAE_RESTART_Enter(sm, 0);
		else if (sm->startWhen == 0 &&
			 sm->startCount >= sm->maxStart &&
			 !sm->portValid)
			sm_SUPP_PAE_HELD_Enter(sm, 0);
		break;
	case SUPP_PAE_AUTHENTICATING:
		if (sm->eapSuccess && !sm->portValid &&
		    sm->conf.accept_802_1x_keys &&
		    sm->conf.required_keys == 0) {
			wpa_printf(0, "EAPOL: IEEE 802.1X for "
				   "plaintext connection; no EAPOL-Key frames "
				   "required");
			sm->portValid = 1;
			if (sm->ctx->eapol_done_cb)
				sm->ctx->eapol_done_cb(sm->ctx->ctx);
		}
		if (sm->eapSuccess && sm->portValid)
			sm_SUPP_PAE_AUTHENTICATED_Enter(sm, 0);
		else if (sm->eapFail || (sm->keyDone && !sm->portValid))
			sm_SUPP_PAE_HELD_Enter(sm, 0);
		else if (sm->suppTimeout)
			sm_SUPP_PAE_CONNECTING_Enter(sm, 0);
		break;
	case SUPP_PAE_HELD:
		if (sm->heldWhile == 0)
			sm_SUPP_PAE_CONNECTING_Enter(sm, 0);
		else if (sm->eapolEap)
			sm_SUPP_PAE_RESTART_Enter(sm, 0);
		break;
	case SUPP_PAE_AUTHENTICATED:
		if (sm->eapolEap && sm->portValid)
			sm_SUPP_PAE_RESTART_Enter(sm, 0);
		else if (!sm->portValid)
			sm_SUPP_PAE_DISCONNECTED_Enter(sm, 0);
		break;
	case SUPP_PAE_RESTART:
		if (!sm->eapRestart)
			sm_SUPP_PAE_AUTHENTICATING_Enter(sm, 0);
		break;
	case SUPP_PAE_S_FORCE_AUTH:
		break;
	case SUPP_PAE_S_FORCE_UNAUTH:
		break;
	}
}


static void sm_KEY_RX_NO_KEY_RECEIVE_Enter(struct eapol_sm *sm, int global)
{
	if (!global || sm->KEY_RX_state != KEY_RX_NO_KEY_RECEIVE) { sm->changed = 1; wpa_printf(0, "EAPOL" ": " "KEY_RX" " entering state " "NO_KEY_RECEIVE"); } sm->KEY_RX_state = KEY_RX_NO_KEY_RECEIVE;;
}


static void sm_KEY_RX_KEY_RECEIVE_Enter(struct eapol_sm *sm, int global)
{
	if (!global || sm->KEY_RX_state != KEY_RX_KEY_RECEIVE) { sm->changed = 1; wpa_printf(0, "EAPOL" ": " "KEY_RX" " entering state " "KEY_RECEIVE"); } sm->KEY_RX_state = KEY_RX_KEY_RECEIVE;;
	eapol_sm_processKey(sm);
	sm->rxKey = 0;
}


static void sm_KEY_RX_Step(struct eapol_sm *sm)
{
	if (sm->initialize || !sm->portEnabled)
		sm_KEY_RX_NO_KEY_RECEIVE_Enter(sm, 1);
	switch (sm->KEY_RX_state) {
	case KEY_RX_UNKNOWN:
		break;
	case KEY_RX_NO_KEY_RECEIVE:
		if (sm->rxKey)
			sm_KEY_RX_KEY_RECEIVE_Enter(sm, 0);
		break;
	case KEY_RX_KEY_RECEIVE:
		if (sm->rxKey)
			sm_KEY_RX_KEY_RECEIVE_Enter(sm, 0);
		break;
	}
}


static void sm_SUPP_BE_REQUEST_Enter(struct eapol_sm *sm, int global)
{
	if (!global || sm->SUPP_BE_state != SUPP_BE_REQUEST) { sm->changed = 1; wpa_printf(0, "EAPOL" ": " "SUPP_BE" " entering state " "REQUEST"); } sm->SUPP_BE_state = SUPP_BE_REQUEST;;
	sm->authWhile = 0;
	sm->eapReq = 1;
	eapol_sm_getSuppRsp(sm);
}


static void sm_SUPP_BE_RESPONSE_Enter(struct eapol_sm *sm, int global)
{
	if (!global || sm->SUPP_BE_state != SUPP_BE_RESPONSE) { sm->changed = 1; wpa_printf(0, "EAPOL" ": " "SUPP_BE" " entering state " "RESPONSE"); } sm->SUPP_BE_state = SUPP_BE_RESPONSE;;
	eapol_sm_txSuppRsp(sm);
	sm->eapResp = 0;
}


static void sm_SUPP_BE_SUCCESS_Enter(struct eapol_sm *sm, int global)
{
	if (!global || sm->SUPP_BE_state != SUPP_BE_SUCCESS) { sm->changed = 1; wpa_printf(0, "EAPOL" ": " "SUPP_BE" " entering state " "SUCCESS"); } sm->SUPP_BE_state = SUPP_BE_SUCCESS;;
	sm->keyRun = 1;
	sm->suppSuccess = 1;

	if (eap_key_available(sm->eap)) {
		
 
		sm->replay_counter_valid = 0;
	}
}


static void sm_SUPP_BE_FAIL_Enter(struct eapol_sm *sm, int global)
{
	if (!global || sm->SUPP_BE_state != SUPP_BE_FAIL) { sm->changed = 1; wpa_printf(0, "EAPOL" ": " "SUPP_BE" " entering state " "FAIL"); } sm->SUPP_BE_state = SUPP_BE_FAIL;;
	sm->suppFail = 1;
}


static void sm_SUPP_BE_TIMEOUT_Enter(struct eapol_sm *sm, int global)
{
	if (!global || sm->SUPP_BE_state != SUPP_BE_TIMEOUT) { sm->changed = 1; wpa_printf(0, "EAPOL" ": " "SUPP_BE" " entering state " "TIMEOUT"); } sm->SUPP_BE_state = SUPP_BE_TIMEOUT;;
	sm->suppTimeout = 1;
}


static void sm_SUPP_BE_IDLE_Enter(struct eapol_sm *sm, int global)
{
	if (!global || sm->SUPP_BE_state != SUPP_BE_IDLE) { sm->changed = 1; wpa_printf(0, "EAPOL" ": " "SUPP_BE" " entering state " "IDLE"); } sm->SUPP_BE_state = SUPP_BE_IDLE;;
	sm->suppStart = 0;
	sm->initial_req = 1;
}


static void sm_SUPP_BE_INITIALIZE_Enter(struct eapol_sm *sm, int global)
{
	if (!global || sm->SUPP_BE_state != SUPP_BE_INITIALIZE) { sm->changed = 1; wpa_printf(0, "EAPOL" ": " "SUPP_BE" " entering state " "INITIALIZE"); } sm->SUPP_BE_state = SUPP_BE_INITIALIZE;;
	eapol_sm_abortSupp(sm);
	sm->suppAbort = 0;
}


static void sm_SUPP_BE_RECEIVE_Enter(struct eapol_sm *sm, int global)
{
	if (!global || sm->SUPP_BE_state != SUPP_BE_RECEIVE) { sm->changed = 1; wpa_printf(0, "EAPOL" ": " "SUPP_BE" " entering state " "RECEIVE"); } sm->SUPP_BE_state = SUPP_BE_RECEIVE;;
	sm->authWhile = sm->authPeriod;
	eapol_enable_timer_tick(sm);
	sm->eapolEap = 0;
	sm->eapNoResp = 0;
	sm->initial_req = 0;
}


static void sm_SUPP_BE_Step(struct eapol_sm *sm)
{
	if (sm->initialize || sm->suppAbort)
		sm_SUPP_BE_INITIALIZE_Enter(sm, 1);
	else switch (sm->SUPP_BE_state) {
	case SUPP_BE_UNKNOWN:
		break;
	case SUPP_BE_REQUEST:
		












 
		if (sm->eapResp && sm->eapNoResp) {
			wpa_printf(0, "EAPOL: SUPP_BE REQUEST: both "
				   "eapResp and eapNoResp set?!");
		}
		if (sm->eapResp)
			sm_SUPP_BE_RESPONSE_Enter(sm, 0);
		else if (sm->eapNoResp)
			sm_SUPP_BE_RECEIVE_Enter(sm, 0);
		else if (sm->eapFail)
			sm_SUPP_BE_FAIL_Enter(sm, 0);
		else if (sm->eapSuccess)
			sm_SUPP_BE_SUCCESS_Enter(sm, 0);
		break;
	case SUPP_BE_RESPONSE:
		sm_SUPP_BE_RECEIVE_Enter(sm, 0);
		break;
	case SUPP_BE_SUCCESS:
		sm_SUPP_BE_IDLE_Enter(sm, 0);
		break;
	case SUPP_BE_FAIL:
		sm_SUPP_BE_IDLE_Enter(sm, 0);
		break;
	case SUPP_BE_TIMEOUT:
		sm_SUPP_BE_IDLE_Enter(sm, 0);
		break;
	case SUPP_BE_IDLE:
		if (sm->eapFail && sm->suppStart)
			sm_SUPP_BE_FAIL_Enter(sm, 0);
		else if (sm->eapolEap && sm->suppStart)
			sm_SUPP_BE_REQUEST_Enter(sm, 0);
		else if (sm->eapSuccess && sm->suppStart)
			sm_SUPP_BE_SUCCESS_Enter(sm, 0);
		break;
	case SUPP_BE_INITIALIZE:
		sm_SUPP_BE_IDLE_Enter(sm, 0);
		break;
	case SUPP_BE_RECEIVE:
		if (sm->eapolEap)
			sm_SUPP_BE_REQUEST_Enter(sm, 0);
		else if (sm->eapFail)
			sm_SUPP_BE_FAIL_Enter(sm, 0);
		else if (sm->authWhile == 0)
			sm_SUPP_BE_TIMEOUT_Enter(sm, 0);
		else if (sm->eapSuccess)
			sm_SUPP_BE_SUCCESS_Enter(sm, 0);
		break;
	}
}


static void eapol_sm_txLogoff(struct eapol_sm *sm)
{
	wpa_printf(0, "EAPOL: txLogoff");
	sm->ctx->eapol_send(sm->ctx->eapol_send_ctx,
			    IEEE802_1X_TYPE_EAPOL_LOGOFF, (unsigned char *) "", 0);
	sm->dot1xSuppEapolLogoffFramesTx++;
	sm->dot1xSuppEapolFramesTx++;
}


static void eapol_sm_txStart(struct eapol_sm *sm)
{
	wpa_printf(0, "EAPOL: txStart");
	sm->ctx->eapol_send(sm->ctx->eapol_send_ctx,
			    IEEE802_1X_TYPE_EAPOL_START, (unsigned char *) "", 0);
	sm->dot1xSuppEapolStartFramesTx++;
	sm->dot1xSuppEapolFramesTx++;
}





struct eap_key_data {
	unsigned char encr_key[32];
	unsigned char sign_key[32];
};


static void eapol_sm_processKey(struct eapol_sm *sm)
{
	struct ieee802_1x_hdr *hdr;
	struct ieee802_1x_eapol_key *key;
	struct eap_key_data keydata;
	unsigned char orig_key_sign[16], datakey[32];
	unsigned char ekey[16 + 32];
	int key_len, res, sign_key_len, encr_key_len;
	unsigned short rx_key_length;

	wpa_printf(0, "EAPOL: processKey");
	if (sm->last_rx_key == 0)
		return;

	if (!sm->conf.accept_802_1x_keys) {
		wpa_printf(0, "EAPOL: Received IEEE 802.1X EAPOL-Key"
			   " even though this was not accepted - "
			   "ignoring this packet");
		return;
	}

	hdr = (struct ieee802_1x_hdr *) sm->last_rx_key;
	key = (struct ieee802_1x_eapol_key *) (hdr + 1);
	if (sizeof(*hdr) + ((((unsigned short) ((unsigned short) (unsigned short) (hdr->length)) << 8) & 0xff00) | (((unsigned short) ((unsigned short) (unsigned short) (hdr->length)) >> 8) & 0xff)) > sm->last_rx_key_len) {
		wpa_printf(0, "EAPOL: Too short EAPOL-Key frame");
		return;
	}
	rx_key_length = ((unsigned short) (((key->key_length)[0] << 8) | (key->key_length)[1]));
	wpa_printf(0, "EAPOL: RX IEEE 802.1X ver=%d type=%d len=%d "
		   "EAPOL-Key: type=%d key_length=%d key_index=0x%x",
		   hdr->version, hdr->type, ((((unsigned short) ((unsigned short) (unsigned short) (hdr->length)) << 8) & 0xff00) | (((unsigned short) ((unsigned short) (unsigned short) (hdr->length)) >> 8) & 0xff)),
		   key->type, rx_key_length, key->key_index);

	eapol_sm_notify_lower_layer_success(sm, 1);
	sign_key_len = 32;
	encr_key_len = 32;
	res = eapol_sm_get_key(sm, (unsigned char *) &keydata, sizeof(keydata));
	if (res < 0) {
		wpa_printf(0, "EAPOL: Could not get master key for "
			   "decrypting EAPOL-Key keys");
		return;
	}
	if (res == 16) {
		 
		res = eapol_sm_get_key(sm, (unsigned char *) &keydata, 16);
		if (res) {
			wpa_printf(0, "EAPOL: Could not get LEAP "
				   "master key for decrypting EAPOL-Key keys");
			return;
		}
		sign_key_len = 16;
		encr_key_len = 16;
		os_memcpy(keydata.sign_key, keydata.encr_key, 16);
	} else if (res) {
		wpa_printf(0, "EAPOL: Could not get enough master key "
			   "data for decrypting EAPOL-Key keys (res=%d)", res);
		return;
	}

	 
	if (sm->replay_counter_valid &&
	    os_memcmp(sm->last_replay_counter, key->replay_counter,
		      8) >= 0) {
		wpa_printf(0, "EAPOL: EAPOL-Key replay counter did "
			   "not increase - ignoring key");
		wpa_hexdump(0, "EAPOL: last replay counter",
			    sm->last_replay_counter,
			    8);
		wpa_hexdump(0, "EAPOL: received replay counter",
			    key->replay_counter, 8);
		return;
	}

	 
	os_memcpy(orig_key_sign, key->key_signature, 16);
	os_memset(key->key_signature, 0, 16);
	hmac_md5(keydata.sign_key, sign_key_len,
		 sm->last_rx_key, sizeof(*hdr) + ((((unsigned short) ((unsigned short) (unsigned short) (hdr->length)) << 8) & 0xff00) | (((unsigned short) ((unsigned short) (unsigned short) (hdr->length)) >> 8) & 0xff)),
		 key->key_signature);
	if (os_memcmp(orig_key_sign, key->key_signature,
		      16) != 0) {
		wpa_printf(0, "EAPOL: Invalid key signature in "
			   "EAPOL-Key packet");
		os_memcpy(key->key_signature, orig_key_sign,
			  16);
		return;
	}
	wpa_printf(0, "EAPOL: EAPOL-Key key signature verified");

	key_len = ((((unsigned short) ((unsigned short) (unsigned short) (hdr->length)) << 8) & 0xff00) | (((unsigned short) ((unsigned short) (unsigned short) (hdr->length)) >> 8) & 0xff)) - sizeof(*key);
	if (key_len > 32 || rx_key_length > 32) {
		wpa_printf(0, "EAPOL: Too long key data length %d",
			   key_len ? key_len : rx_key_length);
		return;
	}
	if (key_len == rx_key_length) {
		os_memcpy(ekey, key->key_iv, 16);
		os_memcpy(ekey + 16, keydata.encr_key,
			  encr_key_len);
		os_memcpy(datakey, key + 1, key_len);
		rc4_skip(ekey, 16 + encr_key_len, 0,
			 datakey, key_len);
		wpa_hexdump_key(0, "EAPOL: Decrypted(RC4) key",
				datakey, key_len);
	} else if (key_len == 0) {
		







 
		key_len = rx_key_length;
		os_memcpy(datakey, keydata.encr_key, key_len);
		wpa_hexdump_key(0, "EAPOL: using part of EAP keying "
				"material data encryption key",
				datakey, key_len);
	} else {
		wpa_printf(0, "EAPOL: Invalid key data length %d "
			   "(key_length=%d)", key_len, rx_key_length);
		return;
	}

	sm->replay_counter_valid = 1;
	os_memcpy(sm->last_replay_counter, key->replay_counter,
		  8);

	wpa_printf(0, "EAPOL: Setting dynamic WEP key: %s keyidx %d "
		   "len %d",
		   key->key_index & 0x80 ?
		   "unicast" : "broadcast",
		   key->key_index & 0x03, key_len);

	if (sm->ctx->set_wep_key &&
	    sm->ctx->set_wep_key(sm->ctx->ctx,
				 key->key_index & 0x80,
				 key->key_index & 0x03,
				 datakey, key_len) < 0) {
		wpa_printf(0, "EAPOL: Failed to set WEP key to the "
			   " driver.");
	} else {
		if (key->key_index & 0x80)
			sm->unicast_key_received = 1;
		else
			sm->broadcast_key_received = 1;

		if ((sm->unicast_key_received ||
		     !(sm->conf.required_keys & (1 << (0)))) &&
		    (sm->broadcast_key_received ||
		     !(sm->conf.required_keys & (1 << (1)))))
		{
			wpa_printf(0, "EAPOL: all required EAPOL-Key "
				   "frames received");
			sm->portValid = 1;
			if (sm->ctx->eapol_done_cb)
				sm->ctx->eapol_done_cb(sm->ctx->ctx);
		}
	}
}


static void eapol_sm_getSuppRsp(struct eapol_sm *sm)
{
	wpa_printf(0, "EAPOL: getSuppRsp");
	


 
}


static void eapol_sm_txSuppRsp(struct eapol_sm *sm)
{
	struct wpabuf *resp;

	wpa_printf(0, "EAPOL: txSuppRsp");
	resp = eap_get_eapRespData(sm->eap);
	if (resp == 0) {
		wpa_printf(0, "EAPOL: txSuppRsp - EAP response data "
			   "not available");
		return;
	}

	 
	sm->ctx->eapol_send(sm->ctx->eapol_send_ctx,
			    IEEE802_1X_TYPE_EAP_PACKET, wpabuf_head(resp),
			    wpabuf_len(resp));

	 
	wpabuf_free(resp);

	if (sm->initial_req)
		sm->dot1xSuppEapolReqIdFramesRx++;
	else
		sm->dot1xSuppEapolReqFramesRx++;
	sm->dot1xSuppEapolRespFramesTx++;
	sm->dot1xSuppEapolFramesTx++;
}


static void eapol_sm_abortSupp(struct eapol_sm *sm)
{
	
 
	os_free(sm->last_rx_key);
	sm->last_rx_key = 0;
	wpabuf_free(sm->eapReqData);
	sm->eapReqData = 0;
	eap_sm_abort(sm->eap);
}


static void eapol_sm_step_timeout(void *eloop_ctx, void *timeout_ctx)
{
	eapol_sm_step(timeout_ctx);
}


static void eapol_sm_set_port_authorized(struct eapol_sm *sm)
{
	if (sm->ctx->port_cb)
		sm->ctx->port_cb(sm->ctx->ctx, 1);
}


static void eapol_sm_set_port_unauthorized(struct eapol_sm *sm)
{
	if (sm->ctx->port_cb)
		sm->ctx->port_cb(sm->ctx->ctx, 0);
}









 
void eapol_sm_step(struct eapol_sm *sm)
{
	int i;

	


 
	for (i = 0; i < 100; i++) {
		sm->changed = 0;
		sm_SUPP_PAE_Step(sm);
		sm_KEY_RX_Step(sm);
		sm_SUPP_BE_Step(sm);
		if (eap_peer_sm_step(sm->eap))
			sm->changed = 1;
		if (!sm->changed)
			break;
	}

	if (sm->changed) {
		
 
		eloop_cancel_timeout(eapol_sm_step_timeout, 0, sm);
		eloop_register_timeout(0, 0, eapol_sm_step_timeout, 0, sm);
	}

	if (sm->ctx->cb && sm->cb_status != EAPOL_CB_IN_PROGRESS) {
		int success = sm->cb_status == EAPOL_CB_SUCCESS ? 1 : 0;
		sm->cb_status = EAPOL_CB_IN_PROGRESS;
		sm->ctx->cb(sm, success, sm->ctx->cb_ctx);
	}
}


#line 986 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eapol_supp\\eapol_supp_sm.c"



static const char * eapol_port_control(PortControl ctrl)
{
	switch (ctrl) {
	case Auto:
		return "Auto";
	case ForceUnauthorized:
		return "ForceUnauthorized";
	case ForceAuthorized:
		return "ForceAuthorized";
	default:
		return "Unknown";
	}
}













 
void eapol_sm_configure(struct eapol_sm *sm, int heldPeriod, int authPeriod,
			int startPeriod, int maxStart)
{
	if (sm == 0)
		return;
	if (heldPeriod >= 0)
		sm->heldPeriod = heldPeriod;
	if (authPeriod >= 0)
		sm->authPeriod = authPeriod;
	if (startPeriod >= 0)
		sm->startPeriod = startPeriod;
	if (maxStart >= 0)
		sm->maxStart = maxStart;
}


#line 1157 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eapol_supp\\eapol_supp_sm.c"










 
int eapol_sm_rx_eapol(struct eapol_sm *sm, const unsigned char *src, const unsigned char *buf,
		      size_t len)
{
	const struct ieee802_1x_hdr *hdr;
	const struct ieee802_1x_eapol_key *key;
	int data_len;
	int res = 1;
	size_t plen;

	if (sm == 0)
		return 0;
	sm->dot1xSuppEapolFramesRx++;
	if (len < sizeof(*hdr)) {
		sm->dot1xSuppInvalidEapolFramesRx++;
		return 0;
	}
	hdr = (const struct ieee802_1x_hdr *) buf;
	sm->dot1xSuppLastEapolFrameVersion = hdr->version;
	os_memcpy(sm->dot1xSuppLastEapolFrameSource, src, 6);
	if (hdr->version < 2) {
		 
	}
	plen = ((((unsigned short) ((unsigned short) (unsigned short) (hdr->length)) << 8) & 0xff00) | (((unsigned short) ((unsigned short) (unsigned short) (hdr->length)) >> 8) & 0xff));
	if (plen > len - sizeof(*hdr)) {
		sm->dot1xSuppEapLengthErrorFramesRx++;
		return 0;
	}
#line 1220 "..\\wpa_supplicant-0.7.3\\wpa_supplicant-0.7.3\\src\\eapol_supp\\eapol_supp_sm.c"
	data_len = plen + sizeof(*hdr);

	switch (hdr->type) {
	case IEEE802_1X_TYPE_EAP_PACKET:
		if (sm->cached_pmk) {
			


 
			eapol_sm_abort_cached(sm);
		}
		wpabuf_free(sm->eapReqData);
		sm->eapReqData = wpabuf_alloc_copy(hdr + 1, plen);
		if (sm->eapReqData) {
			wpa_printf(0, "EAPOL: Received EAP-Packet "
				   "frame");
			sm->eapolEap = 1;
			eapol_sm_step(sm);
		}
		break;
	case IEEE802_1X_TYPE_EAPOL_KEY:
		if (plen < sizeof(*key)) {
			wpa_printf(0, "EAPOL: Too short EAPOL-Key "
				   "frame received");
			break;
		}
		key = (const struct ieee802_1x_eapol_key *) (hdr + 1);
		if (key->type == EAPOL_KEY_TYPE_WPA ||
		    key->type == EAPOL_KEY_TYPE_RSN) {
			 
			wpa_printf(0, "EAPOL: Ignoring WPA EAPOL-Key "
				   "frame in EAPOL state machines");
			res = 0;
			break;
		}
		if (key->type != EAPOL_KEY_TYPE_RC4) {
			wpa_printf(0, "EAPOL: Ignored unknown "
				   "EAPOL-Key type %d", key->type);
			break;
		}
		os_free(sm->last_rx_key);
		sm->last_rx_key = os_malloc(data_len);
		if (sm->last_rx_key) {
			wpa_printf(0, "EAPOL: Received EAPOL-Key "
				   "frame");
			os_memcpy(sm->last_rx_key, buf, data_len);
			sm->last_rx_key_len = data_len;
			sm->rxKey = 1;
			eapol_sm_step(sm);
		}
		break;
	default:
		wpa_printf(0, "EAPOL: Received unknown EAPOL type %d",
			   hdr->type);
		sm->dot1xSuppInvalidEapolFramesRx++;
		break;
	}

	return res;
}








 
void eapol_sm_notify_tx_eapol_key(struct eapol_sm *sm)
{
	if (sm)
		sm->dot1xSuppEapolFramesTx++;
}








 
void eapol_sm_notify_portEnabled(struct eapol_sm *sm, int enabled)
{
	if (sm == 0)
		return;
	wpa_printf(0, "EAPOL: External notification - "
		   "portEnabled=%d", enabled);
	sm->portEnabled = enabled;
	eapol_sm_step(sm);
}








 
void eapol_sm_notify_portValid(struct eapol_sm *sm, int valid)
{
	if (sm == 0)
		return;
	wpa_printf(0, "EAPOL: External notification - "
		   "portValid=%d", valid);
	sm->portValid = valid;
	eapol_sm_step(sm);
}












 
void eapol_sm_notify_eap_success(struct eapol_sm *sm, int success)
{
	if (sm == 0)
		return;
	wpa_printf(0, "EAPOL: External notification - "
		   "EAP success=%d", success);
	sm->eapSuccess = success;
	sm->altAccept = success;
	if (success)
		eap_notify_success(sm->eap);
	eapol_sm_step(sm);
}









 
void eapol_sm_notify_eap_fail(struct eapol_sm *sm, int fail)
{
	if (sm == 0)
		return;
	wpa_printf(0, "EAPOL: External notification - "
		   "EAP fail=%d", fail);
	sm->eapFail = fail;
	sm->altReject = fail;
	eapol_sm_step(sm);
}













 
void eapol_sm_notify_config(struct eapol_sm *sm,
			    struct eap_peer_config *config,
			    const struct eapol_config *conf)
{
	if (sm == 0)
		return;

	sm->config = config;

	if (conf == 0)
		return;

	sm->conf.accept_802_1x_keys = conf->accept_802_1x_keys;
	sm->conf.required_keys = conf->required_keys;
	sm->conf.fast_reauth = conf->fast_reauth;
	sm->conf.workaround = conf->workaround;
	if (sm->eap) {
		eap_set_fast_reauth(sm->eap, conf->fast_reauth);
		eap_set_workaround(sm->eap, conf->workaround);
		eap_set_force_disabled(sm->eap, conf->eap_disabled);
	}
}












 
int eapol_sm_get_key(struct eapol_sm *sm, unsigned char *key, size_t len)
{
	const unsigned char *eap_key;
	size_t eap_len;

	if (sm == 0 || !eap_key_available(sm->eap)) {
		wpa_printf(0, "EAPOL: EAP key not available");
		return -1;
	}
	eap_key = eap_get_eapKeyData(sm->eap, &eap_len);
	if (eap_key == 0) {
		wpa_printf(0, "EAPOL: Failed to get eapKeyData");
		return -1;
	}
	if (len > eap_len) {
		wpa_printf(0, "EAPOL: Requested key length (%lu) not "
			   "available (len=%lu)",
			   (unsigned long) len, (unsigned long) eap_len);
		return eap_len;
	}
	os_memcpy(key, eap_key, len);
	wpa_printf(0, "EAPOL: Successfully fetched key (len=%lu)",
		   (unsigned long) len);
	return 0;
}








 
void eapol_sm_notify_logoff(struct eapol_sm *sm, int logoff)
{
	if (sm) {
		sm->userLogoff = logoff;
		eapol_sm_step(sm);
	}
}








 
void eapol_sm_notify_cached(struct eapol_sm *sm)
{
	if (sm == 0)
		return;
	wpa_printf(0, "EAPOL: PMKSA caching was used - skip EAPOL");
	sm->SUPP_PAE_state = SUPP_PAE_AUTHENTICATED;
	sm->suppPortStatus = Authorized;
	eapol_sm_set_port_authorized(sm);
	sm->portValid = 1;
	eap_notify_success(sm->eap);
	eapol_sm_step(sm);
}








 
void eapol_sm_notify_pmkid_attempt(struct eapol_sm *sm, int attempt)
{
	if (sm == 0)
		return;
	if (attempt) {
		wpa_printf(0, "RSN: Trying to use cached PMKSA");
		sm->cached_pmk = 1;
	} else {
		wpa_printf(0, "RSN: Do not try to use cached PMKSA");
		sm->cached_pmk = 0;
	}
}


static void eapol_sm_abort_cached(struct eapol_sm *sm)
{
	wpa_printf(0, "RSN: Authenticator did not accept PMKID, "
		   "doing full EAP authentication");
	if (sm == 0)
		return;
	sm->cached_pmk = 0;
	sm->SUPP_PAE_state = SUPP_PAE_CONNECTING;
	sm->suppPortStatus = Unauthorized;
	eapol_sm_set_port_unauthorized(sm);

	
 
	sm->startWhen = 3;
	eapol_enable_timer_tick(sm);

	if (sm->ctx->aborted_cached)
		sm->ctx->aborted_cached(sm->ctx->ctx);
}









 
void eapol_sm_register_scard_ctx(struct eapol_sm *sm, void *ctx)
{
	if (sm) {
		sm->ctx->scard_ctx = ctx;
		eap_register_scard_ctx(sm->eap, ctx);
	}
}








 
void eapol_sm_notify_portControl(struct eapol_sm *sm, PortControl portControl)
{
	if (sm == 0)
		return;
	wpa_printf(0, "EAPOL: External notification - "
		   "portControl=%s", eapol_port_control(portControl));
	sm->portControl = portControl;
	eapol_sm_step(sm);
}








 
void eapol_sm_notify_ctrl_attached(struct eapol_sm *sm)
{
	if (sm == 0)
		return;
	eap_sm_notify_ctrl_attached(sm->eap);
}








 
void eapol_sm_notify_ctrl_response(struct eapol_sm *sm)
{
	if (sm == 0)
		return;
	if (sm->eapReqData && !sm->eapReq) {
		wpa_printf(0, "EAPOL: received control response (user "
			   "input) notification - retrying pending EAP "
			   "Request");
		sm->eapolEap = 1;
		sm->eapReq = 1;
		eapol_sm_step(sm);
	}
}








 
void eapol_sm_request_reauth(struct eapol_sm *sm)
{
	if (sm == 0 || sm->SUPP_PAE_state != SUPP_PAE_AUTHENTICATED)
		return;
	eapol_sm_txStart(sm);
}











 
void eapol_sm_notify_lower_layer_success(struct eapol_sm *sm, int in_eapol_sm)
{
	if (sm == 0)
		return;
	;
	;
	eap_notify_lower_layer_success(sm->eap);
	;
	if (!in_eapol_sm)
		eapol_sm_step(sm);
}





 
void eapol_sm_invalidate_cached_session(struct eapol_sm *sm)
{
	if (sm)
		eap_invalidate_cached_session(sm->eap);
}


static struct eap_peer_config * eapol_sm_get_config(void *ctx)
{
	struct eapol_sm *sm = ctx;
	return sm ? sm->config : 0;
}


static struct wpabuf * eapol_sm_get_eapReqData(void *ctx)
{
	struct eapol_sm *sm = ctx;
	if (sm == 0 || sm->eapReqData == 0)
		return 0;

	return sm->eapReqData;
}


static int eapol_sm_get_bool(void *ctx, enum eapol_bool_var variable)
{
	struct eapol_sm *sm = ctx;
	if (sm == 0)
		return 0;
	switch (variable) {
	case EAPOL_eapSuccess:
		return sm->eapSuccess;
	case EAPOL_eapRestart:
		return sm->eapRestart;
	case EAPOL_eapFail:
		return sm->eapFail;
	case EAPOL_eapResp:
		return sm->eapResp;
	case EAPOL_eapNoResp:
		return sm->eapNoResp;
	case EAPOL_eapReq:
		return sm->eapReq;
	case EAPOL_portEnabled:
		return sm->portEnabled;
	case EAPOL_altAccept:
		return sm->altAccept;
	case EAPOL_altReject:
		return sm->altReject;
	}
	return 0;
}


static void eapol_sm_set_bool(void *ctx, enum eapol_bool_var variable,
			      int value)
{
	struct eapol_sm *sm = ctx;
	if (sm == 0)
		return;
	switch (variable) {
	case EAPOL_eapSuccess:
		sm->eapSuccess = value;
		break;
	case EAPOL_eapRestart:
		sm->eapRestart = value;
		break;
	case EAPOL_eapFail:
		sm->eapFail = value;
		break;
	case EAPOL_eapResp:
		sm->eapResp = value;
		break;
	case EAPOL_eapNoResp:
		sm->eapNoResp = value;
		break;
	case EAPOL_eapReq:
		sm->eapReq = value;
		break;
	case EAPOL_portEnabled:
		sm->portEnabled = value;
		break;
	case EAPOL_altAccept:
		sm->altAccept = value;
		break;
	case EAPOL_altReject:
		sm->altReject = value;
		break;
	}
}


static unsigned int eapol_sm_get_int(void *ctx, enum eapol_int_var variable)
{
	struct eapol_sm *sm = ctx;
	if (sm == 0)
		return 0;
	switch (variable) {
	case EAPOL_idleWhile:
		return sm->idleWhile;
	}
	return 0;
}


static void eapol_sm_set_int(void *ctx, enum eapol_int_var variable,
			     unsigned int value)
{
	struct eapol_sm *sm = ctx;
	if (sm == 0)
		return;
	switch (variable) {
	case EAPOL_idleWhile:
		sm->idleWhile = value;
		eapol_enable_timer_tick(sm);
		break;
	}
}


static void eapol_sm_set_config_blob(void *ctx, struct wpa_config_blob *blob)
{

	struct eapol_sm *sm = ctx;
	if (sm && sm->ctx && sm->ctx->set_config_blob)
		sm->ctx->set_config_blob(sm->ctx->ctx, blob);

}


static const struct wpa_config_blob *
eapol_sm_get_config_blob(void *ctx, const char *name)
{

	struct eapol_sm *sm = ctx;
	if (sm && sm->ctx && sm->ctx->get_config_blob)
		return sm->ctx->get_config_blob(sm->ctx->ctx, name);
	else
		return 0;



}


static void eapol_sm_notify_pending(void *ctx)
{
	struct eapol_sm *sm = ctx;
	if (sm == 0)
		return;
	if (sm->eapReqData && !sm->eapReq) {
		wpa_printf(0, "EAPOL: received notification from EAP "
			   "state machine - retrying pending EAP Request");
		sm->eapolEap = 1;
		sm->eapReq = 1;
		eapol_sm_step(sm);
	}
}



static void eapol_sm_eap_param_needed(void *ctx, const char *field,
				      const char *txt)
{
	struct eapol_sm *sm = ctx;
	wpa_printf(0, "EAPOL: EAP parameter needed");
	if (sm->ctx->eap_param_needed)
		sm->ctx->eap_param_needed(sm->ctx->ctx, field, txt);
}





static struct eapol_callbacks eapol_cb =
{
	eapol_sm_get_config,
	eapol_sm_get_bool,
	eapol_sm_set_bool,
	eapol_sm_get_int,
	eapol_sm_set_int,
	eapol_sm_get_eapReqData,
	eapol_sm_set_config_blob,
	eapol_sm_get_config_blob,
	eapol_sm_notify_pending,
	eapol_sm_eap_param_needed
};









 
struct eapol_sm *eapol_sm_init(struct eapol_ctx *ctx)
{
	struct eapol_sm *sm;
	struct eap_config conf;
	sm = os_zalloc(sizeof(*sm));
	if (sm == 0)
		return 0;
	sm->ctx = ctx;

	sm->portControl = Auto;

	 
	sm->heldPeriod = 60;
	sm->startPeriod = 30;
	sm->maxStart = 3;

	 
	sm->authPeriod = 30;

	os_memset(&conf, 0, sizeof(conf));
	conf.opensc_engine_path = ctx->opensc_engine_path;
	conf.pkcs11_engine_path = ctx->pkcs11_engine_path;
	conf.pkcs11_module_path = ctx->pkcs11_module_path;
	conf.wps = ctx->wps;

	sm->eap = eap_peer_sm_init(sm, &eapol_cb, sm->ctx->msg_ctx, &conf);
	if (sm->eap == 0) {
		os_free(sm);
		return 0;
	}

	 
	sm->initialize = 1;
	eapol_sm_step(sm);
	sm->initialize = 0;
	eapol_sm_step(sm);

	sm->timer_tick_enabled = 1;
	eloop_register_timeout(1, 0, eapol_port_timers_tick, 0, sm);

	return sm;
}







 
void eapol_sm_deinit(struct eapol_sm *sm)
{
	if (sm == 0)
		return;
	eloop_cancel_timeout(eapol_sm_step_timeout, 0, sm);
	eloop_cancel_timeout(eapol_port_timers_tick, 0, sm);
	eap_peer_sm_deinit(sm->eap);
	os_free(sm->last_rx_key);
	wpabuf_free(sm->eapReqData);
	os_free(sm->ctx);
	os_free(sm);
}
