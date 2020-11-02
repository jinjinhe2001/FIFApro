#ifndef _mapall_h
#define _mapall_h

#include"common.h"
#define G_X_MAX 640
#define G_Y_MAX 350

unsigned char map[38400];
unsigned char getMirrorChar(unsigned char src);
static unsigned char getCharFromField(int row, int col);
void putField(int x0, int y0, int page);

#endif // 

