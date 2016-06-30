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
	ouji->AddStateListner(this);	//�X�e�[�g���X�i�[�ɓo�^�B
}
void OujiAnimationController::OnChangeState(EOujiState prevState, EOujiState nextState)
{
	if (nextState == eState_Stand) {
		//�ҋ@�A�j���[�V�������Z�b�g
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
		//�A�j���[�V������Ԓ��͐؂�ւ��Ȃ��B
		return;
	}
	if (nextAnim != eAnim_Undef){
		ouji->PlayAnimation(nextAnim);
		nextAnim = eAnim_Undef;
	}
}
