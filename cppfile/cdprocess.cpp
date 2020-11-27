#include"cdprocess.h"

#define SCROLL_STAPOS 500

float scrolly = 0;

void move(){
	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	int aa = timer;
	float hy = HERO.y - 1700;
	aa += 1;
	if (timer < aa)
	{
		//scrolly += 1;
	}

	if (key & PAD_INPUT_UP && CheckEnd(1) == TRUE){
		HERO.y -= HERO.movement;
		scrolly += HERO.movement;
		
	}
	if (key & PAD_INPUT_DOWN && CheckEnd(2) == TRUE){
		HERO.y += HERO.movement;
		scrolly -= HERO.movement;
		
	}
	if (key & PAD_INPUT_LEFT && CheckEnd(3) == TRUE){
		HERO.x -= HERO.movement;
	}
	if (key & PAD_INPUT_RIGHT && CheckEnd(4) == TRUE){
		HERO.x += HERO.movement;
	}

}

BOOL CheckEnd(int i){

	int field_bottom = 2750 - gamemainsize_y;
	int field_central = 2750 - field_bottom;
	int field_head = 0;

	switch (i)
	{
	case 1:
		if (HERO.y - HERO.movement < 0) return FALSE;
		break;
	case 2:
		if (SHP * IMGSIZE + ((50 - SHP) * IMGSIZE) < HERO.y + IMGSIZE + HERO.movement)return FALSE;
		break;
	case 3:
		if (HERO.x - HERO.movement < 0)return FALSE;
		break;
	case 4:
		if (HERO.x + HERO.movement + IMGSIZE > gamemainsize_x)return FALSE;
		break;
	}

	return TRUE;
	
}
void CheckScroll(BOOL flag){
	
	if (HERO.y >= 0 && HERO.y <= 800){
		HERO.ScrollUpper = TRUE;
		HERO.ScrollBelow = FALSE;
	}
	if (HERO.y > 800 && HERO.y <= 1950){
		HERO.ScrollUpper = TRUE;
		HERO.ScrollBelow = TRUE;
	}
	if (HERO.y > 1950 && HERO.y <= 2750){
		HERO.ScrollUpper = FALSE;
		HERO.ScrollBelow = TRUE;
	}
	
}
void DrawBullet(int flag){
	int largefont = CreateFontToHandle("ƒƒCƒŠƒI", 42, -1, DX_FONTTYPE_NORMAL);

	if (flag == E){

	}else if (flag == P){
		for (int i = 0; HERO.BULLET[i].living == TRUE; i++){
			switch (HERO.BULLET[i].type)
			{
			case red:
				DrawGraph(HERO.BULLET[i].x, HERO.BULLET[i].y - 1950, HERO.BULLET[i].BULLET_IMAGE, TRUE);
				break;
			case blue:
				DrawGraph(HERO.BULLET[i].x, HERO.BULLET[i].y - 1950, HERO.BULLET[i].BULLET_IMAGE, TRUE);
				break;
			case green:
				DrawGraph(HERO.BULLET[i].x, HERO.BULLET[i].y - 1950, HERO.BULLET[i].BULLET_IMAGE, TRUE);
				break;
			case beam:
				DrawExtendGraph(HERO.BULLET[i].x,HERO.BULLET[i].y - 1950,HERO.BULLET[i].x + IMGSIZE,HERO.BULLET[i].y - 1950 + IMGSIZE,HERO.BULLET[i].BULLET_IMAGE,TRUE);
				break;
			}
			if (HERO.BULLET[i].y + IMGSIZE <= (HERO.y + 110 - gamemainsize_y)){
				HERO.BULLET[i].living = FALSE;
			}
			if(HERO.BULLET[i].living == TRUE){
				HERO.BULLET[i].y -= HERO.BULLET[i].movement;
			}
		}
	}
	
}