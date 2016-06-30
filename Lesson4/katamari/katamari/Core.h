#pragma once

class Ouji;
class MonoBase;

//コア
class Core
{
public:
	Core();
	~Core();
	/*!
	*@brief	初期化
	*/
	void Init();
	/*!
	*@brief	更新
	*/
	void Update();
	/*!
	*@brief	描画処理。
	*@param[in,out]	renderContext	レンダリングコンテキスト
	*/
	void Render(CRenderContext& renderContext);
	/*!
	*@brief	王子を設定
	*@param[in]	ouji	王子
	*/
	void SetOuji(Ouji* ouji)
	{
		this->ouji = ouji;
	}
	/*!
	*@brief	座標を取得。
	*@param[in]	ouji	王子
	*/
	const CVector3& GetPosition()
	{
		return position;
	}
	/*!
	*@brief	Y軸周りの回転を取得
	*@param[in]	ouji	王子
	*/
	const CQuaternion& GetRotationY()
	{
		return rotationY;
	}
	/*!
	*@brief	回転を取得
	*@param[in]	ouji	王子
	*/
	const CQuaternion& GetRotation()
	{
		return rotation;
	}
	/*!
	*@brief	座標を加算。
	*@param[in]	addPos	加算する座標。
	*/
	void AddPosition(const CVector3& addPos)
	{
		position.Add(addPos);
	}
	/*!
	*@brief	回転を追加。
	*@param[in]	addRot	追加する回転。
	*/
	void AddRotationY(const CQuaternion& addRot)
	{
		rotationY.Multiply(addRot);
	}
	/*!
	*@brief	回転を追加。
	*@param[in]	addRot	追加する回転。
	*/
	void AddRotationX(const CQuaternion& addRot)
	{
		rotationX.Multiply(addRot);
	}
	/*!
	*@brief	X軸周りの回転を除外したワールド行列を取得。
	*/
	const CMatrix& GetWorldMatrixIgnoreXRotation() const
	{
		return worldMatrixIgnoreXRotation;
	}
	/*!
	*@brief	X軸周りの回転を除外したワールド行列を取得。
	*/
	const CMatrix& GetWorldMatrix() const
	{
		return model.GetWorldMatrix();
	}
	/*!
	*@brief	スケールを取得。
	*/
	const CVector3& GetScale() const
	{
		return scale;
	}
private:
	CVector3 position;				//!<コアの座標
	CQuaternion rotationY;			//!<Y軸周りのコアの回転
	CQuaternion rotationX;			//!<X軸周りのコアの回転
	CQuaternion	rotation;			//!<回転
	Ouji* ouji;
	CSkinModelData	modelData;		//モデルデータ。
	CSkinModel		model;			//モデル。
	CLight			light;			//!<ライト
	CVector3		scale;			//!<スケール。
	CMatrix			worldMatrixIgnoreXRotation;	//!<X軸周りの回転を除外したワールド行列。
	CVector3		targetScale;	//!<拡大目標。
	std::list<MonoBase*>	makikomiMonoList;	//!<巻き込んだモノのリスト。
};

