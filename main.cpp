#include"main.h"
#include<DxLib.h>

int gametype = GAME_TITLE;
int g_gametitleimg;

BOOL KeyChecker(int key);
BOOL g_akey_prev;

int WINAPI WinMain(HINSTANCE h1, HINSTANCE hp, LPSTR lpc, int nC){
	ChangeWindowMode(TRUE);
	SetGraphMode(960, 840, 32);
	if (DxLib_Init() == -1)return -1;

	g_gametitleimg = LoadGraph("media\\smp1_title.png");


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
	DrawBox(0, 0, 800, 600, GetColor(255, 255, 255), TRUE);
	DrawGraph(00, 0, g_gametitleimg, TRUE);

	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (KeyChecker(key) == TRUE) gametype = GAME_MAIN;


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