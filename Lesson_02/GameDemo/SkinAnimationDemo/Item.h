#pragma once
#include "Light/InGameLight.h"
#include "Map/MapChip.h"
/*
�񕜃A�C�e���N���X
*/
class Item : public IGameObject
{
public:
	Item();
	~Item();
	void Init(CVector3);

	bool Start() override;

	void OnDestroy() override;

	void Update() override;

	void Render(CRenderContext&) override;

	bool IsDelete()
	{
		return deleteFlg;
	}


private:
	CSkinModelData			skinModelData;
	CSkinModel				skinModel;
	CQuaternion				rotation;
	CLight					light;
	CVector3				position;
	bool					deleteFlg;		//�v���C���[�ɂƂ�ꂽ���̃t���O
};

