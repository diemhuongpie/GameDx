#pragma once
#include "BaseScene.h"
class CPlayScene :
	public CBaseScene
{
public:
	CPlayScene();
	~CPlayScene();


	virtual bool initScene()						override;
	virtual void updateScene(CKeyBoard*)			override;
	virtual void updateScene(double deltaTime)		override;
	virtual void renderScene()						override;
};

