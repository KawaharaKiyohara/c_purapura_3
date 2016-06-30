#pragma once

#include "tkEngine/graphics/tkLight.h"
#include "OujiAnimationController.h"
#include "OujiStateBase.h"

class Core;

//���q�N���X
class Ouji
{
public:
	
	
	Ouji();
	~Ouji();
	/*!
	*@brief	�������B
	*/
	void Init();
	/*!
	 *@brief	�`�揈���B
	 *@param[in,out]	renderContext	�����_�����O�R���e�L�X�g
	 */
	void Render(CRenderContext& renderContext);
	/*!
	 *@brief	�X�V����
	 */
	void Update();
	/*!
	*@brief	�A�j���[�V�����̍Đ��B
	*/
	void PlayAnimation(EOujiAnim animationIndex)
	{
		animation.PlayAnimation(animationIndex, 0.2f);
	}
	/*!
	*@brief	�A�j���[�V�����̕�Ԓ��H
	*/
	bool IsInterpolateAnimation()
	{
		return animation.IsInterpolate();
	}
	/*!
	*@brief	�X�e�[�g���X�i�[�̒ǉ��B
	*@param[in]	listner		�X�e�[�g���X�i�[�B
	*/
	void AddStateListner(IOujiStateListner* listner)
	{
		stateListner.push_back(listner);
	}
	/*!
	*@brief	�X�e�[�g���X�i�[�̍폜�B
	*@param[in]	listner		�X�e�[�g���X�i�[�B
	*/
	void RemoveStateListner(IOujiStateListner* listner)
	{
		auto delIt = std::find(stateListner.begin(), stateListner.end(), listner);
		if (delIt != stateListner.end()) {
			stateListner.erase(delIt);
		}
	}
	/*!
	*@brief	��]��ǉ��B
	*@param[in]	addRot	�ǉ������]�B
	*/
	void AddRotation(const CQuaternion& addRot)
	{
		localRotation.Multiply(addRot);
	}
	/*!
	*@brief	�X�e�[�g�̐؂�ւ�
	*@param[in]	nextState		���̃X�e�[�g�B
	*/
	void ChangeState( EOujiState nextState );
	/*!
	*@brief	���W���擾�B
	*/
	const CVector3& GetPosition() const
	{
		return position;
	}
	/*!
	*@brief	���q�̌������擾�B
	*/
	const CVector3& GetDirection() const
	{
		return direction;
	}
	/*!
	*@brief	�R�A��ݒ�B
	*/
	void SetCore(Core* core)
	{
		this->core = core;
	}
	/*!
	*@brief	�R�A���擾�B
	*/
	Core* GetCore()
	{
		return core;
	}
private:
	/*!
	*@brief	���C�g�̏������B
	*/
	void InitLight();
private:
	std::list<IOujiStateListner*>	stateListner;	//!<�X�e�[�g�؂�ւ��̃��X�i�[�B
	CSkinModel				model;					//!<���f���B
	CSkinModelData			modelData;				//!<���f���f�[�^�B
	CAnimation				animation;				//!<�A�j���[�V�����B
	CVector3				localPosition;			//!<�R�A���W�n�ł̍��W�B
	CQuaternion				localRotation;			//!<�R�A���W�n�ł̉�]�B
	CVector3				position;				//!<���[���h���W�n�ł̍��W�B
	CQuaternion				rotation;				//!<���[���h���W�n�ł̉�]�B
	CMatrix					localMatrix;			//!<�e�̍��W�n�ł̃��[�J���}�g���b�N�X�B
	CLight					light;					//!<���C�g
	OujiAnimationController animationController;	//!<�A�j���[�V�����R���g���[���B
	OujiStateBase*			state;					//!<�X�e�[�g
	CVector3				direction;				//!<���q�̌����B
	Core*					core;					//!<�R�A
};

