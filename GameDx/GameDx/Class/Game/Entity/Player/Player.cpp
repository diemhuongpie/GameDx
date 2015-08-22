#include "Player.h"
#include "Game\Utill\InformationResource.h"
#include "Game\Entity\Bullet\BulletManager.h"

CPlayer::CPlayer()
{
	this->initEntity();
}

CPlayer::~CPlayer()
{
}

CPlayer::CPlayer(LPDIRECT3DDEVICE9)
{
	this->initEntity();
	
}

bool CPlayer::initEntity()
{
	m_Position		= vector3d(50, 337, 0.5);
	m_Velocity		= vector2d(GRAVITY, GRAVITY);
	m_Accelero		= vector2d(0, 0);
	m_State			= PLAYSTATE::START;
	m_TimeState		= 0;
	m_Direction		= DIRECTION::DIRECTION_NONE;

	this->loadSprite();
	this->m_Bounding = new CBox2D(0, 0, 0, 0);


	return true;
}

bool CPlayer::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanStart,				1, 3, 3, 0));
	this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanStand,				1, 2, 2, 0));
	this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanStandShoot,		1, 1, 1, 0));
	this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanRun,				1, 3, 3, 0));
	this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanRunShoot,			1, 3, 3, 0));
	this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanJump,				1, 1, 1, 0));
	this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanJumpShoot,			1, 1, 1, 0));
	this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanClimb,				1, 2, 2, 0));
	this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanClimbShoot,		1, 1, 1, 0));
	this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanClimbEnd,			1, 1, 1, 0));
	this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanHit,				1, 3, 3, 0));
	return true;
}

void CPlayer::logicGravity(float deltaTime)
{
	// Update Gravity
	m_Position.y -= m_Velocity.y*deltaTime;
}

void CPlayer::logicCollision(CBaseEntity* entity)
{
	switch (CCollision::CheckCollision(this, entity))
	{
	case COLDIRECTION::COLDIRECTION_LEFT:
		this->setPosition(vector3d (entity->getBounding().getX() - entity->getBounding().getWidth() / 2 - this->getBounding().getWidth(), m_Position.y, 0.5f));
		break;
	case COLDIRECTION::COLDIRECTION_TOP:
		this->setPosition(vector3d(m_Position.x, entity->getBounding().getY() + entity->getBounding().getHeight()/ 2 + this->getBounding().getHeight()/ 2 - 2, 0.5f));
		OutputDebugString(L"pos: ");
		OutputDebugString(_itow(m_Position.y, new WCHAR[1], 10));
		OutputDebugString(L"\n");

		break;
	case COLDIRECTION::COLDIRECTION_BOTTOM:
		this->setPosition(vector3d(m_Position.x, entity->getBounding().getY() - entity->getBounding().getHeight(), 0.5f));
		OutputDebugString(L"pos: ");
		OutputDebugString(_itow(m_Position.x, new WCHAR[1], 10));
		OutputDebugString(L"\n");
		break;
	case COLDIRECTION::COLDIRECTION_RIGHT:
		this->setPosition(vector3d(entity->getBounding().getX() + entity->getBounding().getWidth(), m_Position.y, 0.5f));
		break;
	default:
		break;
	}

	OutputDebugString(L"pos: ");
	OutputDebugString(_itow(CCollision::CheckCollision(this, entity), new WCHAR[1], 10));
	OutputDebugString(L"\n");
}

void CPlayer::updateEntity(float deltaTime)
{
	if (m_State == PLAYERSTATES::STATE_START)
		m_State = PLAYERSTATES::STATE_STAND;

	// Update Action
	switch (m_State)
	{
	case PLAYERSTATES::STATE_START:
		logicGravity(deltaTime);
		break;

	case PLAYERSTATES::STATE_STAND:
	{
		logicStandPlayer(deltaTime);
		logicGravity(deltaTime);
	}
		break;

	case PLAYERSTATES::STATE_MOVE: 
	case PLAYERSTATES::STATE_MOVE_SHOOT:
		logicMovePlayer(deltaTime);
		logicGravity(deltaTime);
		break;

	case PLAYERSTATES::STATE_JUMP:
	case PLAYERSTATES::STATE_JUMP_SHOOT:
		{
			logicJumpPlayer(deltaTime);
			if (m_Direction != DIRECTION::DIRECTION_NONE)
				logicMovePlayer(deltaTime);
			logicGravity(deltaTime);
		}
		break;
	case PLAYERSTATES::STATE_CLIMB:
	/*case PLAYERSTATES::STATE_CLIMB_SHOOT:
	case PLAYERSTATES::STATE_CLIMB_END:*/
		logicClimbPlayer(deltaTime);
		break;

	default:
		break;
	}

	

	if (m_Position.y < 50)
	{
		m_Position.y = 50;
		m_Accelero.y = 5;
		m_Velocity.y = GRAVITY;
		//m_State = PLAYERSTATES::STATE_STAND;
	}

	// Update State
	m_TimeState += deltaTime;

}

