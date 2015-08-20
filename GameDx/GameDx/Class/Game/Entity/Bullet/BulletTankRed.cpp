#include "BulletTankRed.h"


CBulletTankRed::CBulletTankRed(float changeAngle)
{
	m_changeAngle = changeAngle;
	this->initEntity();
}


CBulletTankRed::~CBulletTankRed()
{
}

bool CBulletTankRed::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(L"Resource//Image//Game//Sprites//BossCutMan//enemy_bullet_orange.png", 1, 1, 1, 0));
	return	true;
}

bool CBulletTankRed::initEntity()
{
	m_timeDestroy = 0;
	m_Position = vector3d(100, 100, 0.5);
	m_State = BULLETSTATE::BULLET_STATE_INVIS;
	m_Velocity = vector2d(10, 10);
	m_Bounding = new CBox2D(m_Position.x, m_Position.y, 32, 32);
	m_TagNode = "N";
	

	this->loadSprite();

	return true;
}

void CBulletTankRed::updateEntity(float deltaTime)
{
	switch (m_changeAngle)
	{
	case 0:
		m_angle = 5 * PI / 6;
		break;
	case 1:
		m_angle = PI;
		break;
	case 2:
		m_angle = 7 * PI / 6;
		break;
	case 3:
		m_angle = 4 * PI / 3;
		break;
	}

	switch (m_State)
	{
	case BULLETSTATE::BULLET_STATE_INVIS:
		m_Position = vector3dMinimum;
		break;
	case BULLETSTATE::BULLET_STATE_SHOW:
		if (deltaTime > 0)
		{
			m_timeDestroy += deltaTime;
			m_Position.x += (float)cos(m_angle)*m_Velocity.x*deltaTime / 60;
			m_Position.y += (float)sin(m_angle)*m_Velocity.y*deltaTime / 60;
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

	/*if (m_Position.x < CCamera::getInstance()->getBoundingScreen().getX() || m_Position.x >(CCamera::getInstance()->getBoundingScreen().getX() + CCamera::getInstance()->getBoundingScreen().getWidth())
	)
	m_State = BULLETSTATE::BULLET_STATE_INVIS;*/
	if (m_timeDestroy > 2000)
	{
		m_State = BULLETSTATE::BULLET_STATE_INVIS;
		m_timeDestroy = 0;
	}
	if (m_changeAngle > 3)
	{
		m_changeAngle = 0;
	}
}

void CBulletTankRed::updateEntity(CKeyBoard* device)
{
}

void CBulletTankRed::drawEntity()
{
	if (m_State == BULLETSTATE::BULLET_STATE_SHOW)
		m_listSprite.at(0)->Render(CCamera::setPositionEntity(m_Position), vector2d(1.0, 1.0), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
}

vector3d CBulletTankRed::getPosition()
{
	return m_Position;
}

void CBulletTankRed::setState(int newState)
{
	m_State = newState;
}

int CBulletTankRed::getState()
{
	return m_State;
}

