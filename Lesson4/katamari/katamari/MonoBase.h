#pragma once

//���m�̊��N���X�B
class MonoBase
{
public:
	MonoBase();
	virtual ~MonoBase();
	void Update();
	void Render(CRenderContext& renderContext);
	//�������B
	virtual void Init(const CVector3& pos, const CQuaternion& rot)
	{
	}
	//�������܂ꂽ��R�A���ݒ肳���B
	void SetCore(Core* core);
	//�R�A���擾�B
	Core* GetCore()
	{
		return core;
	}
	//���W���擾�B
	CVector3 GetPosition() 
	{
		return position;
	}
private:
	//�T�u�N���X�Ŏ�������X�V�����B
	virtual void UpdateSub() = 0;
protected:
	CVector3	localPosition;		//!<���[�J�����W
	CQuaternion	localRotation;		//!<���[�J����]
	CVector3	position;			//!<���[���h���W�B
	CQuaternion	rotation;			//!<���[���h��]�B
	Core*		core;				//!<�������܂ꂽ��R�A���ݒ肳���B
	CSkinModelData	modelData;		//���f���f�[�^�B
	CSkinModel		model;			//���f���B
	CLight			light;			//!<���C�g
};

