#ifndef _map_h
#define _map_h

#include"common.h"
#define G_X_MAX 640
#define G_Y_MAX 350


unsigned char getMirrorChar(unsigned char src);
static unsigned char getCharFromField(int row, int col);
void putField(int x0, int y0, int page);
void read_field(); 

#endif // 

