#include "StaticEntity.h"


CStaticEntity::CStaticEntity()
{
}


CStaticEntity::~CStaticEntity()
{
}

RECT		CStaticEntity::getBounding()
{
	RECT result = { 0, 0, 0, 0 };
	if (!m_listSprite.size())
		result = { m_Position.x, m_Position.y, m_listSprite.at(0)->getFrameInfo().Width, m_listSprite.at(0)->getFrameInfo().Height };
	return result;
}
