#include "stdafx.h"
#include "Player.h"
#include "Car.h"
#include "Map/Ground.h"
#include "tkEngine/graphics/material/tkSkinModelMaterial.h"
#include "DamageCollisionWorld.h"
#include "ParticleParam.h"
#include "Enemy/EnemyParameter.h"
#include "tkEngine/Sound/tkSoundSource.h"
#include "Enemy/EnemyManager.h"
#include "HUD/LockOn2D.h"
#include "Scene/GameScene.h"


namespace {
	const float RECOVER_MP = 20.0f;			//MP���R�񕜗ʁB

	const float RUN_THREADHOLD_SQ = 4.0f * 4.0f;		//����A�j���[�V�������Đ����鑬�x��臒l�B
	//�A�j���[�V�����̃C�x���g�e�[�u���B
	AnimationEventGroup animationEventGroupTbl[Player::NumAnimation] = {
		//AnimationStand
		{
			END_ANIMATION_EVENT(),
		},
		//AnimationWalk
		{
			END_ANIMATION_EVENT(),
		},
		//AnimationRun
		{
			EMIT_SOUND_EVENT(0.4f, 1.0f, "Assets/sound/Footstep_00.wav"),
			EMIT_SOUND_EVENT(0.9f, 1.0f, "Assets/sound/Footstep_00.wav"),
			END_ANIMATION_EVENT(),
		},
		//AnimationJump
		{
			END_ANIMATION_EVENT(),
		},
		//AnimationAttack_00
		{
			EMIT_DAMAGE_TO_ENEMY_COLLISION_EVENT(0.4f, 0.3f, 0.7f, 10, "thief_Bip01_R_Hand", CVector3(0.0f, 0.0f, 0.0f), 0),
			EMIT_DAMAGE_TO_ENEMY_COLLISION_EVENT(0.48f, 0.3f, 0.7f, 10, "thief_Bip01_R_Hand", CVector3(0.0f, 0.0f, 0.0f), 0),
			EMIT_DAMAGE_TO_ENEMY_COLLISION_EVENT(0.56f, 0.3f, 0.7f, 10, "thief_Bip01_R_Hand", CVector3(0.0f, 0.0f, 0.0f), 0),
			EMIT_SOUND_EVENT(0.3f, 0.5f, "Assets/sound/PlayerAttack_00.wav"),
			END_ANIMATION_EVENT(),
		},
		//AnimationAttack_01
		{
			EMIT_DAMAGE_TO_ENEMY_COLLISION_EVENT(0.4f, 0.3f, 0.7f, 10, "thief_Bip01_R_Hand", CVector3(0.0f, 0.0f, 0.0f), 1),
			EMIT_DAMAGE_TO_ENEMY_COLLISION_EVENT(0.48f, 0.3f, 0.7f, 10, "thief_Bip01_R_Hand", CVector3(0.0f, 0.0f, 0.0f), 1),
			EMIT_DAMAGE_TO_ENEMY_COLLISION_EVENT(0.56f, 0.3f, 0.7f, 10, "thief_Bip01_R_Hand", CVector3(0.0f, 0.0f, 0.0f), 1),
			EMIT_SOUND_EVENT(0.3f, 0.5f, "Assets/sound/PlayerAttack_00.wav"),
			END_ANIMATION_EVENT(),
		},
		//AnimationAttack_02
		{
			EMIT_DAMAGE_TO_ENEMY_COLLISION_EVENT(1.3f, 0.3f, 0.7f, 20, "thief_Bip01_R_Hand", CVector3(0.0f, 0.0f, 0.0f), 2),
			EMIT_DAMAGE_TO_ENEMY_COLLISION_EVENT(1.31f, 0.3f, 0.7f, 20, "thief_Bip01_R_Hand", CVector3(0.0f, 0.0f, 0.0f), 2),
			EMIT_DAMAGE_TO_ENEMY_COLLISION_EVENT(1.32f, 0.3f, 0.7f, 20, "thief_Bip01_R_Hand", CVector3(0.0f, 0.0f, 0.0f), 2),
			EMIT_DAMAGE_TO_ENEMY_COLLISION_EVENT(1.33f, 0.3f, 0.7f, 20, "thief_Bip01_R_Hand", CVector3(0.0f, 0.0f, 0.0f), 2),
			EMIT_DAMAGE_TO_ENEMY_COLLISION_EVENT(1.34f, 0.3f, 0.7f, 20, "thief_Bip01_R_Hand", CVector3(0.0f, 0.0f, 0.0f), 2),
			EMIT_DAMAGE_TO_ENEMY_COLLISION_EVENT(1.35f, 0.3f, 0.7f, 20, "thief_Bip01_R_Hand", CVector3(0.0f, 0.0f, 0.0f), 2),
			EMIT_DAMAGE_TO_ENEMY_COLLISION_EVENT(1.36f, 0.3f, 0.7f, 20, "thief_Bip01_R_Hand", CVector3(0.0f, 0.0f, 0.0f), 2),
			EMIT_DAMAGE_TO_ENEMY_COLLISION_EVENT(1.37f, 0.3f, 0.7f, 20, "thief_Bip01_R_Hand", CVector3(0.0f, 0.0f, 0.0f), 2),
			EMIT_DAMAGE_TO_ENEMY_COLLISION_EVENT(1.38f, 0.3f, 0.7f, 20, "thief_Bip01_R_Hand", CVector3(0.0f, 0.0f, 0.0f), 2),
			EMIT_DAMAGE_TO_ENEMY_COLLISION_EVENT(1.39f, 0.35f, 0.7f, 20, "thief_Bip01_R_Hand", CVector3(0.0f, 0.0f, 0.0f), 2),

			EMIT_DAMAGE_TO_ENEMY_COLLISION_EVENT(1.3f, 0.3f, 0.7f, 20, "thief_Bip01_L_Hand", CVector3(0.0f, 0.0f, 0.0f), 2),
			EMIT_DAMAGE_TO_ENEMY_COLLISION_EVENT(1.31f, 0.3f, 0.7f, 20, "thief_Bip01_L_Hand", CVector3(0.0f, 0.0f, 0.0f), 2),
			EMIT_DAMAGE_TO_ENEMY_COLLISION_EVENT(1.32f, 0.3f, 0.7f, 20, "thief_Bip01_L_Hand", CVector3(0.0f, 0.0f, 0.0f), 2),
			EMIT_DAMAGE_TO_ENEMY_COLLISION_EVENT(1.33f, 0.3f, 0.7f, 20, "thief_Bip01_L_Hand", CVector3(0.0f, 0.0f, 0.0f), 2),
			EMIT_DAMAGE_TO_ENEMY_COLLISION_EVENT(1.34f, 0.3f, 0.7f, 20, "thief_Bip01_L_Hand", CVector3(0.0f, 0.0f, 0.0f), 2),
			EMIT_DAMAGE_TO_ENEMY_COLLISION_EVENT(1.35f, 0.3f, 0.7f, 20, "thief_Bip01_L_Hand", CVector3(0.0f, 0.0f, 0.0f), 2),
			EMIT_DAMAGE_TO_ENEMY_COLLISION_EVENT(1.36f, 0.3f, 0.7f, 20, "thief_Bip01_L_Hand", CVector3(0.0f, 0.0f, 0.0f), 2),
			EMIT_DAMAGE_TO_ENEMY_COLLISION_EVENT(1.37f, 0.3f, 0.7f, 20, "thief_Bip01_L_Hand", CVector3(0.0f, 0.0f, 0.0f), 2),
			EMIT_DAMAGE_TO_ENEMY_COLLISION_EVENT(1.38f, 0.3f, 0.7f, 20, "thief_Bip01_L_Hand", CVector3(0.0f, 0.0f, 0.0f), 2),
			EMIT_DAMAGE_TO_ENEMY_COLLISION_EVENT(1.39f, 0.35f, 0.7f, 20, "thief_Bip01_L_Hand", CVector3(0.0f, 0.0f, 0.0f), 2),
			EMIT_SOUND_EVENT(1.2f, 0.5f, "Assets/sound/PlayerAttack_01.wav"),
			END_ANIMATION_EVENT(),
		},
		//AnimationDamage
		{
			END_ANIMATION_EVENT(),
		},
		//AnimationDeath
		{
			EMIT_SOUND_EVENT(0.0f, 0.75f, "Assets/sound/PlayerDead.wav"),
			END_ANIMATION_EVENT(),
		},
	};
}

