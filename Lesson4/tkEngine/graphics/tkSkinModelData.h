/*!
 *@brief	�X�L�����f���f�[�^
 */
#ifndef _TKSKINMODELDATA_H_
#define _TKSKINMODELDATA_H_


namespace tkEngine{
	struct D3DXFRAME_DERIVED : public D3DXFRAME {
		D3DXMATRIXA16	CombinedTransformationMatrix;	//�����ςݍs��B
	};
	struct D3DXMESHCONTAINER_DERIVED : public D3DXMESHCONTAINER {
		LPDIRECT3DTEXTURE9* ppTextures;
		LPD3DXMESH pOrigMesh;
		LPD3DXATTRIBUTERANGE pAttributeTable;
		DWORD NumAttributeGroups;
		DWORD NumInfl;
		LPD3DXBUFFER pBoneCombinationBuf;
		D3DXMATRIX** ppBoneMatrixPtrs;
		D3DXMATRIX* pBoneOffsetMatrices;
		DWORD NumPaletteEntries;
		bool UseSoftwareVP;
		DWORD iAttributeSW;
	};
	class CAnimation;
	/*!
	 *@brief	�X�L�����f���f�[�^
	 */
	class CSkinModelData{
	public:
		/*!
		 *@brief	�R���X�g���N�^�B
		 */
		CSkinModelData();
		/*!
		 *@brief	�f�X�g���N�^�B
		 */
		~CSkinModelData();
		/*!
		 * @brief	���f���f�[�^�����[�h�B
		 *@param[in]	filePath	�t�@�C���p�X�B
		 *@param[out]	anim		�A�j���[�V�����t�����f���f�[�^�̏ꍇ�A�A�j���[�V�����N���X���\�z����܂��B
		 */
		void LoadModelData( const char* filePath, CAnimation* anim );
		/*!
		* @brief	�����[�X�B
		*/
		void Release();
		LPD3DXFRAME GetFrameRoot()
		{
			return m_frameRoot;
		}
		ID3DXAnimationController* GetAnimationController()
		{
			return m_pAnimController;
		}
		/*!
		* @brief	�{�[���s����X�V�B
		*/
		void UpdateBoneMatrix( const CMatrix& matWorld );
	private:
		LPD3DXFRAME					m_frameRoot;		//�t���[�����[�g�B
		ID3DXAnimationController*   m_pAnimController;	//�A�j���[�V�����R���g���[���B
	};
}

#endif //_TKSKINMODELDATA_H_
