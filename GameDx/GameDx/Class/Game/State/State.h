/************************************************/
/* CREATE BY MICHAEL LE AND SHN TRUONG*/
/* 14/07/2015*/
/**********************************************/

#ifndef __CSTATE_H__
#define __CSTATE_H__

#include "Game\Utill\stdafx.h"
#include "Game\Utill\Config.h"

class CState
{
public:
	CState();
	CState(directDevice);
	~CState();
	virtual	const	char*	getTag()								= 0;
	virtual			void	setTag(char*)							= 0;
	virtual			void	switchState(CState*)					= 0;
	virtual			bool	loadSprite(directDevice device)			= 0;
	virtual			void	update(vector2d &Position)				= 0;
	/***********************UPDATE IF YOU NEED SOME ANOTHER FUCTION****************/
	virtual			void	render()								= 0;

private:
	char*				m_Tag;
};

#endif