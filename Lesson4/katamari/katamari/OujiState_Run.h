#pragma once

#include "OujiStateBase.h"

class OujiState_Run : public OujiStateBase
{
public:
	OujiState_Run();
	~OujiState_Run();
	/*!
	*@brief	�X�e�[�g���擾�B
	*/
	virtual EOujiState GetState()
	{
		return eState_Run;
	}
	/*!
	*@brief	�X�V�B
	*/
	void Update();
};

