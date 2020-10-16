#ifndef __MAIN_H__
#define __MAIN_H__

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
int keyChecker(int);

#endif