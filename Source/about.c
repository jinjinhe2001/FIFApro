#include"common.h"
#include"help.h"

int about()
{
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	draw_about();
	delay(100);
	while(1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if(mouse_press(0,0,640,480)==1)
			break;
	}
	return 2;
}
void draw_about()
{
	setfillstyle(SOLID_FILL, WHITE);
	
	setcolor(RED);
	bar(0,0,640,480);

	puthz(10,15,"关于",48,48,BLACK);
	puthz(10,100,"开发者说明：",16,17,BLACK);
	puthz(70,130,"本游戏由自实",16,17,BLACK);
	settextstyle(0,0,2);
	outtextxy(170,130,"1901");
	puthz(230,130,"何金津与高纪文开发",16,17,BLACK);
	puthz(70,160,"本软件为二零二零年人工智能与自动化",16,17,BLACK); 
	outtextxy(360,160,"C");
	puthz(375,160,"语言课程设计作品",16,17,BLACK);
	puthz(10,190,"指导老师：",16,17,BLACK);
	puthz(70,220,"周纯杰，何顶新，左峥嵘，高常鑫，周凯波，汪国有，彭刚，陈忠，桑农等",16,17,BLACK);
	puthz(10,250,"老师",16,17,BLACK);
	puthz(70,280,"本游戏开发灵感来源于现实生活足球以及各类足球游戏",16,17,BLACK);
	puthz(70,310,"游戏为学生课设作品，非商用目的，转载请联系作者",16,17,BLACK);
	settextstyle(0,0,5);
	outtextxy(70,370,"HUST AIA");
	
	puthz(70,440,"点击退出。。。",16,17,BLACK);
	
}
