// PackmanConsol.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//
#include "global.h"
#include "court.h"
#include "ball.h"
#include "player.h"

TennisCourt tennisCourt;	//�e�j�X�R�[�g�B
Ball		ball;			//�{�[���B
Player		player;			//�v���C���[�B

//���C���֐��B
int main()
{
	//�Q�[�����[�v�B
	while (true) {
		//�t���[���̊J�n�B
		BeginFrame();
		
		//�X�V�B
		ball.Update();
		player.Update();
		//�`��B
		tennisCourt.Draw();
		player.Draw();
		ball.Draw();

		EndFrame();	//�t���[���̍Ō�ɌĂ�łˁB���܂��Ȃ��B
	}
    return 0;
}

