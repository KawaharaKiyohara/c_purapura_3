#pragma once
class Vector2
{
private:
	int m_x;
	int m_y;
public:
	Vector2();
	~Vector2();
	//X�̒l���擾����B
	int GetX();
	//Y�̒l���擾����B
	int GetY();
	//X�̒l��ݒ肷��B
	void SetX(int x);
	//Y�̒l��ݒ肷��B
	void SetY(int y);
};

