#include "stdafx.h"
#include "OujiAnimationController.h"



OujiAnimationController::OujiAnimationController()
{
}


OujiAnimationController::~OujiAnimationController()
{
}

void OujiAnimationController::Init(Ouji* ouji)
{
	this->ouji = ouji;
	ouji->AddStateListner(this);	//ステートリスナーに登録。
}
void OujiAnimationController::OnChangeState(EOujiState prevState, EOujiState nextState)
{
	if (nextState == eState_Stand) {
		//待機アニメーションをセット
		nextAnim = eAnim_Stand;
	}
	else if (nextState == eState_Turn) {
		nextAnim = eAnim_Walk;
	}
	else if (nextState == eState_Run) {
		nextAnim = eAnim_Run;
	}
}
void OujiAnimationController::Update()
{
	if (ouji->IsInterpolateAnimation()) {
		//アニメーション補間中は切り替えない。
		return;
	}
	if (nextAnim != eAnim_Undef){
		ouji->PlayAnimation(nextAnim);
		nextAnim = eAnim_Undef;
	}
}
