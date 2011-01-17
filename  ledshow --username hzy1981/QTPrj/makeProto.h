#ifndef MAKEPROTO_H
#define MAKEPROTO_H

#include "..\Includes.h"

#undef EXT
#ifdef MAKE_PROTO_C
#define EXT
#else
#define EXT extern
#endif

#define COM_MODE   0x00 //´®¿Ú
#define UDISK_MODE 0x01 //uÅÌ
#define PREVIEW_MODE   0x02 //Èí¼þ·ÂÕæ

typedef struct
{
   char seq;
   INT16U seq0;
   int len;
   int off;
}S_Frame_Info;

EXT S_Frame_Info frameInfo;
INT8U makeProtoData(QString screenStr, int mode);
#endif // MAKEPROTO_H
