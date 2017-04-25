/*!
 * @brief	�v���C���[�̏���(C�����)
 */

#include "stdafx.h"
#include <windows.h>
#include "Player.h"

#ifndef PLAYER_CPP

int playerPosX = 0;		//�v���C���[��X���W�B
int playerPosY = 0;		//�v���C���[��Y���W�B


//�v���C���[�̍X�V�����B
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
//�v���C���[�̕`�揈���B
void PlayerDraw()
{
	//�t���[���o�b�t�@�Ƀh���[�B
	sFrameBuffer[playerPosY][playerPosX] = 'P';
}

#endif