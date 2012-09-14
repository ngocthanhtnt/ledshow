/***************************************************************************
 *    www.braintechnology.de                                               *
 *    Advairtizer V1.0                                                     *
 *                                                                         *
 *    (c) Copyright Braintechnology 2007                                   *
 *    File name   : sw_main.c                                              *
 *    Description : Demo Software for Advairtizer Development Modules      *
 *    History     :                                                        *
 *    Date        : Oktober, 2007                                          *
 *    Author      : Kai Klein                                              *
 *    $Revision: 1.0 $                                                     *
 ***************************************************************************/

#include "enc28j60.h"
#include <net_config.h>

u8 Enc28j60Bank;
u16 NextPacketPtr;
u8  ENCRevID;


#define setb_CS_ETHERNET() GPIO_SetBits(GPIOA,GPIO_Pin_4)
#define clrb_CS_ETHERNET() GPIO_ResetBits(GPIOA,GPIO_Pin_4)



void init_ethernet (void) 
{
    enc28j60Init();      
}

void poll_ethernet (void) 
{
    enc28j60PacketReceive();    
}

void send_frame (OS_FRAME *frame)
{
    enc28j60PacketSend(frame->length, frame->data);    
}



u16 dev_poll(void)
{
//	return enc28j60PacketReceive(UIP_BUFSIZE, uip_buf);
    return 0;
}

void dev_send(void)
{
//	enc28j60PacketSend(uip_len, uip_buf);
    return;
}

void nicGetMacAddress(u8 *macaddr)
{
    // read MAC address registers
	// NOTE: MAC address in ENC28J60 is byte-backward
    *macaddr++ = enc28j60Read(MAADR5);
    *macaddr++ = enc28j60Read(MAADR4);
    *macaddr++ = enc28j60Read(MAADR3);
    *macaddr++ = enc28j60Read(MAADR2);
    *macaddr++ = enc28j60Read(MAADR1);
    *macaddr++ = enc28j60Read(MAADR0);
}

void nicSetMacAddress(const u8 *macaddr)
{
	// write MAC address
	// NOTE: MAC address in ENC28J60 is byte-backward
	enc28j60Write(MAADR5, *macaddr++);
	enc28j60Write(MAADR4, *macaddr++);
	enc28j60Write(MAADR3, *macaddr++);
	enc28j60Write(MAADR2, *macaddr++);
	enc28j60Write(MAADR1, *macaddr++);
	enc28j60Write(MAADR0, *macaddr++);
}

u8 SPI_SendByte(u8 byte)
{
    while(SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_BSY) != RESET);
    SPI_I2S_SendData(SPI1,byte);

    while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE) == RESET);
    return SPI_I2S_ReceiveData(SPI1);
}

__inline u8 SPI_ReadByte(void)
{
  return (SPI_SendByte(0xA5));
}

u8 enc28j60ReadOp(u8 op, u8 address)
{

    u8 data;
    // assert CS
    clrb_CS_ETHERNET();

    data = op | (address & ADDR_MASK);

    SPI_SendByte(data);

    data = SPI_ReadByte();

    // do dummy read if needed
	if(address & 0x80)
		data = SPI_ReadByte();
    
    setb_CS_ETHERNET(); //CS auf High
	return data;
}

void enc28j60WriteOp(u8 op, u8 address, u8 data)
{
    u16 senddata;

    // assert CS
    clrb_CS_ETHERNET();
    
    senddata= op | (address & ADDR_MASK);
    SPI_SendByte(senddata);

    SPI_SendByte(data);

    // release CS
    setb_CS_ETHERNET(); //CS auf High
}

void enc28j60ReadBuffer(u16 len, u8 *data)
{
	// assert CS
    clrb_CS_ETHERNET();
//   	pause(ONE_US*100);
	// issue read command
    SPI_SendByte(ENC28J60_READ_BUF_MEM);

	while(len--)
	{
        *data++ = SPI_ReadByte();
	}	
	// release CS
	setb_CS_ETHERNET();
}

void enc28j60WriteBuffer(u16 len, u8* data)
{
	// assert CS
	clrb_CS_ETHERNET(); //CS auf Low
//   	pause(ONE_US*100);
	// issue write command
    SPI_SendByte(ENC28J60_WRITE_BUF_MEM);

	while(len--)
	{
		// write data
        SPI_SendByte(*data++);
	}	
	// release CS
	setb_CS_ETHERNET();
}

