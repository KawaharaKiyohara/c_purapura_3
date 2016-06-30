#include "stdafx.h"
#include "MonoManager.h"
#include "MonoBase.h"


MonoManager::MonoManager()
{
}


MonoManager::~MonoManager()
{
	for (auto mono : monoList) {
		delete mono;
	}
}
void MonoManager::Render(CRenderContext& renderContext)
{
	for (auto mono : monoList) {
		mono->Render(renderContext);
	}
}
void MonoManager::Update()
{
	for (auto mono : monoList) {
		mono->Update();
	}
}
