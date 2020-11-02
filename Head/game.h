#ifndef _game_h
#define _game_h


#define player_allnum 20
//#define G_X_MAX 640
//#define G_Y_MAX 350

struct Player_IG
{
	int id;
	double x, y;    //球员的坐标
	double begin_x, begin_y;    //球员magicmove  的中心位置
	double possiblity;
	double distance;   //球员距离球的距离
	int haveball;    //球员是否有球
	int left, right, up, down, lastdirection;   // 球员方向
	int stage_idle;
	int state;  //防守对应state=0    进攻对应state=1
	int back;
	double position_x[2];   // 球员中心位置
	double position_y[2];   //球员中心位置
	int speed;				//速度能力值	
	int power;				//力量能力值
	int control;			//控球能力值
	int defend;				//防守能力值
};

struct Ball
{
	double x, y;   //球的坐标
	double ballrun;				//球是否移动
	int left, right, up, down;   //球的方向
	int owner;				//当前持球者
	int min_num;		//离球最近球员
	int position;        //-1界外，0界内，1进球
	int we_near;			//左方离球最近的球员
	int en_near;			//右方离球最近球员
	int score_we, score_en;    //何方得分
	int team;        //0代表无人控球；1代表左边控球；2代表右边控球
};
//unsigned char getMirrorChar(unsigned char src);
//static unsigned char getCharFromField(int row, int col);
//void putField(int x0, int y0, int page);
int game(int nation, int nation2, int time, USER* u);      //游戏主控函数
void init_info(struct Player_IG* player, struct Ball* ball, int nation, int nation2, USER* u);//初始化球员信息，从文件中读取
void show_screen(int x0, int y0, struct Player_IG* player, struct Ball* ball, int page, clock_t derta, int time);  //显示整个屏幕画面
void show_counter(struct Ball* ball, clock_t derta, int time);     //显示计分板和时间

void show_player(int x0, int y0, struct Player_IG* player, struct Ball* ball);//画球员
void show_ball(int x0, int y0, struct Ball* ball); //画球
void updateWithInput(struct Player_IG* player, struct Ball* ball, struct GameKey* gameKey, int x0, int y0); //键盘操作控制球员
void updateWithoutInput(struct Player_IG* player, struct Ball* ball); //与输入无关的信息更新
void strugle_player(struct Player_IG* player, struct Ball* ball, int i);//操控方劫球
void player_AI(struct Player_IG* player, struct Ball* ball);//非操控球员的自主移动
void change_position(struct Player_IG* player, struct Ball* ball);//改变球员中心坐标
void player_magicmove(struct Player_IG* player, struct Ball* ball);//球员的自主移动
void player_atk(struct Player_IG* player, struct Ball* ball);   //电脑方球员进攻策略
void strugle(struct Ball* ball,struct Player_IG* player, int i);     //自动抢球
void tip_ball_in(struct Ball* ball, struct Player_IG* player);  //进球提示框
void tip_ball_out(struct Ball* ball, struct Player_IG* player);//出界提示框
void init_postion(struct Player_IG* player, struct Ball* ball);//加载初始信息
void set_position(struct Player_IG* player, struct Ball* ball, int flag); //根据球的所属改变球员中心位置



#endif // !_game_h

