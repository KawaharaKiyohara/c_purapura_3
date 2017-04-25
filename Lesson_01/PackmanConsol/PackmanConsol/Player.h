/*!
 * @brief	プレイヤーの処理(C言語版)
 */

#pragma once

//#define PLAYER_CPP

#ifndef PLAYER_CPP

extern int playerPosX;		//プレイヤーのX座標。
extern int playerPosY;		//プレイヤーのY座標。
extern void PlayerInit();
extern void PlayerUpdate();
extern void PlayerDraw();

#endif #ifndef PLAYER_CPP