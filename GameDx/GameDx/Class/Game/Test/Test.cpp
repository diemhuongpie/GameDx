#include "Test.h"
#include "Framework\Camera.h"
#include "Framework\Timer.h"

Test::Test(LPDIRECT3DDEVICE9 device)
{
	m_SpriteTest	= new CSprite(L"Resource//Test//BOX_OPENED.png", 1, 3, 3, 0);
	m_position		= D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Text			= new CText(device, 24, (char)"Font//megaman.ttf");

	RECT rect		= {	
						m_position.x,
						m_position.y,
						m_position.x + (m_SpriteTest->getScrRect().right - m_SpriteTest->getScrRect().left),
						m_position.y + (m_SpriteTest->getScrRect().top - m_SpriteTest->getScrRect().bottom)
					  };

	m_Bounding		= new CBox2D(device, rect, vector2dZero);
}


Test::~Test()
{
	SAFE_RELEASE(m_SpriteTest);
	SAFE_RELEASE(m_Text);
	SAFE_RELEASE(m_Bounding);
}

void Test::Update(CKeyBoard* device)
{

	if (device->KeyDown(DIK_RIGHT))
		this->m_position.x += 5;

	if (device->KeyDown(DIK_LEFT))
		this->m_position.x -= 5;

	if (device->KeyDown(DIK_UP))
		this->m_position.y += 5;

	if (device->KeyDown(DIK_DOWN))

		this->m_position.y -= 5;



	m_Bounding->update(CTimer::getInstance()->getTime(), vector2d(m_position.x, m_position.y));

}

void Test::Render()
{
	m_Bounding->render();
	m_Text->Draw(L".", { CCamera::setPositionEntity(m_position).x, CCamera::setPositionEntity(m_position).y, CCamera::setPositionEntity(m_position).x + 30, CCamera::setPositionEntity(m_position).y + 30 }, 1, D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));
	m_SpriteTest->Render(CCamera::setPositionEntity(m_position), vector2d(1.0f, 1.0f), 0.0f, DRAWCENTER_LEFT_TOP);
}

D3DXVECTOR3 Test::getPosision()
{
	return m_position;
}
