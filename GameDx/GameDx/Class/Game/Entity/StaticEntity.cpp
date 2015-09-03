#include "StaticEntity.h"


CStaticEntity::CStaticEntity()
{
	this->initEntity();
}


CStaticEntity::~CStaticEntity()
{
}

bool CStaticEntity::initEntity()
{
	m_TagNode	= "Static";
	m_State		= 0;
	return true;
}

CBox2D		CStaticEntity::getBounding()
{
	if (m_listSprite.size())
	{
		m_Bounding->setX(m_Position.x - this->m_listSprite.at(m_State)->getFrameInfo().Width / 2  * std::abs(m_listSprite.at(m_State)->getScale().x));
		m_Bounding->setY(m_Position.y + this->m_listSprite.at(m_State)->getFrameInfo().Height / 2 * std::abs(m_listSprite.at(m_State)->getScale().y));
		m_Bounding->setWidth(m_listSprite.at(m_State)->getFrameInfo().Width					* std::abs(m_listSprite.at(m_State)->getScale().x));
		m_Bounding->setHeight(m_listSprite.at(m_State)->getFrameInfo().Height				* std::abs(m_listSprite.at(m_State)->getScale().y));
	}
	return *m_Bounding;
}

vector3d CStaticEntity::getPosition()
{
	return m_Position;
}

void	CStaticEntity::setPosition(vector3d vec)
{
	m_Position = vec;
}

char* CStaticEntity::getTagNode()
{
	return this->m_TagNode;
}

int CStaticEntity::getState()
{
	return m_State;
}

void		CStaticEntity::setState(int newState)
{
	m_State = newState;
}

void		CStaticEntity::setTagNode(char* tag)
{
	m_TagNode	= tag;
}

void		CStaticEntity::setSubHealthy(int health)
{};