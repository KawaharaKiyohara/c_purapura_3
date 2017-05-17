#include "stdafx.h"
#include "Food.h"
#include "Player.h"

Food::Food() :
	m_isDead(false)
{
}


Food::~Food()
{
}	
/*!
*@brief	壁の描画処理。
*/
void Food::Draw()
{
	if (!m_isDead) {
		//フレームバッファにドロー。
		sFrameBuffer[m_pos.GetY()][m_pos.GetX()] = '.';
	}
}
/*!
*@brief	座標を設定。
*/
void Food::SetPosition(int x, int y)
{
	m_pos.SetX(x);
	m_pos.SetY(y);
}
/*!
*@brief	更新処理。
*/
void Food::Update()
{
	//プレイヤーと触れたら食べ物が消えるようにしてみよう・・・
	//プレイヤーはg_playerでアクセスできる。
	//プレイヤーとCFoodの座標が同じになった時に、消えるようにすればいいはず。
	//プレイヤーの座標はg_player.GetPositionX()とg_player.GetPositionY()で取得できる。
	//例えばプレイヤーのX座標が欲しいならこんな感じ。
	//int pos_x = g_player.GetPositionX();
	if (m_pos.GetX() == g_player.GetPositionX()
		&& m_pos.GetY() == g_player.GetPositionY()
		) {
		m_isDead = true;
	}

}