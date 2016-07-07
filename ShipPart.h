#pragma once
#include "GraphicsRectItem.h"

class ShipPart : public GraphicsRectItem
{
private:
	bool alive;

public:
	ShipPart(int x, int y, int width, int height, bool alive);
	~ShipPart();
	void draw();
	void setAlive(bool alive);
	bool getAlive() const;

};