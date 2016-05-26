// PackmanConsol.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//
#include "global.h"
#include "court.h"
#include "ball.h"
#include "player.h"

TennisCourt tennisCourt;	//テニスコート。
Ball		ball;			//ボール。
Player		player;			//プレイヤー。

//メイン関数。
int main()
{
	//ゲームループ。
	while (true) {
		//フレームの開始。
		BeginFrame();
		
		//更新。
		ball.Update();
		player.Update();
		//描画。
		tennisCourt.Draw();
		player.Draw();
		ball.Draw();

		EndFrame();	//フレームの最後に呼んでね。おまじない。
	}
    return 0;
}

