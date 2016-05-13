/*!
 * @brief	�Q�[���}�l�[�W���B
 */
 
#include "stdafx.h"
#include "Packman/game/CGameManager.h"

CGameManager* CGameManager::m_instance = nullptr;

CGameManager::CGameManager()
{
}
CGameManager::~CGameManager()
{
}
void CGameManager::Start()
{
	TK_ASSERT(m_instance == nullptr, "error");
	m_instance = this;
	//�J�����쐬�B
	tkEngine::CGameObjectManager::Instance().AddGameObject(0, &m_camera);
	//�}�b�v�쐬�B
	m_mapBuilder.Build();
	m_player.Build(CVector3(0.0f,0.2f,0.0f));
	//�v���C���[�����[���h�ɒǉ��B
	CGameObjectManager::Instance().AddGameObject(0, &m_player);
}
void CGameManager::Update()
{
	{
		//�n�ʂ̃��C�g
		CVector3 lightDir;
		m_groundLight.SetDiffuseLightColor(0, CVector4(0.6f, 0.6f, 0.6f, 1.0f));
		lightDir = CVector3::AxisY;
		m_groundLight.SetDiffuseLightDirection(0, lightDir);

		m_groundLight.SetDiffuseLightColor(1, CVector4(0.6f, 0.6f, 0.6f, 1.0f));
		lightDir = CVector3::AxisX;
		lightDir.Scale(-1.0f);
		m_groundLight.SetDiffuseLightDirection(1, lightDir);

		m_groundLight.SetDiffuseLightColor(2, CVector4(0.6f, 0.6f, 0.6f, 1.0f));
		lightDir.Add(CVector3::AxisX, CVector3::AxisZ);
		lightDir.Normalize();
		m_groundLight.SetDiffuseLightDirection(2, lightDir);

		m_groundLight.SetDiffuseLightColor(3, CVector4(0.6f, 0.6f, 0.6f, 1.0f));
		lightDir = CVector3::AxisY;
		lightDir.Scale(-1.0f);
		lightDir.Normalize();
		m_groundLight.SetDiffuseLightDirection(3, lightDir);
		//���C�g���X�V�B
		m_groundLight.SetAmbinetLight(CVector3(0.2f, 0.2f, 0.2f));
	}
	{
		//�n�ʂ̃��C�g
		CVector3 lightDir;
		m_wallLight.SetDiffuseLightColor(0, CVector4(0.6f, 0.6f, 0.6f, 1.0f));
		lightDir = CVector3::AxisY;
		m_wallLight.SetDiffuseLightDirection(0, lightDir);

		m_wallLight.SetDiffuseLightColor(1, CVector4(0.6f, 0.6f, 0.6f, 1.0f));
		lightDir = CVector3::AxisX;
		lightDir.Scale(-1.0f);
		m_wallLight.SetDiffuseLightDirection(1, lightDir);

		m_wallLight.SetDiffuseLightColor(2, CVector4(0.6f, 0.6f, 0.6f, 1.0f));
		lightDir.Add(CVector3::AxisX, CVector3::AxisZ);
		m_wallLight.SetDiffuseLightDirection(2, lightDir);

		m_wallLight.SetDiffuseLightColor(3, CVector4(0.6f, 0.6f, 0.6f, 1.0f));
		lightDir = CVector3::AxisY;
		lightDir.Scale(-1.0f);
		lightDir.Normalize();
		m_wallLight.SetDiffuseLightDirection(3, lightDir);
		//���C�g���X�V�B
		m_wallLight.SetAmbinetLight(CVector3(0.2f, 0.2f, 0.2f));
	}
	{
		CVector3 lightDir;
		m_foodLight.SetDiffuseLightColor(0, CVector4(0.6f, 0.6f, 0.6f, 1.0f));
		lightDir = CVector3::AxisY;
		m_foodLight.SetDiffuseLightDirection(0, lightDir);

		m_foodLight.SetDiffuseLightColor(1, CVector4(10.6f, 10.6f, 0.6f, 1.0f));
		lightDir = CVector3::AxisX;
		lightDir.Scale(-1.0f);
		CVector3 pos = m_player.GetPosition();
		pos.x /= 0.0f;
		m_player.SetPosition(pos);
		m_foodLight.SetDiffuseLightDirection(1, lightDir);

		m_foodLight.SetDiffuseLightColor(2, CVector4(0.6f, 0.6f, 0.6f, 1.0f));
		lightDir.Add(CVector3::AxisX, CVector3::AxisZ);
		lightDir.Normalize();
		m_foodLight.SetDiffuseLightDirection(2, lightDir);

		m_foodLight.SetDiffuseLightColor(3, CVector4(0.6f, 0.6f, 0.6f, 1.0f));
		lightDir = CVector3::AxisY;
		lightDir.Scale(-1.0f);
		lightDir.Normalize();
		m_foodLight.SetDiffuseLightDirection(3, lightDir);
		m_foodLight.SetAmbinetLight(CVector3(10.0f, 0.5f, 0.0f));
	}
	/*tkEngine::CEngine::Instance().ShadowMap().SetLightPosition(CVector3(0.0f, 2.0f, -1.0f));
	tkEngine::CEngine::Instance().ShadowMap().SetLightDirection(lightDir);*/
	tkEngine::CEngine::Instance().ShadowMap().SetLightPosition(CVector3(2.0f, 3.5f, 1.0f));
	tkEngine::CEngine::Instance().ShadowMap().SetLightDirection(CVector3(-1.0f, -2.5f, -1.0f));
	
}
void CGameManager::Render(tkEngine::CRenderContext& renderContext)
{
}