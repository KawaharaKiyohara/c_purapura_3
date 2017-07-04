/*!
 * @brief	�v���C���[�̃X�e�[�g�N���X�B
 */

#pragma once

class Player;
/*!
 * @brief	�v���C���[�̃X�e�[�g�N���X�B
 */
class IPlayerState{
public:
	IPlayerState( Player* player )
	{
		this->player = player;
	}
	virtual ~ IPlayerState()
	{
	}
	virtual void Update() = 0;
	virtual void Enter() = 0;
	virtual void Leave() = 0;
	//�_���[�W���󂯂邱�Ƃ��o���邩����B
	virtual bool IsPossibleDamage() const
	{
		return true;
	}
	//���b�N�I�����\�H
	virtual bool IsPossibleLockOn() const
	{
		return false;
	}
protected:
	Player* player;		//�v���C���[�B
};
