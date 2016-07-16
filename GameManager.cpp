#include "GameManager.h"

GameManager::GameManager()
{
	lblTitle	= new Label("BATTLESHIP", GLUT_BITMAP_TIMES_ROMAN_24, 20, Rect(325, 40, 0, 0), 0.0, 0.0, 1.0, 1.0, true);
	
	btnNewGame = new Button("NEW GAME", Rect(300, 60, 240, 60), 0.0, 0.0, 1.0, 1.0, true, onButtonNewGameClicked);
	btnRecords = new Button("RECORDS", Rect(300, 150, 240, 60), 0.0, 0.0, 1.0, 1.0, true, onButtonRecordsClicked);
	btnAbout   = new Button("ABOUT", Rect(300, 240, 240, 60), 0.0, 0.0, 1.0, 1.0, true, onButtonAboutClicked);
	btnExit    = new Button("EXIT",	Rect(300, 330, 240, 60), 0.0, 0.0, 1.0, 1.0, true, onButtonExitClicked);
	btnMainMenu = new Button("MENU", Rect(0, 0, 150, 30), 0.0, 0.0, 1.0, 1.0, false, onButtonMainMenuClicked);
	btnAuto = new Button("AUTO", Rect(390, 330, 120, 60), 0.0, 0.0, 1.0, 1.0, false, onButtonAutoClicked);
	btnClean = new Button("CLEAN", Rect(540, 330, 120, 60), 0.0, 0.0, 1.0, 1.0, false, onButtonCleanClicked);
	btnFight = new Button("FIGHT", Rect(690, 330, 120, 60), 0.0, 0.0, 1.0, 1.0, false, onButtonFightClicked);
	btnGiveUp = new Button("GIVE UP", Rect(0, 0, 150, 30), 0.0, 0.0, 1.0, 1.0, false, onButtonGiveUpClicked);
	btnNewGameR = new Button("NEW GAME", Rect(180, 300, 150, 60), 0.0, 0.0, 1.0, 1.0, false, onButtonNewGameClicked);
	btnRecordsR = new Button("RECORDS", Rect(360, 300, 150, 60), 0.0, 0.0, 1.0, 1.0, false, onButtonRecordsClicked);
	btnMainMenuR = new Button("MENU", Rect(540, 300, 150, 60), 0.0, 0.0, 1.0, 1.0, false, onButtonMainMenuClicked);

	playerField = new Field(0, Rect(60, 90, 300, 300), 0.0, 0.0, 1.0, 1.0, false, onPlayerFieldClicked);
	compField = new Field(0, Rect(510, 90, 300, 300), 0.0, 0.0, 1.0, 1.0, false, onCompFieldClicked);

	lblPlayer = new Label("", GLUT_BITMAP_HELVETICA_18, 20, Rect(145, 50, 0, 0), 1.0, 0.5, 0.0);
	lblComp = new Label("Computer", GLUT_BITMAP_HELVETICA_18, 20, Rect(585, 50, 0, 0));

	textEditName = new TextEdit("", Rect(690, 0, 150, 30), 0.0, 0.0, 1.0, 1.0, false, onTextEditClicked);

	mouseShip = new Ship(0, Rect(), Rect(), 0.0, 0.0, 1.0, 1.0, false, onShipClicked);

	singleShip = new ShipButton(4, 1, Rect(420, 270, 30, 30), 0.0, 0.0, 1.0, 1.0, false, onSingleShipBtnClicked);
	doubleShip = new ShipButton(3, 2, Rect(420, 210, 60, 30), 0.0, 0.0, 1.0, 1.0, false, onDoubleShipBtnClicked);
	tripleShip = new ShipButton(2, 3, Rect(420, 150, 90, 30), 0.0, 0.0, 1.0, 1.0, false, onTripleShipBtnClicked);
	quadShip = new ShipButton(1, 4, Rect(420, 90, 120, 30), 0.0, 0.0, 1.0, 1.0, false, onQuadShipBtnClicked);

	player = new Player;
	comp = new Player("Computer");

	//records = new Records;

	items[LblTitle] = lblTitle;
	items[LblPlayer] = lblPlayer;
	items[LblComp] = lblComp;
	items[BtnNewGame] = btnNewGame;
	items[BtnAbout] = btnAbout;
	items[BtnRecords] = btnRecords;
	items[BtnExit] = btnExit;
	items[BtnMainMenu] = btnMainMenu;
	items[BtnAuto] = btnAuto;
	items[BtnClean] = btnClean;
	items[BtnFight] = btnFight;
	items[BtnGiveUp] = btnGiveUp;
	items[BtnNewGameR] = btnNewGameR;
	items[BtnRecordsR] = btnRecordsR;
	items[BtnMainMenuR] = btnMainMenuR;
	items[PlayerField] = playerField;
	items[CompField] = compField;
	items[TextEditName] = textEditName;
	items[MouseShip] = mouseShip;
	items[SingleShipBtn] = singleShip;
	items[DoubleShipBtn] = doubleShip;
	items[TripleShipBtn] = tripleShip;
	items[QuadShipBtn] = quadShip;
}

