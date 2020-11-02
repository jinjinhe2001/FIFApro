#include"team.h"
#include"common.h"


int team(USER* u)
{

	Player* player_create = NULL;
	int player_tem[11] = { 0 };
	int condition = 1;
	int check[11];
	int i;

	clrmous(MouseX, MouseY);
	MouseS = 0;
	delay(100);
	cleardevice();
	draw_team();

	player_create = (Player*)malloc(sizeof(Player*) * 11);
	for (i = 0;i < 11;i++)
	{
		check[i] = 1; //no error
	}

	while (condition == 1)
	{
		newmouse(&MouseX, &MouseY, &press);
		condition = func213(player_create, player_tem, u, check);
	}
	free(player_create);
	if (condition == 21)
		return 21;
}

void draw_team()
{
	setcolor(BLACK);
	setfillstyle(1, 3);
	bar(0, 0, 640, 50);
	bar(0, 430, 640, 480);
	setfillstyle(1, 2);
	bar(0, 50, 640, 430);
	rectangle(0, 50, 640, 430);
	line(320, 50, 320, 430);
	rectangle(70, 20, 610, 50);
	bar(70, 20, 160, 50);
	puthz(100, 25, "英国", 16, 16, BLUE);
	bar(160, 20, 250, 50);
	puthz(190, 25, "美国", 16, 16, BLUE);
	bar(250, 20, 340, 50);
	puthz(270, 25, "俄罗斯", 16, 16, BLUE);
	bar(340, 20, 430, 50);
	puthz(370, 25, "德国", 16, 16, BLUE);
	bar(430, 20, 520, 50);
	puthz(460, 25, "中国", 16, 16, BLUE);
	bar(520, 20, 610, 50);
	puthz(540, 25, "自定义", 16, 16, BLUE);

	rectangle(70, 22, 160, 50);
	bar(40, 130, 280, 280);
	bar(270, 130, 280, 140);

	setfillstyle(1, 7);
	bar(120, 440, 200, 470);
	bar(440, 440, 520, 470);
	bar(280, 440, 360, 470);
	rectangle(120, 440, 200, 470);
	rectangle(440, 440, 520, 470);
	rectangle(280, 440, 360, 470);
	puthz(140, 445, "确定", 16, 16, RED);
	puthz(460, 445, "返回", 16, 16, RED);
	puthz(300, 445, "创建", 16, 16, RED);

}

