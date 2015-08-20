#include "EnemyEyeRed.h"


CEnemyEyeRed::CEnemyEyeRed()
{
}


CEnemyEyeRed::~CEnemyEyeRed()
{
}

CEnemyEyeRed::CEnemyEyeRed(vector3d m_position, bool m_Horizontal, bool m_isleft, bool m_istop)
{
	this->m_Position = m_position;
	this->m_horizontal = m_Horizontal;
	this->m_isLeft = m_isleft;
	this->m_isTop = m_istop;
	this->initEntity();
}

bool CEnemyEyeRed::initEntity()
{
	m_delayTime = 0;
	m_Velocity.x = 1;
	this->m_Bounding = new CBox2D(m_Position.x, m_Position.y, m_listSprite.at(0)->getFrameInfo().Width, m_listSprite.at(0)->getFrameInfo().Height);
	// LOAD SPRITE
	m_checkState = true;
	this->loadSprite();
	return true;
}

bool CEnemyEyeRed::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(L"Resource//Image//Game//Sprites//BossCutMan//enemy_eye_red.png", 1, 3, 3, 0));
	this->m_listSprite.push_back(new CSprite(L"Resource//Image//Game//Sprites//BossCutMan//boom_burst.png", 1, 4, 4, 0));
	return true;
}

void CEnemyEyeRed::resetObject()
{}

void CEnemyEyeRed::updateEntity(CKeyBoard* keyboard)
{

}

void CEnemyEyeRed::updateEntity(float deltaTime)
{
	this->m_Position.x += this->m_Velocity.x*deltaTime;
	this->m_Position.y += this->m_Velocity.y*deltaTime;
	m_delayTime++;

	if (m_delayTime > 85)
	{
		m_delayTime = 0;
	}
	if (m_horizontal)
	{
		if (m_isLeft)
		{
			m_Velocity.x = 6;
		}
		else
		{
			m_Velocity.x = -6;
		}
	}
	else
	{
		if (m_isTop)
		{
			m_Velocity.y = 6;
		}
		else
		{
			m_Velocity.y = -6;
		}
	}

	if (m_delayTime > 0 && m_delayTime < 30)
	{
		m_checkState = 0;
		m_Velocity.x = 0;
	}

	if (m_delayTime >= 30 && m_delayTime <= 45)
	{
		m_checkState = 1;
	}

	if (m_delayTime > 45)
	{
		m_checkState = 2;
	}
	
}

void CEnemyEyeRed::updateEntity(RECT rectCamera)
{

}

void CEnemyEyeRed::drawEntity()
{
	if (m_checkState == 0)
		this->m_listSprite[m_State]->Render(2, 2, m_Position, vector2d(1.0, 1.0), 0.0f, DRAWCENTER_MIDDLE_MIDDLE, true, 3);
	if (m_checkState == 1)
		this->m_listSprite[m_State]->Render(0, 2, m_Position, vector2d(1.0, 1.0), 0.0f, DRAWCENTER_MIDDLE_MIDDLE, true, 3);
	if (m_checkState == 2)
		this->m_listSprite[m_State]->Render(0, 0, m_Position, vector2d(1.0, 1.0), 0.0f, DRAWCENTER_MIDDLE_MIDDLE, true, 3);

}
