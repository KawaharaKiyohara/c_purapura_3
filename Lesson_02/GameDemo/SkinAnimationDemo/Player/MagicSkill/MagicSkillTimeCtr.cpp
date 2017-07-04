/*!
 * @brief	���ԑ���n
 */

#include "stdafx.h"
#include "Player/MagicSkill/MagicSkillTimeCtr.h"
#include "Player/Player.h"
#include "Enemy/EnemyManager.h"
#include "Enemy/Enemy.h"
#include "tkEngine/Sound/tkSoundSource.h"
#include "Scene/gameScene.h"


void MagicSkillTimeCtr::Finish::Update()
{
	float blendRate = postEffectFilter.GetBlendRate();
	blendRate = blendRate - 4.0f * GameTime().GetFrameDeltaTime();
	

	if (blendRate < 0.0f) {
		//�I���B
		DeleteGO(this);
		postEffectFilter.SetEnalbe(false);
	}
	else {
		//�}�X�N�������_�����O����֐��B
		auto maskRender = [](CRenderContext& renderContext) {
			//�v���C���[�������_�����O���ă}�X�N���쐬����B
			g_player->Render(renderContext);
			for (auto& e : g_enemyManager->GetEnemyList()) {
				e->Render(renderContext);
			}
		};
		postEffectFilter.RegistMaskSkinModel(maskRender);
		postEffectFilter.SetBlendRate(blendRate);
	}
}
MagicSkillTimeCtr::MagicSkillTimeCtr(Player* pl, IPostEffectFilter& filter, float mulDeltaTime, float useMp) :
	IMagicSkill(pl),
	finish(filter),
	postEffectFilter(filter)
{
	this->mulDeltaTime = mulDeltaTime;
	this->useMp = useMp;
}
MagicSkillTimeCtr::~MagicSkillTimeCtr()
{
}
void MagicSkillTimeCtr::OnChangeMagic()
{
}
void MagicSkillTimeCtr::OnStartMagic()
{
	//�ۓ������Đ�
	CSoundSource* s = NewGO<CSoundSource>(0);
	s->Init("Assets/Sound/heartbeat.wav");
	s->Play(false);
	g_enemyManager->SetFrameDeltaTimeMul(mulDeltaTime);
	Sky().SetFrameDeltaTimeMul(mulDeltaTime);
	postEffectFilter.SetEnalbe(true);

	auto pauseSound = [](IGameObject* go) {
		CSoundSource* s = (CSoundSource*)go;
		s->Pause();
	};
	FindGameObjectsWithTag(
		GameScene::enGameObjectTags_BGM | GameScene::enGameObjectTags_EnemySound,
		pauseSound
	);

	//�I�������������Ă��邩������Ȃ��̂ō폜�B
	DeleteGO(&finish);
}
void MagicSkillTimeCtr::OnEndMagic()
{
	g_enemyManager->SetFrameDeltaTimeMul(1.0f);
	Sky().SetFrameDeltaTimeMul(1.0f);
	//�I���������Q�[���I�u�W�F�N�g�}�l�[�W���[�ɓo�^�B
	AddGO(0, &finish);
	//�����ł��}�X�N��`�悵�Ȃ��ƂP�t���[�������}�X�N���Ȃ���Ԃŕ`�悳��Ă��܂��B
	postEffectFilter.RegistMaskSkinModel([](CRenderContext& renderContext) {
		//�v���C���[�������_�����O���ă}�X�N���쐬����B
		g_player->Render(renderContext);
		for (auto& e : g_enemyManager->GetEnemyList()) {
			e->Render(renderContext);
		}
	});
	auto resumeSound = [](IGameObject* go) {
		CSoundSource* s = (CSoundSource*)go;
		s->Play(s->GetLoopFlag());
	};
	FindGameObjectsWithTag(
		GameScene::enGameObjectTags_BGM | GameScene::enGameObjectTags_EnemySound,
		resumeSound
		);
}
void MagicSkillTimeCtr::OnUsingMagicSkill()
{
	float blendRate = postEffectFilter.GetBlendRate();
	blendRate = min(1.0f, blendRate + 4.0f * GameTime().GetFrameDeltaTime());
	postEffectFilter.SetBlendRate(blendRate);
	postEffectFilter.RegistMaskSkinModel([](CRenderContext& renderContext){
		//�v���C���[�������_�����O���ă}�X�N���쐬����B
		g_player->Render(renderContext);
		for (auto& e : g_enemyManager->GetEnemyList()) {
			e->Render(renderContext);
		}
	});
}

