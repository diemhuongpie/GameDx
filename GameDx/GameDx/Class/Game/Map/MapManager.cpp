#include "MapManager.h"
#include <fstream>
#include "Framework\Camera.h"

CMapmanager::CMapmanager()
{
}

CMapmanager::~CMapmanager()
{
	SAFE_RELEASE(m_CurrentMap);
}

void		CMapmanager::readMapList()
{
	char*			mapName		="";
	char*			mapPath		="";
	ifstream		fs;

	fs.open(PATH_RESOURCE_MAP_INFOR);
	if (!fs)
		return;

	while (fs)
	{
		fs >> mapName >> mapPath;
		m_MapList.push_back(new MapInfo(mapName, (wchar_t*)mapPath));
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
	if (index < 0 || index >= m_MapList.size())
		return;

	m_CrIndex = index + 1;

	m_CurrentMap->readMapInfor(m_MapList.at(m_CrIndex)->m_Path);
}


