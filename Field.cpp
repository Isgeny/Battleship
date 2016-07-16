#include "Field.h"
#include "GameManager.h"

Field::Field() : aliveShipsCount(0), GraphicsItem()
{

}

Field::Field(int _aliveShipsCount, const Rect& rect, double r, double g, double b, double a, bool visible, CallbackClicked callbackClicked) :
	aliveShipsCount(_aliveShipsCount), GraphicsItem(rect, r, g, b, a, visible, callbackClicked)
{

}

Field::~Field()
{

}

void Field::draw()
{
	//Рисование цифр
	if(visible)
	{
		for(int i = 1; i <= 9; i++)
		{
			glColor4d(r, g, b, a);
			glRasterPos2d(rect.x() - CELL_SZ / 2 - 4, rect.y() + CELL_SZ*i - 7);
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, std::to_string(i)[0]);
		}
		//Рисование цифры 10
		glRasterPos2d(rect.x() - CELL_SZ / 2 - 9, rect.y() + CELL_SZ * 10 - 7);
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '1');
		glRasterPos2d(rect.x() - CELL_SZ / 2 - 2, rect.y() + CELL_SZ * 10 - 7);
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0');
		//Рисование букв
		std::string alphabet = "ABCDEFGHKJ";
		for(int i = 0; i < alphabet.size(); i++)
		{
			glColor4d(r, g, b, a);
			glRasterPos2d(rect.x() + i*CELL_SZ + 10, rect.y() - 10);
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, alphabet[i]);
		}
		//Рисование прямоугольника
		glLineWidth(3.0);
		glBegin(GL_LINE_LOOP);
		glColor4d(r, g, b, a);
		glVertex2d(rect.x() + rect.width(), rect.y() + rect.height());
		glVertex2d(rect.x() + rect.width(), rect.y());
		glVertex2d(rect.x(), rect.y());
		glVertex2d(rect.x(), rect.y() + rect.height());
		glEnd();
	}
}

void Field::mousePressed(int button, int state, int mouseX, int mouseY)
{
	GraphicsItem::mousePressed(button, state, mouseX, mouseY);
}

void Field::setAliveShipsCount(int _aliveShipsCount)
{
	aliveShipsCount = _aliveShipsCount;
}

int Field::getAliveShipsCount() const
{
	return aliveShipsCount;
}

void Field::operator++(int)
{
	aliveShipsCount++;
}

void Field::operator--(int)
{
	if(aliveShipsCount)
		aliveShipsCount--;
}

bool Field::availableToPlaceShip(std::vector<Ship*>& ships, Ship* mouseShip)
{
	//Проверка возможности установки корабля
	int newX = mouseShip->getRect().x() + CELL_SZ/2, newY = mouseShip->getRect().y() + CELL_SZ/2;
	for(auto it = ships.begin(); it != ships.end(); it++)
	{
		for(int i = 0; i < mouseShip->getDecks(); i++)
		{
			if(mouseShip->getOrientation() == HORIZONTAL && (*it)->mouseOnShipArea(newX + i*CELL_SZ, newY) || mouseShip->getOrientation() == VERTICAL && (*it)->mouseOnShipArea(newX, newY + i*CELL_SZ))
			{
				return false;
			}
		}
	}
	return true;
}

