#line 1 "..\\lwIP\\src\\core\\ipv4\\ip.c"






 































 

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





 


 



 


 



 


 



 


 



 


 






 








 




 







 






 






 






 






 






 






 






 






 






 






 






 






 






 






 






 






 






 






 







 






 






 






 






 






 






 






 






 






 






 






 






 






 






 




#line 42 "..\\lwIP\\src\\core\\ipv4\\ip.c"
#line 1 "..\\lwIP\\src\\include\\ipv4\\lwip/ip.h"






























 



#line 36 "..\\lwIP\\src\\include\\ipv4\\lwip/ip.h"

#line 1 "..\\lwIP\\src\\include\\lwip/def.h"






























 



 
#line 37 "..\\lwIP\\src\\include\\lwip/def.h"











#line 38 "..\\lwIP\\src\\include\\ipv4\\lwip/ip.h"
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













#line 43 "..\\lwIP\\src\\core\\ipv4\\ip.c"
#line 44 "..\\lwIP\\src\\core\\ipv4\\ip.c"
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














#line 45 "..\\lwIP\\src\\core\\ipv4\\ip.c"
#line 1 "..\\lwIP\\src\\include\\ipv4\\lwip/ip_frag.h"






























 




#line 37 "..\\lwIP\\src\\include\\ipv4\\lwip/ip_frag.h"
#line 38 "..\\lwIP\\src\\include\\ipv4\\lwip/ip_frag.h"
#line 39 "..\\lwIP\\src\\include\\ipv4\\lwip/ip_frag.h"
#line 40 "..\\lwIP\\src\\include\\ipv4\\lwip/ip_frag.h"
#line 41 "..\\lwIP\\src\\include\\ipv4\\lwip/ip_frag.h"
#line 42 "..\\lwIP\\src\\include\\ipv4\\lwip/ip_frag.h"






 




 
struct ip_reassdata {
  struct ip_reassdata *next;
  struct pbuf *p;
  struct ip_hdr iphdr;
  u16_t datagram_len;
  u8_t flags;
  u8_t timer;
};

void ip_reass_init(void);
void ip_reass_tmr(void);
struct pbuf * ip_reass(struct pbuf *p);



err_t ip_frag(struct pbuf *p, struct netif *netif, struct ip_addr *dest);






#line 46 "..\\lwIP\\src\\core\\ipv4\\ip.c"
#line 47 "..\\lwIP\\src\\core\\ipv4\\ip.c"
#line 1 "..\\lwIP\\src\\include\\ipv4\\lwip/inet_chksum.h"






























 



#line 36 "..\\lwIP\\src\\include\\ipv4\\lwip/inet_chksum.h"

#line 38 "..\\lwIP\\src\\include\\ipv4\\lwip/inet_chksum.h"
#line 39 "..\\lwIP\\src\\include\\ipv4\\lwip/inet_chksum.h"





u16_t inet_chksum(void *dataptr, u16_t len);
u16_t inet_chksum_pbuf(struct pbuf *p);
u16_t inet_chksum_pseudo(struct pbuf *p,
       struct ip_addr *src, struct ip_addr *dest,
       u8_t proto, u16_t proto_len);












#line 48 "..\\lwIP\\src\\core\\ipv4\\ip.c"
#line 49 "..\\lwIP\\src\\core\\ipv4\\ip.c"
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








 









#line 50 "..\\lwIP\\src\\core\\ipv4\\ip.c"
#line 1 "..\\lwIP\\src\\include\\ipv4\\lwip/igmp.h"
































 




#line 39 "..\\lwIP\\src\\include\\ipv4\\lwip/igmp.h"
#line 40 "..\\lwIP\\src\\include\\ipv4\\lwip/igmp.h"
#line 41 "..\\lwIP\\src\\include\\ipv4\\lwip/igmp.h"
#line 42 "..\\lwIP\\src\\include\\ipv4\\lwip/igmp.h"

#line 161 "..\\lwIP\\src\\include\\ipv4\\lwip/igmp.h"

#line 51 "..\\lwIP\\src\\core\\ipv4\\ip.c"
#line 1 "..\\lwIP\\src\\include\\lwip/raw.h"






























 



#line 36 "..\\lwIP\\src\\include\\lwip/raw.h"



#line 40 "..\\lwIP\\src\\include\\lwip/raw.h"
#line 41 "..\\lwIP\\src\\include\\lwip/raw.h"
#line 42 "..\\lwIP\\src\\include\\lwip/raw.h"
#line 43 "..\\lwIP\\src\\include\\lwip/raw.h"





