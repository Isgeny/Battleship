#pragma once
#include "GraphicsItem.h"
#include "Label.h"

class Button : public GraphicsItem
{
private:
	Label* text;

public:
	Button();
	Button(const std::string& text, const Rect& rect, double r = 1.0, double g = 1.0, double b = 1.0, double a = 1.0, bool visible = false, CallbackClicked callbackClicked = NULL);
	~Button();
	void draw();
	void mousePressed(int button, int state, int mouseX, int mouseY);
	void setText(Label* text);
	void setAlpha(double alpha);
	Label* getText() const;

};