#include"common.h"
#include"register.h"
#include"signin.h"
#include"SIfunc.h"
int registerup()
{
	int condition = 1;
	int num = 0;
	char str[6] = { '\0' };
	char U[15] = { '\0' };//6-12位，用户名
	char I[20] = { '\0' };//18位，手机 
	char P[20] = { '\0' };//8-16位，密码
	char CP[20] = { '\0' };//8-16位，确认密码
	char VC[6] = { '\0' };//5位，验证码

	int state1 = 0;       //内容输入判断参数
	int state2 = 0;
	int state3 = 0;
	int state4 = 0;
	int state5 = 0;
	
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	draw_rg(str);
	setcolor(BLACK);
	settextstyle(0, 0, 3);
	outtextxy(280, 30, "FIFA");
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	while (condition == 1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (MouseX > 95 && MouseX < 545 && MouseY>85 && MouseY < 110)
		{
			if (mouse_press(95, 85, 545, 110) == 2)           //未点击账号框
			{
				MouseS = 2;
				if (num == 0 && state1 == 0)                  //num = 0防止重复标亮
				{
					lightbutton_register(95, 85, 545, 110, BLACK, WHITE, 1);
					num = 1;
				}
				continue;
			}

			else if (mouse_press(95, 85, 545, 110) == 1)      //点击账号框
			{
				MouseS = 0;
				lightbutton_register(95, 85, 545, 110, BLACK, WHITE, 1);
				U[0] = '\0';
				inputadmin(U, 95, 85, 12, WHITE);//后期输入函数
				if(strlen(U) != 0)
					state1 = 1;
				else
					state1 = 0;
				continue;
			}
		}
		if (MouseX > 95 && MouseX < 545 && MouseY>145 && MouseY < 170)
		{
			if (mouse_press(95, 145, 545, 170) == 2)     //未点击密码框
			{
				MouseS = 2;
				if (num == 0 && state2 == 0)
				{
					lightbutton_register(95, 145, 545, 170, BLACK, WHITE, 2);
					num = 2;
				}
				continue;
			}

			else if (mouse_press(95, 145, 545, 170) == 1)     //点击密码框
			{
				lightbutton_register(95, 145, 545, 170, BLACK, WHITE, 2);
				MouseS = 0;
				P[0] = '\0';
				inputpassword(P, 95, 145, 16, WHITE);//输入函数
				if(strlen(P) != 0)
					state2 = 1;
				else
					state2 = 0;
				continue;
			}
		}

		if (MouseX > 95 && MouseX < 545 && MouseY>205 && MouseY < 230)
		{
			if (mouse_press(95, 205, 545, 230) == 2)     //未点击确认密码框
			{
				MouseS = 2;
				if (num == 0 && state3 == 0)
				{
					lightbutton_register(95, 205, 545, 230, BLACK, WHITE, 3);
					num = 3;
				}
				continue;
			}

			else if (mouse_press(95, 205, 545, 230) == 1)      //点击确认密码框
			{
				lightbutton_register(95, 205, 545, 230, BLACK, WHITE, 3);
				MouseS = 0;
				CP[0] ='\0';
				inputpassword(CP, 95, 205, 16, WHITE);
				//输入函数
				if(strlen(CP) != 0)
					state3 = 1;
				else
					state3 = 0;
				continue;
			}
		}

		if (MouseX > 95 && MouseX < 545 && MouseY>260 && MouseY < 290)
		{
			if (mouse_press(95, 265, 545, 290) == 2)      //未点击手机框
			{
				MouseS = 2;
				if (num == 0 && state4 == 0)
				{
					lightbutton_register(95, 265, 545, 290, BLACK, WHITE, 4);
					num = 4;
				}
				continue;
			}

			else if (mouse_press(95, 265, 545, 290) == 1)
			{
				lightbutton_register(95, 265, 545, 290, BLACK, WHITE, 4);
				MouseS = 0;
				I[0] = '\0';
				inputadmin(I, 95, 265, 18, WHITE);
				//输入函数
				if(strlen(I) != 0)
					state4 = 1;
				else 
					state4 = 0;
				continue;
			}
		}

		if (mouse_press(95, 325, 175, 350) == 1)
		{
			clrmous(MouseX, MouseY);
			delay(10);
			setfillstyle(1, WHITE);
			bar(95, 325, 173, 350);
			random_str(str);
			setcolor(BLUE);
			settextjustify(LEFT_TEXT, TOP_TEXT);
			settextstyle(1, HORIZ_DIR, 3);
			outtextxy(97, 322, str);
			continue;
		}

		if (MouseX > 175 && MouseX < 545 && MouseY>325 && MouseY < 350)
		{
			MouseS = 2;
			if (mouse_press(175, 325, 545, 350) == 2)            //未点击验证码输入框
			{
				if (num == 0 && state5 == 0)
				{
					lightbutton_register(175, 325, 545, 350, BLACK, WHITE, 5);
					num = 5;
				}
				continue;
			}

			else if (mouse_press(175, 325, 545, 350) == 1)
			{
				lightbutton_register(175, 325, 545, 350, BLACK, WHITE, 5);
				MouseS = 0;
				VC[0] = '\0';
				inputadmin(VC, 175, 325, 5, WHITE);
				//输入函数
				if(strlen(VC) != 0)
					state5 = 1;
				else 
					state5 = 0;
				continue;
			}
		}

	/*	if (MouseX > 143 && MouseX < 237 && MouseY>370 && MouseY < 400)
		{
			if (mouse_press(143, 370, 237, 400) == 2)                //未点击重置框
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_register(143, 370, 237, 400, WHITE, CYAN, 6);
					num = 6;
				}
				continue;
			}

			else if (mouse_press(143, 370, 237, 400) == 1)
			{
				MouseS = 0;
				cleardevice();
				draw_signin(str);
				num = 0;
				state1 = 0;
				state2 = 0;
				state3 = 0;
				state4 = 0;
				state5 = 0;
				U[0] = '\0';
				I[0] = '\0';
				P[0] = '\0';
				CP[0] = '\0';
				VC[0] = '\0';
				//重置
				continue;
			}
		}*/

		if (MouseX > 203 && MouseX < 297 && MouseY>370 && MouseY < 400)
		{
			if (mouse_press(203, 370, 297, 400) == 2)					//未点击注册框
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_register(203, 370, 297, 400, WHITE, RED, 7);
					num = 7;
				}
				continue;
			}

			else if (mouse_press(203, 370, 297, 400) == 1)
			{
				MouseS = 0;
				if (register_complete(U, P, CP, I, VC, str))
				{
					condition=0;
					break;
				}
				else
				{
					continue;
				}
				//注册判断
			}
		}

		if (MouseX > 343 && MouseX < 437 && MouseY>370 && MouseY < 400)
		{
			if (mouse_press(343, 370, 437, 400) == 2)				//未点击返回框
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_register(343, 370, 437, 400, WHITE, RED, 8);
					num = 8;
				}
				continue;
			}

			else if (mouse_press(343, 370, 437, 400) == 1)
			{
				MouseS = 0;
				condition=0;
				break;
			}
		}

		if (num != 0)
		{
			MouseS = 0;
			if (state1 == 0)
			{
				recoverbutton_register(1);
			}
			if (state2 == 0)
			{
				recoverbutton_register(2);
			}
			if (state3 == 0)
			{
				recoverbutton_register(3);
			}
			if (state4 == 0)
			{
				recoverbutton_register(4);
			}
			if (state5 == 0)
			{
				recoverbutton_register(5);
			}
			if (num == 6 || num == 7 || num == 8)
			{
				recoverbutton_register(num);
			}
			num = 0;
		}
		if (MouseS != 0)
		{
			MouseS = 0;
		}
	}
	if (condition == 0)
		return 0;
}

