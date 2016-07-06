#include "GameManager.h"
#include <iterator>

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

	pShip.push_back(new PlacingShip(540, 240, 30, 30, 1, 4));
	pShip.push_back(new PlacingShip(540, 180, 60, 30, 2, 3));
	pShip.push_back(new PlacingShip(540, 120, 90, 30, 3, 2));
	pShip.push_back(new PlacingShip(540, 60, 120, 30, 4, 1));

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

	gameProcess.push_back(playerField);
	gameProcess.push_back(compField);
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
			if(btnNewGame->mouseOnItem(x, y))
				gameStatus = PLACING_SHIP; else
			if(btnRecords->mouseOnItem(x, y))
				gameStatus = RECORDS; else
			if(btnAbout->mouseOnItem(x, y))
				gameStatus = ABOUT; else
			if(btnExit->mouseOnItem(x, y))
				exit(0);
		}
		break;
	case PLACING_SHIP:
		if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			//Проверяем какой корабль выбрали для установки
			for(int i = 0; i < pShip.size(); i++)
			{
				if(pShip[i]->mouseOnItem(x, y))
				{
					pShip[0]->setPressed(false); pShip[1]->setPressed(false);
					pShip[2]->setPressed(false); pShip[3]->setPressed(false);
					pShip[i]->setPressed(true);
					currPressShip = pShip[i];
					mouseMovingShip->setX(-1000);
					mouseMovingShip->setY(-1000);
					mouseMovingShip->setWidth(currPressShip->getDeckCount()*CELL_SIZE);
					mouseMovingShip->setHeight(CELL_SIZE);
					mouseMovingShip->setDeckCount(currPressShip->getDeckCount());
					mouseMovingShip->setVisiable(true);
					break;
				}
			}
			//Устанавливаем корабль
			bool mouseOnField = playerField->mouseOnItem(x, y);
			bool ableToPlaceShip = playerField->availableToPlaceShip(x, y, mouseMovingShip->getWidth(), mouseMovingShip->getHeight(), mouseMovingShip->getDeckCount());
			if(mouseOnField && ableToPlaceShip && currPressShip != NULL && (currPressShip->getAvailableShipPlaceCount()) && (currPressShip->isPressed()))
			{
				int x = mouseMovingShip->getX(), y = mouseMovingShip->getY(), w = mouseMovingShip->getWidth(), h = mouseMovingShip->getHeight(), deck = mouseMovingShip->getDeckCount();
				MyPoint point = mouseMovingShip->getPos();
				playerField->setShip(PLACING_SHIP, x, y , w, h, deck, point);
				playerField->incCountOfPlacedShips();
				currPressShip->decShipCount();
			}  
			//Скрываем выбранный корабль и отрисовку при перемещении мыши
			if(currPressShip != NULL && currPressShip->getAvailableShipPlaceCount() == 0)
			{
				currPressShip->setPressed(false);
				mouseMovingShip->setVisiable(false);
			}
		}
		if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		{
			//Удаление корабля с поля по нажатию ПКМ
			std::vector<Ship* >::iterator it;
			for(it = playerField->getAllShips().begin(); it != playerField->getAllShips().end(); it++)
			{
				if((*it)->mouseOnItem(x, y))
				{
					Ship *s = (*it);
					int deckCount = (*it)->getDeckCount();
					pShip[deckCount - 1]->incShipCount();
					playerField->incCountOfPlacedShips();
					playerField->getAllShips().erase(it);
					delete s;
					break;
				}
			}
		}
		//По нажатию "Clean" очищаем поле
		if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && btnClean->mouseOnItem(x, y))
		{
			playerField->cleanField();
			for(int i = 0; i < 4; i++)
			{
				pShip[i]->setShipPlaceCount(4 - i);
			}
		}
		//По нажатию "Fight" старт игры
		if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && btnFight->mouseOnItem(x, y) && playerField->getCountOfPlacedShips() == 10)
		{
			gameStatus = WAITING_PLAYER_STEP;
		}
		//AUTO
		if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && btnAuto->mouseOnItem(x, y))
		{
			playerField->setRandomShips();
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
	//Перемещение корабля по полю при перемещении мыши
	if(gameStatus == PLACING_SHIP && currPressShip != NULL && playerField->mouseOnItem(x, y))
	{
		MyPoint temp = playerField->coordTransform(x, y);
		int countDeck = mouseMovingShip->getDeckCount(), w = mouseMovingShip->getWidth(), h = mouseMovingShip->getHeight();
		if(w > h && temp.j > (FIELD_SZ - countDeck))
			temp.j = FIELD_SZ - countDeck;
		if(w < h && temp.i > (FIELD_SZ - countDeck))
			temp.i = FIELD_SZ - countDeck;
		mouseMovingShip->setX(temp.j*CELL_SIZE + 60);
		mouseMovingShip->setY(temp.i*CELL_SIZE + 60);
		mouseMovingShip->setPos(temp);
	}
}

void GameManager::mouseWheel(int button, int dir, int x, int y)
{
	//Поворот корабля при прокрутке колесика мыши
	if(gameStatus == PLACING_SHIP)
	{
		int w = mouseMovingShip->getWidth(), h = mouseMovingShip->getHeight(), countDeck = mouseMovingShip->getDeckCount();
		MyPoint temp = playerField->coordTransform(x, y);
		if(w > h && temp.i <= (FIELD_SZ - countDeck))
		{
			mouseMovingShip->setWidth(h);
			mouseMovingShip->setHeight(w);
		}
		else if(w < h && temp.j <= (FIELD_SZ - countDeck))
		{
			mouseMovingShip->setWidth(h);
			mouseMovingShip->setHeight(w);
		}
	}
}

void GameManager::draw()
{
	//Рисование игры
	std::vector<GraphicsItem* >::iterator it;
	switch(gameStatus)
	{
	case MENU:
		drawMainMenuItems();
		break;
	case PLACING_SHIP:
		drawPlacingShipMenuItems();
		break;
	case WAITING_PLAYER_STEP:
		drawCells();
		for(it = gameProcess.begin(); it != gameProcess.end(); it++)
		{
			(*it)->draw();
		}
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