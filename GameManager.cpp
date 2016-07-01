#include "GameManager.h"

GameManager::GameManager() : gameStatus(MENU)
{
	bVec.push_back(new Button(300, 60, 240, 60, "New game"));
	bVec.push_back(new Button(300, 150, 240, 60, "Records"));
	bVec.push_back(new Button(300, 240, 240, 60, "About"));
	bVec.push_back(new Button(300, 330, 240, 60, "Exit"));
	playerField = new Field(60, 60, 300, 300);
	compField   = new Field(510, 60, 300, 300);
}

GameManager::~GameManager()
{
	for(int i = 0; i < bVec.size(); i++)
		delete bVec[i];
	delete playerField;
	delete compField;
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
	switch(gameStatus)
	{
	case MENU: 
		if(button == GLUT_LEFT_BUTTON && state == GLUT_UP)
		{
			if(bVec[0]->mouseOnButton(x, y))
				gameStatus = PLACING_SHIP;
			else
			if(bVec[1]->mouseOnButton(x, y))
				gameStatus = RECORDS;
			else
			if(bVec[2]->mouseOnButton(x, y))
				gameStatus = ABOUT;
			else
			if(bVec[3]->mouseOnButton(x, y))
				exit(0);
		}
		break;
	case PLACING_SHIP:
		if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && playerField->mouseClicked(x, y))
		{
			playerField->setShip(this->coordTranform(x, y), PLACING_SHIP);
		}
		break;
	case WAITING_PLAYER_STEP:
		break;
	case WAITING_COMP_STEP:
		break;
	}
}

void GameManager::drawCells()
{
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

void GameManager::drawGameTitle()
{
	std::string title = "BATTLESHIP";
	int space = 20;
	for(int i = 0; i < title.size(); i++)
	{
		glColor3d(0.0, 0.0, 1.0);
		glRasterPos2d(325 + i*space, 40);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, title[i]);
	}
}

void GameManager::drawButtons()
{
	for(int i = 0; i < bVec.size(); i++)
	{
		bVec[i]->draw();
	}
}

void GameManager::drawFields()
{
	playerField->draw();
	compField->draw();
}

MyPoint GameManager::coordTranform(int mX, int mY)
{
	MyPoint point;
	if((gameStatus == PLACING_SHIP) && (playerField->mouseClicked(mX, mY)))
	{
		point.i = (mY - playerField->getY()) / CELL_SIZE;
		point.j = (mX - playerField->getX()) / CELL_SIZE;
		return point;
	}
	else if((gameStatus == WAITING_PLAYER_STEP) && (compField->mouseClicked(mX, mY)))
	{
		point.i = (mY - compField->getY()) / CELL_SIZE;
		point.j = (mX - compField->getX()) / CELL_SIZE;
		return point;
	}
}