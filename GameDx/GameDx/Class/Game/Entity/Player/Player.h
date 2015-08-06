///*********************************************************/
///* Create by Michael Le*/
///* 08/07/2015 */
///*********************************************************/
//
//#include "Game\Entity\MovableEntity.h"
//#include "Framework\Camera.h"
//
//#ifndef __CPLAYER_H__
//#define __CPLEYER_H__
//
//
//class CPlayer : public CMovable
//{
//public:
//	CPlayer();
//	CPlayer(LPDIRECT3DDEVICE9);
//	~CPlayer();
//
//	virtual bool initEntity()											override;
//	virtual void updateEntity(float deltaTime)							override;
//	virtual void updateEntity(CKeyBoard *device)						override;
//	virtual void drawEntity()											override;
//	
//	virtual bool loadSprite()											override;
//	void controlPlayer(CKeyBoard* device, float deltaTime);
//
//protected:
//	
//	vector2d	m_Acceleration;
//	bool		m_isJUMP;
//	bool		m_isLEFT;
//	bool		m_isSTART;
//	bool		m_isDEAD;
//	bool		m_isCLIMB;
//	bool		m_isCOL;
//private:
//
//};
//
//#endif
