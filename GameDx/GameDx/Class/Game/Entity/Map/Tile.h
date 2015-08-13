#ifndef __TILE_H__
#define __TILE_H__

#include "Game\Entity\StaticEntity.h"
#include "Framework\Camera.h"

class CTile : public CStaticEntity
{
public:
	CTile();
	CTile(vector3d, int);
	~CTile();

	virtual bool initEntity()						override;
	virtual void updateEntity(float deltaTime)		override;
	virtual void updateEntity(CKeyBoard device)		override;
	virtual void updateEntity(RECT rectCamera)		override;
	virtual void drawEntity()						override;
	virtual bool CTile::loadSprite()				override;
	// override function

	int m_Index;
	vector3d m_Pos;
	bool isDraw;
};

#endif