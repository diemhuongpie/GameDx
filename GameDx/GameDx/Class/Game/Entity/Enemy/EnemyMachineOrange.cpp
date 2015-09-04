#include "EnemyMachineOrange.h"


CEnemyMachineOrange::CEnemyMachineOrange()
{
}

CEnemyMachineOrange::CEnemyMachineOrange(vector3d position,int m_rangex)
{
	m_RangeX = m_rangex;
	this->m_Position = position;
	this->m_CurrentPosition = position;
	this->initEntity();
}



CEnemyMachineOrange::~CEnemyMachineOrange()
{
}

bool CEnemyMachineOrange::initEntity()
{
	// LOAD SPRITE
	m_Velocity.x = 5;
	m_heath = 1;
	this->loadSprite();
	this->m_Bounding = new CBox2D(m_Position.x, m_Position.y, m_listSprite.at(0)->getFrameInfo().Width, m_listSprite.at(0)->getFrameInfo().Height);
	
	return true;
}


bool CEnemyMachineOrange::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(L"Resource//Image//Game//Sprites//BossBoomMan//enemy_machine_orange.png", 1, 2, 2, 0));
	this->m_listSprite.push_back(new CSprite(L"Resource//Image//Game//Sprites//BossCutMan//boom_burst.png", 1, 4, 4, 0));
	return true;
}

void CEnemyMachineOrange::resetObject()
{
	m_Velocity.x = 5;
	m_heath = 1;
	m_isDead = false;
	m_Sign = false;
	m_Position = m_CurrentPosition;
}

void CEnemyMachineOrange::updateEntity(CKeyBoard *device)
{}

void CEnemyMachineOrange::updateEntity(CBaseEntity* player)
{
	if (abs(m_CurrentPosition.x - player->getPosition().x) < 100 && abs(m_CurrentPosition.y - player->getPosition().y) < 10)
	{
		m_Sign = true;
	}
	else
	{
		m_Sign = false;
	}
	if (m_Sign)
	{
		if (m_Position.x - player->getPosition().x > 3)
		{
			m_Velocity.x = -5;
		}
		else if (m_Position.x - player->getPosition().x < -3)
		{
			m_Velocity.x = 5;
		}
		else if (abs(m_CurrentPosition.x - player->getPosition().x) < 3)
		{
			m_Velocity.x *= 0.1;
		}
	}
	else
	{
		if (abs(m_CurrentPosition.x - m_Position.x) > m_RangeX)
		{
			m_Velocity.x *= -1;
		}
	}

}
void CEnemyMachineOrange::updateEntity(float deltaTime)
{
	this->m_Position.x += this->m_Velocity.x*deltaTime;
	this->m_Position.y += this->m_Velocity.y*deltaTime;

	

}

void CEnemyMachineOrange::updateEntity(RECT rectCamera)
{

}

void CEnemyMachineOrange::drawEntity()
{
	if (m_isDead == false)
	{
		this->m_listSprite[m_State]->Render(0, 0, m_Position, vector2d(1.0, 1.0), 0.0f, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
	}
	
}
