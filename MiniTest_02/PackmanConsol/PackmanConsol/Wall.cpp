#include "stdafx.h"
#include "Wall.h"

/*!
*@brief	�R���X�g���N�^�B
*/
Wall::Wall()
{
	m_posX = 0;
	m_posY = 0;
}
/*!
*@brief	�ǂ̕`�揈���B
*/
void Wall::Draw()
{
	//�t���[���o�b�t�@�Ƀh���[�B
	sFrameBuffer[m_posY][m_posX] = 'W';
}
/*!
*@brief	���W��ݒ�B
*/
void Wall::SetPosition(int x, int y)
{
	m_posX = x;
	m_posY = y;
}