#pragma once
#pragma warning (disable: 4018)
#pragma warning (disable: 4305)
#pragma warning (disable: 4244)
#define WIN_WIDTH 841
#define WIN_HEIGHT 421
#define CELL_SZ 30
#define FIELD_SZ 10

enum ObjName
{
	SingleShipBtn = 1,
	DoubleShipBtn,
	TripleShipBtn,
	QuadShipBtn,
	BtnNewGame,
	BtnRecords,
	BtnAbout,
	BtnExit,
	BtnMainMenu,
	BtnFight,
	BtnAuto,
	BtnClean,
	PlayerField,
	CompField,
	MouseShip,
	TextEditName
};

enum Orientation
{
	HORIZONTAL,
	VERTICAL
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