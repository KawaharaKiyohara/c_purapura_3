/*!
*@brief	�X�L�����f��
*/
#ifndef _TKSKINMODEL_H_
#define _TKSKINMODEL_H_

#include "tkEngine/graphics/tkAnimation.h"

namespace tkEngine {
	class CEffect;
	class CSkinModelData;
	class CRenderContext;
	class CLight;
	/*!
	*@brief	�X�L�����f��
	*/
	class CSkinModel {
	public:
		CSkinModel();
		~CSkinModel();
		/*!
		*@brief	������
		*/
		void Init(CSkinModelData* modelData);
		/*!
		*@brief	�`��
		*/
		void Draw(CRenderContext& renderContext, const CMatrix& viewMatrix, const CMatrix& projMatrix);
		/*!
		*@brief	�C�~�f�B�G�C�g�`��B
		*@details
		* ���̊֐������s����Ƒ��`��R�}���h��GPU�ɑ����܂��B
		*/
		void ImmidiateDraw(LPDIRECT3DDEVICE9 pd3ddevice, D3DXMATRIX* viewMatrix, D3DXMATRIX* projMatrix);
		
		/*!
		*@brief	���[���h�s����X�V�B
		*@details
		* ���CMotion�N���X�Ɉړ������܂��B
		*@param[in]		trans	���s�ړ��B
		*@param[in]		rot		��]�B
		*@param[in]		scale	�g��B
		*/
		void UpdateWorldMatrix( const CVector3& trans, const CQuaternion& rot, const CVector3& scale );
		/*!
		*@brief	���C�g��ݒ�B
		*/
		void SetLight(CLight* light)
		{
			m_light = light;
		}
		/*!
		*@brief	�@���}�b�v��ݒ�B
		*@param[in] normalMap
		*/
		void SetNormalMap(CTexture* normalMap)
		{
			m_normalMap = normalMap;
		}
		/*!
		*@brief	���[���h�s����擾�B
		*/
		const CMatrix& GetWorldMatrix() const
		{
			return m_worldMatrix;
		}
	private:
		CMatrix				m_worldMatrix;		//!<���[���h�s��B
		CMatrix				m_rotationMatrix;	//!<��]�s��B
		CSkinModelData*		m_skinModelData;	//!<�X�L�����f���f�[�^�B
		CEffect*			m_pEffect;			//!<�G�t�F�N�g�B
		CAnimation			m_animation;		//!<�A�j���[�V�����B
		CLight*				m_light;			//!<���C�g�B
		CTexture*           m_normalMap;		//!<�@���}�b�v�B
	};
}

#endif // #ifndef _TKSKINMODEL_H_