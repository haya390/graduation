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
void SET_PLAYER_BULLET(){

	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (key & PAD_INPUT_A){
		for (int i = 0; i < 20; i++){
			if (HERO.BULLET[i].living == FALSE){
				if (i != 0){
					if (HERO.BULLET[i - 1].time <= 2){
						HERO.BULLET[i - 1].time = GetNowCount();
						break;
					}
					HERO.BULLET[i].time = (GetNowCount() - timer) / 1000;
					HERO.BULLET[i].living = TRUE;
					HERO.BULLET[i].x = HERO.x;
					HERO.BULLET[i].y = HERO.y - 150;
					HERO.BULLET[i].type = HERO.type;
					HERO.BULLET[i].movement = 7;
					InitBulletImage(i);
					break;
				}else{
					HERO.BULLET[i].time = (GetNowCount() - timer) / 1000;
					HERO.BULLET[i].living = TRUE;
					HERO.BULLET[i].x = HERO.x;
					HERO.BULLET[i].y = HERO.y - 150;
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