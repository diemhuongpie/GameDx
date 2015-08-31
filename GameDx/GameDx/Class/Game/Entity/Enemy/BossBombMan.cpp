
#include "BossBombMan.h"
#include "Game\Utill\InformationResource.h"
#include "Game\Entity\Bullet\BulletManager.h"

CBossBombMan::CBossBombMan()
{
	this->initEntity();
}

CBossBombMan::~CBossBombMan()
{

}

bool		CBossBombMan::initEntity()
{
	m_Position			= vector3d(16, 150, 0.5);
	m_Velocity			= vector2d(0.1, 0.1);
	m_State				= BOSSSTATE::BOSS_STAND;

	this->m_Bounding	= new CBox2D(0, 0, 0, 0);

	this->loadSprite();

	return true;
}

bool		CBossBombMan::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(CInfomationResource::getInstance()->InitBoomManResource().at(BOSSSTATE::BOSS_STAND), 2, 2, 2, 0));
	this->m_listSprite.push_back(new CSprite(CInfomationResource::getInstance()->InitBoomManResource().at(BOSSSTATE::BOSS_JUMP_LOW), 2, 2, 2, 0));
	this->m_listSprite.push_back(new CSprite(CInfomationResource::getInstance()->InitBoomManResource().at(BOSSSTATE::BOSS_JUMP_HIGHT), 2, 2, 2, 0));
	this->m_listSprite.push_back(new CSprite(CInfomationResource::getInstance()->InitBoomManResource().at(BOSSSTATE::BOSS_SHOOT), 2, 2, 2, 0));

	return true;
}

void		CBossBombMan::drawEntity()
{
	m_listSprite.at(m_State)->Render(CCamera::setPositionEntity(m_Position), vector2d(SIGN(m_Velocity.x) * 1, 1), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
}

void		CBossBombMan::updateEntity(float deltaTime)
{

}

void		CBossBombMan::updateEntity(CBaseEntity* entity)
{

}

void		CBossBombMan::updateEntity(CKeyBoard* device)
{

}

vector3d	CBossBombMan::getPosition()
{
	return m_Position;
}

void		CBossBombMan::resetObject()
{


}