#pragma once

#include "MonoBase.h"

//“®‚©‚È‚¢ƒ‚ƒm
class Mono_Static : public MonoBase
{
public:
	Mono_Static();
	~Mono_Static();
	//‰Šú‰»B
	void Init( const CVector3& pos, const CQuaternion& rot) ;
	void UpdateSub()
	{

	}
};

