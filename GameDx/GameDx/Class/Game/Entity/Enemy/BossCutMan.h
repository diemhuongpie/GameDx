#ifndef __BOSS_CUT_MAN_H__
#define __BOSS_CUT_MAN_H__
#include "Game\Entity\MovableEntity.h"
#include "Framework\Camera.h"
#include "Game\Entity\Enemy\CutManWeapon.h"


class CBossCutMan : public CMovable
{
public:
	CBossCutMan();
	CBossCutMan(vector3d position);
	~CBossCutMan();
	bool initEntity();
	void updateEntity(float deltaTime);
	void updateEntity(CBaseEntity *);
	void updateEntity(CKeyBoard *device);
	void updateEntity(RECT rectCamera);
	void drawEntity();
	void resetObject();

	bool loadSprite();
private:
	CCutManWeapon*	m_Weapon;
	int m_delayTime;
	int m_delayTime1;
	int m_checkState;
	bool m_isLeft;
};


#endif