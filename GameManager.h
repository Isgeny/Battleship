#pragma once
#include <string>
#include <map>
#include "freeglut.h"
#include "Button.h"
#include "Field.h"
#include "Ship.h"
#include "ShipButton.h"
#include "TextEdit.h"
#include "Records.h"
#include "enums.h"

class GameManager
{
private:
	static GameStatus gameStatus;
	static const std::string title;
	static std::string winnerName, loserName;
	static std::map<ObjName, GraphicsRectItem*> items;
	static Ship *mShip;
	static ShipButton *currPressShip;
	static Field *playerField, *compField;
	static TextEdit* textEditName;
	static Records* records;
	
public:
	GameManager();
	~GameManager();
	static void draw();
	static void mouseClicked(int button, int state, int x, int y);
	static void mouseMove(int x, int y);
	static void mouseWheel(int button, int dir, int x, int y);
	static void keyboardPressed(unsigned char key, int x, int y);
	static void timerRedisplay(int);
	static void timerCompStep(int);

	static void setGameStatus(const GameStatus& status);
	static const GameStatus& getGameStatus();

	static void hideAllItems();
	static void onButtonNewGameClicked(GraphicsRectItem* obj, int button, int state);
	static void onButtonRecordsClicked(GraphicsRectItem* obj, int button, int state);
	static void onButtonAbout(GraphicsRectItem* obj, int button, int state);
	static void onButtonExitClicked(GraphicsRectItem* obj, int button, int state);
	static void onButtonMainMenuClicked(GraphicsRectItem* obj, int button, int state);
	static void onButtonAutoClicked(GraphicsRectItem* obj, int button, int state);
	static void onButtonCleanClicked(GraphicsRectItem* obj, int button, int state);
	static void onButtonFightClicked(GraphicsRectItem* obj, int button, int state);
	static void onPlayerFieldClicked(GraphicsRectItem* obj, int button, int state);
	static void onCompFieldClicked(GraphicsRectItem* obj, int button, int state);
	static void onSingleShipBtnClicked(GraphicsRectItem* obj, int button, int state);
	static void onDoubleShipBtnClicked(GraphicsRectItem* obj, int button, int state);
	static void onTripleShipBtnClicked(GraphicsRectItem* obj, int button, int state);
	static void onQuadShipBtnClicked(GraphicsRectItem* obj, int button, int state);
	static void onTextEditClicked(GraphicsRectItem* obj, int button, int state);
	static void onShipClicked(GraphicsRectItem* obj, int button, int state);
	static void onButtonGiveUp(GraphicsRectItem* obj, int button, int state);
	static void showResults(const std::string& winnerName, const std::string& loserName);

};