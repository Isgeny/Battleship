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
	items[MouseShip]		= new Ship(-100, -100, 0, 0, false, false, onMouseShipClicked, 0, HORIZONTAL, true, 0, 0, 0, 0);
	items[SingleShipBtn]	= new ShipButton(540, 240, 30, 30, false, false, onSingleShipBtnClicked, 1, HORIZONTAL, true, 0, 0, 0, 0, 4);
	items[DoubleShipBtn]	= new ShipButton(540, 180, 60, 30, false, false, onDoubleShipBtnClicked, 2, HORIZONTAL, true, 0, 0, 0, 0, 3);
	items[TripleShipBtn]	= new ShipButton(540, 120, 90, 30, false, false, onTripleShipBtnClicked, 3, HORIZONTAL, true, 0, 0, 0, 0, 2);
	items[QuadShipBtn]		= new ShipButton(540, 60, 120, 30, false, false, onQuadShipBtnClicked, 4, HORIZONTAL, true, 0, 0, 0, 0, 1);

	mShip = (Ship*)items[MouseShip];
	playerField = (Field*)items[PlayerField];
	compField = (Field*)items[CompField];


	/*item[BtnNewGame]	= btn[BtnNewGame];
	item[BtnRecords]	= btn[BtnRecords];
	item[BtnAbout]		= btn[BtnAbout];
	item[BtnExit]		= btn[BtnExit];
	item[BtnFight]		= btn[BtnFight];
	item[BtnClean]		= btn[BtnClean];
	item[BtnAuto]		= btn[BtnAuto];*/

	/*playerField			= new Field(60, 60, 300, 300, true, false, NULL, 0);
	compField			= new Field(510, 60, 300, 300, false, false, NULL, 0);
	item[PlayerField]	= playerField;
	item[CompField]		= compField;

	mShip				= new Ship(0, 0, 0, 0, 0, HORIZONTAL, false, true, 0, 0, 0, 0);
	item[MouseShip]		= mShip;

	plShip[SingleShip]	= new ShipButton(540, 240, 30, 30, 1, HORIZONTAL, true, true, 0, 0, 0, 0, false, 4);
	plShip[DoubleShip]	= new ShipButton(540, 180, 60, 30, 2, HORIZONTAL, true, true, 0, 0, 0, 0, false, 3);
	plShip[TripleShip]	= new ShipButton(540, 120, 90, 30, 3, HORIZONTAL, true, true, 0, 0, 0, 0, false, 2);
	plShip[QuadShip]	= new ShipButton(540, 60, 120, 30, 4, HORIZONTAL, true, true, 0, 0, 0, 0, false, 1);
	item[SingleShip]	= plShip[SingleShip];
	item[DoubleShip]	= plShip[DoubleShip];
	item[TripleShip]	= plShip[TripleShip];
	item[QuadShip]		= plShip[QuadShip];*/
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

