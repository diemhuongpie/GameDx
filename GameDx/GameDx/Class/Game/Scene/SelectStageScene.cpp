#include "SelectStageScene.h"


CSelectStageScene::CSelectStageScene()
{
}

CSelectStageScene::CSelectStageScene(LPDIRECT3DDEVICE9 device)
{
	this->initScene(device);
}

CSelectStageScene::~CSelectStageScene()
{
	SAFE_RELEASE(m_Background);
	SAFE_RELEASE(m_ButtonMenuSelectStage);
}

bool CSelectStageScene::initScene(LPDIRECT3DDEVICE9 device)
{
	m_Background = new CSprite(backgroundSeletStage);

	return true;
}

void CSelectStageScene::updateScene()
{

}

void CSelectStageScene::renderScene()
{
	m_Background->Render(CCamera::setPositionEntity(vector3d(0.0, 0.0f, 0.5f)), vector2d(1.0f, 1.0f), 0, DRAWCENTER_LEFT_BOTTOM);
}