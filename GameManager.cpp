#include "GameManager.h"

GameManager::GameManager()
{
	lblTitle		= new Label("BATTLESHIP", GLUT_BITMAP_TIMES_ROMAN_24, 20, Rect(325, 40, 0, 0), nullptr, true);
	lblPlayer		= new Label("", GLUT_BITMAP_HELVETICA_18, 20, Rect(145, 50, 0, 0), nullptr, false, 1.0, 0.5, 0.0);
	lblComp			= new Label("Computer", GLUT_BITMAP_HELVETICA_18, 20, Rect(585, 50, 0, 0));
	lblRecords		= new Label("RECORDS", GLUT_BITMAP_TIMES_ROMAN_24, 20, Rect(370, 40, 0, 0));
	lblWin			= new Label("", GLUT_BITMAP_HELVETICA_18, 20, Rect(325, 55, 0, 0));

	btnNewGame		= new Button("NEW GAME", Rect(300, 60, 240, 60), onButtonNewGameClicked, true);
	btnRecords		= new Button("RECORDS", Rect(300, 150, 240, 60), onButtonRecordsClicked, true);
	btnAbout		= new Button("ABOUT", Rect(300, 240, 240, 60), onButtonAboutClicked, true);
	btnExit			= new Button("EXIT", Rect(300, 330, 240, 60), onButtonExitClicked, true);
	btnMainMenu		= new Button("MENU", Rect(0, 0, 150, 30), onButtonMainMenuClicked);
	btnAuto			= new Button("AUTO", Rect(420, 330, 120, 60), onButtonAutoClicked);
	btnClean		= new Button("CLEAN", Rect(570, 330, 120, 60), onButtonCleanClicked);
	btnFight		= new Button("FIGHT", Rect(720, 330, 120, 60), onButtonFightClicked);
	btnGiveUp		= new Button("GIVE UP", Rect(0, 0, 150, 30), onButtonGiveUpClicked);
	btnNewGameR		= new Button("NEW GAME", Rect(180, 300, 150, 60), onButtonNewGameRClicked);
	btnRecordsR		= new Button("RECORDS", Rect(360, 300, 150, 60), onButtonRecordsRClicked);
	btnMainMenuR	= new Button("MENU", Rect(540, 300, 150, 60), onButtonMainMenuRClicked);
	btnMainMenuRec	= new Button("MENU", Rect(0, 0, 150, 30), onButtonMainMenuClicked);
	btnMainMenuA	= new Button("MENU", Rect(360, 330, 150, 60), onButtonMainMenuClicked);


	playerField	= new Field(0, Rect(60, 90, 300, 300), onPlayerFieldClicked);
	compField	= new Field(0, Rect(510, 90, 300, 300), onCompFieldClicked);

	textEditName = new TextEdit("Player", Rect(720, 0, 150, 30), onTextEditClicked);

	mouseShip = new Ship(0, Rect(), Rect(), HORIZONTAL, onShipClicked);

	singleShip	= new ShipButton(4, 1, Rect(), Rect(450, 270, 30, 30), false, HORIZONTAL, onSingleShipBtnClicked);
	doubleShip	= new ShipButton(3, 2, Rect(), Rect(450, 210, 60, 30), false, HORIZONTAL, onDoubleShipBtnClicked);
	tripleShip	= new ShipButton(2, 3, Rect(), Rect(450, 150, 90, 30), false, HORIZONTAL, onTripleShipBtnClicked);
	quadShip	= new ShipButton(1, 4, Rect(), Rect(450, 90, 120, 30), false, HORIZONTAL, onQuadShipBtnClicked);

	player = new Player();
	comp   = new Player("Computer");

	resultsTable = new Table(3, 3, Rect(150, 90, 540, 180));
	records		 = new Records(11, 5, Rect(60, 60, 750, 330));

	mouseHint = new HintIcon(Rect(690, 150, 60, 90));

	about = new About();
	
	items.push_back(lblTitle);
	items.push_back(lblPlayer);
	items.push_back(lblComp);
	items.push_back(lblRecords);
	items.push_back(lblWin);
	items.push_back(btnNewGame);
	items.push_back(btnAbout);
	items.push_back(btnRecords);
	items.push_back(btnExit);
	items.push_back(btnMainMenu);
	items.push_back(btnAuto);
	items.push_back(btnClean);
	items.push_back(btnFight);
	items.push_back(btnGiveUp);
	items.push_back(btnNewGameR);
	items.push_back(btnRecordsR);
	items.push_back(btnMainMenuR);
	items.push_back(btnMainMenuRec);
	items.push_back(btnMainMenuA);
	items.push_back(playerField);
	items.push_back(compField);
	items.push_back(textEditName);
	items.push_back(mouseShip);
	items.push_back(singleShip);
	items.push_back(doubleShip);
	items.push_back(tripleShip);
	items.push_back(quadShip);
	items.push_back(resultsTable);
	items.push_back(records);
	items.push_back(mouseHint);
	items.push_back(about);
}

