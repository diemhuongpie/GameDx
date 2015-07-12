#include "Test.h"


Test::Test(LPDIRECT3DDEVICE9 device)
{
	m_SpriteTest	= new CSprite(L"Resource//Test//BOX_OPENED.png", 1, 3, 3, 0);
	m_position		= D3DXVECTOR3(100.0f, 100.0f, 0.0f);
	m_Text			= new CText(device, 24, (char)"Font//megaman.ttf");
}


Test::~Test()
{
	if (m_SpriteTest)
		delete m_SpriteTest;
}

void Test::Update(CKeyBoard* device)
{

	if (device->KeyDown(DIK_SPACE))
	{
		this->m_position.x += 5;

		OutputDebugString(L"Yes");
		OutputDebugString(L"\n");
	}
}

void Test::Render()
{
	m_SpriteTest->Render(m_position);
	m_Text->Draw(L"OiShiMMMM", { 100, 100, 300, 200 }, 1, D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));
}
