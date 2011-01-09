#ifndef MAKEPROTO_H
#define MAKEPROTO_H

#undef EXT
#ifdef MAKE_PROTO_C
#define EXT
#else
#define EXT extern
#endif


typedef struct
{
   char seq;
   char seq0;
   int len;
   int off;
}S_Frame_Info;

EXT S_Frame_Info frameInfo;
#endif // MAKEPROTO_H
