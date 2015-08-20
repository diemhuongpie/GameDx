#ifndef __TILE_H__
#define __TILE_H__

#include "Game\Utill\stdafx.h"
#include "Game\Utill\Config.h"
#include "Framework\Sprite.h"
#include "Framework\Camera.h"
#include "Mathematics\Box2D.h"
#include "Game\Entity\StaticEntity.h"

class CTile	: public CStaticEntity
{
public:
	CTile();
	CTile(CSprite* sprite, vector3d pos, CBox2D* bounding, int styleID);
	~CTile();

	virtual		void					updateEntity(float deltaTime)			override;
	virtual		void					drawEntity()							override;
	virtual		bool					loadSprite()							override;
	virtual		CBox2D					getBounding()							override;
	virtual		bool					initEntity()							override;
				
				int						getStyleID();
				void					setStyleID();

	virtual		void					resetObject()							override;


protected:
				// styleID's including CollisionTile, Enemy, Tile
				int						m_styleID;
};

#endif