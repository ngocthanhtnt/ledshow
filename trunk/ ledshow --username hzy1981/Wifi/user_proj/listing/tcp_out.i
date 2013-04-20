#line 1 "..\\lwIP\\src\\core\\tcp_out.c"






 































 

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





 


 



 


 



 


 



 


 



 


 






 








 




 







 






 






 






 






 






 






 






 






 






 






 






 






 






 






 






 






 






 






 







 






 






 






 






 






 






 






 






 






 






 






 






 






 






 




#line 42 "..\\lwIP\\src\\core\\tcp_out.c"



#line 1 "..\\lwIP\\src\\include\\lwip/tcp.h"






























 



#line 36 "..\\lwIP\\src\\include\\lwip/tcp.h"



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






#line 40 "..\\lwIP\\src\\include\\lwip/tcp.h"
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














#line 41 "..\\lwIP\\src\\include\\lwip/tcp.h"
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





#line 42 "..\\lwIP\\src\\include\\lwip/tcp.h"
#line 1 "..\\lwIP\\src\\include\\ipv4\\lwip/ip.h"






























 



#line 36 "..\\lwIP\\src\\include\\ipv4\\lwip/ip.h"

#line 1 "..\\lwIP\\src\\include\\lwip/def.h"






























 



 
#line 37 "..\\lwIP\\src\\include\\lwip/def.h"











#line 38 "..\\lwIP\\src\\include\\ipv4\\lwip/ip.h"
#line 39 "..\\lwIP\\src\\include\\ipv4\\lwip/ip.h"
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


 









#line 40 "..\\lwIP\\src\\include\\ipv4\\lwip/ip.h"
#line 41 "..\\lwIP\\src\\include\\ipv4\\lwip/ip.h"
#line 1 "..\\lwIP\\src\\include\\lwip/netif.h"






























 



#line 36 "..\\lwIP\\src\\include\\lwip/netif.h"



#line 40 "..\\lwIP\\src\\include\\lwip/netif.h"

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













#line 43 "..\\lwIP\\src\\include\\lwip/tcp.h"
#line 1 "..\\lwIP\\src\\include\\ipv4\\lwip/icmp.h"






























 



#line 36 "..\\lwIP\\src\\include\\ipv4\\lwip/icmp.h"



#line 40 "..\\lwIP\\src\\include\\ipv4\\lwip/icmp.h"
#line 41 "..\\lwIP\\src\\include\\ipv4\\lwip/icmp.h"
#line 42 "..\\lwIP\\src\\include\\ipv4\\lwip/icmp.h"





#line 58 "..\\lwIP\\src\\include\\ipv4\\lwip/icmp.h"

enum icmp_dur_type {
  ICMP_DUR_NET = 0,     
  ICMP_DUR_HOST = 1,    
  ICMP_DUR_PROTO = 2,   
  ICMP_DUR_PORT = 3,    
  ICMP_DUR_FRAG = 4,    
  ICMP_DUR_SR = 5       
};

enum icmp_te_type {
  ICMP_TE_TTL = 0,      
  ICMP_TE_FRAG = 1      
};

void icmp_input(struct pbuf *p, struct netif *inp);

void icmp_dest_unreach(struct pbuf *p, enum icmp_dur_type t);
void icmp_time_exceeded(struct pbuf *p, enum icmp_te_type t);








 
__packed
struct icmp_echo_hdr {
  u8_t type;
  u8_t code;
  u16_t chksum;
  u16_t id;
  u16_t seqno;
} ;








 









#line 44 "..\\lwIP\\src\\include\\lwip/tcp.h"
#line 45 "..\\lwIP\\src\\include\\lwip/tcp.h"





struct tcp_pcb;

 

 

void             tcp_tmr     (void);  

 
 
struct tcp_pcb * tcp_new     (void);
struct tcp_pcb * tcp_alloc   (u8_t prio);

void             tcp_arg     (struct tcp_pcb *pcb, void *arg);
void             tcp_accept  (struct tcp_pcb *pcb,
                              err_t (* accept)(void *arg, struct tcp_pcb *newpcb,
                 err_t err));
void             tcp_recv    (struct tcp_pcb *pcb,
                              err_t (* recv)(void *arg, struct tcp_pcb *tpcb,
                              struct pbuf *p, err_t err));
void             tcp_sent    (struct tcp_pcb *pcb,
                              err_t (* sent)(void *arg, struct tcp_pcb *tpcb,
                              u16_t len));
void             tcp_poll    (struct tcp_pcb *pcb,
                              err_t (* poll)(void *arg, struct tcp_pcb *tpcb),
                              u8_t interval);
void             tcp_err     (struct tcp_pcb *pcb,
                              void (* err)(void *arg, err_t err));










void             tcp_recved  (struct tcp_pcb *pcb, u16_t len);
err_t            tcp_bind    (struct tcp_pcb *pcb, struct ip_addr *ipaddr,
                              u16_t port);
err_t            tcp_connect (struct tcp_pcb *pcb, struct ip_addr *ipaddr,
                              u16_t port, err_t (* connected)(void *arg,
                              struct tcp_pcb *tpcb,
                              err_t err));

struct tcp_pcb * tcp_listen_with_backlog(struct tcp_pcb *pcb, u8_t backlog);


void             tcp_abandon (struct tcp_pcb *pcb, int reset);

err_t            tcp_close   (struct tcp_pcb *pcb);

 



err_t            tcp_write   (struct tcp_pcb *pcb, const void *dataptr, u16_t len,
                              u8_t apiflags);

void             tcp_setprio (struct tcp_pcb *pcb, u8_t prio);






 
void             tcp_slowtmr (void);
void             tcp_fasttmr (void);


 
void             tcp_input   (struct pbuf *p, struct netif *inp);
 
