#pragma once
#include <string>
#include <vector>
#include "Button.h"
#include "Field.h"
#include "Ship.h"
#include "PlacingShip.h"
#include "freeglut.h"
#include "enums.h"

class GameManager
{
private:
	Button *btnNewGame, *btnRecords, *btnAbout, *btnExit, *btnAuto, *btnClean, *btnFight;
	Field *playerField, *compField;
	std::vector<GraphicsItem* > mainMenuItems, menuPlacingShipItems, gameProcess;
	std::vector<PlacingShip* > pShip;
	PlacingShip *currPressShip;
	Ship *mouseMovingShip;
	GameStatus gameStatus;

public:
	GameManager();
	~GameManager();
	GameStatus getGameStatus() const;
	void setGameStatus(GameStatus status);
	void mousePressed(int button, int state, int x, int y);
	void mouseMove(int x, int y);
	void mouseWheel(int button, int dir, int x, int y);
	void draw();
	void drawCells();
	void drawMainMenuItems();
	void drawPlacingShipMenuItems();

};