//プレイヤークラス。
#pragma once

class Player{
public:
	//コンストラクタ。
	Player();
	//デストラクタ。
	~Player();
	//更新。
	void Update();
	//描画。
	void Draw();
	//衝突した？
	bool IsHit(Vector2 pos);
private:
	Vector2		position;	//座標。
};

extern Player	player;			//プレイヤー。