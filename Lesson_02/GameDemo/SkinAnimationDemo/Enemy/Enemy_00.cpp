/*!
 * @brief	�^�C�v0�̓G�B
 */

#include "stdafx.h"
#include "Enemy/Enemy_00.h"
#include "Player/Player.h"
#include "Item.h"
#include "Enemy/HFSM/EnemyStateSearch.h"
#include "Enemy/HFSM/EnemyStateFind.h"
#include "Enemy/HFSM/EnemyStateDamage.h"
#include "Enemy/HFSM/EnemyStateDeath.h"
#include "DamageCollisionWorld.h"
#include "tkEngine/Sound/tkSoundSource.h"
#include "Scene/GameScene.h"
#include "ItemMaker.h"

Enemy_00::Enemy_00()
{
	state = enLocalState_Search;
	initPosition = CVector3::Zero;
	moveSpeed = 0.0f;
	direction = CVector3::AxisZ;
	moveDirection = CVector3::AxisZ;
	radius = 0.0f;
	height = 0.0f;
	hp = 70;
}
Enemy_00::~Enemy_00()
{
	for (auto& state : states) {
		delete state;
	}
}

void Enemy_00::Init(const char* modelPath, CVector3 pos, CQuaternion rotation)
{
	Enemy::Init(modelPath, pos, rotation);

	
}
void Enemy_00::OnLoadedSkinModelData()
{
	PlayAnimation(enAnimWalk);
	animation.SetAnimationLoopFlag(enAnimAttack, false);
	animation.SetAnimationLoopFlag(enAnimDamage, false);
	animation.SetAnimationLoopFlag(enAnimDeath, false);


	sphereShape.reset(new CSphereCollider);
	sphereShape->Create(radius);
	collisionObject.reset(new btCollisionObject());
	collisionObject->setCollisionShape(sphereShape->GetBody());

	InitHFSM();
}
/*!
 * @brief	HFSM���������B
 */
void Enemy_00::InitHFSM()
{
	//�T����Ԃ�ǉ��B
	states.push_back( new EnemyStateSearch(this) );
	//������Ԃ�ǉ��B
	states.push_back( new EnemyStateFind(this) );
	//�_���[�W��Ԃ�ǉ��B
	states.push_back( new EnemyStateDamage(this));
	//���S��Ԃ�ǉ��B
	states.push_back( new EnemyStateDeath(this));
	state = enLocalState_Search;
	states[state]->Enter(IEnemyState::SEnterArg());
}

void Enemy_00::Update()
{
	if (!gameScene->IsStart()) {
		return;
	}
	Enemy::Update();

	if (GetLocalFrameDeltaTime() < FLT_EPSILON) {
		//��~���̓_���[�W�����ƍs��̍X�V(�Ă΂Ȃ��Ɖe��������Ȃ�����)�͍s���B
		Damage();
		if (!objectCulling.IsCulling()) {
			skinModel.Update(position, rotation, CVector3::One);
		}
		return;
	}
	states[state]->Update();
	switch (state) {
	case enLocalState_Search:
	{
		CVector3 unityPos = g_player->GetPosition();
		CVector3 diff;
		diff.Subtract(unityPos, position);
		if (diff.LengthSq() < 5.0f * 5.0f) {
			//�������B
			states[state]->Leave();
			state = enLocalState_Find;
			states[state]->Enter(IEnemyState::SEnterArg());
		}
	}break;
	case enLocalState_Find:
	{
	
	}break;
	case enLocalState_Damage:
		if (!animation.IsPlay()) {
			states[state]->Leave();
			state = enLocalState_Find;
			states[state]->Enter(IEnemyState::SEnterArg());
		}
		break;
	}
	//�_���[�W����
	Damage();
	
	if (state != enLocalState_Death) {
		CVector3 speed = characterController.GetMoveSpeed();
		speed.x = moveDirection.x * moveSpeed;
		speed.z = moveDirection.z * moveSpeed;
		characterController.SetMoveSpeed(speed);
		characterController.Execute(GetLocalFrameDeltaTime());
		position = characterController.GetPosition();

		//��]�͓K���ɁB
		if (states[state]->IsPossibleRotate())
		{
			float angle = atan2f(direction.x, direction.z);
			rotation.SetRotation(CVector3::AxisY, angle);
		}
	}
//	light.SetPointLightPosition(g_player->GetPointLightPosition());
//	light.SetPointLightColor(g_player->GetPointLightColor());
	
	if (!objectCulling.IsCulling()) {
		animation.Update(GetLocalFrameDeltaTime());
		skinModel.Update(position, rotation, CVector3::One);
	}

	if (state != enLocalState_Death) {
		timer += GetLocalFrameDeltaTime();
		if (timer > 2.0f) {
			if (g_random.GetRandDouble() < 0.2f) {
				CSoundSource* se = NewGO<CSoundSource>(0);
				se->SetTags(GameScene::enGameObjectTags_EnemySound);
				se->Init("Assets/Sound/enemy_umeki.wav", true);
				se->Play(false);
				se->SetPosition(position);
			}
			timer = 0.0f;
		}
	}
}
void Enemy_00::Damage()
{
	if (state == enLocalState_Death) {
		//����ł�B
		return;
	}
	float offset = radius + height * 0.5f;
	CVector3 centerPos;
	centerPos = position;
	centerPos.y += offset;
	btTransform trans;
	trans.setOrigin(btVector3(centerPos.x, centerPos.y, centerPos.z));
	collisionObject->setWorldTransform(trans);
	const DamageCollisionWorld::Collision* dmgColli = g_damageCollisionWorld->FindOverlappedDamageCollision(
		DamageCollisionWorld::enDamageToEnemy,
		collisionObject.get()
	);
	if (!dmgColli) {
		centerPos.y += offset;
		trans.setOrigin(btVector3(centerPos.x, centerPos.y, centerPos.z));
		collisionObject->setWorldTransform(trans);
		const DamageCollisionWorld::Collision* dmgColli = g_damageCollisionWorld->FindOverlappedDamageCollision(
			DamageCollisionWorld::enDamageToEnemy,
			collisionObject.get()
		);
	}
	if (dmgColli != NULL && states[state]->IsPossibleApplyDamage(dmgColli) ) {
		//�_���[�W��H����Ă���B
		hp -= dmgColli->damage;
		if (hp <= 0) {
			//���S�B
			states[state]->Leave();
			state = enLocalState_Death;
			states[state]->Enter(IEnemyState::SEnterArg());
			g_itemMaker->NewItem(position);
		}
		else {
			states[state]->Leave();
			state = enLocalState_Damage;
			IEnemyState::SEnterArg enterArg;
			enterArg.arg[0] = dmgColli->groupID;	//�_���[�W���󂯂��R���W�����̃O���[�v�h�c��n���B
			states[state]->Enter(enterArg);
		}
	}
}
void Enemy_00::Render(CRenderContext& renderContext)
{
	if (!objectCulling.IsCulling()) {
		skinModel.Draw(renderContext, g_camera->GetCamera().GetViewMatrix(), g_camera->GetCamera().GetProjectionMatrix());
	}
}
/*!
* @brief	���b�N�I���\������B
*@retval	true	���b�N�I���\�B
*@retval	false	���b�N�I���s�\�B
*/
bool Enemy_00::IsPossibleLockOn() const 
{
	return states[state]->IsPossibleLockOn();
}