Player::Player() :
	position(CVector3::Zero),
	isUpdateAnim(false),
	attackState(this),
	standState(this),
	damageState(this),
	deadState(this),
	runState(this),
	magicSkillDash(this),
	magicSkillSlow(this, SepiaFilter(), 0.3f, 50.0f),
	magicSkillStop(this, MonochromeFilter(), 0.0f, 100.0f),
	magicSkillStealth(this)
{
	pCurrentMagicSkill = &magicSkillDash;
	memset(battleSeats, 0, sizeof(battleSeats));
}
Player::~Player()
{
	DeleteGO(lockOn2D);
}
/*!
* @brief	�J�n
*/
bool Player::Start()
{
	switch (initStep) {
	case InitStep_LoadModelData:
		skinModelData.LoadModelDataAsync("Assets/modelData/Player.X", &animation);
		initStep = InitStep_WaitModelData;
		break;
	case InitStep_WaitModelData:
		if (skinModelData.IsLoadEnd()) {
			//�X�L�����f���̓ǂݍ��݊����B
			lockOn2D = NewGO<LockOn2D>(1);

			//�̂̃}�e���A�����擾�B
			CSkinModelMaterial* mat = skinModelData.GetBody()->FindMaterial("Thethief_D.tga");
			
			if (mat != NULL) {
				mat->SetTexture(CSkinModelMaterial::enTextureShaderHandle_NormalMap, *TextureResources().Load("Assets/modelData/Thethief_N.tga"));
				mat->SetTexture(CSkinModelMaterial::enTextureShaderHandle_SpecularMap, *TextureResources().Load("Assets/modelData/Thethief_S.tga"));
			}
			//����̃}�e���A�����擾�B
			mat = skinModelData.GetBody()->FindMaterial("Thethief_wuqi_D.tga");
			if (mat != NULL) {
				mat->SetTexture(CSkinModelMaterial::enTextureShaderHandle_NormalMap, *TextureResources().Load("Assets/modelData/Thethief_wuqi_N.tga"));
				mat->SetTexture(CSkinModelMaterial::enTextureShaderHandle_SpecularMap, *TextureResources().Load("Assets/modelData/Thethief_wuqi_S.tga"));
			}
			skinModel.Init(skinModelData.GetBody());
			skinModel.SetLight(&gameScene->GetDefaultLight());
			skinModel.SetHasNormalMap(true);
			skinModel.SetHasSpeculerMap(true);
			skinModel.SetShadowCasterFlag(true);
			skinModel.SetShadowReceiverFlag(true);
			skinModel.SetFresnelFlag(true);
			skinModel.SetReflectionCasterFlag(true);
			skinModel.SetWriteVelocityMap(false);

			isPointLightOn = false;
			UpdatePointLight();

			PlayAnimation(AnimationInvalid, 0.0f);
			rotation = CQuaternion::Identity;
			
			ChangeState(enStateStand);
			radius = 0.6f;
			height = 0.3f;
			characterController.Init(radius, height, position);
			characterController.SetGravity(-18.8f);
			toLampLocalPos.Set(0.0f, 1.0f, 0.5f);
			InitBattleSeats();
			//g_physicsWorld->AddRigidBody(&rigidBody);
			animation.SetAnimationEndTime(AnimationAttack_00, 0.63333f);
			animation.SetAnimationEndTime(AnimationAttack_01, 0.76666f);
			animation.SetAnimationEndTime(AnimationDamage, 0.733333f);
			animation.SetAnimationLoopFlag(AnimationJump, false);
			animation.SetAnimationLoopFlag(AnimationAttack_00, false);
			animation.SetAnimationLoopFlag(AnimationAttack_01, false);
			animation.SetAnimationLoopFlag(AnimationAttack_02, false);
			animation.SetAnimationLoopFlag(AnimationDamage, false);
			animation.SetAnimationLoopFlag(AnimationDeath, false);
			animation.PlayAnimation(AnimationStand);
			nextAttackAnimNo = AnimationInvalid;
			reqAttackAnimNo = AnimationInvalid;

			//�A�j���[�V�����C�x���g�R���g���[���̏������B
			animationEventController.Init(
				&skinModel,
				&animation,
				animationEventGroupTbl,
				sizeof(animationEventGroupTbl) / sizeof(animationEventGroupTbl[0])
				);
			return true;
		}
		break;
	}
	
	return false;
}
bool Player::LockOnEnemy()
{
	bool result = false;

	CMatrix mToPlayerWorld = skinModel.GetWorldMatrix();
	mToPlayerWorld.Inverse(mToPlayerWorld);
	const std::vector<Enemy*>& enemyList = g_enemyManager->GetEnemyList();
	//���b�N�\��Z��臒l
	const float lockOnLen = 20.0f;		//�K���B
	Enemy* nearEnemy = NULL;
	float nearLen = FLT_MAX;
	for (const auto& enemy : enemyList)
	{
		if (!enemy->IsPossibleLockOn()) {
			continue;
		}
		//�G�̍��W���J�������W�n�ɕϊ�����B
		CVector3 posInPlayer = enemy->GetPosition();
		mToPlayerWorld.Mul(posInPlayer);
		float lenTmp = posInPlayer.Length();
		if (lockOnLen > lenTmp) {
			//���b�N�I���B
			if (nearEnemy == NULL) {
				nearEnemy = enemy;
				nearLen = lenTmp;
			}
			else {
				if (lenTmp < nearLen) {
					//�����̕����߂��B
					nearEnemy = enemy;
					nearLen = lenTmp;
				}
			}
			result = true;
		}
	}
	lockOnEnemy = nearEnemy;
	return result;
}
void Player::UpdateStateMachine()
{
	if (currentState != NULL) {
		currentState->Update();
		if (currentState->IsPossibleLockOn()) {
			//���b�N�I���\�H
			if (!isLockOn) {
				if (Pad(0).IsTrigger(enButtonRB3)) {
					//���b�N�I���B
					if (LockOnEnemy()) {
						//�G�����b�N�I���ł����B
						isLockOn = true;
					}
				}
			}
			else {
				
				{
					const std::vector<Enemy*>& enemyList = g_enemyManager->GetEnemyList();
					CVector3 criteriaEnemy = lockOnEnemy->GetPosition();
					criteriaEnemy.Subtract(position);
					criteriaEnemy.Normalize();
					Enemy *nearEnemy = lockOnEnemy;
					float nearEnemyRad = 0.0f;
					//���b�N�I������G��ύX
					if (Pad(0).IsTrigger(enButtonLeft))
					{
						for (Enemy *enemy : enemyList)
						{
							CVector3 enemyDirection = enemy->GetPosition();
							enemyDirection.Subtract(position);
							enemyDirection.Normalize();
							float enemyRad;
							enemyRad = criteriaEnemy.Dot(enemyDirection);
							if (0 < enemyRad)
							{
								nearEnemyRad = enemyRad;
								nearEnemy = enemy;
							}
						}
					}
					else if (Pad(0).IsTrigger(enButtonRight))
					{
						for (Enemy *enemy : enemyList)
						{
							CVector3 enemyDirection = enemy->GetPosition();
							enemyDirection.Subtract(position);
							enemyDirection.Normalize();
							float enemyRad;
							enemyRad = criteriaEnemy.Dot(enemyDirection);
							if (enemyRad < 0)
							{
								nearEnemyRad = enemyRad;
								nearEnemy = enemy;
							}
						}
					}
					lockOnEnemy = nearEnemy;
				}
				
				if (Pad(0).IsTrigger(enButtonRB3)
					|| !lockOnEnemy->IsPossibleLockOn()
				) {
					//�E�X�e�B�b�N�̉������݃{�^���������ꂽ
					//�܂��́A���b�N�I�����̃G�l�~�[�����b�N�I���ł��Ȃ��Ȃ�����
					//���b�N�I������������B
					lockOnEnemy = NULL;
					isLockOn = false;
				}
			}
			lockOn2D->SetLockOnEnemy(lockOnEnemy);
		}
		else {
			//���b�N�I���s�\�B
			lockOnEnemy = NULL;
			isLockOn = false;
		}
	}
	
	position = characterController.GetPosition();
}

