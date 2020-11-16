#include<DxLib.h>
#include"gamemain.h"
#include"loading.h"
#include"cdprocess.h"




int MAPDATA[MAPHEIGHT][MAPWIDTH];

int hx, hy;
int i = 0;
int IMG_FLAME_RATE = 0;
int IMG_TYPE_FLAG = 0;
int SHP;

void InitStage(int i){
	char buf[256];
	sprintf_s(buf, 256, "media\\stage%d.txt",i);
	int fh = FileRead_open(buf);

	for (int y = 0; y < MAPHEIGHT; y++){
		FileRead_gets(buf, 256, fh);
		for (int x = 0; x < MAPWIDTH; x++){
			MAPDATA[y][x] = (int)(buf[x] - '0');
			if (MAPDATA[y][x] == MAP_HERO){
				HERO.x = x * IMGSIZE;
				HERO.y = y * IMGSIZE;
				SHP = HERO.y - 1700;
			}
			if (MAPDATA[y][x] == enemy1){
				Init_ENEMY1();
			}
			if (MAPDATA[y][x] == enemy2){
				Init_ENEMY2();
			}
			if (MAPDATA[y][x] == enemy3){
				Init_ENEMY3();
			}
		}
	}
	
	FileRead_close(fh);
}

void gamemain(){
	DrawMap();
	move();
	SET_PLAYER_BULLET();
	DrawBullet(P);

	
	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (key & PAD_INPUT_2){
		if (HERO.type == beam){
			HERO.type = red;
			IMG_TYPE_FLAG = 0;
		}
		else{
			HERO.type++;
			IMG_TYPE_FLAG++;
		}

	}

	

	clsDx();
	printfDx("YŽ²:%f\nXŽ²:%f\nƒXƒNƒ[ƒ‹—Ê:%f", HERO.y, HERO.x,scrolly);
}

void DrawMap(){
	if (IMG_FLAME_RATE == 11) IMG_FLAME_RATE = 0;

	for (int y = 0; y < MAPHEIGHT; y++){
		for (int x = 0; x < MAPWIDTH; x++){
			
			switch (MAPDATA[y][x])
			{
			case field:
				DrawGraph(x * IMGSIZE, y * IMGSIZE - 1700 + scrolly, G_IMGhandle[field][0], TRUE);
				break;
			case enemy1:
				DrawGraph(x * IMGSIZE, y * IMGSIZE - 1700, G_IMGhandle[enemy1][IMG_FLAME_RATE], TRUE);
				break;
			case enemy2:
				DrawGraph(x * IMGSIZE, y * IMGSIZE - 1700, G_IMGhandle[enemy2][IMG_FLAME_RATE], TRUE);
				break;
			case enemy3:
				DrawGraph(x * IMGSIZE, y * IMGSIZE - 1700, G_IMGhandle[enemy3][IMG_FLAME_RATE], TRUE);
				break;
			case player:
				DrawGraph(HERO.x, HERO.y - 1800 + scrolly, gif[IMG_TYPE_FLAG][IMG_FLAME_RATE], TRUE);
				break;
			}
		}
	}
	IMG_FLAME_RATE++;
}