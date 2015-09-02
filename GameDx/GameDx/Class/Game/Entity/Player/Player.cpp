#include "Player.h"
#include "Game\Utill\InformationResource.h"
#include "Game\Entity\Bullet\BulletManager.h"

bool CheckOverlapCollision(int key, vector<CollisionEvents*> listCollisionEvents, CBaseEntity* entity)
{
	for (int i = 0; i < listCollisionEvents.size(); ++i)
	{
		if (listCollisionEvents.at(i)->m_CollisionDirection == key && listCollisionEvents.at(i)->m_Entity == entity)
			return false;
	}
	return true;
}


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
	m_Position		= vector3d(135, 150, 0.5);
	m_Velocity		= vector2d(GRAVITYSTART, GRAVITYSTART);
	m_Accelero		= vector2d(0, 0.01);
	m_State			= PLAYSTATE::START;
	m_TimeState		= 0;
	m_Direction		= vector2d(DIRECTION::DIRECTION_NONE, DIRECTION::DIRECTION_NONE);
	m_RockManSpriteList = new vector<CSprite*>[NUM_OF_ROCKMAN_SKILL];

	this->loadSprite();
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
	
	for (int i = 0; i < m_RockManSpriteList[ROCKMAN_NORMAL_SKILL].size(); ++i)
		this->m_listSprite.push_back(this->m_RockManSpriteList[ROCKMAN_NORMAL_SKILL].at(i));
	
	return true;
}

void CPlayer::resetObject()
{

}

