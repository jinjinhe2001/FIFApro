#include"common.h"
#include"choosem.h"

int choosemain(USER *u)
{
	int condition = 1;
	delay(100); 	
	clrmous(MouseX, MouseY);
	cleardevice();
	drawback_2(u);
	while (condition == 1)
	{
		newmouse(&MouseX, &MouseY, &press);
		condition = func2();
	}
	if (condition == 21)
		return 21;
	if (condition == 22)
		return 22;
	if (condition == 23)
		return 23;
	if (condition == 24)
		return 24;
	if (condition == 25)
		return 25;
	if (condition == 0)
		return 0;
}
 
int func2()
{
	static int num;
	if ((MouseX >= 80) && (MouseX <= 320) && (MouseY >= 60) && (MouseY <= 240))
	{	
		if(mouse_press(80, 60, 320, 240) == 2)
		{
			MouseS = 1;
			if(num == 0)
			{
				lightbutton2(80, 60, 320, 240, BLACK, 11, 1);
				num = 1;
			}
			else if(num != 1)
			{
				recoverbutton2(num);
				num=0;
			}
			return 1;
		}
		else if(mouse_press(80, 60, 320, 240) == 1)
		{
			return 21;
		}
	}
	if ((MouseX >= 320) && (MouseX <= 560) && (MouseY >= 60) && (MouseY <= 240))
	{	
		if(mouse_press(320, 60, 560, 240) == 2)
		{
			MouseS = 1;
			if(num == 0)
			{
				lightbutton2(320, 60, 560, 240, BLACK, 11, 2);
				num = 2;	
			}
			else if(num != 2)
			{
				recoverbutton2(num);
				num = 0;
			}
			return 1;
		}
		else if(mouse_press(320, 60, 560, 240) == 1)
		{
			clrmous(MouseX, MouseY);
			delay(50);
			return 22;
		}
	}
	if ((MouseX >= 80) && (MouseX <= 320) && (MouseY >= 240) && (MouseY <= 420))
	{
		if(mouse_press(80, 240, 320, 420) == 2)
		{
			MouseS = 1; 
			if(num == 0)
			{
				lightbutton2(80, 240, 320, 420, BLACK, 11, 3);
				num = 3;	
			}
			else if(num != 3)
			{
				recoverbutton2(num);
				num = 0;
			}
			return 1;
		}
		else if(mouse_press(80, 240, 320, 420) == 1)
		{
			return 23;
		} 
	}
	if ((MouseX >= 320) && (MouseX <= 560) && (MouseY >= 240) && (MouseY <= 420))
	{	
		if(mouse_press(320, 240, 560, 420) == 2)
		{
			MouseS = 1;
			if(num == 0)
			{
				lightbutton2(320, 240, 560, 420, BLACK, 11, 4);
				num = 4;	
			}
			else if(num != 4)
			{
				recoverbutton2(num);
				num = 0;
			}
			return 1;
		}
		else if(mouse_press(320, 240, 560, 420) == 1)
		{
			return 24;
		}
	}
	if ((MouseX >= 0) && (MouseX <= 60) && (MouseY >= 60) && (MouseY <= 420))  //训练模式
	{
		if (mouse_press(0, 60, 60, 420) == 2)
		{
			MouseS = 1;
			if (num == 0)
			{
				lightbutton2(0, 60, 60, 420, BLACK, 11, 6);
				num = 6;
			}
			else if (num != 6)
			{
				recoverbutton2(num);
				num = 0;
			}
			return 1;
		}
		else if (mouse_press(0, 60, 60, 420) == 1)
		{
			return 25;
		}
	}
	if (MouseX >= 590 && MouseX <= 640 && MouseY >= 430 && MouseY <= 480) 
	{
		if(mouse_press(590, 430, 640, 480) == 2)
		{
			MouseS = 1;
			if(num == 0)
			{
				lightbutton2(590, 430, 640, 480, BLACK, 11, 5);
				num = 5;
			}
			else if(num != 5)
			{
				recoverbutton2(num);
				num = 0;
			}
			return 1;
		}
		if(mouse_press(590, 430, 640, 480) == 1)
		{
			return 0;
		}
	}
	if(num != 0)
	{
		MouseS = 0;
		recoverbutton2(num);
		num = 0;
		if(MouseS != 0)
			MouseS = 0;
	}
	return 1;
}



