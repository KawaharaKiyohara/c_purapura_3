/*!
 * @brief	�}�b�v�\�z�����B
 */

#ifndef _CMAPBUILDER_H_
#define _CMAPBUILDER_H_

#include "packman/game/Map/CGround.h"
class CMapBuilder{
public:
	CMapBuilder();
	~CMapBuilder();
	void Build();
private:
	CGround m_ground;

};
#endif 