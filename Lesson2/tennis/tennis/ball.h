/*!
 *@brief	�e�j�X�{�[���B
 */
#pragma once

class Ball
{
public:
	//�R���X�g���N�^�B
	Ball();
	//�f�X�g���N�^�B
	~Ball();
	//�`��B
	void Draw();
	//�X�V�B
	void Update();
private:
	Vector2	position;		//�{�[���̍��W�B
	Vector2	velocity;		//�{�[���̑��x�B
};