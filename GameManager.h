#pragma once
#include <string>
#include <vector>
#include <map>
#include "freeglut.h"
#include "Button.h"
#include "Field.h"
#include "Ship.h"
#include "PlacingShip.h"
#include "enums.h"

class GameManager
{
private:
	GameStatus gameStatus;
	const std::string title = "BATTLESHIP";
	std::map<ObjName, Button*> btn;
	std::map<ObjName, PlacingShip*> plShip;
	Field *playerField, *compField;
	Ship *mShip;
	PlacingShip *currPressShip;
	std::map<ObjName, GraphicsRectItem*> item;
	
public:
	GameManager();
	~GameManager();
	void draw();
	void drawCells();
	void mousePressed(int button, int state, int x, int y);
	void mouseMove(int x, int y);
	void mouseWheel(int button, int dir, int x, int y);
	void setGameStatus(const GameStatus& status);
	const GameStatus& getGameStatus() const;
	void makeCompStep();
	
};