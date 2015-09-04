#ifndef __ENEMY_ROBOT_RED_H__
#define __ENEMY_ROBOT_RED_H__

#include "Game\Entity\MovableEntity.h"
#include "Framework\Camera.h"

class EnemyRobotRed : public CMovable
{
public:
	EnemyRobotRed(vector3d);
	~EnemyRobotRed();
	bool initEntity();
	void updateEntity(float deltaTime);
	void updateEntity(CKeyBoard *device);
	void updateEntity(CBaseEntity*){};
	void updateEntity(RECT rectCamera);
	void drawEntity();
	void resetObject();
	bool loadSprite();
private:
	bool m_isLEFT;
	int m_delayTime;
	bool check_State;
};

#endif

