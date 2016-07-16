#pragma once
#include "GraphicsItem.h"
class Cross : public GraphicsItem
{
public:
	Cross();
	Cross(const Rect& rect, double r = 0.0, double g = 0.0, double b = 1.0, double a = 1.0, bool visible = false);
	~Cross();
	void draw();

};

