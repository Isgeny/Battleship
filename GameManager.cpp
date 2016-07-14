#include "GameManager.h"

GameManager::GameManager()
{
	items[BtnNewGame]		= new Button(300, 60, 240, 60, true, false, onButtonNewGameClicked, "NEW GAME");
	items[BtnRecords]		= new Button(300, 150, 240, 60, true, false, onButtonRecordsClicked, "RECORDS");
	items[BtnAbout]			= new Button(300, 240, 240, 60, true, false, onButtonFightClicked, "ABOUT");
	items[BtnExit]			= new Button(300, 330, 240, 60, true, false, onButtonExitClicked, "EXIT");
	items[BtnFight]			= new Button(690, 330, 120, 60, false, false, onButtonFightClicked, "FIGHT!");
	items[BtnAuto]			= new Button(390, 330, 120, 60, false, false, onButtonAutoClicked, "AUTO");
	items[BtnClean]			= new Button(540, 330, 120, 60, false, false, onButtonCleanClicked, "CLEAN");
	
	items[BtnGiveUp]		= new Button(0, 0, 150, 30, false, false, onButtonGiveUp, "GIVE UP");
	items[BtnMainMenu]		= new Button(0, 0, 150, 30, false, false, onButtonMainMenuClicked, "MAIN MENU");
	items[BtnNewGameR]		= new Button(210, 330, 120, 60, false, false, onButtonNewGameClicked, "NEW GAME");
	items[BtnRecordsR]		= new Button(360, 330, 120, 60, false, false, onButtonRecordsClicked, "RECORDS");
	items[BtnMainMenuR]		= new Button(510, 330, 120, 60, false, false, onButtonMainMenuClicked, "MENU");

	items[PlayerField]		= new Field(60, 90, 300, 300, false, false, onPlayerFieldClicked, 0, "", 1.0, 0.5, 0.0);
	items[CompField]		= new Field(510, 90, 300, 300, false, false, onCompFieldClicked, 0, "Computer");
	items[MouseShip]		= new Ship(-100, -100, 0, 0, false, false, NULL, 0, HORIZONTAL, true, 0, 0, 0, 0);
	items[SingleShipBtn]	= new ShipButton(420, 270, 30, 30, false, false, onSingleShipBtnClicked, 1, HORIZONTAL, true, 0, 0, 0, 0, 4);
	items[DoubleShipBtn]	= new ShipButton(420, 210, 60, 30, false, false, onDoubleShipBtnClicked, 2, HORIZONTAL, true, 0, 0, 0, 0, 3);
	items[TripleShipBtn]	= new ShipButton(420, 150, 90, 30, false, false, onTripleShipBtnClicked, 3, HORIZONTAL, true, 0, 0, 0, 0, 2);
	items[QuadShipBtn]		= new ShipButton(420, 90, 120, 30, false, false, onQuadShipBtnClicked, 4, HORIZONTAL, true, 0, 0, 0, 0, 1);
	items[TextEditName]		= new TextEdit(690, 0, 150, 30, false, false, onTextEditClicked, "", false);


	records = new Records;
	mShip = (Ship*)items[MouseShip];
	playerField = (Field*)items[PlayerField];
	compField = (Field*)items[CompField];
	textEditName = (TextEdit*)items[TextEditName];
}

GameManager::~GameManager()
{
	for(auto it = items.begin(); it != items.end(); it++)
		delete it->second;
	items.erase(items.begin(), items.end());
	delete records;
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
	for(int i = 0; i <= 15; i++)
	{
		glVertex2d(0, CELL_SZ*i + 1);
		glVertex2d(WIN_WIDTH, CELL_SZ*i + 1);
	}
	glEnd();
	//Рисование графических элементов
	for(auto it = items.begin(); it != items.end(); it++)
		it->second->draw();
	//Рисование заголовка игры
	switch(gameStatus)
	{
	case MENU:
		for(int i = 0; i < title.size(); i++)
		{
			glColor3d(0.0, 0.0, 1.0);
			glRasterPos2d(325 + i * 20, 40);
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, title[i]);
		}
	break;
	case RESULTS:
		std::string txt = winnerName + " WON!";
		for(int i = 0; i < txt.size(); i++)
		{
			glColor3d(0.0, 0.0, 1.0);
			glRasterPos2d(WIN_WIDTH/2 - txt.size()*20 /2 + i*20, 55);
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, txt[i]);
		}
	break;
	}
	glutSwapBuffers();
}

