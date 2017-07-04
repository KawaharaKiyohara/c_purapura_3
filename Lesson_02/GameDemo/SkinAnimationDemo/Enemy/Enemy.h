/*!
 * @brief	�G�̊��N���X�B
 */
 
#pragma once

#include "tkEngine/character/tkCharacterController.h"
#include "AnimationEventController.h"
#include "tkEngine/culling/tkObjectFrustumCulling.h"

struct EnemyParam;
class Enemy : public IGameObject{
public:
	enum EnAnimation {
		enAnimStand,
		enAnimWalk,
		enAnimAttack,
		enAnimDamage,
		enAnimDeath,
		enNumAnim,
		enAnimInvalid = 0xffffffff
	};
	Enemy() :
		currentAnimNo(enAnimInvalid),
		moveSpeed(0.0f),
		moveDirection(CVector3::AxisZ)
	{
	}
	virtual ~Enemy()
	{
	}
	virtual void Init(const char* modelPath, CVector3 pos, CQuaternion rotation);
	bool Start() override;
	void Update() override;
	void PlayAnimation(EnAnimation animNo)
	{
		if(currentAnimNo != animNo)
		{
			animation.PlayAnimation(animNo, 0.3f);
			currentAnimNo = animNo;
		}
	}
	//�����A�j���[�V�������Đ�����Ă��Ă��C�ɂ����ɂł��ŏ����痬���B
	void PlayAnimationForce(EnAnimation animNo)
	{
		animation.PlayAnimation(animNo, 0.3f);
		currentAnimNo = animNo;
	}
	void SetMoveSpeed(float moveSpeed)
	{
		this->moveSpeed = moveSpeed;
	}
	const CVector3& GetMoveDirection() const
	{
		return moveDirection;
	}
	void SetMoveDirection( const CVector3& dir )
	{
		moveDirection = dir;
	}
	void SetDirection(const CVector3& dir)
	{
		direction = dir;
	}
	
	

	bool IsPlayAnimation() const
	{
		return animation.IsPlay();
	}
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
	* @brief	�G�̃p�����[�^���擾�B
	*/
	const EnemyParam* GetEnemyParam() const
	{
		return enemyParam;
	}
	/*!
	* @brief	���S�������Ƃ�ʒm�B
	*/
	void NotifyDead();
	/*!
	* @brief	���W���擾�B
	*/
	const CVector3& GetPosition() const
	{
		return position;
	}
	/*!
	* @brief	���b�N�I���\������B
	*@retval	true	���b�N�I���\�B
	*@retval	false	���b�N�I���s�\�B
	*/
	virtual bool IsPossibleLockOn() const
	{
		return true;
	}
	/*!
	* @brief	�������擾�B
	*/
	float GetHeight() const
	{
		return height;
	}
	/*!
	* @brief	���[�J�����^�C�����擾�B
	*/
	float GetLocalFrameDeltaTime() const
	{
		return GameTime().GetFrameDeltaTime() * deltaTimeMul;
	}
	/*!
	* @brief	���^�C���ɏ�Z�����l��ݒ�B
	*@param[in]	mul		�O���[�o�����^�C���ɏ�Z�����l�B���̒l��0.5��ݒ肷��ƃG�l�~�[�̋�����0.5�{���ɂȂ�܂��B
	*/
	void SetFrameDeltaTimeMul(float mul)
	{
		deltaTimeMul = mul;
	}
private:
	/*!
	* @brief	AABB�̒��S���W�ƃn�[�t�T�C�Y���v�Z�B
	*/
	void CalcAABBCenterPosAndHalfSize();
	/*!
	* @brief	�X�L�����f���f�[�^�̓ǂݍ��݂������������ɌĂ΂��R�[���o�b�N�B
	*/
	virtual void OnLoadedSkinModelData() {} 
protected:

	CSkinModelDataHandle			skinModelData;
	CSkinModel						skinModel;			//�X�L�����f���B
	CAnimation						animation;			//�A�j���[�V�����B
	CVector3						position;			//�ʒu
	CQuaternion						rotation;			//��]�B
	CVector3						centerPosition;		//���S���W�B
	CVector3						aabbHalfSize;		//AABB�̃n�[�t�T�C�Y�B
	EnAnimation						currentAnimNo;		//���݂̃A�j���[�V�����ԍ��B
	float							moveSpeed;			//�ړ����x�B
	CVector3						moveDirection;		//�i�s�����B
	CVector3						direction;			//�����B
	int								hp;					//�̗́B
	const EnemyParam*				enemyParam;			//�G�̃p�����[�^�B
	CVector3						initPosition;			//�����ʒu�B
	AnimationEventController		animationEventController;	//�A�j���[�V�����C�x���g�R���g���[���[�B
	CCharacterController			characterController;	//�L�����N�^�R���g���[���B
	float							height;
	float							radius;
	float							timer = 0.0f;
	CObjectFrustumCulling			objectCulling;			//�I�u�W�F�N�g�̃J�����O�����B
	CAabb							aabb;					//�I�u�W�F�N�g������AABB
	char							modelFilePath[1024];
	float							deltaTimeMul = 1.0f;	//���^�C���ɏ�Z�����l�B
};