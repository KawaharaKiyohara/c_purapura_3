/*!
 *@brief	�p�X�����Ŏg�p����m�[�h�N���X�B
 */
#ifndef _TKPATHFINDINGNODE_H_
#define _TKPATHFINDINGNODE_H_

namespace tkEngine{
	/*!
	 *@brief	�p�X�����Ŏg�p����m�[�h�N���X�B
	 */
	class CPathFindingNode{
	public:
		/*!
		 *@brief	�R���X�g���N�^�B
		 */
		CPathFindingNode()
		{
		}
		/*!
		 *@brief	�f�X�g���N�^�B
		 */
		~CPathFindingNode()
		{
		}
	private:
		std::vector<CPathFindingNode*>	m_linkNodes;		//!<�אڃm�[�h�B
	};
}

#endif // #ifndef _TKPATHFINDINGNODE_H_