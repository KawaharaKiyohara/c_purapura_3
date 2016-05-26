#include "global.h"
#include "player.h"
#include "court.h"

const int PLAYER_W = 1;
const int PLAYER_H = 4;
static char playerText[PLAYER_H][PLAYER_W] = {
	{ ']' },
	{ '|' },
	{ '|' },
	{ ']' }
};

Player::Player()
{
	position.x = 4;
	position.y = 6;
}
Player::~Player()
{
}
void Player::Update()
{
	Vector2 positionBack = position;
	if (GetAsyncKeyState(VK_UP)) {
		position.y--;
	}
	else if (GetAsyncKeyState(VK_DOWN)) {
		position.y++;
	}
	if (tennisCourt.IsHitWall(position) == 1) {
		//上の壁に衝突している。
		position = positionBack;
	}
	Vector2 bottomPosition = position;
	bottomPosition.y += PLAYER_H - 1;
	if (tennisCourt.IsHitWall(bottomPosition) == 2) {
		//下の壁に衝突している。
		position = positionBack;
	}
}
bool Player::IsHit(Vector2 pos)
{
	if (position.x == pos.x
		&& position.y <= pos.y
		&& position.y + PLAYER_H - 1 >= pos.y)
	{
		//当たってる。
		return true;
	}
	//当たってない。
	return false;
}
void Player::Draw()
{
	DrawFrameBuffer(playerText, position.x, position.y, PLAYER_W, PLAYER_H);
}
