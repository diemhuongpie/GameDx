#include "Player.h"


CPlayer::CPlayer()
{

}


CPlayer::~CPlayer()
{
}

CPlayer::CPlayer(LPDIRECT3DDEVICE9)
{
}

bool CPlayer::initEntity()
{

	return true;
}

bool CPlayer::loadSprite()
{
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

}
