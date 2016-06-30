#include "stdafx.h"
#include "Core.h"
#include "GameCamera.h"
#include "MonoBase.h"


#define CORE_DEFAULT_SCALE 5.0f

Core::Core()
{
}


Core::~Core()
{
}

void Core::Init()
{
	//���f���f�[�^�̃��[�h�B
	modelData.LoadModelData("Assets/modelData/core.x", NULL);
	//���f���Ƀ��f���f�[�^���Z�b�g�B
	model.Init(&modelData);

	//���C�g���������B
	light.SetDiffuseLightDirection(0, CVector3(0.707f, 0.0f, 0.707f));
	light.SetDiffuseLightDirection(1, CVector3(-0.707f, 0.0f, 0.707f));
	light.SetDiffuseLightDirection(2, CVector3(0.0f, 0.707f, 0.707f));
	light.SetDiffuseLightDirection(3, CVector3(0.0f, -0.707f, 0.707f));

	light.SetDiffuseLightColor(0, CVector4(0.2f, 0.2f, 0.2f, 1.0f));
	light.SetDiffuseLightColor(1, CVector4(0.2f, 0.2f, 0.2f, 1.0f));
	light.SetDiffuseLightColor(2, CVector4(0.3f, 0.3f, 0.3f, 1.0f));
	light.SetDiffuseLightColor(3, CVector4(0.2f, 0.2f, 0.2f, 1.0f));
	light.SetAmbinetLight(CVector3(0.5f, 0.5f, 0.5f));

	model.SetLight(&light);

	light.SetAmbinetLight(CVector3(0.7f, 0.7f, 0.7f));

	position.y = 0.5f;
	model.SetLight(&light);
	scale = CVector3(CORE_DEFAULT_SCALE, CORE_DEFAULT_SCALE, CORE_DEFAULT_SCALE);
	targetScale = scale;
	rotationY = CQuaternion::Identity;
	rotationX = CQuaternion::Identity;
	worldMatrixIgnoreXRotation = CMatrix::Identity;
	rotation = CQuaternion::Identity;
}
void Core::Update()
{
	//���m�Ƃ̏Փ˔�����s��
	MonoManager* monoManager = game->GetMonoManager();
	
	for (auto mono : monoManager->GetMonoList()) {
		if (mono->GetCore()) {
			//�������܂�Ă���B
			continue;
		}
		CVector3 diff = mono->GetPosition();
		diff.Subtract(position);
		if (diff.Length() < 0.8f * (scale.x/ CORE_DEFAULT_SCALE)) {
			//�������݁B
			mono->SetCore(this);
			makikomiMonoList.push_back(mono);
			if ((makikomiMonoList.size() % 5) == 0) {
				//5�������񂾂�X�P�[���A�b�v�B
				targetScale.Scale(1.02f);
			}
		}
	}
	//X������̉�]�����O�������[���h�s����v�Z�B
	CMatrix mTrans, mScale, mRot;
	mTrans.MakeTranslation(position);
	mRot.MakeRotationFromQuaternion(rotationY);
	mScale.MakeScaling(scale);
	worldMatrixIgnoreXRotation.Mul(mScale, mRot);
	worldMatrixIgnoreXRotation.Mul(worldMatrixIgnoreXRotation, mTrans);

	rotation = rotationY;
	rotation.Multiply(rotationX);
	model.UpdateWorldMatrix(position, rotation, scale);
	
	//�����Â傫�����Ă����B
	scale.x = targetScale.x * 0.02f + scale.x * 0.98f;
	scale.y = targetScale.y * 0.02f + scale.y * 0.98f;
	scale.z = targetScale.z * 0.02f + scale.z * 0.98f;
	

}
void Core::Render(CRenderContext& renderContext)
{
	GameCamera* gameCamera = game->GetGameCamera();
	model.Draw(renderContext, gameCamera->GetViewMatrix(), gameCamera->GetProjectionMatrix());
}
