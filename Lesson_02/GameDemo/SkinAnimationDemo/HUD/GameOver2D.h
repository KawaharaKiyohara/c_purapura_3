/*!
 * @brief	�Q�[���I�[�o�[�B
 */

#pragma once

class GameOver2D : public IGameObject{
public:
	GameOver2D();
	~GameOver2D();
	bool Start() override;
	void Update() override;
	void PostRender(CRenderContext& renderContext) override;
private:
	enum State {
		State_WaitFadeIn,
		State_FadeIn,
	};
	CSprite  	m_youDeadSprite;	//you dead �X�v���C�g�B
	CTexture	m_youDeadTex;		//you dead �e�N�X�`���B
	State		m_state = State_WaitFadeIn;
	float		m_timer = 0.0f;			//�^�C�}�B
};