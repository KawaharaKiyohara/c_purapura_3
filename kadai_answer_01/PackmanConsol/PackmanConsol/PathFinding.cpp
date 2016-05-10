#include "stdafx.h"
#include "PathFinding.h"

CPathFinding::CPathFinding()
{

}
CPathFinding::~CPathFinding()
{

}
void CPathFinding::FindRoot(std::vector<CVector2>& root,  CVector2 startPos, CVector2 targetPos)
{
	root.clear();
	//�R�X�g��������
	for (int y = 0; y < MAP_HEIGHT; y++) {
		for (int x = 0; x < MAP_WIDTH; x++) {
			m_nodes[y][x].moveCost = -1;
			m_nodes[y][x].isDone = false;
			if (m_nodes[y][x].mapID == 1) {
				//�ǂ͒T���ς݂ɂ���B
				m_nodes[y][x].isDone = true;
			}
			m_nodes[y][x].parentNode = NULL;
		}
	}
	//�J�n�m�[�h���擾����B
	SNode* startNode = &m_nodes[startPos.GetY()][startPos.GetX()];
	startNode->moveCost = 0;
	while (true) {
		SNode* processNode = NULL;
		//�S�m�[�h�ɑ΂��Ċm�F/�A�b�v�f�[�g���s���B
		for (int y = 0; y < MAP_HEIGHT; y++) {
			for (int x = 0; x < MAP_WIDTH; x++) {
				SNode* node = &m_nodes[y][x];
				if (node->isDone || node->moveCost < 0) {
					continue;
				}
				//�������̃m�[�h���Ȃ���Ό��݂̃m�[�h�B
				if (!processNode) {
					processNode = node;
					continue;
				}
				//�K��ς݂łȂ��m�[�h�̂����A��ԏ������R�X�g�̃m�[�h��T���B
				if (node->moveCost < processNode->moveCost) {
					//����Ɉ����B
					processNode = node;
				}
			}
		}
		// �������̃m�[�h���Ȃ��Ȃ�����A�܂肷�ׂă`�F�b�N���I������烋�[�v�I��
		if (!processNode) {
			break;
		}
		//�����ς݂ɂ���B
		processNode->isDone = true;
		//�אڂ��Ă���m�[�h�ɃR�X�g��ݒ肷��B
		for (int i = 0; i < LINK_NODE_MAX; i++) {
			SNode* node = processNode->linkNode[i];
			if (node == NULL) {
				continue;
			}
			int cost = processNode->moveCost + 1;
			bool needsUpdate = (node->moveCost < 0) || (node->moveCost > cost);
			if (needsUpdate) {
				//�X�V�̕K�v����B
				node->moveCost = cost;
				node->parentNode = processNode;
			}
		}
	}
	//���[�g�����B
	SNode* node = &m_nodes[targetPos.GetY()][targetPos.GetX()];
	
	while (node != startNode) {
		root.push_back(node->position);
		node = node->parentNode;
	}
	std::reverse(root.begin(),root.end());	
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