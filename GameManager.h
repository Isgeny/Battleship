#pragma once
#include "Rect.h"
#include "GraphicsItem.h"
#include "Button.h"
#include "Field.h"
#include "Ship.h"
#include "ShipButton.h"
#include "TextEdit.h"
#include "Player.h"
#include "Dot.h"
#include "Cross.h"
#include "Table.h"
#include "Records.h"
#include "HintIcon.h"
#include "enums.h"

class GameManager
{
private:
	static GameStatus gameStatus;
	static double alpha;
	static std::vector<GraphicsItem*> items;
	static Label *lblTitle, *lblPlayer, *lblComp, *lblRecords, *lblWin;
	static Button *btnNewGame, *btnRecords, *btnAbout, *btnExit, *btnMainMenu, *btnAuto, *btnClean, *btnFight, *btnGiveUp, *btnNewGameR, *btnRecordsR, *btnMainMenuR, *btnMainMenuRec;
	static Field *playerField, *compField;
	static TextEdit *textEditName;
	static Ship *mouseShip;
	static ShipButton *singleShip, *doubleShip, *tripleShip, *quadShip;
	static ShipButton *currPressShip;
	static Player *player, *comp;
	static Table* resultsTable;
	static Records* records;
	static HintIcon* mouseHint;

	static std::vector<Ship*> playerShips, compShips;
	static std::vector<Ship*>::iterator it;
	static std::vector<Dot*> dots;
	static std::vector<Cross*> crosses;
	
public:
	GameManager();
	~GameManager();
	static void draw();
	static void resize(int width, int height);
	static void mouseClicked(int button, int state, int x, int y);
	static void mouseMove(int x, int y);
	static void mouseWheel(int button, int dir, int x, int y);
	static void keyboardPressed(unsigned char key, int x, int y);
	static void timerRedisplay(int);
	static void timerCompStep(int);
	static void timerTextEditCarriage(int);
	static void hideAllItems();
	static void setAlpha(int alpha);
	static void deleteAllShips(std::vector<Ship*>& ships);
	static void deleteAllDots(std::vector<Dot*>& dots);
	static void deleteAllCrosses(std::vector<Cross*>& crosses);
	static void onButtonNewGameClicked(GraphicsItem* obj, int button, int state, int x, int y);
	static void onButtonNewGameRClicked(GraphicsItem* obj, int button, int state, int x, int y);
	static void onButtonRecordsClicked(GraphicsItem* obj, int button, int state, int x, int y);
	static void onButtonRecordsRClicked(GraphicsItem* obj, int button, int state, int x, int y);
	static void onButtonAboutClicked(GraphicsItem* obj, int button, int state, int x, int y);
	static void onButtonExitClicked(GraphicsItem* obj, int button, int state, int x, int y);
	static void onButtonMainMenuClicked(GraphicsItem* obj, int button, int state, int x, int y);
	static void onButtonMainMenuRClicked(GraphicsItem* obj, int button, int state, int x, int y);
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
	static void showResults(Player* winner, Field* winnerField, std::vector<Ship*>& winnerShips, Player* loser, Field* loserField, std::vector<Ship*>& loserShips, bool giveUp = false);

};