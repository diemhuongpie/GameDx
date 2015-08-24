#pragma once
#include "Game\Entity\MovableEntity.h"
#include "Framework\Camera.h"
#include "Mathematics\Collision.h"
#include "Game\Entity\Bullet\BaseBullet.h"


class CEnemyPartBoomBlue : public CBaseBullet
{
public:
	CEnemyPartBoomBlue(int);
	~CEnemyPartBoomBlue();
	bool initEntity();
	void updateEntity(float deltaTime);
	void updateEntity(CKeyBoard *device);

	virtual		void	logicCollision(CBaseEntity* entity)  override;

	void updateEntity(RECT rectCamera);
	void drawEntity();
	void resetObject();
	bool loadSprite();
	vector3d				getPosition();
	void					setState(int newState);
	int						getState();

private:
	float m_delayTime;
	vector3d m_oldPos;
	int	  m_velX;
};

