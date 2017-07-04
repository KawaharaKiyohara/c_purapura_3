#pragma once

class Ouji;
class MonoBase;

//�R�A
class Core
{
public:
	Core();
	~Core();
	/*!
	*@brief	������
	*/
	void Init();
	/*!
	*@brief	�X�V
	*/
	void Update();
	/*!
	*@brief	�`�揈���B
	*@param[in,out]	renderContext	�����_�����O�R���e�L�X�g
	*/
	void Render(CRenderContext& renderContext);
	/*!
	*@brief	���q��ݒ�
	*@param[in]	ouji	���q
	*/
	void SetOuji(Ouji* ouji)
	{
		this->ouji = ouji;
	}
	
	/*!
	*@brief	Y������̉�]���擾
	*@param[in]	ouji	���q
	*/
	const CQuaternion& GetRotationY()
	{
		return rotationY;
	}
	/*!
	*@brief	��]���擾
	*@param[in]	ouji	���q
	*/
	const CQuaternion& GetRotation()
	{
		return rotation;
	}
	
	
	/*!
	*@brief	X������̉�]�����O�������[���h�s����擾�B
	*/
	const CMatrix& GetWorldMatrixIgnoreXRotation() const
	{
		return worldMatrixIgnoreXRotation;
	}
	/*!
	*@brief	X������̉�]�����O�������[���h�s����擾�B
	*/
	const CMatrix& GetWorldMatrix() const
	{
		return model.GetWorldMatrix();
	}
	/*!
	*@brief	�X�P�[�����擾�B
	*/
	const CVector3& GetScale() const
	{
		return scale;
	}
	CVector3 position;				//!<�R�A�̍��W�B
	CQuaternion rotationY;			//!<Y������̃R�A�̉�]�B
	CQuaternion rotationX;			//!<X������̃R�A�̉�]�B
private:
	
	CQuaternion	rotation;			//!<��]
	Ouji* ouji;
	CSkinModelData	modelData;		//���f���f�[�^�B
	CSkinModel		model;			//���f���B
	CLight			light;			//!<���C�g
	CVector3		scale;			//!<�X�P�[���B
	CMatrix			worldMatrixIgnoreXRotation;	//!<X������̉�]�����O�������[���h�s��B
	CVector3		targetScale;	//!<�g��ڕW�B
	std::list<MonoBase*>	makikomiMonoList;	//!<�������񂾃��m�̃��X�g�B
};

