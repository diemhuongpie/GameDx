#include "Collision.h"


CCollision::CCollision()
{
}


CCollision::~CCollision()
{
}

COLDIRECTION CCollision::CheckCollision(CMovable* MovableObject, CBaseEntity* Object)
{
	float moveX, moveY;
	float mormalX, mormalY;
	float timeCollision;
	vector2d velocity;
	CMovable* Object;

	if (AABB(*(MovableObject->m_Bounding),*(Object->m_Bounding), moveX, moveY))
	{
		if (moveX != 0)
		{
			if (moveX < 0.0f)
				return COLDIRECTION::COLDIRECTION_LEFT;
			else
			return COLDIRECTION::COLDIRECTION_RIGHT;
		}
		else
		if (moveY != 0)
		{
			if (moveY < 0.0f)
				return COLDIRECTION::COLDIRECTION_BOTTOM;
			else
				return COLDIRECTION::COLDIRECTION_TOP;
		}
		else
		{
		}
	}
	else
	{
		if (Object->m_Velocity != vector2dZero)
		{
			
			velocity = vector2d(MovableObject->m_Velocity.x - Object->m_Velocity.x, MovableObject->m_Velocity.y - Object->m_Velocity.y);
		}
		else
			velocity = MovableObject->m_Velocity;

	}
}