#pragma once
class Ground
{
public:
	Ground();
	~Ground();
	//�������B
	void Init();
	//�`��B
	void Render(CRenderContext& renderContext);
private:
	CSkinModelData	modelData;		//���f���f�[�^�B
	CSkinModel		model;			//���f���B
	CLight			light;			//!<���C�g

};

