/****************************************************************************/
/* Create by Michael Le*/
/* 07/07/2015 */
/***************************************************************************/


#ifndef __CGAME_H__
#define __CGAME_H__


#include "Game\Utill\stdafx.h"
#include "Framework\Windows.h"
#include "Game\Test\Test.h"
#include "Game\Scene\MenuScene.h"

class CGame
{
public:
	CGame(HINSTANCE hInstance);
	~CGame(void);

	void initGame();
	void updateGame();
	void renderGame();

private:
	CWindows*		m_Windows;
	CKeyBoard*		m_Keyboard;
	CMenuScene*		beginScene;
};

#endif