void CPlayer::updateEntity(float deltaTime)
{
	OutputDebugString(L"\n LISTSIZZZZZZZZZZZZZZ: ");
	OutputDebugString(_itow(m_listCollitionEvent.size(), new WCHAR[1], 10));

	OutputDebugString(L"\n DeltaTime: ");
	OutputDebugString(_itow(deltaTime, new WCHAR[1], 10));
	for (int i = 0; i < m_listCollitionEvent.size(); ++i)
	{
		OutputDebugString(_itow(m_listCollitionEvent.at(i)->m_CollisionDirection, new WCHAR[1], 10));

	}
	// Update State
	m_TimeState += deltaTime;

	//Update State
	switch (m_State)
	{
	case PLAYERSTATES::STATE_START:
		if (m_listCollitionEvent.empty())
		{
			m_Direction.y		= DIRECTION::DIRECTION_DOWN;
			m_Velocity.y		= GRAVITY * m_Direction.y;
			m_State				= PLAYERSTATES::STATE_STAND;
		}
		for (int i = 0; i < m_listCollitionEvent.size(); ++i)
		{
			switch (m_listCollitionEvent.at(i)->m_CollisionDirection)
			{
			case COLDIRECTION::COLDIRECTION_LEFT:
				break;
			case COLDIRECTION::COLDIRECTION_RIGHT:
				break;
			case COLDIRECTION::COLDIRECTION_TOP:
				m_Direction.y		= DIRECTION::DIRECTION_DOWN;
				m_Velocity.y		= GRAVITY * m_Direction.y;
				m_State = PLAYERSTATES::STATE_STAND;
				break;
			case COLDIRECTION::COLDIRECTION_BOTTOM:
				m_Direction.y		= DIRECTION::DIRECTION_DOWN;
				m_Velocity.y		= GRAVITY * m_Direction.y;
				break;
			default:
				break;
			}
		}
		if (deltaTime > 0 && deltaTime < 20)
		m_Position.y += m_Velocity.y * deltaTime;

	break;
	case PLAYERSTATES::STATE_STAND:
	case PLAYERSTATES::STATE_STAND_SHOOT:

		OutputDebugString(L"\n LISTSIZESTAND: ");
		OutputDebugString(_itow(m_listCollitionEvent.size(), new WCHAR[1], 10));
		if (m_listCollitionEvent.size() > 1)
		{
		OutputDebugString(_itow(m_listCollitionEvent.at(0)->m_CollisionDirection, new WCHAR[1], 10));
		OutputDebugString(_itow(m_listCollitionEvent.at(1)->m_CollisionDirection, new WCHAR[1], 10));
		}
		if (m_listCollitionEvent.empty())
		{
			m_Velocity.x			= 0;
			m_Direction.y			= DIRECTION::DIRECTION_DOWN;
			m_Velocity.y			= GRAVITY * m_Direction.y;
			//m_State				= PLAYERSTATES::STATE_JUMP;
			
		}

		for (int i = 0; i < m_listCollitionEvent.size(); ++i)
		{
			switch (m_listCollitionEvent.at(i)->m_CollisionDirection)
			{
			case COLDIRECTION::COLDIRECTION_LEFT:
				OutputDebugString(L"\n STANDLEFT: ");
				m_Velocity.x		= 0;
				if (m_Direction.x == DIRECTION::DIRECTION_LEFT)
					m_Velocity.x	= MOVESPEED * m_Direction.x;

				break;
			case COLDIRECTION::COLDIRECTION_RIGHT:
				m_Velocity.x		= 0;
				if (m_Direction.x == DIRECTION::DIRECTION_RIGHT)
					m_Velocity.x	= MOVESPEED * m_Direction.x;

				break;
			case COLDIRECTION::COLDIRECTION_TOP:
				OutputDebugString(L"\n STANDTOP: ");
				OutputDebugString(_itow(deltaTime, new WCHAR[1], 10));
				m_Velocity.y = 0;
				m_Velocity.x = 0;
				if (m_Direction.y == DIRECTION::DIRECTION_UP)
				{
					m_TimeState		= 0;
					m_Velocity.y	= GRAVITY * m_Direction.y;
				}
				break;
			case COLDIRECTION::COLDIRECTION_BOTTOM:
				m_Direction.y		= DIRECTION::DIRECTION_DOWN;
				m_Velocity.y		= GRAVITY * m_Direction.y;
				break;
			default:
				break;
			}
		}
		if (deltaTime > 0 && deltaTime < 20)
		{
			m_Position.x += m_Velocity.x *deltaTime;
			m_Position.y += m_Velocity.y * deltaTime;
		}

	break;

	case PLAYERSTATES::STATE_MOVE:
	case PLAYERSTATES::STATE_MOVE_SHOOT:
		if (m_listCollitionEvent.empty())
		{
			OutputDebugString(L"\n NO: ");
			m_Velocity.x			= 0;
			m_Direction.y			= DIRECTION::DIRECTION_DOWN;
			m_Velocity.y			= GRAVITY * m_Direction.y;
			//m_State					= PLAYERSTATES::STATE_JUMP;
		}
		OutputDebugString(L"\n LISTSIZEMOVE: ");
		OutputDebugString(_itow(m_listCollitionEvent.size(), new WCHAR[1], 10));
		for (int i = 0; i < m_listCollitionEvent.size(); ++i)
		{
			OutputDebugString(_itow(m_listCollitionEvent.at(i)->m_CollisionDirection, new WCHAR[1], 10));

		}

		for (int i = 0; i < m_listCollitionEvent.size(); ++i)
		{
			switch (m_listCollitionEvent.back()->m_CollisionDirection)
			{
			case COLDIRECTION::COLDIRECTION_LEFT:
				OutputDebugString(L"\n LEFT: ");
				m_Velocity.x		= 0;
				if (m_Direction.x == DIRECTION::DIRECTION_LEFT)
					m_Velocity.x	= MOVESPEED * m_Direction.x;

				break;
			case COLDIRECTION::COLDIRECTION_RIGHT:
				OutputDebugString(L"\n RIGHT: ");
				m_Velocity.x		= 0;
				if (m_Direction.x == DIRECTION::DIRECTION_RIGHT)
					m_Velocity.x	= MOVESPEED * m_Direction.x;

				break;
			case COLDIRECTION::COLDIRECTION_TOP:
				OutputDebugString(L"\n TOP: ");
				m_Velocity.y		= 0;
				m_Velocity.x		= MOVESPEED * m_Direction.x;
				if (m_Direction.y == DIRECTION::DIRECTION_UP)
				{
					m_TimeState		= 0;
					m_Velocity.y	= GRAVITY * m_Direction.y;
				}
				break;
			case COLDIRECTION::COLDIRECTION_BOTTOM:
				OutputDebugString(L"\n BOT: ");
				m_Direction.y		= DIRECTION::DIRECTION_DOWN;
				m_Velocity.y		= GRAVITY * m_Direction.y;
				break;
			default:
				break;
			}
			m_listCollitionEvent.pop_back();
		}
		OutputDebugString(L"\n VEL: ");
		OutputDebugString(_itow(m_Velocity.x * 100, new WCHAR[1], 10));

		m_Position.x += m_Velocity.x * deltaTime;
		m_Position.y += m_Velocity.y * deltaTime;
		break;

	case PLAYERSTATES::STATE_JUMP:
	case PLAYERSTATES::STATE_JUMP_SHOOT:
		for (int i = 0; i < m_listCollitionEvent.size(); ++i)
		{
			switch (m_listCollitionEvent.at(i)->m_CollisionDirection)
			{
			case COLDIRECTION::COLDIRECTION_LEFT:
				m_Velocity.x		= 0;
				break;
			case COLDIRECTION::COLDIRECTION_RIGHT:
				m_Velocity.x		= 0;
				break;
			case COLDIRECTION::COLDIRECTION_TOP:
				if (m_Velocity.y < 0)
				{
					m_Velocity.y	= 0;
					m_TimeState		= 0;
					m_State			= PLAYERSTATES::STATE_STAND;
				}
				else
				{
					m_Direction.y	= DIRECTION::DIRECTION_UP;
					m_Velocity.y	= GRAVITY * m_Direction.y;
				}
				break;
			case COLDIRECTION::COLDIRECTION_BOTTOM:
				m_Direction.y		= DIRECTION::DIRECTION_DOWN;
				m_Velocity.y		= GRAVITY * m_Direction.y;
				break;
			default:
				break;
			}
				//m_listCollitionEvent.pop_back();
		}

		if (m_listCollitionEvent.empty())
		{
			if (m_TimeState > TIME_FOR_JUMB / 2)
			{
				m_Direction.y		= DIRECTION::DIRECTION_DOWN;
				m_Velocity.y		= GRAVITY * m_Direction.y;
			}
		}
		m_Position.x += m_Velocity.x * deltaTime;
		m_Position.y += m_Velocity.y * deltaTime;

	break;

	case PLAYERSTATES::STATE_CLIMB:
		m_Position.y += m_Velocity.y * deltaTime;
		break;

	default:
	break;
	}

}

