#ifndef __TILE_H__
#define __TILE_H__

#include "Game\Entity\StaticEntity.h"

class CTile : public CStaticEntity
{
public:
	CTile();
	CTile(vector3d, int);
	~CTile();

	virtual bool			initEntity() override;
	virtual void			updateEntity(float deltaTime) override;
	virtual void			updateEntity(CKeyBoard* deivce) override;
	virtual void			drawEntity() override;
	virtual	CBox2D			getBounding() override;
	virtual const char*		getTagNode() override;
	virtual bool CTile::loadSprite() override;
	// override function

	int m_State;
	vector3d m_Pos;
	// override function
};

#endif