#include "Player.h"

Player::Player() : name(""), wins(0), games(0), points(0), pointsK(100)
{

}

Player::Player(const std::string& _name, int _wins, int _games, int _points, int _pointsK) : 
	name(_name), wins(_wins), games(_games), points(_points), pointsK(_pointsK)
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

void Player::incWins()
{
	wins++;
}

void Player::setGames(int _games)
{
	games = _games;
}

void Player::incGames()
{
	games++;
}

void Player::setPoints(int _points)
{
	points = _points;
}

void Player::setPointsK(int _pointsK)
{
	pointsK = _pointsK;
}

void Player::incPointsK()
{
	pointsK += 100;
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

int Player::getPoints() const
{
	return points;
}

int Player::getPointsK() const
{
	return pointsK;
}

std::istream& operator >> (std::istream& in, Player& p)
{
	in >> p.name >> p.points >> p.wins  >> p.games;
	return in;
}

std::ostream& operator << (std::ostream& out, Player& p)
{
	out << p.name << ' ' << p.points << ' ' << p.wins << ' ' << p.games;
	return out;
}