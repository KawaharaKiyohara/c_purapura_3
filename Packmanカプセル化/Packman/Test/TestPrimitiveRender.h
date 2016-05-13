/*!
 * @brief	�v���~�e�B�u�`��̃e�X�g�N���X�B
 */

#ifndef TESTPRIMITIVERENDER_H
#define TESTPRIMITIVERENDER_H

#include "tkEngine/graphics/tkPrimitive.h"
#include "tkEngine/graphics/tkCamera.h"
#include "tkEngine/graphics/tkEffect.h"

class CTestPrimitiveRender : public tkEngine::IGameObject{
	void Start() override final;
	void Update() override final;
	void Render(tkEngine::CRenderContext& renderContext) override final;
private:
	tkEngine::CPrimitive	m_primitive;	//�v���~�e�B�u�B
	tkEngine::CCamera		m_camera;		//�J�����B
	tkEngine::CEffect*		m_pEffect;		//�G�t�F�N�g�B
};
#endif //TESTPRIMITIVERENDER_H