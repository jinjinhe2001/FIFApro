#include"mouses.h"

struct Mouse gMouse;
unsigned far* pVarm;
static unsigned int oldX,oldY;
static void *mouseBuffer;//储存鼠标背景

static unsigned mouseShape[]={
   /*  Cursor Mask  */
     0x001E,      /*  0001111000000000   */
     0x0012,      /*  0001001000000000   */
     0x0012,      /*  0001001000000000   */
     0x0012,      /*  0001001000000000   */
     0x0012,      /*  0001001000000000   */
     0xFF13,      /*  0001001111111111   */
     0x4912,      /*  0001001001001001   */
     0x4912,      /*  0001001001001001   */
     0x49F2,      /*  1111001001001001   */
     0x0190,      /*  1001000000000001   */
     0x0190,      /*  1001000000000001   */
     0x0190,      /*  1001000000000001   */
     0x0180,      /*  1000000000000001   */
     0x0180,      /*  1000000000000001   */
     0x0180,      /*  1000000000000001   */
     0xFFFF       /*  1111111111111111   */
};
/***********************************************************
Function: initMouse
Description: 初始化鼠标
Input:无
return：无
**********************************************************/
void initMouse(){
	union REGS regs;
	regs.x.ax=0;
	int86(51,&regs,&regs);
	if(regs.x.ax==0){
		closegraph();
		printf("the mouse initial is failed");
		getch();
	}
	regs.x.ax=7;
	regs.x.cx=0;
	regs.x.dx=640-16;
	int86(51,&regs,&regs);
	regs.x.ax=8;
	regs.x.cx=0;
	regs.x.dx=480-1;
	int86(51,&regs,&regs);
	mouseBuffer=malloc(134);
	oldint1c=getvect(0x1c);
	gMouse.x=320;
	gMouse.y=240;
	gMouse.isShow=0;
}
/***********************************************************
Function: showMouse
Description: 自动显示鼠标（开启中断）
Input: 无
return：无
**********************************************************/
void showMouse(){
	if(gMouse.isShow)return;
	gMouse.isShow=0;
	installInt(newint1c,0x1c);
}
/***********************************************************
Function: hideMouse
Description: 自动隐藏鼠标（恢复中断）
Input: 无
return：无
**********************************************************/
void hideMouse(){
	if(gMouse.isShow==0)return;
	installInt(oldint1c,0x1c);
	putimage(gMouse.x,gMouse.y,mouseBuffer,COPY_PUT);
	gMouse.isShow=0;
}
/***********************************************************
Function: readMouse
Description: 读取鼠标信息
Input: 鼠标结构体指针mouse
return：无
**********************************************************/
void readMouse(struct Mouse* mouse){
	union REGS regs;
	regs.x.ax=3;
	int86(51,&regs,&regs);
	mouse->x=regs.x.cx;
	mouse->y=regs.x.dx;
	mouse->button=regs.x.bx;
}
/***********************************************************
Function: updateGMouse
Description: 更新全局鼠标信息
Input: 无
return：无
**********************************************************/
void updateGMouse(){
	_AX = 3;
  geninterrupt(0x33);
  gMouse.x=_CX&0xfff8;
  gMouse.y=_DX;
  gMouse.button=_BX;
}
/***********************************************************
Function: printMouse
Description: 显示鼠标
Input: 无
return: 无
**********************************************************/
void printMouse(){
	unsigned i;
	pVarm=(unsigned far*)(0xa0000000+80*gMouse.y+(gMouse.x>>3));
	if(gMouse.isShow){
		putimage(oldX,oldY,mouseBuffer,COPY_PUT);
	}
	getimage(gMouse.x,gMouse.y,gMouse.x+15,gMouse.y+15,mouseBuffer);
	oldX=gMouse.x;
	oldY=gMouse.y;
	gMouse.isShow=1;
	outportb(0x3c4,0x02);
	outportb(0x3c5,WHITE);
	for(i=0;i<16;i++){
		*(pVarm+40*i)=mouseShape[i];
	}
	outport(0x3c4,0xff02);
}