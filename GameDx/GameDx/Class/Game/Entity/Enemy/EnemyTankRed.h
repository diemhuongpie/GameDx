#ifndef __ENEMY_TANK_RED_H__
#define __ENEMY_TANK_RED_H__

#include "Game\Entity\StaticEntity.h"
#include "Game\Entity\MovableEntity.h"
#include "Framework\Camera.h"
#include "Game\Entity\Bullet\BulletManager.h"


class CEnemyTankRed : public CStaticEntity
{
public:
	CEnemyTankRed();
	CEnemyTankRed(vector3d position);
	~CEnemyTankRed();
	virtual bool initEntity()											override;
	void updateEntity(CKeyBoard* keyboard);
	void updateEntity(float deltaTime);
	void updateEntity(RECT rectCamera);
	void drawEntity();
	bool loadSprite();

private:
	int m_checkState;
	int	m_delayTime;
	int m_delayShoot;

};

#endif