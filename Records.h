#pragma once
#include <string>
#include <vector>

struct Uzverb
{
	std::string name;
	int stepCount;
};

class Records
{
private:
	std::vector<Uzverb> uVec;

public:
	Records();
	~Records();
	const std::vector<Uzverb>& getUVec() const;
	void addNewUser(const std::string& name, int stepCount);

};