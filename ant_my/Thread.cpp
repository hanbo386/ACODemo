#include "StdAfx.h"
#include "Thread.h"

void ThreadCall::Fun(void *data)
{
	ThreadInfo *info = (ThreadInfo *)data;
	return info->threadClass->operator ()(info->data);
}

