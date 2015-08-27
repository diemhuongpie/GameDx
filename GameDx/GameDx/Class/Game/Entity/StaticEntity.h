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


class CStaticEntity : public CBaseEntity
{
public:
	CStaticEntity();
	~CStaticEntity();

	virtual		bool					loadSprite()							= 0;
	virtual		void					updateEntity(float deltaTime){};
	virtual		void					updateEntity(CBaseEntity* entity){};

	virtual		CBox2D					getBounding()							override;
	virtual		bool					initEntity()							override;
	virtual		char*					getTagNode()							override;
	virtual		void					setTagNode(char* tag)					override;
	virtual		vector3d				getPosition()							override;
	virtual		void					setPosition(vector3d)					override;
	virtual		int						getState()								override;
	virtual		void					setState(int newState)					override;

protected:
};

#endif
