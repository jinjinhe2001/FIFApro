#include"common.h"
#include"database.h"
#include"SIfunc.h"


void inputadmin(char* id, int x1, int y1, int charnum, int color)	//x1,y1分别是账号，验证码等输入信息的左端点和上端点 
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
					i--;//??????
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

void inputpassword(char* id, int x1, int y1, int charnum, int color)//x1,y1分别是密码等隐藏信息输入的左端点和上端点
{
	int k = 0;
	int i = 0;
	char t;
	setfillstyle(SOLID_FILL, color);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setcolor(BLACK);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	line(x1 + 10, y1 + 6, x1 + 10, y1 + 20);
	while(bioskey(1))
	{
		k = bioskey(0);//?
	}
	while (1)
	{
		t = bioskey(0);//????
		if (i < charnum)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' '
				&& t != 033)//ESC 
			{
				if (t != '\b')
				{
					*(id + i) = t;
					*(id + i + 1) = '\0';
					bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 20);//遮蔽
					outtextxy(x1 + 8 + i * 18, y1 + 4, "*");//输出* 
					i++;
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);
				}
				else if (t == '\b' && i > 0)//退格 
				{
					bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 20);//遮蔽标 
					bar(x1 - 10 + i * 18, y1 + 4, x1 + 7 + i * 18, y1 + 20);//遮蔽* 
					i--;
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);//光标
					*(id + i) = '\0';
					*(id + i + 1) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 20);//遮蔽光标 
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
				if (t == '\b' && i > 0)
				{
					bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 20);
					bar(x1 - 10 + i * 18, y1 + 4, x1 + 7 + i * 18, y1 + 20);
					i--;
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);
					*(id + i) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 20);
				break;
			}
		}
	}
}

int forgetpass_complete(char* u, char* id, char* np, char* cp)
{
	int st1 = 1;//用户名是否输入的变量
	int st2 = 1;//身份证是否输入的变量
	int st3 = 1;//新密码是否输入的变量
	int st4 = 1;//确认密码是否输入的变量
	int state1 = 1;//身份证输入格式是否正确的变量
	int state2 = 1;//密码输入格式是否正确的变量
	int state3 = 1;//确认密码是否一致的变量
	while (1)
	{
		recoverhz(95 + 452, 138, WHITE);//遮盖汉字
		recoverhz(95 + 452, 218, WHITE);
		recoverhz(95 + 452, 298, WHITE);
		recoverhz(95 + 452, 348 + 30, WHITE);
		judge(u, &st1, 95 + 452, 140); //判断是否输入,未输入会=1
		judge(id, &st2, 95 + 452, 220);
		judge(np, &st3, 95 + 452, 300);
		judge(cp, &st4, 95 + 452, 380);
		if (st1 == 1 || st2 == 1 || st3 == 1 || st4 == 1)
		{
			break;
		}
		else if (st1 == 0 && st2 == 0 && st3 == 0 && st4 == 0)
		{
			if (judge_sameuser(u,2))//用户名不存在
			{
				puthz(95 + 450, 140, "用户不存在", 16, 17, RED);
				state1 = checkright_ID(id, 95 + 452, 220, 2);//判断各项格式是否正确
				state2 = checkright_password(np, 95 + 452, 300);
				state3 = checkright_confirmedpassword(np, cp, 95 + 452, 380);
				break;
			}
			else if (!judge_sameuser(u,2))//用户名存在
			{
				state1 = checkright_ID(id, 95 + 452, 220, 2);
				state2 = checkright_password(np, 95 + 452, 300);
				state3 = checkright_confirmedpassword(np, cp, 95 + 452, 380);
				if (state1 != 0 || state2 != 0 || state3 != 0)
				{
					break;
				}	
				else if (state1 == 0 && state2 == 0 && state3 == 0)
				{
					if (name_id(u, id, np, cp))//写入数据库
					{
						return 1;//返回登录界面
					}
					else
					{
						break;
					}
				}
			}
		}
	}
	return 0;
}

