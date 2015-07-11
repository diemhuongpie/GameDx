//#include "Camera.h"
//
//vector3d			CCamera::m_Position					= vector3dZero;
//matrix				CCamera::m_MatrixTransform;
//vector4d			CCamera::m_Viewport;
//float*				CCamera::m_ViewportX				= 0;
//float*				CCamera::m_viewportY				= 0;
//RECT				CCamera::m_LimitRect				= RECT();
//CCamera*			CCamera::m_Instance					= NULL;
//CAMERASTATE			CCamera::
//
//CCamera::CCamera()
//{
//	m_Position		= vector3d(0, 530/2, 0);
//	m_ViewportX		= &m_Position.x;
//	m_viewportY		= &m_Position.y;
//
//	setLimitRectOfCurrentMap(3000, 530 / 2);
//	D3DXMatrixIdentity(&m_MatrixTransform);
//	
//}
//
//
//CCamera::~CCamera()
//{
//}
//
//void CCamera::Update(vector3d	positionEntity)
//{
//	switch (CCamera::getInstance()->getStateCamera())
//	{
//	case CAMERA_NORMAL:
//		
//		break;
//	case CAMERA_AUTO:
//		
//		break;
//	case CAMERA_STOP:
//		break;
//	default:
//		break;
//	}
//}
