#include"cdflame.h"

int bullet_count = sizeof(HERO.BULLET) / sizeof(HERO.BULLET[0]);



void syokika(){
	scrolly = 0;
	InitStage(HERO.StageNum);
	HERO.LIFE = 3;
	HERO.SF = TRUE;
	HERO.movement = 5;
	HERO.type = red;
	for (int i = 0; i < bullet_count; i++){
		HERO.BULLET[i].living = FALSE;
	}
}
void Init_ENEMY1(int x, int y){



}
void Init_ENEMY2(int x, int y){



}
void Init_ENEMY3(int x, int y){



}
void Init_BOSS(int i,int x,int y){

	STAGEBOSS.living = TRUE;
	STAGEBOSS.x = x * IMGSIZE;
	STAGEBOSS.y = y * IMGSIZE;
	STAGEBOSS.LIFE = 500;
	STAGEBOSS.movement = 1;
	STAGEBOSS.type = 1;

}
void SET_PLAYER_BULLET(){

	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (key & PAD_INPUT_A){
		for (int i = 0; i < 20; i++){
			if (HERO.BULLET[i].living == FALSE){
				if (i != 0){
					int Tseigyo = HERO.BULLET[i].time - HERO.BULLET[i - 1].time;
					if (Tseigyo <= 1.5){
						HERO.BULLET[i - 1].time = GetNowCount();
						break;
					}
					HERO.BULLET[i].time = (GetNowCount() - timer) / 1000;
					HERO.BULLET[i].living = TRUE;
					HERO.BULLET[i].x = HERO.x;
					HERO.BULLET[i].y = HERO.y - 50;
					HERO.BULLET[i].type = HERO.type;
					HERO.BULLET[i].movement = 7;
					InitBulletImage(i);
					break;
				}else{
					HERO.BULLET[i].time = (GetNowCount() - timer) / 1000;
					HERO.BULLET[i].living = TRUE;
					HERO.BULLET[i].x = HERO.x;
					HERO.BULLET[i].y = HERO.y - 50;
					HERO.BULLET[i].type = HERO.type;
					HERO.BULLET[i].movement = 7;
					InitBulletImage(i);
					break;
				}

			}else{
				
			}
		}

	}
}