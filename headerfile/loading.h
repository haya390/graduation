#ifndef __LOADING_H__
#define __LOADING_H__

#include<DxLib.h>
#include<stdio.h>

enum youso
{
	player,enemy1,enemy2,enemy3,field,wall
};

BOOL IMGhandle();

extern int G_IMGhandle[10];

#endif