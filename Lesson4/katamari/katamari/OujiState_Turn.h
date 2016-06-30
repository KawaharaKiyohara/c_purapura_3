#pragma once
#include "OujiStateBase.h"
class OujiState_Turn :
	public OujiStateBase
{
public:
	OujiState_Turn();
	~OujiState_Turn();
	/*!
	*@brief	ステートを取得。
	*/
	virtual EOujiState GetState()
	{
		return eState_Turn;
	}
	/*!
	*@brief	更新。
	*/
	void Update();
};

