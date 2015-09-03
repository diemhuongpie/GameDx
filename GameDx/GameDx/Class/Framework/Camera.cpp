#ifndef __VLD_H__
#define __VLD_H__
#include <vld.h>
#endif
#include "Camera.h"
#include "Game\Map\MapManager.h"

int changeStyleCam(string style);

vector3d			CCamera::m_Position					= vector3dZero;
vector4d			CCamera::m_SizeForState				= vector4d(0,0,0,0);
matrix				CCamera::m_MatrixTransform;
vector4d			CCamera::m_Viewport;
float*				CCamera::m_ViewportX				= 0;
float*				CCamera::m_ViewportY				= 0;
RECT				CCamera::m_LimitRect				= RECT();
CCamera*			CCamera::m_Instance					= NULL;
int					CCamera::m_StateCamera				= CAMERASTATE::CAMERA_X;


vector < vector<DataCameraPath*>>		CCamera::m_ListPathCamera;

CCamera::CCamera()
{
	m_Position		= vector3d(0, BACKBUFFER_HEIGHT, 0);
	m_ViewportX		= &m_Position.x;
	m_ViewportY		= &m_Position.y;

	readDataPath();

	setLimitRectOfCurrentMap(3350, BACKBUFFER_HEIGHT);
	D3DXMatrixIdentity(&m_MatrixTransform);
	
}


CCamera::~CCamera()
{
	SAFE_RELEASE(m_ViewportX);
	SAFE_RELEASE(m_ViewportY);
	SAFE_RELEASE(m_Instance);
}

CCamera*	CCamera::getInstance()
{
	if (!m_Instance)
		m_Instance	= new CCamera();
	return	m_Instance;
}

int	CCamera::getStateCamera()
{
	return m_StateCamera;
}

vector3d	CCamera::getPosisionCamera()
{
	return m_Position;
}

vector4d	CCamera::getSizeForState()
{
	return m_SizeForState;
}

vector4d	CCamera::getViewport()
{
	return m_Viewport;
}

CBox2D		CCamera::getBoundingScreen()
{
	return CBox2D(m_Position.x, m_Position.y, BACKBUFFER_WIDTH, BACKBUFFER_HEIGHT);
}

void CCamera::Update(vector3d	&positionEntity)
{
	CCamera::checkStateCamera(positionEntity);
	switch (CCamera::getInstance()->getStateCamera())
	{
	case CAMERA_DOWN:
		DownUpdate(positionEntity);
		break;
	case CAMERA_X:
		NormalUpdate(positionEntity);
		break;
	case CAMERA_AUTO:
		break;
	case CAMERA_UP:
		UpUpdate(positionEntity);
		break;
	case CAMERA_STOP:
		StopUpdate(positionEntity);
		break;
	default:
		break;
	}
}

void	CCamera::NormalUpdate(vector3d	&positionEntity)
{
	if (	positionEntity.x - BACKBUFFER_WIDTH / 2.0f != m_Position.x				&& 
		(	positionEntity.x < (m_SizeForState.y - BACKBUFFER_WIDTH / 2)		)	&& 
		 (	positionEntity.x > (m_SizeForState.x + BACKBUFFER_WIDTH / 2)		))
		m_Position.x = positionEntity.x - BACKBUFFER_WIDTH / 2.0f;

	m_MatrixTransform._22 = -1.0f;
	m_MatrixTransform._41 = -*m_ViewportX;
	m_MatrixTransform._42 = m_Position.y;
}

void	CCamera::UpUpdate(vector3d &positionEntity)
{
	if (m_Position.y >= positionEntity.y + BACKBUFFER_HEIGHT)
		m_StateCamera = CAMERASTATE::CAMERA_STOP;
	else
		m_Position.y += 2;

	m_MatrixTransform._22 = -1.0f;
	m_MatrixTransform._41 = -*m_ViewportX;
	m_MatrixTransform._42 = m_Position.y;
}

void	CCamera::DownUpdate(vector3d &positionEntity)
{
	if (m_Position.y <= positionEntity.y + 10)
		m_StateCamera = CAMERASTATE::CAMERA_STOP;
	else
		m_Position.y -= 2;

	/*if ((m_Position.y <= positionEntity.y) && (positionEntity.y <= m_SizeForState.w))
		m_StateCamera = CAMERASTATE::CAMERA_UP;*/

	m_MatrixTransform._22 = -1.0f;
	m_MatrixTransform._41 = -*m_ViewportX;
	m_MatrixTransform._42 = m_Position.y;
}

void	CCamera::StopUpdate(vector3d &positionEntity)
{
	if ((m_Position.y >= positionEntity.y + BACKBUFFER_HEIGHT + 10) && positionEntity.y >= m_SizeForState.z)
		m_StateCamera = CAMERASTATE::CAMERA_DOWN;

	if ((m_Position.y <= positionEntity.y) && (positionEntity.y <= m_SizeForState.w))
		m_StateCamera = CAMERASTATE::CAMERA_UP;

	m_MatrixTransform._22 = -1.0f;
	m_MatrixTransform._41 = -*m_ViewportX;
	m_MatrixTransform._42 = m_Position.y;

}

