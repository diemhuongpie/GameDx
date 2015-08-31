#pragma once
#include "Game\Entity\Bullet\BaseBullet.h"
#include "Game\Utill\InformationResource.h"
#include "Framework\Camera.h"

class CBulletFireMan : public CBaseBullet
{
public:
	CBulletFireMan();
	~CBulletFireMan();
	virtual		void					updateEntity(float deltaTime)		override;
	virtual		void					updateEntity(CKeyBoard *device)		override;
	virtual		void					updateEntity(CBaseEntity*)			override;
	virtual		bool					loadSprite()						override;
				bool					initEntity();
				void					drawEntity();
				vector3d				getPosition();
				void					setState(int newState);
				int						getState();
				void					resetObject();

private:
	int						m_timeDestroy;
	float					m_angle;
};

