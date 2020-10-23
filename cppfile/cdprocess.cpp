#include"cdprocess.h"

#define SCROLL_STAPOS 500

void move(){
	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	float hy = HERO.y - 1700;

	if ((hy - HERO.scrolly) < SCROLL_STAPOS){
		HERO.scrolly += (hy - HERO.scrolly);
	}
	if (hy - 1700 > HERO.scrolly)hy = HERO.y;	
	

	if (key & PAD_INPUT_UP){
		HERO.y -= 10;
	}
	if (key & PAD_INPUT_DOWN){
		HERO.y += 10;
	}
	if (key & PAD_INPUT_LEFT){
		HERO.x -= 1;
	}
	if (key & PAD_INPUT_RIGHT){
		HERO.x += 1;
	}

	DrawMap();
}