#ifndef __CDPROCESS_H__
#define __CDPROCESS_H__

#include"main.h"
#include"gamemain.h"
#include"cdflame.h"

void move();
BOOL CheckEnd(int);
void CheckScroll(BOOL);
void DrawBullet(int,int);/*1の時自機/2の時敵機1/3の時敵機2/4の時敵機3*/

extern float scrolly;

#endif