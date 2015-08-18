#ifndef __BULLETMANAGER_H__
#define __BULLETMANAGER_H__

#include "Game\Algorithsm\Singleton.h"
#include "Game\Entity\MovableEntity.h"
#include "Game\Entity\StaticEntity.h"
#include "Game\Entity\Bullet\BulletNormal.h"
#include "Game\Entity\Bullet\BulletMachineAutoOrange.h"
#include "Game\Entity\Bullet\BulletEnemyBall.h"
#include "Game\Entity\Bullet\BaseBullet.h"

class CBulletManager : public CSingleton<CBulletManager>
{
public:
	CBulletManager();
	~CBulletManager();

	void			updateBullet(float			deltaTime);
	void			updateBullet(CKeyBoard*		keyBoard);
	void			updateBullet(CStaticEntity*	staticEntity);
	void			updateBullet(CMovable*		player);

	void			renderBullet();

	void			getBullet	(int			styleBullet, vector3d		m_Position);
	void			createBullet(int			styleBullet);


private:
	vector<CBaseBullet*>			m_listBullet;
	int m_styleBullet;
	

};

#endif