#include"common.h"
#include"mainsolo.h"
//#include"putbmp.h"


int mainsolo(USER *u)
{
	int condition = 1;
	clrmous(MouseX, MouseY);
	cleardevice();
	drawback_21(u);
	delay(100); 
	while (condition == 1)
	{
		newmouse(&MouseX, &MouseY, &press);
		condition = func21();
	}
	if (condition == 211)
		return 211;
	if (condition == 212)
		return 212;
	if (condition == 2)
		return 2;
}

void drawback_21(USER *u)
{
	
	
	setfillstyle(1, LIGHTGREEN);
	bar(0,60,639,144);
	setfillstyle(1, GREEN);
	bar(0,144,639,228);
	setfillstyle(1, LIGHTGREEN);
	bar(0,228,639,312);
	setfillstyle(1, GREEN);
	bar(0,312,639,396);
	setfillstyle(1, LIGHTGREEN);
	bar(0,396,639,480);
	
	setfillstyle(1, WHITE);
	
	setcolor(BLACK);
	setfillstyle(1, 8);
	setlinestyle(SOLID_LINE, 0, 2);
	bar(0, 30, 300, 450);
	setfillstyle(1, 7);
	setcolor(WHITE);
	
	bar(40, 65, 260, 165);
	rectangle(40, 65, 260, 165);
	puthz(90, 100, "准备游戏", 32, 32, GREEN);
	
	bar(40, 190, 260, 290);
	rectangle(40, 190, 260, 290);
	puthz(90, 225, "球员创立", 32, 32, GREEN);
	
	bar(40, 315, 260, 415);
	rectangle(40, 315, 260, 415);
	puthz(90, 350, "球队管理", 32, 32, GREEN);
	
	bar(590, 430, 640, 480);
	rectangle(590, 430, 640, 480);	
	puthz(600, 448, "返回", 16, 16, GREEN);
	

	setfillstyle(1, CYAN);
	bar(0, 0, 639, 60);
	setcolor(WHITE);

	settextstyle(0, 0, 1);
	outtextxy(90, 30, "User:");
	outtextxy(130, 30, u->user);
	outtextxy(470, 30, "Money:");
	outtextxy(520, 30, u->money);

	setfillstyle(1, WHITE);
	sector(30, 21, 230, 310, 35, 35);
	fillellipse(30, 21 - 5, 15, 15);
	setcolor(WHITE);
	circle(30, 21 - 5, 15);
}

int func21()
{
	static int num;
	if(MouseX >= 40 && MouseX <= 260 && MouseY >=65 && MouseY <= 165)
	{
		if(mouse_press(40, 65, 260, 165) == 2)
		{
			MouseS = 1;
			if(num == 0)
			{
				lightbutton21(40, 65, 260, 165, BLACK, 11, 1);
				num = 1;
			}
			else if(num != 1)
			{
				recoverbutton21(num);
			}
			return 1;
		}
		else if(mouse_press(40, 65, 260, 165) == 1)
			return 211;
	}
	
	if(MouseX >= 40 && MouseX <= 260 && MouseY >=190 && MouseY <= 290)
	{
		if(mouse_press(40, 190, 260, 290) == 2)
		{
			MouseS = 1;
			if(num == 0)
			{
				lightbutton21(40, 190, 260, 290, BLACK, 11, 2);
				num = 2;
			}
			else if(num != 2)
			{
				recoverbutton21(num);
			}
			return 1;
		}
		else if(mouse_press(40, 190, 260, 290) == 1)
			return 212;
	}
	if(MouseX >= 40 && MouseX <= 260 && MouseY >= 315 && MouseY <= 415)
	{
		if (mouse_press(40, 315, 260, 415) == 2)
		{
			MouseS = 1;
			if (num == 0)
			{
				lightbutton21(40, 315, 260, 415, BLACK, 11, 4);
				num = 4;
			}
			else if (num != 4)
			{
				recoverbutton21(num);
				num = 0;
			}
			return 1;
		}
		else if (mouse_press(40, 315, 260, 415) == 1)
			return 213;
	}
	
	if (MouseX >= 590 && MouseX <= 640 && MouseY >= 430 && MouseY <= 480) 
	{
		if(mouse_press(590, 430, 640, 480) == 2)
		{
			MouseS = 1;
			if(num == 0)
			{
				lightbutton21(590, 430, 640, 480, BLACK, 11, 3);
				num = 3;
			}
			else if(num != 3)
			{
				recoverbutton21(num);
				num = 0;
			}
			return 1;
		}
		if(mouse_press(590, 430, 640, 480) == 1)
		{
			return 2;
		}
	}
	if(num != 0)
	{
		MouseS = 0;
		recoverbutton21(num);
		num = 0;
		if(MouseS != 0)
			MouseS = 0;
	}
	return 1;
}

void lightbutton21(int x, int y, int x1, int y1, int color1, int color2, int flag)
{
	clrmous(MouseX, MouseY);
	delay(10);
	setcolor(color1);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setfillstyle(1, color2);
	bar(x, y, x1, y1);
	rectangle(x, y, x1, y1);	//画边框
	switch (flag)
	{
	case 1:
		puthz(90, 100, "准备游戏", 32, 32, BLUE);
		break;
	case 2:
		puthz(90, 225, "球员创立", 32, 32, BLUE);
		break;
	case 3:
		puthz(600, 448, "返回", 16, 16, BLUE);
		break;
	case 4:
		puthz(90, 350, "球队管理", 32, 32, BLUE);
		break;

	default:
		closegraph();
		printf("something runs wrong in lightbutton");
		exit(1);
	}
}

void recoverbutton21(int status)
{
	clrmous(MouseX, MouseY);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setfillstyle(1, 7);	
	switch (status)
	{
	case 1:
		bar(40, 65, 260, 165);
		rectangle(40, 65, 260, 165);
		puthz(90, 100, "准备游戏", 32, 32, GREEN);
		break;
	case 2:
		bar(40, 190, 260, 290);
		rectangle(40, 190, 260, 290);
		puthz(90, 225, "球员创立", 32, 32, GREEN);
		break;
	case 3:
		bar(590, 430, 640, 480);
		rectangle(590, 430, 640, 480);
		puthz(600, 448, "返回", 16, 16, GREEN);
		break;
	case 4:
		bar(40, 315, 260, 415);
		rectangle(40, 315, 260, 415);
		puthz(90, 350, "球队管理", 32, 32, GREEN);
		break;
	}
}












