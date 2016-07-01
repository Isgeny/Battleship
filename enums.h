#pragma once
#define WIN_WIDTH 841
#define WIN_HEIGHT 421
#define CELL_SIZE 30
#define FIELD_SZ 10

struct MyPoint
{
	int x, y;
};

enum Cell
{
	EMPTY,
	SHIP,
	KILLED_SHIP,
	DOT
};

enum GameStatus
{
	MENU,
	PLACING_SHIP,
	WAITING_PLAYER_STEP,
	WAITING_COMP_STEP
};