void CPlayer::updateEntity(CKeyBoard* device)
{
	m_listCollitionEvent.clear();

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
	case PLAYERSTATES::STATE_START:
		break;
	case PLAYERSTATES::STATE_STAND:
		if (device->KeyDown(DIK_RIGHT))
		{
			m_listCollitionEvent.clear();
			m_Direction		= vector2d(DIRECTION::DIRECTION_RIGHT, DIRECTION::DIRECTION_NONE);
		//	m_Velocity.x	= GRAVITY * m_Direction.x;
			m_State			= PLAYERSTATES::STATE_MOVE;
		}
		else if (device->KeyDown(DIK_LEFT))
		{
			m_Direction		= vector2d (DIRECTION::DIRECTION_LEFT, DIRECTION::DIRECTION_NONE);
		//	m_Velocity.x	= GRAVITY * m_Direction.x;
			m_State			= PLAYERSTATES::STATE_MOVE;
		}
		else if (device->KeyPress(DIK_Z) && device->KeyPress(DIK_X))
		{
			//CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::NORMAL, m_Position, m_Velocity);
			m_Direction.y	= DIRECTION::DIRECTION_UP;
			m_Velocity.y	= GRAVITY * m_Direction.y;
			m_TimeState		= 0;
			m_State			= PLAYERSTATES::STATE_JUMP_SHOOT;
		}
		else if (device->KeyPress(DIK_X))
		{
			m_Direction.y	= DIRECTION::DIRECTION_UP;
			m_Velocity.y	= GRAVITY * m_Direction.y;
			m_TimeState		= 0;
			m_State			= PLAYERSTATES::STATE_JUMP;
		}
		else if (device->KeyPress(DIK_UP))
		{
			m_Direction.y	= DIRECTION::DIRECTION_UP;
			m_State			= PLAYERSTATES::STATE_CLIMB;
		}
		else if (device->KeyPress(DIK_Z))
		{
			//CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::NORMAL, m_Position,m_Velocity);
			m_TimeState		= 0;
			m_State			= PLAYERSTATES::STATE_STAND_SHOOT;
		}
		else
		{
			m_Velocity.x	= 0;
			m_Velocity.y	= 0;
			m_Direction.y	= DIRECTION::DIRECTION_DOWN;
		}
		break;

	case PLAYERSTATES::STATE_MOVE:
		if (device->KeyPress(DIK_Z) && device->KeyPress(DIK_X))
		{
			//CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::NORMAL, m_Position, m_Velocity);
			m_Direction.y	= DIRECTION::DIRECTION_UP;
			m_Velocity.y	= GRAVITY * m_Direction.y;
			m_TimeState		= 0;
			m_State			= PLAYERSTATES::STATE_JUMP_SHOOT;
		}
		else if (device->KeyPress(DIK_Z))
		{
			//CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::NORMAL, m_Position, m_Velocity);
			m_TimeState		= 0;
			m_State			= PLAYERSTATES::STATE_MOVE_SHOOT;
		}
		else if (device->KeyPress(DIK_X))
		{
			m_Direction.y	= DIRECTION::DIRECTION_UP;
			m_Velocity.y	= GRAVITY *m_Direction.y;
			m_TimeState		= 0;
			m_State			= PLAYERSTATES::STATE_JUMP;
		}
		else if (device->KeyDown(DIK_RIGHT))
		{
			m_Direction		= vector2d (DIRECTION::DIRECTION_RIGHT, DIRECTION::DIRECTION_NONE);
			m_Velocity.x	= MOVESPEED * m_Direction.x;
			
		}
		else if (device->KeyDown(DIK_LEFT))
		{
			m_Direction		= vector2d(DIRECTION::DIRECTION_LEFT, DIRECTION::DIRECTION_NONE);
			m_Velocity.x	= MOVESPEED * m_Direction.x;
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
			//CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::NORMAL, m_Position, m_Velocity);
			m_TimeState		= 0;
			m_State			= PLAYERSTATES::STATE_JUMP_SHOOT;
		}
		else if (device->KeyDown(DIK_RIGHT))
		{
			m_Direction.x	= DIRECTION::DIRECTION_RIGHT;
			m_Velocity.x	= MOVESPEED * m_Direction.x;
		}
		else if (device->KeyDown(DIK_LEFT))
		{
			m_Direction	.x	= DIRECTION::DIRECTION_LEFT;
			m_Velocity.x	= MOVESPEED * m_Direction.x;
		}
		else
		{
			m_Velocity.y	= GRAVITY * m_Direction.y;
			m_Velocity.x	= 0;
		}
		break;

	case PLAYERSTATES::STATE_STAND_SHOOT:
		
		if (device->KeyPress(DIK_Z))
		{
			//CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::NORMAL, m_Position, m_Velocity);

			if (m_TimeState > TIME_FOR_SHOOT)
			{
				m_State		= PLAYERSTATES::STATE_STAND;
			}
			else
				m_TimeState = 0;
				//CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::NORMAL, m_Position, m_Velocity);
		}
		else if (device->KeyPress(DIK_RIGHT))
		{
			m_Direction		= vector2d (DIRECTION::DIRECTION_RIGHT, DIRECTION::DIRECTION_NONE);
			//CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::NORMAL, m_Position, m_Velocity);
			m_Velocity.x	= MOVESPEED * m_Direction.x;
			m_State			= PLAYERSTATES::STATE_MOVE_SHOOT;
		}
		else if (device->KeyPress(DIK_LEFT))
		{
			m_Direction		= vector2d (DIRECTION::DIRECTION_LEFT, DIRECTION::DIRECTION_NONE);
			//CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::NORMAL, m_Position, m_Velocity);
			m_Velocity.x	= MOVESPEED * m_Direction.x;
			m_State			= PLAYERSTATES::STATE_MOVE_SHOOT;
		}
		else if (device->KeyPress(DIK_X))
		{
			m_Direction.y	= DIRECTION::DIRECTION_UP;
			m_Velocity.y	= GRAVITY * m_Direction.y;
			m_TimeState		= 0;
			m_State			= PLAYERSTATES::STATE_JUMP;
		}
		else
		{
			if (m_TimeState > TIME_FOR_SHOOT * 0.2)
			{
				m_State		= PLAYERSTATES::STATE_STAND;
				//m_TimeState = 0;
			}
		}
		break;

	case PLAYERSTATES::STATE_MOVE_SHOOT:
		if (device->KeyDown(DIK_X))
		{
			m_Direction.y	= DIRECTION::DIRECTION_UP;
			m_TimeState		= 0;
			m_Velocity.y	= GRAVITY * m_Direction.y;
			m_State			= PLAYERSTATES::STATE_JUMP;
		}
		else if (device->KeyDown(DIK_LEFT))
		{
			m_Direction		= vector2d (DIRECTION::DIRECTION_LEFT, DIRECTION::DIRECTION_NONE);
			m_Velocity.x	= MOVESPEED * m_Direction.x;

			if (device->KeyPress(DIK_Z))
			{
				if (m_TimeState > TIME_FOR_SHOOT)
				{
					m_State		= PLAYERSTATES::STATE_MOVE;
				}
				else
					//CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::NORMAL, m_Position, m_Velocity);
					m_TimeState	= 0;
			}
			else
			{
				if (m_TimeState > TIME_FOR_SHOOT * 0.2)
				{
					m_State		= PLAYERSTATES::STATE_MOVE;
					//m_TimeState = 0;
				}
			}
		}
		else if (device->KeyDown(DIK_RIGHT))
		{
			m_Direction			= vector2d (DIRECTION::DIRECTION_RIGHT, DIRECTION::DIRECTION_NONE);
			m_Velocity.x		= MOVESPEED * m_Direction.x;

			if (device->KeyPress(DIK_Z))
			{
				if (m_TimeState > TIME_FOR_SHOOT)
				{
					m_State		= PLAYERSTATES::STATE_MOVE;
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
				}
			}
		}
		else
		{
			if (m_TimeState > TIME_FOR_SHOOT * 0.2)
			{
				m_State			= PLAYERSTATES::STATE_MOVE;
			}
		}
		break;

	case PLAYERSTATES::STATE_JUMP_SHOOT:
		if (device->KeyDown(DIK_RIGHT))
		{
			m_Direction			= vector2d(DIRECTION::DIRECTION_RIGHT, DIRECTION::DIRECTION_UP);
			if (m_TimeState > TIME_FOR_SHOOT * 2)
			{
				m_State			= PLAYERSTATES::STATE_MOVE;
				m_State			= 0;
			}
			m_Velocity.x		= MOVESPEED * m_Direction.x;
		}
		else if (device->KeyDown(DIK_LEFT))
		{
			m_Direction			= vector2d (DIRECTION::DIRECTION_LEFT, DIRECTION::DIRECTION_UP);
			if (m_TimeState > TIME_FOR_SHOOT * 2)
			{
				m_State			= PLAYERSTATES::STATE_MOVE;
				m_State			= 0;
			}
			m_Velocity.x		= MOVESPEED * DIRECTION::DIRECTION_LEFT;
		}
		else
		{
			m_Velocity.y		= GRAVITY * m_Direction.y;
			m_Velocity.x		= 0;
		}
		break;

	case PLAYERSTATES::STATE_CLIMB:
		if (device->KeyPress(DIK_Z) && device->KeyPress(DIK_X))
		{
			m_TimeState			= 0;
			m_State				= PLAYERSTATES::STATE_JUMP_SHOOT;
		}
		else if (device->KeyPress(DIK_Z))
		{
			//CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::NORMAL, m_Position, m_Velocity);
			m_TimeState			= 0;
			m_State				= PLAYERSTATES::STATE_CLIMB_SHOOT;
		}
		else if (device->KeyPress(DIK_X))
		{
			m_TimeState			= 0;
			m_State				= PLAYERSTATES::STATE_JUMP;
		}
		else if (device->KeyDown(DIK_UP))
		{
			m_Direction.y		= DIRECTION::DIRECTION_UP;
			m_Velocity.y		= GRAVITY * DIRECTION::DIRECTION_UP; 
		}
		else if (device->KeyDown(DIK_DOWN))
		{
			m_Direction.y		= DIRECTION::DIRECTION_DOWN;
			m_Velocity.y		= GRAVITY * DIRECTION::DIRECTION_DOWN;
		}
		else
		{
			m_Direction.y		= DIRECTION::DIRECTION_NONE;
			m_Velocity.y		= GRAVITY * m_Direction.y;
			//m_State			= PLAYERSTATES::STATE_CLIMB;
		}
		break;

	case PLAYERSTATES::STATE_CLIMB_SHOOT:
		if (device->KeyPress(DIK_X))
		{
			m_State				= PLAYERSTATES::STATE_JUMP;
		}
		else if (device->KeyDown(DIK_LEFT))
		{
			m_Direction.x		= DIRECTION::DIRECTION_LEFT;
			m_Velocity.x		= MOVESPEED * DIRECTION::DIRECTION_LEFT;

			if (device->KeyPress(DIK_Z))
			{
				if (m_TimeState > TIME_FOR_SHOOT)
				{
					m_State		= PLAYERSTATES::STATE_CLIMB;
				}
				else
					//CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::NORMAL, m_Position, m_Velocity);
					//m_State = PLAYERSTATES::STATE_CLIMB;
					m_TimeState = 0;
			}
			else
			{
				if (m_TimeState > TIME_FOR_SHOOT * 0.2)
				{
					m_State		= PLAYERSTATES::STATE_CLIMB;
					m_TimeState = 0;
				}
			}
		}
		else if (device->KeyDown(DIK_RIGHT))
		{
			m_Direction.x		= DIRECTION::DIRECTION_RIGHT;
			m_Velocity.x		= MOVESPEED * DIRECTION::DIRECTION_RIGHT;

			if (device->KeyPress(DIK_Z))
			{
				if (m_TimeState > TIME_FOR_SHOOT)
				{
					m_State		= PLAYERSTATES::STATE_CLIMB;
				}
				else
				//CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::NORMAL, m_Position, m_Velocity);
				m_TimeState		= 0;
			}
			else
			{
				if (m_TimeState > TIME_FOR_SHOOT * 0.2)
				{
					m_State		= PLAYERSTATES::STATE_CLIMB;
					m_TimeState = 0;
				}
			}
		}
		else if (device->KeyDown(DIK_UP))
		{
			m_Direction.y		= DIRECTION::DIRECTION_UP;
			m_State				= PLAYERSTATES::STATE_CLIMB;
			m_Velocity.y		= GRAVITY * DIRECTION::DIRECTION_UP;
		}
		else if (device->KeyDown(DIK_DOWN))
		{
			m_Direction.y		= DIRECTION::DIRECTION_DOWN;
			m_State				= PLAYERSTATES::STATE_CLIMB;
			m_Velocity.y		= GRAVITY * DIRECTION::DIRECTION_DOWN;
		}

		else
		{
			//CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::NORMAL, m_Position, m_Velocity);
			//m_Direction.x = DIRECTION::DIRECTION_NONE;
			if (m_TimeState > TIME_FOR_SHOOT / 2)
			{
				m_State			= PLAYERSTATES::STATE_CLIMB;
				m_TimeState		= 0;
			}
			//else
				//CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::NORMAL, m_Position, m_Velocity);
		}

		break;
	default:
		//m_State				= PLAYERSTATES::STATE_STAND;
		break;
	}
}

