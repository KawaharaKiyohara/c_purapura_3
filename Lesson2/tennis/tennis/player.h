//�v���C���[�N���X�B
#pragma once

class Player{
public:
	//�R���X�g���N�^�B
	Player();
	//�f�X�g���N�^�B
	~Player();
	//�X�V�B
	void Update();
	//�`��B
	void Draw();
	//�Փ˂����H
	bool IsHit(Vector2 pos);
private:
	Vector2		position;	//���W�B
};

extern Player	player;			//�v���C���[�B