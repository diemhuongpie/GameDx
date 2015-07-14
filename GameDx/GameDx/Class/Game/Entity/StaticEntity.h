/****************************************************************************/
/* Create by Michael Le AND Shin Truong*/
/* 08/07/2015 */
/***************************************************************************/

#ifndef __CSTATICENTITY_H__
#define __CSTATICENTITY_H__

#include "Game\Utill\stdafx.h"
#include "Game\Utill\Config.h"
#include "BaseEntity.h"
#include "Mathematics\Box2D.h"


class CStaticEntity
{
public:
	CStaticEntity();
	~CStaticEntity();

protected:
	vector2d				m_Position;
	CBox2D*					m_Bounding;
};

#endif
