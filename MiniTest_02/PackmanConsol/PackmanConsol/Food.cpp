#include "stdafx.h"
#include "Food.h"
#include "Player.h"

Food::Food() :
	m_isDead(false)
{
	m_posX = 0;
	m_posY = 0;
}


Food::~Food()
{
}	
/*!
*@brief	�ǂ̕`�揈���B
*/
void Food::Draw()
{
	if (!m_isDead) {
		//�t���[���o�b�t�@�Ƀh���[�B
		sFrameBuffer[m_posY][m_posX] = '.';
	}
}
/*!
*@brief	���W��ݒ�B
*/
void Food::SetPosition(int x, int y)
{
	m_posX = x;
	m_posY = y;
}
/*!
*@brief	�X�V�����B
*/
void Food::Update()
{
	//�v���C���[�ƐG�ꂽ��H�ו���������悤�ɂ��Ă݂悤�E�E�E
	//�v���C���[��g_player�ŃA�N�Z�X�ł���B
	//�v���C���[��CFood�̍��W�������ɂȂ������ɁA������悤�ɂ���΂����͂��B
	//�v���C���[�̍��W��g_player.GetPositionX()��g_player.GetPositionY()�Ŏ擾�ł���B
	//�Ⴆ�΃v���C���[��X���W���~�����Ȃ炱��Ȋ����B
	//int pos_x = g_player.GetPositionX();

}