#include "Bullet.h"


CBullet::CBullet()
{
}


CBullet::~CBullet()
{
}

bool	CBullet::loadSprite()
{
	return	true;
}

bool	CBullet::initEntity()
{
	return true;
}

void	CBullet::updateEntity(float deltaTime)
{

}

void	CBullet::updateEntity(CKeyBoard* device)
{

}

void	CBullet::drawEntity()
{

}

vector3d CBullet::getPosition()
{

	return m_Position;
}
