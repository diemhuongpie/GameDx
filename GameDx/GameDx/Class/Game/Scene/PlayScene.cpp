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
	m_Tag			= "PlayScene";
	//map = new Map();
	//m_Player->initEntity();

	m_Player			= new CPlayer();
	m_EnemyTankRed		= new CEnemyTankRed();
	m_BulletManager		= new CBulletManager();
	//m_EnemyBall = new CEnemyBall();

	return true;
}

void	CPlayScene::updateScene(double deltaTime)
{

	CCamera::getInstance()->Update(m_Player->getPosition());

	m_Player		->updateEntity(deltaTime);
	m_EnemyTankRed	->updateEntity(deltaTime);

	CCollision::CheckCollision(m_Player, m_EnemyTankRed);
	CBox2D::Intersect(m_Player->getBounding(), m_EnemyTankRed->getBounding());
	m_BulletManager->updateBullet(deltaTime);
	
	OutputDebugString(L"IS INTERSECT: ");
	OutputDebugString(_itow(CBox2D::Intersect(m_Player->getBounding(), m_EnemyTankRed->getBounding()), new WCHAR[1], 10));
	OutputDebugString(L"\n");
}

void	CPlayScene::updateScene(CKeyBoard* keyboard)
{
	if (keyboard->KeyPress(DIK_P))
		return;

	m_Player->updateEntity(keyboard);
}

void	CPlayScene::renderScene()
{
	m_Player		->drawEntity();
	m_EnemyTankRed	->drawEntity();

	m_BulletManager	->renderBullet();
	//map->drawEntity();
}