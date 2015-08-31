#ifndef __BOMB_BULLET_H__
#define __BOMB_BULLET_H__
#include "Game\Utill\stdafx.h"
#include "Framework\KeyBoard.h"
#include "Framework\Camera.h"
#include "Game\Entity\Bullet\BaseBullet.h"
#include "Game\Utill\InformationResource.h"

class CBombBullet : public CBaseBullet
{
public:	
	CBombBullet();
	~CBombBullet();

	bool					initEntity();
	virtual void			updateEntity(float deltaTime)				override;
	virtual void			updateEntity(CKeyBoard*)					override;
	virtual void			updateEntity(CBaseEntity*)					override;

	void					drawEntity();
	bool					loadSprite();
	vector3d				getPosition();
	void					setState(int newState);
	int						getState();
	void					resetObject();

private:

	vector3d				m_MaxPosition;
	float					m_countTimeForBummm;
};

#endif