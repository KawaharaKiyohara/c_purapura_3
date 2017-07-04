#pragma once

class MapChip;
class ItemMaker;

/*!
 * @brief	�}�b�v�N���X�B
 */
class Map : public IGameObject {
public:
	
	Map();
	~Map();
	bool Start() override;
	void Update() override;
	void Render(CRenderContext& renderContext) override;
private:

private:
	std::vector<MapChip*> mapChipList;	//�}�b�v�`�b�v�̃��X�g�B
};
