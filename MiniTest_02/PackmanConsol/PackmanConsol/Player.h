#pragma once
class Player {
	;
private:
	int m_posX;			//!<x座標。
	int m_posY;			//!<y座標。
public:
	/*!
	*@brief	コンストラクタ。
	*/
	Player();
	/*!
	*@brief	デストラクタ。
	*/
	~Player();
	/*!
	*@brief	プレイヤーの描画処理。
	*/
	void Draw();
	/*!
	*@brief	更新処理。
	*/
	void Update();
	/*!
	*@brief	X座標を取得。
	*/
	int GetPositionX();
	/*!
	*@brief	Y座標を取得。
	*/
	int GetPositionY();
	/*!
	*@brief	座標を設定。
	*@param	x		x座標。
	*@param	y		y座標。
	*/
	void SetPosition(int x, int y);
};

extern Player g_player;