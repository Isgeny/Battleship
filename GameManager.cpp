#include "GameManager.h"

GameManager::GameManager()
{
	items[BtnNewGame]		= new Button(300, 60, 240, 60, true, false, onButtonNewGameClicked, "NEW GAME");
	items[BtnRecords]		= new Button(300, 150, 240, 60, true, false, onButtonRecordsClicked, "RECORDS");
	items[BtnAbout]			= new Button(300, 240, 240, 60, true, false, onButtonFightClicked, "ABOUT");
	items[BtnExit]			= new Button(300, 330, 240, 60, true, false, onButtonExitClicked, "EXIT");
	items[BtnFight]			= new Button(690, 300, 120, 60, false, false, onButtonFightClicked, "FIGHT!");
	items[BtnAuto]			= new Button(390, 300, 120, 60, false, false, onButtonAutoClicked, "AUTO");
	items[BtnClean]			= new Button(540, 300, 120, 60, false, false, onButtonCleanClicked, "CLEAN");
	items[PlayerField]		= new Field(60, 60, 300, 300, false, false, onPlayerFieldClicked, 0);
	items[CompField]		= new Field(510, 60, 300, 300, false, false, onCompFieldClicked, 0);
	items[MouseShip]		= new Ship(-100, -100, 0, 0, false, false, NULL, 0, HORIZONTAL, true, 0, 0, 0, 0);
	items[SingleShipBtn]	= new ShipButton(540, 240, 30, 30, false, false, onSingleShipBtnClicked, 1, HORIZONTAL, true, 0, 0, 0, 0, 4);
	items[DoubleShipBtn]	= new ShipButton(540, 180, 60, 30, false, false, onDoubleShipBtnClicked, 2, HORIZONTAL, true, 0, 0, 0, 0, 3);
	items[TripleShipBtn]	= new ShipButton(540, 120, 90, 30, false, false, onTripleShipBtnClicked, 3, HORIZONTAL, true, 0, 0, 0, 0, 2);
	items[QuadShipBtn]		= new ShipButton(540, 60, 120, 30, false, false, onQuadShipBtnClicked, 4, HORIZONTAL, true, 0, 0, 0, 0, 1);

	mShip = (Ship*)items[MouseShip];
	playerField = (Field*)items[PlayerField];
	compField = (Field*)items[CompField];
}

GameManager::~GameManager()
{
	for(auto it = items.begin(); it != items.end(); it++)
		delete it->second;
	items.erase(items.begin(), items.end());
}

void GameManager::draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//Рисование клеток
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glColor3d(0.5, 0.75, 0.95);
	for(int i = 0; i <= 28; i++)
	{
		glVertex2d(CELL_SZ*i + 1, 0);
		glVertex2d(CELL_SZ*i + 1, WIN_HEIGHT);
	}
	for(int i = 0; i <= 14; i++)
	{
		glVertex2d(0, CELL_SZ*i + 1);
		glVertex2d(WIN_WIDTH, CELL_SZ*i + 1);
	}
	glEnd();
	//Рисование графических элементов
	for(auto it = items.begin(); it != items.end(); it++)
		it->second->draw();
	//Рисование заголовка игры
	if(gameStatus == MENU)
	{
		for(int i = 0; i < title.size(); i++)
		{
			glColor3d(0.0, 0.0, 1.0);
			glRasterPos2d(325 + i * 20, 40);
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, title[i]);
		}
	}
	glutSwapBuffers();
}

void GameManager::mouseclicked(int button, int state, int x, int y)
{
	//Обработка нажатий мыши
	switch(gameStatus)
	{
	case MENU:
	case PLACING_SHIP:
		for(auto it = items.begin(); it != items.end(); it++)
		{
			if(it->second->mouseOnItem(x, y) && it->second->isVisiable())
			{
				it->second->setButton(button);
				it->second->setState(state);
				it->second->setClicked(true);
			}
		}
		for(auto it = playerField->getShips().begin(); it != playerField->getShips().end(); it++)
		{
			if((*it)->mouseOnItem(x, y))
			{
				(*it)->setButton(button);
				(*it)->setState(state);
				(*it)->setClicked(true);
				return;
			}
		}
		break;
	case WAITING_PLAYER_STEP:
		if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && compField->mouseOnItem(x, y) && compField->availableToMakeHit(x, y))
		{
			compField->makeHit(x, y);
			gameStatus = WAITING_COMP_STEP;
		}
		break;
	}
}

