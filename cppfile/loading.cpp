#include"loading.h"

int G_IMGhandle;

BOOL IMGhandle(){

	G_IMGhandle = LoadGraph("media\\Ž©‹@.png");
	if (G_IMGhandle == -1)return FALSE;

}