#include "stdafx.h"
#include "OujiStateBase.h"



OujiStateBase::OujiStateBase()
{
}


OujiStateBase::~OujiStateBase()
{
}
/*!
*@brief	王子をセット
*@param[in]	ouji	王子。
*/
void OujiStateBase::SetOuji(Ouji* ouji)
{
	this->ouji = ouji;
}
