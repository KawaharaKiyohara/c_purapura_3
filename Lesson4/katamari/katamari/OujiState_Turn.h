#pragma once
#include "OujiStateBase.h"
class OujiState_Turn :
	public OujiStateBase
{
public:
	OujiState_Turn();
	~OujiState_Turn();
	/*!
	*@brief	�X�e�[�g���擾�B
	*/
	virtual EOujiState GetState()
	{
		return eState_Turn;
	}
	/*!
	*@brief	�X�V�B
	*/
	void Update();
};

