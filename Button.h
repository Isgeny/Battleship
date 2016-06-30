#pragma once
#include <string>
#include "freeglut.h"
class Button
{
private:
	int x, y, width, height;
	std::string text;

public:
	Button(int _x, int _y , int _width, int _height, const std::string& _text);
	int getX() const;
	int getY() const;
	int getWith() const;
	int getHeight() const;
	std::string getText() const;
	void setX(int _x);
	void setY(int _y);
	void setWidth(int _width);
	void setHeight(int _height);
	void setText(std::string& _text);
	bool mouseOnButton(int mX, int mY);
	void draw();
};