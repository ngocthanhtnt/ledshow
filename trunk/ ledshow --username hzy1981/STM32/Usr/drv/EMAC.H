#ifndef __EMAC_H
#define __EMAC_H


#include "Net_Config.h"


void init_ethernet (void);
void send_frame (OS_FRAME *frame);
void poll_ether (void);
#endif

