#pragma once

//ゲームカメラクラス。
class GameCamera {
public:
	GameCamera();
	~GameCamera();
	void Update();
	//ビュー行列の取得。
	CMatrix GetViewMatrix();
	//プロジェクション行列の取得。
	CMatrix GetProjectionMatrix();
	//王子を設定。
	void SetOuji(Ouji* ouji)
	{
		this->ouji = ouji;
	}
private:
	/////////////////////////////////////////
	//ここからメンバ変数。
	/////////////////////////////////////////
	CCamera  camera;		//カメラ。
	Ouji* ouji;				//王子
};


