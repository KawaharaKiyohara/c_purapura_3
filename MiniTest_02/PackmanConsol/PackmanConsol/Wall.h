#pragma once
class Wall
{
private:
	int	m_posX;		//!<x座標。
	int m_posY;		//!<y座標
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

