#include "Sprite.h"

LPD3DXSPRITE		CSprite::m_spriteHandler	= NULL;
LPDIRECT3DDEVICE9	CSprite::m_d3dDevice	= 0;
vector<CSprite*>	CSprite::m_LoadedSprite;


CSprite::CSprite(wstring filePath, int nRows, int nColumns, int nFrame, int Index)
{
	this->m_Image					= NULL;
	this->m_nColumns				= nColumns;
	this->m_nRow					= nRows;
	this->m_nFrames					= nFrame;
	this->m_Index					= Index;
	this->m_drawTime				= 0;

	HRESULT hr;
	hr = D3DXGetImageInfoFromFile(filePath.c_str(), &this->m_Info);
	if (hr != D3D_OK)	
		return;

	hr = D3DXCreateTextureFromFileEx(
										m_d3dDevice,
										filePath.c_str(),
										m_Info.Width,
										m_Info.Height,
										1,
										D3DUSAGE_DYNAMIC,
										D3DFMT_UNKNOWN,
										D3DPOOL_DEFAULT,
										D3DX_DEFAULT,
										D3DX_DEFAULT,
										D3DCOLOR_XRGB(0, 63, 63),
										&m_Info,
										NULL,
										&m_Image
									);
	if (hr != D3D_OK)		
		return;

	this->m_FrameInfo.Width		= (int)((float)this->m_Info.Width  / (float)this->m_nColumns);
	this->m_FrameInfo.Height	= (int)((float)this->m_Info.Height / (float)this->m_nRow);
	this->m_isCompleted = false;
	this->m_drawTime = 0;

}

CSprite::~CSprite()
{
}

bool		CSprite::Render(D3DXVECTOR3 position, D3DXVECTOR2 scale, float rotate, int drawcenter, bool isLoop)
{
	RECT rec;
	rec = getScrRect();

	D3DXVECTOR3 center = this->setCenter(drawcenter);

	position.x = (int)position.x;
	position.y = (int)position.y;
	position.z = (int)position.z;

	//D3DXMatrixTranslation(&m_TranslationMatrix, 0.0f, (530.0f), 0.0f);
	//
	//D3DXMatrixRotationX(&m_RotationMatrix, D3DXToRadian(-180));

	//D3DXMatrixMultiply(&m_TranformMatrix, &m_RotationMatrix, &m_TranslationMatrix);

	////D3DXMatrixTranslation(&m_TranformMatrix, 0.0f, (m_FrameInfo.Height / 2), 0.0f);

	//m_spriteHandler->SetTransform(&m_TranformMatrix);

	m_spriteHandler->Draw(
		m_Image,
		&rec,
		&center,
		&position,
		D3DCOLOR_XRGB(255, 255, 255)
		);


	if (isLoop)
		Next();
	m_isCompleted = isCompleted();
	return m_isCompleted;
}

RECT		CSprite::getScrRect()
{
	RECT rect;
	rect.left		= (UINT)m_FrameInfo.Width  * (m_Index - (int)(m_Index / m_nColumns) * m_nColumns);
	rect.top		= (UINT)m_FrameInfo.Height * (int)(m_Index / m_nColumns);
	rect.right		= rect.left + (UINT)m_FrameInfo.Width;
	rect.bottom		= rect.top + (UINT)m_FrameInfo.Height;
	return rect;
}

D3DXVECTOR3	CSprite::setCenter(int drawcenter)
{
	D3DXVECTOR3 result;
	switch (drawcenter)
	{
	case DRAWCENTER_LEFT_TOP:
		result.x = 0;
		result.y = 0;
		break;
	case DRAWCENTER_LEFT_MIDDLE:
		result.x = 0;
		result.y = this->m_FrameInfo.Height / 2.0f;
		break;
	case DRAWCENTER_LEFT_BOTTOM:
		result.x = 0;
		result.y = 0;
		break;
	case DRAWCENTER_MIDDLE_TOP:
		result.x = this->m_FrameInfo.Width / 2.0f;
		result.y = 0;
		break;
	case DRAWCENTER_MIDDLE_MIDDLE:
		result.x = this->m_FrameInfo.Width / 2.0f;
		result.y = this->m_FrameInfo.Height / 2.0f;
		break;
	case DRAWCENTER_MIDDLE_BOTTOM:
		result.x = this->m_FrameInfo.Width / 2.0f;
		result.y = this->m_FrameInfo.Height;
		break;
	case DRAWCENTER_RIGHT_TOP:
		result.x = this->m_FrameInfo.Width;
		result.y = 0;
		break;
	case DRAWCENTER_RIGHT_MIDDLE:
		result.x = this->m_FrameInfo.Width;
		result.y = this->m_FrameInfo.Height / 2.0f;
		break;
	case DRAWCENTER_RIGHT_BOTTOM:
		result.x = this->m_FrameInfo.Width;
		result.y = this->m_FrameInfo.Height;
		break;
	default:
		break;
	}
	result.z = 0;
	return result;
}

void		CSprite::Next() 
{
	m_Index++;
}

void		CSprite::Reset() 
{
	m_Index = 0;
	m_isCompleted = false;
}

int			CSprite::getIndex()
{
	return m_Index;
}

bool		CSprite::isCompleted() 
{
	if (m_Index == m_nColumns*m_nRow) {
		Reset();
		return true;
	}
	return false;
}

void		CSprite::initSpriteHandler(LPD3DXSPRITE spriteHandler)
{
	m_spriteHandler = spriteHandler;
	m_spriteHandler->GetDevice(&m_d3dDevice);
}