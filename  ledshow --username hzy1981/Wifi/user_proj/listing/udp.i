#line 1 "..\\lwIP\\src\\core\\udp.c"




 































 






 


 

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





 


 



 


 



 


 



 


 



 


 






 








 




 







 






 






 






 






 






 






 






 






 






 






 






 






 






 






 






 






 






 






 







 






 






 






 






 






 






 






 






 






 






 






 






 






 






 




#line 50 "..\\lwIP\\src\\core\\udp.c"



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















#line 54 "..\\lwIP\\src\\core\\udp.c"
#line 55 "..\\lwIP\\src\\core\\udp.c"
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







#line 56 "..\\lwIP\\src\\core\\udp.c"
#line 57 "..\\lwIP\\src\\core\\udp.c"
#line 1 "..\\lwIP\\src\\include\\ipv4\\lwip/inet_chksum.h"






























 



#line 36 "..\\lwIP\\src\\include\\ipv4\\lwip/inet_chksum.h"

#line 38 "..\\lwIP\\src\\include\\ipv4\\lwip/inet_chksum.h"
#line 39 "..\\lwIP\\src\\include\\ipv4\\lwip/inet_chksum.h"





u16_t inet_chksum(void *dataptr, u16_t len);
u16_t inet_chksum_pbuf(struct pbuf *p);
u16_t inet_chksum_pseudo(struct pbuf *p,
       struct ip_addr *src, struct ip_addr *dest,
       u8_t proto, u16_t proto_len);












#line 58 "..\\lwIP\\src\\core\\udp.c"
#line 59 "..\\lwIP\\src\\core\\udp.c"
#line 60 "..\\lwIP\\src\\core\\udp.c"
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








 









#line 61 "..\\lwIP\\src\\core\\udp.c"
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





#line 62 "..\\lwIP\\src\\core\\udp.c"
#line 1 "..\\lwIP\\src\\include\\lwip/snmp.h"































 



#line 37 "..\\lwIP\\src\\include\\lwip/snmp.h"
#line 38 "..\\lwIP\\src\\include\\lwip/snmp.h"
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







#line 63 "..\\lwIP\\src\\core\\udp.c"
#line 1 "..\\lwIP\\port\\include\\arch/perf.h"






























 






#line 64 "..\\lwIP\\src\\core\\udp.c"
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





















#line 65 "..\\lwIP\\src\\core\\udp.c"

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



 
#line 67 "..\\lwIP\\src\\core\\udp.c"

 
 
struct udp_pcb *udp_pcbs;












 
void
udp_input(struct pbuf *p, struct netif *inp)
{
  struct udp_hdr *udphdr;
  struct udp_pcb *pcb, *prev;
  struct udp_pcb *uncon_pcb;
  struct ip_hdr *iphdr;
  u16_t src, dest;
  u8_t local_match;
  u8_t broadcast;

  ;

  ;

  iphdr = p->payload;

  
 
  if (p->tot_len < (((ntohs((iphdr)->_v_hl_tos) >> 8) & 0x0f) * 4 + 8) || pbuf_header(p, -(s16_t)(((ntohs((iphdr)->_v_hl_tos) >> 8) & 0x0f) * 4))) {
     
    do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("udp_input: short UDP datagram (%" "4d" " bytes) discarded\n", p->tot_len);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);

    ;
    ;
    ;
    pbuf_free(p);
    goto end;
  }

  udphdr = (struct udp_hdr *)p->payload;

   
  broadcast = ip_addr_isbroadcast(&(iphdr->dest), inp);

  do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("udp_input: received datagram of length %" "4d" "\n", p->tot_len);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);

   
  src = ntohs(udphdr->src);
  dest = ntohs(udphdr->dest);

  ;

   
  do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("udp (%" "4d" ".%" "4d" ".%" "4d" ".%" "4d" ", %" "4d" ") <-- " "(%" "4d" ".%" "4d" ".%" "4d" ".%" "4d" ", %" "4d" ")\n", ((u16_t)(ntohl((&iphdr->dest)->addr) >> 24) & 0xff), ((u16_t)(ntohl((&iphdr->dest)->addr) >> 16) & 0xff), ((u16_t)(ntohl((&iphdr->dest)->addr) >> 8) & 0xff), ((u16_t)(ntohl((&iphdr->dest)->addr)) & 0xff), ntohs(udphdr->dest), ((u16_t)(ntohl((&iphdr->src)->addr) >> 24) & 0xff), ((u16_t)(ntohl((&iphdr->src)->addr) >> 16) & 0xff), ((u16_t)(ntohl((&iphdr->src)->addr) >> 8) & 0xff), ((u16_t)(ntohl((&iphdr->src)->addr)) & 0xff), ntohs(udphdr->src));} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
