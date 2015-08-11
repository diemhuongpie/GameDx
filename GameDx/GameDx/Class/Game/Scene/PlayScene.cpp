#include "PlayScene.h"


CPlayScene::CPlayScene()
{
	this->initScene();
}


CPlayScene::~CPlayScene()
{
}

bool	CPlayScene::initScene()
{
	//m_Player->initEntity();

	m_Player = new CPlayer();
	m_EnemyTankRed = new CEnemyTankRed();

	//m_EnemyBall = new CEnemyBall();

	return true;
}

void	CPlayScene::updateScene(double deltaTime)
{
	m_Player->updateEntity(deltaTime);
	m_EnemyTankRed->updateEntity(deltaTime);

	CCollision::CheckCollision(m_Player, m_EnemyTankRed);
}

void	CPlayScene::updateScene(CKeyBoard* keyboard)
{
	if (keyboard->KeyPress(DIK_P))
		return;

	m_Player->updateEntity(keyboard);
}

void	CPlayScene::renderScene()
{
	m_Player->drawEntity();
	m_EnemyTankRed->drawEntity();
}