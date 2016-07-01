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

std::vector<std::vector<Cell>>& Field::getField()
{
	return field;
}

void Field::setShip(MyPoint pos, GameStatus status)
{
	//Установка корабля
}

void Field::makeHit(MyPoint pos, GameStatus status)
{
	//Удар по кораблям противника
}

void Field::draw()
{
	//Рисование поля
	GraphicsItem::draw();
}