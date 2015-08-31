#ifndef __BOSS_BOMB_MAN_H__
#define __BOSS_BOMB_MAN_H__

#include "Game\Entity\MovableEntity.h"

class CBossBombMan :public CMovable
{
public:
	CBossBombMan();
	~CBossBombMan();

	virtual bool			initEntity()														override;
	virtual void			updateEntity(float deltaTime)										override;
	virtual void			updateEntity(CBaseEntity*)											override;
	virtual void			updateEntity(CKeyBoard *device)										override;
	virtual void			drawEntity()														override;

	virtual	vector3d		getPosition()														override;
	virtual bool			loadSprite()														override;
	virtual void			resetObject()														override;


protected:

	vector<CollisionEvents*>	m_listCollitionEvent;
};

#endif