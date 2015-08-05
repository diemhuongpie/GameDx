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
	// LOGIC INIT
	m_Position = vector3d(100, 300, 0.5);
	m_State = PLAYSTATE::START;

	// LOAD SPRITE
	this->loadSprite();

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

	//m_Position.x += m_Velocity.x*deltaTime;
	//m_Position.y += m_Velocity.y*deltaTime;


	///* LOGIC FOR TIME*/
	//if (!m_isSTART)
	//{
	//	controlPlayer(device, deltaTime);
	//}
	//else
	//{
	//	m_Position.y -= 5;
	//	if (m_Position.y <= 103)
	//	{
	//		m_isSTART = false;
	//	}
	//}

	//if (m_Position.x >= 200 && m_Position.x <= 300 && m_Position.y >= 120)
	//{
	//	m_isCOL = true;
	//}
	//else
	//	m_isCOL = false;

}

void CPlayer::updateEntity(CKeyBoard* device)
{

}

void CPlayer::drawEntity()
{
	if (m_isSTART)
	{
		this->m_listSprite[m_State]->Render(CCamera::setPositionEntity(m_Position), vector2d(-1.0f, 1.0f), 0.0f, DRAWCENTER_MIDDLE_MIDDLE, false, 5);
	}
	else
	{
		
		if (m_isLEFT)
		{
			if (m_isCLIMB)
			{
				this->m_listSprite[m_State]->Render(0, 0, CCamera::setPositionEntity(m_Position), vector2d(-1.0, 1.0), 0.0f, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
			}
			else
				this->m_listSprite[m_State]->Render(CCamera::setPositionEntity(m_Position), vector2d(-1.0f, 1.0f), 0.0f, DRAWCENTER_MIDDLE_MIDDLE, true, 5);
		}
		else
		{
			if (m_isCLIMB)
			{
				this->m_listSprite[m_State]->Render(0, 0, CCamera::setPositionEntity(m_Position), vector2d(1.0, 1.0), 0.0f, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
			}
			else
				this->m_listSprite[m_State]->Render(CCamera::setPositionEntity(m_Position), vector2d(1.0f, 1.0f), 0.0f, DRAWCENTER_MIDDLE_MIDDLE, true, 5);
		}
			
	}
}

void CPlayer::controlPlayer(CKeyBoard *device, float deltaTime)
{
	if (device->KeyDown(DIK_A) && !m_isJUMP)
	{
		m_State = PLAYSTATE::JUMP_SHOOT; // shot when you jumping
	}
	else if (m_isCOL)
	{
		if (device->KeyDown(DIK_RIGHT))
			m_isLEFT = false;
		if (device->KeyDown(DIK_LEFT))
			m_isLEFT = true;

		if (device->KeyDown(DIK_UP))
		{
			m_isCLIMB = false;
			m_State = PLAYSTATE::CLIMB;
			m_Velocity.y = 1;
		}
		else if (device->KeyDown(DIK_DOWN))
		{
			m_isCLIMB = false;
			m_State = PLAYSTATE::CLIMB;
			m_Velocity.y = -1;
		}
		else if (device->KeyDown(DIK_A))
		{
			m_isCLIMB = false;
			m_State = PLAYSTATE::CLIMB_SHOOT; // shot when you climbing
		}
		else
		{
			m_Velocity.y = 0;
			m_isCLIMB = true;
			m_State = PLAYSTATE::CLIMB;
		}
		m_Velocity.x = 0;
	}
	else
	{
		//gravity
		if (m_Position.y <= 100 && !m_isCOL)
		{
			m_isJUMP = true;
			m_Velocity.y = 0;
			m_Position.y = 100;
		}
		else
			this->m_Velocity.y--;
		//jump
		if (device->KeyPress(DIK_SPACE) && m_isJUMP)
		{
			m_State = PLAYSTATE::JUMP;
			m_isJUMP = false;
			m_Velocity.y = VEL_PLAYER_Y;
			if (m_Velocity.y > 25)
			{
				m_Velocity.y = 25;
			}
		}

		if (device->KeyDown(DIK_RIGHT))
		{
			if (device->KeyDown(DIK_A))
			{
				m_State = PLAYSTATE::RUN_SHOOT;
			}
			else
			{
				if (m_isJUMP)
					m_State = PLAYSTATE::RUN;
			}
			this->m_Velocity.x = VEL_PLAYER_X;

			m_isLEFT = false;
		}
		else if (device->KeyDown(DIK_LEFT))
		{

			if (device->KeyDown(DIK_A))
			{
				m_State = PLAYSTATE::RUN_SHOOT;
			}
			else
			{
				if (m_isJUMP)
					m_State = PLAYSTATE::RUN;
			}
			this->m_Velocity.x = -VEL_PLAYER_X;
			m_isLEFT = true;
		}
		else
		{
			if (device->KeyDown(DIK_A))
			{
				m_State = PLAYSTATE::STAND_SHOOT;
			}
			else
			{
				if (m_isJUMP)
					m_State = PLAYSTATE::STAND;
			}

			if (m_Velocity.x != 0)
			{
				m_Velocity += m_Acceleration*deltaTime;
				if (m_isLEFT)
				{
					this->m_Acceleration.x = ACCEL_PLAYER_X;
					if (m_Velocity.x <= 1 && m_Velocity.x >= 0)
					{
						m_Velocity.x = 0;
						this->m_Acceleration.x = 0;
					}

				}
				else
				{
					this->m_Acceleration.x = -ACCEL_PLAYER_X;
					if (m_Velocity.x >= -1 && m_Velocity.x <= 0)
					{
						m_Velocity.x = 0;
						this->m_Acceleration.x = 0;
					}
				}
			}

		}
	}


}