void CPlayer::updateEntity(CBaseEntity* entity)
{
	if (CCollision::CheckCollision(this, entity) == COLDIRECTION::COLDIRECTION_LEFT)
	{
		//if (!CheckOverlapCollision(COLDIRECTION::COLDIRECTION_LEFT, m_listCollitionEvent, entity))
			m_listCollitionEvent.push_back(new CollisionEvents(COLDIRECTION::COLDIRECTION_LEFT, entity));
	}
	else if (CCollision::CheckCollision(this, entity) == COLDIRECTION::COLDIRECTION_RIGHT)
	{
	//	if (!CheckOverlapCollision(COLDIRECTION::COLDIRECTION_RIGHT, m_listCollitionEvent, entity))
			m_listCollitionEvent.push_back(new CollisionEvents(COLDIRECTION::COLDIRECTION_RIGHT, entity));
	}
	else if (CCollision::CheckCollision(this, entity) == COLDIRECTION::COLDIRECTION_TOP)
	{
		//if (!CheckOverlapCollision(COLDIRECTION::COLDIRECTION_TOP, m_listCollitionEvent, entity))
			m_listCollitionEvent.push_back(new CollisionEvents(COLDIRECTION::COLDIRECTION_TOP, entity));
	}
	else if (CCollision::CheckCollision(this, entity) == COLDIRECTION::COLDIRECTION_BOTTOM)
	{
		//if (!CheckOverlapCollision(COLDIRECTION::COLDIRECTION_BOTTOM, m_listCollitionEvent, entity))
			m_listCollitionEvent.push_back(new CollisionEvents(COLDIRECTION::COLDIRECTION_BOTTOM, entity));
	}
}

