#line 1 "..\\lwIP\\src\\core\\dhcp.c"




 































































 

#line 1 "..\\lwIP\\src\\include\\lwip/opt.h"




 































 






 
#line 1 "..\\lwIP\\port\\include\\lwipopts.h"




















 





 








 





 


 


 



 




 


 


 


 


 


 




 
 


 



 







 






 






 







 


 


 



 


 



 



 


 






 




 



 








 





 



#line 188 "..\\lwIP\\port\\include\\lwipopts.h"
   

   

   

   

   

   








 


 





 


 











 
#line 46 "..\\lwIP\\src\\include\\lwip/opt.h"
#line 1 "..\\lwIP\\src\\include\\lwip/debug.h"






























 



#line 1 "..\\lwIP\\src\\include\\lwip/arch.h"






























 











#line 1 "..\\lwIP\\port\\include\\arch/cc.h"






























 



#line 1 "..\\lwIP\\port\\include\\arch/cpu.h"






























 





#line 36 "..\\lwIP\\port\\include\\arch/cc.h"
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



 
#line 37 "..\\lwIP\\port\\include\\arch/cc.h"

 

typedef unsigned   char    u8_t;     
typedef signed     char    s8_t;     
typedef unsigned   short   u16_t;    
typedef signed     short   s16_t;    
typedef unsigned   long    u32_t;    
typedef signed     long    s32_t;    
typedef u32_t mem_ptr_t;             


 













 

 
#line 75 "..\\lwIP\\port\\include\\arch/cc.h"






#line 96 "..\\lwIP\\port\\include\\arch/cc.h"

 

#line 105 "..\\lwIP\\port\\include\\arch/cc.h"

 
#line 113 "..\\lwIP\\port\\include\\arch/cc.h"





#line 44 "..\\lwIP\\src\\include\\lwip/arch.h"

 




























#line 131 "..\\lwIP\\src\\include\\lwip/arch.h"







#line 156 "..\\lwIP\\src\\include\\lwip/arch.h"




#line 176 "..\\lwIP\\src\\include\\lwip/arch.h"










#line 198 "..\\lwIP\\src\\include\\lwip/arch.h"





#line 222 "..\\lwIP\\src\\include\\lwip/arch.h"


extern int errno;








#line 36 "..\\lwIP\\src\\include\\lwip/debug.h"






 






 



 


 

 

 

 





#line 74 "..\\lwIP\\src\\include\\lwip/debug.h"

 








 
#line 96 "..\\lwIP\\src\\include\\lwip/debug.h"







#line 47 "..\\lwIP\\src\\include\\lwip/opt.h"





 





 







 







 







 








 




 








 








 







 












 







 









 







 









 





















 








 




 







 








 







 







 







 







 









 









 







 







 







 








 








 






 








 


 






 







 











 








 




 








 








 








 








 









 








 







 






 








 







 








 



 






 






 






 








 


 






 








 


 















 








 


 







 










 








 



 







 







 






 








 








 


 








 



 




 




 




 




 






 




 













 





 








 


 






 






 








 


 






 







 






 






 







 










 











 







 







 








 






 








 






 







 










 
#line 872 "..\\lwIP\\src\\include\\lwip/opt.h"






 




 








 








 



 






 







 







 










 







 







 
















 












 








 


 








 


 








 


 








 








 








 






 








 








 






 








 








 






 








 








 








 








 








 








 








 



 






 








 


 







 








 








 






 






 






 






 








 


 




#line 1352 "..\\lwIP\\src\\include\\lwip/opt.h"

#line 1364 "..\\lwIP\\src\\include\\lwip/opt.h"







 


 






 






 




#line 1527 "..\\lwIP\\src\\include\\lwip/opt.h"





 


 



 


 



 


 



 


 



 


 






 








 




 







 






 






 






 






 






 






 






 






 






 






 






 






 






 






 






 






 






 






 







 






 






 






 






 






 






 






 






 






 






 






 






 






 






 




#line 72 "..\\lwIP\\src\\core\\dhcp.c"



#line 1 "..\\lwIP\\src\\include\\lwip/stats.h"






























 



#line 36 "..\\lwIP\\src\\include\\lwip/stats.h"

#line 1 "..\\lwIP\\src\\include\\lwip/mem.h"






























 



#line 36 "..\\lwIP\\src\\include\\lwip/mem.h"





#line 69 "..\\lwIP\\src\\include\\lwip/mem.h"



 



typedef u16_t mem_size_t;


#line 86 "..\\lwIP\\src\\include\\lwip/mem.h"
 
void  mem_init(void);
void *mem_realloc(void *mem, mem_size_t size);

void *mem_malloc(mem_size_t size);
void *mem_calloc(mem_size_t count, mem_size_t size);
void  mem_free(void *mem);














#line 38 "..\\lwIP\\src\\include\\lwip/stats.h"
#line 1 "..\\lwIP\\src\\include\\lwip/memp.h"






























 




#line 37 "..\\lwIP\\src\\include\\lwip/memp.h"





 
typedef enum {
#line 1 "..\\lwIP\\src\\include\\lwip/memp_std.h"










 


 







 









 

MEMP_RAW_PCB,



MEMP_UDP_PCB,



MEMP_TCP_PCB,
MEMP_TCP_PCB_LISTEN,
MEMP_TCP_SEG,



MEMP_REASSDATA,













MEMP_ARP_QUEUE,


















 
MEMP_PBUF,
MEMP_PBUF_POOL,





 







 
#line 46 "..\\lwIP\\src\\include\\lwip/memp.h"
  MEMP_MAX
} memp_t;

#line 77 "..\\lwIP\\src\\include\\lwip/memp.h"





#line 91 "..\\lwIP\\src\\include\\lwip/memp.h"

#line 99 "..\\lwIP\\src\\include\\lwip/memp.h"

void  memp_init(void);





void *memp_malloc(memp_t type);

void  memp_free(memp_t type, void *mem);







#line 39 "..\\lwIP\\src\\include\\lwip/stats.h"





#line 151 "..\\lwIP\\src\\include\\lwip/stats.h"

#line 159 "..\\lwIP\\src\\include\\lwip/stats.h"

#line 167 "..\\lwIP\\src\\include\\lwip/stats.h"

#line 175 "..\\lwIP\\src\\include\\lwip/stats.h"

#line 183 "..\\lwIP\\src\\include\\lwip/stats.h"

#line 191 "..\\lwIP\\src\\include\\lwip/stats.h"

#line 199 "..\\lwIP\\src\\include\\lwip/stats.h"

#line 207 "..\\lwIP\\src\\include\\lwip/stats.h"

#line 215 "..\\lwIP\\src\\include\\lwip/stats.h"

#line 233 "..\\lwIP\\src\\include\\lwip/stats.h"

#line 251 "..\\lwIP\\src\\include\\lwip/stats.h"

#line 261 "..\\lwIP\\src\\include\\lwip/stats.h"

 
#line 278 "..\\lwIP\\src\\include\\lwip/stats.h"





#line 76 "..\\lwIP\\src\\core\\dhcp.c"
#line 77 "..\\lwIP\\src\\core\\dhcp.c"
#line 1 "..\\lwIP\\src\\include\\lwip/udp.h"






























 



#line 36 "..\\lwIP\\src\\include\\lwip/udp.h"



#line 1 "..\\lwIP\\src\\include\\lwip/pbuf.h"






























 




#line 37 "..\\lwIP\\src\\include\\lwip/pbuf.h"
#line 1 "..\\lwIP\\src\\include\\lwip/err.h"






























 



#line 36 "..\\lwIP\\src\\include\\lwip/err.h"
#line 37 "..\\lwIP\\src\\include\\lwip/err.h"






 



 typedef s8_t err_t;


 



























extern const char *lwip_strerr(err_t err);








#line 38 "..\\lwIP\\src\\include\\lwip/pbuf.h"








typedef enum {
  PBUF_TRANSPORT,
  PBUF_IP,
  PBUF_LINK,
  PBUF_RAW
} pbuf_layer;

typedef enum {
  PBUF_RAM,  
  PBUF_ROM,  
  PBUF_REF,  
  PBUF_POOL  
} pbuf_type;


 


struct pbuf {
   
  struct pbuf *next;

   
  void *payload;
  
  





 
  u16_t tot_len;
  
   
  u16_t len;  

   
  u8_t   type;

   
  u8_t flags;

  



 
  u16_t ref;
  
};

 


struct pbuf *pbuf_alloc(pbuf_layer l, u16_t size, pbuf_type type);
void pbuf_realloc(struct pbuf *p, u16_t size); 
u8_t pbuf_header(struct pbuf *p, s16_t header_size);
void pbuf_ref(struct pbuf *p);
void pbuf_ref_chain(struct pbuf *p);
u8_t pbuf_free(struct pbuf *p);
u8_t pbuf_clen(struct pbuf *p);  
void pbuf_cat(struct pbuf *head, struct pbuf *tail);
void pbuf_chain(struct pbuf *head, struct pbuf *tail);
struct pbuf *pbuf_dechain(struct pbuf *p);
err_t pbuf_copy(struct pbuf *p_to, struct pbuf *p_from);
u16_t pbuf_copy_partial(struct pbuf *p, void *dataptr, u16_t len, u16_t offset);
err_t pbuf_take(struct pbuf *buf, const void *dataptr, u16_t len);
struct pbuf *pbuf_coalesce(struct pbuf *p, pbuf_layer layer);





#line 40 "..\\lwIP\\src\\include\\lwip/udp.h"
#line 1 "..\\lwIP\\src\\include\\lwip/netif.h"






























 



#line 36 "..\\lwIP\\src\\include\\lwip/netif.h"



#line 40 "..\\lwIP\\src\\include\\lwip/netif.h"

#line 1 "..\\lwIP\\src\\include\\ipv4\\lwip/ip_addr.h"






























 



#line 36 "..\\lwIP\\src\\include\\ipv4\\lwip/ip_addr.h"

#line 1 "..\\lwIP\\src\\include\\ipv4\\lwip/inet.h"






























 



#line 36 "..\\lwIP\\src\\include\\ipv4\\lwip/inet.h"





 
struct in_addr {
  u32_t s_addr;
};






u32_t inet_addr(const char *cp);
int inet_aton(const char *cp, struct in_addr *addr);
char *inet_ntoa(struct in_addr addr);  

#line 67 "..\\lwIP\\src\\include\\ipv4\\lwip/inet.h"





#line 91 "..\\lwIP\\src\\include\\ipv4\\lwip/inet.h"
u16_t htons(u16_t x);
u16_t ntohs(u16_t x);
u32_t htonl(u32_t x);
u32_t ntohl(u32_t x);








#line 38 "..\\lwIP\\src\\include\\ipv4\\lwip/ip_addr.h"








__packed
struct ip_addr {
  u32_t addr;
} ;








 



__packed
struct ip_addr2 {
  u16_t addrw[2];
} ;





struct netif;

extern const struct ip_addr ip_addr_any;
extern const struct ip_addr ip_addr_broadcast;



 






 













































 








u8_t ip_addr_isbroadcast(struct ip_addr *, struct netif *);





#line 156 "..\\lwIP\\src\\include\\ipv4\\lwip/ip_addr.h"


 









#line 42 "..\\lwIP\\src\\include\\lwip/netif.h"

#line 44 "..\\lwIP\\src\\include\\lwip/netif.h"
#line 45 "..\\lwIP\\src\\include\\lwip/netif.h"

struct dhcp;










 


 


 




 

 

 

 


 

 

 




 

struct netif {
   
  struct netif *next;

   
  struct ip_addr ip_addr;
  struct ip_addr netmask;
  struct ip_addr gw;

  
 
  err_t (* input)(struct pbuf *p, struct netif *inp);
  

 
  err_t (* output)(struct netif *netif, struct pbuf *p,
       struct ip_addr *ipaddr);
  

 
  err_t (* linkoutput)(struct netif *netif, struct pbuf *p);
#line 119 "..\\lwIP\\src\\include\\lwip/netif.h"
  
 
  void *state;

   
  struct dhcp *dhcp;
  struct dhcp_srv *dhcpsrv;
#line 135 "..\\lwIP\\src\\include\\lwip/netif.h"
   
  u8_t hwaddr_len;
   
  u8_t hwaddr[6U];
   
  u16_t mtu;
   
  u8_t flags;
   
  char name[2];
   
  u8_t num;
#line 179 "..\\lwIP\\src\\include\\lwip/netif.h"
};

#line 199 "..\\lwIP\\src\\include\\lwip/netif.h"


 
extern struct netif *netif_list;
 
extern struct netif *netif_default;



struct netif *netif_add(struct netif *netif, struct ip_addr *ipaddr, struct ip_addr *netmask,
      struct ip_addr *gw,
      void *state,
      err_t (* init)(struct netif *netif),
      err_t (* input)(struct pbuf *p, struct netif *netif));

void
netif_set_addr(struct netif *netif,struct ip_addr *ipaddr, struct ip_addr *netmask,
    struct ip_addr *gw);
void netif_remove(struct netif * netif);




 
struct netif *netif_find(char *name);

void netif_set_default(struct netif *netif);