struct raw_pcb {
 
  struct ip_addr local_ip; struct ip_addr remote_ip; u16_t so_options; u8_t tos; u8_t ttl ;

  struct raw_pcb *next;

  u8_t protocol;

  








 
  u8_t (* recv)(void *arg, struct raw_pcb *pcb, struct pbuf *p,
    struct ip_addr *addr);
   
  void *recv_arg;
};


 
struct raw_pcb * raw_new        (u8_t proto);
void             raw_remove     (struct raw_pcb *pcb);
err_t            raw_bind       (struct raw_pcb *pcb, struct ip_addr *ipaddr);
err_t            raw_connect    (struct raw_pcb *pcb, struct ip_addr *ipaddr);

void             raw_recv       (struct raw_pcb *pcb,
                                 u8_t (* recv)(void *arg, struct raw_pcb *pcb,
                                              struct pbuf *p,
                                              struct ip_addr *addr),
                                 void *recv_arg);
err_t            raw_sendto     (struct raw_pcb *pcb, struct pbuf *p, struct ip_addr *ipaddr);
err_t            raw_send       (struct raw_pcb *pcb, struct pbuf *p);

 
u8_t             raw_input      (struct pbuf *p, struct netif *inp);








#line 52 "..\\lwIP\\src\\core\\ipv4\\ip.c"
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















#line 53 "..\\lwIP\\src\\core\\ipv4\\ip.c"
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









#line 54 "..\\lwIP\\src\\core\\ipv4\\ip.c"
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







#line 55 "..\\lwIP\\src\\core\\ipv4\\ip.c"
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





















#line 56 "..\\lwIP\\src\\core\\ipv4\\ip.c"
#line 1 "..\\lwIP\\src\\include\\lwip/stats.h"






























 



#line 36 "..\\lwIP\\src\\include\\lwip/stats.h"

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





#line 57 "..\\lwIP\\src\\core\\ipv4\\ip.c"
#line 1 "..\\lwIP\\port\\include\\arch/perf.h"






























 






