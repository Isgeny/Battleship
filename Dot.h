#pragma once
#include "GraphicsItem.h"
#include "enums.h"

class Dot : public GraphicsItem
{
private:
	int radius;

public:
	Dot();
	Dot(int radius, const Rect& rect, CallbackClicked callbackClicked = nullptr, bool visible = false, double r = 0.0, double g = 0.0, double b = 1.0, double a = 1.0);
	~Dot();
	void draw();
	void setRadius(int radius);
	int getRadius() const;

};