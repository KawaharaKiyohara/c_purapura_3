/*!
 * @brief	�e�N�X�`���B
 */

#ifndef _TKTEXTURE_H_
#define _TKTEXTURE_H_

namespace tkEngine{
	/*!
	 * @brief	�e�N�X�`���B
	 */
	class CTexture{
	public:
		CTexture()
		{
		}
		~CTexture()
		{
		}
		void SetTextureDX( LPDIRECT3DTEXTURE9 tex )
		{
			m_tex = tex;
		}
		LPDIRECT3DTEXTURE9 GetTextureDX() 
		{
			return m_tex;
		}
	private:
		LPDIRECT3DTEXTURE9	m_tex;		//!<�e�N�X�`���B
	};
}

#endif // _TKTEXTURE_H_