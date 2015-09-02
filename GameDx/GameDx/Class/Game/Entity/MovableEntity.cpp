#include "MovableEntity.h"


CMovable::CMovable()
{
	this->initEntity();
}


CMovable::~CMovable()
{
}

bool CMovable::initEntity()
{
	m_TagNode = "Movable";
	return true;
}

vector3d	CMovable::getPosition()
{
	return m_Position;
}

void	CMovable::setPosition(vector3d pos)
{
	m_Position		= pos;
}

CBox2D		CMovable::getBounding()
{
	if (m_listSprite.size())
	{
		m_Bounding->setX		(m_Position.x - this->m_listSprite.at(m_State)->getFrameInfo().Width / 2					 * std::abs(m_listSprite.at(m_State)->getScale().x));
		m_Bounding->setY		(m_Position.y + this->m_listSprite.at(m_State)->getFrameInfo().Height / 2 * std::abs(m_listSprite.at(m_State)->getScale().y));
		m_Bounding->setWidth	(m_listSprite.at(m_State)->getFrameInfo().Width					 	 * std::abs(m_listSprite.at(m_State)->getScale().x));
		m_Bounding->setHeight	(m_listSprite.at(m_State)->getFrameInfo().Height					 * std::abs(m_listSprite.at(m_State)->getScale().y));
	}

	return *m_Bounding;
}

vector2d CMovable::getVelocity()
{
	return m_Velocity;
}

char* CMovable::getTagNode()
{
	return this->m_TagNode;
}

void	CMovable::setTagNode(char* tag)
{
	m_TagNode		= tag;
}

int CMovable::getState()
{
	return m_State;
}

void	CMovable::setState(int newState)
{
	m_State			= newState;
}

void	CMovable::setVelocity(vector2d newVel)
{
	m_Velocity = newVel;
}

vector<CollisionEvents*> CMovable::getListCollisionEvents()
{
	return m_listCollitionEvent;
}