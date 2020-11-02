#ifndef _signin_h
#define _signin_h

int signin(USER *u);				//登录总函数 
void draw_signin();					//画登录界面 
int func_0(USER *u);				//功能函数 
void lightbutton_login(int x, int y, int x1, int y1, int color1, int color2, int flag);	//点亮按钮 
void recoverbutton_login(int status);	//恢复按钮 
void draw_bk();	//背景画图 
#endif
