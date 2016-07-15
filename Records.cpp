#include "Records.h"

Records::Records()
{
	uVec.resize(10);
	for(auto it = uVec.begin(); it != uVec.end(); it++)
	{
		it->name = "";
		it->wins = 0;
	}
	readFile();
}

Records::~Records()
{

}

const std::vector<User>& Records::getUVec() const
{
	return uVec;
}

void Records::readFile()
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

std::istream& operator >> (std::istream& in, User& u)
{
	in >> u.name >> u.wins;
	return in;
}

std::ostream& operator << (std::ostream& out, User& u)
{
	out << u.name << u.wins;
	return out;
}