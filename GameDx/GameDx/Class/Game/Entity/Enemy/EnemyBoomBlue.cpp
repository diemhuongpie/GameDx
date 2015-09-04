#include "Game\Entity\Enemy\EnemyBoomBlue.h"
#include "Game\Entity\Bullet\BulletManager.h"


CEnemyBoomBlue::CEnemyBoomBlue(vector3d position)
{
	m_Position = position;
	this->initEntity();
}


CEnemyBoomBlue::~CEnemyBoomBlue()
{
}

bool CEnemyBoomBlue::initEntity()
{
	m_isDead = false;
	m_delayTime = 0;
	// LOAD SPRITE
	
	this->loadSprite();
	this->m_Bounding = new CBox2D(m_Position.x, m_Position.y, m_listSprite.at(0)->getFrameInfo().Width, m_listSprite.at(0)->getFrameInfo().Height);

	return true;

}


bool CEnemyBoomBlue::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(L"Resource//Image//Game//Sprites//BossBoomMan//enemy_boom_blue.png", 1, 1, 1, 0));

	return true;
}

void CEnemyBoomBlue::resetObject()
{

	m_isDead = false;
	m_delayTime = 0;
}

void CEnemyBoomBlue::updateEntity(CKeyBoard *device)
{
	if (device->KeyDown(DIK_I))
	{
		resetObject();
	}
}

void CEnemyBoomBlue::updateEntity(CBaseEntity* entity)
{
	if (entity->getTagNode() == "PlayerBullet" && CBox2D::Intersect(this->getBounding(), entity->getBounding()))
	{
		m_heath--;
	}
}

void CEnemyBoomBlue::updateEntity(float deltaTime)
{
	m_Position.x += m_Velocity.x*deltaTime/60;
	m_Position.y += m_Velocity.y*deltaTime/60;
	

	if (m_isDead == false)
	{
		m_delayTime++;
		if (m_delayTime > 0 && m_delayTime < 100)
		{
			m_Velocity.y = 5;
		}
		if (m_delayTime > 100 && m_delayTime < 120)
		{
			m_Velocity.y = 0;
			if (m_Velocity.y == 0)
				CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::ENEMY_PART_BOOM, this->m_Position);
		}
		if (m_delayTime > 120 && m_delayTime < 250)
		{
			m_Velocity.y = -7;
		}

		if (m_delayTime > 250)
		{
			m_isDead = true;
			m_delayTime = 0;
		}
	}
	

	//OutputDebugString(L"Count: ");
	//OutputDebugString(_itow(m_Velocity.x, new WCHAR[1], 10));


}

void CEnemyBoomBlue::updateEntity(RECT rectCamera)
{

}

void CEnemyBoomBlue::drawEntity()
{
	if (m_isDead == false)
	{
		this->m_listSprite[0]->Render(CCamera::setPositionEntity(m_Position), vector2d(1.0, 1.0), 0.0f, DRAWCENTER_MIDDLE_MIDDLE, true, 5);
	}
		
}


