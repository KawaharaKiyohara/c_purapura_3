#include "stdafx.h"
#include "OujiState_Run.h"



OujiState_Run::OujiState_Run()
{
}


OujiState_Run::~OujiState_Run()
{
}

/*!
*@brief	XVB
*/
void OujiState_Run::Update()
{
	if (KeyInput().IsUpPress()) {
		
	}
	else if (KeyInput().IsDownPress()) {
		
	}
	else {
		ouji->ChangeState(eState_Stand);
	}
}