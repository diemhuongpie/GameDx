#include "IntroStageScene.h"
#include <ctime>
#include <stack>

bool timeForChangingSprite		= true;
static wchar_t* temp			= new wchar_t[wcslen(CUTMAN_STAGE_INFO_STRING) + 1];
static int index				= 1;

CIntroStageScene::CIntroStageScene()
{
	this->initScene();
}


CIntroStageScene::~CIntroStageScene()
{
	SAFE_RELEASE(temp);
}

bool CIntroStageScene::initScene()
{
	m_Background	= new CSprite(CInfomationResource::backgroundIntroStage);
	m_Sprite		= new CSprite(CInfomationResource::sprite, 1, 3, 3, 0);
	m_Position		= D3DXVECTOR3(BACKBUFFER_WIDTH / 3, BACKBUFFER_HEIGHT / 4, 0.5f);
	m_direct		= -1;
	m_RandomPoint	= 0;
	m_isRandomPoint = 0;
	return true;
}

void CIntroStageScene::updateScene()
{
	static double deltaTime = CTimer::getInstance()->getElapedTime();
	if (m_Position.y < BACKBUFFER_HEIGHT / 3 && m_Position.y >= 0)
	{
		if (m_direct == -1)
		if (m_Position.y <= BACKBUFFER_HEIGHT / 40)
			{
					m_direct = 1;
			}

		m_Position.y += deltaTime* 0.12 * m_direct;
	}
	static double countTimeOfIntroStage = 0;
	if (deltaTime >= 0)
		countTimeOfIntroStage += deltaTime;

	if (countTimeOfIntroStage >= 1000 * 64 / 16)
	{
		timeForChangingSprite = false;
		wmemset(temp, L'', wcslen(CUTMAN_STAGE_INFO_STRING)+ 1);
		temp = wcsncpy(temp, CUTMAN_STAGE_INFO_STRING, index);

		if (index <= wcslen(CUTMAN_STAGE_INFO_STRING))
			index++;
		/*else
			if (m_isRandomPoint <= 320)
			{
				srand(time(0));
				m_RandomPoint = std::rand() % 6 + 5;
				m_isRandomPoint++;
			}*/
	}
}

void CIntroStageScene::updateScene(CKeyBoard* keybard)
{
	
}

void CIntroStageScene::renderScene()
{

	m_Background->Render(vector3d(0.0, 0.0f, 0.5f),	vector2d(1.0f, 1.0f), 0, DRAWCENTER_LEFT_TOP);

	static clock_t tiner = 0;
	if (CTimer::getInstance()->getElapedTime() > 0)
			tiner += CTimer::getInstance()->getElapedTime();
	OutputDebugString(L"Siiiiize: ");
	OutputDebugString(_itow(tiner, new WCHAR[1], 10));
	OutputDebugString(L"\n");

	tiner = 00;


	if (m_Position.y >= BACKBUFFER_HEIGHT / 3)
	{
		if (!timeForChangingSprite)
		{
			m_Sprite->Render(1, 1, m_Position,vector2d(2.0f, 2.0f), 0.0f, DRAWCENTER_LEFT_TOP, true, 10);

	//		//Draw information of CUTMAN Stage

	//		CText::getInstace()->Draw(wcsncpy(temp, CUTMAN_STAGE_INFO_STRING, index), vector3d(22 * BACKBUFFER_WIDTH / 40, 6 * BACKBUFFER_HEIGHT / 20, 0.5f), DEFAULT_FONT_COLOR, 16, DT_LEFT, DEFAULT_FONTNAME);
	//		
	//		if (CTimer::getInstance()->getElapedTime() > 0)
	//			tiner += CTimer::getInstance()->getElapedTime();

	//		/*if (tiner >= 1000.0 / 60.0f)*/
	//		OutputDebugString(L"Siiiiize: ");
	//		OutputDebugString(_itow(tiner, new WCHAR[1], 10));
	//		OutputDebugString(L"\n");

	//		tiner = 00;
	//		//Draw Point need to get of this stage
	//		/*if (index > wcslen(CUTMAN_STAGE_INFO_STRING))
	//		{
	//			CText::getInstace()	->Draw(DEFAULT_POINT_STRING,							vector3d(27 * BACKBUFFER_WIDTH / 40, 9 * BACKBUFFER_HEIGHT / 20, 0.5f), DEFAULT_FONT_COLOR, 16, DT_CENTER, DEFAULT_FONTNAME);
	//			if (m_RandomPoint < 10)
	//				CText::getInstace()	->Draw(_itow(m_RandomPoint, new WCHAR[2], 10),		vector3d(23.8 * BACKBUFFER_WIDTH / 40, 9 * BACKBUFFER_HEIGHT / 20, 0.5f), DEFAULT_FONT_COLOR, 16, DT_CENTER, DEFAULT_FONTNAME);
	//			else
	//				CText::getInstace() ->Draw(_itow(m_RandomPoint, new WCHAR[2], 10),		vector3d(23.3 * BACKBUFFER_WIDTH / 40, 9 * BACKBUFFER_HEIGHT / 20, 0.5f), DEFAULT_FONT_COLOR, 16, DT_CENTER, DEFAULT_FONTNAME);
	//		}*/
		}
	//	else
	//	{
	//		m_Sprite->Render(1, 3, m_Position, vector2d(2.0f, 2.0f), 0.0f, DRAWCENTER_LEFT_TOP, true, 10);
	//	}
	}
	else
	{
		m_Sprite->Render(0, 0, m_Position, vector2d(2.0f, 2.0f), 0.0f, DRAWCENTER_LEFT_TOP, true, 20);
	}

	
}