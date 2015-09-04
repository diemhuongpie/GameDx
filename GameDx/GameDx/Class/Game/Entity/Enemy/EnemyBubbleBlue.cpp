#include "EnemyBubbleBlue.h"


CEnemyBubbleBlue::CEnemyBubbleBlue(vector3d position)
{
	this->m_Position = position;
	this->m_oldPosition = position;
	this->m_heath = 1;
	this->initEntity();
	this->m_TagNode = "Enemy";
	m_isDead = false;
}


CEnemyBubbleBlue::~CEnemyBubbleBlue()
{
}

bool CEnemyBubbleBlue::initEntity()
{
	m_Velocity = vector2d(0, 0);
	this->loadSprite();
	this->m_Bounding = new CBox2D(m_Position.x, m_Position.y, m_listSprite.at(0)->getFrameInfo().Width, m_listSprite.at(0)->getFrameInfo().Height);
	m_delayTime = 0;
	x = 1;
	m_count = 0;
	// LOAD SPRITE
	
	return true;

}


bool CEnemyBubbleBlue::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(L"Resource//Image//Game//Sprites//BossCutMan//enemy_bubble_blue.png", 1, 2, 2, 0));
	this->m_listSprite.push_back(new CSprite(L"Resource//Image//Game//Sprites//BossCutMan//boom_burst.png", 1, 4, 4, 0));
	return true;
}
void CEnemyBubbleBlue::resetObject()
{
	this->m_heath = 1;
	
	m_Position = m_oldPosition;
	m_delayTime = 0;
	x = 1;
	m_count = 0;
	m_isDead = false;
}

void  CEnemyBubbleBlue::enemyMoving(vector3d position_p)
{
	switch (x)
	{
	case 1:
		m_position1.x  = position_p.x + 60 ; //m_position1.x = toadonv.x + 100
		m_position1.y = position_p.y + 40;
		break;
	case 2:
		m_position1.x = position_p.x;
		m_position1.y = position_p.y;

		break;
	case 3:
		m_position1.x = position_p.x - 60; //m_position1.x = toadonv.x + 100
		m_position1.y = position_p.y + 40;
		break;
	}
}
void CEnemyBubbleBlue::updateEntity(CKeyBoard *device)
{
	if (device->KeyDown(DIK_J))
	{
		//m_heath = 0;
		x++;
		if (x > 3)
			x = 1;
	}
	if (device->KeyDown(DIK_K))
	{
		resetObject();
	}
}

void CEnemyBubbleBlue::updateEntity(RECT rectCamera)
{
}

void CEnemyBubbleBlue::updateEntity(float deltaTime)
{
	OutputDebugString(L"VELX: ");
	OutputDebugString(_itow(m_Position.x, new WCHAR[1], 10));
	OutputDebugString(L"\n");
	OutputDebugString(L"VELY: ");
	OutputDebugString(_itow(m_Velocity.x, new WCHAR[1], 10));
	OutputDebugString(L"\n");

	if (m_isDead == false)
	{
		if (m_checkState)
		{
			if (m_Position.x > m_position1.x)
			{
				m_dx = m_Position.x - m_position1.x;
				m_speedX = -3 * cos(m_angle);
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

			if (m_dx < 0)
			{
				m_angle -= PI / 2;
			}
			if (m_delayTime > 0 && m_delayTime < 25)
			{
				x = 2;
				m_count--;
			}
			if (m_delayTime > 25 && m_delayTime < 50)
			{
				x = 3;
			}
			if (m_delayTime > 50 && m_delayTime < 75)
			{
				x = 2;
			}
			if (m_delayTime > 105)
			{
				x = 1;
				m_count++;
			}
			m_angle = (float)atan(m_dy / m_dx);
			this->m_Position.x += m_speedX*deltaTime / 60;
			this->m_Position.y += m_speedY*deltaTime / 60;

		}
		else
		{
			this->m_Position.x += -15 * deltaTime / 60;
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

	if (m_Velocity.x > 0)
	{
		m_isLEFT = false;
	}
	else
	{
		m_isLEFT = true;
	}
}
void CEnemyBubbleBlue::updateEntity(CBaseEntity *player)
{
	/*if (bullet->getTagNode ==  "PlayerBullet" && CBox2D::Intersect(this->getBounding(),bullet->getBounding()))
	{
		m_heath--;
	}*/

	enemyMoving(player->getPosition());
	if (m_isDead == false)
	{
		m_delayTime++;
		if (player->getPosition().x - m_Position.x < 50)
		{
			m_checkState = true;
		}
	}
	if (m_delayTime > 130)
	{
		m_delayTime = 0;
	}
}

void  CEnemyBubbleBlue::drawEntity()
{
	if (m_isDead == false)
	{
		if (m_isLEFT)
		{
			this->m_listSprite[m_State]->Render(CCamera::setPositionEntity(m_Position), vector2d(1.0f, 1.0f));
		}
		else
		{
			this->m_listSprite[m_State]->Render(CCamera::setPositionEntity(m_Position), vector2d(1.0f, 1.0f));
		}

	}
	
}
