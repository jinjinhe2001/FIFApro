#include"common.h"
#include"int.h"
#include"game.h"
#include<time.h>
#include"shoot.h"
#include"map.h"
#include"Gend.h"

int game(int nation, int nation2,int time, USER *u)
{
	int gameDriver=VGA;
	int gameMode=VGAMED;


	float camera_x = 0, camera_y = 0;
	unsigned int page;
	clock_t now, last;  //用于屏幕切换
	clock_t first, end;
	clock_t dertat;
	struct Ball* ball;
	struct Player_IG* player;
	struct GameKey* gameKey = getGameKey();
	 //从prepare传参过来，用于初始化球员能力值
	initgraph(&gameDriver,&gameMode,"C:\\BORLANDC\\BGI");

	ball = (struct Ball*)malloc(sizeof(struct Ball));
	player = (struct Player_IG*)malloc(sizeof(struct Player_IG) * player_allnum);

	read_field();
	bar(0, 0, 640, 480);
	setbkcolor(GREEN);
	init_postion(player, ball);
	init_info(player, ball, nation, nation2, u);
	set_position(player, ball, 0);
	ball->score_we = 1;
	ball->score_en = 0;
	now = clock();
	first = now;
	init_newint9_game();
	while(1)
	{
		if (escHit) 
		{
			cancel_newint9_game();
			exit(0);
		}
		camera_x = ball->x - 320;
		camera_y = ball->y - 240;
		if (camera_x < 0)
			camera_x = 0;
		if (camera_y < 0)
			camera_y = 0;
		if (camera_x > 310)
			camera_x = 310;
		if (camera_y > 240)
			camera_y = 240;
		now = clock();
		end = now;
		if (last != now)
		{
			page++;
			setactivepage(page % 2);
			putField(camera_x, camera_y, page % 2);
			show_screen(camera_x, camera_y, player, ball, page % 2, dertat, time);
			setvisualpage(page % 2);
			last = now;
		}
		setKeyPressed();
		updateWithInput(player, ball, gameKey, camera_x, camera_y);
		updateWithoutInput(player, ball);
		delay(40);
		dertat = (end - first) / CLOCKS_PER_SEC;
		if (dertat >= 5)
		{	
			free(player);
			delay(500);
			while (ball->score_we == ball->score_en)
			{
				ball->score_we += game_shoot(0);
				ball->score_en += game_shoot(1);
			}
			Gend(u,ball, 1);
			free(ball);
			break;
		}
	}

}

