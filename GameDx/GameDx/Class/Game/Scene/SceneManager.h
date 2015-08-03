#ifndef __SCENEMANAGER_H__
#define __SCENEMANAGER_H__

#include "Game\Utill\stdafx.h"
#include <stack>
#include "Game\Utill\Config.h"
#include "Game\Scene\BaseScene.h"
#include "Game\Scene\MenuScene.h"
#include "Game\Scene\PlayScene.h"

class CSceneManager
{
public:

	static	CSceneManager*				getInstance();
			std::stack<CBaseScene*>&	getScene();
	static	void						initDevice(LPDIRECT3DDEVICE9 device);
			void						init();

private:
	CSceneManager();
	~CSceneManager();

	static	CSceneManager*				m_Instance;

private:
	static	LPDIRECT3DDEVICE9			m_Device;
			std::stack<CBaseScene*>		m_ListScene;
};

#endif