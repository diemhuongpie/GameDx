/****************************************************************************/
/* Create by Michael Le*/
/* 07/07/2015 */
/***************************************************************************/

#ifndef __CONFIG_H__
#define __CONFIG_H__

#include "stdafx.h"
#include <tchar.h>
#include <string>
using namespace std;

class CBaseEntity;
/*DEFINE*/
#define FPS							80
#define GAME_RATE					(1000.0f/80.0f)
#define WINDOWS_NAME				L"Oishi"

#define GRAVITY						0.15
#define MOVESPEED					0.08
#define GRAVITYSTART				0.02

#define DRAWCENTER_LEFT_TOP			1					
#define DRAWCENTER_LEFT_MIDDLE		2			
#define DRAWCENTER_LEFT_BOTTOM		3					
#define DRAWCENTER_MIDDLE_TOP		4				
#define DRAWCENTER_MIDDLE_MIDDLE	5					
#define DRAWCENTER_MIDDLE_BOTTOM	6		
#define DRAWCENTER_RIGHT_TOP		7
#define DRAWCENTER_RIGHT_MIDDLE		8
#define DRAWCENTER_RIGHT_BOTTOM		9

#define KEYBOARD_BUFFER_SIZE		1024
#define ISKEYDOWN(keystatus)		(keystatus & 0x80)

#define directDevice				LPDIRECT3DDEVICE9

#define vector3d					D3DXVECTOR3
#define vector3dZero				D3DXVECTOR3(0.0f,0.0f,0.5f)
#define	vector3dMinimum				D3DXVECTOR3(-10000, -10000, 0.5f)
#define vector2d					D3DXVECTOR2
#define vector2dZero				D3DXVECTOR2(0.0f,0.0f)
#define vector4d					D3DXVECTOR4

#define CBoxZero					CBox2D(0, 0, 0, 0)			

#define matrix						D3DXMATRIX

#define PI							3.14

#define SIGN(A)						(A >= 0 ? 1 : -1)
#define DIRECT_COORDINATE(A)		{-(A)}
#define SAFE_RELEASE(A)				{if (A) {delete A; A = 0;}}
#define SETMAX(A,B)					{A > B ? B : A}	

#define BACKBUFFER_WIDTH			256
#define	BACKBUFFER_HEIGHT			224

#define DELTA_FIX_SIZE_RESOURCE		10
#define TIME_FOR_JUMB				650
#define TIME_FOR_SHOOT				1000

#define SCREEN_SIZE					CBox2D()
#define deltaBoundingBox			vector2d(5.0f, 5.0f)

#define DEFAULT_FONT_SIZE			8
#define DEFAULT_FONTNAME			_T("MegaMan 2")
#define DEFAULT_FONTPATH			_T("Resource//Font//megaman_2.ttf")
#define DEFAULT_FONT_COLOR			0xFFFFFFFF
#define DAFAULT_TEXT_COLOR_STAGE	0x9AFEFFFF

#define START_GAME_STRING			"PRESS START"
#define PRODUCTOR					"PROJECT GAME UIT"
#define TM							"TM"

#define SELECT_CUTMAN_STRING		"CUTMAN"
#define SELECT_GUTMAN_STRING		"GUTMAN"
#define	SELECT_ICEMAN_STRING		"ICEMAN"
#define	SELECT_BOMBMAN_STRING		"BOMBMAN"
#define	SELECT_FIREMAN_STRING		"FIREMAN"
#define	SELECT_ELECMAN				"ELECMAN"
#define SELECT_STAGE_STRING			"SELECT\nSTAGE"
#define PRESS_START_GAME_STRING		"PRESS\nSTART"

#define DEFAULT_POINT_STRING		L"0000"
#define CUTMAN_STAGE_INFO_STRING	L"CUTMAN\n\nCLEAR POINT"
#define BOMBMAN_STAGE_INFO_STRING	L"BOMBMAN\n\nCLEAR POINT"
#define FIREMAN_STAGE_INFO_STRING	L"FIREMAN\n\nCLEAR POINT"

#define PATH_RESOURCE_MAP_INFOR		L"Resource//Image//Maps//mapinfo//mapinfo.txt"
#define PATH_RESOURCE_PATH_CAMERA	"Resource//Path//CameraPath.txt"

#define VEL_PLAYER_X			4
#define VEL_PLAYER_Y			19
#define ACCEL_PLAYER_X			0.5f
#define ACCEL_PLAYER_Y			1

#define POOLSIZE					5
#define LEVELPOOL(A)				(A*POOLSIZE)		
#define GAME_OVER_STRING			"GAME  OVER"
#define CONTINUE_STRING				"CONTINUE"
#define SELECT_STAGE_STRING_GV		"SELECT  STAGE"