err_t            tcp_output  (struct tcp_pcb *pcb);
void             tcp_rexmit  (struct tcp_pcb *pcb);
void             tcp_rexmit_rto  (struct tcp_pcb *pcb);
u32_t            tcp_update_rcv_ann_wnd(struct tcp_pcb *pcb);








 
#line 144 "..\\lwIP\\src\\include\\lwip/tcp.h"






 
#line 163 "..\\lwIP\\src\\include\\lwip/tcp.h"



 























 
















 



__packed
struct tcp_hdr {
  u16_t src;
  u16_t dest;
  u32_t seqno;
  u32_t ackno;
  u16_t _hdrlen_rsvd_flags;
  u16_t wnd;
  u16_t chksum;
  u16_t urgp;
} ;


















enum tcp_state {
  CLOSED      = 0,
  LISTEN      = 1,
  SYN_SENT    = 2,
  SYN_RCVD    = 3,
  ESTABLISHED = 4,
  FIN_WAIT_1  = 5,
  FIN_WAIT_2  = 6,
  CLOSE_WAIT  = 7,
  CLOSING     = 8,
  LAST_ACK    = 9,
  TIME_WAIT   = 10
};


 






  





 







 
#line 286 "..\\lwIP\\src\\include\\lwip/tcp.h"


 
struct tcp_pcb {
 
  struct ip_addr local_ip; struct ip_addr remote_ip; u16_t so_options; u8_t tos; u8_t ttl ;
 
  struct tcp_pcb *next; enum tcp_state state; u8_t prio; void *callback_arg; u16_t local_port; err_t (* accept)(void *arg, struct tcp_pcb *newpcb, err_t err);

   
  u16_t remote_port;
  
  u8_t flags;
#line 306 "..\\lwIP\\src\\include\\lwip/tcp.h"

  
 
   
  u32_t rcv_nxt;    
  u16_t rcv_wnd;    
  u16_t rcv_ann_wnd;  
  u32_t rcv_ann_right_edge;  

   
  u32_t tmr;
  u8_t polltmr, pollinterval;
  
   
  s16_t rtime;
  
  u16_t mss;    
  
   
  u32_t rttest;  
  u32_t rtseq;   
  s16_t sa, sv;  

  s16_t rto;     
  u8_t nrtx;     

   
  u32_t lastack;  
  u8_t dupacks;
  
   
  u16_t cwnd;  
  u16_t ssthresh;

   
  u32_t snd_nxt;    
  u16_t snd_wnd;    
  u32_t snd_wl1, snd_wl2; 
 
  u32_t snd_lbb;        

  u16_t acked;
  
  u16_t snd_buf;    

  u16_t snd_queuelen;  
  
  
   
  struct tcp_seg *unsent;    
  struct tcp_seg *unacked;   




  struct pbuf *refused_data;  


  




 
  err_t (* sent)(void *arg, struct tcp_pcb *pcb, u16_t space);
  
  





 
  err_t (* recv)(void *arg, struct tcp_pcb *pcb, struct pbuf *p, err_t err);

  




 
  err_t (* connected)(void *arg, struct tcp_pcb *pcb, err_t err);

  





 
  err_t (* poll)(void *arg, struct tcp_pcb *pcb);

  






 
  void (* errf)(void *arg, err_t err);







   
  u32_t keep_idle;




  
   
  u32_t persist_cnt;
   
  u8_t persist_backoff;

   
  u8_t keep_cnt_sent;
};

struct tcp_pcb_listen {  
 
  struct ip_addr local_ip; struct ip_addr remote_ip; u16_t so_options; u8_t tos; u8_t ttl ;
 
  struct tcp_pcb_listen *next; enum tcp_state state; u8_t prio; void *callback_arg; u16_t local_port; err_t (* accept)(void *arg, struct tcp_pcb *newpcb, err_t err);





};

#line 472 "..\\lwIP\\src\\include\\lwip/tcp.h"

#line 479 "..\\lwIP\\src\\include\\lwip/tcp.h"

#line 486 "..\\lwIP\\src\\include\\lwip/tcp.h"

#line 497 "..\\lwIP\\src\\include\\lwip/tcp.h"

#line 504 "..\\lwIP\\src\\include\\lwip/tcp.h"

#line 511 "..\\lwIP\\src\\include\\lwip/tcp.h"









 
struct tcp_seg {
  struct tcp_seg *next;     
  struct pbuf *p;           
  void *dataptr;            
  u16_t len;                
  u8_t  flags;


  struct tcp_hdr *tcphdr;   
};





 





 
struct tcp_pcb *tcp_pcb_copy(struct tcp_pcb *pcb);
void tcp_pcb_purge(struct tcp_pcb *pcb);
void tcp_pcb_remove(struct tcp_pcb **pcblist, struct tcp_pcb *pcb);

u8_t tcp_segs_free(struct tcp_seg *seg);
u8_t tcp_seg_free(struct tcp_seg *seg);
struct tcp_seg *tcp_seg_copy(struct tcp_seg *seg);

#line 562 "..\\lwIP\\src\\include\\lwip/tcp.h"







err_t tcp_send_ctrl(struct tcp_pcb *pcb, u8_t flags);
err_t tcp_enqueue(struct tcp_pcb *pcb, void *dataptr, u16_t len,
                  u8_t flags, u8_t apiflags, u8_t optflags);

void tcp_rexmit_seg(struct tcp_pcb *pcb, struct tcp_seg *seg);

void tcp_rst(u32_t seqno, u32_t ackno,
       struct ip_addr *local_ip, struct ip_addr *remote_ip,
       u16_t local_port, u16_t remote_port);

u32_t tcp_next_iss(void);

