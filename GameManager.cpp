#include "GameManager.h"

GameManager::GameManager() : gameStatus(MENU)
{
	btn[BtnNewGame]		= new Button(300, 60, 240, 60, "New game");
	btn[BtnRecords]		= new Button(300, 150, 240, 60, "Records");
	btn[BtnAbout]		= new Button(300, 240, 240, 60, "About");
	btn[BtnExit]		= new Button(300, 330, 240, 60, "Exit");
	btn[BtnFight]		= new Button(690, 300, 120, 60, "FIGHT!");
	btn[BtnAuto]		= new Button(390, 300, 120, 60, "AUTO");
	btn[BtnClean]		= new Button(540, 300, 120, 60, "CLEAN");
	item[BtnNewGame]	= btn[BtnNewGame];
	item[BtnRecords]	= btn[BtnRecords];
	item[BtnAbout]		= btn[BtnAbout];
	item[BtnExit]		= btn[BtnExit];
	item[BtnFight]		= btn[BtnFight];
	item[BtnClean]		= btn[BtnClean];
	item[BtnAuto]		= btn[BtnAuto];

	playerField			= new Field(60, 60, 300, 300, 0);
	compField			= new Field(510, 60, 300, 300, 0);
	item[PlayerField]	= playerField;
	item[CompField]		= compField;

	mShip				= new Ship(0, 0, 0, 0, 0, HORIZONTAL, false, true, 0, 0, 0, 0);
	item[MouseShip]		= mShip;

	plShip[SingleShip]	= new PlacingShip(540, 240, 30, 30, 1, HORIZONTAL, true, true, 0, 0, 0, 0, false, 4);
	plShip[DoubleShip]	= new PlacingShip(540, 180, 60, 30, 2, HORIZONTAL, true, true, 0, 0, 0, 0, false, 3);
	plShip[TripleShip]	= new PlacingShip(540, 120, 90, 30, 3, HORIZONTAL, true, true, 0, 0, 0, 0, false, 2);
	plShip[QuadShip]	= new PlacingShip(540, 60, 120, 30, 4, HORIZONTAL, true, true, 0, 0, 0, 0, false, 1);
	item[SingleShip]	= plShip[SingleShip];
	item[DoubleShip]	= plShip[DoubleShip];
	item[TripleShip]	= plShip[TripleShip];
	item[QuadShip]		= plShip[QuadShip];
}

GameManager::~GameManager()
{
	for(auto it = item.begin(); it != item.end(); it++)
		delete it->second;
	item.erase(item.begin(), item.end());
}

void GameManager::draw()
{
	drawCells();
	switch(gameStatus)
	{
	case MENU:
		for(int i = 0; i < title.size(); i++)
		{
			glColor3d(0.0, 0.0, 1.0);
			glRasterPos2d(325 + i*20, 40);
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, title[i]);
		}
		item[BtnNewGame]->draw();
		item[BtnRecords]->draw();
		item[BtnAbout]->draw();
		item[BtnExit]->draw();
		break;
	case PLACING_SHIP:
		item[MouseShip]->draw();
		item[PlayerField]->draw();
		item[BtnAuto]->draw();
		item[BtnClean]->draw();
		item[BtnFight]->draw();
		for(auto it = plShip.begin(); it != plShip.end(); it++)
			it->second->draw();
		break;
	case WAITING_PLAYER_STEP:
		item[PlayerField]->draw();
		item[CompField]->draw();
		break;
	case WAITING_COMP_STEP:
		item[PlayerField]->draw();
		item[CompField]->draw();
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
		glVertex2d(CELL_SZ*i + 1, 0);
		glVertex2d(CELL_SZ*i + 1, WIN_HEIGHT);
	}
	for(int i = 0; i <= 14; i++)
	{
		glVertex2d(0, CELL_SZ*i + 1);
		glVertex2d(WIN_WIDTH, CELL_SZ*i + 1);
	}
	glEnd();
}

