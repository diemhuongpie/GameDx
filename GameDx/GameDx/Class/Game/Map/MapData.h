#ifndef __MAP_INFOR_H__
#define __MAP_INFOR_H__

#include "Game\Utill\Config.h"
#include "Mathematics\Box2D.h"
#include "Game\Utill\stdafx.h"
#include "Game\Utill\Config.h"
#include "Game\Entity\Tile\Tile.h"
#include "Game\Entity\BaseEntity.h"

class MapData
{
public:
	MapData();
	~MapData();

	void					readMapInfor(wstring);
	void					readTileMap(wstring);
	CBox2D					getSize();
		
	void					update(float deltaTime);
	void					render();

protected:
	vector<CTile*>			m_listTile;
	vector<CTile*>			m_listCollisionTile;
	vector<CBaseEntity*>	m_listEntity;

};

#endif