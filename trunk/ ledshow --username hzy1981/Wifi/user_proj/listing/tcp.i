#line 1 "..\\lwIP\\src\\core\\tcp.c"








 































 

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





 


 



 


 



 


 



 


 



 


 






 








 




 







 






 






 






 






 






 






 






 






 






 






 






 






 






 






 






 






 






 






 







 






 






 






 






 






 






 






 






 






 






 






 






 






 






 




#line 44 "..\\lwIP\\src\\core\\tcp.c"



#line 1 "..\\lwIP\\src\\include\\lwip/def.h"






























 



 
#line 37 "..\\lwIP\\src\\include\\lwip/def.h"











#line 48 "..\\lwIP\\src\\core\\tcp.c"
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














#line 49 "..\\lwIP\\src\\core\\tcp.c"
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







#line 50 "..\\lwIP\\src\\core\\tcp.c"
#line 1 "..\\lwIP\\src\\include\\lwip/snmp.h"































 



#line 37 "..\\lwIP\\src\\include\\lwip/snmp.h"
#line 1 "..\\lwIP\\src\\include\\lwip/netif.h"






























 



#line 36 "..\\lwIP\\src\\include\\lwip/netif.h"



#line 1 "..\\lwIP\\src\\include\\lwip/err.h"






























 



#line 36 "..\\lwIP\\src\\include\\lwip/err.h"
#line 37 "..\\lwIP\\src\\include\\lwip/err.h"






 



 typedef s8_t err_t;


 



























extern const char *lwip_strerr(err_t err);








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
#line 1 "..\\lwIP\\src\\include\\lwip/pbuf.h"






























 




#line 37 "..\\lwIP\\src\\include\\lwip/pbuf.h"
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

#line 38 "..\\lwIP\\src\\include\\lwip/snmp.h"
#line 1 "..\\lwIP\\src\\include\\lwip/udp.h"






























 



#line 36 "..\\lwIP\\src\\include\\lwip/udp.h"



#line 40 "..\\lwIP\\src\\include\\lwip/udp.h"
#line 41 "..\\lwIP\\src\\include\\lwip/udp.h"
#line 42 "..\\lwIP\\src\\include\\lwip/udp.h"
#line 1 "..\\lwIP\\src\\include\\ipv4\\lwip/ip.h"






























 



#line 36 "..\\lwIP\\src\\include\\ipv4\\lwip/ip.h"

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







#line 51 "..\\lwIP\\src\\core\\tcp.c"
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
#line 41 "..\\lwIP\\src\\include\\lwip/tcp.h"
#line 42 "..\\lwIP\\src\\include\\lwip/tcp.h"
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









#line 52 "..\\lwIP\\src\\core\\tcp.c"
#line 53 "..\\lwIP\\src\\core\\tcp.c"

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



 
#line 55 "..\\lwIP\\src\\core\\tcp.c"

 
u32_t tcp_ticks;
const u8_t tcp_backoff[13] =
    { 1, 2, 3, 4, 5, 6, 7, 7, 7, 7, 7, 7, 7};
  
const u8_t tcp_persist_backoff[7] = { 3, 6, 12, 24, 48, 96, 120 };

 

 
struct tcp_pcb *tcp_bound_pcbs;  
 
union tcp_listen_pcbs_t tcp_listen_pcbs;

 
struct tcp_pcb *tcp_active_pcbs;  
 
struct tcp_pcb *tcp_tw_pcbs;

struct tcp_pcb *tcp_tmp_pcb;

