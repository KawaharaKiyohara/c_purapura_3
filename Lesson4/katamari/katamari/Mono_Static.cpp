#include "stdafx.h"
#include "Mono_Static.h"



Mono_Static::Mono_Static()
{
}


Mono_Static::~Mono_Static()
{
}

//初期化。
void Mono_Static::Init(const CVector3& pos, const CQuaternion& rot)
{
	//モデルデータのロード。
	modelData.LoadModelData("Assets/modelData/mono.x", NULL);
	//モデルにモデルデータをセット。
	model.Init(&modelData);
	light.SetAmbinetLight(CVector3(0.7f, 0.7f, 0.7f));

	model.SetLight(&light);
	position = pos;
	localPosition = pos;
	rotation = rot;
	localRotation = rot;
	model.UpdateWorldMatrix(position, rotation, CVector3(10.0f, 1.0f, 10.0f));
}
