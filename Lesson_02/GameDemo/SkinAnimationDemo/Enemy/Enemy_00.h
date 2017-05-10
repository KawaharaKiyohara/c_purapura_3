/*!
 * @brief	�^�C�v0�̓G�B
 */

#pragma once


#include "Enemy/Enemy.h"
#include "tkEngine/shape/tkSphereShape.h"


class IEnemyState;
/*!
 * @brief	�^�C�v0�̓G�B
 */
class Enemy_00 : public Enemy{
	//���
	enum EnLocalState {
		enLocalState_Search,	//�p�j���B
		enLocalState_Find,		//������ԁB
		enLocalState_Damage,	//�_���[�W�����B
		enLocalState_Death,		//���S�B
	};
public:
	Enemy_00();
	~Enemy_00();
	void Init( const char* modelPath, CVector3 pos, CQuaternion	rotation) override;
	void Update() override;
	void Render(CRenderContext& renderContext) override;
	/*!
	* @brief	���b�N�I���\������B
	*@retval	true	���b�N�I���\�B
	*@retval	false	���b�N�I���s�\�B
	*/
	bool IsPossibleLockOn() const override;
private:
	void Damage();
	void InitHFSM();
	/*!
	* @brief	�X�L�����f���f�[�^�̓ǂݍ��݂������������ɌĂ΂��R�[���o�b�N�B
	*/
	void OnLoadedSkinModelData()override;
private:
	std::vector<IEnemyState*>			states;					//�X�e�[�g�̃��X�g�B
	EnLocalState						state;					//�X�e�[�g�B
	
	std::unique_ptr<btCollisionObject>	collisionObject;		//�R���W�����I�u�W�F�N�g�B
	std::unique_ptr<CSphereCollider>	sphereShape;			//
};