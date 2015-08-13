#ifndef __QUADTREE_H__
#define __QUADTREE_H__

#include "Game\Utill\stdafx.h"
#include "Game\Utill\Config.h"
#include "Game\Algorithsm\Singleton.h"
#include "QuadNode.h"

class CQuadTree : public CSingleton<CQuadTree>
{
public:
	CQuadTree();
	~CQuadTree();

	void								CreateTree();
	void								ReleaseTree();
	vector<CBaseEntity*>				Retrieve();
protected:
	CQuadNode*							m_Node;

};

#endif

