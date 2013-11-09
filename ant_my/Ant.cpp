#include "StdAfx.h"
#include "Ant.h"

struct Trial_type
{
	int HomeToFood;
	int FoodToHome;
};
static Trial_type Trial[MAZE_WIDTH][MAZE_HEIGHT];

CAnt::CAnt(void)
{
	
}

CAnt::~CAnt(void)
{

}

void CAnt::Init(void)
{
	x_temp = 1;
	y_temp = 1;
}


void CAnt::AntInit(void)
{
	x = x_temp;
	y = y_temp;
	flag = 1;									//程序开始时，蚂蚁位于巢穴位置

	for(int i = 1; i < MAZE_WIDTH; i++)			//记录蚂蚁走过的路径，0表示走过，1表示未走过
	{
		for(int j = 1; j < MAZE_HEIGHT; j++)
		{
			mazepath[i][j] = 1;
		}
	}
	mazepath[1][1] = 0;
	
	while(!path_x.empty())						//初始化时需要将路径栈清空
	{
		path_x.pop();
		path_y.pop();
	}

	path_x.push(x);								//将蚂蚁的起始位置入栈
	path_y.push(y);

	move_path_x.push(x);
	move_path_y.push(y);
}

void CAnt::AntSearchPath(int i, int flag)
{
	temp = 0;
	trial_temp = 0;
	x_temp = 0;
	y_temp = 0;

	//缺巢穴和食物标记的初始化
	
	/*y_m = ((xAnt+1)/MAZE_EACH*2 - 1)/2;		//蚂蚁坐标系的坐标，与矩阵坐标是横纵是相反的
	x_m = ((1-yAnt)/MAZE_EACH*2 - 1)/2;
	x = int(x_m + 0.1);							//此处强制类型转换执行的是下行转换，需要添加一个增量
	y = int(y_m + 0.1);*/
	switch(flag)
	{
	case 1:
		if((mazedata[x][y+1] != 'H') && (mazepath[x][y+1] != 0))
		{
			if(Trial[x][y+1].HomeToFood >= trial_temp)
				{
					trial_temp = Trial[x][y+1].HomeToFood;
					x_temp = x;
					y_temp = y+1;
				}
				temp++;
				if(temp)
				{
					int n;
					n = 1 + rand()%(100+i);
					if(n < ERROR)
						return;
				}
		}
		if(mazedata[x+1][y] != 'H' && mazepath[x+1][y] != 0)
		{
			if(Trial[x+1][y].HomeToFood >= trial_temp)
				{
					trial_temp = Trial[x+1][y].HomeToFood;
					x_temp = x+1;
					y_temp = y;
				}
				temp++;
				if(temp)
				{
					int n;
					n = 1 + rand()%(10+i);
					if(n < ERROR)
						return;
				}
		}
		if(mazedata[x][y-1] != 'H' && mazepath[x][y-1] != 0)
		{
			if(Trial[x][y-1].HomeToFood >= trial_temp)
				{
					trial_temp = Trial[x][y-1].HomeToFood;
					x_temp = x;
					y_temp = y-1;
				}
				temp++;
				if(temp)
				{
					int n;
					n = 1 + rand()%(100+i);
					if(n < ERROR)
						return;
				}
		}
		if(mazedata[x-1][y] != 'H' && mazepath[x-1][y] != 0)
		{
			if(Trial[x-1][y].HomeToFood >= trial_temp)
				{
					trial_temp = Trial[x-1][y].HomeToFood;
					x_temp = x-1;
					y_temp = y;
				}
				temp++;
				if(temp)
				{
					int n;
					n = 1 + rand()%(100+i);
					if(n < ERROR)
						return;
				}
		}
		break;
	case 0:
		if((mazedata[x][y+1] != 'H') && (mazepath[x][y+1] != 0))
		{
			if(Trial[x][y+1].FoodToHome >= trial_temp)
				{
					trial_temp = Trial[x][y+1].FoodToHome;
					x_temp = x;
					y_temp = y+1;
				}
				temp++;
				if(temp)
				{
					int n;
					n = 1 + rand()%(100+i);
					if(n < ERROR)
						return;
				}
		}
		if(mazedata[x+1][y] != 'H' && mazepath[x+1][y] != 0)
		{
			if(Trial[x+1][y].FoodToHome >= trial_temp)
				{
					trial_temp = Trial[x+1][y].FoodToHome;
					x_temp = x+1;
					y_temp = y;
				}
				temp++;
				if(temp)
				{
					int n;
					n = 1 + rand()%(100+i);
					if(n < ERROR)
						return;
				}
		}
		if(mazedata[x][y-1] != 'H' && mazepath[x][y-1] != 0)
		{
			if(Trial[x][y-1].FoodToHome >= trial_temp)
				{
					trial_temp = Trial[x][y-1].FoodToHome;
					x_temp = x;
					y_temp = y-1;
				}
				temp++;
				if(temp)
				{
					int n;
					n = 1 + rand()%(100+i);
					if(n < ERROR)
						return;
				}
		}
		if(mazedata[x-1][y] != 'H' && mazepath[x-1][y] != 0)
		{
			if(Trial[x-1][y].FoodToHome >= trial_temp)
				{
					trial_temp = Trial[x-1][y].FoodToHome;
					x_temp = x-1;
					y_temp = y;
				}
				temp++;
				if(temp)
				{
					int n;
					n = 1 + rand()%(100+i);
					if(n < ERROR)
						return;
				}
		}
		break;

	}
	
}

void CAnt::AntMove(int flag)
{
	
	if(temp)							//当可以继续前进时
	{
		path_x.push(x_temp);
		path_y.push(y_temp);			//把刚即将过的位置压入栈

		move_path_x.push(x_temp);
		move_path_y.push(y_temp);

		mazepath[x_temp][y_temp] = 0;	//将下一位置记录为已走过
		if(flag == 1)
			Trial[x_temp][y_temp].FoodToHome++;		//留下信息素
		else
			Trial[x_temp][y_temp].HomeToFood++;
		//cout<<" "<<Trial[2][1].FoodToHome;
			
		if(mazedata[x_temp][y_temp] == 'F' || mazedata[x_temp][y_temp] == 'N')				//将要移动至食物所在或是移动至巢穴
		{
			flag = 1;
			AntInit();																		//
		}
		else
			flag = 0;
	}
	else												//此路不通，则返回上一位置
	{

		path_x.pop();
		path_y.pop();									//将当前位置弹出栈

		if(!path_x.empty())
		{
			x_temp = path_x.top();
			y_temp = path_y.top();						//读取前一位置

			move_path_x.push(x_temp);
			move_path_y.push(y_temp);
			
		}
		else
		{
			Init();
			AntInit();
		}
	}

	x = x_temp;
	y = y_temp;
	
	//1.检查四个方向是否有障碍物
	//2.检查四个方向的信息素
	//3.选择为走过的无障碍物且信息量最多的方向，并留下信息素
	//4.若无路可走则返回上一个位置，重复步骤1-4
	//display();
	//Sleep(200);
}
