#ifndef _DATA_H_
#define _DATA_H_

typedef struct userinfo
{
	char user[15];           //6-12位，账户 
	char password[20];       //8-16位，密码
	char phonenum[15];		//11位,电话号码 
	char money[7];//金币

}USER;	//封装用户信息

typedef struct playerinfo
{
	char player_num[3];  //球员球衣号
	char name[4];       //姓名
	char speed[2];      //速度
	char control[2];   //控球
	char power[2];		//力量
	char defend[2];		//防守
	char allA[3];// 用于检查是否分配完 
	int all;     // 总能力值
}Player; 
/*struct gamestruct
{
	int nation1;
	int nation2;
	int time;
};*/
#endif
