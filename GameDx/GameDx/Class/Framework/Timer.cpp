#include "Framework\Timer.h"
#include "Game\Utill\Config.h"
CTimer* CTimer::m_Instance = NULL;

CTimer::CTimer()
{
	m_Time = 0;
}


CTimer::~CTimer()
{
	SAFE_RELEASE(m_Instance);
}

CTimer*	CTimer::getInstance()
{
	if (!m_Instance)
		m_Instance = new CTimer();
	return m_Instance;
}

void	CTimer::setTime(clock_t newTime)
{
	m_Time = newTime;
}

clock_t	CTimer::getTime()
{
	return m_Time;
}