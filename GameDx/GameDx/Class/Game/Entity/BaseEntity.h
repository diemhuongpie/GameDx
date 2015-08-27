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
	virtual void			updateEntity(CBaseEntity*)							= 0;
	virtual void			drawEntity()										= 0;

	virtual	CBox2D			getBounding()										= 0;
	virtual vector3d		getPosition()										= 0;
	virtual void			setPosition(vector3d)								= 0;
	virtual char*			getTagNode()										= 0;
	virtual	void			setTagNode(char*)									= 0;
	virtual int				getState()											= 0;
	virtual void			setState(int newState)								= 0;
	virtual void			resetObject()										= 0;

protected:
	int						m_State;
	bool					m_isDead;
	char*					m_TagNode;
	CBox2D*					m_Bounding;
	vector3d				m_Position;
	vector<CSprite*>		m_listSprite;
	int						m_heath;
	float					m_delayDeath;

};

#endif