void init_postion(struct Player_IG* player, struct Ball* ball)
{
	(player + 0)->position_x[0] = 200;
	(player + 1)->position_x[0] = 200;
	(player + 2)->position_x[0] = 200;
	(player + 3)->position_x[0] = 400;
	(player + 4)->position_x[0] = 400;
	(player + 5)->position_x[0] = 400;
	(player + 6)->position_x[0] = 500;
	(player + 7)->position_x[0] = 500;
	(player + 8)->position_x[0] = 500;
	(player + 9)->position_x[0] = 500;

	(player + 0)->position_y[0] = 180;
	(player + 1)->position_y[0] = 300;
	(player + 2)->position_y[0] = 440;
	(player + 3)->position_y[0] = 180;
	(player + 4)->position_y[0] = 300;
	(player + 5)->position_y[0] = 440;
	(player + 6)->position_y[0] = 120;
	(player + 7)->position_y[0] = 240;
	(player + 8)->position_y[0] = 360;
	(player + 9)->position_y[0] = 520;

	(player + 10)->position_x[0] = 760;
	(player + 11)->position_x[0] = 760;
	(player + 12)->position_x[0] = 760;
	(player + 13)->position_x[0] = 560;
	(player + 14)->position_x[0] = 560;
	(player + 15)->position_x[0] = 560;
	(player + 16)->position_x[0] = 460;
	(player + 17)->position_x[0] = 460;
	(player + 18)->position_x[0] = 460;
	(player + 19)->position_x[0] = 460;

	(player + 10)->position_y[0] = 180;
	(player + 11)->position_y[0] = 300;
	(player + 12)->position_y[0] = 440;
	(player + 13)->position_y[0] = 180;
	(player + 14)->position_y[0] = 300;
	(player + 15)->position_y[0] = 440;
	(player + 16)->position_y[0] = 120;
	(player + 17)->position_y[0] = 240;
	(player + 18)->position_y[0] = 360;
	(player + 19)->position_y[0] = 520;

	(player + 0)->position_x[1] = 400;
	(player + 1)->position_x[1] = 400;
	(player + 2)->position_x[1] = 400;
	(player + 3)->position_x[1] = 600;
	(player + 4)->position_x[1] = 600;
	(player + 5)->position_x[1] = 600;
	(player + 6)->position_x[1] = 700;
	(player + 7)->position_x[1] = 700;
	(player + 8)->position_x[1] = 700;
	(player + 9)->position_x[1] = 700;

	(player + 0)->position_y[1] = 180;
	(player + 1)->position_y[1] = 300;
	(player + 2)->position_y[1] = 440;
	(player + 3)->position_y[1] = 180;
	(player + 4)->position_y[1] = 300;
	(player + 5)->position_y[1] = 440;
	(player + 6)->position_y[1] = 120;
	(player + 7)->position_y[1] = 240;
	(player + 8)->position_y[1] = 360;
	(player + 9)->position_y[1] = 520;

	(player + 10)->position_x[1] = 560;
	(player + 11)->position_x[1] = 560;
	(player + 12)->position_x[1] = 560;
	(player + 13)->position_x[1] = 360;
	(player + 14)->position_x[1] = 360;
	(player + 15)->position_x[1] = 360;
	(player + 16)->position_x[1] = 260;
	(player + 17)->position_x[1] = 260;
	(player + 18)->position_x[1] = 260;
	(player + 19)->position_x[1] = 260;

	(player + 10)->position_y[1] = 180;
	(player + 11)->position_y[1] = 300;
	(player + 12)->position_y[1] = 440;
	(player + 13)->position_y[1] = 180;
	(player + 14)->position_y[1] = 300;
	(player + 15)->position_y[1] = 440;
	(player + 16)->position_y[1] = 120;
	(player + 17)->position_y[1] = 240;
	(player + 18)->position_y[1] = 360;
	(player + 19)->position_y[1] = 520;
}
void init_info(struct Player_IG* player, struct Ball* ball, int nation, int nation2, USER* u)
{
	int i, j, k;//检测
	FILE* fp; //打开球员能力值文件
	FILE* ffp;
	Player* playerone;
	int len;
	char a[2];
	char b[6];
	char path[50] = "Database\\USER\\";
	strcat(path, u->user);
	strcat(path, "\\selft.dat");

	if (nation == 0)
	{
		if ((fp = fopen("database\\team1.dat", "rb+")) == NULL)
		{
			printf("cannot open file UserData.dat");
			delay(3000);
			exit(1);
		}
	}
	else if (nation == 1)
	{
		if ((fp = fopen("database\\team2.dat", "rb+")) == NULL)
		{
			printf("cannot open file UserData.dat");
			delay(3000);
			exit(1);
		}
	}
	else if (nation == 2)
	{
		if ((fp = fopen("database\\team3.dat", "rb+")) == NULL)
		{
			printf("cannot open file UserData.dat");
			delay(3000);
			exit(1);
		}
	}
	else if (nation == 3)
	{
		if ((fp = fopen("database\\team4.dat", "rb+")) == NULL)
		{
			printf("cannot open file UserData.dat");
			delay(3000);
			exit(1);
		}
	}
	else if (nation == 4)
	{
		if ((fp = fopen("database\\team5.dat", "rb+")) == NULL)
		{
			printf("cannot open file UserData.dat");
			delay(3000);
			exit(1);
		}
	}
	else if (nation == 5)
	{
		if ((fp = fopen(path, "rb+")) == NULL)
		{
			printf("cannot open file UserData.dat");
			delay(3000);
			exit(1);
		}
	}
	fseek(fp, 0, SEEK_END);
	len = ftell(fp) / sizeof(Player);
	fseek(fp, i * sizeof(Player), SEEK_SET);


	for (i = 0; i < 10; i++)
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

		(player + i)->speed = atoi(playerone->speed);
		(player + i)->control = atoi(playerone->control);
		(player + i)->power = atoi(playerone->power);
		(player + i)->defend = atoi(playerone->defend);

		if (playerone != NULL)
		{
			free(playerone);
			playerone = NULL;
		}
	}
	if (fclose(fp) != 0)
	{
		printf("\n cannot close Database");
		delay(3000);
		exit(1);
	}

	if (nation2 == 0)
	{
		if ((ffp = fopen("database\\team1.dat", "rb+")) == NULL)
		{
			printf("cannot open file UserData.dat");
			delay(3000);
			exit(1);
		}
	}
	else if (nation2 == 1)
	{
		if ((ffp = fopen("database\\team2.dat", "rb+")) == NULL)
		{
			printf("cannot open file UserData.dat");
			delay(3000);
			exit(1);
		}
	}
	else if (nation2 == 2)
	{
		if ((ffp = fopen("database\\team3.dat", "rb+")) == NULL)
		{
			printf("cannot open file UserData.dat");
			delay(3000);
			exit(1);
		}
	}
	else if (nation2 == 3)
	{
		if ((ffp = fopen("database\\team4.dat", "rb+")) == NULL)
		{
			printf("cannot open file UserData.dat");
			delay(3000);
			exit(1);
		}
	}
	else if (nation2 == 4)
	{
		if ((ffp = fopen("database\\team5.dat", "rb+")) == NULL)
		{
			printf("cannot open file UserData.dat");
			delay(3000);
			exit(1);
		}
	}
	fseek(ffp, 0, SEEK_END);
	len = ftell(ffp) / sizeof(Player);
	fseek(ffp, i * sizeof(Player), SEEK_SET);


	for (i = 10; i < 20; i++)
	{
		if ((playerone = (Player*)malloc(sizeof(Player))) == NULL)
		{
			printf("memoryallocation runs wrong in lgfunc.c");
			delay(3000);
			exit(1);
		}
		memset(playerone, '\0', sizeof(Player));
		fseek(ffp, (i - 10) * sizeof(Player), SEEK_SET);
		fgets(playerone->player_num, 3, ffp);
		fgets(a, 2, ffp);
		fgets(playerone->name, 4, ffp);
		fgets(a, 2, ffp);
		fgets(playerone->speed, 2, ffp);
		fgets(a, 2, ffp);
		fgets(playerone->power, 2, ffp);
		fgets(a, 2, ffp);
		fgets(playerone->control, 2, ffp);
		fgets(a, 2, ffp);
		fgets(playerone->defend, 2, ffp);
		fgets(a, 2, ffp);
		fgets(playerone->allA, 3, ffp);
		fgets(b, 6, ffp);

		(player + i)->speed = atoi(playerone->speed);
		(player + i)->control = atoi(playerone->control);
		(player + i)->power = atoi(playerone->power);
		(player + i)->defend = atoi(playerone->defend);
		if (playerone != NULL)
		{
			free(playerone);
			playerone = NULL;
		}
	}
	if (fclose(ffp) != 0)
	{
		printf("\n cannot close Database");
		delay(3000);
		exit(1);
	}
}
void set_position(struct Player_IG* player, struct Ball* ball, int flag)
{
	int i;
	if (flag == 0)
	{
		for (i = 0;i < 20;i++)
		{
			(player + i)->x = (player + i)->position_x[0];
			(player + i)->y = (player + i)->position_y[0];
			(player + i)->haveball = 0;
		}
		for (i = 0;i < 20;i++)
		{
			(player + i)->begin_x = (player + i)->position_x[0];
			(player + i)->begin_y = (player + i)->position_y[0];
		}
		ball->x = 480;
		ball->y = 320;
		ball->position = 0;
	}
	else if (flag == 1)
	{
		for (i = 0;i < 20;i++)
		{
			(player + i)->x = (player + i)->position_x[0];
			(player + i)->y = (player + i)->position_y[0];
			(player + i)->haveball = 0;
		}
		for (i = 0;i < 10;i++)
		{
			(player + i)->begin_x = (player + i)->position_x[0];
			(player + i)->begin_y = (player + i)->position_y[0];
		}
		for (i = 10;i < 20;i++)
		{
			(player + i)->begin_x = (player + i)->position_x[1];
			(player + i)->begin_y = (player + i)->position_y[1];
		}
		ball->x = 510;
		ball->y = 300;
		ball->position = 0;
	}
	else if (flag == 2)
	{
		for (i = 0;i < 20;i++)
		{
			(player + i)->x = (player + i)->position_x[0];
			(player + i)->y = (player + i)->position_y[0];
			(player + i)->haveball = 0;
		}
		for (i = 0;i < 10;i++)
		{
			(player + i)->begin_x = (player + i)->position_x[1];
			(player + i)->begin_y = (player + i)->position_y[1];
		}
		for (i = 10;i < 20;i++)
		{
			(player + i)->begin_x = (player + i)->position_x[0];
			(player + i)->begin_y = (player + i)->position_y[0];
		}
		ball->x = 450;
		ball->y = 300;
		ball->position = 0;
	}
	ball->owner = -1;
}

