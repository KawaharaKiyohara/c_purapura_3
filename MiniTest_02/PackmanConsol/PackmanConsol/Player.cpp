#include "stdafx.h"
#include "Player.h"


Player g_player;

Player::Player()
{
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
	sFrameBuffer[m_pos.GetY()][m_pos.GetX()] = 'P';
}
/*!
*@brief	�X�V�����B
*/
void Player::Update()
{
	int posY = m_pos.GetY();
	int posX = m_pos.GetX();
	if (GetAsyncKeyState(VK_UP) & 0x8000) {
		posY--;
		if (posY < 0) {
			posY = 0;
		}
	}
	else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
		posX--;
		if (posX < 0) {
			posX = 0;
		}
	}
	else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
		posY++;
		if (posY > MAP_HEIGHT - 1) {
			posY = MAP_HEIGHT - 1;
		}
	}
	else if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		posX++;
		if (posX > MAP_WIDTH - 1) {
			posX = MAP_WIDTH - 1;
		}
	}
	m_pos.SetX(posX);
	m_pos.SetY(posY);
}
/*!
*@brief	X���W���擾�B
*/
int Player::GetPositionX()
{
	return m_pos.GetX();
}
/*!
*@brief	Y���W���擾�B
*/
int Player::GetPositionY()
{
	return m_pos.GetY();
}
/*!
*@brief	���W��ݒ�B
*@param	x		x���W�B
*@param	y		y���W�B
*/
void Player::SetPosition(int x, int y)
{
	m_pos.SetX(x);
	m_pos.SetY(y);
}
