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
	m_Position		= vector3d(200, 337, 0.5);
	m_Velocity		= vector2d(9.8, 9.8);
	m_Accelero		= vector2d(0, 0);
	m_State			= PLAYSTATE::START;
	m_TimeState		= 0;
	m_IsMoveJumb	= false;

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

void CPlayer::updateEntity(float deltaTime)
{
	if (m_State == PLAYERSTATES::STATE_START)
		m_State = PLAYERSTATES::STATE_STAND;

	// Update Action
	switch (m_State)
	{
	case PLAYERSTATES::STATE_START:
		break;

	case PLAYERSTATES::STATE_STAND:
		logicStandPlayer(deltaTime);
		break;

	case PLAYERSTATES::STATE_MOVE: 
	case PLAYERSTATES::STATE_MOVE_SHOOT:
		logicMovePlayer(deltaTime);
		break;

	case PLAYERSTATES::STATE_JUMP:
	case PLAYERSTATES::STATE_JUMP_SHOOT:
		{
			logicJumpPlayer(deltaTime);
			if (m_IsMoveJumb)
				logicMovePlayer(deltaTime);
		}
		break;

	default:
		break;
	}

	// Update Gravity
	m_Position.y -= m_Velocity.y*deltaTime / 10 + m_Accelero.y;

	// Update Accelero
	m_Accelero.y += 2;

	if (m_Position.y < 50)
	{
		m_Position.y = 50;
		m_Accelero.y = 10;
		m_Velocity.y = 10;
		//m_State = PLAYERSTATES::STATE_STAND;
	}

	// Update State
	m_TimeState += deltaTime;

	OutputDebugString(L"Vel: ");
	OutputDebugString(_itow(m_Velocity.x, new WCHAR[1], 10));
	OutputDebugString(L"\n");

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
		else if (device->KeyPress(DIK_Z))
		{
			CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::NORMAL, m_Position, m_Velocity);
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
			m_IsMoveJumb	= false;
			CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::MACHINE_AUTO_ORANGE, m_Position, m_Velocity);
			m_State			= PLAYERSTATES::STATE_JUMP_SHOOT;
		}
		else if (device->KeyPress(DIK_RIGHT))
		{
			m_IsMoveJumb	= true;
			m_Velocity.x	= std::abs(m_Velocity.x) * DIRECTION::DIRECTION_RIGHT;
		}
		else if (device->KeyPress(DIK_LEFT))
		{
			m_IsMoveJumb	= true;
			m_Velocity.x	= std::abs(m_Velocity.x) * DIRECTION::DIRECTION_LEFT;
		}
		else
		{
			m_IsMoveJumb	= false;
			if (m_TimeState > TIME_FOR_JUMB)
			{
				m_State		= PLAYERSTATES::STATE_STAND;
				m_TimeState	= 0;
			}
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
			m_IsMoveJumb	= true;
			m_Velocity.x	= std::abs(m_Velocity.x) * DIRECTION::DIRECTION_RIGHT;
		}
		else if (device->KeyDown(DIK_LEFT))
		{
			if (m_TimeState > TIME_FOR_SHOOT / 2)
			{
				m_State		= PLAYERSTATES::STATE_MOVE;
				m_State		= 0;
			}
			m_IsMoveJumb	= true;
			m_Velocity.x	= std::abs(m_Velocity.x) * DIRECTION::DIRECTION_LEFT;
		}
		else
		{
			m_IsMoveJumb	= false;
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
		OutputDebugString(L"pos: ");
		OutputDebugString(_itow(m_Position.x, new WCHAR[1], 10));
		OutputDebugString(L"\n");

		break;
	default:
		m_listSprite.at(m_State)->Render(CCamera::setPositionEntity(m_Position), vector2d(SIGN(m_Velocity.x) * 2, 2), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
		break;
	}
}

void CPlayer::logicMovePlayer(float deltaTime)
{
	m_Position.x += m_Velocity.x*(deltaTime / 100);
}

void CPlayer::logicJumpPlayer(float deltaTime)
{	
		m_Velocity.y = -25;

		OutputDebugString(L"pos: ");
		OutputDebugString(_itow(m_Position.x, new WCHAR[1], 10));
		OutputDebugString(L"\n");
}

void CPlayer::logicStandPlayer(float deltaTime)
{
	if ((m_Velocity.x > 0 && m_Velocity.x <= 1) || (m_Velocity.x >= -1 && m_Velocity.x < 0))
	{
		m_Velocity.x = 0;
	}
}

void CPlayer::logicClimbPlayer(float deltaTime)
{

}
vector3d CPlayer::getPosition()
{
	return m_Position;
}
