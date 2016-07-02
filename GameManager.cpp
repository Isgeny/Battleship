#include "GameManager.h"

GameManager::GameManager() : gameStatus(MENU)
{
	btnNewGame = new Button(300, 60, 240, 60, "New game");
	btnRecords = new Button(300, 150, 240, 60, "Records");
	btnAbout = new Button(300, 240, 240, 60, "About");
	btnExit = new Button(300, 330, 240, 60, "Exit");
	btnFight = new Button(690, 300, 120, 60, "FIGHT!");
	btnAuto = new Button(390, 300, 120, 60, "AUTO");
	btnClean = new Button(540, 300, 120, 60, "CLEAN");

	playerField = new Field(60, 60, 300, 300);
	compField = new Field(510, 60, 300, 300);

	pShip.push_back(new PlacingShip(540, 240, 30, 30, 1));
	pShip.push_back(new PlacingShip(540, 180, 60, 30, 2));
	pShip.push_back(new PlacingShip(540, 120, 90, 30, 3));
	pShip.push_back(new PlacingShip(540, 60, 120, 30, 4));

	mouseMovingShip = new Ship();

	mainMenuItems.push_back(btnNewGame);
	mainMenuItems.push_back(btnRecords);
	mainMenuItems.push_back(btnAbout);
	mainMenuItems.push_back(btnExit);

	menuPlacingShipItems.push_back(playerField);
	menuPlacingShipItems.push_back(btnFight);
	menuPlacingShipItems.push_back(btnAuto);
	menuPlacingShipItems.push_back(btnClean);
	menuPlacingShipItems.push_back(pShip[0]);
	menuPlacingShipItems.push_back(pShip[1]);
	menuPlacingShipItems.push_back(pShip[2]);
	menuPlacingShipItems.push_back(pShip[3]);
}

GameManager::~GameManager()
{
	delete btnNewGame;
	delete btnRecords;
	delete btnAbout;
	delete btnExit;
	delete btnAuto;
	delete btnClean;
	delete playerField;
	delete compField;
	for(int i = 0; i < pShip.size(); i++)
		delete pShip[i];
	delete mouseMovingShip;
}

GameStatus GameManager::getGameStatus() const
{
	return gameStatus;
}

void GameManager::setGameStatus(GameStatus st)
{
	gameStatus = st;
}

void GameManager::mousePressed(int button, int state, int x, int y)
{
	//Обработка нажатий мыши
	switch(gameStatus)
	{
	case MENU:
		if(button == GLUT_LEFT_BUTTON && state == GLUT_UP)
		{
			if(btnNewGame->mouseOnButton(x, y))
				gameStatus = PLACING_SHIP; else
			if(btnRecords->mouseOnButton(x, y))
				gameStatus = RECORDS; else
			if(btnAbout->mouseOnButton(x, y))
				gameStatus = ABOUT; else
			if(btnExit->mouseOnButton(x, y))
				exit(0);
		}
		break;
	case PLACING_SHIP:
		if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			for(int i = 0; i < pShip.size(); i++)
				if(pShip[i]->mouseOnPlacingShip(x, y))
				{
					pShip[0]->setPressed(false); pShip[1]->setPressed(false);
					pShip[2]->setPressed(false); pShip[3]->setPressed(false);
					pShip[i]->setPressed(true);
					currPressShip = pShip[i];
				}
		}
		break;
	case WAITING_PLAYER_STEP:
		break;
	case WAITING_COMP_STEP:
		break;
	}
}

void GameManager::mouseMove(int x, int y)
{
	if(gameStatus == PLACING_SHIP && currPressShip != NULL && playerField->mouseOnField(x, y))
	{
		MyPoint point;
		point = coordTranform(x, y);
		mouseMovingShip->setX(point.j*CELL_SIZE + 60);
		mouseMovingShip->setY(point.i*CELL_SIZE + 60);
		mouseMovingShip->setWidth(currPressShip->getDeckCount()*CELL_SIZE);
		mouseMovingShip->setHeight(CELL_SIZE);
	}
}

void GameManager::draw()
{
	//Рисование игры
	switch(gameStatus)
	{
	case MENU:
		drawMainMenuItems();
		break;
	case PLACING_SHIP:
		drawPlacingShipMenuItems();
		break;
	}
}

void GameManager::drawCells()
{
	//Рисование клеточек
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glColor3d(0.5, 0.75, 0.95);
	for(int i = 0; i <= 28; i++)
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
}

void GameManager::drawMainMenuItems()
{
	//Рисование элементов главного меню
	drawCells();
	std::string title = "BATTLESHIP";
	int space = 20;
	for(int i = 0; i < title.size(); i++)
	{
		glColor3d(0.0, 0.0, 1.0);
		glRasterPos2d(325 + i*space, 40);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, title[i]);
	}
	for(int i = 0; i < mainMenuItems.size(); i++)
		mainMenuItems[i]->draw();
}

void GameManager::drawPlacingShipMenuItems()
{
	//Рисование элементов меню расстановки кораблей
	drawCells();
	mouseMovingShip->draw();
	for(int i = 0; i < menuPlacingShipItems.size(); i++)
		menuPlacingShipItems[i]->draw();
}

void GameManager::drawGameProcessItems()
{
}

MyPoint GameManager::coordTranform(int mX, int mY)
{
	//Перевод координат формы в координаты игрового поля
	MyPoint point;
	if((gameStatus == PLACING_SHIP) && (playerField->mouseOnField(mX, mY)))
	{
		point.i = (mY - playerField->getY()) / CELL_SIZE;
		point.j = (mX - playerField->getX()) / CELL_SIZE;
		return point;
	}
	else if((gameStatus == WAITING_PLAYER_STEP) && (compField->mouseOnField(mX, mY)))
	{
		point.i = (mY - compField->getY()) / CELL_SIZE;
		point.j = (mX - compField->getX()) / CELL_SIZE;
		return point;
	}
}