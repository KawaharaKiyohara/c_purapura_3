//�e�j�X�R�[�g�̃w�b�_�[�t�@�C���B
#pragma once

class TennisCourt{
public:
	//�R���X�g���N�^�B
	TennisCourt();
	//�f�X�g���N�^�B
	~TennisCourt();
	//�`��B
	void Draw();
	//�ǂƂ̏Փ˔���B
	//0���Ԃ��Ă�����Փ˂��Ă��Ȃ��B
	//1���Ԃ��Ă������̕ǂƏՓ˂��Ă���B
	//2���Ԃ��Ă����牺�̕ǂƏՓ˂��Ă���B
	//3���Ԃ��Ă����獶�̕ǂƏՓ˂��Ă���B
	//4���Ԃ��Ă�����E�̕ǂƏՓ˂��Ă���B
	int IsHitWall(Vector2 pos);
private:
	Vector2  position;	//���W
};

extern TennisCourt tennisCourt;	//�e�j�X�R�[�g�B