#include "freeglut.h"
#include "Button.h"
#include "GameManager.h"
#include <vector>

std::vector<Button> bVec = {Button(300, 60,  240, 60, "New game"),
							Button(300, 150, 240, 60, "Records"), 
							Button(300, 240, 240, 60, "About"),
							Button(300, 330, 240, 60, "Exit")};
GameManager game;

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

	game.drawCells();
	game.drawGameTitle();
	for(int i = 0; i < bVec.size(); i++)
		bVec.at(i).draw();

	glutSwapBuffers();
}

void mousePressed(int button, int state, int x, int y)
{

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
	glutMouseFunc(mousePressed);
	glutMainLoop();
	return 0;
}