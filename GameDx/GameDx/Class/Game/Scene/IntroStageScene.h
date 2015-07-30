#ifndef __INTROSTAGESCENE_H__
#define __INTROSTAGESCENE_H__

#include "BaseScene.h"
#include "Framework\Sprite.h"
#include "Framework\Text.h"
#include "Game\Utill\InformationResource.h"
class CIntroStageScene :
	public CBaseScene
{
public:
	CIntroStageScene();
	~CIntroStageScene();

	virtual bool initScene()						override;
	virtual void updateScene()						override;
	virtual void updateScene(CKeyBoard*)			override;
	virtual void renderScene()						override;

private:
	CSprite*		m_Background;
	CSprite*		m_Sprite;
	vector3d		m_Position;
	int				m_direct;
};

#endif