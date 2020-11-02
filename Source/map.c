#include"map.h"

unsigned char map[38400];
unsigned char getMirrorChar(unsigned char src)
{
	unsigned char result = 0;
	int i;
	for (i = 0;i < 8;i++) {
		result <<= 1;
		result += (src & 0x0001);
		src >>= 1;
	}
	return result;
}

static unsigned char getCharFromField(int row, int col)
{
	if (col < 60)return (*(map + 60 * row + col));
	return getMirrorChar(*(map + 60 * row + 119 - col));
}

void putField(int x0, int y0, int page)
{
	int xBase, xMod, i, j;
	unsigned char far* pVarm;
	if (page) {
		pVarm = 0xa0008000;
	}
	else {
		pVarm = 0xa0000000;
	}
	cleardevice();
	xBase = x0 >> 3;
	xMod = x0 % 8;
	outportb(0x3c4, 0x02);
	outportb(0x3c5, WHITE);
	for (i = 0;i < G_Y_MAX;i++) {
		for (j = 0;j < G_X_MAX / 8;j++) {
			*(pVarm + 80 * i + j) = (getCharFromField(y0 + i, j + xBase) << xMod) + \
				(getCharFromField(y0 + i, j + xBase + 1) >> (8 - xMod));
		}
	}
	outport(0x3c4, 0xff02);
}

void read_field()
{
	static int i = 0;
	if (i == 0)
	{
		FILE* fp;
		fp = fopen("field", "r");
		if (fp == NULL)
		{
			printf("?");
			sleep(1);
		}
		fread(map, 1, 38400, fp);
		fclose(fp);
	}
	i = 1;
} 
	 