void show_screen(int x0, int y0, struct Player_IG* player, struct Ball* ball, int page, clock_t derta, int time)
{
	//显示计分板和时间
	//放置球员		
	show_player(x0, y0, player, ball);
	show_ball(x0, y0, ball);	
	show_counter(ball, derta, time);
}
void show_counter(struct Ball* ball, clock_t derta, int time)
{
	char str1[10];
	char str2[10];
	char str3[10];
	setfillstyle(1, WHITE);
	rectangle(260, 0, 380, 50);
	bar(260, 0, 380, 50);
	bar(0, 0, 70, 30);
	puthz(300, 0, "比分", 16, 16, RED);
	textcolor(0);
	derta = time - derta;
	itoa(derta, str3, 10);
	itoa(ball->score_we, str1, 10);
	itoa(ball->score_en, str2, 10);
	//设置字体大小
	settextstyle(0, 0, 2);
	outtextxy(320, 25, ":");
	outtextxy(290, 25, str1);
	outtextxy(335, 25, str2);
	//显示时间
	outtextxy(5, 5, str3);
	outtextxy(55, 5, "s");
}

void show_ball(int x0, int y0, struct Ball* ball)
{
	setfillstyle(1, WHITE);
	fillellipse(ball->x - x0, ball->y - y0, 5, 5);	//放置足球
	setcolor(BLACK);
	setlinestyle(0, 0, 1);
	line(ball->x - x0, ball->y + 5 - y0, ball->x - x0, ball->y - 5 - y0);
	line(ball->x - 5 - x0, ball->y - y0, ball->x + 5 - x0, ball->y - y0);
}