void CPlayer::drawEntity()
{
	switch (m_State)
	{
	case PLAYERSTATES::STATE_STAND_SHOOT:
	case PLAYERSTATES::STATE_MOVE_SHOOT:
		m_listSprite.at(m_State)->Render(CCamera::setPositionEntity(vector3d(m_Position.x + SIGN(m_Direction.x) * DELTA_FIX_SIZE_RESOURCE, m_Position.y, 0.5f)),
											vector2d(SIGN(m_Direction.x) * 1, 1),
											0,
											DRAWCENTER_MIDDLE_MIDDLE,
											true,
											10);
		break;
		\
	case PLAYERSTATES::STATE_CLIMB:
		if (m_Direction.y != 0)
			m_listSprite.at(m_State)->Render(CCamera::setPositionEntity(m_Position), vector2d(SIGN(m_Direction.x) * 1, 1), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
		else
			m_listSprite.at(m_State)->Render(1, 1, CCamera::setPositionEntity(m_Position), vector2d(SIGN(m_Direction.x) * 1, 1), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
		break;
	default:
		m_listSprite.at(m_State)->Render(CCamera::setPositionEntity(m_Position), vector2d(SIGN(m_Direction.x) * 1, 1), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
		break;
	}

}

vector3d CPlayer::getPosition()
{
	return m_Position;
}
