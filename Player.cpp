#include "Player.h"

Player::Player() : name(""), wins(0), games(0), r(0.0), g(0.0), b(0.0)
{

}

Player::Player(const std::string& _name, int _wins, int _games, double _r, double _g, double _b) : 
	name(_name), wins(_wins), games(_games), r(_r), g(_g), b(_b)
{

}

Player::~Player()
{

}