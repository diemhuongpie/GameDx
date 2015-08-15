#ifndef __SINGLETON_H__
#define __SINGLETON_H__

template <class  T> class CSingleton
{
protected:
	static T*		s_Instance;

public:
	CSingleton(){}
	virtual ~CSingleton(){}

	static	T*		getInstance()
	{
		if (!s_Instance)
			s_Instance = new T();
		return s_Instance;
	}

	static	void	release()
	{
		delete	s_Instance;
	};
};

template <class T>
T*	CSingleton<T>::s_Instance = 0;
#endif