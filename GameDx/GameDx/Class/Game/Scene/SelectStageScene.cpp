#include "SelectStageScene.h"
#include "Game\Utill\Config.h"


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
	m_Background				= new CSprite(CInfomationResource::backgroundSeletStage,	1, 1, 1, 0);
	m_ButtonMenuSelectStage		= new CSprite(CInfomationResource::buttonMenuState,			1, 2, 2, 0);
	m_IndexSelect				= STAGESELECTED::CUTMAN;

	return true;
}

void CSelectStageScene::updateScene()
{
	switch (m_IndexSelect)
	{
	case STAGESELECTED::CUTMAN:
		m_PositionButton = vector3d(147.0f, 55.0f, 0.5f);
		break;
	case STAGESELECTED::GUTSMAN:
		m_PositionButton = vector3d(147.0f, 55.0f, 0.5f);
		break;
	case STAGESELECTED::ICEMAN:
		m_PositionButton = vector3d(147.0f, 55.0f, 0.5f);
		break;
	case STAGESELECTED::BOMBMAN:
		m_PositionButton = vector3d(147.0f, 55.0f, 0.5f);
		break;
	case STAGESELECTED::FIREMAN:
		m_PositionButton = vector3d(147.0f, 55.0f, 0.5f);
		break;
	case STAGESELECTED::ELECMAN:
		m_PositionButton = vector3d(147.0f, 55.0f, 0.5f);
		break;
	default:
		break;
	}
}

void CSelectStageScene::updateScene(CKeyBoard* device)
{
	if (device->KeyPress(DIK_LEFT))
		m_IndexSelect--;
	if (device->KeyPress(DIK_RIGHT))
		m_IndexSelect++;

	if (m_IndexSelect < 0)	m_IndexSelect	=	5;
	if (m_IndexSelect > 5)	m_IndexSelect	=	0;




}

void CSelectStageScene::renderScene()
{
	//m_Background			->Render((vector3d(0.0, 0.0f, 0.5f)), vector2d(1.0f, 1.0f), 0, DRAWCENTER_LEFT_TOP, true, FPS);
	m_ButtonMenuSelectStage	->Render(m_PositionButton,			vector2d(1.0f, 1.0f), 0, DRAWCENTER_LEFT_TOP, false, 60);
}