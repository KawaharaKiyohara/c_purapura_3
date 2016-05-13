/*!
 * @brief	�Q�[���}�l�[�W���B
 */

#ifndef _CGAMEMANAGER_H_
#define _CGAMEMANAGER_H_

#include "Packman/game/CCamera.h"
#include "tkEngine/graphics/tkLight.h"
#include "Packman/game/map/CMapBuilder.h"
#include "Packman/game/Player/CPlayer.h"

/*!
 *@brief	�Q�[���}�l�[�W���[�B
 */
class CGameManager : public tkEngine::IGameObject{
public:
	/*!
	 *@brief	�R���X�g���N�^�B
	 */
	CGameManager();
	/*!
	 *@brief	�f�X�g���N�^�B
	 */
	~CGameManager();
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
	 *@brief	�Q�[���}�l�[�W���[�̃C���X�^���X���擾�B
	 */
	static CGameManager& GetInstance()
	{
		return *m_instance;
	}
	/*!
	 *@brief	�Q�[���J�����̃C���X�^���X���擾�B
	 */
	CGameCamera&  GetGameCamera()
	{
		return m_camera;
	}
	/*!
	 *@brief	�n�ʂ̃��C�g���擾�B
	 */
	CLight& GetGroundLight()
	{
		return m_groundLight;
	}
	/*!
	 *@brief	�ǂ̃��C�g���擾�B
	 */
	CLight& GetWallLight()
	{
		return m_wallLight;
	}
	/*!
	 *@brief	�H�ו��̃��C�g���擾�B
	 */
	CLight& GetFoodLight()
	{
		return m_foodLight;
	}
	/*!
	*@brief	�v���C�����擾�B
	*/
	CPlayer& GetPlayer()
	{
		return m_player;
	}
private:
	CGameCamera		m_camera;			//�J�����B
	CLight			m_groundLight;		//�n�ʂ̃��C�g
	CLight			m_wallLight;		//�ǂ̃��C�g�B
	CLight			m_foodLight;		//�H�ו��̃��C�g�B
	static CGameManager*	m_instance;	//�B��̃C���X�^���X�B
	CMapBuilder		m_mapBuilder;		//�}�b�v�\�z�����B
	CPlayer			m_player;			//�v���C��
};

static inline CPlayer& Player()
{
	return CGameManager::GetInstance().GetPlayer();
}

#endif //_CGAMEMANAGER_H_