void tcp_keepalive(struct tcp_pcb *pcb);
void tcp_zero_window_probe(struct tcp_pcb *pcb);


u16_t tcp_eff_send_mss(u16_t sendmss, struct ip_addr *addr);


extern struct tcp_pcb *tcp_input_pcb;
extern u32_t tcp_ticks;

#line 604 "..\\lwIP\\src\\include\\lwip/tcp.h"







 
union tcp_listen_pcbs_t {  
  struct tcp_pcb_listen *listen_pcbs; 
  struct tcp_pcb *pcbs;
};
extern union tcp_listen_pcbs_t tcp_listen_pcbs;
extern struct tcp_pcb *tcp_active_pcbs;  

 
extern struct tcp_pcb *tcp_tw_pcbs;       

extern struct tcp_pcb *tcp_tmp_pcb;       






 


 
#line 665 "..\\lwIP\\src\\include\\lwip/tcp.h"

#line 672 "..\\lwIP\\src\\include\\lwip/tcp.h"

#line 690 "..\\lwIP\\src\\include\\lwip/tcp.h"









#line 46 "..\\lwIP\\src\\core\\tcp_out.c"
#line 47 "..\\lwIP\\src\\core\\tcp_out.c"
#line 48 "..\\lwIP\\src\\core\\tcp_out.c"
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







#line 49 "..\\lwIP\\src\\core\\tcp_out.c"
#line 50 "..\\lwIP\\src\\core\\tcp_out.c"
#line 51 "..\\lwIP\\src\\core\\tcp_out.c"
#line 52 "..\\lwIP\\src\\core\\tcp_out.c"
#line 53 "..\\lwIP\\src\\core\\tcp_out.c"
#line 1 "..\\lwIP\\src\\include\\ipv4\\lwip/inet_chksum.h"






























 



#line 36 "..\\lwIP\\src\\include\\ipv4\\lwip/inet_chksum.h"

#line 38 "..\\lwIP\\src\\include\\ipv4\\lwip/inet_chksum.h"
#line 39 "..\\lwIP\\src\\include\\ipv4\\lwip/inet_chksum.h"





u16_t inet_chksum(void *dataptr, u16_t len);
u16_t inet_chksum_pbuf(struct pbuf *p);
u16_t inet_chksum_pseudo(struct pbuf *p,
       struct ip_addr *src, struct ip_addr *dest,
       u8_t proto, u16_t proto_len);












#line 54 "..\\lwIP\\src\\core\\tcp_out.c"
#line 1 "..\\lwIP\\src\\include\\lwip/stats.h"






























 



#line 36 "..\\lwIP\\src\\include\\lwip/stats.h"

#line 38 "..\\lwIP\\src\\include\\lwip/stats.h"
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





#line 55 "..\\lwIP\\src\\core\\tcp_out.c"
#line 1 "..\\lwIP\\src\\include\\lwip/snmp.h"































 



#line 37 "..\\lwIP\\src\\include\\lwip/snmp.h"
#line 38 "..\\lwIP\\src\\include\\lwip/snmp.h"
#line 1 "..\\lwIP\\src\\include\\lwip/udp.h"






























 



#line 36 "..\\lwIP\\src\\include\\lwip/udp.h"



#line 40 "..\\lwIP\\src\\include\\lwip/udp.h"
#line 41 "..\\lwIP\\src\\include\\lwip/udp.h"
#line 42 "..\\lwIP\\src\\include\\lwip/udp.h"
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















#line 39 "..\\lwIP\\src\\include\\lwip/snmp.h"







 
enum snmp_ifType {
  snmp_ifType_other=1,                 
  snmp_ifType_regular1822,
  snmp_ifType_hdh1822,
  snmp_ifType_ddn_x25,
  snmp_ifType_rfc877_x25,
  snmp_ifType_ethernet_csmacd,
  snmp_ifType_iso88023_csmacd,
  snmp_ifType_iso88024_tokenBus,
  snmp_ifType_iso88025_tokenRing,
  snmp_ifType_iso88026_man,
  snmp_ifType_starLan,
  snmp_ifType_proteon_10Mbit,
  snmp_ifType_proteon_80Mbit,
  snmp_ifType_hyperchannel,
  snmp_ifType_fddi,
  snmp_ifType_lapb,
  snmp_ifType_sdlc,
  snmp_ifType_ds1,                     
  snmp_ifType_e1,                      
  snmp_ifType_basicISDN,
  snmp_ifType_primaryISDN,             
  snmp_ifType_propPointToPointSerial,
  snmp_ifType_ppp,
  snmp_ifType_softwareLoopback,
  snmp_ifType_eon,                     
  snmp_ifType_ethernet_3Mbit,
  snmp_ifType_nsip,                    
  snmp_ifType_slip,                    
  snmp_ifType_ultra,                   
  snmp_ifType_ds3,                     
  snmp_ifType_sip,                     
  snmp_ifType_frame_relay
};

#line 229 "..\\lwIP\\src\\include\\lwip/snmp.h"

 
#line 240 "..\\lwIP\\src\\include\\lwip/snmp.h"

 
#line 252 "..\\lwIP\\src\\include\\lwip/snmp.h"

 



 
#line 279 "..\\lwIP\\src\\include\\lwip/snmp.h"

 
#line 307 "..\\lwIP\\src\\include\\lwip/snmp.h"
 
#line 317 "..\\lwIP\\src\\include\\lwip/snmp.h"

 
#line 325 "..\\lwIP\\src\\include\\lwip/snmp.h"

 
#line 357 "..\\lwIP\\src\\include\\lwip/snmp.h"







#line 56 "..\\lwIP\\src\\core\\tcp_out.c"

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



 
#line 58 "..\\lwIP\\src\\core\\tcp_out.c"

 
static void tcp_output_segment(struct tcp_seg *seg, struct tcp_pcb *pcb);

