// PackmanConsol.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include "Player.h"



//マップの定義。1は壁。0は餌。
static int sMap[MAP_HEIGHT][MAP_WIDTH] = {
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1 },
	{ 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1 },
	{ 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1 },
	{ 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1 },
	{ 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1 },
	{ 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1 },
	{ 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
};

//フレームバッファ・・・のようなもの。
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
*@brief	食べ物クラス。
*/
class CFood {
private:
	int m_posX;		//!<x座標。
	int m_posY;		//!<y座標
	bool m_isDead;	//!<死亡フラグ。
public:
	/*!
	*@brief	コンストラクタ。
	*/
	CFood() :
		m_isDead(false)
	{
		m_posX = 0;
		m_posY = 0;
	}
	/*!
	*@brief	壁の描画処理。
	*/
	void Draw()
	{
		if (!m_isDead) {
			//フレームバッファにドロー。
			sFrameBuffer[m_posY][m_posX] = '.';
		}
	}
	/*!
	*@brief	座標を設定。
	*/
	void SetPosition(int x, int y)
	{
		m_posX = x;
		m_posY = y;
	}
	/*!
	*@brief	更新処理。
	*/
	void Update()
	{
	}
};
/*!
*@brief	壁クラス。
*/
class CWall {
private:
	int	m_posX;		//!<x座標。
	int m_posY;		//!<y座標
public:
	/*!
	*@brief	コンストラクタ。
	*/
	CWall()
	{
		m_posX = 0;
		m_posY = 0;
	}
	/*!
	*@brief	壁の描画処理。
	*/
	void Draw()
	{
		//フレームバッファにドロー。
		sFrameBuffer[m_posY][m_posX] = 'W';
	}
	/*!
	*@brief	座標を設定。
	*/
	void SetPosition(int x, int y)
	{
		m_posX = x;
		m_posY = y;
	}
};

/*!
 *@brief	メイン関数。
 */
int main()
{
	//プレイヤーの初期位置を決定。
	playerPosX = 7;
	playerPosY = 7;
	//壁
	int numWall = 0;	//壁の数。
	CWall walls[MAP_HEIGHT*MAP_WIDTH];
	//食べ物
	int numFood = 0;
	CFood foods[MAP_HEIGHT*MAP_WIDTH];
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
		PlayerUpdate();
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
		PlayerDraw();
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