void show_player(int x0, int y0, struct Player_IG* player, struct Ball*ball)
{
	int i;
	for (i = 0;i < player_allnum;i++)//球员的position为右下角的位置坐标
	{
		if (i < 10)
		{
			setfillstyle(1, RED);
			fillellipse((player + i)->x - 10 - x0, (player + i)->y + 2 - y0, 3, 3);   //左脚
			fillellipse((player + i)->x - 5 - x0, (player + i)->y - 7 - y0, 6, 10);    //头
			fillellipse((player + i)->x - 6 - x0, (player + i)->y - 20 - y0, 5, 5);    //身体
			fillellipse((player + i)->x - x0, (player + i)->y + 2 - y0, 3, 3);        //右脚
		}
		else if (i < 20)
		{
			setfillstyle(1, BLUE);
			fillellipse((player + i)->x - 10 - x0, (player + i)->y + 2 - y0, 3, 3);   //左脚
			fillellipse((player + i)->x - 5 - x0, (player + i)->y - 7 - y0, 6, 10);    //头
			fillellipse((player + i)->x - 6 - x0, (player + i)->y - 20 - y0, 5, 5);    //身体
			fillellipse((player + i)->x - x0, (player + i)->y + 2 - y0, 3, 3);    //右脚
		}
		if (i == ball->we_near)
		{
			setfillstyle(1, YELLOW);
			fillellipse((player + i)->x - x0 - 7, (player + i)->y - y0 - 30, 5, 5);
		}
	}
}
void updateWithInput(struct Player_IG* player, struct Ball* ball, struct GameKey* gameKey, int x0, int y0)
{
	int mindistance = 1000;   //先初始化
	int min_num = 0;
	int we_near = 0;
	int i;
	//历遍球员，找到离球最近的球员

	for (i = 0;i < player_allnum;i++)
	{
		(player + i)->distance = sqrt(((player + i)->x - ball->x) * ((player + i)->x - ball->x) + ((player + i)->y - ball->y) * ((player + i)->y - ball->y));
	}
	for (i = 0;i < player_allnum;i++)
	{
		if ((player + i)->distance < mindistance) {
			mindistance = (player + i)->distance;
			min_num = i;
		}
		if ((player + i)->haveball)
		{
			min_num = i;
			break;
		}
	}
	ball->min_num = min_num;

	//找到离球最近的操控方球员
	mindistance = 1000;
	for (i = 0;i < 10;i++)
	{
		if ((player + i)->distance < mindistance)
		{
			mindistance = (player + i)->distance;
			we_near = i;
		}
		if ((player + i)->haveball)
		{
			we_near = i;
			break;
		}
	}
	ball->we_near = we_near;

	(player + we_near)->left = 0 ;
	(player + we_near)->right = 0;
	(player + we_near)->up = 0;
	(player + we_near)->down = 0;
	//键盘操控球员具体实现
	if (gameKey->j.pressed)  //将球踢出
	{
		if ((player + we_near)->haveball == 1)
		{
			ball->ballrun = (player + we_near)->power + 1 ;
			(player + we_near)->haveball = 0;
		}
	}
	if (gameKey->k.pressed)  //抢球键
	{
		strugle_player(player, ball, ball->we_near);
	}
	if (gameKey->a.pressed)
	{
		(player + we_near)->x -= ((player + we_near)->speed / 2 + 3);
		(player + we_near)->left = 1;
		(player + we_near)->lastdirection = 1;
		(player + we_near)->right = 0;
	}
	else
	{
		(player + we_near)->left = 0;
	}

	if (gameKey->d.pressed)
	{
		(player + we_near)->x += ((player + we_near)->speed / 2 + 3);
		(player + we_near)->right = 1;
		(player + we_near)->lastdirection = 2;
		(player + we_near)->left = 0;
	}
	else
	{
		(player + we_near)->right = 0;
	}

	if (gameKey->w.pressed)
	{
		(player + we_near)->y -= ((player + we_near)->speed / 2 + 3);
		(player + we_near)->up = 1;
		(player + we_near)->lastdirection = 3;
		(player + we_near)->down = 0;
	}
	else 
	{
		(player + we_near)->up = 0;
	}

	if (gameKey->s.pressed)
	{
		(player + we_near)->y += ((player + we_near)->speed / 2 + 3);
		(player + we_near)->down = 1;
		(player + we_near)->lastdirection = 4;
		(player + we_near)->up = 0;
	}
	else
	{
		(player + we_near)->down = 0;
	}
}
void updateWithoutInput(struct Player_IG* player, struct Ball* ball)
{
	if (ball->owner != -1)
	{
		ball->left = (player + ball->owner)->left;
		ball->right = (player + ball->owner)->right;
		ball->up = (player + ball->owner)->up;
		ball->down = (player + ball->owner)->down;

		if (ball->left == 1)
		{
			ball->x = (player + ball->owner)->x - 10;

		}
		if (ball->right == 1)
		{
			ball->x = (player + ball->owner)->x;

		}
		if (ball->up == 1)
		{
			ball->x = (player + ball->owner)->x - 5;
			ball->y = (player + ball->owner)->y - 5;
		}
		if (ball->down == 1)
		{
			ball->x = (player + ball->owner)->x - 5;
			ball->y = (player + ball->owner)->y + 5;
		}
		if (ball->owner >= 0 && ball->owner <= 9)
			ball->team = 1;
		if (ball->owner >= 10 && ball->owner <= 19)
			ball->team = 2;
	}
	if (ball->ballrun > 0)
	{
		//根据power参数进行修正
		if (ball->right == 1)
			ball->x += (ball->right * ball->ballrun * 0.8 + 16);
		if (ball->left == 1)
			ball->x -= (ball->left * ball->ballrun * 0.8 + 16);
		if (ball->down == 1)
			ball->y += (ball->down * ball->ballrun + 16);
		if (ball->up == 1)
			ball->y -= (ball->up * ball->ballrun + 16);
		ball->ballrun -= 2;
		ball->owner = -1;
	}
	else
	{
		ball->left = 0;
		ball->right = 0;
		ball->up = 0;
		ball->down = 0;
	}

	//判断离球最近者是否控球
	if (((player + ball->min_num)->x - ball->x) * ((player + ball->min_num)->x - ball->x) + ((player + ball->min_num)->y - ball->y) * ((player + ball->min_num)->y - ball->y) < 500 && ball->owner == -1)
	{
		ball->owner = ball->min_num;
		ball->ballrun = 0;
		(player + ball->owner)->haveball = 1;
		ball->left = (player + ball->owner)->left;
		ball->right = (player + ball->owner)->right;
		ball->up = (player + ball->owner)->up;
		ball->down = (player + ball->owner)->down;
	}



	//根据球员方向，改变球的放置位置
	
	// 判断球的位置，改变position参数
	//此处需要添加一个参数，根据持球人，确定出界或进球后的球权归属
	//此处判断无需加上镜头偏移量
	if (ball->y <= -(510 / 74) * (ball->x - 23) + 560 || ball->y <= (510 / 74) * (ball->x - 937) + 578 || ball->y < 70 || ball->y>578)
	{
		ball->position = -1;
		if (ball->y >= 270 && ball->y <= 330)
			ball->position = 1;
	}
	if (ball->position == 1)
	{
		tip_ball_in(ball, player);

	}
	if (ball->position == -1)
		tip_ball_out(ball, player);

	player_AI(player, ball);
}

