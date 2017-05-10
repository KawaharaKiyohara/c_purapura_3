#include "stdafx.h"
#include "PlayerStateDead.h"
#include "Player/Player.h"
#include "tkEngine/particle/tkParticleEmitter.h"

PlayerStateDead::PlayerStateDead(Player* player) :
	IPlayerState(player)
{

}
PlayerStateDead::~PlayerStateDead()
{

}
void PlayerStateDead::Update()
{
	timer += GameTime().GetFrameDeltaTime();
	if (timer > 1.0f) {
		//�G�~�b�^�[���폜
		for (auto& p : player->particleEmitterList) {
			DeleteGO(p);
		}
		player->particleEmitterList.clear();
	}
}
void PlayerStateDead::Enter()
{
	timer = 0.0f;
	player->EmitBloodParticle();
}
void PlayerStateDead::Leave()
{
	for (auto& p : player->particleEmitterList) {
		DeleteGO(p);
	}
	player->particleEmitterList.clear();
}