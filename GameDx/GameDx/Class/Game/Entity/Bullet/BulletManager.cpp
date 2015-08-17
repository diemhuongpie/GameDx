#include "BulletManager.h"


CBulletManager::CBulletManager()
{
	for (int i = 0; i < 1; ++i)
	{
		m_listBullet.push_back(new CBulletMachineAutoOrange());
	}
}

CBulletManager::~CBulletManager()
{
}

void	CBulletManager::updateBullet(float deltaTime)
{
	for (int i = 0; i < m_listBullet.size(); ++i)
		m_listBullet.at(i)->updateEntity(deltaTime);
}

void	CBulletManager::updateBullet(CStaticEntity* staticEntity)
{

}

void	CBulletManager::updateBullet(CMovable* movEntity)
{

}

void	CBulletManager::getBullet(int styleBullet, vector3d pos)
{
	for (int i = 0; i < m_listBullet.size(); ++i)
	if (m_listBullet.at(i)->getState() == BULLETSTATE::BULLET_STATE_INVIS)
	{
		m_listBullet.at(i)->setState(BULLETSTATE::BULLET_STATE_SHOW);
		m_listBullet.at(i)->setPosition(pos);
		break;
	}
}

void	CBulletManager::createBullet(int styleBullet)
{

}

void	CBulletManager::renderBullet()
{
	for (int i = 0; i < m_listBullet.size(); ++i)
		m_listBullet.at(i)->drawEntity();
}