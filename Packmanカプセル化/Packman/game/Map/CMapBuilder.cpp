/*!
 * @brief	�}�b�v�\�z�����B
 */

#include "stdafx.h"
#include "Packman/game/Map/CMapBuilder.h"
#include "Packman/game/Map/CWall.h"
#include "Packman/game/item/CFood.h"
namespace{
	const float GRID_SIZE = 0.2f;
	const int NUM_GRID = 15;
	//1�͕ǁB
	static int sMap[NUM_GRID][NUM_GRID] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1},
		{1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
		{1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
		{1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1},
		{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1},
		{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
		{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		
		
	};
}
CMapBuilder::CMapBuilder()
{
}
CMapBuilder::~CMapBuilder()
{
}
void CMapBuilder::Build()
{
	//�n�ʂ��쐬�B
	m_ground.Create( NUM_GRID * GRID_SIZE );
	CGameObjectManager::Instance().AddGameObject(0, &m_ground);
	float radius = GRID_SIZE *0.2f;
	CFood::CreateShape(GRID_SIZE *0.2f);
	for (int i = 0; i < NUM_GRID; i++) {
		for (int k = 0; k < NUM_GRID; k++) {
			int x = k - NUM_GRID / 2;
			int z = i - NUM_GRID / 2;
			if (sMap[i][k] == 1) {
				//�ǂ��쐬�B
				CWall* wall = CGameObjectManager::Instance().NewGameObject<CWall>(0);
				wall->Build(CVector3(GRID_SIZE, GRID_SIZE, GRID_SIZE), CVector3(GRID_SIZE*x, GRID_SIZE*0.5f, GRID_SIZE*-z));
			}
			else if (sMap[i][k] == 0) {
				//�p�b�N�}���̃G�T���쐬�B
				CFood* food = CGameObjectManager::Instance().NewGameObject<CFood>(0);
				food->Build(CVector3(GRID_SIZE*x, radius, GRID_SIZE*-z ) );
			}
		}
	}
}