void netif_set_ipaddr(struct netif *netif, struct ip_addr *ipaddr);
void netif_set_netmask(struct netif *netif, struct ip_addr *netmask);
void netif_set_gw(struct netif *netif, struct ip_addr *gw);

void netif_set_up(struct netif *netif);
void netif_set_down(struct netif *netif);
u8_t netif_is_up(struct netif *netif);

#line 241 "..\\lwIP\\src\\include\\lwip/netif.h"

#line 251 "..\\lwIP\\src\\include\\lwip/netif.h"





#line 263 "..\\lwIP\\src\\include\\lwip/netif.h"

#line 41 "..\\lwIP\\src\\include\\lwip/udp.h"
#line 42 "..\\lwIP\\src\\include\\lwip/udp.h"
#line 1 "..\\lwIP\\src\\include\\ipv4\\lwip/ip.h"






























 



#line 36 "..\\lwIP\\src\\include\\ipv4\\lwip/ip.h"

#line 1 "..\\lwIP\\src\\include\\lwip/def.h"






























 



 
#line 37 "..\\lwIP\\src\\include\\lwip/def.h"











#line 38 "..\\lwIP\\src\\include\\ipv4\\lwip/ip.h"
#line 39 "..\\lwIP\\src\\include\\ipv4\\lwip/ip.h"
#line 40 "..\\lwIP\\src\\include\\ipv4\\lwip/ip.h"
#line 41 "..\\lwIP\\src\\include\\ipv4\\lwip/ip.h"
#line 42 "..\\lwIP\\src\\include\\ipv4\\lwip/ip.h"





 











 














 
#line 87 "..\\lwIP\\src\\include\\ipv4\\lwip/ip.h"

struct ip_pcb {
 
  struct ip_addr local_ip; struct ip_addr remote_ip; u16_t so_options; u8_t tos; u8_t ttl ;
};



 
#line 106 "..\\lwIP\\src\\include\\ipv4\\lwip/ip.h"





__packed
struct ip_hdr {
   
  u16_t _v_hl_tos;
   
  u16_t _len;
   
  u16_t _id;
   
  u16_t _offset;




   
  u16_t _ttl_proto;
   
  u16_t _chksum;
   
  struct ip_addr src;
  struct ip_addr dest; 
} ;





#line 147 "..\\lwIP\\src\\include\\ipv4\\lwip/ip.h"

#line 155 "..\\lwIP\\src\\include\\ipv4\\lwip/ip.h"


struct netif *ip_route(struct ip_addr *dest);
err_t ip_input(struct pbuf *p, struct netif *inp);
err_t ip_output(struct pbuf *p, struct ip_addr *src, struct ip_addr *dest,
       u8_t ttl, u8_t tos, u8_t proto);
err_t ip_output_if(struct pbuf *p, struct ip_addr *src, struct ip_addr *dest,
       u8_t ttl, u8_t tos, u8_t proto,
       struct netif *netif);
#line 173 "..\\lwIP\\src\\include\\ipv4\\lwip/ip.h"
struct netif *ip_current_netif(void);
const struct ip_hdr *ip_current_header(void);













#line 43 "..\\lwIP\\src\\include\\lwip/udp.h"







 



__packed
struct udp_hdr {
  u16_t src;
  u16_t dest;   
  u16_t len;
  u16_t chksum;
} ;









struct udp_pcb {
 
  struct ip_addr local_ip; struct ip_addr remote_ip; u16_t so_options; u8_t tos; u8_t ttl ;

 

  struct udp_pcb *next;

  u8_t flags;
   
  u16_t local_port, remote_port;











  









 
  void (* recv)(void *arg, struct udp_pcb *pcb, struct pbuf *p,
    struct ip_addr *addr, u16_t port);
   
  void *recv_arg;  
};
 
extern struct udp_pcb *udp_pcbs;


 
struct udp_pcb * udp_new        (void);
void             udp_remove     (struct udp_pcb *pcb);
err_t            udp_bind       (struct udp_pcb *pcb, struct ip_addr *ipaddr,
                 u16_t port);
err_t            udp_connect    (struct udp_pcb *pcb, struct ip_addr *ipaddr,
                 u16_t port);
void             udp_disconnect    (struct udp_pcb *pcb);
void             udp_recv       (struct udp_pcb *pcb,
         void (* recv)(void *arg, struct udp_pcb *upcb,
                 struct pbuf *p,
                 struct ip_addr *addr,
                 u16_t port),
         void *recv_arg);
err_t            udp_sendto_if  (struct udp_pcb *pcb, struct pbuf *p, struct ip_addr *dst_ip, u16_t dst_port, struct netif *netif);
err_t            udp_sendto     (struct udp_pcb *pcb, struct pbuf *p, struct ip_addr *dst_ip, u16_t dst_port);
err_t            udp_send       (struct udp_pcb *pcb, struct pbuf *p);




 
void             udp_input      (struct pbuf *p, struct netif *inp);















#line 78 "..\\lwIP\\src\\core\\dhcp.c"
#line 79 "..\\lwIP\\src\\core\\dhcp.c"
#line 80 "..\\lwIP\\src\\core\\dhcp.c"
#line 81 "..\\lwIP\\src\\core\\dhcp.c"
#line 1 "..\\lwIP\\src\\include\\lwip/sys.h"






























 



#line 36 "..\\lwIP\\src\\include\\lwip/sys.h"








 
typedef u8_t sys_sem_t;
typedef u8_t sys_mbox_t;
struct sys_timeo {u8_t dummy;};

#line 64 "..\\lwIP\\src\\include\\lwip/sys.h"



#line 142 "..\\lwIP\\src\\include\\lwip/sys.h"

 
u32_t sys_now(void);

 



 





 
#line 188 "..\\lwIP\\src\\include\\lwip/sys.h"












 

#line 210 "..\\lwIP\\src\\include\\lwip/sys.h"

#line 219 "..\\lwIP\\src\\include\\lwip/sys.h"

#line 228 "..\\lwIP\\src\\include\\lwip/sys.h"

#line 237 "..\\lwIP\\src\\include\\lwip/sys.h"






#line 82 "..\\lwIP\\src\\core\\dhcp.c"
#line 1 "..\\lwIP\\src\\include\\lwip/dhcp.h"

 




#line 8 "..\\lwIP\\src\\include\\lwip/dhcp.h"



#line 12 "..\\lwIP\\src\\include\\lwip/dhcp.h"
#line 13 "..\\lwIP\\src\\include\\lwip/dhcp.h"





 

 

 


struct dhcp
{
   
  u8_t state;
   
  u8_t tries;
    
  u32_t xid;
    
  struct udp_pcb *pcb;
   
  struct pbuf *p;
   
  struct dhcp_msg *msg_in;
   
  struct dhcp_msg *options_in; 
   
  u16_t options_in_len;

  struct pbuf *p_out;  
  struct dhcp_msg *msg_out;  
  u16_t options_out_len;  
  u16_t request_timeout;  
  u16_t t1_timeout;   
  u16_t t2_timeout;   
  struct ip_addr server_ip_addr;  
  struct ip_addr offered_ip_addr;
  struct ip_addr offered_sn_mask;
  struct ip_addr offered_gw_addr;
  struct ip_addr offered_bc_addr;

  u32_t dns_count;  
  struct ip_addr offered_dns_addr[2];  
 
  u32_t offered_t0_lease;  
  u32_t offered_t1_renew;  
  u32_t offered_t2_rebind;  





 




};

 



__packed
 
struct dhcp_msg
{
  u8_t op;
  u8_t htype;
  u8_t hlen;
  u8_t hops;
  u32_t xid;
  u16_t secs;
  u16_t flags;
  struct ip_addr ciaddr;
  struct ip_addr yiaddr;
  struct ip_addr siaddr;
  struct ip_addr giaddr;

  u8_t chaddr[16U];

  u8_t sname[64U];

  u8_t file[128U];
  u32_t cookie;

 



 

 


  u8_t options[68U];
} ;






err_t dhcpsrv_start(struct netif *netif);

 
err_t dhcp_start(struct netif *netif);
 
err_t dhcp_renew(struct netif *netif);
 
err_t dhcp_release(struct netif *netif);
 
void dhcp_stop(struct netif *netif);
 
void dhcp_inform(struct netif *netif);

 

void dhcp_arp_reply(struct netif *netif, struct ip_addr *addr);


 
void dhcp_coarse_tmr(void);
 
void dhcp_fine_tmr(void);
 
 
#line 158 "..\\lwIP\\src\\include\\lwip/dhcp.h"







 
#line 176 "..\\lwIP\\src\\include\\lwip/dhcp.h"
 



 


 



#line 195 "..\\lwIP\\src\\include\\lwip/dhcp.h"








 
#line 214 "..\\lwIP\\src\\include\\lwip/dhcp.h"

 




















#line 242 "..\\lwIP\\src\\include\\lwip/dhcp.h"

 







 











struct dhcp_client{
	u8_t hwaddr[16U];
	u8_t name[64U];
	struct ip_addr ipaddr;
	
	struct dhcp_client *pre;
	struct dhcp_client *next;
};

struct dhcp_srv{
   
  u8_t bitmap[((200-100)/sizeof(u8_t)+1)];
  struct dhcp_client head_node;
  struct dhcp_client *cur_client;
    
  u32_t xid;
    
  struct udp_pcb *pcb;
   
  struct pbuf *p;
   
  struct dhcp_msg *msg_in;
   
  struct dhcp_msg *options_in; 
   
  u16_t options_in_len;

  struct pbuf *p_out;  
  struct dhcp_msg *msg_out;  
  u16_t options_out_len;  
};





















#line 83 "..\\lwIP\\src\\core\\dhcp.c"
#line 1 "..\\lwIP\\src\\include\\ipv4\\lwip/autoip.h"




 




































 
 



#line 48 "..\\lwIP\\src\\include\\ipv4\\lwip/autoip.h"

#line 104 "..\\lwIP\\src\\include\\ipv4\\lwip/autoip.h"

#line 84 "..\\lwIP\\src\\core\\dhcp.c"
#line 1 "..\\lwIP\\src\\include\\lwip/dns.h"































 




#line 38 "..\\lwIP\\src\\include\\lwip/dns.h"



 


 
#line 61 "..\\lwIP\\src\\include\\lwip/dns.h"

 












 
typedef void (*dns_found_callback)(const char *name, struct ip_addr *ipaddr, void *callback_arg);


void           dns_init(void);

void           dns_tmr(void);

void           dns_setserver(u8_t numdns, struct ip_addr *dnsserver);

struct ip_addr dns_getserver(u8_t numdns);

err_t          dns_gethostbyname(const char *hostname, struct ip_addr *addr,
                                 dns_found_callback found, void *callback_arg);
static u32_t dns_lookup(const char *name);








#line 85 "..\\lwIP\\src\\core\\dhcp.c"
#line 1 "..\\lwIP\\src\\include\\netif/etharp.h"
































 




#line 39 "..\\lwIP\\src\\include\\netif/etharp.h"



#line 43 "..\\lwIP\\src\\include\\netif/etharp.h"
#line 44 "..\\lwIP\\src\\include\\netif/etharp.h"
#line 45 "..\\lwIP\\src\\include\\netif/etharp.h"
#line 46 "..\\lwIP\\src\\include\\netif/etharp.h"
















__packed
struct eth_addr {
  u8_t addr[6];
} ;








__packed
struct eth_hdr {



  struct eth_addr dest;
  struct eth_addr src;
  u16_t type;
} ;








__packed
 
struct etharp_hdr {
  struct eth_hdr ethhdr;
  u16_t hwtype;
  u16_t proto;
  u16_t _hwlen_protolen;
  u16_t opcode;
  struct eth_addr shwaddr;
  struct ip_addr2 sipaddr;
  struct eth_addr dhwaddr;
  struct ip_addr2 dipaddr;
} ;








__packed
struct ethip_hdr {
  struct eth_hdr eth;
  struct ip_hdr ip;
} ;





 







 






 
struct etharp_q_entry {
  struct etharp_q_entry *next;
  struct pbuf *p;
};



void etharp_tmr(void);
s8_t etharp_find_addr(struct netif *netif, struct ip_addr *ipaddr,
         struct eth_addr **eth_ret, struct ip_addr **ip_ret);
void etharp_ip_input(struct netif *netif, struct pbuf *p);
void etharp_arp_input(struct netif *netif, struct eth_addr *ethaddr,
         struct pbuf *p);
err_t etharp_output(struct netif *netif, struct pbuf *q, struct ip_addr *ipaddr);
err_t etharp_query(struct netif *netif, struct ip_addr *ipaddr, struct pbuf *q);
err_t etharp_request(struct netif *netif, struct ip_addr *ipaddr);



 


err_t ethernet_input(struct pbuf *p, struct netif *netif);

#line 169 "..\\lwIP\\src\\include\\netif/etharp.h"



extern const struct eth_addr ethbroadcast, ethzero;







#line 86 "..\\lwIP\\src\\core\\dhcp.c"

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



 
#line 88 "..\\lwIP\\src\\core\\dhcp.c"





 





 



 
static void dhcp_handle_ack(struct netif *netif);
static void dhcp_handle_nak(struct netif *netif);
static void dhcp_handle_offer(struct netif *netif);

