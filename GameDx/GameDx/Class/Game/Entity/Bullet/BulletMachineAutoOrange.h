#pragma once
#include "Game\Entity\MovableEntity.h"
#include "Game\Entity\Bullet\BulletNormal.h"
#include "Game\Utill\InformationResource.h"
#include "Framework\Camera.h"

class CBulletMachineAutoOrange : public CMovable
{
public:
	CBulletMachineAutoOrange();
	~CBulletMachineAutoOrange();
	bool					initEntity()										;
	void					updateEntity(float deltaTime)						;
	void					updateEntity(CKeyBoard*)							;
	void					drawEntity()										;
	bool					loadSprite()										;
	vector3d				getPosition();
	void					Shoot(float);
	void					setState(int newState);
	int						getState();
private:
	vector3d m_BulletPosition[5];

};

