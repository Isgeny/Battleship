#pragma once
#include "GraphicsItem.h"
#include "Label.h"
#include "enums.h"

class HintIcon : public GraphicsItem
{
private:
	Label *pl, *rot, *del;

public:
	HintIcon(const Rect& rect, CallbackClicked callbackClicked = nullptr, bool visible = false, double r = 0.0, double g = 0.0, double b = 1.0, double a = 1.0);
	~HintIcon();
	void draw();
	void setVisible(bool visible);

};

