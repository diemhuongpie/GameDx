#include "BulletManager.h"


CBulletManager::CBulletManager()
{
	m_listBullet = new vector<CBaseBullet*>[TYPE_BULLET::NUMBER_OF_TYPE_BULLET];

	for (int i = 0; i < 10; ++i)
	{
		m_listBullet[TYPE_BULLET::ENEMY_BALL].push_back(new CBulletEnemyBall());
		m_listBullet[TYPE_BULLET::MACHINE_AUTO_ORANGE].push_back(new CBulletMachineAutoOrange());
	}
	for (int i = 0; i < 5; ++i)
	{
		m_listBullet[TYPE_BULLET::NORMAL].push_back(new CBulletNormal());
	}
}

CBulletManager::~CBulletManager()
{
}


void	CBulletManager::ShowBullet(int styleBullet, vector3d pos)
{
	for (int i = 0; i < m_listBullet[styleBullet].size(); ++i)
		if (m_listBullet[styleBullet].at(i)->getState() == BULLETSTATE::BULLET_STATE_INVIS)
		{
			m_listBullet[styleBullet].at(i)->setState(BULLETSTATE::BULLET_STATE_SHOW);
			m_listBullet[styleBullet].at(i)->setPosition(pos);
			break;
		}
}

void	CBulletManager::ShowBullet(int styleBullet, vector3d pos, vector2d Vel)
{
	for (int i = 0; i < m_listBullet[styleBullet].size(); ++i)
	if (m_listBullet[styleBullet].at(i)->getState() == BULLETSTATE::BULLET_STATE_INVIS)
	{
		m_listBullet[styleBullet].at(i)->setState(BULLETSTATE::BULLET_STATE_SHOW);
		m_listBullet[styleBullet].at(i)->setPosition(pos);
		m_listBullet[styleBullet].at(i)->setVelocity(Vel);
		break;
	}
}

vector<CBaseBullet*>*		CBulletManager::getListBullet()
{
	return m_listBullet;
}