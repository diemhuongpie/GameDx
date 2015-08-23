#include "Game\Entity\Enemy\CutManWeapon.h"


CCutManWeapon::CCutManWeapon(vector3d position, vector3d position_p)
{
	m_Position = position;
	m_PositionBoss = position;
	m_PositionPlayer = position_p;
	this->initEntity();
}


CCutManWeapon::~CCutManWeapon()
{
}

bool CCutManWeapon::initEntity()
{
	m_isDead = false;
	m_count = 0;
	m_dy = 0;
	m_dx = 0;
	// LOAD SPRITE
	this->loadSprite();
	return true;

}


bool CCutManWeapon::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(L"Resource//Image//Game//Sprites//BossCutMan//weapon_cut.png", 1, 4, 4, 0));

	return true;
}

void CCutManWeapon::logicCollision(CBaseEntity* entity)
{
	
}
void CCutManWeapon::resetObject()
{
	m_Position = m_PositionBoss;
	m_isDead = false;
	m_count = 0;
	m_dy = 0;
	m_dx = 0;
}

void CCutManWeapon::updateEntity(CKeyBoard *device)
{
	if (device->KeyDown(DIK_H))
	{
		resetObject();
	}
}
	

void CCutManWeapon::moveTo(vector3d m_Position, vector3d m_PositionPlayer)
{
	if (m_Position.x > m_PositionPlayer.x)
	{
		m_Velocity.x = -3 * cos(m_angle);
		m_dx = m_Position.x - m_PositionPlayer.x;
	}
	else
	{
		m_dx = m_PositionPlayer.x - m_Position.x;
		m_Velocity.x = 3 * cos(m_angle);
	}
	if (m_Position.y > m_PositionPlayer.y)
	{
		m_dy = m_Position.y - m_PositionPlayer.y;
		m_Velocity.y = -2 * sin(m_angle);
	}
	else
	{
		m_dy = m_PositionPlayer.y - m_Position.y;
		m_Velocity.y = 2 * sin(m_angle);
	}
	if (m_dx < 0)
	{
		m_angle -= PI / 2;
	}

}
void CCutManWeapon::updateEntity(float deltaTime)
{
	if (m_isDead == false)
	{
		if (m_count == 0)
		{
			moveTo(m_Position, m_PositionPlayer);
		}
		if (m_count == 1)
		{
			moveTo(m_Position, m_PositionBoss);
		}

		m_angle = (float)atan(m_dy / m_dx);

		m_Position.x += m_Velocity.x*deltaTime;
		m_Position.y += m_Velocity.y*deltaTime;
	}



	if (abs(m_Position.x - m_PositionPlayer.x) < 2 || abs(m_Position.y - m_PositionPlayer.y) < 2
		|| ((abs(m_Position.x - m_PositionBoss.x) < 3 || abs(m_Position.y - m_PositionBoss.y) < 3) && m_count > 0))
	{
		m_count++;
	}
	OutputDebugString(L"Count: ");
	OutputDebugString(_itow(m_count, new WCHAR[1], 10));
	
		

	

	if (m_count >= 2)
	{
		m_isDead = true;
		m_count = 0;
	}
}

void CCutManWeapon::updateEntity(RECT rectCamera)
{

}

void CCutManWeapon::drawEntity()
{
	if (m_isDead == false)
		this->m_listSprite[0]->Render(m_Position, vector2d(-1.0, 1.0), 0.0f, DRAWCENTER_MIDDLE_MIDDLE, true, 5);
}


