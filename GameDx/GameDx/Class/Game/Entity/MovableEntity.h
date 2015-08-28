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

	virtual		void					updateEntity(float deltaTime)										= 0;
	virtual		void					updateEntity(CKeyBoard*)											= 0;
	virtual		void					updateEntity(CBaseEntity*){};

	virtual		bool					loadSprite()														= 0;
	virtual		vector3d				getPosition()														override;
	virtual		CBox2D					getBounding()														override;
	virtual		bool					initEntity()														override;
	virtual		char*					getTagNode()														override;
	virtual		void					setTagNode(char* tag)												override;
	virtual		vector2d				getVelocity()																;
	virtual		int						getState()															override;
	virtual		void					setState(int newState)												override;
	virtual		void					setPosition(vector3d pos)											override;
	virtual		void					setVelocity(vector2d vel)													;

protected:
				vector2d				m_Velocity;
};

#endif