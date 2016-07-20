#pragma once
#include "GraphicsItem.h"
#include "Label.h"
#include "enums.h"

class About : public GraphicsItem
{
private:
	std::vector<std::string> aboutGame;
	Label *aGame, *aboutDev, *dev, *univer, *group, *email;

public:
	About();
	~About();
	void draw();
	void setVisible(bool visible);
};

