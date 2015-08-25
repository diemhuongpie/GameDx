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
	m_Position		= vector3d(50, 50, 0.5);
	m_Velocity		= vector2d(GRAVITY, -GRAVITY);
	m_Accelero		= vector2d(0, 0.01);
	m_State			= PLAYSTATE::START;
	m_TimeState		= 0;
	m_Direction		= vector2d(DIRECTION::DIRECTION_RIGHT, DIRECTION::DIRECTION_NONE);
	m_RockManSpriteList = new vector<CSprite*>[NUM_OF_ROCKMAN_SKILL];

	this->loadSprite();
	for (int i = 0; i < m_RockManSpriteList[ROCKMAN_NORMAL_SKILL].size(); ++i)
		this->m_listSprite.push_back(this->m_RockManSpriteList[ROCKMAN_NORMAL_SKILL].at(i));
	this->m_Bounding = new CBox2D(0, 0, 0, 0);


	return true;
}

bool CPlayer::loadSprite()
{
	this->m_RockManSpriteList[ROCKMAN_NORMAL_SKILL].push_back(new CSprite(CInfomationResource::getInstance()->InitRockManNormalResource().at(PLAYERSTATES::STATE_START), 1, 3, 3, 0));
	this->m_RockManSpriteList[ROCKMAN_NORMAL_SKILL].push_back(new CSprite(CInfomationResource::getInstance()->InitRockManNormalResource().at(PLAYERSTATES::STATE_STAND), 1, 2, 2, 0));
	this->m_RockManSpriteList[ROCKMAN_NORMAL_SKILL].push_back(new CSprite(CInfomationResource::getInstance()->InitRockManNormalResource().at(PLAYERSTATES::STATE_STAND_SHOOT), 1, 1, 1, 0));
	this->m_RockManSpriteList[ROCKMAN_NORMAL_SKILL].push_back(new CSprite(CInfomationResource::getInstance()->InitRockManNormalResource().at(PLAYERSTATES::STATE_MOVE), 1, 3, 3, 0));
	this->m_RockManSpriteList[ROCKMAN_NORMAL_SKILL].push_back(new CSprite(CInfomationResource::getInstance()->InitRockManNormalResource().at(PLAYERSTATES::STATE_MOVE_SHOOT), 1, 3, 3, 0));
	this->m_RockManSpriteList[ROCKMAN_NORMAL_SKILL].push_back(new CSprite(CInfomationResource::getInstance()->InitRockManNormalResource().at(PLAYERSTATES::STATE_JUMP), 1, 1, 1, 0));
	this->m_RockManSpriteList[ROCKMAN_NORMAL_SKILL].push_back(new CSprite(CInfomationResource::getInstance()->InitRockManNormalResource().at(PLAYERSTATES::STATE_JUMP_SHOOT), 1, 1, 1, 0));
	this->m_RockManSpriteList[ROCKMAN_NORMAL_SKILL].push_back(new CSprite(CInfomationResource::getInstance()->InitRockManNormalResource().at(PLAYERSTATES::STATE_CLIMB), 1, 2, 2, 0));
	this->m_RockManSpriteList[ROCKMAN_NORMAL_SKILL].push_back(new CSprite(CInfomationResource::getInstance()->InitRockManNormalResource().at(PLAYERSTATES::STATE_CLIMB_SHOOT), 1, 1, 1, 0));
	this->m_RockManSpriteList[ROCKMAN_NORMAL_SKILL].push_back(new CSprite(CInfomationResource::getInstance()->InitRockManNormalResource().at(PLAYERSTATES::STATE_CLIMB_END), 1, 1, 1, 0));
	this->m_RockManSpriteList[ROCKMAN_NORMAL_SKILL].push_back(new CSprite(CInfomationResource::getInstance()->InitRockManNormalResource().at(PLAYERSTATES::STATE_HIT), 1, 3, 3, 0));


	this->m_RockManSpriteList[ROCKMAN_CUT_SKILL].push_back(new CSprite(CInfomationResource::getInstance()->InitRockManCutResource().at(PLAYERSTATES::STATE_START), 1, 3, 3, 0));
	this->m_RockManSpriteList[ROCKMAN_CUT_SKILL].push_back(new CSprite(CInfomationResource::getInstance()->InitRockManCutResource().at(PLAYERSTATES::STATE_STAND), 1, 2, 2, 0));
	this->m_RockManSpriteList[ROCKMAN_CUT_SKILL].push_back(new CSprite(CInfomationResource::getInstance()->InitRockManCutResource().at(PLAYERSTATES::STATE_STAND_SHOOT), 1, 1, 1, 0));
	this->m_RockManSpriteList[ROCKMAN_CUT_SKILL].push_back(new CSprite(CInfomationResource::getInstance()->InitRockManCutResource().at(PLAYERSTATES::STATE_MOVE), 1, 3, 3, 0));
	this->m_RockManSpriteList[ROCKMAN_CUT_SKILL].push_back(new CSprite(CInfomationResource::getInstance()->InitRockManCutResource().at(PLAYERSTATES::STATE_MOVE_SHOOT), 1, 3, 3, 0));
	this->m_RockManSpriteList[ROCKMAN_CUT_SKILL].push_back(new CSprite(CInfomationResource::getInstance()->InitRockManCutResource().at(PLAYERSTATES::STATE_JUMP), 1, 1, 1, 0));
	this->m_RockManSpriteList[ROCKMAN_CUT_SKILL].push_back(new CSprite(CInfomationResource::getInstance()->InitRockManCutResource().at(PLAYERSTATES::STATE_JUMP_SHOOT), 1, 1, 1, 0));
	this->m_RockManSpriteList[ROCKMAN_CUT_SKILL].push_back(new CSprite(CInfomationResource::getInstance()->InitRockManCutResource().at(PLAYERSTATES::STATE_CLIMB), 1, 2, 2, 0));
	this->m_RockManSpriteList[ROCKMAN_CUT_SKILL].push_back(new CSprite(CInfomationResource::getInstance()->InitRockManCutResource().at(PLAYERSTATES::STATE_CLIMB_SHOOT), 1, 1, 1, 0));
	this->m_RockManSpriteList[ROCKMAN_CUT_SKILL].push_back(new CSprite(CInfomationResource::getInstance()->InitRockManCutResource().at(PLAYERSTATES::STATE_CLIMB_END), 1, 1, 1, 0));
	this->m_RockManSpriteList[ROCKMAN_CUT_SKILL].push_back(new CSprite(CInfomationResource::getInstance()->InitRockManCutResource().at(PLAYERSTATES::STATE_HIT), 1, 3, 3, 0));


	this->m_RockManSpriteList[ROCKMAN_BOMB_SKILL].push_back(new CSprite(CInfomationResource::getInstance()->InitRockManBombResource().at(PLAYERSTATES::STATE_START), 1, 3, 3, 0));
	this->m_RockManSpriteList[ROCKMAN_BOMB_SKILL].push_back(new CSprite(CInfomationResource::getInstance()->InitRockManBombResource().at(PLAYERSTATES::STATE_STAND), 1, 2, 2, 0));
	this->m_RockManSpriteList[ROCKMAN_BOMB_SKILL].push_back(new CSprite(CInfomationResource::getInstance()->InitRockManBombResource().at(PLAYERSTATES::STATE_STAND_SHOOT), 1, 1, 1, 0));
	this->m_RockManSpriteList[ROCKMAN_BOMB_SKILL].push_back(new CSprite(CInfomationResource::getInstance()->InitRockManBombResource().at(PLAYERSTATES::STATE_MOVE), 1, 3, 3, 0));
	this->m_RockManSpriteList[ROCKMAN_BOMB_SKILL].push_back(new CSprite(CInfomationResource::getInstance()->InitRockManBombResource().at(PLAYERSTATES::STATE_MOVE_SHOOT), 1, 3, 3, 0));
	this->m_RockManSpriteList[ROCKMAN_BOMB_SKILL].push_back(new CSprite(CInfomationResource::getInstance()->InitRockManBombResource().at(PLAYERSTATES::STATE_JUMP), 1, 1, 1, 0));
	this->m_RockManSpriteList[ROCKMAN_BOMB_SKILL].push_back(new CSprite(CInfomationResource::getInstance()->InitRockManBombResource().at(PLAYERSTATES::STATE_JUMP_SHOOT), 1, 1, 1, 0));
	this->m_RockManSpriteList[ROCKMAN_BOMB_SKILL].push_back(new CSprite(CInfomationResource::getInstance()->InitRockManBombResource().at(PLAYERSTATES::STATE_CLIMB), 1, 2, 2, 0));
	this->m_RockManSpriteList[ROCKMAN_BOMB_SKILL].push_back(new CSprite(CInfomationResource::getInstance()->InitRockManBombResource().at(PLAYERSTATES::STATE_CLIMB_SHOOT), 1, 1, 1, 0));
	this->m_RockManSpriteList[ROCKMAN_BOMB_SKILL].push_back(new CSprite(CInfomationResource::getInstance()->InitRockManBombResource().at(PLAYERSTATES::STATE_CLIMB_END), 1, 1, 1, 0));
	this->m_RockManSpriteList[ROCKMAN_BOMB_SKILL].push_back(new CSprite(CInfomationResource::getInstance()->InitRockManBombResource().at(PLAYERSTATES::STATE_HIT), 1, 3, 3, 0));
	
	return true;
}

