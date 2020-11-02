#include"common.h"
#include"help.h"

int help()
{
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	draw_help();
	delay(100);
	while(1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if(mouse_press(0,0,640,480)==1)
			break;
	}
	return 2;
}
void draw_help()
{
	setfillstyle(SOLID_FILL, WHITE);
	settextstyle(0,0,2);
	setcolor(RED);
	bar(0,0,640,480);
	puthz(10,15,"帮助",48,48,BLACK);
	puthz(10,100,"软件操作说明：",16,17,BLACK);
	puthz(70,130,"本游戏具有单人游戏与双人游戏两种模式",16,17,BLACK);
	puthz(70,160,"单人游戏菜单中你可以在管理球队界面进行五个基本球队名单的查看以及自",16,17,BLACK);
	puthz(10,190,"定义球队的创建",16,17,BLACK);
	puthz(70,220,"单人游戏菜单中你也可以创建自定义球员在准备游戏界面选择你的球队查",16,17,BLACK);
	puthz(10,250,"看阵容并获得胜利吧",16,17,BLACK);
	puthz(70,280,"双人游戏准备界面你可以选择两方的球队",16,17,BLACK);
	puthz(70,310,"单人游戏中用上下左右方向键进行球员移动",16,17,BLACK);
	outtextxy(400,310,"A");
	puthz(420,310,"键传球射门",16,17,BLACK);
	outtextxy(507,310,"D");
	puthz(525,310,"键抢断",16,17,BLACK);
	puthz(10,340,"抢断游戏会选择最近球员给玩家操控",16,17,BLACK);
	puthz(70,370,"双人游戏双方分别用上下左右以及",16,17,BLACK);
	outtextxy(327,370,"wsad");
	puthz(391,370,"操控球员",16,17,BLACK);
	outtextxy(458,370,"JK");
	puthz(488,370,"以及",16,17,BLACK);
	outtextxy(523,370,"13");
	puthz(553,370,"键为传球与",16,17,BLACK);	
	puthz(10,400,"抢断",16,17,BLACK);
	
	puthz(70,440,"点击退出。。。",16,17,BLACK);
}
