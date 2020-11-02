#ifndef _team_h
#define _team_h
 
#include"common.h" 
int team(USER *u);//球队管理主控函数
void draw_team();//画teanm界面
int func213(Player* player_create, int player_tem[], USER* u, int check[]);//判断鼠标位置
void show_team(int num, USER *u, Player* player_create, int *create, int player_tem[]);//展示球队信息
void recoverhz2(int num);//点亮汉字
void drawC2(int x, int y, int ratio, int color); //画球衣
void show_list(int state, USER *u);//展示对应球员列表
void show_ability(int i, int num, Player* player_create, int* create, USER* u, int delete_num, int player_tem[], int flag, int check[]);//展示球员参数
void show_clo(int num, USER *u, Player *player_create, int* create, int player_tem[]); //展示球衣号
void lightbuttonteam(int x, int y, int x1, int y1, int color1, int color2, int flag);//点亮按钮
void recoverbuttonteam(int status);//回复按钮
void input_file(Player* player_create, int* create, USER* u); //将球队写入文件
void delete_player(Player* player_create, int delete_num);//删除球员
void warn_no(); //提示不能创建


 
#endif // !_team_h

