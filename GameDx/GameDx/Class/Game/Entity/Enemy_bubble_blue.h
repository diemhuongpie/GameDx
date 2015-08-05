#pragma once
#include "Game\Entity\MovableEntity.h"
#include "Framework\Camera.h"

class CEnemy_bubble_blue : public CMovable
{
public:
	CEnemy_bubble_blue();
	~CEnemy_bubble_blue();
	bool initEntity();
	void updateEntity(CKeyBoard *device, float deltaTime);
	void updateEntity(RECT rectCamera);
	void drawEntity();
	bool loadSprite();
	void enemyMoving();
private:
	vector3d m_position1;
	int x;
	int m_count;
	float m_dx, m_dy;
	float m_speedX, m_speedY;
	float m_angle;
	bool m_isLEFT;
};

