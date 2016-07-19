#pragma once
#include <vector>
#include <fstream>
#include <iostream>
#include "Table.h"
#include "Player.h"

class Records : public Table
{
private:
	std::vector<Player*> players;

public:
	Records(int rows, int columns, const Rect& rect, double r = 1.0, double g = 1.0, double b = 1.0, double a = 1.0, bool visible = false, CallbackClicked callbackClicked = NULL);
	~Records();
	void draw();
	void readPlayersFromFile();
	void writePlayersToFile();
	void addNewUser(Player* player);
	Player* findPlayer(const std::string& name);
	void updateRecords();
	void sortByPoints();

};