int name_id(char* name, char* id, char* pass, char* againpass)
{
	int str;
	int len;
	int i,j;
	FILE* fp;
	USER* u = NULL;
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
		if ((u = (USER*)malloc(sizeof(USER))) == NULL)
		{
			printf("memoryallocation runs wrong in lgfunc.c");
			delay(3000);
			exit(1);
		}
		fseek(fp, i * sizeof(USER), SEEK_SET);//每次往后移一个用户
		fread(u, sizeof(USER), 1, fp);//将信息读入u
		if (strcmp(name, u->user) == 0)
		{
			if (strcmp(id, u->phonenum) != 0)
			{
				recoverhz(95 + 452, 220, WHITE);
				puthz(95 + 452, 220, "手机不匹配", 16, 17, RED);
				break;
			}
			else if (strcmp(id, u->phonenum) == 0)
			{
				setcolor(BLUE);
				setlinestyle(SOLID_LINE, 0, 3);
				line(550, 228, 560, 238);
				line(560, 238, 570, 218);
				if (strcmp(pass, againpass) == 0)//两次输入密码相同
				{
					u->password[0] = '\0';
					/*for (j = 0; j < 16; j++)
					{
						if (pass[j] == '\0')
						{
							str = j + 1;
							break;
						}
					}
					for (j = 0; j < str; j++)
					{
						u->password[j] = pass[j];
					}
					for (j = str; j < 16; j++)
					{
						u->password[j] = '\0';
					}*/
					strcpy(u->password, pass);
					fseek(fp, i * sizeof(USER), SEEK_SET);
					fwrite(u, sizeof(USER), 1, fp);//修改完后一定要记得写入数据
					puthz(150, 480 - 10 - 60, "密码修改成功", 16, 17, RED);
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
					delay(2000);
					return 1;
				}
			}
		}
		if (u != NULL)
		{
			free(u);
			u = NULL;
		}

	}
}

int login_complete(char* u, char* p)//用来判断登录信息是否输入完全和正确
{
	int state1 = 1;//是否输入的变量
	int state2 = 1;
	while (1)
	{
		recoverhz1(230, 150, WHITE);
		recoverhz1(250, 150, WHITE);
		recoverhz1(250, 210, WHITE);
		judge(u, &state1, 240, 160);
		judge(p, &state2, 240, 220);
		if (state1 == 1 || state2 == 1)
		{
			break;
		}
		else if (state1 == 0 && state2 == 0)
		{
			if (judge_rightpassword(u, p))
			{
				return 1;
			}
			else
			{
				break;
			}
		}
	}
	return 0;
} 

int register_complete(char* u, char* p, char* cp, char* id, char* vc,char* rdvc)//rdvc?randomvc
{
	int i;
	int state = 0;
	int state1 = 1;
	int state2 = 1;
	int state3 = 1;
	int state4 = 1;
	int state5 = 1;
	while (1)
	{
		recoverhz(547, 80, LIGHTGRAY);
		recoverhz(547, 140, LIGHTGRAY);
		recoverhz(547, 200, LIGHTGRAY);
		recoverhz(547, 260, LIGHTGRAY);
		recoverhz(547, 320, LIGHTGRAY);
		recoverhz(130, 53, LIGHTGRAY);
		recoverhz(280, 420, LIGHTGRAY);
		judge(u, &state, 547, 90);         
		judge(p, &state, 547, 150); 
		judge(cp, &state, 547, 210);
		judge(id, &state, 547, 270);
		judge(vc, &state, 547, 330);
		if (state == 1)
		{
			break;
		}
		else if (state == 0)
		{
			if (!judge_sameuser(u,1))         
			{
				state1 = checkright_user(u, 547, 90);
				state2 = checkright_password(p, 547, 150);
				state3 = checkright_confirmedpassword(p, cp, 547, 210);
				state4 = checkright_ID(id, 547, 270, 1);
				state5 = checkright_verificationcode(rdvc, vc, 547, 330);
				break;
			}
			else if(judge_sameuser(u,2))//
			{
				puthz(135, 60, "可用的用户名", 16, 17, RED);
				state1 = checkright_user(u, 547, 90);
				state2 = checkright_password(p, 547, 150);
				state3 = checkright_confirmedpassword(p, cp, 547, 210);
				state4 = checkright_ID(id, 547, 270, 1);
				state5 = checkright_verificationcode(rdvc, vc, 547, 330);
				if (state1 != 0 || state2 != 0 || state3 != 0 || state4 != 0 || state5 != 0)
				{
					break;
				}
				else if (state1 == 0 && state2 == 0 && state3 == 0 && state4 == 0 && state5 == 0)
				{
					input_database(u, id, p);
					puthz(280,420, "注册成功", 16, 17, RED);
					delay(2000);
					return 1;
				}
			}
		}
	}
	return 0;
}


