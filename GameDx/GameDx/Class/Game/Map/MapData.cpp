#include "MapData.h"
#include <fstream>

MapData::MapData()
{
	m_listBox.clear();
	m_listTile.clear();
	m_listEntity.clear();
}


MapData::~MapData()
{
}

void	MapData::readMapInfor(wchar_t* filePath)
{
	readTileMap(filePath);
}

void	MapData::readTileMap(wchar_t* filePath)
{
	ifstream				fs;
	fs.open(wcscat(filePath, L"data.txt"));

	if (!fs)
		return;

	int						posX,
							posY;
	string					type;

	while (fs >> posX >> posY >> type)
	{
		posX *= 2;
		posY *= 2; posY += 32;
		if (type == "0C")
			m_listTile.push_back(new CTile(new CSprite(wcscat(filePath, L"resource//1.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, 32, 32), 0));
		if (type == "1C")
			m_listTile.push_back(new CTile(new CSprite(wcscat(filePath, L"resource//2.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, 32, 32), 1));
		if (type == "2C")
			m_listTile.push_back(new CTile(new CSprite(wcscat(filePath, L"resource//3.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, 32, 32), 2));
		if (type == "3C")
			m_listTile.push_back(new CTile(new CSprite(wcscat(filePath, L"resource//4.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, 32, 32), 3));
		if (type == "4C")
			m_listTile.push_back(new CTile(new CSprite(wcscat(filePath, L"resource//5.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, 32, 32), 4));
		if (type == "5C")
			m_listTile.push_back(new CTile(new CSprite(wcscat(filePath, L"resource//6.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, 32, 32), 5));
		if (type == "6C")
			m_listTile.push_back(new CTile(new CSprite(wcscat(filePath, L"resource//7.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, 32, 32), 6));
		if (type == "7C")
			m_listTile.push_back(new CTile(new CSprite(wcscat(filePath, L"resource//8.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, 32, 32), 7));
		if (type == "8C")
			m_listTile.push_back(new CTile(new CSprite(wcscat(filePath, L"resource//9.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, 32, 32), 8));
		if (type == "9C")
			m_listTile.push_back(new CTile(new CSprite(wcscat(filePath, L"resource//10.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, 32, 32), 9));
		if (type == "10C")
			m_listTile.push_back(new CTile(new CSprite(wcscat(filePath, L"resource//11.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, 32, 32), 10));
		if (type == "11C")
			m_listTile.push_back(new CTile(new CSprite(wcscat(filePath, L"resource//12.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, 32, 32), 11));
		if (type == "12C")
			m_listTile.push_back(new CTile(new CSprite(wcscat(filePath, L"resource//13.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, 32, 32), 12));
		if (type == "13C")
			m_listTile.push_back(new CTile(new CSprite(wcscat(filePath, L"resource//14.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, 32, 32), 13));
		if (type == "14C")
			m_listTile.push_back(new CTile(new CSprite(wcscat(filePath, L"resource//15.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, 32, 32), 14));
		if (type == "15C")
			m_listTile.push_back(new CTile(new CSprite(wcscat(filePath, L"resource//16.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, 32, 32), 15));
		if (type == "16C")
			m_listTile.push_back(new CTile(new CSprite(wcscat(filePath, L"resource//17.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, 32, 32), 16));
		if (type == "17C")
			m_listTile.push_back(new CTile(new CSprite(wcscat(filePath, L"resource//18.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, 32, 32), 17));
		if (type == "18C")
			m_listTile.push_back(new CTile(new CSprite(wcscat(filePath, L"resource//19.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, 32, 32), 18));
		if (type == "19C")
			m_listTile.push_back(new CTile(new CSprite(wcscat(filePath, L"resource//20.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, 32, 32), 19));
		if (type == "20C")
			m_listTile.push_back(new CTile(new CSprite(wcscat(filePath, L"resource//21.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, 32, 32), 20));
		if (type == "21C")
			m_listTile.push_back(new CTile(new CSprite(wcscat(filePath, L"resource//22.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, 32, 32), 21));
		if (type == "22C")
			m_listTile.push_back(new CTile(new CSprite(wcscat(filePath, L"resource//23.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, 32, 32), 22));
		if (type == "23C")
			m_listTile.push_back(new CTile(new CSprite(wcscat(filePath, L"resource//24.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, 32, 32), 23));
		if (type == "24C")
			m_listTile.push_back(new CTile(new CSprite(wcscat(filePath, L"resource//25.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, 32, 32), 24));
		if (type == "25C")
			m_listTile.push_back(new CTile(new CSprite(wcscat(filePath, L"resource//26.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, 32, 32), 25));
		if (type == "26C")
			m_listTile.push_back(new CTile(new CSprite(wcscat(filePath, L"resource//27.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, 32, 32), 26));
		if (type == "27C")
			m_listTile.push_back(new CTile(new CSprite(wcscat(filePath, L"resource//28.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, 32, 32), 27));
		if (type == "28C")
			m_listTile.push_back(new CTile(new CSprite(wcscat(filePath, L"resource//29.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, 32, 32), 28));
		if (type == "29C")
			m_listTile.push_back(new CTile(new CSprite(wcscat(filePath, L"resource//30.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, 32, 32), 29));
		if (type == "30C")
			m_listTile.push_back(new CTile(new CSprite(wcscat(filePath, L"resource//31.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, 32, 32), 30));
		if (type == "31C")
			m_listTile.push_back(new CTile(new CSprite(wcscat(filePath, L"resource//32.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, 32, 32), 31));
		if (type == "32C")
			m_listTile.push_back(new CTile(new CSprite(wcscat(filePath, L"resource//33.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, 32, 32), 32));
		if (type == "33C")
			m_listTile.push_back(new CTile(new CSprite(wcscat(filePath, L"resource//34.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, 32, 32), 33));
		if (type == "34C")
			m_listTile.push_back(new CTile(new CSprite(wcscat(filePath, L"resource//35.png"), 1, 1, 1, 0), vector3d(posX, posY, 0.5f), new CBox2D(posX, posY, 32, 32), 34));
	}
}