GameManager::~GameManager()
{
	//records->writeFile();
	for(auto it = items.begin(); it != items.end(); it++)
	{
		delete it->second;
	}
	items.erase(items.begin(), items.end());
	//delete records;
}

void GameManager::draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glEnable(GL_ALPHA);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//Рисование клеток
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glColor4d(0.5, 0.75, 0.95, alpha);
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
	{
		it->second->draw();
	}
	for(auto it = playerShips.begin(); it != playerShips.end(); it++)
	{
		(*it)->draw();
	}
	for(auto it = compShips.begin(); it != compShips.end(); it++)
	{
		(*it)->draw();
	}
	for(auto it = dots.begin(); it != dots.end(); it++)
	{
		(*it)->draw();
	}
	for(auto it = crosses.begin(); it != crosses.end(); it++)
	{
		(*it)->draw();
	}
	if(gameStatus == RESULTS)
	{
		//Отрисовка победителя
		std::string txt = winner->getName() + " WON!";
		for(int i = 0; i < txt.size(); i++)
		{
			glColor3d(0.0, 0.0, 1.0);
			glRasterPos2d(WIN_WIDTH/2 - txt.size()*20 /2 + i*20, 55);
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, txt[i]);
		}
		//Отрисовка векртикальных линий
		glColor3d(0.0, 0.0, 1.0);
		glBegin(GL_LINES);
		for(int i = 0; i < 3; i++)
		{
			glVertex2d(270 + i*150, 90);
			glVertex2d(270 + i*150, 270);
		}
		//Отрисовка горизонтальных линий
		for(int i = 0; i < 3; i++)
		{
			glVertex2d(150, 135 + i*60);
			glVertex2d(690, 135 + i*60);
		}
		glEnd();
		//Отрисовка шапки таблицы
		const std::string pName = "NAME";
		for(int i = 0; i < pName.size(); i++)
		{
			glColor3d(0.0, 0.0, 1.0);
			glRasterPos2d(170 + i*20, 115);
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, pName[i]);
		}
		const std::string pKilled = "KILLED";
		for(int i = 0; i < pKilled.size(); i++)
		{
			glColor3d(0.0, 0.0, 1.0);
			glRasterPos2d(290 + i * 20, 115);
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, pKilled[i]);
		}
		const std::string pWins = "WINS";
		for(int i = 0; i < pWins.size(); i++)
		{
			glColor3d(0.0, 0.0, 1.0);
			glRasterPos2d(460 + i * 20, 115);
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, pWins[i]);
		}
		const std::string pGames = "GAMES";
		for(int i = 0; i < pGames.size(); i++)
		{
			glColor3d(0.0, 0.0, 1.0);
			glRasterPos2d(590 + i * 20, 115);
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, pGames[i]);
		}
	}
	glDisable(GL_BLEND);
	glDisable(GL_ALPHA);
	glutSwapBuffers();
}

void GameManager::mouseClicked(int button, int state, int x, int y)
{
	for(auto it = items.begin(); it != items.end(); it++)
	{
		it->second->mousePressed(button, state, x, y);
	}
	it = playerShips.begin();
	while(it != playerShips.end())
	{
		(*it)->mousePressed(button, state, x, y);
		if(it != playerShips.end())
			it++;
	}
	for(auto it = compShips.begin(); it != compShips.end(); it++)
	{
		(*it)->mousePressed(button, state, x, y);
	}
}

