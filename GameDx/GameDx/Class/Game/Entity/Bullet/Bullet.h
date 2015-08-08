#ifndef __BULLET_H__
#define __BULLET_H__

#include "Game\Entity\MovableEntity.h"

class CBullet	: public CMovable
{
public:
	CBullet();
	~CBullet();

	virtual		bool					initEntity()										override;
	virtual		void					updateEntity(CKeyBoard* device)						override;
	virtual		void					updateEntity(float deltaTime)						override;
	virtual		void					drawEntity()										override;
	virtual		bool					loadSprite()										override;
	virtual		vector3d				getPosition();										

private:

};

#endif