int func213(Player* player_create, int player_tem[], USER* u, int check[])
{
	static int num = 1;    //用来确定进入哪一支球队的界面
	static int state = 1;  //在自定义球队下，确定展示哪一支球员列表
	int i;
	static int warn = 0;   //防止 确定 创建 返回三个键位被重复点亮
	static int create = 0;  //确定创建的球队里添加了几个球员
	static int delete_num;
	int flag;   //用于识别从哪个地方查看球员信息
	setcolor(BLACK);



	if (MouseX >= 70 && MouseY >= 20 && MouseX <= 160 && MouseY <= 50)
	{
		if (mouse_press(70, 20, 160, 50) == 1)
		{
			clrmous(MouseX, MouseY);
			rectangle(70, 22, 160, 50);
			puthz(100, 25, "英国", 16, 16, RED);
			if (num != 1)
			{
				recoverhz2(num);
			}
			num = 1;
			show_team(num, u, player_create, &create, player_tem);
			state = 1;
			return 1;
		}
	}
	else if (MouseX >= 160 && MouseY >= 20 && MouseX <= 250 && MouseY <= 50)
	{
		if (mouse_press(160, 20, 250, 50) == 1)
		{
			clrmous(MouseX, MouseY);
			rectangle(160, 22, 250, 50);
			puthz(190, 25, "美国", 16, 16, RED);
			if (num != 2)
			{
				recoverhz2(num);
			}
			num = 2;
			show_team(num, u, player_create, &create, player_tem);
			state = 1;
			return 1;
		}
	}
	else if (MouseX >= 250 && MouseY >= 20 && MouseX <= 340 && MouseY <= 50)
	{
		if (mouse_press(250, 22, 340, 50) == 1)
		{
			clrmous(MouseX, MouseY);
			rectangle(250, 22, 340, 50);
			puthz(270, 25, "俄罗斯", 16, 16, RED);
			if (num != 3)
			{
				recoverhz2(num);
			}
			num = 3;
			show_team(num, u, player_create, &create, player_tem);
			state = 1;
			return 1;
		}
	}
	else if (MouseX >= 340 && MouseY >= 20 && MouseX <= 430 && MouseY <= 50)
	{
		if (mouse_press(340, 20, 430, 50) == 1)
		{
			clrmous(MouseX, MouseY);
			rectangle(340, 22, 430, 50);
			puthz(370, 25, "德国", 16, 16, RED);
			if (num != 4)
			{
				recoverhz2(num);
			}
			num = 4;
			show_team(num, u, player_create, &create, player_tem);
			state = 1;
			return 1;
		}
	}
	else if (MouseX >= 430 && MouseY >= 20 && MouseX <= 520 && MouseY <= 50)
	{
		if (mouse_press(430, 20, 520, 50) == 1)
		{
			clrmous(MouseX, MouseY);
			rectangle(430, 22, 520, 50);
			puthz(460, 25, "中国", 16, 16, RED);
			if (num != 5)
			{
				recoverhz2(num);
			}
			num = 5;
			show_team(num, u, player_create, &create, player_tem);
			state = 1;
			return 1;
		}
	}
	else if (MouseX >= 520 && MouseY >= 20 && MouseX <= 610 && MouseY <= 50)
	{
		if (mouse_press(520, 20, 610, 50) == 1)
		{
			clrmous(MouseX, MouseY);
			rectangle(520, 22, 610, 50);
			puthz(540, 25, "自定义", 16, 16, RED);
			if (num != 6)
			{
				recoverhz2(num);
			}
			num = 6;
			show_team(num, u, player_create, &create, player_tem);
			state = 1;
			return 1;
		}
	}
	else if (MouseX >= 30 && MouseY >= 300 && MouseX <= 314 && MouseY <= 388)//点击球衣操作
	{
		for (i = 0;i < 11;i++)
		{
			if (mouse_press(30 + i * 50, 300, 64 + i * 50, 328) == 1)
			{
				clrmous(MouseX, MouseY);
				if (num != 6)
				{
					show_ability(i, num, player_create, &create, u, delete_num, player_tem, flag, check);
					delete_num = i;
					return 1;
				}
				else
				{
					if ((create - 1) >= i)
					{
						flag = 1;
						show_ability(i, 6, player_create, &create, u, delete_num, player_tem, flag, check);
						delete_num = i;
						return 1;
					}
				}
			}
			else if (mouse_press(50 + i * 50, 360, 84 + i * 50, 388) == 1)
			{
				clrmous(MouseX, MouseY);
				if (num != 6)
				{
					show_ability((i + 6), num, player_create, &create, u, delete_num, player_tem, flag, check);
					delete_num = i + 6;
					return 1;
				}
				else
				{
					if ((create - 1) >= i + 6)
					{
						flag = 1;
						show_ability((i + 6), 6, player_create, &create, u, delete_num, player_tem, flag, check);
						delete_num = i + 6;
						return 1;
					}
				}
			}
		}
	}
	//点击球员列表操作
	else if (MouseX >= 400 && MouseY >= 90 && MouseX <= 550 && MouseY <= 420)
	{
		for (i = 0;i < 11;i++)
		{

			if (mouse_press(400, 90 + 30 * i, 550, 120 + 30 * i) == 1)
			{
				clrmous(MouseX, MouseY);
				if (num != 6)
				{
					show_ability(i, num, player_create, &create, u, delete_num, player_tem, flag, check);
					return 1;
				}
				else
				{
					flag = 2;
					show_ability(i, state, player_create, &create, u, delete_num, player_tem, flag, check);
					return 1;
				}
			}
		}
	}
	//点击球员列表操作

	else if (num == 6)//自定义球队中球员列表翻页
	{
		circle(350, 255, 15);
		circle(585, 255, 15);
		if (MouseX >= 335 && MouseY >= 240 && MouseX <= 365 && MouseY <= 270)
		{
			if (mouse_press(335, 240, 365, 270) == 1)
			{
				clrmous(MouseX, MouseY);
				state = state--;
				if (state < 1)
					state = 1;
				show_list(state, u);
				delay(150);
				return 1;
			}
		}
		else if (MouseX >= 570 && MouseY >= 240 && MouseX <= 600 && MouseY <= 270)
		{
			if (mouse_press(570, 240, 600, 270) == 1)
			{
				clrmous(MouseX, MouseY);
				state = state++;
				if (state > 6)
					state = 6;
				show_list(state, u);
				delay(150);
				return 1;
			}
		}
	}
	if (MouseX >= 120 && MouseY >= 440 && MouseX <= 200 && MouseY <= 470 && num == 6)//确定按钮
	{
		if (mouse_press(120, 440, 200, 470) == 2)
		{
			MouseS = 1;
			if (warn == 0)
			{
				warn = 1;
				lightbuttonteam(120, 440, 200, 470, BLACK, 11, warn);
			}
			else if (warn != 1)
			{
				recoverbuttonteam(warn);
				warn = 0;
			}
			return 1;
		}
		else if (mouse_press(120, 440, 200, 470) == 1)
		{
			clrmous(MouseX, MouseY);
			if (player_tem[create] == 0 && check[create]!= 1 && create < 11)
			{
				player_tem[create] = 1;
				create++;
				delay(300);
				show_clo(num, u, player_create, &create, player_tem);
			}
			/*else if (player_tem[delete_num] == 0)
			{
				player_tem[delete_num] = 1;
			}*/
			return 1;
		}
	}
	if (MouseX >= 280 && MouseY >= 440 && MouseX <= 360 && MouseY <= 470 && create == 11)//创建按钮
	{
		if (mouse_press(280, 440, 360, 470) == 2)
		{
			MouseS = 1;
			if (warn == 0)
			{
				warn = 2;
				lightbuttonteam(280, 440, 360, 470, BLACK, 11, warn);
			}
			else if (warn != 2)
			{
				recoverbuttonteam(warn);
				warn = 0;
			}
			return 1;
		}
		else if (mouse_press(280, 440, 360, 470) == 1)
		{
			clrmous(MouseX, MouseY);
			printf("%s", (player_create + 1)->player_num);
			delay(2000);
			input_file(player_create, &create, u);
			return 21;
		}
	}
	if (MouseX >= 570 && MouseY >= 240 && MouseX <= 600 && MouseY <= 270)//删除球员按钮
	{
		if (mouse_press(255, 130, 280, 155) == 1)
		{
			clrmous(MouseX, MouseY);
			delete_player(player_create, delete_num);
			player_tem[delete_num] = 0;
			return 1;
		}
		else if (mouse_press(255, 130, 280, 155) == 2)
		{
			MouseS = 1;
			if (warn == 0)
			{
				warn = 4;
				lightbuttonteam(280, 440, 360, 470, BLACK, 11, warn);
			}
			else if (warn != 4)
			{
				recoverbuttonteam(warn);
				warn = 0;
			}
			return 1;
		}
	}

	//返回按钮
	if (MouseX >= 440 && MouseY >= 440 && MouseX <= 520 && MouseY <= 470)
	{
		if (mouse_press(440, 440, 520, 470) == 2)
		{
			MouseS = 1;
			if (warn == 0)
			{
				warn = 3;
				lightbuttonteam(440, 440, 520, 470, BLACK, 11, warn);
			}
			else if (warn != 3)
			{
				recoverbuttonteam(warn);
				warn = 0;
			}
			return 1;
		}
		else if (mouse_press(440, 440, 520, 470) == 1)
		{
			return 21;
		}
	}
	if (warn != 0)
	{
		MouseS = 0;
		recoverbuttonteam(warn);
		warn = 0;
		if (MouseS != 0)
			MouseS = 0;
	}
	return 1;
}


