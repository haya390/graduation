#include<stdio.h>
#include<DxLib.h>
#include"gamemain.h"

int MAPDATA[MAPHEIGHT][MAPWIDTH];

int hx, hy;

void InitStage(int i){
	char buf[256];
	sprintf_s(buf, 256, "media\\stage%d.txt",i);
	int fh = FileRead_open(buf);

	for (int y = 0; y < MAPHEIGHT; y++){
		FileRead_gets(buf, 256, fh);
		for (int x = 0; x < MAPWIDTH; x++){
			MAPDATA[y][x] = (int)(buf[x] - '0');
			hx = x;
			hy = y;
		}
	}
	syokika();
	FileRead_close(fh);
}

void gamemain(){
	
}