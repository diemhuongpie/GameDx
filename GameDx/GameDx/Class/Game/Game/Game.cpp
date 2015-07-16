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
	SAFE_RELEASE(m_Windows);
	SAFE_RELEASE(m_Keyboard);
	SAFE_RELEASE(m_Test);
	SAFE_RELEASE(beginScene);
}


void CGame::initGame()
{
	beginScene	= new CSelectStageScene(m_Windows->getDevice());
	m_Test		= new Test(m_Windows->getDevice());
}
void CGame::updateGame()
{
	m_Keyboard->Update();
	m_Test->Update(m_Keyboard);
	CCamera::getInstance()->Update(m_Test->getPosision());

	if (m_Keyboard->KeyDown(DIK_ESCAPE))
		PostQuitMessage(0);

}
void CGame::renderGame()
{
	if (this->m_Windows->startDraw()) {
		beginScene->renderScene();
		m_Test->Render();
	}
	this->m_Windows->stopDraw();
}