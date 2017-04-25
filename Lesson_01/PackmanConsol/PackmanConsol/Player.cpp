/*!
 * @brief	プレイヤーの処理(C言語版)
 */

#include "stdafx.h"
#include <windows.h>
#include "Player.h"

#ifndef PLAYER_CPP

int playerPosX = 0;		//プレイヤーのX座標。
int playerPosY = 0;		//プレイヤーのY座標。


//プレイヤーの更新処理。
void PlayerUpdate()
{
	if (GetAsyncKeyState(VK_UP) & 0x8000) {
		playerPosY--;
		if (playerPosY < 0) {
			playerPosY = 0;
		}
	}
	else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
		playerPosX--;
		if (playerPosX < 0) {
			playerPosX = 0;
		}
	}
	else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
		playerPosY++;
		if (playerPosY > MAP_HEIGHT - 1) {
			playerPosY = MAP_HEIGHT - 1;
		}
	}
	else if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		playerPosX++;
		if (playerPosX > MAP_WIDTH - 1) {
			playerPosX = MAP_WIDTH - 1;
		}
	}
}
//プレイヤーの描画処理。
void PlayerDraw()
{
	//フレームバッファにドロー。
	sFrameBuffer[playerPosY][playerPosX] = 'P';
}

#endif