#include"cdprocess.h"

#define SCROLL_STAPOS 500

float scrolly = 0;

void move(){
	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	float hy = HERO.y - 1700;

	
	

	if (key & PAD_INPUT_UP){
		HERO.y -= HERO.movement;
		scrolly += HERO.movement;
	}
	if (key & PAD_INPUT_DOWN){
		HERO.y += HERO.movement;
		if (HERO.y < 2450){
			scrolly -= HERO.movement;
		}
	}
	if (key & PAD_INPUT_LEFT){
		HERO.x -= HERO.movement;
	}
	if (key & PAD_INPUT_RIGHT){
		HERO.x += HERO.movement;
	}
		
	

	DrawMap();
}