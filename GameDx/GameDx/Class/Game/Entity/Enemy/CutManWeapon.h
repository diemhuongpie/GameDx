#pragma once
#include "Game\Entity\MovableEntity.h"
#include "Framework\Camera.h"


class CCutManWeapon : public CMovable
{
public:
	CCutManWeapon(vector3d);
	~CCutManWeapon();
	bool initEntity();
	void updateEntity(float deltaTime);
	void updateEntity(CKeyBoard *device);
	void updateEntity(CBaseEntity* entity);
	void updateEntity(RECT rectCamera);
	void updateEntity(CBaseEntity*, CBaseEntity*);

	void drawEntity();
	void resetObject();
	void moveTo(vector3d, vector3d);

	bool loadSprite();
private :
	int m_count;
	float m_dx, m_dy;
	float m_angle;
};

