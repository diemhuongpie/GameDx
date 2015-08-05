#pragma once
#include "Game\Entity\MovableEntity.h"
#include "Framework\Camera.h"

class CEnemy_ball : public CMovable
{
public:
	CEnemy_ball();
	CEnemy_ball(LPDIRECT3DDEVICE9);
	~CEnemy_ball();

	bool initEntity()											;
	void updateEntity(CKeyBoard *device, float deltaTime)		;
	void updateEntity(RECT rectCamera)							;
	void drawEntity()											;

	bool loadSprite()											;

private:
	int m_delay_Time;
	bool check_State;
};

