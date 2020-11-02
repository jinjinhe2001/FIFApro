#ifndef __MOUSES_h
#define __MOUSES_h

#include<conio.h>
#include<graphics.h>
#include<stdio.h>
#include<dos.h>
//#include"tools.h"
#include"int.h"

#define LB_MASK 0x0001
#define RB_MASK 0x0002

#define MOUSE_SIZE_X 16
#define MOUSE_SIZE_Y 16


struct Mouse{
	unsigned int x,y;
	unsigned int button;
	int isShow;
};

extern struct Mouse gMouse;
extern unsigned far* pVarm;//指向varm的指针


extern unsigned Cursor[4][32];

void setGraphicMouse(int x,int y,unsigned pattern);
//下面是楼上函数的简化版
void setPatternMouse(int pattern);

void initMouse(void);
void showMouse(void);
void hideMouse(void);
void readMouse(struct Mouse* mouse);


#endif