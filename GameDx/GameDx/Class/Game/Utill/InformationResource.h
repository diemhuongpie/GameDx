

#ifndef __INFOMATIONRESOURCE_H__
#define __INFOMATIONRESOURCE_H__

#include "stdafx.h"
#include "Framework\Sprite.h"
#include "Game\Algorithsm\Singleton.h"

class CInfomationResource : public CSingleton<CInfomationResource>
{
public:
	/************RESOURCE FOR PLAYER************/
	vector<const wchar_t*>	InitRockManNormalResource();
	vector<const wchar_t*>	InitRockManCutResource();
	vector<const wchar_t*>	InitRockManBombResource();

	vector<const wchar_t*>	m_linkResourceRockManList;
	/*************************************************/

	/************RESOURCE FOR BOSS******************/
	vector<const wchar_t*>	InitBoomManResource();
	vector<const wchar_t*>	m_linkResourceBombManList;
	/*************************************************/

	/************BULLET RESOURCE**********************/
	static const wchar_t*	rockmanBullet;
	static const wchar_t*	bombmanBullet;
	static const wchar_t*	effectBumBomSkill;
	/*************************************************/

	/************RESOURCE FOR MANA******************/
	static const wchar_t*	manaBar;
	static const wchar_t*	manaNormal;
	static const wchar_t*	manaCut;
	static const wchar_t*	manaBomb;
	static const wchar_t*	manaFire;
	/*************************************************/

	/************RESOURCE FOR SELECTSTAGE*******/
	static const wchar_t*	backgroundSeletStage;
	static const wchar_t*	buttonMenuState;
	/*************************************************/

	/************RESOURCE FOR MENU*******/
	static const wchar_t*	backgroundMenu;
	static const wchar_t*	megaManBackground;
	static const wchar_t*	rulerBackground;
	/*************************************************/

	/************RESOURCE FOR INTROSCENE*******/
	static const wchar_t*	spriteCutManIntro;
	static const wchar_t*	spriteBombManIntro;
	static const wchar_t*	spriteBombManBallIntro;
	static const wchar_t*	backgroundIntroStage;
	/*************************************************/

	/************RESOURCE FOR POPUPSCENE*******/
	static const wchar_t*	popUp;
	static const wchar_t*	itemLife;
	static const wchar_t*	rockManCutSkill;
	static const wchar_t*	rockManBombSkill;
	/*************************************************/
};

#endif