void GameManager::mouseMove(int x, int y)
{
	//Перемещение корабля по полю при перемещении мыши
	if(gameStatus == PLACING_SHIP && playerField->contains(x, y))
	{
		int newX = x / CELL_SZ * CELL_SZ, newY = y / CELL_SZ * CELL_SZ, mouseDecks = mouseShip->getDecks();
		if(mouseShip->getOrientation() == HORIZONTAL && x > playerField->getRect().x() + FIELD_SZ*CELL_SZ - mouseDecks*CELL_SZ)
			newX = playerField->getRect().x() + FIELD_SZ*CELL_SZ - mouseDecks*CELL_SZ;
		else if(mouseShip->getOrientation() == VERTICAL && y > playerField->getRect().y() + FIELD_SZ*CELL_SZ - mouseDecks*CELL_SZ)
			newY = playerField->getRect().y() + FIELD_SZ*CELL_SZ - mouseDecks*CELL_SZ;
		mouseShip->getRect().setX(newX);
		mouseShip->getRect().setY(newY);
	}
}

void GameManager::mouseWheel(int button, int dir, int x, int y)
{
	//Поворот корабля при прокрутке колесика мыши
	if(gameStatus == PLACING_SHIP && x < playerField->getRect().x() + FIELD_SZ*CELL_SZ - mouseShip->getDecks()*CELL_SZ + CELL_SZ && y <= playerField->getRect().y() + FIELD_SZ*CELL_SZ - mouseShip->getDecks()*CELL_SZ + CELL_SZ)
	{
		int mW = mouseShip->getRect().width(), mH = mouseShip->getRect().height();
		mouseShip->getRect().setWidth(mH);
		mouseShip->getRect().setHeight(mW);
		if(mouseShip->getOrientation() == HORIZONTAL)
			mouseShip->setOrientation(VERTICAL);
		else
			mouseShip->setOrientation(HORIZONTAL);
	}
}

void GameManager::keyboardPressed(unsigned char key, int x, int y)
{
	if(gameStatus == PLACING_SHIP && textEditName->hasFocus())
	{
		std::string temp = textEditName->getText();
		switch(key)
		{
		case 8:	//Backspace
			if(temp.size())
			{
				temp.erase(temp.size() - 1);
				textEditName->setText(temp);
			}
		break;
		case 13: //Enter
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
		int rX = rand() % playerField->getRect().width() + playerField->getRect().x();
		int rY = rand() % playerField->getRect().height() + playerField->getRect().y();
		playerField->mousePressed(GLUT_LEFT_BUTTON, GLUT_DOWN, rX, rY);
		for(auto it = playerShips.begin(); it != playerShips.end(); it++)
		{
			(*it)->mousePressed(GLUT_LEFT_BUTTON, GLUT_DOWN, rX, rY);
		}
	}
	glutTimerFunc(500, timerCompStep, 0);
}

void GameManager::hideAllItems()
{
	for(auto it = items.begin(); it != items.end(); it++)
	{
		it->second->setVisible(false);
	}
}

void GameManager::onButtonNewGameClicked(GraphicsItem* obj, int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		gameStatus = PLACING_SHIP;
		hideAllItems();
		items[BtnMainMenu]->setVisible(true);
		items[BtnAuto]->setVisible(true);
		items[BtnClean]->setVisible(true);
		items[BtnFight]->setVisible(true);
		items[PlayerField]->setVisible(true);
		items[SingleShipBtn]->setVisible(true);
		items[DoubleShipBtn]->setVisible(true);
		items[TripleShipBtn]->setVisible(true);
		items[QuadShipBtn]->setVisible(true);
		items[MouseShip]->setVisible(true);
		items[TextEditName]->setVisible(true);
		for(auto it = playerShips.begin(); it != playerShips.end(); it++)
		{
			(*it)->setVisible(true);
		}
	}
}

void GameManager::onButtonRecordsClicked(GraphicsItem* obj, int button, int state, int x, int y)
{
	hideAllItems();
	gameStatus = RECORDS;
}

void GameManager::onButtonAboutClicked(GraphicsItem* obj, int button, int state, int x, int y)
{
	hideAllItems();
	gameStatus = ABOUT;
}

void GameManager::onButtonExitClicked(GraphicsItem* obj, int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		exit(0);
	}
}

void GameManager::onButtonMainMenuClicked(GraphicsItem* obj, int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		gameStatus = MENU;
		hideAllItems();
		playerField->hideShips(playerShips);
		items[LblTitle]->setVisible(true);
		items[BtnNewGame]->setVisible(true);
		items[BtnRecords]->setVisible(true);
		items[BtnAbout]->setVisible(true);
		items[BtnExit]->setVisible(true);
	}
}

void GameManager::onButtonAutoClicked(GraphicsItem* obj, int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		for(auto it = playerShips.begin(); it != playerShips.end(); it++)
		{
			delete (*it);
		}
		playerShips.erase(playerShips.begin(), playerShips.end());
		playerField->setAliveShipsCount(0);
		playerField->setRandomShips(playerShips);
		singleShip->setShips(0);
		doubleShip->setShips(0);
		tripleShip->setShips(0);
		quadShip->setShips(0);
	}
}

