#pragma once
#include "Vector2.h"
class Wall
{
private:
	Vector2 m_pos;
public:
	/*!
	*@brief	�R���X�g���N�^�B
	*/
	Wall();
	/*!
	*@brief	�ǂ̕`�揈���B
	*/
	void Draw();
	/*!
	*@brief	���W��ݒ�B
	*/
	void SetPosition(int x, int y);
};

