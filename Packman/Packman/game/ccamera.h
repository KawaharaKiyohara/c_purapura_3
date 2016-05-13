/*!
 * @brief	�J�����B
 */

#ifndef _CCAMERA_H_
#define _CCAMERA_H_

#include "tkEngine/graphics/tkCamera.h"

/*!
 *@brief	�J�����N���X�B
 */
class CGameCamera : public tkEngine::IGameObject{ 
public:
	/*!
	 *@brief	�R���X�g���N�^�B
	 */
	CGameCamera();
	/*!
	 *@brief	�f�X�g���N�^�B
	 */
	~CGameCamera();
	/*!
	 *@brief	Update�����߂ČĂ΂�钼�O�Ɉ�x�����Ă΂�鏈���B
	 */
	void Start() override final;
	/*!
	 *@brief	�X�V�����B60fps�Ȃ�16�~���b�Ɉ�x�B30fps�Ȃ�32�~���b�Ɉ�x�Ă΂��B
	 */
	void Update() override final;
	/*!
	 *@brief	�`�揈���B60fps�Ȃ�16�~���b�Ɉ�x�B30fps�Ȃ�32�~���b�Ɉ�x�Ă΂��B
	 */
	void Render(tkEngine::CRenderContext& renderContext) override final;
	/*!
	 *@brief	�r���[�v���W�F�N�V�����s����擾�B
	 */
	const CMatrix& GetViewProjectionMatrix()
	{
		return m_camera.GetViewProjectionMatrix();
	}
private:
	tkEngine::CCamera	m_camera;	//!<�J�����B
	CVector3			m_playerDist;
};
#endif // _CCAMERA_H_