#pragma once

#include "OujiStateBase.h"

//���q�̃X�e�[�g���X�i�[�̃C���^�[�t�F�[�X�N���X�B
//�I�u�T�[�o�[�p�^�[���B
class IOujiStateListner {
public:
	IOujiStateListner()
	{

	}
	virtual ~IOujiStateListner()
	{

	}
	//�X�e�[�g�̐؂�ւ��������������̃R�[���o�b�N�֐��B
	virtual void OnChangeState(EOujiState prevState, EOujiState nextState)
	{
	}

};
