#include "freeglut.h"
#include "GameManager.h"

GameManager game;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	switch(game.getGameStatus())
	{
	case MENU:
		game.drawCells();
		game.drawGameTitle();
		game.drawButtons();
		break;
	case PLACING_SHIP:
		game.drawCells();
		game.drawFields();
	}
	
	glutSwapBuffers();
}

void mousePressed(int button, int state, int x, int y)
{
	game.mousePressed(button, state, x, y);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(550, 300);
	glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
	glutCreateWindow("Battleship");

	glClearColor(0.95, 0.95, 0.95, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, WIN_WIDTH, WIN_HEIGHT, 0);
	glMatrixMode(GL_MODELVIEW);

	glutDisplayFunc(display);
	glutMouseFunc(mousePressed);
	glutMainLoop();
	return 0;
}