#include "stdafx.h"
#include "Player.h"


Player g_player;

Player::Player()
{
	//初期化を行う。
	m_posX = 0;
	m_posY = 0;
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
	sFrameBuffer[m_posY][m_posX] = 'P';
}
/*!
*@brief	更新処理。
*/
void Player::Update()
{
	if (GetAsyncKeyState(VK_UP) & 0x8000) {
		m_posY--;
		if (m_posY < 0) {
			m_posY = 0;
		}
	}
	else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
		m_posX--;
		if (m_posX < 0) {
			m_posX = 0;
		}
	}
	else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
		m_posY++;
		if (m_posY > MAP_HEIGHT - 1) {
			m_posY = MAP_HEIGHT - 1;
		}
	}
	else if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		m_posX++;
		if (m_posX > MAP_WIDTH - 1) {
			m_posX = MAP_WIDTH - 1;
		}
	}
}
/*!
*@brief	X座標を取得。
*/
int Player::GetPositionX()
{
	return m_posX;
}
/*!
*@brief	Y座標を取得。
*/
int Player::GetPositionY()
{
	return m_posY;
}
/*!
*@brief	座標を設定。
*@param	x		x座標。
*@param	y		y座標。
*/
void Player::SetPosition(int x, int y)
{
	m_posX = x;
	m_posY = y;
}
