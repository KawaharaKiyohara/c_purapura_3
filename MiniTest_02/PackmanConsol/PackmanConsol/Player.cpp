#include "stdafx.h"
#include "Player.h"


Player g_player;

Player::Player()
{
	//������m_pos�̃R���X�g���N�^��
	//�Ă΂�Ă���̂ŏ������s�v

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
	if (GetAsyncKeyState(VK_UP) & 0x8000) {
		int posY = m_pos.GetY();
		posY--;
		m_pos.SetY(posY);
		if (m_pos.GetY() < 0) {
			m_pos.SetY(0);
		}
	}
	else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
		int posX = m_pos.GetX();
		posX--;
		m_pos.SetX(posX);
		if (m_pos.GetX() < 0) {
			m_pos.SetX(0);
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
			m_pos.SetX(MAP_WIDTH - 1);
		}
	}
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
