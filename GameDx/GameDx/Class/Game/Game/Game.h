/****************************************************************************/
/* Create by Michael Le*/
/* 07/07/2015 */
/***************************************************************************/


#ifndef __CGAME_H__
#define __CGAME_H__


#include "Framework\Windows.h"
#include "Framework\Camera.h"
#include "Game\Test\Test.h"
#include "Game\Utill\stdafx.h"
#include "Game\Scene\SceneManager.h"

class CGame
{
public:
	CGame(HINSTANCE hInstance);
	~CGame(void);

	void initGame();
	void updateGame(double deltaTime);
	void renderGame();

private:
	CWindows*				m_Windows;
	CKeyBoard*				m_Keyboard;
	Test*					m_Test;
};

#endif
