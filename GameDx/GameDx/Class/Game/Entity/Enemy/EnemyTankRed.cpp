//

#include "EnemyTankRed.h"
#include "Framework\Camera.h"

CEnemyTankRed::CEnemyTankRed(vector3d position)
{
	this->m_Position = position;
	m_checkState = 0;
	this->initEntity();
}


CEnemyTankRed::~CEnemyTankRed()
{
}

//CEnemyTankRed::CEnemyTankRed(LPDIRECT3DDEVICE9)
//{
//	this->initEntity();
//}

bool CEnemyTankRed::initEntity()
{
	m_Position		= vector3d(80.0f, 300.0f, 0.5f);
	m_delayTime = 0;
	m_delayShoot = 0;
	this->loadSprite();

	this->m_Bounding = new CBox2D (0, 0 , 0, 0);
	return true;
}

bool CEnemyTankRed::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(L"Resource//Image//Game//Sprites//BossCutMan//enemy_tank_red.png",1,4,4,0));
	this->m_listSprite.push_back(new CSprite(L"Resource//Image//Game//Sprites//BossCutMan//boom_burst.png", 1,4,4,0));
	return true;
}

void CEnemyTankRed::updateEntity(float deltaTime)
{
	m_delayTime += deltaTime;
	

	if (m_delayTime > 0 && m_delayTime <= 1500)
		m_checkState = 0;
	if (m_delayTime > 1500 && m_delayTime <= 1800)
		m_checkState = 1;
	if (m_delayTime > 1800)
	{
		m_delayShoot += deltaTime;
		if (m_delayShoot > 400)
		{
			CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::TANK_RED, this->m_Position);
			m_delayShoot = 0;
		}
			
		m_checkState = 2;
	}

	if (m_delayTime > 3400)
		m_delayTime = 0;
}

void CEnemyTankRed::updateEntity(CKeyBoard* device)
{

}

void CEnemyTankRed::drawEntity()
{
	if (m_checkState == 0)
	{
		m_listSprite.at(this->m_State)->Render(0,0,CCamera::setPositionEntity(m_Position), vector2d(1.0f, 1.0f), 0.0f, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
	}
	if (m_checkState == 1)
	{
		m_listSprite.at(this->m_State)->Render(CCamera::setPositionEntity(m_Position), vector2d(1.0f, 1.0f), 0.0f, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
	}
	if (m_checkState == 2)
	{
		m_listSprite.at(this->m_State)->Render(3,3,CCamera::setPositionEntity(m_Position), vector2d(1.0f, 1.0f), 0.0f, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
	}
	
}