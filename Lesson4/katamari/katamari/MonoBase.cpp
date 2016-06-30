#include "stdafx.h"
#include "MonoBase.h"
#include "GameCamera.h"


MonoBase::MonoBase()
{
	core = NULL;
	localPosition.Set(0.0f, 0.0f, 0.0f);
	localRotation.Set(0.0f, 0.0f, 0.0f, 1.0f);
	position = localPosition;
	rotation = localRotation;
}


MonoBase::~MonoBase()
{
}
void MonoBase::SetCore(Core* core)
{
	this->core = core;
	//�������܂ꂽ�̂ŁA�R�A���W�n�̃|�W�V�������v�Z����B
	CMatrix parentMatrixInv = core->GetWorldMatrix();
	//�R�A���W�n�ɕϊ�����s����v�Z�B
	parentMatrixInv.Inverse(parentMatrixInv);
	//���W���R�A���W�n�ɕϊ�����B
	parentMatrixInv.Mul(localPosition);	
	CQuaternion qParentRot = core->GetRotation();
	qParentRot.Inverse();
	localRotation.Multiply(qParentRot);
}
void MonoBase::Update()
{
	UpdateSub();
	if (core != NULL) {
		//�R�A�̍��W�n���烏�[���h���W�n�ɕϊ��ϊ��B
		CMatrix parentMatrix = core->GetWorldMatrix();
		CQuaternion parentRotation = core->GetRotation();

		position = localPosition;
		parentMatrix.Mul(position);
		rotation = parentRotation;
		rotation.Multiply(localRotation);
	}
	else {
		position = localPosition;
		rotation = localRotation;
	}
	model.UpdateWorldMatrix(position, rotation, CVector3::One);
}
void MonoBase::Render(CRenderContext& renderContext)
{
	GameCamera* gameCamera = game->GetGameCamera();
	model.Draw(renderContext, gameCamera->GetViewMatrix(), gameCamera->GetProjectionMatrix());
}