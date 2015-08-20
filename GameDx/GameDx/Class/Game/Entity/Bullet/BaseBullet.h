#ifndef __BASEBULLET_H__
#define __BASEBULLET_H__
#include "Game\Entity\MovableEntity.h"

class CBaseBullet : public CMovable
{
public:
	CBaseBullet(){};
	~CBaseBullet(){};
	int type_Angle;
	void		logicCollision(CBaseEntity* entity) {};

};
#endif