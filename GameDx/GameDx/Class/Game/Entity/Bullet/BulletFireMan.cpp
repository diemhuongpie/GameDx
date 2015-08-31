#include "BulletFireMan.h"


CBulletFireMan::CBulletFireMan()
{
	this->initEntity();
}


CBulletFireMan::~CBulletFireMan()
{
}

bool CBulletFireMan::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(L"Resource//Image//Game//Sprites//fireman//firebullet.png", 1, 5, 5, 0));
	return	true;
}

bool CBulletFireMan::initEntity()
{
	m_Position = vector3d(100, 100, 0.5);
	m_State = BULLETSTATE::BULLET_STATE_INVIS;
	m_Velocity = vector2d(10, 10);
	m_Bounding = new CBox2D(m_Position.x, m_Position.y, 32, 32);
	m_TagNode = "N";

	this->loadSprite();

	return true;
}

void CBulletFireMan::resetObject()
{}

void CBulletFireMan::updateEntity(float deltaTime)
{

	switch (m_State)
	{
	case BULLETSTATE::BULLET_STATE_INVIS:

		m_Position = vector3dMinimum;
		break;
	case BULLETSTATE::BULLET_STATE_SHOW:
		if (deltaTime > 0)
			m_Position.x += m_Velocity.x*deltaTime/60;
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
}

void CBulletFireMan::updateEntity(CKeyBoard* device)
{
}

void CBulletFireMan::updateEntity(CBaseEntity* device)
{
}

void CBulletFireMan::drawEntity()
{
	if (m_State == BULLETSTATE::BULLET_STATE_SHOW)
		m_listSprite.at(0)->Render(0,2,CCamera::setPositionEntity(m_Position), vector2d(SIGN(m_Velocity.x)*-2.0, SIGN(m_Velocity.y)*2.0), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
}

vector3d CBulletFireMan::getPosition()
{

	return m_Position;
}

void CBulletFireMan::setState(int newState)
{
	m_State = newState;
}

int	CBulletFireMan::getState()
{
	return m_State;
}


