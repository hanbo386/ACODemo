#include "StdAfx.h"
#include "Environment.h"

CEnvironment::CEnvironment(void)
{
}

CEnvironment::~CEnvironment(void)
{
}

void CEnvironment::InitData()
{
	for(int i = 0; i < MAZE_WIDTH; i++)
	{
		for(int j = 0; j < MAZE_HEIGHT; j++)
		{
			//Trial[i][j].FoodToHome = 0;
			//Trial[i][j].HomeToFood = 0;
		}
	}
}

