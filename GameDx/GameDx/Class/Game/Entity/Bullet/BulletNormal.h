#ifndef __BULLET_H__
#define __BULLET_H__

#include "Game\Entity\Bullet\BaseBullet.h"

class CBulletNormal	: public CBaseBullet
{

public:
	CBulletNormal();
	~CBulletNormal();

	bool					initEntity()										;
	virtual void			updateEntity(float deltaTime)				override;
	void					updateEntity(CKeyBoard*)							;
	void					drawEntity()										;
	bool					loadSprite()										;
	vector3d				getPosition();
	void					setState(int newState);
	int						getState();
	void					resetObject();

private :
	float					m_Angle;
};

#endif
