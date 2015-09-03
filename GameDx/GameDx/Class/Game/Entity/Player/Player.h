/*********************************************************/
/* Create by Michael Le*/
/* 08/07/2015 */
/*********************************************************/
#include "Game\Utill\Config.h"
#include "Game\Entity\MovableEntity.h"
#include "Framework\Camera.h"
#include "Mathematics\Collision.h"
#include "Framework\Text.h"
#include "Game\Scene\GameOverScene.h"

class CSceneManager;


#ifndef __CPLAYER_H__
#define __CPLAYER_H__

class CPlayer : public CMovable
{
public:
	CPlayer();
	CPlayer(LPDIRECT3DDEVICE9);
	~CPlayer();

	virtual bool			initEntity()														override;
	virtual void			updateEntity(float deltaTime)										override;
	virtual void			updateEntity(CBaseEntity*)											override;
	virtual void			updateEntity(CKeyBoard *device)										override;
	virtual void			drawEntity()														override;

	virtual CBox2D			getBounding()														override;
	virtual	vector3d		getPosition()														override;
	virtual bool			loadSprite()														override;
	virtual void			resetObject()														override;

			void			setColisWithStair(bool);
			void			setDead();
			void			handlingDead();

protected:
	
			vector<CSprite*>*			m_RockManSpriteList;
			clock_t						m_TimeState;
			vector2d					m_Accelero;
			vector2d					m_Direction;

			int							m_isColisWithStair;					

			/**************************************************************************************************/
			// Stupid of thing: We built listColisionEvent to detect Colision.
			// But. When we handled collision with tile so dont care TagColision.
			// Now we dont now which is handle's collision for tile and another collision. It's mistaked by me.
			/**************************************************************************************************/

			
private:

};

#include "Game\Scene\SceneManager.h"
#endif
