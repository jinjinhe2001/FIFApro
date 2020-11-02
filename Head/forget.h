#ifndef _FORGETPASS_H
#define _FORGETPASS_H

int forget();		//忘记密码总函数 
void draw_forget();	//画界面 
void lightbutton_forget(int x, int y, int x1, int y1, int color1, int color2, int flag);//按钮点亮 
void recoverbutton_forget(int status);				//按钮恢复 

#endif