void CPlayer::resetObject()
{

}

void CPlayer::logicGravity(float deltaTime)
{
	// Update Gravity
	m_Velocity.y -= m_Accelero.y;
	m_Position.y = m_Velocity.y*deltaTime;
}

void CPlayer::logicCollision(CBaseEntity* entity)
{
	switch (CCollision::CheckCollision(this, entity))
	{
	case COLDIRECTION::COLDIRECTION_LEFT:
		this->m_Velocity.x = 0;
		if (m_Direction.x == DIRECTION::DIRECTION_LEFT)
		this->m_Velocity.x = GRAVITY * m_Direction.x;

		this->m_Velocity.y = GRAVITY * m_Direction.y;
			break;
	case COLDIRECTION::COLDIRECTION_RIGHT:
		this->m_Velocity.x = 0;
		if (m_Direction.x == DIRECTION::DIRECTION_RIGHT)
			this->m_Velocity.x = GRAVITY * m_Direction.x;

		this->m_Velocity.y = GRAVITY * m_Direction.y;
		break;
	case COLDIRECTION::COLDIRECTION_TOP:
		this->m_Velocity.x = GRAVITY * m_Direction.x;
		this->m_Velocity.y = 0;
			break;
	case COLDIRECTION::COLDIRECTION_BOTTOM:
		this->m_Velocity.x = GRAVITY * m_Direction.x;
		this->m_Velocity.y = -GRAVITY;
		break;
		default:
			break;
	}
	/*else
		this->m_Velocity = vector2d(GRAVITY, GRAVITY);*/
	
}