static struct tcp_hdr *
tcp_output_set_header(struct tcp_pcb *pcb, struct pbuf *p, int optlen,
                      u32_t seqno_be  )
{
  struct tcp_hdr *tcphdr = p->payload;
  tcphdr->src = htons(pcb->local_port);
  tcphdr->dest = htons(pcb->remote_port);
  tcphdr->seqno = seqno_be;
  tcphdr->ackno = htonl(pcb->rcv_nxt);
  (tcphdr)->_hdrlen_rsvd_flags = htons((ntohs((tcphdr)->_hdrlen_rsvd_flags) & ~0x3fU) | (0x10U));
  tcphdr->wnd = htons(pcb->rcv_ann_wnd);
  tcphdr->urgp = 0;
  (tcphdr)->_hdrlen_rsvd_flags = htons((((5 + optlen / 4)) << 12) | (ntohs((tcphdr)->_hdrlen_rsvd_flags) & 0x3fU));
  tcphdr->chksum = 0;

   
  pcb->rcv_ann_right_edge = pcb->rcv_nxt + pcb->rcv_ann_wnd;

  return tcphdr;
}







 
err_t
tcp_send_ctrl(struct tcp_pcb *pcb, u8_t flags)
{
   
  return tcp_enqueue(pcb, 0, 0, flags, 0x01, 0);
}


















 
err_t
tcp_write(struct tcp_pcb *pcb, const void *data, u16_t len, u8_t apiflags)
{
  do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_write(pcb=%p, data=%p, len=%" "4d" ", apiflags=%" "4d" ")\n", (void *)pcb, data, len, (u16_t)apiflags);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);

   
  if (pcb->state == ESTABLISHED ||
     pcb->state == CLOSE_WAIT ||
     pcb->state == SYN_SENT ||
     pcb->state == SYN_RCVD) {
    if (len > 0) {




      return tcp_enqueue(pcb, (void *)data, len, 0, apiflags, 0);

    }
    return 0;
  } else {
    do { if ( ((0x00U | 0x20U | 3) & 0x80U) && ((0x00U | 0x20U | 3) & 0x80U) && ((s16_t)((0x00U | 0x20U | 3) & 0x03) >= 0x00)) { do {printf ("tcp_write() called in invalid state\n");} while(0); if ((0x00U | 0x20U | 3) & 0x08U) { while(1); } } } while(0);
    return -8;
  }
}














 
err_t
tcp_enqueue(struct tcp_pcb *pcb, void *arg, u16_t len,
            u8_t flags, u8_t apiflags, u8_t optflags)
{
  struct pbuf *p;
  struct tcp_seg *seg, *useg, *queue;
  u32_t seqno;
  u16_t left, seglen;
  void *ptr;
  u16_t queuelen;
  u8_t optlen;

  do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_enqueue(pcb=%p, arg=%p, len=%" "4d" ", flags=%" "4x" ", apiflags=%" "4d" ")\n", (void *)pcb, arg, len, (u16_t)flags, (u16_t)apiflags);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);


  do { if (!(((len != 0) || (optflags != 0) || ((flags & (0x02U | 0x01U)) != 0)))) { do { printf("Assertion \"%s\" failed at line %d in %s\n", "tcp_enqueue: packet needs payload, options, or SYN/FIN (programmer violates API)", 169, "..\\lwIP\\src\\core\\tcp_out.c"); } while(0); return -10;;}} while(0);


  do { if (!(((len != 0) || (arg == 0)))) { do { printf("Assertion \"%s\" failed at line %d in %s\n", "tcp_enqueue: len != 0 || arg == NULL (programmer violates API)", 172, "..\\lwIP\\src\\core\\tcp_out.c"); } while(0); return -10;;}} while(0);


   
  if (len > pcb->snd_buf) {
    do { if ( ((0x00U | 3) & 0x80U) && ((0x00U | 3) & 0x80U) && ((s16_t)((0x00U | 3) & 0x03) >= 0x00)) { do {printf ("tcp_enqueue: too much data (len=%" "4d" " > snd_buf=%" "4d" ")\n", len, pcb->snd_buf);} while(0); if ((0x00U | 3) & 0x08U) { while(1); } } } while(0);
    pcb->flags |= ((u8_t)0x80U);
    return -1;
  }
  left = len;
  ptr = arg;

  optlen = (optflags & (u8_t)0x01U ? 4 : 0) + (optflags & (u8_t)0x02U ? 12 : 0);

  
 
  seqno = pcb->snd_lbb;

  do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_enqueue: queuelen: %" "4d" "\n", (u16_t)pcb->snd_queuelen);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);

  
 
  queuelen = pcb->snd_queuelen;
   
  if ((queuelen >= (6 * (1500 - 40))/(1500 - 40)) || (queuelen > (0xffff-3))) {
    do { if ( ((0x00U | 3) & 0x80U) && ((0x00U | 3) & 0x80U) && ((s16_t)((0x00U | 3) & 0x03) >= 0x00)) { do {printf ("tcp_enqueue: too long queue %" "4d" " (max %" "4d" ")\n", queuelen, (6 * (1500 - 40))/(1500 - 40));} while(0); if ((0x00U | 3) & 0x08U) { while(1); } } } while(0);
    ;
    pcb->flags |= ((u8_t)0x80U);
    return -1;
  }
  if (queuelen != 0) {
    ;

  } else {
    ;

  }

  
 
  useg = queue = seg = 0;
  seglen = 0;
  while (queue == 0 || left > 0) {
     
    seglen = left > (pcb->mss - optlen) ? (pcb->mss - optlen) : left;

     
    seg = memp_malloc(MEMP_TCP_SEG);
    if (seg == 0) {
      do { if ( ((0x00U | 2) & 0x80U) && ((0x00U | 2) & 0x80U) && ((s16_t)((0x00U | 2) & 0x03) >= 0x00)) { do {printf ("tcp_enqueue: could not allocate memory for tcp_seg\n");} while(0); if ((0x00U | 2) & 0x08U) { while(1); } } } while(0);

      goto memerr;
    }
    seg->next = 0;
    seg->p = 0;

     
    if (queue == 0) {
      queue = seg;
    }
     
    else {
       
      ;
      useg->next = seg;
    }
     
    useg = seg;

    

 
    if (apiflags & 0x01) {
      if ((seg->p = pbuf_alloc(PBUF_TRANSPORT, seglen + optlen, PBUF_RAM)) == 0) {
        do { if ( ((0x00U | 2) & 0x80U) && ((0x00U | 2) & 0x80U) && ((s16_t)((0x00U | 2) & 0x03) >= 0x00)) { do {printf ("tcp_enqueue : could not allocate memory for pbuf copy size %" "4d" "\n", seglen);} while(0); if ((0x00U | 2) & 0x08U) { while(1); } } } while(0);

        goto memerr;
      }
      ;

      queuelen += pbuf_clen(seg->p);
      if (arg != 0) {
        memcpy((char *)seg->p->payload + optlen,ptr,seglen);
      }
      seg->dataptr = seg->p->payload;
    }
     
    else {
       
      if ((seg->p = pbuf_alloc(PBUF_TRANSPORT, optlen, PBUF_RAM)) == 0) {
        do { if ( ((0x00U | 2) & 0x80U) && ((0x00U | 2) & 0x80U) && ((s16_t)((0x00U | 2) & 0x03) >= 0x00)) { do {printf ("tcp_enqueue: could not allocate memory for header pbuf\n");} while(0); if ((0x00U | 2) & 0x08U) { while(1); } } } while(0);

        goto memerr;
      }
      queuelen += pbuf_clen(seg->p);

      



 
      if (left > 0) {
        if ((p = pbuf_alloc(PBUF_RAW, seglen, PBUF_ROM)) == 0) {
           
          pbuf_free(seg->p);
          seg->p = 0;
          do { if ( ((0x00U | 2) & 0x80U) && ((0x00U | 2) & 0x80U) && ((s16_t)((0x00U | 2) & 0x03) >= 0x00)) { do {printf ("tcp_enqueue: could not allocate memory for zero-copy pbuf\n");} while(0); if ((0x00U | 2) & 0x08U) { while(1); } } } while(0);

          goto memerr;
        }
        ++queuelen;
         
        p->payload = ptr;
        seg->dataptr = ptr;

         
        pbuf_cat(seg->p , p );
        p = 0;
      }
    }

    
 
    if ((queuelen > (6 * (1500 - 40))/(1500 - 40)) || (queuelen > (0xffff-3))) {
      do { if ( ((0x00U | 2) & 0x80U) && ((0x00U | 2) & 0x80U) && ((s16_t)((0x00U | 2) & 0x03) >= 0x00)) { do {printf ("tcp_enqueue: queue too long %" "4d" " (%" "4d" ")\n", queuelen, (6 * (1500 - 40))/(1500 - 40));} while(0); if ((0x00U | 2) & 0x08U) { while(1); } } } while(0);
      goto memerr;
    }

    seg->len = seglen;

     
    if (pbuf_header(seg->p, 20)) {
      do { if ( ((0x00U | 2) & 0x80U) && ((0x00U | 2) & 0x80U) && ((s16_t)((0x00U | 2) & 0x03) >= 0x00)) { do {printf ("tcp_enqueue: no room for TCP header in pbuf.\n");} while(0); if ((0x00U | 2) & 0x08U) { while(1); } } } while(0);
      ;
      goto memerr;
    }
    seg->tcphdr = seg->p->payload;
    seg->tcphdr->src = htons(pcb->local_port);
    seg->tcphdr->dest = htons(pcb->remote_port);
    seg->tcphdr->seqno = htonl(seqno);
    seg->tcphdr->urgp = 0;
    (seg->tcphdr)->_hdrlen_rsvd_flags = htons((ntohs((seg->tcphdr)->_hdrlen_rsvd_flags) & ~0x3fU) | (flags));
     

    seg->flags = optflags;

     
    (seg->tcphdr)->_hdrlen_rsvd_flags = htons((((5 + optlen / 4)) << 12) | (ntohs((seg->tcphdr)->_hdrlen_rsvd_flags) & 0x3fU));
    do { if ( ((0x00U | 0x40U) & 0x80U) && ((0x00U | 0x40U) & 0x80U) && ((s16_t)((0x00U | 0x40U) & 0x03) >= 0x00)) { do {printf ("tcp_enqueue: queueing %" "8ld" ":%" "8ld" " (0x%" "4x" ")\n", ntohl(seg->tcphdr->seqno), ntohl(seg->tcphdr->seqno) + ((seg)->len + (((ntohs(((seg)->tcphdr)->_hdrlen_rsvd_flags) & 0x3fU) & 0x01U || (ntohs(((seg)->tcphdr)->_hdrlen_rsvd_flags) & 0x3fU) & 0x02U)? 1: 0)), (u16_t)flags);} while(0); if ((0x00U | 0x40U) & 0x08U) { while(1); } } } while(0);




    left -= seglen;
    seqno += seglen;
    ptr = (void *)((u8_t *)ptr + seglen);
  }

  

 
  if (pcb->unsent == 0) {
    useg = 0;
  }
  else {
    for (useg = pcb->unsent; useg->next != 0; useg = useg->next);
  }
   

  
 
  if (useg != 0 &&
    ((useg)->len + (((ntohs(((useg)->tcphdr)->_hdrlen_rsvd_flags) & 0x3fU) & 0x01U || (ntohs(((useg)->tcphdr)->_hdrlen_rsvd_flags) & 0x3fU) & 0x02U)? 1: 0)) != 0 &&
    !((ntohs((useg->tcphdr)->_hdrlen_rsvd_flags) & 0x3fU) & (0x02U | 0x01U)) &&
    !(flags & (0x02U | 0x01U)) &&
     
    (useg->len + queue->len <= pcb->mss) &&
     
    (useg->flags == queue->flags)) {
     
    if(pbuf_header(queue->p, -(20 + optlen))) {
       
      ;
      ;
      goto memerr;
    }
    if (queue->p->len == 0) {
       
      struct pbuf *old_q = queue->p;
      queue->p = queue->p->next;
      old_q->next = 0;
      queuelen--;
      pbuf_free(old_q);
    }
    ;
    pbuf_cat(useg->p, queue->p);
    useg->len += queue->len;
    useg->next = queue->next;

    do { if ( ((0x00U | 0x40U | 0x20U) & 0x80U) && ((0x00U | 0x40U | 0x20U) & 0x80U) && ((s16_t)((0x00U | 0x40U | 0x20U) & 0x03) >= 0x00)) { do {printf ("tcp_enqueue: chaining segments, new len %" "4d" "\n", useg->len);} while(0); if ((0x00U | 0x40U | 0x20U) & 0x08U) { while(1); } } } while(0);
    if (seg == queue) {
      seg = useg;
      seglen = useg->len;
    }
    memp_free(MEMP_TCP_SEG, queue);
  }
  else {
     
    if (useg == 0) {
       
      pcb->unsent = queue;
    }
     
    else {
      useg->next = queue;
    }
  }
  if ((flags & 0x02U) || (flags & 0x01U)) {
    ++len;
  }
  if (flags & 0x01U) {
    pcb->flags |= ((u8_t)0x20U);
  }
  pcb->snd_lbb += len;

  pcb->snd_buf -= len;

   
  pcb->snd_queuelen = queuelen;
  do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_enqueue: %" "4d" " (after enqueued)\n", pcb->snd_queuelen);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
  if (pcb->snd_queuelen != 0) {
    ;

  }

  
 
  if (seg != 0 && seglen > 0 && seg->tcphdr != 0 && ((apiflags & 0x02)==0)) {
    (seg->tcphdr)->_hdrlen_rsvd_flags = htons(ntohs((seg->tcphdr)->_hdrlen_rsvd_flags) | (0x08U));
  }

  return 0;
memerr:
  pcb->flags |= ((u8_t)0x80U);
  ;

  if (queue != 0) {
    tcp_segs_free(queue);
  }
  if (pcb->snd_queuelen != 0) {
    ;

  }
  do { if ( ((0x00U | 0x20U) & 0x80U) && ((0x00U | 0x20U) & 0x80U) && ((s16_t)((0x00U | 0x20U) & 0x03) >= 0x00)) { do {printf ("tcp_enqueue: %" "4d" " (with mem err)\n", pcb->snd_queuelen);} while(0); if ((0x00U | 0x20U) & 0x08U) { while(1); } } } while(0);
  return -1;
}


