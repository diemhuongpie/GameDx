#pragma once
#include "Game\Entity\MovableEntity.h"
#include "Framework\Camera.h"

class CEnemyNinja : public CMovable
{
public:
	CEnemyNinja();
	CEnemyNinja(vector3d, vector3d);
	~CEnemyNinja();
	bool initEntity();
	void updateEntity(float deltaTime);
	void updateEntity(CKeyBoard *device);
	void updateEntity(RECT rectCamera);
	void drawEntity();
	void resetObject();
	bool loadSprite();
	void jump();
	void fire();

private:
	bool m_isLEFT;
	int	 m_checkState;
	int	 m_delayTime;
	vector3d m_PositionPlayer;

};

