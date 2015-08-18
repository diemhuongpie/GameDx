#ifndef __MAP_INFOR_H__
#define __MAP_INFOR_H__

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

	void					readMapInfor(wchar_t*);
	void					readTileMap(wchar_t*);
	CBox2D					getSize();
		
	void					init();
	void					update(float deltaTime);
	void					render();

protected:
	vector<CTile*>			m_listTile;
	vector<CBox2D*>			m_listBox;
	vector<CBaseEntity*>	m_listEntity;

};

#endif