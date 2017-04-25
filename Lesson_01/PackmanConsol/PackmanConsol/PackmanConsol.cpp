// PackmanConsol.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include "Player.h"



//�}�b�v�̒�`�B1�͕ǁB0�͉a�B
static int sMap[MAP_HEIGHT][MAP_WIDTH] = {
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1 },
	{ 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1 },
	{ 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1 },
	{ 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1 },
	{ 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1 },
	{ 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1 },
	{ 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
};

//�t���[���o�b�t�@�E�E�E�̂悤�Ȃ��́B
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
*@brief	�H�ו��N���X�B
*/
class CFood {
private:
	int m_posX;		//!<x���W�B
	int m_posY;		//!<y���W
	bool m_isDead;	//!<���S�t���O�B
public:
	/*!
	*@brief	�R���X�g���N�^�B
	*/
	CFood() :
		m_isDead(false)
	{
		m_posX = 0;
		m_posY = 0;
	}
	/*!
	*@brief	�ǂ̕`�揈���B
	*/
	void Draw()
	{
		if (!m_isDead) {
			//�t���[���o�b�t�@�Ƀh���[�B
			sFrameBuffer[m_posY][m_posX] = '.';
		}
	}
	/*!
	*@brief	���W��ݒ�B
	*/
	void SetPosition(int x, int y)
	{
		m_posX = x;
		m_posY = y;
	}
	/*!
	*@brief	�X�V�����B
	*/
	void Update()
	{
	}
};
/*!
*@brief	�ǃN���X�B
*/
class CWall {
private:
	int	m_posX;		//!<x���W�B
	int m_posY;		//!<y���W
public:
	/*!
	*@brief	�R���X�g���N�^�B
	*/
	CWall()
	{
		m_posX = 0;
		m_posY = 0;
	}
	/*!
	*@brief	�ǂ̕`�揈���B
	*/
	void Draw()
	{
		//�t���[���o�b�t�@�Ƀh���[�B
		sFrameBuffer[m_posY][m_posX] = 'W';
	}
	/*!
	*@brief	���W��ݒ�B
	*/
	void SetPosition(int x, int y)
	{
		m_posX = x;
		m_posY = y;
	}
};

/*!
 *@brief	���C���֐��B
 */
int main()
{
	//�v���C���[�̏����ʒu������B
	playerPosX = 7;
	playerPosY = 7;
	//��
	int numWall = 0;	//�ǂ̐��B
	CWall walls[MAP_HEIGHT*MAP_WIDTH];
	//�H�ו�
	int numFood = 0;
	CFood foods[MAP_HEIGHT*MAP_WIDTH];
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
		PlayerUpdate();
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
		PlayerDraw();
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

