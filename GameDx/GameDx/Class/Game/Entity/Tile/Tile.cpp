#include "Tile.h"

CTile::CTile()
{
}

CTile::~CTile()
{
}

CTile::CTile(CSprite* sprite, vector3d pos, CBox2D* bounding, int styleID)
{
	m_listSprite.push_back(sprite);
	m_Position						= vector3d(pos.x, pos.y, 0.5);
	m_Bounding						= new CBox2D(m_Position.x - bounding->getWidth()/2, m_Position.y + bounding->getHeight()/2, bounding->getWidth(), bounding->getHeight());
	m_styleID						= styleID;

	initEntity();
}

CTile::CTile(CSprite* sprite, vector3d pos)
{
	m_listSprite.push_back(sprite);
	m_Position = pos;
}

bool		CTile::loadSprite()
{
	return true;
}

bool		CTile::initEntity()
{
	m_State = 0;
	loadSprite();
	return true;
}

void		CTile::updateEntity(float deltaTime)
{

}

void		CTile::drawEntity()
{
	m_listSprite.at(m_State)->Render(CCamera::setPositionEntity(m_Position), vector2d(1.0, 1.0), 0.0f, DRAWCENTER_MIDDLE_MIDDLE, true, FPS);
}

void CTile::resetObject()
{}