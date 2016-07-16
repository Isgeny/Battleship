#pragma once
#include <string>
class Player
{
private:
	std::string name;
	int wins, games;
	double r, g, b, a;

public:
	Player();
	~Player();
	Player(const std::string& name, int wins = 0, int games = 0, double r = 0.0, double g = 0.0, double b = 1.0, double a = 1.0);
	void setName(const std::string& name);
	void setWins(int wins);
	void setGames(int games);
	void setRGBA(double r, double g, double b, double a);
	const std::string& getName() const;
	int getWins() const;
	int getGames() const;
	void readDataFromFile();

};