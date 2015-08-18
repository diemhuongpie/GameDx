#ifndef __BULLET_H__
#define __BULLET_H__

#include "Game\Entity\Bullet\BaseBullet.h"

class CBulletNormal	: public CBaseBullet
{

public:
	CBulletNormal();
	~CBulletNormal();

	bool					initEntity()										;
	void					updateEntity(float deltaTime)						;
	void					updateEntity(CKeyBoard*)							;
	void					drawEntity()										;
	bool					loadSprite()										;
	vector3d				getPosition();
	void					setState(int newState);
	int						getState();

};

#endif