void show_team(int num, USER* u, Player* player_create, int* create, int player_tem[])
{
	int i;
	setcolor(BLACK);
	setfillstyle(1, 2);
	bar(0, 50, 640, 430);
	rectangle(0, 50, 640, 430);
	line(320, 50, 320, 430);
	rectangle(70, 20, 610, 50);
	setfillstyle(1, LIGHTGRAY);
	bar(40, 130, 280, 280);
	puthz(60, 190, "速度：", 16, 16, BLACK);
	puthz(60, 240, "控球：", 16, 16, BLACK);
	puthz(180, 190, "力量：", 16, 16, BLACK);
	puthz(180, 240, "抢断：", 16, 16, BLACK);
	puthz(420, 60, "球员列表", 24, 24, BLACK);
	setfillstyle(1, LIGHTGRAY);
	for (i = 0;i < 11;i++)
	{
		bar(400, 90 + i * 30, 550, 120 + i * 30);
		rectangle(400, 90 + i * 30, 550, 120 + i * 30);
	}
	if (num == 1)
	{
		settextstyle(0, 0, 2);
		outtextxy(45, 85, "FIGHT FOR ROYAL");
		for (i = 0;i < 6;i++)
		{
			drawC2(30 + i * 50, 300, 1, 1);
		}
		for (i = 0;i < 5;i++)
		{
			drawC2(50 + i * 50, 360, 1, 1);
		}
		show_list(num, u);
		show_clo(num, u, player_create, &create, player_tem);
	}
	else if (num == 2)
	{
		settextstyle(0, 0, 2);
		outtextxy(40, 85, "FREE  TO  BATTLE");
		for (i = 0;i < 6;i++)
		{
			drawC2(30 + i * 50, 300, 1, 8);
		}
		for (i = 0;i < 5;i++)
		{
			drawC2(50 + i * 50, 360, 1, 8);
		}
		show_list(num, u);
		show_clo(num, u, player_create, &create, player_tem);
	}
	else if (num == 3)
	{
		settextstyle(0, 0, 2);
		outtextxy(45, 85, "NOBODY CATCH US");
		for (i = 0;i < 6;i++)
		{
			drawC2(30 + i * 50, 300, 1, 3);
		}
		for (i = 0;i < 5;i++)
		{
			drawC2(50 + i * 50, 360, 1, 3);
		}
		show_list(num, u);
		show_clo(num, u, player_create, &create, player_tem);
	}
	else if (num == 4)
	{
		settextstyle(0, 0, 2);
		outtextxy(45, 85, "WE ARE FOOTBALL");
		for (i = 0;i < 6;i++)
		{
			drawC2(30 + i * 50, 300, 1, 4);
		}
		for (i = 0;i < 5;i++)
		{
			drawC2(50 + i * 50, 360, 1, 4);
		}
		show_list(num, u);
		show_clo(num, u, player_create, &create, player_tem);
	}
	else if (num == 5)
	{
		settextstyle(0, 0, 2);
		outtextxy(15, 85, "FAIL THEN FIGHATING");
		for (i = 0;i < 6;i++)
		{
			drawC2(30 + i * 50, 300, 1, 5);
		}
		for (i = 0;i < 5;i++)
		{
			drawC2(50 + i * 50, 360, 1, 5);
		}
		show_list(num, u);
		show_clo(num, u, player_create, &create, player_tem);
	}
	else if (num == 6)
	{
		setfillstyle(1, 8);
		setcolor(BLACK);
		settextstyle(0, 0, 2);
		outtextxy(45, 85, "WE ARE CHAMPION!");
		circle(350, 255, 15);
		circle(585, 255, 15);
		for (i = 0;i < 6;i++)
		{
			drawC2(30 + i * 50, 300, 1, 6);
		}
		for (i = 0;i < 5;i++)
		{
			drawC2(50 + i * 50, 360, 1, 6);
		}
		show_list(1, u);
		show_clo(num, u, player_create, &create, player_tem);
	}
}

