#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "Game\Utill\stdafx.h"
#include "Game\Utill\Config.h"
#include "Mathematics\Box2D.h"

class CCamera
{
public:
	static	void			Update							(vector3d	&positionPlayer);
	static	void			Render							();
	static	void			NormalUpdate					(vector3d	&positionPlayer);
	static	void			DownUpdate						(vector3d	&positionPlayer);
	static	void			UpUpdate						(vector3d	&positionPlayer);
	static	void			StopUpdate						(vector3d	&positionPlayer);
	static	vector3d		setPositionEntity				(vector3d	&position);
	static	CCamera*		getInstance						();
			int				getStateCamera					();
			vector3d		getPosisionCamera				();
			vector4d		getViewport						();
			vector4d		getSizeForState					();
			CBox2D			getBoundingScreen				();
			void			setPositionCamera				(vector3d*);
			void			setLimitRectOfCurrentMap		(float, float);
	static	void			checkStateCamera				(vector3d positionEntity);
	static	bool			readDataPath					();

private:

	static vector3d							m_Position;
	static matrix							m_MatrixTransform;
	static vector4d							m_Viewport;
	static float*							m_ViewportX;
	static float*							m_ViewportY;
	static int								m_StateCamera;
	static vector4d							m_SizeForState;
	static RECT								m_LimitRect;

	static vector<vector<DataCameraPath*>>	m_ListPathCamera;
private:
	CCamera();
	~CCamera();

	static CCamera*				m_Instance;



};

#endif