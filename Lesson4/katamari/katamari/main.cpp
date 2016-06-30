#include "stdafx.h"
#include "lib/system.h"
#include "main.h"
#include "GameCamera.h"
#include "Mono_Static.h"
#include <time.h>

Game* game = NULL;

#define MAX_MONO  500

//コンストラクタ。
Game::Game()
{
	gameCamera = NULL;
}
//デストラクタ。
Game::~Game()
{
	delete gameCamera;
}
//Updateが呼ばれる前に一度だけ呼ばれる処理。
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

	//モノをランダムに生成して配置していく。
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
//描画。
void Game::Render(CRenderContext& renderContext)
{
	ouji.Render(renderContext);
	ground.Render(renderContext);
	core.Render(renderContext);
	monoManager.Render(renderContext);
	
}
//更新。
void Game::Update()
{
	ouji.Update();
	gameCamera->Update();
	core.Update();
	monoManager.Update();
}
