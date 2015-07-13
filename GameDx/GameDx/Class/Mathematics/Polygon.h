#ifndef __POLYGON_H__
#define __POLYGON_H__

#include "Game\Utill\stdafx.h"
#include "Game\Utill\Config.h"

class CPolygon
{
public:
	CPolygon();
	~CPolygon();

	virtual		void	update(float deltaTime, vector2d posision) = 0;
	virtual		void	render()									= 0;
};

#endif