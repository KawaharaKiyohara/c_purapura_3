#pragma once

#include "OujiStateBase.h"

//王子のステートリスナーのインターフェースクラス。
//オブサーバーパターン。
class IOujiStateListner {
public:
	IOujiStateListner()
	{

	}
	virtual ~IOujiStateListner()
	{

	}
	//ステートの切り替えが発生した時のコールバック関数。
	virtual void OnChangeState(EOujiState prevState, EOujiState nextState)
	{
	}

};
