#ifndef SCREEN_STATUS_H
#define SCREEN_STATUS_H

#undef EXT
#ifdef LIGHTNESS_C
#define EXT
#else
#define EXT extern
#endif

#define MAX_LIGHTNESS_LEVEL 0x09

EXT void Lightness_Proc();
EXT void Open_Close_Proc();
#endif
