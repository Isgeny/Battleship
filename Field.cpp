#include "Field.h"

Field::Field() : GraphicsItem(), countOfPlacedShips(0)
{

}

Field::Field(int x, int y, int weight, int height, int countPl) : 
	GraphicsItem(x, y, weight, height), countOfPlacedShips(countPl)
{

}

Field::~Field()
{

}

void Field::setShip(GameStatus status, int x, int y, int weight, int height, int deck, MyPoint pos)
{
	ships.push_back(new Ship(x, y, weight, height, deck, pos));
}

void Field::setRandomShips()
{
	srand(time(NULL));
	int i = 0;
	while(i < 4)
	{
		int mX = rand() % width + x, mY = rand() % height + y, mW = 30, mH = 30, mDeck = 1;
		if(availableToPlaceShip(mX, mY, mW, mH, mDeck))
		{
			MyPoint temp = coordTransform(mX, mY);
			if(mW > mH && temp.j > (FIELD_SZ - mDeck))
				temp.j = FIELD_SZ - mDeck;
			if(mW < mH && temp.i >(FIELD_SZ - mDeck))
				temp.i = FIELD_SZ - mDeck;
			ships.push_back(new Ship(temp.j*CELL_SIZE + x, temp.i*CELL_SIZE + y, mW, mH, mDeck, temp));
			i++;
		}
	}
	i = 0;
	while(i < 3)
	{
		int mX = rand() % width + x, mY = rand() % height + y, mW = 60, mH = 30, mDeck = 2;
		if(availableToPlaceShip(mX, mY, mW, mH, mDeck))
		{
			MyPoint temp = coordTransform(mX, mY);
			if(mW > mH && temp.j > (FIELD_SZ - mDeck))
				temp.j = FIELD_SZ - mDeck;
			if(mW < mH && temp.i >(FIELD_SZ - mDeck))
				temp.i = FIELD_SZ - mDeck;
			ships.push_back(new Ship(temp.j*CELL_SIZE + x, temp.i*CELL_SIZE + y, mW, mH, mDeck, temp));
			i++;
		}
	}
	i = 0;
	while(i < 2)
	{
		int mX = rand() % width + x, mY = rand() % height + y, mW = 30, mH = 90, mDeck = 3;
		if(availableToPlaceShip(mX, mY, mW, mH, mDeck))
		{
			MyPoint temp = coordTransform(mX, mY);
			if(mW > mH && temp.j > (FIELD_SZ - mDeck))
				temp.j = FIELD_SZ - mDeck;
			if(mW < mH && temp.i >(FIELD_SZ - mDeck))
				temp.i = FIELD_SZ - mDeck;
			ships.push_back(new Ship(temp.j*CELL_SIZE + x, temp.i*CELL_SIZE + y, mW, mH, mDeck, temp));
			i++;
		}
	}
	i = 0;
	while(i < 1)
	{
		int mX = rand() % width + x, mY = rand() % height + y, mW = 30, mH = 120, mDeck = 4;
		if(availableToPlaceShip(mX, mY, mW, mH, mDeck))
		{
			MyPoint temp = coordTransform(mX, mY);
			if(mW > mH && temp.j > (FIELD_SZ - mDeck))
				temp.j = FIELD_SZ - mDeck;
			if(mW < mH && temp.i >(FIELD_SZ - mDeck))
				temp.i = FIELD_SZ - mDeck;
			ships.push_back(new Ship(temp.j*CELL_SIZE + x, temp.i*CELL_SIZE + y, mW, mH, mDeck, temp));
			i++;
		}
	}
}

void Field::makeHit(MyPoint pos, GameStatus status)
{
	//Удар по кораблям компьютера
}

std::vector<Ship*>& Field::getAllShips()
{
	return ships;
}

void Field::draw()
{
	//Рисование поля
	GraphicsItem::draw();
	//Рисование цифр
	for(int i = 1; i <= 9; i++)
	{
		glColor3d(0.0, 0.0, 1.0);
		glRasterPos2d(x - CELL_SIZE / 2 - 4, y + CELL_SIZE*i - 7);
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, std::to_string(i)[0]);
	}
	//Рисование цифры 10
	glRasterPos2d(x - CELL_SIZE / 2 - 9, y + CELL_SIZE * 10 - 7);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '1');
	glRasterPos2d(x - CELL_SIZE / 2 - 2, y + CELL_SIZE * 10 - 7);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0');
	//Рисование букв
	std::string alphabet = "ABCDEFGHKJ";
	for(int i = 0; i < alphabet.size(); i++)
	{
		glColor3d(0.0, 0.0, 1.0);
		glRasterPos2d(x + i*CELL_SIZE + 10, y - 10);
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, alphabet[i]);
	}
	//Рисование кораблей
	for(int i = 0; i < ships.size(); i++)
	{
		ships[i]->draw();
	}
}

bool Field::availableToPlaceShip(int mX, int mY, int mW, int mH, int mDeck)
{
	std::vector<Ship* >::iterator it;
	for(it = ships.begin(); it != ships.end(); it++)
	{
		for(int i = 0; i < mDeck; i++)
		{
			if((mW >= mH) && (mX + CELL_SIZE*i >= (*it)->getX() - CELL_SIZE) && (mX + CELL_SIZE*i <= (*it)->getX() + (*it)->getWidth() + CELL_SIZE) && (mY >= (*it)->getY() - CELL_SIZE) && (mY <= (*it)->getY() + (*it)->getHeight() + CELL_SIZE))
			{
				return false;
			}
			else if((mW <= mH) && (mX >= (*it)->getX() - CELL_SIZE) && (mX <= (*it)->getX() + (*it)->getWidth() + CELL_SIZE) && (mY + CELL_SIZE*i >= (*it)->getY() - CELL_SIZE) && (mY + CELL_SIZE*i <= (*it)->getY() + (*it)->getHeight() + CELL_SIZE))
			{
				return false;
			}
		}
	}
	return true;
}

void Field::cleanField()
{
	std::vector<Ship* > t = ships;
	std::vector<Ship* >::iterator it;
	ships.erase(ships.begin(), ships.end());
	for(it = t.begin(); it != t.end(); it++)
	{
		delete (*it);
	}
}

int Field::getCountOfPlacedShips() const
{
	return countOfPlacedShips;
}

void Field::setCountOfPlacedShips(int count)
{
	countOfPlacedShips = count;
}

void Field::incCountOfPlacedShips()
{
	countOfPlacedShips++;
}

void Field::decCountOfPlacedShips()
{
	countOfPlacedShips--;
}

MyPoint Field::coordTransform(int mX, int mY)
{
	//Перевод координат формы в координаты игрового поля
	MyPoint temp;
	if(mouseOnItem(mX, mY))
	{
		temp.i = (mY - y) / CELL_SIZE;
		temp.j = (mX - x) / CELL_SIZE;
		return temp;
	} 
	else
		return MyPoint();
}
