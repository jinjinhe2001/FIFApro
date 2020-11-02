#include"int.h"

void interrupt (*oldint9)()=NULL;
void interrupt (*oldint1c)()=NULL;

void installInt(void interrupt (*faddr)(),char intNum){
	disable();
	setvect(intNum,faddr);
	enable();
}




int escHit;
void interrupt newint9_esc(unsigned bp,unsigned di,  
	unsigned si,unsigned ds,unsigned es,unsigned dx, 
	unsigned cx,unsigned bx,unsigned ax,unsigned ip, 
	unsigned cs,unsigned flags){
	
	if(inportb(0x60)==1){
		
		escHit=inportb(0x61);
		outportb(0x61,escHit);
		outportb(0x20,0x20);
		escHit=1;
	}else (*oldint9)();
	
}
void init_newint9_esc(){
	if(oldint9==NULL){
		oldint9=getvect(9);
	}
	escHit=0;
	installInt(newint9_esc,0x09);
}
void cancel_newint9_esc(){
	if(oldint9==NULL){
		return ;
	}
	installInt(oldint9,0x09);
	escHit=0;
}

//游戏键盘中断
struct GameKey* getGameKey(){
	static struct GameKey* gameKey=NULL;
	if(gameKey==NULL){
		gameKey=(struct GameKey*)malloc(sizeof(struct GameKey));
		memset(gameKey,0,sizeof(struct GameKey));
	}
	return gameKey;
}


static unsigned char near stack_game[0x1000]={0};
int busyGameKey=0;
static unsigned int sp_game;
static unsigned int ss_game;
void interrupt newint9_game(unsigned bp,unsigned di, 
	unsigned si,unsigned ds,unsigned es,unsigned dx, 
	unsigned cx,unsigned bx,unsigned ax,unsigned ip, 
	unsigned cs,unsigned flags){
	if(busyGameKey){
		//outportb(0x61,inportb(0x61));
		//outportb(0x20,0x20);
		dealGameKey();
		return ;
	}
	busyGameKey=1;
	disable();
	sp_game=_SP;
	ss_game=_SS;
	_SP=(unsigned)&stack_game[0x1000-2];
	_SS=(unsigned)stack_game;
	enable();
	
	dealGameKey();
	
	disable();
	_SP=sp_game;
	_SS=ss_game;
	enable();
	busyGameKey=0;
}

void dealGameKey(){
	struct GameKey* gameKey=getGameKey();
	
	unsigned char key=inportb(0x60);

   outportb(0x61,inportb(0x61));
	outportb(0x20,0x20);
	if((0x7f&key)==0x11){
		if((key&0x80))gameKey->w.state=0;
		else {
			gameKey->w.state=1;
			gameKey->w.pressed=1;
		}
	}else if((0x7f&key)==0x1e){
		if((key&0x80))gameKey->a.state=0;
		else {
			gameKey->a.state=1;
			gameKey->a.pressed=1;
		}
	}else if((0x7f&key)==0x1f){
		if((key&0x80))gameKey->s.state=0;
		else {
			gameKey->s.state=1;
			gameKey->s.pressed=1;
		}
	}else if((0x7f&key)==0x20){
		if((key&0x80))gameKey->d.state=0;
		else {
			gameKey->d.state=1;
			gameKey->d.pressed=1;
		}
	}else if((0x7f&key)==0x24){
		if((key&0x80))gameKey->j.state=0;
		else {
			gameKey->j.state=1;
			gameKey->j.pressed=1;
		}
	}else if((0x7f&key)==0x25){
		if((key&0x80))gameKey->k.state=0;
		else {
			gameKey->k.state=1;
			gameKey->k.pressed=1;
		}
	}else if ((0x7f & key) == 0x48) {
		//上箭头
		if ((key & 0x80))gameKey->up.state = 0;
		else {
			gameKey->up.state = 1;
			gameKey->up.pressed = 1;
		}
	}
	else if ((0x7f & key) == 0x4b) {
		//左箭头
		if ((key & 0x80))gameKey->left.state = 0;
		else {
			gameKey->left.state = 1;
			gameKey->left.pressed = 1;
		}
	}
	else if ((0x7f & key) == 0x50) {
		//下箭头
		if ((key & 0x80))gameKey->down.state = 0;
		else {
			gameKey->down.state = 1;
			gameKey->down.pressed = 1;
		}
	}
	else if ((0x7f & key) == 0x4d) {
		//右箭头
		if ((key & 0x80))gameKey->right.state = 0;
		else {
			gameKey->right.state = 1;
			gameKey->right.pressed = 1;
		}
	}
	else if ((0x7f & key) == 0x4f) {
		//数字键盘1
		if ((key & 0x80))gameKey->one.state = 0;
		else {
			gameKey->one.state = 1;
			gameKey->one.pressed = 1;
		}
	}
	else if ((0x7f & key) == 0x51) {
		//数字键盘3
		if ((key & 0x80))gameKey->three.state = 0;
		else {
			gameKey->three.state = 1;
			gameKey->three.pressed = 1;
		}
	}
	else if((0x7f&key)==1){
		escHit=1;
	}
}
#define KEY_NUM 12
void setKeyPressed(){
	int i;
	struct Key* key=(struct Key*)getGameKey();
	for(i=0;i<KEY_NUM;i++){
		if((key+i)->state==0){
			(key+i)->pressed=0;
		}
	}
	escHit=0;
}

void clearGameKey(){
	struct GameKey* gameKey=getGameKey();
	escHit=0;
	memset(gameKey,0,sizeof(struct GameKey));
	
}


void init_newint9_game(){
	if(oldint9==NULL){
		oldint9=getvect(9);
	}
	clearGameKey();
	installInt(newint9_game,0x09);
}
void cancel_newint9_game(){
	if(oldint9==NULL){
		return ;
	}
	installInt(oldint9,0x09);
	clearGameKey();
}

