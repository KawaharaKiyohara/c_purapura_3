#pragma once
#include "Vector2.h"
class Wall
{
private:
	Vector2 m_pos;
public:
	/*!
	*@brief	コンストラクタ。
	*/
	Wall();
	/*!
	*@brief	壁の描画処理。
	*/
	void Draw();
	/*!
	*@brief	座標を設定。
	*/
	void SetPosition(int x, int y);
};