void GameManager::onButtonCleanClicked(GraphicsItem* obj, int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		for(auto it = playerShips.begin(); it != playerShips.end(); it++)
		{
			delete (*it);
		}
		playerShips.erase(playerShips.begin(), playerShips.end());
		if(currPressShip)
		{
			currPressShip->setFocus(false);
		}
		mouseShip->setVisible(false);
		singleShip->setShips(4);
		doubleShip->setShips(3);
		tripleShip->setShips(2);
		quadShip->setShips(1);
		playerField->setAliveShipsCount(0);
	}
}

void GameManager::onButtonFightClicked(GraphicsItem* obj, int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_UP && playerField->getAliveShipsCount() == 10 && textEditName->getText() != "")
	{
		gameStatus = WAITING_PLAYER_STEP;
		compField->setRandomShips(compShips);
		//compField->hideShips();				//Скрываем корабли компьютера
		hideAllItems();
		playerField->setVisible(true);
		compField->setVisible(true);
		btnGiveUp->setVisible(true);
		player->setName(textEditName->getText());
		lblPlayer->setText(player->getName());
		lblPlayer->setVisible(true);
		lblComp->setVisible(true);
	}
}

void GameManager::onPlayerFieldClicked(GraphicsItem* obj, int button, int state, int x, int y)
{
	if(gameStatus == PLACING_SHIP && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && currPressShip && currPressShip->hasFocus() && playerField->availableToPlaceShip(playerShips, mouseShip) && playerField->getAliveShipsCount() != 10)
	{
		mouseShip->setAreaRect(mouseShip->getRect().x() - CELL_SZ, mouseShip->getRect().y() - CELL_SZ, mouseShip->getRect().width() + 2 * CELL_SZ, mouseShip->getRect().height() + 2 * CELL_SZ);
		mouseShip->setHealths(mouseShip->getDecks());
		playerShips.push_back(new Ship(*mouseShip));
		(*playerField)++;
		(*currPressShip)--;
		//Скрываем выбранный корабль и отрисовку корабля мыши
		if(!currPressShip->getShips())
		{
			currPressShip->setFocus(false);
			mouseShip->setVisible(false);
		}
	}
	if(gameStatus == WAITING_COMP_STEP && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && playerField->availableToPlaceDot(x, y, playerShips, dots))
	{
		int newX = x / CELL_SZ * CELL_SZ, newY = y / CELL_SZ * CELL_SZ, w = 30, h = 30;
		dots.push_back(new Dot(40, Rect(newX, newY, w, h), 0.0, 0.0, 1.0, 1.0, true));
		gameStatus = WAITING_PLAYER_STEP;
		lblPlayer->setRGBA(1.0, 0.5, 0.0, 1.0);
		lblComp->setRGBA(0.0, 0.0, 1.0, 1.0);
	}
}

void GameManager::onCompFieldClicked(GraphicsItem* obj, int button, int state, int x, int y)
{
	if(gameStatus == WAITING_PLAYER_STEP && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && compField->availableToPlaceDot(x, y, compShips, dots))
	{
		int newX = x / CELL_SZ * CELL_SZ, newY = y / CELL_SZ * CELL_SZ, w = 30, h = 30;
		dots.push_back(new Dot(40, Rect(newX, newY, w, h), 0.0, 0.0, 1.0, 1.0, true));
		gameStatus = WAITING_COMP_STEP;
		lblPlayer->setRGBA(0.0, 0.0, 1.0, 1.0);
		lblComp->setRGBA(1.0, 0.5, 0.0, 1.0);
	}
}

void GameManager::onSingleShipBtnClicked(GraphicsItem* obj, int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		singleShip->setFocus(true);
		doubleShip->setFocus(false);
		tripleShip->setFocus(false);
		quadShip->setFocus(false);
		currPressShip = singleShip;
		mouseShip->setRect(-100, -100, 30, 30);
		mouseShip->setDecks(1);
		mouseShip->setOrientation(HORIZONTAL);
		mouseShip->setVisible(true);
	}
}

void GameManager::onDoubleShipBtnClicked(GraphicsItem* obj, int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		singleShip->setFocus(false);
		doubleShip->setFocus(true);
		tripleShip->setFocus(false);
		quadShip->setFocus(false);
		currPressShip = doubleShip;
		mouseShip->setRect(-100, -100, 60, 30);
		mouseShip->setDecks(2);
		mouseShip->setOrientation(HORIZONTAL);
		mouseShip->setVisible(true);
	}
}

