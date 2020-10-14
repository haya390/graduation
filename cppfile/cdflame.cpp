#include"cdflame.h"

int bullet_count = sizeof(HERO.BULLET) / sizeof(HERO.BULLET[0]);

Charadata HERO;
Charadata ENEMY;

void syokika(){
	HERO.attacktype = red;
	HERO.LIFE = 3;
	HERO.movement = 1;
	HERO.type = bullet;
	HERO.x = hx;
	HERO.y = hy;
	for (int i = 0; i < bullet_count; i++){
		HERO.BULLET[i].living = FALSE;
	}
}