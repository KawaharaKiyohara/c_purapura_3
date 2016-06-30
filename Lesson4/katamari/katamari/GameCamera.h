#pragma once

//�Q�[���J�����N���X�B
class GameCamera {
public:
	GameCamera();
	~GameCamera();
	void Update();
	//�r���[�s��̎擾�B
	CMatrix GetViewMatrix();
	//�v���W�F�N�V�����s��̎擾�B
	CMatrix GetProjectionMatrix();
	//���q��ݒ�B
	void SetOuji(Ouji* ouji)
	{
		this->ouji = ouji;
	}
private:
	/////////////////////////////////////////
	//�������烁���o�ϐ��B
	/////////////////////////////////////////
	CCamera  camera;		//�J�����B
	Ouji* ouji;				//���q
};


