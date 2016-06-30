#include "stdafx.h"
#include "GameCamera.h"


GameCamera::GameCamera()
{
	camera.SetPosition(CVector3(0.0f, 4.0f, -6.0f));
	camera.SetTarget(CVector3(0.0f, 0.0f, 0.0f));
	camera.SetFar(1000.0f);
	camera.Update();
}
GameCamera::~GameCamera()
{
}
CMatrix GameCamera::GetViewMatrix()
{
	return camera.GetViewMatrix();
}
//プロジェクション行列の取得。
CMatrix GameCamera::GetProjectionMatrix()
{
	return camera.GetProjectionMatrix();
}
void GameCamera::Update()
{
	CVector3 position = ouji->GetDirection();
	position.Scale(-10.0f);
	position.y = 2.0f;
	CVector3 target = ouji->GetPosition();
	target.y += 1.0f;
	camera.SetTarget(target);
	position.Add(target);
	camera.SetPosition(position);
	camera.Update();
}