#ifndef _PSTDIO_H_
#define _PSTDIO_H_

int Pstdio(USER *u);				//球员创建主函数 
void draw_Pstdio(Player *player);	//画界面函数 
int func_212(USER *u,Player *player,int *num,int *state,int *delmoney);//功能主函数 
void changemoney(int *delmoney,Player *player,int *pre_all);	//改变金币 
void lightbutton_P(int x, int y, int x1, int y1, int color1, int color2, int flag);//点亮 
void recoverbutton_P(int status);//恢复 
void inputadminP(char* id, int x1, int y1, int charnum, int color);//输入名字 
void drawC(int x,int y,int ratio,int color);//画衣服 
void drawcross(int x,int y,int length,int high,int color);//画十字 x，y为中心位置 
void drawcross1(int x,int y,int length,int high,int color);//画-字 
void recovercross();				//恢复+-号 
void changeAll(Player *player, int flag);//改变总能力条 
void changespeed(Player *player, int flag);//改变速度能力条 
void changecontrol(Player *player, int flag);//改变控制能力条 
void changepower(Player *player, int flag);//改变力量能力条 
void changedefend(Player *player, int flag);//改变防守能力条 
void changeAbar(Player *player);			//改变条 
void randPnum(Player *player);				//随机球衣号 
int creat_complete(Player *player,int *delmoney,USER *u);//判断创建条件 
void input_pinfo(Player *player,USER *u,int *delmoney);//写入信息 
void Pwarning(int flag);				//弹框 
#endif
