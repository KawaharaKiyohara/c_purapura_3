#include "stdafx.h"
#include "Wall.h"

/*!
*@brief	コンストラクタ。
*/
Wall::Wall()
{
	m_posX = 0;
	m_posY = 0;
}
/*!
*@brief	壁の描画処理。
*/
void Wall::Draw()
{
	//フレームバッファにドロー。
	sFrameBuffer[m_posY][m_posX] = 'W';
}
/*!
*@brief	座標を設定。
*/
void Wall::SetPosition(int x, int y)
{
	m_posX = x;
	m_posY = y;
}