#include"practice.h"
#include"shoot.h"
#include"gamepra.h"


int practice(USER *u)
{
	int condition = 1;
	clrmous(MouseX, MouseY);
	cleardevice();
	delay(100); 
	drawback_25(u);
	while (condition == 1)
	{
		newmouse(&MouseX, &MouseY, &press);
		condition = func25();
	}

	if (condition == -2)
		return -2;
	if (condition == 2)
		return 2;
}
int func25()
{
	static int num;
	
	if ((MouseX >= 200) && (MouseX <= 400) && (MouseY >= 120) && (MouseY <= 220))
	{	
		if(mouse_press(200, 120, 400, 220) == 2)
		{
			MouseS = 1;
			if(num == 0)
			{
				lightbutton25(200, 120, 400, 220, BLACK, 11, 1);
				num = 1;
			}
			else if(num != 1)
			{
				recoverbutton25(num);
				num=0;
			}
			return 1;
		}
		else if(mouse_press(200, 120, 400, 220) == 1)
		{
			gamepra();
			return -2;
		}
	}
	if ((MouseX >= 200) && (MouseX <= 400) && (MouseY >= 260) && (MouseY <= 360))
	{	
		if(mouse_press(200, 260, 400, 360) == 2)
		{
			MouseS = 1;
			if(num == 0)
			{
				lightbutton25(200, 260, 400, 360, BLACK, 11, 2);
				num = 2;	
			}
			else if(num != 2)
			{
				recoverbutton25(num);
				num = 0;
			}
			return 1;
		}
		else if(mouse_press(200, 260, 400, 360) == 1)
		{
			delay(100);

			game_shoot(0);
			return 2;
		}
	}

	if (MouseX >= 590 && MouseX <= 640 && MouseY >= 430 && MouseY <= 480) 
	{
		if(mouse_press(590, 430, 640, 480) == 2)
		{
			MouseS = 1;
			if(num == 0)
			{
				lightbutton25(590, 430, 640, 480, BLACK, 11, 5);
				num = 5;
			}
			else if(num != 5)
			{
				recoverbutton25(num);
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
		recoverbutton25(num);
		num = 0;
		if(MouseS != 0)
			MouseS = 0;
	}
	return 1;
	
}
void drawback_25(USER *u)
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
	bar(200, 120, 400, 220);
	rectangle(200, 120, 400, 220);
	puthz(235, 155, "控球练习", 32, 34, GREEN); 
	
	bar(200, 260, 400, 360);
	rectangle(200, 260, 400, 360);
	puthz(235, 295, "点球练习", 32, 34, GREEN);	
	
	bar(590, 430, 640, 480);
	rectangle(590, 430, 640, 480);
	puthz(600, 448, "返回", 16, 16, GREEN);
	
	
}
void lightbutton25(int x, int y, int x1, int y1, int color1, int color2, int flag)
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
			puthz(235, 155, "控球练习", 32, 34, BLUE); 
			break;
		case 2:
			puthz(235, 295, "点球练习", 32, 34, BLUE);	
			break;
		case 5:
			puthz(600, 448, "返回", 16, 16, BLUE);
			break;
		default:
			closegraph();
			printf("something runs wrong in lightbutton");
			exit(1);
	}
}

void recoverbutton25(int status)
{
	clrmous(MouseX, MouseY);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);	
	switch (status)
	{
		case 1:
		{
			setfillstyle(1, WHITE);
			bar(200, 120, 400, 220);
			rectangle(200, 120, 400, 220);
			puthz(235, 155, "控球练习", 32, 34, GREEN); 
			break;
		}
		case 2:
		{
			setfillstyle(1, WHITE);
			bar(200, 260, 400, 360);
			rectangle(200, 260, 400, 360);
			puthz(235, 295, "点球练习", 32, 34, GREEN);	
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
	}
}

