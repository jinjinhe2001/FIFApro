#ifndef _practice_h
#define _practice_h
#include"common.h"

int practice(USER *u);	//练习主函数 
void show_25();			//界面UI画图 
void drawback_25(USER *u); //背景画图 
int func25();			// 练习功能界面 
void lightbutton25(int x, int y, int x1, int y1, int color1, int color2, int flag);//按钮点亮 
void recoverbutton25(int status);												//按钮恢复 

#endif
