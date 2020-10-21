#ifndef __GAMEMAIN_H__
#define __GAMEMAIN_H__

#include<DxLib.h>
#include"main.h"
#include"loading.h"
#include"cdflame.h"
#include"cdprocess.h"

enum MAPDATA
{
	MAP_FIELD,MAP_ENEMY_1,MAP_ENEMY_2,MAP_ENEMY_3,MAP_HERO,MAP_WALL
};

void gamemain();
void InitStage(int);

#define MAPWIDTH 12 /*ïù*/
#define MAPHEIGHT 50 /*çÇÇ≥*/
#define IMGSIZE 50/*âÊëúÉTÉCÉY*/

extern int MAPDATA[MAPHEIGHT][MAPWIDTH];

void DrawMap();

#endif