void GameManager::mouseMove(int x, int y)
{
	//Перемещение корабля по полю при перемещении мыши
	if(gameStatus == PLACING_SHIP && items[PlayerField]->mouseOnItem(x, y))
	{
		int newX = x / CELL_SZ * CELL_SZ, newY = y / CELL_SZ * CELL_SZ, mDeck = mShip->getDeckCount();
		if(mShip->getOrientation() == HORIZONTAL && x > items[PlayerField]->getX() + FIELD_SZ*CELL_SZ - mDeck*CELL_SZ)
			newX = items[PlayerField]->getX() + FIELD_SZ*CELL_SZ - mDeck*CELL_SZ;
		else if(mShip->getOrientation() == VERTICAL && y > items[PlayerField]->getY() + FIELD_SZ*CELL_SZ - mDeck*CELL_SZ)
			newY = items[PlayerField]->getY() + FIELD_SZ*CELL_SZ - mDeck*CELL_SZ;
		mShip->setX(newX);
		mShip->setY(newY);
	}
}

void GameManager::mouseWheel(int button, int dir, int x, int y)
{
	//Поворот корабля при прокрутке колесика мыши
	if(gameStatus == PLACING_SHIP && x <= items[PlayerField]->getX() + FIELD_SZ*CELL_SZ - mShip->getDeckCount()*CELL_SZ + CELL_SZ && y <= items[PlayerField]->getY() + FIELD_SZ*CELL_SZ - mShip->getDeckCount()*CELL_SZ + CELL_SZ)
	{
		int mW = mShip->getWidth(), mH = mShip->getHeight();
		mShip->setWidth(mH);
		mShip->setHeight(mW);
		if(mShip->getOrientation() == HORIZONTAL)
			mShip->setOrientation(VERTICAL);
		else
			mShip->setOrientation(HORIZONTAL);
	}
}

void GameManager::timerRedisplay(int)
{
	glutPostRedisplay();
	glutTimerFunc(50, timerRedisplay, 0);
}

void GameManager::timerCompStep(int)
{
	if(gameStatus == WAITING_COMP_STEP)
	{
		int rX = rand() % playerField->getWidth() + playerField->getX();
		int rY = rand() % playerField->getHeight() + playerField->getY();
		if(playerField->availableToMakeHit(rX, rY))
		{
			playerField->makeHit(rX, rY);
			gameStatus = WAITING_PLAYER_STEP;
		}
	}
	glutTimerFunc(50, timerCompStep, 0);
}

void GameManager::setGameStatus(const GameStatus& st)
{
	gameStatus = st;
}

const GameStatus& GameManager::getGameStatus()
{
	return gameStatus;
}

void GameManager::hideAllItems()
{
	for(auto it = items.begin(); it != items.end(); it++)
		it->second->setVisiable(false);
}

void GameManager::onButtonNewGameClicked(GraphicsRectItem* obj, int button, int state)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		gameStatus = PLACING_SHIP;
		hideAllItems();
		items[PlayerField]->setVisiable(true);
		items[BtnAuto]->setVisiable(true);
		items[BtnClean]->setVisiable(true);
		items[BtnFight]->setVisiable(true);
		items[SingleShipBtn]->setVisiable(true);
		items[DoubleShipBtn]->setVisiable(true);
		items[TripleShipBtn]->setVisiable(true);
		items[QuadShipBtn]->setVisiable(true);
		items[MouseShip]->setVisiable(true);
	}
	obj->setClicked(false);
}

void GameManager::onButtonRecordsClicked(GraphicsRectItem* obj, int button, int state)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		gameStatus = RECORDS;

		
	}
	obj->setClicked(false);
}

void GameManager::onButtonAbout(GraphicsRectItem* obj, int button, int state)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		gameStatus = ABOUT;

		
	}
	obj->setClicked(false);
}

void GameManager::onButtonExitClicked(GraphicsRectItem* obj, int button, int state)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_UP)
		exit(0);
}

void GameManager::onButtonAutoClicked(GraphicsRectItem* obj, int button, int state)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		playerField->cleanField();
		playerField->setRandomShips();
		for(int i = 1; i <= 4; i++)
			static_cast<ShipButton*>(items[(ObjName)i])->setShipPlaceCount(0);
	}
	obj->setClicked(false);
}

void GameManager::onButtonCleanClicked(GraphicsRectItem* obj, int button, int state)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		playerField->cleanField();
		if(currPressShip)
			currPressShip->setPressed(false);
		mShip->setVisiable(false);
		static_cast<ShipButton*>(items[SingleShipBtn])->setShipPlaceCount(4);
		static_cast<ShipButton*>(items[DoubleShipBtn])->setShipPlaceCount(3);
		static_cast<ShipButton*>(items[TripleShipBtn])->setShipPlaceCount(2);
		static_cast<ShipButton*>(items[QuadShipBtn])->setShipPlaceCount(1);
	}
	obj->setClicked(false);
}

void GameManager::onButtonFightClicked(GraphicsRectItem* obj, int button, int state)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_UP && playerField->getPlacedShipsCount() == 10)
	{
		gameStatus = WAITING_PLAYER_STEP;
		compField->setRandomShips();
		compField->hideShips();	//Скрываем корабли компьютера
		hideAllItems();
		items[PlayerField]->setVisiable(true);
		items[CompField]->setVisiable(true);
	}
	obj->setClicked(false);
}

