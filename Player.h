#pragma once
#include "enums.h"

class Player
{
private:
	std::string name;
	int wins, games;
	int points, pointsK;

public:
	Player();
	~Player();
	Player(const std::string& name, int wins = 0, int games = 0, int points = 0, int pointsK = 100);
	void setName(const std::string& name);
	void setWins(int wins);
	void incWins();
	void setGames(int games);
	void incGames();
	void setPoints(int points);
	void setPointsK(int pointsK);
	void incPointsK();
	const std::string& getName() const;
	int getWins() const;
	int getGames() const;
	int getPoints() const;
	int getPointsK() const;
	friend std::istream& operator >> (std::istream& in, Player& p);
	friend std::ostream& operator << (std::ostream& out, Player& p);

};