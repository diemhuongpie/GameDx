#include "Sprite.h"

LPD3DXSPRITE		CSprite::m_spriteHandler	= NULL;
LPDIRECT3DDEVICE9	CSprite::m_d3dDevice		= 0;
vector<CSprite*>	CSprite::m_LoadedSprite;


CSprite::CSprite(wstring filePath, int nRows, int nColumns, int nFrame, int Index)
{
	this->m_Image					= NULL;
	this->m_nColumns				= nColumns;
	this->m_nRow					= nRows;
	this->m_nFrames					= nFrame;
	this->m_Index					= Index;
	this->m_ElapedTime				= 0.0;
	
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

}

CSprite::~CSprite()
{
	if (this->m_LoadedSprite.empty())
	{
		m_LoadedSprite.clear();
		m_LoadedSprite.~vector();
	}
}

bool		CSprite::Render(D3DXVECTOR3 position, D3DXVECTOR2 scale, float rotate, int drawcenter, bool isLoop, float FPSs)
{
	// lấy kích thước của 1 frame (frame là 1 bức ảnh nhỏ trong sprite, sprite là 1 bức ảnh gồm nhiều bức ảnh nhỏ, mô tả trạng thái của nhân vật)
	RECT rec;
	rec				= getScrRect();
	m_isCompleted	= false;

	// xét tâm vẽ
	D3DXVECTOR3 center = this->setCenter(drawcenter);

	// xét tọa độ
	position.x = (int)position.x;
	position.y = (int)position.y;
	position.z = (int)position.z;

	// xét transform, gồm xoay, lật, thu nhỏ, phóng to...
	m_spriteHandler->GetTransform(&m_CurrentMatrix);
	D3DXMatrixTransformation2D(&m_TransformMatrix, &(D3DXVECTOR2)position, 0, &scale, &(D3DXVECTOR2)position, D3DXToRadian(rotate), NULL);
	D3DXMatrixMultiply(&m_MultyMatrix, &m_TransformMatrix, &m_CurrentMatrix);
	m_spriteHandler->SetTransform(&m_MultyMatrix);

	// vẽ sprite lên màn hình
	m_spriteHandler->Draw(
		m_Image,
		&rec,
		&center,
		&position,
		D3DCOLOR_XRGB(255, 255, 255)
		);

	m_spriteHandler->SetTransform(&m_CurrentMatrix);

	OutputDebugString(L"FPSs: ");
	OutputDebugString(_itow((1000.0 / m_ElapedTime), new WCHAR[1], 10));
	OutputDebugString(L"\n");

	// xét FPSs (FPS of Sprite). FPS được tính bằng số frame được vẽ lên màn hình trên 1 giây (1000 millisecon)
	// vì vậy nếu thời gian vẽ của Game (thời gian của 1 vòng lặp update hoặc render) nhỏ hơn thời gian mình muốn.
	// thì mình phải sleep. Tuy nhiên nếu sleep thì nó bị giật, nên tốt nhất là vẽ lại frame đó. Nghĩa là index giữ nguyên.
	// Nếu mà thời gian vẽ đạt được rồi, nghĩa là đủ thời gian để vẽ thì gọi hàm Next để tăng index. và gán lại elapedTime.
	if (double(FPSs)*m_ElapedTime >= 1000.0f)
	{
		Next();
		m_ElapedTime	= 0.0;
		this->m_isLoop	= isLoop;

		// xét xem đã vẽ xong hành động chưa. Nếu hành động được lặp lại. thì đưa index về 0; nếu ko thì vẽ frame cuối cùng ra ( nghĩa là ko bị lặp lại)
		m_isCompleted	= isCompleted();	
	}

	// special thing. stupid code
	if (CTimer::getInstance()->getElapedTime() < 0)
		return false;

	// trường hợp nếu thời gian vẽ thực tế nhỏ hơn thời gian cài đặt thì bỏ qua việc tăng index. và cộng thời gian của lần lặp này.
	m_ElapedTime		+= CTimer::getInstance()->getElapedTime();

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
		result.y = this->m_FrameInfo.Height;
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
	if (m_Index >= m_nColumns*m_nRow)
	{
		if (this->m_isLoop)
			Reset();
		else
			m_Index = m_nColumns*m_nRow;
		return true;
	}
	return false;
}

void		CSprite::initSpriteHandler(LPD3DXSPRITE spriteHandler)
{
	m_spriteHandler = spriteHandler;
	m_spriteHandler->GetDevice(&m_d3dDevice);
}