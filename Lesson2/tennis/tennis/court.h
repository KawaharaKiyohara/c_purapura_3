//テニスコートのヘッダーファイル。
#pragma once

class TennisCourt{
public:
	//コンストラクタ。
	TennisCourt();
	//デストラクタ。
	~TennisCourt();
	//描画。
	void Draw();
	//壁との衝突判定。
	//0が返ってきたら衝突していない。
	//1が返ってきたら上の壁と衝突している。
	//2が返ってきたら下の壁と衝突している。
	//3が返ってきたら左の壁と衝突している。
	//4が返ってきたら右の壁と衝突している。
	int IsHitWall(Vector2 pos);
private:
	Vector2  position;	//座標
};

extern TennisCourt tennisCourt;	//テニスコート。