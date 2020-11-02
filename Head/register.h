#ifndef _register_h
#define _register_h

int registerup();			//创建界面函数 
void draw_rg(char *str);	//画界面 
void random_str(char* str);	//随机号  
void lightbutton_register(int x, int y, int x1, int y1, int color1, int color2, int flag);//点亮 
void recoverbutton_register(int status);//恢复按钮 
#endif
