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

	MovableObject	->m_Bounding = new CBox2D(MovableObject->getBounding());
	Object			->m_Bounding = new CBox2D(Object->getBounding());

	if (AABB(*(MovableObject->m_Bounding), *(Object->m_Bounding), moveX, moveY))
	{
		if (moveY != 0)
			if (moveY >= 0)
				return COLDIRECTION::COLDIRECTION_TOP;
			else
				return COLDIRECTION::COLDIRECTION_BOTTOM;
		else 
			if (moveX != 0)
				if (moveX < 0)
					return COLDIRECTION::COLDIRECTION_LEFT;
				else
					return COLDIRECTION::COLDIRECTION_RIGHT;
			else
			{
				// already changing axis Oy into dacac
				if (MovableObject->m_Bounding->getY() == Object->m_Bounding->getY() + Object->m_Bounding->getHeight())
					return COLDIRECTION::COLDIRECTION_TOP;
				else if (MovableObject->m_Bounding->getY() + MovableObject->m_Bounding->getHeight() == Object->m_Bounding->getY())
						return COLDIRECTION::COLDIRECTION_BOTTOM;
					else if (MovableObject->m_Bounding->getX() == Object->m_Bounding->getX() + Object->m_Bounding->getWidth())
							return COLDIRECTION::COLDIRECTION_LEFT;
						else if (MovableObject->m_Bounding->getX() + MovableObject->m_Bounding->getWidth() == Object->m_Bounding->getX())
								return COLDIRECTION::COLDIRECTION_RIGHT;
			}
	}
	else
	{
		if (Object->m_isMovable == false)
			velocity = MovableObject->getVelocity();
		else
		{
			object = (CMovable*)Object;
			velocity = vector2d(MovableObject->getVelocity().x - object->getVelocity().x, MovableObject->getVelocity().y - object->getVelocity().y);
		}

		if (AABB(GetBroadPhaseBox(*(MovableObject->m_Bounding), velocity), *(Object->m_Bounding), moveX, moveY))
		{
			timeCollition = SweptAABB(GetBoundForMovable(*(MovableObject->m_Bounding), velocity), *(Object->m_Bounding), normalX, normalY);
			
			if (timeCollition > 0.0f && timeCollition < 1.0f)
			{
				if (normalX != 0)
				{
					if (moveX != 0)
						if(normalX == -1.0f)
							return COLDIRECTION::COLDIRECTION_LEFT;
						else if (normalX == 1.0f)
							return COLDIRECTION::COLDIRECTION_RIGHT;
				}
				else
				{
					if (moveY != 0)
						if(normalY == -1.0f)
							return COLDIRECTION::COLDIRECTION_BOTTOM;
						else if (normalY == 1.0f)
							return COLDIRECTION::COLDIRECTION_TOP;
				}
				
			}

		}
	}
	return COLDIRECTION::COLDIRECTION_NONE;
}