void drawback_2(USER *u)
{
	setcolor(BLACK);
	setfillstyle(1, 7);
	setlinestyle(SOLID_LINE, 0, 2);//展示边框

	setcolor(WHITE);
	setfillstyle(1, CYAN);
	bar(0,0,639,60);
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
	settextstyle(0, 0, 1);
	outtextxy(90,30,"User:");
	outtextxy(130,30,u->user);
	outtextxy(470,30,"Money:");
	outtextxy(520,30,u->money);
	
	setfillstyle(1, WHITE);
	sector(30, 21, 230, 310, 35, 35);
	fillellipse(30, 21 - 5, 15, 15);
	setcolor(WHITE);
	circle(30, 21 - 5, 15);

	settextstyle(0, 0, 3);//第三个参数表示大小 
	setcolor(BLACK);
	setfillstyle(1, WHITE);
	bar(80, 60, 320, 240);
	rectangle(80, 60, 320, 240);
	puthz(120, 120, "单人游戏", 32, 34, GREEN); 
	
	bar(320, 60, 560, 240);
	rectangle(320, 60, 560, 240);
	puthz(360, 120, "双人游戏", 32, 34, GREEN);	
	
	bar(80, 240, 320, 420);
	rectangle(80, 240, 320, 420);
	puthz(150, 300, "帮助", 32, 34, GREEN);	
	
	bar(320, 240, 560, 420);
	rectangle(320, 240, 560, 420);
	puthz(390, 300, "关于", 32, 34, GREEN);
	
	bar(590, 430, 640, 480);
	rectangle(590, 430, 640, 480);
	puthz(600, 448, "返回", 16, 16, GREEN);
	
	bar(0, 60, 60, 420);
	rectangle(0, 60, 60, 420);
	puthz(10, 80, "训", 32, 34, GREEN);
	puthz(10, 170, "练", 32, 34, GREEN);
	puthz(10, 260, "模", 32, 34, GREEN);
	puthz(10, 350, "式", 32, 34, GREEN);
	
}

void lightbutton2(int x, int y, int x1, int y1, int color1, int color2, int flag)
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
		puthz(120, 120, "单人游戏", 32, 34, BLUE);
		break;
	case 2:
		puthz(360, 120, "双人游戏", 32, 34, BLUE);
		break;
	case 3:
		puthz(150, 300, "帮助", 32, 34, BLUE);
		break;
	case 4:
		puthz(390, 300, "关于", 32, 34, BLUE);
		break;
	case 5:
		puthz(600, 448, "返回", 16, 16, BLUE);
		break;
	case 6:
		puthz(10, 80, "训", 32, 34, BLUE);
		puthz(10, 170, "练", 32, 34, BLUE);
		puthz(10, 260, "模", 32, 34, BLUE);
		puthz(10, 350, "式", 32, 34, BLUE);
		break;
	default:
		closegraph();
		printf("something runs wrong in lightbutton");
		exit(1);
	}
}

void recoverbutton2(int status)
{
	clrmous(MouseX, MouseY);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);	
	switch (status)
	{
	case 1:
	{
		setfillstyle(1, WHITE);
		bar(80, 60, 320, 240);
		rectangle(80, 60, 320, 240);
		puthz(120, 120, "单人游戏", 32, 34, GREEN); 
		break;
	}
	case 2:
	{
		setfillstyle(1, WHITE);
		bar(320, 60, 560, 240);
		rectangle(320, 60, 560, 240);
		puthz(360, 120, "双人游戏", 32, 34, GREEN);
		break;
	}
	case 3:
	{
		setfillstyle(1, WHITE);
		bar(80, 240, 320, 420);
		rectangle(80, 240, 320, 420);
		puthz(150, 300, "帮助", 32, 34, GREEN);
		break;
	}
	case 4:
	{
		setfillstyle(1, WHITE);
		bar(320, 240, 560, 420);
		rectangle(320, 240, 560, 420);
		puthz(390, 300, "关于", 32, 34, GREEN);
		break;
	}
	case 5:
	{
		setfillstyle(1, WHITE);
		bar(590, 430, 640, 480);
		rectangle(590, 430, 640, 480);
		puthz(600, 448, "返回", 16, 16, GREEN);
		break;
	}
	case 6:
	{
		setfillstyle(1, WHITE);
		bar(0, 60, 60, 420);
		rectangle(0, 60, 60, 420);
		puthz(10, 80, "训", 32, 34, GREEN);
		puthz(10, 170, "练", 32, 34, GREEN);
		puthz(10, 260, "模", 32, 34, GREEN);
		puthz(10, 350, "式", 32, 34, GREEN);
	}
	}
}





