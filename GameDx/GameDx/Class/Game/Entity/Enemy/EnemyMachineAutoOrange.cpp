#include "EnemyMachineAutoOrange.h"
#include "Game\Entity\Bullet\BulletManager.h"


CEnemyMachineAutoOrange::CEnemyMachineAutoOrange()
{
}

CEnemyMachineAutoOrange::CEnemyMachineAutoOrange(vector3d position,bool dir)
{
	this->m_TagNode = "Enemy";
	this->m_isTop = dir;
	this->m_heath = 1;
	this->m_Position = position;
	this->m_oldPosition = position;
	this->initEntity();
}


CEnemyMachineAutoOrange::~CEnemyMachineAutoOrange()
{
}

bool CEnemyMachineAutoOrange::initEntity()
{
	check_State = true;
	m_delayTime = 0;
	m_isDead = false;
	m_heath = 1;
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
	check_State = true;
	m_delayTime = 0;
	m_isDead = false;
	m_heath = 1;
	m_Position = m_oldPosition;
}

void CEnemyMachineAutoOrange::updateEntity(CKeyBoard *device)
{
}

void CEnemyMachineAutoOrange::updateEntity(CBaseEntity* entity)
{
	if (entity->getTagNode() == "PlayerBullet" && CBox2D::Intersect(this->getBounding(), entity->getBounding()))
	{
		m_heath--;
	}
}

void CEnemyMachineAutoOrange::updateEntity(float deltaTime)
{
	if (m_isDead == false)
	{
		m_delayTime += deltaTime;
		if (m_delayTime > 0 && m_delayTime < 500)
		{
			check_State = true;
		}
		if (m_delayTime >= 500)
		{
			check_State = false;
			if (m_isTop)
				CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::MACHINE_AUTO_ORANGE_T, vector3d(this->m_Position.x, this->m_Position.y - 2, this->m_Position.z));
			else
				CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::MACHINE_AUTO_ORANGE_B, vector3d(this->m_Position.x, this->m_Position.y + 2, this->m_Position.z));
		}
		if (m_delayTime > 2000)
			m_delayTime = 0;
	}

	if (m_heath == 0)
		m_State = 1;

	if (m_State == 1)
	{
		m_delayDeath += deltaTime;
		if (m_delayDeath > 500)
		{
			m_isDead = true;
			m_delayDeath = 0;
		}
	}
	
}

void CEnemyMachineAutoOrange::updateEntity(RECT rectCamera)
{

}

void  CEnemyMachineAutoOrange::drawEntity()
{
	if (m_isDead == false)
	{
		if (m_isTop)
		{
			if (check_State)
				this->m_listSprite[m_State]->Render(0, 0, CCamera::setPositionEntity(m_Position), vector2d(1.0, 1.0), 0.0f, DRAWCENTER_MIDDLE_MIDDLE, true, 3);
			else
				this->m_listSprite[m_State]->Render(1, 3, CCamera::setPositionEntity(m_Position), vector2d(1.0, 1.0), 0.0f, DRAWCENTER_MIDDLE_MIDDLE, true, 3);
		}
		else
		{
			if (check_State)
				this->m_listSprite[m_State]->Render(0, 0, CCamera::setPositionEntity(m_Position), vector2d(1.0, -1.0), 0.0f, DRAWCENTER_MIDDLE_MIDDLE, true, 3);
			else
				this->m_listSprite[m_State]->Render(1, 3, CCamera::setPositionEntity(m_Position), vector2d(1.0, -1.0), 0.0f, DRAWCENTER_MIDDLE_MIDDLE, true, 3);
		}
		
	}
}