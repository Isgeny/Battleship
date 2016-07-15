#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

struct User
{
	std::string name;
	int wins;
};

class Records
{
private:
	std::vector<User> uVec;

public:
	Records();
	~Records();
	const std::vector<User>& getUVec() const;
	void readFile();
	void writeFile();
	void addNewUser(const std::string& name, int wins);
	friend std::istream& operator >> (std::istream& in, User& u);
	friend std::ostream& operator << (std::ostream& out, User& u);
};