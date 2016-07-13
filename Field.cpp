#include "Field.h"
#include "GameManager.h"

Field::Field(int x, int y, int width, int height, bool visible, bool clicked, void (*callbackClickedFunc)(GraphicsRectItem*, int button, int state), int _placedShipsCount, const std::string& _playerName, double _pR, double _pG, double _pB) :
	GraphicsRectItem(x, y, width, height, visible, clicked, callbackClickedFunc), placedShipsCount(_placedShipsCount), playerName(_playerName), pR(_pR), pG(_pG), pB(_pB)
{

}

Field::~Field()
{
	for(auto it = ships.begin(); it != ships.end(); it++)
		delete (*it);
	for(auto it = dots.begin(); it != dots.end(); it++)
		delete (*it);
}

void Field::draw()
{
	if(visible)
	{
		GraphicsRectItem::draw();
		//Рисование цифр
		for(int i = 1; i <= 9; i++)
		{
			glColor3d(0.0, 0.0, 1.0);
			glRasterPos2d(x - CELL_SZ / 2 - 4, y + CELL_SZ*i - 7);
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, std::to_string(i)[0]);
		}
		//Рисование цифры 10
		glRasterPos2d(x - CELL_SZ / 2 - 9, y + CELL_SZ * 10 - 7);
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '1');
		glRasterPos2d(x - CELL_SZ / 2 - 2, y + CELL_SZ * 10 - 7);
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0');
		//Рисование букв
		std::string alphabet = "ABCDEFGHKJ";
		for(int i = 0; i < alphabet.size(); i++)
		{
			glColor3d(0.0, 0.0, 1.0);
			glRasterPos2d(x + i*CELL_SZ + 10, y - 10);
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, alphabet[i]);
		}
		//Рисование имени игрока
		for(int i = 0; i < playerName.size(); i++)
		{
			glColor3f(pR, pG, pB);
			glRasterPos2d(x + width/2 + i*20 - playerName.size() * 19/2, y - 40);
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, playerName[i]);
		}
		//Рисование кораблей
		for(auto it = ships.begin(); it != ships.end(); it++)
			(*it)->draw();
		//Рисование точек
		for(auto it = dots.begin(); it != dots.end(); it++)
			(*it)->draw();
	}
}

void Field::setPlacedShipsCount(int aPlacedShipsCount)
{
	placedShipsCount = aPlacedShipsCount;
}

void Field::setPlayerName(const std::string & _playerName)
{
	playerName = _playerName;
}

void Field::setPlayerNameRGB(double _r, double _g, double _b)
{
	pR = _r; pG = _g; pB = _b;
}

int Field::getPlacedShipsCount() const
{
	return placedShipsCount;
}

const std::string & Field::getPlayerName() const
{
	return playerName;
}

std::vector<Ship*>& Field::getShips()
{
	return ships;
}

std::vector<Dot*>& Field::getDots()
{
	return dots;
}

void Field::operator++(int)
{
	placedShipsCount++;
}

void Field::operator--(int)
{
	if(placedShipsCount)
		placedShipsCount--;
}

bool Field::availableToPlaceShip(Ship* mShip)
{
	//Проверка возможности установки корабля
	int newX = mShip->getX() + CELL_SZ / 2, newY = mShip->getY() + CELL_SZ / 2;
	for(auto it = ships.begin(); it != ships.end(); it++)
	{
		for(int i = 0; i < mShip->getDeckCount(); i++)
		{
			if(mShip->getOrientation() == HORIZONTAL && (*it)->mouseOnShipArea(newX + i*CELL_SZ, newY) || mShip->getOrientation() == VERTICAL && (*it)->mouseOnShipArea(newX, newY + i*CELL_SZ))
			{
				return false;
			}
		}
	}
	return true;
}

bool Field::availableToMakeHit(int mX, int mY)
{
	//Проверка наличия уничтоженного корабля по координатам мыши
	for(auto it = ships.begin(); it != ships.end(); it++)
	{
		for(auto itPart = (*it)->getParts().begin(); itPart != (*it)->getParts().end(); itPart++)
		{
			if((*itPart)->mouseOnItem(mX, mY) && !(*itPart)->getAlive())
			{
				return false;
			}
		}
	}
	//Проверка наличия точки по координатам мыши
	for(auto it = dots.begin(); it != dots.end(); it++)
	{
		if((*it)->mouseOnItem(mX, mY))
		{
			return false;
		}
	}
	return true;
}

void Field::setShip(Ship *mouseShip)
{
	ships.push_back(new Ship(mouseShip));
	ships.back()->updateParts();
	ships.back()->setCallbackClickedFunc(GameManager::onShipClicked);
}

