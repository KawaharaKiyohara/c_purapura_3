#pragma once

#include "IOujiStateListener.h"
/*!
*@brief	�A�j���[�V�����B
*/
enum EOujiAnim {
	eAnim_Stand,		//�����A�j��
	eAnim_Walk,			//�����A�j��
	eAnim_Run,			//����A�j��
	eAnim_Jump,			//�W�����v�A�j���B
	eAnim_Num,
	eAnim_Undef = 0xffffffff,	//����`�A�j��
};
class Ouji;

//���q�̃A�j���[�V�����R���g���[���[�B
class OujiAnimationController : public IOujiStateListner
{
public:

	OujiAnimationController();
	~OujiAnimationController();
	/*!
	*@brief	�������B
	*@param[in]		ouji		���q�B
	*/
	void Init(Ouji* ouji);
	/*!
	*@brief �X�V�B
	*/
	void Update();
	/*!
	*@brief �X�V�B
	*/
	void OnChangeState(EOujiState prevState, EOujiState nextState) ;
private:
	Ouji*		ouji;		//!<���q�B
	EOujiAnim	nextAnim;	//!<���̃A�j���[�V�����B
};