void GameManager::mousePressed(int button, int state, int x, int y)
{
	//Обработка нажатий мыши
	switch(gameStatus)
	{
	case MENU:
		if(button == GLUT_LEFT_BUTTON && state == GLUT_UP)
		{
			for(auto it = btn.begin(); it != btn.end(); it++)
			{
				if(it->second->mouseOnItem(x, y))
				{
					switch(it->first)
					{
					case BtnNewGame: gameStatus = PLACING_SHIP; break;
					case BtnRecords: gameStatus = RECORDS; break;
					case BtnAbout:	 gameStatus = ABOUT; break;
					case BtnExit:	 exit(0); break;
					}
					break;
				}
			}
		}
		break;
	case PLACING_SHIP:
		if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			//Проверяем какой корабль выбрали для установки
			for(auto it = plShip.begin(); it != plShip.end(); it++)
			{
				if(it->second->mouseOnItem(x, y))
				{
					plShip[SingleShip]->setPressed(false); plShip[DoubleShip]->setPressed(false); plShip[TripleShip]->setPressed(false); plShip[QuadShip]->setPressed(false);
					it->second->setPressed(true);
					currPressShip = it->second;
					mShip->setWidth(it->second->getWidth());
					mShip->setHeight(it->second->getHeight());
					mShip->setDeckCount(it->second->getDeckCount());
					mShip->setOrientation(it->second->getOrientation());
					mShip->setX(-100);
					mShip->setY(-100);
					mShip->setVisiable(true);
					break;
				}
			}
			//Устанавливаем корабль
			if(currPressShip != NULL && currPressShip->isPressed() && playerField->mouseOnItem(x, y) && 
				playerField->availableToPlaceShip(mShip->getX(), mShip->getY(), mShip->getDeckCount(), mShip->getOrientation()))
			{
				int x = mShip->getX(), y = mShip->getY(), w = mShip->getWidth(), h = mShip->getHeight(), deck = mShip->getDeckCount(); Orientation or = mShip->getOrientation();
				int areaX = x - CELL_SZ, areaY = y - CELL_SZ, areaW = w + 2 * CELL_SZ, areaH = h + 2 * CELL_SZ;
				playerField->setShip(x, y, w, h, deck, or, areaX, areaY, areaW, areaH);
				(*playerField)++;
				(*currPressShip)--;
			}
			//Скрываем выбранный корабль и отрисовку корабля мыши
			if(currPressShip != NULL && currPressShip->getShipPlaceCount() == 0)
			{
				currPressShip->setPressed(false);
				mShip->setVisiable(false);
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
					(*plShip[(ObjName)deck])++;
					break;
				}
			}
		}
		//По нажатию "Clean" очищаем поле
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
		//По нажатию "AUTO" автоматическая расстановка кораблей
		if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && item[BtnAuto]->mouseOnItem(x, y))
		{
			playerField->cleanField();
			playerField->setRandomShips();
			for(int i = 1; i <= 4; i++)
				plShip[(ObjName)i]->setShipPlaceCount(0);
		}
		break;
	case WAITING_PLAYER_STEP:
		if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && compField->mouseOnItem(x, y) && compField->availableToMakeHit(x, y))
			compField->makeHit(x, y);
		break;
	case WAITING_COMP_STEP:
		break;
	}
}

void GameManager::mouseMove(int x, int y)
{
	//Перемещение корабля по полю при перемещении мыши
	if(gameStatus == PLACING_SHIP && playerField->mouseOnItem(x, y))
	{
		int newX = x / CELL_SZ * CELL_SZ, newY = y / CELL_SZ * CELL_SZ, mDeck = mShip->getDeckCount();
		if(mShip->getOrientation() == HORIZONTAL && x > playerField->getX() + FIELD_SZ*CELL_SZ - mDeck*CELL_SZ)
			newX = playerField->getX() + FIELD_SZ*CELL_SZ - mDeck*CELL_SZ;
		else if(mShip->getOrientation() == VERTICAL && y > playerField->getY() + FIELD_SZ*CELL_SZ - mDeck*CELL_SZ)
			newY = playerField->getY() + FIELD_SZ*CELL_SZ - mDeck*CELL_SZ;
		mShip->setX(newX);
		mShip->setY(newY);
	}
}

void GameManager::mouseWheel(int button, int dir, int x, int y)
{
	//Поворот корабля при прокрутке колесика мыши
	if(gameStatus == PLACING_SHIP && x <= playerField->getX() + FIELD_SZ*CELL_SZ - mShip->getDeckCount()*CELL_SZ + CELL_SZ && y <= playerField->getY() + FIELD_SZ*CELL_SZ - mShip->getDeckCount()*CELL_SZ + CELL_SZ)
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

const GameStatus& GameManager::getGameStatus() const
{
	return gameStatus;
}