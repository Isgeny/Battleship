#include "freeglut.h"
#include <time.h>
#include "GameManager.h"

GameManager game;


void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	game.draw();
	glutSwapBuffers();
}

void mousePressed(int button, int state, int x, int y)
{
	game.mousePressed(button, state, x, y);
}

void mouseMove(int x, int y)
{
	game.mouseMove(x, y);
}

void mouseWheel(int button, int dir, int x, int y)
{
	game.mouseWheel(button, dir, x, y);
}

void timerRedisplay(int)
{
	glutPostRedisplay();
	glutTimerFunc(50, timerRedisplay, 0);
}

void timerCompStep(int)
{
	game.makeCompStep();
	glutTimerFunc(1500, timerCompStep, 0);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(550, 300);
	glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
	glutCreateWindow("Battleship");
	srand(time(NULL));

	glClearColor(0.95, 0.95, 0.95, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, WIN_WIDTH, WIN_HEIGHT, 0);
	glMatrixMode(GL_MODELVIEW);

	glutDisplayFunc(display);
	glutMouseFunc(mousePressed);
	glutPassiveMotionFunc(mouseMove);
	glutMouseWheelFunc(mouseWheel);
	glutTimerFunc(50, timerRedisplay, 0);
	glutTimerFunc(1500, timerCompStep, 0);
	glutMainLoop();
	return 0;
}