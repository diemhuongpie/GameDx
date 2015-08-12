/****************************************************************************/
/* Create by Michael Le AND Shin Truong*/
/* 08/07/2015 */
/***************************************************************************/

#ifndef __CMOVABLE__H__
#define __CMOVABLE__H__

#include "BaseEntity.h"
#include "Game\Utill\stdafx.h"
#include "Game\Utill\Config.h"
#include "Mathematics\Box2D.h"


class CMovable : public CBaseEntity
{
public:
	CMovable();
	~CMovable();
	virtual		bool					loadSprite()			=	0;
	virtual		vector3d				getPosition()					;
	virtual		CBox2D					getBounding()			override;
	virtual		bool					initEntity()			override;
	virtual		const char*				getTagNode()			override;
	virtual		vector2d				getVelocity()					;

protected:
				vector2d				m_Velocity;
};

#endif