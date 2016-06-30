#pragma once
#include "OujiStateBase.h"

class OujiState_Stand : public OujiStateBase
{
public:
	OujiState_Stand();
	~OujiState_Stand();
	/*!
	*@brief	ステートを取得。
	*/
	virtual EOujiState GetState()
	{
		return eState_Stand;
	}
	/*!
	*@brief	更新。
	*/
	void Update();
};