void player_AI(struct Player_IG* player, struct Ball* ball)
{
	static int pre_owner = -1;
	if (pre_owner != ball->owner)
		change_position(player, ball);    //改变队伍的状态为  进攻或防守
	player_magicmove(player, ball);
	if (ball->owner >= 10 && ball->owner <= 19)   //电脑方球员进攻算法
		player_atk(player, ball);
	pre_owner = ball->owner;

}

void change_position(struct Player_IG* player, struct Ball* ball)
{
	int i; //用于对每个球员的信息批量修改
	for (i = 0;i < 20;i++)
	{
		(player + i)->state = 0;
	}
	if (ball->owner >= 0 && ball->owner < 10)
	{
		for (i = 0;i < 10;i++)
			(player + i)->state = 1;
		for (i = 10;i < 20;i++)
			(player + i)->state = 0;
	}
	else if (ball->owner >= 10 && ball->owner < 20)
	{
		for (i = 0;i < 10;i++)
			(player + i)->state = 1;
		for (i = 10;i < 20;i++)
			(player + i)->state = 0;
	}
	for (i = 0;i < 20;i++)
	{
		(player + i)->begin_x = (player + i)->position_x[(player + i)->state];
		(player + i)->begin_y = (player + i)->position_y[(player + i)->state];
	}
}


