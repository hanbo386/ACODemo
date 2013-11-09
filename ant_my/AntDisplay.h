#pragma once
#include "StdAfx.h"
#include "Common.h"
#include <queue>
#include "Ant.h"

class CAntDisplay
{
/*public:
	static CAnt ant;*/
public:
	float xAnt;
	float yAnt;
/*public:
	queue<int> x_queue;
	queue<int> y_queue;*/
public:
	int x;
	int y;
	int x_temp;
	int y_temp;
	CAnt ant[2];
public:
	void DisplayInit(void);
	void GetMovePath(int);
	void DisplayAnt(void);
	void DisplayMove(int);
	void Thread(void);
	//static void Mouse(int,int,int,int,CAntDisplay);
};

