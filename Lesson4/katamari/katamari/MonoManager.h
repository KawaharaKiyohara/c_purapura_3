#pragma once

class MonoBase;

class MonoManager
{
public:
	MonoManager();
	~MonoManager();
	/*!
	*@brief	モノを追加。
	*/
	void AddMono(MonoBase* mono)
	{
		monoList.push_back(mono);
	}
	/*!
	*@brief	モノのリストを取得。
	*/
	const std::list<MonoBase*>& GetMonoList() const
	{
		return monoList;
	}
	void Render(CRenderContext& renderContext);
	void Update();
private:
	std::list<MonoBase*> monoList;	//モノのリスト
};

