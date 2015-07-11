#include "MenuScene.h"

CMenuScene::CMenuScene()
{
}

CMenuScene::CMenuScene(LPDIRECT3DDEVICE9 device)
{

	this->initScene(device);
}

CMenuScene::~CMenuScene()
{
}

bool CMenuScene::initScene(LPDIRECT3DDEVICE9 device)
{
	m_Background	= new CSprite(L"Resource//Image//bb.png");

	m_Pencil24		= new CText(device);

	return true;
}

void CMenuScene::updateScene()
{
}

void CMenuScene::renderScene()
{
	m_Background->Render(vector3d(0.0, 0.0f, 0.5f), vector2d(1.0f, 1.0f), 0, 1);
	m_Background->Render(vector3d(100.0, 200.0f, 0.5f), vector2d(1.0f, 1.0f), 0, 1);
	m_Pencil24->Draw(L"0 - 0", { 0, 0, 150, 250 }, 1, D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));

	m_Pencil24->Draw(L"520 - 0", { 500, 0, 30, 20 }, 1, D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));

}