/*!
* @brief	�����������B
*/
void Player::Damage()
{
	isApplyDamageTrigger = false;
	if(currentState->IsPossibleDamage()){
		CRigidBody* rb = characterController.GetRigidBody();
		const DamageCollisionWorld::Collision* dmgColli = g_damageCollisionWorld->FindOverlappedDamageCollision(
			DamageCollisionWorld::enDamageToPlayer,
			rb->GetBody()
		);
		if (dmgColli != NULL) {
			//�_���[�W���󂯂��B
			hp -= dmgColli->damage;
			if (hp <= 0.0f) {
				//���S
				hp = 0;
				ChangeState(enState_Dead);
				isApplyDamageTrigger = true;
			}
			else {
				ChangeState(enState_Damage);
				isApplyDamageTrigger = true;
			}
		}
	}
}
/*!
* @brief	�|�C���g���C�g���X�V�B
*/
void Player::UpdatePointLight()
{
	if (Pad(0).IsTrigger(enButtonLB3)) {
		isPointLightOn = !isPointLightOn;
	}

	if (isPointLightOn) {
		pointLightColor.Set(0.25f, 0.25f, 0.25f, 3.0f);
	}
	else {
		pointLightColor = CVector4(0.0f, 0.0f, 0.0f, 0.0f);
	}
	//light.SetPointLightColor(pointLightColor);
	pointLightPosition = toLampLocalPos;
	CMatrix mWorld = skinModel.GetWorldMatrix();
	mWorld.Mul(pointLightPosition);

	gameScene->GetDefaultLight().SetPointLightPosition(pointLightPosition);
	gameScene->GetDefaultLight().SetPointLightColor(pointLightColor);
}
/*!
* @brief	���񏈗��B
*/
void Player::Turn()
{
	if (isLockOn) {
		CVector3 toEnemy;
		toEnemy.Subtract(lockOnEnemy->GetPosition(), position);
		rotation.SetRotation(CVector3::Up, atan2f(toEnemy.x, toEnemy.z));
	}
	else {
		CVector3 moveSpeed = characterController.GetMoveSpeed();
		moveSpeed.y = 0.0f;
		if (moveSpeed.LengthSq() > 0.001f) {
			rotation.SetRotation(CVector3::Up, atan2f(moveSpeed.x, moveSpeed.z));
		}
	}
	
}
/*!
* @brief	�A�j���[�V�����Đ��B
*/
void Player::PlayAnimation(AnimationNo animNo, float interpolateTime)
{
	if (animation.GetPlayAnimNo() != animNo && animNo != AnimationInvalid) {
		//�ʂ̃A�j���[�V����
		animation.PlayAnimation(animNo, interpolateTime);
	}
}
/*!
* @brief	�A�j���[�V�����R���g���[���B
*/
void Player::AnimationControl()
{
	if (characterController.IsJump()) {
		PlayAnimation(AnimationJump, 0.05f);
	}else{
		if (state == enStateRun) {
			if (characterController.GetMoveSpeed().LengthSq() > RUN_THREADHOLD_SQ) {
				//����A�j���[�V�����𗬂��B
				PlayAnimation(AnimationRun, 0.1f);
			}
			else {
				//�����A�j���[�V�����B
				PlayAnimation(AnimationWalk, 0.1f);
			}
		}
		else if (state == enStateStand) {
			//�����A�j���[�V�����𗬂��B
			PlayAnimation(AnimationStand, 0.3f);
		}
		else if (state == enState_Attack) {
			if (nextAttackAnimNo == AnimationAttack_Start) {
				//�U���J�n�B
				PlayAnimation(nextAttackAnimNo, 0.1f);
				reqAttackAnimNo = nextAttackAnimNo;
				nextAttackAnimNo = AnimationInvalid;
			}else if( nextAttackAnimNo != AnimationInvalid ){
				//�A���̃A�j���[�V���������N�G�X�g�L���[�ɐςށB
				animation.PlayAnimationQueue(nextAttackAnimNo, 0.05f);
				reqAttackAnimNo = nextAttackAnimNo;
				nextAttackAnimNo = AnimationInvalid;
			}
		}
		else if (state == enState_Damage) {
			if (isApplyDamageTrigger) {
				//�ʂ̃A�j���[�V����
				animation.PlayAnimation(AnimationDamage, 0.1f);
			}
		}
		else if (state == enState_Dead) {
			PlayAnimation(AnimationDeath, 0.1f);
		}
	}
	animation.Update(localFrameDeltaTime);
}
/*!
* @brief	�o�g���Ŏg�p����V�[�g���������B
*/
void Player::InitBattleSeats()
{
	float angleBase = 2.0f * CMath::PI / NUM_BATTLE_SEAT;
	for (int i = 0; i < NUM_BATTLE_SEAT; i++) {
		battleSeats[i].seatNo = i;
		battleSeats[i].isUse = false;
		battleSeats[i].localPosition.x = sinf(angleBase * i) * 1.5f;
		battleSeats[i].localPosition.y = 0.0f;
		battleSeats[i].localPosition.z = cosf(angleBase * i) * 1.5f;
		battleSeats[i].position.Add(battleSeats[i].localPosition, position);
	}
}
/*!
* @brief	�o�g���Ŏg�p����V�[�g���X�V�B
*/
void Player::UpdateBattleSeats()
{
	for (auto& seat : battleSeats) {
		seat.position.Add(seat.localPosition, position);
	}
}
/*!
* @brief	���g�p�̃V�[�g�������B
*@param[in]	pos		���g�p�̃V�[�g�̒����炱�̍��W�Ɉ�ԋ߂��V�[�g��Ԃ��܂��B
*@return		���g�p�̃V�[�g���Ȃ��ꍇ��NULL���Ԃ��Ă���B
*/
Player::SBattleSeat* Player::FindUnuseSeat(const CVector3& pos)
{
	float dist = FLT_MAX;
	float distTmp;
	SBattleSeat* result = NULL;
	for (auto& seat : battleSeats) {
		if (!seat.isUse) {
			//���g�p�B
			CVector3 diff;
			diff.Subtract(seat.position, pos);
			distTmp = diff.LengthSq();
			if (distTmp < dist) {
				dist = distTmp;
				result = &seat;
			}
		}
	}
	return result;
}
/*!
* @brief	�����Ԃ��̃p�[�e�B�N�����G�~�b�g�B
*/
void Player::EmitBloodParticle()
{
	CMatrix* m = skinModel.FindBoneWorldMatrix("thief_Bip01_Neck");
	for (SParicleEmitParameter& param : bloodEmitterParam) {
		CParticleEmitter* particleEmitter = NewGO<CParticleEmitter>(1);
		CVector3 pos;
		pos.Set(m->m[3][0], m->m[3][1], m->m[3][2]);
		particleEmitter->Init(g_random, g_camera->GetCamera(), param, pos);
		particleEmitterList.push_back(particleEmitter);
		CSoundSource* se = NewGO<CSoundSource>(0);
		se->Init("Assets/sound/Damage_01.wav");
		se->Play(false);
		se->SetVolume(0.5f);
	}
}
/*!
* @brief	��Ԑ؂�ւ��B
*/
void Player::ChangeState(EnState nextState)
{
	if (currentState != NULL) {
		//���݂̃X�e�[�g�𔲂���B
		currentState->Leave();
	}
	switch (nextState) {
	case enStateStand:
		currentState = &standState;
		break;
	case enStateRun:
		currentState = &runState;
		break;
	case enState_Attack:
		currentState = &attackState;
		break;
	case enState_Damage:
		currentState = &damageState;
		break;
	case enState_Dead:
		currentState = &deadState;
		break;
	default:
		TK_ASSERT(false, "nextState is invalid");
		break;
	}
	state = nextState;
	currentState->Enter();
	
}
/*!
* @brief	�X���b�g�ɐݒ肳��Ă��閂�@���X�V�B
*/
void Player::UpdateCurrentMagicSkill()
{
	bool isChangeMagic = false;
	if (Pad(0).IsTrigger(enButtonRB1)) {
		currentMagicSkill = (EMagicSkill)((currentMagicSkill + 1) % eMagicSkillNum);
		isChangeMagic = true;
	}
	else if (Pad(0).IsTrigger(enButtonLB1)) {
		int t = currentMagicSkill - 1;
		if (t < 0) {
			currentMagicSkill = (EMagicSkill)(eMagicSkillNum - 1);
		}
		else {
			currentMagicSkill = (EMagicSkill)t;
		}
		isChangeMagic = true;
	}
	if (isChangeMagic) {
		switch (currentMagicSkill) {
		case eMagicSkillDash:
			if (pCurrentMagicSkill != NULL) {
				pCurrentMagicSkill->OnEndMagic();
			}
			pCurrentMagicSkill = &magicSkillDash;
			pCurrentMagicSkill->OnChangeMagic();
			break;
		case eMagicSkillSlow:
			if (pCurrentMagicSkill != NULL) {
				pCurrentMagicSkill->OnEndMagic();
			}
			pCurrentMagicSkill = &magicSkillSlow;
			pCurrentMagicSkill->OnChangeMagic();
			break;
		case eMagicSkillStopTheWorld:
			if (pCurrentMagicSkill != NULL) {
				pCurrentMagicSkill->OnEndMagic();
			}
			pCurrentMagicSkill = &magicSkillStop;
			pCurrentMagicSkill->OnChangeMagic();
			break;
		case eMagicSkillStealth:
			if (pCurrentMagicSkill != NULL) {
				pCurrentMagicSkill->OnEndMagic();
			}
			pCurrentMagicSkill = &magicSkillStealth;
			pCurrentMagicSkill->OnChangeMagic();
			break;
		case eMagicSkillHighJump:
			break;
		default:
			TK_LOG("������\n");
			break;
		}
	}
	if (pCurrentMagicSkill != NULL) {
		pCurrentMagicSkill->Update();
	}
}
/*!
* @brief	�`��B
*/
void Player::Render(CRenderContext& renderContext)
{
	skinModel.Draw(renderContext, g_camera->GetCamera().GetViewMatrix(), g_camera->GetCamera().GetProjectionMatrix());
}

void Player::Update()
{
	if (!gameScene->IsStart()) {
		return;
	}
	localFrameDeltaTime = GameTime().GetFrameDeltaTime();
	//�X���b�g�ɐݒ肳��Ă��閂�@���X�V�B
	UpdateCurrentMagicSkill();
	//�X�e�[�g�}�V�[���̍X�V�B
	UpdateStateMachine();
	//����B
	Turn();
	//�_���[�W�����B
	Damage();
	//�A�j���[�V�����R���g���[���B
	AnimationControl();
	//�o�g���p�̃V�[�g�̍X�V�B
	UpdateBattleSeats();
	//�A�j���[�V�����C�x���g�R���g���[���̎��s�B
	animationEventController.Update();
	//�}�W�b�N�|�C���g�͏����Â񕜂���B
	RecoverMagicPoint(RECOVER_MP * GameTime().GetFrameDeltaTime());
	//���[���h�s��̍X�V�B
	skinModel.Update(position, rotation, CVector3::One);
	//�|�C���g���C�g���X�V�B
	UpdatePointLight();
	

	lastFrameState = state;
}