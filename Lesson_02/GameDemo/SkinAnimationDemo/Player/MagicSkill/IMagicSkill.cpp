/*!
 * @brief	�}�W�b�N�X�L��
 */

#include "stdafx.h"
#include "Player/MagicSkill/IMagicSkill.h"
#include "Player/Player.h"


/*!
 * @brief	�X�V�B
 */
void IMagicSkill::Update()
{
	if (Pad(0).IsPress(enButtonRB2)) {
		//MP�̎c�ʂ����Ė��@���g���邩���ׂ�B
		float useMp = GetUseMP() * GameTime().GetFrameDeltaTime();
		if (player->GetMP() - useMp >= 0.0f) {
			if (!isUsingMagicSkill) {
				//���@�g�p�J�n�B
				OnStartMagic();
				isUsingMagicSkill = true;
			}
			OnUsingMagicSkill();
		}
		else {
			//���@�g���Ȃ������B
			OnEndMagic();
			isUsingMagicSkill = false;
		}
		player->UseMagicPoint(useMp);
	}
	else if (isUsingMagicSkill) {
		//���@�g�p�I���B
		OnEndMagic();
		isUsingMagicSkill = false;
	}
}
