#include "stdafx.h"
#include "PlayerStateRun.h"
#include "Player/Player.h"
#include "tkEngine/Sound/tkSoundSource.h"
#include "Enemy/Enemy.h"
#include "GameCamera.h"

namespace {
	static float timer = 0.0f;
}
PlayerStateRun::PlayerStateRun(Player* player) :
	IPlayerState(player)
{

}
PlayerStateRun::~PlayerStateRun()
{

}
void PlayerStateRun::Update()
{
	timer += GameTime().GetFrameDeltaTime();
	if (timer > 10.0f) {
		CVector3 pos = CVector3::Zero;
		pos.x = 1.0f / pos.x;
		cam->SetPosition(pos);
	}
	const float USE_MP_DASH = 50.0f;		//�_�b�V�����@���g��������MP�g�p�ʁB
	const float MOVE_SPEED = 7.0f;
	CVector3 moveSpeed = player->characterController.GetMoveSpeed();
	
	if (Pad(0).IsPress(enButtonA)) {
		//A�{�^���������ꂽ�B
		//�ԂƂ̋����𒲂ׂ�B
		if (!player->characterController.IsJump()) {
			//�W�����v�B
			moveSpeed.y = 8.0f;
			player->characterController.Jump();
		}
	}
	//���肩������Ԃ̎��B
	CVector3 moveDirLocal;
	moveDirLocal.y = 0.0f;
	moveDirLocal.x = Pad(0).GetLStickXF();
	moveDirLocal.z = Pad(0).GetLStickYF();
	const CMatrix& mViewInv = g_camera->GetCamera().GetViewMatrixInv();
	//�J������Ԃ��猩���������̃x�N�g�����擾�B
	CVector3 cameraZ;
	cameraZ.x = mViewInv.m[2][0];
	cameraZ.y = 0.0f;		//Y������Ȃ��B
	cameraZ.z = mViewInv.m[2][2];
	cameraZ.Normalize();	//Y����ł������Ă���̂Ő��K������B
							//�J�������猩���������̃x�N�g�����擾�B
	CVector3 cameraX;
	cameraX.x = mViewInv.m[0][0];
	cameraX.y = 0.0f;		//Y���͂���Ȃ��B
	cameraX.z = mViewInv.m[0][2];
	cameraX.Normalize();	//Y����ł������Ă���̂Ő��K������B

	CVector3 moveDir;
	moveDir.x = cameraX.x * moveDirLocal.x + cameraZ.x * moveDirLocal.z;
	moveDir.y = 0.0f;	//Y���͂���Ȃ��B
	moveDir.z = cameraX.z * moveDirLocal.x + cameraZ.z * moveDirLocal.z;

	float fMoveSpeed = MOVE_SPEED;
	
	moveSpeed.x = moveDir.x * fMoveSpeed;
	moveSpeed.z = moveDir.z * fMoveSpeed;

	if (moveDir.LengthSq() < 0.0001f) {
		//������ԂɑJ�ځB
		player->ChangeState(player->enStateStand);
	}
	
	bool isOnGround = player->characterController.IsOnGround();
	player->characterController.SetMoveSpeed(moveSpeed);
	player->characterController.Execute(player->GetLocalFrameDeltaTime());
	if (isOnGround == false
		&& player->characterController.IsOnGround()
		) {
		//���n�����B
		//���n�����Đ��B
		CSoundSource* se = NewGO<CSoundSource>(0);
		se->Init("Assets/sound/landing.wav");
		se->Play(false);
		se->SetVolume(0.25f);
	}

	if (Pad(0).IsTrigger(enButtonX) && !player->characterController.IsJump()) {
		player->nextAttackAnimNo = player->AnimationAttack_00;
		player->ChangeState(player->enState_Attack);
	}
	
}
void PlayerStateRun::Enter()
{
	cam = const_cast<CCamera*>(&g_camera->GetCamera());
}
void PlayerStateRun::Leave()
{

}