void enc28j60SetBank(u8 address)
{
	// set the bank (if needed)
	if((address & BANK_MASK) != Enc28j60Bank)
	{
		// set the bank
		enc28j60WriteOp(ENC28J60_BIT_FIELD_CLR, ECON1, (ECON1_BSEL1|ECON1_BSEL0));
		enc28j60WriteOp(ENC28J60_BIT_FIELD_SET, ECON1, (address & BANK_MASK)>>5);
		Enc28j60Bank = (address & BANK_MASK);
	}
}

u8 enc28j60Read(u8 address)
{
	// set the bank
	enc28j60SetBank(address);
	// do the read
	return enc28j60ReadOp(ENC28J60_READ_CTRL_REG, address);
}

void enc28j60Write(u8 address, u8 data)
{
	// set the bank
	enc28j60SetBank(address);
	// do the write
	enc28j60WriteOp(ENC28J60_WRITE_CTRL_REG, address, data);
}

void enc28j60PhyWrite(u8 address, u16 data)
{
	// set the PHY register address
	enc28j60Write(MIREGADR, address);
	
	// write the PHY data
	enc28j60Write(MIWRL, data);	
	enc28j60Write(MIWRH, data>>8);

	// wait until the PHY write completes
	while(enc28j60Read(MISTAT) & MISTAT_BUSY);
}

