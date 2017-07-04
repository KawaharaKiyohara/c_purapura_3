/*!
 * @brief	���ݎg�p�\�ȃ}�W�b�N�X�L����\��2D
 */

#pragma once

#include "Player/Player.h"

/*!
 * @brief	���ݎg�p�\�ȃ}�W�b�N�X�L����\��2D
 */
class MagicSkill2D : public IGameObject{
public:
	MagicSkill2D();
	~MagicSkill2D();
	bool Start() override;
	void Update() override;
	void PostRender(CRenderContext& renderContext) override;
private:
	CSprite		m_bgSprite;		//!<�w�i�X�v���C�g�B
	CSprite		m_skillSprite;	//!<�X�L����\���X�v���C�g�B
	CTexture*	m_magicSkillTexture[Player::eMagicSkillNum];
};