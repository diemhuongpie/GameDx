#ifndef __ENEMY_BUBBLE_BLE_H__
#define __ENEMY_BUBBLE_BLE_H__

#include "Game\Entity\MovableEntity.h"
#include "Framework\Camera.h"

class CEnemyBubbleBlue : public CMovable
{
public:
	CEnemyBubbleBlue(vector3d);
	~CEnemyBubbleBlue();

	bool initEntity();
	void updateEntity(CKeyBoard *device);
	void updateEntity(CBaseEntity * player);
	void updateEntity(float deltaTime);
	void updateEntity(RECT rectCamera);
	void drawEntity();
	bool loadSprite();
	void resetObject();
	void enemyMoving(vector3d position_Player);

	
private:
	vector3d m_oldPosition;
	vector3d m_position1;
	int m_delayTime;
	int x;
	int m_count;
	float m_dx, m_dy;
	float m_speedX, m_speedY;
	float m_angle;
	bool m_isLEFT;
};

#endif
