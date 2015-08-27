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

void CQuadTree::CollisionNodeInViewPort(CMovable* movableEntity, float deltaTime)
{
	m_Node->DetectCollisionInViewport(movableEntity, deltaTime);
}