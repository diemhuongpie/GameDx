#pragma once
#include "Game\Entity\MovableEntity.h"
#include "Framework\Camera.h"

class Enemy_robot_red : public CMovable
{
public:
	Enemy_robot_red();
	~Enemy_robot_red();
	bool initEntity();
	void updateEntity(CKeyBoard *device, float deltaTime);
	void updateEntity(RECT rectCamera);
	void drawEntity();

	bool loadSprite();
private:
	bool m_isLEFT;
	int m_delay_Time;
	bool check_State;
};

