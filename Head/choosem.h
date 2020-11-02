#ifndef _choosemain_h
#define _choosemain_h

int choosemain(USER *u);//选择主函数界面
void drawback_2(USER *u); //画主选择页面
int func2();  //判断鼠标操作点击按钮
void lightbutton2(int x, int y, int x1, int y1, int color1, int color2, int flag);//触碰按钮点亮
void recoverbutton2(int status);//从按钮移开复原

#endif
