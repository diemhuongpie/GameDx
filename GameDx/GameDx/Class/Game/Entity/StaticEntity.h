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

<<<<<<< Updated upstream

=======
// class nay van dang la asbtract class
>>>>>>> Stashed changes
class CStaticEntity : public CBaseEntity
{
public:
	CStaticEntity();
	~CStaticEntity();

	virtual		bool					loadSprite()			= 0;
	virtual		CBox2D					getBounding()			override;
	virtual		bool					initEntity()			override;
	virtual		const char*				getTagNode()			override;
				vector2d				getPosition();

protected:
<<<<<<< Updated upstream
=======
				vector3d				m_Position;
				CBox2D*					m_Bounding;
				vector<CSprite*>		m_listSprite;
>>>>>>> Stashed changes
};

#endif
