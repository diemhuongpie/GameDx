#ifndef __ENEMY_BALL_H__
#define __ENEMY_BALL_H__

#include "Game\Entity\MovableEntity.h"
#include "Framework\Camera.h"
#include "Mathematics\Collision.h"
#include "EnemyBubbleBlue.h"

class CEnemyBall : public CMovable
{
public:
	CEnemyBall();
	CEnemyBall(LPDIRECT3DDEVICE9);
	~CEnemyBall();

	bool initEntity()											;
	void updateEntity(float deltaTime)							;
	void updateEntity(CKeyBoard *device)						;

	virtual	void logicCollision(CBaseEntity* entity)  override;
	void		 updateEntityFromCollision(float detaTime, CBaseEntity* entity){};
	
	void updateEntity(RECT rectCamera)							;
	void drawEntity()											;
	void resetObject()											;
	bool loadSprite()											;

private:
	int m_delayTime;
	bool check_State;
};

#endif