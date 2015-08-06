#include "PlayScene.h"


CPlayScene::CPlayScene()
{
	//m_Player = new CPlayer();
}


CPlayScene::~CPlayScene()
{
}

bool	CPlayScene::initScene()
{
	//m_Player->initEntity();

	return true;
}

void	CPlayScene::updateScene(double deltaTime)
{
	//->updateEntity(deltaTime);

}

void	CPlayScene::updateScene(CKeyBoard* keyboard)
{
	if (keyboard->KeyPress(DIK_P))
		return;

	//m_Player->updateEntity(keyboard);
}

void	CPlayScene::renderScene()
{
	//m_Player->drawEntity();
}