#line 135 "..\\lwIP\\src\\core\\udp.c"


  pcb = 0;
  
 
  if (dest == 68) {
     
    if (src == 67) {
      if ((inp->dhcp != 0) && (inp->dhcp->pcb != 0)) {
        

 
        if ((((&inp->dhcp->pcb->remote_ip) == 0 || (&inp->dhcp->pcb->remote_ip)->addr == 0) ||
           ((&(inp->dhcp->pcb->remote_ip))->addr == (&(iphdr->src))->addr))) {
          pcb = inp->dhcp->pcb;
        }
      }
    }
  } else

  {
    prev = 0;
    local_match = 0;
    uncon_pcb = 0;
    


 
    for (pcb = udp_pcbs; pcb != 0; pcb = pcb->next) {
      local_match = 0;
       
      do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("pcb (%" "4d" ".%" "4d" ".%" "4d" ".%" "4d" ", %" "4d" ") --- " "(%" "4d" ".%" "4d" ".%" "4d" ".%" "4d" ", %" "4d" ")\n", ((u16_t)(ntohl((&pcb->local_ip)->addr) >> 24) & 0xff), ((u16_t)(ntohl((&pcb->local_ip)->addr) >> 16) & 0xff), ((u16_t)(ntohl((&pcb->local_ip)->addr) >> 8) & 0xff), ((u16_t)(ntohl((&pcb->local_ip)->addr)) & 0xff), pcb->local_port, ((u16_t)(ntohl((&pcb->remote_ip)->addr) >> 24) & 0xff), ((u16_t)(ntohl((&pcb->remote_ip)->addr) >> 16) & 0xff), ((u16_t)(ntohl((&pcb->remote_ip)->addr) >> 8) & 0xff), ((u16_t)(ntohl((&pcb->remote_ip)->addr)) & 0xff), pcb->remote_port);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
#line 173 "..\\lwIP\\src\\core\\udp.c"

       
      if ((pcb->local_port == dest) &&
          ((!broadcast && ((&pcb->local_ip) == 0 || (&pcb->local_ip)->addr == 0)) ||
           ((&(pcb->local_ip))->addr == (&(iphdr->dest))->addr) ||
#line 184 "..\\lwIP\\src\\core\\udp.c"
           (broadcast))) {

        local_match = 1;
        if ((uncon_pcb == 0) && 
            ((pcb->flags & 0x04U) == 0)) {
           
          uncon_pcb = pcb;
        }
      }
       
      if ((local_match != 0) &&
          (pcb->remote_port == src) &&
          (((&pcb->remote_ip) == 0 || (&pcb->remote_ip)->addr == 0) ||
           ((&(pcb->remote_ip))->addr == (&(iphdr->src))->addr))) {
         
        if (prev != 0) {
          
 
          prev->next = pcb->next;
          pcb->next = udp_pcbs;
          udp_pcbs = pcb;
        } else {
          ;
        }
        break;
      }
      prev = pcb;
    }
     
    if (pcb == 0) {
      pcb = uncon_pcb;
    }
  }

   
  if (pcb != 0 || ((&inp->ip_addr)->addr == (&iphdr->dest)->addr)) {
    do { if ( ((0x00U | 0x40U) & 0x80U) && ((0x00U | 0x40U) & 0x80U) && ((s16_t)((0x00U | 0x40U) & 0x03) >= 0x00)) { do {printf ("udp_input: calculating checksum\n");} while(0); if ((0x00U | 0x40U) & 0x08U) { while(1); } } } while(0);
#line 255 "..\\lwIP\\src\\core\\udp.c"
    {

      if (udphdr->chksum != 0) {
        if (inet_chksum_pseudo(p, (struct ip_addr *)&(iphdr->src),
                               (struct ip_addr *)&(iphdr->dest),
                               17, p->tot_len) != 0) {
          do { if ( ((0x00U | 2) & 0x80U) && ((0x00U | 2) & 0x80U) && ((s16_t)((0x00U | 2) & 0x03) >= 0x00)) { do {printf ("udp_input: UDP datagram discarded due to failing checksum\n");} while(0); if ((0x00U | 2) & 0x08U) { while(1); } } } while(0);

          ;
          ;
          ;
          pbuf_free(p);
          goto end;
        }
      }

    }
    if(pbuf_header(p, -8)) {
       
      ;
      ;
      ;
      pbuf_free(p);
      goto end;
    }
    if (pcb != 0) {
      ;
       
      if (pcb->recv != 0) {
         
        pcb->recv(pcb->recv_arg, pcb, p, &(iphdr->src), src);
      } else {
         
        pbuf_free(p);
        goto end;
      }
    } else {
      do { if ( ((0x00U | 0x40U) & 0x80U) && ((0x00U | 0x40U) & 0x80U) && ((s16_t)((0x00U | 0x40U) & 0x03) >= 0x00)) { do {printf ("udp_input: not for us.\n");} while(0); if ((0x00U | 0x40U) & 0x08U) { while(1); } } } while(0);


      
 
      if (!broadcast &&
          !(((&iphdr->dest)->addr & ntohl(0xf0000000UL)) == ntohl(0xe0000000UL))) {
         
        pbuf_header(p, (((ntohs((iphdr)->_v_hl_tos) >> 8) & 0x0f) * 4) + 8);
        ;
        icmp_dest_unreach(p, ICMP_DUR_PORT);
      }

      ;
      ;
      ;
      pbuf_free(p);
    }
  } else {
    pbuf_free(p);
  }
