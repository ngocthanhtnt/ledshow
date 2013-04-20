#line 1 "..\\lwIP\\src\\core\\tcp_in.c"









 































 

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





 


 



 


 



 


 



 


 



 


 






 








 




 







 






 






 






 






 






 






 






 






 






 






 






 






 






 






 






 






 






 






 







 






 






 






 






 






 






 






 






 






 






 






 






 






 






 




#line 45 "..\\lwIP\\src\\core\\tcp_in.c"



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









#line 49 "..\\lwIP\\src\\core\\tcp_in.c"
#line 50 "..\\lwIP\\src\\core\\tcp_in.c"
#line 51 "..\\lwIP\\src\\core\\tcp_in.c"
#line 52 "..\\lwIP\\src\\core\\tcp_in.c"
#line 53 "..\\lwIP\\src\\core\\tcp_in.c"
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







#line 54 "..\\lwIP\\src\\core\\tcp_in.c"
#line 55 "..\\lwIP\\src\\core\\tcp_in.c"
#line 1 "..\\lwIP\\src\\include\\ipv4\\lwip/inet_chksum.h"






























 



#line 36 "..\\lwIP\\src\\include\\ipv4\\lwip/inet_chksum.h"

#line 38 "..\\lwIP\\src\\include\\ipv4\\lwip/inet_chksum.h"
#line 39 "..\\lwIP\\src\\include\\ipv4\\lwip/inet_chksum.h"





u16_t inet_chksum(void *dataptr, u16_t len);
u16_t inet_chksum_pbuf(struct pbuf *p);
u16_t inet_chksum_pseudo(struct pbuf *p,
       struct ip_addr *src, struct ip_addr *dest,
       u8_t proto, u16_t proto_len);












#line 56 "..\\lwIP\\src\\core\\tcp_in.c"
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





#line 57 "..\\lwIP\\src\\core\\tcp_in.c"
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







#line 58 "..\\lwIP\\src\\core\\tcp_in.c"
#line 1 "..\\lwIP\\port\\include\\arch/perf.h"






























 






#line 59 "..\\lwIP\\src\\core\\tcp_in.c"



 
static struct tcp_seg inseg;
static struct tcp_hdr *tcphdr;
static struct ip_hdr *iphdr;
static u32_t seqno, ackno;
static u8_t flags;
static u16_t tcplen;

static u8_t recv_flags;
static struct pbuf *recv_data;

struct tcp_pcb *tcp_input_pcb;

 
static err_t tcp_process(struct tcp_pcb *pcb);
static u8_t tcp_receive(struct tcp_pcb *pcb);
static void tcp_parseopt(struct tcp_pcb *pcb);

