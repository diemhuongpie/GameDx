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
	m_delay_Time = 0;
	// LOAD SPRITE
	this->loadSprite();
	return true;

}


bool CEnemyMachineAutoOrange::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(L"Resource//Image//Game//Sprites//BossCutMan//enemy_machine_auto_orange.png", 1, 4, 4, 0));
	this->m_listSprite.push_back(new CSprite(L"Resource//Image//Game//Sprites//BossCutMan//boom_burst.png", 1, 4, 4, 0));
	return true;
}
void CEnemyMachineAutoOrange::updateEntity(CKeyBoard *device)
{
}
void CEnemyMachineAutoOrange::updateEntity(float deltaTime)
{
	m_delay_Time += deltaTime;
	if (m_delay_Time > 0 && m_delay_Time < 500)
	{
		check_State = true;
	}
	if (m_delay_Time >= 1000)
	{
		check_State		= false;
		CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::MACHINE_AUTO_ORANGE, this->m_Position);
	}
	if (m_delay_Time > 2000)
		m_delay_Time = 0;
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