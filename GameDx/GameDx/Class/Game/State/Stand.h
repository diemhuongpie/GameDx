#ifndef __CSTAND_H__
#define __CSTAND_H__


#include "State.h"
class CStand :
	public CState
{
public:
	CStand();
	~CStand();
};


class CPlayerStand :
	public CStand
{
public:
	CPlayerStand();
	~CPlayerStand();
};

#endif


