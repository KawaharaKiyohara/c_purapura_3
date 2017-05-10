/*!
 * @brief	カメラ
 */

#ifndef _TKCAMERA_H_
#define _TKCAMERA_H_

namespace tkEngine{
	class CCamera{
	public:
		CCamera();
		~CCamera();
		/*!
		 * @brief	ビュー行列、プロジェクション行列、ビュープロジェクション行列を更新。
		 */
		virtual void Update();
		
		/*!
		 * @brief	注視点を設定。
		 *@param[in]	target		注視点。
		 */
		void SetTarget( const CVector3& target )
		{
			m_target = target;
		}
		/*!
		 * @brief	注視点を取得。
		 *@return	注視点。
		 */
		const CVector3& GetTarget() const
		{
			return m_target;
		}
		/*!
		 * @brief	カメラの上方向を設定。
		 */
		void SetUp( const CVector3& up )
		{
			m_up = up;
		}
		/*!
		 * @brief	カメラの上方向を取得
		 */
		const CVector3& GetUp() const
		{
			return m_up;
		}
		/*!
		* @brief	ビュー行列の逆行列を取得。
		*/
		const CMatrix& GetViewMatrixInv() const
		{
			return m_viewMatrixInv;
		}
		/*!
		 * @brief	ビュー行列を取得。
		 */
		const CMatrix& GetViewMatrix() const
		{
			return m_viewMatrix;
		}
		/*!
		 * @brief	プロジェクション行列を取得。
		 */
		const CMatrix& GetProjectionMatrix() const
		{
			return m_projectionMatrix;
		}
		/*!
		 * @brief	ビュープロジェクション行列を取得。
		 */
		const CMatrix& GetViewProjectionMatrix() const
		{
			return m_viewProjectionMatrix;
		}
		/*!
		* @brief	カメラの回転行列を取得。
		*/
		const CMatrix& GetCameraRotation() const
		{
			return m_cameraRotation;
		}
		/*!
		 * @brief	遠平面を設定。
		 */
		void SetFar( float fFar )
		{
			m_far = fFar;
		}
		/*!
		 * @brief	近平面を設定。
		 */
		void SetNear( float fNear )
		{
			m_near = fNear;
		}
		/*!
		 * @brief	遠平面を取得。
		 */
		float GetFar() const
		{
			return m_far;
		}
		/*!
		 * @brief	近平面を取得。
		 */
		float GetNear() const
		{
			return m_near;
		}
		
		/*!
		* @brief	ワールド座標からスクリーン座標を計算する。
		*@details
		* 計算されるスクリーン座標は画面の中心を{0,0}、左上を{画面の幅*-0.5,画面の高さ*-0.5}</br>
		* 右下を{画面の幅*0.5,画面の高さ*0.5}とする座標です。
		*@param[out]	screenPos		スクリーン座標の格納先。
		*@param[in]		worldPos		ワールド座標。
		*/
		void CalcScreenPositionFromWorldPosition(CVector2& screenPos, const CVector3& worldPos) const;
	public:
		CVector3	m_position;							//!<カメラ位置。
		float			m_viewAngle;						//!<画角(ラジアン)。
	private:
		
		CVector3	m_up;								//!<カメラの上方向。
		CVector3	m_target;							//!<カメラの中止点。
		CMatrix		m_viewMatrix;						//!<ビュー行列。
		CMatrix		m_projectionMatrix;					//!<プロジェクション行列。
		CMatrix		m_viewProjectionMatrix;				//!<ビュープロジェクション行列。
		CMatrix		m_viewMatrixInv;					//!<ビュー行列の逆行列。
		CMatrix		m_cameraRotation;					//!<カメラの回転行列。
		float			m_near;								//!<近平面。
		float			m_far;								//!<遠平面。
		
		float			m_aspect;							//!<アスペクト比。
		bool		m_isNeedUpdateProjectionMatrix;
	};
}
#endif //_TKCAMERA_H_