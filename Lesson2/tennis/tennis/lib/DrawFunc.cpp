//�`��֌W�B

#include "global.h"
#include "DrawFunc.h"

//�t���[���o�b�t�@�E�E�E�̂悤�Ȃ��́B
char frameBuffer[MAP_HEIGHT][MAP_WIDTH];

void EndFrame()
{
	//�t���[���o�b�t�@�̓��e����ʂɕ\������B
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			std::cout << frameBuffer[i][j];
		}
		std::cout << "\n";
	}
	Sleep(100);	//100�~���b����B
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = 0;
	pos.Y = 0;

	SetConsoleCursorPosition(hCons, pos);
}

//�t���[���o�b�t�@�ɕ`��B
void DrawFrameBuffer(
	const void *text,
	const int POS_X,
	const int POS_Y,
	const int W,
	const int H
	)
{
	char* _text = (char*)text;
	for (int h = 0; h < H; h++) {
		char* p = &_text[h*W];
		for (int w = 0; w < W; w++) {
			if(POS_Y + h < MAP_HEIGHT && POS_X + w < MAP_WIDTH){
				frameBuffer[POS_Y + h][POS_X + w] = p[w];
			}
		}
	}
}
//�R���\�[���E�B���h�E�̏������B
void InitConsoleWindow( int W, int H )
{
	SMALL_RECT rect;
	rect.Top = 0;
	rect.Left = 0;
	rect.Right = W;
	rect.Bottom = H;
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleWindowInfo( hCons, TRUE, &rect );
}
extern void BeginFrame()
{
	memset(frameBuffer, 0, sizeof(frameBuffer));
}