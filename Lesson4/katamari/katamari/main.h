#pragma once

#include "Ouji.h"
#include "Ground.h"
#include "Core.h"
#include "MonoManager.h"

class GameCamera;
/*!
* @brief	ゲームクラス
*/
class Game : public IGameObject {
public:
	//コンストラクタ。
	Game();
	//デストラクタ。
	~Game();
	//Updateが呼ばれる前に一度だけ呼ばれる処理。
	void Start();
	//描画。
	void Render( CRenderContext& renderContext );
	//更新。
	void Update();
	//ゲームカメラの取得。
	GameCamera* GetGameCamera()
	{
		return gameCamera;
	}
	//モノマネージャーを取得。
	MonoManager* GetMonoManager()
	{
		return &monoManager;
	}
private:
	GameCamera* gameCamera;		//ゲームカメラ。
	Ouji		ouji;			//王子。
	Ground		ground;			//地面
	Core		core;			//コア
	MonoManager monoManager;	//モノマネージャ
	CRandom     random;			//ランダム。
};
extern Game* game;