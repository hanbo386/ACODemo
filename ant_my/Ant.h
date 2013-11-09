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
public:									//��Ա��������
	
	int mazepath[MAZE_WIDTH][MAZE_HEIGHT];

	//extern Trial_type Trial[MAZE_WIDTH][MAZE_HEIGHT];
	//static GLfloat xAnt = -0.85f;
	//static GLfloat yAnt = 0.85f;

	int flag;						//��λ��־�����ҵ�ʳ����߳�Ѩ������״̬��λ
	stack<int> path_x;
	stack<int> path_y;

	int x;							//��Ӧ���������
	int y;
	float x_m;						//���ڱ�������任�в����ķ�����
	float y_m;
	int temp;
	int trial_temp;
	int x_temp;
	int y_temp;

public:

	void Init(void);
	void AntInit(void);					//ÿֻ����״̬�ĳ�ʼ��
	void AntSearchPath(int,int);			//����ÿ���ƶ�ǰ������ѡ���ƶ�Ŀ��
	void AntMove(int);					//���ϸ���Ŀ���ѡ���������ƶ�

public:
	queue<int> move_path_x;
	queue<int> move_path_y;

};