#pragma once

#include "MonoBase.h"

//動かないモノ
class Mono_Static : public MonoBase
{
public:
	Mono_Static();
	~Mono_Static();
	//初期化。
	void Init( const CVector3& pos, const CQuaternion& rot) ;
	void UpdateSub()
	{

	}
};

