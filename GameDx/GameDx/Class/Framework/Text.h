/****************************************************************************/
/* Create by Michael Le*/
/* 08/07/2015 */
/***************************************************************************/

#ifndef __TEXT_H__
#define __TEXT_H__

#include "Game\Utill\stdafx.h"

class CText
{
public:
	CText(LPDIRECT3DDEVICE9);
	CText(LPDIRECT3DDEVICE9, int fontSize, char fontFace);
	~CText();

	void Draw(wstring, RECT, UINT, D3DCOLOR);
	void Init();
	void setFontSize(int fontSize);
	void setFontFace(char fontFace);
private:
	LPDIRECT3DDEVICE9	m_Device;
	LPD3DXFONT			m_Font;
	int					m_FontSize;
	CHAR				m_FontFace;
};

#endif

