#include "Text.h"


CText::CText(LPDIRECT3DDEVICE9 device)
{
	m_Device	= device;
	m_FontFace	= (char)"Arial";
	m_FontSize	= 24;
	this->Init();
}

CText::CText(LPDIRECT3DDEVICE9 device, int fontSize, char fontFace)
{
	m_Device	= device;
	m_FontFace	= fontFace;
	m_FontSize	= fontSize;
	this->Init();
}


CText::~CText()
{
	if (m_Font != NULL)
	{
		m_Font->Release();
		m_Font = NULL;
	}
}

void CText::Init()
{

	D3DXFONT_DESC FontDesc = {
								m_FontSize,
								0,
								400,
								0,
								false,
								DEFAULT_CHARSET,
								OUT_TT_PRECIS,
								CLIP_DEFAULT_PRECIS,
								DEFAULT_PITCH,
								m_FontFace
							};
	HRESULT hr = D3DXCreateFontIndirect(m_Device, &FontDesc, &m_Font);
	if (FAILED(hr))
		return;
}

void CText::Draw(wstring text, RECT position, UINT alignment, D3DCOLOR colorText)
{
	m_Font->DrawText(NULL, text.c_str(), -1, &position, alignment, colorText);
}
