#include "EnemyTankRed.h"


CEnemyTankRed::CEnemyTankRed()
{
	this->initEntity();
}


CEnemyTankRed::~CEnemyTankRed()
{
}

CEnemyTankRed::CEnemyTankRed(LPDIRECT3DDEVICE9)
{
	this->initEntity();
}

bool CEnemyTankRed::initEntity()
{
	m_Position		= vector3d(80.0f, 300.0f, 0.5f);
	m_isMovable		= false;

	this->loadSprite();

	this->m_Bounding = new CBox2D (this->getBounding());
	return true;
}

bool CEnemyTankRed::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(L"Resource//Image//Game//Sprites//Others//rock.png"));

	return true;
}

void CEnemyTankRed::updateEntity(float deltaTime)
{

}

void CEnemyTankRed::updateEntity(CKeyBoard* device)
{

}

void CEnemyTankRed::drawEntity()
{
	m_listSprite.at(0)->Render(m_Position, vector2d(1.0f, 1.0f), 0.0f, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
}