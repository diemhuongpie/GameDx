#include "IntroStageScene.h"
#include <ctime>
#include <stack>
#include "Game\Scene\SelectStageScene.h"


CIntroStageScene::CIntroStageScene()
{
	this->initScene();
}


CIntroStageScene::~CIntroStageScene()
{
	SAFE_RELEASE(m_Temp);
	m_SpriteList.clear();
}

bool CIntroStageScene::initScene()
{
	m_Tag						= "IntroStageScene";
	m_Direct					= DIRECT_COORDINATE(DIRECTION::DIRECTION_UP);
	m_RandomPoint				=  0;
	m_isRandomPoint				=  0;
	m_Index						=  0;
	m_countTimeForText			=  0;
	m_LoadTextTime				= false;
	m_TimeForChangingSprite		= true;

	m_SpriteList.push_back(new CSprite(CInfomationResource::backgroundIntroStage));
	m_SpriteList.push_back(new CSprite(CInfomationResource::spriteCutManIntro, 1, 3, 3, 0));
	m_SpriteList.push_back(new CSprite(CInfomationResource::spriteBombManIntro, 1, 8, 8, 0));
	m_SpriteList.push_back(new CSprite(CInfomationResource::spriteBombManBallIntro));



	if (CSelectStageScene::m_IndexSelect == STAGESELECTED::CUTMAN)
	{
		m_Temp					= new wchar_t[wcslen(CUTMAN_STAGE_INFO_STRING) + 1];
		m_Position				= D3DXVECTOR3(BACKBUFFER_WIDTH / 3, BACKBUFFER_HEIGHT / 4, 0.5f);

	}
	if (CSelectStageScene::m_IndexSelect == STAGESELECTED::BOMBMAN)
	{
		m_Temp					= new wchar_t[wcslen(BOMBMAN_STAGE_INFO_STRING) + 1];
		m_Position				= D3DXVECTOR3(2 * BACKBUFFER_WIDTH / 3, 3 * BACKBUFFER_HEIGHT / 4, 0.5f);
	}
	if (CSelectStageScene::m_IndexSelect == STAGESELECTED::FIREMAN)
		m_Temp					= new wchar_t[wcslen(FIREMAN_STAGE_INFO_STRING) + 1];

	return true;
}

void CIntroStageScene::updateScene(double deltaTime)
{
	if (CSelectStageScene::m_IndexSelect == STAGESELECTED::CUTMAN)
	{
		if (m_Position.y < BACKBUFFER_HEIGHT / 3 && m_Position.y >= 0)
		{
			if (m_Position.y <= BACKBUFFER_HEIGHT / 40)
					m_Direct = DIRECT_COORDINATE(DIRECTION::DIRECTION_DOWN);

			m_Position.y += deltaTime* 0.12 * m_Direct;
		}
	}

	if (CSelectStageScene::m_IndexSelect == STAGESELECTED::BOMBMAN)
	{
		if (m_Position.x > BACKBUFFER_WIDTH / 4)
		{
			m_Position.x -= deltaTime*0.07;

			if (m_Position.y <= BACKBUFFER_HEIGHT / 5)
				m_Direct = DIRECT_COORDINATE(DIRECTION::DIRECTION_DOWN);

			m_Position.y += deltaTime* 0.11 *m_Direct;
			
		}
	}


	static double countTimeOfIntroStage = 0;
	if (deltaTime >= 0)
	{
		countTimeOfIntroStage	+= deltaTime;
		m_countTimeForText		+= deltaTime;
	}


	if (countTimeOfIntroStage	>= 1000 * 64 / 16)
	{
		m_TimeForChangingSprite = false;
		if (CSelectStageScene::m_IndexSelect == STAGESELECTED::CUTMAN)
		{
			wmemset(m_Temp, L'', wcslen(CUTMAN_STAGE_INFO_STRING) + 1);
			wcsncpy(m_Temp, CUTMAN_STAGE_INFO_STRING, m_Index);
		}
		if (CSelectStageScene::m_IndexSelect == STAGESELECTED::BOMBMAN)
		{
			wmemset(m_Temp, L'', wcslen(BOMBMAN_STAGE_INFO_STRING) + 1);
			wcsncpy(m_Temp, BOMBMAN_STAGE_INFO_STRING, m_Index);
		}
		if (CSelectStageScene::m_IndexSelect == STAGESELECTED::FIREMAN)
		{
			wmemset(m_Temp, L'', wcslen(FIREMAN_STAGE_INFO_STRING) + 1);
			wcsncpy(m_Temp, FIREMAN_STAGE_INFO_STRING, m_Index);
		}

		if (m_countTimeForText >= 1000 * 2 / 16)
		{
			m_LoadTextTime = true;

			if (m_Index <= wcslen(BOMBMAN_STAGE_INFO_STRING))
			{
				m_Index++;
			}

			m_countTimeForText = 0;
		}

		if (m_Index > wcslen(BOMBMAN_STAGE_INFO_STRING))
			if (m_isRandomPoint <= 15)
			{
				m_RandomPoint++;
				m_isRandomPoint++;
			}
			if (m_isRandomPoint == 16)
			{
				srand(time(0));
				m_RandomPoint = std::rand() % 6 + 5;
				m_isRandomPoint++;
			}
			if (m_isRandomPoint > 16 && countTimeOfIntroStage >= 10 * 1000)
			{
				countTimeOfIntroStage	= 0;
				m_isRandomPoint			= 0;
				m_Index					= 1;
				m_TimeForChangingSprite = true;
				CSceneManager::getInstance()->getScene().pop_back();
				CSceneManager::getInstance()->getScene().push_back(new CPlayScene());
			}
	}
}

void CIntroStageScene::updateScene(CKeyBoard* keybard)
{
	
}