GameManager::~GameManager()
{
	for(auto it = items.begin(); it != items.end(); it++)
		delete *it;
	items.erase(items.begin(), items.end());
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
		(*it)->draw();
	for(auto it = playerShips.begin(); it != playerShips.end(); it++)
		(*it)->draw();
	for(auto it = compShips.begin(); it != compShips.end(); it++)
		(*it)->draw();
	for(auto it = dots.begin(); it != dots.end(); it++)
		(*it)->draw();
	for(auto it = crosses.begin(); it != crosses.end(); it++)
		(*it)->draw();
	glDisable(GL_BLEND);
	glDisable(GL_ALPHA);
	glutSwapBuffers();
}

void GameManager::resize(int width, int height)
{
	//Запрещение изменения размера окна
	glutReshapeWindow(WIN_WIDTH, WIN_HEIGHT);
}

void GameManager::mouseClicked(int button, int state, int x, int y)
{
	for(auto it = items.begin(); it != items.end(); it++)
		(*it)->mousePressed(button, state, x, y);
	for(int i = 0; i < playerShips.size(); i++)
	{
		if(playerShips[i])
			playerShips[i]->mousePressed(button, state, x, y);
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
		int newX = x/CELL_SZ*CELL_SZ, newY = y/CELL_SZ*CELL_SZ, mouseDecks = mouseShip->getDecks();
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
	if(gameStatus == PLACING_SHIP && x < playerField->getRect().x() + playerField->getRect().width() - mouseShip->getDecks()*CELL_SZ + CELL_SZ && y <= playerField->getRect().y() + FIELD_SZ*CELL_SZ - mouseShip->getDecks()*CELL_SZ + CELL_SZ)
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
		textEditName->keyboardPressed(key, x, y);
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
		if(rX % CELL_SZ != 0 && rY % CELL_SZ != 0)
		{
			for(auto it = playerShips.begin(); it != playerShips.end(); it++)
			{
				if((*it)->contains(rX, rY))
				{
					if(playerField->availableToPlaceCross(rX, rY, crosses))
					{
						crosses.push_back(new Cross(Rect(rX/CELL_SZ*CELL_SZ, rY/CELL_SZ*CELL_SZ, CELL_SZ, CELL_SZ), nullptr, true));
						(*(*it))--;
						comp->incPointsK();
						comp->setPoints(comp->getPoints() + comp->getPointsK());
						if(!(*it)->getHealths())
						{
							playerField->placeDotsAroundShip(*it, playerShips, dots);
							(*playerField)--;
							comp->incPointsK();
							if(!playerField->getAliveShipsCount())
							{
								comp->setPoints(comp->getPoints() + 3000);
								gameStatus = RESULTS;
								showResults(comp, compField, compShips, player, playerField, playerShips);
							}
						}
						break;
					}
				}
			}
			if(playerField->availableToPlaceDot(rX, rY, playerShips, dots))
			{
				dots.push_back(new Dot(40, Rect(rX/CELL_SZ*CELL_SZ, rY/CELL_SZ*CELL_SZ, CELL_SZ, CELL_SZ), nullptr, true));
				gameStatus = WAITING_PLAYER_STEP;
				lblPlayer->setRGBA(1.0, 0.5, 0.0, 1.0);
				lblComp->setRGBA(0.0, 0.0, 1.0, 1.0);
				comp->setPointsK(100);
				comp->setPoints(comp->getPoints() + comp->getPointsK());
			}
		}
	}
	glutTimerFunc(50, timerCompStep, 0);
}

