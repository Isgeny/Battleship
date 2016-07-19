#pragma once
#include "GraphicsItem.h"
#include "Label.h"
#include "enums.h"

class Button : public GraphicsItem
{
private:
	Label* text;

public:
	Button();
	Button(const std::string& text, const Rect& rect, CallbackClicked callbackClicked = nullptr, bool visible = false, double r = 0.0, double g = 0.0, double b = 1.0, double a = 1.0);
	~Button();
	void draw();
	void setVisible(bool visible);
	void setText(Label* text);
	void setText(const std::string& text);
	void setAlpha(double alpha);
	Label* getText() const;

};