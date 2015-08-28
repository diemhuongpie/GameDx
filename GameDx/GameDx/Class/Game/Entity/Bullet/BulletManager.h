#ifndef __BULLETMANAGER_H__
#define __BULLETMANAGER_H__

#include "Game\Algorithsm\Singleton.h"
#include "Game\Entity\MovableEntity.h"
#include "Game\Entity\StaticEntity.h"
#include "Game\Entity\Bullet\BulletNormal.h"
#include "Game\Entity\Bullet\BaseBullet.h"
#include "Game\Entity\Bullet\BulletEnemy.h"
#include "Game\Entity\Bullet\BulletTankRed.h"
#include "Game\Entity\Enemy\EnemyPartBoomBlue.h"
#include "Game\Entity\Bullet\BulletFireMan.h"

class CBulletManager : public CSingleton<CBulletManager>
{
public:
	CBulletManager();
	~CBulletManager();

	void							ShowBullet	(int			styleBullet, vector3d		m_Position);
	void							ShowBullet	(int			styleBullet, vector3d		m_Position, vector2d		m_Vel);
	vector<CBaseBullet*>*			getListBullet();

private:
	vector<CBaseBullet*>*			m_listBullet;
	float							m_angle;

};

#endif