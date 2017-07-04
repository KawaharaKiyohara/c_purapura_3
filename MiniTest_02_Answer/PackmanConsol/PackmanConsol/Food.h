#pragma once
#include "Vector2.h"

/*!
*@brief	食べ物クラス。
*/
class Food {
private:
	Vector2 m_pos;
	bool m_isDead;	//!<死亡フラグ。
public:
	/*!
	*@brief	コンストラクタ。
	*/
	Food();
	/*!
	*@brief	デストラクタ。
	*/
	~Food();
	/*!
	*@brief	壁の描画処理。
	*/
	void Draw();
	/*!
	*@brief	座標を設定。
	*/
	void SetPosition(int x, int y);
	/*!
	*@brief	更新処理。
	*/
	void Update();
};
