#include"cdprocess.h"

void move(){
	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

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