void player_atk(struct Player_IG* player, struct Ball* ball)   //电脑方球员进攻策略
{
	(player + ball->owner)->up = 0;
	(player + ball->owner)->down = 0;
	(player + ball->owner)->left = 0;
	(player + ball->owner)->right = 0;
	if ((player + ball->owner)->x > 500)
	{
		(player + ball->owner)->left = 1;
		(player + ball->owner)->x -= ((player + ball->owner)->speed + 2);
	}
	else
	{
	
		//向前加速
		if ((player + ball->owner)->x > 10)
		{
			(player + ball->owner)->left = 1;
			(player + ball->owner)->x -=  5;
		}
		else
		{
			(player + ball->owner)->left = 0;
		}
		if ((player + ball->owner)->x < 50)
		{
			(player + ball->owner)->left = 1;
			(player + ball->owner)->x -= 3;
		}

		//向球门靠拢		
		if ((player + ball->owner)->y < 280)
		{
			(player + ball->owner)->down = 1;
			(player + ball->owner)->y += 8;
		}
		else
		{
			(player + ball->owner)->down = 0;
		}
		if ((player + ball->owner)->y > 320)
		{
			(player + ball->owner)->up = 1;
			(player + ball->owner)->y -= 8;
		}
		else
		{
			(player + ball->owner)->up = 0;
		}
		//if ((player + ball->owner)->x <200)
	}
}

