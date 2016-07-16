#include "freeglut.h"
#include <time.h>
#include <string>
#include "GameManager.h"

GameStatus GameManager::gameStatus = MENU;
std::map<ObjName, GraphicsItem*> GameManager::items;
Label* GameManager::lblTitle;
Label* GameManager::lblPlayer;
Label* GameManager::lblComp;
Button* GameManager::btnNewGame;
Button* GameManager::btnRecords;
Button* GameManager::btnAbout;
Button* GameManager::btnExit;
Button* GameManager::btnMainMenu;
Button* GameManager::btnAuto;
Button* GameManager::btnClean;
Button* GameManager::btnFight;
Button* GameManager::btnGiveUp;
Button* GameManager::btnNewGameR;
Button* GameManager::btnRecordsR;
Button* GameManager::btnMainMenuR;
Field* GameManager::playerField;
Field* GameManager::compField;
TextEdit* GameManager::textEditName;
Ship* GameManager::mouseShip;
ShipButton* GameManager::singleShip;
ShipButton* GameManager::doubleShip;
ShipButton* GameManager::tripleShip;
ShipButton* GameManager::quadShip;
ShipButton* GameManager::currPressShip;
Player* GameManager::player;
Player* GameManager::comp;
Player* GameManager::winner;
Player* GameManager::loser;
std::vector<Ship*> GameManager::playerShips, GameManager::compShips;
std::vector<Ship*>::iterator GameManager::it;
std::vector<Dot*> GameManager::dots;
std::vector<Cross*> GameManager::crosses;
double GameManager::alpha = 1.0;
//Records* GameManager::records;
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
	glutReshapeFunc(GameManager::resize);
	glutMouseFunc(GameManager::mouseClicked);
	glutPassiveMotionFunc(GameManager::mouseMove);
	glutMouseWheelFunc(GameManager::mouseWheel);
	glutKeyboardFunc(GameManager::keyboardPressed);
	glutTimerFunc(50, GameManager::timerRedisplay, 0);
	glutTimerFunc(50, GameManager::timerCompStep, 0);

	glutMainLoop();
	return 0;
}