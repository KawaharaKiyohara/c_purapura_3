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
	//�J�n�m�[�h���擾����B
	SNode* startNode = &m_nodes[startPos.GetY()][startPos.GetY()];
	startNode->moveCost = 0;
	//�R�X�g��-1�ŏ�����
	for (int y = 0; y < MAP_HEIGHT; y++) {
		for (int x = 0; x < MAP_WIDTH; x++) {
			m_nodes[y][x].moveCost = -1;
		}
	}
	while (true) {
		SNode* processNode = NULL;
		//�S�m�[�h�ɑ΂��Ċm�F/�A�b�v�f�[�g���s���B
		for (int y = 0; y < MAP_HEIGHT; y++) {
			for (int x = 0; x < MAP_WIDTH; x++) {
				if(m_nodes[y][x].moveCost)
			}
		}
	}

}
void CPathFinding::BuildNodes()
{
	//�m�[�h���\�z����B
	for (int y = 0; y < MAP_HEIGHT; y++) {
		for (int x = 0; x < MAP_WIDTH; x++) {
			SNode* node = &m_nodes[y][x];
			//�}�b�v�̂h�c������
			node->mapID = g_map[y][x];
			//�אڃ}�b�v��NULL�������B
			node->linkNode[0] = NULL;
			node->linkNode[1] = NULL;
			node->linkNode[2] = NULL;
			node->linkNode[3] = NULL;
			node->moveCost = 0;
			//�אڃ}�b�v�̃m�[�h������B
			//�E�̃m�[�h
			if (x + 1 < MAP_WIDTH) {
				node->linkNode[0] = &m_nodes[y][x+1];
			}
			//���̃m�[�h
			if (x - 1 >= 0) {
				node->linkNode[1] = &m_nodes[y][x-1];
			}
			//��̃m�[�h
			if (y + 1 < MAP_HEIGHT) {
				node->linkNode[2] = &m_nodes[y+1][x];
			}
			//���̃m�[�h
			if (y - 1 >= 0) {
				node->linkNode[3] = &m_nodes[y-1][x];
			}
			node->position.Set(x, y);
		}
	}
}