/****************************************************************************/
/* Create by Michael Le*/
/* 07/07/2015 */
/***************************************************************************/


#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif


#include "Game\Utill\stdafx.h"
#include "Game\Game\Game.h";
#include "Game\Scene\MenuScene.h"

int CALLBACK WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	CGame* game = new CGame(hInstance);
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	int stateGame = GAMESTATE::STATE_RUN;
	clock_t start;
	while (stateGame)
	{
		start = clock();
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) stateGame = GAMESTATE::STATE_END;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		game->updateGame();
		game->renderGame();

		CTimer::getInstance()->setTime(clock() - start);
		if (CTimer::getInstance()->getTime() < FRAME_RATE)
			SleepEx((DWORD)fabs(FRAME_RATE - (CTimer::getInstance()->getTime())), FALSE);

		CTimer::getInstance()->setTime(clock() - start);

		OutputDebugString(L"FPS: ");
		OutputDebugString(_itow((1000.0f / CTimer::getInstance()->getTime()), new WCHAR[1], 10));
		OutputDebugString(L"\n");
	}
	return 0;
}