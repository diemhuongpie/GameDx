#include "Tile.h"

CTile::CTile()
{

}

CTile::CTile(vector3d pos, int State)
{
	m_Pos = pos;
	m_State = State;
}


CTile::~CTile()
{
}

bool CTile::initEntity()
{
	return true;
}

void CTile::updateEntity(float deltaTime)
{

}

void CTile::updateEntity(CKeyBoard* device)
{

}


void CTile::drawEntity()
{

}

CBox2D CTile::getBounding()
{
	return *m_Bounding;
}

const char*	CTile::getTagNode()
{
	return this->m_TagNode;
}

bool CTile::loadSprite()
{
	return true;
}