void GameManager::onPlayerFieldClicked(GraphicsRectItem* obj, int button, int state)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && currPressShip && currPressShip->isPressed() && playerField->availableToPlaceShip(mShip))
	{
		mShip->setArea(mShip->getX() - CELL_SZ, mShip->getY() - CELL_SZ, mShip->getWidth() + 2 * CELL_SZ, mShip->getHeight() + 2 * CELL_SZ);
		playerField->setShip(mShip);
		(*playerField)++;
		(*currPressShip)--;
		//Скрываем выбранный корабль и отрисовку корабля мыши
		if(!currPressShip->getShipPlaceCount())
		{
			currPressShip->setPressed(false);
			mShip->setVisiable(false);
		}
	}
	obj->setClicked(false);
}

void GameManager::onCompFieldClicked(GraphicsRectItem* obj, int button, int state)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{

	}
	obj->setClicked(false);
}

void GameManager::onSingleShipBtnClicked(GraphicsRectItem* obj, int button, int state)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		static_cast<ShipButton*>(items[SingleShipBtn])->setPressed(true);
		static_cast<ShipButton*>(items[DoubleShipBtn])->setPressed(false);
		static_cast<ShipButton*>(items[TripleShipBtn])->setPressed(false);
		static_cast<ShipButton*>(items[QuadShipBtn])->setPressed(false);
		currPressShip = (ShipButton*)items[SingleShipBtn];
		mShip->setX(-100);
		mShip->setY(-100);
		mShip->setWidth(30);
		mShip->setHeight(30);
		mShip->setDeckCount(1);
		mShip->setOrientation(HORIZONTAL);
		mShip->setVisiable(true);
	}
	obj->setClicked(false);
}

void GameManager::onDoubleShipBtnClicked(GraphicsRectItem* obj, int button, int state)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		static_cast<ShipButton*>(items[SingleShipBtn])->setPressed(false);
		static_cast<ShipButton*>(items[DoubleShipBtn])->setPressed(true);
		static_cast<ShipButton*>(items[TripleShipBtn])->setPressed(false);
		static_cast<ShipButton*>(items[QuadShipBtn])->setPressed(false);
		currPressShip = (ShipButton*)items[DoubleShipBtn];
		mShip->setX(-100);
		mShip->setY(-100);
		mShip->setWidth(60);
		mShip->setHeight(30);
		mShip->setDeckCount(2);
		mShip->setOrientation(HORIZONTAL);
		mShip->setVisiable(true);
	}
	obj->setClicked(false);
}

void GameManager::onTripleShipBtnClicked(GraphicsRectItem* obj, int button, int state)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		static_cast<ShipButton*>(items[SingleShipBtn])->setPressed(false);
		static_cast<ShipButton*>(items[DoubleShipBtn])->setPressed(false);
		static_cast<ShipButton*>(items[TripleShipBtn])->setPressed(true);
		static_cast<ShipButton*>(items[QuadShipBtn])->setPressed(false);
		currPressShip = (ShipButton*)items[TripleShipBtn];
		mShip->setX(-100);
		mShip->setY(-100);
		mShip->setWidth(90);
		mShip->setHeight(30);
		mShip->setDeckCount(3);
		mShip->setOrientation(HORIZONTAL);
		mShip->setVisiable(true);
	}
	obj->setClicked(false);
}

void GameManager::onQuadShipBtnClicked(GraphicsRectItem* obj, int button, int state)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		static_cast<ShipButton*>(items[SingleShipBtn])->setPressed(false);
		static_cast<ShipButton*>(items[DoubleShipBtn])->setPressed(false);
		static_cast<ShipButton*>(items[TripleShipBtn])->setPressed(false);
		static_cast<ShipButton*>(items[QuadShipBtn])->setPressed(true);
		currPressShip = (ShipButton*)items[QuadShipBtn];
		mShip->setX(-100);
		mShip->setY(-100);
		mShip->setWidth(120);
		mShip->setHeight(30);
		mShip->setDeckCount(4);
		mShip->setOrientation(HORIZONTAL);
		mShip->setVisiable(true);
	}
	obj->setClicked(false);
}

void GameManager::onShipClicked(GraphicsRectItem* obj, int button, int state)
{
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		for(auto it = playerField->getShips().begin(); it != playerField->getShips().end(); it++)
		{
			if((*it) == obj)
			{
				int deck = (*it)->getDeckCount();
				delete (*it);
				playerField->getShips().erase(it);
				(*playerField)--;
				(*(ShipButton*)(items[(ObjName)deck]))++;
				break;
			}
		}
	}
}