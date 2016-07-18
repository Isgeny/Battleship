#include "Records.h"

Records::Records(int rows, int columns, const Rect& rect, double r, double g, double b, double a, bool visible, CallbackClicked callbackClicked) :
	Table(rows, columns, rect, r, g, b, a, visible, callbackClicked)
{
	readPlayersFromFile();
	writePlayersToFile();
}

Records::~Records()
{
	for(auto it = players.begin(); it != players.end(); it++)
		delete (*it);
}

void Records::draw()
{
	Table::draw();
}

void Records::readPlayersFromFile()
{
	std::ifstream input;
	input.open("Records.txt");
	while(!input.eof())
	{
		Player *temp = new Player;
		input >> *temp;
		players.push_back(temp);
	}
	input.close();
}

void Records::writePlayersToFile()
{
	std::ofstream output;
	output.open("Records.txt");
	for(auto it = players.begin(); it != players.end(); it++)
	{
		output << (*(*it));
	}
	output.close();
}

void Records::addNewUser(Player* player)
{

}

/*void Records::readFile()
{
	std::ifstream input;
	input.open("Records.txt");
	int i = 0;
	if(input.is_open())
	{
		while(!input.eof())
		{
			User temp;
			input >> temp;
			uVec[i] = temp;
			i++;
		}
	}
}

void Records::writeFile()
{
	std::ofstream output;
	output.open("Records.txt");
	for(auto it = uVec.begin(); it != uVec.end(); it++)
	{
		output << it->name << it->wins;
	}
}

void Records::addNewUser(const std::string& name, int stepCount)
{
	for(auto it = uVec.begin(); it != uVec.end(); it++)
	{
		if(stepCount < it->wins)
		{
			User temp;
			temp.name = name;
			temp.wins = stepCount;
			uVec.insert(it, temp);
			uVec.resize(10);
		}
	}
}
*/