void spi2_init(void)
{
	// SPI init

    SPI_InitTypeDef   SPI_InitStructure;
    GPIO_InitTypeDef GPIO_InitStructure;

    //Enable Clock
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);  
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); 
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);
    
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 ;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    //Reset
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOB, &GPIO_InitStructure); 
    GPIO_SetBits(GPIOB, GPIO_Pin_10);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11  ;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
    SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
    SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
    SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;
    SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;
    SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
    SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_8;
    SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
    SPI_InitStructure.SPI_CRCPolynomial = 7;
    SPI_Init(SPI1, &SPI_InitStructure);
    
    SPI_Cmd(SPI1, ENABLE); 
}
u8 testmac[6];
void enc28j60Init(void)
{
    u32 timeout;
    
    //EXTI_InitTypeDef EXTI_InitStructure;
    //NVIC_InitTypeDef NVIC_InitStructure;

    const u8 mymac[6] = {0x1e,0x30,0x6c,0xa2,0x45,0x5e};
         
    spi2_init();
/*
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

    // interrupt 
    NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQChannel;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    //Set EXIT FOR CONVENT    
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource11);
    
    // Configure Key Button EXTI Line to generate an interrupt on falling edge   
    EXTI_InitStructure.EXTI_Line = EXTI_Line11;
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    EXTI_Init(&EXTI_InitStructure);        
*/

//    do{
    timeout = 100000;
    // perform system reset
    enc28j60WriteOp(ENC28J60_SOFT_RESET, 0, ENC28J60_SOFT_RESET);
    while(timeout--);

    // check CLKRDY bit to see if reset is complete
	// Errata workaround #2, CLKRDY check is unreliable, delay 1 mS instead
    while(!(enc28j60Read(ESTAT) & ESTAT_CLKRDY))
    {
        timeout++;
        if (timeout > 100000)
        //debug_printf("enc28j60Read timeout");
        break;
    };



	// do bank 0 stuff
	// initialize receive buffer
	// 16-bit transfers, must write low byte first
	// set receive buffer start address
	NextPacketPtr = RXSTART_INIT;
    // Rx start
	enc28j60Write(ERXSTL, RXSTART_INIT&0xFF);
	enc28j60Write(ERXSTH, RXSTART_INIT>>8);
	// set receive pointer address
	enc28j60Write(ERXRDPTL, RXSTART_INIT&0xFF);
	enc28j60Write(ERXRDPTH, RXSTART_INIT>>8);
	// RX end
	enc28j60Write(ERXNDL, RXSTOP_INIT&0xFF);
	enc28j60Write(ERXNDH, RXSTOP_INIT>>8);
	// TX start
	enc28j60Write(ETXSTL, TXSTART_INIT&0xFF);
	enc28j60Write(ETXSTH, TXSTART_INIT>>8);
	// TX end
	enc28j60Write(ETXNDL, TXSTOP_INIT&0xFF);
	enc28j60Write(ETXNDH, TXSTOP_INIT>>8);
	// do bank 1 stuff, packet filter:
        // For broadcast packets we allow only ARP packtets
        // All other packets should be unicast only for our mac (MAADR)
        //
        // The pattern to match on is therefore
        // Type     ETH.DST
        // ARP      BROADCAST
        // 06 08 -- ff ff ff ff ff ff -> ip checksum for theses bytes=f7f9
        // in binary these poitions are:11 0000 0011 1111
        // This is hex 303F->EPMM0=0x3f,EPMM1=0x30
	enc28j60Write(ERXFCON, ERXFCON_UCEN|ERXFCON_CRCEN|ERXFCON_PMEN);
	enc28j60Write(EPMM0, 0x3f);
	enc28j60Write(EPMM1, 0x30);
	enc28j60Write(EPMCSL, 0xf9);
	enc28j60Write(EPMCSH, 0xf7);
        //
        //
	// do bank 2 stuff
	// enable MAC receive
	enc28j60Write(MACON1, MACON1_MARXEN|MACON1_TXPAUS|MACON1_RXPAUS);
	// bring MAC out of reset
	//enc28j60Write(MACON2, 0x00); 

    // enable automatic padding to 60bytes and CRC operations
	enc28j60WriteOp(ENC28J60_BIT_FIELD_SET, MACON3, MACON3_PADCFG0|MACON3_TXCRCEN|MACON3_FRMLNEN);
	// set inter-frame gap (back-to-back)
	enc28j60Write(MABBIPG, 0x12);

    // Allow infinite deferals if the medium is continuously busy 
    // (do not time out a transmission if the half duplex medium is 
    // completely saturated with other people's data)
    enc28j60Write(MACON4, MACON4_DEFER);

    // Late collisions occur beyond 63+8 bytes (8 bytes for preamble/start of frame delimiter)
	// 55 is all that is needed for IEEE 802.3, but ENC28J60 B5 errata for improper link pulse 
	// collisions will occur less often with a larger number.
    enc28j60Write(MACLCON2, 63);

    // set inter-frame gap (non-back-to-back)
	enc28j60Write(MAIPGL, 0x12);
	enc28j60Write(MAIPGH, 0x0C);

	// Set the maximum packet size which the controller will accept
        // Do not send packets longer than MAX_FRAMELEN:
	enc28j60Write(MAMXFLL, MAX_FRAMELEN&0xFF);	
	enc28j60Write(MAMXFLH, MAX_FRAMELEN>>8);
    	
    // do bank 3 stuff
    nicSetMacAddress(mymac);

   enc28j60Write(ECOCON, 0x00);	// Output off (0V)

   ENCRevID = enc28j60Read(EREVID);
	
	// no loopback of transmitted frames
	enc28j60PhyWrite(PHCON2, PHCON2_HDLDIS);
	// switch to bank 0
	enc28j60SetBank(ECON1);
	// enable interrutps
	enc28j60WriteOp(ENC28J60_BIT_FIELD_SET, EIE, EIE_INTIE|EIE_PKTIE);
	// enable packet reception
	enc28j60WriteOp(ENC28J60_BIT_FIELD_SET, ECON1, ECON1_RXEN);
}
/************************************************
 * enc28j60 Powersave Mode
 * mode 1 = powerdown
 * mode 0 = wakeup
 * usage:
 * bool result enc28j60_powersave(1);
 ************************************************/