void show_list(int state, USER* u)
{
	int i;
	int len;
	FILE* fp;
	Player* playerone;
	char path[50] = "Database\\USER\\";
	char a[2];
	char b[6];
	setcolor(BLACK);
	setfillstyle(1, LIGHTGRAY);
	for (i = 0;i < 11;i++)
	{
		bar(400, 90 + i * 30, 550, 120 + i * 30);
		rectangle(400, 90 + i * 30, 550, 120 + i * 30);
	}
	settextstyle(0, 0, 2);
	if (state == 1)
	{
		if ((fp = fopen("Database\\team1.dat", "rb+")) == NULL)
		{
			printf("cannot open file team1.dat");
			delay(3000);
			exit(1);
		}
	}
	else if (state == 2)
	{
		if ((fp = fopen("database\\team2.dat", "rb+")) == NULL)
		{
			printf("cannot open file team2.dat");
			delay(3000);
			exit(1);
		}
	}
	else if (state == 3)
	{
		if ((fp = fopen("database\\team3.dat", "rb+")) == NULL)
		{
			printf("cannot open file team3.dat");
			delay(3000);
			exit(1);
		}

	}
	else if (state == 4)
	{
		if ((fp = fopen("database\\team4.dat", "rb+")) == NULL)
		{
			printf("cannot open file team4.dat");
			delay(3000);
			exit(1);
		}
	}
	else if (state == 5)
	{
		if ((fp = fopen("database\\team5.dat", "rb+")) == NULL)
		{
			printf("cannot open file team5.dat");
			delay(3000);
			exit(1);
		}
	}
	else if (state == 6)
	{
		strcat(path, u->user);
		strcat(path, "\\selfp.dat");
		if ((fp = fopen(path, "rb+")) == NULL)
		{
			printf("cannot open file team6.dat");
			delay(3000);
			exit(1);
		}
	}

	fseek(fp, 0, SEEK_END);
	len = ftell(fp) / sizeof(Player);
	fseek(fp, 0, SEEK_SET);
	for (i = 0;i < len;i++)
	{
		if ((playerone = (Player*)malloc(sizeof(Player))) == NULL)
		{
			printf("memoryallocation runs wrong in lgfunc.c");
			delay(3000);
			exit(1);
		}
		memset(playerone, '\0', sizeof(Player));
		fseek(fp, i * sizeof(Player), SEEK_SET);
		fgets(playerone->player_num, 3, fp);
		fgets(a, 2, fp);
		fgets(playerone->name, 4, fp);
		fgets(a, 2, fp);
		fgets(playerone->speed, 2, fp);
		fgets(a, 2, fp);
		fgets(playerone->power, 2, fp);
		fgets(a, 2, fp);
		fgets(playerone->control, 2, fp);
		fgets(a, 2, fp);
		fgets(playerone->defend, 2, fp);
		fgets(a, 2, fp);
		fgets(playerone->allA, 3, fp);
		fgets(b, 6, fp);
		outtextxy(410, 99 + i * 30, playerone->player_num);
		outtextxy(475, 99 + i * 30, playerone->name);

		if (playerone != NULL)
		{
			free(playerone);
			playerone = NULL;
		}
	}
	if (fclose(fp) != 0)
	{
		printf("\n cannot close Databaselist");
		delay(10000);
		exit(1);
	}
}

