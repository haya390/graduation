#include"loading.h"

int G_IMGhandle[10];

int jougen = sizeof(G_IMGhandle) / sizeof(G_IMGhandle[0]);

BOOL IMGhandle(){

	G_IMGhandle[player] = LoadGraph("media\\Ž©‹@.png");
	if (G_IMGhandle[player] == -1)return FALSE;

	return TRUE;
}