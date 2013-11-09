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
	flag = 1;									//����ʼʱ������λ�ڳ�Ѩλ��

	for(int i = 1; i < MAZE_WIDTH; i++)			//��¼�����߹���·����0��ʾ�߹���1��ʾδ�߹�
	{
		for(int j = 1; j < MAZE_HEIGHT; j++)
		{
			mazepath[i][j] = 1;
		}
	}
	mazepath[1][1] = 0;
	
	while(!path_x.empty())						//��ʼ��ʱ��Ҫ��·��ջ���
	{
		path_x.pop();
		path_y.pop();
	}

	path_x.push(x);								//�����ϵ���ʼλ����ջ
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

	//ȱ��Ѩ��ʳ���ǵĳ�ʼ��
	
	/*y_m = ((xAnt+1)/MAZE_EACH*2 - 1)/2;		//��������ϵ�����꣬����������Ǻ������෴��
	x_m = ((1-yAnt)/MAZE_EACH*2 - 1)/2;
	x = int(x_m + 0.1);							//�˴�ǿ������ת��ִ�е�������ת������Ҫ���һ������
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
	
	if(temp)							//�����Լ���ǰ��ʱ
	{
		path_x.push(x_temp);
		path_y.push(y_temp);			//�Ѹռ�������λ��ѹ��ջ

		move_path_x.push(x_temp);
		move_path_y.push(y_temp);

		mazepath[x_temp][y_temp] = 0;	//����һλ�ü�¼Ϊ���߹�
		if(flag == 1)
			Trial[x_temp][y_temp].FoodToHome++;		//������Ϣ��
		else
			Trial[x_temp][y_temp].HomeToFood++;
		//cout<<" "<<Trial[2][1].FoodToHome;
			
		if(mazedata[x_temp][y_temp] == 'F' || mazedata[x_temp][y_temp] == 'N')				//��Ҫ�ƶ���ʳ�����ڻ����ƶ�����Ѩ
		{
			flag = 1;
			AntInit();																		//
		}
		else
			flag = 0;
	}
	else												//��·��ͨ���򷵻���һλ��
	{

		path_x.pop();
		path_y.pop();									//����ǰλ�õ���ջ

		if(!path_x.empty())
		{
			x_temp = path_x.top();
			y_temp = path_y.top();						//��ȡǰһλ��

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
	
	//1.����ĸ������Ƿ����ϰ���
	//2.����ĸ��������Ϣ��
	//3.ѡ��Ϊ�߹������ϰ�������Ϣ�����ķ��򣬲�������Ϣ��
	//4.����·�����򷵻���һ��λ�ã��ظ�����1-4
	//display();
	//Sleep(200);
}
