#pragma once

#include "OujiStateBase.h"

class OujiState_Run : public OujiStateBase
{
public:
	OujiState_Run();
	~OujiState_Run();
	/*!
	*@brief	ステートを取得。
	*/
	virtual EOujiState GetState()
	{
		return eState_Run;
	}
	/*!
	*@brief	更新。
	*/
	void Update();
};

