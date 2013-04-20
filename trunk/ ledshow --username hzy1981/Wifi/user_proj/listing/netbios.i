#line 1 "..\\lwIP\\src\\core\\netbios.c"




 


























 

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





 


 



 


 



 


 



 


 



 


 






 








 




 







 






 






 






 






 






 






 






 






 






 






 






 






 






 






 






 






 






 






 







 






 






 






 






 






 






 






 






 






 






 






 






 






 






 




#line 35 "..\\lwIP\\src\\core\\netbios.c"



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















#line 39 "..\\lwIP\\src\\core\\netbios.c"
#line 40 "..\\lwIP\\src\\core\\netbios.c"


typedef struct ip_addr ip_addr_t;
typedef struct ip_addr ip_addr_p_t;









void ip_addr_copy(struct ip_addr *dst,struct ip_addr *sst)
{
	*dst=*sst;
}


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



 
#line 60 "..\\lwIP\\src\\core\\netbios.c"







 






 









 




 


 



 


 
#line 110 "..\\lwIP\\src\\core\\netbios.c"

 
#line 118 "..\\lwIP\\src\\core\\netbios.c"

 



__packed
struct netbios_hdr {
  u16_t trans_id;
  u16_t flags;
  u16_t questions;
  u16_t answerRRs;
  u16_t authorityRRs;
  u16_t additionalRRs;
} ;





 



__packed
struct netbios_name_hdr {
  u8_t nametype;
  u8_t encname[(16*2)+1];
  u16_t type;
  u16_t cls;
  u32_t ttl;
  u16_t datalen;
  u16_t flags;
 
  struct ip_addr addr;
} ;





 



__packed
struct netbios_resp
{
  struct netbios_hdr      resp_hdr;
  struct netbios_name_hdr resp_name;
} ;





 
static int
netbios_name_decoding( char *name_enc, char *name_dec, int name_dec_len)
{
  char *pname;
  char  cname;
  char  cnbname;
  int   index = 0;

  (void)name_dec_len;

   
  pname  = name_enc;
  for (;;) {
    
 
    cname = *pname;
    if (cname == '\0')
      break;     
    if (cname == '.')
      break;     
    if (cname < 'A' || cname > 'Z') {
       
      return -1;
    }
    cname -= 'A';
    cnbname = cname << 4;
    pname++;

    cname = *pname;
    if (cname == '\0' || cname == '.') {
      
 
      return -1;
    }
    if (cname < 'A' || cname > 'Z') {
       
      return -1;
    }
    cname -= 'A';
    cnbname |= cname;
    pname++;

     
    if (index < 16) {
       
      name_dec[index++] = (cnbname!=' '?cnbname:'\0');
    }
  }

  return 0;
}

#line 276 "..\\lwIP\\src\\core\\netbios.c"

 
static void
netbios_recv(void *arg, struct udp_pcb *upcb, struct pbuf *p, ip_addr_t *addr, u16_t port)
{
  (void)arg;
   
  if (p != 0) {
    char   netbios_name[16+1];
    struct netbios_hdr*      netbios_hdr      = (struct netbios_hdr*)p->payload;
    struct netbios_name_hdr* netbios_name_hdr = (struct netbios_name_hdr*)(netbios_hdr+1);
    
     
    if (netif_default != 0) {
       
       
      if (((netbios_hdr->flags & ntohs(0x7800U)) == ntohs(0x0000U)) &&
          ((netbios_hdr->flags & ntohs(0x8000U)) == 0) &&
           (netbios_hdr->questions == ntohs(1))) {
         
        netbios_name_decoding( (char*)(netbios_name_hdr->encname), netbios_name, sizeof(netbios_name));
         
        if (strcmp(netbios_name, "MARVEL") == 0) {
          struct pbuf *q;
          struct netbios_resp *resp;

          q = pbuf_alloc(PBUF_TRANSPORT, sizeof(struct netbios_resp), PBUF_RAM);
          if (q != 0) {
            resp = (struct netbios_resp*)q->payload;

             
            resp->resp_hdr.trans_id      = netbios_hdr->trans_id;
            resp->resp_hdr.flags         = htons(0x8000U |
                                                 0x0000U |
                                                 0x0400U |
                                                 0x0100U);
            resp->resp_hdr.questions     = 0;
            resp->resp_hdr.answerRRs     = htons(1);
            resp->resp_hdr.authorityRRs  = 0;
            resp->resp_hdr.additionalRRs = 0;

             
            memcpy(resp->resp_name . encname,netbios_name_hdr->encname,sizeof(netbios_name_hdr->encname));
            resp->resp_name.nametype     = netbios_name_hdr->nametype;
            resp->resp_name.type         = netbios_name_hdr->type;
            resp->resp_name.cls          = netbios_name_hdr->cls;
            resp->resp_name.ttl          = htonl(300000);
            resp->resp_name.datalen      = htons(sizeof(resp->resp_name.flags)+sizeof(resp->resp_name.addr));
            resp->resp_name.flags        = htons(0x0000U);
            ip_addr_copy(&resp->resp_name.addr, &netif_default->ip_addr);

             
            udp_sendto(upcb, q, addr, port);
            
             
            pbuf_free(q);
          }
        }
      }
    }
     
    pbuf_free(p);
  }
}

void netbios_init(void)
{
  struct udp_pcb *pcb;

  ;

  pcb = udp_new();
  if (pcb != 0) {
     
    pcb->so_options |= (u16_t)0x0020U;
    udp_bind(pcb, ((struct ip_addr *)&ip_addr_any), 137);
    udp_recv(pcb, netbios_recv, pcb);
  }
}
