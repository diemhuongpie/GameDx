/*********************************************************/
/* Create by Michael Le*/
/* 08/07/2015 */
/*********************************************************/

#include "MovableEntity.h"

#ifndef __CPLAYER_H__
#define __CPLEYER_H__

class CPlayer : public CMovable
{
public:
	CPlayer();
	CPlayer(LPDIRECT3DDEVICE9);
	~CPlayer();

	virtual bool initEntity()						override;
	virtual void updateEntity(float deltaTime)		override;
	virtual void updateEntity(CKeyBoard device)		override;
	virtual void updateEntity(RECT rectCamera)		override;
	virtual void drawEntity()						override;

	virtual bool loadSprite()						override;

private:

};

#endif
