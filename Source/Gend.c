#include"common.h"
#include"Gend.h"
#include"game.h"

int Gend(USER* u, struct Ball* ball, int flag)
{
	int condition = 1;
	int money=0;
	int addM = 0;
	char CaddM[6];

	clrmous(MouseX, MouseY);
	MouseS = 0;
	delay(100);
	cleardevice();
	if (flag == 1)
	{
		if (ball->score_we > ball->score_en)
		{
			money = atoi(u->money);
			money += (1500 + 500 * (ball->score_we - ball->score_en));
			addM = (1500 + 500 * (ball->score_we - ball->score_en));
			itoa(money, u->money, 10);
		}
		else
		{
			money = atoi(u->money);
			money += 500;
			addM = 500;
			itoa(money, u->money, 10);
		}
	}
	else
	{
		money = atoi(u->money);
		money += 2000;
		addM = 2000;
		itoa(money, u->money, 10);
	}

	draw_Gend(u, ball);
	puthz(210, 240, "加金币数：", 24, 30, RED);
	itoa(addM, CaddM, 10);
	outtextxy(360, 245, CaddM);

	Minfo_input(u);
	while (condition == 1)
	{
		
		newmouse(&MouseX, &MouseY, &press);
		condition = func_Gend();
	}

	if (condition == 2)
		return -2;
}
void draw_Gend(USER* u,struct Ball* ball)
{
	char s_we[2];
	char s_en[2];
	int win_ball=0;
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
	itoa(ball->score_we, s_we, 10);
	itoa(ball->score_en, s_en, 10);
	outtextxy(90,30,"User:");
	outtextxy(130,30,u->user);
	outtextxy(470,30,"Money:");
	outtextxy(520,30,u->money);
	settextstyle(0, 0, 4);
	puthz(290, 150, "比分", 24, 30, RED);
	outtextxy(250, 100, s_we);
	outtextxy(310, 100, ":");
	outtextxy(350, 100, s_en);
	strcpy(s_we, "\0");
	strcpy(s_en, "\0");
	settextstyle(0, 0, 2);
	puthz(50, 200, "左方净胜分：", 24, 30, RED);
	win_ball = ball->score_we - ball->score_en;
	if (win_ball < 0)
	{
		win_ball = -win_ball;
		outtextxy(230, 205, "-");
	}
	itoa(win_ball, s_we, 10);
	outtextxy(240, 205, s_we);
	puthz(370, 200, "右方净胜分：", 24, 30, RED);
	win_ball = ball->score_en - ball->score_we;
	if (win_ball < 0)
	{
		win_ball = -win_ball;
		outtextxy(540, 205, "-");
	}
	itoa(win_ball, s_en, 10);
	outtextxy(550, 205, s_en);
	setfillstyle(1, WHITE);
	bar(280, 300, 360, 330);
	rectangle(280, 300, 360, 330);
	puthz(305, 310, "返回", 16, 16, RED);	
}
int func_Gend()
{
	static int num;
	if ((MouseX >= 280) && (MouseX <= 360) && (MouseY >= 300) && (MouseY <= 330))
	{	
		if(mouse_press(280, 300, 360, 330) == 2)
		{
			MouseS = 1;
			if(num == 0)
			{
				lightbuttonGend(280, 300, 360, 330, BLACK, 11, 1);
				num = 1;
			}
			else if(num != 1)
			{
				recoverbuttonGend(num);
				num=0;
			}
			return 1;
		}
		else if(mouse_press(280, 300, 360, 330) == 1)
		{
			return 2;
		}
	}

	if(num != 0)
	{
		MouseS = 0;
		recoverbuttonGend(num);
		num = 0;
		if(MouseS != 0)
			MouseS = 0;
	}
	return 1;
}
void Minfo_input(USER *u)
{
	FILE* fp;
	USER* us;
	int len;
	int i;

	if ((fp = fopen("database\\UserData.dat", "rb+")) == NULL)
	{
		printf("cannot open file UserDat.dat");
		delay(3000);
		exit(1);
	}
	fseek(fp, 0, SEEK_END);//文件指针定位到最后一位
	len = ftell(fp) / sizeof(USER);//计算用户个数
	for (i = 0; i < len; i++)
	{
		if ((us = (USER*)malloc(sizeof(USER))) == NULL)
		{
			printf("memoryallocation runs wrong in lgfunc.c");
			delay(3000);
			exit(1);
		}
		fseek(fp, i * sizeof(USER), SEEK_SET);//每次往后移一个用户
		fread(us, sizeof(USER), 1, fp);//将信息读入u
		if (strcmp(us->user, u->user) == 0)
		{
			fseek(fp, i * sizeof(USER), SEEK_SET);
			fwrite(u, sizeof(USER), 1, fp);
			if (u != NULL)
			{
				free(u);
				u = NULL;
			}
			if (fclose(fp) != 0)
			{
				printf("\n cannot close Database");
				exit(1);
			}
		}
		if (u != NULL)
		{
			free(u);
			u = NULL;
		}

	}
}
void lightbuttonGend(int x, int y, int x1, int y1, int color1, int color2, int flag)
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
		puthz(305, 310, "返回", 16, 16, BLUE);	
		break;

	default:
		closegraph();
		printf("something runs wrong in lightbutton");
		exit(1);
	}
	
}
void recoverbuttonGend(int status)
{
	clrmous(MouseX, MouseY);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);	
	switch (status)
	{
		case 1:
		{
			setfillstyle(1, WHITE);
			bar(280, 300, 360, 330);
			rectangle(280, 300, 360, 330);
			puthz(305, 310, "返回", 16, 16, RED);	
			break;
		}
	}
}
