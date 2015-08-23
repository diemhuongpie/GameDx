#pragma once
#include "Game\Entity\MovableEntity.h"
#include "Framework\Camera.h"

class CEnemyMachineOrange : public CMovable
{
public:
	CEnemyMachineOrange();
	CEnemyMachineOrange(vector3d position , vector3d position_player,int m_rangex);
	~CEnemyMachineOrange();
	bool initEntity();
	void updateEntity(float deltaTime);
	void updateEntity(CKeyBoard *device);
	void updateEntity(RECT rectCamera);
	void drawEntity();
	void resetObject();
	bool loadSprite();
private:
	bool m_Sign;
	vector3d m_CurrentPosition;
	vector3d m_PositionPlayer;
	int m_RangeX;
};

