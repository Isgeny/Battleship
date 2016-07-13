#include "freeglut.h"
#include <time.h>
#include <string>
#include "GameManager.h"

std::map<ObjName, GraphicsRectItem*> GameManager::items;
GameStatus GameManager::gameStatus = MENU;
const std::string GameManager::title = "BATTLESHIP";
Ship* GameManager::mShip;
ShipButton* GameManager::currPressShip;
Field* GameManager::playerField;
Field* GameManager::compField;
TextEdit* GameManager::textEditName;
GameManager game;

int main(int argc, char** argv)
{
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
	glutMouseFunc(GameManager::mouseClicked);
	glutPassiveMotionFunc(GameManager::mouseMove);
	glutMouseWheelFunc(GameManager::mouseWheel);
	glutKeyboardFunc(GameManager::keyboardPressed);
	glutTimerFunc(50, GameManager::timerRedisplay, 0);
	glutTimerFunc(1500, GameManager::timerCompStep, 0);

	glutMainLoop();
	return 0;
}