void recoverhz2(int num)
{
	clrmous(MouseX, MouseY);
	setfillstyle(1, 2);
	switch (num)
	{
	case 1:
		bar(70, 20, 160, 50);
		puthz(100, 25, "英国", 16, 16, BLUE);
		break;
	case 2:
		bar(160, 20, 250, 50);
		puthz(190, 25, "美国", 16, 16, BLUE);
		break;
	case 3:
		bar(250, 22, 340, 50);
		puthz(270, 25, "俄罗斯", 16, 16, BLUE);
		break;
	case 4:
		bar(340, 20, 430, 50);
		puthz(370, 25, "德国", 16, 16, BLUE);
		break;
	case 5:
		bar(430, 20, 520, 50);
		puthz(460, 25, "中国", 16, 16, BLUE);
		break;
	case 6:
		bar(520, 20, 610, 50);
		puthz(540, 25, "自定义", 16, 16, BLUE);
		break;
	}
	setcolor(BLACK);
	rectangle(70, 20, 610, 50);
}

void drawC2(int x, int y, int ratio, int color)
{
	int d[20] = { 7,0, 0, 8, 6, 15, 8, 12, 6, 28, 28, 28, 26, 12, 28, 15, 34, 8, 27,0 };
	int i;
	for (i = 0;i <= 18;i += 2)
		d[i] = d[i] * ratio + x;
	for (i = 1;i <= 19;i += 2)
		d[i] = d[i] * ratio + y;
	setfillstyle(1, color);
	setlinestyle(SOLID_LINE, 0, 3);
	fillpoly(10, d);

}