#line 445 "..\\lwIP\\src\\core\\tcp_out.c"








 
err_t
tcp_output(struct tcp_pcb *pcb)
{
  struct pbuf *p;
  struct tcp_hdr *tcphdr;
  struct tcp_seg *seg, *useg;
  u32_t wnd, snd_nxt;



  u8_t optlen = 0;

  


 
  if (tcp_input_pcb == pcb) {
    return 0;
  }

  wnd = (((pcb->snd_wnd) < (pcb->cwnd)) ? (pcb->snd_wnd) : (pcb->cwnd));

  seg = pcb->unsent;

   
  useg = pcb->unacked;
  if (useg != 0) {
    for (; useg->next != 0; useg = useg->next);
  }

  




 
  if (pcb->flags & ((u8_t)0x02U) &&
     (seg == 0 ||
      ntohl(seg->tcphdr->seqno) - pcb->lastack + seg->len > wnd)) {




    p = pbuf_alloc(PBUF_IP, 20 + optlen, PBUF_RAM);
    if (p == 0) {
      do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_output: (ACK) could not allocate pbuf\n");} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
      return -2;
    }
    do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_output: sending ACK for %" "8ld" "\n", pcb->rcv_nxt);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);

     
    pcb->flags &= ~(((u8_t)0x01U) | ((u8_t)0x02U));

    tcphdr = tcp_output_set_header(pcb, p, optlen, htonl(pcb->snd_nxt));

     
#line 516 "..\\lwIP\\src\\core\\tcp_out.c"


    tcphdr->chksum = inet_chksum_pseudo(p, &(pcb->local_ip), &(pcb->remote_ip),
          6, p->tot_len);





    ip_output(p, &(pcb->local_ip), &(pcb->remote_ip), pcb->ttl, pcb->tos,
        6);

    pbuf_free(p);

    return 0;
  }

#line 554 "..\\lwIP\\src\\core\\tcp_out.c"
   
  while (seg != 0 &&
         ntohl(seg->tcphdr->seqno) - pcb->lastack + seg->len <= wnd) {
    ;

    





 
    if((((((pcb)->unacked == 0) || ((pcb)->flags & ((u8_t)0x40U)) || (((pcb)->unsent != 0) && (((pcb)->unsent->next != 0) || ((pcb)->unsent->len >= (pcb)->mss))) ) ? 1 : 0) == 0) &&
      ((pcb->flags & (((u8_t)0x80U) | ((u8_t)0x20U))) == 0)){
      break;
    }
#line 578 "..\\lwIP\\src\\core\\tcp_out.c"

    pcb->unsent = seg->next;

    if (pcb->state != SYN_SENT) {
      (seg->tcphdr)->_hdrlen_rsvd_flags = htons(ntohs((seg->tcphdr)->_hdrlen_rsvd_flags) | (0x10U));
      pcb->flags &= ~(((u8_t)0x01U) | ((u8_t)0x02U));
    }

    tcp_output_segment(seg, pcb);
    snd_nxt = ntohl(seg->tcphdr->seqno) + ((seg)->len + (((ntohs(((seg)->tcphdr)->_hdrlen_rsvd_flags) & 0x3fU) & 0x01U || (ntohs(((seg)->tcphdr)->_hdrlen_rsvd_flags) & 0x3fU) & 0x02U)? 1: 0));
    if (((s32_t)((pcb->snd_nxt)-(snd_nxt)) < 0)) {
      pcb->snd_nxt = snd_nxt;
    }
     
    if (((seg)->len + (((ntohs(((seg)->tcphdr)->_hdrlen_rsvd_flags) & 0x3fU) & 0x01U || (ntohs(((seg)->tcphdr)->_hdrlen_rsvd_flags) & 0x3fU) & 0x02U)? 1: 0)) > 0) {
      seg->next = 0;
       
      if (pcb->unacked == 0) {
        pcb->unacked = seg;
        useg = seg;
       
      } else {
        

 
        if (((s32_t)((ntohl(seg->tcphdr->seqno))-(ntohl(useg->tcphdr->seqno))) < 0)){
           
          struct tcp_seg **cur_seg = &(pcb->unacked);
          while (*cur_seg &&
            ((s32_t)((ntohl((*cur_seg)->tcphdr->seqno))-(ntohl(seg->tcphdr->seqno))) < 0)) {
              cur_seg = &((*cur_seg)->next );
          }
          seg->next = (*cur_seg);
          (*cur_seg) = seg;
        } else {
           
          useg->next = seg;
          useg = useg->next;
        }
      }
     
    } else {
      tcp_seg_free(seg);
    }
    seg = pcb->unsent;
  }

  if (seg != 0 && pcb->persist_backoff == 0 && 
      ntohl(seg->tcphdr->seqno) - pcb->lastack + seg->len > pcb->snd_wnd) {
     
    pcb->persist_cnt = 0;
    pcb->persist_backoff = 1;
  }

  pcb->flags &= ~((u8_t)0x80U);
  return 0;
}






 
static void
tcp_output_segment(struct tcp_seg *seg, struct tcp_pcb *pcb)
{
  u16_t len;
  struct netif *netif;
  u32_t *opts;

   
  ;

  
 
  seg->tcphdr->ackno = htonl(pcb->rcv_nxt);

   
  seg->tcphdr->wnd = htons(pcb->rcv_ann_wnd);

  pcb->rcv_ann_right_edge = pcb->rcv_nxt + pcb->rcv_ann_wnd;

  
 
  opts = (u32_t *)(seg->tcphdr + 1);
  if (seg->flags & (u8_t)0x01U) {
    (*opts) = htonl(((u32_t)2 << 24) | ((u32_t)4 << 16) | (((u32_t)(1500 - 40) / 256) << 8) | ((1500 - 40) & 255));
    opts += 1;
  }
#line 676 "..\\lwIP\\src\\core\\tcp_out.c"

  
 
  if (((&(pcb->local_ip)) == 0 || (&(pcb->local_ip))->addr == 0)) {
    netif = ip_route(&(pcb->remote_ip));
    if (netif == 0) {
      return;
    }
    (&(pcb->local_ip))->addr = ((&(netif->ip_addr)) == 0? 0: (&(netif->ip_addr))->addr);
  }

   
  if(pcb->rtime == -1)
    pcb->rtime = 0;

  if (pcb->rttest == 0) {
    pcb->rttest = tcp_ticks;
    pcb->rtseq = ntohl(seg->tcphdr->seqno);

    do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_output_segment: rtseq %" "8ld" "\n", pcb->rtseq);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
  }
  do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_output_segment: %" "8ld" ":%" "8ld" "\n", htonl(seg->tcphdr->seqno), htonl(seg->tcphdr->seqno) + seg->len);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);



  len = (u16_t)((u8_t *)seg->tcphdr - (u8_t *)seg->p->payload);

  seg->p->len -= len;
  seg->p->tot_len -= len;

  seg->p->payload = seg->tcphdr;

  seg->tcphdr->chksum = 0;

  seg->tcphdr->chksum = inet_chksum_pseudo(seg->p,
             &(pcb->local_ip),
             &(pcb->remote_ip),
             6, seg->p->tot_len);

  ;





  ip_output(seg->p, &(pcb->local_ip), &(pcb->remote_ip), pcb->ttl, pcb->tos,
      6);

}




















 
void
tcp_rst(u32_t seqno, u32_t ackno,
  struct ip_addr *local_ip, struct ip_addr *remote_ip,
  u16_t local_port, u16_t remote_port)
{
  struct pbuf *p;
  struct tcp_hdr *tcphdr;
  p = pbuf_alloc(PBUF_IP, 20, PBUF_RAM);
  if (p == 0) {
      do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_rst: could not allocate memory for pbuf\n");} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
      return;
  }
  ;


  tcphdr = p->payload;
  tcphdr->src = htons(local_port);
  tcphdr->dest = htons(remote_port);
  tcphdr->seqno = htonl(seqno);
  tcphdr->ackno = htonl(ackno);
  (tcphdr)->_hdrlen_rsvd_flags = htons((ntohs((tcphdr)->_hdrlen_rsvd_flags) & ~0x3fU) | (0x04U | 0x10U));
  tcphdr->wnd = htons((2*(1500 - 40)));
  tcphdr->urgp = 0;
  (tcphdr)->_hdrlen_rsvd_flags = htons(((5) << 12) | (ntohs((tcphdr)->_hdrlen_rsvd_flags) & 0x3fU));

  tcphdr->chksum = 0;

  tcphdr->chksum = inet_chksum_pseudo(p, local_ip, remote_ip,
              6, p->tot_len);

  ;
  ;
    
  ip_output(p, local_ip, remote_ip, 255, 0, 6);
  pbuf_free(p);
  do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_rst: seqno %" "8ld" " ackno %" "8ld" ".\n", seqno, ackno);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
}







 
void
tcp_rexmit_rto(struct tcp_pcb *pcb)
{
  struct tcp_seg *seg;

  if (pcb->unacked == 0) {
    return;
  }

   
  for (seg = pcb->unacked; seg->next != 0; seg = seg->next);
   
  seg->next = pcb->unsent;
   
  pcb->unsent = pcb->unacked;
   
  pcb->unacked = 0;

   
  ++pcb->nrtx;

   
  pcb->rttest = 0;

   
  tcp_output(pcb);
}







 
void
tcp_rexmit(struct tcp_pcb *pcb)
{
  struct tcp_seg *seg;
  struct tcp_seg **cur_seg;

  if (pcb->unacked == 0) {
    return;
  }

   
   
  seg = pcb->unacked;
  pcb->unacked = seg->next;

  cur_seg = &(pcb->unsent);
  while (*cur_seg &&
    ((s32_t)((ntohl((*cur_seg)->tcphdr->seqno))-(ntohl(seg->tcphdr->seqno))) < 0)) {
      cur_seg = &((*cur_seg)->next );
  }
  seg->next = *cur_seg;
  *cur_seg = seg;

  ++pcb->nrtx;

   
  pcb->rttest = 0;

   
  ;
  tcp_output(pcb);
}








 
void
tcp_keepalive(struct tcp_pcb *pcb)
{
  struct pbuf *p;
  struct tcp_hdr *tcphdr;

  do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_keepalive: sending KEEPALIVE probe to %" "4d" ".%" "4d" ".%" "4d" ".%" "4d" "\n", ((u16_t)(ntohl((&pcb->remote_ip)->addr) >> 24) & 0xff), ((u16_t)(ntohl((&pcb->remote_ip)->addr) >> 16) & 0xff), ((u16_t)(ntohl((&pcb->remote_ip)->addr) >> 8) & 0xff), ((u16_t)(ntohl((&pcb->remote_ip)->addr)) & 0xff));} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);



  do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_keepalive: tcp_ticks %" "8ld" "   pcb->tmr %" "8ld" " pcb->keep_cnt_sent %" "4d" "\n", tcp_ticks, pcb->tmr, pcb->keep_cnt_sent);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);

   
  p = pbuf_alloc(PBUF_IP, 20, PBUF_RAM);
   
  if(p == 0) {
    do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_keepalive: could not allocate memory for pbuf\n");} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);

    return;
  }
  ;


  tcphdr = tcp_output_set_header(pcb, p, 0, htonl(pcb->snd_nxt - 1));


  tcphdr->chksum = inet_chksum_pseudo(p, &pcb->local_ip, &pcb->remote_ip,
                                      6, p->tot_len);

  ;

   




  ip_output(p, &pcb->local_ip, &pcb->remote_ip, pcb->ttl, 0, 6);


  pbuf_free(p);

  do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_keepalive: seqno %" "8ld" " ackno %" "8ld" ".\n", pcb->snd_nxt - 1, pcb->rcv_nxt);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);

}









 
void
tcp_zero_window_probe(struct tcp_pcb *pcb)
{
  struct pbuf *p;
  struct tcp_hdr *tcphdr;
  struct tcp_seg *seg;

  do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_zero_window_probe: sending ZERO WINDOW probe to %" "4d" ".%" "4d" ".%" "4d" ".%" "4d" "\n", ((u16_t)(ntohl((&pcb->remote_ip)->addr) >> 24) & 0xff), ((u16_t)(ntohl((&pcb->remote_ip)->addr) >> 16) & 0xff), ((u16_t)(ntohl((&pcb->remote_ip)->addr) >> 8) & 0xff), ((u16_t)(ntohl((&pcb->remote_ip)->addr)) & 0xff));} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);





  do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_zero_window_probe: tcp_ticks %" "8ld" "   pcb->tmr %" "8ld" " pcb->keep_cnt_sent %" "4d" "\n", tcp_ticks, pcb->tmr, pcb->keep_cnt_sent);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);




  seg = pcb->unacked;

  if(seg == 0)
    seg = pcb->unsent;

  if(seg == 0)
    return;

  p = pbuf_alloc(PBUF_IP, 20 + 1, PBUF_RAM);
   
  if(p == 0) {
    do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_zero_window_probe: no memory for pbuf\n");} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
    return;
  }
  ;


  tcphdr = tcp_output_set_header(pcb, p, 0, seg->tcphdr->seqno);

   
  *((char *)p->payload + sizeof(struct tcp_hdr)) = *(char *)seg->dataptr;


  tcphdr->chksum = inet_chksum_pseudo(p, &pcb->local_ip, &pcb->remote_ip,
                                      6, p->tot_len);

  ;

   




  ip_output(p, &pcb->local_ip, &pcb->remote_ip, pcb->ttl, 0, 6);


  pbuf_free(p);

  do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_zero_window_probe: seqno %" "8ld" " ackno %" "8ld" ".\n", pcb->snd_nxt - 1, pcb->rcv_nxt);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);


}
