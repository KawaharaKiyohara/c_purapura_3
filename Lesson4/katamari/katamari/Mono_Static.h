#pragma once

#include "MonoBase.h"

//�����Ȃ����m
class Mono_Static : public MonoBase
{
public:
	Mono_Static();
	~Mono_Static();
	//�������B
	void Init( const CVector3& pos, const CQuaternion& rot) ;
	void UpdateSub()
	{

	}
};

