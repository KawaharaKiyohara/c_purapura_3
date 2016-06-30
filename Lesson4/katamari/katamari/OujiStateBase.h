#pragma once

#include "OujiAnimationController.h"

class Ouji;
/*!
*@brief	�X�e�[�g�B
*/
enum EOujiState {
	eState_Stand,		//������ԁB
	eState_Run,			//�����ԁB
	eState_Jump,		//�W�����v��ԁB
	eState_Turn,		//����B
	eState_Num,

	eState_Undef = 0xffffffff,

};

//���q�̃X�e�[�g�̒��ۃN���X�B
class OujiStateBase
{
public:
	OujiStateBase();
	virtual ~OujiStateBase();
	/*!
	*@brief	���q���Z�b�g
	*@param[in]	ouji	���q�B
	*/
	void SetOuji(Ouji* ouji);
	/*!
	*@brief	���̃X�e�[�g�ɑJ�ڂ���Ƃ��ɌĂ΂�鏈���B
	*/
	virtual void Start()
	{

	}
	/*!
	*@brief	���̃X�e�[�g�𔲂���Ƃ��ɌĂ΂�鏈���B
	*/
	virtual void End()
	{

	}
	/*!
	*@brief	�X�e�[�g���擾�B
	*/
	virtual EOujiState GetState()
	{
		return eState_Undef;
	}
	/*!
	*@brief	�X�V�B
	*/
	virtual void Update()
	{

	}
protected:
	Ouji*	ouji;		//���q�B
};

