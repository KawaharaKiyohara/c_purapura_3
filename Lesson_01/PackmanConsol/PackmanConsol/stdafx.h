// stdafx.h : 標準のシステム インクルード ファイルのインクルード ファイル、または
// 参照回数が多く、かつあまり変更されない、プロジェクト専用のインクルード ファイル
// を記述します。
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

//マップの高さ。
const int MAP_HEIGHT = 15;
//マップの幅。
const int MAP_WIDTH = 15;

extern char sFrameBuffer[MAP_HEIGHT][MAP_WIDTH];

// TODO: プログラムに必要な追加ヘッダーをここで参照してください
