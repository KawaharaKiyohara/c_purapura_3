#include "stdafx.h"
#include "OujiStateBase.h"



OujiStateBase::OujiStateBase()
{
}


OujiStateBase::~OujiStateBase()
{
}
/*!
*@brief	���q���Z�b�g
*@param[in]	ouji	���q�B
*/
void OujiStateBase::SetOuji(Ouji* ouji)
{
	this->ouji = ouji;
}