bool enc28j60_powersave(u8 mode)
{
    bool result = FALSE;
    u32 timeout = 0;
    switch(mode)
    {
        case 1:
            enc28j60WriteOp(ENC28J60_BIT_FIELD_CLR, ECON1, ECON1_RXEN);              
            while(!(enc28j60Read(ESTAT) & ESTAT_RXBUSY))
            {//Wait for any in-progress packets to finish being received by polling
                timeout++;
                if (timeout > 100000)
                    break;
            };
            timeout = 0;
            while(!(enc28j60Read(ECON1) & ECON1_TXRTS))
            {//Wait for any current transmissions to end by confirming
                timeout++;
                if (timeout > 100000)
                    break;
            };
            enc28j60WriteOp(ENC28J60_BIT_FIELD_SET, ECON2, ECON2_VRPS);
            enc28j60WriteOp(ENC28J60_BIT_FIELD_SET, ECON2, ECON2_PWRSV);//Enter Sleep
            result = FALSE;
        break;
        case 0:
            enc28j60WriteOp(ENC28J60_BIT_FIELD_CLR, ECON2, ECON2_PWRSV);//Enter Sleep
            timeout = 0;
            while(!(enc28j60Read(ESTAT) & ESTAT_CLKRDY))
            {//Wait for PHY to stabilize (wait 300us)
                timeout++;
                if (timeout > 100000)
                    break;
            };
            enc28j60WriteOp(ENC28J60_BIT_FIELD_SET, ECON1, ECON1_RXEN);
            //set maybee 12.1.5 Link Change Interrupt Flag (LINKIF)
            result = TRUE;
        break;
    }
    return result;
}


void EXTI15_10_IRQHandler(void)
{
    if(EXTI_GetITStatus(EXTI_Line11) != RESET)
    {
        
        //uip_len = dev_poll();	// look for a packet
        //if(uip_len != 0)

        /* Clear the Key Button EXTI line pending bit */
        EXTI_ClearITPendingBit(EXTI_Line11);
    }
}

void enc28j60PacketSend(u16 len, u8 *packet)
{
    // Set the write pointer to start of transmit buffer area
	enc28j60Write(EWRPTL, (TXSTART_INIT)&0xFF);
	enc28j60Write(EWRPTH, (TXSTART_INIT)>>8);
	// Set the TXND pointer to correspond to the packet size given
	enc28j60Write(ETXNDL, (TXSTART_INIT+len)&0xFF);
	enc28j60Write(ETXNDH, (TXSTART_INIT+len)>>8);
	// write per-packet control byte (0x00 means use macon3 settings)
	enc28j60WriteOp(ENC28J60_WRITE_BUF_MEM, 0, 0x00);
	// copy the packet into the transmit buffer
	enc28j60WriteBuffer(len, packet);
	// send the contents of the transmit buffer onto the network
	enc28j60WriteOp(ENC28J60_BIT_FIELD_SET, ECON1, ECON1_TXRTS);

    if(ENCRevID == 0x05u || ENCRevID == 0x06u)
	{
		u16 AttemptCounter = 0x0000;
		while((enc28j60Read(EIR) & (EIR_TXERIF | EIR_TXIF)) && (++AttemptCounter < 1000));
		if((enc28j60Read(EIR) & EIR_TXERIF) || (AttemptCounter >= 1000))
		{
			WORD_VAL ReadPtrSave;
			WORD_VAL TXEnd;
			TXSTATUS TXStatus;
			u8 i;

			// Cancel the previous transmission if it has become stuck set
			//BFCReg(ECON1, ECON1_TXRTS);
            enc28j60WriteOp(ENC28J60_BIT_FIELD_CLR, ECON1, ECON1_TXRTS);

			// Save the current read pointer (controlled by application)
			ReadPtrSave.v[0] = enc28j60Read(ERDPTL);
			ReadPtrSave.v[1] = enc28j60Read(ERDPTH);

			// Get the location of the transmit status vector
			TXEnd.v[0] = enc28j60Read(ETXNDL);
			TXEnd.v[1] = enc28j60Read(ETXNDH);
			TXEnd.Val++;
			
			// Read the transmit status vector
			enc28j60Write(ERDPTL, TXEnd.v[0]);
			enc28j60Write(ERDPTH, TXEnd.v[1]);

			enc28j60ReadBuffer(sizeof(TXStatus) ,(u8*)&TXStatus);

			// Implement retransmission if a late collision occured (this can 
			// happen on B5 when certain link pulses arrive at the same time 
			// as the transmission)
			for(i = 0; i < 16u; i++)
			{
				if((enc28j60Read(EIR) & EIR_TXERIF) && TXStatus.bits.LateCollision)
				{
					// Reset the TX logic
                    enc28j60WriteOp(ENC28J60_BIT_FIELD_SET, ECON1, ECON1_TXRTS);
                    enc28j60WriteOp(ENC28J60_BIT_FIELD_CLR, ECON1, ECON1_TXRTS);
                    enc28j60WriteOp(ENC28J60_BIT_FIELD_CLR, EIR, EIR_TXERIF | EIR_TXIF);

					// Transmit the packet again
					enc28j60WriteOp(ENC28J60_BIT_FIELD_SET, ECON1, ECON1_TXRTS);
					while(!(enc28j60Read(EIR) & (EIR_TXERIF | EIR_TXIF)));

					// Cancel the previous transmission if it has become stuck set
					enc28j60WriteOp(ENC28J60_BIT_FIELD_CLR, ECON1, ECON1_TXRTS);

					// Read transmit status vector
					enc28j60Write(ERDPTL, TXEnd.v[0]);
					enc28j60Write(ERDPTH, TXEnd.v[1]);
                    enc28j60ReadBuffer(sizeof(TXStatus) ,(u8*)&TXStatus);
				}
				else
				{
					break;
				}
			}

			// Restore the current read pointer
			enc28j60Write(ERDPTL, ReadPtrSave.v[0]);
			enc28j60Write(ERDPTH, ReadPtrSave.v[1]);
		}
	}
    // Reset the transmit logic problem. See Rev. B4 Silicon Errata point 12.
	if( (enc28j60Read(EIR) & EIR_TXERIF) )
    {
        enc28j60WriteOp(ENC28J60_BIT_FIELD_CLR, ECON1, ECON1_TXRTS);
    }
}

