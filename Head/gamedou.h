#ifndef  _gamedou_h
#define  _gamedou_h

int game_dou(int nation1, int nation2, int time, USER* u);//双人游戏主控函数
void init_info_dou(struct Player_IG* player, struct Ball* ball, int nation1, int nation2);//载入双方球员信息
void show_screen_dou(int x0, int y0, struct Player_IG* player, struct Ball* ball, int page, clock_t derta, int time);//画屏幕
void updateWithInput_dou(struct Player_IG* player, struct Ball* ball, struct GameKey* gameKey, int x0, int y0);//操控函数
void updateWithoutInput_dou(struct Player_IG* player, struct Ball* ball);//双人游戏与操作无关的信息更新
void player_magicmove_dou(struct Player_IG* player, struct Ball* ball);//双人游戏的球员AI

#endif // ! _game_double_h

