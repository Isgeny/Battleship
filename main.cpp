#include "freeglut.h"
#include "Button.h"
#include<vector>
#define WIN_WIDTH 871
#define WIN_HEIGHT 421
#define CELL_SIZE 30

std::vector<Button> bVec = {Button(300, 60,  240, 60, "New game"),
							Button(300, 150, 240, 60, "Records"), 
							Button(300, 240, 240, 60, "About"),
							Button(300, 330, 240, 60, "Exit")};

void initialize()
{
	glClearColor(0.95, 0.95, 0.95, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, WIN_WIDTH, WIN_HEIGHT, 0);
	glMatrixMode(GL_MODELVIEW);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	//Отрисовка клеточек
	glLineWidth(2.0);
	glBegin(GL_LINES);	
	glColor3d(0.5, 0.75, 0.95);
	for(int i = 0; i <= 29; i++)
	{
		glVertex2d(CELL_SIZE*i + 1, 0);
		glVertex2d(CELL_SIZE*i + 1, WIN_HEIGHT);
	}
	for(int i = 0; i <= 14; i++)
	{
		glVertex2d(0, CELL_SIZE*i + 1);
		glVertex2d(WIN_WIDTH, CELL_SIZE*i + 1);
	}
	glEnd();

	//Отрисовка кнопок
	for(int i = 0; i < bVec.size(); i++)
		bVec.at(i).draw();

	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(550, 300);
	glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
	glutCreateWindow("Battleship");
	initialize();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}