void GameManager::timerTextEditCarriage(int)
{
	if(textEditName->hasCarriage())
		textEditName->setCarriage(false);
	else
		textEditName->setCarriage(true);
	glutTimerFunc(750, timerTextEditCarriage, 0);
}

void GameManager::hideAllItems()
{
	for(auto it = items.begin(); it != items.end(); it++)
		(*it)->setVisible(false);
}

void GameManager::setAlpha(int _alpha)
{
	alpha = _alpha;
	for(auto it = items.begin(); it != items.end(); it++)
	{
		(*it)->setAlpha(_alpha);
	}
	for(auto it = playerShips.begin(); it != playerShips.end(); it++)
	{
		(*it)->setAlpha(_alpha);
	}
	for(auto it = compShips.begin(); it != compShips.end(); it++)
	{
		(*it)->setAlpha(_alpha);
	}
	for(auto it = dots.begin(); it != dots.end(); it++)
	{
		(*it)->setAlpha(_alpha);
	}
	for(auto it = crosses.begin(); it != crosses.end(); it++)
	{
		(*it)->setAlpha(_alpha);
	}
}

void GameManager::deleteAllShips(std::vector<Ship*>& ships)
{
	for(auto it = ships.begin(); it != ships.end(); it++)
		delete (*it);
	ships.erase(ships.begin(), ships.end());
}

void GameManager::deleteAllDots(std::vector<Dot*>& dots)
{
	for(auto it = dots.begin(); it != dots.end(); it++)
		delete (*it);
	dots.erase(dots.begin(), dots.end());
}

void GameManager::deleteAllCrosses(std::vector<Cross*>& crosses)
{
	for(auto it = crosses.begin(); it != crosses.end(); it++)
		delete (*it);
	crosses.erase(crosses.begin(), crosses.end());
}

void GameManager::onButtonNewGameClicked(GraphicsItem* obj, int button, int state, int x, int y)
{
	gameStatus = PLACING_SHIP;
	hideAllItems();
	btnMainMenu->setVisible(true);
	btnAuto->setVisible(true);
	btnClean->setVisible(true);
	btnFight->setVisible(true);
	playerField->setVisible(true);
	singleShip->setVisible(true);
	doubleShip->setVisible(true);
	tripleShip->setVisible(true);
	quadShip->setVisible(true);
	mouseShip->setVisible(true);
	textEditName->setVisible(true);
	mouseHint->setVisible(true);
	for(auto it = playerShips.begin(); it != playerShips.end(); it++)
		(*it)->setVisible(true);
}

void GameManager::onButtonNewGameRClicked(GraphicsItem * obj, int button, int state, int x, int y)
{
	onButtonNewGameClicked(obj, button, state, x, y);
	setAlpha(1.0);
	deleteAllShips(playerShips);
	deleteAllShips(compShips);
	deleteAllDots(dots);
	deleteAllCrosses(crosses);
	resultsTable->deleteData();
}

void GameManager::onButtonRecordsClicked(GraphicsItem* obj, int button, int state, int x, int y)
{
	hideAllItems();
	gameStatus = RECORDS;
	setAlpha(1.0);
	btnMainMenuRec->setVisible(true);
	records->setVisible(true);
	lblRecords->setVisible(true);
}

void GameManager::onButtonRecordsRClicked(GraphicsItem* obj, int button, int state, int x, int y)
{
	onButtonRecordsClicked(obj, button, state, x, y);
	deleteAllShips(playerShips);
	deleteAllShips(compShips);
	deleteAllDots(dots);
	deleteAllCrosses(crosses);
	resultsTable->deleteData();
}

void GameManager::onButtonAboutClicked(GraphicsItem* obj, int button, int state, int x, int y)
{
	hideAllItems();
	gameStatus = ABOUT;
	btnMainMenuA->setVisible(true);
	about->setVisible(true);
}

void GameManager::onButtonExitClicked(GraphicsItem* obj, int button, int state, int x, int y)
{
	exit(0);
}

