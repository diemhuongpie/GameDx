#include "MapManager.h"
#include <fstream>

class CCamera;

CMapmanager::CMapmanager()
{
	m_CurrentMap		= new MapData();
}

CMapmanager::~CMapmanager()
{
	SAFE_RELEASE(m_CurrentMap);
}

void		CMapmanager::readMapList()
{
	wstring			mapName;
	wstring			mapPath;
	wfstream		fs;

	fs.open(PATH_RESOURCE_MAP_INFOR);
	if (!fs)
		return;

	while (fs)
	{
		fs >> mapName >> mapPath;
		m_MapList.push_back(new MapInfo(mapName, mapPath));
	}
}

void		CMapmanager::switchMap(int step)
{
	setCurrentMapAt(m_CrIndex + step);
	// get Size limited CCamera
}
	
MapData*	CMapmanager::getCurrentMap()
{ 
	return m_CurrentMap;
}

void		CMapmanager::setCurrentMapAt(int index)
{
	if (index < 1 || index >= m_MapList.size() + 1)
		return;

	m_CrIndex = index - 1;

	m_CurrentMap->readMapInfor(m_MapList.at(m_CrIndex)->m_Path);
}


int			CMapmanager::getCurrentIndexMap()
{
	return m_CrIndex;
}

#include "Framework\Camera.h"