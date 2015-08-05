#ifndef __CCOLLOSION_H__
#define __CCOLLOSION_H__

#include "Game\Utill\Config.h"
#include "Box2D.h"
#include "Game\Entity\MovableEntity.h"
#include "Mathematics\SweptAABB.h"


class CCollision
{
public:
	CCollision();
	~CCollision();
	
	COLDIRECTION CheckCollision(CMovable* MovableObject, CBaseEntity* Object);
};

#endif
