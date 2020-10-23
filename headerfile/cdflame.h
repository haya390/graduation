#ifndef __CDFLAME_H__
#define __CDFLAME_H__

#include<DxLib.h>
#include<stdio.h>
#include"cdprocess.h"

enum attacktype{
	red = 1, blue = 2, green = 3
};
enum type{
	bullet = 1/*À’e*/,beam = 2
};

struct Data{
	float x; /*‰¡²*/
	float y; /*c²*/
	BOOL living; /*‘¶İØ–¾*/
	int type; /*À’e/ƒr[ƒ€*/
	float movement; /*ˆÚ“®—Ê*/
};

struct Charadata{
	float x;/*‰¡²*/
	float y;/*c²*/
	int LIFE;/*Å‘å”í’e‰ñ”*/
	float movement;/*ˆÚ“®—Ê*/
	int attacktype;/*‘®«*/
	int type;/*À’e/ƒr[ƒ€*/
	BOOL living;/*‘¶İØ–¾*/
	Data BULLET[20];
	float scrollx;

};

extern Charadata HERO;
extern Charadata ENEMY;

extern int hx,ex;
extern int hy,ey;

void syokika();
void Init_ENEMY1();
void Init_ENEMY2();
void Init_ENEMY3();

#endif