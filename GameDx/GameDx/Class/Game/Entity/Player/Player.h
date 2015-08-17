/*********************************************************/
/* Create by Michael Le*/
/* 08/07/2015 */
/*********************************************************/

#include "Game\Entity\MovableEntity.h"
#include "Framework\Camera.h"

#ifndef __CPLAYER_H__
#define __CPLAYER_H__


class CPlayer : public CMovable
{
public:
	CPlayer();
	CPlayer(LPDIRECT3DDEVICE9);
	~CPlayer();

	virtual bool			initEntity()											override;
	virtual void			updateEntity(float deltaTime)							override;
	virtual void			updateEntity(CKeyBoard *device)							override;
	virtual void			drawEntity()											override;
	virtual	vector3d		getPosition()											override;
	virtual bool			loadSprite()											override;

public:
			void 			logicStandPlayer(float deltaTime);
			void 			logicMovePlayer(float deltaTime);
			void 			logicJumpPlayer(float deltaTime);
			void			logicClimbPlayer(float deltaTime);
			
protected:
	
			clock_t			m_TimeState;
			vector2d		m_Accelero;
			bool			m_IsMoveJumb;


private:

};

#endif
