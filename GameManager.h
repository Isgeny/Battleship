#pragma once
#include <string>
#include <vector>
#include <map>
#include "freeglut.h"
#include "Button.h"
#include "Field.h"
#include "Ship.h"
#include "ShipButton.h"
#include "enums.h"

class GameManager
{
private:
	static GameStatus gameStatus;
	static const std::string title;
	static std::map<ObjName, GraphicsRectItem*> items;
	static Ship *mShip;
	static ShipButton *currPressShip;
	static Field *playerField, *compField;
	
public:
	GameManager();
	~GameManager();
	static void draw();
	static void mousePressed(int button, int state, int x, int y);
	static void mouseMove(int x, int y);
	static void mouseWheel(int button, int dir, int x, int y);

	static void setGameStatus(const GameStatus& status);
	static const GameStatus& getGameStatus();
	static void makeCompStep();

	static void hideAllItems();
	static void onButtonNewGameClicked();
	static void onButtonRecordsClicked();
	static void onButtonAbout();
	static void onButtonExitClicked();
	static void onButtonAutoClicked();
	static void onButtonCleanClicked();
	static void onButtonFightClicked();
	static void onPlayerFieldClicked();
	static void onCompFieldClicked();
	static void onSingleShipBtnClicked();
	static void onDoubleShipBtnClicked();
	static void onTripleShipBtnClicked();
	static void onQuadShipBtnClicked();
	static void onMouseShipClicked();
	
};