#include "freeglut.h"
#include <time.h>
#include "GameManager.h"

int main(int argc, char** argv)
{
	GameManager game;
	srand(time(NULL));
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
	
	glutDisplayFunc(GameManager::draw);
	glutReshapeFunc(GameManager::resize);
	glutMouseFunc(GameManager::mouseClicked);
	glutPassiveMotionFunc(GameManager::mouseMove);
	glutMouseWheelFunc(GameManager::mouseWheel);
	glutKeyboardFunc(GameManager::keyboardPressed);
	glutTimerFunc(50, GameManager::timerRedisplay, 0);
	glutTimerFunc(50, GameManager::timerCompStep, 0);
	glutTimerFunc(750, GameManager::timerTextEditCarriage, 0);

	glutMainLoop();
	return 0;
}