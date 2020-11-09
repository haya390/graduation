#include"loading.h"
#include"cdflame.h"
#include<string.h>

int G_IMGhandle[10][13];
int gif[3][12];
int TITLE;

BOOL IMGhandle(){

	G_IMGhandle[field][0] = LoadGraph("media\\背景(お試し仕様).png");
	if (G_IMGhandle[field][0] == -1)return FALSE;

	TITLE = LoadGraph("media\\タイトル.png");
	if (TITLE == -1)return FALSE;



	for (int i = 0 , soeji = 1; i < 13; i++,soeji++){
		
		char red[50], blue[50], green[50];
		sprintf_s(red, "media\\赤\\%d.プレ―ン(赤).png", soeji);
		sprintf_s(blue, "media\\青\\%d.プレ―ン(青).png", soeji);
		sprintf_s(green, "media\\緑\\%d.プレ―ン(緑).png", soeji);

		G_IMGhandle[enemy1][i] = LoadGraph(red,soeji);
		if (G_IMGhandle[enemy1][i] == -1)return FALSE;
		G_IMGhandle[enemy2][i] = LoadGraph(blue,soeji);
		if (G_IMGhandle[enemy2][i] == -1)return FALSE;
		G_IMGhandle[enemy3][i] = LoadGraph(green,soeji);
		if (G_IMGhandle[enemy3][i] == -1)return FALSE;
	}

	LoadDivGraph("media\\img_sub\\R.png",12,6,2,55,55,gif[0]);
	LoadDivGraph("media\\img_sub\\B.png", 12, 6, 2, 55, 55, gif[1]);
	LoadDivGraph("media\\img_sub\\G.png", 12, 6, 2, 55, 55, gif[2]);

	return TRUE;
}
BOOL InitBulletImage(int i){
	switch (HERO.type)
	{
	case red:
		break;
	case blue:
		break;
	case green:
		break;
	case beam:
		break;
	}

	return TRUE;
}