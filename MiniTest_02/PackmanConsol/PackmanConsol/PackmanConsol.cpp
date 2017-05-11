// PackmanConsol.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include "Player.h"
#include "Food.h"
#include "Wall.h"

char sFrameBuffer[MAP_HEIGHT][MAP_WIDTH];

void EndFrame()
{
	Sleep(100);	//100�~���b����B
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = 0;
	pos.Y = 0;

	SetConsoleCursorPosition(hCons, pos);
}



/*!
 *@brief	���C���֐��B
 */
int main()
{
	//�v���C���[�̏����ʒu������B
	g_player.SetPosition(7, 7);
	//��
	int numWall = 0;	//�ǂ̐��B
	Wall walls[MAP_HEIGHT*MAP_WIDTH];
	//�H�ו�
	int numFood = 0;
	Food foods[MAP_HEIGHT*MAP_WIDTH];
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			if (sMap[i][j] == 1) {
				//�ǁB
				walls[numWall].SetPosition(j, i);
				//�ǂ��������̂ŃJ�E���g�A�b�v�B
				numWall++;
			}
			else if (sMap[i][j] == 0) {
				//�H�ו�
				foods[numFood].SetPosition(j, i);
				//�H�ו����������̂ŃJ�E���g�A�b�v�B
				numFood++;
			}
		}
	}
	//�Q�[�����[�v�B
	while (true) {
		//�t���[���o�b�t�@���N���A�B
		memset(sFrameBuffer, 0, sizeof(sFrameBuffer));
		//�v���C���[�̈ړ������B
		g_player.Update();
		//�H�ו��̍X�V�����B
		for (int i = 0; i < numFood; i++) {
			foods[i].Update();
		}
		//�H�ו��̕`�揈���B
		for (int i = 0; i < numFood; i++) {
			foods[i].Draw();
		}
		//�ǂ̕`�揈���B
		for (int i = 0; i < numWall; i++) {
			walls[i].Draw();
		}
		//�v���[���[�̕`�揈���B
		g_player.Draw();
		//�t���[���o�b�t�@�̓��e����ʂɕ\������B
		for (int i = 0; i < MAP_HEIGHT; i++) {
			for (int j = 0; j < MAP_WIDTH; j++) {
				std::cout << sFrameBuffer[i][j];
			}
			std::cout << "\n";
		}
		EndFrame();	//�t���[���̍Ō�ɌĂ�łˁB���܂��Ȃ��B
	}
    return 0;
}