static err_t tcp_listen_input(struct tcp_pcb_listen *pcb);
static err_t tcp_timewait_input(struct tcp_pcb *pcb);









 
void
tcp_input(struct pbuf *p, struct netif *inp)
{
  struct tcp_pcb *pcb, *prev;
  struct tcp_pcb_listen *lpcb;
  u8_t hdrlen;
  err_t err;

  ;

  ;
  ;

  iphdr = p->payload;
  tcphdr = (struct tcp_hdr *)((u8_t *)p->payload + ((ntohs((iphdr)->_v_hl_tos) >> 8) & 0x0f) * 4);





   
  if (pbuf_header(p, -((s16_t)(((ntohs((iphdr)->_v_hl_tos) >> 8) & 0x0f) * 4))) || (p->tot_len < sizeof(struct tcp_hdr))) {
     
    do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_input: short packet (%" "4d" " bytes) discarded\n", p->tot_len);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
    ;
    ;
    ;
    pbuf_free(p);
    return;
  }

   
  if (ip_addr_isbroadcast(&(iphdr->dest), inp) ||
      (((&(iphdr->dest))->addr & ntohl(0xf0000000UL)) == ntohl(0xe0000000UL))) {
    ;
    ;
    ;
    pbuf_free(p);
    return;
  }


   
  if (inet_chksum_pseudo(p, (struct ip_addr *)&(iphdr->src),
      (struct ip_addr *)&(iphdr->dest),
      6, p->tot_len) != 0) {
      do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_input: packet discarded due to failing checksum 0x%04" "4x" "\n", inet_chksum_pseudo(p, (struct ip_addr *)&(iphdr->src), (struct ip_addr *)&(iphdr->dest), 6, p->tot_len));} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);





    ;
    ;
    ;
    pbuf_free(p);
    return;
  }


  
 
  hdrlen = (ntohs((tcphdr)->_hdrlen_rsvd_flags) >> 12);
  if(pbuf_header(p, -(hdrlen * 4))){
     
    do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_input: short packet\n");} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
    ;
    ;
    ;
    pbuf_free(p);
    return;
  }

   
  tcphdr->src = ntohs(tcphdr->src);
  tcphdr->dest = ntohs(tcphdr->dest);
  seqno = tcphdr->seqno = ntohl(tcphdr->seqno);
  ackno = tcphdr->ackno = ntohl(tcphdr->ackno);
  tcphdr->wnd = ntohs(tcphdr->wnd);

  flags = (ntohs((tcphdr)->_hdrlen_rsvd_flags) & 0x3fU);
  tcplen = p->tot_len + ((flags & (0x01U | 0x02U)) ? 1 : 0);

  
 
  prev = 0;

  
  for(pcb = tcp_active_pcbs; pcb != 0; pcb = pcb->next) {
    ;
    ;
    ;
    if (pcb->remote_port == tcphdr->src &&
       pcb->local_port == tcphdr->dest &&
       ((&(pcb->remote_ip))->addr == (&(iphdr->src))->addr) &&
       ((&(pcb->local_ip))->addr == (&(iphdr->dest))->addr)) {

      

 
      ;
      if (prev != 0) {
        prev->next = pcb->next;
        pcb->next = tcp_active_pcbs;
        tcp_active_pcbs = pcb;
      }
      ;
      break;
    }
    prev = pcb;
  }

  if (pcb == 0) {
    
 
    for(pcb = tcp_tw_pcbs; pcb != 0; pcb = pcb->next) {
      ;
      if (pcb->remote_port == tcphdr->src &&
         pcb->local_port == tcphdr->dest &&
         ((&(pcb->remote_ip))->addr == (&(iphdr->src))->addr) &&
         ((&(pcb->local_ip))->addr == (&(iphdr->dest))->addr)) {
        

 
        do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_input: packed for TIME_WAITing connection.\n");} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
        tcp_timewait_input(pcb);
        pbuf_free(p);
        return;
      }
    }

  
 
    prev = 0;
    for(lpcb = tcp_listen_pcbs.listen_pcbs; lpcb != 0; lpcb = lpcb->next) {
      if ((((&(lpcb->local_ip)) == 0 || (&(lpcb->local_ip))->addr == 0) ||
        ((&(lpcb->local_ip))->addr == (&(iphdr->dest))->addr)) &&
        lpcb->local_port == tcphdr->dest) {
        

 
        if (prev != 0) {
          ((struct tcp_pcb_listen *)prev)->next = lpcb->next;
                 
          lpcb->next = tcp_listen_pcbs.listen_pcbs;
                 
          tcp_listen_pcbs.listen_pcbs = lpcb;
        }
      
        do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_input: packed for LISTENing connection.\n");} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
        tcp_listen_input(lpcb);
        pbuf_free(p);
        return;
      }
      prev = (struct tcp_pcb *)lpcb;
    }
  }








  if (pcb != 0) {
     






     
    inseg.next = 0;
    inseg.len = p->tot_len;
    inseg.dataptr = p->payload;
    inseg.p = p;
    inseg.tcphdr = tcphdr;

    recv_data = 0;
    recv_flags = 0;

     
    if (pcb->refused_data != 0) {
       
      do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_input: notify kept packet\n");} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
      do { if((pcb)->recv != 0) { (err) = (pcb)->recv((pcb)->callback_arg,(pcb),(pcb->refused_data),(0)); } else { (err) = 0; if (pcb->refused_data != 0) pbuf_free(pcb->refused_data); } } while (0);
      if (err == 0) {
        pcb->refused_data = 0;
      } else {
         
        do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_input: drop incoming packets, because pcb is \"full\"\n");} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
        ;
        ;
        pbuf_free(p);
        return;
      }
    }

    tcp_input_pcb = pcb;
    err = tcp_process(pcb);
    tcp_input_pcb = 0;
    
 
    if (err != -5) {
      if (recv_flags & (u8_t)0x08U) {
        


 
        do { if((pcb->errf) != 0) (pcb->errf)((pcb->callback_arg),(-6)); } while (0);
        tcp_pcb_remove(&tcp_active_pcbs, pcb);
        memp_free(MEMP_TCP_PCB, pcb);
      } else if (recv_flags & (u8_t)0x10U) {
        
 
        tcp_pcb_remove(&tcp_active_pcbs, pcb);
        memp_free(MEMP_TCP_PCB, pcb);
      } else {
        err = 0;
        

 
        if (pcb->acked > 0) {
          do { if((pcb)->sent != 0) (err) = (pcb)->sent((pcb)->callback_arg,(pcb),(pcb->acked)); else (err) = 0; } while (0);
        }
      
        if (recv_data != 0) {
          if(flags & 0x08U) {
            recv_data->flags |= 0x01U;
          }

           
          do { if((pcb)->recv != 0) { (err) = (pcb)->recv((pcb)->callback_arg,(pcb),(recv_data),(0)); } else { (err) = 0; if (recv_data != 0) pbuf_free(recv_data); } } while (0);

           
          if (err != 0) {
            pcb->refused_data = recv_data;
            do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_input: keep incoming packet, because pcb is \"full\"\n");} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
          }
        }

        
 
        if (recv_flags & (u8_t)0x20U) {
          do { if((pcb)->recv != 0) { (err) = (pcb)->recv((pcb)->callback_arg,(pcb),(0),(0)); } else { (err) = 0; if (0 != 0) pbuf_free(0); } } while (0);
        }

         
        if (err == 0) {
          tcp_output(pcb);
        }
      }
    }


     
    if (inseg.p != 0)
    {
      pbuf_free(inseg.p);
      inseg.p = 0;
    }





      
  } else {

    
 
    do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_input: no PCB match found, resetting.\n");} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
    if (!((ntohs((tcphdr)->_hdrlen_rsvd_flags) & 0x3fU) & 0x04U)) {
      ;
      ;
      tcp_rst(ackno, seqno + tcplen,
        &(iphdr->dest), &(iphdr->src),
        tcphdr->dest, tcphdr->src);
    }
    pbuf_free(p);
  }

  ;
  ;
}












 
static err_t
tcp_listen_input(struct tcp_pcb_listen *pcb)
{
  struct tcp_pcb *npcb;
  err_t rc;

  
 
  if (flags & 0x10U) {
    
 
    do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_listen_input: ACK in LISTEN, sending reset\n");} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
    tcp_rst(ackno + 1, seqno + tcplen,
      &(iphdr->dest), &(iphdr->src),
      tcphdr->dest, tcphdr->src);
  } else if (flags & 0x02U) {
    do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("TCP connection request %" "4d" " -> %" "4d" ".\n", tcphdr->src, tcphdr->dest);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
#line 415 "..\\lwIP\\src\\core\\tcp_in.c"
    npcb = tcp_alloc(pcb->prio);
    

 
    if (npcb == 0) {
      do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_listen_input: could not allocate PCB\n");} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
      ;
      return -1;
    }



     
    (&(npcb->local_ip))->addr = ((&(iphdr->dest)) == 0? 0: (&(iphdr->dest))->addr);
    npcb->local_port = pcb->local_port;
    (&(npcb->remote_ip))->addr = ((&(iphdr->src)) == 0? 0: (&(iphdr->src))->addr);
    npcb->remote_port = tcphdr->src;
    npcb->state = SYN_RCVD;
    npcb->rcv_nxt = seqno + 1;
    npcb->rcv_ann_right_edge = npcb->rcv_nxt;
    npcb->snd_wnd = tcphdr->wnd;
    npcb->ssthresh = npcb->snd_wnd;
    npcb->snd_wl1 = seqno - 1; 
    npcb->callback_arg = pcb->callback_arg;

    npcb->accept = pcb->accept;

     
    npcb->so_options = pcb->so_options & ((u16_t)0x0001U|(u16_t)0x0010U|(u16_t)0x0008U|(u16_t)0x0100U|(u16_t)0x0080U);
    
 
    do { npcb->next = * &tcp_active_pcbs; *(&tcp_active_pcbs) = npcb; ; } while (0);

     
    tcp_parseopt(npcb);

    npcb->mss = tcp_eff_send_mss(npcb->mss, &(npcb->remote_ip));


    ;

     
    rc = tcp_enqueue(npcb, 0, 0, 0x02U | 0x10U, 0, (u8_t)0x01U




      );
    if (rc != 0) {
      tcp_abandon(npcb, 0);
      return rc;
    }
    return tcp_output(npcb);
  }
  return 0;
}









 
static err_t
tcp_timewait_input(struct tcp_pcb *pcb)
{
  if (((s32_t)((seqno + tcplen)-(pcb->rcv_nxt)) > 0)) {
    pcb->rcv_nxt = seqno + tcplen;
  }
  if (tcplen > 0) {
    do { (pcb)->flags |= ((u8_t)0x02U); tcp_output(pcb); } while (0);
  }
  return tcp_output(pcb);
}











 
static err_t
tcp_process(struct tcp_pcb *pcb)
{
  struct tcp_seg *rseg;
  u8_t acceptable = 0;
  err_t err;

  err = 0;

   
  if (flags & 0x04U) {
     
    if (pcb->state == SYN_SENT) {
      if (ackno == pcb->snd_nxt) {
        acceptable = 1;
      }
    } else {
      if ((((s32_t)((seqno)-(pcb->rcv_nxt)) >= 0) && ((s32_t)((seqno)-(pcb->rcv_nxt+pcb->rcv_wnd)) <= 0))) {

        acceptable = 1;
      }
    }

    if (acceptable) {
      do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_process: Connection RESET\n");} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
      ;
      recv_flags |= (u8_t)0x08U;
      pcb->flags &= ~((u8_t)0x01U);
      return -6;
    } else {
      do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_process: unacceptable reset seqno %" "8ld" " rcv_nxt %" "8ld" "\n", seqno, pcb->rcv_nxt);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);

      do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_process: unacceptable reset seqno %" "8ld" " rcv_nxt %" "8ld" "\n", seqno, pcb->rcv_nxt);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);

      return 0;
    }
  }

  if ((flags & 0x02U) && (pcb->state != SYN_SENT && pcb->state != SYN_RCVD)) { 
     
    do { (pcb)->flags |= ((u8_t)0x02U); tcp_output(pcb); } while (0);
    return 0;
  }
  
   
  pcb->tmr = tcp_ticks;
  pcb->keep_cnt_sent = 0;

  tcp_parseopt(pcb);

   
  switch (pcb->state) {
  case SYN_SENT:
    do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("SYN-SENT: ackno %" "8ld" " pcb->snd_nxt %" "8ld" " unacked %" "8ld" "\n", ackno, pcb->snd_nxt, ntohl(pcb->unacked->tcphdr->seqno));} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);

     
    if ((flags & 0x10U) && (flags & 0x02U)
        && ackno == ntohl(pcb->unacked->tcphdr->seqno) + 1) {
      pcb->snd_buf++;
      pcb->rcv_nxt = seqno + 1;
      pcb->rcv_ann_right_edge = pcb->rcv_nxt;
      pcb->lastack = ackno;
      pcb->snd_wnd = tcphdr->wnd;
      pcb->snd_wl1 = seqno - 1;  
      pcb->state = ESTABLISHED;


      pcb->mss = tcp_eff_send_mss(pcb->mss, &(pcb->remote_ip));


      
 
      pcb->ssthresh = pcb->mss * 10;

      pcb->cwnd = ((pcb->cwnd == 1) ? (pcb->mss * 2) : pcb->mss);
      ;
      --pcb->snd_queuelen;
      do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_process: SYN-SENT --queuelen %" "4d" "\n", (u16_t)pcb->snd_queuelen);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
      rseg = pcb->unacked;
      pcb->unacked = rseg->next;

      
 
      if(pcb->unacked == 0)
        pcb->rtime = -1;
      else {
        pcb->rtime = 0;
        pcb->nrtx = 0;
      }

      tcp_seg_free(rseg);

      
 
      do { if((pcb)->connected != 0) (err) = (pcb)->connected((pcb)->callback_arg,(pcb),(0)); else (err) = 0; } while (0);
      do { (pcb)->flags |= ((u8_t)0x02U); tcp_output(pcb); } while (0);
    }
     
    else if (flags & 0x10U) {
       
      tcp_rst(ackno, seqno + tcplen, &(iphdr->dest), &(iphdr->src),
        tcphdr->dest, tcphdr->src);
    }
    break;
  case SYN_RCVD:
    if (flags & 0x10U) {
       
      if ((((s32_t)((ackno)-(pcb->lastack+1)) >= 0) && ((s32_t)((ackno)-(pcb->snd_nxt)) <= 0))) {
        u16_t old_cwnd;
        pcb->state = ESTABLISHED;
        do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("TCP connection established %" "4d" " -> %" "4d" ".\n", inseg . tcphdr->src, inseg . tcphdr->dest);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);

        ;

         
        do { if((pcb)->accept != 0) (err) = (pcb)->accept((pcb)->callback_arg,(pcb),(0)); else (err) = 0; } while (0);
        if (err != 0) {
          
 
          tcp_abandon((pcb), 1);
          return -5;
        }
        old_cwnd = pcb->cwnd;
        
 
        tcp_receive(pcb);

        pcb->cwnd = ((old_cwnd == 1) ? (pcb->mss * 2) : pcb->mss);

        if (recv_flags & (u8_t)0x20U) {
          do { (pcb)->flags |= ((u8_t)0x02U); tcp_output(pcb); } while (0);
          pcb->state = CLOSE_WAIT;
        }
      }
       
      else {
         
        tcp_rst(ackno, seqno + tcplen, &(iphdr->dest), &(iphdr->src),
                tcphdr->dest, tcphdr->src);
      }
    } else if ((flags & 0x02U) && (seqno == pcb->rcv_nxt - 1)) {
       
      tcp_rexmit(pcb);
    }
    break;
  case CLOSE_WAIT:
     
  case ESTABLISHED:
    tcp_receive(pcb);
    if (recv_flags & (u8_t)0x20U) {  
      do { (pcb)->flags |= ((u8_t)0x02U); tcp_output(pcb); } while (0);
      pcb->state = CLOSE_WAIT;
    }
    break;
  case FIN_WAIT_1:
    tcp_receive(pcb);
    if (recv_flags & (u8_t)0x20U) {
      if ((flags & 0x10U) && (ackno == pcb->snd_nxt)) {
        do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("TCP connection closed %" "4d" " -> %" "4d" ".\n", inseg . tcphdr->src, inseg . tcphdr->dest);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);

        do { (pcb)->flags |= ((u8_t)0x02U); tcp_output(pcb); } while (0);
        tcp_pcb_purge(pcb);
        do { if(*(&tcp_active_pcbs) == pcb) { (*(&tcp_active_pcbs)) = (* &tcp_active_pcbs)->next; } else { for(tcp_tmp_pcb = * &tcp_active_pcbs; tcp_tmp_pcb != 0; tcp_tmp_pcb = tcp_tmp_pcb->next) { if(tcp_tmp_pcb->next != 0 && tcp_tmp_pcb->next == pcb) { tcp_tmp_pcb->next = pcb->next; break; } } } pcb->next = 0; } while(0);
        pcb->state = TIME_WAIT;
        do { pcb->next = * &tcp_tw_pcbs; *(&tcp_tw_pcbs) = pcb; ; } while (0);
      } else {
        do { (pcb)->flags |= ((u8_t)0x02U); tcp_output(pcb); } while (0);
        pcb->state = CLOSING;
      }
    } else if ((flags & 0x10U) && (ackno == pcb->snd_nxt)) {
      pcb->state = FIN_WAIT_2;
    }
    break;
  case FIN_WAIT_2:
    tcp_receive(pcb);
    if (recv_flags & (u8_t)0x20U) {
      do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("TCP connection closed %" "4d" " -> %" "4d" ".\n", inseg . tcphdr->src, inseg . tcphdr->dest);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
      do { (pcb)->flags |= ((u8_t)0x02U); tcp_output(pcb); } while (0);
      tcp_pcb_purge(pcb);
      do { if(*(&tcp_active_pcbs) == pcb) { (*(&tcp_active_pcbs)) = (* &tcp_active_pcbs)->next; } else { for(tcp_tmp_pcb = * &tcp_active_pcbs; tcp_tmp_pcb != 0; tcp_tmp_pcb = tcp_tmp_pcb->next) { if(tcp_tmp_pcb->next != 0 && tcp_tmp_pcb->next == pcb) { tcp_tmp_pcb->next = pcb->next; break; } } } pcb->next = 0; } while(0);
      pcb->state = TIME_WAIT;
      do { pcb->next = * &tcp_tw_pcbs; *(&tcp_tw_pcbs) = pcb; ; } while (0);
    }
    break;
  case CLOSING:
    tcp_receive(pcb);
    if (flags & 0x10U && ackno == pcb->snd_nxt) {
      do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("TCP connection closed %" "4d" " -> %" "4d" ".\n", inseg . tcphdr->src, inseg . tcphdr->dest);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
      tcp_pcb_purge(pcb);
      do { if(*(&tcp_active_pcbs) == pcb) { (*(&tcp_active_pcbs)) = (* &tcp_active_pcbs)->next; } else { for(tcp_tmp_pcb = * &tcp_active_pcbs; tcp_tmp_pcb != 0; tcp_tmp_pcb = tcp_tmp_pcb->next) { if(tcp_tmp_pcb->next != 0 && tcp_tmp_pcb->next == pcb) { tcp_tmp_pcb->next = pcb->next; break; } } } pcb->next = 0; } while(0);
      pcb->state = TIME_WAIT;
      do { pcb->next = * &tcp_tw_pcbs; *(&tcp_tw_pcbs) = pcb; ; } while (0);
    }
    break;
  case LAST_ACK:
    tcp_receive(pcb);
    if (flags & 0x10U && ackno == pcb->snd_nxt) {
      do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("TCP connection closed %" "4d" " -> %" "4d" ".\n", inseg . tcphdr->src, inseg . tcphdr->dest);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
       
      recv_flags |= (u8_t)0x10U;
    }
    break;
  default:
    break;
  }
  return 0;
}














 
static u8_t
tcp_receive(struct tcp_pcb *pcb)
{
  struct tcp_seg *next;



  struct pbuf *p;
  s32_t off;
  s16_t m;
  u32_t right_wnd_edge;
  u16_t new_tot_len;
  u8_t accepted_inseq = 0;

  if (flags & 0x10U) {
    right_wnd_edge = pcb->snd_wnd + pcb->snd_wl2;

     
    if (((s32_t)((pcb->snd_wl1)-(seqno)) < 0) ||
       (pcb->snd_wl1 == seqno && ((s32_t)((pcb->snd_wl2)-(ackno)) < 0)) ||
       (pcb->snd_wl2 == ackno && tcphdr->wnd > pcb->snd_wnd)) {
      pcb->snd_wnd = tcphdr->wnd;
      pcb->snd_wl1 = seqno;
      pcb->snd_wl2 = ackno;
      if (pcb->snd_wnd > 0 && pcb->persist_backoff > 0) {
          pcb->persist_backoff = 0;
      }
      do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_receive: window update %" "4d" "\n", pcb->snd_wnd);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
#line 763 "..\\lwIP\\src\\core\\tcp_in.c"
    }

    if (pcb->lastack == ackno) {
      pcb->acked = 0;

      if (pcb->snd_wl2 + pcb->snd_wnd == right_wnd_edge){
        ++pcb->dupacks;
        if (pcb->dupacks >= 3 && pcb->unacked != 0) {
          if (!(pcb->flags & ((u8_t)0x04U))) {
             
            do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_receive: dupacks %" "4d" " (%" "8ld" "), fast retransmit %" "8ld" "\n", (u16_t)pcb->dupacks, pcb->lastack, ntohl(pcb->unacked->tcphdr->seqno));} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);


            tcp_rexmit(pcb);
             
            

 
             
            if (pcb->cwnd > pcb->snd_wnd)
              pcb->ssthresh = pcb->snd_wnd / 2;
            else
              pcb->ssthresh = pcb->cwnd / 2;

             
            if (pcb->ssthresh < 2*pcb->mss) {
              do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_receive: The minimum value for ssthresh %" "4d" " should be min 2 mss %" "4d" "...\n", pcb->ssthresh, 2*pcb->mss);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
              pcb->ssthresh = 2*pcb->mss;
            }

            pcb->cwnd = pcb->ssthresh + 3 * pcb->mss;
            pcb->flags |= ((u8_t)0x04U);
          } else {
            
 
            if ((u16_t)(pcb->cwnd + pcb->mss) > pcb->cwnd) {
              pcb->cwnd += pcb->mss;
            }
          }
        }
      } else {
        do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_receive: dupack averted %" "8ld" " %" "8ld" "\n", pcb->snd_wl2 + pcb->snd_wnd, right_wnd_edge);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);

      }
    } else if ((((s32_t)((ackno)-(pcb->lastack+1)) >= 0) && ((s32_t)((ackno)-(pcb->snd_nxt)) <= 0))){
       
      
      

 
      if (pcb->flags & ((u8_t)0x04U)) {
        pcb->flags &= ~((u8_t)0x04U);
        pcb->cwnd = pcb->ssthresh;
      }

       
      pcb->nrtx = 0;

       
      pcb->rto = (pcb->sa >> 3) + pcb->sv;

       
      pcb->acked = (u16_t)(ackno - pcb->lastack);

      pcb->snd_buf += pcb->acked;

       
      pcb->dupacks = 0;
      pcb->lastack = ackno;

      
 
      if (pcb->state >= ESTABLISHED) {
        if (pcb->cwnd < pcb->ssthresh) {
          if ((u16_t)(pcb->cwnd + pcb->mss) > pcb->cwnd) {
            pcb->cwnd += pcb->mss;
          }
          do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_receive: slow start cwnd %" "4d" "\n", pcb->cwnd);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
        } else {
          u16_t new_cwnd = (pcb->cwnd + pcb->mss * pcb->mss / pcb->cwnd);
          if (new_cwnd > pcb->cwnd) {
            pcb->cwnd = new_cwnd;
          }
          do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_receive: congestion avoidance cwnd %" "4d" "\n", pcb->cwnd);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
        }
      }
      do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_receive: ACK for %" "8ld" ", unacked->seqno %" "8ld" ":%" "8ld" "\n", ackno, pcb->unacked != 0? ntohl(pcb->unacked->tcphdr->seqno): 0, pcb->unacked != 0? ntohl(pcb->unacked->tcphdr->seqno) + ((pcb->unacked)->len + (((ntohs(((pcb->unacked)->tcphdr)->_hdrlen_rsvd_flags) & 0x3fU) & 0x01U || (ntohs(((pcb->unacked)->tcphdr)->_hdrlen_rsvd_flags) & 0x3fU) & 0x02U)? 1: 0)): 0);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);






      
 
      while (pcb->unacked != 0 &&
             ((s32_t)((ntohl(pcb->unacked->tcphdr->seqno) + ((pcb->unacked)->len + (((ntohs(((pcb->unacked)->tcphdr)->_hdrlen_rsvd_flags) & 0x3fU) & 0x01U || (ntohs(((pcb->unacked)->tcphdr)->_hdrlen_rsvd_flags) & 0x3fU) & 0x02U)? 1: 0)))-(ackno)) <= 0)) {

        do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_receive: removing %" "8ld" ":%" "8ld" " from pcb->unacked\n", ntohl(pcb->unacked->tcphdr->seqno), ntohl(pcb->unacked->tcphdr->seqno) + ((pcb->unacked)->len + (((ntohs(((pcb->unacked)->tcphdr)->_hdrlen_rsvd_flags) & 0x3fU) & 0x01U || (ntohs(((pcb->unacked)->tcphdr)->_hdrlen_rsvd_flags) & 0x3fU) & 0x02U)? 1: 0)));} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);




        next = pcb->unacked;
        pcb->unacked = pcb->unacked->next;

        do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_receive: queuelen %" "4d" " ... ", (u16_t)pcb->snd_queuelen);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
        ;
        pcb->snd_queuelen -= pbuf_clen(next->p);
        tcp_seg_free(next);

        do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("%" "4d" " (after freeing unacked)\n", (u16_t)pcb->snd_queuelen);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
        if (pcb->snd_queuelen != 0) {
          ;

        }
      }

      
 
      if(pcb->unacked == 0)
        pcb->rtime = -1;
      else
        pcb->rtime = 0;

      pcb->polltmr = 0;
    } else {
       
      pcb->acked = 0;
    }

    




 
    while (pcb->unsent != 0 &&
           (((s32_t)((ackno)-(ntohl(pcb->unsent->tcphdr->seqno) + ((pcb->unsent)->len + (((ntohs(((pcb->unsent)->tcphdr)->_hdrlen_rsvd_flags) & 0x3fU) & 0x01U || (ntohs(((pcb->unsent)->tcphdr)->_hdrlen_rsvd_flags) & 0x3fU) & 0x02U)? 1: 0)))) >= 0) && ((s32_t)((ackno)-(pcb->snd_nxt)) <= 0))) {

      do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_receive: removing %" "8ld" ":%" "8ld" " from pcb->unsent\n", ntohl(pcb->unsent->tcphdr->seqno), ntohl(pcb->unsent->tcphdr->seqno) + ((pcb->unsent)->len + (((ntohs(((pcb->unsent)->tcphdr)->_hdrlen_rsvd_flags) & 0x3fU) & 0x01U || (ntohs(((pcb->unsent)->tcphdr)->_hdrlen_rsvd_flags) & 0x3fU) & 0x02U)? 1: 0)));} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);



      next = pcb->unsent;
      pcb->unsent = pcb->unsent->next;
      do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_receive: queuelen %" "4d" " ... ", (u16_t)pcb->snd_queuelen);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
      ;
      pcb->snd_queuelen -= pbuf_clen(next->p);
      tcp_seg_free(next);
      do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("%" "4d" " (after freeing unsent)\n", (u16_t)pcb->snd_queuelen);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
      if (pcb->snd_queuelen != 0) {
        ;

      }
    }
     

    do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_receive: pcb->rttest %" "8ld" " rtseq %" "8ld" " ackno %" "8ld" "\n", pcb->rttest, pcb->rtseq, ackno);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);


    

 
    if (pcb->rttest && ((s32_t)((pcb->rtseq)-(ackno)) < 0)) {
      
 
      m = (s16_t)(tcp_ticks - pcb->rttest);

      do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_receive: experienced rtt %" "4d" " ticks (%" "4d" " msec).\n", m, m * (2*250));} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);


       
      m = m - (pcb->sa >> 3);
      pcb->sa += m;
      if (m < 0) {
        m = -m;
      }
      m = m - (pcb->sv >> 2);
      pcb->sv += m;
      pcb->rto = (pcb->sa >> 3) + pcb->sv;

      do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_receive: RTO %" "4d" " (%" "4d" " milliseconds)\n", pcb->rto, pcb->rto * (2*250));} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);


      pcb->rttest = 0;
    }
  }

  
 
  if (tcplen > 0) {
    





















 

    


 
    
 
    if ((((s32_t)((pcb->rcv_nxt)-(seqno + 1)) >= 0) && ((s32_t)((pcb->rcv_nxt)-(seqno + tcplen - 1)) <= 0))){
      

















 

      off = pcb->rcv_nxt - seqno;
      p = inseg.p;
      ;
      ;
      if (inseg.p->len < off) {
        ;
        new_tot_len = (u16_t)(inseg.p->tot_len - off);
        while (p->len < off) {
          off -= p->len;
          

 
          p->tot_len = new_tot_len;
          p->len = 0;
          p = p->next;
        }
        if(pbuf_header(p, (s16_t)-off)) {
           
          ;
        }
      } else {
        if(pbuf_header(inseg.p, (s16_t)-off)) {
           
          ;
        }
      }
      
 
      inseg.dataptr = p->payload;
      inseg.len -= (u16_t)(pcb->rcv_nxt - seqno);
      inseg.tcphdr->seqno = seqno = pcb->rcv_nxt;
    }
    else {
      if (((s32_t)((seqno)-(pcb->rcv_nxt)) < 0)){
         
         

        do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_receive: duplicate seqno %" "8ld" "\n", seqno);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
        do { (pcb)->flags |= ((u8_t)0x02U); tcp_output(pcb); } while (0);
      }
    }

    

 
    if ((((s32_t)((seqno)-(pcb->rcv_nxt)) >= 0) && ((s32_t)((seqno)-(pcb->rcv_nxt + pcb->rcv_wnd - 1)) <= 0))){

      if (pcb->rcv_nxt == seqno) {
        accepted_inseq = 1; 
        

 
        tcplen = ((&inseg)->len + (((ntohs(((&inseg)->tcphdr)->_hdrlen_rsvd_flags) & 0x3fU) & 0x01U || (ntohs(((&inseg)->tcphdr)->_hdrlen_rsvd_flags) & 0x3fU) & 0x02U)? 1: 0));

        if (tcplen > pcb->rcv_wnd) {
          do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_receive: other end overran receive window" "seqno %" "8ld" " len %" "8ld" " right edge %" "8ld" "\n", seqno, tcplen, pcb->rcv_nxt + pcb->rcv_wnd);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);



          if ((ntohs((inseg . tcphdr)->_hdrlen_rsvd_flags) & 0x3fU) & 0x01U) {
            
 
            (inseg . tcphdr)->_hdrlen_rsvd_flags = htons((ntohs((inseg . tcphdr)->_hdrlen_rsvd_flags) & ~0x3fU) | ((ntohs((inseg . tcphdr)->_hdrlen_rsvd_flags) & 0x3fU) &~ 0x01U));
          }
           
          inseg.len = pcb->rcv_wnd;
          if ((ntohs((inseg . tcphdr)->_hdrlen_rsvd_flags) & 0x3fU) & 0x02U) {
            inseg.len -= 1;
          }
          pbuf_realloc(inseg.p, inseg.len);
          tcplen = ((&inseg)->len + (((ntohs(((&inseg)->tcphdr)->_hdrlen_rsvd_flags) & 0x3fU) & 0x01U || (ntohs(((&inseg)->tcphdr)->_hdrlen_rsvd_flags) & 0x3fU) & 0x02U)? 1: 0));
          ;

        }
#line 1119 "..\\lwIP\\src\\core\\tcp_in.c"

        pcb->rcv_nxt = seqno + tcplen;

         
        ;
        pcb->rcv_wnd -= tcplen;

        tcp_update_rcv_ann_wnd(pcb);

        







 
        if (inseg.p->tot_len > 0) {
          recv_data = inseg.p;
          

 
          inseg.p = 0;
        }
        if ((ntohs((inseg . tcphdr)->_hdrlen_rsvd_flags) & 0x3fU) & 0x01U) {
          do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_receive: received FIN.\n");} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
          recv_flags |= (u8_t)0x20U;
        }

#line 1188 "..\\lwIP\\src\\core\\tcp_in.c"


         
        do { if((pcb)->flags & ((u8_t)0x01U)) { (pcb)->flags &= ~((u8_t)0x01U); (pcb)->flags |= ((u8_t)0x02U); tcp_output(pcb); } else { (pcb)->flags |= ((u8_t)0x01U); } } while (0);

      } else {
         
        do { (pcb)->flags |= ((u8_t)0x02U); tcp_output(pcb); } while (0);
#line 1316 "..\\lwIP\\src\\core\\tcp_in.c"

      }
    } else {
      do { (pcb)->flags |= ((u8_t)0x02U); tcp_output(pcb); } while (0);
    }
  } else {
    
 
    
 
    if(!(((s32_t)((seqno)-(pcb->rcv_nxt)) >= 0) && ((s32_t)((seqno)-(pcb->rcv_nxt + pcb->rcv_wnd-1)) <= 0))){
      do { (pcb)->flags |= ((u8_t)0x02U); tcp_output(pcb); } while (0);
    }
  }
  return accepted_inseq;
}








 
static void
tcp_parseopt(struct tcp_pcb *pcb)
{
  u16_t c, max_c;
  u16_t mss;
  u8_t *opts, opt;




  opts = (u8_t *)tcphdr + 20;

   
  if((ntohs((tcphdr)->_hdrlen_rsvd_flags) >> 12) > 0x5) {
    max_c = ((ntohs((tcphdr)->_hdrlen_rsvd_flags) >> 12) - 5) << 2;
    for (c = 0; c < max_c; ) {
      opt = opts[c];
      switch (opt) {
      case 0x00:
         
        do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_parseopt: EOL\n");} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
        return;
      case 0x01:
         
        ++c;
        do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_parseopt: NOP\n");} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
        break;
      case 0x02:
        do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_parseopt: MSS\n");} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
        if (opts[c + 1] != 0x04 || c + 0x04 > max_c) {
           
          do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_parseopt: bad length\n");} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
          return;
        }
         
        mss = (opts[c + 2] << 8) | opts[c + 3];
         
        pcb->mss = ((mss > (1500 - 40)) || (mss == 0)) ? (1500 - 40) : mss;
         
        c += 0x04;
        break;
#line 1403 "..\\lwIP\\src\\core\\tcp_in.c"
      default:
        do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_parseopt: other\n");} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
        if (opts[c + 1] == 0) {
          do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("tcp_parseopt: bad length\n");} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
          
 
          return;
        }
        
 
        c += opts[c + 1];
      }
    }
  }
}

