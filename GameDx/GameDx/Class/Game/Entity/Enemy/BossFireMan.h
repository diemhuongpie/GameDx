#pragma once
#include "Game\Entity\MovableEntity.h"
#include "Framework\Camera.h"


class CBossFireMan : public CMovable
{
public:
	CBossFireMan(vector3d,vector3d);
	~CBossFireMan();
	virtual		void					updateEntity(float deltaTime)		override;
	virtual		void					updateEntity(CKeyBoard *device)		override;
	virtual		void					updateEntity(CBaseEntity*)			override;
	virtual		bool					loadSprite()						override;
				bool					initEntity()								;
				void					updateEntity(RECT rectCamera)				;
				void					drawEntity()								;
				void					resetObject()								;

private:
	vector3d m_PositionPlayer;
	int m_delayTime;
	bool m_isLeft;
};

