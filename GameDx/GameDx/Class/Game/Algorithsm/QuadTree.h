#ifndef __QUADTREE_H__
#define __QUADTREE_H__

#include "Game\Utill\stdafx.h"
#include "Game\Utill\Config.h"
#include "Game\Algorithsm\Singleton.h"
#include "QuadNode.h"
#include "Game\Entity\MovableEntity.h"

class CQuadTree : public CSingleton<CQuadTree>
{
public:
	CQuadTree();
	~CQuadTree();

	void								CreateTree();
	void								ReleaseTree();
	void								RenderTree();
	void								DeviceObjectToTree(vector<CBaseEntity*> ListTileObject);
	void								CollisionNodeInViewPort(CMovable* movableEntity);
protected:
	CQuadNode*							m_Node;

};

#endif

