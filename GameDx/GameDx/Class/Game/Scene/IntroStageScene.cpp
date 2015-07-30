#include "IntroStageScene.h"


CIntroStageScene::CIntroStageScene()
{
	this->initScene();
}


CIntroStageScene::~CIntroStageScene()
{
}

bool CIntroStageScene::initScene()
{
	m_Background	= new CSprite(CInfomationResource::backgroundIntroStage);
	m_Sprite		= new CSprite(CInfomationResource::sprite, 1, 2, 2, 0);
	m_Position		= D3DXVECTOR3(BACKBUFFER_WIDTH / 3, BACKBUFFER_HEIGHT / 4, 0.5f);
	m_direct		= -1;
	return true;
}

void CIntroStageScene::updateScene()
{
	if (m_Position.y < BACKBUFFER_HEIGHT / 3 && m_Position.y >= 0)
	{
		if (m_direct == -1)
			if (m_Position.y == 0)
				m_direct = 1;

		m_Position.y += m_direct;
	}
}

void CIntroStageScene::updateScene(CKeyBoard* keybard)
{
	
}

void CIntroStageScene::renderScene()
{
	m_Background->Render(vector3d(0.0, 0.0f, 0.5f), vector2d(1.0f, 1.0f), 0, DRAWCENTER_LEFT_TOP);

	if (m_Position.y == BACKBUFFER_HEIGHT / 3)
		m_Sprite->Render(0, 2, m_Position, vector2d(2.0f, 2.0f), 0.0f, DRAWCENTER_LEFT_TOP, true, 10);
	else
		m_Sprite->Render(0, 0, m_Position, vector2d(2.0f, 2.0f), 0.0f, DRAWCENTER_LEFT_TOP, true, 20);
}