end:
  ;
}


















 
err_t
udp_send(struct udp_pcb *pcb, struct pbuf *p)
{
   
  return udp_sendto(pcb, p, &pcb->remote_ip, pcb->remote_port);
}

















 
err_t
udp_sendto(struct udp_pcb *pcb, struct pbuf *p,
  struct ip_addr *dst_ip, u16_t dst_port)
{
  struct netif *netif;

  do { if ( ((0x00U | 0x40U | 3) & 0x80U) && ((0x00U | 0x40U | 3) & 0x80U) && ((s16_t)((0x00U | 0x40U | 3) & 0x03) >= 0x00)) { do {printf ("udp_send\n");} while(0); if ((0x00U | 0x40U | 3) & 0x08U) { while(1); } } } while(0);

   



  netif = ip_route(dst_ip);


   
  if (netif == 0) {
    do { if ( ((0x00U | 1) & 0x80U) && ((0x00U | 1) & 0x80U) && ((s16_t)((0x00U | 1) & 0x03) >= 0x00)) { do {printf ("udp_send: No route to 0x%" "8lx" "\n", dst_ip->addr);} while(0); if ((0x00U | 1) & 0x08U) { while(1); } } } while(0);
    ;
    return -4;
  }
  return udp_sendto_if(pcb, p, dst_ip, dst_port, netif);
}



















 
err_t
udp_sendto_if(struct udp_pcb *pcb, struct pbuf *p,
  struct ip_addr *dst_ip, u16_t dst_port, struct netif *netif)
{
  struct udp_hdr *udphdr;
  struct ip_addr *src_ip;
  err_t err;
  struct pbuf *q;  

#line 418 "..\\lwIP\\src\\core\\udp.c"

   
  if (pcb->local_port == 0) {
    do { if ( ((0x00U | 0x40U | 2) & 0x80U) && ((0x00U | 0x40U | 2) & 0x80U) && ((s16_t)((0x00U | 0x40U | 2) & 0x03) >= 0x00)) { do {printf ("udp_send: not yet bound to a port, binding now\n");} while(0); if ((0x00U | 0x40U | 2) & 0x08U) { while(1); } } } while(0);
    err = udp_bind(pcb, &pcb->local_ip, pcb->local_port);
    if (err != 0) {
      do { if ( ((0x00U | 0x40U | 2) & 0x80U) && ((0x00U | 0x40U | 2) & 0x80U) && ((s16_t)((0x00U | 0x40U | 2) & 0x03) >= 0x00)) { do {printf ("udp_send: forced port bind failed\n");} while(0); if ((0x00U | 0x40U | 2) & 0x08U) { while(1); } } } while(0);
      return err;
    }
  }

   
  if (pbuf_header(p, 8)) {
     
    q = pbuf_alloc(PBUF_IP, 8, PBUF_RAM);
     
    if (q == 0) {
      do { if ( ((0x00U | 0x40U | 2) & 0x80U) && ((0x00U | 0x40U | 2) & 0x80U) && ((s16_t)((0x00U | 0x40U | 2) & 0x03) >= 0x00)) { do {printf ("udp_send: could not allocate header\n");} while(0); if ((0x00U | 0x40U | 2) & 0x08U) { while(1); } } } while(0);
      return -1;
    }
     
    pbuf_chain(q, p);
     
    do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("udp_send: added header pbuf %p before given pbuf %p\n", (void *)q, (void *)p);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);

  } else {
     
     
    q = p;
    do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("udp_send: added header in given pbuf %p\n", (void *)p);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
  }
  ;

   
  udphdr = q->payload;
  udphdr->src = htons(pcb->local_port);
  udphdr->dest = htons(dst_port);
   
  udphdr->chksum = 0x0000; 

   
  if (((&pcb->local_ip) == 0 || (&pcb->local_ip)->addr == 0)) {
     
    src_ip = &(netif->ip_addr);
  } else {
    
 
    if (!((&(pcb->local_ip))->addr == (&(netif->ip_addr))->addr)) {
       
      if (q != p) {
         
        pbuf_free(q);
        q = 0;
         
      }
      return -9;
    }
     
    src_ip = &(pcb->local_ip);
  }

  do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("udp_send: sending datagram of length %" "4d" "\n", q->tot_len);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);

