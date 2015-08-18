#include "BulletEnemyBall.h"


CBulletEnemyBall::CBulletEnemyBall()
{
	initEntity();
}


CBulletEnemyBall::~CBulletEnemyBall()
{
}

bool CBulletEnemyBall::loadSprite()
{
	//for (int i = 0; i < 5; i ++)
	this->m_listSprite.push_back(new CSprite(L"Resource//Image//Game//Sprites//BossCutMan//enemy_bullet_orange.png", 1, 1, 1, 0));
	return	true;
}

bool CBulletEnemyBall::initEntity()
{
	m_Position = vector3d(100, 100, 0.5);

	for (int i = 0; i < 8; i++)
	{
		m_BulletPosition.push_back(vector3d(m_Position.x, m_Position.y, 0.5f));
		m_Bounding = new CBox2D(m_BulletPosition.at(0).x, m_BulletPosition.at(0).y, 32, 32);
	}
	m_State = BULLETSTATE::BULLET_STATE_INVIS;
	m_Velocity = vector2d(10, 10);
	m_TagNode = "N";

	this->loadSprite();

	return true;
}

void CBulletEnemyBall::updateEntity(float deltaTime)
{
	switch (m_State)
	{
	case BULLETSTATE::BULLET_STATE_INVIS:
		for (int i = 0; i < 8; i++)
			m_BulletPosition.at(i) = vector3dMinimum;
		break;
	case BULLETSTATE::BULLET_STATE_SHOW:
		if (deltaTime > 0)
		{
			Shoot(deltaTime / 60);
		}
		break;
	case BULLETSTATE::BULLET_STATE_HIT:
		m_State = BULLETSTATE::BULLET_STATE_INVIS;
		break;
	case BULLETSTATE::BULLET_STATE_DIE:
		break;
	default:
		break;
	}
	for (int i = 0; i < 8; i++)
		if (m_BulletPosition.at(i).x >(CCamera::getInstance()->getBoundingScreen().getX() + CCamera::getInstance()->getBoundingScreen().getWidth()))
			m_State = BULLETSTATE::BULLET_STATE_INVIS;
}

void CBulletEnemyBall::Shoot(float deltaTime)
{
	m_BulletPosition[0].x += 10 * deltaTime / 60;
	m_BulletPosition[1].x += 10 * deltaTime / 60;
	m_BulletPosition[1].y -= 10 * deltaTime / 60;
	m_BulletPosition[2].y -= 10 * deltaTime / 60;
	m_BulletPosition[3].x -= 10 * deltaTime / 60;
	m_BulletPosition[3].y -= 10 * deltaTime / 60;
	m_BulletPosition[4].x -= 10 * deltaTime / 60;
	m_BulletPosition[5].x -= 10 * deltaTime / 60;
	m_BulletPosition[5].y += 10 * deltaTime / 60;
	m_BulletPosition[6].y += 10 * deltaTime / 60;
	m_BulletPosition[7].x += 10 * deltaTime / 60;
	m_BulletPosition[7].y += 10 * deltaTime / 60;
}
void CBulletEnemyBall::updateEntity(CKeyBoard* device)
{
}

void CBulletEnemyBall::drawEntity()
{
	if (m_State == BULLETSTATE::BULLET_STATE_SHOW)
	{
		for (int i = 0; i < 8; i++)
			m_listSprite.at(0)->Render(m_BulletPosition.at(i), vector2d(1, 1), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
	}

}

vector3d CBulletEnemyBall::getPosition()
{
	for (int i = 0; i < 8; i++)
	{
		return m_BulletPosition.at(i);
	}

}

void CBulletEnemyBall::setPosition(vector3d position)
{
	for (int i = 0; i < 5; i++)
	{
		m_BulletPosition.at(i) = position;
	}
}
void CBulletEnemyBall::setState(int newState)
{
	m_State = newState;
}

int	CBulletEnemyBall::getState()
{
	return m_State;
}