void enc28j60PacketReceive()
{
	u16 rxstat;
	u16 len;
    u16 rs,re;
    OS_FRAME *frame;

	// check if a packet has been received and buffered

	if( enc28j60Read(EPKTCNT) ==0 )
    {
//		return(0);
        return;
    }

	enc28j60Write(ERDPTL, (NextPacketPtr));
	enc28j60Write(ERDPTH, (NextPacketPtr)>>8);
	// read the next packet pointer
	NextPacketPtr  = enc28j60ReadOp(ENC28J60_READ_BUF_MEM, 0);
	NextPacketPtr |= enc28j60ReadOp(ENC28J60_READ_BUF_MEM, 0)<<8;
	// read the packet length
	len  = enc28j60ReadOp(ENC28J60_READ_BUF_MEM, 0);
	len |= enc28j60ReadOp(ENC28J60_READ_BUF_MEM, 0)<<8;
    len-=4; //remove the CRC count

	// read the receive status
	rxstat  = enc28j60ReadOp(ENC28J60_READ_BUF_MEM, 0);
	rxstat |= enc28j60ReadOp(ENC28J60_READ_BUF_MEM, 0)<<8;

	// copy the packet from the receive buffer
    frame =  alloc_mem (len);  

	enc28j60ReadBuffer(len, frame->data);
                
    rs = enc28j60Read(ERXSTH);
    rs <<= 8;
    rs |= enc28j60Read(ERXSTL);
    re = enc28j60Read(ERXNDH);
    re <<= 8;
    re |= enc28j60Read(ERXNDL);
    if (NextPacketPtr - 1 < rs || NextPacketPtr - 1 > re)
    {
        enc28j60Write(ERXRDPTL, (re));
        enc28j60Write(ERXRDPTH, (re)>>8);
    }
    else
    {
        enc28j60Write(ERXRDPTL, (NextPacketPtr-1));
        enc28j60Write(ERXRDPTH, (NextPacketPtr-1)>>8);
    }

	// decrement the packet counter indicate we are done with this packet
	// clear the PKTIF: Receive Packet Pending Interrupt Flag bit
    enc28j60WriteOp(ENC28J60_BIT_FIELD_SET, ECON2, ECON2_PKTDEC);

    put_in_queue (frame);

//    return len;
}

