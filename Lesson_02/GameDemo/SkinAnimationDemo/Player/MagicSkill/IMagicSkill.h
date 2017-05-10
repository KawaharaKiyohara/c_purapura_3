/*!
 * @brief	�}�W�b�N�X�L��
 */

#pragma once

class Player;
class IMagicSkill{
public:
	/*!
	 * @brief	�}�W�b�N�X�L���B
	 */
	IMagicSkill(Player* pl) :
		player(pl)
	{
	}
	/*!
	 * @brief	�f�X�g���N�^�B
	 */
	virtual ~IMagicSkill()
	{
	}
	/*!
	* @brief	���@�؂�ւ����Ɉ�x�����Ă΂��֐��B
	*/
	virtual void OnChangeMagic()
	{

	}
	/*!
	 * @brief	���@�������Ɉ�x�����Ă΂��֐��B
	 */
	virtual void OnStartMagic()
	{
	}
	/*!
	 * @brief	���@�I�����Ɉ�x�����Ă΂��֐��B
	 */
	virtual void OnEndMagic()
	{
	}
	/*!
	 * @brief	�X�V�B
	 */
	void Update();	
private:
	/*!
	* @brief	���@�g�p���ɌĂ΂��֐�
	*/
	virtual void OnUsingMagicSkill() = 0;
	/*!
	* @brief	�g�p�����MP���擾�B
	*/
	virtual float GetUseMP() const = 0;
protected:
	Player*		player = nullptr;				//�v���C���[
	bool		isUsingMagicSkill = false;		//���@�g�p���H
};