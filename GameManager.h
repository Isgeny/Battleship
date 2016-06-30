#pragma once
#include <string>
#include "freeglut.h"
#define WIN_WIDTH 871
#define WIN_HEIGHT 421
#define CELL_SIZE 30

enum GameStatus
{
	MENU,
	PLACING_SHIP,
	WAITING_PLAYER_STEP,
	WAITING_COMP_STEP
};

class GameManager
{
private:
	GameStatus status;

public:
	GameManager();
	GameStatus getGameStatus() const;
	void setGameStatus(GameStatus status);
	void drawGameTitle();
	void drawCells();

};