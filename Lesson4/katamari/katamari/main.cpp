#include "stdafx.h"
#include "lib/system.h"
#include "main.h"
#include "GameCamera.h"
#include "Mono_Static.h"
#include <time.h>

Game* game = NULL;

#define MAX_MONO  500

//�R���X�g���N�^�B
Game::Game()
{
	gameCamera = NULL;
}
//�f�X�g���N�^�B
Game::~Game()
{
	delete gameCamera;
}
//Update���Ă΂��O�Ɉ�x�����Ă΂�鏈���B
void Game::Start()
{
	random.Init((unsigned)time(NULL));
	gameCamera = new GameCamera;
	ouji.Init();
	ground.Init();
	core.Init();
	core.SetOuji(&ouji);
	ouji.SetCore(&core);
	gameCamera->SetOuji(&ouji);

	//���m�������_���ɐ������Ĕz�u���Ă����B
	for (int i = 0; i < MAX_MONO; i++) {
		Mono_Static* mono = new Mono_Static;
		CVector3 pos;
		float xSeed = (random.GetRandDouble() - 0.5f)* 2.0f;
		float zSeed = (random.GetRandDouble() - 0.5f)* 2.0f;
		pos.Set(xSeed * 30.0f, 0.5f, zSeed * 30.0f);
		mono->Init( pos, CQuaternion::Identity );
		monoManager.AddMono(mono);
	}
}
//�`��B
void Game::Render(CRenderContext& renderContext)
{
	ouji.Render(renderContext);
	ground.Render(renderContext);
	core.Render(renderContext);
	monoManager.Render(renderContext);
	
}
//�X�V�B
void Game::Update()
{
	ouji.Update();
	gameCamera->Update();
	core.Update();
	monoManager.Update();
}
