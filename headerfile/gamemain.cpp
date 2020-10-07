#include<stdio.h>
#include<DxLib.h>
#include"gamemain.h"

int MAPDATA[MAPHEIGHT][MAPWIDTH];

Charadata HERO;

void InitStage(int i){
	char buf[256];
	sprintf_s(buf, 256, "media\\stage%d.txt",i);
	int fh = FileRead_open(buf);

	for (int y = 0; y < MAPHEIGHT; y++){
		FileRead_gets(buf, 256, fh);
		for (int x = 0; x < MAPWIDTH; x++){
			MAPDATA[y][x] = (int)(buf[x] - '0');
			if (buf[x] - '0' == MAP_HERO){
				HERO.x = (float)(x*IMGSIZE);
				HERO.y = (float)(y*IMGSIZE);
			}
		}
	}

	FileRead_close(fh);
}

void gamemain(){
	
}