void judge(char* str, int* p, int x, int y)
{
	if (strlen(str) == 0)
	{
		*p = 1;
		puthz(x, y, "未输入", 16, 17, RED);
	}
	else
	{
		*p = 0;
	}
}

void recoverhz1(int x, int y,int color)
{
	setfillstyle(SOLID_FILL,color);
	bar(x, y, x + 70, y + 20);
}

void recoverhz(int x, int y,int color)
{
	setfillstyle(SOLID_FILL,color);
	bar(x, y, x + 100, y + 30);
}

int judge_rightpassword(char* name, char* pass)	
{
	int len;
	int i;
	FILE* fp;
	USER* u;
	if ((fp = fopen("database\\UserData.dat", "rb+")) == NULL)
	{
		printf("cannot open file UserData.dat");
		delay(3000);
		exit(1);
	}
	fseek(fp, 0, SEEK_END);
	len = ftell(fp) / sizeof(USER);
	for (i = 0; i < len; i++)
	{
		if ((u = (USER*)malloc(sizeof(USER))) == NULL)
		{
			printf("memoryallocation runs wrong in lgfunc.c");
			delay(3000);
			exit(1);
		}
		fseek(fp, i * sizeof(USER), SEEK_SET);
		fread(u, sizeof(USER), 1, fp);
		if (strcmp(name, u->user) == 0)//用户名匹配
		{
			if (strcmp(pass, u->password) != 0)//密码不配
			{
				puthz(250, 210, "密码错误", 16, 17, RED);
				if (u != NULL)
				{
					free(u);
					u = NULL;
				}
				break;
			}
			else if (strcmp(pass, u->password) == 0)//密码匹配
			{
				puthz(155, 280, "登录成功", 16, 17, RED);
				if (u != NULL)
				{
					free(u);
					u = NULL;
				}
				delay(1000);
				if (fclose(fp) != 0)
				{
					printf("\n cannot close Database");
					delay(3000);
					exit(1);
				}
				return 1;
				//切换界面
			}
		}
		if (u != NULL)
		{
			free(u);
			u = NULL;
		}
	}
	if (i == len)
	{
		puthz(230, 150, "账户未注册", 16, 17, RED);//走到最后一位
	}

	if (u != NULL)
	{
		free(u);
		u = NULL;
	}

	if (fclose(fp) != 0)
	{
		printf("\n cannot close Database");
		delay(3000);
		exit(1);
	}
	return 0;
}
int input_uinfo(USER* us)
{
	int i;
	int len;
	FILE* fp;
	USER* u = NULL;
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
		if ((u = (USER*)malloc(sizeof(USER))) == NULL)
		{
			printf("memoryallocation runs wrong in lgfunc.c");
			delay(3000);
			exit(1);
		}
		fseek(fp, i * sizeof(USER), SEEK_SET);//每次往后移一个用户
		fread(u, sizeof(USER), 1, fp);		  //将信息读入u
		if (strcmp(us->user, u->user) == 0)
		{
		//	memset(us,'\0',sizeof(USER));              //先重置
			strcpy(us->user,u->user); 
			strcpy(us->password,u->password); 
			strcpy(us->phonenum,u->phonenum); 
			strcpy(us->money,u->money);
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
			delay(2000);
			return 1;
		}
		if (u != NULL)
		{
			free(u);
			u = NULL;
		}
	}
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
	return 0;
}

