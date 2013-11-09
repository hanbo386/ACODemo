#include "StdAfx.h"
#include "Common.h"
#include "Ant.h"
#include "AntDisplay.h"
#include "Environment.h"
#include "Display.h"
#include <windows.h>
#include <pthread.h>
#include <string>
#include <GL/glut.h>
#include <GL/glaux.h>



void Mouse(int button, int state, int x, int y)
{
	 switch (button) 
	 {
		case GLUT_LEFT_BUTTON:
			if (state == GLUT_DOWN)
			{	
				Thread();
				for(int i = 0; i < MAZE_WIDTH; i++)
				{
					for(int j = 0; j < MAZE_HEIGHT; j++)
					{
						//cout<<Trial[i][j].FoodToHome<<" ";
					}
				}
				glutIdleFunc(&DisplayMove);
				//pthread_t thread_a,thread_b;

				//pthread_create(&thread_a, NULL, fun, (void *)0);
				//pthread_create(&thread_b, NULL, fun, (void *)1);

				//pthread_join(thread_a, (void **)0);
				//pthread_join(thread_b, (void **)0);
				

			}

		break;

		case GLUT_RIGHT_BUTTON:
			if (state == GLUT_DOWN)
				glutIdleFunc(NULL);
		break;

		default:
		break;
	 }
}

int main(int argc, char *argv[])
{
	//CEnvironment Maze;
	
	/*HWND hWnd = NULL;
	HINSTANCE hlnst = NULL;
	HDC hDC = NULL;
	HGLRC hRC = NULL;

	wglMakeCurrent(NULL,NULL);*/
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(440, 0);
	glutInitWindowSize(1000, 800);
	glutCreateWindow("ÒÏÈºËã·¨ÑÝÊ¾");

	glutDisplayFunc(&DisplayMaze);
	CEnvironment maze;
	maze.InitData();
	glutMouseFunc(&Mouse);

	
	//glutIdleFunc(&fun);
	//typedef void (CAntDisplay::*pFun)(int,int,int,int);
	//pFun p = &CAntDisplay::Mouse;
	glutMainLoop();

	
	return 0;

}