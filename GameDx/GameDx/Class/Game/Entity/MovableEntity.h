/****************************************************************************/
/* Create by Michael Le AND Shin Truong*/
/* 08/07/2015 */
/***************************************************************************/

#ifndef __CMOVABLE__H__
#define __CMOVABLE__H__

#include "BaseEntity.h"
#include "Game\Utill\stdafx.h"
#include "Game\Utill\Config.h"
#include "Framework\Sprite.h"
#include "Mathematics\Box2D.h"

class CMovable : public CBaseEntity
{
public:
	CMovable();
	~CMovable();
	virtual		bool					loadSprite()		=	0;
	virtual		vector3d				getPosition();

protected:
				int						m_State;
				vector3d				m_Position;
				vector2d				m_Velocity;
				CBox2D*					m_Bounding;
				vector<CSprite*>		m_listSprite;

};

#endif