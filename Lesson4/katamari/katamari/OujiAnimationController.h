#pragma once

#include "IOujiStateListener.h"
/*!
*@brief	アニメーション。
*/
enum EOujiAnim {
	eAnim_Stand,		//立ちアニメ
	eAnim_Walk,			//歩きアニメ
	eAnim_Run,			//走りアニメ
	eAnim_Jump,			//ジャンプアニメ。
	eAnim_Num,
	eAnim_Undef = 0xffffffff,	//未定義アニメ
};
class Ouji;

//王子のアニメーションコントローラー。
class OujiAnimationController : public IOujiStateListner
{
public:

	OujiAnimationController();
	~OujiAnimationController();
	/*!
	*@brief	初期化。
	*@param[in]		ouji		王子。
	*/
	void Init(Ouji* ouji);
	/*!
	*@brief 更新。
	*/
	void Update();
	/*!
	*@brief 更新。
	*/
	void OnChangeState(EOujiState prevState, EOujiState nextState) ;
private:
	Ouji*		ouji;		//!<王子。
	EOujiAnim	nextAnim;	//!<次のアニメーション。
};

