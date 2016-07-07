#pragma once
#pragma warning (disable: 4018)
#pragma warning (disable: 4305)
#pragma warning (disable: 4244)
#define WIN_WIDTH 841
#define WIN_HEIGHT 421
#define CELL_SZ 30
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

enum ObjName
{
	SingleShip = 1,
	DoubleShip,
	TripleShip,
	QuadShip,
	BtnNewGame,
	BtnRecords,
	BtnAbout,
	BtnExit,
	BtnFight,
	BtnAuto,
	BtnClean,
	PlayerField,
	CompField,
	MouseShip,
};

enum Orientation
{
	HORIZONTAL,
	VERTICAL
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