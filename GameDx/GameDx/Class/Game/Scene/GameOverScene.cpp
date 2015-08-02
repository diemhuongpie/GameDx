#include "GameOverScene.h"


CGameOverScene::CGameOverScene()
{
	this->initScene();
}


CGameOverScene::~CGameOverScene()
{
}

bool CGameOverScene::initScene()
{
	m_Background = new CSprite(CInfomationResource::backgroundIntroStage);

	return true;

}

void CGameOverScene::updateScene(double deltaTime)
{

}

void CGameOverScene::updateScene(CKeyBoard*)
{

}

void CGameOverScene::renderScene()
{
	m_Background->Render(vector3d(0.0, 0.0f, 0.5f), vector2d(1.0f, 1.0f), 0, DRAWCENTER_LEFT_TOP);
}
