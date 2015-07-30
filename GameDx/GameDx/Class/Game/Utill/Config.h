/****************************************************************************/
/* Create by Michael Le*/
/* 07/07/2015 */
/***************************************************************************/

#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <tchar.h>

/*DEFINE*/
#define FPS 60
#define GAME_RATE (1000.0f/60.0f)
#define WINDOWS_NAME L"Oishi"

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
#define vector2d					D3DXVECTOR2
#define vector2dZero				D3DXVECTOR2(0.0f,0.0f)
#define vector4d					D3DXVECTOR4

#define matrix						D3DXMATRIX

#define SAFE_RELEASE(A)				{if (A) {delete A; A = 0;}}

#define BACKBUFFER_WIDTH			510
#define	BACKBUFFER_HEIGHT			485

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

#define CUTMAN_STAGE_INFO_STRING	"CUTMAN\nCLEAR POINT"
/************************************/

/*ENUM*/
enum GAMESTATE
{
	STATE_END,
	STATE_RUN
};


enum CAMERASTATE
{
	CAMERA_NORMAL,						// with rockman, this mean is update for X asix
	CAMERA_AUTO,						// with rockman, this mean is update for Y asix
	CAMERA_STOP
};


enum KEYSTATE
{
	KEY_PRESS = 0,
	KEY_RELEASE,
	KEY_UP,
	KEY_DOWN
};

enum PLAYERSTATE
{
	PLAYER_STAND = 0,
	PLAYER_MOVE,
	PLAYER_JUMP,
	PLAYER_CLIMB,
	PLAYER_DIE,
	PLAYER_HIT,
	PLAYER_SHOOT
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
/******************/

/*STRUCT*/
struct KeyState
{
	int KeyCode;
	KEYSTATE KeyStates;
};
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
#endif