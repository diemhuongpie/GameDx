#ifndef __ENEMY_BALL_H__
#define __ENEMY_BALL_H__

#include "Game\Entity\MovableEntity.h"
#include "Framework\Camera.h"

class CEnemyBall : public CMovable
{
public:
	CEnemyBall();
	CEnemyBall(LPDIRECT3DDEVICE9);
	~CEnemyBall();

	bool initEntity()											;
	void updateEntity(CKeyBoard *device, float deltaTime)		;
	void updateEntity(RECT rectCamera)							;
	void drawEntity()											;

	bool loadSprite()											;

private:
	int m_delay_Time;
	bool check_State;
};

#endif