/*!
 *@brief	�����_�����O�^�[�Q�b�g�̍쐬�e�X�g�B
 */

#ifndef _TESTCREATERENDERTARGET_H_
#define _TESTCREATERENDERTARGET_H_

#include "tkEngine/graphics/tkRenderTarget.h"

class CTestCreateRenderTarget : public tkEngine::IGameObject{
	void Start() override final;
	void Update() override final;
	void Render(tkEngine::CRenderContext& renderContext) override final;
private:
	tkEngine::CRenderTarget		m_renderTarget;		//!<�����_�����O�^�[�Q�b�g�B
};


#endif //_TESTCREATERENDERTARGET_H_