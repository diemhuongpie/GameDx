/****************************************************************************/
/* Create by Michael Le AND Shin Truong*/
/* 08/07/2015 */
/***************************************************************************/

#ifndef __CMOVABLE__H__
#define __CMOVABLE__H__

#include "Game\Utill\stdafx.h"
#include "Game\Utill\Config.h"
#include "BaseEntity.h"
#include "Mathematics\Box2D.h"

class CMovable : public CBaseEntity
{
public:
	CMovable();
	~CMovable();

protected:
	vector2d			m_Position;
	vector2d			m_Velocity;
	CBox2D*				m_Bounding;

};

#endif