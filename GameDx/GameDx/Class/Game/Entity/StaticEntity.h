/****************************************************************************/
/* Create by Michael Le AND Shin Truong*/
/* 08/07/2015 */
/***************************************************************************/

#ifndef __CSTATICENTITY_H__
#define __CSTATICENTITY_H__

#include "BaseEntity.h"
#include "Game\Utill\stdafx.h"
#include "Game\Utill\Config.h"
#include "Mathematics\Box2D.h"
#include "Framework\Sprite.h"

// class nay van dang la asbtract class
class CStaticEntity : public CBaseEntity
{
public:
	CStaticEntity();
	~CStaticEntity();

	// load sprite vao day....sau do goi no trong ham Init va ham Init sex duoc goi trong ham new.
	virtual		bool					loadSprite()			= 0;
	virtual		RECT					getBounding()			override;
	virtual		bool					initEntity()			override;
				vector2d				getPosition();

protected:
				vector3d				m_Position;
				vector<CSprite*>		m_listSprite;
};

#endif