void show_ability(int i, int num, Player* player_create, int* create, USER* u, int delete_num, int player_tem[], int flag, int check[])
{
	int k;
	Player* player;
	FILE* fp;
	char path[50] = "Database\\USER\\";
	char a[2];
	char b[6];
	strcat(path, u->user);
	strcat(path, "\\selfp.dat");
	setfillstyle(1, LIGHTGRAY);
	bar(40, 130, 280, 280);
	puthz(60, 190, "速度：", 16, 16, BLACK);
	puthz(60, 240, "控球：", 16, 16, BLACK);
	puthz(180, 190, "力量：", 16, 16, BLACK);
	puthz(180, 240, "抢断：", 16, 16, BLACK);
	//显示删除键
	setfillstyle(1, BLACK);
	setcolor(BLACK);
	settextstyle(0, 0, 2);
	if (num == 1)
	{
		if ((fp = fopen("Database\\team1.dat", "rb+")) == NULL)
		{
			printf("cannot open file team1.dat");
			delay(3000);
			exit(1);
		}
	}
	else if (num == 2)
	{
		if ((fp = fopen("Database\\team2.dat", "rb+")) == NULL)
		{
			printf("cannot open file team1.dat");
			delay(3000);
			exit(1);
		}
	}
	else if (num == 3)
	{
		if ((fp = fopen("Database\\team3.dat", "rb+")) == NULL)
		{
			printf("cannot open file team1.dat");
			delay(3000);
			exit(1);
		}
	}
	else if (num == 4)
	{
		if ((fp = fopen("Database\\team4.dat", "rb+")) == NULL)
		{
			printf("cannot open file team1.dat");
			delay(3000);
			exit(1);
		}
	}
	else if (num == 5)
	{
		if ((fp = fopen("Database\\team5.dat", "rb+")) == NULL)
		{
			printf("cannot open file team1.dat");
			delay(3000);
			exit(1);
		}
	}
	else if (num == 6 && flag == 2)
	{
		if ((fp = fopen(path, "rb+")) == NULL)
		{
			printf("cannot open file team1.dat");
			delay(3000);
			exit(1);
		}
	}
	if ((player = (Player*)malloc(sizeof(Player))) == NULL)
	{
		printf("memoryallocation runs wrong in lgfunc.c");
		delay(3000);
		exit(1);
	}
	if (num != 6 || (num == 6 && flag == 2))
	{
		memset((player_create + *create), '\0', sizeof(Player));
		fseek(fp, i * sizeof(Player), SEEK_SET);
		fgets((player_create + *create)->player_num, 3, fp);
		fgets(a, 2, fp);
		fgets((player_create + *create)->name, 4, fp);
		fgets(a, 2, fp);
		fgets((player_create + *create)->speed, 2, fp);
		fgets(a, 2, fp);
		fgets((player_create + *create)->control, 2, fp);
		fgets(a, 2, fp);
		fgets((player_create + *create)->power, 2, fp);
		fgets(a, 2, fp);
		fgets((player_create + *create)->defend, 2, fp);
		fgets(a, 2, fp);
		fgets((player_create + *create)->allA, 3, fp);
		fgets(b, 6, fp);
		/*strcpy((player_create + *create)->player_num, player->player_num);
		strcpy((player_create + *create)->name, player->name);
		strcpy((player_create + *create)->speed, player->speed);
		strcpy((player_create + *create)->control, player->control);
		strcpy((player_create + *create)->power, player->power);
		strcpy((player_create + *create)->defend, player->defend);
		strcpy((player_create + *create)->allA, player->allA);	*/
		//(player_create + *create)->all = 0;
		check[*create] = 0;
		outtextxy(120, 190, (player_create + *create)->speed);
		outtextxy(120, 240, (player_create + *create)->control);
		outtextxy(240, 190, (player_create + *create)->power);
		outtextxy(240, 240, (player_create + *create)->defend);
		outtextxy(140, 150, (player_create + *create)->name);

		if (player != NULL)
		{
			free(player);
			player = NULL;
		}
		if (fclose(fp) != 0)
		{
			printf("\n cannot close Databaseability");
			delay(3000);
			exit(1);
		}
	}
	/*if (player_tem[delete_num] == 0)
	{
		strcpy((player_create + delete_num)->player_num, player->player_num);
		strcpy((player_create + delete_num)->name, player->name);
		strcpy((player_create + delete_num)->speed, player->speed);
		strcpy((player_create + delete_num)->control, player->control);
		strcpy((player_create + delete_num)->power, player->power);
		strcpy((player_create + delete_num)->defend, player->defend);
		strcpy((player_create + delete_num)->allA, player->allA);
		(player_create + delete_num)->all = 0;
	}*/
	if (num == 6 && flag == 1)
	{
		outtextxy(120, 190, (player_create + i)->speed);
		outtextxy(120, 240, (player_create + i)->control);
		outtextxy(240, 190, (player_create + i)->power);
		outtextxy(240, 240, (player_create + i)->defend);
		outtextxy(140, 150, (player_create + i)->name);

		(player_create + *create)->all = 0;
		if (player != NULL)
		{
			free(player);
			player = NULL;
		}

	}

}

