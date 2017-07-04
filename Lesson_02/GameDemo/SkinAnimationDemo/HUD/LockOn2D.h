/*!
 * @brief	���b�N�I��
 */
#pragma once

class Enemy;

class LockOn2D : public IGameObject{
public:
	LockOn2D();
	~LockOn2D();
	bool Start() override;
	void Update() override;
	void PostRender(CRenderContext& renderContext) override;
	
	void SetLockOnEnemy(Enemy* enemy)
	{
		m_lockOnEnemy = enemy;
	}
private:
	Enemy*  m_lockOnEnemy = NULL;		//���b�N�I�����Ă���G�B
	CSprite  m_lockOnSprite;	//���b�N�I���X�v���C�g�B
	CTexture m_lockOnTexture;	//���b�N�I���e�N�X�`���B
};