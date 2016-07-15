#pragma once
#include <string>
class Player
{
private:
	std::string name;
	int wins, games;
	double r, g, b;

public:
	Player();
	~Player();
	Player(const std::string& name, int wins, int games, double r, double g, double b);
	void setName(const std::string& name);
	void setWins(int wins);
	void setGames(int games);
	void setRGB(double r, double g, double b);
	const std::string& getName() const;
	int getWins() const;
	int getGames() const;
	double getR() const;
	double getG() const;
	double getB() const;
	void readDataFromFile();

};

