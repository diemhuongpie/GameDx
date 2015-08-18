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
	m_Position						= pos;
	m_Bounding						= bounding;
	m_styleID						= styleID;

	initEntity();
}

bool		CTile::loadSprite()
{
	return true;
}

CBox2D		CTile::getBounding()
{ 
	return *m_Bounding;
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
	m_listSprite.at(m_State)->Render(CCamera::setPositionEntity(m_Position), vector2d(2.0, 2.0), 0.0f, DRAWCENTER_LEFT_TOP, true, FPS);
}