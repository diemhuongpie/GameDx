#include "EnemyPartBoomBlue.h"


CEnemyPartBoomBlue::CEnemyPartBoomBlue(int velX)
{
	m_velX = velX;
	this->initEntity();
}


CEnemyPartBoomBlue::~CEnemyPartBoomBlue()
{
}

bool CEnemyPartBoomBlue::initEntity()
{
	m_Position = vector3d(100, 100, 0.5);
	m_State = BULLETSTATE::BULLET_STATE_INVIS;
	m_delayDeath = 0;
	m_delayTime = 0;
	// LOAD SPRITE
	this->loadSprite();
	this->m_Bounding = new CBox2D(m_Position.x, m_Position.y, m_listSprite.at(0)->getFrameInfo().Width, m_listSprite.at(0)->getFrameInfo().Height);
	return true;

}


bool CEnemyPartBoomBlue::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(L"Resource//Image//Game//Sprites//BossBoomMan//enemy_boom_part_blue.png", 1, 1, 1, 0));

	return true;
}


void CEnemyPartBoomBlue::resetObject()
{

}

void CEnemyPartBoomBlue::updateEntity(CKeyBoard *device)
{

}



void CEnemyPartBoomBlue::updateEntity(float deltaTime)
{
	switch (m_State)
	{
	case BULLETSTATE::BULLET_STATE_INVIS:

		m_Position = vector3dMinimum;
		break;
	case BULLETSTATE::BULLET_STATE_SHOW:
		m_delayDeath += deltaTime;
		m_Position.x += m_Velocity.x*deltaTime / 60;
		m_Position.y += m_Velocity.y*deltaTime / 60;
		m_delayTime++;
		if (m_delayTime > 0 && m_delayTime < 20)
		{
			m_Velocity.y = 4;
			m_Velocity.x = m_velX;
		}
		if (m_delayTime > 20 && m_delayTime < 200)
		{
			m_Velocity.x = m_velX;
			m_Velocity.y = -5;
		}
		if (m_velX > 0)
		{
			m_Velocity.x--;
			if (m_Velocity.x < 1)
			{
				m_Velocity.x = 0;
			}
		}
		if (m_velX < 0)
		{
			m_Velocity.x++;
			if (m_Velocity.x > -1)
			{
				m_Velocity.x = 0;
			}
		}
		break;
	case BULLETSTATE::BULLET_STATE_HIT:
		m_State = BULLETSTATE::BULLET_STATE_INVIS;
		break;
	case BULLETSTATE::BULLET_STATE_DIE:
		break;
	default:
		break;
	}	
	if (m_Position.x < CCamera::getInstance()->getBoundingScreen().getX() || m_Position.x >(CCamera::getInstance()->getBoundingScreen().getX() + CCamera::getInstance()->getBoundingScreen().getWidth()))
		m_State = BULLETSTATE::BULLET_STATE_INVIS;

	

	if (m_delayTime > 200)
	{
		m_isDead = true;
		m_delayTime = 0;
	}

	if (m_delayDeath > 2000)
	{
		m_State = BULLETSTATE::BULLET_STATE_INVIS;
		m_delayDeath = 0;
	}
}

void CEnemyPartBoomBlue::updateEntity(RECT rectCamera)
{

}

void CEnemyPartBoomBlue::drawEntity()
{
	if (m_State == BULLETSTATE::BULLET_STATE_SHOW)
		m_listSprite.at(0)->Render(CCamera::setPositionEntity(m_Position), vector2d(1.0, 1.0), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
}

vector3d CEnemyPartBoomBlue::getPosition()
{
	return m_Position;
}

void CEnemyPartBoomBlue::setState(int newState)
{
	m_State = newState;
}

int CEnemyPartBoomBlue::getState()
{
	return m_State;
}

