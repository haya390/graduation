#ifndef __CDFLAME_H__
#define __CDFLAME_H__

#include<DxLib.h>
#include<stdio.h>

enum attacktype{
	red = 1, blue = 2, green = 3
};
enum type{
	bullet = 1,beam = 2
};

struct BULLET{
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
	BULLET ENEMY_BULLET[5];
	BULLET HERO_BULLET[20];
};

extern int hx,ex;
extern int hy,ey;

void syokika();

#endif