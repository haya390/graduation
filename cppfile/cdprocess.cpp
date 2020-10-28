#include"cdprocess.h"

#define SCROLL_STAPOS 500

float scrolly = 0;

void move(){
	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	float hy = HERO.y - 1700;

	
	

	if (key & PAD_INPUT_UP && CheckEnd(1) == TRUE){
		HERO.y -= HERO.movement;
		scrolly += HERO.movement;
	}
	if (key & PAD_INPUT_DOWN && CheckEnd(2) == TRUE){
		HERO.y += HERO.movement;
		if (HERO.y < 2450){
			scrolly -= HERO.movement;
		}
	}
	if (key & PAD_INPUT_LEFT && CheckEnd(3) == TRUE){
		HERO.x -= HERO.movement;
	}
	if (key & PAD_INPUT_RIGHT && CheckEnd(4) == TRUE){
		HERO.x += HERO.movement;
	}



}

BOOL CheckEnd(int i){

	switch (i)
	{
	case 1:
		if ((HERO.y - SHP) > 800)return TRUE;
		break;
	case 2:
		if ((HERO.y + IMGSIZE) < 2500)return TRUE;
		break;
	case 3:
		if (HERO.x > 0)return TRUE;
		break;
	case 4:
		if ((HERO.x + IMGSIZE) < 600)return TRUE;
		break;
	}

	return FALSE;
}