/*!
 *@brief	���C�g
 */

#ifndef _TKLIGHT_H_
#define _TKLIGHT_H_

namespace tkEngine {
	/*!
	 *@brief	���C�g
	 */
	class CLight : Noncopyable{
	public:
		static const int NUM_DIFFUSE_LIGHT = 4;
	public:
		CLight()
		{
			for( int i = 0; i < NUM_DIFFUSE_LIGHT; i++ ){
				m_diffuseLightDirection[i] = CVector3::AxisX;
				m_diffuseLightColor[i].Set( 0.0f, 0.0f, 0.0f, 0.0f );
			}
			m_ambientLight.Set( 0.1f, 0.1f, 0.1f );
		}
		/*!
		 *@brief	�f�B�t���[�Y���C�g�̌�����ݒ�B
		 *@param[in]	no				���C�g�̔ԍ��B
		 *@param[in]	lightDirection	���C�g�̕����B
		 */
		void SetDiffuseLightDirection( int no, const CVector3 lightDirection )
		{
			TK_ASSERT( no < NUM_DIFFUSE_LIGHT, "error");
			m_diffuseLightDirection[no] = lightDirection;
		}
		/*!
		 *@brief	�f�B�t���[�Y���C�g�̌������擾�B
		 *@param[in]	no		���C�g�̔ԍ��B
		 *@return	���C�g�̌����B
		 */
		const CVector3& GetDiffuseLightDirection( int no ) const
		{
			return m_diffuseLightDirection[no];
		}
		/*!
		 *@brief	�f�B�t���[�Y���C�g�̃J���[��ݒ�B
		 *@param[in]	no			���C�g�̔ԍ��B
		 *@param[in]	lightColor	���C�g�̃J���[�B
		 */
		void SetDiffuseLightColor( int no, const CVector4& lightColor )
		{
			TK_ASSERT( no < NUM_DIFFUSE_LIGHT, "error" );
			m_diffuseLightColor[no] = lightColor;
		}
		/*!
		 *@brief	�f�B�t���[�Y���C�g�̃J���[���擾�B
		 */
		const CVector4& GetDiffuseLightColor( int no ) const
		{
			TK_ASSERT( no < NUM_DIFFUSE_LIGHT, "error" );
			return m_diffuseLightColor[no];
		}
		/*!
		 *@brief	�������擾�B
		 */
		const CVector3& GetAmbientLight() const
		{
			return m_ambientLight;
		}
		/*!
		 *@brief	������ݒ�B
		 */
		void SetAmbinetLight( const CVector3& ambient )
		{
			m_ambientLight = ambient;
		}
	private:
		CVector3		m_diffuseLightDirection[NUM_DIFFUSE_LIGHT];		//!<�f�B�t���[�Y���C�g�̌����B
		CVector4		m_diffuseLightColor[NUM_DIFFUSE_LIGHT];			//!<�f�B�t���[�Y���C�g�̃J���[(x:R�����Ay:G�����Az:B�����Aw:�X�y�L�����̋���)�B
		CVector3		m_ambientLight;									//!<�A���r�G���g���C�g�B
	};
}
#endif // _TKLIGHT_H_