#define DELTA_SIZE_Y_FOR_BOOM_OF_BOSSMAN			30
#define TIME_FOR_WAIT_BUM							2000
#define TIME_FOR_BUM								1000
/************************************/

/*ENUM*/
enum GAMESTATE
{
	STATE_END,
	STATE_RUN
};

enum CAMERASTATE
{
	CAMERA_X,							// with rockman, this mean is update for X asix
	CAMERA_AUTO,						// AUTO ++ HEIGH
	CAMERA_UP,
	CAMERA_DOWN,
	CAMERA_STOP
};


enum KEYSTATE
{
	KEY_PRESS = 0,
	KEY_RELEASE,
	KEY_UP,
	KEY_DOWN
};

enum BULLETSTATE
{
	BULLET_STATE_SHOW,
	BULLET_STATE_INVIS,
	BULLET_STATE_HIT,
	BULLET_STATE_DIE
};

enum TYPE_BULLET
{
	NORMAL = 0,
	MACHINE_AUTO_ORANGE,
	ENEMY_BALL,
	TANK_RED,
	ENEMY,
	ENEMY_PART_BOOM,
	BOSS_FIRE_MAN,
	BOSS_BOMB_MAN,
	NUMBER_OF_TYPE_BULLET
};

enum PLAYSTATE
{
	START					= 0,
	STAND,
	STAND_SHOOT,
	RUN,
	RUN_SHOOT,
	JUMP,
	JUMP_SHOOT,
	CLIMB,
	CLIMB_SHOOT,
	CLIMB_END,
	HIT
};

enum BOSSSTATE
{
	BOSS_STAND,
	BOSS_JUMP_LOW,
	BOSS_JUMP_HIGHT,
	BOSS_SHOOT,
	BOSS_DIE
};


enum STAGESELECTED
{
	CUTMAN,
	GUTSMAN,
	ICEMAN,
	BOMBMAN,
	FIREMAN,
	ELECMAN
};

enum DIRECTION
{
	DIRECTION_NONE	=  0,
	DIRECTION_RIGHT =  1,
	DIRECTION_UP	=  1,
	DIRECTION_LEFT	= -1,
	DIRECTION_DOWN	= -1
};

enum COLDIRECTION
{
	COLDIRECTION_NONE,
	COLDIRECTION_TOP,
	COLDIRECTION_BOTTOM,
	COLDIRECTION_LEFT,
	COLDIRECTION_RIGHT
};
enum PLAYERSTATES
{
	STATE_START				= 0,
	STATE_STAND				= 1,
	STATE_STAND_SHOOT		= 2,
	STATE_MOVE				= 3,
	STATE_MOVE_SHOOT		= 4,
	STATE_JUMP				= 5,
	STATE_JUMP_SHOOT		= 6,
	STATE_CLIMB				= 7,
	STATE_CLIMB_SHOOT		= 8,
	STATE_CLIMB_END			= 9,
	STATE_HIT				= 10
};

enum STYLELIST_IN_QUADTREE
{
	ENEMY_LIST,
	TILE_LIST,
	COLLISION_LIST
};

enum SKILL_ROCKMAN
{
	ROCKMAN_NORMAL_SKILL,
	ROCKMAN_CUT_SKILL,
	ROCKMAN_BOMB_SKILL,
	ROCKMAN_FIRE_SKILL,

	NUM_OF_ROCKMAN_SKILL
};
/******************/

/*STRUCT*/
struct CollisionEvents
{
	int				m_CollisionDirection;
	CBaseEntity*	m_Entity;
	

	CollisionEvents(int colDirect, CBaseEntity* entity)
	{
		m_CollisionDirection	= colDirect;
		m_Entity				= entity;
	}
};

struct KeyState
{
	int KeyCode;
	KEYSTATE KeyStates;
};

struct	MapInfo
{
	wstring			m_Name;
	wstring			m_Path;

	MapInfo(wstring name, wstring path)
	{
		m_Name = name;
		m_Path = path;
	}

	~MapInfo()
	{
	}
};

typedef struct DataCameraPath
{
	int				m_minX,
					m_maxX,
					m_minY,
					m_maxY;

	int				m_styleCamera;

	DataCameraPath()
	{
	};
	DataCameraPath(int min1, int max1, int min2, int max2, int style)
	{
		m_minX					= min1;
		m_maxX					= max1;
		m_minY					= min2;
		m_maxY					= max2;
		m_styleCamera			= style;
	}

}DataCameraPath;

/******************************/

/*CONST*/
/******************/

/******************************/

/*VLD*/
#ifndef __VLD_H__
#define __VLD_H__
#include <vld.h>
#endif
/********************/

#define				SIZE_MAP_WIDTH			20000
#define				SIZE_MAP_HIGHT			20000
#define				MAX_OBJECT_OF_NODE		4
#define				MAX_LEVEL_OF_NODE		5

#endif