void CPlayer::updateEntity(CKeyBoard* device)
{
	switch (m_State)
	{
	case PLAYERSTATES::STATE_STAND:
		if (device->KeyDown(DIK_RIGHT))
		{
			m_State			= PLAYERSTATES::STATE_MOVE;
			m_Velocity.x	= std::abs(m_Velocity.x) * DIRECTION::DIRECTION_RIGHT;
		}
		else if (device->KeyDown(DIK_LEFT))
		{
			m_State			= PLAYERSTATES::STATE_MOVE;
			m_Velocity.x	= std::abs(m_Velocity.x) * DIRECTION::DIRECTION_LEFT;
		}
		else if (device->KeyPress(DIK_Z) && device->KeyPress(DIK_X))
		{
			CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::NORMAL, m_Position, m_Velocity);
			m_State			= PLAYERSTATES::STATE_JUMP_SHOOT;
			m_TimeState		= 0;
		}
		else if (device->KeyPress(DIK_X))
		{
			m_State			= PLAYERSTATES::STATE_JUMP;
			m_TimeState		= 0;
			m_Velocity.y	= std::abs(m_Velocity.y) * (DIRECTION::DIRECTION_UP);
		}
		else if (device->KeyPress(DIK_UP))
		{
			m_State			= PLAYERSTATES::STATE_CLIMB;
		}
		else if (device->KeyPress(DIK_Z))
		{
			CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::NORMAL, m_Position,m_Velocity);
			m_State			= PLAYERSTATES::STATE_STAND_SHOOT;
			m_TimeState		= 0;
		}
		break;

	case PLAYERSTATES::STATE_MOVE:
		if (device->KeyPress(DIK_Z) && device->KeyPress(DIK_X))
		{
			CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::NORMAL, m_Position, m_Velocity);
			m_State			= PLAYERSTATES::STATE_JUMP_SHOOT;
			m_TimeState		= 0;
		}
		else if (device->KeyPress(DIK_Z))
		{
			CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::NORMAL, m_Position, m_Velocity);
			m_State			= PLAYERSTATES::STATE_MOVE_SHOOT;
			m_TimeState		= 0;
		}
		else if (device->KeyPress(DIK_X))
		{
			m_State			= PLAYERSTATES::STATE_JUMP;
			m_TimeState		= 0;
		}
		else if (device->KeyDown(DIK_RIGHT))
		{
				m_Velocity.x = std::abs(m_Velocity.x) * DIRECTION::DIRECTION_RIGHT;
		}
		else if (device->KeyDown(DIK_LEFT))
		{
			m_Velocity.x	= std::abs(m_Velocity.x) * DIRECTION::DIRECTION_LEFT;
		}
		else
		{
			m_State			= PLAYERSTATES::STATE_STAND; 
		}
		break;

	case PLAYERSTATES::STATE_JUMP:
		if (device->KeyPress(DIK_Z))
		{
			m_Direction		= DIRECTION::DIRECTION_NONE;
			CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::NORMAL, m_Position, m_Velocity);
			m_State			= PLAYERSTATES::STATE_JUMP_SHOOT;
		}
		else if (device->KeyDown(DIK_RIGHT))
		{
			m_Direction		= DIRECTION::DIRECTION_RIGHT;
			m_Velocity.x	= std::abs(m_Velocity.x) * DIRECTION::DIRECTION_RIGHT;
		}
		else if (device->KeyDown(DIK_LEFT))
		{
			m_Direction		= DIRECTION::DIRECTION_LEFT;
			m_Velocity.x	= std::abs(m_Velocity.x) * DIRECTION::DIRECTION_LEFT;
		}
		else
		{
			m_Direction		= DIRECTION::DIRECTION_NONE;
		}


		if (m_TimeState > TIME_FOR_JUMB)
		{
			m_State = PLAYERSTATES::STATE_STAND;
			m_TimeState = 0;
		}
		break;

	case PLAYERSTATES::STATE_STAND_SHOOT:
		
		if (device->KeyPress(DIK_Z))
		{
			CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::NORMAL, m_Position, m_Velocity);

			if (m_TimeState > TIME_FOR_SHOOT)
			{
				m_State		= PLAYERSTATES::STATE_STAND;
			}
			else
				CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::NORMAL, m_Position, m_Velocity);
				m_TimeState = 0;
		}
		else if (device->KeyPress(DIK_RIGHT))
		{
			CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::NORMAL, m_Position, m_Velocity);
			m_State			= PLAYERSTATES::STATE_MOVE_SHOOT;
			m_Velocity.x	= std::abs(m_Velocity.x) * DIRECTION::DIRECTION_RIGHT;
		}
		else if (device->KeyPress(DIK_LEFT))
		{
			CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::NORMAL, m_Position, m_Velocity);
			m_State			= PLAYERSTATES::STATE_MOVE_SHOOT;
			m_Velocity.x	= std::abs(m_Velocity.x) * DIRECTION::DIRECTION_LEFT;
		}
		else if (device->KeyPress(DIK_X))
		{
			m_State			= PLAYERSTATES::STATE_JUMP;
		}
		else
		{
			if (m_TimeState > TIME_FOR_SHOOT * 0.2)
			{
				m_State		= PLAYERSTATES::STATE_STAND;
				m_TimeState = 0;
			}
		}
		break;

	case PLAYERSTATES::STATE_MOVE_SHOOT:
		if (device->KeyDown(DIK_X))
		{
			m_State			= PLAYERSTATES::STATE_JUMP;
			m_TimeState		= 0;
		}
		else if (device->KeyDown(DIK_LEFT))
		{
			m_Velocity.x	= std::abs(m_Velocity.x) * DIRECTION::DIRECTION_LEFT;

			if (device->KeyPress(DIK_Z))
			{
				if (m_TimeState > TIME_FOR_SHOOT)
				{
					m_State = PLAYERSTATES::STATE_MOVE;
				}
				else
					CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::NORMAL, m_Position, m_Velocity);
				m_TimeState	= 0;
			}
			else
			{
				if (m_TimeState > TIME_FOR_SHOOT * 0.2)
				{
					m_State		= PLAYERSTATES::STATE_MOVE;
					m_TimeState = 0;
				}
			}
		}
		else if (device->KeyDown(DIK_RIGHT))
		{
			m_Velocity.x	= std::abs(m_Velocity.x) * DIRECTION::DIRECTION_RIGHT;

			if (device->KeyPress(DIK_Z))
			{
				if (m_TimeState > TIME_FOR_SHOOT)
				{
					m_State = PLAYERSTATES::STATE_MOVE;
				}
				else
					CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::NORMAL, m_Position, m_Velocity);
				m_TimeState	= 0;
			}
			else
			{
				if (m_TimeState > TIME_FOR_SHOOT * 0.2)
				{
					m_State		= PLAYERSTATES::STATE_MOVE;
					m_TimeState = 0;
				}
			}
		}
		else
		{
			if (m_TimeState > TIME_FOR_SHOOT * 0.2)
			{
				m_State		= PLAYERSTATES::STATE_MOVE;
				m_TimeState = 0;
			}
		}
		break;

	case PLAYERSTATES::STATE_JUMP_SHOOT:
		if (device->KeyDown(DIK_RIGHT))
		{
			if (m_TimeState > TIME_FOR_SHOOT / 2)
			{
				m_State		= PLAYERSTATES::STATE_MOVE;
				m_State		= 0;
			}
			m_Direction		= DIRECTION::DIRECTION_RIGHT;
			m_Velocity.x	= std::abs(m_Velocity.x) * DIRECTION::DIRECTION_RIGHT;
		}
		else if (device->KeyDown(DIK_LEFT))
		{
			if (m_TimeState > TIME_FOR_SHOOT / 2)
			{
				m_State		= PLAYERSTATES::STATE_MOVE;
				m_State		= 0;
			}
			m_Direction		= DIRECTION::DIRECTION_LEFT;
			m_Velocity.x	= std::abs(m_Velocity.x) * DIRECTION::DIRECTION_LEFT;
		}
		else
		{
			m_Direction		= DIRECTION::DIRECTION_NONE;
			if (m_TimeState > TIME_FOR_SHOOT / 2)
			{
				m_State		= PLAYERSTATES::STATE_STAND;
				m_TimeState = 0;
			}
		}
		break;

	case PLAYERSTATES::STATE_CLIMB:
		if (device->KeyPress(DIK_Z) && device->KeyPress(DIK_X))
		{
			m_State			= PLAYERSTATES::STATE_JUMP_SHOOT;
			m_TimeState		= 0;
		}
		else if (device->KeyPress(DIK_Z))
		{
			m_State			= PLAYERSTATES::STATE_CLIMB_SHOOT;
		}
		else if (device->KeyPress(DIK_X))
		{
			m_State			= PLAYERSTATES::STATE_JUMP;
			m_TimeState		= 0;
		}
		else if (device->KeyDown(DIK_UP))
		{
			m_Direction		= DIRECTION::DIRECTION_UP;
		}
		else if (device->KeyDown(DIK_DOWN))
		{
			m_Direction		= DIRECTION::DIRECTION_DOWN;
		}
		else
		{
			m_Direction		= DIRECTION::DIRECTION_NONE;
			m_State			= PLAYERSTATES::STATE_CLIMB;
		}
		break;

	case PLAYERSTATES::STATE_CLIMB_SHOOT:
		if (device->KeyPress(DIK_X))
		{
			m_State			= PLAYERSTATES::STATE_JUMP;
		}
		if (device->KeyDown(DIK_RIGHT))
		{
			m_Velocity.x	= std::abs(m_Velocity.x) * DIRECTION::DIRECTION_RIGHT;
		}
		else if (device->KeyDown(DIK_LEFT))
		{
			m_Velocity.x	= std::abs(m_Velocity.x) * DIRECTION::DIRECTION_LEFT;
		}
		break;
	default:
		//m_State				= PLAYERSTATES::STATE_STAND;
		break;
	}
}

