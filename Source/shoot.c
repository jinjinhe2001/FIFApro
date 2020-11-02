#include"shoot.h"

int game_shoot(int i)
{
	int flag=0;
	int goal=0;
	int count = 0;
	char goalstr[6];

	settextstyle(0,0,2);
	srand((unsigned)time(NULL));

	clrmous(MouseX, MouseY);
	draw_shoot();
	Saying(0);
	setcolor(WHITE);
	puthz(10, 20, "进球数：", 16, 16, WHITE);
	itoa(goal,goalstr,10);
	outtextxy(80,21,goalstr);
	flag=1;
	if (i == 0)
	{
		while (1)
		{
		
			newmouse(&MouseX, &MouseY, &press);
			if (flag == 0)
			{
				clrmous(MouseX, MouseY);
				draw_shoot();
				Saying(0);
				setcolor(WHITE);
				puthz(10, 20, "进球数：", 16, 16, WHITE);
				itoa(goal, goalstr, 10);
				outtextxy(80, 21, goalstr);
				flag = 1;
			}
			if (MouseX > 80 && MouseX < 560 && MouseY>65 && MouseY < 240)
			{
				if (mouse_press(80, 65, 560, 240) == 2)
				{
					MouseS = 1;
					continue;
				}
				else if (mouse_press(80, 65, 560, 240) == 1)
				{
					MouseS = 0;
					clrmous(MouseX, MouseY);
					goal += shooting();

					count++;
					if (count >= 5)
					{
						itoa(goal, goalstr, 10);
						outtextxy(80, 21, goalstr);
						Pshowing(goalstr);	
						break;
					}
					
					printf("%d", goal);
					flag = 0;
					continue;
				}
			}
			if (MouseS != 0)
			{
				MouseS = 0;
			}
		}
	}
	else
	{
		while (1)
		{
			newmouse(&MouseX, &MouseY, &press);

			clrmous(MouseX, MouseY);
			draw_shoot();
			Saying(3);
			setcolor(WHITE);
			puthz(10, 20, "进球数：", 16, 16, WHITE);
			itoa(goal, goalstr, 10);
			outtextxy(80, 21, goalstr);
			flag = 1;		
			delay(1000);

			MouseS = 0;
			goal += shootingAI();
			count++;
			if (count >= 5)
			{
				itoa(goal, goalstr, 10);
				outtextxy(80, 21, goalstr);
				Pshowing(goalstr);
				break;
			}
				
			printf("%d", goal);
			flag = 0;
		}
	}

	return goal;
} 
 
void draw_shoot()
{
	cleardevice();
	setfillstyle(1, LIGHTBLUE);
	bar(0,0,639,480);
	setfillstyle(1, GREEN);
	bar(0,240,639,480);
	
	setfillstyle(1, WHITE);
	bar(75,240,565,245);
	bar(80,240,75,60);
	bar(80,60,560,65);
	bar(560,60,565,240);
	
	setfillstyle(1, LIGHTGRAY);
	bar(80,240,560,65);
	draw_ball(320,320,20);
	draw_player(320,240); 
}
void draw_ball(int x,int y,int ratio)
{
	setcolor(BLACK);
	setfillstyle(1, WHITE);
	fillellipse(x, y, ratio, ratio);
	setlinestyle(0, 0, 1);
	line(x-ratio,y,x+ratio,y);
	line(x,y-ratio,x,y+ratio);
}
void draw_player(int x,int y)
{      	
	setfillstyle(1, WHITE);
	setcolor(BLACK);
	bar(x,y-35,x+35,y-30);
	bar(x,y-35,x-35,y-30);	
	fillellipse(x + 35 , y - 32, 9, 9); 
	fillellipse(x - 35 , y - 32, 9, 9); 
	fillellipse(x - 15 , y + 6, 9, 9);   
	fillellipse(x +15,y + 6 , 9, 9); 
	fillellipse(x, y - 21 , 18, 30);    
	fillellipse(x, y - 60 , 15, 15);    
}
void Saying(int word)
{
	if(word==0)
	{
		puthz(180, 0, "请点击灰色区域射门", 32, 32, WHITE);
	}
	if(word==1)
	{
		puthz(240, 0, "球没进", 32, 32, WHITE);
	}
	if(word==2)
	{
		puthz(240, 0, "进球了！", 32, 32, WHITE);
	}
	if (word == 3)
	{
		puthz(200, 0, "对方自动点球", 32, 32, WHITE);
	}
	
}
int shooting()
{ 
	int x=0,y=0;
	int disx,disy;
	int pat=rand()%2;
	clrmous(MouseX, MouseY);
	if(pat==0)
	{
	//	while(x<80||x>560)
			//x=rand()%150-75+MouseX;
		//while(y<65||y>240)
		//	y=rand()%120-60+MouseY;
		x=MouseX+rand()%100-50;
		y=MouseY+30+rand()%100-50;
	}
	else
	{
		x=rand()%480+80;
		y=rand()%175+65;
	}
	
	
	setfillstyle(1, LIGHTBLUE);
	bar(0,0,639,240);
	setfillstyle(1, GREEN);
	bar(0,240,639,350);
	
	setfillstyle(1, WHITE);
	bar(75,240,565,245);
	bar(80,240,75,60);
	bar(80,60,560,65);
	bar(560,60,565,240);
	
	setfillstyle(1, LIGHTGRAY);
	bar(80,240,560,65);
	draw_player(x,y); 
	draw_ball(MouseX,MouseY,20);

	disx=abs(MouseX-x);
	disy=abs(MouseY-y+30);
	if(disx<40&&disy<60)
	{
		Saying(1);
		delay(3000);
		return 0;
	}
	else
	{
		Saying(2);
		delay(3000);
		return 1;
	}
}
int shootingAI()
{
	int x = 0, y = 0;
	int ball_x, ball_y;
	int disx, disy;
	int pat = rand() % 2;
	clrmous(MouseX, MouseY);

	ball_x = rand() % 480 + 80;
	ball_y = rand() % 175 + 65;
	if (pat == 0)
	{
		//	while(x<80||x>560)
				//x=rand()%150-75+MouseX;
			//while(y<65||y>240)
			//	y=rand()%120-60+MouseY;
		x = ball_x + rand() % 100 - 50;
		y = ball_y + 30 + rand() % 100 - 50;
	}
	else
	{
		x = rand() % 480 + 80;
		y = rand() % 175 + 65;
	}


	setfillstyle(1, LIGHTBLUE);
	bar(0, 0, 639, 240);
	setfillstyle(1, GREEN);
	bar(0, 240, 639, 350);

	setfillstyle(1, WHITE);
	bar(75, 240, 565, 245);
	bar(80, 240, 75, 60);
	bar(80, 60, 560, 65);
	bar(560, 60, 565, 240);

	setfillstyle(1, LIGHTGRAY);
	bar(80, 240, 560, 65);
	draw_player(x, y);
	draw_ball(ball_x, ball_y, 20);

	disx = abs(ball_x - x);
	disy = abs(ball_y - y + 30);
	if (disx < 40 && disy < 60)
	{
		Saying(1);
		delay(3000);
		return 0;
	}
	else
	{
		Saying(2);
		delay(3000);
		return 1;
	}
}
void Pshowing(char *goalstr)
{	
	setfillstyle(1, BLACK);
	bar(158, 118, 482, 282);
	setfillstyle(1, LIGHTGRAY);
	bar(160, 120, 480, 280);
	puthz(170,130,"进球数：",24,24,BLACK);
	outtextxy(270, 134, goalstr);

	
	delay(3000);
	return ;
}
