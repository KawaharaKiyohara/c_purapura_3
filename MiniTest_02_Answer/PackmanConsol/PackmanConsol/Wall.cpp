#include "stdafx.h"
#include "Wall.h"

/*!
*@brief	�R���X�g���N�^�B
*/
Wall::Wall()
{
}
/*!
*@brief	�ǂ̕`�揈���B
*/
void Wall::Draw()
{
	//�t���[���o�b�t�@�Ƀh���[�B
	sFrameBuffer[m_pos.GetY()][m_pos.GetX()] = 'W';
}
/*!
*@brief	���W��ݒ�B
*/
void Wall::SetPosition(int x, int y)
{
	m_pos.SetX(x);
	m_pos.SetY(y);
}