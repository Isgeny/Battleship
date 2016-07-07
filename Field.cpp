#include "Field.h"

Field::Field() : GraphicsRectItem(), placedShipsCount(0)
{

}

Field::Field(int aX, int aY, int aWeight, int aHeight, int aPlacedShipsCount) :
	GraphicsRectItem(aX, aY, aWeight, aHeight), placedShipsCount(aPlacedShipsCount)
{

}

Field::~Field()
{

}

void Field::draw()
{
	//Рисование поля
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
	//Рисование кораблей
	for(int i = 0; i < ships.size(); i++)
	{
		ships[i]->draw();
	}
}

void Field::setPlacedShipsCount(int aPlacedShipsCount)
{
	placedShipsCount = aPlacedShipsCount;
}

int Field::getPlacedShipsCount() const
{
	return placedShipsCount;
}

std::vector<Ship*>& Field::getShips()
{
	return ships;
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

bool Field::availableToPlaceShip(Ship* mouseShip)
{
	//Проверка возможности установки корабля
	int beginX = mouseShip->getX() + CELL_SZ / 2, beginY = mouseShip->getY() + CELL_SZ / 2, mDeck = mouseShip->getDeckCount();
	Orientation orient = mouseShip->getOrientation();
	for(auto it = ships.begin(); it != ships.end(); it++)
	{
		for(int i = 0; i < mDeck; i++)
		{
			if(orient == HORIZONTAL && (*it)->mouseOnShipArea(beginX + i*CELL_SZ, beginY) || orient == VERTICAL && (*it)->mouseOnShipArea(beginX, beginY + i*CELL_SZ))
			{
				return false;
			}
		}
	}
	return true;
}

void Field::setShip(Ship* mouseShip)
{
	//Установка корабля на поле
	ships.push_back(new Ship(mouseShip));
}

void Field::cleanField()
{
	//Очистка поля
	for(auto it = ships.begin(); it != ships.end(); it++)
		delete *it;
	ships.erase(ships.begin(), ships.end());
	placedShipsCount = 0;
}

void Field::setRandomShips()
{
	//Рандомная расстановка кораблей
	srand(time(NULL));
	Ship* compMouseShip = new Ship;
	while(placedShipsCount < 10)
	{
		int rX = (rand() % width) + x, rY = (rand() % height) + y, deck;
		int newX = rX / CELL_SZ * CELL_SZ, newY = rY / CELL_SZ * CELL_SZ;
		if(placedShipsCount < 4)
			deck = 1;
		else if(placedShipsCount >= 4 && placedShipsCount < 7)
			deck = 2;
		else if(placedShipsCount >= 7 && placedShipsCount < 9)
			deck = 3;
		else if(placedShipsCount == 9)
			deck = 4;
		bool boolOrient = rand() % 2; Orientation orient;
		if(boolOrient)
		{
			orient = HORIZONTAL;
			compMouseShip->setWidth(CELL_SZ*deck);
			compMouseShip->setHeight(CELL_SZ);
		}
		else
		{
			orient = VERTICAL;
			compMouseShip->setWidth(CELL_SZ);
			compMouseShip->setHeight(CELL_SZ*deck);
		}
		compMouseShip->setOrientation(orient);
		compMouseShip->setVisiable(true);
		compMouseShip->setDeckCount(deck);
		if(orient == HORIZONTAL && rX > x + FIELD_SZ*CELL_SZ - deck*CELL_SZ)
			newX = x + FIELD_SZ*CELL_SZ - deck*CELL_SZ;
		else if(orient == VERTICAL && rY > y + FIELD_SZ*CELL_SZ - deck*CELL_SZ)
			newY = y + FIELD_SZ*CELL_SZ - deck*CELL_SZ;
		compMouseShip->setX(newX);
		compMouseShip->setY(newY);
		compMouseShip->setArea(newX, newY);
		if(this->availableToPlaceShip(compMouseShip))
		{
			this->setShip(compMouseShip);
			placedShipsCount++;
		}
	}
	delete compMouseShip;
}

void Field::makeHit(int mX, int mY)
{
	//Удар по кораблям противника
}