void GameManager::mouseClicked(int button, int state, int x, int y)
{
	//Обработка нажатий мыши
	switch(gameStatus)
	{
	case MENU:
	case PLACING_SHIP:
		for(auto it = items.begin(); it != items.end(); it++)
		{
			if(it->second->mouseOnItem(x, y) && it->second->isVisible())
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
		if(!textEditName->mouseOnItem(x, y) && textEditName->hasFocus())
			textEditName->setFocus(false);
		break;
	case WAITING_PLAYER_STEP:
		if(items[BtnGiveUp]->mouseOnItem(x, y))
		{
			items[BtnGiveUp]->setButton(button);
			items[BtnGiveUp]->setState(state);
			items[BtnGiveUp]->setClicked(true);
		}
		if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && compField->mouseOnItem(x, y) && compField->availableToMakeHit(x, y))
		{
			compField->makeHit(x, y);
			gameStatus = WAITING_COMP_STEP;
			playerField->setPlayerNameRGB(0.0, 0.0, 1.0);
			compField->setPlayerNameRGB(1.0, 0.5, 0.0);
			if(compField->allShipsKilled())
			{
				showResults(playerField->getPlayerName(), compField->getPlayerName());
			}
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

void GameManager::keyboardPressed(unsigned char key, int x, int y)
{
	if(gameStatus == PLACING_SHIP && textEditName->hasFocus())
	{
		std::string temp = textEditName->getText();
		switch(key)
		{
		case 8:	//backspace
			if(temp.size())
			{
				temp.erase(temp.size() - 1);
				textEditName->setText(temp);
			}
		break;
		case 13:	//Enter
			textEditName->setFocus(false);
		break;
		default:
			temp += key;
			textEditName->setText(temp);
		break;
		}
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
			compField->setPlayerNameRGB(0.0, 0.0, 1.0);
			playerField->setPlayerNameRGB(1.0, 0.5, 0.0);
		}
		if(playerField->allShipsKilled())
		{
			gameStatus = RESULTS;
			hideAllItems();
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
		it->second->setVisible(false);
}

void GameManager::onButtonNewGameClicked(GraphicsRectItem* obj, int button, int state)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		gameStatus = PLACING_SHIP;
		hideAllItems();
		items[PlayerField]->setVisible(true);
		items[BtnAuto]->setVisible(true);
		items[BtnClean]->setVisible(true);
		items[BtnFight]->setVisible(true);
		items[SingleShipBtn]->setVisible(true);
		items[DoubleShipBtn]->setVisible(true);
		items[TripleShipBtn]->setVisible(true);
		items[QuadShipBtn]->setVisible(true);
		items[MouseShip]->setVisible(true);
		items[TextEditName]->setVisible(true);
		items[BtnMainMenu]->setVisible(true);
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

void GameManager::onButtonMainMenuClicked(GraphicsRectItem * obj, int button, int state)
{
	gameStatus = MENU;
	hideAllItems();
	items[BtnNewGame]->setVisible(true);
	items[BtnRecords]->setVisible(true);
	items[BtnAbout]->setVisible(true);
	items[BtnExit]->setVisible(true);
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
		mShip->setVisible(false);
		static_cast<ShipButton*>(items[SingleShipBtn])->setShipPlaceCount(4);
		static_cast<ShipButton*>(items[DoubleShipBtn])->setShipPlaceCount(3);
		static_cast<ShipButton*>(items[TripleShipBtn])->setShipPlaceCount(2);
		static_cast<ShipButton*>(items[QuadShipBtn])->setShipPlaceCount(1);
	}
	obj->setClicked(false);
}

void GameManager::onButtonFightClicked(GraphicsRectItem* obj, int button, int state)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_UP && playerField->getPlacedShipsCount() == 10 && textEditName->getText() != "")
	{
		gameStatus = WAITING_PLAYER_STEP;
		compField->setRandomShips();
		//compField->hideShips();	//Скрываем корабли компьютера
		hideAllItems();
		items[PlayerField]->setVisible(true);
		playerField->setPlayerName(textEditName->getText());
		items[CompField]->setVisible(true);
		items[BtnGiveUp]->setVisible(true);
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
			mShip->setVisible(false);
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
		mShip->setVisible(true);
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
		mShip->setVisible(true);
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
		mShip->setVisible(true);
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
		mShip->setVisible(true);
	}
	obj->setClicked(false);
}

void GameManager::onTextEditClicked(GraphicsRectItem * obj, int button, int state)
{
	textEditName->setFocus(true);
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

void GameManager::onButtonGiveUp(GraphicsRectItem* obj, int button, int state)
{
	showResults(compField->getPlayerName(), playerField->getPlayerName());
}

void GameManager::showResults(const std::string& _winnerName, const std::string& _loserName)
{
	hideAllItems();
	gameStatus = RESULTS;
	winnerName = _winnerName;
	loserName = _loserName;
	items[BtnNewGameR]->setVisible(true);
	items[BtnRecordsR]->setVisible(true);
	items[BtnMainMenuR]->setVisible(true);
}
