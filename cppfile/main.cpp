#include"main.h"
#include<DxLib.h>

int monitorsize_x = 960;
int monitorsize_y = 840;

int gamemainsize_x = 600;
int gamemainsize_y = 800;

int gametype = GAME_TITLE;
BOOL g_akey_prev = FALSE;

int s = GetNowCount();
int KeyChecker(int);

int g_timestart = 0;

int WINAPI WinMain(HINSTANCE h1, HINSTANCE hp, LPSTR lpc, int nC){
	SetWindowSizeChangeEnableFlag(TRUE);
	ChangeWindowMode(TRUE);
	SetGraphMode(monitorsize_x, monitorsize_y, 32);
	if (DxLib_Init() == -1)return -1;
	if (IMGhandle() == FALSE)return FALSE;
	SetWindowText("Trinity");
	SetDrawScreen(DX_SCREEN_BACK);



	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0){
		ClearDrawScreen();
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
		ScreenFlip();
	}
	DxLib_End();
	return 0;
}
void DrawTitle(){
	SetGraphMode(monitorsize_x, monitorsize_y, 32);
	IMGhandle();

	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (KeyChecker(key) == TRUE){
		gametype = GAME_MAIN;
		InitStage(1);
		SetGraphMode(gamemainsize_x, gamemainsize_y, 32);
		IMGhandle();
	}
}
void DrawGameMain(){
	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (KeyChecker(key) == TRUE){
		gametype = GAME_OVER;
		SetGraphMode(monitorsize_x, monitorsize_y, 32);
		IMGhandle();
		g_timestart = GetNowCount();
	}
	gamemain();
}
void DrawGameOver(){
	int g_nFrame = 0;//
	LONGLONG Time;//
	
	int Cr = GetColor(255, 255, 255);
	int Timecount = 0;
	int largefont = CreateFontToHandle("メイリオ", 42, -1, DX_FONTTYPE_NORMAL);
	int Timefont = CreateFontToHandle("メイリオ", 50, -1, DX_FONTTYPE_NORMAL);

	DrawStringToHandle(200, 200, "左を押すとコンティニュー", GetColor(255, 255, 255), largefont, 32, FALSE);
	DrawStringToHandle(200, 250, "右を押すとゲーム終了", GetColor(255, 255, 255), largefont, 32, FALSE);
	Time = GetNowCount();//

		// ゲーム時間をカウント
		g_nFrame++;
		// 終了処理

		if (CheckHitKey(KEY_INPUT_LEFT) == TRUE){
			gametype = GAME_MAIN;
			SetGraphMode(gamemainsize_x, gamemainsize_y, 32);
			IMGhandle();
			
			/*時間処理*/
		}
		else if (CheckHitKey(KEY_INPUT_RIGHT) == TRUE){
			exit(0);
		}
		
		if (Time - g_timestart >= 5000){
			gametype = GAME_TITLE;
			
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