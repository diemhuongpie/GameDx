#include "EnemyFishOrange.h"


CEnemyFishOrange::CEnemyFishOrange()
{
}

CEnemyFishOrange::CEnemyFishOrange(vector3d position)
{
	m_Position = position;
	m_CurrentPosition = position;
	m_Velocity.x = -3.5;
	m_heath = 1;
	m_Velocity.y = 2; 
	this->loadSprite();
	this->m_Bounding = new CBox2D(m_Position.x, m_Position.y, m_listSprite.at(0)->getFrameInfo().Width, m_listSprite.at(0)->getFrameInfo().Height);
	
}


CEnemyFishOrange::~CEnemyFishOrange()
{
}

bool CEnemyFishOrange::initEntity()
{
	// LOAD SPRITE
	
	this->loadSprite();
	return true;
}


bool CEnemyFishOrange::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(L"Resource//Image//Game//Sprites//BossBoomMan//enemy_fish_orange.png", 1, 1, 1, 0));
	this->m_listSprite.push_back(new CSprite(L"Resource//Image//Game//Sprites//BossCutMan//boom_burst.png", 1, 4, 4, 0));
	return true;
}

void CEnemyFishOrange::resetObject()
{
	m_CurrentPosition = m_Position;
	m_Velocity.x = -3.5;
	m_heath = 1;
	m_Velocity.y = 2;
	m_isDead = false;
}
void CEnemyFishOrange::updateEntity(CBaseEntity *entity)
{
	if (entity->getTagNode() == "PlayerBullet" && CBox2D::Intersect(this->getBounding(), entity->getBounding()))
	{
		m_heath--;
	}
}
void CEnemyFishOrange::updateEntity(CKeyBoard *device)
{}

void CEnemyFishOrange::updateEntity(float deltaTime)
{
	if (m_isDead == false)
	{
		this->m_Position.x += this->m_Velocity.x*deltaTime;
		this->m_Position.y += this->m_Velocity.y*deltaTime;

		if (abs(m_Position.y - m_CurrentPosition.y) > 8)
		{
			m_Velocity.y *= -1;
		}
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

void CEnemyFishOrange::updateEntity(RECT rectCamera)
{

}

void CEnemyFishOrange::drawEntity()
{
	if (m_isDead == false)
		this->m_listSprite[m_State]->Render(0, 0, m_Position, vector2d(1.0, 1.0), 0.0f, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
}