static u8_t tcp_timer;
static u16_t tcp_new_port(void);




 
void
tcp_tmr(void)
{
   
  tcp_fasttmr();

  if (++tcp_timer & 1) {
    
 
    tcp_slowtmr();
  }
}














 
err_t
tcp_close(struct tcp_pcb *pcb)
{
  err_t err;






  switch (pcb->state) {
  case CLOSED:
    





 
    err = 0;
    do { if(*(&tcp_bound_pcbs) == pcb) { (*(&tcp_bound_pcbs)) = (* &tcp_bound_pcbs)->next; } else { for(tcp_tmp_pcb = * &tcp_bound_pcbs; tcp_tmp_pcb != 0; tcp_tmp_pcb = tcp_tmp_pcb->next) { if(tcp_tmp_pcb->next != 0 && tcp_tmp_pcb->next == pcb) { tcp_tmp_pcb->next = pcb->next; break; } } } pcb->next = 0; } while(0);
    memp_free(MEMP_TCP_PCB, pcb);
    pcb = 0;
    break;
  case LISTEN:
    err = 0;
    tcp_pcb_remove((struct tcp_pcb **)&tcp_listen_pcbs.pcbs, pcb);
    memp_free(MEMP_TCP_PCB_LISTEN, pcb);
    pcb = 0;
    break;
  case SYN_SENT:
    err = 0;
    tcp_pcb_remove(&tcp_active_pcbs, pcb);
    memp_free(MEMP_TCP_PCB, pcb);
    pcb = 0;
    ;
    break;
  case SYN_RCVD:
    err = tcp_send_ctrl(pcb, 0x01U);
    if (err == 0) {
      ;
      pcb->state = FIN_WAIT_1;
    }
    break;
  case ESTABLISHED:
    err = tcp_send_ctrl(pcb, 0x01U);
    if (err == 0) {
      ;
      pcb->state = FIN_WAIT_1;
    }
    break;
  case CLOSE_WAIT:
    err = tcp_send_ctrl(pcb, 0x01U);
    if (err == 0) {
      ;
      pcb->state = LAST_ACK;
    }
    break;
  default:
     
    err = 0;
    pcb = 0;
    break;
  }

  if (pcb != 0 && err == 0) {
    



 
    
 
    tcp_output(pcb);
  }
  return err;
}








 
void
tcp_abandon(struct tcp_pcb *pcb, int reset)
{
  u32_t seqno, ackno;
  u16_t remote_port, local_port;
  struct ip_addr remote_ip, local_ip;

  void (* errf)(void *arg, err_t err);

  void *errf_arg;

  
  

 
  if (pcb->state == TIME_WAIT) {
    tcp_pcb_remove(&tcp_tw_pcbs, pcb);
    memp_free(MEMP_TCP_PCB, pcb);
  } else {
    seqno = pcb->snd_nxt;
    ackno = pcb->rcv_nxt;
    (&local_ip)->addr = ((&(pcb->local_ip)) == 0? 0: (&(pcb->local_ip))->addr);
    (&remote_ip)->addr = ((&(pcb->remote_ip)) == 0? 0: (&(pcb->remote_ip))->addr);
    local_port = pcb->local_port;
    remote_port = pcb->remote_port;

    errf = pcb->errf;

    errf_arg = pcb->callback_arg;
    tcp_pcb_remove(&tcp_active_pcbs, pcb);
    if (pcb->unacked != 0) {
      tcp_segs_free(pcb->unacked);
    }
    if (pcb->unsent != 0) {
      tcp_segs_free(pcb->unsent);
    }





    memp_free(MEMP_TCP_PCB, pcb);
    do { if((errf) != 0) (errf)((errf_arg),(-5)); } while (0);
    if (reset) {
      do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_abandon: sending RST\n");} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
      tcp_rst(seqno, ackno, &local_ip, &remote_ip, local_port, remote_port);
    }
  }
}













 
err_t
tcp_bind(struct tcp_pcb *pcb, struct ip_addr *ipaddr, u16_t port)
{
  struct tcp_pcb *cpcb;

  do { if (!(pcb->state == CLOSED)) { do { printf("Assertion \"%s\" failed at line %d in %s\n", "tcp_bind: can only bind in state CLOSED", 265, "..\\lwIP\\src\\core\\tcp.c"); } while(0); return -13;}} while(0);

  if (port == 0) {
    port = tcp_new_port();
  }
   
   
  for(cpcb = (struct tcp_pcb *)tcp_listen_pcbs.pcbs;
      cpcb != 0; cpcb = cpcb->next) {
    if (cpcb->local_port == port) {
      if (((&(cpcb->local_ip)) == 0 || (&(cpcb->local_ip))->addr == 0) ||
          ((ipaddr) == 0 || (ipaddr)->addr == 0) ||
          ((&(cpcb->local_ip))->addr == (ipaddr)->addr)) {
        return -11;
      }
    }
  }
   
  for(cpcb = tcp_active_pcbs;
      cpcb != 0; cpcb = cpcb->next) {
    if (cpcb->local_port == port) {
      if (((&(cpcb->local_ip)) == 0 || (&(cpcb->local_ip))->addr == 0) ||
          ((ipaddr) == 0 || (ipaddr)->addr == 0) ||
          ((&(cpcb->local_ip))->addr == (ipaddr)->addr)) {
        return -11;
      }
    }
  }
   
  for(cpcb = tcp_bound_pcbs; cpcb != 0; cpcb = cpcb->next) {
    if (cpcb->local_port == port) {
      if (((&(cpcb->local_ip)) == 0 || (&(cpcb->local_ip))->addr == 0) ||
          ((ipaddr) == 0 || (ipaddr)->addr == 0) ||
          ((&(cpcb->local_ip))->addr == (ipaddr)->addr)) {
        return -11;
      }
    }
  }
  
 
  for(cpcb = tcp_tw_pcbs; cpcb != 0; cpcb = cpcb->next) {
    if (cpcb->local_port == port) {
      if (((&(cpcb->local_ip))->addr == (ipaddr)->addr)) {
        return -11;
      }
    }
  }

  if (!((ipaddr) == 0 || (ipaddr)->addr == 0)) {
    pcb->local_ip = *ipaddr;
  }
  pcb->local_port = port;
  do { pcb->next = * &tcp_bound_pcbs; *(&tcp_bound_pcbs) = pcb; ; } while (0);
  do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_bind: bind to port %" "4d" "\n", port);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
  return 0;
}



 
static err_t
tcp_accept_null(void *arg, struct tcp_pcb *pcb, err_t err)
{
  (void)arg;
  (void)pcb;
  (void)err;

  return -5;
}















 
struct tcp_pcb *
tcp_listen_with_backlog(struct tcp_pcb *pcb, u8_t backlog)
{
  struct tcp_pcb_listen *lpcb;

  (void)backlog;
  do { if (!(pcb->state == CLOSED)) { do { printf("Assertion \"%s\" failed at line %d in %s\n", "tcp_listen: pcb already connected", 356, "..\\lwIP\\src\\core\\tcp.c"); } while(0); return 0;}} while(0);

   
  if (pcb->state == LISTEN) {
    return pcb;
  }
  lpcb = memp_malloc(MEMP_TCP_PCB_LISTEN);
  if (lpcb == 0) {
    return 0;
  }
  lpcb->callback_arg = pcb->callback_arg;
  lpcb->local_port = pcb->local_port;
  lpcb->state = LISTEN;
  lpcb->so_options = pcb->so_options;
  lpcb->so_options |= (u16_t)0x0002U;
  lpcb->ttl = pcb->ttl;
  lpcb->tos = pcb->tos;
  (&lpcb->local_ip)->addr = ((&pcb->local_ip) == 0? 0: (&pcb->local_ip)->addr);
  do { if(*(&tcp_bound_pcbs) == pcb) { (*(&tcp_bound_pcbs)) = (* &tcp_bound_pcbs)->next; } else { for(tcp_tmp_pcb = * &tcp_bound_pcbs; tcp_tmp_pcb != 0; tcp_tmp_pcb = tcp_tmp_pcb->next) { if(tcp_tmp_pcb->next != 0 && tcp_tmp_pcb->next == pcb) { tcp_tmp_pcb->next = pcb->next; break; } } } pcb->next = 0; } while(0);
  memp_free(MEMP_TCP_PCB, pcb);

  lpcb->accept = tcp_accept_null;





  do { lpcb->next = * &tcp_listen_pcbs . listen_pcbs; *(&tcp_listen_pcbs . listen_pcbs) = lpcb; ; } while (0);
  return (struct tcp_pcb *)lpcb;
}






 
u32_t tcp_update_rcv_ann_wnd(struct tcp_pcb *pcb)
{
  u32_t new_right_edge = pcb->rcv_nxt + pcb->rcv_wnd;

  if (((s32_t)((new_right_edge)-(pcb->rcv_ann_right_edge + pcb->mss)) >= 0)) {
     
    pcb->rcv_ann_wnd = pcb->rcv_wnd;
    return new_right_edge - pcb->rcv_ann_right_edge;
  } else {
    if (((s32_t)((pcb->rcv_nxt)-(pcb->rcv_ann_right_edge)) > 0)) {
      
 
      pcb->rcv_ann_wnd = 0;
    } else {
       
      pcb->rcv_ann_wnd = pcb->rcv_ann_right_edge - pcb->rcv_nxt;
    }
    return 0;
  }
}








 
void
tcp_recved(struct tcp_pcb *pcb, u16_t len)
{
  int wnd_inflation;

  ;


  pcb->rcv_wnd += len;
  if (pcb->rcv_wnd > (2*(1500 - 40)))
    pcb->rcv_wnd = (2*(1500 - 40));

  wnd_inflation = tcp_update_rcv_ann_wnd(pcb);

  


 
  if (wnd_inflation >= ((2*(1500 - 40)) / 4)) 
    do { (pcb)->flags |= ((u8_t)0x02U); tcp_output(pcb); } while (0);

  do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_recved: recveived %" "4d" " bytes, wnd %" "4d" " (%" "4d" ").\n", len, pcb->rcv_wnd, (2*(1500 - 40)) - pcb->rcv_wnd);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);

}






 
static u16_t
tcp_new_port(void)
{
  struct tcp_pcb *pcb;




  static u16_t port = 4096;
  
 again:
  if (++port > 0x7fff) {
    port = 4096;
  }
  
  for(pcb = tcp_active_pcbs; pcb != 0; pcb = pcb->next) {
    if (pcb->local_port == port) {
      goto again;
    }
  }
  for(pcb = tcp_tw_pcbs; pcb != 0; pcb = pcb->next) {
    if (pcb->local_port == port) {
      goto again;
    }
  }
  for(pcb = (struct tcp_pcb *)tcp_listen_pcbs.pcbs; pcb != 0; pcb = pcb->next) {
    if (pcb->local_port == port) {
      goto again;
    }
  }
  return port;
}












 
err_t
tcp_connect(struct tcp_pcb *pcb, struct ip_addr *ipaddr, u16_t port,
      err_t (* connected)(void *arg, struct tcp_pcb *tpcb, err_t err))
{
  err_t ret;
  u32_t iss;

  do { if (!(pcb->state == CLOSED)) { do { printf("Assertion \"%s\" failed at line %d in %s\n", "tcp_connect: can only connected from state CLOSED", 505, "..\\lwIP\\src\\core\\tcp.c"); } while(0); return -13;}} while(0);

  do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_connect to port %" "4d" "\n", port);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
  if (ipaddr != 0) {
    pcb->remote_ip = *ipaddr;
  } else {
    return -9;
  }
  pcb->remote_port = port;
  if (pcb->local_port == 0) {
    pcb->local_port = tcp_new_port();
  }
  iss = tcp_next_iss();
  pcb->rcv_nxt = 0;
  pcb->snd_nxt = iss;
  pcb->lastack = iss - 1;
  pcb->snd_lbb = iss - 1;
  pcb->rcv_wnd = (2*(1500 - 40));
  pcb->rcv_ann_wnd = (2*(1500 - 40));
  pcb->rcv_ann_right_edge = pcb->rcv_nxt;
  pcb->snd_wnd = (2*(1500 - 40));
  
 
  pcb->mss = ((1500 - 40) > 536) ? 536 : (1500 - 40);

  pcb->mss = tcp_eff_send_mss(pcb->mss, ipaddr);

  pcb->cwnd = 1;
  pcb->ssthresh = pcb->mss * 10;
  pcb->state = SYN_SENT;

  pcb->connected = connected;

  do { if(*(&tcp_bound_pcbs) == pcb) { (*(&tcp_bound_pcbs)) = (* &tcp_bound_pcbs)->next; } else { for(tcp_tmp_pcb = * &tcp_bound_pcbs; tcp_tmp_pcb != 0; tcp_tmp_pcb = tcp_tmp_pcb->next) { if(tcp_tmp_pcb->next != 0 && tcp_tmp_pcb->next == pcb) { tcp_tmp_pcb->next = pcb->next; break; } } } pcb->next = 0; } while(0);
  do { pcb->next = * &tcp_active_pcbs; *(&tcp_active_pcbs) = pcb; ; } while (0);

  ;
  
  ret = tcp_enqueue(pcb, 0, 0, 0x02U, 0, (u8_t)0x01U



                    );
  if (ret == 0) { 
    tcp_output(pcb);
  }
  return ret;
} 







 
void
tcp_slowtmr(void)
{
  struct tcp_pcb *pcb, *pcb2, *prev;
  u16_t eff_wnd;
  u8_t pcb_remove;       
  err_t err;

  err = 0;

  ++tcp_ticks;

   
  prev = 0;
  pcb = tcp_active_pcbs;
  if (pcb == 0) {
    do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_slowtmr: no active pcbs\n");} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
  }
  while (pcb != 0) {
    do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_slowtmr: processing active pcb\n");} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
    ;
    ;
    ;

    pcb_remove = 0;

    if (pcb->state == SYN_SENT && pcb->nrtx == 6) {
      ++pcb_remove;
      do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_slowtmr: max SYN retries reached\n");} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
    }
    else if (pcb->nrtx == 12) {
      ++pcb_remove;
      do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_slowtmr: max DATA retries reached\n");} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
    } else {
      if (pcb->persist_backoff > 0) {
        
 
        pcb->persist_cnt++;
        if (pcb->persist_cnt >= tcp_persist_backoff[pcb->persist_backoff-1]) {
          pcb->persist_cnt = 0;
          if (pcb->persist_backoff < sizeof(tcp_persist_backoff)) {
            pcb->persist_backoff++;
          }
          tcp_zero_window_probe(pcb);
        }
      } else {
         
        if(pcb->rtime >= 0)
          ++pcb->rtime;

        if (pcb->unacked != 0 && pcb->rtime >= pcb->rto) {
           
          do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_slowtmr: rtime %" "4d" " pcb->rto %" "4d" "\n", pcb->rtime, pcb->rto);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);



          
 
          if (pcb->state != SYN_SENT) {
            pcb->rto = ((pcb->sa >> 3) + pcb->sv) << tcp_backoff[pcb->nrtx];
          }

           
          pcb->rtime = 0;

           
          eff_wnd = (((pcb->cwnd) < (pcb->snd_wnd)) ? (pcb->cwnd) : (pcb->snd_wnd));
          pcb->ssthresh = eff_wnd >> 1;
          if (pcb->ssthresh < pcb->mss) {
            pcb->ssthresh = pcb->mss * 2;
          }
          pcb->cwnd = pcb->mss;
          do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_slowtmr: cwnd %" "4d" " ssthresh %" "4d" "\n", pcb->cwnd, pcb->ssthresh);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);


 
          
 
          tcp_rexmit_rto(pcb);
        }
      }
    }
     
    if (pcb->state == FIN_WAIT_2) {
      if ((u32_t)(tcp_ticks - pcb->tmr) >
          20000 / (2*250)) {
        ++pcb_remove;
        do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_slowtmr: removing pcb stuck in FIN-WAIT-2\n");} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
      }
    }

     
    if((pcb->so_options & (u16_t)0x0008U) && 
       ((pcb->state == ESTABLISHED) || 
        (pcb->state == CLOSE_WAIT))) {





      if((u32_t)(tcp_ticks - pcb->tmr) > 
         (pcb->keep_idle + 9U * 75000UL) / (2*250))

      {
        do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_slowtmr: KEEPALIVE timeout. Aborting connection to %" "4d" ".%" "4d" ".%" "4d" ".%" "4d" ".\n", ((u16_t)(ntohl((&pcb->remote_ip)->addr) >> 24) & 0xff), ((u16_t)(ntohl((&pcb->remote_ip)->addr) >> 16) & 0xff), ((u16_t)(ntohl((&pcb->remote_ip)->addr) >> 8) & 0xff), ((u16_t)(ntohl((&pcb->remote_ip)->addr)) & 0xff));} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);


        
        tcp_abandon((pcb), 1);
      }





      else if((u32_t)(tcp_ticks - pcb->tmr) > 
              (pcb->keep_idle + pcb->keep_cnt_sent * 75000UL) 
              / (2*250))

      {
        tcp_keepalive(pcb);
        pcb->keep_cnt_sent++;
      }
    }

    

 
#line 697 "..\\lwIP\\src\\core\\tcp.c"

     
    if (pcb->state == SYN_RCVD) {
      if ((u32_t)(tcp_ticks - pcb->tmr) >
          20000 / (2*250)) {
        ++pcb_remove;
        do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_slowtmr: removing pcb stuck in SYN-RCVD\n");} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
      }
    }

     
    if (pcb->state == LAST_ACK) {
      if ((u32_t)(tcp_ticks - pcb->tmr) > 2 * 60000UL / (2*250)) {
        ++pcb_remove;
        do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_slowtmr: removing pcb stuck in LAST-ACK\n");} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
      }
    }

     
    if (pcb_remove) {
      tcp_pcb_purge(pcb);      
       
      if (prev != 0) {
        ;
        prev->next = pcb->next;
      } else {
         
        ;
        tcp_active_pcbs = pcb->next;
      }

      do { if((pcb->errf) != 0) (pcb->errf)((pcb->callback_arg),(-5)); } while (0);

      pcb2 = pcb->next;
      memp_free(MEMP_TCP_PCB, pcb);
      pcb = pcb2;
    } else {

       
      ++pcb->polltmr;
      if (pcb->polltmr >= pcb->pollinterval) {
        pcb->polltmr = 0;
        do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_slowtmr: polling application\n");} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
        do { if((pcb)->poll != 0) (err) = (pcb)->poll((pcb)->callback_arg,(pcb)); else (err) = 0; } while (0);
        if (err == 0) {
          tcp_output(pcb);
        }
      }
      
      prev = pcb;
      pcb = pcb->next;
    }
  }

  
   
  prev = 0;    
  pcb = tcp_tw_pcbs;
  while (pcb != 0) {
    ;
    pcb_remove = 0;

     
    if ((u32_t)(tcp_ticks - pcb->tmr) > 2 * 60000UL / (2*250)) {
      ++pcb_remove;
    }
    


     
    if (pcb_remove) {
      tcp_pcb_purge(pcb);      
       
      if (prev != 0) {
        ;
        prev->next = pcb->next;
      } else {
         
        ;
        tcp_tw_pcbs = pcb->next;
      }
      pcb2 = pcb->next;
      memp_free(MEMP_TCP_PCB, pcb);
      pcb = pcb2;
    } else {
      prev = pcb;
      pcb = pcb->next;
    }
  }
}






 
void
tcp_fasttmr(void)
{
  struct tcp_pcb *pcb;

  for(pcb = tcp_active_pcbs; pcb != 0; pcb = pcb->next) {
     
    if (pcb->refused_data != 0) {
       
      err_t err;
      do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_fasttmr: notify kept packet\n");} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
      do { if((pcb)->recv != 0) { (err) = (pcb)->recv((pcb)->callback_arg,(pcb),(pcb->refused_data),(0)); } else { (err) = 0; if (pcb->refused_data != 0) pbuf_free(pcb->refused_data); } } while (0);
      if (err == 0) {
        pcb->refused_data = 0;
      }
    }

       
    if (pcb->flags & ((u8_t)0x01U)) {
      do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_fasttmr: delayed ACK\n");} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
      do { (pcb)->flags |= ((u8_t)0x02U); tcp_output(pcb); } while (0);
      pcb->flags &= ~(((u8_t)0x01U) | ((u8_t)0x02U));
    }
  }
}






 
u8_t
tcp_segs_free(struct tcp_seg *seg)
{
  u8_t count = 0;
  struct tcp_seg *next;
  while (seg != 0) {
    next = seg->next;
    count += tcp_seg_free(seg);
    seg = next;
  }
  return count;
}






 
u8_t
tcp_seg_free(struct tcp_seg *seg)
{
  u8_t count = 0;
  
  if (seg != 0) {
    if (seg->p != 0) {
      count = pbuf_free(seg->p);



    }
    memp_free(MEMP_TCP_SEG, seg);
  }
  return count;
}






 
void
tcp_setprio(struct tcp_pcb *pcb, u8_t prio)
{
  pcb->prio = prio;
}
#line 896 "..\\lwIP\\src\\core\\tcp.c"





 
static err_t
tcp_recv_null(void *arg, struct tcp_pcb *pcb, struct pbuf *p, err_t err)
{
  arg = arg;
  if (p != 0) {
    pbuf_free(p);
  } else if (err == 0) {
    return tcp_close(pcb);
  }
  return 0;
}






 
static void
tcp_kill_prio(u8_t prio)
{
  struct tcp_pcb *pcb, *inactive;
  u32_t inactivity;
  u8_t mprio;


  mprio = 127;
  
   
  inactivity = 0;
  inactive = 0;
  for(pcb = tcp_active_pcbs; pcb != 0; pcb = pcb->next) {
    if (pcb->prio <= prio &&
       pcb->prio <= mprio &&
       (u32_t)(tcp_ticks - pcb->tmr) >= inactivity) {
      inactivity = tcp_ticks - pcb->tmr;
      inactive = pcb;
      mprio = pcb->prio;
    }
  }
  if (inactive != 0) {
    do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_kill_prio: killing oldest PCB %p (%" "8ld" ")\n", (void *)inactive, inactivity);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);

    tcp_abandon((inactive), 1);
  }      
}




 
static void
tcp_kill_timewait(void)
{
  struct tcp_pcb *pcb, *inactive;
  u32_t inactivity;

  inactivity = 0;
  inactive = 0;
   
  for(pcb = tcp_tw_pcbs; pcb != 0; pcb = pcb->next) {
    if ((u32_t)(tcp_ticks - pcb->tmr) >= inactivity) {
      inactivity = tcp_ticks - pcb->tmr;
      inactive = pcb;
    }
  }
  if (inactive != 0) {
    do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_kill_timewait: killing oldest TIME-WAIT PCB %p (%" "8ld" ")\n", (void *)inactive, inactivity);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);

    tcp_abandon((inactive), 1);
  }      
}






 
struct tcp_pcb *
tcp_alloc(u8_t prio)
{
  struct tcp_pcb *pcb;
  u32_t iss;
  
  pcb = memp_malloc(MEMP_TCP_PCB);
  if (pcb == 0) {
     
    do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_alloc: killing off oldest TIME-WAIT connection\n");} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
    tcp_kill_timewait();
     
    pcb = memp_malloc(MEMP_TCP_PCB);
    if (pcb == 0) {
       
      tcp_kill_prio(prio);
       
      pcb = memp_malloc(MEMP_TCP_PCB);
    }
  }
  if (pcb != 0) {
    memset(pcb, 0, sizeof(struct tcp_pcb));
    pcb->prio = 64;
    pcb->snd_buf = (1500 - 40);
    pcb->snd_queuelen = 0;
    pcb->rcv_wnd = (2*(1500 - 40));
    pcb->rcv_ann_wnd = (2*(1500 - 40));
    pcb->tos = 0;
    pcb->ttl = 255;
    
 
    pcb->mss = ((1500 - 40) > 536) ? 536 : (1500 - 40);
    pcb->rto = 3000 / (2*250);
    pcb->sa = 0;
    pcb->sv = 3000 / (2*250);
    pcb->rtime = -1;
    pcb->cwnd = 1;
    iss = tcp_next_iss();
    pcb->snd_wl2 = iss;
    pcb->snd_nxt = iss;
    pcb->lastack = iss;
    pcb->snd_lbb = iss;   
    pcb->tmr = tcp_ticks;

    pcb->polltmr = 0;


    pcb->recv = tcp_recv_null;

    
     
    pcb->keep_idle  = 7200000UL;
    





    pcb->keep_cnt_sent = 0;
  }
  return pcb;
}












 
struct tcp_pcb *
tcp_new(void)
{
  return tcp_alloc(64);
}







  
void
tcp_arg(struct tcp_pcb *pcb, void *arg)
{  
  pcb->callback_arg = arg;
}








  
void
tcp_recv(struct tcp_pcb *pcb,
   err_t (* recv)(void *arg, struct tcp_pcb *tpcb, struct pbuf *p, err_t err))
{
  pcb->recv = recv;
}







  
void
tcp_sent(struct tcp_pcb *pcb,
   err_t (* sent)(void *arg, struct tcp_pcb *tpcb, u16_t len))
{
  pcb->sent = sent;
}








  
void
tcp_err(struct tcp_pcb *pcb,
   void (* errf)(void *arg, err_t err))
{
  pcb->errf = errf;
}








  
void
tcp_accept(struct tcp_pcb *pcb,
     err_t (* accept)(void *arg, struct tcp_pcb *newpcb, err_t err))
{
  pcb->accept = accept;
}








  
void
tcp_poll(struct tcp_pcb *pcb,
   err_t (* poll)(void *arg, struct tcp_pcb *tpcb), u8_t interval)
{

  pcb->poll = poll;

  pcb->pollinterval = interval;
}






 
void
tcp_pcb_purge(struct tcp_pcb *pcb)
{
  if (pcb->state != CLOSED &&
     pcb->state != TIME_WAIT &&
     pcb->state != LISTEN) {

    do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_pcb_purge\n");} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);

#line 1186 "..\\lwIP\\src\\core\\tcp.c"


    if (pcb->refused_data != 0) {
      do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_pcb_purge: data left on ->refused_data\n");} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
      pbuf_free(pcb->refused_data);
      pcb->refused_data = 0;
    }
    if (pcb->unsent != 0) {
      do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_pcb_purge: not all data sent\n");} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
    }
    if (pcb->unacked != 0) {
      do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_pcb_purge: data left on ->unacked\n");} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
    }
#line 1211 "..\\lwIP\\src\\core\\tcp.c"
    tcp_segs_free(pcb->unsent);
    tcp_segs_free(pcb->unacked);
    pcb->unacked = pcb->unsent = 0;
  }
}






 
void
tcp_pcb_remove(struct tcp_pcb **pcblist, struct tcp_pcb *pcb)
{
  do { if(*(pcblist) == pcb) { (*(pcblist)) = (*pcblist)->next; } else { for(tcp_tmp_pcb = *pcblist; tcp_tmp_pcb != 0; tcp_tmp_pcb = tcp_tmp_pcb->next) { if(tcp_tmp_pcb->next != 0 && tcp_tmp_pcb->next == pcb) { tcp_tmp_pcb->next = pcb->next; break; } } } pcb->next = 0; } while(0);

  tcp_pcb_purge(pcb);
  
   
  if (pcb->state != TIME_WAIT &&
     pcb->state != LISTEN &&
     pcb->flags & ((u8_t)0x01U)) {
    pcb->flags |= ((u8_t)0x02U);
    tcp_output(pcb);
  }

  if (pcb->state != LISTEN) {
    ;
    ;



  }

  pcb->state = CLOSED;

  ;
}





 
u32_t
tcp_next_iss(void)
{
  static u32_t iss = 6510;
  
  iss += tcp_ticks;        
  return iss;
}






 
u16_t
tcp_eff_send_mss(u16_t sendmss, struct ip_addr *addr)
{
  u16_t mss_s;
  struct netif *outif;

  outif = ip_route(addr);
  if ((outif != 0) && (outif->mtu != 0)) {
    mss_s = outif->mtu - 20 - 20;
    



 
    sendmss = (((sendmss) < (mss_s)) ? (sendmss) : (mss_s));
  }
  return sendmss;
}


#line 1457 "..\\lwIP\\src\\core\\tcp.c"

