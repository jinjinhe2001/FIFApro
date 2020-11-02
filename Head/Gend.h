#ifndef _Gend_h
#define _Gend_h

int Gend(USER *u, struct Ball* ball,int flag);			//总结界面总函数 
void draw_Gend(USER* u, struct Ball* ball);				//总结界面画图 
int func_Gend();								//总结界面功能 
void Minfo_input(USER *u);						//金币信息写入 
void lightbuttonGend(int x, int y, int x1, int y1, int color1, int color2, int flag);//按钮点亮 
void recoverbuttonGend(int status);													//按钮恢复 



#endif