void GameManager::onButtonMainMenuClicked(GraphicsItem* obj, int button, int state, int x, int y)
{
	gameStatus = MENU;
	hideAllItems();
	playerField->hideShips(playerShips);
	lblTitle->setVisible(true);
	btnNewGame->setVisible(true);
	btnRecords->setVisible(true);
	btnAbout->setVisible(true);
	btnExit->setVisible(true);
	mouseShip->setRect(Rect());
	if(currPressShip)
		currPressShip->setFocus(false);
}

void GameManager::onButtonMainMenuRClicked(GraphicsItem* obj, int button, int state, int x, int y)
{
	onButtonMainMenuClicked(obj, button, state, x, y);
	setAlpha(1.0);
	deleteAllShips(playerShips);
	deleteAllShips(compShips);
	deleteAllDots(dots);
	deleteAllCrosses(crosses);
	resultsTable->deleteData();
}

void GameManager::onButtonAutoClicked(GraphicsItem* obj, int button, int state, int x, int y)
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
	if(currPressShip)
		currPressShip->setFocus(false);
	mouseShip->setVisible(false);
}

void GameManager::onButtonCleanClicked(GraphicsItem* obj, int button, int state, int x, int y)
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

void GameManager::onButtonFightClicked(GraphicsItem* obj, int button, int state, int x, int y)
{
	if(playerField->getAliveShipsCount() == 10 && textEditName->getText() != "")
	{
		gameStatus = WAITING_PLAYER_STEP;
		compField->setRandomShips(compShips);
		compField->hideShips(compShips);	//Скрываем корабли компьютера
		hideAllItems();
		playerField->setVisible(true);
		compField->setVisible(true);
		btnGiveUp->setVisible(true);
		player->setName(textEditName->getText());
		lblPlayer->setText(player->getName());
		lblPlayer->getRect().setX(playerField->getRect().x() + playerField->getRect().width()/2 - lblPlayer->getText().size()*19/2);
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
}

void GameManager::onCompFieldClicked(GraphicsItem* obj, int button, int state, int x, int y)
{
	if(gameStatus == WAITING_PLAYER_STEP && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && compField->availableToPlaceDot(x, y, compShips, dots))
	{
		int newX = x / CELL_SZ * CELL_SZ, newY = y / CELL_SZ * CELL_SZ, w = 30, h = 30;
		dots.push_back(new Dot(40, Rect(newX, newY, w, h), nullptr, true));
		gameStatus = WAITING_COMP_STEP;
		lblPlayer->setRGBA(0.0, 0.0, 1.0, 1.0);
		lblComp->setRGBA(1.0, 0.5, 0.0, 1.0);
		player->setPointsK(100);
		player->setPoints(player->getPoints() + player->getPointsK());
	}
}

void GameManager::onSingleShipBtnClicked(GraphicsItem* obj, int button, int state, int x, int y)
{
	if(singleShip->getShips())
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
	if(doubleShip->getShips())
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
	if(tripleShip->getShips())
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
	if(quadShip->getShips())
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
				switch(deck)
				{
					case 1: (*singleShip)++; break;
					case 2: (*doubleShip)++; break;
					case 3: (*tripleShip)++; break;
					case 4: (*quadShip)++; break;
				}
				break;
			}
		}
	}
	if(gameStatus == WAITING_PLAYER_STEP && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && compField->availableToPlaceCross(x, y, crosses) && compField->contains(x, y))
	{
		int newX = x/CELL_SZ*CELL_SZ, newY = y/CELL_SZ*CELL_SZ, w = 30, h = 30;
		crosses.push_back(new Cross(Rect(newX, newY, w, h), nullptr, true));
		(*ship)--;
		player->incPointsK();
		player->setPoints(player->getPoints() + player->getPointsK());
		if(!ship->getHealths())
		{
			compField->placeDotsAroundShip(ship, compShips, dots);
			ship->setVisible(true);
			(*compField)--;
			player->incPointsK();
			if(!compField->getAliveShipsCount())
			{
				player->setPoints(player->getPoints() + 3000);
				gameStatus = RESULTS;
				showResults(player, playerField, playerShips, comp, compField, compShips);
			}
		}
	}
}

