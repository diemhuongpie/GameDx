#ifndef __QUADNODE_H__
#define __QUADNODE_H__

#include "Mathematics\Box2D.h"
#include "Game\Utill\stdafx.h"	
#include "Game\Utill\Config.h"
#include "Game\Entity\BaseEntity.h"
#include "Game\Entity\MovableEntity.h"
#include "Framework\Camera.h"
#include "Mathematics\Collision.h"

class CQuadNode
{
public:
	CQuadNode();
	CQuadNode(int Level, CBox2D NodeBound);
	~CQuadNode();

	void					ReleaseNode();
	bool					InsertEntity(CBaseEntity*);

	int						getNodeLevel();							void		setNodeLevel(int);
	CBox2D					getNodeSize();							void		setNodeSize(CBox2D);
	vector<CBaseEntity*>	getEntityList();						
	CQuadNode**				getParent();							
	void					SplitParent();
	void					RenderNode();
	void					DetectCollisionInViewport(CMovable* movableEntity, float deltaTime);

private:
	int						m_NodeLevel;
	vector3d				m_PosNode;
	CBox2D					m_NodeSize;
	vector<CBaseEntity*>	m_EntityList;
	CQuadNode**				m_Node;

};

#endif