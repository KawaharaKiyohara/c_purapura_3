/*!
 *@brief	�G�̊��N���X�B
 */
#include "stdafx.h"
#include "Enemy/Enemy.h"
#include "tkEngine/Physics/tkPhysics.h"
#include "tkEngine/Physics/tkCollisionAttr.h"
#include "Enemy/EnemyParameter.h"
#include "Scene/GameScene.h"
#include "tkEngine/nature/tkSky.h"

void Enemy::Init(const char* modelPath, CVector3 pos, CQuaternion rotation)
{
	for (const EnemyParam& param : g_enemyParamTable) {
		if (strcmp(param.name, modelPath) == 0) {
			enemyParam = &param;
			break;
		}
	}
	position = pos;
	this->rotation = rotation;
	sprintf(modelFilePath, "Assets/modelData/%s.x", modelPath);
	skinModelData.LoadModelDataAsync(
		modelFilePath,
		&animation
	);
	
}
bool Enemy::Start()
{
	if (skinModelData.IsLoadEnd()) {
		OnLoadedSkinModelData();
		//�}�e���A�����擾�B
		const std::vector<CSkinModelMaterial*> materials = skinModelData.GetBody()->GetSkinModelMaterials();
		int i = 0;
		for (CSkinModelMaterial* mat : materials) {
			char work[256];
			strcpy(work, mat->GetName());
			strtok(work, ".");
			sprintf(modelFilePath, "Assets/modelData/%s_n.png", work);
			CTexture* tex = TextureResources().Load(modelFilePath);
			if (tex) {
				mat->SetTexture(CSkinModelMaterial::enTextureShaderHandle_NormalMap, *tex);
				skinModel.SetHasNormalMap(true);
			}
			sprintf(modelFilePath, "Assets/modelData/%s_s.png", work);
			tex = TextureResources().Load(modelFilePath);
			if (tex) {
				mat->SetTexture(CSkinModelMaterial::enTextureShaderHandle_SpecularMap, *tex);
				skinModel.SetHasSpeculerMap(true);
			}

			i++;
		}

		skinModel.Init(skinModelData.GetBody());
		
		initPosition = position;
		

		skinModel.SetLight(&gameScene->GetDefaultLight());
		skinModel.SetShadowCasterFlag(true);
		skinModel.SetShadowReceiverFlag(true);
		skinModel.SetFresnelFlag(true);

		radius = 0.6f;
		height = 1.5f;
		characterController.Init(radius, height, position);
		characterController.SetGravity(-18.8f);
		if (enemyParam->animationEventGroup != NULL) {
			animationEventController.Init(
				&skinModel,
				&animation,
				enemyParam->animationEventGroup,
				enNumAnim
				);
		}

		//�I�u�W�F�N�g�̃J�����O�����̏������B
		objectCulling.Init(g_camera->GetCamera());
		//AABB���������B
		CalcAABBCenterPosAndHalfSize();
		aabb.Init(centerPosition, aabbHalfSize);
		return true;
	}
	return false;
}
/*!
* @brief	AABB�̒��S���W�ƃn�[�t�T�C�Y���v�Z�B
*/
void Enemy::CalcAABBCenterPosAndHalfSize()
{
	aabbHalfSize.x = radius;
	aabbHalfSize.y = height * 0.5f;
	aabbHalfSize.z = radius;
	centerPosition = position;
	centerPosition.y += aabbHalfSize.y;
}
void Enemy::Update()
{
	if (!gameScene->IsStart()) {
		return;
	}
	animationEventController.Update();

	CalcAABBCenterPosAndHalfSize();
	aabb.Update(centerPosition, aabbHalfSize);
	//�I�u�W�F�N�g�J�����O�����̎��s�B
	objectCulling.Execute(aabb);
}
/*!
* @brief	���S�������Ƃ�ʒm�B
*/
void Enemy::NotifyDead()
{
	characterController.RemoveRigidBoby();
}
