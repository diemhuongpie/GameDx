#pragma once
#include "Game\Entity\MovableEntity.h"
#include "Framework\Camera.h"

class CEnemy_cut : public CMovable
{
public:
	CEnemy_cut();
	CEnemy_cut(vector3d m_position_player);
	~CEnemy_cut();

	bool initEntity();
	void updateEntity(CKeyBoard *device, float deltaTime);
	void updateEntity(RECT rectCamera);
	void drawEntity();

	bool loadSprite();

private: 
	vector3d m_position_p;
	bool m_isLEFT;
	bool m_isJUMP;
};

