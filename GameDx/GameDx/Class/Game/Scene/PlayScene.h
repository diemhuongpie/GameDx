#pragma once
#include "BaseScene.h"
#include "Game\Entity\Player.h"
#include "Game\Entity\Enemy_ball.h"
#include "Game\Entity\Enemy_bubble_blue.h"
#include "Game\Entity\Enemy_robot_red.h"
#include "Game\Entity\Enemy_cut.h"

class CPlayScene :
	public CBaseScene
{
public:
	CPlayer *player;
	CEnemy_ball *e_ball;
	CEnemy_bubble_blue *e_bubble_blue;
	CEnemy_cut *e_cut;
	
	double time;
	CPlayScene();
	~CPlayScene();


	virtual bool initScene()						override;
	virtual void updateScene(CKeyBoard*)			override;
	virtual void updateScene(double deltaTime)		override;
	virtual void renderScene()						override;
};

