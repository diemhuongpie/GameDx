/****************************************************************************/
/* Create by Michael Le*/
/* 08/07/2015 */
/***************************************************************************/


#ifndef __CBASEENTITY_H__
#define __CBASEENTITY_H__

#include "Game\Utill\stdafx.h"
#include "Game\Utill\Config.h"
#include "Framework\KeyBoard.h"
#include "Mathematics\Box2D.h"
#include "Framework\Sprite.h"

class CBaseEntity
{
public:
	
	CBaseEntity();
	CBaseEntity(directDevice);
	~CBaseEntity();

	virtual bool			initEntity()										= 0;
	virtual void			updateEntity(float deltaTime)						= 0;
	virtual void			updateEntity(CKeyBoard* deivce)						= 0;
	virtual void			drawEntity()										= 0;
	virtual	CBox2D			getBounding()										= 0;
	virtual const char*		getTagNode()										= 0;
	virtual int				getState()											= 0;
	virtual void			setState(int newState)								= 0;

protected:
	int						m_State;
	const char*				m_TagNode;
	CBox2D*					m_Bounding;
	vector3d				m_Position;
	vector<CSprite*>		m_listSprite;

};

#endif