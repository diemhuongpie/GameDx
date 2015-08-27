#include "MapData.h"
#include <fstream>
#include <sstream>

MapData::MapData()
{
	m_listCollisionTile.clear();
	m_listTile.clear();
	m_listEntity.clear();
}


MapData::~MapData()
{
	m_listTile.clear();
}


void	MapData::readMapInfor(wstring filePath)
{
	readTileMap(filePath);
	CQuadTree::getInstance()->DeviceObjectToTree(m_listTile);
	CQuadTree::getInstance()->DeviceObjectToTree(m_listCollisionTile);
	vector<CBaseEntity*> results;

}

void	MapData::readTileMap(wstring filePath)
{
	wfstream				fs(filePath + L"data.txt");

	if (!fs)
		return;

	int						posX,
							posY,
							posWidth,
							posHeight;
	wstring					type;

	while (fs)
	{
		fs >> type >> posX >> posY >> posWidth >> posHeight;
		if (type != L"C" && type != L"L")
		{
			if (type == L"0C")
				m_listTile.push_back(new CTile(new CSprite((filePath + L"resource//1.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, posWidth, posHeight), 0));
			if (type == L"1C")
				m_listTile.push_back(new CTile(new CSprite((filePath + L"resource//2.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, posWidth, posHeight), 1));
			if (type == L"2C")
				m_listTile.push_back(new CTile(new CSprite((filePath + L"resource//3.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, posWidth, posHeight), 2));
			if (type == L"3C")
				m_listTile.push_back(new CTile(new CSprite((filePath + L"resource//4.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, posWidth, posHeight), 3));
			if (type == L"4C")
				m_listTile.push_back(new CTile(new CSprite((filePath + L"resource//5.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, posWidth, posHeight), 4));
			if (type == L"5C")
				m_listTile.push_back(new CTile(new CSprite((filePath + L"resource//6.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, posWidth, posHeight), 5));
			if (type == L"6C")
				m_listTile.push_back(new CTile(new CSprite((filePath + L"resource//7.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, posWidth, posHeight), 6));
			if (type == L"7C")
				m_listTile.push_back(new CTile(new CSprite((filePath + L"resource//8.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, posWidth, posHeight), 7));
			if (type == L"8C")
				m_listTile.push_back(new CTile(new CSprite((filePath + L"resource//9.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, posWidth, posHeight), 8));
			if (type == L"9C")
				m_listTile.push_back(new CTile(new CSprite((filePath + L"resource//10.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, posWidth, posHeight), 9));
			if (type == L"10C")
				m_listTile.push_back(new CTile(new CSprite((filePath + L"resource//11.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, posWidth, posHeight), 10));
			if (type == L"11C")
				m_listTile.push_back(new CTile(new CSprite((filePath + L"resource//12.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, posWidth, posHeight), 11));
			if (type == L"12C")
				m_listTile.push_back(new CTile(new CSprite((filePath + L"resource//13.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, posWidth, posHeight), 12));
			if (type == L"14C")
				m_listTile.push_back(new CTile(new CSprite((filePath + L"resource//15.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, posWidth, posHeight), 14));
			if (type == L"15C")
				m_listTile.push_back(new CTile(new CSprite((filePath + L"resource//16.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, posWidth, posHeight), 15));
			if (type == L"16C")
				m_listTile.push_back(new CTile(new CSprite((filePath + L"resource//17.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, posWidth, posHeight), 16));
			if (type == L"17C")
				m_listTile.push_back(new CTile(new CSprite((filePath + L"resource//18.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, posWidth, posHeight), 17));
			if (type == L"18C")
				m_listTile.push_back(new CTile(new CSprite((filePath + L"resource//19.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, posWidth, posHeight), 18));
			if (type == L"19C")
				m_listTile.push_back(new CTile(new CSprite((filePath + L"resource//20.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, posWidth, posHeight), 19));
			if (type == L"20C")
				m_listTile.push_back(new CTile(new CSprite((filePath + L"resource//21.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, posWidth, posHeight), 20));
			if (type == L"21C")
				m_listTile.push_back(new CTile(new CSprite((filePath + L"resource//22.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, posWidth, posHeight), 21));
			if (type == L"22C")
				m_listTile.push_back(new CTile(new CSprite((filePath + L"resource//23.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, posWidth, posHeight), 22));
			if (type == L"23C")
				m_listTile.push_back(new CTile(new CSprite((filePath + L"resource//24.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, posWidth, posHeight), 23));
			if (type == L"24C")
				m_listTile.push_back(new CTile(new CSprite((filePath + L"resource//25.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, posWidth, posHeight), 24));
			if (type == L"25C")
				m_listTile.push_back(new CTile(new CSprite((filePath + L"resource//26.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, posWidth, posHeight), 25));
			if (type == L"26C")
				m_listTile.push_back(new CTile(new CSprite((filePath + L"resource//27.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, posWidth, posHeight), 26));
			if (type == L"27C")
				m_listTile.push_back(new CTile(new CSprite((filePath + L"resource//28.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, posWidth, posHeight), 27));
			if (type == L"28C")
				m_listTile.push_back(new CTile(new CSprite((filePath + L"resource//29.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, posWidth, posHeight), 28));
			if (type == L"29C")
				m_listTile.push_back(new CTile(new CSprite((filePath + L"resource//30.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, posWidth, posHeight), 29));
			if (type == L"30C")
				m_listTile.push_back(new CTile(new CSprite((filePath + L"resource//31.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, posWidth, posHeight), 30));
			if (type == L"13C")
				m_listTile.push_back(new CTile(new CSprite((filePath + L"resource//14.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, posWidth, posHeight), 13));
			if (type == L"31C")
				m_listTile.push_back(new CTile(new CSprite((filePath + L"resource//32.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, posWidth, posHeight), 31));
			if (type == L"32C")
				m_listTile.push_back(new CTile(new CSprite((filePath + L"resource//33.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, posWidth, posHeight), 32));
			if (type == L"33C")
				m_listTile.push_back(new CTile(new CSprite((filePath + L"resource//34.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, posWidth, posHeight), 33));
			if (type == L"34C")
				m_listTile.push_back(new CTile(new CSprite((filePath + L"resource//35.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, posWidth, posHeight), 34));


			m_listTile.at(m_listTile.size() - 1)->setTagNode("Tile");
		}

		if (type == L"C")
		{
			m_listCollisionTile.push_back(new CTile(new CSprite((filePath + L"resource//C.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, posWidth, posHeight), 35));
			m_listCollisionTile.at(m_listCollisionTile.size() - 1)->setTagNode("Collision");
		}
	}
}

void		MapData::update(float deltaTime, CMovable* entity)
{
	CQuadTree::getInstance()->CollisionNodeInViewPort(entity, deltaTime);
}

void		MapData::render()
{
	CQuadTree::getInstance()->RenderTree();
}