/*********************************************
FUNCTION:input_database
DESCRIPTION：把用户注册信息写入文件
INPUT:name,id,code,bank,bankcode
RETURN:1/0
***********************************************/
void input_database(char* name, char* ph, char* code)
{
	FILE* fp,* fp1,* fp2;
	USER* u;
	char n;
	char *money="15000";
	char *path,*pathn="Database\\USER\\";
	char path1[50],path2[50];
	path = (char *)malloc(50*sizeof(char));
	strcpy(path1,"Database\\USER\\");
	strcpy(path2,"Database\\USER\\");
	if ((fp = fopen("database\\UserData.dat", "rb+" )) == NULL)//写入 
	{
		printf("cannot open file UserData.dat");
		delay(3000);
		exit(1);
	}
	if ((u = (USER*)malloc(sizeof(USER))) == NULL)
	{
		printf("memoryallocation runs wrong in SIfunc.c");
		delay(3000);
		exit(1);
	}
	memset(u,'\0',sizeof(USER));
	strcpy(u->user, name);
	strcpy(u->phonenum, ph);
	strcpy(u->password, code);
	strcpy(u->money,money);
	fseek(fp, 0, SEEK_END);//跳转至文件末尾
	fwrite(u, sizeof(USER), 1, fp);//把用户信息写入文件 余额默认为0
	path = strcat(pathn,name);
	mkdir(path);
	strcat(path1,name);
	strcat(path2,name);
	strcat(path1,"\\");
	strcat(path2,"\\");
	strcat(path1,"selfp.dat");
	strcat(path2,"selft.dat");
	if ((fp1 = fopen(path1, "wb+" )) == NULL)//建立数据库
	{
		printf("cannot build file selfp.dat");
		delay(3000);
		exit(1);
	}
	if ((fp2 = fopen(path2, "wb+" )) == NULL)//建立数据库
	{
		printf("cannot build file selft.dat");
		delay(3000);
		exit(1);
	}
	if (u != NULL)
	{
		free(u);
		u = NULL;
	}
	if (fclose(fp) != 0)
	{
		printf("\n cannot close Database.");
		delay(3000);
		exit(1);
	}
	if (fclose(fp1) != 0)
	{
		printf("\n cannot close Database.");
		delay(3000);
		exit(1);
	}
	if (fclose(fp2) != 0)
	{
		printf("\n cannot close Database.");
		delay(3000);
		exit(1);
	}
	free(path);
	free(path1);
	free(path2);
}

/*********************************************
FUNCTION:judge_sameuser
DESCRIPTION：判断账户是否出现重名,
	flag为1判断是否注册，
	flag为2判断找回密码中是否存在
INPUT:new_user,flag
RETURN:1/0
***********************************************/
int judge_sameuser(char* new_user,int flag)
{
	int len;
	int i;
	FILE* fp;
	USER* u = NULL;
	if ((fp = fopen("database\\UserData.dat", "rb+")) == NULL)//建立数据库
	{
		printf("cannot open file UserData.dat");
		delay(3000);
		exit(1);
	}
	fseek(fp, 0, SEEK_END);
	len = ftell(fp) / sizeof(USER);
	for (i = 0; i < len; i++)
	{
		if ((u = (USER*)malloc(sizeof(USER))) == NULL)
		{
			printf("memoryallocation runs wrong in lgfunc.c");
			delay(3000);
			exit(1);
		}
		fseek(fp, i * sizeof(USER), SEEK_SET);
		fread(u, sizeof(USER), 1, fp);
		if (strcmp(u->user, new_user) == 0)
		{
			switch (flag)
			{
			case 1: 
				puthz(135, 60, "用户已被注册", 16, 17, RED);
				break;
			case 2:
				puthz(450, 110, "账号存在", 16, 17, RED);
				break;
			default:
				printf("something wrong");
				delay(3000);
				exit(1);
			}
			if (u != NULL)
			{
				free(u);
				u = NULL;
			}
			if (fclose(fp) != 0)
			{
				printf("\n cannot close Database.");
				delay(3000);
				exit(1);
			}
			return 0;
		}
		free(u);
		u = NULL;
	}
	if (u != NULL)
	{
		free(u);
		u = NULL;
	}

	if (fclose(fp) != 0)
	{
		printf("\n cannot close Database.");
		delay(3000);
		exit(1);
	}
	return 1;
}

/*********************************************
FUNCTION:checkright_user
DESCRIPTION：检查账户是否大于6位
INPUT:str,x,y
RETURN:1/0
***********************************************/
int checkright_user(char* str, int x, int y)
{
	if (strlen(str) < 6 /*小于6位*/)
	{
		puthz(x, y, "账户应", 16, 17, RED);
		setcolor(RED);
		settextjustify(LEFT_TEXT, TOP_TEXT);
		settextstyle(1, HORIZ_DIR, 2);
		outtextxy(x + 53, y - 5, ">6");
		return 1;
	}
	else if(strlen(str)>=6&&strlen(str)<=12)
	{
		setcolor(BLUE);
		setlinestyle(SOLID_LINE, 0, 3);
		//line(550, 98, 560, 108); 
		//line(560, 108, 570, 88); 
		line(x + 3, y + 8, x + 13, y + 18);
		line(x + 13, y + 18, x + 23, y - 2);
		return 0;
	}
	return 1;
}

