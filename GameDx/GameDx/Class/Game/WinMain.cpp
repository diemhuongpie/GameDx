/****************************************************************************/
/* Create by Michael Le*/
/* 07/07/2015 */
/***************************************************************************/


#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif


#include "Game\Utill\stdafx.h"
#include "Game\Utill\Config.h"
#include "Game\Game\Game.h"
#include "Game\Scene\MenuScene.h"

int CALLBACK WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	CGame* game = new CGame(hInstance);
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	int stateGame = GAMESTATE::STATE_RUN;
	while (stateGame)
	{
		CTimer::getInstance()->begin();
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				stateGame = GAMESTATE::STATE_END;
				SAFE_RELEASE(game);
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		if (stateGame == GAMESTATE::STATE_RUN)
		{
			game->updateGame(CTimer::getInstance()->getElapedTime());
			game->renderGame();
		}


		CTimer::getInstance()->end();
		CTimer::getInstance()->setElapedTime();
		if (CTimer::getInstance()->getElapedTime() < GAME_RATE)
		{
			SleepEx((DWORD)fabs(GAME_RATE - (CTimer::getInstance()->getElapedTime())), FALSE);
			CTimer::getInstance()->end();
			CTimer::getInstance()->setElapedTime();
		}
	}
	return 0;
}