void draw_rg(char *str)
{
	setfillstyle(1, LIGHTGRAY);
	bar(0,0,640,480);
	setfillstyle(1, WHITE);
	
	puthz(95, 60, "账号", 16, 17, BLACK);
	bar(95, 85, 545, 110);
	//rectangle(95,85,545,110);

	puthz(95, 120, "密码", 16, 17, BLACK);
	bar(95, 145, 545, 170);
	//rectangle(95,145,545,170);

	puthz(95, 180, "确认密码", 16, 17, BLACK);
	bar(95, 205, 545, 230);
	//rectangle(95,205,545,230);

	puthz(95, 240, "手机号码", 16, 17, BLACK);
	bar(95, 265, 545, 290);
	//rectangle(95,265,545,290);

	setlinestyle(SOLID_LINE, 0, 3);
	setcolor(BLACK);
	setfillstyle(1, WHITE);
	puthz(95, 300, "验证码", 16, 17, BLACK);
	bar(95, 325, 545, 350);
	rectangle(95, 325, 175, 350);

	random_str(str);
	setcolor(BLUE);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	settextstyle(1, HORIZ_DIR, 3);
	outtextxy(100, 322, str);                      //验证码输出



	setfillstyle(1, RED);
	bar(203, 370, 297, 400);
	puthz(221, 373, "注册", 24, 34, WHITE);

	setfillstyle(1, RED);
	bar(343, 370, 437, 400);
	puthz(361, 373, "返回", 24, 34, WHITE);
}

void random_str(char* str)
{
	char a, j, i;
	srand(time(NULL));
	for (i = 0; i < 5; i++)
	{
		j = rand() % 3;
		if (j == 0)
		{
			a = rand() % 26 + 65;
			str[i] = a;
		}
		else if (j == 1)
		{
			a = rand() % 26 + 97;
			str[i] = a;
		}
		else
		{
			a = rand() % 10 + 48;
			str[i] = a;
		}
	}
	str[5] = '\0';
}

void lightbutton_register(int x, int y, int x1, int y1, int color1, int color2, int flag)
{
	clrmous(MouseX, MouseY);
	delay(10);
	setcolor(color1);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setfillstyle(1, color2);
	bar(x, y, x1, y1);
	rectangle(x, y, x1, y1);	//画边框

/*	if (flag == 6)
	{
		puthz(161, 373, "重置", 24, 34, LIGHTCYAN);
	}*/
	if (flag == 7)
	{
		puthz(221, 373, "注册", 24, 34, LIGHTRED);
	}
	else if (flag == 8)
	{
		puthz(361, 373, "返回", 24, 34, LIGHTRED);
	}
}

void recoverbutton_register(int status)
{
	clrmous(MouseX, MouseY);
	setfillstyle(1, WHITE);
	switch (status)
	{
	case 1:
		bar(95, 85, 545, 110);
		break;
	case 2:
		bar(95, 145, 545, 170);
		break;
	case 3:
		bar(95, 205, 545, 230);
		break;
	case 4:
		bar(95, 265, 545, 290);
		break;
	case 5:
		bar(175, 325, 545, 350);
		break;
/*	case 6:
		setfillstyle(1, CYAN);
		bar(143, 370, 237, 400);
		puthz(161, 373, "重置", 24, 34, WHITE);
		break;*/
	case 7:
		setfillstyle(1, RED);
		bar(203, 370, 297, 400);
		puthz(221, 373, "注册", 24, 34, WHITE);
		break;
	case 8:
		setfillstyle(1, RED);
		bar(343, 370, 437, 400);
		puthz(361, 373, "返回", 24, 34, WHITE);
		break;
	}
}
