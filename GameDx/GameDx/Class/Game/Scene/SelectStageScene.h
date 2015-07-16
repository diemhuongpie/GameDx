#ifndef	__SELECTSTAGESCENE_H__
#define	__SELECTSTAGESCENE_H__

#include "Framework\Sprite.h"
#include "Framework\Text.h"
#include "BaseScene.h"
#include "Game\Utill\InformationResource.h"
#include "Framework\Camera.h"

class CSelectStageScene :
	public CBaseScene
{
public:
	CSelectStageScene();
	CSelectStageScene(LPDIRECT3DDEVICE9);
	~CSelectStageScene();

	virtual bool initScene(LPDIRECT3DDEVICE9)		override;
	virtual void updateScene()						override;
	virtual void renderScene()						override;

private:
	CSprite*				m_Background;
	CSprite*				m_ButtonMenuSelectStage;
	//vector<CText*>			m_Text;
};

#endif