void player_magicmove(struct Player_IG* player, struct Ball* ball)
{
	int if_sameteam = 0;
	static long int k = 0;
	int i;
	k++;
	for (i = 0;i < player_allnum;i++)
	{
		if (i == ball->we_near || i == ball->owner)
			continue;
		if (sqrt(((player + i)->x - (player + i)->begin_x) * ((player + i)->x - (player + i)->begin_x) + ((player + i)->y - (player + i)->begin_y) * ((player + i)->y - (player + i)->begin_y)) >= 100)
		{
			(player + i)->back = 1;
		}

		if ((player + i)->back == 1)
		{
			if ((player + i)->x > (player + i)->begin_x)
			{
				(player + i)->right = 0;
				(player + i)->left = 1;
				(player + i)->x -= 3;
			}
			else
			{
				(player + i)->left = 0;
			}
			if ((player + i)->x < (player + i)->begin_x)
			{
				(player + i)->left = 0;
				(player + i)->right = 1;
				(player + i)->x += 3;
			}
			else
			{
				(player + i)->right = 0;
			}
			if ((player + i)->y > (player + i)->begin_y)
			{
				(player + i)->down = 0;
				(player + i)->up = 1;
				(player + i)->y -= 2;
			}
			else
			{
				(player + i)->up = 0;
			}
			if ((player + i)->y < (player + i)->begin_y)
			{
				(player + i)->up = 0;
				(player + i)->down = 1;
				(player + i)->y += 2;
			}
			else
			{
				(player + i)->down = 0;
			}

			if (sqrt(((player + i)->x - (player + i)->begin_x) * ((player + i)->x - (player + i)->begin_x) + ((player + i)->y - (player + i)->begin_y) * ((player + i)->y - (player + i)->begin_y)) <= 50)
				(player + i)->back = 0;
			continue;
		}

		if (ball->owner >= 0 && ball->owner < 10)
		{
			if (i >= 0 && i < 10)
				if_sameteam = 1;
		}
		else if (ball->owner >= 10 && ball->owner < 20)
		{
			if (i >= 10 && i < 20)
				if_sameteam = 1;
		}

		if (((player + i)->x - ball->x) * ((player + i)->x - ball->x) + ((player + i)->y - ball->y) * \
			((player + i)->y - ball->y) < 10000 && if_sameteam == 0 && sqrt(((player + i)->x - (player + i)->begin_x) * \
				((player + i)->x - (player + i)->begin_x) + ((player + i)->y - (player + i)->begin_y) * ((player + i)->y - (player + i)->begin_y)) < 100)
		{
			if (((player + i)->x- ball->x) * ((player + i)->x- ball->x) + ((player + i)->y- ball->y) * ((player + i)->y - ball->y) > 0)
			{
				if ((player + i)->x > ball->x)
				{

					(player + i)->left = 1;
					(player + i)->x -= 5;
				}
				else
				{
					(player + i)->left = 0;
				}
				if ((player + i)->x < ball->x)
				{
					(player + i)->right = 1;
					(player + i)->x += 5;
				}
				else
				{
					(player + i)->right = 0;
				}
				if ((player + i)->y > ball->y)
				{
					(player + i)->up = 1;
					(player + i)->y -= 1;
				}
				else
				{
					(player + i)->up = 0;
				}
				if ((player + i)->y < ball->y )
				{
					(player + i)->down = 1;
					(player + i)->y += 1;
				}
				else
				{
					(player + i)->down = 0;
				}
			}
		}
		else   //如果球不在附近 ，继续自由移动
		{
			if ((player + i)->x > (player + i)->begin_x)
			{
				(player + i)->left = 1;
				(player + i)->x -= 3;
			}
			else
			{
				(player + i)->left = 0;
			}
			if ((player + i)->x < (player + i)->begin_x)
			{
				(player + i)->right = 1;
				(player + i)->x += 2;
			}
			else
			{
				(player + i)->right = 0;
			}
			if ((player + i)->y > (player + i)->begin_y)
			{
				(player + i)->up = 1;
				(player + i)->y -= 2;
			}
			else
			{
				(player + i)->up = 0;
			}
			if ((player + i)->y < (player + i)->begin_y)
			{
				(player + i)->down = 1;
				(player + i)->y += 3;
			}
			else
			{
				(player + i)->down = 0;
			}
			if (sqrt(((player + i)->x - (player + i)->begin_x) * ((player + i)->x - (player + i)->begin_x) + ((player + i)->y - (player + i)->begin_y) * ((player + i)->y - (player + i)->begin_y)) < 5)
			{
				if ((player + i)->begin_x != (player + i)->position_x[0] || (player + i)->begin_y != (player + i)->position_y[0])
				{
					//(player + i)->begin_x = (player + i)->position_x[(player + i)->state];
					//(player + i)->begin_y = (player + i)->position_y[(player + i)->state];
					(player + i)->begin_x = (player + i)->position_x[0];
					(player + i)->begin_y = (player + i)->position_y[0];
				}
				else
				{
					(player + i)->begin_x = rand() % 50 - 25 + (player + i)->position_x[0];
					(player + i)->begin_y = rand() % 50 - 25 + (player + i)->position_y[0];
				}
			}
		}

		/*static clock_t start, again;
		static double time_1, time_2;
		double timing;
		static int m = 1;
		if (m)
		{
			start = clock();
			time_1 = (double)start / CLK_TCK;
			m--;
		}
		again = clock();
		time_2 = (double)again / CLK_TCK;
		timing = time_1 - time_2;
		if (timing >= 0.5)
		{*/
		if (if_sameteam == 0 &&(((player + i)->x - ball->x) * ((player + i)->x - ball->x) + ((player + i)->y - ball->y) * ((player + i)->y - ball->y) < 225))
			strugle(ball, player, i);
		if_sameteam = 0;
	}
}

