#pragma once
#include <string>
#include <vector>
#include "Button.h"
#include "Field.h"
#include "freeglut.h"
#include "enums.h"

class GameManager
{
private:
	std::vector<Button* > bVec;
	Field *playerField, *compField;
	GameStatus gameStatus;
	int mX, mY;

public:
	GameManager();
	~GameManager();
	GameStatus getGameStatus() const;
	void setGameStatus(GameStatus status);
	void mousePressed(int button, int state, int x, int y);
	void drawCells();
	void drawGameTitle();
	void drawButtons();
	void drawFields();

};