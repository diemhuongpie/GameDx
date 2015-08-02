#ifndef __CMENUSCENE_H__
#define __CMENUSCENE_H__

#include "Framework\Sprite.h"
#include "Framework\Text.h"
#include "BaseScene.h"
#include "Framework\Windows.h"

class CMenuScene :
	public CBaseScene
{
public:
	CMenuScene();
	~CMenuScene();

	virtual bool initScene()						override;
	virtual void updateScene(CKeyBoard*)			override;
	virtual void updateScene()						override;
	virtual void renderScene()						override;

private:
	CSprite*		m_Background;
	CSprite*		m_MegaMan;
	CSprite*		m_RuleBackground;
	bool			m_enterTheGame;
};
#endif