/*
void enc28j60RegDump(void)
{   			
	debug_printf("RevID: 0x%x\n", enc28j60Read(EREVID));

	debug_printf( ("Cntrl: ECON1 ECON2 ESTAT  EIR  EIE\n"));
	debug_printf( ("         "));
	debug_printf("%02x",enc28j60Read(ECON1));
	debug_printf( ("    "));
	debug_printf("%02x",enc28j60Read(ECON2));
	debug_printf( ("    "));
	debug_printf("%02x",enc28j60Read(ESTAT));
	debug_printf( ("    "));
	debug_printf("%02x",enc28j60Read(EIR));
	debug_printf( ("   "));
	debug_printf("%02x",enc28j60Read(EIE));
	debug_printf( ("\n"));

	debug_printf( ("MAC  : MACON1  MACON2  MACON3  MACON4  MAC-Address\n"));
	debug_printf( ("        0x"));
	debug_printf("%02x",enc28j60Read(MACON1));
	debug_printf( ("    0x"));
	debug_printf("%02x",enc28j60Read(MACON2));
	debug_printf( ("    0x"));
	debug_printf("%02x",enc28j60Read(MACON3));
	debug_printf( ("    0x"));
	debug_printf("%02x",enc28j60Read(MACON4));
	debug_printf( ("   "));
	debug_printf("%02x",enc28j60Read(MAADR5));
	debug_printf("%02x",enc28j60Read(MAADR4));
	debug_printf("%02x",enc28j60Read(MAADR3));
	debug_printf("%02x",enc28j60Read(MAADR2));
	debug_printf("%02x",enc28j60Read(MAADR1));
	debug_printf("%02x",enc28j60Read(MAADR0));
	debug_printf( ("\n"));

	debug_printf( ("Rx   : ERXST  ERXND  ERXWRPT ERXRDPT ERXFCON EPKTCNT MAMXFL\n"));
	debug_printf( ("       0x"));
	debug_printf("%02x",enc28j60Read(ERXSTH));
	debug_printf("%02x",enc28j60Read(ERXSTL));
	debug_printf( (" 0x"));
	debug_printf("%02x",enc28j60Read(ERXNDH));
	debug_printf("%02x",enc28j60Read(ERXNDL));
	debug_printf( ("  0x"));
	debug_printf("%02x",enc28j60Read(ERXWRPTH));
	debug_printf("%02x",enc28j60Read(ERXWRPTL));
	debug_printf( ("  0x"));
	debug_printf("%02x",enc28j60Read(ERXRDPTH));
	debug_printf("%02x",enc28j60Read(ERXRDPTL));
	debug_printf( ("   0x"));
	debug_printf("%02x",enc28j60Read(ERXFCON));
	debug_printf( ("    0x"));
	debug_printf("%02x",enc28j60Read(EPKTCNT));
	debug_printf( ("  0x"));
	debug_printf("%02x",enc28j60Read(MAMXFLH));
	debug_printf("%02x",enc28j60Read(MAMXFLL));
	debug_printf( ("\n"));

	debug_printf( ("Tx   : ETXST  ETXND  MACLCON1 MACLCON2 MAPHSUP\n"));
	debug_printf( ("       0x"));
	debug_printf("%02x",enc28j60Read(ETXSTH));
	debug_printf("%02x",enc28j60Read(ETXSTL));
	debug_printf( (" 0x"));
	debug_printf("%02x",enc28j60Read(ETXNDH));
	debug_printf("%02x",enc28j60Read(ETXNDL));
	debug_printf( ("   0x"));
	debug_printf("%02x",enc28j60Read(MACLCON1));
	debug_printf( ("     0x"));
	debug_printf("%02x",enc28j60Read(MACLCON2));
	debug_printf( ("     0x"));
	debug_printf("%02x",enc28j60Read(MAPHSUP));
	debug_printf( ("\n"));
	debug_printf( ("PHY   : PHCON1  PHCON2  PHSTAT1 PHSTAT2\n"));
	debug_printf( ("       0x"));
	debug_printf("%02x",enc28j60Read(PHCON1));//ist 16 bit breit nicht 8 !
	debug_printf( ("     0x"));
    debug_printf("%02x",enc28j60Read(PHCON2));//ist 16 bit breit nicht 8 !
    debug_printf( ("     0x"));
    debug_printf("%02x",enc28j60Read(PHSTAT1));//ist 16 bit breit nicht 8 !
	debug_printf( ("     0x"));
    debug_printf("%02x",enc28j60Read(PHSTAT2));//ist 16 bit breit nicht 8 !
    debug_printf( ("\n"));

}
*/


