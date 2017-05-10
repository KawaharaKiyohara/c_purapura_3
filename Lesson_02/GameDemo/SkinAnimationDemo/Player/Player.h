#pragma once


#include "AnimationEventController.h"
#include "Player/FSM/PlayerStateAttack.h"
#include "Player/FSM/PlayerStateDamage.h"
#include "Player/FSM/PlayerStateDead.h"
#include "Player/FSM/PlayerStateRun.h"
#include "Player/FSM/PlayerStateStand.h"
#include "Player/MagicSkill/IMagicSkill.h"
#include "Player/MagicSkill/MagicSkillDash.h"
#include "Player/MagicSkill/MagicSkillTimeCtr.h"
#include "Player/MagicSkill/MagicSkillStealth.h"

namespace tkEngine{
	class CParticleEmitter;
}

class Enemy;
class LockOn2D;

/*!
 * @brief	�v���C���[�B
 */
class Player : public IGameObject {
private:
	static const int NUM_BATTLE_SEAT = 8;		//�V�[�g�̐��B
	//�������X�e�b�v�B
	enum InitStep {
		InitStep_LoadModelData,
		InitStep_WaitModelData,
	};
public:
	enum EMagicSkill{
		eMagicSkillDash,			//!<�_�b�V���͋����B
		eMagicSkillSlow,			//!<���肪�X���[���[�V�����B
		eMagicSkillStopTheWorld,	//!<���Ԓ�~�B
		eMagicSkillStealth,			//!<�������B
		eMagicSkillHighJump,		//!<�W�����v�͋����B
		eMagicSkillNum,				//!<�}�W�b�N�X�L���̐��B
	};
	
	enum AnimationNo {
		AnimationInvalid = -1,
		AnimationStand,		//�����B
		AnimationWalk,		//�����B
		AnimationRun,		//����B
		AnimationJump,		//�W�����v�B
		AnimationAttack_Start,
		AnimationAttack_00 = AnimationAttack_Start,	//�U��00�B
		AnimationAttack_01,	//�U��01�B
		AnimationAttack_02,	//�U��02�B
		AnimationAttack_End = AnimationAttack_02,
		AnimationDamage,	//�_���[�W�B
		AnimationDeath,		//���S�B
		NumAnimation,		//�A�j���[�V�����̐��B
	};
	//�퓬�Ŏg�p����V�[�g
	struct SBattleSeat {
		bool		isUse;			//�g�p���t���O�B
		int			seatNo;			//�V�[�g�ԍ��B
		CVector3	localPosition;	//���[�J�����W�B
		CVector3	position;		//���[���h���W�B
	};
	enum EnState {
		enStateRun,			//�����Ă���B
		enStateStand,		//�����~�܂��Ă���B
		enState_Attack,		//�U���B
		enState_Damage,		//�_���[�W���󂯂Ă���B
		enState_Dead,		//���S�B
	};
	bool					isUpdateAnim;		//

