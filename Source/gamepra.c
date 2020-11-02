#include"gamepra.h"
#include"map.h"
#include"int.h"
#include"game.h"

void gamepra()
{
	int gameDriver = VGA;
	int gameMode = VGAMED;
	float camera_x = 0, camera_y = 0;
	unsigned int page;
	clock_t now, last;  //用于屏幕切换
	struct Ball* ball;
	struct Player_IG* player;
	struct GameKey* gameKey = getGameKey();
	//从prepare传参过来，用于初始化球员能力值
	initgraph(&gameDriver, &gameMode, "C:\\BORLANDC\\BGI");

	ball = (struct Ball*)malloc(sizeof(struct Ball));
	player = (struct Player_IG*)malloc(sizeof(struct Player_IG));

	read_field();
	bar(0, 0, 640, 480);
	setbkcolor(GREEN);
	ball->x = 320;
	ball->y = 240;
	player->x = 300;
	player->y = 200;
	now = clock();
	init_newint9_game();
	while (1)
	{
		if (escHit)
		{
			cancel_newint9_game();
			free(player);
			free(ball);
			return -2;
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
		if (last != now)
		{
			page++;
			setactivepage(page % 2);
			putField(camera_x, camera_y, page % 2);
			show_screen_pra(camera_x, camera_y, player, ball, page % 2);
			setvisualpage(page % 2);
			last = now;
		}
		setKeyPressed();
		updateWithInput_pra(player, ball, gameKey, camera_x, camera_y);
		updateWithoutInput_pra(player, ball);
		delay(40);
	}
}

void show_screen_pra(int x0, int y0, struct Player_IG* player, struct Ball* ball, int page)
{
	//显示计分板和时间
	//放置球员		
	show_player_pra(x0, y0, player, ball);
	show_ball_pra(x0, y0, ball);
}

void show_ball_pra(int x0, int y0, struct Ball* ball)
{
	setfillstyle(1, WHITE);
	fillellipse(ball->x - x0, ball->y - y0, 5, 5);	//放置足球
	setcolor(BLACK);
	setlinestyle(0, 0, 1);
	line(ball->x - x0, ball->y + 5 - y0, ball->x - x0, ball->y - 5 - y0);
	line(ball->x - 5 - x0, ball->y - y0, ball->x + 5 - x0, ball->y - y0);
}

void show_player_pra(int x0, int y0, struct Player_IG* player, struct Ball* ball)
{
	setfillstyle(1, BLUE);
	fillellipse(player->x - 10 - x0, player->y + 2 - y0, 3, 3);   //左脚
	fillellipse(player->x - 5 - x0, player->y - 7 - y0, 6, 10);    //头
	fillellipse(player->x - 6 - x0, player->y - 20 - y0, 5, 5);    //身体
	fillellipse(player->x - x0, player->y + 2 - y0, 3, 3);    //右脚

	textcolor(BLACK);
	settextstyle(0, 0, 1);
	outtextxy(player->x - x0 - 10, player->y - y0 - 30, "player");

}

void updateWithInput_pra(struct Player_IG* player, struct Ball* ball, struct GameKey* gameKey, int x0, int y0)
{

	player->left = 0;
	player->right = 0;
	player->up = 0;
	player->down = 0;

	//键盘操控球员具体实现
	if (gameKey->j.pressed)  //将球踢出
	{
		if (player->haveball == 1)
		{
			player->haveball = 0;
			ball->ballrun = 8;  
		}
	}
	if (gameKey->a.pressed)
	{
		player->x -= 7;
		player->left = 1;
		player->lastdirection = 1;
		player->right = 0;
	}
	else
	{
		player->left = 0;
	}

	if (gameKey->d.pressed)
	{
		player->x += 7;
		player->right = 1;
		player->lastdirection = 2;
		player->left = 0;
	}
	else
	{
		player->right = 0;
	}

	if (gameKey->w.pressed)
	{
		player->y -= 6;
		player->up = 1;
		player->lastdirection = 3;
		player->down = 0;
	}
	else
	{
		player->up = 0;
	}

	if (gameKey->s.pressed)
	{
		player->y += 6;
		player->down = 1;
		player->lastdirection = 4;
		player->up = 0;
	}
	else
	{
		player->down = 0;
	}
}

void updateWithoutInput_pra(struct Player_IG* player, struct Ball* ball)
{
	if (ball->owner != -1)
	{
		ball->left = (player + ball->owner)->left;
		ball->right = (player + ball->owner)->right;
		ball->up = (player + ball->owner)->up;
		ball->down = (player + ball->owner)->down;
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
	if ((player->x - ball->x) * (player->x - ball->x) + (player->y - ball->y) * (player->y - ball->y) < 225)
	{
		ball->owner = 0;
		ball->ballrun = 0;
		(player + ball->owner)->haveball = 1;
		ball->left = (player + ball->owner)->left;
		ball->right = (player + ball->owner)->right;
		ball->up = (player + ball->owner)->up;
		ball->down = (player + ball->owner)->down;
	}
	else
	{
		player->haveball = 0;
	}
	//根据球员方向，改变球的放置位置
	if (ball->owner != -1)
	{
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
}