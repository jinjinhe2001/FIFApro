#ifndef _gamepra_h
#define _gamepra_h
void gamepra();//练习模式主控函数
void show_screen_pra(int x0, int y0, struct Player_IG* player, struct Ball* ball, int page);//画练习模式
void show_ball_pra(int x0, int y0, struct Ball* ball);//画球
void show_player_pra(int x0, int y0, struct Player_IG* player, struct Ball* ball);//画球员
void updateWithInput_pra(struct Player_IG* player, struct Ball* ball, struct GameKey* gameKey, int x0, int y0);//双人操控
void updateWithoutInput_pra(struct Player_IG* player, struct Ball* ball);//更新与操作无关的球员信息

#endif