void show_clo(int num, USER* u, Player* player_create, int* create, int player_tem[])
{
	int i;
	FILE* fp;
	Player* player = NULL;
	char a[2];
	char b[6];
	settextstyle(0, 0, 1);
	setcolor(WHITE);
	if (num != 6)
	{
		if ((fp = fopen("Database\\team1.dat", "rb+")) == NULL)
		{
			printf("cannot open file team1.dat");
			delay(3000);
			exit(1);
		}
		if ((player = (Player*)malloc(sizeof(Player))) == NULL)
		{
			printf("memoryallocation runs wrong in lgfunc.c");
			delay(3000);
			exit(1);
		}
		fseek(fp, 0, SEEK_SET);
		for (i = 0;i < 11;i++)
		{

			memset(player, '\0', sizeof(Player));
			fseek(fp, i * sizeof(Player), SEEK_SET);
			fgets(player->player_num, 3, fp);
			fgets(a, 2, fp);
			fgets(player->name, 4, fp);
			fgets(a, 2, fp);
			fgets(player->speed, 2, fp);
			fgets(a, 2, fp);
			fgets(player->power, 2, fp);
			fgets(a, 2, fp);
			fgets(player->control, 2, fp);
			fgets(a, 2, fp);
			fgets(player->defend, 2, fp);
			fgets(a, 2, fp);
			fgets(player->allA, 3, fp);
			fgets(b, 6, fp);
			if (i < 6)
				outtextxy(40.5 + i * 50, 307, player->player_num);
			if (i > 5)
				outtextxy(60.5 + (i - 6) * 50, 367, player->player_num);
			if (player != NULL)
			{
				free(player);
				player = NULL;
			}
		}
		if (fclose(fp) != 0)
		{
			printf("\n cannot close Databaseclo");
			delay(10000);
			exit(1);
		}
	}
	else if (num == 6)
	{
		for (i = 0;i < create;i++)
		{
			if (i < 6 && player_tem[i] == 1)
				outtextxy(40.5 + i * 50, 307, (player_create + i)->player_num);
			if (i > 5 && player_tem[i] == 1)
				outtextxy(60.5 + (i - 6) * 50, 367, (player_create + i)->player_num);
			free(player);
		}
	}

}

