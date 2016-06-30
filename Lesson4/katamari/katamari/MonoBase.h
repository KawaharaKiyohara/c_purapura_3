#pragma once

//モノの基底クラス。
class MonoBase
{
public:
	MonoBase();
	virtual ~MonoBase();
	void Update();
	void Render(CRenderContext& renderContext);
	//初期化。
	virtual void Init(const CVector3& pos, const CQuaternion& rot)
	{
	}
	//巻き込まれたらコアが設定される。
	void SetCore(Core* core);
	//コアを取得。
	Core* GetCore()
	{
		return core;
	}
	//座標を取得。
	CVector3 GetPosition() 
	{
		return position;
	}
private:
	//サブクラスで実装する更新処理。
	virtual void UpdateSub() = 0;
protected:
	CVector3	localPosition;		//!<ローカル座標
	CQuaternion	localRotation;		//!<ローカル回転
	CVector3	position;			//!<ワールド座標。
	CQuaternion	rotation;			//!<ワールド回転。
	Core*		core;				//!<巻き込まれたらコアが設定される。
	CSkinModelData	modelData;		//モデルデータ。
	CSkinModel		model;			//モデル。
	CLight			light;			//!<ライト
};

