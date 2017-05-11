#pragma once
/*!
*@brief	�H�ו��N���X�B
*/
class Food {
private:
	int m_posX;		//!<x���W�B
	int m_posY;		//!<y���W
	bool m_isDead;	//!<���S�t���O�B
public:
	/*!
	*@brief	�R���X�g���N�^�B
	*/
	Food();
	/*!
	*@brief	�f�X�g���N�^�B
	*/
	~Food();
	/*!
	*@brief	�ǂ̕`�揈���B
	*/
	void Draw();
	/*!
	*@brief	���W��ݒ�B
	*/
	void SetPosition(int x, int y);
	/*!
	*@brief	�X�V�����B
	*/
	void Update();
};
