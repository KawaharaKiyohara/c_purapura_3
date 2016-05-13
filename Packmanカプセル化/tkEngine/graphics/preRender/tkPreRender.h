/*!
 * @brief	�v�������_�[
 */

#ifndef _TKPRERENDER_H_
#define _TKPRERENDER_H_

#include "tkEngine/graphics/tkGraphicsConfig.h"
#include "tkEngine/graphics/preRender/tkIDMap.h"
#include "tkEngine/graphics/preRender/tkShadowMap.h"

namespace tkEngine{
	/*!
	 * @brief	�v�������_�����O�B
	 */
	class CPreRender : Noncopyable{
	public:
		/*!
		 * @brief	�R���X�g���N�^�B
		 */
		CPreRender();
		/*!
		 * @brief	�f�X�g���N�^�B
		 */
		~CPreRender();
		/*!
		 * @brief	�쐬�B
		 *@param[in]	config	�R���t�B�O�B
		 */
		void Create( const SGraphicsConfig& config );
		/*!
		 * @brief	�`��B
		 */
		void Render( CRenderContext& context )
		{
			m_idMap.RenderToIDMap(context);
			m_shadowMap.RenderToShadowMap(context);
		}
		/*!
		* @brief	�X�V�B
		*/
		void Update()
		{
			m_shadowMap.Update();
		}
		/*!
		* @brief	IDMap�̎擾�B
		*/
		CIDMap& GetIDMap()
		{
			return m_idMap;
		}
		/*!
		* @brief	�V���h�E�}�b�v�̎擾�B
		*/
		CShadowMap& GetShadowMap()
		{
			return m_shadowMap;
		}
	private:
		SGraphicsConfig	m_config;		//!<�R���t�B�O�B
		CIDMap			m_idMap;		//!<ID�}�b�v
		CShadowMap		m_shadowMap;	//!<�V���h�E�}�b�v�B
	};
}
#endif //_TKPRERENDER_H_