void lightbuttonteam(int x, int y, int x1, int y1, int color1, int color2, int flag)
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
		puthz(140, 445, "确定", 16, 16, BLUE);;
		break;
	case 2:
		puthz(300, 445, "创建", 16, 16, BLUE);
		break;
	case 3:
		puthz(460, 445, "返回", 16, 16, BLUE);
		break;
	default:
		closegraph();
		printf("something runs wrong in lightbutton");
		exit(1);
	}
}

void recoverbuttonteam(int status)
{
	clrmous(MouseX, MouseY);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setfillstyle(1, 7);
	switch (status)
	{
	case 1:
		bar(120, 440, 200, 470);
		rectangle(120, 440, 200, 470);
		puthz(140, 445, "确定", 16, 16, RED);
		break;
	case 2:
		bar(280, 440, 360, 470);
		rectangle(280, 440, 360, 470);
		puthz(300, 445, "创建", 16, 16, RED);
		break;
	case 3:
		bar(440, 440, 520, 470);
		rectangle(440, 440, 520, 470);
		puthz(460, 445, "返回", 16, 16, RED);
		break;
	default:
		break;
	}
}

void input_file(Player* player_create, int* create, USER* u)
{
	int i;
	FILE* fp;
	char path[50] = "Database\\USER\\";
	strcat(path, u->user);
	strcat(path, "\\SELFT.dat");
	if (*create != 11)
	{
		warn_no();
	}
	else if (*create == 11)
	{

		if ((fp = fopen(path, "wb+")) == NULL)
		{
			printf("cannot open file teamfp.dat");
			delay(3000);
			exit(1);
		}
		fseek(fp, 0, SEEK_SET);
		for (i = 0;i < 11;i++)
		{
			printf("%s", (player_create + i)->player_num);
			fputs((player_create + i)->player_num, fp);
			fputs(" ", fp);
			fputs((player_create + i)->name, fp);
			fputs(" ", fp);
			fputs((player_create + i)->speed, fp);
			fputs(" ", fp);
			fputs((player_create + i)->power, fp);
			fputs(" ", fp);
			fputs((player_create + i)->control, fp);
			fputs(" ", fp);
			fputs((player_create + i)->defend, fp);
			fputs(" ", fp);
			fputs((player_create + i)->allA, fp);
			fputs("   ", fp);

		}
		if (fclose(fp) != 0)
		{
			printf("\n cannot close Database.");
			delay(3000);
			exit(1);
		}
	}
}

void delete_player(Player* player_create, int delete_num)
{
	strcpy((player_create + delete_num)->player_num, '\0');
	strcpy((player_create + delete_num)->name, '\0');
	strcpy((player_create + delete_num)->speed, '\0');
	strcpy((player_create + delete_num)->control, '\0');
	strcpy((player_create + delete_num)->power, '\0');
	strcpy((player_create + delete_num)->defend, '\0');
	strcpy((player_create + delete_num)->allA, '\0');
	(player_create + delete_num)->all = 0;
}

void warn_no()
{
	puthz(460, 445, "人数未满，请继续添加", 16, 16, RED);
	delay(2000);
	draw_team();
}