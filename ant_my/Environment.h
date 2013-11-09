#pragma once
#include "StdAfx.h"
#include "Common.h"


class CEnvironment
{
public:
	CEnvironment(void);
	~CEnvironment(void);

public:
	//int Trial[MAZE_WIDTH][MAZE_HEIGHT];
	//char mazedata[MAZE_WIDTH][MAZE_HEIGHT];
public:
	void InitData();
	void Search();
	void UpdataTrial();
	//static void DisplayMaze(void);
};