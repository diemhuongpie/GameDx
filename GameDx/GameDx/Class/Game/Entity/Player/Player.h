/*********************************************************/
/* Create by Michael Le*/
/* 08/07/2015 */
/*********************************************************/

#include "Game\Entity\MovableEntity.h"
#include "Framework\Camera.h"
#include "Mathematics\Collision.h"

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

	virtual	vector3d		getPosition()														override;
	virtual bool			loadSprite()														override;
	virtual void			resetObject()														override;

			void			HandlingCollisionEvents()													;


protected:
	
			clock_t						m_TimeState;
			vector2d					m_Accelero;
			vector2d					m_Direction;
			vector<CSprite*>*			m_RockManSpriteList;
			vector<CollisionEvents*>	m_listCollitionEvent;
private:

};

#endif
