#include "Player.h"
#include "Game\Utill\InformationResource.h"
#include "Game\Entity\Bullet\BulletManager.h"

inline bool haveEventInList(vector<CollisionEvents*> listEvent, int styleEventCollision);
inline bool	onSensor(vector3d pos1, vector2d sensorOfPos1, vector3d pos2);

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
	m_Position						= vector3d(100, 60, 0.5);
	m_Velocity						= vector2d(GRAVITYSTART, GRAVITYSTART);
	m_Accelero						= vector2d(0, 0.01);
	m_State							= PLAYSTATE::START;
	m_TimeState						= 0;
	m_Direction						= vector2d(DIRECTION::DIRECTION_RIGHT, DIRECTION::DIRECTION_NONE);
	m_RockManSpriteList				= new vector<CSprite*>[NUM_OF_ROCKMAN_SKILL];
	this->m_isColisWithStair		= false;
	this->loadSprite();
	this->m_Bounding				= new CBox2D(0, 0, 0, 0);


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

void CPlayer::setColisWithStair(bool isCol)
{
	m_isColisWithStair = isCol;
}

void CPlayer::updateEntity(float deltaTime)
{
	// update Pos by Camera
	// SpagetiCode...But it's easy to implement.
	if (m_Position.x <= CCamera::getInstance()->getSizeForState().x &&
			CCamera::getInstance()->getStateCamera() == CAMERASTATE::CAMERA_X)
		m_Position.x = CCamera::getInstance()->getSizeForState().x;

	if (m_Position.x >= CCamera::getInstance()->getSizeForState().y &&
		CCamera::getInstance()->getStateCamera() == CAMERASTATE::CAMERA_X)
		m_Position.x = CCamera::getInstance()->getSizeForState().y;

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
				m_State				= PLAYERSTATES::STATE_STAND;
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

		if (m_listCollitionEvent.empty())
		{
			m_Velocity.x			= 0;
			m_Direction.y			= DIRECTION::DIRECTION_DOWN;
			m_Velocity.y			= GRAVITY * m_Direction.y;
			m_State					= PLAYERSTATES::STATE_JUMP;
			
		}

		for (int i = 0; i < m_listCollitionEvent.size(); ++i)
		{
			switch (m_listCollitionEvent.at(i)->m_CollisionDirection)
			{
			case COLDIRECTION::COLDIRECTION_LEFT:
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
			m_Velocity.x			= 0;
			m_Direction.y			= DIRECTION::DIRECTION_DOWN;
			m_Velocity.y			= GRAVITY * m_Direction.y;
			m_State					= PLAYERSTATES::STATE_JUMP;
		}
		
		for (int i = 0; i < m_listCollitionEvent.size(); ++i)
		{
			switch (m_listCollitionEvent.back()->m_CollisionDirection)
			{
			case COLDIRECTION::COLDIRECTION_LEFT:
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
				m_Velocity.y		= 0;
				m_Velocity.x		= MOVESPEED * m_Direction.x;
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
			m_listCollitionEvent.pop_back();
		}

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
		if (m_isColisWithStair)
		{
			if (m_Direction.y == DIRECTION::DIRECTION_UP)
				m_Position.y += m_Velocity.y * deltaTime;
			if (m_Direction.y == DIRECTION::DIRECTION_DOWN)
				m_Position.y += m_Velocity.y * deltaTime;
		}
		else
		{
			m_State			= PLAYERSTATES::STATE_JUMP;
			m_Direction.y	= DIRECTION::DIRECTION_UP;
		}

		break;

	default:
	break;
	}

}

void CPlayer::updateEntity(CKeyBoard* device)
{
	m_listCollitionEvent.clear();

	if (CCamera::getInstance()->getStateCamera() == CAMERASTATE::CAMERA_UP || CCamera::getInstance()->getStateCamera() == CAMERASTATE::CAMERA_DOWN)
	{
		m_Direction.y	= DIRECTION_NONE;
		return;
	}

	if (device->KeyPress(DIK_1))
	{
		this->m_listSprite.clear();
		for (int i = 0; i < m_RockManSpriteList[ROCKMAN_CUT_SKILL].size(); ++i)
			this->m_listSprite.push_back(this->m_RockManSpriteList[ROCKMAN_CUT_SKILL].at(i));
	}

	if (device->KeyPress(DIK_2))
	{
		this->m_listSprite.clear();
		for (int i = 0; i < m_RockManSpriteList[ROCKMAN_BOMB_SKILL].size(); ++i)
			this->m_listSprite.push_back(this->m_RockManSpriteList[ROCKMAN_BOMB_SKILL].at(i));
	}
	if (device->KeyPress(DIK_0))
	{
		this->m_listSprite.clear();
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
			m_State			= PLAYERSTATES::STATE_MOVE;
		}
		else if (device->KeyDown(DIK_LEFT))
		{
			m_Direction		= vector2d (DIRECTION::DIRECTION_LEFT, DIRECTION::DIRECTION_NONE);
			m_State			= PLAYERSTATES::STATE_MOVE;
		}
		else if (device->KeyPress(DIK_Z) && device->KeyPress(DIK_X))
		{
			CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::NORMAL, m_Position, vector2d(MOVESPEED * m_Direction.x, GRAVITY));
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
		else if (device->KeyPress(DIK_UP) && m_isColisWithStair)
		{
			m_Direction.y	= DIRECTION::DIRECTION_UP;
			m_State			= PLAYERSTATES::STATE_CLIMB;
		}
		else if (device->KeyPress(DIK_DOWN) && m_isColisWithStair)
		{
			m_Direction.y = DIRECTION::DIRECTION_DOWN;
			m_State = PLAYERSTATES::STATE_CLIMB;
		}
		else if (device->KeyPress(DIK_Z))
		{
			CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::NORMAL, m_Position, vector2d(MOVESPEED * m_Direction.x, GRAVITY));
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
			CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::NORMAL, m_Position, vector2d(MOVESPEED * m_Direction.x, GRAVITY));
			m_Direction.y	= DIRECTION::DIRECTION_UP;
			m_Velocity.y	= GRAVITY * m_Direction.y;
			m_TimeState		= 0;
			m_State			= PLAYERSTATES::STATE_JUMP_SHOOT;
		}
		else if (device->KeyPress(DIK_Z))
		{
			CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::NORMAL, m_Position, vector2d(MOVESPEED * m_Direction.x, GRAVITY));
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
			CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::NORMAL, m_Position, vector2d(MOVESPEED * m_Direction.x, GRAVITY));
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
			CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::NORMAL, m_Position, vector2d(MOVESPEED * SIGN(m_Direction.x), GRAVITY));

			if (m_TimeState > TIME_FOR_SHOOT)
			{
				m_State		= PLAYERSTATES::STATE_STAND;
			}
			else
			{
				CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::NORMAL, m_Position, vector2d(MOVESPEED * SIGN(m_Direction.x), GRAVITY));
				m_TimeState = 0;
			}
		}
		else if (device->KeyPress(DIK_RIGHT))
		{
			m_Direction		= vector2d (DIRECTION::DIRECTION_RIGHT, DIRECTION::DIRECTION_NONE);
			CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::NORMAL, m_Position, vector2d(MOVESPEED * SIGN(m_Direction.x), GRAVITY));
			m_Velocity.x	= MOVESPEED * m_Direction.x;
			m_State			= PLAYERSTATES::STATE_MOVE_SHOOT;
		}
		else if (device->KeyPress(DIK_LEFT))
		{
			m_Direction		= vector2d (DIRECTION::DIRECTION_LEFT, DIRECTION::DIRECTION_NONE);
			CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::NORMAL, m_Position, vector2d(MOVESPEED * SIGN(m_Direction.x), GRAVITY));
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
		else if (device->KeyDown(DIK_RIGHT))
		{
			m_Direction			= vector2d (DIRECTION::DIRECTION_RIGHT, DIRECTION::DIRECTION_NONE);
			m_Velocity.x		= MOVESPEED * m_Direction.x;

			if (device->KeyPress(DIK_Z))
			{
				if (m_TimeState > TIME_FOR_SHOOT)
				{
					m_State		= PLAYERSTATES::STATE_JUMP;
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
		if (device->KeyPress(DIK_Z))
		{
				CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::NORMAL, m_Position, vector2d(MOVESPEED * m_Direction.x, GRAVITY));
		}

		else if (device->KeyDown(DIK_RIGHT))
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
			CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::NORMAL, m_Position, vector2d(MOVESPEED * SIGN(m_Direction.x), GRAVITY));
			m_TimeState			= 0;
			m_State				= PLAYERSTATES::STATE_JUMP_SHOOT;
		}
		else if (device->KeyPress(DIK_Z))
		{
			CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::NORMAL, m_Position, vector2d(MOVESPEED * SIGN(m_Direction.x), GRAVITY));
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
					CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::NORMAL, m_Position, vector2d(MOVESPEED * SIGN(m_Direction.x), GRAVITY));
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
				CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::NORMAL, m_Position, vector2d(MOVESPEED * SIGN(m_Direction.x), GRAVITY));
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
		else if (device->KeyPress(DIK_Z))
		{
			if (m_TimeState > TIME_FOR_SHOOT)
			{
				m_State = PLAYERSTATES::STATE_CLIMB;
			}
			else
			{
				CBulletManager::getInstance()->ShowBullet(TYPE_BULLET::NORMAL, m_Position, vector2d(MOVESPEED * SIGN(m_Direction.x), GRAVITY));
				m_TimeState = 0;
			}
		}
		else
		{
			if (m_TimeState > TIME_FOR_SHOOT / 2)
			{
				m_State			= PLAYERSTATES::STATE_CLIMB;
				m_TimeState		= 0;
			}
		}

		break;
	default:
		break;
	}

}