vector3d	CCamera::setPositionEntity(vector3d	&pos)
{
	if (!m_Instance)
		m_Instance = new CCamera();
	D3DXVec3Transform(&m_Viewport, &pos, &m_MatrixTransform);
	return D3DXVECTOR3(m_Viewport.x, m_Viewport.y, 0);
	return pos;
}

void		CCamera::setLimitRectOfCurrentMap(float width, float height)
{
	this->m_LimitRect.left			= 0;
	this->m_LimitRect.right			= this->m_LimitRect.left + width;
	this->m_LimitRect.bottom		= 530;
	this->m_LimitRect.top			= this->m_LimitRect.bottom + height;
};

void		CCamera::checkStateCamera(vector3d positionEntity)
{

	for (int i = 0; i < m_ListPathCamera.at(CMapmanager::getInstance()->getCurrentIndexMap()).size(); i++)
	{
		if ((positionEntity.x > m_ListPathCamera.at(CMapmanager::getInstance()->getCurrentIndexMap()).at(i)->m_minX) &&
			(positionEntity.x < m_ListPathCamera.at(CMapmanager::getInstance()->getCurrentIndexMap()).at(i)->m_maxX) &&
			(positionEntity.y > m_ListPathCamera.at(CMapmanager::getInstance()->getCurrentIndexMap()).at(i)->m_minY) &&
			(positionEntity.y < m_ListPathCamera.at(CMapmanager::getInstance()->getCurrentIndexMap()).at(i)->m_maxY))
		{
			m_SizeForState.x	= m_ListPathCamera.at(CMapmanager::getInstance()->getCurrentIndexMap()).at(i)->m_minX;
			m_SizeForState.y	= m_ListPathCamera.at(CMapmanager::getInstance()->getCurrentIndexMap()).at(i)->m_maxX;
			m_SizeForState.z	= m_ListPathCamera.at(CMapmanager::getInstance()->getCurrentIndexMap()).at(i)->m_minY;
			m_SizeForState.w	= m_ListPathCamera.at(CMapmanager::getInstance()->getCurrentIndexMap()).at(i)->m_maxY;

			// noob la
			if (m_StateCamera == CAMERASTATE::CAMERA_X)
				if (m_ListPathCamera.at(CMapmanager::getInstance()->getCurrentIndexMap()).at(i)->m_styleCamera != CAMERASTATE::CAMERA_X)
					m_StateCamera = m_ListPathCamera.at(CMapmanager::getInstance()->getCurrentIndexMap()).at(i)->m_styleCamera;
				else{}
			else if (m_StateCamera != CAMERASTATE::CAMERA_X)
				if (m_ListPathCamera.at(CMapmanager::getInstance()->getCurrentIndexMap()).at(i)->m_styleCamera == CAMERASTATE::CAMERA_X)
					m_StateCamera = m_ListPathCamera.at(CMapmanager::getInstance()->getCurrentIndexMap()).at(i)->m_styleCamera;

		}
		/*if (positionEntity.y > m_Position.y + 30)
			m_StateCamera = CAMERASTATE::CAMERA_UP;
			else if (positionEntity.y  < m_Position.y - BACKBUFFER_HEIGHT - 30)
			m_StateCamera = CAMERASTATE::CAMERA_DOWN;*/
	}

	if (!(m_StateCamera == CAMERASTATE::CAMERA_X))
	{
		if ((m_Position.y <= positionEntity.y) && (positionEntity.y <= m_SizeForState.w))
		UpUpdate(positionEntity);
		else if ((m_Position.y + BACKBUFFER_HEIGHT > positionEntity.y) && positionEntity.y < m_SizeForState.z)
		DownUpdate(positionEntity);
	}
};

bool		CCamera::readDataPath()
{
	fstream fs;
	fs.open(PATH_RESOURCE_PATH_CAMERA);

	if (!fs)
		return false;

	/******************STUPID**********************/
	int								sizeOfPathCamera			= 0;
	int								indexList					= 0;

	int								minX						= 0,
									maxX						= 0,
									minY						= 0,
									maxY						= 0;
	string							styleCam					= "NULL";
	vector<DataCameraPath*>			listCamera;
	/*****************END STUPID*****************/

	while (fs)
	{
		fs >> sizeOfPathCamera;
		for (int i = 0; i < sizeOfPathCamera * 5; ++i)
		{
			fs >> minX >> maxX >> minY >> maxY >> styleCam;
			listCamera.push_back(new DataCameraPath(minX, maxX, minY, maxY, changeStyleCam(styleCam)));
		}
		m_ListPathCamera.push_back(listCamera);
	}

	return true;
}

int changeStyleCam(string style)
{
	if (style == "X")
		return CAMERASTATE::CAMERA_X;
	if (style == "YU")
		return CAMERASTATE::CAMERA_UP;
	if (style == "YD")
		return CAMERASTATE::CAMERA_DOWN;
	else
		return CAMERASTATE::CAMERA_X;
}