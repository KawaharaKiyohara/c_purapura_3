#include "stdafx.h"
#include "Map/Map.h"
#include "Map/MapChip.h"
#include "ItemMaker.h"

using namespace std;
namespace {
	//�}�b�v�`�b�v�̔z�u���̃e�[�u���B
	SMapChipLocInfo mapChipLocInfoTable[] = {
		#include "locationInfo.h"
	};
}
Map::Map()
{
	g_itemMaker = NewGO<ItemMaker>(0);
}
Map::~Map()
{
	for (auto& mapchip : mapChipList) {
		DeleteGO(mapchip);
	}
	DeleteGO(g_itemMaker);
}

#define ENABLE_MAPCHIP_INSTANCING

bool Map::Start()
{
	//�z�u��񂩂�}�b�v���\�z
	int tableSize = sizeof(mapChipLocInfoTable)/sizeof(mapChipLocInfoTable[0]);
#ifdef ENABLE_MAPCHIP_INSTANCING
	map<int , vector<SMapChipLocInfo*>*> m;
	//�C���X�^���V���O�`����s�����߂ɁA�������O�̃��f�����W�߂�B
	for(int i = 0; i < tableSize; i++){
		int hash = CUtil::MakeHash(mapChipLocInfoTable[i].modelName);
		auto& it = m.find(hash);
		if (it != m.end()) {
			//���̖��O�̃��f���͓o�^�ς�
			it->second->push_back(&mapChipLocInfoTable[i]);
		}
		else {
			//�V�K
			vector<SMapChipLocInfo*>* newList = new vector<SMapChipLocInfo*>;
			newList->push_back(&mapChipLocInfoTable[i]);
			m.insert(std::pair< int, vector<SMapChipLocInfo*>*>(
				hash,
				newList
			));
		}
	}
	for (auto& mapchipList : m) {
		if (!strcmp((*mapchipList.second)[0]->modelName, "Apple"))
		{
			g_itemMaker->Init(*mapchipList.second);
		}
		else
		{
			//�}�b�v�`�b�v�𐶐�
			MapChip* mapChip = NewGO<MapChip>(0);
			mapChip->Init(*mapchipList.second);
			mapChipList.push_back(mapChip);
		}
		delete mapchipList.second;
	}
#else
	//�C���X�^���V���O���g��Ȃ��o�[�W�����B
	for (int i = 0; i < tableSize; i++) {
		vector<SMapChipLocInfo*> list;
		list.push_back(&mapChipLocInfoTable[i]);
		MapChip* mapChip = NewGO<MapChip>(0);
		mapChip->Init(list);
		mapChipList.push_back(mapChip);
	}
#endif
	return true;
}
void Map::Update()
{
}
void Map::Render(CRenderContext& renderContext)
{
}