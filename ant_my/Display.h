#include "StdAfx.h"
#include "Common.h"
#include "Ant.h"
#include <stdio.h>	
#include <stdlib.h>
#include <pthread.h>
#include <GL/glaux.h>
#include <iostream>
using namespace std;

float xAnt[ANT_AMOUNT], yAnt[ANT_AMOUNT];
int x;
int y;
int x_temp;
int y_temp;
CAnt ant[ANT_AMOUNT];

void DisplayInit(void);
void *GetMovePath(void *);
void DisplayAnt(void);
void DisplayMove(int);
void Thread(void);

void DisplayInit(void)
{
	for(int i = 0; i < ANT_AMOUNT; i++)
	{
		xAnt[i] = -0.85;
		yAnt[i] = 0.85;
	}
}

void *GetMovePath(void *thread)
{
	int thread_seq = (int)thread;
	ant[thread_seq].Init();
	ant[thread_seq].AntInit();
	
	int i = ANT_MOVE;
	while(i)
	{
	
		ant[thread_seq].AntSearchPath(thread_seq,ant[thread_seq].flag);		//蚂蚁探索路径
		ant[thread_seq].AntMove(ant[thread_seq].flag);				//蚂蚁一次移
		i--;
		//cout<<Trial[1][2].FoodToHome<<" ";
	}
	//cout<<Trial[1][2].FoodToHome<<" ";
	pthread_exit((void *)0);
	return 0;
}

void Thread(void)
{
	pthread_t ant[ANT_AMOUNT];

	for(int i = 0; i < ANT_AMOUNT; i++)
	{
		pthread_create(&ant[i], NULL, GetMovePath, (void *)i);
	}
	
	for(int i = 0; i < ANT_AMOUNT; i++)
	{
		pthread_join(ant[i], (void **)0);
	}

}

void DisplayAnt(void)
{
	DisplayMaze();
	glPointSize(3.0);

	for(int i = 0; i < ANT_AMOUNT; i++)
	{
		glBegin(GL_POINTS);
		glColor3f(0.5,0.5,0.5 );
		glVertex2f(xAnt[i],yAnt[i]);
		glEnd();
	}

	glFlush();
}

void DisplayMove(void)
{
	//Thread();
	DisplayAnt();										//迷宫中绘制一次蚂蚁

	//此处缺队列空的判定，暂时不用加，以后补上

	for(int i = 0; i <ANT_AMOUNT; i++)
	{
		if(!ant[i].move_path_x.empty())
		{
			x = ant[i].move_path_x.front();
			y = ant[i].move_path_y.front();

			xAnt[i] = -1 + (2 * y + 1) * MAZE_EACH/2;
			yAnt[i] =  1 - (2 * x + 1) * MAZE_EACH/2;			//根据矩阵坐标计算蚂蚁的坐标

			//cout<<xAnt<<" "<<yAnt<<endl;

			ant[i].move_path_x.pop();
			ant[i].move_path_y.pop();	
		}
		if(!ant[i].move_path_x.empty())
		{
			x_temp = ant[i].move_path_x.front();
			y_temp = ant[i].move_path_y.front();		

			if(y_temp == y+1)				
			{
				xAnt[i] = xAnt[i] + MAZE_EACH;
			}
			else if(y_temp == y-1)
			{
				xAnt[i] = xAnt[i] - MAZE_EACH;
			}
			else if(x_temp == x+1)
			{
				yAnt[i] = yAnt[i] - MAZE_EACH;
			}
			else if(x_temp == x-1)
			{
				yAnt[i] = yAnt[i] + MAZE_EACH;
			}
		}
	}

	//int n;
	//n = 100 + rand()%100;
	Sleep(SPEED);
}