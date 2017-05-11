#include "stdafx.h"
#include "Food.h"
#include "Player.h"

Food::Food() :
	m_isDead(false)
{
	m_posX = 0;
	m_posY = 0;
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
		sFrameBuffer[m_posY][m_posX] = '.';
	}
}
/*!
*@brief	座標を設定。
*/
void Food::SetPosition(int x, int y)
{
	m_posX = x;
	m_posY = y;
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

}