void CPlayer::updateEntity(CBaseEntity* entity)
{
	if (onSensor(entity->getPosition(), vector2d(5, 5), this->m_Position))
	{
		if (entity->getTagNode() == "Stair")
		{
			this->m_isColisWithStair = true;
			return;
		}
		this->m_isColisWithStair			= false;
	}
	if (entity->getTagNode()	== "Collision")
	{
		if (CCollision::CheckCollision(this, entity) == COLDIRECTION::COLDIRECTION_LEFT)
		{
			if ((!haveEventInList(m_listCollitionEvent, COLDIRECTION::COLDIRECTION_LEFT)))
				m_listCollitionEvent.push_back(new CollisionEvents(COLDIRECTION::COLDIRECTION_LEFT, entity));
		}

		else if (CCollision::CheckCollision(this, entity) == COLDIRECTION::COLDIRECTION_RIGHT)
		{
			if ((!haveEventInList(m_listCollitionEvent, COLDIRECTION::COLDIRECTION_RIGHT)))
				m_listCollitionEvent.push_back(new CollisionEvents(COLDIRECTION::COLDIRECTION_RIGHT, entity));
		}

		else if (CCollision::CheckCollision(this, entity) == COLDIRECTION::COLDIRECTION_TOP)
		{
			if ((!haveEventInList(m_listCollitionEvent, COLDIRECTION::COLDIRECTION_TOP)))
				m_listCollitionEvent.push_back(new CollisionEvents(COLDIRECTION::COLDIRECTION_TOP, entity));
		}

		else if (CCollision::CheckCollision(this, entity) == COLDIRECTION::COLDIRECTION_BOTTOM)
		{
			if ((!haveEventInList(m_listCollitionEvent, COLDIRECTION::COLDIRECTION_BOTTOM)))
				m_listCollitionEvent.push_back(new CollisionEvents(COLDIRECTION::COLDIRECTION_BOTTOM, entity));
		}
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

	
	CText::getInstace()->Draw(_itow(m_Position.x, new WCHAR[1], 10), vector3d(150, 50, 0.5), DEFAULT_FONT_COLOR, 12);
	CText::getInstace()->Draw(_itow(m_Position.y, new WCHAR[1], 10), vector3d(200, 50, 0.5), DEFAULT_FONT_COLOR, 12);
}

vector3d CPlayer::getPosition()
{
	return m_Position;
}

inline bool haveEventInList(vector<CollisionEvents*> listEvent, int styleEventCollision)
{
	for (int i = 0; i < listEvent.size(); ++i)
	{
		if (listEvent.at(i)->m_CollisionDirection == styleEventCollision)
			return true;
	}
	return false;
}

CBox2D		CPlayer::getBounding()
{
	if (m_listSprite.size())
	{
		m_Bounding->setX(m_Position.x - this->m_listSprite.at(m_State)->getFrameInfo().Width / 2 * std::abs(m_listSprite.at(m_State)->getScale().x) + 2);
		m_Bounding->setY(m_Position.y + this->m_listSprite.at(m_State)->getFrameInfo().Height / 2 * std::abs(m_listSprite.at(m_State)->getScale().y));
		m_Bounding->setWidth(m_listSprite.at(m_State)->getFrameInfo().Width					 	 * std::abs(m_listSprite.at(m_State)->getScale().x) - 2);
		m_Bounding->setHeight(m_listSprite.at(m_State)->getFrameInfo().Height					 * std::abs(m_listSprite.at(m_State)->getScale().y));
	}

	return *m_Bounding;
}

//  check pos2 onto pos1 with sensor
inline bool	onSensor(vector3d pos1, vector2d sensorOfPos1, vector3d pos2)
{
	if ((pos2.x > pos1.x - sensorOfPos1.x)	&&
		(pos2.x < pos1.x + sensorOfPos1.x)	&&
		(pos2.y > pos1.y - sensorOfPos1.y)	&&
		(pos2.y < pos1.y + sensorOfPos1.y))
		return true;
	return false;
}