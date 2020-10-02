#include"main.h"
#include<DxLib.h>

int monitorsize_x = 960;
int monitorsize_y = 840;

int gamemainsize_x = 600;
int gamemainsize_y = 800;

int gametype = GAME_TITLE;

BOOL g_akey_prev;

int WINAPI WinMain(HINSTANCE h1, HINSTANCE hp, LPSTR lpc, int nC){
	ChangeWindowMode(TRUE);
	SetGraphMode(monitorsize_x, monitorsize_y, 32);
	if (DxLib_Init() == -1)return -1;

	while (ProcessMessage() == 0){
		switch (gametype)
		{
		case GAME_TITLE:
			break;
		case GAME_MAIN:
			break;
		case GAME_OVER:
			break;
		case GAME_CLEAR:
			break;
		}
	}

	WaitKey();
	DxLib_End();
	return 0;
}
void DrawTitle(){



}
void DrawGameMain(){

}
void DrawGameOver(){

}
void DrawGameClear(){

}
int KeyChecker(int key){
	if (key & PAD_INPUT_A){
		if (g_akey_prev == FALSE){
			g_akey_prev = TRUE;
			return TRUE;
		}
	}
	else{
		g_akey_prev = FALSE;
	}
	return FALSE;
}