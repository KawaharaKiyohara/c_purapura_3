#pragma once

#include "Ouji.h"
#include "Ground.h"
#include "Core.h"
#include "MonoManager.h"

class GameCamera;
/*!
* @brief	�Q�[���N���X
*/
class Game : public IGameObject {
public:
	//�R���X�g���N�^�B
	Game();
	//�f�X�g���N�^�B
	~Game();
	//Update���Ă΂��O�Ɉ�x�����Ă΂�鏈���B
	void Start();
	//�`��B
	void Render( CRenderContext& renderContext );
	//�X�V�B
	void Update();
	//�Q�[���J�����̎擾�B
	GameCamera* GetGameCamera()
	{
		return gameCamera;
	}
	//���m�}�l�[�W���[���擾�B
	MonoManager* GetMonoManager()
	{
		return &monoManager;
	}
private:
	GameCamera* gameCamera;		//�Q�[���J�����B
	Ouji		ouji;			//���q�B
	Ground		ground;			//�n��
	Core		core;			//�R�A
	MonoManager monoManager;	//���m�}�l�[�W��
	CRandom     random;			//�����_���B
};
extern Game* game;