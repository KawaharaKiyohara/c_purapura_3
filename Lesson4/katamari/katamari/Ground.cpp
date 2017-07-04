#include "stdafx.h"
#include "Ground.h"
#include "GameCamera.h"


Ground::Ground()
{
}


Ground::~Ground()
{
}

//�������B
void Ground::Init()
{
	//���f���f�[�^�̃��[�h�B
	modelData.LoadModelData("Assets/modelData/ground.x", NULL);
	//���f���Ƀ��f���f�[�^���Z�b�g�B
	model.Init(&modelData);
	light.SetAmbinetLight(CVector3(0.7f, 0.7f, 0.7f));

	model.SetLight(&light);
	model.UpdateWorldMatrix(CVector3::Zero, CQuaternion::Identity, CVector3(3.0f, 1.0f, 3.0f));
}
//�`��B
void Ground::Render(CRenderContext& renderContext)
{
	GameCamera* gameCamera = game->GetGameCamera();
	model.Draw(renderContext, gameCamera->GetViewMatrix(), gameCamera->GetProjectionMatrix());
}