void CIntroStageScene::renderScene()
{
	static clock_t	tiner	= 0;
	if (CTimer::getInstance()->getElapedTime() > 0)
			tiner += CTimer::getInstance()->getElapedTime();

	OutputDebugString(L"Siiiiize: ");
	OutputDebugString(_itow(CTimer::getInstance()->getElapedTime(), new WCHAR[1], 10));
	OutputDebugString(L"\n");

	tiner = 00;

	m_SpriteList.at(0)->Render(vector3d(0.0, 0.0f, 0.5f),	vector2d(1.0f, 1.0f), 0, DRAWCENTER_LEFT_TOP);

	if (CSelectStageScene::m_IndexSelect == STAGESELECTED::CUTMAN)
	{
		if (m_Position.y >= BACKBUFFER_HEIGHT / 3)
		{
			if (!m_TimeForChangingSprite)
			{
				m_SpriteList.at(1)->Render(1, 1, m_Position,vector2d(1.0f, 1.0f), 0.0f, DRAWCENTER_LEFT_TOP, true, 10);

				if (m_LoadTextTime)
				{
					//Draw information of Stage

					CText::getInstace()->Draw(m_Temp, vector3d(22 * BACKBUFFER_WIDTH / 40, 6 * BACKBUFFER_HEIGHT / 20, 0.5f), DEFAULT_FONT_COLOR, 11, DT_LEFT, DEFAULT_FONTNAME);
				}

				//Draw Point need to get of this stage
				if (m_Index > wcslen(CUTMAN_STAGE_INFO_STRING))
				{
					CText::getInstace()->Draw(DEFAULT_POINT_STRING, vector3d(27 * BACKBUFFER_WIDTH / 40, 10 * BACKBUFFER_HEIGHT / 20, 0.5f), DEFAULT_FONT_COLOR, 11, DT_CENTER, DEFAULT_FONTNAME);
					if (m_RandomPoint < 10)
						CText::getInstace()->Draw(_itow(m_RandomPoint, new WCHAR[2], 10), vector3d(22 * BACKBUFFER_WIDTH / 40, 10 * BACKBUFFER_HEIGHT / 20, 0.5f), DEFAULT_FONT_COLOR, 11, DT_CENTER, DEFAULT_FONTNAME);
					else
						CText::getInstace()->Draw(_itow(m_RandomPoint, new WCHAR[2], 10), vector3d(21.5 * BACKBUFFER_WIDTH / 40, 10 * BACKBUFFER_HEIGHT / 20, 0.5f), DEFAULT_FONT_COLOR, 11, DT_CENTER, DEFAULT_FONTNAME);
				}
			}

			else
				m_SpriteList.at(1)->Render(1, 3, m_Position, vector2d(1.0f, 1.0f), 0.0f, DRAWCENTER_LEFT_TOP, true, 10);
				
		}
		else
			m_SpriteList.at(1)->Render(0, 0, m_Position, vector2d(1.0f, 1.0f), 0.0f, DRAWCENTER_LEFT_TOP, true, 20);
	}


	if (CSelectStageScene::m_IndexSelect == STAGESELECTED::BOMBMAN)
	{
		if (m_Position.x <= BACKBUFFER_WIDTH / 3)
		{
			if (!m_TimeForChangingSprite)
			{
				m_SpriteList.at(2)->Render(1, 1, m_Position, vector2d(1.0f, 1.0f), (0.0f), DRAWCENTER_LEFT_TOP, true, 10);
				m_SpriteList.at(3)->Render(vector3d(m_Position.x, m_Position.y + 10, 0.5f), vector2d(1.0f, 1.0f), (0.0f), DRAWCENTER_MIDDLE_MIDDLE, true, 10);
				if (m_LoadTextTime)
				{
					//Draw information of Stage

					CText::getInstace()->Draw(m_Temp, vector3d(22 * BACKBUFFER_WIDTH / 40, 6 * BACKBUFFER_HEIGHT / 20, 0.5f), DEFAULT_FONT_COLOR, 11, DT_LEFT, DEFAULT_FONTNAME);
				}

				//Draw Point need to get of this stage
				if (m_Index > wcslen(BOMBMAN_STAGE_INFO_STRING))
				{
					CText::getInstace()->Draw(DEFAULT_POINT_STRING, vector3d(27 * BACKBUFFER_WIDTH / 40, 10 * BACKBUFFER_HEIGHT / 20, 0.5f), DEFAULT_FONT_COLOR, 11, DT_CENTER, DEFAULT_FONTNAME);
					if (m_RandomPoint < 10)
						CText::getInstace()->Draw(_itow(m_RandomPoint, new WCHAR[2], 10), vector3d(22 * BACKBUFFER_WIDTH / 40, 10 * BACKBUFFER_HEIGHT / 20, 0.5f), DEFAULT_FONT_COLOR, 11, DT_CENTER, DEFAULT_FONTNAME);
					else
						CText::getInstace()->Draw(_itow(m_RandomPoint, new WCHAR[2], 10), vector3d(21.5 * BACKBUFFER_WIDTH / 40, 10 * BACKBUFFER_HEIGHT / 20, 0.5f), DEFAULT_FONT_COLOR, 11, DT_CENTER, DEFAULT_FONTNAME);
				}
			}
			else
			{
				m_SpriteList.at(2)->Render(0, 0, m_Position, vector2d(1.0f, 1.0f), 0.0f, DRAWCENTER_LEFT_TOP, true, 10);
			}
		}
		else
			m_SpriteList.at(2)->Render(3, 3, m_Position, vector2d(1.0f, 1.0f), 0.0f, DRAWCENTER_LEFT_TOP, true, 10);
	}
	

}