void GameManager::onButtonGiveUpClicked(GraphicsItem* obj, int button, int state, int x, int y)
{
	if(gameStatus == WAITING_PLAYER_STEP || gameStatus == WAITING_COMP_STEP)
	{
		gameStatus = RESULTS;
		showResults(comp, compField, compShips, player, playerField, playerShips, true);
	}
}

void GameManager::showResults(Player* winner, Field* winnerField, std::vector<Ship*>& winnerShips, Player* loser, Field* loserField, std::vector<Ship*>& loserShips, bool giveUp)
{
	alpha = 0.1;
	playerField->setAlpha(alpha);
	compField->setAlpha(alpha);
	btnGiveUp->setAlpha(alpha);
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
	if(giveUp)
	{
		lblWin->setText(loser->getName() + "GIVE UP");
	}
	else
	{
		lblWin->setText(winner->getName() + " WON!");
	}
	lblWin->setVisible(true);
	btnNewGameR->setVisible(true);
	btnRecordsR->setVisible(true);
	btnMainMenuR->setVisible(true);
	
	resultsTable->addData(0, 0, "NAME");
	resultsTable->addData(0, 1, "KILLED");
	resultsTable->addData(0, 2, "POINTS");
	double count = 0.0;
	for(auto it = loserShips.begin(); it != loserShips.end(); it++)
		count += (*it)->getHealths();
	count = 20.0 - count;
	resultsTable->addData(1, 0, winner->getName());
	resultsTable->addData(1, 1, std::to_string((int)(count / 20.0 * 100.0)) + "%");
	resultsTable->addData(1, 2, std::to_string(player->getPoints()));
	count = 0.0;
	for(auto it = winnerShips.begin(); it != winnerShips.end(); it++)
		count += (*it)->getHealths();
	count = 20.0 - count;
	resultsTable->addData(2, 0, loser->getName());
	resultsTable->addData(2, 1, std::to_string((int)(count / 20.0 * 100.0)) + "%");
	resultsTable->addData(2, 2, std::to_string(comp->getPoints()));
	resultsTable->setVisible(true);

	if(!giveUp)
	{
		Player* somePlayer1 = records->findPlayer(winner->getName());
		if(somePlayer1 == nullptr)
		{
			winner->incWins();
			winner->incGames();
			records->addNewUser(winner);
		}
		else
		{
			somePlayer1->incWins();
			somePlayer1->incGames();
			if(winner->getPoints() > somePlayer1->getPoints())
			{
				somePlayer1->setPoints(winner->getPoints());
			}
		}
		Player* somePlayer2 = records->findPlayer(loser->getName());
		if(somePlayer2 == nullptr)
		{
			loser->incGames();
			records->addNewUser(loser);
		}
		else
		{
			somePlayer2->incGames();
			if(loser->getPoints() > somePlayer2->getPoints())
			{
				somePlayer2->setPoints(loser->getPoints());
			}
		}
		records->sortByPoints();
		records->writePlayersToFile();
	}

	singleShip->setShips(4);
	doubleShip->setShips(3);
	tripleShip->setShips(2);
	quadShip->setShips(1);
	playerField->setAliveShipsCount(0);
	compField->setAliveShipsCount(0);
	player->setPoints(0);
	player->setPointsK(100);
	player->setWins(0);
	player->setGames(0);
	comp->setWins(0);
	player->setGames(0);
	comp->setPoints(0);
	player->setPointsK(100);
}

//Инициализация статических полей класса
GameStatus GameManager::gameStatus = MENU;
double GameManager::alpha = 1.0;
std::vector<GraphicsItem*> GameManager::items;
Label* GameManager::lblTitle;
Label* GameManager::lblPlayer;
Label* GameManager::lblComp;
Label* GameManager::lblRecords;
Label* GameManager::lblWin;
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
Button* GameManager::btnMainMenuRec;
Button* GameManager::btnMainMenuA;
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
Table* GameManager::resultsTable;
Records* GameManager::records;
HintIcon* GameManager::mouseHint;
About* GameManager::about;

std::vector<Ship*> GameManager::playerShips, GameManager::compShips;
std::vector<Ship*>::iterator GameManager::it;
std::vector<Dot*> GameManager::dots;
std::vector<Cross*> GameManager::crosses;