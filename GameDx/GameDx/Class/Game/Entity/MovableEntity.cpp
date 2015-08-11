#include "MovableEntity.h"


CMovable::CMovable()
{
	this->initEntity();
}


CMovable::~CMovable()
{
}

bool CMovable::initEntity()
{
	m_isMovable = true;
	return true;
}

vector3d	CMovable::getPosition()
{
	return m_Position;
}

RECT		CMovable::getBounding()
{
	RECT result = { 0, 0, 0, 0 };
	if (m_listSprite.size())
		result = { m_Position.x - m_listSprite.at(0)->getFrameInfo().Width / 2, m_Position.y + m_listSprite.at(0)->getFrameInfo().Height / 2, m_Position.x + m_listSprite.at(0)->getFrameInfo().Width / 2, m_Position.y - m_listSprite.at(0)->getFrameInfo().Height / 2 };
	return result;
}

vector2d CMovable::getVelocity()
{
	return m_Velocity;
}

