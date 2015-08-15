#ifndef	__SELECTSTAGESCENE_H__
#define	__SELECTSTAGESCENE_H__

#include "Framework\Sprite.h"
#include "Framework\Text.h"
#include "Framework\Camera.h"
#include "Framework\KeyBoard.h"
#include "Game\Scene\BaseScene.h"
#include "Game\Utill\InformationResource.h"
#include "Game\Utill\Config.h"

class CSelectStageScene :
	public CBaseScene
{
public:
	CSelectStageScene();
	~CSelectStageScene();

	virtual bool			initScene()							override;
	virtual void			updateScene(double deltaTime)		override;
	virtual void			updateScene(CKeyBoard*)				override;
	virtual void			renderScene()						override;

	static int				m_IndexSelect;

private:
	CSprite*				m_Background;
	CSprite*				m_ButtonMenuSelectStage;
	vector3d				m_PositionButton;
	bool					m_enterTheGame;
	bool					m_Particle;
};

#endif