	Player(); 
	~Player();
	bool Start() override ;
	void Update() override ;
	void Render( CRenderContext& renderContext ) override;
	void SetPosition(const CVector3& position)
	{
		this->position = position;
	}
	const CVector3& GetPosition() const
	{
		return position;
	}
	/*!
	* @brief	��Ԃ��擾�B
	*/
	EnState GetState() const
	{
		return state;
	}
	/*!
	* @brief	�|�C���g���C�g�̈ʒu���擾�B
	*/
	const CVector3& GetPointLightPosition() const
	{
		return pointLightPosition;
	}
	/*!
	* @brief	�|�C���g���C�g�̐F���擾�B
	*/
	const CVector4& GetPointLightColor() const
	{
		return pointLightColor;
	}
	/*!
	* @brief	���g�p�̃V�[�g�������B
	*@param[in]	pos		���g�p�̃V�[�g�̒����炱�̍��W�Ɉ�ԋ߂��V�[�g��Ԃ��܂��B
	*@return		���g�p�̃V�[�g���Ȃ��ꍇ��NULL���Ԃ��Ă���B
	*/
	SBattleSeat* FindUnuseSeat(const CVector3& pos) ;
	/*!
	* @brief	���̃��[���h�s�������
	*@details
	* ���O�Ō������s���Ă��邽�߁A�x���ł��B�p�ɂɌĂ΂Ȃ��悤�ɁB
	*@param[in]	boneName	���̖��O�B
	*@return ���������獜�̃��[���h�s��̃A�h���X��Ԃ��B������Ȃ������ꍇ��NULL��Ԃ��B
	*/
	CMatrix* FindBoneWorldMatrix(const char* boneName)
	{
		return skinModel.FindBoneWorldMatrix(boneName);
	}
	/*!
	* @brief	HP�̎擾�B
	*/
	int GetHP() const
	{
		return hp;
	}
	/*!
	* @brief	�ő�HP�̎擾�B
	*/
	int GetMaxHP() const
	{
		return maxHP;
	}
	/*!
	* @brief	MP�̎擾�B
	*/
	float GetMP() const
	{
		return mp;
	}
	/*!
	* @brief	�ő�MP�̎擾�B
	*/
	float GetMaxMP() const
	{
		return maxMP;
	}
	/*!
	 * @brief	���݃X���b�g�ɃZ�b�g����Ă��閂�@���擾�B
	 */
	EMagicSkill GetCurrentMagicSkill() const
	{
		return currentMagicSkill;
	}
	/*!
	* @brief	�v���C���[�̓������^�C����ݒ�B
	*/
	void SetLocalFrameDeltaTime(float deltaTime)
	{
		localFrameDeltaTime = deltaTime;
	}
	/*!
	* @brief	�v���C���[�̓������^�C�����擾�B
	*/
	float GetLocalFrameDeltaTime() const
	{
		return localFrameDeltaTime;
	}
	/*!
	* @brief	�}�W�b�N�|�C���g���g�p����B
	*/
	void UseMagicPoint(float useMp)
	{
		mp = max(0, mp - useMp);
	}
	/*!
	* @brief	�X�e���X���ʃt���O��ݒ�B
	*/
	void SetStealthFlag(bool flag)
	{
		skinModel.SetStealth(flag);
	}

	void Heel()
	{
		hp = maxHP;
	}
private:
	/*!
	* @brief	�����Ԃ��̃p�[�e�B�N�����G�~�b�g�B
	*/
	void EmitBloodParticle();
	/*!
	* @brief	��Ԑ؂�ւ��B
	*/
	void ChangeState(EnState nextState);
	/*!
	* @brief	�����������B
	*/
	void Damage();
	/*!
	* @brief	�|�C���g���C�g���X�V�B
	*/
	void UpdatePointLight();
	/*!
	* @brief	�A�j���[�V�����R���g���[���B
	*/
	void AnimationControl();
	/*!
	* @brief	�A�j���[�V�����Đ��B
	*/
	void PlayAnimation(AnimationNo animNo, float interpolateTime);
	/*!
	* @brief	�o�g���Ŏg�p����V�[�g���������B
	*/
	void InitBattleSeats();
	/*!
	* @brief	�o�g���Ŏg�p����V�[�g���X�V�B
	*/
	void UpdateBattleSeats();

	void UpdateStateMachine();
	
	/*!
	* @brief	�}�W�b�N�|�C���g�̉񕜁B
	*/
	void RecoverMagicPoint(float recoverMp)
	{
		mp = min(maxMP, mp + recoverMp);
	}
	/*!
	* @brief	�G�����b�N�I���B
	*@retval	true	���b�N�I���ł����B
	*@retval	false	���b�N�I���ł��Ȃ������B
	*/
	bool LockOnEnemy();
	/*!
	* @brief	���񏈗��B
	*/
	void Turn();
	/*!
	* @brief	�X���b�g�ɐݒ肳��Ă��閂�@���X�V�B
	*/
	void UpdateCurrentMagicSkill();
private:

