#include "stdafx.h"
#include "Player.h"


Player g_player;

Player::Player()
{
}


Player::~Player()
{
}
/*!
*@brief	プレイヤーの描画処理。
*/
void Player::Draw()
{
	//フレームバッファにドロー。
	sFrameBuffer[m_pos.GetY()][m_pos.GetX()] = 'P';
}
/*!
*@brief	更新処理。
*/
void Player::Update()
{
	int posY = m_pos.GetY();
	int posX = m_pos.GetX();
	if (GetAsyncKeyState(VK_UP) & 0x8000) {
		posY--;
		if (posY < 0) {
			posY = 0;
		}
	}
	else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
		posX--;
		if (posX < 0) {
			posX = 0;
		}
	}
	else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
		posY++;
		if (posY > MAP_HEIGHT - 1) {
			posY = MAP_HEIGHT - 1;
		}
	}
	else if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		posX++;
		if (posX > MAP_WIDTH - 1) {
			posX = MAP_WIDTH - 1;
		}
	}
	m_pos.SetX(posX);
	m_pos.SetY(posY);
}
/*!
*@brief	X座標を取得。
*/
int Player::GetPositionX()
{
	return m_pos.GetX();
}
/*!
*@brief	Y座標を取得。
*/
int Player::GetPositionY()
{
	return m_pos.GetY();
}
/*!
*@brief	座標を設定。
*@param	x		x座標。
*@param	y		y座標。
*/
void Player::SetPosition(int x, int y)
{
	m_pos.SetX(x);
	m_pos.SetY(y);
}