void GameManager::onTripleShipBtnClicked(GraphicsItem* obj, int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		singleShip->setFocus(false);
		doubleShip->setFocus(false);
		tripleShip->setFocus(true);
		quadShip->setFocus(false);
		currPressShip = tripleShip;
		mouseShip->setRect(-100, -100, 90, 30);
		mouseShip->setDecks(3);
		mouseShip->setOrientation(HORIZONTAL);
		mouseShip->setVisible(true);
	}
}

void GameManager::onQuadShipBtnClicked(GraphicsItem* obj, int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		singleShip->setFocus(false);
		doubleShip->setFocus(false);
		tripleShip->setFocus(false);
		quadShip->setFocus(true);
		currPressShip = quadShip;
		mouseShip->setRect(-100, -100, 120, 30);
		mouseShip->setDecks(4);
		mouseShip->setOrientation(HORIZONTAL);
		mouseShip->setVisible(true);
	}
}

void GameManager::onTextEditClicked(GraphicsItem* obj, int button, int state, int x, int y)
{

}

void GameManager::onShipClicked(GraphicsItem* obj, int button, int state, int x, int y)
{
	Ship* ship = static_cast<Ship*>(obj);
	if(gameStatus == PLACING_SHIP && button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		for(it = playerShips.begin(); it != playerShips.end(); it++)
		{
			if((*it) == obj)
			{
				int deck = (*it)->getDecks();
				delete (*it);
				playerShips.erase(it);
				it = playerShips.end();
				(*playerField)--;
				(*(ShipButton*)(items[(ObjName)deck]))++;
				break;
			}
		}
	}
	if(gameStatus == WAITING_PLAYER_STEP && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && compField->availableToPlaceCross(x, y, crosses))
	{
		int newX = x / CELL_SZ * CELL_SZ, newY = y / CELL_SZ * CELL_SZ, w = 30, h = 30;
		crosses.push_back(new Cross(Rect(newX, newY, w, h), 1.0, 0.0, 0.0, 1.0, true));
		(*ship)--;
		if(!ship->getHealths())
		{
			compField->placeDotsAroundShip(ship, compShips, dots);
			(*compField)--;
			if(!compField->getAliveShipsCount())
			{
				gameStatus = RESULTS;
				showResults(player, comp);
			}
		}
	}
	if(gameStatus == WAITING_COMP_STEP && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && playerField->availableToPlaceCross(x, y, crosses))
	{
		int newX = x / CELL_SZ * CELL_SZ, newY = y / CELL_SZ * CELL_SZ, w = 30, h = 30;
		crosses.push_back(new Cross(Rect(newX, newY, w, h), 1.0, 0.0, 0.0, 1.0, true));
		(*ship)--;
		if(!ship->getHealths())
		{
			playerField->placeDotsAroundShip(ship, playerShips, dots);
			(*playerField)--;
			if(!playerField->getAliveShipsCount())
			{
				gameStatus = RESULTS;
				showResults(comp, player);
			}
		}
	}
}

void GameManager::onButtonGiveUpClicked(GraphicsItem* obj, int button, int state, int x, int y)
{
	if(gameStatus == WAITING_PLAYER_STEP || gameStatus == WAITING_COMP_STEP)
	{
		showResults(comp, player);
	}
}

void GameManager::showResults(Player* _winner, Player* _loser)
{
	alpha = 0.1;
	playerField->setAlpha(alpha);
	compField->setAlpha(alpha);
	btnGiveUp->setAlpha(alpha);
	btnGiveUp->getText()->setAlpha(alpha);
	lblPlayer->setAlpha(alpha);
	lblComp->setAlpha(alpha);
	for(auto it = playerShips.begin(); it != playerShips.end(); it++)
		(*it)->setAlpha(alpha);
	for(auto it = compShips.begin(); it != compShips.end(); it++)
		(*it)->setAlpha(alpha);
	for(auto it = dots.begin(); it != dots.end(); it++)
		(*it)->setAlpha(alpha);
	for(auto it = crosses.begin(); it != crosses.end(); it++)
		(*it)->setAlpha(alpha);
	btnNewGameR->setVisible(true);
	btnRecordsR->setVisible(true);
	btnMainMenuR->setVisible(true);
	winner = _winner;
	loser = _loser;
}
