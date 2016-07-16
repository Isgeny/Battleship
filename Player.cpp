#include "Player.h"

Player::Player() : name(""), wins(0), games(0), r(0.0), g(0.0), b(1.0), a(1.0)
{

}

Player::Player(const std::string& _name, int _wins, int _games, double _r, double _g, double _b, double _a) : 
	name(_name), wins(_wins), games(_games), r(_r), g(_g), b(_b), a(_a)
{

}

Player::~Player()
{

}

void Player::setName(const std::string& _name)
{
	name = _name;
}

void Player::setWins(int _wins)
{
	wins = _wins;
}

void Player::setGames(int _games)
{
	games = _games;
}

void Player::setRGBA(double _r, double _g, double _b, double _a)
{
	r = _r; g = _g; b = _b; a = _a;
}

const std::string & Player::getName() const
{
	return name;
}

int Player::getWins() const
{
	return wins;
}

int Player::getGames() const
{
	return games;
}

void Player::readDataFromFile()
{

}