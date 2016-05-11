#pragma once
#include "CVector2.h"
#include "PackmanConsol.h"

#define LINK_NODE_MAX	4		//�אڃm�[�h�̍ő吔�B
struct SNode {
	SNode* linkNode[LINK_NODE_MAX];		//�אڃm�[�h�BNULL�ł���Ηאڃm�[�h�Ȃ��B
	SNode* parentNode;					//�e�̃m�[�h�B
	int mapID;							//�}�b�v�ԍ��B
	CVector2 position;					//�m�[�h�̍��W�B
	int moveCost;						//�ړ��R�X�g
	bool isDone;						//�����ς݃t���O�B
};
class CPathFinding {
public:
	CPathFinding();
	~CPathFinding();
	//�m�[�h�̍\�z�B
	void BuildNodes();
	//���[�g�̌���
	//root		�������ꂽ���[�g�̊i�[��B
	//startPos	�J�n���W�B
	//targetPos	�ڕW���W�B
	void FindRoot(std::vector<CVector2>& root, CVector2 startPos, CVector2 targetPos);
private:
	SNode		m_nodes[MAP_HEIGHT][MAP_WIDTH];		//�m�[�h�̔z��B
};