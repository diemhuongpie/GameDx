#include "Text.h"


CText::CText(LPDIRECT3DDEVICE9 device, LPD3DXSPRITE& spriteHandle)
{
	m_Device				= device;
	m_SpriteHandle			= spriteHandle;
	m_FontFace				= DEFAULT_FONTNAME;
	m_FontSize				= DEFAULT_FONT_SIZE;

	AddFontResourceEx(DEFAULT_FONTPATH, FR_PRIVATE, 0);

	this->Init();
}

CText::CText(LPDIRECT3DDEVICE9 device, LPD3DXSPRITE& spriteHandle, LPCTSTR fontFace,LPCTSTR fontPath)
{
	m_Device				= device;
	m_SpriteHandle			= spriteHandle;
	m_FontFace				= fontFace;

	AddFontResourceEx(fontPath, FR_PRIVATE, 0);

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
HRESULT hr = D3DXCreateFont(
							m_Device,
							m_FontSize,
							0, 400, 0, false,
							DEFAULT_CHARSET,
							OUT_TT_PRECIS,
							CLIP_DEFAULT_PRECIS,
							DEFAULT_PITCH,
							m_FontFace,
							&m_Font);
	if (FAILED(hr))
		return;
};


template<class T>
void CText::Draw(const T& Content, D3DXVECTOR3 Position, D3DCOLOR Color, int Size, UINT DT_Type)
{
	if (Size != fontSize_)
		setFontSize(Size);

	D3DXVECTOR3 pos(Position);

	RECT drawField;
	drawField = { pos.x, pos.y, 0, 0 };

	font_->DrawText(spriteHandler_, Default::tostr(Content).c_str(),
		-1, &drawField, DT_CALCRECT, Color);

	if (DT_Type == DT_CENTER)
	{
		LONG w				 = drawField.right - drawField.left;
		drawField.left		-= (LONG)(w / 2.0F);
		drawField.right		-= (LONG)(w / 2.0F);
	}
	else if (DT_Type == DT_RIGHT)
	{
		LONG w				 = drawField.right - drawField.left;
		drawField.left		-= w;
		drawField.right		-= w;
	}

	font_->DrawText(spriteHandler_, Default::tostr(Content).c_str(),
		-1, &drawField, DT_Type, Color);
};

void CText::setFontSize(int fontSize)
{
	m_Font->Release();
	m_FontSize = fontSize;
	Init();
}
