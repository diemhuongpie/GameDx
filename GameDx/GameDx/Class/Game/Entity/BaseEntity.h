/****************************************************************************/
/* Create by Michael Le*/
/* 08/07/2015 */
/***************************************************************************/


#ifndef __CBASEENTITY_H__
#define __CBASEENTITY_H__

#include "Game\Utill\stdafx.h"
#include "Framework\KeyBoard.h"
#include "Game\State\State.h"

class CBaseEntity
{
public:
	CBaseEntity();
	CBaseEntity(LPDIRECT3DDEVICE9);
	~CBaseEntity();

	virtual bool initEntity()								= 0;
	virtual void updateEntity(float deltaTime)				= 0;
	virtual void updateEntity(CKeyBoard device)				= 0;
	virtual void updateEntity(RECT rectCamera)				= 0;
	virtual void drawEntity()								= 0;

protected:
	CState*				m_State;

};

#endif