// PackmanConsol.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>

//�}�b�v�̍����B
const int MAP_HEIGHT = 15;
//�}�b�v�̕��B
const int MAP_WIDTH = 15;

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
 *@brief	�v���C���[�N���X�B
 */
class CPlayer {
private:
	int m_posX;			//!<x���W�B
	int m_posY;			//!<y���W�B
public:
	/*!
	 *@brief	�R���X�g���N�^�B
	 */
	CPlayer()
	{
		//���������s���B
		m_posX = 0;
		m_posY = 0;
	}
	/*!
	 *@brief	�f�X�g���N�^�B
	 */
	~CPlayer()
	{

	}
	/*!
	 *@brief	�ړ������B
	 */
	void Move()
	{
		if (GetAsyncKeyState(VK_UP) & 0x8000) {
			m_posY--;
			if (m_posY < 0) {
				m_posY = 0;
			}
		}
		else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
			m_posX--;
			if (m_posX < 0) {
				m_posX = 0;
			}
		}
		else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
			m_posY++;
			if (m_posY > MAP_HEIGHT - 1) {
				m_posY = MAP_HEIGHT - 1;
			}
		}
		else if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			m_posX++;
			if (m_posX > MAP_WIDTH - 1) {
				m_posX = MAP_WIDTH - 1;
			}
		}
	}
	/*!
	 *@brief	X���W���擾�B
	 */
	int GetPositionX()
	{
		return m_posX;
	}
	/*!
	 *@brief	Y���W���擾�B
	 */
	int GetPositionY()
	{
		return m_posY;
	}
	/*!
	 *@brief	���W��ݒ�B
	 *@param	x		x���W�B
	 *@param	y		y���W�B
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
	CPlayer player;
	//�v���C���[�̏����ʒu������B
	player.SetPosition(7, 7);
	//�Q�[�����[�v�B
	while (true) {
		//�v���C���[�̈ړ������B
		player.Move();	
		//�`��B
		for (int i = 0; i < MAP_HEIGHT; i++) {
			for (int j = 0; j < MAP_WIDTH; j++) {
				if (player.GetPositionX() == j && player.GetPositionY() == i) {
					std::cout << "�o";
				}else if (sMap[i][j] == 1) {
					std::cout << "��";
				}
				else if (sMap[i][j] == 0) {
					std::cout << "�Z";
				}
			}
			std::cout << "\n";
		}
		EndFrame();	//�t���[���̍Ō�ɌĂ�łˁB���܂��Ȃ��B
	}
    return 0;
}

