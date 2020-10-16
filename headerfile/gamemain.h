#ifndef __GAMEMAIN_H__
#define __GAMEMAIN_H__

#include<DxLib.h>
#include"main.h"
#include"loading.h"
#include"cdflame.h"
#include"cdprocess.h"

enum MAPDATA
{
	MAP_NO = 0,MAP_HERO = 1,MAP_ENEMY_1 = 2,MAP_ENEMY_2 = 3,MAP_ENEMY_3 = 4,MAP_WALL = 5
};

void gamemain();
void InitStage(int);

#define MAPWIDTH 12 /*ïù*/
#define MAPHEIGHT 50 /*çÇÇ≥*/
#define IMGSIZE 50/*âÊëúÉTÉCÉY*/

extern int MAPDATA[MAPHEIGHT][MAPWIDTH];

#endif