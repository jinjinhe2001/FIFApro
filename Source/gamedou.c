#include"common.h"
#include"gamedou.h"
#include"map.h"
#include"game.h"
#include"int.h"

int game_dou(int nation1, int nation2, int time, USER* u)
{
	int gameDriver = VGA;
	int gameMode = VGAMED;

	int gd = VGA;
	int gm = VGAHI;
	float camera_x = 0, camera_y = 0;
	unsigned int page;
	clock_t now, last;  //用于屏幕切换
	clock_t first, end;
	clock_t dertat;
	struct Ball* ball;
	struct Player_IG* player;
	struct GameKey* gameKey = getGameKey();
	//从prepare传参过来，用于初始化球员能力值
	initgraph(&gameDriver, &gameMode, "C:\\BORLANDC\\BGI");

	ball = (struct Ball*)malloc(sizeof(struct Ball));
	player = (struct Player_IG*)malloc(sizeof(struct Player_IG) * player_allnum);

	read_field();
	bar(0, 0, 640, 480);
	setbkcolor(GREEN);
	init_postion(player, ball);
	init_info_dou(player, ball,nation1, nation2);
	set_position(player, ball, 0);
	ball->score_we = 1;
	ball->score_en = 0;
	now = clock();
	first = now;
	init_newint9_game();
	while (1)
	{
		if (escHit)
		{
			cancel_newint9_game();
			break;
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
			show_screen_dou(camera_x, camera_y, player, ball, page % 2, dertat, time);
			setvisualpage(page % 2);
			last = now;
		}
		setKeyPressed();
		updateWithInput_dou(player, ball, gameKey, camera_x, camera_y);
		updateWithoutInput_dou(player, ball);
		delay(40);
		dertat = (end - first) / CLOCKS_PER_SEC;
		if (dertat >= 5)
		{	
			free(player);
			delay(100);
			while (ball->score_we == ball->score_en)
			{
				ball->score_we += game_shoot(0);
				ball->score_en += game_shoot(0);
			}
			Gend(u, ball, 2);
			free(ball);
			return -2;
		}
	}

}
void init_info_dou(struct Player_IG* player, struct Ball* ball,int nation1, int nation2)
{
	int i, j, k;//检测
	FILE* fp; //打开球员能力值文件
	FILE* ffp;
	Player *playerone;
	int len;
	char a[2];
	char b[6];

	if (nation1 == 0)
	{
		if ((fp = fopen("database\\team1.dat", "rb+")) == NULL)
		{
			printf("cannot open file UserData.dat");
			delay(3000);
			exit(1);
		}
	}
	else if (nation1 == 1)
	{
		if ((fp = fopen("database\\team2.dat", "rb+")) == NULL)
		{
			printf("cannot open file UserData.dat");
			delay(3000);
			exit(1);
		}
	}
	else if (nation1 == 2)
	{
		if ((fp = fopen("database\\team3.dat", "rb+")) == NULL)
		{
			printf("cannot open file UserData.dat");
			delay(3000);
			exit(1);
		}
	}
	else if (nation1 == 3)
	{
		if ((fp = fopen("database\\team4.dat", "rb+")) == NULL)
		{
			printf("cannot open file UserData.dat");
			delay(3000);
			exit(1);
		}
	}
	else if (nation1 == 4)
	{
		if ((fp = fopen("database\\team5.dat", "rb+")) == NULL)
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
		fseek(ffp, (i-10) * sizeof(Player), SEEK_SET);
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


	for (i = 0;i < 20;i++)
	{
		(player + i)->x = (player + i)->position_x[0];
		(player + i)->y = (player + i)->position_y[0];
	}
	for (i = 0;i < 20;i++)
	{
		(player + i)->begin_x = (player + i)->position_x[0];
		(player + i)->begin_y = (player + i)->position_y[0];
	}
	ball->x = 480;
	ball->y = 320;
	ball->position = 0;
	ball->owner = -1;
}

void show_screen_dou(int x0, int y0, struct Player_IG* player, struct Ball* ball, int page, clock_t derta, int time)
{
	//显示计分板和时间
	//放置球员		
	show_player(x0, y0, player, ball);
	//tips
	setfillstyle(1, LIGHTGRAY);
	fillellipse((player + ball->en_near)->x - x0 - 7, (player + ball->en_near)->y - y0 - 30, 5, 5);
	show_ball(x0, y0, ball);
	show_counter(ball, derta, time);
}

void updateWithInput_dou(struct Player_IG* player, struct Ball* ball, struct GameKey* gameKey, int x0, int y0)
{
	int mindistance = 1000;   //先初始化
	int min_num = 0;
	int we_near = 0;
	int en_near;
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
	mindistance = 1000;
	for (i = 10;i < 20;i++)
	{
		if ((player + i)->distance < mindistance)
		{
			mindistance = (player + i)->distance;
			en_near = i;
		}
		if ((player + i)->haveball)
		{
			en_near = i;
			break;
		}
	}
	ball->en_near = en_near;
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

	(player + we_near)->left = 0;
	(player + we_near)->right = 0;
	(player + we_near)->up = 0;
	(player + we_near)->down = 0;
	(player + en_near)->left = 0;
	(player + en_near)->right = 0;
	(player + en_near)->up = 0;
	(player + en_near)->down = 0;
	//键盘操控球员具体实现
	if (gameKey->j.pressed)  //将球踢出
	{
		if ((player + we_near)->haveball == 1)
		{
			(player + we_near)->haveball = 0;
			ball->ballrun = (player + we_near)->power+1;  //
		}
	}
	if (gameKey->k.pressed)  //抢球键
	{
		strugle_player(player, ball, we_near);
	}
	if (gameKey->a.pressed)
	{
		(player + we_near)->x -= ((player + we_near)->speed / 2 + 2);
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
		(player + we_near)->x += ((player + we_near)->speed / 2 + 2);
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
		(player + we_near)->y -= ((player + we_near)->speed / 2 + 2);
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
		(player + we_near)->y += ((player + en_near)->speed / 2 + 2);
		(player + we_near)->down = 1;
		(player + we_near)->lastdirection = 4;
		(player + we_near)->up = 0;
	}
	else
	{
		(player + we_near)->down = 0;
	}
	if (gameKey->up.pressed)
	{
		(player + en_near)->y -= ((player + en_near)->speed / 2 + 2);
		(player + en_near)->up = 1;
		(player + en_near)->lastdirection = 3;
		(player + en_near)->down = 0;
	}
	else
		(player + en_near)->up = 0;
	if (gameKey->down.pressed)
	{
		(player + en_near)->y += ((player + en_near)->speed / 2 + 2);
		(player + en_near)->down = 1;
		(player + en_near)->lastdirection = 4;
		(player + en_near)->up = 0;
	}
	else
		(player + en_near)->down = 0;
	if (gameKey->left.pressed)
	{
		(player + en_near)->x -= ((player + en_near)->speed / 2 + 2);
		(player + en_near)->left = 1;
		(player + en_near)->lastdirection = 1;
		(player + en_near)->right = 0;
	}
	else
	{
		(player + en_near)->left = 0;
	}

	if (gameKey->right.pressed)
	{
		(player + en_near)->x += ((player + en_near)->speed / 2 + 2);
		(player + en_near)->right = 1;
		(player + en_near)->lastdirection = 2;
		(player + en_near)->left = 0;
	}
	else
	{
		(player + en_near)->right = 0;
	}
	if (gameKey->one.pressed)  //将球踢出
	{
		if ((player + en_near)->haveball == 1)
		{
			(player + en_near)->haveball = 0;
			ball->ballrun = (player + we_near)->power + 1; //
		}
	}
	if (gameKey->three.pressed)  //抢球键
	{
		strugle_player(player, ball, en_near);
	}
}

void updateWithoutInput_dou(struct Player_IG* player, struct Ball* ball)
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
	}
	if (ball->ballrun > 0)
	{

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
	if (((player + ball->min_num)->x - ball->x) * ((player + ball->min_num)->x - ball->x) + ((player + ball->min_num)->y - ball->y) * ((player + ball->min_num)->y - ball->y) < 400 && ball->owner == -1)
	{
		ball->owner = ball->min_num;
		ball->ballrun = 0;
		(player + ball->owner)->haveball = 1;
		ball->left = (player + ball->owner)->left;
		ball->right = (player + ball->owner)->right;
		ball->up = (player + ball->owner)->up;
		ball->down = (player + ball->owner)->down;
		if (ball->owner >= 0 && ball->owner <= 9)
			ball->team = 1;
		if (ball->owner >= 10 && ball->owner <= 19)
			ball->team = 2;
	}

	// 判断球的位置，改变position参数
	//此处需要添加一个参数，根据持球人，确定出界或进球后的球权归属
	//此处判断无需加上镜头偏移量
	//这里的的出界进球范围yi修改
	if (ball->y <= -(510 / 74) * (ball->x - 23) + 560 || ball->y <= (510 / 74) * (ball->x - 937) + 578 || ball->y < 70 || ball->y>578)
	{
		ball->position = -1;
		if (ball->y >= 270 && ball->y <= 330)
			ball->position = 1;
	}
	if (ball->position == 1)
		tip_ball_in(ball, player);
	if (ball->position == -1)
		tip_ball_out(ball, player);
	player_magicmove_dou(player, ball);
}
void player_magicmove_dou(struct Player_IG* player, struct Ball* ball)
{
	int if_sameteam = 0;
	static long int k = 0;
	int i;
	k++;
	for (i = 0;i < player_allnum;i++)
	{
		if (i == ball->we_near || i == ball->owner || i == ball->en_near)
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
			if (((player + i)->x - ball->x) * ((player + i)->x - ball->x) + ((player + i)->y - ball->y) * ((player + i)->y - ball->y) > 0)
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
				if ((player + i)->y < ball->y)
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
		if (if_sameteam == 0 && (((player + i)->x - ball->x) * ((player + i)->x - ball->x) + ((player + i)->y - ball->y) * ((player + i)->y - ball->y) < 225))
			strugle(ball, player, i);
		if_sameteam = 0;
	}
}