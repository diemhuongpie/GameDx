#include "EnemyMachineAutoOrange.h"
#include "Game\Entity\Bullet\BulletManager.h"


CEnemyMachineAutoOrange::CEnemyMachineAutoOrange()
{
}

CEnemyMachineAutoOrange::CEnemyMachineAutoOrange(vector3d position)
{
	this->m_Position = position;
	this->initEntity();
}


CEnemyMachineAutoOrange::~CEnemyMachineAutoOrange()
{
}

void CEnemyMachineAutoOrange::logicCollision(CBaseEntity* entity)
{

}

bool CEnemyMachineAutoOrange::initEntity()
{
	check_State = true;
	m_delayTime = 0;
	this->loadSprite();
	this->m_Bounding = new CBox2D(m_Position.x, m_Position.y, m_listSprite.at(0)->getFrameInfo().Width, m_listSprite.at(0)->getFrameInfo().Height);
	// LOAD SPRITE
	return true;

}


bool CEnemyMachineAutoOrange::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(L"Resource//Image//Game//Sprites//BossCutMan//enemy_machine_auto_orange.png", 1, 4, 4, 0));
	this->m_listSprite.push_back(new CSprite(L"Resource//Image//Game//Sprites//BossCutMan//boom_burst.png", 1, 4, 4, 0));
	return true;
}

void CEnemyMachineAutoOrange::resetObject()
{

}

void CEnemyMachineAutoOrange::updateEntity(CKeyBoard *device)
{
}

void CEnemyMachineAutoOrange::updateEntity(CBaseEntity* entity)
{
}

void CEnemyMachineAutoOrange::updateEntity(float deltaTime)
{
	m_delayTime += deltaTime;
	if (m_delayTime > 0 && m_delayTime < 500)
	{
		check_State = true;
	}
	if (m_delayTime >= 500)
	{
		check_State		= false;
		CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::MACHINE_AUTO_ORANGE, this->m_Position);
	}
	if (m_delayTime > 2000)
		m_delayTime = 0;
}

void CEnemyMachineAutoOrange::updateEntity(RECT rectCamera)
{

}

void  CEnemyMachineAutoOrange::drawEntity()
{
	if (check_State)
		this->m_listSprite[0]->Render(0, 0, CCamera::setPositionEntity(m_Position), vector2d(1.0, 1.0), 0.0f, DRAWCENTER_MIDDLE_MIDDLE, true, 3);
	else
		this->m_listSprite[0]->Render(1, 3, CCamera::setPositionEntity(m_Position), vector2d(1.0, 1.0), 0.0f, DRAWCENTER_MIDDLE_MIDDLE, true, 3);
}