#pragma once
#include <pthread.h>

class ThreadClass						//���еĻص��඼ֱ�ӻ��Ӽ̳��Ը���
{
public:
	virtual void *operator()(void *) = 0;
};


struct _threadInfo
{
	ThreadClass *threadClass;
	void *data;
};
typedef _threadInfo ThreadInfo;


class ThreadCall
{
public:
	static void *Fun(void *data)
	{
		ThreadInfo *info=(ThreadInfo *)data;   
        return info->threadClass->operator ()(info->data); 
	}
};



