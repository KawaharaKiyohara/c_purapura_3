/*!
 *@brief	パス検索で使用するノードクラス。
 */
#ifndef _TKPATHFINDINGNODE_H_
#define _TKPATHFINDINGNODE_H_

namespace tkEngine{
	/*!
	 *@brief	パス検索で使用するノードクラス。
	 */
	class CPathFindingNode{
	public:
		/*!
		 *@brief	コンストラクタ。
		 */
		CPathFindingNode()
		{
		}
		/*!
		 *@brief	デストラクタ。
		 */
		~CPathFindingNode()
		{
		}
	private:
		std::vector<CPathFindingNode*>	m_linkNodes;		//!<隣接ノード。
	};
}

#endif // #ifndef _TKPATHFINDINGNODE_H_