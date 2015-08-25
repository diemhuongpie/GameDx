#include "Game\Utill\InformationResource.h"
#include "Config.h"
#include <fstream>

/************RESOURCE FOR PLAYER************/
vector <const wchar_t*> CInfomationResource::InitRockManNormalResource()
{
	m_linkResourceRockManList.clear();
	m_linkResourceRockManList.push_back(L"Resource//Image//Game//Sprites//RockMan//RockManNormal//rockman_start.png");
	m_linkResourceRockManList.push_back(L"Resource//Image//Game//Sprites//RockMan//RockManNormal//rockman_stand.png");
	m_linkResourceRockManList.push_back(L"Resource//Image//Game//Sprites//RockMan//RockManNormal//rockman_stand_fire.png");
	m_linkResourceRockManList.push_back(L"Resource//Image//Game//Sprites//RockMan//RockManNormal//rockman_run.png");
	m_linkResourceRockManList.push_back(L"Resource//Image//Game//Sprites//RockMan//RockManNormal//rockman_run_fire.png");
	m_linkResourceRockManList.push_back(L"Resource//Image//Game//Sprites//RockMan//RockManNormal//rockman_jump.png");
	m_linkResourceRockManList.push_back(L"Resource//Image//Game//Sprites//RockMan//RockManNormal//rockman_jump_fire.png");
	m_linkResourceRockManList.push_back(L"Resource//Image//Game//Sprites//RockMan//RockManNormal//rockman_stair.png");
	m_linkResourceRockManList.push_back(L"Resource//Image//Game//Sprites//RockMan//RockManNormal//rockman_stair_fire.png");
	m_linkResourceRockManList.push_back(L"Resource//Image//Game//Sprites//RockMan//RockManNormal//rockman_stair_end.png");
	m_linkResourceRockManList.push_back(L"Resource//Image//Game//Sprites//RockMan//RockManNormal//rockman_collide.png");
	m_linkResourceRockManList.push_back(L"Resource//Image//Game//Sprites//RockMan//RockManNormal//rockman_die.png");

	return m_linkResourceRockManList;
	/*rockmanHit					= L"Resource//Image//Game//Sprites//RockMan//RockManNormal//rockman_collide.png";
	rockmanDie					= L"Resource//Image//Game//Sprites//RockMan//RockManNormal//rockman_die.png";
	rockmanJump					= L"Resource//Image//Game//Sprites//RockMan//RockManNormal//rockman_jump.png";
	rockmanJumpShoot			= L"Resource//Image//Game//Sprites//RockMan//RockManNormal//rockman_jump_fire.png";
	rockmanRun					= L"Resource//Image//Game//Sprites//RockMan//RockManNormal//rockman_run.png";
	rockmanRunShoot				= L"Resource//Image//Game//Sprites//RockMan//RockManNormal//rockman_run_fire.png";
	rockmanClimb				= L"Resource//Image//Game//Sprites//RockMan//RockManNormal//rockman_stair.png";
	rockmanClimbEnd				= L"Resource//Image//Game//Sprites//RockMan//RockManNormal//rockman_stair_end.png";
	rockmanClimbShoot			= L"Resource//Image//Game//Sprites//RockMan//RockManNormal//rockman_stair_fire.png";
	rockmanStand				= L"Resource//Image//Game//Sprites//RockMan//RockManNormal//rockman_stand.png";
	rockmanStandShoot			= L"Resource//Image//Game//Sprites//RockMan//RockManNormal//rockman_stand_fire.png";
	rockmanStart				= L"Resource//Image//Game//Sprites//RockMan//RockManNormal//rockman_start.png";*/

}

vector<const wchar_t*> CInfomationResource::InitRockManCutResource()
{
	m_linkResourceRockManList.clear();
	m_linkResourceRockManList.push_back(L"Resource//Image//Game//Sprites//RockMan//RockManCut//rockman_cut_start.png");
	m_linkResourceRockManList.push_back(L"Resource//Image//Game//Sprites//RockMan//RockManCut//rockman_cut_stand.png");
	m_linkResourceRockManList.push_back(L"Resource//Image//Game//Sprites//RockMan//RockManCut//rockman_cut_fire_stand.png");
	m_linkResourceRockManList.push_back(L"Resource//Image//Game//Sprites//RockMan//RockManCut//rockman_cut_run.png");
	m_linkResourceRockManList.push_back(L"Resource//Image//Game//Sprites//RockMan//RockManCut//rockman_cut_run_fire.png");
	m_linkResourceRockManList.push_back(L"Resource//Image//Game//Sprites//RockMan//RockManCut//rockman_cut_jump.png");
	m_linkResourceRockManList.push_back(L"Resource//Image//Game//Sprites//RockMan//RockManCut//rockman_cut_jump_fire.png");
	m_linkResourceRockManList.push_back(L"Resource//Image//Game//Sprites//RockMan//RockManCut//rockman_cut_stair.png");
	m_linkResourceRockManList.push_back(L"Resource//Image//Game//Sprites//RockMan//RockManCut//rockman_cut_stair_fire.png");
	m_linkResourceRockManList.push_back(L"Resource//Image//Game//Sprites//RockMan//RockManCut//rockman_cut_stair_end.png");
	m_linkResourceRockManList.push_back(L"Resource//Image//Game//Sprites//RockMan//RockManCut//rockman_cut_collide.png");
	m_linkResourceRockManList.push_back(L"Resource//Image//Game//Sprites//RockMan//RockManCut//rockman_cut_die.png");

	return m_linkResourceRockManList;
}

