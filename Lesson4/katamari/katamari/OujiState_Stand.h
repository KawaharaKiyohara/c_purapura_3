#pragma once
#include "OujiStateBase.h"

class OujiState_Stand : public OujiStateBase
{
public:
	OujiState_Stand();
	~OujiState_Stand();
	/*!
	*@brief	�X�e�[�g���擾�B
	*/
	virtual EOujiState GetState()
	{
		return eState_Stand;
	}
	/*!
	*@brief	�X�V�B
	*/
	void Update();
};

