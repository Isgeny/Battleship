#pragma once
#include <cmath>
#include "GraphicsRectItem.h"

class Dot : public GraphicsRectItem
{
public:
	Dot(int x, int y, int width, int height, bool visiable, bool clicked, void (*callbackClickedFunc)(GraphicsRectItem*, int button, int state));
	~Dot();
	void draw();

};