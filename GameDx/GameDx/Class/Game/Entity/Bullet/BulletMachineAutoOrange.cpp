#include "Game\Entity\Bullet\BulletMachineAutoOrange.h"


BulletMachineAutoOrange::BulletMachineAutoOrange()
{
	this->initEntity();
}


BulletMachineAutoOrange::~BulletMachineAutoOrange()
{
}

bool BulletMachineAutoOrange::loadSprite()
{
	for (int i = 0; i < 5; i ++)
		this->m_listSprite.push_back(new CSprite(L"Resource//Image//Game//Sprites//BossCutMan//enemy_bullet_orange.png", 1, 1, 1, 0));
	return	true;
}

bool BulletMachineAutoOrange::initEntity()
{
	//m_Position = vector3d(100, 100, 0.5);
	for (int i = 0; i < 5; i++)
	{
		m_BulletPosition[i] = m_Position;
	}
	m_State = BULLETSTATE::BULLET_STATE_INVIS;
	m_Velocity = vector2d(10, 10);
	m_Bounding = new CBox2D(m_Position.x, m_Position.y, 32, 32);
	m_TagNode = "N";

	this->loadSprite();

	return true;
}

void BulletMachineAutoOrange::updateEntity(float deltaTime)
{
	switch (m_State)
	{
	case BULLETSTATE::BULLET_STATE_INVIS:
		m_Position = vector3dMinimum;
		break;
	case BULLETSTATE::BULLET_STATE_SHOW:
		if (deltaTime > 0)
			Shoot(deltaTime / 60);
		break;
	case BULLETSTATE::BULLET_STATE_HIT:
		m_State = BULLETSTATE::BULLET_STATE_INVIS;
		break;
	case BULLETSTATE::BULLET_STATE_DIE:
		break;
	default:
		break;
	}

	if (m_Position.x > (CCamera::getInstance()->getBoundingScreen().getX() + CCamera::getInstance()->getBoundingScreen().getWidth()))
		m_State = BULLETSTATE::BULLET_STATE_INVIS;
}

void BulletMachineAutoOrange::Shoot(float deltatime)
{
	m_BulletPosition[0].x += 4 * deltatime;
	m_BulletPosition[1].x += 4 * deltatime;
	m_BulletPosition[1].y += 4 * deltatime;
	m_BulletPosition[2].y += 4 * deltatime;
	m_BulletPosition[3].x -= 4 * deltatime;
	m_BulletPosition[3].y += 4 * deltatime;
	m_BulletPosition[4].x -= 4 * deltatime;
}
void BulletMachineAutoOrange::updateEntity(CKeyBoard* device)
{
}

void BulletMachineAutoOrange::drawEntity()
{
	if (m_State == BULLETSTATE::BULLET_STATE_SHOW)
	{
		m_listSprite.at(0)->Render(CCamera::setPositionEntity(m_BulletPosition[0]), vector2d(1, 1), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
		m_listSprite.at(1)->Render(CCamera::setPositionEntity(m_BulletPosition[1]), vector2d(1, 1), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
		m_listSprite.at(2)->Render(CCamera::setPositionEntity(m_BulletPosition[2]), vector2d(1, 1), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
		m_listSprite.at(3)->Render(CCamera::setPositionEntity(m_BulletPosition[3]), vector2d(1, 1), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
		m_listSprite.at(4)->Render(CCamera::setPositionEntity(m_BulletPosition[4]), vector2d(1, 1), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
	}
		
}

vector3d BulletMachineAutoOrange::getPosition()
{
	return m_Position;
}

void BulletMachineAutoOrange::setState(int newState)
{
	m_State = newState;
}

int	BulletMachineAutoOrange::getState()
{
	return m_State;
}