void Field::cleanField() //Удаление кораблей и точек с поля
{
	for(auto it = ships.begin(); it != ships.end(); it++)
		delete (*it);
	for(auto it = dots.begin(); it != dots.end(); it++)
		delete (*it);
	ships.erase(ships.begin(), ships.end());
	dots.erase(dots.begin(), dots.end());
	placedShipsCount = 0;
}

void Field::setRandomShips() //Рандомная расстановка кораблей
{
	while(placedShipsCount < 10)
	{
		int rX = rand() % width + x, rY = rand() % height + y, x = rX / CELL_SZ * CELL_SZ, y = rY / CELL_SZ * CELL_SZ, width, height, deckCount;
		if(placedShipsCount < 4)
			deckCount = 1;
		else if(placedShipsCount >= 4 && placedShipsCount < 7)
			deckCount = 2;
		else if(placedShipsCount >= 7 && placedShipsCount < 9)
			deckCount = 3;
		else if(placedShipsCount == 9)
			deckCount = 4;
		int or = rand() % 2; Orientation orientation;
		if(or)
		{
			orientation = HORIZONTAL;
			width = deckCount * CELL_SZ;
			height = CELL_SZ;
			if(rX > this->x + FIELD_SZ*CELL_SZ - deckCount*CELL_SZ)
			{
				x = this->x + FIELD_SZ*CELL_SZ - deckCount*CELL_SZ;
			}	
		}
		else
		{
			orientation = VERTICAL;
			width = CELL_SZ;
			height = deckCount * CELL_SZ;
			if(rY > this->y + FIELD_SZ*CELL_SZ - deckCount*CELL_SZ)
			{
				y = this->y + FIELD_SZ*CELL_SZ - deckCount*CELL_SZ;
			}
		}
		int areaX = x - CELL_SZ, areaY = y - CELL_SZ, areaWidth = width + 2*CELL_SZ, areaHeight = height + 2*CELL_SZ;
		Ship* mShip = new Ship(x, y, width, height, true, false, NULL, deckCount, orientation, true, areaX, areaY, areaWidth, areaHeight);
		if(this->availableToPlaceShip(mShip))
		{
			this->setShip(mShip);
			this->placedShipsCount++;
		}
		else
			delete mShip;
	}
}

void Field::hideShips()
{
	for(auto it = ships.begin(); it != ships.end(); it++)
		(*it)->setVisible(false);
}

void Field::makeHit(int mX, int mY)
{
	for(auto itShip = ships.begin(); itShip != ships.end(); itShip++)
	{
		if((*itShip)->mouseOnItem(mX, mY))
		{
			for(auto itPart = (*itShip)->getParts().begin(); itPart != (*itShip)->getParts().end(); itPart++)
			{
				if((*itPart)->mouseOnItem(mX, mY))
				{
					(*itPart)->setAlive(false);
					if((*itShip)->allPartsKilled())
					{
						(*itShip)->setAlive(false);
						(*itShip)->setVisible(true);
						this->placeDotsAroundShip((*itShip));
					}
					return;
				}
			}
		}
		
	}
	dots.push_back(new Dot(mX / CELL_SZ * CELL_SZ, mY / CELL_SZ * CELL_SZ, CELL_SZ, CELL_SZ, true, false, NULL));
}

void Field::placeDotsAroundShip(Ship* killedShip)
{
	int x = killedShip->getX() - CELL_SZ / 2, y = killedShip->getY() - CELL_SZ / 2;
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < killedShip->getDeckCount() + 2; j++)
		{
			if(killedShip->getOrientation() == HORIZONTAL && this->availableToMakeHit(x + j*CELL_SZ, y + i*CELL_SZ) && this->mouseOnItem(x + j*CELL_SZ, y + i*CELL_SZ))
			{
				dots.push_back(new Dot(x / CELL_SZ * CELL_SZ + j*CELL_SZ, y / CELL_SZ * CELL_SZ + i*CELL_SZ, CELL_SZ, CELL_SZ, true, false, NULL));
			}
			else if(killedShip->getOrientation() == VERTICAL && this->availableToMakeHit(x + i*CELL_SZ, y + j*CELL_SZ) && this->mouseOnItem(x + i*CELL_SZ, y + j*CELL_SZ))
			{
				dots.push_back(new Dot(x / CELL_SZ * CELL_SZ + i*CELL_SZ, y / CELL_SZ * CELL_SZ + j*CELL_SZ, CELL_SZ, CELL_SZ, true, false, NULL));
			}
		}
	}
}