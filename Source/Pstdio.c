#include<common.h>
#include<Pstdio.h>

int Pstdio(USER *u)
{
	int num,state=0;
	int delmoney=1000;
	Player player;
	int condition=1;
	int pre_all=0;
	
	player.allA[0]='2';
	player.allA[1]='0';
	player.allA[2]='\0';
	player.speed[0]='0';
	player.speed[1]='\0';
	player.control[0]='0';
	player.control[1]='\0';
	player.power[0]='0';
	player.power[1]='\0';
	player.defend[0]='0';
	player.defend[1]='\0';
	player.all=20;
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	draw_Pstdio(&player);
	while(condition==1)
	{
		changemoney(&delmoney,&player,&pre_all);
		newmouse(&MouseX, &MouseY, &press);
		condition = func_212(u,&player,&num,&state,&delmoney);
	}
	
	return 21;
}
void draw_Pstdio(Player *player)
{
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
	
	setfillstyle(1, LIGHTGRAY);
	 
	bar(57, 17, 583, 383);
	bar(145, 415, 235, 465);
	bar(415, 415, 505, 465);

	setfillstyle(1, WHITE);
	bar(60, 20, 580, 380);//大框 
	setfillstyle(1, GREEN);
	bar(260,17,380,100);
	drawC(287,30,2,LIGHTRED);
	setlinestyle(SOLID_LINE, 0, 1);	
	setfillstyle(1, CYAN);
	bar(140, 410, 230, 460);//确认键 
	bar(410, 410, 500, 460);//取消 
	

	puthz(155, 415, "确认", 32, 32, BLACK);//汉字 
	puthz(425, 415, "返回", 32, 32, BLACK);//汉字 

	setfillstyle(1, RED);
	bar(60, 97, 260, 100);//中上线段 
	bar(380, 97, 580, 100);
	
	setcolor(BLACK);
	rectangle(260, 17, 380, 100);
	
	setfillstyle(1, YELLOW);//总能力条背景 
	bar(77, 57, 243, 83);
	bar(407, 57, 543, 83);
	
	puthz(440,110,"金币",16,16,BLACK);
	settextstyle(0,0,1);
	outtextxy(475,115,"-");	
	
	
	setfillstyle(1, RED);
	bar(410, 60, 539, 80);//红色能力条 
	settextstyle(0,0,2);
	outtextxy(460,40,player->allA);
	outtextxy(165,220,player->speed);
	outtextxy(165,320,player->control);
	outtextxy(465,220,player->power);
	outtextxy(465,320,player->defend);
	randPnum(player);
	
	setfillstyle(1, LIGHTGRAY);
	bar(80, 60, 240, 80);//灰色名字框 
	
	
	drawcross1(400,70,5,2,BLUE);
	drawcross(550,70,5,2,BLUE);
	
	drawcross1(90,195,5,2,BLUE);
	drawcross(250,195,5,2,BLUE);
	
	drawcross1(90,295,5,2,BLUE);
	drawcross(250,295,5,2,BLUE);
	
	drawcross1(390,195,5,2,BLUE);
	drawcross(550,195,5,2,BLUE);
	
	drawcross1(390,295,5,2,BLUE);
	drawcross(550,295,5,2,BLUE);
	setfillstyle(1, LIGHTGRAY);//小能力条 
	bar(100, 180, 240, 210);
	bar(100, 280, 240, 310);
	
	bar(400, 180, 540, 210);
	bar(400, 280, 540, 310);

	puthz(65, 25, "名字", 16, 24, BLACK);//汉字 
	puthz(390, 25, "能力点", 16, 24, BLACK);//汉字 
//	outtextxy(550, 58, all);

	puthz(150, 150, "速度", 16, 24, BLACK);
	puthz(150, 250, "控球", 16, 24, BLACK);

	puthz(450, 150, "力量", 16, 24, BLACK);
	puthz(450, 250, "防守", 16, 24, BLACK);
	
}
int func_212(USER *u,Player *player,int *num,int *state,int *delmoney)
{
	if (MouseX > 80 && MouseX < 240 && MouseY>60 && MouseY < 80)
	{
		if (mouse_press(80, 60, 240, 80) == 2)//名字框未点击
		{
			MouseS = 2;
			if (*num == 0 && *state == 0)//防止被重复标亮
			{
				lightbutton_P(80, 60, 240, 80, LIGHTGRAY, WHITE, 1);//color1为边框色，color2为填充色
				*num = 1;
			}
			return 1;

			//标亮函数
		}
		else if (mouse_press(80, 60, 240, 80) == 1)//名字框点击
		{
			MouseS = 0;
			lightbutton_P(80, 60, 240, 80, LIGHTGRAY, WHITE, 1);
			inputadminP(player->name, 80, 57, 3, WHITE);
			//输入函数
			if (strlen(player->name) != 0)
				*state = 1;
			else
				*state = 0;
			return 1;
		}
	}
	if (MouseX > 140 && MouseX < 230 && MouseY>410 && MouseY < 460)
	{
		if (mouse_press(140, 410, 230, 460) == 2)//确认框未点击
		{
			if (*num == 0)
			{
				MouseS = 1;
				lightbutton_P(140, 410, 230, 460, BLACK, LIGHTCYAN, 2);//标亮函数
				*num = 2;
			}
			return 1;
		}
		else if (mouse_press(140, 410, 230, 460) == 1)//确认框点击
		{
			MouseS = 0;
			if (creat_complete(player,delmoney,u))     //信息正确
			{
				input_pinfo(player,u,delmoney);
				return 0;
			}
			else
			{
				return 0;
			}
			//检测登录状态函数
		}
	}
	if (MouseX > 410 && MouseX < 500 && MouseY>410 && MouseY < 460)
	{
		if (mouse_press(410, 410, 500, 460) == 2)//返回框未点击
		{
			if (*num == 0)
			{
				MouseS = 1;
				lightbutton_P(410, 410, 500, 460, BLACK, LIGHTCYAN, 3);//点亮函数
				*num = 3;
			}
			return 1;
		}
		else if (mouse_press(410, 410, 500, 460) == 1)//返回点击
		{
			MouseS = 0;
			return 0;
			//切换至返回界面
		}
	}
	if (MouseX > 395 && MouseX < 405 && MouseY > 68 && MouseY < 72)//小按钮 
	{
		if (mouse_press(395, 68, 405, 72) == 2)
		{
			MouseS = 1;
			if (*num == 0)//防止被重复标亮
			{
				clrmous(MouseX, MouseY);
				delay(10);
				drawcross1(400,70,5,2,RED);
				*num = 4;
			}
			return 1;

		}
		else if (mouse_press(395, 68, 405, 72) == 1)
		{
			MouseS = 1;
			clrmous(MouseX, MouseY);
			delay(10);	
			drawcross1(400,70,5,2,RED);
			changeAll(player,1);
			return 1;
		}
	}
	if (MouseX > 545 && MouseX < 555 && MouseY > 68 && MouseY < 72)//小按钮 
	{
		if (mouse_press(545, 68, 555, 72) == 2)
		{
			MouseS = 1;
			if (*num == 0)//防止被重复标亮
			{
				clrmous(MouseX, MouseY);
				delay(10);	
				drawcross(550,70,5,2,RED);
				*num = 4;
			}
			return 1;

		}
		else if (mouse_press(545, 68, 555, 72) == 1)
		{
			MouseS = 1;
			clrmous(MouseX, MouseY);
			delay(10);
			drawcross(550,70,5,2,RED);
			changeAll(player,2);
			return 1;
		}
	}
	if (MouseX > 85 && MouseX < 95 && MouseY > 193 && MouseY < 197)//小按钮 
	{
		if (mouse_press(85, 193, 95, 197) == 2)
		{
			MouseS = 1;
			if (*num == 0)//防止被重复标亮
			{
				clrmous(MouseX, MouseY);
				delay(10);
				drawcross1(90,195,5,2,RED);
				*num = 4;
			}
			return 1;

		}
		else if (mouse_press(85, 193, 95, 197) == 1)
		{
			MouseS = 1;
			clrmous(MouseX, MouseY);
			delay(10);
			drawcross1(90,195,5,2,RED);
			changespeed(player,1);
			return 1;
		}
	}
	if (MouseX > 245 && MouseX < 255 && MouseY > 193 && MouseY < 197)//小按钮 
	{
		if (mouse_press(245, 193, 255, 197) == 2)
		{
			MouseS = 1;
			if (*num == 0)//防止被重复标亮
			{
				clrmous(MouseX, MouseY);
				delay(10);
				drawcross(250,195,5,2,RED);
				*num = 4;
			}
			return 1;

		}
		else if (mouse_press(245, 193, 255, 197) == 1)
		{
			MouseS = 1;
			clrmous(MouseX, MouseY);
			delay(10);
			drawcross(250,195,5,2,RED);
			changespeed(player,2);
			return 1;
		}
	}
	if (MouseX > 85 && MouseX < 95 && MouseY > 293 && MouseY < 297)//小按钮 
	{
		if (mouse_press(85, 293, 95, 297) == 2)
		{
			MouseS = 1;
			if (*num == 0)//防止被重复标亮
			{
				clrmous(MouseX, MouseY);
				delay(10);
				drawcross1(90,295,5,2,RED);
			
				*num = 4;
			}
			return 1;

		}
		else if (mouse_press(85, 293, 95, 297) == 1)
		{
			MouseS = 1;
			clrmous(MouseX, MouseY);
			delay(10);
			drawcross1(90,295,5,2,RED);
			changecontrol(player,1);
			return 1;
		}
	}
	if (MouseX > 245 && MouseX < 255 && MouseY > 293 && MouseY < 297)//小按钮 
	{
		if (mouse_press(245, 293, 255, 297) == 2)
		{
			MouseS = 1;
			if (*num == 0)//防止被重复标亮
			{
				clrmous(MouseX, MouseY);
				delay(10);
				drawcross(250,295,5,2,RED);
				*num = 4;
			}
			return 1;

		}
		else if (mouse_press(245, 293, 255, 297) == 1)
		{
			MouseS = 1;
			clrmous(MouseX, MouseY);
			delay(10);
			drawcross(250,295,5,2,RED);
			changecontrol(player,2);
			return 1;
		}
	}
	if (MouseX > 385 && MouseX < 395 && MouseY > 193 && MouseY < 197)//小按钮 
	{
		if (mouse_press(385, 193, 395, 197) == 2)
		{
			MouseS = 1;
			if (*num == 0)//防止被重复标亮
			{
				clrmous(MouseX, MouseY);
				delay(10);
				drawcross1(390,195,5,2,RED);
				*num = 4;
			}
			return 1;

		}
		else if (mouse_press(385, 193, 395, 197) == 1)
		{
			MouseS = 1;
			clrmous(MouseX, MouseY);
			delay(10);	
			drawcross1(390,195,5,2,RED);
			changepower(player,1);
			return 1;
		}
	}
	if (MouseX > 545 && MouseX < 555 && MouseY > 193 && MouseY < 197)//小按钮 
	{
		if (mouse_press(545, 193, 555, 197) == 2)
		{
			MouseS = 1;
			if (*num == 0)//防止被重复标亮
			{
				clrmous(MouseX, MouseY);
				delay(10);	
				drawcross(550,195,5,2,RED);
				*num = 4;
			}
			return 1;

		}
		else if (mouse_press(545, 193, 555, 197) == 1)
		{
			MouseS = 1;
			clrmous(MouseX, MouseY);
			delay(10);
			drawcross(550,195,5,2,RED);
			changepower(player,2);
			return 1;
		}
	}	
	if (MouseX > 385 && MouseX < 395 && MouseY > 293 && MouseY < 297)//小按钮 
	{
		if (mouse_press(385, 293, 395, 297) == 2)
		{
			MouseS = 1;
			if (*num == 0)//防止被重复标亮
			{
				clrmous(MouseX, MouseY);
				delay(10);
				drawcross1(390,295,5,2,RED);
				*num = 4;
			}
			return 1;

		}
		else if (mouse_press(385, 293, 395, 297) == 1)
		{
			MouseS = 1;
			clrmous(MouseX, MouseY);
			delay(10);
			drawcross1(390,295,5,2,RED);
			changedefend(player,1);
			return 1;
		}
	}
	if (MouseX > 545 && MouseX < 555 && MouseY > 293 && MouseY < 297)//小按钮 
	{
		if (mouse_press(545, 293, 555, 297) == 2)
		{
			MouseS = 1;
			if (*num == 0)//防止被重复标亮
			{
				clrmous(MouseX, MouseY);
				delay(10);
				drawcross(550,295,5,2,RED);
				*num = 4;
			}
			return 1;

		}
		else if (mouse_press(545, 293, 555, 297) == 1)
		{
			MouseS = 1;
			clrmous(MouseX, MouseY);
			delay(10);
			drawcross(550,295,5,2,RED);
			changedefend(player,2);
			return 1;
		}
	}
	if (*num != 0)
	{
		MouseS = 0;
		if (*state == 0)
		{
			recoverbutton_P(1);//恢复按钮颜色
		}
		if (*num == 2 || *num == 3 )
		{
			recoverbutton_P(*num);
		}
		if(*num==4)
		{
			recovercross();
		}
		*num = 0;
	}
	if (MouseS != 0)
	{
		MouseS = 0;
	}
	return 1;
} 
void changemoney(int *delmoney,Player *player,int *pre_all)
{
	char string[6];
	int speed,control,power,defend;
	int temp=0;
	
	speed = atoi(player->speed);
	control = atoi(player->control);
	power = atoi(player->power);
	defend = atoi(player->defend);
	temp=speed+control+power+defend+player->all;
	if(*pre_all!=temp)
	{
		*delmoney=1000+(temp-20)*500;
		itoa(*delmoney,string,10);
		setfillstyle(1,WHITE);
		bar(485,110,500,130);
		settextstyle(0,0,1);
		outtextxy(485,115,string);
		*pre_all=temp;
	}
}