void GameManager::mousePressed(int button, int state, int x, int y)
{
	//Обработка нажатий мыши
	switch(gameStatus)
	{
	case MENU:
		if(button == GLUT_LEFT_BUTTON && state == GLUT_UP)
		{
			for(auto it = items.begin(); it != items.end(); it++)
			{
				if(it->second->mouseOnItem(x, y) && it->second->isVisiable())
				{
					it->second->setPressed(true);
				}
			}
		}
		break;
	case PLACING_SHIP:
		if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			for(auto it = items.begin(); it != items.end(); it++)
			{
				if(it->second->mouseOnItem(x, y) && it->second->isVisiable())
				{
					it->second->setPressed(true);
				}
			}
		}
		//Удаление корабля с поля по нажатию ПКМ
		if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		{
			for(auto it = playerField->getShips().begin(); it != playerField->getShips().end(); it++)
			{
				if((*it)->mouseOnItem(x, y))
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
		/*//По нажатию "AUTO" автоматическая расстановка кораблей
		if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && item[BtnAuto]->mouseOnItem(x, y))
		{
			playerField->cleanField();
			playerField->setRandomShips();
			for(int i = 1; i <= 4; i++)
				plShip[(ObjName)i]->setShipPlaceCount(0);
		}
		//По нажатию "CLEAN" очищаем поле
		if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && item[BtnClean]->mouseOnItem(x, y))
		{
			playerField->cleanField();
			if(currPressShip != NULL)
				currPressShip->setPressed(false);
			mShip->setVisiable(false);
			plShip[SingleShip]->setShipPlaceCount(4);
			plShip[DoubleShip]->setShipPlaceCount(3);
			plShip[TripleShip]->setShipPlaceCount(2);
			plShip[QuadShip]->setShipPlaceCount(1);
		}
		//По нажатию "FIGHT" старт игры
		if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && item[BtnFight]->mouseOnItem(x, y) && playerField->getPlacedShipsCount() == 10)
		{
			gameStatus = WAITING_PLAYER_STEP;
			compField->setRandomShips();
			//compField->hideShips();	//Скрываем корабли компьютера
		}
		break;
	case WAITING_PLAYER_STEP:
		if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && compField->mouseOnItem(x, y) && compField->availableToMakeHit(x, y))
		{
			compField->makeHit(x, y);
			gameStatus = WAITING_COMP_STEP;
		}
		break;
	}*/
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

void GameManager::setGameStatus(const GameStatus& st)
{
	gameStatus = st;
}

const GameStatus& GameManager::getGameStatus()
{
	return gameStatus;
}

void GameManager::makeCompStep()
{
	/*if(gameStatus == WAITING_COMP_STEP)
	{
		int rX = rand() % playerField->getWidth() + playerField->getX();
		int rY = rand() % playerField->getHeight() + playerField->getY();
		if(playerField->availableToMakeHit(rX, rY))
		{
			playerField->makeHit(rX, rY);
			gameStatus = WAITING_PLAYER_STEP;
		}
	}*/
}

void GameManager::hideAllItems()
{
	for(auto it = items.begin(); it != items.end(); it++)
		it->second->setVisiable(false);
}

void GameManager::onButtonNewGameClicked()
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
	items[BtnNewGame]->setPressed(false);
}

void GameManager::onButtonRecordsClicked()
{
	gameStatus = RECORDS;
}

void GameManager::onButtonAbout()
{
	gameStatus = ABOUT;
}

void GameManager::onButtonExitClicked()
{
	exit(0);
}

void GameManager::onButtonAutoClicked()
{

}

void GameManager::onButtonCleanClicked()
{

}

void GameManager::onButtonFightClicked()
{

}

void GameManager::onPlayerFieldClicked()
{
	if(currPressShip && currPressShip->isPressed() && playerField->availableToPlaceShip(mShip))
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
	items[PlayerField]->setPressed(false);
}

void GameManager::onCompFieldClicked()
{

	items[CompField]->setPressed(false);
}

void GameManager::onSingleShipBtnClicked()
{
	items[DoubleShipBtn]->setPressed(false);
	items[TripleShipBtn]->setPressed(false);
	items[QuadShipBtn]->setPressed(false);
	currPressShip = (ShipButton*)items[SingleShipBtn];
	mShip->setX(-100);
	mShip->setY(-100);
	mShip->setWidth(30);
	mShip->setHeight(30);
	mShip->setDeckCount(1);
	mShip->setOrientation(HORIZONTAL);
	mShip->setVisiable(true);
}

void GameManager::onDoubleShipBtnClicked()
{
	items[SingleShipBtn]->setPressed(false);
	items[TripleShipBtn]->setPressed(false);
	items[QuadShipBtn]->setPressed(false);
	currPressShip = (ShipButton*)items[DoubleShipBtn];
	mShip->setX(-100);
	mShip->setY(-100);
	mShip->setWidth(60);
	mShip->setHeight(30);
	mShip->setDeckCount(2);
	mShip->setOrientation(HORIZONTAL);
	mShip->setVisiable(true);
}

void GameManager::onTripleShipBtnClicked()
{
	items[SingleShipBtn]->setPressed(false);
	items[DoubleShipBtn]->setPressed(false);
	items[QuadShipBtn]->setPressed(false);
	currPressShip = (ShipButton*)items[TripleShipBtn];
	mShip->setX(-100);
	mShip->setY(-100);
	mShip->setWidth(90);
	mShip->setHeight(30);
	mShip->setDeckCount(3);
	mShip->setOrientation(HORIZONTAL);
	mShip->setVisiable(true);
}

void GameManager::onQuadShipBtnClicked()
{
	items[SingleShipBtn]->setPressed(false);
	items[DoubleShipBtn]->setPressed(false);
	items[TripleShipBtn]->setPressed(false);
	currPressShip = (ShipButton*)items[QuadShipBtn];
	mShip->setX(-100);
	mShip->setY(-100);
	mShip->setWidth(120);
	mShip->setHeight(30);
	mShip->setDeckCount(4);
	mShip->setOrientation(HORIZONTAL);
	mShip->setVisiable(true);
}

void GameManager::onMouseShipClicked()
{
	items[MouseShip]->setPressed(false);
}