void strugle_player(struct Player_IG* player, struct Ball* ball, int i)
{
	if (i != ball->owner)
	{
		if (abs((player + i)->x - ball->x) <40 &&abs((player + i)->y - ball->y)  < 40)
		{
			if (rand() % 9 < ((0.3 + ((player + i)->defend - (player + ball->owner)->control) * 0.05) * 10))
			{
				(player + ball->owner)->haveball = 0;
				(player + i)->haveball = 1;
				ball->min_num = i;
				ball->owner = i;
			}
		}
	}
}

void strugle(struct Ball* ball, struct  Player_IG* player, int i)
{
	static int times[20] = { 0 };
	times[i]++;
	if (i >= 10 && i <= 19)
	{
		if (times[i] != 10)
			return;
		else
			times[i] = 0;
	}
	if ((player + i)->haveball == 0)
	{
		(player + ball->owner)->haveball = 0;
		(player + i)->haveball = 1;
		ball->min_num = i;
		ball->owner = i;
	}
}

void tip_ball_out(struct Ball* ball, struct Player_IG* player)
{
	ball->ballrun = 0;
	ball->owner = -1;
	setfillstyle(1, LIGHTGRAY);
	bar(150, 160, 490, 280);
	if (ball->team == 1)
	{
		ball->team = 2;
		puthz(200, 210, "我方球出界，对方发球", 24, 24, BLACK);
		set_position(player, ball, 1);
		delay(2000);
	}
	else if (ball->team == 2)
	{
		ball->team = 1;
		puthz(200, 210, "对方球出界，我方发球", 24, 24, BLACK);
		set_position(player, ball, 2);
		delay(2000);
	}
}

void tip_ball_in(struct Ball* ball,struct Player_IG *player)
{
	ball->ballrun = 0;
	ball->owner = -1;
	setfillstyle(1, LIGHTGRAY);
	bar(150, 160, 490, 280);
	if (ball->team == 1)
	{
		ball->team = 2;
		puthz(200, 210, "我方进球，对方发球", 24, 24, BLACK);
		set_position(player, ball, 1);
		ball->score_we++;
		delay(2000);
	}
	else if (ball->team == 2)
	{
		ball->team = 1;
		puthz(200, 210, "对方进球，我方发球", 24, 24, BLACK);
		set_position(player, ball, 2);
		ball->score_en++;
		delay(2000);
	}
}


