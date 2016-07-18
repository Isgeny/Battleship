#pragma once
#include <string>
class Player
{
private:
	std::string name;
	int wins, games;
	int steps;
	double r, g, b, a;

public:
	Player();
	~Player();
	Player(const std::string& name, int wins = 0, int games = 0, double r = 0.0, double g = 0.0, double b = 1.0, double a = 1.0);
	void setName(const std::string& name);
	void setWins(int wins);
	void incWins();
	void setGames(int games);
	void incGames();
	void setSteps(int steps);
	void setRGBA(double r, double g, double b, double a);
	const std::string& getName() const;
	int getWins() const;
	int getGames() const;
	int getSteps() const;
	void operator ++ (int);
	friend std::istream& operator >> (std::istream& in, Player& p);
	friend std::ostream& operator << (std::ostream& out, Player& p);

};