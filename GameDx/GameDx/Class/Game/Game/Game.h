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
#include "Game\Scene\SelectStageScene.h"

class CGame
{
public:
	CGame(HINSTANCE hInstance);
	~CGame(void);

	void initGame();
	void updateGame();
	void renderGame();

private:
	CWindows*				m_Windows;
	CKeyBoard*				m_Keyboard;
	CSelectStageScene*		beginScene;
	Test*					m_Test;
};

#endif
