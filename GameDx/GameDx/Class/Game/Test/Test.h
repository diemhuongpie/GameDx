#ifndef __TEST_H__
#define __TEST_H__

#include "Game\Utill\stdafx.h"
#include "Framework\Sprite.h"
#include "Framework\KeyBoard.h"
#include "Framework\Text.h"
#include "Mathematics\Box2D.h"
#include "Game\Entity\MovableEntity.h"
#include "Game\Entity\StaticEntity.h"

class Test
{
public:
	Test(LPDIRECT3DDEVICE9);
	~Test();
	D3DXVECTOR3	getPosision();

	void	Update(CKeyBoard* device);
	void	Render();

private:
	CSprite*	m_SpriteTest;
	D3DXVECTOR3	m_position;
	CText*		m_Text;
	CBox2D*		m_Bounding;
	CMovable*	MovableObject;

	CSprite*		m_StaticSprite;
	CStaticEntity*	m_StaticObject;
	D3DXVECTOR3		m_positionStatic;
};

#endif
