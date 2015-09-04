#ifndef __ENEMY_MACHINE_AUTO_ORANGE_H__
#define __ENEMY_MACHINE_AUTO_ORANGE_H__

#include "Game\Entity\MovableEntity.h"
#include "Framework\Camera.h"


class CEnemyMachineAutoOrange : public CMovable
{
public:
	CEnemyMachineAutoOrange();
	CEnemyMachineAutoOrange(vector3d position,bool dir);
	~CEnemyMachineAutoOrange();
	bool initEntity();
	void updateEntity(float deltaTime);
	void updateEntity(CKeyBoard *device);
	void updateEntity(CBaseEntity* entity);
	void updateEntity(RECT rectCamera);
	void drawEntity();

	void resetObject();
	bool loadSprite();
private:
	int m_delayTime;
	bool m_isTop;
	bool check_State;
	vector3d m_oldPosition;
};

#endif