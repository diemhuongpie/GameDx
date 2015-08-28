#pragma once
#include "Game\Entity\MovableEntity.h"
#include "Framework\Camera.h"


class CBossFireMan : public CMovable
{
public:
	CBossFireMan(vector3d,vector3d);
	~CBossFireMan();
	bool initEntity();
	void updateEntity(float deltaTime);
	virtual		void	logicCollision(CBaseEntity* entity)  override;
	void updateEntity(CKeyBoard *device);
	void updateEntity(RECT rectCamera);
	void drawEntity();
	void resetObject();

	bool loadSprite();
private:
	vector3d m_PositionPlayer;
	int m_delayTime;
	bool m_isLeft;
};

