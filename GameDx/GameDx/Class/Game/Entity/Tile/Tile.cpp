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
	m_Position						= (pos);
	m_Bounding						= new CBox2D(pos.x - bounding->getWidth() / 2, pos.y + bounding->getHeight() / 2, bounding->getWidth(), bounding->getHeight());
	//m_Bounding						= new CBox2D (this->getBounding());
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

//CBox2D		CTile::getBounding()
//{ 
//	return *m_Bounding;
//	//return this->getBounding();
//}

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
	m_listSprite.at(m_State)->Render(CCamera::setPositionEntity(vector3d(m_Bounding->getX(), m_Bounding->getY(), 0.5f)), vector2d(2.0, 2.0), 0.0f, DRAWCENTER_MIDDLE_MIDDLE, true, FPS);

	//m_listSprite.at(m_State)->Render(CCamera::setPositionEntity(m_Position), vector2d(2.0, 2.0), DRAWCENTER_MIDDLE_MIDDLE, true, FPS);
}

void CTile::resetObject()
{}