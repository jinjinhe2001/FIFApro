#ifndef _shoot_h
#define _shoot_h
#include"common.h" 

void draw_shoot();				//点球总界面 
void draw_ball(int x,int y,int ratio);//画球 
void draw_player(int x,int y);//画人 
void Saying(int word);//提示语 
int shooting();	//点球 
int shootingAI();//AI点球 
void Pshowing(char *goalstr);//最终总计进球 
#endif 
