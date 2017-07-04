#include "stdafx.h"
#include "Enemy/EnemyManager.h"
#include "Enemy/Enemy_00.h"

using namespace std;
namespace {
	struct SEnemyLocInfo {
		const char* modelName;		//���f���B
		CVector3	pos;			//���W�B
		CQuaternion	rotation;		//��]�B
	};
	SEnemyLocInfo enemyLocInfoTable[] = {
		#include "EnemyInfo.h"
		{NULL, CVector3::Zero, CQuaternion::Identity}
	};
}
EnemyManager::EnemyManager()
{
}
EnemyManager::~EnemyManager()
{
	for (auto& enemy : enemyList) {
		DeleteGO(enemy);
	}
}
bool EnemyManager::Start()
{
	//�z�u��񂩂�G���\�z�B
	map<const char*, vector<SEnemyLocInfo*>*> m;
	//�������O�̃��f�����W�߂�B
	for (SEnemyLocInfo& info : enemyLocInfoTable) {
		if (info.modelName) {
			Enemy_00* enemy = NewGO<Enemy_00>(0);
			enemy->Init(info.modelName, info.pos, info.rotation);
			enemyList.push_back(enemy);
		}
	}
	return true;
}
void EnemyManager::SetFrameDeltaTimeMul(float mul)
{
	for (auto e : enemyList) {
		e->SetFrameDeltaTimeMul(mul);
	}
}
void EnemyManager::Update()
{
}
void EnemyManager::Render(CRenderContext& renderContext) 
{
}
