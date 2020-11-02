#ifndef _maindou_h
#define _maindou_h


int choose_main_double(USER* u); //双人选择主控界面
void draw_22();  //画双人界面
int functwotwo(USER* u);//判断鼠标操作
void lightbutton22(int x, int y, int x1, int y1, int color1, int color2, int flag);//点亮按钮
void recoverbutton22(int status);//回复按钮
void recoverhz22(int flag);//汉字恢复
void lighthz22(int num, int flag);//点亮汉字

#endif