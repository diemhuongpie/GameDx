#include "BulletManager.h"


CBulletManager::CBulletManager()
{
	for (int i = 0; i < 10; ++i)
	{
		if (m_styleBullet == TYPE_BULLET::MACHINE_AUTO_ORANGE)
			m_listBullet.push_back(new CBulletMachineAutoOrange());
		if (m_styleBullet == TYPE_BULLET::NORMAL)
			m_listBullet.push_back(new CBulletNormal());
		if (m_styleBullet == TYPE_BULLET::ENEMY_BALL)
			m_listBullet.push_back(new CBulletEnemyBall());
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
	
	m_styleBullet = styleBullet;
	for (int i = 0; i < m_listBullet.size(); ++i)
		if (m_listBullet.at(i)->getState() == BULLETSTATE::BULLET_STATE_INVIS)
		{
			m_listBullet.at(i)->setState(BULLETSTATE::BULLET_STATE_SHOW);
			m_listBullet.at(i)->setPosition(pos);
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