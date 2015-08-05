#include "PlayScene.h"


CPlayScene::CPlayScene()
{
	player = new CPlayer();
	//e_cut = new CEnemy_cut(player->getPosition());
	//e_ball = new CEnemy_ball();
	//e_bubble_blue = new CEnemy_bubble_blue();
}


CPlayScene::~CPlayScene()
{
}

bool	CPlayScene::initScene()
{
	player->initEntity();
	//e_cut->initEntity();
	//e_ball->initEntity();
	//e_bubble_blue->initEntity();
	return true;
}

void	CPlayScene::updateScene(double deltaTime)
{
	deltaTime = static_cast<float>(CTimer::getInstance()->getElapedTime()) / 60;
	time = deltaTime;
}

void	CPlayScene::updateScene(CKeyBoard* keyboard)
{
	player->updateEntity(keyboard,time);
	//e_cut->updateEntity(keyboard,time);
	//e_ball->updateEntity(keyboard,time);
	//e_bubble_blue->updateEntity(keyboard, time);
	if (keyboard->KeyPress(DIK_P))
		return;
}

void	CPlayScene::renderScene()
{
	player->drawEntity();
	//e_cut->drawEntity();
	//e_ball->drawEntity();
	//e_bubble_blue->drawEntity();
}