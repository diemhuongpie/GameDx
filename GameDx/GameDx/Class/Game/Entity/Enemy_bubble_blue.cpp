#include "Enemy_bubble_blue.h"


CEnemy_bubble_blue::CEnemy_bubble_blue()
{
	this->initEntity();
}


CEnemy_bubble_blue::~CEnemy_bubble_blue()
{
}

bool CEnemy_bubble_blue::initEntity()
{
	m_Position = D3DXVECTOR3(500.0f, 100.0f, 0.0f);
	x = 1;
	m_count = 0;
	// LOAD SPRITE
	this->loadSprite();
	return true;

}


bool CEnemy_bubble_blue::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(L"Resource//Image//Game//Sprites//BossCutMan//enemy_bubble_blue.png", 1, 2, 2, 0));
	return true;
}

void  CEnemy_bubble_blue::enemyMoving()
{
	switch (x)
	{
	case 1:
		m_position1 = D3DXVECTOR3(300.0f, 300, 0.0f); //m_position1.x = toadonv.x + 100
		break;
	case 2:
		m_position1 = D3DXVECTOR3(200.0f, 250.0f, 0.0f);
		break;
	case 3:
		m_position1 = D3DXVECTOR3(100.0f, 300, 0.0f); //m_position1.x = toadonv.x - 100
		break;
	}
}
void CEnemy_bubble_blue::updateEntity(CKeyBoard *device, float deltaTime)
{
	if (m_Position.x > m_position1.x)
	{
		m_speedX = -3 * cos(m_angle);
		m_dx = m_Position.x - m_position1.x;
	}
	else
	{
		m_dx = m_position1.x - m_Position.x;
		m_speedX = 3 * cos(m_angle);
	}
	if (m_Position.y > m_position1.y)
	{
		m_dy = m_Position.y - m_position1.y;
		m_speedY = -2 * sin(m_angle);
	}
	else
	{
		m_dy = m_position1.y - m_Position.y;
		m_speedY = 2 * sin(m_angle);
	}
	m_Velocity = D3DXVECTOR2(m_speedX, m_speedY);

	m_angle = (float)atan(m_dy / m_dx);

	if (m_dx < 0)
	{
		m_angle -= PI / 2;
	}
	if (m_Position.x <= 300 && m_Position.x >= 290)
	{
		x = 2;
		m_count--;
	}
	if (m_Position.x <= 200 && m_Position.x >= 190 && m_Position.y <= 260)
	{
		if (m_count == 1)
			x = 1;
		else
			x = 3;
	}
	if (m_Position.x <= 105)
	{
		x = 2;
		m_count++;
	}
	enemyMoving();
	this->m_Position.x += this->m_Velocity.x*deltaTime;
	this->m_Position.y += this->m_Velocity.y*deltaTime;

	if (m_Velocity.x > 0)
	{
		m_isLEFT = false;
	}
	else
	{
		m_isLEFT = true;
	}
}

void CEnemy_bubble_blue::updateEntity(RECT rectCamera)
{
	
	
}

void  CEnemy_bubble_blue::drawEntity()
{
	if (m_isLEFT)
	{
		this->m_listSprite[0]->Render(m_Position, vector2d(1.0f, 1.0f));
	}
	else
	{
		this->m_listSprite[0]->Render(m_Position, vector2d(1.0f, 1.0f));
	}

}