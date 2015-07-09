/****************************************************************************/
/* Create by Michael Le*/
/* 07/07/2015 */
/***************************************************************************/

#ifndef __CONFIG_H__
#define __CONFIG_H__



/*DEFINE*/
#define FPS 60
#define FRAME_RATE (1000.0f/60.0f)
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

#define KEYBOARD_BUFFER_SIZE	1024
#define ISKEYDOWN(keystatus) (keystatus & 0x80)

/************************************/

/*ENUM*/
enum GAMESTATE
{
	STATE_END,
	STATE_RUN
};

enum KEYSTATE
{
	KEY_PRESS = 0,
	KEY_RELEASE,
	KEY_UP,
	KEY_DOWN
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

#endif