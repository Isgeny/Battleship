#pragma once
#pragma warning (disable: 4018)
#define WIN_WIDTH 841
#define WIN_HEIGHT 421
#define CELL_SIZE 30
#define FIELD_SZ 10

struct MyPoint
{
	int i, j;

	MyPoint() : i(0), j(0)
	{

	}

	MyPoint(int posI, int posJ) : i(posI), j(posJ)
	{

	}

};

enum Cell
{
	EMPTY,
	SHIP,
	SHIP_AREA,
	DOT
};

enum GameStatus
{
	MENU,
	RECORDS,
	ABOUT,
	PLACING_SHIP,
	WAITING_PLAYER_STEP,
	WAITING_COMP_STEP
};