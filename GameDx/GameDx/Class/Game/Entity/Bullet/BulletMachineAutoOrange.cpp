#include "BulletMachineAutoOrange.h"
#include "Game\Entity\Bullet\BulletMachineAutoOrange.h"


CBulletMachineAutoOrange::CBulletMachineAutoOrange()
{
	this->initEntity();
}


CBulletMachineAutoOrange::~CBulletMachineAutoOrange()
{
}


bool CBulletMachineAutoOrange::loadSprite()
{
	for (int i = 0; i < 5; i++)
		this->m_listSprite.push_back(new CSprite(L"Resource//Image//Game//Sprites//BossCutMan//enemy_bullet_orange.png", 1, 1, 1, 0));
	return	true;
}

bool CBulletMachineAutoOrange::initEntity()
{
	m_Position = vector3d(100, 100, 0.5);

	for (int i = 0; i < 5; i++)
	{
		m_BulletPosition.push_back(vector3d(m_Position.x, m_Position.y, 0.5f));
		m_Bounding = new CBox2D(m_BulletPosition.at(i).x, m_BulletPosition.at(i).y, 32, 32);
	}
	m_State = BULLETSTATE::BULLET_STATE_INVIS;
	m_Velocity = vector2d(7, 7);
	m_TagNode = "A";

	this->loadSprite();
	return true;
}

void CBulletMachineAutoOrange::updateEntity(float deltaTime)
{
	switch (m_State)
	{
	case BULLETSTATE::BULLET_STATE_INVIS:
		for (int i = 0; i < 5; i ++)
			m_BulletPosition.at(i) = vector3dMinimum;
		break;
	case BULLETSTATE::BULLET_STATE_SHOW:
		if (deltaTime > 0)
			Shoot(deltaTime/60);
		break;
	case BULLETSTATE::BULLET_STATE_HIT:
		m_State = BULLETSTATE::BULLET_STATE_INVIS;
		break;
	case BULLETSTATE::BULLET_STATE_DIE:
		break;
	default:
		break;
	}
	for (int i = 0; i < 5; i++)
		if (m_BulletPosition.at(i).x >(CCamera::getInstance()->getBoundingScreen().getX() + CCamera::getInstance()->getBoundingScreen().getWidth()))
			m_State = BULLETSTATE::BULLET_STATE_INVIS;
}

void CBulletMachineAutoOrange::Shoot(float deltatime)
{
	m_BulletPosition.at(0).x += m_Velocity.x * deltatime;
	m_BulletPosition.at(1).x += m_Velocity.x * deltatime;
	m_BulletPosition.at(1).y -= m_Velocity.y * deltatime;
	m_BulletPosition.at(2).y -= m_Velocity.y * deltatime;
	m_BulletPosition.at(3).x -= m_Velocity.x * deltatime;
	m_BulletPosition.at(3).y -= m_Velocity.y * deltatime;
	m_BulletPosition.at(4).x -= m_Velocity.x * deltatime;
}
void CBulletMachineAutoOrange::updateEntity(CKeyBoard* device)
{
}

void CBulletMachineAutoOrange::drawEntity()
{
	if (m_State == BULLETSTATE::BULLET_STATE_SHOW)
	{
		for (int i = 0; i < 5; i++)
			m_listSprite.at(i)->Render(m_BulletPosition.at(i), vector2d(1, 1), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
	}		
}

vector3d CBulletMachineAutoOrange::getPosition()
{
	for (int i = 0; i < 5; i++)
	{
		return m_BulletPosition.at(i);
	}

}

void CBulletMachineAutoOrange::setPosition(vector3d position)
{
	for (int i = 0; i < 5; i++)
	{
		m_BulletPosition.at(i) = position;
	}
}

void CBulletMachineAutoOrange::setState(int newState)
{
	m_State = newState;
}

int	CBulletMachineAutoOrange::getState()
{
	return m_State;
}