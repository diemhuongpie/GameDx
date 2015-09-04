#ifndef __MAP_INFOR_H__
#define __MAP_INFOR_H__

#include "Game\Utill\Config.h"
#include "Mathematics\Box2D.h"
#include "Game\Utill\stdafx.h"
#include "Game\Utill\Config.h"
#include "Game\Entity\Tile\Tile.h"
#include "Game\Entity\BaseEntity.h"
#include "Game\Entity\MovableEntity.h"

#include "Game\Entity\Enemy\EnemyBubbleBlue.h"
#include "Game\Entity\Enemy\BossBombMan.h"
#include "Game\Entity\Enemy\BossCutMan.h"
#include "Game\Entity\Enemy\BossFireMan.h"
#include "Game\Entity\Enemy\EnemyBall.h"
#include "Game\Entity\Enemy\EnemyBoomBlue.h"
#include "Game\Entity\Enemy\EnemyCut.h"
#include "Game\Entity\Enemy\EnemyEyeRed.h"
#include "Game\Entity\Enemy\EnemyFishOrange.h"
#include "Game\Entity\Enemy\EnemyInkBlue.h"
#include "Game\Entity\Enemy\EnemyMachineAutoOrange.h"
#include "Game\Entity\Enemy\EnemyNinja.h"
#include "Game\Entity\Enemy\EnemyPartBoomBlue.h"
#include "Game\Entity\Enemy\EnemyMachineOrange.h"
#include "Game\Entity\Enemy\EnemyRobotRed.h"
#include "Game\Entity\Enemy\EnemyTankRed.h"

#include "Game\Algorithsm\QuadTree.h"



class MapData
{
public:
	MapData();
	~MapData();

	void					readMapInfor(wstring);
	void					readTileMap(wstring);
	CBox2D					getSize();
		
	void					update(float deltaTime, CMovable* entity);
	void					render();

protected:
	vector<CBaseEntity*>			m_listTile;
	vector<CBaseEntity*>			m_listCollisionTile;
	vector<CBaseEntity*>			m_listEntity;

};

#endif