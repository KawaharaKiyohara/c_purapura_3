#pragma once

#include "tkEngine/graphics/tkSkinModelData.h"
#include "tkEngine/graphics/tkSkinModel.h"
#include "tkEngine/graphics/tkAnimation.h"
#include "tkEngine/graphics/tkEffect.h"
#include "tkEngine/graphics/tkCamera.h"
#include "tkEngine/graphics/tkLight.h"
#include "tkEngine/graphics/tkTexture.h"

class UnityChanInstance :
	public IGameObject
{
private:
	enum InitStep {
		InitStep_Load,
		InitStep_WaitLoad,
	};
public:
	UnityChanInstance();
	~UnityChanInstance();
	bool Start() override;
	void Update() override;
	void Render(CRenderContext& renderContext) override;
private:
	CSkinModelDataHandle	skinModelData;
	CSkinModel				skinModel;			//�X�L�����f���B
	CAnimation				animation;			//�A�j���[�V�����B
	CLight					light;				//���C�g�B
	int						currentAnimSetNo;
	CTexture				normalMap;			//�@���}�b�v�B
	CTexture				specMap;			//�X�y�L�����}�b�v�B
	CMatrix*				worldMatrixBuffer;
	InitStep				initStep = InitStep_Load;

};

