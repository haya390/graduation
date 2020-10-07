#include"loading.h"

int G_IMGhandle[30];

BOOL IMGhandle(){

	G_IMGhandle[0] = LoadGraph("media\\Ž©‹@.png");
	if (G_IMGhandle[0] == -1)return FALSE;

}