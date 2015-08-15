#ifndef __CBASESCENE_H__
#define __CBASESCENE_H__

#include "Game\Utill\stdafx.h"
#include "Framework\KeyBoard.h"

class CBaseScene
{
public:
	CBaseScene(){};
	~CBaseScene(){};

	virtual bool				initScene()						= 0;
	virtual void				updateScene(double deltaTime)	= 0;
	virtual void				updateScene(CKeyBoard*)			= 0;
	virtual void				renderScene()					= 0;

protected:
	const char*					m_Tag;
};

#endif
