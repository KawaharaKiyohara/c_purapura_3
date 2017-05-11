#include "stdafx.h"
#include "Player.h"


Player g_player;

Player::Player()
{
	//���������s���B
	m_posX = 0;
	m_posY = 0;
}


Player::~Player()
{
}
/*!
*@brief	�v���C���[�̕`�揈���B
*/
void Player::Draw()
{
	//�t���[���o�b�t�@�Ƀh���[�B
	sFrameBuffer[m_posY][m_posX] = 'P';
}
/*!
*@brief	�X�V�����B
*/
void Player::Update()
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
int Player::GetPositionX()
{
	return m_posX;
}
/*!
*@brief	Y���W���擾�B
*/
int Player::GetPositionY()
{
	return m_posY;
}
/*!
*@brief	���W��ݒ�B
*@param	x		x���W�B
*@param	y		y���W�B
*/
void Player::SetPosition(int x, int y)
{
	m_posX = x;
	m_posY = y;
}
