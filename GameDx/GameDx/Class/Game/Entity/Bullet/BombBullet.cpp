#include "BombBullet.h"

void		updateBombBullet	(vector3d &pos, vector3d maxpos, vector2d &vec, float deltaTime);
vector3d	changePosition		(int style,		vector3d pos);

CBombBullet::CBombBullet()
{
	initEntity();
}

CBombBullet::~CBombBullet()
{

}

bool		CBombBullet::initEntity()
{
	m_Position					= vector3d(100, 100, 0.5);
	m_MaxPosition				= vector3d(m_Position.x, m_Position.y + DELTA_SIZE_Y_FOR_BOOM_OF_BOSSMAN, 0.5);
	m_Velocity					= vector2d(10, 10);
	
	m_Bounding					= new CBox2D(m_Position.x, m_Position.y, 32, 32);
	m_State						= BULLETSTATE::BULLET_STATE_INVIS;
	
	m_countTimeForBummm			= 00.00;

	// you have to choose tagNode for bullet player or boss. "player" or "enemy".
	m_TagNode					= "NULL";

	this->loadSprite();

	return true;
}

bool		CBombBullet::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanBullet, 1, 1, 1, 0));
	this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanBullet, 1, 1, 1, 0));
	this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanBullet, 1, 1, 1, 0));
	return	true;
}

void		CBombBullet::resetObject()
{
}

void		CBombBullet::updateEntity(float deltaTime) // update logic
{
	switch (m_State)
	{
	case BULLETSTATE::BULLET_STATE_INVIS:
		m_Position = vector3dMinimum;
		break;
	case BULLETSTATE::BULLET_STATE_SHOW:
		updateBombBullet(m_Position, m_MaxPosition, m_Velocity, deltaTime);
		
		// update collision.
		m_State = BULLETSTATE::BULLET_STATE_HIT;
		break;
	case BULLETSTATE::BULLET_STATE_HIT:
		if (deltaTime > 0)
			m_countTimeForBummm += deltaTime;

		if (m_countTimeForBummm > TIME_FOR_WAIT_BUM)
			m_State = BULLETSTATE::BULLET_STATE_DIE;
		break;
	case BULLETSTATE::BULLET_STATE_DIE:
		if (m_countTimeForBummm > TIME_FOR_WAIT_BUM + TIME_FOR_BUM)
			m_State = BULLETSTATE::BULLET_STATE_INVIS;
		break;
	default:
		break;
	}

	// update invis
}

void		CBombBullet::updateEntity(CKeyBoard* device)
{

}

void		CBombBullet::updateEntity(CBaseEntity* entity)
{

}

void		CBombBullet::drawEntity()
{
	if (m_State == BULLETSTATE::BULLET_STATE_DIE)
	{
		m_listSprite.at(m_State)->Render(CCamera::setPositionEntity(m_Position),					vector2d(SIGN(m_Velocity.x), SIGN(m_Velocity.y)), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
		m_listSprite.at(m_State)->Render(CCamera::setPositionEntity(changePosition(1, m_Position)),	vector2d(SIGN(m_Velocity.x), SIGN(m_Velocity.y)), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);  // left
		m_listSprite.at(m_State)->Render(CCamera::setPositionEntity(changePosition(2, m_Position)), vector2d(SIGN(m_Velocity.x), SIGN(m_Velocity.y)), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);  // top
		m_listSprite.at(m_State)->Render(CCamera::setPositionEntity(changePosition(3, m_Position)), vector2d(SIGN(m_Velocity.x), SIGN(m_Velocity.y)), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);  // right
		m_listSprite.at(m_State)->Render(CCamera::setPositionEntity(changePosition(4, m_Position)), vector2d(SIGN(m_Velocity.x), SIGN(m_Velocity.y)), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);  // bot
	}
	else if (m_State != BULLETSTATE::BULLET_STATE_INVIS)
		m_listSprite.at(m_State)->Render(CCamera::setPositionEntity(m_Position), vector2d(SIGN(m_Velocity.x), SIGN(m_Velocity.y)), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
}

vector3d	CBombBullet::getPosition()
{
	return m_Position;
}

void		CBombBullet::setState(int newState)
{
	m_State = newState;
}

int			CBombBullet::getState()
{
	return m_State;
}


inline void updateBombBullet(vector3d &pos, vector3d maxpos, vector2d &vec, float deltaTime)
{
	pos.x += vec.x*deltaTime;
	pos.y += vec.y*deltaTime;

	if (pos.y > maxpos.y)
	{
		vec.y *= -1;
		pos.y = maxpos.y;
	}
}

inline vector3d changePosition(int style, vector3d pos)
{
	switch (style)
	{
	case 1:
		return vector3d(pos.x - 5,	pos.y,		0.5);
	case 2:
		return vector3d(pos.x + 5,	pos.y,		0.5);
	case 3:
		return vector3d(pos.x,		pos.y + 5,	0.5);
	case 4:
		return vector3d(pos.x,		pos.y - 5,	0.5);
	default:
		break;
	}
};