static err_t dhcp_discover(struct netif *netif);
static err_t dhcp_select(struct netif *netif);
static void dhcp_check(struct netif *netif);
static void dhcp_bind(struct netif *netif);

static err_t dhcp_decline(struct netif *netif);

static err_t dhcp_rebind(struct netif *netif);
static void dhcp_set_state(struct dhcp *dhcp, u8_t new_state);

 
static void dhcp_recv(void *arg, struct udp_pcb *pcb, struct pbuf *p, struct ip_addr *addr, u16_t port);
static err_t dhcp_unfold_reply(struct dhcp *dhcp);
static u8_t *dhcp_get_option_ptr(struct dhcp *dhcp, u8_t option_type);
static u8_t dhcp_get_option_byte(u8_t *ptr);



static u32_t dhcp_get_option_long(u8_t *ptr);
static void dhcp_free_reply(struct dhcp *dhcp);

 
static void dhcp_timeout(struct netif *netif);
static void dhcp_t1_timeout(struct netif *netif);
static void dhcp_t2_timeout(struct netif *netif);

 
 
static err_t dhcp_create_request(struct netif *netif);
 
static void dhcp_delete_request(struct netif *netif);
 
static void dhcp_option(struct dhcp *dhcp, u8_t option_type, u8_t option_len);
 
static void dhcp_option_byte(struct dhcp *dhcp, u8_t value);
static void dhcp_option_short(struct dhcp *dhcp, u16_t value);
static void dhcp_option_long(struct dhcp *dhcp, u32_t value);
 
