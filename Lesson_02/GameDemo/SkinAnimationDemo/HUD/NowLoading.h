/*!
 * @brief	NowLoading
 */

#pragma once


class NowLoading : public IGameObject{
public:
	NowLoading();
	~NowLoading();
	bool Start() override;
	void Update() override;
	void PostRender(CRenderContext& renderContext) override;

private:
	CSprite  	m_backGround;			//�w�i�X�v���C�g�B
	CTexture	m_backGroundTex;		//�w�i�e�N�X�`���B
	CSprite		m_icon;					//�A�C�R���X�v���C�g�B
	CTexture	m_iconTex;							//�A�C�R���e�N�X�`���B
	CQuaternion	m_rotation = CQuaternion::Identity;	//�A�C�R���̉�]�B
	float		m_angle = 0.0f;
};