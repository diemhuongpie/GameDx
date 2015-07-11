#ifndef __CMENUSCENE_H__
#define __CMENUSCENE_H__

#include "Framework\Sprite.h"
#include "Framework\Text.h"
#include "BaseScene.h"

class CMenuScene :
	public CBaseScene
{
public:
	CMenuScene();
	CMenuScene(LPDIRECT3DDEVICE9);
	~CMenuScene();

	virtual bool initScene(LPDIRECT3DDEVICE9)		override;
	virtual void updateScene()						override;
	virtual void renderScene()						override;

private:
	CSprite*		m_Background;
	CText*			m_Pencil24;
};

#endif