static void dhcp_option_trailer(struct dhcp *dhcp);












 
static void
dhcp_handle_nak(struct netif *netif)
{
  struct dhcp *dhcp = netif->dhcp;
  do { if ( ((0x00U | 0x40U | 3) & 0x80U) && ((0x00U | 0x40U | 3) & 0x80U) && ((s16_t)((0x00U | 0x40U | 3) & 0x03) >= 0x00)) { do {printf ("dhcp_handle_nak(netif=%p) %c%c%" "4d" "\n", (void*)netif, netif->name[0], netif->name[1], (u16_t)netif->num);} while(0); if ((0x00U | 0x40U | 3) & 0x08U) { while(1); } } } while(0);

   
  netif_set_down(netif);
   
  netif_set_ipaddr(netif, ((struct ip_addr *)&ip_addr_any));
  netif_set_gw(netif, ((struct ip_addr *)&ip_addr_any));
  netif_set_netmask(netif, ((struct ip_addr *)&ip_addr_any)); 
   
  dhcp_set_state(dhcp, 12);
   
  dhcp_discover(netif);
}









 
static void
dhcp_check(struct netif *netif)
{
  struct dhcp *dhcp = netif->dhcp;
  err_t result;
  u16_t msecs;
  do { if ( ((0x00U | 0x40U | 3) & 0x80U) && ((0x00U | 0x40U | 3) & 0x80U) && ((s16_t)((0x00U | 0x40U | 3) & 0x03) >= 0x00)) { do {printf ("dhcp_check(netif=%p) %c%c\n", (void *)netif, (s16_t)netif->name[0], (s16_t)netif->name[1]);} while(0); if ((0x00U | 0x40U | 3) & 0x08U) { while(1); } } } while(0);

  dhcp_set_state(dhcp, 8);
  
 
  result = etharp_query(netif, &dhcp->offered_ip_addr, 0);
  if (result != 0) {
    do { if ( ((0x00U | 0x40U | 2) & 0x80U) && ((0x00U | 0x40U | 2) & 0x80U) && ((s16_t)((0x00U | 0x40U | 2) & 0x03) >= 0x00)) { do {printf ("dhcp_check: could not perform ARP query\n");} while(0); if ((0x00U | 0x40U | 2) & 0x08U) { while(1); } } } while(0);
  }
  dhcp->tries++;
  msecs = 500;
  dhcp->request_timeout = (msecs + 500 - 1) / 500;
  do { if ( ((0x00U | 0x40U | 0x20U) & 0x80U) && ((0x00U | 0x40U | 0x20U) & 0x80U) && ((s16_t)((0x00U | 0x40U | 0x20U) & 0x03) >= 0x00)) { do {printf ("dhcp_check(): set request timeout %" "4d" " msecs\n", msecs);} while(0); if ((0x00U | 0x40U | 0x20U) & 0x08U) { while(1); } } } while(0);
}





 
static void
dhcp_handle_offer(struct netif *netif)
{
  struct dhcp *dhcp = netif->dhcp;
   
  u8_t *option_ptr = dhcp_get_option_ptr(dhcp, 54);
  do { if ( ((0x00U | 0x40U | 3) & 0x80U) && ((0x00U | 0x40U | 3) & 0x80U) && ((s16_t)((0x00U | 0x40U | 3) & 0x03) >= 0x00)) { do {printf ("dhcp_handle_offer(netif=%p) %c%c%" "4d" "\n", (void*)netif, netif->name[0], netif->name[1], (u16_t)netif->num);} while(0); if ((0x00U | 0x40U | 3) & 0x08U) { while(1); } } } while(0);

  if (option_ptr != 0) {
    dhcp->server_ip_addr.addr = htonl(dhcp_get_option_long(&option_ptr[2]));
    do { if ( ((0x00U | 0x20U) & 0x80U) && ((0x00U | 0x20U) & 0x80U) && ((s16_t)((0x00U | 0x20U) & 0x03) >= 0x00)) { do {printf ("dhcp_handle_offer(): server 0x%08" "8lx" "\n", dhcp->server_ip_addr . addr);} while(0); if ((0x00U | 0x20U) & 0x08U) { while(1); } } } while(0);
     
    (&dhcp->offered_ip_addr)->addr = (((struct ip_addr *)&dhcp->msg_in->yiaddr) == 0? 0: ((struct ip_addr *)&dhcp->msg_in->yiaddr)->addr);
    do { if ( ((0x00U | 0x20U) & 0x80U) && ((0x00U | 0x20U) & 0x80U) && ((s16_t)((0x00U | 0x20U) & 0x03) >= 0x00)) { do {printf ("dhcp_handle_offer(): offer for 0x%08" "8lx" "\n", dhcp->offered_ip_addr . addr);} while(0); if ((0x00U | 0x20U) & 0x08U) { while(1); } } } while(0);

    dhcp_select(netif);
  }
}








 
static err_t
dhcp_select(struct netif *netif)
{
  struct dhcp *dhcp = netif->dhcp;
  err_t result;
  u16_t msecs;




  do { if ( ((0x00U | 0x40U | 3) & 0x80U) && ((0x00U | 0x40U | 3) & 0x80U) && ((s16_t)((0x00U | 0x40U | 3) & 0x03) >= 0x00)) { do {printf ("dhcp_select(netif=%p) %c%c%" "4d" "\n", (void*)netif, netif->name[0], netif->name[1], (u16_t)netif->num);} while(0); if ((0x00U | 0x40U | 3) & 0x08U) { while(1); } } } while(0);
  dhcp_set_state(dhcp, 1);

   
  result = dhcp_create_request(netif);
  if (result == 0) {
    dhcp_option(dhcp, 53, 1);
    dhcp_option_byte(dhcp, 3);

    dhcp_option(dhcp, 57, 2);
    dhcp_option_short(dhcp, (netif->mtu));

     
    dhcp_option(dhcp, 50, 4);
    dhcp_option_long(dhcp, ntohl(dhcp->offered_ip_addr.addr));

    dhcp_option(dhcp, 54, 4);
    dhcp_option_long(dhcp, ntohl(dhcp->server_ip_addr.addr));

    dhcp_option(dhcp, 55, 4 );
    dhcp_option_byte(dhcp, 1);
    dhcp_option_byte(dhcp, 3);
    dhcp_option_byte(dhcp, 28);
    dhcp_option_byte(dhcp, 6);

#line 284 "..\\lwIP\\src\\core\\dhcp.c"

    dhcp_option_trailer(dhcp);
     
    pbuf_realloc(dhcp->p_out, sizeof(struct dhcp_msg) - 68U + dhcp->options_out_len);

    
 
     
    udp_sendto_if(dhcp->pcb, dhcp->p_out, ((struct ip_addr *)&ip_addr_broadcast), 67, netif);
     
    udp_connect(dhcp->pcb, ((struct ip_addr *)&ip_addr_any), 67);
    dhcp_delete_request(netif);
    do { if ( ((0x00U | 0x40U | 0x20U) & 0x80U) && ((0x00U | 0x40U | 0x20U) & 0x80U) && ((s16_t)((0x00U | 0x40U | 0x20U) & 0x03) >= 0x00)) { do {printf ("dhcp_select: REQUESTING\n");} while(0); if ((0x00U | 0x40U | 0x20U) & 0x08U) { while(1); } } } while(0);
  } else {
    do { if ( ((0x00U | 0x40U | 2) & 0x80U) && ((0x00U | 0x40U | 2) & 0x80U) && ((s16_t)((0x00U | 0x40U | 2) & 0x03) >= 0x00)) { do {printf ("dhcp_select: could not allocate DHCP request\n");} while(0); if ((0x00U | 0x40U | 2) & 0x08U) { while(1); } } } while(0);
  }
  dhcp->tries++;
  msecs = (dhcp->tries < 6 ? 1 << dhcp->tries : 60) * 1000;
  dhcp->request_timeout = (msecs + 500 - 1) / 500;
  do { if ( ((0x00U | 0x20U) & 0x80U) && ((0x00U | 0x20U) & 0x80U) && ((s16_t)((0x00U | 0x20U) & 0x03) >= 0x00)) { do {printf ("dhcp_select(): set request timeout %" "4d" " msecs\n", msecs);} while(0); if ((0x00U | 0x20U) & 0x08U) { while(1); } } } while(0);
  return result;
}




 
void
dhcp_coarse_tmr()
{
  struct netif *netif = netif_list;
  do { if ( ((0x00U | 0x40U) & 0x80U) && ((0x00U | 0x40U) & 0x80U) && ((s16_t)((0x00U | 0x40U) & 0x03) >= 0x00)) { do {printf ("dhcp_coarse_tmr()\n");} while(0); if ((0x00U | 0x40U) & 0x08U) { while(1); } } } while(0);
   
  while (netif != 0) {
     
    if (netif->dhcp != 0) {
       
      if (netif->dhcp->t2_timeout-- == 1) {
        do { if ( ((0x00U | 0x40U | 0x20U) & 0x80U) && ((0x00U | 0x40U | 0x20U) & 0x80U) && ((s16_t)((0x00U | 0x40U | 0x20U) & 0x03) >= 0x00)) { do {printf ("dhcp_coarse_tmr(): t2 timeout\n");} while(0); if ((0x00U | 0x40U | 0x20U) & 0x08U) { while(1); } } } while(0);
         
        dhcp_t2_timeout(netif);
       
      } else if (netif->dhcp->t1_timeout-- == 1) {
        do { if ( ((0x00U | 0x40U | 0x20U) & 0x80U) && ((0x00U | 0x40U | 0x20U) & 0x80U) && ((s16_t)((0x00U | 0x40U | 0x20U) & 0x03) >= 0x00)) { do {printf ("dhcp_coarse_tmr(): t1 timeout\n");} while(0); if ((0x00U | 0x40U | 0x20U) & 0x08U) { while(1); } } } while(0);
         
        dhcp_t1_timeout(netif);
      }
    }
     
    netif = netif->next;
  }
}







 
void
dhcp_fine_tmr()
{
  struct netif *netif = netif_list;
   
  while (netif != 0) {
     
    if (netif->dhcp != 0) {
             
      if (netif->dhcp->request_timeout > 1) {
        netif->dhcp->request_timeout--;
      }
      else if (netif->dhcp->request_timeout == 1) {
        netif->dhcp->request_timeout--;
         
        do { if ( ((0x00U | 0x40U | 0x20U) & 0x80U) && ((0x00U | 0x40U | 0x20U) & 0x80U) && ((s16_t)((0x00U | 0x40U | 0x20U) & 0x03) >= 0x00)) { do {printf ("dhcp_fine_tmr(): request timeout\n");} while(0); if ((0x00U | 0x40U | 0x20U) & 0x08U) { while(1); } } } while(0);
         
        dhcp_timeout(netif);
      }
    }
     
    netif = netif->next;
  }
}








 
static void
dhcp_timeout(struct netif *netif)
{
  struct dhcp *dhcp = netif->dhcp;
  do { if ( ((0x00U | 0x40U | 3) & 0x80U) && ((0x00U | 0x40U | 3) & 0x80U) && ((s16_t)((0x00U | 0x40U | 3) & 0x03) >= 0x00)) { do {printf ("dhcp_timeout()\n");} while(0); if ((0x00U | 0x40U | 3) & 0x08U) { while(1); } } } while(0);
   
  if ((dhcp->state == 12) || (dhcp->state == 6)) {
    do { if ( ((0x00U | 0x40U) & 0x80U) && ((0x00U | 0x40U) & 0x80U) && ((s16_t)((0x00U | 0x40U) & 0x03) >= 0x00)) { do {printf ("dhcp_timeout(): restarting discovery\n");} while(0); if ((0x00U | 0x40U) & 0x08U) { while(1); } } } while(0);
    dhcp_discover(netif);
   
  } else if (dhcp->state == 1) {
    do { if ( ((0x00U | 0x40U | 0x20U) & 0x80U) && ((0x00U | 0x40U | 0x20U) & 0x80U) && ((s16_t)((0x00U | 0x40U | 0x20U) & 0x03) >= 0x00)) { do {printf ("dhcp_timeout(): REQUESTING, DHCP request timed out\n");} while(0); if ((0x00U | 0x40U | 0x20U) & 0x08U) { while(1); } } } while(0);
    if (dhcp->tries <= 5) {
      dhcp_select(netif);
    } else {
      do { if ( ((0x00U | 0x40U | 0x20U) & 0x80U) && ((0x00U | 0x40U | 0x20U) & 0x80U) && ((s16_t)((0x00U | 0x40U | 0x20U) & 0x03) >= 0x00)) { do {printf ("dhcp_timeout(): REQUESTING, releasing, restarting\n");} while(0); if ((0x00U | 0x40U | 0x20U) & 0x08U) { while(1); } } } while(0);
      dhcp_release(netif);
      dhcp_discover(netif);
    }
   
  } else if (dhcp->state == 8) {
    do { if ( ((0x00U | 0x40U | 0x20U) & 0x80U) && ((0x00U | 0x40U | 0x20U) & 0x80U) && ((s16_t)((0x00U | 0x40U | 0x20U) & 0x03) >= 0x00)) { do {printf ("dhcp_timeout(): CHECKING, ARP request timed out\n");} while(0); if ((0x00U | 0x40U | 0x20U) & 0x08U) { while(1); } } } while(0);
    if (dhcp->tries <= 1) {
      dhcp_check(netif);
    
 
    } else {
       
      dhcp_bind(netif);
    }
  }
   
  else if (dhcp->state == 5) {
    do { if ( ((0x00U | 0x40U | 0x20U) & 0x80U) && ((0x00U | 0x40U | 0x20U) & 0x80U) && ((s16_t)((0x00U | 0x40U | 0x20U) & 0x03) >= 0x00)) { do {printf ("dhcp_timeout(): RENEWING, DHCP request timed out\n");} while(0); if ((0x00U | 0x40U | 0x20U) & 0x08U) { while(1); } } } while(0);
     
     
    dhcp_renew(netif);
   
  } else if (dhcp->state == 4) {
    do { if ( ((0x00U | 0x40U | 0x20U) & 0x80U) && ((0x00U | 0x40U | 0x20U) & 0x80U) && ((s16_t)((0x00U | 0x40U | 0x20U) & 0x03) >= 0x00)) { do {printf ("dhcp_timeout(): REBINDING, DHCP request timed out\n");} while(0); if ((0x00U | 0x40U | 0x20U) & 0x08U) { while(1); } } } while(0);
    if (dhcp->tries <= 8) {
      dhcp_rebind(netif);
    } else {
      do { if ( ((0x00U | 0x40U | 0x20U) & 0x80U) && ((0x00U | 0x40U | 0x20U) & 0x80U) && ((s16_t)((0x00U | 0x40U | 0x20U) & 0x03) >= 0x00)) { do {printf ("dhcp_timeout(): RELEASING, DISCOVERING\n");} while(0); if ((0x00U | 0x40U | 0x20U) & 0x08U) { while(1); } } } while(0);
      dhcp_release(netif);
      dhcp_discover(netif);
    }
  }
}





 
static void
dhcp_t1_timeout(struct netif *netif)
{
  struct dhcp *dhcp = netif->dhcp;
  do { if ( ((0x00U | 0x20U) & 0x80U) && ((0x00U | 0x20U) & 0x80U) && ((s16_t)((0x00U | 0x20U) & 0x03) >= 0x00)) { do {printf ("dhcp_t1_timeout()\n");} while(0); if ((0x00U | 0x20U) & 0x08U) { while(1); } } } while(0);
  if ((dhcp->state == 1) || (dhcp->state == 10) || (dhcp->state == 5)) {
    
 
    do { if ( ((0x00U | 0x40U | 0x20U) & 0x80U) && ((0x00U | 0x40U | 0x20U) & 0x80U) && ((s16_t)((0x00U | 0x40U | 0x20U) & 0x03) >= 0x00)) { do {printf ("dhcp_t1_timeout(): must renew\n");} while(0); if ((0x00U | 0x40U | 0x20U) & 0x08U) { while(1); } } } while(0);
    dhcp_renew(netif);
  }
}





 
static void
dhcp_t2_timeout(struct netif *netif)
{
  struct dhcp *dhcp = netif->dhcp;
  do { if ( ((0x00U | 0x40U | 0x20U) & 0x80U) && ((0x00U | 0x40U | 0x20U) & 0x80U) && ((s16_t)((0x00U | 0x40U | 0x20U) & 0x03) >= 0x00)) { do {printf ("dhcp_t2_timeout()\n");} while(0); if ((0x00U | 0x40U | 0x20U) & 0x08U) { while(1); } } } while(0);
  if ((dhcp->state == 1) || (dhcp->state == 10) || (dhcp->state == 5)) {
     
    do { if ( ((0x00U | 0x40U | 0x20U) & 0x80U) && ((0x00U | 0x40U | 0x20U) & 0x80U) && ((s16_t)((0x00U | 0x40U | 0x20U) & 0x03) >= 0x00)) { do {printf ("dhcp_t2_timeout(): must rebind\n");} while(0); if ((0x00U | 0x40U | 0x20U) & 0x08U) { while(1); } } } while(0);
    dhcp_rebind(netif);
  }
}





 
static void
dhcp_handle_ack(struct netif *netif)
{
  struct dhcp *dhcp = netif->dhcp;
  u8_t *option_ptr;
   
  dhcp->offered_sn_mask.addr = 0;
  dhcp->offered_gw_addr.addr = 0;
  dhcp->offered_bc_addr.addr = 0;

   
  option_ptr = dhcp_get_option_ptr(dhcp, 51);
  if (option_ptr != 0) {
     
    dhcp->offered_t0_lease = dhcp_get_option_long(option_ptr + 2);
  }
   
  option_ptr = dhcp_get_option_ptr(dhcp, 58);
  if (option_ptr != 0) {
     
    dhcp->offered_t1_renew = dhcp_get_option_long(option_ptr + 2);
  } else {
     
    dhcp->offered_t1_renew = dhcp->offered_t0_lease / 2;
  }

   
  option_ptr = dhcp_get_option_ptr(dhcp, 59);
  if (option_ptr != 0) {
     
    dhcp->offered_t2_rebind = dhcp_get_option_long(option_ptr + 2);
  } else {
     
    dhcp->offered_t2_rebind = dhcp->offered_t0_lease;
  }

   
  (&dhcp->offered_ip_addr)->addr = ((&dhcp->msg_in->yiaddr) == 0? 0: (&dhcp->msg_in->yiaddr)->addr);




 
#line 519 "..\\lwIP\\src\\core\\dhcp.c"

   
  option_ptr = dhcp_get_option_ptr(dhcp, 1);
   
  if (option_ptr != 0) {
    dhcp->offered_sn_mask.addr = htonl(dhcp_get_option_long(&option_ptr[2]));
  }

   
  option_ptr = dhcp_get_option_ptr(dhcp, 3);
  if (option_ptr != 0) {
    dhcp->offered_gw_addr.addr = htonl(dhcp_get_option_long(&option_ptr[2]));
  }

   
  option_ptr = dhcp_get_option_ptr(dhcp, 28);
  if (option_ptr != 0) {
    dhcp->offered_bc_addr.addr = htonl(dhcp_get_option_long(&option_ptr[2]));
  }
  
   
  option_ptr = dhcp_get_option_ptr(dhcp, 6);
  if (option_ptr != 0) {
    u8_t n;
    dhcp->dns_count = dhcp_get_option_byte(&option_ptr[1]) / (u32_t)sizeof(struct ip_addr);
     
    if (dhcp->dns_count > 2)
      dhcp->dns_count = 2;
    for (n = 0; n < dhcp->dns_count; n++) {
      dhcp->offered_dns_addr[n].addr = htonl(dhcp_get_option_long(&option_ptr[2 + n * 4]));

      dns_setserver( n, (struct ip_addr *)(&(dhcp->offered_dns_addr[n].addr)));

    }

    dns_setserver( n, (struct ip_addr *)(&ip_addr_any));

  }
}












 
err_t
dhcp_start(struct netif *netif)
{
  struct dhcp *dhcp;
  err_t result = 0;

  do { if (!((netif != 0))) { do { printf("Assertion \"%s\" failed at line %d in %s\n", "netif != NULL", 577, "..\\lwIP\\src\\core\\dhcp.c"); } while(0); return -10;;}} while(0);
  dhcp = netif->dhcp;
  do { if ( ((0x00U | 0x40U | 0x20U) & 0x80U) && ((0x00U | 0x40U | 0x20U) & 0x80U) && ((s16_t)((0x00U | 0x40U | 0x20U) & 0x03) >= 0x00)) { do {printf ("dhcp_start(netif=%p) %c%c%" "4d" "\n", (void*)netif, netif->name[0], netif->name[1], (u16_t)netif->num);} while(0); if ((0x00U | 0x40U | 0x20U) & 0x08U) { while(1); } } } while(0);
  
 
  netif->flags &= ~0x08U;

   
  if (netif->mtu < 576) {
    do { if ( ((0x00U | 0x40U) & 0x80U) && ((0x00U | 0x40U) & 0x80U) && ((s16_t)((0x00U | 0x40U) & 0x03) >= 0x00)) { do {printf ("dhcp_start(): Cannot use this netif with DHCP: MTU is too small\n");} while(0); if ((0x00U | 0x40U) & 0x08U) { while(1); } } } while(0);
    return -1;
  }

   
  if (dhcp == 0) {
    do { if ( ((0x00U | 0x40U) & 0x80U) && ((0x00U | 0x40U) & 0x80U) && ((s16_t)((0x00U | 0x40U) & 0x03) >= 0x00)) { do {printf ("dhcp_start(): starting new DHCP client\n");} while(0); if ((0x00U | 0x40U) & 0x08U) { while(1); } } } while(0);
    dhcp = mem_malloc(sizeof(struct dhcp));
    if (dhcp == 0) {
      do { if ( ((0x00U | 0x40U) & 0x80U) && ((0x00U | 0x40U) & 0x80U) && ((s16_t)((0x00U | 0x40U) & 0x03) >= 0x00)) { do {printf ("dhcp_start(): could not allocate dhcp\n");} while(0); if ((0x00U | 0x40U) & 0x08U) { while(1); } } } while(0);
      return -1;
    }
     
    netif->dhcp = dhcp;
    do { if ( ((0x00U | 0x40U) & 0x80U) && ((0x00U | 0x40U) & 0x80U) && ((s16_t)((0x00U | 0x40U) & 0x03) >= 0x00)) { do {printf ("dhcp_start(): allocated dhcp");} while(0); if ((0x00U | 0x40U) & 0x08U) { while(1); } } } while(0);
   
  } else {
    do { if ( ((0x00U | 0x40U | 0x20U | 3) & 0x80U) && ((0x00U | 0x40U | 0x20U | 3) & 0x80U) && ((s16_t)((0x00U | 0x40U | 0x20U | 3) & 0x03) >= 0x00)) { do {printf ("dhcp_start(): restarting DHCP configuration\n");} while(0); if ((0x00U | 0x40U | 0x20U | 3) & 0x08U) { while(1); } } } while(0);
    if (dhcp->pcb != 0) {
      udp_remove(dhcp->pcb);
    }
    if (dhcp->p != 0) {
      pbuf_free(dhcp->p);
    }
  }
    
   
  memset(dhcp, 0, sizeof(struct dhcp));
   
  dhcp->pcb = udp_new();
  if (dhcp->pcb == 0) {
    do { if ( ((0x00U | 0x40U) & 0x80U) && ((0x00U | 0x40U) & 0x80U) && ((s16_t)((0x00U | 0x40U) & 0x03) >= 0x00)) { do {printf ("dhcp_start(): could not obtain pcb\n");} while(0); if ((0x00U | 0x40U) & 0x08U) { while(1); } } } while(0);
    mem_free((void *)dhcp);
    netif->dhcp = dhcp = 0;
    return -1;
  }



   
  udp_bind(dhcp->pcb, ((struct ip_addr *)&ip_addr_any), 68);
  udp_connect(dhcp->pcb, ((struct ip_addr *)&ip_addr_any), 67);
   
  udp_recv(dhcp->pcb, dhcp_recv, netif);
  do { if ( ((0x00U | 0x40U) & 0x80U) && ((0x00U | 0x40U) & 0x80U) && ((s16_t)((0x00U | 0x40U) & 0x03) >= 0x00)) { do {printf ("dhcp_start(): starting DHCP configuration\n");} while(0); if ((0x00U | 0x40U) & 0x08U) { while(1); } } } while(0);
   
  result = dhcp_discover(netif);
  if (result != 0) {
     
    dhcp_stop(netif);
    return -1;
  }
   
  netif->flags |= 0x08U;
  return result;
}









 
void
dhcp_inform(struct netif *netif)
{
  struct dhcp *dhcp, *old_dhcp = netif->dhcp;
  err_t result = 0;
  dhcp = mem_malloc(sizeof(struct dhcp));
  if (dhcp == 0) {
    do { if ( ((0x00U | 0x40U | 2) & 0x80U) && ((0x00U | 0x40U | 2) & 0x80U) && ((s16_t)((0x00U | 0x40U | 2) & 0x03) >= 0x00)) { do {printf ("dhcp_inform(): could not allocate dhcp\n");} while(0); if ((0x00U | 0x40U | 2) & 0x08U) { while(1); } } } while(0);
    return;
  }
  netif->dhcp = dhcp;
  memset(dhcp, 0, sizeof(struct dhcp));

  do { if ( ((0x00U | 0x40U) & 0x80U) && ((0x00U | 0x40U) & 0x80U) && ((s16_t)((0x00U | 0x40U) & 0x03) >= 0x00)) { do {printf ("dhcp_inform(): allocated dhcp\n");} while(0); if ((0x00U | 0x40U) & 0x08U) { while(1); } } } while(0);
  dhcp->pcb = udp_new();
  if (dhcp->pcb == 0) {
    do { if ( ((0x00U | 0x40U | 2) & 0x80U) && ((0x00U | 0x40U | 2) & 0x80U) && ((s16_t)((0x00U | 0x40U | 2) & 0x03) >= 0x00)) { do {printf ("dhcp_inform(): could not obtain pcb");} while(0); if ((0x00U | 0x40U | 2) & 0x08U) { while(1); } } } while(0);
    mem_free((void *)dhcp);
    return;
  }
  do { if ( ((0x00U | 0x40U) & 0x80U) && ((0x00U | 0x40U) & 0x80U) && ((s16_t)((0x00U | 0x40U) & 0x03) >= 0x00)) { do {printf ("dhcp_inform(): created new udp pcb\n");} while(0); if ((0x00U | 0x40U) & 0x08U) { while(1); } } } while(0);
   
  result = dhcp_create_request(netif);
  if (result == 0) {

    dhcp_option(dhcp, 53, 1);
    dhcp_option_byte(dhcp, 8);

    dhcp_option(dhcp, 57, 2);
    dhcp_option_short(dhcp, (netif->mtu));

    dhcp_option_trailer(dhcp);

    pbuf_realloc(dhcp->p_out, sizeof(struct dhcp_msg) - 68U + dhcp->options_out_len);




    udp_bind(dhcp->pcb, ((struct ip_addr *)&ip_addr_any), 68);
    udp_connect(dhcp->pcb, ((struct ip_addr *)&ip_addr_broadcast), 67);
    do { if ( ((0x00U | 0x40U | 0x20U) & 0x80U) && ((0x00U | 0x40U | 0x20U) & 0x80U) && ((s16_t)((0x00U | 0x40U | 0x20U) & 0x03) >= 0x00)) { do {printf ("dhcp_inform: INFORMING\n");} while(0); if ((0x00U | 0x40U | 0x20U) & 0x08U) { while(1); } } } while(0);
    udp_sendto_if(dhcp->pcb, dhcp->p_out, ((struct ip_addr *)&ip_addr_broadcast), 67, netif);
    udp_connect(dhcp->pcb, ((struct ip_addr *)&ip_addr_any), 67);
    dhcp_delete_request(netif);
  } else {
    do { if ( ((0x00U | 0x40U | 2) & 0x80U) && ((0x00U | 0x40U | 2) & 0x80U) && ((s16_t)((0x00U | 0x40U | 2) & 0x03) >= 0x00)) { do {printf ("dhcp_inform: could not allocate DHCP request\n");} while(0); if ((0x00U | 0x40U | 2) & 0x08U) { while(1); } } } while(0);
  }

  if (dhcp->pcb != 0) {
    udp_remove(dhcp->pcb);
  }
  dhcp->pcb = 0;
  mem_free((void *)dhcp);
  netif->dhcp = old_dhcp;
}







 
void dhcp_arp_reply(struct netif *netif, struct ip_addr *addr)
{
  do { if (!((netif != 0))) { do { printf("Assertion \"%s\" failed at line %d in %s\n", "netif != NULL", 717, "..\\lwIP\\src\\core\\dhcp.c"); } while(0); return;;}} while(0);
  do { if ( ((0x00U | 0x40U | 3) & 0x80U) && ((0x00U | 0x40U | 3) & 0x80U) && ((s16_t)((0x00U | 0x40U | 3) & 0x03) >= 0x00)) { do {printf ("dhcp_arp_reply()\n");} while(0); if ((0x00U | 0x40U | 3) & 0x08U) { while(1); } } } while(0);
   
  if ((netif->dhcp != 0) && (netif->dhcp->state == 8)) {
    do { if ( ((0x00U | 0x40U | 0x20U) & 0x80U) && ((0x00U | 0x40U | 0x20U) & 0x80U) && ((s16_t)((0x00U | 0x40U | 0x20U) & 0x03) >= 0x00)) { do {printf ("dhcp_arp_reply(): CHECKING, arp reply for 0x%08" "8lx" "\n", addr->addr);} while(0); if ((0x00U | 0x40U | 0x20U) & 0x08U) { while(1); } } } while(0);
    
 
    if (((addr)->addr == (&netif->dhcp->offered_ip_addr)->addr)) {
       
      do { if ( ((0x00U | 0x40U | 0x20U | 1) & 0x80U) && ((0x00U | 0x40U | 0x20U | 1) & 0x80U) && ((s16_t)((0x00U | 0x40U | 0x20U | 1) & 0x03) >= 0x00)) { do {printf ("dhcp_arp_reply(): arp reply matched with offered address, declining\n");} while(0); if ((0x00U | 0x40U | 0x20U | 1) & 0x08U) { while(1); } } } while(0);
      dhcp_decline(netif);
    }
  }
}









 
static err_t
dhcp_decline(struct netif *netif)
{
  struct dhcp *dhcp = netif->dhcp;
  err_t result = 0;
  u16_t msecs;
  do { if ( ((0x00U | 0x40U | 3) & 0x80U) && ((0x00U | 0x40U | 3) & 0x80U) && ((s16_t)((0x00U | 0x40U | 3) & 0x03) >= 0x00)) { do {printf ("dhcp_decline()\n");} while(0); if ((0x00U | 0x40U | 3) & 0x08U) { while(1); } } } while(0);
  dhcp_set_state(dhcp, 12);
   
  result = dhcp_create_request(netif);
  if (result == 0) {
    dhcp_option(dhcp, 53, 1);
    dhcp_option_byte(dhcp, 4);

    dhcp_option(dhcp, 50, 4);
    dhcp_option_long(dhcp, ntohl(dhcp->offered_ip_addr.addr));

    dhcp_option_trailer(dhcp);
     
    pbuf_realloc(dhcp->p_out, sizeof(struct dhcp_msg) - 68U + dhcp->options_out_len);

     
    udp_connect(dhcp->pcb, ((struct ip_addr *)&ip_addr_any), 67);
     
    udp_sendto_if(dhcp->pcb, dhcp->p_out, ((struct ip_addr *)&ip_addr_broadcast), 67, netif);
    dhcp_delete_request(netif);
    do { if ( ((0x00U | 0x40U | 0x20U) & 0x80U) && ((0x00U | 0x40U | 0x20U) & 0x80U) && ((s16_t)((0x00U | 0x40U | 0x20U) & 0x03) >= 0x00)) { do {printf ("dhcp_decline: BACKING OFF\n");} while(0); if ((0x00U | 0x40U | 0x20U) & 0x08U) { while(1); } } } while(0);
  } else {
    do { if ( ((0x00U | 0x40U | 2) & 0x80U) && ((0x00U | 0x40U | 2) & 0x80U) && ((s16_t)((0x00U | 0x40U | 2) & 0x03) >= 0x00)) { do {printf ("dhcp_decline: could not allocate DHCP request\n");} while(0); if ((0x00U | 0x40U | 2) & 0x08U) { while(1); } } } while(0);
  }
  dhcp->tries++;
  msecs = 10*1000;
  dhcp->request_timeout = (msecs + 500 - 1) / 500;
  do { if ( ((0x00U | 0x40U) & 0x80U) && ((0x00U | 0x40U) & 0x80U) && ((s16_t)((0x00U | 0x40U) & 0x03) >= 0x00)) { do {printf ("dhcp_decline(): set request timeout %" "4d" " msecs\n", msecs);} while(0); if ((0x00U | 0x40U) & 0x08U) { while(1); } } } while(0);
  return result;
}







 
static err_t
dhcp_discover(struct netif *netif)
{
  struct dhcp *dhcp = netif->dhcp;
  err_t result = 0;
  u16_t msecs;
  do { if ( ((0x00U | 0x40U | 3) & 0x80U) && ((0x00U | 0x40U | 3) & 0x80U) && ((s16_t)((0x00U | 0x40U | 3) & 0x03) >= 0x00)) { do {printf ("dhcp_discover()\n");} while(0); if ((0x00U | 0x40U | 3) & 0x08U) { while(1); } } } while(0);
  (&dhcp->offered_ip_addr)->addr = ((((struct ip_addr *)&ip_addr_any)) == 0? 0: (((struct ip_addr *)&ip_addr_any))->addr);
  dhcp_set_state(dhcp, 6);
   
  result = dhcp_create_request(netif);
  if (result == 0) {
    do { if ( ((0x00U | 0x40U) & 0x80U) && ((0x00U | 0x40U) & 0x80U) && ((s16_t)((0x00U | 0x40U) & 0x03) >= 0x00)) { do {printf ("dhcp_discover: making request\n");} while(0); if ((0x00U | 0x40U) & 0x08U) { while(1); } } } while(0);
    dhcp_option(dhcp, 53, 1);
    dhcp_option_byte(dhcp, 1);

    dhcp_option(dhcp, 57, 2);
    dhcp_option_short(dhcp, (netif->mtu));

    dhcp_option(dhcp, 55, 4 );
    dhcp_option_byte(dhcp, 1);
    dhcp_option_byte(dhcp, 3);
    dhcp_option_byte(dhcp, 28);
    dhcp_option_byte(dhcp, 6);

    dhcp_option_trailer(dhcp);

    do { if ( ((0x00U | 0x40U) & 0x80U) && ((0x00U | 0x40U) & 0x80U) && ((s16_t)((0x00U | 0x40U) & 0x03) >= 0x00)) { do {printf ("dhcp_discover: realloc()ing\n");} while(0); if ((0x00U | 0x40U) & 0x08U) { while(1); } } } while(0);
    pbuf_realloc(dhcp->p_out, sizeof(struct dhcp_msg) - 68U + dhcp->options_out_len);

    udp_connect(dhcp->pcb, ((struct ip_addr *)&ip_addr_any), 67);
    do { if ( ((0x00U | 0x40U) & 0x80U) && ((0x00U | 0x40U) & 0x80U) && ((s16_t)((0x00U | 0x40U) & 0x03) >= 0x00)) { do {printf ("dhcp_discover: sendto(DISCOVER, IP_ADDR_BROADCAST, DHCP_SERVER_PORT)\n");} while(0); if ((0x00U | 0x40U) & 0x08U) { while(1); } } } while(0);
    udp_sendto_if(dhcp->pcb, dhcp->p_out, ((struct ip_addr *)&ip_addr_broadcast), 67, netif);
    do { if ( ((0x00U | 0x40U) & 0x80U) && ((0x00U | 0x40U) & 0x80U) && ((s16_t)((0x00U | 0x40U) & 0x03) >= 0x00)) { do {printf ("dhcp_discover: deleting()ing\n");} while(0); if ((0x00U | 0x40U) & 0x08U) { while(1); } } } while(0);
    dhcp_delete_request(netif);
    do { if ( ((0x00U | 0x40U | 0x20U) & 0x80U) && ((0x00U | 0x40U | 0x20U) & 0x80U) && ((s16_t)((0x00U | 0x40U | 0x20U) & 0x03) >= 0x00)) { do {printf ("dhcp_discover: SELECTING\n");} while(0); if ((0x00U | 0x40U | 0x20U) & 0x08U) { while(1); } } } while(0);
  } else {
    do { if ( ((0x00U | 0x40U | 2) & 0x80U) && ((0x00U | 0x40U | 2) & 0x80U) && ((s16_t)((0x00U | 0x40U | 2) & 0x03) >= 0x00)) { do {printf ("dhcp_discover: could not allocate DHCP request\n");} while(0); if ((0x00U | 0x40U | 2) & 0x08U) { while(1); } } } while(0);
  }
  dhcp->tries++;
#line 831 "..\\lwIP\\src\\core\\dhcp.c"
  msecs = (dhcp->tries < 6 ? 1 << dhcp->tries : 60) * 1000;
  dhcp->request_timeout = (msecs + 500 - 1) / 500;
  do { if ( ((0x00U | 0x40U | 0x20U) & 0x80U) && ((0x00U | 0x40U | 0x20U) & 0x80U) && ((s16_t)((0x00U | 0x40U | 0x20U) & 0x03) >= 0x00)) { do {printf ("dhcp_discover(): set request timeout %" "4d" " msecs\n", msecs);} while(0); if ((0x00U | 0x40U | 0x20U) & 0x08U) { while(1); } } } while(0);
  return result;
}






 
static void
dhcp_bind(struct netif *netif)
{
  u32_t timeout;
  struct dhcp *dhcp;
  struct ip_addr sn_mask, gw_addr;
  do { if (!((netif != 0))) { do { printf("Assertion \"%s\" failed at line %d in %s\n", "dhcp_bind: netif != NULL", 849, "..\\lwIP\\src\\core\\dhcp.c"); } while(0); return;;}} while(0);
  dhcp = netif->dhcp;
  do { if (!((dhcp != 0))) { do { printf("Assertion \"%s\" failed at line %d in %s\n", "dhcp_bind: dhcp != NULL", 851, "..\\lwIP\\src\\core\\dhcp.c"); } while(0); return;;}} while(0);
  do { if ( ((0x00U | 0x40U | 3) & 0x80U) && ((0x00U | 0x40U | 3) & 0x80U) && ((s16_t)((0x00U | 0x40U | 3) & 0x03) >= 0x00)) { do {printf ("dhcp_bind(netif=%p) %c%c%" "4d" "\n", (void*)netif, netif->name[0], netif->name[1], (u16_t)netif->num);} while(0); if ((0x00U | 0x40U | 3) & 0x08U) { while(1); } } } while(0);

   
  if (dhcp->offered_t1_renew != 0xffffffffUL) {
     
    do { if ( ((0x00U | 0x40U) & 0x80U) && ((0x00U | 0x40U) & 0x80U) && ((s16_t)((0x00U | 0x40U) & 0x03) >= 0x00)) { do {printf ("dhcp_bind(): t1 renewal timer %" "8ld" " secs\n", dhcp->offered_t1_renew);} while(0); if ((0x00U | 0x40U) & 0x08U) { while(1); } } } while(0);
    timeout = (dhcp->offered_t1_renew + 60 / 2) / 60;
    if(timeout > 0xffff) {
      timeout = 0xffff;
    }
    dhcp->t1_timeout = (u16_t)timeout;
    if (dhcp->t1_timeout == 0) {
      dhcp->t1_timeout = 1;
    }
    do { if ( ((0x00U | 0x40U | 0x20U) & 0x80U) && ((0x00U | 0x40U | 0x20U) & 0x80U) && ((s16_t)((0x00U | 0x40U | 0x20U) & 0x03) >= 0x00)) { do {printf ("dhcp_bind(): set request timeout %" "8ld" " msecs\n", dhcp->offered_t1_renew*1000);} while(0); if ((0x00U | 0x40U | 0x20U) & 0x08U) { while(1); } } } while(0);
  }
   
  if (dhcp->offered_t2_rebind != 0xffffffffUL) {
    do { if ( ((0x00U | 0x40U) & 0x80U) && ((0x00U | 0x40U) & 0x80U) && ((s16_t)((0x00U | 0x40U) & 0x03) >= 0x00)) { do {printf ("dhcp_bind(): t2 rebind timer %" "8ld" " secs\n", dhcp->offered_t2_rebind);} while(0); if ((0x00U | 0x40U) & 0x08U) { while(1); } } } while(0);
    timeout = (dhcp->offered_t2_rebind + 60 / 2) / 60;
    if(timeout > 0xffff) {
      timeout = 0xffff;
    }
    dhcp->t2_timeout = (u16_t)timeout;
    if (dhcp->t2_timeout == 0) {
      dhcp->t2_timeout = 1;
    }
    do { if ( ((0x00U | 0x40U | 0x20U) & 0x80U) && ((0x00U | 0x40U | 0x20U) & 0x80U) && ((s16_t)((0x00U | 0x40U | 0x20U) & 0x03) >= 0x00)) { do {printf ("dhcp_bind(): set request timeout %" "8ld" " msecs\n", dhcp->offered_t2_rebind*1000);} while(0); if ((0x00U | 0x40U | 0x20U) & 0x08U) { while(1); } } } while(0);
  }
   
  (&sn_mask)->addr = ((&dhcp->offered_sn_mask) == 0? 0: (&dhcp->offered_sn_mask)->addr);

   
   
  if (sn_mask.addr == 0) {
     
    u8_t first_octet = ((u16_t)(ntohl((&sn_mask)->addr) >> 24) & 0xff);
    if (first_octet <= 127) {
      sn_mask.addr = htonl(0xff000000);
    } else if (first_octet >= 192) {
      sn_mask.addr = htonl(0xffffff00);
    } else {
      sn_mask.addr = htonl(0xffff0000);
    }
  }

  (&gw_addr)->addr = ((&dhcp->offered_gw_addr) == 0? 0: (&dhcp->offered_gw_addr)->addr);
   
  if (gw_addr.addr == 0) {
     
    gw_addr.addr = (dhcp->offered_ip_addr.addr & sn_mask.addr);
     
    gw_addr.addr |= htonl(0x00000001);
  }

#line 913 "..\\lwIP\\src\\core\\dhcp.c"

  do { if ( ((0x00U | 0x20U) & 0x80U) && ((0x00U | 0x20U) & 0x80U) && ((s16_t)((0x00U | 0x20U) & 0x03) >= 0x00)) { do {printf ("dhcp_bind(): IP: 0x%08" "8lx" "\n", dhcp->offered_ip_addr . addr);} while(0); if ((0x00U | 0x20U) & 0x08U) { while(1); } } } while(0);
  netif_set_ipaddr(netif, &dhcp->offered_ip_addr);
  do { if ( ((0x00U | 0x20U) & 0x80U) && ((0x00U | 0x20U) & 0x80U) && ((s16_t)((0x00U | 0x20U) & 0x03) >= 0x00)) { do {printf ("dhcp_bind(): SN: 0x%08" "8lx" "\n", sn_mask . addr);} while(0); if ((0x00U | 0x20U) & 0x08U) { while(1); } } } while(0);
  netif_set_netmask(netif, &sn_mask);
  do { if ( ((0x00U | 0x20U) & 0x80U) && ((0x00U | 0x20U) & 0x80U) && ((s16_t)((0x00U | 0x20U) & 0x03) >= 0x00)) { do {printf ("dhcp_bind(): GW: 0x%08" "8lx" "\n", gw_addr . addr);} while(0); if ((0x00U | 0x20U) & 0x08U) { while(1); } } } while(0);
  netif_set_gw(netif, &gw_addr);
   
  netif_set_up(netif);
   
  dhcp_set_state(dhcp, 10);
}





 
err_t
dhcp_renew(struct netif *netif)
{
  struct dhcp *dhcp = netif->dhcp;
  err_t result;
  u16_t msecs;



  do { if ( ((0x00U | 0x40U | 3) & 0x80U) && ((0x00U | 0x40U | 3) & 0x80U) && ((s16_t)((0x00U | 0x40U | 3) & 0x03) >= 0x00)) { do {printf ("dhcp_renew()\n");} while(0); if ((0x00U | 0x40U | 3) & 0x08U) { while(1); } } } while(0);
  dhcp_set_state(dhcp, 5);

   
  result = dhcp_create_request(netif);
  if (result == 0) {

    dhcp_option(dhcp, 53, 1);
    dhcp_option_byte(dhcp, 3);

    dhcp_option(dhcp, 57, 2);
    dhcp_option_short(dhcp, (netif->mtu));

#line 962 "..\\lwIP\\src\\core\\dhcp.c"










     
    dhcp_option_trailer(dhcp);

    pbuf_realloc(dhcp->p_out, sizeof(struct dhcp_msg) - 68U + dhcp->options_out_len);

    udp_connect(dhcp->pcb, &dhcp->server_ip_addr, 67);
    udp_sendto_if(dhcp->pcb, dhcp->p_out, &dhcp->server_ip_addr, 67, netif);
    dhcp_delete_request(netif);

    do { if ( ((0x00U | 0x40U | 0x20U) & 0x80U) && ((0x00U | 0x40U | 0x20U) & 0x80U) && ((s16_t)((0x00U | 0x40U | 0x20U) & 0x03) >= 0x00)) { do {printf ("dhcp_renew: RENEWING\n");} while(0); if ((0x00U | 0x40U | 0x20U) & 0x08U) { while(1); } } } while(0);
  } else {
    do { if ( ((0x00U | 0x40U | 2) & 0x80U) && ((0x00U | 0x40U | 2) & 0x80U) && ((s16_t)((0x00U | 0x40U | 2) & 0x03) >= 0x00)) { do {printf ("dhcp_renew: could not allocate DHCP request\n");} while(0); if ((0x00U | 0x40U | 2) & 0x08U) { while(1); } } } while(0);
  }
  dhcp->tries++;
   
  msecs = dhcp->tries < 10 ? dhcp->tries * 2000 : 20 * 1000;
  dhcp->request_timeout = (msecs + 500 - 1) / 500;
  do { if ( ((0x00U | 0x40U | 0x20U) & 0x80U) && ((0x00U | 0x40U | 0x20U) & 0x80U) && ((s16_t)((0x00U | 0x40U | 0x20U) & 0x03) >= 0x00)) { do {printf ("dhcp_renew(): set request timeout %" "4d" " msecs\n", msecs);} while(0); if ((0x00U | 0x40U | 0x20U) & 0x08U) { while(1); } } } while(0);
  return result;
}





 
static err_t
dhcp_rebind(struct netif *netif)
{
  struct dhcp *dhcp = netif->dhcp;
  err_t result;
  u16_t msecs;



  do { if ( ((0x00U | 0x40U | 0x20U) & 0x80U) && ((0x00U | 0x40U | 0x20U) & 0x80U) && ((s16_t)((0x00U | 0x40U | 0x20U) & 0x03) >= 0x00)) { do {printf ("dhcp_rebind()\n");} while(0); if ((0x00U | 0x40U | 0x20U) & 0x08U) { while(1); } } } while(0);
  dhcp_set_state(dhcp, 4);

   
  result = dhcp_create_request(netif);
  if (result == 0) {

    dhcp_option(dhcp, 53, 1);
    dhcp_option_byte(dhcp, 3);

    dhcp_option(dhcp, 57, 2);
    dhcp_option_short(dhcp, (netif->mtu));

#line 1029 "..\\lwIP\\src\\core\\dhcp.c"

#line 1037 "..\\lwIP\\src\\core\\dhcp.c"

    dhcp_option_trailer(dhcp);

    pbuf_realloc(dhcp->p_out, sizeof(struct dhcp_msg) - 68U + dhcp->options_out_len);

     
    udp_connect(dhcp->pcb, ((struct ip_addr *)&ip_addr_any), 67);
    udp_sendto_if(dhcp->pcb, dhcp->p_out, ((struct ip_addr *)&ip_addr_broadcast), 67, netif);
    dhcp_delete_request(netif);
    do { if ( ((0x00U | 0x40U | 0x20U) & 0x80U) && ((0x00U | 0x40U | 0x20U) & 0x80U) && ((s16_t)((0x00U | 0x40U | 0x20U) & 0x03) >= 0x00)) { do {printf ("dhcp_rebind: REBINDING\n");} while(0); if ((0x00U | 0x40U | 0x20U) & 0x08U) { while(1); } } } while(0);
  } else {
    do { if ( ((0x00U | 0x40U | 2) & 0x80U) && ((0x00U | 0x40U | 2) & 0x80U) && ((s16_t)((0x00U | 0x40U | 2) & 0x03) >= 0x00)) { do {printf ("dhcp_rebind: could not allocate DHCP request\n");} while(0); if ((0x00U | 0x40U | 2) & 0x08U) { while(1); } } } while(0);
  }
  dhcp->tries++;
  msecs = dhcp->tries < 10 ? dhcp->tries * 1000 : 10 * 1000;
  dhcp->request_timeout = (msecs + 500 - 1) / 500;
  do { if ( ((0x00U | 0x40U | 0x20U) & 0x80U) && ((0x00U | 0x40U | 0x20U) & 0x80U) && ((s16_t)((0x00U | 0x40U | 0x20U) & 0x03) >= 0x00)) { do {printf ("dhcp_rebind(): set request timeout %" "4d" " msecs\n", msecs);} while(0); if ((0x00U | 0x40U | 0x20U) & 0x08U) { while(1); } } } while(0);
  return result;
}





 
err_t
dhcp_release(struct netif *netif)
{
  struct dhcp *dhcp = netif->dhcp;
  err_t result;
  u16_t msecs;
  do { if ( ((0x00U | 0x40U | 3) & 0x80U) && ((0x00U | 0x40U | 3) & 0x80U) && ((s16_t)((0x00U | 0x40U | 3) & 0x03) >= 0x00)) { do {printf ("dhcp_release()\n");} while(0); if ((0x00U | 0x40U | 3) & 0x08U) { while(1); } } } while(0);

   
  dhcp_set_state(dhcp, 13);
   
  dhcp->server_ip_addr.addr = 0;
  dhcp->offered_ip_addr.addr = dhcp->offered_sn_mask.addr = 0;
  dhcp->offered_gw_addr.addr = dhcp->offered_bc_addr.addr = 0;
  dhcp->offered_t0_lease = dhcp->offered_t1_renew = dhcp->offered_t2_rebind = 0;
  dhcp->dns_count = 0;
  
   
  result = dhcp_create_request(netif);
  if (result == 0) {
    dhcp_option(dhcp, 53, 1);
    dhcp_option_byte(dhcp, 7);

    dhcp_option_trailer(dhcp);

    pbuf_realloc(dhcp->p_out, sizeof(struct dhcp_msg) - 68U + dhcp->options_out_len);

    udp_connect(dhcp->pcb, &dhcp->server_ip_addr, 67);
    udp_sendto_if(dhcp->pcb, dhcp->p_out, &dhcp->server_ip_addr, 67, netif);
    dhcp_delete_request(netif);
    do { if ( ((0x00U | 0x40U | 0x20U) & 0x80U) && ((0x00U | 0x40U | 0x20U) & 0x80U) && ((s16_t)((0x00U | 0x40U | 0x20U) & 0x03) >= 0x00)) { do {printf ("dhcp_release: RELEASED, DHCP_OFF\n");} while(0); if ((0x00U | 0x40U | 0x20U) & 0x08U) { while(1); } } } while(0);
  } else {
    do { if ( ((0x00U | 0x40U | 2) & 0x80U) && ((0x00U | 0x40U | 2) & 0x80U) && ((s16_t)((0x00U | 0x40U | 2) & 0x03) >= 0x00)) { do {printf ("dhcp_release: could not allocate DHCP request\n");} while(0); if ((0x00U | 0x40U | 2) & 0x08U) { while(1); } } } while(0);
  }
  dhcp->tries++;
  msecs = dhcp->tries < 10 ? dhcp->tries * 1000 : 10 * 1000;
  dhcp->request_timeout = (msecs + 500 - 1) / 500;
  do { if ( ((0x00U | 0x40U | 0x20U) & 0x80U) && ((0x00U | 0x40U | 0x20U) & 0x80U) && ((s16_t)((0x00U | 0x40U | 0x20U) & 0x03) >= 0x00)) { do {printf ("dhcp_release(): set request timeout %" "4d" " msecs\n", msecs);} while(0); if ((0x00U | 0x40U | 0x20U) & 0x08U) { while(1); } } } while(0);
   
  netif_set_down(netif);
   
  netif_set_ipaddr(netif, ((struct ip_addr *)&ip_addr_any));
  netif_set_gw(netif, ((struct ip_addr *)&ip_addr_any));
  netif_set_netmask(netif, ((struct ip_addr *)&ip_addr_any));
  
   
  return result;
}





 
void
dhcp_stop(struct netif *netif)
{
  struct dhcp *dhcp = netif->dhcp;
  do { if (!((netif != 0))) { do { printf("Assertion \"%s\" failed at line %d in %s\n", "dhcp_stop: netif != NULL", 1120, "..\\lwIP\\src\\core\\dhcp.c"); } while(0); return;;}} while(0);
   
  netif->flags &= ~0x08U;

  do { if ( ((0x00U | 0x40U | 3) & 0x80U) && ((0x00U | 0x40U | 3) & 0x80U) && ((s16_t)((0x00U | 0x40U | 3) & 0x03) >= 0x00)) { do {printf ("dhcp_stop()\n");} while(0); if ((0x00U | 0x40U | 3) & 0x08U) { while(1); } } } while(0);
   
  if (dhcp != 0) {
#line 1133 "..\\lwIP\\src\\core\\dhcp.c"

    if (dhcp->pcb != 0) {
      udp_remove(dhcp->pcb);
      dhcp->pcb = 0;
    }
    if (dhcp->p != 0) {
      pbuf_free(dhcp->p);
      dhcp->p = 0;
    }
     
    dhcp_free_reply(dhcp);
    mem_free((void *)dhcp);
    netif->dhcp = 0;
  }
}







 
static void
dhcp_set_state(struct dhcp *dhcp, u8_t new_state)
{
  if (new_state != dhcp->state) {
    dhcp->state = new_state;
    dhcp->tries = 0;
  }
}





 
static void
dhcp_option(struct dhcp *dhcp, u8_t option_type, u8_t option_len)
{
  ;
  dhcp->msg_out->options[dhcp->options_out_len++] = option_type;
  dhcp->msg_out->options[dhcp->options_out_len++] = option_len;
}



 
static void
dhcp_option_byte(struct dhcp *dhcp, u8_t value)
{
  ;
  dhcp->msg_out->options[dhcp->options_out_len++] = value;
}

