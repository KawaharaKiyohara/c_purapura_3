/*!
 * @brief	�v���C���[�̑ҋ@��ԃN���X�B
 */
 
#pragma once

#include "Player/FSM/IPlayerState.h"

class PlayerStateStand : public IPlayerState
{
public:
	PlayerStateStand(Player* player);
	~PlayerStateStand();
	void Update() override;
	void Enter() override;
	void Leave() override;
	bool IsPossibleLockOn() const override
	{
		return true;
	}
};

