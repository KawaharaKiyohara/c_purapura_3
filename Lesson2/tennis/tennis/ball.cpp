#include "global.h"
#include "ball.h"
#include "court.h"
#include "player.h"

static char ballText[1][1] = {
	{ '@' }
};
Ball::Ball()
{
	//�������B
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
	//���W���ړ�������B
	position.x += velocity.x;
	position.y += velocity.y;
	//�ǂƃ{�[���̏Փ˔���B
	int ret = tennisCourt.IsHitWall(position);
	if (ret == 1 && velocity.y < 0) {
		//��̕ǂƏՓ˂��Ă���B
		velocity.y = 1;
	}
	else if (ret == 2 && velocity.y > 0 ) {
		//���̕ǂƏՓ˂��Ă���B
		velocity.y = -1;
	}
	else if (ret == 3 && velocity.x < 0) {
		//���̕ǂƏՓ˂��Ă���B
		velocity.x = 1;
	}
	else if (ret == 4 && velocity.x > 0) {
		//�E�̕ǂƏՓ˂��Ă���B
		//���x��Y�����ɔ��]�B
		velocity.x = -1;
	}
	//�v���C���[�Ƃ̂����蔻��
	if (player.IsHit(position) && velocity.x < 0) {
		velocity.x = 1;
	}
}
