#include "BulletManager.h"


CBulletManager::CBulletManager()
{
	m_listBullet = new vector<CBaseBullet*>[TYPE_BULLET::NUMBER_OF_TYPE_BULLET];

	for (int i = 0; i < 5; ++i)
	{
		m_listBullet[TYPE_BULLET::NORMAL].push_back(new CBulletNormal());
	}
	for (int i = 0; i < 4; ++i)
	{
		m_listBullet[TYPE_BULLET::TANK_RED].push_back(new CBulletTankRed(m_angle));
		m_angle++;
	}
	//************BULLET_ENEMY_PART_BOOM*************//
	m_listBullet[TYPE_BULLET::ENEMY_PART_BOOM].push_back(new CEnemyPartBoomBlue(3));
	m_listBullet[TYPE_BULLET::ENEMY_PART_BOOM].push_back(new CEnemyPartBoomBlue(-3));
	m_listBullet[TYPE_BULLET::ENEMY_PART_BOOM].push_back(new CEnemyPartBoomBlue(4.5));
	m_listBullet[TYPE_BULLET::ENEMY_PART_BOOM].push_back(new CEnemyPartBoomBlue(-4.5));
	//************BULLET_MACHINE_AUTO_ORANGE*************//
	m_listBullet[TYPE_BULLET::MACHINE_AUTO_ORANGE].push_back(new CBulletEnemy(0));
	m_listBullet[TYPE_BULLET::MACHINE_AUTO_ORANGE].push_back(new CBulletEnemy(PI/4));
	m_listBullet[TYPE_BULLET::MACHINE_AUTO_ORANGE].push_back(new CBulletEnemy(PI/2));
	m_listBullet[TYPE_BULLET::MACHINE_AUTO_ORANGE].push_back(new CBulletEnemy(3*PI/4));
	m_listBullet[TYPE_BULLET::MACHINE_AUTO_ORANGE].push_back(new CBulletEnemy(PI));
	//************BULLET_ENEMY_BALL*************//
	m_listBullet[TYPE_BULLET::ENEMY_BALL].push_back(new CBulletEnemy(0));
	m_listBullet[TYPE_BULLET::ENEMY_BALL].push_back(new CBulletEnemy(PI / 4));
	m_listBullet[TYPE_BULLET::ENEMY_BALL].push_back(new CBulletEnemy(PI / 2));
	m_listBullet[TYPE_BULLET::ENEMY_BALL].push_back(new CBulletEnemy(3 * PI / 4));
	m_listBullet[TYPE_BULLET::ENEMY_BALL].push_back(new CBulletEnemy(7 * PI / 4));
	m_listBullet[TYPE_BULLET::ENEMY_BALL].push_back(new CBulletEnemy(3 * PI / 2));
	m_listBullet[TYPE_BULLET::ENEMY_BALL].push_back(new CBulletEnemy(5 * PI / 4));
	m_listBullet[TYPE_BULLET::ENEMY_BALL].push_back(new CBulletEnemy(PI));
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
	if (m_angle > 3)
		m_angle = 0;
}

void	CBulletManager::ShowBullet(int styleBullet, vector3d pos, vector2d Vel)
{
	for (int i = 0; i < m_listBullet[styleBullet].size(); ++i)
	if (m_listBullet[styleBullet].at(i)->getState() == BULLETSTATE::BULLET_STATE_INVIS)
	{
		m_listBullet[styleBullet].at(i)->setState(BULLETSTATE::BULLET_STATE_SHOW);
		m_listBullet[styleBullet].at(i)->setPosition(pos);
		m_listBullet[styleBullet].at(i)->setVelocity(vector2d(Vel.x*3, Vel.y*3));
		break;
	}
}

vector<CBaseBullet*>*		CBulletManager::getListBullet()
{
	return m_listBullet;
}