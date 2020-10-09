#include"cdflame.h"

Charadata HERO;

int enemy_count = sizeof(HERO.ENEMY_BULLET) / sizeof(HERO.ENEMY_BULLET[0]);

void syokika(){
	HERO.attacktype = red;
	HERO.LIFE = 3;
	HERO.movement = 1;
	HERO.type = bullet;
	HERO.x = hx;
	HERO.y = hy;
	for (int i = 0;i < enemy_count;i++){
		HERO.ENEMY_BULLET[i].living = FALSE;
		HERO.ENEMY_BULLET[i].movement = 1;
		HERO.ENEMY_BULLET[i].type = bullet;
		HERO.ENEMY_BULLET[i].x = 0;
		HERO.ENEMY_BULLET[i].y = 0;
	}
}