#pragma once
#include <string>
#include "freeglut.h"
#include "GraphicsItem.h"
#include "enums.h"

class Button : GraphicsItem
{
private:
	std::string text;

public:
	Button();
	Button(int _x, int _y , int _width, int _height, const std::string& _text);
	~Button();
	std::string getText() const;
	void setText(std::string& _text);
	bool mouseOnButton(int mX, int mY);
	void draw();
};