#pragma once
#include "Common.h"
#include <iostream>
#include <stack>
#include <queue>
#include <GL/glut.h>
using namespace std;

class CAnt
{
public:
	CAnt(void);
	~CAnt(void);

public:
	friend class CAntDisplay;
public:									//成员变量待定
	
	int mazepath[MAZE_WIDTH][MAZE_HEIGHT];

	//extern Trial_type Trial[MAZE_WIDTH][MAZE_HEIGHT];
	//static GLfloat xAnt = -0.85f;
	//static GLfloat yAnt = 0.85f;

	int flag;						//复位标志，当找到食物或者巢穴后将蚂蚁状态复位
	stack<int> path_x;
	stack<int> path_y;

	int x;							//对应矩阵的坐标
	int y;
	float x_m;						//用于保存坐标变换中产生的非整数
	float y_m;
	int temp;
	int trial_temp;
	int x_temp;
	int y_temp;

public:

	void Init(void);
	void AntInit(void);					//每只蚂蚁状态的初始化
	void AntSearchPath(int,int);			//蚂蚁每次移动前搜索并选择移动目标
	void AntMove(int);					//蚂蚁根据目标的选择结果进行移动

public:
	queue<int> move_path_x;
	queue<int> move_path_y;

};