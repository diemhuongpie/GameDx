#ifndef __CBASESCENE_H__
#define __CBASESCENE_H__

#include "Game\Utill\stdafx.h"
#include "Framework\KeyBoard.h"

class CBaseScene
{
public:
	CBaseScene(){};
	~CBaseScene(){};

	virtual bool initScene(LPDIRECT3DDEVICE9)		= 0;
	virtual void updateScene()						= 0;
	virtual void updateScene(CKeyBoard*)			= 0;
	virtual void renderScene()						= 0;
};

#endif