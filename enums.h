#pragma once
#pragma warning (disable: 4018)
#pragma warning (disable: 4305)
#pragma warning (disable: 4244)
#define WIN_WIDTH 841
#define WIN_HEIGHT 421
#define CELL_SZ 30
#define FIELD_SZ 10
#define LIMIT_GENERATING 100000

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
	BtnGiveUp,
	BtnMainMenuR,
	BtnMainMenuRec,
	BtnRecordsR,
	BtnNewGameR,
	PlayerField,
	CompField,
	MouseShip,
	TextEditName,
	LblTitle,
	LblPlayer,
	LblComp,
	LblTableName,
	LblTableKilled,
	LblTableWins,
	LblTableGames,
	ResultsTable,
	RecordsTable
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
	WAITING_COMP_STEP,
	RESULTS
};