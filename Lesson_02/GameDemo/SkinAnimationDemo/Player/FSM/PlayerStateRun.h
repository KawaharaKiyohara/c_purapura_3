/*!
 * @brief	�v���C���[�̑����ԃN���X�B
 */
#pragma once

#include "Player/FSM/IPlayerState.h"

class PlayerStateRun : public IPlayerState
{
public:
	PlayerStateRun(Player* player);
	~PlayerStateRun();
	void Update() override;
	void Enter() override;
	void Leave() override;
	bool IsPossibleLockOn() const override
	{
		return true;
	}
private:
	CCamera* cam = nullptr;
};

