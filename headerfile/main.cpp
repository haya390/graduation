#include"main.h"
#include<DxLib.h>

int monitorsize_x = 960;
int monitorsize_y = 840;

int gamemainsize_x = 600;
int gamemainsize_y = 800;

int gametype = GAME_TITLE;
BOOL g_akey_prev = FALSE;

int KeyChecker(int);

int WINAPI WinMain(HINSTANCE h1, HINSTANCE hp, LPSTR lpc, int nC){
	ChangeWindowMode(TRUE);
	SetGraphMode(monitorsize_x, monitorsize_y, 32);
	if (DxLib_Init() == -1)return -1;

	while (ProcessMessage() == 0){
		switch (gametype)
		{
		case GAME_TITLE:
			DrawTitle();
			break;
		case GAME_MAIN:
			DrawGameMain();
			break;
		case GAME_OVER:
			DrawGameOver();
			break;
		case GAME_CLEAR:
			DrawGameClear();
			break;
		}
		if (CheckHitKey(KEY_INPUT_ESCAPE) == TRUE)exit(0);
		ScreenFlip();
	}
	DxLib_End();
	return 0;
}
void DrawTitle(){
	SetGraphMode(monitorsize_x, monitorsize_y, 32);

	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (KeyChecker(key) == TRUE){
		gametype = GAME_MAIN;
		InitStage(1);
		SetGraphMode(gamemainsize_x, gamemainsize_y, 32);
	}
}
void DrawGameMain(){
	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (KeyChecker(key) == TRUE){
		gametype = GAME_OVER;
	}
	gamemain();
}
void DrawGameOver(){
	int largefont = CreateFontToHandle("メイリオ", 42, -1, DX_FONTTYPE_NORMAL);
	SetGraphMode(monitorsize_x, monitorsize_y, 32);

	DrawStringToHandle(200, 200, "左を押すとコンティニュー", GetColor(255, 255, 255), largefont, 32, FALSE);
	DrawStringToHandle(200, 250, "右を押すとゲーム終了", GetColor(255, 255, 255), largefont, 32, FALSE);

	if (CheckHitKey(KEY_INPUT_LEFT) == TRUE){
		gametype = GAME_MAIN;
		/*時間処理*/
	}
	else if (CheckHitKey(KEY_INPUT_RIGHT) == TRUE){
		exit(0);
	}

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