#ifndef __CDFLAME_H__
#define __CDFLAME_H__

#include<DxLib.h>
#include<stdio.h>
#include"cdprocess.h"

enum attacktype{
	red = 1, blue = 2, green = 3
};
enum type{
	bullet = 1,beam = 2
};

struct Data{
	float x; /*‰¡²*/
	float y; /*c²*/
	BOOL living; /*‘¶İØ–¾*/
	int type; /*À’e/ƒr[ƒ€*/
	float movement; /*ˆÚ“®—Ê*/
};

struct Charadata{
	int LIFE;/*Å‘å”í’e‰ñ”*/
	float movement;/*ˆÚ“®—Ê*/
	int attacktype;/*‘®«*/
	int type;/*À’e/ƒr[ƒ€*/
	float x;/*‰¡²*/
	float y;/*c²*/
	BOOL living;/*‘¶İØ–¾*/
	Data BULLET[20];
};

extern Charadata HERO;
extern Charadata ENEMY;

extern int hx,ex;
extern int hy,ey;

void syokika();

#endif