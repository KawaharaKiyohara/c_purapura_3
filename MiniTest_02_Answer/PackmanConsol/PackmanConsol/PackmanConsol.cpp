// PackmanConsol.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include "Player.h"
#include "Food.h"
#include "Wall.h"

char sFrameBuffer[MAP_HEIGHT][MAP_WIDTH];

void EndFrame()
{
	Sleep(100);	//100ミリ秒眠る。
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = 0;
	pos.Y = 0;

	SetConsoleCursorPosition(hCons, pos);
}



/*!
 *@brief	メイン関数。
 */
int main()
{
	//プレイヤーの初期位置を決定。
	g_player.SetPosition(7, 7);
	//壁
	int numWall = 0;	//壁の数。
	Wall walls[MAP_HEIGHT*MAP_WIDTH];
	//食べ物
	int numFood = 0;
	Food foods[MAP_HEIGHT*MAP_WIDTH];
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			if (sMap[i][j] == 1) {
				//壁。
				walls[numWall].SetPosition(j, i);
				//壁を一つ作ったのでカウントアップ。
				numWall++;
			}
			else if (sMap[i][j] == 0) {
				//食べ物
				foods[numFood].SetPosition(j, i);
				//食べ物を一つ作ったのでカウントアップ。
				numFood++;
			}
		}
	}
	//ゲームループ。
	while (true) {
		//フレームバッファをクリア。
		memset(sFrameBuffer, 0, sizeof(sFrameBuffer));
		//プレイヤーの移動処理。
		g_player.Update();
		//食べ物の更新処理。
		for (int i = 0; i < numFood; i++) {
			foods[i].Update();
		}
		//食べ物の描画処理。
		for (int i = 0; i < numFood; i++) {
			foods[i].Draw();
		}
		//壁の描画処理。
		for (int i = 0; i < numWall; i++) {
			walls[i].Draw();
		}
		//プレーヤーの描画処理。
		g_player.Draw();
		//フレームバッファの内容を画面に表示する。
		for (int i = 0; i < MAP_HEIGHT; i++) {
			for (int j = 0; j < MAP_WIDTH; j++) {
				std::cout << sFrameBuffer[i][j];
			}
			std::cout << "\n";
		}
		EndFrame();	//フレームの最後に呼んでね。おまじない。
	}
    return 0;
}

