/*!
 * @brief	�C���Q�[�����̃��C�g�B
 */

#pragma once


/*!
 * @brief	�C���Q�[�����̃��C�g�B
 */
class InGameLight : public IGameObject{
public:
	InGameLight();
	~InGameLight();
	bool Start() override;
	void Update() override; 
	/*!
	 * @brief	�f�t�H���g���C�g�̎擾�B
	 */
	CLight& GetDefaultLight()
	{
		return defaultLight;
	}
private:
	CLight	defaultLight;		//!<�f�t�H���g���C�g�B
};