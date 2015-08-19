#pragma once
#include "Game\Entity\Bullet\BaseBullet.h"

class CBulletEnemy : public CBaseBullet
{
public:
	CBulletEnemy(float );
	~CBulletEnemy();
	bool					initEntity();
	void					updateEntity(float deltaTime);
	void					updateEntity(CKeyBoard*);
	void					drawEntity();
	bool					loadSprite();
	vector3d				getPosition();
	void					setState(int newState);
	int						getState();

private:
	float					m_Angle;
};

