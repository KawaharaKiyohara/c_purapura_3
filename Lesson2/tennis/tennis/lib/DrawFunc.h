//�`��֌W
#pragma once

//�}�b�v�̕��B
const int MAP_WIDTH = 64;
 //�}�b�v�̍����B
const int MAP_HEIGHT = 16;

//�t���[���o�b�t�@�E�E�E�̂悤�Ȃ��́B
extern char frameBuffer[MAP_HEIGHT][MAP_WIDTH];

extern void BeginFrame();

extern void EndFrame();

//�t���[���o�b�t�@�ɕ`��B
extern void DrawFrameBuffer(
	const void* text,
	const int POS_X,
	const int POS_Y,
	const int W,
	const int H
);

//�R���\�[���E�B���h�E�̏������B
extern void InitConsoleWindow( int W, int H );
