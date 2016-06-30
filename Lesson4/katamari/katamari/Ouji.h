#pragma once

#include "tkEngine/graphics/tkLight.h"
#include "OujiAnimationController.h"
#include "OujiStateBase.h"

class Core;

//王子クラス
class Ouji
{
public:
	
	
	Ouji();
	~Ouji();
	/*!
	*@brief	初期化。
	*/
	void Init();
	/*!
	 *@brief	描画処理。
	 *@param[in,out]	renderContext	レンダリングコンテキスト
	 */
	void Render(CRenderContext& renderContext);
	/*!
	 *@brief	更新処理
	 */
	void Update();
	/*!
	*@brief	アニメーションの再生。
	*/
	void PlayAnimation(EOujiAnim animationIndex)
	{
		animation.PlayAnimation(animationIndex, 0.2f);
	}
	/*!
	*@brief	アニメーションの補間中？
	*/
	bool IsInterpolateAnimation()
	{
		return animation.IsInterpolate();
	}
	/*!
	*@brief	ステートリスナーの追加。
	*@param[in]	listner		ステートリスナー。
	*/
	void AddStateListner(IOujiStateListner* listner)
	{
		stateListner.push_back(listner);
	}
	/*!
	*@brief	ステートリスナーの削除。
	*@param[in]	listner		ステートリスナー。
	*/
	void RemoveStateListner(IOujiStateListner* listner)
	{
		auto delIt = std::find(stateListner.begin(), stateListner.end(), listner);
		if (delIt != stateListner.end()) {
			stateListner.erase(delIt);
		}
	}
	/*!
	*@brief	回転を追加。
	*@param[in]	addRot	追加する回転。
	*/
	void AddRotation(const CQuaternion& addRot)
	{
		localRotation.Multiply(addRot);
	}
	/*!
	*@brief	ステートの切り替え
	*@param[in]	nextState		次のステート。
	*/
	void ChangeState( EOujiState nextState );
	/*!
	*@brief	座標を取得。
	*/
	const CVector3& GetPosition() const
	{
		return position;
	}
	/*!
	*@brief	王子の向きを取得。
	*/
	const CVector3& GetDirection() const
	{
		return direction;
	}
	/*!
	*@brief	コアを設定。
	*/
	void SetCore(Core* core)
	{
		this->core = core;
	}
	/*!
	*@brief	コアを取得。
	*/
	Core* GetCore()
	{
		return core;
	}
private:
	/*!
	*@brief	ライトの初期化。
	*/
	void InitLight();
private:
	std::list<IOujiStateListner*>	stateListner;	//!<ステート切り替えのリスナー。
	CSkinModel				model;					//!<モデル。
	CSkinModelData			modelData;				//!<モデルデータ。
	CAnimation				animation;				//!<アニメーション。
	CVector3				localPosition;			//!<コア座標系での座標。
	CQuaternion				localRotation;			//!<コア座標系での回転。
	CVector3				position;				//!<ワールド座標系での座標。
	CQuaternion				rotation;				//!<ワールド座標系での回転。
	CMatrix					localMatrix;			//!<親の座標系でのローカルマトリックス。
	CLight					light;					//!<ライト
	OujiAnimationController animationController;	//!<アニメーションコントローラ。
	OujiStateBase*			state;					//!<ステート
	CVector3				direction;				//!<王子の向き。
	Core*					core;					//!<コア
};