void CPlayer::drawEntity()
{
	switch (m_State)
	{
	case PLAYERSTATES::STATE_STAND_SHOOT:
	case PLAYERSTATES::STATE_MOVE_SHOOT:
		m_listSprite.at(m_State)->Render(CCamera::setPositionEntity(vector3d(m_Position.x + SIGN(m_Velocity.x) * DELTA_FIX_SIZE_RESOURCE, m_Position.y, 0.5f)),
											vector2d(SIGN(m_Velocity.x) * 2, 2),
											0,
											DRAWCENTER_MIDDLE_MIDDLE,
											true,
											10);
		break;

	case PLAYERSTATES::STATE_CLIMB:
		if (m_Direction == DIRECTION::DIRECTION_NONE)
			m_listSprite.at(m_State)->Render(1, 1, CCamera::setPositionEntity(m_Position), vector2d(SIGN(m_Velocity.x) * 2, 2), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
		else
			m_listSprite.at(m_State)->Render(CCamera::setPositionEntity(m_Position), vector2d(SIGN(m_Velocity.x) * 2, 2), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
		break;
	default:
		m_listSprite.at(m_State)->Render(CCamera::setPositionEntity(m_Position), vector2d(SIGN(m_Velocity.x) * 2, 2), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
		break;
	}

}

void CPlayer::logicMovePlayer(float deltaTime)
{
	m_Position.x += m_Velocity.x*deltaTime;
}

void CPlayer::logicJumpPlayer(float deltaTime)
{	
		// Update Accelero
		m_Accelero.y += 1;

		m_Accelero.y = SETMAX(m_Accelero.y, 5);

		if (m_TimeState > TIME_FOR_JUMB / 2)
		{
			m_Velocity.y	= GRAVITY;
			m_Position.y	+= m_Velocity.y*deltaTime + m_Accelero.y;
		}
		else
		{
			m_Velocity.y	= -GRAVITY;
			m_Position.y	-= m_Accelero.y;
		}


		OutputDebugString(L"acs: ");
		OutputDebugString(_itow(m_Accelero.y, new WCHAR[1], 10));
		OutputDebugString(L"\n");
}

void CPlayer::logicStandPlayer(float deltaTime)
{
}

void CPlayer::logicClimbPlayer(float deltaTime)
{
	if (m_Direction == DIRECTION::DIRECTION_UP)
		m_Position.y += m_Velocity.y* deltaTime;
	else if (m_Direction == DIRECTION::DIRECTION_DOWN)
		m_Position.y -= m_Velocity.y *deltaTime;
}

vector3d CPlayer::getPosition()
{
	return m_Position;
}
