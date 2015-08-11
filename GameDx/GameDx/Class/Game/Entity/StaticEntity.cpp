#include "StaticEntity.h"


CStaticEntity::CStaticEntity()
{
	this->initEntity();
}


CStaticEntity::~CStaticEntity()
{
}

bool CStaticEntity::initEntity()
{
	m_isMovable = false;
	return true;
}

RECT		CStaticEntity::getBounding()
{
	RECT result = { 0, 0, 0, 0 };
	if (m_listSprite.size())
		//result = { m_Position.x, m_Position.y, m_listSprite.at(0)->getFrameInfo().Width, m_listSprite.at(0)->getFrameInfo().Height };
		result = { m_Position.x - m_listSprite.at(0)->getFrameInfo().Width / 2, m_Position.y + m_listSprite.at(0)->getFrameInfo().Height / 2, m_Position.x + m_listSprite.at(0)->getFrameInfo().Width / 2, m_Position.y - m_listSprite.at(0)->getFrameInfo().Height / 2 };
	return result;
}

vector2d CStaticEntity::getPosition()
{
	return m_Position;
}