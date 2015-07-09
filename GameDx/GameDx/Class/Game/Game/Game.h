#ifndef __CGAME_H__
#define __CGAME_H__


#include "Game\Utill\stdafx.h"
#include "Framework\Windows.h"
/****************************************************************************/
/* Create by Michael Le*/
/* 07/07/2015 */
/***************************************************************************/

#include "Game\Test\Test.h"

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
	Test*			m_Test;
};

#endif
