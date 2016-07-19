#pragma once
#include "Table.h"
#include "Player.h"
#include "enums.h"

class Records : public Table 
{
private:
	std::vector<Player*> players;

public:
	Records(int rows, int columns, const Rect& rect, CallbackClicked callbackClicked = nullptr, bool visible = false, double r = 0.0, double g = 0.0, double b = 1.0, double a = 1.0);
	~Records();
	void draw();
	void readPlayersFromFile();
	void writePlayersToFile();
	void addNewUser(Player* player);
	Player* findPlayer(const std::string& name);
	void updateRecords();
	void sortByPoints();

};