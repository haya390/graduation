#include"cdprocess.h"

#define SCROLL_STAPOS 500

void move(){
	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	float hy = HERO.y;

	if ((hy - HERO.scrollx) < SCROLL_STAPOS){
		HERO.scrollx += (hy - HERO.scrollx);
	}
	if (hy > HERO.scrollx)hy = HERO.y;
	

	if (key & PAD_INPUT_UP){
		HERO.y -= 1;
	}
	if (key & PAD_INPUT_DOWN){
		HERO.y += 1;
	}
	if (key & PAD_INPUT_LEFT){
		HERO.x -= 1;
	}
	if (key & PAD_INPUT_RIGHT){
		HERO.x += 1;
	}

	DrawMap();
}