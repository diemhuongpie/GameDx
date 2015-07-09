/****************************************************************************/
/* Create by Michael Le*/
/* 07/07/2015 */
/***************************************************************************/

#ifndef __TIMER_H__
#define __TIMER_H__

#include <time.h>

class CTimer
{
public:
	~CTimer();
	
	static CTimer*	getInstance();
	void			setTime(clock_t newTime);
	clock_t			getTime();

private:
	clock_t	m_Time;

private:
	static	CTimer*	m_Instance;
	CTimer();
};

#endif

