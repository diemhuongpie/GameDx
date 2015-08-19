#include "QuadTree.h"


CQuadTree::CQuadTree()
{
	this->CreateTree();
}


CQuadTree::~CQuadTree()
{
}

void CQuadTree::CreateTree()
{
	m_Node = new CQuadNode();

	//Get List Entities of Map
}

void CQuadTree::ReleaseTree()
{
	/*if (!m_Node)
	for (int i = 0; i < 4; ++i)
	{
		(m_Node->getParent())[i];
		m_Node->ReleaseNode();
		delete m_Node;
	}*/
}

void CQuadTree::RenderTree()
{
	m_Node->RenderNode();
}

void CQuadTree::DeviceObjectToTree(vector<CBaseEntity*> ListTileObject)
{
	for (vector<CBaseEntity*>::iterator i = ListTileObject.begin(); i != ListTileObject.end(); ++i)
	{
		m_Node->InsertEntity(*i);
	}
}