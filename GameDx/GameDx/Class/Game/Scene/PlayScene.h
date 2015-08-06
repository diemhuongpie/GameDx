#ifndef __PLAYSCENE_H__
#define __PLAYSCENE_H__

#include "BaseScene.h"
#include "Game\Entity\Player\Player.h"
#include "Game\Entity\Enemy\EnemyBall.h"
#include "Game\Entity\Enemy\EnemyBubbleBlue.h"
#include "Game\Entity\Enemy\EnemyRobotRed.h"
#include "Game\Entity\Enemy\EnemyCut.h"

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

private:
			//CPlayer*								m_Player;
			CEnemyBall*								m_EnemyBall;
			CEnemyBubbleBlue*						m_EnemyBubbleBlue;
			CEnemyCut*								m_EnemyCut;
	
};

#endif
