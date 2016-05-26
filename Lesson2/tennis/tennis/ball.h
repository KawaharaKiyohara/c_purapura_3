/*!
 *@brief	テニスボール。
 */
#pragma once

class Ball
{
public:
	//コンストラクタ。
	Ball();
	//デストラクタ。
	~Ball();
	//描画。
	void Draw();
	//更新。
	void Update();
private:
	Vector2	position;		//ボールの座標。
	Vector2	velocity;		//ボールの速度。
};