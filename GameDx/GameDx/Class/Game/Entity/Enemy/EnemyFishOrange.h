#pragma once
#include "Game\Entity\MovableEntity.h"
#include "Framework\Camera.h"

class CEnemyFishOrange : public CMovable
{
public:
	CEnemyFishOrange();
	CEnemyFishOrange(vector3d position = D3DXVECTOR3(100,500,0));
	~CEnemyFishOrange();
	bool initEntity();
	void updateEntity(float deltaTime);
	void updateEntity(CKeyBoard *device);
	void updateEntity(RECT rectCamera);
	void drawEntity();

	bool loadSprite();
private:
	vector3d m_CurrentPosition;
};

