#include "stdafx.h"
#include "Player.h"


Player g_player;

Player::Player()
{
	//ここでm_posのコンストラクタが
	//呼ばれているので初期化不要

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
	if (GetAsyncKeyState(VK_UP) & 0x8000) {
		int posY = m_pos.GetY();
		posY--;
		m_pos.SetY(posY);
		if (m_pos.GetY() < 0) {
			m_pos.SetY(0);
		}
	}
	else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
		int posX = m_pos.GetX();
		posX--;
		m_pos.SetX(posX);
		if (m_pos.GetX() < 0) {
			m_pos.SetX(0);
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
			m_pos.SetX(MAP_WIDTH - 1);
		}
	}
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
