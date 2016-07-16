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
#include "Player.h"
#include "Dot.h"
#include "Cross.h"
#include "enums.h"

class GameManager
{
private:
	static GameStatus gameStatus;
	static std::map<ObjName, GraphicsItem*> items;
	static Label *lblTitle, *lblPlayer, *lblComp;
	static Button *btnNewGame, *btnRecords, *btnAbout, *btnExit, *btnMainMenu, *btnAuto, *btnClean, *btnFight, *btnGiveUp, *btnNewGameR, *btnRecordsR, *btnMainMenuR;
	static Field *playerField, *compField;
	static TextEdit *textEditName;
	static Ship *mouseShip;
	static ShipButton *singleShip, *doubleShip, *tripleShip, *quadShip;
	static ShipButton *currPressShip;
	static Player *player, *comp, *winner, *loser;
	static std::vector<Ship*> playerShips, compShips;
	static std::vector<Ship*>::iterator it;
	static std::vector<Dot*> dots;
	static std::vector<Cross*> crosses;
	static double alpha;
	//static Records* records;
	
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
	static void hideAllItems();
	static void onButtonNewGameClicked(GraphicsItem* obj, int button, int state, int x, int y);
	static void onButtonRecordsClicked(GraphicsItem* obj, int button, int state, int x, int y);
	static void onButtonAboutClicked(GraphicsItem* obj, int button, int state, int x, int y);
	static void onButtonExitClicked(GraphicsItem* obj, int button, int state, int x, int y);
	static void onButtonMainMenuClicked(GraphicsItem* obj, int button, int state, int x, int y);
	static void onButtonAutoClicked(GraphicsItem* obj, int button, int state, int x, int y);
	static void onButtonCleanClicked(GraphicsItem* obj, int button, int state, int x, int y);
	static void onButtonFightClicked(GraphicsItem* obj, int button, int state, int x, int y);
	static void onPlayerFieldClicked(GraphicsItem* obj, int button, int state, int x, int y);
	static void onCompFieldClicked(GraphicsItem* obj, int button, int state, int x, int y);
	static void onSingleShipBtnClicked(GraphicsItem* obj, int button, int state, int x, int y);
	static void onDoubleShipBtnClicked(GraphicsItem* obj, int button, int state, int x, int y);
	static void onTripleShipBtnClicked(GraphicsItem* obj, int button, int state, int x, int y);
	static void onQuadShipBtnClicked(GraphicsItem* obj, int button, int state, int x, int y);
	static void onTextEditClicked(GraphicsItem* obj, int button, int state, int x, int y);
	static void onShipClicked(GraphicsItem* obj, int button, int state, int x, int y);
	static void onButtonGiveUpClicked(GraphicsItem* obj, int button, int state, int x, int y);
	static void showResults(Player* winner, Player* loser);

};