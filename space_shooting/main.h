#ifndef __MAIN_H__
#define __MAIN_H__

#include<DxLib.h>
#include"loading.h"
#include"gamemain.h"
#include"cdflame.h"
#include"cdprocess.h"

enum GameType
{
	GAME_TITLE = 0,GAME_MAIN = 1,GAME_OVER = 2,GAME_CLEAR = 3
};

void DrawTitle();
void DrawGameMain();
void DrawGameOver();
void DrawGameClear();
int keychecker_z(int);
int keychecker_b(int);

extern int gamemainsize_x;
extern int gamemainsize_y;
extern int timer;

#endif