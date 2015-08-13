#ifndef __QUADNODE_H__
#define __QUADNODE_H__

#include "Mathematics\Box2D.h"
#include "Game\Utill\stdafx.h"	
#include "Game\Utill\Config.h"
#include "Game\Entity\BaseEntity.h"

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

private:
	int						m_NodeLevel;
	CBox2D					m_NodeSize;
	vector<CBaseEntity*>	m_EntityList;
	CQuadNode**				m_Node;
};

#endif