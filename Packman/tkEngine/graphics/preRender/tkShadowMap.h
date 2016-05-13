/*!
 * @brief	�V���h�E�}�b�v�B
 */

#ifndef _TKSHADOWMAP_H_
#define _TKSHADOWMAP_H_

namespace tkEngine{
	/*!
	 * @brief	�e���f���B
	 */
	class CShadowModel{
	public:
		CShadowModel();
		~CShadowModel();
		/*!
		 * @brief	�v���~�e�B�u����쐬�B
		 */
		void Create( CPrimitive* prmi );
		/*!
		 * @brief	���[���h�s���ݒ�B
		 */
		void SetWorldMatrix( const CMatrix& mWorld )
		{
			m_mWorld = mWorld;
		}
		/*!
		 * @brief	�`��B
		 */
		void Render( CRenderContext& renderContext, CEffect* pEffect, const CMatrix& mLVP );
	private:
		CPrimitive*		m_prim;		//!<�v���~�e�B�u�B
		CMatrix			m_mWorld;	//!<���[���h�s���ݒ�B
	};
	class CShadowMap : Noncopyable{
	public:
		/*!
		 * @brief	�R���X�g���N�^�B
		 */
		CShadowMap();
		/*!
		 * @brief	�f�X�g���N�^�B
		 */
		~CShadowMap();
		/*!
		 * @brief	�쐬�B
		 */
		void Create( int w, int h );
		/*!
		 * @brief	�J���B
		 */
		void Release();
		/*!
		 * @brief	�e���f�����G���g���[�B
		 */
		void Entry( CShadowModel* model );
		/*!
		 * @brief	�V���h�E�}�b�v�ɏ������݁B
		 *@param[in]	renderContext		�����_�����O�R���e�L�X�g�B
		 */
		void RenderToShadowMap( CRenderContext& renderContext );
		/*!
		 * @brief	�V���h�E�}�b�v�̃e�N�X�`�����擾�B
		 */
		CTexture* GetTexture()
		{
			return m_shadowMapRT.GetTexture();
		}
		/*!
		 * @brief	���C�g�̕�����ݒ�B
		 */
		void SetLightDirection( const CVector3& lightDir )
		{
			m_lightDirection = lightDir;
		}
		/*!
		 * @brief	���C�g�̈ʒu��ݒ�B
		 */
		void SetLightPosition( const CVector3& lightPosition )
		{
			m_lightPosition = lightPosition;
		}
		/*!
		* @brief	���C�g�r���[�v���W�F�N�V�����s����擾�B
		*/
		const CMatrix& GetLVPMatrix() const
		{
			return m_LVPMatrix;
		}
		/*!
		* @brief	�����ʂ�ݒ�B
		*/
		void SetFar(float Far)
		{
			m_far = Far;
		}
		/*!
		* @brief	�����ʂ�ݒ�B
		*/
		void SetNear(float Near)
		{
			m_far = Near;
		}
		/*!
		* @brief	�X�V�B
		*/
		void Update();
		/*!
		* @brief	�ߕ��ʁB
		*/
		float GetNear() const
		{
			return m_near;
		}
		/*!
		* @brief	������
		*/
		float GetFar() const
		{
			return m_far;
		}
	private:
		bool						m_isEnable;			//!<�L���H
		CRenderTarget				m_shadowMapRT;		//!<�V���h�E�}�b�v���������ރ����_�����O�^�[�Q�b�g�B
		std::vector<CShadowModel*>	m_shadowModels;		//!<�V���h�E�}�b�v�ɏ������݂��s���e���f���B
		CEffect*					m_pShadowMapEffect;	//!<�V���h�E�}�b�v�̃G�t�F�N�g�B
		CVector3					m_lightPosition;	//!<���C�g�̈ʒu�B
		CVector3					m_lightDirection;	//!<���C�g�̌����B
		CMatrix						m_lvMatrix;
		CMatrix						m_LVPMatrix;		//!<���C�g�r���[�v���W�F�N�V�����s��B
		CMatrix						m_projectionMatrix;
		float						m_near;				//!<�ߕ��ʁB
		float						m_far;				//!<�����ʁB
	};
}

#endif //_TKSHADOWMAP_H_