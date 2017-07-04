/*!
 *@brief	�Q�[���V�[���B
 */

#pragma once

#include "tkEngine/Sound/tkSoundSource.h"
#include "Light/InGameLight.h"

class Map;
class Ground;
class PlayerHPBar;
class PlayerMPBar;

class UnityChanInstance;
class GameOver2D;
class MagicSkill2D;

class GameScene : public IGameObject{
public:
	//�Q�[���I�u�W�F�N�g�̃^�O�B
	enum EnGameObjectTags {
		enGameObjectTags_BGM = 1,				//!<BGM
		enGameObjectTags_EnemySound = 1 << 1,	//!<�G�l�~�[�T�E���h�B
	};
	/*!
	 *@brief	�R���X�g���N�^�B
	 */
	GameScene();
	/*!
	 *@brief	�f�X�g���N�^�B
	 */
	~GameScene();
	void OnDestroy() override;
	bool Start() override;
	void Update() override;
	
	//�f�t�H���g���C�g�̎擾�B
	CLight& GetDefaultLight()
	{
		return inGameLight.GetDefaultLight();
	}
	CSkinModelData* GetItemModelData()
	{
		if (itemModelData.IsLoadEnd())
		{
			return itemModelData.GetBody();
		}
		else
		{
			return nullptr;
		}
	}
private:
	enum InitStep {
		InitStep_Load,
		InitStep_WaitLoad,
	};
	enum State {
		State_Play,	//�Q�[���v���C���B
		State_Over,	//�Q�[���I�[�o�[�B
		State_WaitFadeOut,	//�t�F�[�h�A�E�g�҂��B
	};
	Map*				map = NULL;
	Ground*				ground = NULL;
	PlayerHPBar*		playerHPBar = NULL;
	PlayerMPBar*		playerMPBar = NULL;
	UnityChanInstance*	unityChanInstance = NULL;
	CSoundSource		bgmSoundSource;
	InitStep			initStep = InitStep_Load;
	State				state = State_Play;
	float				gameOverTimer = 0.0f;
	GameOver2D*			gameOver2D = NULL;
	MagicSkill2D*		magicSkill2D = NULL;
	InGameLight			inGameLight;		//�C���Q�[�����C�g�B
	CSkinModelDataHandle itemModelData;
};

extern GameScene* gameScene;