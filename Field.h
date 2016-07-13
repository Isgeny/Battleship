#pragma once
#include <vector>
#include <string>
#include "GraphicsRectItem.h"
#include "Ship.h"
#include "Dot.h"

class Field : public GraphicsRectItem
{
private:
	int placedShipsCount;
	std::vector<Ship*> ships;
	std::vector<Dot*> dots;
	std::string playerName;
	double pR, pG, pB;
	int playerStepCount;

public:
	Field(int x, int y, int weight, int height, bool visible, bool clicked, void (*callbackClickedFunc)(GraphicsRectItem*, int button, int state), int placedShipsCount, const std::string& playerName, double pR = 0.0, double pG = 0.0, double pB = 1.0, int playerStepCount = 0);
	~Field();
	void draw();
	void setPlacedShipsCount(int placedShipsCount);
	void setPlayerName(const std::string& playerName);
	void setPlayerNameRGB(double r, double g, double b);
	void setPlayerStepCount(int playerStepCount);
	void incPlayerStepCount();
	int getPlacedShipsCount() const;
	const std::string& getPlayerName() const;
	std::vector<Ship*>& getShips();
	std::vector<Dot*>& getDots();
	int getPlayerStepCount() const;
	bool availableToPlaceShip(Ship* mShip);
	bool availableToMakeHit(int mX, int mY);
	void setShip(Ship *mouseShip);
	void cleanField();
	void operator++(int);
	void operator--(int);
	void setRandomShips();
	void hideShips();
	void makeHit(int mX, int mY);
	void placeDotsAroundShip(Ship* killedShip);
	
};