static void
dhcp_option_short(struct dhcp *dhcp, u16_t value)
{
  ;
  dhcp->msg_out->options[dhcp->options_out_len++] = (u8_t)((value & 0xff00U) >> 8);
  dhcp->msg_out->options[dhcp->options_out_len++] = (u8_t) (value & 0x00ffU);
}

static void
dhcp_option_long(struct dhcp *dhcp, u32_t value)
{
  ;
  dhcp->msg_out->options[dhcp->options_out_len++] = (u8_t)((value & 0xff000000UL) >> 24);
  dhcp->msg_out->options[dhcp->options_out_len++] = (u8_t)((value & 0x00ff0000UL) >> 16);
  dhcp->msg_out->options[dhcp->options_out_len++] = (u8_t)((value & 0x0000ff00UL) >> 8);
  dhcp->msg_out->options[dhcp->options_out_len++] = (u8_t)((value & 0x000000ffUL));
}










 
static err_t
dhcp_unfold_reply(struct dhcp *dhcp)
{
  u16_t ret;
  do { if (!((dhcp != 0))) { do { printf("Assertion \"%s\" failed at line %d in %s\n", "dhcp != NULL", 1220, "..\\lwIP\\src\\core\\dhcp.c"); } while(0); return -10;;}} while(0);
  do { if (!((dhcp->p != 0))) { do { printf("Assertion \"%s\" failed at line %d in %s\n", "dhcp->p != NULL", 1221, "..\\lwIP\\src\\core\\dhcp.c"); } while(0); return -9;;}} while(0);
   
  dhcp_free_reply(dhcp);
   
  if (dhcp->p->tot_len > (sizeof(struct dhcp_msg) - 68U)) {
    dhcp->options_in_len = dhcp->p->tot_len - (sizeof(struct dhcp_msg) - 68U);
    dhcp->options_in = mem_malloc(dhcp->options_in_len);
    if (dhcp->options_in == 0) {
      do { if ( ((0x00U | 0x40U | 2) & 0x80U) && ((0x00U | 0x40U | 2) & 0x80U) && ((s16_t)((0x00U | 0x40U | 2) & 0x03) >= 0x00)) { do {printf ("dhcp_unfold_reply(): could not allocate dhcp->options\n");} while(0); if ((0x00U | 0x40U | 2) & 0x08U) { while(1); } } } while(0);
      return -1;
    }
  }
  dhcp->msg_in = mem_malloc(sizeof(struct dhcp_msg) - 68U);
  if (dhcp->msg_in == 0) {
    do { if ( ((0x00U | 0x40U | 2) & 0x80U) && ((0x00U | 0x40U | 2) & 0x80U) && ((s16_t)((0x00U | 0x40U | 2) & 0x03) >= 0x00)) { do {printf ("dhcp_unfold_reply(): could not allocate dhcp->msg_in\n");} while(0); if ((0x00U | 0x40U | 2) & 0x08U) { while(1); } } } while(0);
    mem_free((void *)dhcp->options_in);
    dhcp->options_in = 0;
    return -1;
  }

   
  ret = pbuf_copy_partial(dhcp->p, dhcp->msg_in, sizeof(struct dhcp_msg) - 68U, 0);
  ;
  do { if ( ((0x00U | 0x40U) & 0x80U) && ((0x00U | 0x40U) & 0x80U) && ((s16_t)((0x00U | 0x40U) & 0x03) >= 0x00)) { do {printf ("dhcp_unfold_reply(): copied %" "4d" " bytes into dhcp->msg_in[]\n", sizeof(struct dhcp_msg) - 68U);} while(0); if ((0x00U | 0x40U) & 0x08U) { while(1); } } } while(0);


  if (dhcp->options_in != 0) {
     
    ret = pbuf_copy_partial(dhcp->p, dhcp->options_in, dhcp->options_in_len, sizeof(struct dhcp_msg) - 68U);
    ;
    do { if ( ((0x00U | 0x40U) & 0x80U) && ((0x00U | 0x40U) & 0x80U) && ((s16_t)((0x00U | 0x40U) & 0x03) >= 0x00)) { do {printf ("dhcp_unfold_reply(): copied %" "4d" " bytes to dhcp->options_in[]\n", dhcp->options_in_len);} while(0); if ((0x00U | 0x40U) & 0x08U) { while(1); } } } while(0);

  }
  (void)ret;
  return 0;
}





 
static void dhcp_free_reply(struct dhcp *dhcp)
{
  if (dhcp->msg_in != 0) {
    mem_free((void *)dhcp->msg_in);
    dhcp->msg_in = 0;
  }
  if (dhcp->options_in) {
    mem_free((void *)dhcp->options_in);
    dhcp->options_in = 0;
    dhcp->options_in_len = 0;
  }
  do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("dhcp_free_reply(): free'd\n");} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
}




 
static void dhcp_recv(void *arg, struct udp_pcb *pcb, struct pbuf *p, struct ip_addr *addr, u16_t port)
{
  struct netif *netif = (struct netif *)arg;
  struct dhcp *dhcp = netif->dhcp;
  struct dhcp_msg *reply_msg = (struct dhcp_msg *)p->payload;
  u8_t *options_ptr;
  u8_t msg_type;
  u8_t i;
  do { if ( ((0x00U | 0x40U | 3) & 0x80U) && ((0x00U | 0x40U | 3) & 0x80U) && ((s16_t)((0x00U | 0x40U | 3) & 0x03) >= 0x00)) { do {printf ("dhcp_recv(pbuf = %p) from DHCP server %" "4d" ".%" "4d" ".%" "4d" ".%" "4d" " port %" "4d" "\n", (void*)p, (u16_t)(ntohl(addr->addr) >> 24 & 0xff), (u16_t)(ntohl(addr->addr) >> 16 & 0xff), (u16_t)(ntohl(addr->addr) >> 8 & 0xff), (u16_t)(ntohl(addr->addr) & 0xff), port);} while(0); if ((0x00U | 0x40U | 3) & 0x08U) { while(1); } } } while(0);


  do { if ( ((0x00U | 0x40U) & 0x80U) && ((0x00U | 0x40U) & 0x80U) && ((s16_t)((0x00U | 0x40U) & 0x03) >= 0x00)) { do {printf ("pbuf->len = %" "4d" "\n", p->len);} while(0); if ((0x00U | 0x40U) & 0x08U) { while(1); } } } while(0);
  do { if ( ((0x00U | 0x40U) & 0x80U) && ((0x00U | 0x40U) & 0x80U) && ((s16_t)((0x00U | 0x40U) & 0x03) >= 0x00)) { do {printf ("pbuf->tot_len = %" "4d" "\n", p->tot_len);} while(0); if ((0x00U | 0x40U) & 0x08U) { while(1); } } } while(0);
   
  (void)pcb;
  (void)addr;
  (void)port;
  dhcp->p = p;
   
  if (reply_msg->op != 2) {
    do { if ( ((0x00U | 0x40U | 1) & 0x80U) && ((0x00U | 0x40U | 1) & 0x80U) && ((s16_t)((0x00U | 0x40U | 1) & 0x03) >= 0x00)) { do {printf ("not a DHCP reply message, but type %" "4d" "\n", (u16_t)reply_msg->op);} while(0); if ((0x00U | 0x40U | 1) & 0x08U) { while(1); } } } while(0);
    goto free_pbuf_and_return;
  }
   
  for (i = 0; i < netif->hwaddr_len; i++) {
    if (netif->hwaddr[i] != reply_msg->chaddr[i]) {
      do { if ( ((0x00U | 0x40U | 2) & 0x80U) && ((0x00U | 0x40U | 2) & 0x80U) && ((s16_t)((0x00U | 0x40U | 2) & 0x03) >= 0x00)) { do {printf ("netif->hwaddr[%" "4d" "]==%02" "4x" " != reply_msg->chaddr[%" "4d" "]==%02" "4x" "\n", (u16_t)i, (u16_t)netif->hwaddr[i], (u16_t)i, (u16_t)reply_msg->chaddr[i]);} while(0); if ((0x00U | 0x40U | 2) & 0x08U) { while(1); } } } while(0);

      goto free_pbuf_and_return;
    }
  }
   
  if (ntohl(reply_msg->xid) != dhcp->xid) {
    do { if ( ((0x00U | 0x40U | 2) & 0x80U) && ((0x00U | 0x40U | 2) & 0x80U) && ((s16_t)((0x00U | 0x40U | 2) & 0x03) >= 0x00)) { do {printf ("transaction id mismatch reply_msg->xid(%" "8lx" ")!=dhcp->xid(%" "8lx" ")\n",ntohl(reply_msg->xid),dhcp->xid);} while(0); if ((0x00U | 0x40U | 2) & 0x08U) { while(1); } } } while(0);
    goto free_pbuf_and_return;
  }
   
  if (dhcp_unfold_reply(dhcp) != 0) {
    do { if ( ((0x00U | 0x40U | 2) & 0x80U) && ((0x00U | 0x40U | 2) & 0x80U) && ((s16_t)((0x00U | 0x40U | 2) & 0x03) >= 0x00)) { do {printf ("problem unfolding DHCP message - too short on memory?\n");} while(0); if ((0x00U | 0x40U | 2) & 0x08U) { while(1); } } } while(0);
    goto free_pbuf_and_return;
  }

  do { if ( ((0x00U | 0x40U) & 0x80U) && ((0x00U | 0x40U) & 0x80U) && ((s16_t)((0x00U | 0x40U) & 0x03) >= 0x00)) { do {printf ("searching DHCP_OPTION_MESSAGE_TYPE\n");} while(0); if ((0x00U | 0x40U) & 0x08U) { while(1); } } } while(0);
   
  options_ptr = dhcp_get_option_ptr(dhcp, 53);
  if (options_ptr == 0) {
    do { if ( ((0x00U | 0x40U | 1) & 0x80U) && ((0x00U | 0x40U | 1) & 0x80U) && ((s16_t)((0x00U | 0x40U | 1) & 0x03) >= 0x00)) { do {printf ("DHCP_OPTION_MESSAGE_TYPE option not found\n");} while(0); if ((0x00U | 0x40U | 1) & 0x08U) { while(1); } } } while(0);
    goto free_pbuf_and_return;
  }

   
  msg_type = dhcp_get_option_byte(options_ptr + 2);
   
  if (msg_type == 5) {
    do { if ( ((0x00U | 0x40U | 1) & 0x80U) && ((0x00U | 0x40U | 1) & 0x80U) && ((s16_t)((0x00U | 0x40U | 1) & 0x03) >= 0x00)) { do {printf ("DHCP_ACK received\n");} while(0); if ((0x00U | 0x40U | 1) & 0x08U) { while(1); } } } while(0);
     
    if (dhcp->state == 1) {
      dhcp_handle_ack(netif);
      dhcp->request_timeout = 0;

       
      dhcp_check(netif);




    }
     
    else if ((dhcp->state == 3) || (dhcp->state == 4) || (dhcp->state == 5)) {
      dhcp->request_timeout = 0;
      dhcp_bind(netif);
    }
  }
   
  else if ((msg_type == 6) &&
    ((dhcp->state == 3) || (dhcp->state == 1) ||
     (dhcp->state == 4) || (dhcp->state == 5  ))) {
    do { if ( ((0x00U | 0x40U | 1) & 0x80U) && ((0x00U | 0x40U | 1) & 0x80U) && ((s16_t)((0x00U | 0x40U | 1) & 0x03) >= 0x00)) { do {printf ("DHCP_NAK received\n");} while(0); if ((0x00U | 0x40U | 1) & 0x08U) { while(1); } } } while(0);
    dhcp->request_timeout = 0;
    dhcp_handle_nak(netif);
  }
   
  else if ((msg_type == 2) && (dhcp->state == 6)) {
    do { if ( ((0x00U | 0x40U | 1) & 0x80U) && ((0x00U | 0x40U | 1) & 0x80U) && ((s16_t)((0x00U | 0x40U | 1) & 0x03) >= 0x00)) { do {printf ("DHCP_OFFER received in DHCP_SELECTING state\n");} while(0); if ((0x00U | 0x40U | 1) & 0x08U) { while(1); } } } while(0);
    dhcp->request_timeout = 0;
     
    dhcp_handle_offer(netif);
  }
free_pbuf_and_return:
  dhcp_free_reply(dhcp);
  pbuf_free(p);
  dhcp->p = 0;
}





 
static err_t
dhcp_create_request(struct netif *netif)
{
  struct dhcp *dhcp;
  u16_t i;

  


 
  static u32_t xid = 0xABCD0000;
#line 1399 "..\\lwIP\\src\\core\\dhcp.c"
  do { if (!((netif != 0))) { do { printf("Assertion \"%s\" failed at line %d in %s\n", "dhcp_create_request: netif != NULL", 1399, "..\\lwIP\\src\\core\\dhcp.c"); } while(0); return -10;;}} while(0);
  dhcp = netif->dhcp;
  do { if (!((dhcp != 0))) { do { printf("Assertion \"%s\" failed at line %d in %s\n", "dhcp_create_request: dhcp != NULL", 1401, "..\\lwIP\\src\\core\\dhcp.c"); } while(0); return -9;;}} while(0);
  ;
  ;
  dhcp->p_out = pbuf_alloc(PBUF_TRANSPORT, sizeof(struct dhcp_msg), PBUF_RAM);
  if (dhcp->p_out == 0) {
    do { if ( ((0x00U | 0x40U | 2) & 0x80U) && ((0x00U | 0x40U | 2) & 0x80U) && ((s16_t)((0x00U | 0x40U | 2) & 0x03) >= 0x00)) { do {printf ("dhcp_create_request(): could not allocate pbuf\n");} while(0); if ((0x00U | 0x40U | 2) & 0x08U) { while(1); } } } while(0);
    return -1;
  }
  ;


   
  if (dhcp->tries==0)
      xid++;
  dhcp->xid = xid;
  do { if ( ((0x00U | 0x40U | 2) & 0x80U) && ((0x00U | 0x40U | 2) & 0x80U) && ((s16_t)((0x00U | 0x40U | 2) & 0x03) >= 0x00)) { do {printf ("transaction id xid(%" "8lx" ")\n", xid);} while(0); if ((0x00U | 0x40U | 2) & 0x08U) { while(1); } } } while(0);


  dhcp->msg_out = (struct dhcp_msg *)dhcp->p_out->payload;

  dhcp->msg_out->op = 1;
   
  dhcp->msg_out->htype = 1;
   
  dhcp->msg_out->hlen = 6;
  dhcp->msg_out->hops = 0;
  dhcp->msg_out->xid = htonl(dhcp->xid);
  dhcp->msg_out->secs = 0;
  dhcp->msg_out->flags = 0;
  dhcp->msg_out->ciaddr.addr = 0;
  if (dhcp->state==10 || dhcp->state==5 || dhcp->state==4) {
    dhcp->msg_out->ciaddr.addr = netif->ip_addr.addr;
  }
  dhcp->msg_out->yiaddr.addr = 0;
  dhcp->msg_out->siaddr.addr = 0;
  dhcp->msg_out->giaddr.addr = 0;
  for (i = 0; i < 16U; i++) {
     
    dhcp->msg_out->chaddr[i] = (i < netif->hwaddr_len) ? netif->hwaddr[i] : 0 ;
  }
  for (i = 0; i < 64U; i++) {
    dhcp->msg_out->sname[i] = 0;
  }
  for (i = 0; i < 128U; i++) {
    dhcp->msg_out->file[i] = 0;
  }
  dhcp->msg_out->cookie = htonl(0x63825363UL);
  dhcp->options_out_len = 0;
   
  for (i = 0; i < 68U; i++) {
    dhcp->msg_out->options[i] = (u8_t)i;  
  }
  return 0;
}





 
static void
dhcp_delete_request(struct netif *netif)
{
  struct dhcp *dhcp;
  do { if (!((netif != 0))) { do { printf("Assertion \"%s\" failed at line %d in %s\n", "dhcp_delete_request: netif != NULL", 1465, "..\\lwIP\\src\\core\\dhcp.c"); } while(0); return;;}} while(0);
  dhcp = netif->dhcp;
  do { if (!((dhcp != 0))) { do { printf("Assertion \"%s\" failed at line %d in %s\n", "dhcp_delete_request: dhcp != NULL", 1467, "..\\lwIP\\src\\core\\dhcp.c"); } while(0); return;;}} while(0);
  ;
  ;
  if (dhcp->p_out != 0) {
    pbuf_free(dhcp->p_out);
  }
  dhcp->p_out = 0;
  dhcp->msg_out = 0;
}








 
static void
dhcp_option_trailer(struct dhcp *dhcp)
{
  do { if (!((dhcp != 0))) { do { printf("Assertion \"%s\" failed at line %d in %s\n", "dhcp_option_trailer: dhcp != NULL", 1488, "..\\lwIP\\src\\core\\dhcp.c"); } while(0); return;;}} while(0);
  ;
  ;
  dhcp->msg_out->options[dhcp->options_out_len++] = 255;
   
  while ((dhcp->options_out_len < 68U) || (dhcp->options_out_len & 3)) {
     
    ;
     
    dhcp->msg_out->options[dhcp->options_out_len++] = 0;
  }
}









 
static u8_t *dhcp_get_option_ptr(struct dhcp *dhcp, u8_t option_type)
{
  u8_t overload = 0;

   
  if ((dhcp->options_in != 0) && (dhcp->options_in_len > 0)) {
     
    u8_t *options = (u8_t *)dhcp->options_in;
    u16_t offset = 0;
     
    while ((offset < dhcp->options_in_len) && (options[offset] != 255)) {
       
       
      if (options[offset] == 52) {
        do { if ( ((0x00U | 0x40U | 2) & 0x80U) && ((0x00U | 0x40U | 2) & 0x80U) && ((s16_t)((0x00U | 0x40U | 2) & 0x03) >= 0x00)) { do {printf ("overloaded message detected\n");} while(0); if ((0x00U | 0x40U | 2) & 0x08U) { while(1); } } } while(0);
         
        offset += 2;
        overload = options[offset++];
      }
       
      else if (options[offset] == option_type) {
        do { if ( ((0x00U | 0x40U) & 0x80U) && ((0x00U | 0x40U) & 0x80U) && ((s16_t)((0x00U | 0x40U) & 0x03) >= 0x00)) { do {printf ("option found at offset %" "4d" " in options\n", offset);} while(0); if ((0x00U | 0x40U) & 0x08U) { while(1); } } } while(0);
        return &options[offset];
       
      } else {
         do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("skipping option %" "4d" " in options\n", options[offset]);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
         
        offset++;
         
        offset += 1 + options[offset];
      }
    }
     
    if (overload != 0) {
      u16_t field_len;
      if (overload == 1) {
        do { if ( ((0x00U | 0x40U | 1) & 0x80U) && ((0x00U | 0x40U | 1) & 0x80U) && ((s16_t)((0x00U | 0x40U | 1) & 0x03) >= 0x00)) { do {printf ("overloaded file field\n");} while(0); if ((0x00U | 0x40U | 1) & 0x08U) { while(1); } } } while(0);
        options = (u8_t *)&dhcp->msg_in->file;
        field_len = 128U;
      } else if (overload == 2) {
        do { if ( ((0x00U | 0x40U | 1) & 0x80U) && ((0x00U | 0x40U | 1) & 0x80U) && ((s16_t)((0x00U | 0x40U | 1) & 0x03) >= 0x00)) { do {printf ("overloaded sname field\n");} while(0); if ((0x00U | 0x40U | 1) & 0x08U) { while(1); } } } while(0);
        options = (u8_t *)&dhcp->msg_in->sname;
        field_len = 64U;
       
      } else {
        do { if ( ((0x00U | 0x40U | 1) & 0x80U) && ((0x00U | 0x40U | 1) & 0x80U) && ((s16_t)((0x00U | 0x40U | 1) & 0x03) >= 0x00)) { do {printf ("overloaded sname and file field\n");} while(0); if ((0x00U | 0x40U | 1) & 0x08U) { while(1); } } } while(0);
        options = (u8_t *)&dhcp->msg_in->sname;
        field_len = 128U + 64U;
      }
      offset = 0;

       
      while ((offset < field_len) && (options[offset] != 255)) {
        if (options[offset] == option_type) {
           do { if ( ((0x00U | 0x40U) & 0x80U) && ((0x00U | 0x40U) & 0x80U) && ((s16_t)((0x00U | 0x40U) & 0x03) >= 0x00)) { do {printf ("option found at offset=%" "4d" "\n", offset);} while(0); if ((0x00U | 0x40U) & 0x08U) { while(1); } } } while(0);
          return &options[offset];
         
        } else {
          do { if ( ((0x00U | 0x40U) & 0x80U) && ((0x00U | 0x40U) & 0x80U) && ((s16_t)((0x00U | 0x40U) & 0x03) >= 0x00)) { do {printf ("skipping option %" "4d" "\n", options[offset]);} while(0); if ((0x00U | 0x40U) & 0x08U) { while(1); } } } while(0);
           
          offset++;
          offset += 1 + options[offset];
        }
      }
    }
  }
  return 0;
}








 
static u8_t
dhcp_get_option_byte(u8_t *ptr)
{
  do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("option byte value=%" "4d" "\n", (u16_t)(*ptr));} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
  return *ptr;
}

#line 1613 "..\\lwIP\\src\\core\\dhcp.c"








 
static u32_t dhcp_get_option_long(u8_t *ptr)
{
  u32_t value;
  value = (u32_t)(*ptr++) << 24;
  value |= (u32_t)(*ptr++) << 16;
  value |= (u32_t)(*ptr++) << 8;
  value |= (u32_t)(*ptr++);
  do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("option long value=%" "8ld" "\n", value);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
  return value;
}