vector<const wchar_t*> CInfomationResource::InitRockManBombResource()
{
	m_linkResourceRockManList.clear();
	m_linkResourceRockManList.push_back(L"Resource//Image//Game//Sprites//RockMan//RockManBoom//rockman_boom_start.png");
	m_linkResourceRockManList.push_back(L"Resource//Image//Game//Sprites//RockMan//RockManBoom//rockman_boom_stand.png");
	m_linkResourceRockManList.push_back(L"Resource//Image//Game//Sprites//RockMan//RockManBoom//rockman_boom_firestand.png");
	m_linkResourceRockManList.push_back(L"Resource//Image//Game//Sprites//RockMan//RockManBoom//rockman_boom_run.png");
	m_linkResourceRockManList.push_back(L"Resource//Image//Game//Sprites//RockMan//RockManBoom//rockman_boom_run_fire.png");
	m_linkResourceRockManList.push_back(L"Resource//Image//Game//Sprites//RockMan//RockManBoom//rockman_boom_jump.png");
	m_linkResourceRockManList.push_back(L"Resource//Image//Game//Sprites//RockMan//RockManBoom//rockman_boom_jump_fire.png");
	m_linkResourceRockManList.push_back(L"Resource//Image//Game//Sprites//RockMan//RockManBoom//rockman_boom_stair.png");
	m_linkResourceRockManList.push_back(L"Resource//Image//Game//Sprites//RockMan//RockManBoom//rockman_boom_stair_fire.png");
	m_linkResourceRockManList.push_back(L"Resource//Image//Game//Sprites//RockMan//RockManBoom//rockman_boom_stair_end.png");
	m_linkResourceRockManList.push_back(L"Resource//Image//Game//Sprites//RockMan//RockManBoom//rockman_boom_collide.png");
	m_linkResourceRockManList.push_back(L"Resource//Image//Game//Sprites//RockMan//RockManBoom//rockman_boom_die.png");

	return m_linkResourceRockManList;
}


/*******************************************/

/************BULLET RESOURCE*****************/
const wchar_t*		CInfomationResource::rockmanBullet				= L"Resource//Image//Game//Sprites//RockMan//Bullet//bullet_rockman.png";

/************RESOURCE FOR SELECTSTAGE*******/
const wchar_t*		CInfomationResource::backgroundSeletStage		= L"Resource//Image//SelectStage//selectStage.png";
const wchar_t*		CInfomationResource::buttonMenuState			= L"Resource//Image//SelectStage//button_menu_state.png";
/******************************************/

/************RESOURCE FOR MENU*******/
const wchar_t*		CInfomationResource::backgroundMenu				= L"Resource//Image//SceneMenu//background.png";
const wchar_t*		CInfomationResource::megaManBackground			= L"Resource//Image//SceneMenu//backgroundRockMan.png";
const wchar_t*		CInfomationResource::rulerBackground			= L"Resource//Image//SceneMenu//bar.png";
/*************************************************/

/************RESOURCE FOR INTROSCENE*******/
const wchar_t*		CInfomationResource::spriteCutManIntro			= L"Resource//Image//IntroScene//cutManIntro.png";
const wchar_t*		CInfomationResource::spriteBombManIntro			= L"Resource//Image//IntroScene//bombManIntro.png";
const wchar_t*		CInfomationResource::spriteBombManBallIntro		= L"Resource//Image//IntroScene//bombManBallIntro.png";
const wchar_t*		CInfomationResource::backgroundIntroStage		= L"Resource//Image//Background//background_3.png";
/*************************************************/

/************RESOURCE FOR POPUPSCENE*******/
const wchar_t*	CInfomationResource::popUp							= L"Resource//Image//PopupScene//popup.png";
const wchar_t*	CInfomationResource::itemLife						= L"Resource//Image//PopupScene//Item_life.png";
const wchar_t*	CInfomationResource::rockManCutSkill				= L"Resource//Image//PopupScene//bar_mana_cutman.png";
const wchar_t*	CInfomationResource::rockManBombSkill				= L"Resource//Image//PopupScene//bar_mana_boomman.png";
/*************************************************/
