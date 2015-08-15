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

	// Update Action
	switch (m_State)
	{
	case PLAYERSTATES::STATE_START:
		break;
	case PLAYERSTATES::STATE_STAND:
			logicStandPlayer(deltaTime);
		break;
	case PLAYERSTATES::STATE_MOVE:
			logicMovePlayer(deltaTime);
		break;
	case PLAYERSTATES::STATE_JUMP:
		logicJumpPlayer(deltaTime);
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
		m_Position.y		= 50;
		m_Accelero.y		= 0;
		m_Velocity.y		= 10;
		m_State = PLAYERSTATES::STATE_STAND;
	}

	// Update State
	m_TimeState += deltaTime;

	OutputDebugString(L"DeltaCM: ");
	OutputDebugString(_itow(m_Velocity.y*deltaTime / 10, new WCHAR[1], 10));
	OutputDebugString(L"\n");

	if (m_State == PLAYERSTATES::STATE_STAND)
		m_TimeState		= 0;
	if (m_State == PLAYERSTATES::STATE_STAND_SHOOT && m_TimeState > 1000)
	{
		m_State			= PLAYERSTATES::STATE_STAND;
		m_State			= 0;
	}
	if (m_State == PLAYERSTATES::STATE_JUMP || m_State == PLAYERSTATES::STATE_JUMP_SHOOT)
	{
		if (m_TimeState > 1000)
		{
			m_State			= PLAYERSTATES::STATE_STAND;
			m_Velocity.y	= 9.8;
		}
	}

}

void CPlayer::updateEntity(CKeyBoard* device)
{
	if (device->KeyDown(DIK_D) && device->KeyDown(DIK_F) && device->KeyDown(DIK_RIGHT))
	{
		m_State = PLAYERSTATES::STATE_JUMP_SHOOT;
		m_Velocity.x = std::abs(m_Velocity.x) * DIRECTION::DIRECTION_RIGHT;
		return;
	}
	if (device->KeyDown(DIK_RIGHT) && device->KeyDown(DIK_F))
	{
		m_State = PLAYERSTATES::STATE_MOVE_SHOOT;
		m_Velocity.x = std::abs(m_Velocity.x) * DIRECTION::DIRECTION_RIGHT;
		return;
	}
	if (device->KeyDown(DIK_LEFT) && device->KeyDown(DIK_F))
	{
		m_State = PLAYERSTATES::STATE_MOVE_SHOOT;
		m_Velocity.x = std::abs(m_Velocity.x) * DIRECTION::DIRECTION_LEFT;
		return;
	}
	if (device->KeyDown(DIK_LEFT) && device->KeyDown(DIK_RIGHT))
	{
		m_State = PLAYERSTATES::STATE_STAND;
		return;
	}
	
	if (device->KeyDown(DIK_D) && device->KeyDown(DIK_F))
	{
		m_State			= PLAYERSTATES::STATE_JUMP_SHOOT;
		return;
	}
	if (device->KeyDown(DIK_LEFT))
	{
		m_State			= PLAYERSTATES::STATE_MOVE;
		m_Velocity.x	= std::abs(m_Velocity.x)*DIRECTION::DIRECTION_LEFT;
		return;
	}
	if (device->KeyDown(DIK_RIGHT))
	{
		m_State			= PLAYERSTATES::STATE_MOVE;
		m_Velocity.x	= std::abs(m_Velocity.x)*DIRECTION::DIRECTION_RIGHT;
		return;
	}
	if (device->KeyPress(DIK_F))
	{
		m_State			= PLAYERSTATES::STATE_STAND_SHOOT;
		m_TimeState		= 0;
		CBulletManager::getInstance()->getBullet(1, m_Position);
		return;
	}
	if (device->KeyPress(DIK_D))
	{
		m_State			= PLAYERSTATES::STATE_JUMP;
		m_Velocity.y	= std::abs(m_Velocity.y) * DIRECTION::DIRECTION_UP;
		if (device->KeyDown(DIK_LEFT))
		{
			m_State = PLAYERSTATES::STATE_JUMP;
			m_Velocity.x = std::abs(m_Velocity.x) * DIRECTION::DIRECTION_LEFT;
			return;
		}
		if (device->KeyDown(DIK_RIGHT))
		{
			m_State = PLAYERSTATES::STATE_JUMP;
			m_Velocity.x = std::abs(m_Velocity.x) * DIRECTION::DIRECTION_RIGHT;
			return;
		}
		return;
	}
}

void CPlayer::drawEntity()
{
	m_listSprite.at(m_State)->Render(CCamera::setPositionEntity(m_Position), vector2d(SIGN(m_Velocity.x)*2, 2), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
}

void CPlayer::logicMovePlayer(float deltaTime)
{
	m_Position.x += m_Velocity.x*(deltaTime / 100);
}
void CPlayer::logicJumpPlayer(float deltaTime)
{	
	m_Velocity.y = -15;
}

void CPlayer::logicStandPlayer(float deltaTime)
{
	if ((m_Velocity.x > 0 && m_Velocity.x <= 1) || (m_Velocity.x >= -1 && m_Velocity.x < 0))
	{
		m_Velocity.x = 0;
	}
}

vector3d CPlayer::getPosition()
{
	return m_Position;
}
