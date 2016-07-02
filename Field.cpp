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
	field[pos.i][pos.j] = SHIP;
}

void Field::makeHit(MyPoint pos, GameStatus status)
{
	//Удар по кораблям противника
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
	for(int i = 0; i < FIELD_SZ; i++)
	{
		for(int j = 0; j < FIELD_SZ; j++)
		{
			switch(field[i][j])
			{
			case EMPTY:
				break;
			case SHIP:
				glBegin(GL_LINE_LOOP);
				glColor3d(0.0, 0.0, 1.0);
				glVertex2d(x + j*CELL_SIZE + CELL_SIZE, y + i*CELL_SIZE + CELL_SIZE);
				glVertex2d(x + j*CELL_SIZE + CELL_SIZE, y + i*CELL_SIZE);
				glVertex2d(x + j*CELL_SIZE, y + i*CELL_SIZE);
				glVertex2d(x + j*CELL_SIZE, y + CELL_SIZE + i*CELL_SIZE);
				glEnd();
				break;
			}
		}
	}
}

bool Field::mouseOnField(int mX, int mY)
{
	return (mX > x && mX < x + width && mY > y && mY < y + width);
}
