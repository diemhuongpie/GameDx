/****************************************************************************/
/* Create by Michael Le*/
/* 08/07/2015 */
/***************************************************************************/

#ifndef __TEXT_H__
#define __TEXT_H__

#include "Game\Utill\stdafx.h"
#include "Game\Utill\Config.h"

class CText
{
public:
	CText(LPDIRECT3DDEVICE9, LPD3DXSPRITE&);
	CText(LPDIRECT3DDEVICE9, LPD3DXSPRITE&, LPCTSTR, LPCTSTR);
	~CText();

	template<class T>
	void Draw(const T& Content, D3DXVECTOR3 Position, D3DCOLOR Color = DEFAULT_FONT_COLOR, int Size = DEFAULT_FONT_SIZE, UINT DT_Type = DT_LEFT);

	void Init();
	void setFontSize(int fontSize);
private:
	LPDIRECT3DDEVICE9	m_Device;
	LPD3DXSPRITE		m_SpriteHandle;
	LPD3DXFONT			m_Font;
	int					m_FontSize;
	LPCTSTR				m_FontFace;
};

#endif

