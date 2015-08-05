/****************************************************************************/
/* Create by Michael Le*/
/* 08/07/2015 */
/***************************************************************************/


#ifndef __CBASEENTITY_H__
#define __CBASEENTITY_H__

#include "Game\Utill\stdafx.h"
#include "Framework\KeyBoard.h"

class CBaseEntity
{
public:
	//CBox2D*					m_Bounding;
	vector2d				m_Velocity;

	CBaseEntity();
	CBaseEntity(directDevice);
	~CBaseEntity();

	virtual bool initEntity()										= 0;
	virtual void updateEntity(CKeyBoard *device, float deltaTime)	= 0;
	virtual void updateEntity(RECT rectCamera)						= 0;
	virtual void drawEntity()										= 0;

protected:

};


#endif