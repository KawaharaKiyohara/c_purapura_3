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
	//巻き込まれたので、コア座標系のポジションを計算する。
	CMatrix parentMatrixInv = core->GetWorldMatrix();
	//コア座標系に変換する行列を計算。
	parentMatrixInv.Inverse(parentMatrixInv);
	//座標をコア座標系に変換する。
	parentMatrixInv.Mul(localPosition);	
	CQuaternion qParentRot = core->GetRotation();
	qParentRot.Inverse();
	localRotation.Multiply(qParentRot);
}
void MonoBase::Update()
{
	UpdateSub();
	if (core != NULL) {
		//コアの座標系からワールド座標系に変換変換。
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