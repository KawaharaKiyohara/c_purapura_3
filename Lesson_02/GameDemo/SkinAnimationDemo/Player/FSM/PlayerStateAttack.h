/*!
 * @brief	�v���C���[�̍U����ԃN���X�B
  */
#pragma once

#include "Player/FSM/IPlayerState.h"

class PlayerStateAttack : public IPlayerState
{
public:
	PlayerStateAttack(Player* player);
	~PlayerStateAttack();
	void Update() override;
	void Enter() override;
	void Leave() override;
	bool IsPossibleLockOn() const override
	{
		return true;
	}
};

