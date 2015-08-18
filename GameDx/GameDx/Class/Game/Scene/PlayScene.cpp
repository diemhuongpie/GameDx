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
	m_Tag				= "PlayScene";
	//map = new Map();
	//m_Player->initEntity();

	m_Player			= new CPlayer();
	m_EnemyTankRed		= new CEnemyTankRed();
	m_EnemyAutoOrange	= new CEnemyMachineAutoOrange(D3DXVECTOR3(200, 200, 0));
	//m_EnemyBall = new CEnemyBall();


	return true;
}

void	CPlayScene::updateScene(double deltaTime)
{
	// update Camera
	CCamera::getInstance()->Update(m_Player->getPosition());

	m_Player		->updateEntity(deltaTime);
	m_EnemyTankRed	->updateEntity(deltaTime);

	m_EnemyAutoOrange->updateEntity(deltaTime);

	CCollision::CheckCollision(m_Player, m_EnemyTankRed);
	CBox2D::Intersect(m_Player->getBounding(), m_EnemyTankRed->getBounding());
	
	for (int i = 0; i < TYPE_BULLET::NUMBER_OF_TYPE_BULLET; ++i)
	{
		for (int j = 0; j < CBulletManager::getInstance()->getListBullet()[i].size(); j++)
		{
			CBulletManager::getInstance()->getListBullet()[i].at(j)->updateEntity(deltaTime);
		}
	}
}

void	CPlayScene::updateScene(CKeyBoard* keyboard)
{
	if (keyboard->KeyPress(DIK_P))
		return;
	m_EnemyAutoOrange->updateEntity(keyboard);
	m_Player->updateEntity(keyboard);
}

void	CPlayScene::renderScene()
{
	m_Player		->drawEntity();
	m_EnemyTankRed	->drawEntity();

	m_EnemyAutoOrange->drawEntity();

	for (int i = 0; i < TYPE_BULLET::NUMBER_OF_TYPE_BULLET; ++i)
	{
		for (int j = 0; j < CBulletManager::getInstance()->getListBullet()[i].size(); j++)
		{
			CBulletManager::getInstance()->getListBullet()[i].at(j)->drawEntity();
		}
	}
}