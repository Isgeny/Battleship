#pragma once
#include "GraphicsItem.h"
#include "enums.h"

class Cross : public GraphicsItem
{
public:
	Cross();
	Cross(const Rect& rect, CallbackClicked callbackClicked = nullptr, bool visible = false, double r = 1.0, double g = 0.0, double b = 0.0, double a = 1.0);
	~Cross();
	void draw();

};