#pragma once
#pragma warning (disable: 4018)
#pragma warning (disable: 4305)
#pragma warning (disable: 4244)

#include "freeglut.h"
#include <string>
#include <vector>
#include <cmath>
#include <fstream>
#include <iostream>

#define WIN_WIDTH 871
#define WIN_HEIGHT 421
#define CELL_SZ 30
#define FIELD_SZ 10
#define LIMIT_GENERATING 100000

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