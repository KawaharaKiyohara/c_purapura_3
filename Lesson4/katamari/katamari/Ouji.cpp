#include "stdafx.h"
#include "Ouji.h"
#include "GameCamera.h"
#include "OujiState_Stand.h"
#include "OujiState_Turn.h"
#include "OujiState_Run.h"


namespace {
	const float MOVE_SPEED = 0.1f;
}
Ouji::Ouji()
{
	position.x = 0.0f;
	position.y = 0.0f;
	position.z = 0.0f;

	localPosition.x = 0.0f;
	localPosition.y = 0.0f;
	localPosition.z = -0.5f;
	//単位クォータニオンに初期化。
	localRotation.x = 0.0f;
	localRotation.y = 0.0f;
	localRotation.z = 0.0f;
	localRotation.w = 1.0f;

	rotation.x = 0.0f;
	rotation.y = 0.0f;
	rotation.z = 0.0f;
	rotation.w = 1.0f;

	//王子の向きを設定。
	direction.Set(0.0f, 0.0f, 1.0f);
	core = NULL;
	state = NULL;
}


Ouji::~Ouji()
{
}

void Ouji::Init()
{
	modelData.LoadModelData("Assets/modelData/Unity.X", &animation);
	model.Init(&modelData);
	InitLight();
	//アニメーションコントローラーの初期化。
	animationController.Init(this);
	ChangeState(eState_Stand);
	
	animation.SetAnimationEndTime(eAnim_Run, 0.8f);
}
/*!
*@brief	ステートの切り替え
*@param[in]	nextState		次のステート。
*/
void Ouji::ChangeState(EOujiState nextState)
{
	EOujiState prevState = eState_Undef;
	if (state != NULL) {
		prevState = state->GetState();
	}
	if (nextState != prevState) {
		switch (nextState) {
		case eState_Stand:
			state = new OujiState_Stand;
			state->SetOuji(this);
			break;
		case eState_Jump:
			break;
		case eState_Run:
			state = new OujiState_Run;
			state->SetOuji(this);
			break;
		case eState_Turn:
			//走りステートからは遷移させない。
			if (prevState != eState_Run) {
				state = new OujiState_Turn;
				state->SetOuji(this);
			}
			break;
		default:
			TK_ASSERT(false, "不正なステートが渡されました。");
			break;
		}
		if (nextState == state->GetState()) {
			//ステート切り替わった？
			for (auto listner : stateListner) {
				listner->OnChangeState(prevState, nextState);
			}
		}
	}
}
void Ouji::InitLight()
{
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
}
void Ouji::Render(CRenderContext& renderContext)
{
	GameCamera* gameCamera = game->GetGameCamera();
	model.Draw(renderContext, gameCamera->GetViewMatrix(), gameCamera->GetProjectionMatrix());
}
void Ouji::Update()
{
	CQuaternion qAddRot = CQuaternion::Identity;
	CQuaternion qAddTate = CQuaternion::Identity;	//縦回転のクォータニオン。
	float moveSpeed = 0.0f;
	const CMatrix& wm = core->GetWorldMatrixIgnoreXRotation();
	
	bool isStand = true;
	if (KeyInput().IsLeftPress()) {
		qAddRot.SetRotation(CVector3::AxisY, CMath::DegToRad(-2.0f));
		ChangeState(eState_Turn);
		isStand = false;
	}
	if (KeyInput().IsRightPress()) {
		qAddRot.SetRotation(CVector3::AxisY, CMath::DegToRad(2.0f));
		ChangeState(eState_Turn);
		isStand = false;
	}
	if (KeyInput().IsUpPress()) {
		ChangeState(eState_Run);
		qAddTate.SetRotation(CVector3::AxisX,CMath::DegToRad(2.0f));
		moveSpeed = MOVE_SPEED;
		isStand = false;
	}
	if (KeyInput().IsDownPress()) {
		ChangeState(eState_Run);
		qAddTate.SetRotation(CVector3::AxisX,CMath::DegToRad(-2.0f));
		moveSpeed = -MOVE_SPEED;
		isStand = false;
	}

	if (isStand) {
		ChangeState(eState_Stand);
	}
	core->AddRotationY(qAddRot);
	core->AddRotationX(qAddTate);
	
	
	const CVector3& scale = core->GetScale();
	const CMatrix& oujiMat = model.GetWorldMatrix();

	direction.x = wm.m[2][0] / scale.x;
	direction.y = wm.m[2][1] / scale.y;
	direction.z = wm.m[2][2] / scale.z;
	CVector3 addPos;
	addPos = direction;
	addPos.Scale(moveSpeed);
	core->AddPosition(addPos);

	animation.Update(1.0f / 60.0f);

	//コアの座標系からワールド座標系に変換変換。
	const CMatrix& parentMatrix = core->GetWorldMatrixIgnoreXRotation();
	const CQuaternion parentRotation = core->GetRotationY();

	position = localPosition;
	parentMatrix.Mul(position);
	rotation = parentRotation;
	rotation.Multiply(localRotation);
	model.UpdateWorldMatrix(position, rotation, CVector3::One);

	state->Update();
	animationController.Update();

}