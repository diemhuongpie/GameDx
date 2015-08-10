#include "MovableEntity.h"


CMovable::CMovable()
{
}


CMovable::~CMovable()
{
}

vector3d	CMovable::getPosition()
{
	return m_Position;
}

RECT		CMovable::getBounding()
{
	RECT result = { 0, 0, 0, 0 };
	if (!m_listSprite.size())
	result = { m_Position.x, m_Position.y, m_listSprite.at(0)->getFrameInfo().Width, m_listSprite.at(0)->getFrameInfo().Height };
	return result;
}
