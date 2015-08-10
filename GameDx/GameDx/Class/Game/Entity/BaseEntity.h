/****************************************************************************/
/* Create by Michael Le*/
/* 08/07/2015 */
/***************************************************************************/


#ifndef __CBASEENTITY_H__
#define __CBASEENTITY_H__

#include "Game\Utill\stdafx.h"
#include "Framework\KeyBoard.h"
#include "Mathematics\Box2D.h"

class CBaseEntity
{
public:
	CBox2D*					m_Bounding;
	bool					m_isMovable;
	CBaseEntity();
	CBaseEntity(directDevice);
	~CBaseEntity();

	virtual bool initEntity()										= 0;
	virtual void updateEntity(float deltaTime)						= 0;
	virtual void updateEntity(CKeyBoard* deivce)					= 0;
	virtual void drawEntity()										= 0;

protected:

};


#endif