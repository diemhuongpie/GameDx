#pragma once
#include "Game\Entity\MovableEntity.h"
#include "Framework\Camera.h"
#include "Mathematics\Collision.h"
#include "Game\Entity\Enemy\EnemyPartBoomBlue.h"

class CEnemyBoomBlue : public CMovable
{
public:
	CEnemyBoomBlue(vector3d);
	~CEnemyBoomBlue();
	bool initEntity();
	void updateEntity(float deltaTime);
	void updateEntity(CKeyBoard *device);
	void updateEntity(CBaseEntity* entity);
	void updateEntity(RECT rectCamera);
	void drawEntity();
	void resetObject();
	bool loadSprite();
private :
	float m_delayTime;
};

