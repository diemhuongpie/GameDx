#pragma once
#include "Game\Entity\Bullet\BaseBullet.h"
#include "Game\Utill\InformationResource.h"
#include "Framework\Camera.h"

class CBulletFireMan : public CBaseBullet
{
public:
	CBulletFireMan();
	~CBulletFireMan();
	bool					initEntity();
	void					updateEntity(float deltaTime);
	void					updateEntity(CKeyBoard*);
	void					drawEntity();
	bool					loadSprite();
	vector3d				getPosition();
	void					setState(int newState);
	int						getState();
	void					resetObject();

private:
	int						m_timeDestroy;
	float					m_angle;
};

