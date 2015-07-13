#ifndef __CBOX2D_H__
#define __CBOX2D_H__

#include "Polygon.h"
#include "Game\Utill\stdafx.h"
#include "Game\Utill\Config.h"

class CBox2D :
	public CPolygon
{
public:
	CBox2D();
	CBox2D(RECT);
	CBox2D(RECT, vector2d);
	CBox2D(LPDIRECT3DDEVICE9, RECT, vector2d);
	~CBox2D();

	virtual		void	update(float deltaTime, vector2d pos)			override;
	virtual		void	render()										override;

				float	getX();
				float	getY();
				float	getWidth();
				float	getHeight();
				float	getVelocityX();
				float	getVelocityY();

private:
	vector2d	m_Position;
	vector2d	m_Size;
	vector2d	m_Velocity;

private:
	LPD3DXLINE	m_line;

};

#endif