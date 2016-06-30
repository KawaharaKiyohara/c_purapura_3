#pragma once

#include "OujiAnimationController.h"

class Ouji;
/*!
*@brief	ステート。
*/
enum EOujiState {
	eState_Stand,		//立ち状態。
	eState_Run,			//走り状態。
	eState_Jump,		//ジャンプ状態。
	eState_Turn,		//旋回。
	eState_Num,

	eState_Undef = 0xffffffff,

};

//王子のステートの抽象クラス。
class OujiStateBase
{
public:
	OujiStateBase();
	virtual ~OujiStateBase();
	/*!
	*@brief	王子をセット
	*@param[in]	ouji	王子。
	*/
	void SetOuji(Ouji* ouji);
	/*!
	*@brief	このステートに遷移するときに呼ばれる処理。
	*/
	virtual void Start()
	{

	}
	/*!
	*@brief	このステートを抜けるときに呼ばれる処理。
	*/
	virtual void End()
	{

	}
	/*!
	*@brief	ステートを取得。
	*/
	virtual EOujiState GetState()
	{
		return eState_Undef;
	}
	/*!
	*@brief	更新。
	*/
	virtual void Update()
	{

	}
protected:
	Ouji*	ouji;		//王子。
};

