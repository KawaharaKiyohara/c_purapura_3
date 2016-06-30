#pragma once
class Ground
{
public:
	Ground();
	~Ground();
	//初期化。
	void Init();
	//描画。
	void Render(CRenderContext& renderContext);
private:
	CSkinModelData	modelData;		//モデルデータ。
	CSkinModel		model;			//モデル。
	CLight			light;			//!<ライト

};

