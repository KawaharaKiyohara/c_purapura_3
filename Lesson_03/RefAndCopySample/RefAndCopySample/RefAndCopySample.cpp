// RefAndCopySample.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"


class CVector3 {
public:
	float x;
	float y;
	float z;
	CVector3() {}
	CVector3(float _x, float _y, float _z) :
		x(_x),
		y(_y),
		z(_z)
	{
	}

};
//�v���C���[�N���X�B
class Player {
	CVector3 m_pos;
public:
	
	//���W���擾�B
	//�߂�l�͒l�R�s�[�B
	//�l�R�s�[�Ȃ̂ŁA�߂�l��ύX���Ă��l�͕ς��Ȃ��B
	CVector3 GetPosition()
	{
		return m_pos;
	}
	//m_pos�̎Q�Ƃ��擾�B
	CVector3& GetPositionRef()
	{
		return m_pos;
	}
	//���W��ݒ�
	//�����͒l�n���B
	void SetPosition(CVector3 pos)
	{
		m_pos = pos;
	}
	//���W��\������B
	void PrintPosition()
	{
		printf("m_pox.x = %f\n", m_pos.x);
		printf("m_pox.y = %f\n", m_pos.y);
		printf("m_pox.z = %f\n", m_pos.z);
	}
};
//FunctionA�̈����͒l�n���Ȃ̂Œ���t�̒l��ύX���Ă�
//�Ăяo�����Ƃɉe���͗^���Ȃ��B
void FunctionA(CVector3 t) 
{
	t.x += 5.0f;
	t.y += 5.0f;
	t.z += 5.0f;
}
//FunctionB�̈����͎Q�Ɠn���Ȃ̂Œ���t�̒l��ύX������
//�Ăяo�������ς��B
void FunctionB(CVector3& t)
{
	t.x += 5.0f;
	t.y += 5.0f;
	t.z += 5.0f;
}
//FunctionC�̈����̓|�C���^�Ȃ̂ŁApt�̎w���Ă�����ύX������
//�Ăяo�����̒l���ς��B
void FunctionC(CVector3* pt) 
{
	pt->x += 5.0f;
	pt->y += 5.0f;
	pt->z += 5.0f;
}
int main()
{
	CVector3 t0;
	t0.x = 10.0f;
	t0.y = 20.0f;
	t0.z = 30.0f;

	printf("t0.x = %f\n", t0.x);
	printf("t0.y = %f\n", t0.y);
	printf("t0.z = %f\n", t0.z);
	//����͒l�̃R�s�[�B
	//t1��t0�̒l���R�s�[����邪�At1��t0�͕ʕ��B
	CVector3 t1 = t0;
	t1.x += 5.0f;
	t1.y += 5.0f;
	t1.z += 5.0f;
	//�ʕ��Ȃ̂ŁAt1�̒l��ύX���Ă�t0�̒l�͕ς��Ȃ��B
	printf("�l�̃R�s�[\n");
	printf("t0.x = %f\n", t0.x);
	printf("t0.y = %f\n", t0.y);
	printf("t0.z = %f\n", t0.z);

	//����͎Q�ƁBt2��t0���Q�Ƃ��Ă���B
	//�Ȃ̂�t2��t0�͓������́B
	CVector3& t2 = t0;
	t2.x += 5.0f;
	t2.y += 5.0f;
	t2.z += 5.0f;
	//t2��t0�͓������̂ɂȂ�̂ŁAt2��ύX�����t0�̒l���ς��B
	printf("�Q��\n");
	printf("t0.x = %f\n", t0.x);
	printf("t0.y = %f\n", t0.y);
	printf("t0.z = %f\n", t0.z);

	//�|�C���^�ƎQ�Ƃ͂قƂ�Ǔ����B
	CVector3* pt = &t0;
	pt->x += 5.0f;
	pt->y += 5.0f;
	pt->z += 5.0f;
	//pt�ɂ�t0�̃A�h���X���L�^����Ă���̂ŁAt0�̒l���ς��B
	printf("�l�̃R�s�[\n");
	printf("t0.x = %f\n", t0.x);
	printf("t0.y = %f\n", t0.y);
	printf("t0.z = %f\n", t0.z);


	//FunctionA�̈����͒l�n���B
	FunctionA(t0);
	printf("FunctionA\n");
	printf("t0.x = %f\n", t0.x);
	printf("t0.y = %f\n", t0.y);
	printf("t0.z = %f\n", t0.z);

	//FunctionB�̈����͎Q�Ɠn���B
	FunctionB(t0);
	printf("FunctionB\n");
	printf("t0.x = %f\n", t0.x);
	printf("t0.y = %f\n", t0.y);
	printf("t0.z = %f\n", t0.z);

	//FunctionC�̈����̓|�C���^�B
	FunctionC(&t0);
	printf("FunctionC\n");
	printf("t0.x = %f\n", t0.x);
	printf("t0.y = %f\n", t0.y);
	printf("t0.z = %f\n", t0.z);

	//�N���X�̃����o�ϐ��Œ��ׂĂ݂�B
	Player player;
	player.SetPosition({10.0f, 20.0f, 30.0f});
	//�v���C���[�̍��W���擾�B
	CVector3 pos = player.GetPosition();
	pos.x += 5.0f;
	pos.y += 5.0f;
	pos.z += 5.0f;
	//GetPosition�֐��͒l��Ԃ��Ă���̂ŁApos�̒l��ύX���Ă��匳�͕ς��Ȃ��B
	printf("GetPosition\n");
	player.PrintPosition();

	//player��m_pos�̎Q�Ƃ��擾����B
	CVector3& posRef = player.GetPositionRef();
	posRef.x += 5.0f;
	posRef.y += 5.0f;
	posRef.z += 5.0f;
	//�Q�Ƃ̒l��ύX���Ă���̂ŁA�匳���ς���Ă���B
	printf("GetPositionRef\n");
	player.PrintPosition();

    return 0;
}

