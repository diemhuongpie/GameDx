#ifndef __ENEMY_EYE_RED_H__
#define __ENEMY_EYE_RED_H__
#include "Game\Entity\MovableEntity.h"
#include "Framework\Camera.h"

class CEnemyEyeRed : public CMovable
{
public:
	CEnemyEyeRed();
	CEnemyEyeRed(vector3d m_position_p, bool m_Horizontal,bool m_isleft, bool m_istop);
	~CEnemyEyeRed();
	bool initEntity();
	void updateEntity(CKeyBoard* keyboard);
	void updateEntity(CBaseEntity*);
	void updateEntity( float deltaTime);
	void updateEntity(RECT rectCamera);
	void drawEntity();
	void resetObject();
	bool loadSprite();
private:
	bool m_horizontal;
	bool m_isTop;
	bool m_isLeft;
	int m_checkState;
	int	 m_delayTime;
	vector3d old_pos;
};

#endif