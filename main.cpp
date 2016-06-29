#include "freeglut.h"
#define WIN_WIDTH 840
#define WIN_HEIGHT 390

void initialize()
{
	glClearColor(0.95, 0.95, 0.95, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, WIN_WIDTH, WIN_HEIGHT, 0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);

	glEnd();
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