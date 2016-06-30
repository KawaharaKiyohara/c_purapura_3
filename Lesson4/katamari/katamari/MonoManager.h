#pragma once

class MonoBase;

class MonoManager
{
public:
	MonoManager();
	~MonoManager();
	/*!
	*@brief	���m��ǉ��B
	*/
	void AddMono(MonoBase* mono)
	{
		monoList.push_back(mono);
	}
	/*!
	*@brief	���m�̃��X�g���擾�B
	*/
	const std::list<MonoBase*>& GetMonoList() const
	{
		return monoList;
	}
	void Render(CRenderContext& renderContext);
	void Update();
private:
	std::list<MonoBase*> monoList;	//���m�̃��X�g
};

