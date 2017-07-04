// RefAndCopySample.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
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
//プレイヤークラス。
class Player {
	CVector3 m_pos;
public:
	
	//座標を取得。
	//戻り値は値コピー。
	//値コピーなので、戻り値を変更しても値は変わらない。
	CVector3 GetPosition()
	{
		return m_pos;
	}
	//m_posの参照を取得。
	CVector3& GetPositionRef()
	{
		return m_pos;
	}
	//座標を設定
	//引数は値渡し。
	void SetPosition(CVector3 pos)
	{
		m_pos = pos;
	}
	//座標を表示する。
	void PrintPosition()
	{
		printf("m_pox.x = %f\n", m_pos.x);
		printf("m_pox.y = %f\n", m_pos.y);
		printf("m_pox.z = %f\n", m_pos.z);
	}
};
//FunctionAの引数は値渡しなので中でtの値を変更しても
//呼び出しもとに影響は与えない。
void FunctionA(CVector3 t) 
{
	t.x += 5.0f;
	t.y += 5.0f;
	t.z += 5.0f;
}
//FunctionBの引数は参照渡しなので中でtの値を変更したら
//呼び出し元も変わる。
void FunctionB(CVector3& t)
{
	t.x += 5.0f;
	t.y += 5.0f;
	t.z += 5.0f;
}
//FunctionCの引数はポインタなので、ptの指している先を変更したら
//呼び出し元の値も変わる。
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
	//これは値のコピー。
	//t1にt0の値がコピーされるが、t1とt0は別物。
	CVector3 t1 = t0;
	t1.x += 5.0f;
	t1.y += 5.0f;
	t1.z += 5.0f;
	//別物なので、t1の値を変更してもt0の値は変わらない。
	printf("値のコピー\n");
	printf("t0.x = %f\n", t0.x);
	printf("t0.y = %f\n", t0.y);
	printf("t0.z = %f\n", t0.z);

	//これは参照。t2はt0を参照している。
	//なのでt2とt0は同じもの。
	CVector3& t2 = t0;
	t2.x += 5.0f;
	t2.y += 5.0f;
	t2.z += 5.0f;
	//t2とt0は同じものになるので、t2を変更するとt0の値も変わる。
	printf("参照\n");
	printf("t0.x = %f\n", t0.x);
	printf("t0.y = %f\n", t0.y);
	printf("t0.z = %f\n", t0.z);

	//ポインタと参照はほとんど同じ。
	CVector3* pt = &t0;
	pt->x += 5.0f;
	pt->y += 5.0f;
	pt->z += 5.0f;
	//ptにはt0のアドレスが記録されているので、t0の値が変わる。
	printf("値のコピー\n");
	printf("t0.x = %f\n", t0.x);
	printf("t0.y = %f\n", t0.y);
	printf("t0.z = %f\n", t0.z);


	//FunctionAの引数は値渡し。
	FunctionA(t0);
	printf("FunctionA\n");
	printf("t0.x = %f\n", t0.x);
	printf("t0.y = %f\n", t0.y);
	printf("t0.z = %f\n", t0.z);

	//FunctionBの引数は参照渡し。
	FunctionB(t0);
	printf("FunctionB\n");
	printf("t0.x = %f\n", t0.x);
	printf("t0.y = %f\n", t0.y);
	printf("t0.z = %f\n", t0.z);

	//FunctionCの引数はポインタ。
	FunctionC(&t0);
	printf("FunctionC\n");
	printf("t0.x = %f\n", t0.x);
	printf("t0.y = %f\n", t0.y);
	printf("t0.z = %f\n", t0.z);

	//クラスのメンバ変数で調べてみる。
	Player player;
	player.SetPosition({10.0f, 20.0f, 30.0f});
	//プレイヤーの座標を取得。
	CVector3 pos = player.GetPosition();
	pos.x += 5.0f;
	pos.y += 5.0f;
	pos.z += 5.0f;
	//GetPosition関数は値を返しているので、posの値を変更しても大元は変わらない。
	printf("GetPosition\n");
	player.PrintPosition();

	//playerのm_posの参照を取得する。
	CVector3& posRef = player.GetPositionRef();
	posRef.x += 5.0f;
	posRef.y += 5.0f;
	posRef.z += 5.0f;
	//参照の値を変更しているので、大元も変わっている。
	printf("GetPositionRef\n");
	player.PrintPosition();

    return 0;
}

