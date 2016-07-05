#include "Field.h"

Field::Field() : GraphicsItem()
{
	field.resize(FIELD_SZ);
	for(int i = 0; i < FIELD_SZ; i++)
		field[i].resize(FIELD_SZ);
	for(int i = 0; i < FIELD_SZ; i++)
		for(int j = 0; j < FIELD_SZ; j++)
			field[i][j] = EMPTY;
}

Field::Field(int x, int y, int weight, int height) : 
	GraphicsItem(x, y, weight, height)
{
	field.resize(FIELD_SZ);
	for(int i = 0; i < FIELD_SZ; i++)
		field[i].resize(FIELD_SZ);
	for(int i = 0; i < FIELD_SZ; i++)
		for(int j = 0; j < FIELD_SZ; j++)
			field[i][j] = EMPTY;
}

Field::~Field()
{

}

void Field::setShip(GameStatus status, int x, int y, int weight, int height, int deck, MyPoint pos)
{
	ships.push_back(new Ship(x, y, weight, height, deck, pos));
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

bool Field::mouseOnShipArea(int mX, int mY)
{
	std::vector<Ship* >::iterator it;
	for(it = ships.begin(); it != ships.end(); it++)
	{
		if((mX > (*it)->getX() - CELL_SIZE) && (mX < (*it)->getX() + (*it)->getWidth() + CELL_SIZE) && (mY >(*it)->getY() - CELL_SIZE) && (mY < (*it)->getY() + (*it)->getHeight() + CELL_SIZE))
		{
			return true;
		}
	}
	return false;
}