	friend class PlayerStateAttack;
	friend class PlayerStateDamage;
	friend class PlayerStateDead;
	friend class PlayerStateRun;
	friend class PlayerStateStand;
	
	CSkinModelDataHandle	skinModelData;
	CSkinModel				skinModel;							//�X�L�����f���B
	CAnimation				animation;							//�A�j���[�V�����B
	CVector3				position;							//���W�B
	CQuaternion				rotation;							//��]
	CVector3				toLightPos;							//
	CVector3				pointLightPosition;					//�|�C���g���C�g�̈ʒu�B
	CVector4				pointLightColor;					//�|�C���g���C�g�̃J���[�B
	CVector3				toLampLocalPos;						//�����v�̃��[�J�����W�B
	bool					isApplyDamageTrigger = false;
	EnState					state;								//��ԁB
	EnState					lastFrameState;						//�O�̃t���[���̏�ԁB
	bool					isPointLightOn;						//�|�C���g���C�g�̃X�C�b�`�B
	CRigidBody				rigidBody;							//���́B
	CCharacterController	characterController;				//�L�����N�^�R���g���[���B
	SBattleSeat				battleSeats[NUM_BATTLE_SEAT];		//�V�[�g�B
	AnimationNo				reqAttackAnimNo;					//�Đ��̃��N�G�X�g���o���Ă���U�����[�V�����ԍ��B
	AnimationNo				nextAttackAnimNo;					//���̍U�����[�V�����ԍ��B
	AnimationEventController	animationEventController;		//�A�j���[�V�����C�x���g�R���g���[���B
	std::list<CParticleEmitter*>	particleEmitterList;
	int						hp =  100;							//�q�b�g�|�C���g�B
	int						maxHP = 100;						//�ő�q�b�g�|�C���g�B
	float					mp = 300.0f;						//�}�W�b�N�|�C���g�B
	float					maxMP = 300.0f;						//�ő�}�W�b�N�|�C���g�B
	float					radius = 0.0f;
	float					height = 0.0f;
	float					magicPointRecoverTimer = 0.0f;		//�}�W�b�N�|�C���g�̉񕜃^�C�}�[�B
	bool					isLockOn = false;					//���b�N�I���H
	Enemy*					lockOnEnemy = NULL;					//���b�N�I�����Ă���G�l�~�[�B
	IPlayerState*			currentState = NULL;				//���݂̃X�e�[�g�B
	PlayerStateAttack		attackState;						//�U���X�e�[�g�B
	PlayerStateDamage		damageState;						//�_���[�W�X�e�[�g�B
	PlayerStateDead			deadState;							//���S�X�e�[�g�B
	PlayerStateRun			runState;							//����X�e�[�g�B
	PlayerStateStand		standState;							//�ҋ@�X�e�[�g�B
	LockOn2D*				lockOn2D = NULL;						//���b�N�I��2D
	InitStep				initStep = InitStep_LoadModelData;		//�������X�e�b�v�B
	EMagicSkill				currentMagicSkill = eMagicSkillDash;	//���݃X���b�g�ɃZ�b�g����Ă��閂�@�B
	IMagicSkill*			pCurrentMagicSkill = NULL;				//���݃X���b�g�ɃZ�b�g����Ă��閂�@�B
	MagicSkillDash			magicSkillDash;							//�_�b�V�����@�B
	MagicSkillTimeCtr		magicSkillSlow;							//�X���E���@�B
	MagicSkillTimeCtr		magicSkillStop;							//���Ԓ�~���@�B
	MagicSkillStealth		magicSkillStealth;						//�X�e���X���@�B
	float					localFrameDeltaTime = 0.0f;				//�v���C���[�̓������^�C��(�P�ʁF�b)�B
};