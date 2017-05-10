/*!
 *@brief	�^�C�g���V�[���B
 */

#pragma once


#include "tkEngine/Sound/tkSoundSource.h"

class TitleScene : public IGameObject{
public:
	/*!
	 *@brief	�R���X�g���N�^�B
	 */
	TitleScene();
	/*!
	 *@brief	�f�X�g���N�^�B
	 */
	~TitleScene();
	void OnDestroy() override;
	void Update() override;
	bool Start() override;
	void PostRender(CRenderContext& renderContext) override;
private:
	enum EnState{
		enState_Run,			//���s���B
		enState_WaitFadeOut,	//�t�F�[�h�A�E�g�҂��B
	};
	CSoundSource bgmSoundSource;
	CSprite		bg;
	CTexture	bgTex;
	EnState		state = enState_Run;
};