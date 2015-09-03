#include "PlayScene.h"
#include "SceneManager.h"
#include "PopUpScene.h"
#include "Game\Entity\Tile\Tile.h"

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
	m_Tag				= "PlayScene";
	m_Player			= new CPlayer();
	m_Player->initEntity();
	m_EnemyTankRed		= new CEnemyTankRed(D3DXVECTOR3(400, 100, 0));
	m_EnemyAutoOrange	= new CEnemyMachineAutoOrange(D3DXVECTOR3(200, 350, 0));
	m_EnemyBall			= new CEnemyBall();

	m_boomBlue			= new CEnemyBoomBlue(D3DXVECTOR3(250, 200, 0));
	m_Weapon			= new CCutManWeapon(m_EnemyTankRed->getPosition(), m_Player->getPosition());
	

	m_boomBlue = new CEnemyBoomBlue(D3DXVECTOR3(250, 200, 0));
	m_Weapon = new CCutManWeapon(m_EnemyTankRed->getPosition(), m_Player->getPosition());
	m_fireMan = new CBossFireMan(vector3d(350, 337, 0), m_Player->getPosition());


	CMapmanager::getInstance()->readMapList();
	CMapmanager::getInstance()->setCurrentMapAt(1);

	return true;
}

void	CPlayScene::updateScene(double deltaTime)
{
	// update Camera
	CCamera::getInstance()->Update(m_Player->getPosition());

	m_EnemyTankRed	->updateEntity(deltaTime);
	m_EnemyBall->updateEntity(deltaTime);
	m_EnemyAutoOrange->updateEntity(deltaTime);
	m_Weapon->updateEntity(deltaTime/60);
	m_boomBlue->updateEntity(deltaTime / 60);
	m_fireMan->updateEntity(deltaTime);

	
	// Update Bullet
	for (int i = 0; i < TYPE_BULLET::NUMBER_OF_TYPE_BULLET; ++i)
	{
		for (int j = 0; j < CBulletManager::getInstance()->getListBullet()[i].size(); j++)
		{
			CBulletManager::getInstance()->getListBullet()[i].at(j)->updateEntity(deltaTime);
		}
	}

	// Update Map
	//get List Collision Events
	CMapmanager::getInstance()->getCurrentMap()->update(deltaTime, m_Player);
	m_Player->updateEntity(deltaTime);
	// Handling Collision Events in List


}

void	CPlayScene::updateScene(CKeyBoard* keyboard)
{
	if (keyboard->KeyPress(DIK_P))
		return;
		
	m_EnemyAutoOrange	->updateEntity(keyboard);
	m_Player			->updateEntity(keyboard);
	m_EnemyBall			->updateEntity(keyboard);
	m_Weapon			->updateEntity(keyboard);
	m_boomBlue			->updateEntity(keyboard);

	if (keyboard->KeyPress(DIK_RETURN))
	{
		CSceneManager::getInstance()->getScene().push_back(new CPopUpScene());
	}
}

void	CPlayScene::renderScene()
{
	CMapmanager::getInstance()->getCurrentMap()->render();
	
	m_Player			->drawEntity();

	m_EnemyTankRed		->drawEntity();
	m_EnemyBall			->drawEntity();
	m_EnemyAutoOrange	->drawEntity();
	m_Weapon			->drawEntity();
	m_boomBlue			->drawEntity();
	m_fireMan			->drawEntity();

	for (int i = 0; i < TYPE_BULLET::NUMBER_OF_TYPE_BULLET; ++i)
	{
		for (int j = 0; j < CBulletManager::getInstance()->getListBullet()[i].size(); j++)
		{
			CBulletManager::getInstance()->getListBullet()[i].at(j)->drawEntity();
		}
	}

}