#pragma once
class Wall
{
private:
	int	m_posX;		//!<x���W�B
	int m_posY;		//!<y���W
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