void lightbutton_P(int x, int y, int x1, int y1, int color1, int color2, int flag)
{
	clrmous(MouseX, MouseY);
	delay(10);
	setcolor(color1);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setfillstyle(1, color2);
	bar(x, y, x1, y1);
	rectangle(x, y, x1, y1);
	switch (flag)
	{
	case 1:
		break;
	case 2:
		puthz(155, 415, "确认", 32, 32, DARKGRAY);
		break;
	case 3:
		puthz(425, 415, "返回", 32, 32, DARKGRAY);
		break;
	/*case 4:
		puthz(230, 335, "注册", 16, 24, BLACK);
		break;
	case 5:
		puthz(160, 300, "忘记密码", 16, 16, RED);
		break;*/ 
	default:
		closegraph();
		printf("something runs wrong in lightbutton");
		exit(1);
	}
}
void recoverbutton_P(int status)
{
	clrmous(MouseX, MouseY);
	if (status == 1)
	{
		setfillstyle(SOLID_FILL, LIGHTGRAY);
		setcolor(BLACK);
		setlinestyle(SOLID_LINE, 0, 3);
	}
	else
	{
		setfillstyle(SOLID_FILL, CYAN);
		setlinestyle(SOLID_LINE, 0, 1);
		setcolor(BLACK);
	}
	switch (status)
	{
	case 1:
		bar(80, 60, 240, 80);
		break;
	case 2:
		bar(140, 410, 230, 460);
		puthz(155, 415, "确认", 32, 32, BLACK);
		break;
	case 3:
		bar(410, 410, 500, 460);
		puthz(425, 415, "返回", 32, 32, BLACK);
		break;
/*	case 5:
		setfillstyle(SOLID_FILL, DARKGRAY);
		bar(220, 330, 280, 360);
		//	rectangle(220, 330, 280, 360);
		puthz(230, 335, "注册", 16, 24, WHITE);
		break;
	case 6:
		puthz(160, 300, "忘记密码", 16, 16, BLACK);
		break;*/
	}
}
void inputadminP(char* id, int x1, int y1, int charnum, int color)
{
	int k = 0;
	int i = 0;
	char t;
	clrmous(MouseX, MouseY);
	setfillstyle(SOLID_FILL, color);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setcolor(BLACK);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	line(x1 + 10, y1 + 6, x1 + 10, y1 + 20);
	while(bioskey(1))
	{
		k = bioskey(0);//抵消之前的输入流 
	}
	while (1)
	{
	
		t = bioskey(0); 
		if (i < charnum)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' '
				&& t != 033)//Esc
			{
				if (t != '\b')
				{
					*(id + i) = t;
					*(id + i + 1) = '\0';
					bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 20); //遮蔽之前的标 
					outtextxy(x1 + 8 + i * 18, y1-1, id + i);//显示账户 
					i++;
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);
				}
				else if (t == '\b' && i > 0)//退格 
				{
					bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 20);//遮蔽标 
					bar(x1 - 10 + i * 18, y1 + 4, x1 + 7 + i * 18, y1 + 20);//退格删去最后一个字 
					i--;//??????
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);//光标 
					*(id + i) = '\0';
					*(id + i + 1) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 20);//退格 
				break;
			}
		}
		else if (i >= charnum)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' '
				&& t != 033)//Esc
			{
				if (t == '\b' && i > 0)//可退格 
				{
					bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 20);//遮蔽标
					bar(x1 - 10 + i * 18, y1 + 4, x1 + 7 + i * 18, y1 + 20);//退格删去最后一个字
					i--;
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);//光标 
					*(id + i) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 20);//遮蔽标 
				break;
			}
		}
	}
}
void drawC(int x,int y,int ratio,int color)
{	
	int d[20] = {7,0, 0, 8, 6, 15, 8, 12, 6, 28, 28, 28, 26, 12, 28, 15, 34, 8, 27,0};
	int i;
	for(i=0;i<=18;i+=2)
		d[i]=d[i]*ratio+x;
	for(i=1;i<=19;i+=2)
		d[i]=d[i]*ratio+y;	
	setfillstyle(1,color);
	setlinestyle(SOLID_LINE, 0, 3);	
	fillpoly(10, d);
	
}
void drawcross(int x,int y,int length,int high,int color)
{
	int x1,y1,x2,y2;
	int x3,y3,x4,y4;
	x1=x-length;
	x2=x+length;
	y1=y-high;
	y2=y+high;
	x3=x-high;
	y3=y-length;
	x4=x+high;
	y4=y+length;	
	setfillstyle(1,color);
	bar(x1,y1,x2,y2);
	bar(x3,y3,x4,y4);
} 
void drawcross1(int x,int y,int length,int high,int color)
{
	int x1,y1,x2,y2;
//	int x3,y3,x4,y4;
	x1=x-length;
	x2=x+length;
	y1=y-high;
	y2=y+high;
/*	x3=x-high;
	y3=y-length;
	x4=x+high;
	y4=y+length;*/	
	setfillstyle(1,color);
	bar(x1,y1,x2,y2);
//	bar(x3,y3,x4,y4);
} 
void recovercross()
{
	clrmous(MouseX, MouseY);
	drawcross1(400,70,5,2,BLUE);
	drawcross(550,70,5,2,BLUE);
	drawcross1(90,195,5,2,BLUE);
	drawcross(250,195,5,2,BLUE);
	
	drawcross1(90,295,5,2,BLUE);
	drawcross(250,295,5,2,BLUE);
	
	drawcross1(390,195,5,2,BLUE);
	drawcross(550,195,5,2,BLUE);
	
	drawcross1(390,295,5,2,BLUE);
	drawcross(550,295,5,2,BLUE);
}
void changeAll(Player *player,int flag)
{
	int speed,control,power,defend;
	speed = atoi(player->speed);
	control = atoi(player->control);
	power = atoi(player->power);
	defend = atoi(player->defend);
	if(speed!=0||control!=0||power!=0||defend!=0)
		return;
	delay(150);
	player->all = atoi(player->allA);
	if(flag==1&&player->all>=21)
		player->all--;
	if(flag==2&&player->all<=35)
		player->all++;
	itoa(player->all,player->allA,10);
	setfillstyle(1,WHITE);
	bar(460,40,500,55);
	settextstyle(0,0,2);
	outtextxy(460,40,player->allA);
	changeAbar(player);
}
void changespeed(Player *player, int flag)
{
	int speed;
	delay(150);
	speed = atoi(player->speed);
	if(flag==1&&speed>=1)
	{
		speed--;
		player->all++;
		itoa(player->all,player->allA,10);
		setfillstyle(1,WHITE);
		bar(460,40,500,55);
		settextstyle(0,0,2);
		outtextxy(460,40,player->allA);
	}	
	if(flag==2&&speed<=8&&player->all>0)
	{
		speed++;
		player->all--;
		itoa(player->all,player->allA,10);
		setfillstyle(1,WHITE);
		bar(460,40,500,55);
		settextstyle(0,0,2);
		outtextxy(460,40,player->allA);
	}
	itoa(speed,player->speed,10);
	setfillstyle(1,WHITE);
	bar(165,220,190,245);
	settextstyle(0,0,2);
	outtextxy(165,220,player->speed);
	setfillstyle(1,LIGHTGRAY);
	bar(100, 180, 240, 210);
	setfillstyle(1,RED);
	bar(110, 185, 13*speed+110, 205);
	changeAbar(player);
}
void changecontrol(Player *player, int flag)
{
	int control;
	delay(150);
	control = atoi(player->control);
	if(flag==1&&control>=1)
	{	
		control--;
		player->all++;
		itoa(player->all,player->allA,10);
		setfillstyle(1,WHITE);
		bar(460,40,500,55);
		settextstyle(0,0,2);
		outtextxy(460,40,player->allA);
	} 
		
	if(flag==2&&control<=8&&player->all>0)
	{
		control++;
		player->all--;
		itoa(player->all,player->allA,10);
		setfillstyle(1,WHITE);
		bar(460,40,500,55);
		settextstyle(0,0,2);
		outtextxy(460,40,player->allA);
	}
		
	itoa(control,player->control,10);
	setfillstyle(1,WHITE);
	bar(165,320,190,345);
	settextstyle(0,0,2);
	outtextxy(165,320,player->control);
	setfillstyle(1,LIGHTGRAY);
	bar(100, 280, 240, 310);
	setfillstyle(1,RED);
	bar(110, 285, 13*control+110, 305);
	changeAbar(player);
}
void changepower(Player *player, int flag)
{
	int power;
	delay(150);
	power = atoi(player->power);
	if(flag==1&&power>=1)
	{
		power--;
		player->all++;
		itoa(player->all,player->allA,10);
		setfillstyle(1,WHITE);
		bar(460,40,500,55);
		settextstyle(0,0,2);
		outtextxy(460,40,player->allA);
	} 
		
	if(flag==2&&power<=8&&player->all>0)
	{
		power++;
		player->all--;
		itoa(player->all,player->allA,10);
		setfillstyle(1,WHITE);
		bar(460,40,500,55);
		settextstyle(0,0,2);
		outtextxy(460,40,player->allA);
	}
		
	itoa(power,player->power,10);
	setfillstyle(1,WHITE);
	bar(465,220,490,245);
	settextstyle(0,0,2);
	outtextxy(465,220,player->power);
	setfillstyle(1,LIGHTGRAY);
	bar(400, 180, 540, 210);
	setfillstyle(1,RED);
	bar(410, 185, 13*power+410, 205);
	changeAbar(player);
}
void changedefend(Player *player, int flag)
{
	int defend;
	delay(150);
	defend = atoi(player->defend);
	if(flag==1&&defend>=1)
	{
		defend--;
		player->all++;
		itoa(player->all,player->allA,10);
		setfillstyle(1,WHITE);
		bar(460,40,500,55);
		settextstyle(0,0,2);
		outtextxy(460,40,player->allA);
	} 
	if(flag==2&&defend<=8&&player->all>0)
	{
		defend++;
		player->all--;
		itoa(player->all,player->allA,10);
		setfillstyle(1,WHITE);
		bar(460,40,500,55);
		settextstyle(0,0,2);
		outtextxy(460,40,player->allA);
	}
		
	itoa(defend,player->defend,10);
	setfillstyle(1,WHITE);
	bar(465,320,490,345);
	settextstyle(0,0,2);
	outtextxy(465,320,player->defend);
	setfillstyle(1,LIGHTGRAY);
	bar(400, 280, 540, 310);
	setfillstyle(1,RED);
	bar(410, 285, 13*defend+410, 305);
	changeAbar(player);
}
void changeAbar(Player *player)
{
	float length; 
	setfillstyle(1, YELLOW);
	bar(407, 57, 543, 83);
	length = (539.0-410.0)/(player->all+player->speed[0]+player->defend[0]+player->control[0]+player->power[0]-4*'0');
	setfillstyle(1, RED);
	bar(410, 60, (int)(length * player->all + 410), 80);
}
void randPnum(Player *player)
{
	setcolor(BLACK);
	srand((unsigned)time(NULL));
	player->player_num[0] = rand()%10+'0';
	player->player_num[1] = rand()%10+'0';
	player->player_num[2] = '\0';
	settextstyle(0, 0, 2);
	outtextxy(307,43,player->player_num);
}
int creat_complete(Player *player,int *delmoney,USER *u)
{
	if(strlen(player->name)==0)
		Pwarning(1);
	else if(player->all != 0)
		Pwarning(2);
	else if(strlen(player->name)!=3)
		Pwarning(3);
	else if(delmoney>u->money)
		Pwarning(4);
	else
		return 1;
	return 0;
} 
void input_pinfo(Player *player,USER *u,int *delmoney)
{
	FILE *fp;
	USER *us;
	int len;
	int i;
	char path[50]="Database\\USER\\";
	int money=0;
	
	money=atoi(u->money);
	money-=*delmoney;
	itoa(money,u->money,10);
	strcat(path,u->user);
	strcat(path,"\\selfp.dat");
	if ((fp = fopen(path, "rb+" )) == NULL)
	{
		printf("cannot open file selfp.dat");
		delay(3000);
		exit(1);
	}
	fseek(fp, 0, SEEK_END);
	fwrite(player, sizeof(Player), 1, fp);
	if (fclose(fp) != 0)
	{
		printf("\n cannot close Database.");
		delay(3000);
		exit(1);
	}
	if ((fp = fopen("database\\UserData.dat", "rb+" )) == NULL)
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
			Pwarning(5);
		}
		if (u != NULL)
		{
			free(u);
			u = NULL;
		}

	}
} 
void Pwarning(int flag)
{	
	setfillstyle(1, BLACK);
	bar(158, 118, 482, 282);
	setfillstyle(1, LIGHTGRAY);
	bar(160, 120, 480, 280);
	if(flag==1)
	{
		puthz(170,130,"名字未输入！",24,24,BLACK);
		puthz(170,250,"三秒后继续",24,24,BLACK);
	}
	if(flag==2)
	{
		puthz(170,130,"能力未分配完！",24,24,BLACK);
		puthz(170,250,"三秒后继续",24,24,BLACK);
	}
	if(flag==3)
	{
		puthz(170,130,"名字应输入三个",24,24,BLACK);
		puthz(170,250,"三秒后继续",24,24,BLACK);
	}
	if(flag==4)
	{
		puthz(170,130,"金币不足",24,24,BLACK);
		puthz(170,250,"三秒后继续",24,24,BLACK);
	}
	if(flag==5)
	{
		puthz(170,130,"完成！",24,24,BLACK);
		puthz(170,250,"三秒后继续",24,24,BLACK);
	}
	delay(3000);
		return ;
}
