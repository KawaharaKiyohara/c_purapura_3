#include "stdafx.h"
#include "Vector2.h"


Vector2::Vector2()
{
	m_x = 0;
	m_y = 0;
}


Vector2::~Vector2()
{
}

int Vector2::GetX()
{
	return m_x;
}
int Vector2::GetY()
{
	return m_y;
}
void Vector2::SetX(int x)
{
	m_x = x;
}
void Vector2::SetY(int y)
{
	m_y = y;
}

