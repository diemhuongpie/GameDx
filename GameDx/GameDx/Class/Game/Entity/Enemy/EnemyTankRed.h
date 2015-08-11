#ifndef __ENEMY_TANK_RED_H__
#define __ENEMY_TANK_RED_H__
#include "Game\Entity\StaticEntity.h"

class CEnemyTankRed : public CStaticEntity
{
public:
	CEnemyTankRed();
	CEnemyTankRed(LPDIRECT3DDEVICE9);
	~CEnemyTankRed();

	virtual bool initEntity()											override;
	virtual void updateEntity(float deltaTime)							override;
	virtual void updateEntity(CKeyBoard *device)						override;
	virtual void drawEntity()											override;

	virtual bool loadSprite()											override;
};

#endif