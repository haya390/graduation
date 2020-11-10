#include"cdprocess.h"

#define SCROLL_STAPOS 500

float scrolly = 0;

void move(){
	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	float hy = HERO.y - 1700;


	if ((HERO.y - HERO.movement) >= 0){

		if (key & PAD_INPUT_UP && CheckEnd(1) == TRUE){
			HERO.y -= HERO.movement;
			CheckScroll(TRUE);
			if (HERO.SF == TRUE){
				scrolly += HERO.movement;
			}
		}
		if (key & PAD_INPUT_DOWN && CheckEnd(2) == TRUE){
			HERO.y += HERO.movement;
			CheckScroll(FALSE);
			if (HERO.SF == TRUE){
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
}

BOOL CheckEnd(int i){

	switch (i)
	{
	case 1:
		if (HERO.y - HERO.movement >= 0)return TRUE;
		break;
	case 2:
		if ((HERO.y + IMGSIZE + HERO.movement) <= 2500)return TRUE;
		break;
	case 3:
		if (HERO.x - HERO.movement > 0)return TRUE;
		break;
	case 4:
		if ((HERO.x + IMGSIZE + HERO.movement) < 600)return TRUE;
		break;
	}

	return FALSE;
	
}
void CheckScroll(BOOL flag){
	
	
	
}
void DrawBullet(int flag,int i){
	if (flag == E){

	}else if (flag == P){
		switch (HERO.BULLET[i].type)
		{
		case red:
			DrawGraph(HERO.BULLET[i].x, HERO.BULLET[i].y, HERO.BULLET[i].BULLET_IMAGE[0], TRUE);
			break;
		case blue:
			DrawGraph(HERO.BULLET[i].x, HERO.BULLET[i].y, HERO.BULLET[i].BULLET_IMAGE[1], TRUE);
			break;
		case green:
			DrawGraph(HERO.BULLET[i].x, HERO.BULLET[i].y, HERO.BULLET[i].BULLET_IMAGE[2], TRUE);
			break;
		case beam:
			DrawGraph(HERO.BULLET[i].x, HERO.BULLET[i].y, HERO.BULLET[i].BULLET_IMAGE[3], TRUE);
			break;
		}
	}

}