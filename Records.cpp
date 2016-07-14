#include "Records.h"

Records::Records()
{
	uVec.resize(10);
	for(auto it = uVec.begin(); it != uVec.end(); it++)
	{
		it->name = "";
		it->stepCount = 0;
	}
}

Records::~Records()
{

}

const std::vector<Uzverb>& Records::getUVec() const
{
	return uVec;
}

void Records::addNewUser(const std::string& name, int stepCount)
{
	for(auto it = uVec.begin(); it != uVec.end(); it++)
	{
		if(stepCount < it->stepCount)
		{
			Uzverb temp;
			temp.name = name;
			temp.stepCount = stepCount;
			uVec.insert(it, temp);
		}
	}
}