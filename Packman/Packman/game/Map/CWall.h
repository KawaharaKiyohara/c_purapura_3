/*!
 * @brief	�ǁB
 */

#ifndef _CWALL_H_
#define _CWALL_H_

#include "tkEngine/graphics/prerender/tkIDMap.h"
#include "tkEngine/shape/tkBoxShape.h"

class CWall : public tkEngine::IGameObject{
public:
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
	 *@brief	�\�z�����B
	 *@param[in]	size	���̃T�C�Y�B
	 *@param[in]	pos		���̍��W�B
	 */
	void Build( const CVector3& size, const CVector3& pos );
private:
	tkEngine::CBoxShape		m_box;			//!<���̌`��B
	tkEngine::CIDMapModel	m_idMapModel;	//!<IDMap�ւ̏������ݗp�̃��f���B
	tkEngine::CShadowModel	m_shadowModel;	//!<�V���h�E�}�b�v�ւ̏������ݗp�̃��f���B
	CMatrix					m_wvpMatrix;	//<���[���h�r���[�v���W�F�N�V�����s��B
};
#endif