#line 58 "..\\lwIP\\src\\core\\ipv4\\ip.c"

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



 
#line 60 "..\\lwIP\\src\\core\\ipv4\\ip.c"




 
static struct netif *current_netif;



 
static const struct ip_hdr *current_header;








 
struct netif *
ip_current_netif(void)
{
  return current_netif;
}








 
const struct ip_hdr *
ip_current_header(void)
{
  return current_header;
}









 
struct netif *
ip_route(struct ip_addr *dest)
{
  struct netif *netif;

   
  for(netif = netif_list; netif != 0; netif = netif->next) {
     
    if (netif_is_up(netif)) {
      if ((((dest)->addr & (&(netif->netmask))->addr) == ((&(netif->ip_addr))->addr & (&(netif->netmask))->addr))) {
         
        return netif;
      }
    }
  }
  if ((netif_default == 0) || (!netif_is_up(netif_default))) {
    do { if ( ((0x00U | 2) & 0x80U) && ((0x00U | 2) & 0x80U) && ((s16_t)((0x00U | 2) & 0x03) >= 0x00)) { do {printf ("ip_route: No route to 0x%" "8lx" "\n", dest->addr);} while(0); if ((0x00U | 2) & 0x08U) { while(1); } } } while(0);
    ;
    ;
    return 0;
  }
   
  return netif_default;
}











 
static struct netif *
ip_forward(struct pbuf *p, struct ip_hdr *iphdr, struct netif *inp)
{
  struct netif *netif;

  ;
   
  netif = ip_route((struct ip_addr *)&(iphdr->dest));
  if (netif == 0) {
    do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("ip_forward: no forwarding route for 0x%" "8lx" " found\n", iphdr->dest . addr);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);

    ;
    return (struct netif *)0;
  }
  
 
  if (netif == inp) {
    do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("ip_forward: not bouncing packets back on incoming interface.\n");} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
    ;
    return (struct netif *)0;
  }

   
  (iphdr)->_ttl_proto = (htons((ntohs((iphdr)->_ttl_proto) & 0xff) | ((u16_t)((ntohs((iphdr)->_ttl_proto) >> 8) - 1) << 8)));
   
  if ((ntohs((iphdr)->_ttl_proto) >> 8) == 0) {
    ;

     
    if ((ntohs((iphdr)->_ttl_proto) & 0xff) != 1) {
      icmp_time_exceeded(p, ICMP_TE_TTL);
    }

    return (struct netif *)0;
  }

   
  if (((iphdr)->_chksum) >= htons(0xffff - 0x100)) {
    (iphdr)->_chksum = (((iphdr)->_chksum) + htons(0x100) + 1);
  } else {
    (iphdr)->_chksum = (((iphdr)->_chksum) + htons(0x100));
  }

  do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("ip_forward: forwarding packet to 0x%" "8lx" "\n", iphdr->dest . addr);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);


  ;
  ;
  ;

  ;
   
  netif->output(netif, p, (struct ip_addr *)&(iphdr->dest));
  return netif;
}















 
err_t
ip_input(struct pbuf *p, struct netif *inp)
{
  struct ip_hdr *iphdr;
  struct netif *netif;
  u16_t iphdr_hlen;
  u16_t iphdr_len;

  int check_ip_src=1;


  ;
  ;

   
  iphdr = p->payload;
  if ((ntohs((iphdr)->_v_hl_tos) >> 12) != 4) {
    do { if ( ((0x00U | 1) & 0x80U) && ((0x00U | 1) & 0x80U) && ((s16_t)((0x00U | 1) & 0x03) >= 0x00)) { do {printf ("IP packet dropped due to bad version number %" "4d" "\n", (ntohs((iphdr)->_v_hl_tos) >> 12));} while(0); if ((0x00U | 1) & 0x08U) { while(1); } } } while(0);
    ;
    pbuf_free(p);
    ;
    ;
    ;
    return 0;
  }

   
  iphdr_hlen = ((ntohs((iphdr)->_v_hl_tos) >> 8) & 0x0f);
   
  iphdr_hlen *= 4;
   
  iphdr_len = ntohs(((iphdr)->_len));

   
  if ((iphdr_hlen > p->len) || (iphdr_len > p->tot_len)) {
    if (iphdr_hlen > p->len)
    do { if ( ((0x00U | 2) & 0x80U) && ((0x00U | 2) & 0x80U) && ((s16_t)((0x00U | 2) & 0x03) >= 0x00)) { do {printf ("IP header (len %" "4d" ") does not fit in first pbuf (len %" "4d" "), IP packet dropped.\n", iphdr_hlen, p->len);} while(0); if ((0x00U | 2) & 0x08U) { while(1); } } } while(0);

    if (iphdr_len > p->tot_len)
    do { if ( ((0x00U | 2) & 0x80U) && ((0x00U | 2) & 0x80U) && ((s16_t)((0x00U | 2) & 0x03) >= 0x00)) { do {printf ("IP (len %" "4d" ") is longer than pbuf (len %" "4d" "), " "IP packet dropped.\n", iphdr_len, p->tot_len);} while(0); if ((0x00U | 2) & 0x08U) { while(1); } } } while(0);


     
    pbuf_free(p);
    ;
    ;
    ;
    return 0;
  }

   

  if (inet_chksum(iphdr, iphdr_hlen) != 0) {

    do { if ( ((0x00U | 2) & 0x80U) && ((0x00U | 2) & 0x80U) && ((s16_t)((0x00U | 2) & 0x03) >= 0x00)) { do {printf ("Checksum (0x%" "4x" ") failed, IP packet dropped.\n", inet_chksum(iphdr, iphdr_hlen));} while(0); if ((0x00U | 2) & 0x08U) { while(1); } } } while(0);
    ;
    pbuf_free(p);
    ;
    ;
    ;
    return 0;
  }


  
 
  pbuf_realloc(p, iphdr_len);

   
#line 294 "..\\lwIP\\src\\core\\ipv4\\ip.c"
  {
    

 
    int first = 1;
    netif = inp;
    do {
      do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("ip_input: iphdr->dest 0x%" "8lx" " netif->ip_addr 0x%" "8lx" " (0x%" "8lx" ", 0x%" "8lx" ", 0x%" "8lx" ")\n", iphdr->dest . addr, netif->ip_addr . addr, iphdr->dest . addr & netif->netmask . addr, netif->ip_addr . addr & netif->netmask . addr, iphdr->dest . addr & ~(netif->netmask . addr));} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);





       
      if ((netif_is_up(netif)) && (!((&(netif->ip_addr)) == 0 || (&(netif->ip_addr))->addr == 0))) {
         
        if (((&(iphdr->dest))->addr == (&(netif->ip_addr))->addr) ||
             
            ip_addr_isbroadcast(&(iphdr->dest), netif)) {
          do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("ip_input: packet accepted on interface %c%c\n", netif->name[0], netif->name[1]);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);

           
          break;
        }
      }
      if (first) {
        first = 0;
        netif = netif_list;
      } else {
        netif = netif->next;
      }
      if (netif == inp) {
        netif = netif->next;
      }
    } while(netif != 0);
  }


  


 
  
     
    if ((ntohs((iphdr)->_ttl_proto) & 0xff) == 17) {
      do { if ( ((0x00U | 0x40U | 1) & 0x80U) && ((0x00U | 0x40U | 1) & 0x80U) && ((s16_t)((0x00U | 0x40U | 1) & 0x03) >= 0x00)) { do {printf ("ip_input: UDP packet to DHCP client port %" "4d" "\n", ntohs(((struct udp_hdr *)((u8_t *)iphdr + iphdr_hlen))->dest));} while(0); if ((0x00U | 0x40U | 1) & 0x08U) { while(1); } } } while(0);

      if ((ntohs(((struct udp_hdr *)((u8_t *)iphdr + iphdr_hlen))->dest) == 68)||
	  	(ntohs(((struct udp_hdr *)((u8_t *)iphdr + iphdr_hlen))->dest) == 67)){
        do { if ( ((0x00U | 0x40U | 1) & 0x80U) && ((0x00U | 0x40U | 1) & 0x80U) && ((s16_t)((0x00U | 0x40U | 1) & 0x03) >= 0x00)) { do {printf ("ip_input: DHCP packet accepted.\n");} while(0); if ((0x00U | 0x40U | 1) & 0x08U) { while(1); } } } while(0);
        netif = inp;
        check_ip_src = 0;
      }
    }
 


   

  if (check_ip_src)

  {  if ((ip_addr_isbroadcast(&(iphdr->src), inp)) ||
         ((((&(iphdr->src))->addr & ntohl(0xf0000000UL)) == ntohl(0xe0000000UL)))) {
       
      do { if ( ((0x00U | 0x40U | 1) & 0x80U) && ((0x00U | 0x40U | 1) & 0x80U) && ((s16_t)((0x00U | 0x40U | 1) & 0x03) >= 0x00)) { do {printf ("ip_input: packet source is not valid.\n");} while(0); if ((0x00U | 0x40U | 1) & 0x08U) { while(1); } } } while(0);
       
      pbuf_free(p);
      ;
      ;
      ;
      return 0;
    }
  }

   
  if (netif == 0) {
     
    do { if ( ((0x00U | 0x40U | 1) & 0x80U) && ((0x00U | 0x40U | 1) & 0x80U) && ((s16_t)((0x00U | 0x40U | 1) & 0x03) >= 0x00)) { do {printf ("ip_input: packet not for us.\n");} while(0); if ((0x00U | 0x40U | 1) & 0x08U) { while(1); } } } while(0);

     
    if (!ip_addr_isbroadcast(&(iphdr->dest), inp)) {
       
      ip_forward(p, iphdr, inp);
    } else

    {
      ;
      ;
    }
    pbuf_free(p);
    return 0;
  }
   
  if ((((iphdr)->_offset) & htons(0x1fff | 0x2000)) != 0) {

    do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("IP packet is a fragment (id=0x%04" "4x" " tot_len=%" "4d" " len=%" "4d" " MF=%" "4d" " offset=%" "4d" "), calling ip_reass()\n", ntohs(((iphdr)->_id)), p->tot_len, ntohs(((iphdr)->_len)), ! !(((iphdr)->_offset) & htons(0x2000)), (ntohs(((iphdr)->_offset)) & 0x1fff)*8);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);

     
    p = ip_reass(p);
     
    if (p == 0) {
      return 0;
    }
    iphdr = p->payload;
