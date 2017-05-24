#pragma once
#include "Vector2.h"

/*!
*@brief	�H�ו��N���X�B
*/
class Food {
private:
	Vector2 m_pos;
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
