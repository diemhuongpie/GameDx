//

#include "EnemyTankRed.h"
#include "Framework\Camera.h"

CEnemyTankRed::CEnemyTankRed(vector3d position,bool dir)
{
	m_isLeft = dir;
	this->m_Position = position;
	m_checkState = 0;
	this->initEntity();
}


CEnemyTankRed::~CEnemyTankRed()
{
}


bool CEnemyTankRed::initEntity()
{
	m_delayTime = 0;
	m_delayShoot = 0;
	this->loadSprite();
	m_isDead = false;
	this->m_Bounding = new CBox2D(m_Position.x, m_Position.y, m_listSprite.at(0)->getFrameInfo().Width, m_listSprite.at(0)->getFrameInfo().Height);
	return true;
}

bool CEnemyTankRed::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(L"Resource//Image//Game//Sprites//BossCutMan//enemy_tank_red.png",1,4,4,0));
	this->m_listSprite.push_back(new CSprite(L"Resource//Image//Game//Sprites//BossCutMan//boom_burst.png", 1,4,4,0));
	return true;
}

void CEnemyTankRed::resetObject()
{}

void CEnemyTankRed::updateEntity(CBaseEntity *entity)
{
	if (entity->getTagNode() == "PlayerBullet" && CBox2D::Intersect(this->getBounding(), entity->getBounding()))
	{
		m_heath--;
	}
}
void CEnemyTankRed::updateEntity(float deltaTime)
{
	
	
	if (!m_isDead)
	{
		m_delayTime += deltaTime;
		if (m_delayTime > 0 && m_delayTime <= 1500)
			m_checkState = 0;
		if (m_delayTime > 1500 && m_delayTime <= 1800)
			m_checkState = 1;
		if (m_delayTime > 1800)
		{
			m_delayShoot += deltaTime;
			if (m_delayShoot > 450)
			{
				if (m_isLeft)
					CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::TANK_RED_L, vector3d(this->m_Position.x - 2 , this->m_Position.y, this->m_Position.z));
				else
					CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::TANK_RED_R, vector3d(this->m_Position.x + 2, this->m_Position.y, this->m_Position.z));
				m_delayShoot = 0;
			}
			m_checkState = 2;
		}

		if (m_delayTime > 4000)
			m_delayTime = 0;
	}
	
}

void CEnemyTankRed::updateEntity(CKeyBoard* device)
{

}

void CEnemyTankRed::drawEntity()
{
	if (!m_isDead)
	{
		if (m_isLeft)
		{
			if (m_checkState == 0)
			{
				m_listSprite.at(this->m_State)->Render(0, 0, CCamera::setPositionEntity(m_Position), vector2d(1.0f, 1.0f), 0.0f, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
			}
			if (m_checkState == 1)
			{
				m_listSprite.at(this->m_State)->Render(CCamera::setPositionEntity(m_Position), vector2d(1.0f, 1.0f), 0.0f, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
			}
			if (m_checkState == 2)
			{
				m_listSprite.at(this->m_State)->Render(3, 3, CCamera::setPositionEntity(m_Position), vector2d(1.0f, 1.0f), 0.0f, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
			}
			if (m_checkState == 3)
			{
				m_listSprite.at(this->m_State)->Render(0, 0, CCamera::setPositionEntity(m_Position), vector2d(1.0f, 1.0f), 0.0f, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
			}
		}
		else
		{
			if (m_checkState == 0)
			{
				m_listSprite.at(this->m_State)->Render(0, 0, CCamera::setPositionEntity(m_Position), vector2d(-1.0f, 1.0f), 0.0f, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
			}
			if (m_checkState == 1)
			{
				m_listSprite.at(this->m_State)->Render(CCamera::setPositionEntity(m_Position), vector2d(-1.0f, 1.0f), 0.0f, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
			}
			if (m_checkState == 2)
			{
				m_listSprite.at(this->m_State)->Render(3, 3, CCamera::setPositionEntity(m_Position), vector2d(-1.0f, 1.0f), 0.0f, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
			}
			if (m_checkState == 3)
			{
				m_listSprite.at(this->m_State)->Render(0, 0, CCamera::setPositionEntity(m_Position), vector2d(-1.0f, 1.0f), 0.0f, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
			}
		}
		
	}
	
	
}