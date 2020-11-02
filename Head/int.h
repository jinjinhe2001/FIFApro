#ifndef __INTERRUPT
#define __INTERRUPT

#include<dos.h>
#include<conio.h>
#include"stdlib.h"
//#include"tools.h"

//中断安装程序
void installInt(void interrupt (*faddr)(),char intNum);

//全局变量-----源中断地址
extern void interrupt (*oldint9)();
extern void interrupt (*oldint1c)();

//键盘检测esc时间中断
extern int escHit;
void interrupt newint9_esc(unsigned bp,unsigned di, 
	unsigned si,unsigned ds,unsigned es,unsigned dx, 
	unsigned cx,unsigned bx,unsigned ax,unsigned ip, 
	unsigned cs,unsigned flags);
void init_newint9_esc();
void cancel_newint9_esc();

//游戏运行时的键盘中断
//
extern unsigned int key;
struct Key{
	unsigned int pressed;
	unsigned int state;
};
struct GameKey{
	struct Key w,a,s,d;   //移动按钮
	struct Key j,k;		//技能按钮
	struct Key up, down, left, right;//对手移动
	struct Key one, three;//对手技能
};

struct GameKey* getGameKey();
void interrupt newint9_game(unsigned bp,unsigned di, 
	unsigned si,unsigned ds,unsigned es,unsigned dx, 
	unsigned cx,unsigned bx,unsigned ax,unsigned ip, 
	unsigned cs,unsigned flags);
void init_newint9_game();
void cancel_newint9_game();
void clearGameKey();
void dealGameKey();
void setKeyPressed();



#endif