/*********************************************
FUNCTION:checkright_password
DESCRIPTION：检查密码是否大于8位
INPUT:str,x,y
RETURN:1/0
***********************************************/
int checkright_password(char* str, int x, int y)
{
	if (strlen(str) < 8 )//小于8位
	{
		puthz(x, y, "密码应", 16, 17, RED);
		setcolor(RED);
		settextjustify(LEFT_TEXT, TOP_TEXT);
		settextstyle(1, HORIZ_DIR, 2);
		outtextxy(x + 53, y - 5, ">8");
		return 1;
	}
	else if (strlen(str) >= 8 && strlen(str) <= 16)
	{
		setcolor(BLUE);
		setlinestyle(SOLID_LINE, 0, 3);
		//line(550, 158, 560, 168);
		//line(560, 168, 570, 148);
		line(x + 3, y + 8, x + 13, y + 18);
		line(x + 13, y + 18, x + 23, y - 2);
		return 0;
	}
	return 1;
}

/*********************************************
FUNCTION:checkright_password
DESCRIPTION：检查确认密码是否一致
INPUT:str1,str2,x,y
RETURN:1/0
***********************************************/
int checkright_confirmedpassword(char* str1, char* str2, int x, int y)
{
	if (strcmp(str1, str2) != 0)
	{
		puthz(x, y, "两次不一致", 16, 17, RED);
		return 1;
	}
	else if (strcmp(str1, str2) == 0)
	{
		setcolor(BLUE);
		setlinestyle(SOLID_LINE, 0, 3);
		line(x + 3, y + 8, x + 13, y + 18);
		line(x + 13, y + 18, x + 23, y - 2);
		return 0;
	}
	return 1;
}

/*********************************************
FUNCTION:checkright_ID
DESCRIPTION：检查身份证位数与格式
INPUT:str,x,y,flag
RETURN:1/0
***********************************************/
int checkright_ID(char* str, int x, int y,int flag)
{
	int i;
	int state = 1;
	if (strlen(str) != 11)
	{
		puthz(x, y, "手机为", 16, 17, RED);
		setcolor(RED);
		settextjustify(LEFT_TEXT, TOP_TEXT);
		settextstyle(1, HORIZ_DIR, 2);
		outtextxy(x+50, y-5, "11");
		puthz(x + 73, y, "位", 16, 17, RED);//长度不符合
		return 1;
	}
	else if (strlen(str) == 11)
	{
		for (i = 0; i < 10; i++)
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				continue;
			}
			else
			{
				puthz(x, y, "格式不正确", 16, 17, RED);
				return 0;
			}
			
		}
		if ( str[10]>='0' && str[10]<='9')
		{
			state = 0;
		}
		else
		{
			puthz(x, y, "格式不正确", 16, 17, RED);
			return 1;
		}
	}
	if (state == 0)
	{
		switch (flag)
		{
		case 1:
			setcolor(BLUE);
			setlinestyle(SOLID_LINE, 0, 3);
			line(x + 3, y + 8, x + 13, y + 18);
			line(x + 13, y + 18, x + 23, y - 2);
			break;
		case 2:
			break;
		}
		return 0;
	}
	return 1;
}

/*********************************************
FUNCTION:checkright_verificationcode
DESCRIPTION：检查验证码是否一致
INPUT:str1,str2,x,y
RETURN:1/0
***********************************************/
int checkright_verificationcode(char* str1, char* str2,int x,int y)
{

	if (strcmp(str1, str2) != 0)
	{
		puthz(x, y, "验证码错误", 16, 17, RED);
		return 1;
	}
	else if (strcmp(str1, str2) == 0)
	{
		setcolor(BLUE);
		setlinestyle(SOLID_LINE, 0, 3);
		line(x + 3, y + 8, x + 13, y + 18);
		line(x + 13, y + 18, x + 23, y - 2);
		return 0;
	}
	return 1;
}

