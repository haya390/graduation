#ifndef __LOADING_H__
#define __LOADING_H__

#include<DxLib.h>

enum youso
{
	field,enemy1,enemy2,enemy3,player
};

extern int G_IMGhandle[10][13];
extern int gif[3][12];
extern int TITLE;

BOOL IMGhandle();
BOOL InitBulletImage(int);

#endif