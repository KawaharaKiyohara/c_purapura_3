#include "stdafx.h"
#include "Wall.h"

/*!
*@brief	コンストラクタ。
*/
Wall::Wall()
{
}
/*!
*@brief	壁の描画処理。
*/
void Wall::Draw()
{
	//フレームバッファにドロー。
	sFrameBuffer[m_pos.GetY()][m_pos.GetX()] = 'W';
}
/*!
*@brief	座標を設定。
*/
void Wall::SetPosition(int x, int y)
{
	m_pos.SetX(x);
	m_pos.SetY(y);
}