//描画関係
#pragma once

//マップの幅。
const int MAP_WIDTH = 64;
 //マップの高さ。
const int MAP_HEIGHT = 16;

//フレームバッファ・・・のようなもの。
extern char frameBuffer[MAP_HEIGHT][MAP_WIDTH];

extern void BeginFrame();

extern void EndFrame();

//フレームバッファに描画。
extern void DrawFrameBuffer(
	const void* text,
	const int POS_X,
	const int POS_Y,
	const int W,
	const int H
);

//コンソールウィンドウの初期化。
extern void InitConsoleWindow( int W, int H );
