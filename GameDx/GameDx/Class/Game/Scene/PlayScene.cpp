#include "PlayScene.h"


CPlayScene::CPlayScene()
{
	this->initScene();
}

CPlayScene::~CPlayScene()
{
	SAFE_RELEASE(m_Player);
	SAFE_RELEASE(m_EnemyTankRed);
	SAFE_RELEASE(m_EnemyAutoOrange);

	SAFE_RELEASE(m_EnemyBall);
	SAFE_RELEASE(m_EnemyBubbleBlue);
	SAFE_RELEASE(m_EnemyCut);
}

bool	CPlayScene::initScene()
{
	//m_Player->initEntity();
	m_Tag				= "PlayScene";
	//map = new Map();
	//m_Player->initEntity();

	m_Player			= new CPlayer();
	m_EnemyTankRed = new CEnemyTankRed(D3DXVECTOR3(400, 100, 0));
	m_EnemyAutoOrange	= new CEnemyMachineAutoOrange(D3DXVECTOR3(200, 350, 0));
	m_EnemyBall			= new CEnemyBall();

	CMapmanager::getInstance()->readMapList();
	CMapmanager::getInstance()->setCurrentMapAt(1);
	return true;
}

void	CPlayScene::updateScene(double deltaTime)
{
	// update Camera
	CCamera::getInstance()->Update(m_Player->getPosition());

	m_Player		->updateEntity(deltaTime);
	m_EnemyTankRed	->updateEntity(deltaTime);
	m_EnemyBall->updateEntity(deltaTime);
	m_EnemyAutoOrange->updateEntity(deltaTime);

	/*for (auto i = 0; i < CMapmanager::getInstance()->getCurrentMap()->getlistCollisionTile().size(); ++i)
	{
		if (CCollision::CheckCollision(m_Player, CMapmanager::getInstance()->getCurrentMap()->getlistCollisionTile().at(i)) == COLDIRECTION::COLDIRECTION_BOTTOM)
			m_Player->setPosition(vector3d(CMapmanager::getInstance()->getCurrentMap()->getlistCollisionTile().at(i)->getBounding().getX(), CMapmanager::getInstance()->getCurrentMap()->getlistCollisionTile().at(i)->getBounding().getY() + CMapmanager::getInstance()->getCurrentMap()->getlistCollisionTile().at(i)->getBounding().getHeight(), 0.5f));
	}*/

	CCollision::CheckCollision(m_Player, m_EnemyTankRed);

	CBox2D::Intersect(m_Player->getBounding(), m_EnemyTankRed->getBounding());
	
	// Update Bullet
	for (int i = 0; i < TYPE_BULLET::NUMBER_OF_TYPE_BULLET; ++i)
	{
		for (int j = 0; j < CBulletManager::getInstance()->getListBullet()[i].size(); j++)
		{
			CBulletManager::getInstance()->getListBullet()[i].at(j)->updateEntity(deltaTime);
		}
	}

	// Update Map

}

void	CPlayScene::updateScene(CKeyBoard* keyboard)
{
	if (keyboard->KeyPress(DIK_P))
		return;
	m_EnemyAutoOrange->updateEntity(keyboard);
	m_Player->updateEntity(keyboard);
	m_EnemyBall->updateEntity(keyboard);

}

void	CPlayScene::renderScene()
{
	m_Player		->drawEntity();
	


	m_EnemyTankRed	->drawEntity();
	m_EnemyBall->drawEntity();
	m_EnemyAutoOrange->drawEntity();

	for (int i = 0; i < TYPE_BULLET::NUMBER_OF_TYPE_BULLET; ++i)
	{
		for (int j = 0; j < CBulletManager::getInstance()->getListBullet()[i].size(); j++)
		{
			CBulletManager::getInstance()->getListBullet()[i].at(j)->drawEntity();
		}
	}

	CMapmanager::getInstance()->getCurrentMap()->render();
}