void Field::setRandomShips(std::vector<Ship*>& ships) //Рандомная расстановка кораблей
{
	while(aliveShipsCount < 10)
	{
		int rX = rand() % rect.width() + rect.x(), rY = rand() % rect.height() + rect.y(), x = rX / CELL_SZ * CELL_SZ, y = rY / CELL_SZ * CELL_SZ, width, height, decks;
		if(aliveShipsCount < 4)
			decks = 1;
		else if(aliveShipsCount >= 4 && aliveShipsCount < 7)
			decks = 2;
		else if(aliveShipsCount >= 7 && aliveShipsCount < 9)
			decks = 3;
		else if(aliveShipsCount == 9)
			decks = 4;
		int or = rand() % 2; Orientation orientation;
		if(or)
		{
			orientation = HORIZONTAL;
			width = decks*CELL_SZ;
			height = CELL_SZ;
			if(rX > rect.x() + FIELD_SZ*CELL_SZ - decks*CELL_SZ)
			{
				x = rect.x() + FIELD_SZ*CELL_SZ - decks*CELL_SZ;
			}
		} else
		{
			orientation = VERTICAL;
			width = CELL_SZ;
			height = decks*CELL_SZ;
			if(rY > rect.y() + FIELD_SZ*CELL_SZ - decks*CELL_SZ)
			{
				y = rect.y() + FIELD_SZ*CELL_SZ - decks*CELL_SZ;
			}
		}
		Rect areaRect; areaRect.setX(x - CELL_SZ); areaRect.setY(y - CELL_SZ); areaRect.setWidth(width + 2*CELL_SZ); areaRect.setHeight(height + 2*CELL_SZ);
		Ship* mouseShip = new Ship(decks, areaRect, Rect(x, y, width, height), 0.0, 0.0, 1.0, 1.0, true, GameManager::onShipClicked, orientation);
		mouseShip->setHealths(decks);
		if(availableToPlaceShip(ships, mouseShip))
		{
			ships.push_back(mouseShip);
			aliveShipsCount++;
		} 
		else
		{
			delete mouseShip;
		}
	}
}

void Field::hideShips(std::vector<Ship*>& ships)
{
	for(auto it = ships.begin(); it != ships.end(); it++)
	{
		(*it)->setVisible(false);
	}
}

bool Field::availableToPlaceDot(int mX, int mY, std::vector<Ship*>& ships, std::vector<Dot*>& dots)
{
	for(auto it = ships.begin(); it != ships.end(); it++)
	{
		if((*it)->contains(mX, mY))
		{
			return false;
		}
	}
	//Проверка наличия точки по координатам мыши
	for(auto it = dots.begin(); it != dots.end(); it++)
	{
		if((*it)->contains(mX, mY))
		{
			return false;
		}
	}
	return true;
}

bool Field::availableToPlaceCross(int mX, int mY, std::vector<Cross*>& crosses)
{
	for(auto it = crosses.begin(); it != crosses.end(); it++)
	{
		if((*it)->contains(mX, mY))
		{
			return false;
		}
	}
	return true;
}

void Field::placeDotsAroundShip(Ship* killedShip, std::vector<Ship*>& ships, std::vector<Dot*>& dots)
{
	int x = killedShip->getRect().x() - CELL_SZ/2, y = killedShip->getRect().y() - CELL_SZ/2;
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < killedShip->getDecks() + 2; j++)
		{
			if(killedShip->getOrientation() == HORIZONTAL && availableToPlaceDot(x + j*CELL_SZ, y + i*CELL_SZ, ships, dots) && contains(x + j*CELL_SZ, y + i*CELL_SZ))
			{
				dots.push_back(new Dot(40, Rect(x / CELL_SZ * CELL_SZ + j*CELL_SZ, y / CELL_SZ * CELL_SZ + i*CELL_SZ, CELL_SZ, CELL_SZ), 0.0, 0.0, 1.0, 1.0, true));
			} 
			else if(killedShip->getOrientation() == VERTICAL && availableToPlaceDot(x + i*CELL_SZ, y + j*CELL_SZ, ships, dots) && contains(x + i*CELL_SZ, y + j*CELL_SZ))
			{
				dots.push_back(new Dot(40, Rect(x / CELL_SZ * CELL_SZ + i*CELL_SZ, y / CELL_SZ * CELL_SZ + j*CELL_SZ, CELL_SZ, CELL_SZ), 0.0, 0.0, 1.0, 1.0, true));
			}
		}
	}
}




/*
void Field::setShip(Ship *mouseShip)
{
	ships.push_back(new Ship(*mouseShip));
	ships.back()->updateParts();
	ships.back()->setcallbackClicked(GameManager::onShipClicked);
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


bool Field::allShipsKilled() const
{
	for(auto itShips = ships.begin(); itShips != ships.end(); itShips++)
	{
		if((*itShips)->getAlive())
		{
			return false;
		}
	}
	return true;
}*/

