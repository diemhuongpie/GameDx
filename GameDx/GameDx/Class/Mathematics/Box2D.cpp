#include "Box2D.h"
#include "Framework\Camera.h"

CBox2D::CBox2D()
{
	m_Position		= vector2dZero;
	m_Size			= vector2dZero;
	m_Velocity		= vector2dZero;
}

CBox2D::CBox2D(RECT rectangle)
{
	m_Position.x	= rectangle.left;
	m_Position.y	= rectangle.top;

	m_Size.x		= rectangle.right	- rectangle.left;
	m_Size.y		= rectangle.top		- rectangle.bottom;

	m_Velocity		= vector2dZero;
}

CBox2D::CBox2D(RECT rectangle, vector2d velocity)
{
	m_Position.x	= rectangle.left;
	m_Position.y	= rectangle.top;

	m_Size.x		= rectangle.right	- rectangle.left;
	m_Size.y		= rectangle.top		- rectangle.bottom;

	m_Velocity		= velocity;
}


CBox2D::CBox2D(LPDIRECT3DDEVICE9 device, RECT rectangle, vector2d velocity)
{

	HRESULT hr = D3DXCreateLine(device, &m_line);

	if (FALSE(hr))
		return;

	m_Position.x	= rectangle.left;
	m_Position.y	= rectangle.top;

	m_Size.x		= rectangle.right	- rectangle.left	+ deltaBoundingBox.x*2;
	m_Size.y		= rectangle.top		- rectangle.bottom	+ deltaBoundingBox.y*2;

	m_Velocity		= velocity;
}


CBox2D::~CBox2D()
{
}

void	CBox2D::update(float deltaTime, vector2d positionEntity)
{
	m_Position = positionEntity;
	m_Position.x -= deltaBoundingBox.x;
	m_Position.y += deltaBoundingBox.y;
	// viet swept AABB vo day
}

void	CBox2D::render()
{
	vector2d	vertex1[] = { CCamera::setPositionEntity(vector3d(m_Position)), CCamera::setPositionEntity(vector3d(vector2d(m_Position.x, m_Position.y - m_Size.y))) };
	m_line->Draw(vertex1, 2, 0xFFFF00FF);

	vector2d	vertex2[] = { CCamera::setPositionEntity(vector3d(vector2d(m_Position.x, m_Position.y - m_Size.y))), CCamera::setPositionEntity(vector3d(vector2d(m_Position.x + m_Size.x, m_Position.y - m_Size.y))) };
	m_line->Draw(vertex2, 2, 0xFFFF00FF);

	vector2d	vertex3[] = { CCamera::setPositionEntity(vector3d(vector2d(m_Position.x + m_Size.x, m_Position.y - m_Size.y))), CCamera::setPositionEntity(vector3d(vector2d(m_Position.x + m_Size.x, m_Position.y))) };
	m_line->Draw(vertex3, 2, 0xFFFF00FF);

	vector2d	vertex4[] = { CCamera::setPositionEntity(vector3d(m_Position)), CCamera::setPositionEntity(vector3d(vector2d(m_Position.x + m_Size.x, m_Position.y))) };
	m_line->Draw(vertex4, 2, 0xFFFF00FF);
}

float	CBox2D::getHeight()
{
	return m_Size.y;
}

float	CBox2D::getWidth()
{
	return m_Size.x;
}

float	CBox2D::getX()
{
	return m_Position.x;
}

float	CBox2D::getY()
{
	return m_Position.y;
}

float	CBox2D::getVelocityX()
{
	return m_Velocity.x;
}

float	CBox2D::getVelocityY()
{
	return m_Velocity.y;
}