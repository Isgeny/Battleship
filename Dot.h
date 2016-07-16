#pragma once
#include <cmath>
#include "GraphicsItem.h"
#include "enums.h"
class Dot : public GraphicsItem
{
private:
	int radius;

public:
	Dot();
	Dot(int radius, const Rect& rect, double r = 0.0, double g = 0.0, double b = 1.0, double a = 1.0, bool visible = false);
	~Dot();
	void draw();

};