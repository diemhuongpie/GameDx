#include "BossFireMan.h"
#include "Game\Entity\Bullet\BulletManager.h"


CBossFireMan::CBossFireMan(vector3d position, vector3d position_player)
{
	this->m_State = 0;
	this->m_Position = position;
	this->m_PositionPlayer = position_player;
	this->initEntity();
}


CBossFireMan::~CBossFireMan()
{
}


bool CBossFireMan::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(L"Resource//Image//Game//Sprites//fireman//stand.png", 1, 2, 2, 0));
	this->m_listSprite.push_back(new CSprite(L"Resource//Image//Game//Sprites//fireman//fire.png", 1, 2, 2, 0));
	this->m_listSprite.push_back(new CSprite(L"Resource//Image//Game//Sprites//fireman//run.png", 1, 3, 3, 0));
	this->m_listSprite.push_back(new CSprite(L"Resource//Image//Game//Sprites//fireman//jump.png", 1, 1, 1, 0));
	return true;
}
bool CBossFireMan::initEntity()
{
	this->loadSprite();
	this->m_Bounding = new CBox2D(m_Position.x, m_Position.y, m_listSprite.at(m_State)->getFrameInfo().Width, m_listSprite.at(m_State)->getFrameInfo().Height);
	m_isDead = false;
	m_heath = 100;
	return true;
}

void CBossFireMan::resetObject()
{

}
void CBossFireMan::updateEntity(CBaseEntity* entity)
{
}
void CBossFireMan::updateEntity(CKeyBoard *device)
{

}
void CBossFireMan::updateEntity(float deltaTime)
{

	if (abs(m_Position.x - m_PositionPlayer.x) > 200)
	{
		this->m_State = 1;
		m_Velocity.x = 0;
	
		if (m_Position.x > m_PositionPlayer.x)
		{
			m_isLeft = true;
			CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::BOSS_FIRE_MAN, this->m_Position, vector2d(-3,0));
		}
		if (m_Position.x < m_PositionPlayer.x)
		{
			CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::BOSS_FIRE_MAN, this->m_Position, vector2d(3, 0));
			m_isLeft = false;
		}
		
	}
	else
	{
		this->m_State = 2;
		if (m_Position.x > m_PositionPlayer.x)
		{
			m_isLeft = false;
			m_Velocity.x = 3;
		}
		if (m_Position.x < m_PositionPlayer.x)
		{
			m_isLeft = true;
			m_Velocity.x = -3;
		}
	}

	m_Position.x += m_Velocity.x*deltaTime / 60;
	m_Position.y += m_Velocity.y*deltaTime / 60;
	m_delayTime++;
	
}

void CBossFireMan::updateEntity(RECT rectCamera)
{

}

void  CBossFireMan::drawEntity()
{
	if (m_isLeft)
		this->m_listSprite[m_State]->Render(CCamera::setPositionEntity(m_Position), vector2d(1.0, 1.0), 0.0f, DRAWCENTER_MIDDLE_MIDDLE, true, 5);
	else
		this->m_listSprite[m_State]->Render(CCamera::setPositionEntity(m_Position), vector2d(-1.0, 1.0), 0.0f, DRAWCENTER_MIDDLE_MIDDLE, true, 5);
}


