#include"main.h"
#include<DxLib.h>

int gametype = GAME_TITLE;

int WINAPI WinMain(HINSTANCE h1, HINSTANCE hp, LPSTR lpc, int nC){
	ChangeWindowMode(TRUE);
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
void KeyChecker(){

}