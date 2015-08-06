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
	vector2d velocity;
	CMovable* object;
	double timeCollition;
	float normalX, normalY;


	if (AABB(*(MovableObject->m_Bounding), *(Object->m_Bounding), moveX, moveY))
	{
		if (moveX == 0)
			if (moveY >= 0)
				return COLDIRECTION::COLDIRECTION_TOP;
			else
				return COLDIRECTION::COLDIRECTION_BOTTOM;
		
		else
		if (moveX > 0)
			return COLDIRECTION::COLDIRECTION_LEFT;
		else
			return COLDIRECTION::COLDIRECTION_RIGHT;
		
	}
	else
	{
		if (Object->m_Velocity == vector2dZero)
			velocity = MovableObject->m_Velocity;
		else
		{
			object = (CMovable*)Object;
			velocity = vector2d(MovableObject->m_Velocity.x - object->m_Velocity.x, MovableObject->m_Velocity.y - object->m_Velocity.y);
		}

		if (AABB(*(CBox2D::getBroadPhaseBox(MovableObject->m_Bounding, velocity)), *(Object->m_Bounding), moveX, moveY))
		{
			timeCollition = SweptAABB(*(MovableObject->m_Bounding), *(Object->m_Bounding), normalX, normalY);
			
			if (timeCollition > 0.0f && timeCollition < 1.0f)
			{
				if (normalX != 0)
					if (moveX != 0)
						if(normalX == -1)
							return COLDIRECTION::COLDIRECTION_LEFT;
						else
							return COLDIRECTION::COLDIRECTION_RIGHT;


				
			}

		}
	}
	return COLDIRECTION::COLDIRECTION_NONE;
}