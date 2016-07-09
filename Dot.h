#pragma once
#include <cmath>
#include "GraphicsRectItem.h"

class Dot : public GraphicsRectItem
{
public:
	Dot(int x, int y, int width, int height, bool visiable, bool pressed, void(*callbackFunc)());
	~Dot();
	void draw();

};