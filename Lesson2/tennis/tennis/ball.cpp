#include "global.h"
#include "ball.h"
#include "court.h"
#include "player.h"

static char ballText[1][1] = {
	{ '@' }
};
Ball::Ball()
{
	//初期化。
	velocity.x = 1;
	velocity.y = 1;
	position.x = 4;
	position.y = 4;
}
Ball::~Ball()
{
}
void Ball::Draw()
{
	DrawFrameBuffer(ballText, position.x, position.y, 1, 1);
}
void Ball::Update()
{
	//座標を移動させる。
	position.x += velocity.x;
	position.y += velocity.y;
	//壁とボールの衝突判定。
	int ret = tennisCourt.IsHitWall(position);
	if (ret == 1 && velocity.y < 0) {
		//上の壁と衝突している。
		velocity.y = 1;
	}
	else if (ret == 2 && velocity.y > 0 ) {
		//下の壁と衝突している。
		velocity.y = -1;
	}
	else if (ret == 3 && velocity.x < 0) {
		//左の壁と衝突している。
		velocity.x = 1;
	}
	else if (ret == 4 && velocity.x > 0) {
		//右の壁と衝突している。
		//速度をY方向に反転。
		velocity.x = -1;
	}
	//プレイヤーとのあたり判定
	if (player.IsHit(position) && velocity.x < 0) {
		velocity.x = 1;
	}
}
