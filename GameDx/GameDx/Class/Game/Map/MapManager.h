#ifndef _MAP_H_
#define _MAP_H_

#include <vector>
#include "Game\Algorithsm\Singleton.h"
#include "Game\Map\MapData.h"

using namespace std;

class CMapmanager : public CSingleton<CMapmanager>
{
public:
	CMapmanager();
	~CMapmanager();

	// step = 1 meaning the next one, -1 is the previous one and so on...
	void				switchMap(int step);
	MapData*			getCurrentMap();
	void				setCurrentMapAt(int index);

	void				readMapList();

protected:
	vector<MapInfo*>	m_MapList;
	int					m_CrIndex;
	MapData*			m_CurrentMap;	
};


#endif