#ifndef __CH376_H
#define __CH376_H

//#define  CH376_ReadWrite  SPI1_ReadWrite
//#define  CH376_Init   SPI1_Init
#define CH376_ReadWrite SPI1_ReadWrite

/* ���ӵ�USB����״̬���� */
#define	ERR_USB_UNKNOWN		0xFA				/* δ֪����,��Ӧ�÷��������,����Ӳ�����߳������ */
#define xEndCH376Cmd() GPIO_SetBits(GPIOA,GPIO_Pin_1);

u8 mInitCH376Host( void );
u8 mWaitInterrupt( void );
void xWriteCH376Cmd( u8 mCmd );
void xWriteCH376Data( u8 mData );
u8 xReadCH376Data( void );
u8 Query376Interrupt( void );
void mDelayuS(u8 us);
void mDelaymS(u8 ms);
void mDelay0_5uS( void );
EXT void SPI_CH376_Init(void);
#endif