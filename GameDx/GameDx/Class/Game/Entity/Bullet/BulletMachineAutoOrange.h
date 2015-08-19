#pragma once
#include "Game\Entity\MovableEntity.h"
#include "Game\Entity\Bullet\BulletNormal.h"
#include "Game\Utill\InformationResource.h"
#include "Framework\Camera.h"
#include "Game\Entity\Bullet\BaseBullet.h"

class CBulletMachineAutoOrange : public CBaseBullet
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
	void					setPosition(vector3d);
	void					setState(int newState);
	int						getState();
private:
	vector <vector3d>		m_BulletPosition;
	vector<CMovable*>	m_ListBullet;

};

