#pragma once
#include "Framework\Camera.h"
#include "Game\Entity\Bullet\BaseBullet.h"

class CBulletTankRed : public CBaseBullet
{
public:
	CBulletTankRed(float,bool);
	~CBulletTankRed();
	bool					initEntity();
	void					updateEntity(float deltaTime);
	void					updateEntity(CKeyBoard*);
	void					updateEntity(CBaseEntity*);
	void					drawEntity();
	bool					loadSprite();
	vector3d				getPosition();
	void					setState(int newState);
	int						getState();
	void					resetObject();

private:
	int						m_timeDestroy;
	int						m_changeAngle;
	float					m_angle;
	bool					m_isLeft;
};

