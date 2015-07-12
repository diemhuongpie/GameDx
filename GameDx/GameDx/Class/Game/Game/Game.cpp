#include "Game\Game\Game.h"
#include "Framework\Sprite.h"


CGame::CGame(HINSTANCE hInstance)
{
	m_Windows	= new CWindows(hInstance);
	m_Windows->initWindowGame();

	CSprite::initSpriteHandler(m_Windows->getSpriteHandler());
	m_Keyboard	= new CKeyBoard(hInstance, m_Windows->getWindowHandler());

	this->initGame();
}

CGame::~CGame()
{
}


void CGame::initGame()
{
	beginScene = new CMenuScene(m_Windows->getDevice());
}
void CGame::updateGame()
{
	m_Keyboard->Update();
	//CCamera::getInstance()->Update();

	if (m_Keyboard->KeyDown(DIK_ESCAPE))
		PostQuitMessage(0);

}
void CGame::renderGame()
{
	if (this->m_Windows->startDraw()) {
		beginScene->renderScene();
	}
	this->m_Windows->stopDraw();
}