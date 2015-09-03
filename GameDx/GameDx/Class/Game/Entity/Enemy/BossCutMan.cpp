#include "BossCutMan.h"

enum State_BossCutMan
{
	CUTMAN_STAND = 0,
	CUTMAN_RUN,
	CUTMAN_RUN_UN_WEAPON,
	CUTMAN_JUMP,
	CUTMAN_JUMP_UN_WEAPON,
	CUTMAN_GOT_HIT,
	CUTMAN_FIRE
};


CBossCutMan::CBossCutMan()
{
}

CBossCutMan::CBossCutMan(vector3d position)
{
	m_Position = position;
	this->initEntity();
}


CBossCutMan::~CBossCutMan()
{
}

bool CBossCutMan::initEntity()
{
	m_checkState = true;
	m_delayTime = 0;
	m_Weapon = new CCutManWeapon(m_Position);
	// LOAD SPRITE
	this->loadSprite();
	this->m_Bounding = new CBox2D(m_Position.x, m_Position.y, m_listSprite.at(0)->getFrameInfo().Width, m_listSprite.at(0)->getFrameInfo().Height);
	return true;

}


bool CBossCutMan::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(L"Resource//Image//Game//Sprites//BossCutMan//cutman_stand0.png", 1, 2, 2, 0));
	this->m_listSprite.push_back(new CSprite(L"Resource//Image//Game//Sprites//BossCutMan//cutman_run0.png", 1, 4, 4, 0));
	this->m_listSprite.push_back(new CSprite(L"Resource//Image//Game//Sprites//BossCutMan//cutman_run1.png", 1, 4, 4, 0));
	this->m_listSprite.push_back(new CSprite(L"Resource//Image//Game//Sprites//BossCutMan//cutman_jump0.png", 1, 1, 1, 0));
	this->m_listSprite.push_back(new CSprite(L"Resource//Image//Game//Sprites//BossCutMan//cutman_jump0.png", 1, 1, 1, 0));
	this->m_listSprite.push_back(new CSprite(L"Resource//Image//Game//Sprites//BossCutMan//cutman_collide.png", 1, 2, 2, 0));
	this->m_listSprite.push_back(new CSprite(L"Resource//Image//Game//Sprites//BossCutMan//cutman_fire0.png", 1, 2, 2, 0));
	return true;
}
void CBossCutMan::resetObject()
{

}

void CBossCutMan::updateEntity(CBaseEntity * player)
{
	if (m_delayTime > 0 && m_delayTime <= 500)
	{
		m_checkState = State_BossCutMan::CUTMAN_STAND;
		if (m_Position.y >= 400)
		{
			m_Velocity.y = 0;
		}
	}
	else
	{
		if (abs(m_Position.x - player->getPosition().x > 50))
		{
			
			m_checkState = State_BossCutMan::CUTMAN_RUN;
		}
		else
		{
			m_delayTime1++;
			if (m_delayTime1 > 0 && m_delayTime1 < 50)
			{
				//shot
				m_Weapon->updateEntity(player, this);
			}
			if (m_delayTime1 > 50)
			{
				if (m_isLeft == false)
				{
					m_Velocity.x = 3;
				}
				else
				{
					m_Velocity.x = -3;
				}
				m_Velocity.y = -6;
				m_checkState = State_BossCutMan::CUTMAN_JUMP;
			}

			if (m_delayTime1 > 90)
			{
				m_delayTime1 = 0;
			}
			
		}
		

	}

	if (m_Position.x > player->getPosition().x)
	{
		m_isLeft = true;
	}
	else
	{
		m_isLeft = false;
	}
}

void CBossCutMan::updateEntity(CKeyBoard *device)
{

}
void CBossCutMan::updateEntity(float deltaTime)
{
	m_Position.x += m_Velocity.x*deltaTime;
	m_Position.y += m_Velocity.y*deltaTime;
	m_delayTime	+= deltaTime;
	m_Weapon->updateEntity(deltaTime);
	
	if (m_delayTime >= 500)
		m_delayTime = 0;

	
	if (m_Position.y < 400)
	{
		m_Velocity.y++;
	}

}

void CBossCutMan::updateEntity(RECT rectCamera)
{

}

void  CBossCutMan::drawEntity()
{
	if (m_isLeft)
		this->m_listSprite[m_checkState]->Render(m_Position, vector2d(1.0, 1.0), 0.0f, DRAWCENTER_MIDDLE_MIDDLE, true, 5);
	else
		this->m_listSprite[m_checkState]->Render(m_Position, vector2d(-1.0, 1.0), 0.0f, DRAWCENTER_MIDDLE_MIDDLE, true, 5);
	m_Weapon->drawEntity();
}

