#include<DxLib.h>
#include"gamemain.h"
#include"loading.h"
#include"cdprocess.h"

int MAPDATA[MAPHEIGHT][MAPWIDTH];

int hx, hy;
int i = 0;
int IMG_FLAME_RATE = 0;

void InitStage(int i){
	char buf[256];
	sprintf_s(buf, 256, "media\\stage%d.txt",i);
	int fh = FileRead_open(buf);

	for (int y = 50; y > 0; y--){
		FileRead_gets(buf, 256, fh);
		for (int x = 0; x < MAPWIDTH; x++){
			MAPDATA[y][x] = (int)(buf[x] - '0');
			if (MAPDATA[y][x] == MAP_HERO){
				syokika();
				HERO.x = x * IMGSIZE;
				HERO.y = y * IMGSIZE;
			}
		}
	}
	
	FileRead_close(fh);
}

void gamemain(){
	if(IMG_FLAME_RATE == 11) IMG_FLAME_RATE = 0;
	DrawGraph(HERO.x,HERO.y,gif[IMG_FLAME_RATE],TRUE);

	move();

	IMG_FLAME_RATE++;
}

void DrawMap(){
	for (int y = 0; y < MAPHEIGHT; y++){
		for (int x = 0; x < MAPWIDTH; x++){
			switch (MAPDATA[y][x])
			{
			case field:
				break;
			case enemy1:
				break;
			case enemy2:
				break;
			case enemy3:
				break;
			case player:
				break;
			case wall:
				break;
			}
		}
	}
}