#pragma once
class Vector2
{
private:
	int m_x;
	int m_y;
public:
	Vector2();
	~Vector2();
	//Xの値を取得する。
	int GetX();
	//Yの値を取得する。
	int GetY();
	//Xの値を設定する。
	void SetX(int x);
	//Yの値を設定する。
	void SetY(int y);
};

