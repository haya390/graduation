#ifndef __CDFLAME_H__
#define __CDFLAME_H__

#include<DxLib.h>
#include<stdio.h>
#include"cdprocess.h"

enum ATKtype{
	red = 1, blue = 2, green = 3, beam = 4
};

struct Data{
	float x; /*横軸*/
	float y; /*縦軸*/
	BOOL living; /*存在証明*/
	int type; /*属性の切り替え*/
	float movement; /*移動量*/
	int BULLET_IMAGE;
	int time;/*クールタイム*/
};

struct Charadata{
	float x;/*横軸*/
	float y;/*縦軸*/
	int LIFE;/*最大被弾回数*/
	float movement;/*移動量*/
	BOOL SF;/*スクロール可否*/
	int type;/*属性の切り替え*/
	BOOL living;/*存在証明*/
	Data BULLET[20];/*自機/敵機の弾*/
	int StageNum;/*コンティニューする際のステージナンバーの記録*/
};

extern Charadata HERO;
extern Charadata ENEMY;

extern int hx,ex;
extern int hy,ey;

void syokika();
void Init_ENEMY1();
void Init_ENEMY2();
void Init_ENEMY3();
void SET_PLAYER_BULLET();

#endif