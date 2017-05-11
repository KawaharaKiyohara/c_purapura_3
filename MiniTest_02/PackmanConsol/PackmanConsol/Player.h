#pragma once
class Player {
	;
private:
	int m_posX;			//!<x���W�B
	int m_posY;			//!<y���W�B
public:
	/*!
	*@brief	�R���X�g���N�^�B
	*/
	Player();
	/*!
	*@brief	�f�X�g���N�^�B
	*/
	~Player();
	/*!
	*@brief	�v���C���[�̕`�揈���B
	*/
	void Draw();
	/*!
	*@brief	�X�V�����B
	*/
	void Update();
	/*!
	*@brief	X���W���擾�B
	*/
	int GetPositionX();
	/*!
	*@brief	Y���W���擾�B
	*/
	int GetPositionY();
	/*!
	*@brief	���W��ݒ�B
	*@param	x		x���W�B
	*@param	y		y���W�B
	*/
	void SetPosition(int x, int y);
};

extern Player g_player;