#line 521 "..\\lwIP\\src\\core\\udp.c"
  {       
    do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("udp_send: UDP packet length %" "4d" "\n", q->tot_len);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
    udphdr->len = htons(q->tot_len);
     

    if ((pcb->flags & 0x01U) == 0) {
      udphdr->chksum = inet_chksum_pseudo(q, src_ip, dst_ip, 17, q->tot_len);
       
      if (udphdr->chksum == 0x0000) udphdr->chksum = 0xffff;
    }

    do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("udp_send: UDP checksum 0x%04" "4x" "\n", udphdr->chksum);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
    do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("udp_send: ip_output_if (,,,,IP_PROTO_UDP,)\n");} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
     



    err = ip_output_if(q, src_ip, dst_ip, pcb->ttl, pcb->tos, 17, netif);



  }
   
  ;

   
  if (q != p) {
     
    pbuf_free(q);
    q = 0;
     
  }

  ;
  return err;
}



















 
err_t
udp_bind(struct udp_pcb *pcb, struct ip_addr *ipaddr, u16_t port)
{
  struct udp_pcb *ipcb;
  u8_t rebind;

  do { if ( ((0x00U | 0x40U | 3) & 0x80U) && ((0x00U | 0x40U | 3) & 0x80U) && ((s16_t)((0x00U | 0x40U | 3) & 0x03) >= 0x00)) { do {printf ("udp_bind(ipaddr = ");} while(0); if ((0x00U | 0x40U | 3) & 0x08U) { while(1); } } } while(0);
  do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("%" "4d" ".%" "4d" ".%" "4d" ".%" "4d", ipaddr != 0 ? (u16_t)(ntohl((ipaddr)->addr) >> 24) & 0xff : 0, ipaddr != 0 ? (u16_t)(ntohl((ipaddr)->addr) >> 16) & 0xff : 0, ipaddr != 0 ? (u16_t)(ntohl((ipaddr)->addr) >> 8) & 0xff : 0, ipaddr != 0 ? (u16_t)ntohl((ipaddr)->addr) & 0xff : 0);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
  do { if ( ((0x00U | 0x40U | 3) & 0x80U) && ((0x00U | 0x40U | 3) & 0x80U) && ((s16_t)((0x00U | 0x40U | 3) & 0x03) >= 0x00)) { do {printf (", port = %" "4d" ")\n", port);} while(0); if ((0x00U | 0x40U | 3) & 0x08U) { while(1); } } } while(0);

  rebind = 0;
   
  for (ipcb = udp_pcbs; ipcb != 0; ipcb = ipcb->next) {
     
    if (pcb == ipcb) {
       
      ;
       
      rebind = 1;
    }

    


 
#line 616 "..\\lwIP\\src\\core\\udp.c"
  }

  (&pcb->local_ip)->addr = ((ipaddr) == 0? 0: (ipaddr)->addr);

   
  if (port == 0) {




    port = 4096;
    ipcb = udp_pcbs;
    while ((ipcb != 0) && (port != 0x7fff)) {
      if (ipcb->local_port == port) {
         
        port++;
         
        ipcb = udp_pcbs;
      } else
         
        ipcb = ipcb->next;
    }
    if (ipcb != 0) {
       
      do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("udp_bind: out of free UDP ports\n");} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
      return -11;
    }
  }
  pcb->local_port = port;
  ;
   
  if (rebind == 0) {
     
    pcb->next = udp_pcbs;
    udp_pcbs = pcb;
  }
  do { if ( ((0x00U | 0x40U | 0x20U) & 0x80U) && ((0x00U | 0x40U | 0x20U) & 0x80U) && ((s16_t)((0x00U | 0x40U | 0x20U) & 0x03) >= 0x00)) { do {printf ("udp_bind: bound to %" "4d" ".%" "4d" ".%" "4d" ".%" "4d" ", port %" "4d" "\n", (u16_t)((ntohl(pcb->local_ip . addr) >> 24) & 0xff), (u16_t)((ntohl(pcb->local_ip . addr) >> 16) & 0xff), (u16_t)((ntohl(pcb->local_ip . addr) >> 8) & 0xff), (u16_t)(ntohl(pcb->local_ip . addr) & 0xff), pcb->local_port);} while(0); if ((0x00U | 0x40U | 0x20U) & 0x08U) { while(1); } } } while(0);





  return 0;
}
















 
err_t
udp_connect(struct udp_pcb *pcb, struct ip_addr *ipaddr, u16_t port)
{
  struct udp_pcb *ipcb;

  if (pcb->local_port == 0) {
    err_t err = udp_bind(pcb, &pcb->local_ip, pcb->local_port);
    if (err != 0)
      return err;
  }

  (&pcb->remote_ip)->addr = ((ipaddr) == 0? 0: (ipaddr)->addr);
  pcb->remote_port = port;
  pcb->flags |= 0x04U;
 
#line 710 "..\\lwIP\\src\\core\\udp.c"
  do { if ( ((0x00U | 0x40U | 0x20U) & 0x80U) && ((0x00U | 0x40U | 0x20U) & 0x80U) && ((s16_t)((0x00U | 0x40U | 0x20U) & 0x03) >= 0x00)) { do {printf ("udp_connect: connected to %" "4d" ".%" "4d" ".%" "4d" ".%" "4d" ",port %" "4d" "\n", (u16_t)((ntohl(pcb->remote_ip . addr) >> 24) & 0xff), (u16_t)((ntohl(pcb->remote_ip . addr) >> 16) & 0xff), (u16_t)((ntohl(pcb->remote_ip . addr) >> 8) & 0xff), (u16_t)(ntohl(pcb->remote_ip . addr) & 0xff), pcb->remote_port);} while(0); if ((0x00U | 0x40U | 0x20U) & 0x08U) { while(1); } } } while(0);






   
  for (ipcb = udp_pcbs; ipcb != 0; ipcb = ipcb->next) {
    if (pcb == ipcb) {
       
      return 0;
    }
  }
   
  pcb->next = udp_pcbs;
  udp_pcbs = pcb;
  return 0;
}





 
void
udp_disconnect(struct udp_pcb *pcb)
{
   
  (&pcb->remote_ip)->addr = ((((struct ip_addr *)&ip_addr_any)) == 0? 0: (((struct ip_addr *)&ip_addr_any))->addr);
  pcb->remote_port = 0;
   
  pcb->flags &= ~0x04U;
}









 
void
udp_recv(struct udp_pcb *pcb,
         void (* recv)(void *arg, struct udp_pcb *upcb, struct pbuf *p,
                       struct ip_addr *addr, u16_t port),
         void *recv_arg)
{
   
  pcb->recv = recv;
  pcb->recv_arg = recv_arg;
}








 
void
udp_remove(struct udp_pcb *pcb)
{
  struct udp_pcb *pcb2;

  ;
   
  if (udp_pcbs == pcb) {
     
    udp_pcbs = udp_pcbs->next;
     
  } else
    for (pcb2 = udp_pcbs; pcb2 != 0; pcb2 = pcb2->next) {
       
      if (pcb2->next != 0 && pcb2->next == pcb) {
         
        pcb2->next = pcb->next;
      }
    }
  memp_free(MEMP_UDP_PCB, pcb);
}








 
struct udp_pcb *
udp_new(void)
{
  struct udp_pcb *pcb;
  pcb = memp_malloc(MEMP_UDP_PCB);
   
  if (pcb != 0) {
    

 
     
    memset(pcb, 0, sizeof(struct udp_pcb));
    pcb->ttl = 255;
  }
  return pcb;
}

#line 839 "..\\lwIP\\src\\core\\udp.c"

