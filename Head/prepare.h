#ifndef _prepare_h
#define _prepare_h

int prepare(USER* u); //单人准备游戏界面
void draw_prepare();//画界面
int func211(USER* u);//判断鼠标状态按钮
void lightbutton211(int x, int y, int x1, int y1, int color1, int color2, int flag);//点亮按钮
void recoverbutton211(int status);//恢复按钮
void recoverhz211(int flag);//回复汉字
void lighthz211(int num, int flag);//点亮汉字
void Pshowing_P();//提示框

#endif // !_prepare_h

