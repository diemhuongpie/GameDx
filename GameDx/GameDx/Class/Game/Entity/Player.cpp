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
	m_Position = vector3d(100, 100, 0.5);
	m_State = PLAYERSTATE::PLAYER_STAND;

	// LOAD SPRITE
	this->loadSprite();

	return true;
}

bool CPlayer::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanStand, 1, 2, 2, 0));
	return true;
}

void CPlayer::updateEntity(float deltaTime)
{
	deltaTime = static_cast<float>(CTimer::getInstance()->getElapedTime());
	/* LOGIC FOR TIME*/

}

void CPlayer::updateEntity(CKeyBoard device)
{


}

void CPlayer::updateEntity(RECT rectCamera)
{
}

void CPlayer::drawEntity()
{
	this->m_listSprite[m_State]->Render(m_Position);
}
