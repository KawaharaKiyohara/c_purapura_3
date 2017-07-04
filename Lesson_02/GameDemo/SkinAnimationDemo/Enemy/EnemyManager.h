/*!
 * @brief	�G�l�~�[�}�l�[�W���B
 */

#pragma once


class Enemy;

/*!
 * @brief	�G����̃}�l�[�W���[�B
 *@details
 * Facade�p�^�[���B
 */
class EnemyManager : public IGameObject{
public:
	EnemyManager();
	~EnemyManager();
	bool Start() override;
	void Update() override;
	void Render(CRenderContext& renderContext) override;
	const std::vector<Enemy*>& GetEnemyList() const
	{
		return enemyList;
	}
	std::vector<Enemy*>& GetEnemyList()
	{
		return enemyList;
	}
	/*!
	* @brief	���^�C���ɏ�Z�����l��ݒ�B
	*@param[in]	mul		�O���[�o�����^�C���ɏ�Z�����l�B���̒l��0.5��ݒ肷��ƃG�l�~�[�̋�����0.5�{���ɂȂ�܂��B
	*/
	void SetFrameDeltaTimeMul(float mul);
private:
	std::vector<Enemy*>		enemyList;		//!<�G�l�~�[�̃��X�g�B
};