#include "BulletEnemy.h"
#include "Framework\Camera.h"


CBulletEnemy::CBulletEnemy(float angle)
{
	m_angle = angle;
	this->initEntity();
}


CBulletEnemy::~CBulletEnemy()
{
}

bool CBulletEnemy::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(L"Resource//Image//Game//Sprites//BossCutMan//enemy_bullet_orange.png", 1, 1, 1, 0));
	return	true;
}

bool CBulletEnemy::initEntity()
{
	m_timeDestroy = 0;
	m_Position		= vector3d(100, 100, 0.5);
	m_State			= BULLETSTATE::BULLET_STATE_INVIS;
	m_Velocity		= vector2d(5,5);
	m_Bounding		= new CBox2D(m_Position.x, m_Position.y, 32, 32);
	m_TagNode		= "N";

	this->loadSprite();

	return true;
}

void CBulletEnemy::resetObject()
{}

void CBulletEnemy::updateEntity(float deltaTime)
{
	
	switch (m_State)
	{
	case BULLETSTATE::BULLET_STATE_INVIS:

		m_Position = vector3dMinimum;
		break;
	case BULLETSTATE::BULLET_STATE_SHOW:
		m_timeDestroy += deltaTime;
		m_Position.x += (float)cos(m_angle)*m_Velocity.x*deltaTime / 60;
		m_Position.y += (float)sin(m_angle)*m_Velocity.y*deltaTime / 60;
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
}

void CBulletEnemy::updateEntity(CKeyBoard* device)
{
}

void CBulletEnemy::drawEntity()
{
	if (m_State == BULLETSTATE::BULLET_STATE_SHOW)
		m_listSprite.at(0)->Render(CCamera::setPositionEntity(m_Position), vector2d(1.0,1.0), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
}

vector3d CBulletEnemy::getPosition()
{
	return m_Position;
}

void CBulletEnemy::setState(int newState)
{
	m_State = newState;
}

int CBulletEnemy::getState()
{
	return m_State;
}

