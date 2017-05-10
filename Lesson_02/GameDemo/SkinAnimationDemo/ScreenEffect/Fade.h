/*!
 *@brief	��ʂ̃t�F�[�h�A�E�g/�C��
 */

#pragma once

class Fade : public IGameObject{
public:
	Fade();
	~Fade();
	/*!
	 *@brief	�J�n�֐��B
	 *@details
	 * �������Ȃǂ����̊֐��Ɏ������Ă��������B</br>
	 * ���̊֐���true��Ԃ��Ɩ{�ِ��͈ȍ~�̃t���[���ł͌Ă΂�Ȃ��Ȃ�܂��B</br>
	 * �����ăQ�[���I�u�W�F�N�g�̏�Ԃ������������ɂȂ�Update�֐����Ă΂��悤�ɂȂ�܂��B</br>
	 *@return	true���A���Ă����珉���������B
	 */
	bool Start() override;
	/*!
	 *@brief	�X�V�֐��B
	 */
	void Update() override;
	/*!
	*@brief	�x���`��֐��B
	@details
	* �|�X�g�G�t�F�N�g�̌�Ŏ��s����܂��BHUD�Ȃǃ|�X�g�G�t�F�N�g�̉e�����󂯂����Ȃ��`�敨�͂����Ń����_�����O���Ă��������B
	*@param[in]		renderContext		�����_�����O�R���e�L�X�g�B
	*/
	void PostRender( CRenderContext& renderContext ) override;
	/*!
	*@brief	�t�F�[�h�̏��������s���H�B
	*@return �t�F�[�h�C���A�t�F�[�h�A�E�g�����s����true��Ԃ��܂��B
	*/
	bool IsExecute() const
	{
		return m_isExecute;
	}
	/*!
	*@brief	�t�F�[�h�A�E�g���J�n�B
	*/
	void StartFadeOut()
	{
		float alpha = m_sprite.GetAlpha();
		if (alpha < 1.0f) {
			m_timer = 0.0f;
			SetActiveFlag(true);
			m_isExecute = true;
			m_state = eFadeOut;
		}
	}
	/*!
	*@brief	�t�F�[�h�C�����J�n�B
	*/
	void StartFadeIn()
	{
		float alpha = m_sprite.GetAlpha();
		if (alpha > 0.0f) {
			m_timer = 0.0f;
			SetActiveFlag(true);
			m_isExecute = true;
			m_state = eFadeIn;
		}
	}
private:
	//��ԁB
	enum EnState {
		eFadeOut,		//!<�t�F�[�h�A�E�g�B
		eFadeIn,		//!<�t�F�[�h�C���B
	};
	const float FADE_TIME = 0.3f;		//!<�t�F�[�h�A�E�g�̎��ԁB(�P�ʁF�b)
	CSprite		m_sprite;				//!�u���b�N�A�E�g�p�̃X�v���C�g�B
	CTexture	m_texture;				//!<�u���b�N�A�E�g�p�̃e�N�X�`���B
	EnState		m_state = eFadeIn;		//!<��ԁB
	bool		m_isExecute = false;	//!<�t�F�[�h�����s���H
	float		m_timer = 1.0f;			//!<�^�C�}(�P�ʁF�b)
};