void CPlayer::updateEntity(float deltaTime)
{

	/*if (m_State == PLAYERSTATES::STATE_START)
		m_State = PLAYERSTATES::STATE_STAND;*/

	// Update Action
	switch (m_State)
	{
	case PLAYERSTATES::STATE_START:
		logicGravity(deltaTime);
		logicStartPlayer(deltaTime);
		break;

	case PLAYERSTATES::STATE_STAND:
	{
		logicStandPlayer(deltaTime);
		//logicGravity(deltaTime);
	}
		break;

	case PLAYERSTATES::STATE_MOVE: 
	case PLAYERSTATES::STATE_MOVE_SHOOT:
		logicMovePlayer(deltaTime);
		//logicGravity(deltaTime);
		break;

	case PLAYERSTATES::STATE_JUMP:
	case PLAYERSTATES::STATE_JUMP_SHOOT:
		{
			logicJumpPlayer(deltaTime);
			if (m_Direction.x != 0 && m_Direction.y != 0)
				logicMovePlayer(deltaTime);
			//logicGravity(deltaTime);
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

	

	//if (m_Position.y < 50)
	//{
	//	m_Position.y = 50;
	//	m_Accelero.y = 5;
	//	m_Velocity.y = GRAVITY;
	//	//m_State = PLAYERSTATES::STATE_STAND;
	//}

	// Update State
	m_TimeState += deltaTime;

}

void CPlayer::updateEntity(CKeyBoard* device)
{
	if (device->KeyPress(DIK_1))
	{
		this->m_listSprite.clear();
		//this->loadSprite();
		for (int i = 0; i < m_RockManSpriteList[ROCKMAN_CUT_SKILL].size(); ++i)
			this->m_listSprite.push_back(this->m_RockManSpriteList[ROCKMAN_CUT_SKILL].at(i));
	}

	if (device->KeyPress(DIK_2))
	{
		this->m_listSprite.clear();
		//this->loadSprite();
		for (int i = 0; i < m_RockManSpriteList[ROCKMAN_BOMB_SKILL].size(); ++i)
			this->m_listSprite.push_back(this->m_RockManSpriteList[ROCKMAN_BOMB_SKILL].at(i));
	}
	if (device->KeyPress(DIK_0))
	{
		this->m_listSprite.clear();
		//this->loadSprite();
		for (int i = 0; i < m_RockManSpriteList[ROCKMAN_NORMAL_SKILL].size(); ++i)
			this->m_listSprite.push_back(this->m_RockManSpriteList[ROCKMAN_NORMAL_SKILL].at(i));
	}

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
			//CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::NORMAL, m_Position, m_Velocity);
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
			//CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::NORMAL, m_Position,m_Velocity);
			m_State			= PLAYERSTATES::STATE_STAND_SHOOT;
			m_TimeState		= 0;
		}
		break;

	case PLAYERSTATES::STATE_MOVE:
		if (device->KeyPress(DIK_Z) && device->KeyPress(DIK_X))
		{
			//CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::NORMAL, m_Position, m_Velocity);
			m_State			= PLAYERSTATES::STATE_JUMP_SHOOT;
			m_TimeState		= 0;
		}
		else if (device->KeyPress(DIK_Z))
		{
			//CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::NORMAL, m_Position, m_Velocity);
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
			m_Direction		= vector2d (DIRECTION::DIRECTION_RIGHT, DIRECTION::DIRECTION_NONE);
			m_Velocity.x	= std::abs(m_Velocity.x) * DIRECTION::DIRECTION_RIGHT;
		}
		else if (device->KeyDown(DIK_LEFT))
		{
			m_Direction		=  vector2d(DIRECTION::DIRECTION_LEFT, DIRECTION::DIRECTION_NONE);
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
			//m_Direction		= vector2d (DIRECTION::DIRECTION_NONE, DIRECTION::DIRECTION_NONE);
			CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::NORMAL, m_Position, m_Velocity);
			m_State			= PLAYERSTATES::STATE_JUMP_SHOOT;
		}
		else if (device->KeyDown(DIK_RIGHT))
		{
			m_Direction		= vector2d (DIRECTION::DIRECTION_RIGHT, DIRECTION::DIRECTION_UP);
			m_Velocity.x	= std::abs(m_Velocity.x) * DIRECTION::DIRECTION_RIGHT;
		}
		else if (device->KeyDown(DIK_LEFT))
		{
			m_Direction		= vector2d (DIRECTION::DIRECTION_LEFT, DIRECTION::DIRECTION_UP);
			m_Velocity.x	= std::abs(m_Velocity.x) * DIRECTION::DIRECTION_LEFT;
		}
		else
		{
			m_Direction.y = DIRECTION::DIRECTION_NONE;

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
			m_Direction		= vector2d (DIRECTION::DIRECTION_RIGHT, DIRECTION::DIRECTION_NONE);
			CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::NORMAL, m_Position, m_Velocity);
			m_State			= PLAYERSTATES::STATE_MOVE_SHOOT;
			m_Velocity.x	= std::abs(m_Velocity.x) * DIRECTION::DIRECTION_RIGHT;
		}
		else if (device->KeyPress(DIK_LEFT))
		{
			m_Direction		= vector2d (DIRECTION::DIRECTION_LEFT, DIRECTION::DIRECTION_NONE);
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
			m_Direction		= vector2d (DIRECTION::DIRECTION_LEFT, DIRECTION::DIRECTION_NONE);
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
			m_Direction		= vector2d (DIRECTION::DIRECTION_RIGHT, DIRECTION::DIRECTION_NONE);
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
			m_Direction = vector2d(DIRECTION::DIRECTION_RIGHT, DIRECTION::DIRECTION_UP);
			if (m_TimeState > TIME_FOR_SHOOT / 2)
			{
				m_State		= PLAYERSTATES::STATE_MOVE;
				m_State		= 0;
			}
			m_Velocity.x	= std::abs(m_Velocity.x) * DIRECTION::DIRECTION_RIGHT;
		}
		else if (device->KeyDown(DIK_LEFT))
		{
			m_Direction		= vector2d (DIRECTION::DIRECTION_LEFT, DIRECTION::DIRECTION_UP);
			if (m_TimeState > TIME_FOR_SHOOT / 2)
			{
				m_State		= PLAYERSTATES::STATE_MOVE;
				m_State		= 0;
			}
			m_Velocity.x	= std::abs(m_Velocity.x) * DIRECTION::DIRECTION_LEFT;
		}
		else
		{
			m_Direction.y		 = DIRECTION::DIRECTION_NONE;
			if (m_TimeState > TIME_FOR_JUMB)
			{
				m_State		= PLAYERSTATES::STATE_STAND;
				m_TimeState = 0;
			}
		}
		break;

	case PLAYERSTATES::STATE_CLIMB:
		if (device->KeyPress(DIK_Z) && device->KeyPress(DIK_X))
		{
			m_State = PLAYERSTATES::STATE_JUMP_SHOOT;
			m_TimeState = 0;
		}
		else if (device->KeyPress(DIK_Z))
		{
			CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::NORMAL, m_Position, m_Velocity);
			m_TimeState = 0;
			m_State = PLAYERSTATES::STATE_CLIMB_SHOOT;
		}
		else if (device->KeyPress(DIK_X))
		{
			m_State = PLAYERSTATES::STATE_JUMP;
			m_TimeState = 0;
		}
		else if (device->KeyDown(DIK_UP))
		{
			m_Direction.y	= DIRECTION::DIRECTION_UP;
			m_Velocity.y	= std::abs(m_Velocity.y) * DIRECTION::DIRECTION_UP; 
		}
		else if (device->KeyDown(DIK_DOWN))
		{
			m_Direction.y = DIRECTION::DIRECTION_DOWN;
			m_Velocity.y = std::abs(m_Velocity.y) * DIRECTION::DIRECTION_DOWN;
		}
		else
		{
			m_Direction.y = DIRECTION::DIRECTION_NONE;
			m_State = PLAYERSTATES::STATE_CLIMB;
		}
		break;

	case PLAYERSTATES::STATE_CLIMB_SHOOT:
		if (device->KeyPress(DIK_X))
		{
			m_State = PLAYERSTATES::STATE_JUMP;
		}
		else if (device->KeyDown(DIK_LEFT))
		{
			m_Direction.x = DIRECTION::DIRECTION_LEFT;
			m_Velocity.x	= std::abs(m_Velocity.x) * DIRECTION::DIRECTION_LEFT;

			if (device->KeyPress(DIK_Z))
			{
				if (m_TimeState > TIME_FOR_SHOOT)
				{
					m_State = PLAYERSTATES::STATE_CLIMB;
				}
				else
					CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::NORMAL, m_Position, m_Velocity);
					//m_State = PLAYERSTATES::STATE_CLIMB;
					m_TimeState = 0;
			}
			else
			{
				if (m_TimeState > TIME_FOR_SHOOT * 0.2)
				{
					m_State = PLAYERSTATES::STATE_CLIMB;
					m_TimeState = 0;
				}
			}
		}
		else if (device->KeyDown(DIK_RIGHT))
		{
			m_Direction.x	= DIRECTION::DIRECTION_RIGHT;
			m_Velocity.x	= std::abs(m_Velocity.x) * DIRECTION::DIRECTION_RIGHT;

			if (device->KeyPress(DIK_Z))
			{
				if (m_TimeState > TIME_FOR_SHOOT)
				{
					m_State = PLAYERSTATES::STATE_CLIMB;
				}
				else
				CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::NORMAL, m_Position, m_Velocity);
				m_TimeState = 0;
			}
			else
			{
				if (m_TimeState > TIME_FOR_SHOOT * 0.2)
				{
					m_State = PLAYERSTATES::STATE_CLIMB;
					m_TimeState = 0;
				}
			}
		}
		else if (device->KeyDown(DIK_UP))
		{
			m_Direction.y	= DIRECTION::DIRECTION_UP;
			m_State			= PLAYERSTATES::STATE_CLIMB;
			m_Velocity.y	= std::abs(m_Velocity.y)*DIRECTION::DIRECTION_UP;
		}
		else if (device->KeyDown(DIK_DOWN))
		{
			m_Direction.y	= DIRECTION::DIRECTION_DOWN;
			m_State			= PLAYERSTATES::STATE_CLIMB;
			m_Velocity.y	= std::abs(m_Velocity.y)*DIRECTION::DIRECTION_DOWN;
		}

		else
		{
			//CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::NORMAL, m_Position, m_Velocity);
			//m_Direction.x = DIRECTION::DIRECTION_NONE;
			if (m_TimeState > TIME_FOR_SHOOT)
			{
				m_State = PLAYERSTATES::STATE_CLIMB;
			}
			else
				CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::NORMAL, m_Position, m_Velocity);
			m_TimeState = 0;
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
		m_listSprite.at(m_State)->Render(CCamera::setPositionEntity(vector3d(m_Position.x + m_Direction.x * DELTA_FIX_SIZE_RESOURCE, m_Position.y, 0.5f)),
											vector2d(SIGN(m_Velocity.x) * 2, 2),
											0,
											DRAWCENTER_MIDDLE_MIDDLE,
											true,
											10);
		break;

	case PLAYERSTATES::STATE_CLIMB:
		if (m_Direction.y != 0)
			m_listSprite.at(m_State)->Render(CCamera::setPositionEntity(m_Position), vector2d(m_Direction.x * 2, 2), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
		else
			m_listSprite.at(m_State)->Render(1, 1, CCamera::setPositionEntity(m_Position), vector2d(m_Direction.x * 2, 2), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
		break;
	default:
		m_listSprite.at(m_State)->Render(CCamera::setPositionEntity(m_Position), vector2d(m_Direction.x * 2, 2), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
		break;
	}

}

void CPlayer::logicMovePlayer(float deltaTime)
{

	m_Position.x += m_Velocity.x*deltaTime;
}

void CPlayer::logicJumpPlayer(float deltaTime)
{	

		if (m_TimeState < 550 )
		{
			m_Direction.y = DIRECTION::DIRECTION_UP;
		}
		else
		{
			m_Direction.y = DIRECTION::DIRECTION_DOWN;
		}
			m_Position.y	+= std::abs(m_Velocity.y*deltaTime) * m_Direction.y;
}

void CPlayer::logicStartPlayer(float deltaTime)
{
	if (m_Position.y <= 120)
	{
		m_Position.y = 500;
		m_State = PLAYERSTATES::STATE_STAND;
		m_Velocity.y = GRAVITY;
		m_Direction.x = DIRECTION::DIRECTION_UP;
	}
}

void CPlayer::logicStandPlayer(float deltaTime)
{
	if (m_Velocity.y > 0)
	m_Velocity.y	= GRAVITY*DIRECTION::DIRECTION_DOWN;
	m_Position.y	+= m_Velocity.y* deltaTime;

}

void CPlayer::logicClimbPlayer(float deltaTime)
{
	if (m_Direction.y != 0)
	m_Position.y += m_Velocity.y* deltaTime;
}

vector3d CPlayer::getPosition()
{
	return m_Position;
}