#line 408 "..\\lwIP\\src\\core\\ipv4\\ip.c"
  }

#line 427 "..\\lwIP\\src\\core\\ipv4\\ip.c"

   
  do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("ip_input: \n");} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
  ;
  do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("ip_input: p->len %" "4d" " p->tot_len %" "4d" "\n", p->len, p->tot_len);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);

  current_netif = inp;
  current_header = iphdr;


   
  if (raw_input(p, inp) == 0)

  {

    switch ((ntohs((iphdr)->_ttl_proto) & 0xff)) {

    case 17:



      ;
      udp_input(p, inp);
      break;


    case 6:
      ;
      tcp_input(p, inp);
      break;


    case 1:
      ;
      icmp_input(p, inp);
      break;
#line 469 "..\\lwIP\\src\\core\\ipv4\\ip.c"
    default:

       
      if (!ip_addr_isbroadcast(&(iphdr->dest), inp) &&
          !(((&(iphdr->dest))->addr & ntohl(0xf0000000UL)) == ntohl(0xe0000000UL))) {
        p->payload = iphdr;
        icmp_dest_unreach(p, ICMP_DUR_PROTO);
      }

      pbuf_free(p);

      do { if ( ((0x00U | 2) & 0x80U) && ((0x00U | 2) & 0x80U) && ((s16_t)((0x00U | 2) & 0x03) >= 0x00)) { do {printf ("Unsupported transport protocol %" "4d" "\n", (ntohs((iphdr)->_ttl_proto) & 0xff));} while(0); if ((0x00U | 2) & 0x08U) { while(1); } } } while(0);

      ;
      ;
      ;
    }
  }

  current_netif = 0;
  current_header = 0;

  return 0;
}

























 
err_t
ip_output_if(struct pbuf *p, struct ip_addr *src, struct ip_addr *dest,
             u8_t ttl, u8_t tos,
             u8_t proto, struct netif *netif)
{
#line 539 "..\\lwIP\\src\\core\\ipv4\\ip.c"
  struct ip_hdr *iphdr;
  static u16_t ip_id = 0;

  ;

   
  if (dest != 0) {
    u16_t ip_hlen = 20;
#line 567 "..\\lwIP\\src\\core\\ipv4\\ip.c"
     
    if (pbuf_header(p, 20)) {
      do { if ( ((0x00U | 2) & 0x80U) && ((0x00U | 2) & 0x80U) && ((s16_t)((0x00U | 2) & 0x03) >= 0x00)) { do {printf ("ip_output: not enough room for IP header in pbuf\n");} while(0); if ((0x00U | 2) & 0x08U) { while(1); } } } while(0);

      ;
      ;
      return -2;
    }

    iphdr = p->payload;
    ;


    (iphdr)->_ttl_proto = (htons((ntohs((iphdr)->_ttl_proto) & 0xff) | ((u16_t)(ttl) << 8)));
    (iphdr)->_ttl_proto = (htons((proto) | ((ntohs((iphdr)->_ttl_proto) >> 8) << 8)));

    (&(iphdr->dest))->addr = ((dest) == 0? 0: (dest)->addr);

    (iphdr)->_v_hl_tos = (htons(((4) << 12) | ((ip_hlen / 4) << 8) | (tos)));
    (iphdr)->_len = (htons(p->tot_len));
    (iphdr)->_offset = (0);
    (iphdr)->_id = (htons(ip_id));
    ++ip_id;

    if (((src) == 0 || (src)->addr == 0)) {
      (&(iphdr->src))->addr = ((&(netif->ip_addr)) == 0? 0: (&(netif->ip_addr))->addr);
    } else {
      (&(iphdr->src))->addr = ((src) == 0? 0: (src)->addr);
    }

    (iphdr)->_chksum = (0);

    (iphdr)->_chksum = (inet_chksum(iphdr, ip_hlen));

  } else {
     
    iphdr = p->payload;
    dest = &(iphdr->dest);
  }


   
  if (netif->mtu && (p->tot_len > netif->mtu))
    return ip_frag(p,netif,dest);


  ;

  do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("ip_output_if: %c%c%" "4d" "\n", netif->name[0], netif->name[1], netif->num);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
  ;

#line 626 "..\\lwIP\\src\\core\\ipv4\\ip.c"
  {
    do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("netif->output()");} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);

    return netif->output(netif, p, dest);
  }
}

















 
err_t
ip_output(struct pbuf *p, struct ip_addr *src, struct ip_addr *dest,
          u8_t ttl, u8_t tos, u8_t proto)
{
  struct netif *netif;

  if ((netif = ip_route(dest)) == 0) {
    do { if ( ((0x00U) & 0x80U) && ((0x00U) & 0x80U) && ((s16_t)((0x00U) & 0x03) >= 0x00)) { do {printf ("ip_output: No route to 0x%" "8lx" "\n", dest->addr);} while(0); if ((0x00U) & 0x08U) { while(1); } } } while(0);
    ;
    return -4;
  }

  return ip_output_if(p, src, dest, ttl, tos, proto, netif);
}

#line 704 "..\\lwIP\\src\\core\\ipv4\\ip.c"

