#include "Player.h"
#include "Game\Utill\InformationResource.h"

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
	m_Position		= vector3d(100, 300, 0.5);
	m_State			= PLAYSTATE::START;
	m_Direction		= vector2d(DIRECTION::DIRECTION_RIGHT, DIRECTION::DIRECTION_RIGHT);
	m_Velocity		= vector2d(9.8, 9.8);

	this->loadSprite();
	
	this->m_Bounding = new CBox2D(100, 100, 100, 100);
	this->m_isMovable = true;

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
	switch (m_State)
	{
	case PLAYERSTATES::STATE_START:
		break;
	case PLAYERSTATES::STATE_STAND:
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

	CPlayer* player1 = new CPlayer();
	CPlayer* player2 = new CPlayer();
	player2->m_Bounding = new CBox2D(10, 100, 100, 100);

}

void CPlayer::updateEntity(CKeyBoard* device)
{
	m_State				= PLAYERSTATES::STATE_STAND;

	if (device->KeyDown(DIK_LEFT))
	{
		m_State			= PLAYERSTATES::STATE_MOVE;
		m_Direction.x	= DIRECTION::DIRECTION_LEFT;
	}
	if (device->KeyDown(DIK_RIGHT))
	{
		m_State			= PLAYERSTATES::STATE_MOVE;
		m_Direction.x	= DIRECTION::DIRECTION_RIGHT;
	}
	if (device->KeyPress(DIK_F))
	{
		m_State			= PLAYERSTATES::STATE_STAND_SHOOT;
	}
	if (device->KeyDown(DIK_D))
	{
		m_State			= PLAYERSTATES::STATE_JUMP;
		//m_Direction.x	= DIRECTION::DIRECTION_NONE;
		m_Direction.y	= DIRECTION::DIRECTION_UP;
	}
	if (device->KeyDown(DIK_D) && device->KeyDown(DIK_LEFT))
	{
		m_State			= PLAYERSTATES::STATE_JUMP;
		m_Direction.x	= DIRECTION::DIRECTION_LEFT;
	}
	if (device->KeyDown(DIK_D) && device->KeyDown(DIK_RIGHT))
	{
		m_State			= PLAYERSTATES::STATE_JUMP;
		m_Direction.x	= DIRECTION::DIRECTION_RIGHT;
	}
	if (device->KeyDown(DIK_D) && device->KeyDown(DIK_F))
	{
		m_State			= PLAYERSTATES::STATE_JUMP_SHOOT;
	}
	if (device->KeyDown(DIK_RIGHT) && device->KeyDown(DIK_F))
	{
		m_State			= PLAYERSTATES::STATE_MOVE_SHOOT;
		m_Direction.x	= DIRECTION::DIRECTION_RIGHT;
	}
	if (device->KeyDown(DIK_LEFT) && device->KeyDown(DIK_F))
	{
		m_State			= PLAYERSTATES::STATE_MOVE_SHOOT;
		m_Direction.x	= DIRECTION::DIRECTION_LEFT;
	}
	if (device->KeyDown(DIK_D) && device->KeyDown(DIK_F) && device->KeyDown(DIK_RIGHT))
	{
		m_State			= PLAYERSTATES::STATE_JUMP_SHOOT;
		m_Direction.x	= DIRECTION::DIRECTION_RIGHT;
	}
}

void CPlayer::drawEntity()
{
	m_listSprite.at(m_State)->Render(m_Position, vector2d(m_Direction.x*2.0, m_Direction.y*2.0), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
}

void CPlayer::logicMovePlayer(float deltaTime)
{
	m_Position.x += m_Velocity.x*(deltaTime / 60)*m_Direction.x;
	//m_Position.y += m_Velocity.y*(deltaTime / 60)*m_Direction;
}
void CPlayer::logicJumpPlayer(float deltaTime)
{
}

void CPlayer::controlPlayer(CKeyBoard *device, float deltaTime)
{
}
