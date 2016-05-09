#include "stdafx.h"
#include "PathFinding.h"

CPathFinding::CPathFinding()
{

}
CPathFinding::~CPathFinding()
{

}
void CPathFinding::FindRoot(SNode* root, CVector2 startPos, CVector2 targetPos )
{
	//開始ノードを取得する。
	SNode* startNode = &m_nodes[startPos.GetY()][startPos.GetY()];
	startNode->moveCost = 0;
	//コストを-1で初期化
	for (int y = 0; y < MAP_HEIGHT; y++) {
		for (int x = 0; x < MAP_WIDTH; x++) {
			m_nodes[y][x].moveCost = -1;
		}
	}
	while (true) {
		SNode* processNode = NULL;
		//全ノードに対して確認/アップデートを行う。
		for (int y = 0; y < MAP_HEIGHT; y++) {
			for (int x = 0; x < MAP_WIDTH; x++) {
				if(m_nodes[y][x].moveCost)
			}
		}
	}

}
void CPathFinding::BuildNodes()
{
	//ノードを構築する。
	for (int y = 0; y < MAP_HEIGHT; y++) {
		for (int x = 0; x < MAP_WIDTH; x++) {
			SNode* node = &m_nodes[y][x];
			//マップのＩＤを入れる
			node->mapID = g_map[y][x];
			//隣接マップをNULL初期化。
			node->linkNode[0] = NULL;
			node->linkNode[1] = NULL;
			node->linkNode[2] = NULL;
			node->linkNode[3] = NULL;
			node->moveCost = 0;
			//隣接マップのノードを入れる。
			//右のノード
			if (x + 1 < MAP_WIDTH) {
				node->linkNode[0] = &m_nodes[y][x+1];
			}
			//左のノード
			if (x - 1 >= 0) {
				node->linkNode[1] = &m_nodes[y][x-1];
			}
			//上のノード
			if (y + 1 < MAP_HEIGHT) {
				node->linkNode[2] = &m_nodes[y+1][x];
			}
			//下のノード
			if (y - 1 >= 0) {
				node->linkNode[3] = &m_nodes[y-1][x];
			}
			node->position.Set(x, y);
		}
	}
}