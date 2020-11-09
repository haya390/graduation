#include"cdflame.h"

int bullet_count = sizeof(HERO.BULLET) / sizeof(HERO.BULLET[0]);

Charadata HERO;
Charadata ENEMY;

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
void Init_ENEMY1(){



}
void Init_ENEMY2(){



}
void Init_ENEMY3(){



}
int SET_PLAYER_BULLET(){
	int limit = 0;
	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (keychecker_z(key) == TRUE){
		int time_a = GetNowCount();

		limit = GetNowCount() - time_a;
		for (int i = 0; i < (limit / 500) && HERO.BULLET[i].living == FALSE; i++){
			HERO.BULLET[i].living = TRUE;
			HERO.BULLET[i].x = HERO.x;
			HERO.BULLET[i].y = HERO.y;
			HERO.BULLET[i].type = HERO.type;
			HERO.BULLET[i].movement = 7;
			InitBulletImage(i);
		}
	}
	return limit;
}